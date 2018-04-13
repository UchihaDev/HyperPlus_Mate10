#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/miscdevice.h>
#include <linux/interrupt.h>
#include <linux/dma-mapping.h>
#include <asm/uaccess.h>
#include <linux/iommu.h>
#include <linux/hisi/hisi-iommu.h>
#include <linux/clk.h>
#include <linux/regulator/consumer.h>
#include <linux/regulator/driver.h>
#include <linux/regulator/machine.h>
#include "../../../../include/media/huawei/fd_drv_cfg.h"
#include "fd_log.h"
#include "fd.h"


ktime_t pre_start, pre_end,tme_start,tme_end;
s64 PRE_time,TME_time;
s64 total_time;
uint32_t g_flags,g_mask;

//static struct fd_device fd_dev;

static int fd_need_powerup(unsigned int refs)
{
    if (refs == 0xffffffff)
        fd_err("%s:need_powerup exc, refs == 0xffffffff\n", __func__);

    return ((refs == 0) ? 1 : 0);
}

static int fd_need_powerdn(unsigned int refs)
{
    if (refs == 0xffffffff)
        fd_err("%s:need_powerdn exc, refs == 0xffffffff\n", __func__);

    return ((refs == 1) ? 1 : 0);
}

static int fd_setclk_enable(struct fd_device *pdev)
{
    int ret = 0;
    if ((ret = clk_set_rate(pdev->clk, pdev->clk_rate)) != 0) {
        fd_err("[%s] Failed: clk_set_rate.%d\n", __func__, ret);
        return ret;
    }
    if ((ret = clk_prepare_enable(pdev->clk)) != 0) {
        fd_err("[%s] Failed: clk_prepare_enable.%d\n", __func__, ret);
        return ret;
    }
    if ((ret = clk_prepare_enable(pdev->jpg_clk)) != 0) {
        fd_err("[%s] Failed: clk_prepare_enable.%d\n", __func__, ret);
        goto clk_err;
    }
    return ret;
clk_err:
    clk_disable_unprepare(pdev->clk);
    return ret;
}
static int fd_clk_disable(struct fd_device *pdev)
{
    int ret = 0;
    fd_info("%s enter \n",__func__);
    clk_disable_unprepare(pdev->jpg_clk);
    clk_disable_unprepare(pdev->clk);
    if ((ret = clk_set_rate(pdev->clk, pdev->fd_low_clk_rate)) != 0) {
        fd_err("[%s] Failed: clk_set_rate.%d\n", __func__, ret);
        return ret;
    }
    return ret;
}

void  fd_top_cfg(struct fd_device *devp)
{
    void __iomem* top_vir_base = NULL;
    top_vir_base = ioremap_nocache(devp->top_phy_base, devp->top_mem_size);
    if (top_vir_base == NULL)
    {
        fd_err("%s(%d) remap failed",__func__, __LINE__);
        return;
    }
    writel(0x00000003,top_vir_base+0x74);
    writel(0x00020011,top_vir_base+0x40);
    writel(0x02605550,top_vir_base+0x007C);
    iounmap(top_vir_base);
}

static int fd_poweron(struct fd_device *devp)
{
    int ret = 0;
    fd_info("%s enter\n",__func__);
    if (!fd_need_powerup(devp->fd_power_ref)) {
        devp->fd_power_ref++;
        fd_info("%s: fd power up, ref=%d\n", __func__, devp->fd_power_ref);
        return 0;
    }
    ret = regulator_enable(devp->fd_media1_supply);
    if(ret!=0){
        fd_err("Failed: regulator_enable.%d\n", ret);
        return ret;
    }
    if ((ret = fd_setclk_enable(devp)) != 0) {
        fd_err("Failed: ispfunc_setclk_enable.%d\n", ret);
        goto fd_pwr_err;
    }

    ret = regulator_enable(devp->fd_supply);
    if(ret!=0){
        fd_err("Failed: regulator_enable.%d\n", ret);
        goto fd_pwr_err;
    }
    fd_top_cfg(devp);
    writel(0x02605550,devp->mstr_vir_base+0x0008);
    devp->fd_power_ref++;
    return ret;

fd_pwr_err:
    ret = regulator_disable(devp->fd_media1_supply);
    if(ret!=0){
        fd_err("Failed: regulator_disable.%d\n", ret);
    }
    return ret;
}

static int fd_poweroff(struct fd_device *devp)
{
    int ret = 0;

    fd_info("%s enter\n",__func__);
    if (!fd_need_powerdn(devp->fd_power_ref)) {
        devp->fd_power_ref--;
        fd_info("%s: fd power down, ref=%d\n", __func__, devp->fd_power_ref);
        return 0;
    }
    ret = regulator_disable(devp->fd_supply);
    if(ret!=0)
        fd_err("Failed: regulator_disable.%d\n", ret);

    ret = fd_clk_disable(devp);
    if(ret!=0)
        fd_err("Failed: fd_clk_disable.%d\n", ret);

    ret = regulator_disable(devp->fd_media1_supply);
    if(ret!=0)
        fd_err("Failed: regulator_disable.%d\n", ret);

    devp->fd_power_ref--;
    fd_info("%s: fd power down, ref=%d\n", __func__, devp->fd_power_ref);
    return ret;
}

void fd_res_deinit(struct platform_device *plat_devp)
{
    struct fd_device *pdev =
         (struct fd_device *) platform_get_drvdata(plat_devp);
    fd_info("enter");
    if(NULL == pdev){
        fd_err("%s: pdev is null", __func__);
        return;
    }
    if (NULL != pdev->mstr_vir_base) {
        devm_iounmap(&plat_devp->dev, pdev->mstr_vir_base);
        pdev->mstr_vir_base = NULL;
    }
    if (NULL != pdev->smmu_vir_base) {
        devm_iounmap(&plat_devp->dev, pdev->smmu_vir_base);
        pdev->smmu_vir_base = NULL;
    }
    if (NULL != pdev->fd_viraddr) {
        devm_iounmap(&plat_devp->dev, pdev->fd_viraddr);
        pdev->fd_viraddr = NULL;
    }
}

int fd_init_reg_res(struct platform_device *pdev, struct fd_device *fd_devp)
{
    int ret = 0;

    struct resource *mem_res = NULL;

    mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    if (NULL == mem_res) {
        fd_err("Get cfg res fail!");
        ret = -ENOENT;
        goto ERR_EXIT;
    }
    fd_devp->fd_viraddr = devm_ioremap(&pdev->dev, mem_res->start, resource_size(mem_res));
    if (NULL == fd_devp->fd_viraddr) {
        fd_err("Map cfg reg failed!");
        ret =  -ENOMEM;
        goto ERR_EXIT;
    }
    mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
    if (NULL == mem_res) {
        fd_err("Get cfg res fail!");
        ret = -ENOENT;
        goto ERR_EXIT;
    }
    fd_devp->smmu_vir_base= devm_ioremap(&pdev->dev, mem_res->start, resource_size(mem_res));
    if (NULL == fd_devp->smmu_vir_base) {
        fd_err("Map cfg reg failed!");
        ret =  -ENOMEM;
        goto ERR_EXIT;
    }
    mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
    if (NULL == mem_res) {
        fd_err("Get cfg res fail!");
        ret = -ENOENT;
        goto ERR_EXIT;
    }

    fd_devp->mstr_vir_base = devm_ioremap(&pdev->dev, mem_res->start, resource_size(mem_res));
    if (NULL == fd_devp->mstr_vir_base) {
        fd_err("Map cfg reg failed!");
        ret =  -ENOMEM;
        goto ERR_EXIT;
    }
    return ret;
ERR_EXIT:
    fd_res_deinit(pdev);
    return ret;
}
static int fd_res_init(struct platform_device *pdev,struct fd_device *fd_dev)
{
    int ret = 0, i;
    if(!fd_dev) return -1;
    mutex_init(&fd_dev->wlock);
    mutex_init(&fd_dev->rlock);
    atomic_set(&(fd_dev->tme_mode), MODE_MANUAL_TME);//lint !e1058
    for(i = 0; i < RESULT_TYPE_COUNT; i++)
    {
        atomic_set(&fd_dev->waitFlag[i], WAIT_RESULT_PENDING);//lint !e1058
        init_waitqueue_head(&fd_dev->wq[i]);
    }
    /* get base addr  */
    ret = fd_init_reg_res(pdev,fd_dev);
    if (ret) {
        goto ERR_EXIT;
    }
    return ret;
ERR_EXIT:
    fd_res_deinit(pdev);
    return ret;
}

static irqreturn_t fd_irq_handler(int irq, void *dev_id)
{
    struct fd_device *pdev = (struct fd_device *)dev_id;
    uint32_t flags, mask, error, idle_status;
    char __iomem * base_addr = NULL;
    unsigned int statePRE = WAIT_RESULT_PENDING, stateTME = WAIT_RESULT_PENDING;
    if(!pdev || !pdev->fd_viraddr)
        return IRQ_NONE;
    base_addr = pdev->fd_viraddr;
    mask  = FD_HW_READ_32(base_addr + AHFD_INT_MASK);
    flags = FD_HW_READ_32(base_addr + AHFD_INT_STATUS) & mask;
    if(flags & IRQ_ERR)
    {
        error = FD_HW_READ_32(base_addr + AHFD_ERR_STATUS);
        fd_err("IRQ Error! irq flags = 0x%x, error status = 0x%x", flags, error);

        /* if error is related to PRE */
        if(error & AHFD_PRE_ERR_MASK)
            statePRE = WAIT_RESULT_ERROR;
        /* if error is related to TME */
        if(error & AHFD_TME_ERR_MASK)
            stateTME = WAIT_RESULT_ERROR;
        if(error & AHFD_SWRST_ERR_MASK)
            fd_err("IPU Error Requires SW Reset!");
        goto _exit_int;
    }
    if(flags & IRQ_PRE_WR)
    {
        //pre_end = ktime_get();
        FD_HW_WRITE_32(0, base_addr + AHFD_PRE_EN);
        statePRE = WAIT_RESULT_READY;
    }
    if(flags & IRQ_TME_WR)
    {
        //tme_end = ktime_get();
        FD_HW_WRITE_32(0, base_addr + AHFD_TME_EN);
        stateTME = WAIT_RESULT_READY;
    }
_exit_int:

    // aknowledge interrupt(s)
    FD_HW_WRITE_32(flags, base_addr + AHFD_INT_CLEAR);
    if(WAIT_RESULT_PENDING != statePRE)
    {
        atomic_set(&pdev->waitFlag[IDX_WAIT_PRE], statePRE);//lint !e1058
        wake_up_interruptible(&pdev->wq[IDX_WAIT_PRE]);
    }
    if(WAIT_RESULT_PENDING != stateTME)
    {
        atomic_set(&pdev->waitFlag[IDX_WAIT_TME], stateTME);//lint !e1058
        wake_up_interruptible(&pdev->wq[IDX_WAIT_TME]);
    }
    idle_status = FD_HW_READ_32(base_addr + AHFD_IDLE_STATUS);
    if((WAIT_RESULT_READY == statePRE) && (MODE_AUTO_TME == atomic_read(&pdev->tme_mode)) && (idle_status & 0x1))
    {
        fd_dbg("TME auto mode");
        mask |= IRQ_TME_WR;
        FD_HW_WRITE_32(mask, base_addr + AHFD_INT_MASK);
        FD_HW_WRITE_32(1, base_addr + AHFD_TME_EN);
    }
    return IRQ_HANDLED;
}
static void fd_smmu_w(struct fd_device *fddev, u32 val,unsigned int off)
{
    char __iomem * reg = fddev->smmu_vir_base+ off;
    writel(val, reg);
}

//read fd cfg reg
static u32 fd_smmu_r(struct fd_device *fddev,unsigned int off)
{
    char __iomem * reg = fddev->smmu_vir_base + off;
    u32 val = readl(reg);
    fd_dbg("REG READ:0x%pK = 0x%08x", reg, val);
    return val;
}

static void fd_smmu_mstr_w(struct fd_device *fddev, u32 val,unsigned int off)
{
    char __iomem * reg = fddev->mstr_vir_base+ off;
    writel(val, reg);
}

//read fd cfg reg
static u32 fd_smmu_mstr_r(struct fd_device *fddev,unsigned int off)
{
    char __iomem * reg = fddev->mstr_vir_base + off;
    u32 val = readl(reg);
    fd_dbg("REG READ:0x%pK = 0x%08x", reg, val);
    return val;
}
int  fd_smmu_cfg(struct fd_device *pdev,int bypass)
{
    u32 tmp = 0;
    /* disable SMMU for global */
    tmp = fd_smmu_r(pdev,SMMU_GLOBAL_BYPASS);
    tmp = (tmp & 0xFFF0FFFE);
    tmp = tmp|(1<<16);
    fd_smmu_w(pdev,tmp,SMMU_GLOBAL_BYPASS);
    if (bypass) {
    /* disable SMMU only for FD stream id */
    int i ;
    for(i=MIN_FD_SMMU_STREAM_ID;i<MAX_FD_SMMU_STREAM_ID;i++)
    {
        fd_smmu_w(pdev,(fd_smmu_r(pdev,smmu_offset_list[2]+i*SMMU_STREAM_OFFSET))|0x1,
             smmu_offset_list[2]+i*SMMU_STREAM_OFFSET);
    }
    goto exit;
}
    fd_smmu_w(pdev,0xFF,smmu_offset_list[1]);
    fd_smmu_w(pdev,0x0,smmu_offset_list[0]);
    //SMMU Context Config
    tmp = pdev->phy_pgd_base;
    fd_smmu_w(pdev,tmp,smmu_offset_list[3]);
    tmp = fd_smmu_r(pdev,smmu_offset_list[4]);
    tmp |= 0x1;
    fd_smmu_w(pdev,tmp,smmu_offset_list[4]);
    //fama
    tmp = fd_smmu_r(pdev,smmu_offset_list[6]);
    FD_REG_SET_FIELD(tmp, FAMA_CTRL1_NS_fama_ptw_msb_ns, pdev->phy_pgd_fama_ptw_msb);
    fd_smmu_w(pdev,tmp,smmu_offset_list[6]);
    tmp = fd_smmu_r(pdev,smmu_offset_list[5]);
    FD_REG_SET_FIELD(tmp, FAMA_CTRL0_NS_fama_chn_sel_ns, 1);
    fd_smmu_w(pdev,tmp,smmu_offset_list[5]);
    //fama
exit:
    return 0;
}
int  fd_smmu_master_cfg(struct fd_device *pdev,int bypass,IO_IPU_MAPS_va *maps_Va)
{
    u32 tmp = 0;
    u32 i ,j,k = 0;
    tmp = fd_smmu_mstr_r(pdev,mstr_offset_list[1]); //offset:0x34
    tmp = (tmp |0x3);
    fd_smmu_mstr_w(pdev,tmp,mstr_offset_list[1]);
    /* disable SMMU for global */
    tmp = fd_smmu_mstr_r(pdev,SMMU_MSTR_GLB_BYPASS);
    tmp = (tmp & 0xFFFFFFFE);
    fd_smmu_mstr_w(pdev,tmp,SMMU_MSTR_GLB_BYPASS);
    if (bypass) {
    /* disable SMMU only for FD stream id */
    for(k=MIN_FD_MSTR_STREAM_ID;k<MAX_FD_MSTR_STREAM_ID;k++)
        {
            fd_smmu_mstr_w(pdev,(fd_smmu_mstr_r(pdev,mstr_offset_list[2]+k*SMMU_STREAM_OFFSET))|0x1,
                (mstr_offset_list[2]+k*SMMU_STREAM_OFFSET));//offset:0x100
        }
        goto exit;
    }
   /* config smmu master ics*/
    tmp = fd_smmu_mstr_r(pdev,mstr_offset_list[0]);
    tmp = (tmp |0x7FF);
    fd_smmu_mstr_w(pdev,tmp,mstr_offset_list[0]);
    i = (maps_Va->img_size_Y)/(1024*32);
    j = (maps_Va->img_size_UV)/(1024*32);

    tmp = maps_Va->preImg_va[0];
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[3]+0*SMMU_STREAM_OFFSET));
    //stream 1 va_start
    tmp =maps_Va->preImg_va[1];
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[3]+1*SMMU_STREAM_OFFSET));
    //stream 2 va_start
    if(i<=FD_MSTR_STREAM_ID_2)
    tmp = maps_Va->preImg_va[0];
    else
    tmp =maps_Va->preMap_va_1[0];
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[3]+2*SMMU_STREAM_OFFSET));
    //stream 3 va_start
    tmp =maps_Va->preMap_va_1[0];
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[3]+3*SMMU_STREAM_OFFSET));
    //stream 4 va_start
    tmp =maps_Va->preMap_va_1[0];
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[3]+4*SMMU_STREAM_OFFSET));
    //stream 5 va_start
   tmp = maps_Va->preMap_va_1[0];
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[3]+5*SMMU_STREAM_OFFSET));
    //stream 6 va_start
    tmp = maps_Va->preMap_va_1[0];
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[3]+6*SMMU_STREAM_OFFSET));
    //stream 7 va_start
    tmp = maps_Va->preMap_va_1[0];
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[3]+7*SMMU_STREAM_OFFSET));
    //stream 8 va_start
    tmp = maps_Va->preMap_va_1[0];
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[3]+8*SMMU_STREAM_OFFSET));
    //stream 9 va_start
    tmp =maps_Va->preMap_va_1[0];
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[3]+9*SMMU_STREAM_OFFSET));
    //stream 10 va_start
    tmp = maps_Va->preMap_va_1[0];
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[3]+10*SMMU_STREAM_OFFSET));

    //stream 0 va_end
    tmp = (u32)maps_Va->preImg_va[0]+(i*32*1024); //300K to 320K -32K = 288k    //186k  to 192k -32k = 160k
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[4]+0*SMMU_STREAM_OFFSET));
    //stream 1 va_end
    tmp = (u32)maps_Va->preImg_va[1]+(j*32*1024);//150K to 160k - 32k = 128k   //93k to 96k -32k = 64k
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[4]+1*SMMU_STREAM_OFFSET));

    //stream 2 va_end
    if(i<=FD_MSTR_STREAM_ID_2)
    tmp = (u32)maps_Va->preImg_va[0]+(i*32*1024); //300k to 320k -32k = 288k   //2752k -32k = 2720k
    else
    tmp =maps_Va->preMap_va_1[0]+2785280;
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[4]+2*SMMU_STREAM_OFFSET));
    //stream 3 va_end
    tmp =maps_Va->preMap_va_1[0]+2785280;//300k to 320k - 32k = 288k
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[4]+3*SMMU_STREAM_OFFSET));
    //need check by fanny
    //stream 4 va_end
    tmp =maps_Va->preMap_va_1[0]+2785280;//150k to 160k - 32k = 128k
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[4]+4*SMMU_STREAM_OFFSET));

    //stream 5 va_end
   tmp =maps_Va->preMap_va_1[0]+2785280;// 150k to 160k - 32k = 128k
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[4]+5*SMMU_STREAM_OFFSET));

    //stream 6 va_end
   tmp =maps_Va->preMap_va_1[0]+2785280; //75k to 96k - 32k = 64k
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[4]+6*SMMU_STREAM_OFFSET));

    //stream 7 va_end
    tmp =maps_Va->preMap_va_1[0]+2785280; //300k to 320k  - 32k = 288k
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[4]+7*SMMU_STREAM_OFFSET));

    //stream 8 va_end
    tmp =maps_Va->preMap_va_1[0]+2785280; //3k to 32k  - 32k = 0
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[4]+8*SMMU_STREAM_OFFSET));

    //stream 9 va_end
    tmp =maps_Va->preMap_va_1[0]+2785280;// 1200k to 1216k  - 32k = 1184k
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[4]+9*SMMU_STREAM_OFFSET));

    //stream 10 va_end
    tmp = maps_Va->preMap_va_1[0]+2785280; //844k to 864k  - 32k = 832k
    fd_smmu_mstr_w(pdev,tmp,(mstr_offset_list[4]+10*SMMU_STREAM_OFFSET));
exit:
   // iounmap(fd_dev.mstr_vir_base);
   return 0;
}

static int fd_open(struct inode *inode, struct file *fd)
{
    int ret = 0;
    struct miscdevice *miscdev = fd->private_data;
    struct fd_device *pdev = container_of(miscdev, struct fd_device, device);

    fd_info("AHFD device open.");
    if (!atomic_dec_and_test(&pdev->accessible)) {
        fd_err("fd dev has been opened!");
        atomic_inc(&pdev->accessible);
        return -EBUSY;
    }
    ret = fd_poweron(pdev);
    if (ret < 0) {
        fd_err("Failed to power on fd.");
        goto err_out1;
    }
    ret = request_irq(pdev->fd_irq, fd_irq_handler, 0, "fd_irq", (void *)pdev);
    if (ret) {
        fd_err("Failed to request fd irq.%d", ret);
        goto err_out;
    }
    fd->private_data = (void *)pdev;
    return ret;
err_out:
    fd_poweroff(pdev);
    return ret;
err_out1:
    atomic_inc(&pdev->accessible);
    return ret;

}

static int fd_release(struct inode *inode, struct file *fd)
{
    struct fd_device *pdev = (struct fd_device *)fd->private_data;
    if (NULL == pdev) {
        fd_err("dev is NULL.");
        return -ENODEV;
    }
    fd_info("FD device close.");
    if (atomic_sub_and_test(0, &pdev->accessible)) {
        free_irq(pdev->fd_irq, pdev);
        fd_poweroff(pdev);
        atomic_inc(&pdev->accessible);
    }
    else {
        fd_warn("accessible not zero.");
    }
    fd_info("AHFD Release");
    return 0;
}
static long AHFD_Get_Version(struct fd_device *pdev, unsigned int cmd, unsigned long arg)
{
    uint32_t version = 0;
    if(NULL != pdev->fd_viraddr)
        version = FD_HW_READ_32(pdev->fd_viraddr + AHFD_IPU_VER_OFFSET);
    if(!access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd)))
    {
        fd_err("AHFD_GET_VERSION !access_ok");
        return -EFAULT;
    }
    if (__put_user(version, (uint32_t __user *)arg))
    {
        fd_err("AHFD_GET_VERSION can't copy to user");
        return -EFAULT;
    }
    fd_info("AHFD_GET_VERSION 0x%x", version);
    return 0;
}

/* Check if input register range is within AHFD register space */
static int fd_access_ok(uint32_t offset, uint32_t size)
{
    /*
    * offset and size are unsigned, therefore always positive.
    * There can be no resulting access of address lower than register space base address.
    * Check offsets to upper bounds of register space.
    */
    if (offset            > AHFD_MAX_OFFSET     ||
        size              > AHFD_MAX_OFFSET / 4 ||
        offset + 4 * size > AHFD_MAX_OFFSET)
    {
        fd_err("Illegal address access");
        return -1;
    }

    return 0;
}

/*
* Check if buffer is correctly organized as described in fd_drv_cfg.h and does
* not try any bogus accesses
*/
static int fd_register_buffer_ok(uint32_t *start, uint32_t length)
{
    uint32_t size, offset;
    uint32_t arr_pos = 0;

    /* Check that the buffer still has an available offset and size */
    while(length > 2)
    {
        offset = start[arr_pos];
        size   = start[(arr_pos + 1)];/*lint !e679 */

        /* No empty sub-arrays */
        if(0 == size)
            return -1;

        /* Check if respects AHFD register space boundaries */
        if(fd_access_ok(offset, size) < 0)
            return -1;

        /* Sub-array length exceeds buffer length */
        if(length < size + 2)
            return -1;

        length  -= (size + 2);
        arr_pos += (size + 2);
    }

    /* If there are any dangling offset [and size] */
    if(length > 0)
        return -1;

    return 0;
}

static long AHFD_Write_Regs(struct fd_device *pdev, unsigned int cmd, unsigned long arg)
{
    long rc = 0;
    struct fd_reg_array regs;
    if (mutex_lock_interruptible(&pdev->wlock))
    {
        fd_err("AHFD_WRITE_REGS mutex interrupt error");
        return -EINTR;
    }
    fd_dbg("AHFD_WRITE_REGS:\n");
    if (copy_from_user(&regs, (struct fd_reg_array*)arg, sizeof(struct fd_reg_array)))
    {
        fd_err("AHFD_WRITE_REGS can't copy from user1");
        rc = -EFAULT;
        goto _write_exit;
    }
    if((regs.length > FD_REG_MAX_ARRAY) || (regs.length==0) || (!regs.values) ||((regs.length* sizeof(uint32_t)) > (FD_REG_MAX_ARRAY* sizeof(uint32_t))))
    {
        fd_err("AHFD_WRITE_REGS invalid input");
        rc = -EINVAL;
        goto _write_exit;
    }
    if (copy_from_user(pdev->registerBufferWrite, regs.values, regs.length * sizeof(uint32_t)))
    {
        fd_err("AHFD_WRITE_REGS can't copy from user2");
        rc = -EFAULT;
        goto _write_exit;
    }
    if(NULL != pdev->fd_viraddr)
    {
        char __iomem *base_addr = pdev->fd_viraddr;
        char __iomem *addr;
        uint32_t size, k, offset;
        uint32_t *regStart = pdev->registerBufferWrite;
        uint32_t buffer_length = regs.length;
        uint32_t regVal;
        if(fd_register_buffer_ok(regStart, buffer_length) < 0)
        {
            fd_err("AHFD_WRITE_REGS invalid input");
            rc = -EACCES;
            goto _write_exit;
        }
        while(buffer_length >0)
        {
            offset = *(regStart++);
            size   = *(regStart++);
            addr   = base_addr + offset;
            /* Check buffer validity */

            //fd_info("offset = 0x%x, size = %d", offset, size);

            for(k = size; k != 0; k--)
            {
                regVal = *(regStart++);
                FD_HW_WRITE_32(regVal, addr);
                /*for FD perf count*/
                /*if(offset == 0x041C)
                {
                    uint32_t tmp = regVal & 0x4;
                    if(tmp !=0)
                    {
                        pre_start = ktime_get();
                    }
                }
                if((offset == 0x031C)&&(regVal == 1))
                {
                    tme_start = ktime_get();
                }*/

                addr += 4;
            }
            buffer_length -= (size + 2);
        }
    }
_write_exit:
            mutex_unlock(&pdev->wlock);//lint !e455
            return rc;
}
static long AHFD_Read_Regs(struct fd_device *pdev, unsigned int cmd, unsigned long arg)
{
    long rc = 0;
    struct fd_reg_array regs;

    if (mutex_lock_interruptible(&pdev->rlock))
    {
        fd_err("AHFD_READ_REGS mutex interrupt error");
        return  -EINTR;
    }
    fd_dbg("AHFD_READ_REGS:\n");
    if (copy_from_user(&regs, (struct fd_reg_array*)arg, sizeof(struct fd_reg_array)))
    {
        fd_err("AHFD_READ_REGS can't copy from user1");
        rc = -EFAULT;
        goto _read_exit;
    }
    if((regs.length > FD_REG_MAX_ARRAY) || (regs.length==0) || (!regs.values) ||((regs.length* sizeof(uint32_t)) > (FD_REG_MAX_ARRAY* sizeof(uint32_t))))
    {
        fd_err("AHFD_READ_REGS invalid input");
        rc = -EINVAL;
        goto _read_exit;
    }

    if (copy_from_user(pdev->registerBufferRead, regs.values, regs.length * sizeof(uint32_t)))
    {
        fd_err("AHFD_READ_REGS can't copy from user2");
        rc = -EFAULT;
        goto _read_exit;
    }
    if(NULL != pdev->fd_viraddr)
    {
        char __iomem *base_addr = pdev->fd_viraddr;
        char __iomem *addr;
        uint32_t size, k, offset;
        uint32_t *regStart = pdev->registerBufferRead;
        uint32_t buffer_length = regs.length;
        uint32_t regVal;
        if(fd_register_buffer_ok(regStart, regs.length) < 0)
        {
            fd_err("AHFD_READ_REGS invalid input");
            rc = -EACCES;
            goto _read_exit;
        }
        while(buffer_length >0)
        {
            offset = *(regStart++);
            size   = *(regStart++);
            addr   = base_addr + offset;
            //fd_info("offset = 0x%x, size = %d", offset, size);

            for(k = size; k != 0; k--)
            {
                regVal = FD_HW_READ_32(addr);
                *(regStart++) = regVal;
                addr += 4;
            }
            buffer_length -= (size + 2);
        }
    }
    if((regs.length* sizeof(uint32_t)) > (FD_REG_MAX_ARRAY* sizeof(uint32_t)))
    {
        fd_err("AHFD_READ_REGS invalid input");
        rc = -EINVAL;
        goto _read_exit;
    }
    if (copy_to_user(regs.values, pdev->registerBufferRead, regs.length * sizeof(uint32_t)))
    {
        fd_err("AHFD_READ_REGS can't copy to user");
        rc = -EFAULT;
        goto _read_exit;
    }
_read_exit:
        mutex_unlock(&pdev->rlock);//lint !e455
        return rc;
}
static long AHFD_Wait_Result(struct fd_device *pdev, unsigned int cmd, unsigned long arg)
{
    long rc = 0;
    unsigned int waitType;
    if(!access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd)))
    {
        fd_err("AHFD_GET_VERSION !access_ok");
        return -EFAULT;
    }
    if(__get_user(waitType,&arg))
    {
        fd_err("AHFD_Wait_Result can't get from user");
        return  -EFAULT;
    }
    fd_dbg("AHFD_WAIT_RESULT type = %d\n", waitType);

    if(waitType & RESULT_TYPE_PRE)
    {
        // wait if flag is not WAIT_RESULT_PENDING ( = 0)
        wait_event_interruptible(pdev->wq[IDX_WAIT_PRE], !atomic_sub_and_test(WAIT_RESULT_PENDING, &pdev->waitFlag[IDX_WAIT_PRE]));//lint !e666
        // check for error flag and reset flag to WAIT_RESULT_PENDING (= 0)
        if(!atomic_sub_and_test(WAIT_RESULT_READY, &pdev->waitFlag[IDX_WAIT_PRE]))
        {
            fd_err("Error while AHFD_WAIT_RESULT");
            rc = -EIO;
            atomic_set(&pdev->waitFlag[IDX_WAIT_PRE], WAIT_RESULT_PENDING);//lint !e1058
        }
        fd_dbg("AHFD_WAIT_RESULT IDX_WAIT_PRE finished, status = %ld\n", rc);
    }

    if(waitType & RESULT_TYPE_TME)
    {
        // wait if flag is not WAIT_RESULT_PENDING ( = 0)
        wait_event_interruptible(pdev->wq[IDX_WAIT_TME], !atomic_sub_and_test(WAIT_RESULT_PENDING, &pdev->waitFlag[IDX_WAIT_TME]));//lint !e666

        // check for error flag and reset flag to WAIT_RESULT_PENDING (= 0)
        if(!atomic_sub_and_test(WAIT_RESULT_READY, &pdev->waitFlag[IDX_WAIT_TME]))
        {
            fd_err("Error while AHFD_WAIT_RESULT");
            rc = -EIO;
            atomic_set(&pdev->waitFlag[IDX_WAIT_TME], WAIT_RESULT_PENDING);//lint !e1058
        }
        /*for FD perf count*/
        /*PRE_time = ktime_to_us(ktime_sub(pre_end, pre_start));
        TME_time = ktime_to_us(ktime_sub(tme_end, pre_end));
        fd_dbg("AHFD_WAIT_RESULT IDX_WAIT_TME finished, status = %ld\n", rc);
        fd_info("PRE_time: %lu,TME_time: %lu\n", (unsigned long)PRE_time, (unsigned long)TME_time);*/
    }
    return rc;
}
static long AHFD_Set_Mode(struct fd_device *pdev, unsigned int cmd, unsigned long arg)
{
    int mode;
    if(!access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd)))
    {
        fd_err("AHFD_GET_VERSION !access_ok");
        return -EFAULT;
    }
    if(__get_user(mode,&arg))
    {
        fd_err("AHFD_Set_Mode can't get from user");
        return  -EFAULT;
    }
    if((mode != MODE_AUTO_TME) && (mode != MODE_MANUAL_TME))
    {
        fd_err("AHFD_SET_MODE invalid input");
        return -EINVAL;
    }
    atomic_set(&pdev->tme_mode, mode);//lint !e1058
    fd_info("AHFD_SET_MODE %d\n", mode);
    return 0;
}

static long AHFD_set_smmu_cfg(struct fd_device *pdev, unsigned int cmd, unsigned long arg)
{
    long rc = 0;
    int bypass = 0;
    if(pdev->smmu_flag == 1)
    {
        IO_IPU_MAPS_va maps_Va;
        if (copy_from_user(&maps_Va, (IO_IPU_MAPS_va *)arg, sizeof(IO_IPU_MAPS_va)))
        {
            fd_err("AHFD_set_smmu_cfg can't copy from user");
            rc = -EFAULT;
            goto _set_exit;
        }
        bypass = 0;
        fd_smmu_cfg(pdev,bypass);
        fd_smmu_master_cfg(pdev,bypass,&maps_Va);
    }
    else
    {
        bypass = 1;
        fd_smmu_cfg(pdev,bypass);
        fd_smmu_master_cfg(pdev,bypass,NULL);
    }
_set_exit:
            return rc;
}
static long fd_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    long rc = 0;
    struct fd_device *pdev = NULL;
    if(!file || !file->private_data)
    {
        fd_err("No private data!");
        return -EINVAL;
    }
    pdev = (struct fd_device *)file->private_data;
    if(!arg)
    {
        fd_err("Invalid argument 0");
        return -EINVAL;
    }
    switch (cmd) {
        case AHFD_GET_VERSION:
            {
                 rc = AHFD_Get_Version(pdev, cmd, arg);
                 break;
            }
        case AHFD_WRITE_REGS:
            {
                rc = AHFD_Write_Regs(pdev, cmd, arg);
                break;
            }
        case AHFD_READ_REGS:
            {
                rc = AHFD_Read_Regs(pdev, cmd, arg);
                break;
            }
        case AHFD_WAIT_RESULT:
            {
                rc = AHFD_Wait_Result(pdev, cmd, arg);
                break;
            }
        case AHFD_SET_MODE:
            {
                rc =  AHFD_Set_Mode(pdev, cmd, arg);
                break;
            }
        case AHFD_SET_MASTER_VA:
            {
                rc =  AHFD_set_smmu_cfg(pdev, cmd, arg);
                break;
            }
        default:
        {
            return -EINVAL;
        }
    }

    return rc;
}

static struct file_operations fd_fops = {
    .owner = THIS_MODULE,
    .open = fd_open,
    .release = fd_release,
    .unlocked_ioctl = fd_ioctl,
};

static struct miscdevice fd_misc_dev = {
        .minor = MISC_DYNAMIC_MINOR,
        .name = "hisi-fd",
        .fops = &fd_fops,
};



static int fd_remove(struct platform_device *plat_devp)
{
    struct fd_device *pdev =
    (struct fd_device *)platform_get_drvdata(plat_devp);

    if (NULL == pdev) {
    fd_err("fd dev is NULL.This should not happen");
    return -ENODEV;
    }
    clk_put(pdev->jpg_clk);
    fd_res_deinit(plat_devp);
    misc_deregister(&pdev->device);
    if (pdev) {
       kfree(pdev);
    }
    return 0;
}

static int fd_setup_irq(struct platform_device *pdev, struct fd_device *fd_Dev)
{
    int irq = 0;
    irq = platform_get_irq(pdev, 0);/*lint !e838*/
    if (irq < 0) {
        fd_err("Get irq fail!");
        return -EINVAL;
    }
    fd_Dev->fd_irq = (unsigned int)irq;
    fd_info("Get irq: %d.", irq);
    return 0;
}
static void fd_get_pgd_base(struct fd_device *fd_Dev)
{
    struct iommu_domain_data *info;

    fd_Dev->phy_pgd_base = 0;
    //get iommu domain
    if ((fd_Dev->domain = hisi_ion_enable_iommu(NULL)) == NULL) {
        fd_err("[%s] Failed : iommu_domain_alloc.%pK\n", __func__, fd_Dev->domain);
        return;
    }
    if ((info = (struct iommu_domain_data *)fd_Dev->domain->priv) == NULL) {
        fd_err("[%s] Failed : info.%pK\n",__func__, info);
        return;
    }
    fd_Dev->phy_pgd_base = (unsigned int)info->phy_pgd_base;
    fd_Dev->phy_pgd_fama_ptw_msb = ((unsigned int)(info->phy_pgd_base >> 32)) & 0x0000007F;

}

static int fd_get_offset_list(void)
{
    u32 wia[MAX_FD_OFFSET_LIST_NUM]={ 0 };
    struct property *prop = NULL;
    unsigned int i = 0, len = 0;
    struct device_node *fd_node = NULL;
    const char *smmu_name = "smmu_offset_list";
    const char *mstr_name = "mstr_offset_list";
    const char *fd_name = "fd_offset_list";

    fd_node =
        of_find_compatible_node(NULL, NULL, "hisilicon,hisi-fd");
    if (!fd_node) {
        return -1;
    }
    prop = of_find_property(fd_node, smmu_name, NULL);
    if (!prop) {
        return -EINVAL;
    }
    if (!prop->value) {
        return -ENODATA;
    }
    len = ((unsigned int)prop->length) /sizeof(uint32_t);
    if (of_property_read_u32_array(fd_node, smmu_name, wia, len)) {
        return -1;
    }
    for (i = 0; i < len; i++) {
        smmu_offset_list[i] =  wia[i];
    }
    prop = of_find_property(fd_node, mstr_name, NULL);
    if (!prop) {
        return -EINVAL;
    }
    if (!prop->value) {
        return -ENODATA;
    }
    len = ((unsigned int)prop->length) /sizeof(uint32_t);
    if (of_property_read_u32_array(fd_node, mstr_name, wia, len)) {
        return -1;
    }
    for (i = 0; i < len; i++) {
        mstr_offset_list[i] =  wia[i];
    }

    prop = of_find_property(fd_node, fd_name, NULL);
    if (!prop) {
        return -EINVAL;
    }
    if (!prop->value) {
        return -ENODATA;
    }
    len = ((unsigned int)prop->length) /sizeof(uint32_t);
    if (of_property_read_u32_array(fd_node, fd_name, wia, len)) {
        return -1;
    }
    for (i = 0; i < len; i++) {
        fd_offset_list[i] =  wia[i];
    }
    return 0;
}

static void fd_get_dt_data(struct platform_device *Ddev, struct fd_device *fd_devp)
{
    int ret;
    u32 flag = 0;
    u32 clk_rate = 0;
    uint32_t base_array[2] = {0};
    struct device *pdev = &(Ddev->dev);
    struct device_node *np = pdev->of_node;
    if (NULL == np) {
        fd_err("%s: of node NULL.", __func__);
        return ;
    }
    //get offset data
    fd_get_offset_list();
    //get media supply for FD
    fd_devp->fd_media1_supply = devm_regulator_get(pdev, "hisi-media");
    if (IS_ERR(fd_devp->fd_media1_supply)) {
        fd_err("[%s] Failed : ISPSRT devm_regulator_get.%pK\n", __func__, fd_devp->fd_media1_supply);
        return ;
    }

    //get supply for FD
    fd_devp->fd_supply = devm_regulator_get(pdev, "hisi-fd");
    if (IS_ERR(fd_devp->fd_supply)) {
        fd_err("[%s] Failed : ISPSRT devm_regulator_get.%pK\n", __func__, fd_devp->fd_supply);
        return ;
    }
    //get clk parameters
    fd_devp->clk = devm_clk_get(pdev, "clk_fd_func");
    if (IS_ERR(fd_devp->clk)) {
        fd_err("get clk failed");
        return ;
    }
    fd_devp->jpg_clk = clk_get(NULL, "clk_jpg_func");
    if (fd_devp->jpg_clk == NULL) {
        fd_err("get jpg clk failed");
        return ;
    }

    ret = of_property_read_u32_array(np, "huawei,top-base", base_array, 2);
    if (ret < 0) {
        fd_err("%s failed get jpeg base %d", __func__, __LINE__);
        return ;
    }
    fd_devp->top_phy_base = base_array[0];
    fd_devp->top_mem_size = base_array[1];
    ret = of_property_read_u32(np, "clock-low-frequency", &fd_devp->fd_low_clk_rate);
    if (ret) {
        fd_err("get fd_low_clk_rate failed, ret:%d", ret);
        return ;
    }
    ret = of_property_read_u32(np, "clock-value", &clk_rate);
    if (ret) {
        fd_err("get rate failed, ret:%d", ret);
        return ;
    }
    fd_devp->clk_rate = clk_rate;

    fd_info("get clk rate: %u", clk_rate);
   //get smmu flag
    ret = of_property_read_u32(np, "huawei,smmu-flag", &flag);
    if (ret) {
        fd_err("get smmu flag failed, ret:%d", ret);
        return ;
    }
    fd_info("get smmu-flag: %u",flag);
    fd_devp->smmu_flag = flag;
    if(fd_devp->smmu_flag == 1)
    {
         fd_get_pgd_base(fd_devp);
    }
}

static int fd_probe(struct platform_device *pdev)
{
    int ret = 0;
    struct fd_device *fddev = NULL;
    fddev = (struct fd_device *)kzalloc(sizeof(struct fd_device), GFP_KERNEL);
   if (!fddev) {
    fd_err("failed to alloc fddev.\n");
    return -ENXIO;
    }
    platform_set_drvdata(pdev, fddev);
    atomic_set(&fddev->accessible, 1);//lint !e1058
    fddev->device = fd_misc_dev;
    if((ret = misc_register(&fddev->device))!=0){/*lint !e838*/
    goto err_out1;
    }
    ret = fd_setup_irq(pdev, fddev);
    if (ret) {
        goto err_out;
    }
    ret = fd_res_init(pdev,fddev);
    if (ret) {
        goto err_out;
    }
    fd_get_dt_data(pdev,fddev);
    fd_info("Success!");
    return ret;

err_out:
    misc_deregister(&fddev->device);
err_out1:
    kfree(fddev);
    return ret;
}


#ifdef CONFIG_OF
static struct of_device_id fd_of_id[] = {
    {.compatible = "hisilicon,hisi-fd", .data = (void *)NULL},
    {} /*lint !e785*/
};
#endif

static struct platform_driver fd_platform_driver = {
    .probe = fd_probe,
    .remove = fd_remove,
    .driver = {
    .name = "hisi-fd",
    .owner  = THIS_MODULE, /*lint !e64*/
#ifdef CONFIG_OF
    .of_match_table = of_match_ptr(fd_of_id),
#endif
    },/*lint !e785*/
};/*lint !e785*/

/*lint -e528 -esym(528,*)*/
module_platform_driver(fd_platform_driver);/*lint   !e64*/
/*lint -e528 +esym(528,*)*/

/*lint -e753 -esym(753,*)*/
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("hisilicon_fd driver");
MODULE_AUTHOR("hisilicon");
/*lint -e753 +esym(753,*)*/


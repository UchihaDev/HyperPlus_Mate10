/*
 * hisilicon dieid driver, hisi_dieid.c
 *
 * Copyright (c) 2013 Hisilicon Technologies CO., Ltd.
 *
 */
#include <asm/compiler.h>
#include <linux/compiler.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/err.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>
#include <linux/platform_device.h>
#include <linux/cpumask.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <asm/memory.h>
#include <linux/semaphore.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/interrupt.h>
#include <linux/kthread.h>
#include <linux/smp.h>
#include <linux/dma-mapping.h>
#include <linux/workqueue.h>
#include <linux/timer.h>

#include <linux/hisi/hisi_efuse.h>
#include <linux/mfd/hisi_pmic.h>

#define HISI_DIEID_DEV_NAME "dieid"

#define HISI_DIEID_READ_DIEID	0x2000
#define HISI_DIEID_TIMEOUT_1000MS	1000

#define HISI_PMU_BUF_SIZE	100
#define HISI_PMU_IP_SIZE	8
#define HISI_MAIN_PMU_IP_SIZE	17
#define HISI_SOC_BUF_SIZE	200
#define HISI_SOC_IP_SIZE	20
#define HISI_AP_DIEID_BUF_SIZE	300

/*sub pmu*/
#define HI6423_SID	6
#define HI6422_SID	1

/*define hi6423v100 & hi6422v300 commen para*/
#define OPEN_CLK_VALUE	0x5a
#define RESET_VALUE	0x00
#define DELAY_TIME	30
#define AND_VALUE1 	0xe3
#define AND_VALUE2	0xfb
#define AND_VALUE3	0xfc
#define AND_VALUE4	0xfd
#define AND_VALUE5	0x3f
#define AND_VALUE6	0xc0

/*define hi6423v100 register*/
#define ID_OTP_CLK_CTRL	0x54
#define ID_OTP_CTRL0	0x51
#define ID_OTP_CTRL1	0x52
#define ID_OTP_0	0x4d
#define HI6423_READ_TIMES	4

/*define hi6422v300 register*/
#define OTP_119_112	0xf6
#define OTP_REG_BEGIN	0x0c
#define HI6422_READ_TIMES	8
#define RST_REG_NUM	4

enum hi6422v300_reg{
	OTP_CLK_CTRL = 0xC0,
	OTP_CTRL0,
	OTP_CTRL1,
	OTP_CTRL2
};

/*main pmu*/
enum hi6421v600_dieid_regs{
	PMIC_OTP_44_R_ADDR = 0x288,
	PMIC_OTP_45_R_ADDR,
	PMIC_OTP_46_R_ADDR,
	PMIC_OTP_47_R_ADDR,
	PMIC_OTP_48_R_ADDR,
	PMIC_OTP_49_R_ADDR,
	PMIC_OTP_50_R_ADDR,
	PMIC_OTP_51_R_ADDR,
	PMIC_OTP_52_R_ADDR,
	PMIC_OTP_53_R_ADDR,
	PMIC_OTP_54_R_ADDR,
	PMIC_OTP_55_R_ADDR,
	PMIC_OTP_56_R_ADDR,
	PMIC_OTP_57_R_ADDR,
	PMIC_OTP_58_R_ADDR,
	PMIC_OTP_59_R_ADDR,
	PMIC_OTP_60_R_ADDR
};

/*Hisi dieit test*/
enum  hisi_ap_dieid_test{
	HISI_SOC_DIEID = 1,
	HISI_MAIN_PMU_DIEID,
	HISI_SUB_PMU_DIEID,
	HISI_AP_DIEID
};


static int get_hi6423_dieid(unsigned char *die_id)
{
	int i;
	unsigned char val = 0, id_reg = ID_OTP_0;

	/*clock open */
	hisi_pmic_write_sub_pmu(HI6423_SID, ID_OTP_CLK_CTRL, OPEN_CLK_VALUE);

	/* step1 : set id_otp_ptm = 2'b00, id_otp_pprog = 1'b0, enter in read mode*/
	val = hisi_pmic_read_sub_pmu(HI6423_SID, ID_OTP_CTRL1);
	val = val & AND_VALUE1;
	hisi_pmic_write_sub_pmu(HI6423_SID, ID_OTP_CTRL1, val);

	/* step2 : set id_otp_pa = 2'b00, address writed to register*/
	val = hisi_pmic_read_sub_pmu(HI6423_SID, ID_OTP_CTRL1);
	val = val & AND_VALUE3;
	hisi_pmic_write_sub_pmu(HI6423_SID, ID_OTP_CTRL1, val);

	/* step3 : set id_por_int = 1'b1, enable read mode*/
	val = hisi_pmic_read_sub_pmu(HI6423_SID, ID_OTP_CTRL0);
	val = (val & AND_VALUE2) | 0x4;
	hisi_pmic_write_sub_pmu(HI6423_SID, ID_OTP_CTRL0, val);

	/* step4 : delay 30us, then set id_otp_por_int = 1'b0 to cancel the read mode enable signal */
	udelay(DELAY_TIME);
	val = hisi_pmic_read_sub_pmu(HI6423_SID, ID_OTP_CTRL0);
	val = val & AND_VALUE2;
	hisi_pmic_write_sub_pmu(HI6423_SID, ID_OTP_CTRL0, val);

	/* step5 : read from registers ID_OTP_0~3*/
	for (i = 0; i < HI6423_READ_TIMES; i++) {
		*die_id = hisi_pmic_read_sub_pmu(HI6423_SID, id_reg);
		id_reg++;
		die_id++;
	}

	/*clock close */
	hisi_pmic_write_sub_pmu(HI6423_SID, ID_OTP_CLK_CTRL, RESET_VALUE);

	return 0;
}


static int get_hi6422_dieid(unsigned char *die_id)
{
	int i;
	unsigned char val = 0, otp_reg = OTP_REG_BEGIN, id_reg = OTP_119_112, rst_reg = OTP_CLK_CTRL;

	/*step1 : set register-controlled read mode*/
	val = hisi_pmic_read_sub_pmu(HI6422_SID, OTP_CTRL1);
	val = (val & AND_VALUE4) | 0x02;
	hisi_pmic_write_sub_pmu(HI6422_SID, OTP_CTRL1, val);

	/*step2 : open clock*/
	hisi_pmic_write_sub_pmu(HI6422_SID, OTP_CLK_CTRL, OPEN_CLK_VALUE);

	/*step3 : set Normal Read mode*/
	val = hisi_pmic_read_sub_pmu(HI6422_SID, OTP_CTRL2);
	val = val & AND_VALUE5;
	hisi_pmic_write_sub_pmu(HI6422_SID, OTP_CTRL2, val);

	/*step4 : set address in Normal Read mode from bit[119:112] to [175:168]*/
	for (i = 0; i < HI6422_READ_TIMES; i++) {
		val = hisi_pmic_read_sub_pmu(HI6422_SID, OTP_CTRL2);
		val = (val & AND_VALUE6) | otp_reg;
		hisi_pmic_write_sub_pmu(HI6422_SID, OTP_CTRL2, val);
		otp_reg = otp_reg + 2;

		/*step5 : enable read*/
		val = hisi_pmic_read_sub_pmu(HI6422_SID, OTP_CTRL0);
		val = (val & AND_VALUE2) | 0x04;
		hisi_pmic_write_sub_pmu(HI6422_SID, OTP_CTRL0, val);

		/*step6 : rescind read_enable signal*/
		udelay(DELAY_TIME);
		val = hisi_pmic_read_sub_pmu(HI6422_SID, OTP_CTRL0);
		val = val & AND_VALUE2;
		hisi_pmic_write_sub_pmu(HI6422_SID, OTP_CTRL0, val);
	}

	/*step7 : check out data*/
	for (i = 0; i < HI6422_READ_TIMES; i++) {
		*die_id = hisi_pmic_read_sub_pmu(HI6422_SID, id_reg);
		id_reg++;
		die_id++;
	}

	/*step8 : reset registers to default value*/
	for (i = 0; i < RST_REG_NUM; i++) {
		hisi_pmic_write_sub_pmu(HI6422_SID, rst_reg, RESET_VALUE);
		rst_reg++;
	}

	return 0;
}

static int hisi_subpmu_get_dieid(char *dieid)
{
	int ret = 0;
	unsigned char ip[HISI_PMU_IP_SIZE] = {0};
	char  pmu2_buf[HISI_PMU_BUF_SIZE]={0};
	char  pmu3_buf[HISI_PMU_BUF_SIZE]={0};

	ret = get_hi6422_dieid(ip);
	if (ret){
		pr_err("%s:get_hi6422_dieid_fail!\n",__func__);
	}

	ret = snprintf(pmu2_buf,sizeof(pmu2_buf),"\r\nHi6422_PMU2:0x%02x%02x%02x%02x%02x%02x%02x%02x\r\n",
				ip[7], ip[6], ip[5], ip[4], ip[3], ip[2], ip[1], ip[0]);
	if(ret <0){
		pr_err("%s:snprintf_s is error!\n", __func__);
	}

	memset(ip,0,HISI_PMU_IP_SIZE);
	ret = get_hi6423_dieid(ip);
	if (ret){
		pr_err("%s:get_hi6423_dieid_fail!\n",__func__);
	}

	ret = snprintf(pmu3_buf,sizeof(pmu3_buf),"\r\nHi6423_PMU3:0x%02x%02x%02x%02x%02x%02x%02x%02x\r\n",
				ip[7], ip[6], ip[5], ip[4], ip[3], ip[2], ip[1], ip[0]);
	if(ret <0){
		pr_err("%s:snprintf_s is error!\n", __func__);
	}

	strncat(dieid,pmu2_buf,strlen(pmu2_buf));
	strncat(dieid,pmu3_buf,strlen(pmu3_buf));
	printk(KERN_ERR "%s:sub pmu diedi is %s\n", __func__, dieid);

	return ret;
}

static int hisi_pmic_get_dieid(char *dieid)
{
	int ret = 0;
	unsigned char ip[HISI_MAIN_PMU_IP_SIZE] = {0};
	char  pmu_buf[HISI_PMU_BUF_SIZE] ={0};

	ip[0] = hisi_pmic_reg_read(PMIC_OTP_44_R_ADDR);
	ip[1] = hisi_pmic_reg_read(PMIC_OTP_45_R_ADDR);
	ip[2] = hisi_pmic_reg_read(PMIC_OTP_46_R_ADDR);
	ip[3] = hisi_pmic_reg_read(PMIC_OTP_47_R_ADDR);
	ip[4] = hisi_pmic_reg_read(PMIC_OTP_48_R_ADDR);
	ip[5] = hisi_pmic_reg_read(PMIC_OTP_49_R_ADDR);
	ip[6] = hisi_pmic_reg_read(PMIC_OTP_50_R_ADDR);
	ip[7] = hisi_pmic_reg_read(PMIC_OTP_51_R_ADDR);
	ip[8] = hisi_pmic_reg_read(PMIC_OTP_52_R_ADDR);
	ip[9] = hisi_pmic_reg_read(PMIC_OTP_53_R_ADDR);
	ip[10] = hisi_pmic_reg_read(PMIC_OTP_54_R_ADDR);
	ip[11] = hisi_pmic_reg_read(PMIC_OTP_55_R_ADDR);
	ip[12] = hisi_pmic_reg_read(PMIC_OTP_56_R_ADDR);
	ip[13] = hisi_pmic_reg_read(PMIC_OTP_57_R_ADDR);
	ip[14] = hisi_pmic_reg_read(PMIC_OTP_58_R_ADDR);
	ip[15] = hisi_pmic_reg_read(PMIC_OTP_59_R_ADDR);
	ip[16] = hisi_pmic_reg_read(PMIC_OTP_60_R_ADDR);

	ret = snprintf(pmu_buf,sizeof(pmu_buf),
				"\r\nHi6421_PMU1:0x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\r\n",
					ip[0],ip[1],ip[2],ip[3],ip[4],ip[5],ip[6],ip[7],
					ip[8],ip[9],ip[10],ip[11],ip[12],ip[13],ip[14],ip[15],ip[16]);
	if(ret <0){
		pr_err("%s:snprintf_s is error!\n", __func__);
	}

	strncat(dieid,pmu_buf,strlen(pmu_buf));
	printk(KERN_ERR "%s:main pmu dieid is %s\n", __func__, dieid);
	return ret;
}

static int hisi_soc_get_dieid(char *dieid)
{
	int ret = 0;
	unsigned char  ip[HISI_SOC_IP_SIZE] = {0};
	char  soc_buf[HISI_SOC_BUF_SIZE]={0};

	ret = get_efuse_dieid_value(ip, sizeof(ip), HISI_DIEID_TIMEOUT_1000MS);
	if (OK != ret){
		pr_err("%s: %d: get_efuse_dieid_value failed,ret=%d\n", __func__, __LINE__, ret);
	}
	ret = snprintf(soc_buf,sizeof(soc_buf),
				"\r\nHi3670_SOC:0x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\r\n",
				ip[19],ip[18],ip[17],ip[16],ip[15],ip[14],ip[13],ip[12],
				ip[11],ip[10],ip[9],ip[8],ip[7],ip[6],ip[5],ip[4],
	    			ip[3],ip[2],ip[1],ip[0]);
	if(ret <0){
		pr_err("%s:snprintf_s is error!\n", __func__);
	}

	strncat(dieid,soc_buf,strlen(soc_buf));

	printk(KERN_ERR "%s:soc dieid  is %s\n", __func__, dieid);
	return ret;
}

static int hisi_ap_get_dieid(char *dieid)
{
	int ret = 0;
	char  dieid_buf[HISI_SOC_BUF_SIZE] ={0};

	ret = hisi_soc_get_dieid(dieid_buf);
	if(ret<0){
		pr_err("%s:hisi_soc_get_dieid is error!\n", __func__);
	}
	strncat(dieid,dieid_buf,strlen(dieid_buf));

	memset(dieid_buf,0,sizeof(dieid_buf));
	ret = hisi_pmic_get_dieid(dieid_buf);
	if(ret<0){
		pr_err("%s:hisi_pmic_get_dieid is error!\n", __func__);
	}
	strncat(dieid,dieid_buf,strlen(dieid_buf));

	memset(dieid_buf,0,sizeof(dieid_buf));
	ret = hisi_subpmu_get_dieid(dieid_buf);
	if(ret<0){
		 pr_err("%s:hisi_pmic_get_dieid is error!\n", __func__);
	}
	strncat(dieid,dieid_buf,strlen(dieid_buf));

	printk(KERN_ERR "%s:end cmd line is %s\n", __func__, dieid);
	return ret;
}

int hisi_ap_get_dieid_test(int cmd)
{
	int ret = 0;
	char  dieid[HISI_SOC_BUF_SIZE] = {0};
	char  ap_dieid[HISI_AP_DIEID_BUF_SIZE] = {0};
	switch (cmd){
		case HISI_SOC_DIEID:
			memset(dieid,0,HISI_SOC_BUF_SIZE);
			hisi_soc_get_dieid(dieid);
			printk(KERN_ERR "%s:testsoc dieid is %s\n", __func__, dieid);
		break;
		case HISI_MAIN_PMU_DIEID:
			memset(dieid,0,HISI_SOC_BUF_SIZE);
			hisi_pmic_get_dieid(dieid);
			printk(KERN_ERR "%s:test main pmu dieid is %s\n", __func__, dieid);
		break;
		case HISI_SUB_PMU_DIEID:
			memset(dieid,0,HISI_SOC_BUF_SIZE);
			hisi_subpmu_get_dieid(dieid);
			printk(KERN_ERR "%s:test sub pmu dieid is %s\n", __func__, dieid);
		break;
		case HISI_AP_DIEID:
			memset(ap_dieid,0,HISI_AP_DIEID_BUF_SIZE);
			hisi_ap_get_dieid(ap_dieid);
			printk(KERN_ERR "%s:test sub pmu dieid is %s\n", __func__, ap_dieid);
		break;
		default:
			printk(KERN_ERR "%s:test cmd:%d is error.\n", __func__, cmd);
			ret = -EFAULT;
		break;
	}
	return ret;
}

/*
 * Function name:dieid_ioctl.
 * Discription:complement read/write dieid by terms of sending command-words.
 * return value:
 *          @ 0 - success.
 *          @ -1- failure.
 */
static long dieid_ioctl(struct file *file, u_int cmd, u_long arg)
{
	int ret = 0;
	void __user *argp = (void __user *)arg;
	char ap_buffer[HISI_AP_DIEID_BUF_SIZE] = {0};
	int  buf_length =  0;

	pr_info("%s: %d: cmd=0x%x.\n", __func__, __LINE__, cmd);

	if (!arg) {
		ret = -EFAULT;
		return ret;
	}
	switch(cmd){
		case HISI_DIEID_READ_DIEID:
			ret = hisi_ap_get_dieid(ap_buffer);
			if(ret<0){
				pr_err("%s:hisi_pmic_get_dieid is error!\n", __func__);
			}
			buf_length = strlen(ap_buffer)+1;
			if(buf_length > HISI_AP_DIEID_BUF_SIZE){
				/*send back to user*/
				if (copy_to_user(argp, ap_buffer, HISI_AP_DIEID_BUF_SIZE))
				{
					ret = -EFAULT;
				}
			}
			else{
				/*send back to user*/
				if (copy_to_user(argp, ap_buffer, strlen(ap_buffer)+1))
				{
					ret = -EFAULT;
				}
			}

			break;
		default:
			pr_info("[DIEID][%s] Unknow command!\n", __func__);
			ret = -ENOTTY;
			break;
	}

	return ret;
}

static const struct file_operations hisi_dieid_fops = {
	.owner =	THIS_MODULE,
	.unlocked_ioctl = dieid_ioctl,
};

static int dieid_major = 0;
static struct class  *dieid_class;

static int __init hisi_dieid_init(void)
{
	int ret = 0;
	struct device *pdevice;
	dieid_major = register_chrdev(0, HISI_DIEID_DEV_NAME, &hisi_dieid_fops);
	if (dieid_major <= 0)
	{
		ret = -EFAULT;
		pr_err("hisi dieid: unable to get dieid_major for memory devs.\n");
		return ret;
	}

	dieid_class = class_create(THIS_MODULE, HISI_DIEID_DEV_NAME);
	if (IS_ERR(dieid_class))
	{
		ret = -EFAULT;
		pr_err("hisi dieid: class_create error.\n");
		goto error1;
	}

	pdevice = device_create(dieid_class, NULL, MKDEV(dieid_major, 0), NULL, HISI_DIEID_DEV_NAME);
	if (IS_ERR(pdevice))
	{
		ret = -EFAULT;
		pr_err("hisi dieid: device_create error.\n");
		goto error2;
	}

	return ret;

error2:
	class_destroy(dieid_class);
error1:
	unregister_chrdev(dieid_major, HISI_DIEID_DEV_NAME);
	return ret;
}

static void __exit hisi_dieid_exit(void)
{
	device_destroy(dieid_class, MKDEV(dieid_major, 0));
	class_destroy(dieid_class);
	unregister_chrdev(dieid_major, HISI_DIEID_DEV_NAME);
}

late_initcall_sync(hisi_dieid_init);
module_exit(hisi_dieid_exit);

MODULE_DESCRIPTION("Hisilicon dieid module");
MODULE_AUTHOR("lishaoqiang1@hisilicon.com");
MODULE_LICENSE("GPL");

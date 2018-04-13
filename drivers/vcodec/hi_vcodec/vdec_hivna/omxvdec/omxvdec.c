/*
 * vdec driver interface
 *
 * Copyright (c) 2017 Hisilicon Limited
 *
 * Author: gaoyajun<gaoyajun@hisilicon.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation.
 *
 */

#include <linux/clk.h>
#include <linux/of.h>
#include <linux/io.h>

#include "omxvdec.h"
#include "linux_kernel_osal.h"
#include "vfmw_dts.h"
#include "scd_drv.h"
#include "vdm_drv.h"
#include "vfmw_intf.h"
/*lint -e774*/

#define PCTRL_PERI              (0xE8A090A4)
#define PCTRL_PERI_SATA0        (0xE8A090BC)

static HI_S32 gIsNormalInit = 0;

static HI_BOOL       gIsDeviceDetected  = HI_FALSE;
static struct class *g_OmxVdecClass     = HI_NULL;
static const HI_CHAR g_OmxVdecDrvName[] = OMXVDEC_NAME;
static dev_t         g_OmxVdecDevNum;
static OMXVDEC_ENTRY g_OmxVdecEntry;
static VDEC_MEM_INFO g_VdecMapInfo[MAX_OPEN_COUNT];

//Modified for 64-bit platform
typedef enum {
	T_IOCTL_ARG,
	T_IOCTL_ARG_COMPAT,
	T_BUTT,
} COMPAT_TYPE_E;

typedef enum {
	KIRIN_970_ES,
	KIRIN_970_CS,
	KIRIN_980,
	KIRIN_BUTT,
} KIRIN_PLATFORM_E;

#define CHECK_PARA_SIZE_RETURN(size, para_size, command)                 \
do {                                                                     \
	if (size != para_size) {                                         \
		dprint(PRN_FATAL, "%s: prarameter_size is error\n", command); \
		return -EINVAL;                                             \
	}                                                                \
}while(0)

#define CHECK_RETURN(cond, else_print)                                    \
do {                                                                     \
	if (!(cond)) {                                                    \
		dprint(PRN_FATAL, "%s : %s\n", __func__, else_print);    \
		return -EINVAL;                                          \
	}                                                                \
}while(0)

#define CHECK_SCENE_EQ_RETURN(cond, else_print)                                    \
do {                                                                     \
	if (cond) {                                                    \
		dprint(PRN_ALWS, "%s : %s\n", __func__, else_print);    \
		return -EIO;                                          \
	}                                                                \
}while(0)
/* get fd index */
static HI_S32 omxvdec_get_file_index(struct file *file)
{
	HI_S32 index;
	for (index = 0; index < MAX_OPEN_COUNT; index++) {
		if ((g_VdecMapInfo[index].file != HI_NULL) && (file == g_VdecMapInfo[index].file))
			break;
	}
	if (index == MAX_OPEN_COUNT) {
		dprint(PRN_FATAL, "%s this file is not exist \n", __func__);
		return HI_FAILURE;
	}
	return index;
}

static HI_S32 omxvdec_setup_cdev(OMXVDEC_ENTRY *omxvdec, const struct file_operations *fops)
{
	HI_S32 rc;
	struct device *dev;

	g_OmxVdecClass = class_create(THIS_MODULE, "omxvdec_class");
	if (IS_ERR(g_OmxVdecClass)) {
		rc = PTR_ERR(g_OmxVdecClass);
		g_OmxVdecClass = HI_NULL;
		dprint(PRN_FATAL, "%s call class_create failed, rc : %d\n", __func__, rc);
		return rc;
	}

	rc = alloc_chrdev_region(&g_OmxVdecDevNum, 0, 1, "hisi video decoder");
	if (rc) {
		dprint(PRN_FATAL, "%s call alloc_chrdev_region failed, rc : %d\n", __func__, rc);
		goto cls_destroy;
	}

	dev = device_create(g_OmxVdecClass, NULL, g_OmxVdecDevNum, NULL, OMXVDEC_NAME);
	if (IS_ERR(dev)) {
		rc = PTR_ERR(dev);
		dprint(PRN_FATAL, "%s call device_create failed, rc : %d\n", __func__, rc);
		goto unregister_region;
	}

	cdev_init(&omxvdec->cdev, fops);
	omxvdec->cdev.owner = THIS_MODULE;
	omxvdec->cdev.ops = fops;
	rc = cdev_add(&omxvdec->cdev, g_OmxVdecDevNum, 1);
	if (rc < 0) {
		dprint(PRN_FATAL, "%s call cdev_add failed, rc : %d\n", __func__, rc);
		goto dev_destroy;
	}

	return HI_SUCCESS;

dev_destroy:
	device_destroy(g_OmxVdecClass, g_OmxVdecDevNum);
unregister_region:
	unregister_chrdev_region(g_OmxVdecDevNum, 1);
cls_destroy:
	class_destroy(g_OmxVdecClass);
	g_OmxVdecClass = HI_NULL;

	return rc;
}

static HI_S32 omxvdec_cleanup_cdev(OMXVDEC_ENTRY *omxvdec)
{
	if (!g_OmxVdecClass) {
		dprint(PRN_FATAL, "%s: Invalid g_OmxVdecClass is NULL", __func__);
		return HI_FAILURE;
	}

	cdev_del(&omxvdec->cdev);
	device_destroy(g_OmxVdecClass, g_OmxVdecDevNum);
	unregister_chrdev_region(g_OmxVdecDevNum, 1);
	class_destroy(g_OmxVdecClass);
	g_OmxVdecClass = HI_NULL;

	return HI_SUCCESS;
}

static HI_S32 omxvdec_open(struct inode *inode, struct file *file)
{
	HI_S32 ret = -EBUSY;
	OMXVDEC_ENTRY *omxvdec = HI_NULL;
	HI_S32 index;

	omxvdec = container_of(inode->i_cdev, OMXVDEC_ENTRY, cdev);

	VDEC_MUTEX_LOCK(&omxvdec->omxvdec_mutex);
	VDEC_MUTEX_LOCK(&omxvdec->vdec_mutex_scd);
	VDEC_MUTEX_LOCK(&omxvdec->vdec_mutex_vdh);

	if (omxvdec->open_count < MAX_OPEN_COUNT) {
		omxvdec->open_count++;
		if (omxvdec->open_count == 1) {
			ret = VDEC_MEM_Init();
			if (ret != HI_SUCCESS)
			{
				dprint(PRN_FATAL, "%s : init ion mem failed\n", __func__);
				goto error0;
			}
			ret = VDEC_Regulator_Enable();
			if (ret != HI_SUCCESS) {
				dprint(PRN_FATAL, "%s : VDEC_Regulator_Enable failed\n", __func__);
				goto error1;
			}
			ret = VCTRL_OpenVfmw();
			if (ret != HI_SUCCESS) {
				dprint(PRN_FATAL, "%s : vfmw open failed\n", __func__);
				goto error2;
			}
			gIsNormalInit = 1;
		}
		/* save file */
		for (index = 0; index < MAX_OPEN_COUNT; index++)
		{
			if (g_VdecMapInfo[index].file == HI_NULL)
				break;
		}
		if (index == MAX_OPEN_COUNT)
		{
			dprint(PRN_FATAL, "%s : in Map Info, open too much\n", __func__);
			ret = -EBUSY;
			goto exit;
		}
		g_VdecMapInfo[index].file = file;

		file->private_data = omxvdec;
		ret = HI_SUCCESS;
	} else {
		dprint(PRN_FATAL,  "%s open omxvdec instance too much\n", __func__);
		ret = -EBUSY;
	}

	dprint(PRN_ALWS, "%s, open_count : %d\n", __func__, omxvdec->open_count);
	goto exit;

error2:
	(HI_VOID)VDEC_Regulator_Disable();
error1:
	(HI_VOID)VDEC_MEM_Exit();
error0:
	omxvdec->open_count--;
exit:
	VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_vdh);
	VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_scd);
	VDEC_MUTEX_UNLOCK(&omxvdec->omxvdec_mutex);

	return ret;
}

static HI_S32 omxvdec_release(struct inode *inode, struct file *file)
{
	OMXVDEC_ENTRY *omxvdec = HI_NULL;
	HI_S32 ret = HI_SUCCESS;
	HI_S32 index;

	omxvdec = file->private_data;
	if (omxvdec == HI_NULL) {
		dprint(PRN_FATAL,  "%s: invalid omxvdec is null\n", __func__);
		return -EFAULT;
	}

	VDEC_MUTEX_LOCK(&omxvdec->omxvdec_mutex);
	VDEC_MUTEX_LOCK(&omxvdec->vdec_mutex_scd);
	VDEC_MUTEX_LOCK(&omxvdec->vdec_mutex_vdh);

	if (file->private_data == HI_NULL) {
		dprint(PRN_FATAL, "%s: invalid file->private_data is null\n", __func__);
		ret = -EFAULT;
		goto exit;
	}
	/* release file info */
	index = omxvdec_get_file_index(file);
	if (index == HI_FAILURE) {
		dprint(PRN_FATAL, "%s file is not open\n", __func__);
		ret = -EFAULT;
		goto exit;
	}
	if (omxvdec->open_count > 0)
		omxvdec->open_count--;

	if (omxvdec->open_count == 0) {
#ifdef MSG_POOL_ADDR_CHECK
		VCTRL_VDHUnmapMessagePool(&(omxvdec->com_msg_pool));
		memset(&(omxvdec->com_msg_pool), 0, sizeof(omxvdec->com_msg_pool)); /* unsafe_function_ignore: memset */
#endif
		VCTRL_CloseVfmw();
		VDEC_Regulator_Disable();
		VDEC_MEM_Exit();
		gIsNormalInit = 0;
	}
	memset(&g_VdecMapInfo[index], 0, sizeof(g_VdecMapInfo[index])); /* unsafe_function_ignore: memset */
	file->private_data = HI_NULL;

	dprint(PRN_ALWS, "exit %s , open_count : %d\n", __func__, omxvdec->open_count);
exit:
	VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_vdh);
	VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_scd);
	VDEC_MUTEX_UNLOCK(&omxvdec->omxvdec_mutex);

	return ret;
}

/* Modified for 64-bit platform */
static HI_S32 omxvdec_compat_get_data(COMPAT_TYPE_E eType, HI_VOID __user *pUser, HI_VOID *pData)
{
	HI_S32 ret = HI_SUCCESS;
	HI_S32 s32Data = 0;
	compat_ulong_t CompatData = 0;
	OMXVDEC_IOCTL_MSG *pIoctlMsg = (OMXVDEC_IOCTL_MSG *)pData;

	if (HI_NULL == pUser || HI_NULL == pData) {
		dprint(PRN_FATAL, "%s: param is null\n", __func__);
		return HI_FAILURE;
	}

	switch (eType) {
	case T_IOCTL_ARG:
		if (copy_from_user(pIoctlMsg, pUser, sizeof(*pIoctlMsg))) {
			dprint(PRN_FATAL, "%s puser copy failed\n", __func__);
			ret = HI_FAILURE;
		}
		break;
	case T_IOCTL_ARG_COMPAT: {
		COMPAT_IOCTL_MSG __user *pCompatMsg = pUser;

		ret |= get_user(s32Data, &(pCompatMsg->chan_num));
		pIoctlMsg->chan_num = s32Data;

		ret |= get_user(s32Data, &(pCompatMsg->in_size));
		pIoctlMsg->in_size = s32Data;

		ret |= get_user(s32Data, &(pCompatMsg->out_size));
		pIoctlMsg->out_size = s32Data;

		ret |= get_user(CompatData, &(pCompatMsg->in));
		pIoctlMsg->in   = (HI_VOID *) ((HI_VIRT_ADDR_T)CompatData);

		ret |= get_user(CompatData, &(pCompatMsg->out));
		pIoctlMsg->out = (HI_VOID *) ((HI_VIRT_ADDR_T)CompatData);
	}
		break;
	default:
		dprint(PRN_FATAL, "%s: unkown type %d\n", __func__, eType);
		ret = HI_FAILURE;
		break;
	}

	return ret;
}

static long omxvdec_ioctl_common(struct file *file, unsigned int cmd, unsigned long arg, COMPAT_TYPE_E type)
{
	HI_S32 ret;
	HI_BOOL x_scene;
	OMXVDEC_IOCTL_MSG  vdec_msg;
	HI_VOID           *u_arg   = (HI_VOID *)arg;
	OMXVDEC_ENTRY     *omxvdec = file->private_data;

	CLK_RATE_E        clk_rate;
	OMXSCD_REG_CFG_S  scd_reg_cfg;
	SCD_STATE_REG_S   scd_state_reg;
	OMXVDH_REG_CFG_S  vdm_reg_cfg;
	VDMHAL_BACKUP_S   vdm_state_reg;
	HI_S32            vdm_is_run;
	HI_S32            fd_index;

	x_scene = VCTRL_Scen_Ident(cmd);
	CHECK_SCENE_EQ_RETURN(x_scene == HI_TRUE, "xxx scene");

	CHECK_RETURN(omxvdec != HI_NULL, "omxvdec is null");

	ret = omxvdec_compat_get_data(type, u_arg, &vdec_msg);
	CHECK_RETURN(ret == HI_SUCCESS, "compat data get failed");

	switch (cmd) {
	case VDEC_IOCTL_SET_CLK_RATE:
		CHECK_PARA_SIZE_RETURN(sizeof(clk_rate), vdec_msg.in_size, "VDEC_IOCTL_SET_CLK_RATE");
		if (copy_from_user(&clk_rate, vdec_msg.in, sizeof(clk_rate))) {
			dprint(PRN_FATAL, "VDEC_IOCTL_SET_CLK_RATE : copy_from_user failed\n");
			return -EFAULT;
		}

		VDEC_MUTEX_LOCK(&omxvdec->omxvdec_mutex);
		VDEC_MUTEX_LOCK(&omxvdec->vdec_mutex_scd);
		VDEC_MUTEX_LOCK(&omxvdec->vdec_mutex_vdh);
		fd_index = omxvdec_get_file_index(file);
		if (fd_index == HI_FAILURE) {
			dprint(PRN_FATAL, "%s file is wrong\n", __func__);
			VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_vdh);
			VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_scd);
			VDEC_MUTEX_UNLOCK(&omxvdec->omxvdec_mutex);
			return -EIO;
		}
		if (VDEC_Regulator_SetClkRate(clk_rate) != HI_SUCCESS) {
			dprint(PRN_FATAL, "VDEC_Regulator_SetClkRate faied\n");
			VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_vdh);
			VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_scd);
			VDEC_MUTEX_UNLOCK(&omxvdec->omxvdec_mutex);
			return HI_FAILURE;
		}
		VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_vdh);
		VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_scd);
		VDEC_MUTEX_UNLOCK(&omxvdec->omxvdec_mutex);
		break;

	case VDEC_IOCTL_VDM_PROC:
		CHECK_PARA_SIZE_RETURN(sizeof(vdm_reg_cfg), vdec_msg.in_size, "VDEC_IOCTL_VDM_PROC_IN");
		CHECK_PARA_SIZE_RETURN(sizeof(vdm_state_reg), vdec_msg.out_size, "VDEC_IOCTL_VDM_PROC_OUT");
		if (copy_from_user(&vdm_reg_cfg, vdec_msg.in, sizeof(vdm_reg_cfg))) {
			dprint(PRN_FATAL, "VDEC_IOCTL_VDM_PROC : copy_from_user failed\n");
			return -EFAULT;
		}

		VDEC_MUTEX_LOCK(&omxvdec->vdec_mutex_vdh);
		fd_index = omxvdec_get_file_index(file);
		if (fd_index == HI_FAILURE) {
			dprint(PRN_FATAL, "%s file is wrong\n", __func__);
			VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_vdh);
			return -EIO;
		}

		dsb(sy);

		ret = VCTRL_VDMHal_Process(&vdm_reg_cfg, &vdm_state_reg,
					&(g_VdecMapInfo[fd_index].vdh[0]), &(omxvdec->com_msg_pool));
		if (ret != HI_SUCCESS) {
			dprint(PRN_FATAL, "VCTRL_VDMHal_Process failed\n");
			VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_vdh);
			return -EIO;
		}

		VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_vdh);
		if (copy_to_user(vdec_msg.out, &vdm_state_reg, sizeof(vdm_state_reg))) {
			dprint(PRN_FATAL, "VDEC_IOCTL_VDM_PROC : copy_to_user failed\n");
			return -EFAULT;
		}
		break;

	case VDEC_IOCTL_GET_VDM_HWSTATE:
		CHECK_PARA_SIZE_RETURN(sizeof(vdm_is_run), vdec_msg.out_size, "VDEC_IOCTL_GET_VDM_HWSTATE");
		VDEC_MUTEX_LOCK(&omxvdec->vdec_mutex_vdh);
		fd_index = omxvdec_get_file_index(file);
		if (fd_index == HI_FAILURE) {
			dprint(PRN_FATAL, "%s file is wrong\n", __func__);
			VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_vdh);
			return -EIO;
		}
		vdm_is_run = VCTRL_VDMHAL_IsRun();

		VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_vdh);
		if (copy_to_user(vdec_msg.out, &vdm_is_run, sizeof(vdm_is_run))) {
			dprint(PRN_FATAL, "VDEC_IOCTL_GET_VDM_HWSTATE : copy_to_user failed\n");
			return -EFAULT;
		}
		break;

	case VDEC_IOCTL_SCD_PROC:
		CHECK_PARA_SIZE_RETURN(sizeof(scd_reg_cfg), vdec_msg.in_size, "VDEC_IOCTL_SCD_PROC_IN");
		CHECK_PARA_SIZE_RETURN(sizeof(scd_state_reg), vdec_msg.out_size, "VDEC_IOCTL_SCD_PROC_OUT");
		if (copy_from_user(&scd_reg_cfg, vdec_msg.in, sizeof(scd_reg_cfg))) {
			dprint(PRN_FATAL, "VDEC_IOCTL_SCD_PROC :  copy_from_user failed\n");
			return -EFAULT;
		}

		VDEC_MUTEX_LOCK(&omxvdec->vdec_mutex_scd);
		fd_index = omxvdec_get_file_index(file);
		if (fd_index == HI_FAILURE) {
			dprint(PRN_FATAL, "%s file is wrong\n", __func__);
			VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_scd);
			return -EIO;
		}

		dsb(sy);

		ret = VCTRL_SCDHal_Process(&scd_reg_cfg, &scd_state_reg, &(g_VdecMapInfo[fd_index].scd[0]));
		if (ret != HI_SUCCESS) {
			dprint(PRN_FATAL, "VCTRL_SCDHal_Process failed\n");
			VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_scd);
			return -EIO;
		}

		VDEC_MUTEX_UNLOCK(&omxvdec->vdec_mutex_scd);
		if (copy_to_user(vdec_msg.out, &scd_state_reg, sizeof(scd_state_reg))) {
			dprint(PRN_FATAL, "VDEC_IOCTL_SCD_PROC : copy_to_user failed\n");
			return -EFAULT;
		}
		break;

	default:
		/* could not handle ioctl */
		dprint(PRN_FATAL, "%s %d:  cmd : %d is not supported\n", __func__, __LINE__, _IOC_NR(cmd));
		return -ENOTTY;
	}

	return 0;
}

static long omxvdec_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	return omxvdec_ioctl_common(file, cmd, arg, T_IOCTL_ARG);
}
/* Modified for 64-bit platform */
#ifdef CONFIG_COMPAT
static long omxvdec_compat_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	void *user_ptr = compat_ptr(arg);
	return  omxvdec_ioctl_common(file, cmd, (unsigned long)user_ptr, T_IOCTL_ARG_COMPAT);
}
#endif

static const struct file_operations omxvdec_fops = {
	.owner          = THIS_MODULE,
	.open           = omxvdec_open,
	.unlocked_ioctl = omxvdec_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl   = omxvdec_compat_ioctl,
#endif
	.release        = omxvdec_release,
};

static HI_BOOL omxvdec_device_idle(KIRIN_PLATFORM_E plt_frm)
{
	HI_S32 idle   = 0;
	HI_U32 *pctrl = HI_NULL;

	switch(plt_frm) {
	case KIRIN_970_ES :
		pctrl  = (HI_U32 *)ioremap(PCTRL_PERI, 4);
		if (pctrl)
			idle = readl(pctrl) & 0x4;
		break;
	case KIRIN_970_CS :
		pctrl  = (HI_U32 *)ioremap(PCTRL_PERI_SATA0, 4);
		if (pctrl)
			idle = readl(pctrl) & 0x40000; //b[18]
		break;
	case KIRIN_980 :
		pctrl  = (HI_U32 *)ioremap(PCTRL_PERI_SATA0, 4);
		if (pctrl)
			idle = readl(pctrl) & 0x40000; //b[18]
		break;
	default :
		dprint(PRN_ERROR,  "unkown platform %d\n", plt_frm);
		break;
	};

	if (!pctrl) {
		dprint(PRN_ERROR,  "ioremap failed\n");
		return HI_FALSE;
	}

	iounmap(pctrl);
	pctrl = HI_NULL;
	return ((idle != 0) ? HI_TRUE : HI_FALSE); /* [false alarm] */
}

static HI_S32 omxvdec_probe(struct platform_device *pltdev)
{
	HI_S32 ret;

#ifdef PLATFORM_KIRIN980
	HI_U32 fpga_es = 0;
	struct device *dev = &pltdev->dev;

	of_property_read_u32(dev->of_node, "fpga_flag_es", &fpga_es);
	if (fpga_es == 1) {
		dprint(PRN_ALWS, "Atlanta es fpga\n");
		if (omxvdec_device_idle(KIRIN_980) == HI_FALSE) {
			dprint(PRN_ERROR,  "vdec is not exist\n");
			return HI_FAILURE;
		}
	} else {
		dprint(PRN_ALWS, "not Atlanta es fpga\n");
	}
#endif

#ifdef PLATFORM_KIRIN970
	HI_U32 fpga_cs = 0;
	HI_U32 fpga_es = 0;
	struct device *dev = &pltdev->dev;

	of_property_read_u32(dev->of_node, "fpga_flag_es", &fpga_es);
	of_property_read_u32(dev->of_node, "fpga_flag_cs", &fpga_cs);
	if (fpga_es == 1) {
		dprint(PRN_ALWS, "boston es fpga\n");
		if (omxvdec_device_idle(KIRIN_970_ES) == HI_FALSE) {
			dprint(PRN_ERROR,  "vdec is not exist\n");
			return HI_FAILURE;
		}
	} else if (fpga_cs == 1) {
		dprint(PRN_ALWS, "boston cs fpga\n");
		if (omxvdec_device_idle(KIRIN_970_CS) == HI_FALSE) {
			dprint(PRN_ERROR,  "vdec is not exist\n");
			return HI_FAILURE;
		}
	} else {
		dprint(PRN_ALWS, "not boston cs/es fpga\n");
	}
#endif

	if (gIsDeviceDetected == HI_TRUE) {
		dprint(PRN_DBG, "Already probe omxvdec\n");
		return 0;
	}

	platform_set_drvdata(pltdev, HI_NULL);

	memset(&g_OmxVdecEntry, 0, sizeof(OMXVDEC_ENTRY)); /* unsafe_function_ignore: memset */
	memset(g_VdecMapInfo, 0, sizeof(g_VdecMapInfo));/* unsafe_function_ignore: memset */
	VDEC_INIT_MUTEX(&g_OmxVdecEntry.omxvdec_mutex);
	VDEC_INIT_MUTEX(&g_OmxVdecEntry.vdec_mutex_scd);
	VDEC_INIT_MUTEX(&g_OmxVdecEntry.vdec_mutex_vdh);

	ret = VDEC_MEM_Probe();
	if (ret != HI_SUCCESS)
	{
		dprint(PRN_FATAL, "%s call VDEC_MEM_Probe failed\n", __func__);
		goto cleanup0;
	}

	ret = omxvdec_setup_cdev(&g_OmxVdecEntry, &omxvdec_fops);
	if (ret < 0) {
		dprint(PRN_FATAL, "%s call omxvdec_setup_cdev failed\n", __func__);
		goto cleanup0;
	}

	ret = VDEC_Regulator_Probe(&pltdev->dev);
	if (ret != HI_SUCCESS) {
		dprint(PRN_FATAL, "%s call Regulator_Initialize failed\n", __func__);
		goto cleanup1;
	}

	g_OmxVdecEntry.device = &pltdev->dev;
	platform_set_drvdata(pltdev, &g_OmxVdecEntry);
	gIsDeviceDetected = HI_TRUE;

	return 0;

cleanup1:
	omxvdec_cleanup_cdev(&g_OmxVdecEntry);

cleanup0:
	return ret;
}

static HI_S32 omxvdec_remove(struct platform_device *pltdev)
{
	OMXVDEC_ENTRY *omxvdec = HI_NULL;

	omxvdec = platform_get_drvdata(pltdev);
	if (omxvdec != HI_NULL) {
		if (IS_ERR(omxvdec)) {
			dprint(PRN_ERROR, "call platform_get_drvdata err, errno : %ld\n", PTR_ERR(omxvdec));
		} else {
			omxvdec_cleanup_cdev(omxvdec);
			VDEC_Regulator_Remove(&pltdev->dev);
			platform_set_drvdata(pltdev, HI_NULL);
			gIsDeviceDetected = HI_FALSE;
		}
	}

	return 0;
}

static HI_S32 omxvdec_suspend(struct platform_device *pltdev, pm_message_t state)
{
	SINT32 ret;

	dprint(PRN_ALWS, "%s enter\n", __func__);

	if (gIsNormalInit != 0)
		VCTRL_Suspend();

	ret = VDEC_Regulator_Disable();
	if (ret != HI_SUCCESS)
		dprint(PRN_FATAL, "%s disable regulator failed\n", __func__);

	dprint(PRN_ALWS, "%s success\n", __func__);

	return HI_SUCCESS;
}

static HI_S32 omxvdec_resume(struct platform_device *pltdev)
{
	SINT32 ret;
	dprint(PRN_ALWS, "%s enter\n", __func__);

	if (gIsNormalInit != 0) {
		ret = VDEC_Regulator_Enable();
		if (ret != HI_SUCCESS) {
			dprint(PRN_FATAL, "%s enable regulator failed\n", __func__);
			return HI_FAILURE;
		}
		VCTRL_Resume();
	}

	dprint(PRN_ALWS, "%s success\n", __func__);

	return HI_SUCCESS;
}

static HI_VOID omxvdec_device_release(struct device *dev)
{
	return;
}

static struct platform_driver omxvdec_driver = {

	.probe   = omxvdec_probe,
	.remove  = omxvdec_remove,
	.suspend = omxvdec_suspend,
	.resume  = omxvdec_resume,
	.driver  = {
		.name  = (HI_PCHAR) g_OmxVdecDrvName,
		.owner = THIS_MODULE,
		.of_match_table = Hisi_Vdec_Match_Table
	},
};

static struct platform_device omxvdec_device = {

	.name = g_OmxVdecDrvName,
	.id   = -1,
	.dev  = {
		.platform_data = NULL,
		.release       = omxvdec_device_release,
	},
};

HI_S32 __init OMXVDEC_DRV_ModInit(HI_VOID)
{
	HI_S32 ret;

	ret = platform_device_register(&omxvdec_device);
	if (ret < 0) {
		dprint(PRN_FATAL, "%s call platform_device_register failed\n", __func__);
		return ret;
	}

	ret = platform_driver_register(&omxvdec_driver);
	if (ret < 0) {
		dprint(PRN_FATAL, "%s call platform_driver_register failed\n", __func__);
		goto exit;
	}
#ifdef MODULE
	dprint(PRN_ALWS, "Load hi_omxvdec.ko :%d success\n", OMXVDEC_VERSION);
#endif

	return HI_SUCCESS;
exit:
	platform_device_unregister(&omxvdec_device);

	return ret;
}

HI_VOID __exit OMXVDEC_DRV_ModExit(HI_VOID)
{
	platform_driver_unregister(&omxvdec_driver);
	platform_device_unregister(&omxvdec_device);

#ifdef MODULE
	dprint(PRN_ALWS, "Unload hi_omxvdec.ko : %d success\n", OMXVDEC_VERSION);
#endif

}

module_init(OMXVDEC_DRV_ModInit);
module_exit(OMXVDEC_DRV_ModExit);

MODULE_AUTHOR("gaoyajun@hisilicon.com");
MODULE_DESCRIPTION("vdec driver");
MODULE_LICENSE("GPL");

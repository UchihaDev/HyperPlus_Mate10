/*
 * vfmw interface
 *
 * Copyright (c) 2017 Hisilicon Limited
 *
 * Author: gaoyajun<gaoyajun@hisilicon.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation.
 *
 */
#include <linux/module.h>
#include <linux/kern_levels.h>

#include "basedef.h"
#include "public.h"
#include "vfmw_intf.h"

#ifdef HI_TVP_SUPPORT
#include "tvp_adapter.h"
#endif

#ifdef HIVDEC_SMMU_SUPPORT
#include "smmu.h"
#include "smmu_regs.h"
#endif
#include "vdm_hal_api.h"
#include "drv_omxvdec.h"

#ifndef IRQF_DISABLED
#define IRQF_DISABLED               (0x00000020)
#endif
#define VDM_TIMEOUT               (400)//ms
#define VDM_FPGA_TIMEOUT          (500000)//ms
#define SCD_TIMEOUT               (400)//ms
#define SCD_FPGA_TIMEOUT          (200000)//ms
#define SCEN_IDENT                (0x828)
#define MAP_SIZE                  (256 * 1024)

#define TIME_PERIOD(begin, end) ((end >= begin)? (end-begin):(0xffffffff - begin + end))

// cppcheck-suppress *
#define  VCTRL_ASSERT_RET(cond, else_print)                                      \
do {                                                                             \
	if (!(cond)) {                                                           \
		dprint(PRN_FATAL,"%s %d %s\n", __func__, __LINE__, else_print ); \
		return VCTRL_ERR;                                                \
	}                                                                        \
}while(0)

static DRV_MEM_S g_RegsBaseAddr;

Vfmw_Osal_Func_Ptr g_vfmw_osal_fun_ptr;

#ifdef MSG_POOL_ADDR_CHECK
SINT32 CheckFrmBufAddr(UINT32 SrcFrmAddr, MEM_BUFFER_S* pVdhMemMap)
{
	UINT32 index;
	HI_S32 is_mapped = 0;

	if (!SrcFrmAddr) {
		dprint(PRN_FATAL, "%s SrcFrmAddr is NULL", __func__);
		return VDMHAL_ERR;
	}

	for (index = VDH_SHAREFD_FRM_BUF; index < VDH_SHAREFD_MAX; index++) {
		if (pVdhMemMap[index].u8IsMapped == 0)
			break;

		if ((SrcFrmAddr >= pVdhMemMap[index].u32StartPhyAddr)
			&& (SrcFrmAddr <= (pVdhMemMap[index].u32StartPhyAddr
				+ pVdhMemMap[index].u32Size))) {
			is_mapped = 1;
			break;
		}
	}

	if (!is_mapped) {
		dprint(PRN_FATAL, "%s SrcFrmAddr is out of range (%d)\n", __func__, index);
		return VDMHAL_ERR;
	}
	return VDMHAL_OK;
}

SINT32 CheckPmvBufAddr(UINT32 SrcPmvAddr, MEM_BUFFER_S* pVdhMemMap)
{
	if ((SrcPmvAddr < pVdhMemMap[VDH_SHAREFD_PMV_BUF].u32StartPhyAddr)
		|| (SrcPmvAddr > (pVdhMemMap[VDH_SHAREFD_PMV_BUF].u32StartPhyAddr
			+ pVdhMemMap[VDH_SHAREFD_PMV_BUF].u32Size))) {
		return VDMHAL_ERR;
	}
	return VDMHAL_OK;
}

SINT32 VCTRL_VDHUnmapMessagePool(MEM_BUFFER_S *pMemMap)
{
	HI_S32 ret;

	if (pMemMap->u8IsMapped == 1) {
		pMemMap->u8IsMapVirtual = 1;
		ret = VDEC_MEM_UnmapKernel(pMemMap);
		if (ret)
			dprint(PRN_FATAL, "%s Unmap Kernel is error(MESSAGE_POOL)\n", __func__);
	}
	return VCTRL_OK;
}

SINT32 VCTRL_VDHMapMessagePool(MEM_BUFFER_S* pMemMap, HI_S32 share_fd, HI_BOOL isVdhAllBufRemap)
{
	HI_S32 ret;

	if ((pMemMap->u8IsMapped == 1) && (isVdhAllBufRemap == HI_TRUE)) {
		pMemMap->u8IsMapVirtual = 1;
		VDEC_MEM_UnmapKernel(pMemMap);
		memset(pMemMap, 0, sizeof(*pMemMap)); /* unsafe_function_ignore: memset */
	}

	if (pMemMap->u8IsMapped == 0) {
		pMemMap->u8IsMapVirtual = 1;
		ret = VDEC_MEM_MapKernel(share_fd, pMemMap);
		VCTRL_ASSERT_RET((ret == HI_SUCCESS), "share fd map failed");
		pMemMap->u8IsMapped = 1;
		pMemMap->u32ShareFd = share_fd;

		ret = VDMHAL_IMP_OpenHAL(pMemMap);
		if (ret) {
			VDEC_MEM_UnmapKernel(pMemMap);
			memset(pMemMap, 0, sizeof(*pMemMap)); /* unsafe_function_ignore: memset */
			dprint(PRN_FATAL, "%s VDMHAL_IMP_OpenHAL is failed\n", __func__);
			return VCTRL_ERR;
		}
	}

	return VCTRL_OK;
}
#endif

VOID VCTRL_Suspend(VOID)
{
	UINT8 isScdSleep = 0;
	UINT8 isVdmSleep = 0;
	UINT32 SleepCount = 0;
	UINT32 BeginTime, EntrTime, CurTime;

	EntrTime = VFMW_OSAL_GetTimeInMs();

	SCDDRV_PrepareSleep();

	VDMHAL_PrepareSleep();

	BeginTime = VFMW_OSAL_GetTimeInMs();
	do {
		if (SCDDRV_SLEEP_STAGE_SLEEP == SCDDRV_GetSleepStage())
			isScdSleep = 1;

		if (VDMHAL_GetSleepStage() == VDMDRV_SLEEP_STAGE_SLEEP)
			isVdmSleep = 1;

		if ((isScdSleep == 1) && (isVdmSleep == 1)) {
			break;
		} else {
			if (SleepCount > 30) {
				if (isScdSleep != 1) {
					dprint(PRN_FATAL, "Force scd sleep\n");
					SCDDRV_ForceSleep();
				}
				if (isVdmSleep != 1) {
					dprint(PRN_FATAL, "Force vdm sleep\n");
					VDMHAL_ForceSleep();
				}
				break;
			}

			VFMW_OSAL_mSleep(10);
			SleepCount++;
		}
	} while ((isScdSleep != 1) || (isVdmSleep != 1));

#ifdef HI_TVP_SUPPORT
	if (TVP_VDEC_Suspend() != VDEC_OK)
		dprint(PRN_ALWS, "%s, Warning : TVP_VDEC_Suspend failed", __func__);
#endif

	CurTime = VFMW_OSAL_GetTimeInMs();
	dprint(PRN_ALWS, "Vfmw suspend totally take %d ms\n", TIME_PERIOD(EntrTime, CurTime));

	return;
}

VOID VCTRL_Resume(VOID)
{
	UINT32 EntrTime, CurTime;

	EntrTime = VFMW_OSAL_GetTimeInMs();

	SMMU_InitGlobalReg();

	SCDDRV_ExitSleep();

	VDMHAL_ExitSleep();

#ifdef HI_TVP_SUPPORT
	if (TVP_VDEC_Resume() != VDEC_OK)
		dprint(PRN_ALWS, "%s, Warning : TVP_VDEC_Resume failed", __func__);
#endif

	CurTime = VFMW_OSAL_GetTimeInMs();
	dprint(PRN_ALWS, "Vfmw resume totally take %d ms\n", TIME_PERIOD(EntrTime, CurTime));

	return;
}

static SINT32 VCTRL_ISR(SINT32 irq, VOID *dev_id)
{
	UINT32 D32;
	D32 = RD_SCDREG(REG_SCD_INI_CLR)&0x1;
	if (D32 == 1)
		SCDDRV_ISR();

	RD_VREG(VREG_INT_STATE, D32, 0);
	if (D32 == 1)
		VDMHAL_ISR(0);

	/* RD_VREG(SMMU_INTSTAT_NS, D32, 0);
	if (D32 != 0)
		SMMU_IntServProc();*/
	return IRQ_HANDLED;
}

static SINT32 VCTRL_RequestIrq(UINT32 IrqNumNorm, UINT32 IrqNumProt, UINT32 IrqNumSafe)
{
#if !defined(VDM_BUSY_WAITTING)
	if (VFMW_OSAL_RequestIrq(IrqNumNorm, VCTRL_ISR, IRQF_DISABLED, "vdec_norm_irq", NULL) != 0) {    //for 2.6.24以后
		dprint(PRN_FATAL, "Request vdec norm irq %d failed\n", IrqNumNorm);
		return VCTRL_ERR;
	}
#endif

#if !defined(SMMU_BUSY_WAITTING)
#ifdef ENV_SOS_KERNEL
	if (VFMW_OSAL_RequestIrq(IrqNumProt, VCTRL_ISR, IRQF_DISABLED, "vdec_prot_smmu_irq", NULL) != 0) {    //for 2.6.24以后
		dprint(PRN_FATAL, "Request vdec prot irq %d failed\n", IrqNumProt);
		return VCTRL_ERR;
	}
#endif
#endif

	return VCTRL_OK;
}

static VOID VCTRL_FreeIrq(UINT32 IrqNumNorm, UINT32 IrqNumProt, UINT32 IrqNumSafe)
{
#if !defined(VDM_BUSY_WAITTING)
	VFMW_OSAL_FreeIrq(IrqNumNorm, NULL);
#endif

#if !defined(SMMU_BUSY_WAITTING)
#ifdef ENV_SOS_KERNEL
	VFMW_OSAL_FreeIrq(IrqNumProt, NULL);
#endif
#endif
}

static SINT32 VCTRL_HalInit(VOID)
{
#ifdef HIVDEC_SMMU_SUPPORT
	if (SMMU_Init() != SMMU_OK) {
		dprint(PRN_FATAL, "SMMU_Init failed\n");
		return VCTRL_ERR;
	}
#endif

	SCDDRV_init();
	VDMHAL_IMP_Init();
	SMMU_InitGlobalReg();

	return VCTRL_OK;
}

static VOID VCTRL_HalDeInit(VOID)
{
#ifdef HIVDEC_SMMU_SUPPORT
	SMMU_DeInit();
#endif
	VDMHAL_IMP_DeInit();
	SCDDRV_DeInit();
}

static SINT32 VCTRL_SCDGetAddrInfo(MEM_BUFFER_S* pMemMap, SCD_CONFIG_REG_S *ctrlReg, HI_S32 maxShareFdNum)
{
	HI_S32 ret;
	HI_S32 index;

	VCTRL_ASSERT_RET((HI_NULL != pMemMap), "pMemMap parameter error");
	VCTRL_ASSERT_RET((HI_NULL != ctrlReg), "ctrlReg parameter error");

	for (index = 0; index < maxShareFdNum; index++) {
		if ((pMemMap[index].u8IsMapped == 0)
				|| (ctrlReg->IsScdAllBufRemap)) {
			pMemMap[index].u8IsMapVirtual = 0;
			ret = VDEC_MEM_MapKernel(ctrlReg->scd_share_fd[index], &pMemMap[index]);
			VCTRL_ASSERT_RET((ret == HI_SUCCESS), "share fd map is failed");
			pMemMap[index].u8IsMapped = 1;
			pMemMap[index].u32ShareFd = ctrlReg->scd_share_fd[index];
			VDEC_MEM_UnmapKernel(&pMemMap[index]);
		}
	}
	return VCTRL_OK;
}

static SINT32 VCTRL_VDHGetAddrInfo(MEM_BUFFER_S* pMemMap, MEM_BUFFER_S* pComMsgMap, OMXVDH_REG_CFG_S * pVdmRegCfg)
{
	HI_S32 ret;
	HI_U32 index;
	HI_S32 *share_fd = &(pVdmRegCfg->vdh_share_fd[0]);
	HI_BOOL isVdhFrmBufRemap = pVdmRegCfg->IsFrmBufRemap;
	HI_BOOL isVdhPmvBufRemap = pVdmRegCfg->IsPmvBufRemap;
	HI_BOOL isVdhAllBufRemap = pVdmRegCfg->IsAllBufRemap;

	VCTRL_ASSERT_RET((HI_NULL != pMemMap), "pMemMap parameter error");
	VCTRL_ASSERT_RET((pVdmRegCfg->vdhFrmBufNum <= MAX_FRAME_NUM), "vdhFrmBufNum error");

	for (index = 0; index < (VDH_SHAREFD_FRM_BUF + pVdmRegCfg->vdhFrmBufNum); index++) {
#ifdef MSG_POOL_ADDR_CHECK
		if (index == VDH_SHAREFD_MESSAGE_POOL) {
			ret = VCTRL_VDHMapMessagePool(pComMsgMap, share_fd[index], isVdhAllBufRemap);
			VCTRL_ASSERT_RET((ret == VCTRL_OK), "msg share fd map failed");
			memcpy(&pMemMap[index], pComMsgMap, sizeof(pMemMap[index])); /* unsafe_function_ignore: memcpy */
			continue;
		}
#endif
		if ((pMemMap[index].u8IsMapped == 1) && (isVdhAllBufRemap)) {
			memset(&pMemMap[index], 0, sizeof(pMemMap[index])); /* unsafe_function_ignore: m
emset */
		}
		/* pmv or fmv remap */
		if ((pMemMap[index].u8IsMapped == 1)
			&& (((index == VDH_SHAREFD_PMV_BUF) && (isVdhPmvBufRemap))
				|| ((index >= VDH_SHAREFD_FRM_BUF) && (isVdhFrmBufRemap)))) {
			memset(&pMemMap[index], 0, sizeof(pMemMap[index])); /* unsafe_function_ignore: m
emset */
		}

		if (pMemMap[index].u8IsMapped == 0) {
			pMemMap[index].u8IsMapVirtual = 0;
			ret = VDEC_MEM_MapKernel(share_fd[index], &pMemMap[index]);
			VCTRL_ASSERT_RET((ret == HI_SUCCESS), "share fd map failed");
			pMemMap[index].u8IsMapped = 1;
			pMemMap[index].u32ShareFd = share_fd[index];
			VDEC_MEM_UnmapKernel(&pMemMap[index]);
		}
	}
	return VCTRL_OK;
}

SINT32 VCTRL_OpenDrivers(VOID)
{
	MEM_RECORD_S *pstMem;
	SINT32 ret   = VCTRL_ERR;

	pstMem = &g_RegsBaseAddr.stVdhReg;
	if (MEM_MapRegisterAddr(gVdhRegBaseAddr, MAP_SIZE, pstMem) == MEM_MAN_OK) {
		if (MEM_AddMemRecord(pstMem->PhyAddr, pstMem->VirAddr, pstMem->Length) != MEM_MAN_OK) {
			dprint(PRN_ERROR, "%s %d MEM_AddMemRecord failed\n", __func__, __LINE__);
			goto exit;
		}
	} else {
		dprint(PRN_FATAL, "Map vdh register failed! gVdhRegBaseAddr : %pK, gVdhRegRange : %d\n",
			(void *)(uintptr_t)gVdhRegBaseAddr, gVdhRegRange);
		goto exit;
	}

	ret = VCTRL_RequestIrq(gVdecIrqNumNorm, gVdecIrqNumProt, gVdecIrqNumSafe);
	if (ret != VCTRL_OK) {
		dprint(PRN_FATAL, "VCTRL_RequestIrq failed\n");
		goto exit;
	}

	if (VCTRL_HalInit() != VCTRL_OK) {
		dprint(PRN_FATAL, "VCTRL_HalInit failed\n");
		goto exit;
	}

	VFMW_OSAL_InitEvent(G_SCDHWDONEEVENT, 0);
	VFMW_OSAL_InitEvent(G_VDMHWDONEEVENT, 0);

	return VCTRL_OK;

exit:
	VCTRL_CloseVfmw();
	return VCTRL_ERR;
}

SINT32 VCTRL_OpenVfmw(VOID)
{
	memset(&g_RegsBaseAddr, 0, sizeof(g_RegsBaseAddr)); /* unsafe_function_ignore: m
emset */

	MEM_InitMemManager();
	if (VCTRL_OpenDrivers() != VCTRL_OK) {
		dprint(PRN_FATAL, "OpenDrivers fail\n");
		return VCTRL_ERR;
	}

#ifdef HI_TVP_SUPPORT
	if (TVP_VDEC_SecureInit() != VDEC_OK)
		dprint(PRN_FATAL, "%s, TVP_VDEC_SecureInit failed\n", __func__);
#endif

	return VCTRL_OK;
}

SINT32 VCTRL_CloseVfmw(VOID)
{
	MEM_RECORD_S *pstMem;

	VCTRL_HalDeInit();

	pstMem = &g_RegsBaseAddr.stVdhReg;
	if (pstMem->Length != 0) {
		MEM_UnmapRegisterAddr(pstMem->PhyAddr, pstMem->VirAddr, pstMem->Length);
		MEM_DelMemRecord(pstMem->PhyAddr, pstMem->VirAddr, pstMem->Length);
		memset(&g_RegsBaseAddr.stVdhReg, 0, sizeof(g_RegsBaseAddr.stVdhReg)); /* unsafe_function_ignore: m
emset */
	}

	VCTRL_FreeIrq(gVdecIrqNumNorm, gVdecIrqNumProt, gVdecIrqNumSafe);

#ifdef HI_TVP_SUPPORT
	TVP_VDEC_SecureExit();
#endif
	return VCTRL_OK;
}

SINT32 VCTRL_VDMHal_Process(OMXVDH_REG_CFG_S *pVdmRegCfg, VDMHAL_BACKUP_S *pVdmRegState,
				MEM_BUFFER_S* pVdhMemMap, MEM_BUFFER_S* pComMsgMap)
{
	HI_S32 ret = HI_SUCCESS;
	VDMDRV_SLEEP_STAGE_E sleepState;

	sleepState = VDMHAL_GetSleepStage();
	if (VDMDRV_SLEEP_STAGE_SLEEP == sleepState) {
		dprint(PRN_ALWS, "vdm sleep state\n");
		return HI_FAILURE;
	}

	if (pVdmRegCfg->vdh_reset_flag)
		VDMHAL_IMP_ResetVdm(0);

	ret = VCTRL_VDHGetAddrInfo(&pVdhMemMap[0], pComMsgMap, pVdmRegCfg);
	if (ret) {
		dprint(PRN_FATAL, "VCTRL_VDHGetAddrInfo is failed\n");
		return HI_FAILURE;
	}

	ret = VDMHAL_HwDecProc(pVdmRegCfg, pVdhMemMap);

	if (ret) {
		dprint(PRN_FATAL, "%s config error\n", __func__);
	} else {
		ret = VFMW_OSAL_WaitEvent(G_VDMHWDONEEVENT, VDM_TIMEOUT);
		if (ret == HI_SUCCESS) {
			VDMHAL_GetRegState(pVdmRegState);
		} else {
			dprint(PRN_FATAL, "VFMW_OSAL_WaitEvent wait time out\n");
			VDMHAL_IMP_ResetVdm(0);
		}
	}

	sleepState = VDMHAL_GetSleepStage();
	if (sleepState == VDMDRV_SLEEP_STAGE_PREPARE)
		VDMHAL_SetSleepStage(VDMDRV_SLEEP_STAGE_SLEEP);

	return ret;
}

SINT32 VCTRL_SCDHal_Process(OMXSCD_REG_CFG_S *pScdRegCfg,SCD_STATE_REG_S *pScdStateReg, MEM_BUFFER_S* pScdMemMap)
{
	HI_S32 ret = HI_SUCCESS;
	SCDDRV_SLEEP_STAGE_E sleepState;
	CONFIG_SCD_CMD cmd = pScdRegCfg->cmd;

	sleepState = SCDDRV_GetSleepStage();
	if (SCDDRV_SLEEP_STAGE_SLEEP == sleepState) {
		dprint(PRN_ALWS, "SCD sleep state\n");
		return HI_FAILURE;
	}

	if (pScdRegCfg->SResetFlag) {
		if (SCDDRV_ResetSCD() != HI_SUCCESS) {
			dprint(PRN_FATAL, "VDEC_IOCTL_SCD_WAIT_HW_DONE  Reset SCD failed\n");
			return HI_FAILURE;
		}
	}

	ret = VCTRL_SCDGetAddrInfo(&pScdMemMap[0], &(pScdRegCfg->SmCtrlReg), SCD_SHAREFD_MAX);
	if (ret != VCTRL_OK) {
		dprint(PRN_FATAL, "memory map failure\n");
		return HI_FAILURE;
	}

	switch (cmd) {
	case CONFIG_SCD_REG_CMD:
		ret = SCDDRV_WriteReg(&pScdRegCfg->SmCtrlReg, pScdMemMap);
		if (ret != HI_SUCCESS) {
			dprint(PRN_FATAL, "SCD busy\n");
			return HI_FAILURE;
		}

		ret = VFMW_OSAL_WaitEvent(G_SCDHWDONEEVENT, ((0 == gIsFPGA) ? SCD_TIMEOUT : SCD_FPGA_TIMEOUT));
		if (ret == HI_SUCCESS) {
			SCDDRV_GetRegState(pScdStateReg);
		} else {
			dprint(PRN_ALWS, "VDEC_IOCTL_SCD_WAIT_HW_DONE  wait time out\n");
			SCDDRV_ResetSCD();
		}

		sleepState = SCDDRV_GetSleepStage();
		if (sleepState == SCDDRV_SLEEP_STAGE_PREPARE) {
			SCDDRV_SetSleepStage(SCDDRV_SLEEP_STAGE_SLEEP);
		}
		break;

	default:
		dprint(PRN_FATAL, " cmd type unknown:%d\n", cmd);
		return HI_FAILURE;
	}

	return ret;
}

SINT32 VCTRL_VDMHAL_IsRun(VOID)
{
	return VDMHAL_IsVdmRun(0);
}

HI_BOOL VCTRL_Scen_Ident(HI_U32 cmd)
{
	if ((RD_SCDREG(SCEN_IDENT) == 1) && (cmd != VDEC_IOCTL_SET_CLK_RATE))
		return HI_TRUE;

	return HI_FALSE;
}

HI_S32 VFMW_DRV_ModInit(HI_VOID)
{
	OSAL_InitInterface();
	VFMW_OSAL_SemaInit(G_SCD_SEM);
	VFMW_OSAL_SemaInit(G_VDH_SEM);
	VFMW_OSAL_SemaInit(G_BPD_SEM);

	VFMW_OSAL_SpinLockInit(G_SPINLOCK_SCD);
	VFMW_OSAL_SpinLockInit(G_SPINLOCK_VDH);
	VFMW_OSAL_SpinLockInit(G_SPINLOCK_RECORD);
	VFMW_OSAL_InitEvent(G_SCDHWDONEEVENT, 0);
	VFMW_OSAL_InitEvent(G_VDMHWDONEEVENT, 0);

#ifdef MODULE
	dprint(PRN_ALWS, "%s : Load hi_vfmw.ko (%d) success\n", __func__, VFMW_VERSION_NUM);
#endif

	return 0;
}

HI_VOID VFMW_DRV_ModExit(HI_VOID)
{
#ifdef MODULE
	dprint(PRN_ALWS, "%s : Unload hi_vfmw.ko (%d) success\n",__func__, VFMW_VERSION_NUM);
#endif

	return;
}

module_init(VFMW_DRV_ModInit);
module_exit(VFMW_DRV_ModExit);

MODULE_AUTHOR("gaoyajun");
MODULE_LICENSE("GPL");

/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/******************************************************************************
  1 头文件包含
******************************************************************************/
#include "hdlc_hardware_driver.h"
#include "product_config.h"
#include "mdrv.h"
#include "soc_hdlc_interface.h"
#include "TTFUtil.h"
#include "hdlc_hardware_conf.h"

#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif

/*****************************************************************************
   协议栈打印打点方式下的.C文件宏定义
*****************************************************************************/
#define    THIS_FILE_ID        PS_FILE_ID_HDLC_HARDWARE_DRIVER_C


/******************************************************************************
   2 外部函数变量声明
******************************************************************************/


/*****************************************************************************
   3 私有定义
*****************************************************************************/


/*****************************************************************************
   4 全局变量定义
*****************************************************************************/

/* HDLC配置相关信息 */
PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU   g_stHdlcConfigInfo;

/******************************************************************************
   5 函数实现
******************************************************************************/

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardFrmIsr
 功能描述  : HDLC封装中断完成通知服务程序
 输入参数  : 无
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardFrmIsr(unsigned int ulPara)
{
    PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU  *pstConf = PPP_DRIVER_HDLC_HARD_GET_CONFIG;

    g_stHdlcRegSaveInfo.ulHdlcFrmRawInt = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_RAW_INT_ADDR(HDLC_IP_BASE_ADDR));
    g_stHdlcRegSaveInfo.ulHdlcFrmStatus = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_STATUS_ADDR(HDLC_IP_BASE_ADDR));

    /* 收到一次中断后清除原始中断 */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_FRM_INT_CLR_ADDR(HDLC_IP_BASE_ADDR), 0xFFFFFFFFU);

    /* 释放封装完成信号量 */
    /*lint -e(455) VOS_SmV语句屏蔽, 正常机制 */
    VOS_SmV(pstConf->ulHdlcFrmMasterSem);

    g_PppHdlcHardStat.ulFrmIsrCnt++;

    /* drv提供的接口不关心返回值 */
    return 1; /* IRQ_HANDLED; */
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardDefIsr
 功能描述  : HDLC解封装中断完成通知服务程序
 输入参数  : 无
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardDefIsr(unsigned int ulPara)
{
    PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU  *pstConf = PPP_DRIVER_HDLC_HARD_GET_CONFIG;

    g_stHdlcRegSaveInfo.ulHdlcDefRawInt = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_RAW_INT_ADDR(HDLC_IP_BASE_ADDR));
    g_stHdlcRegSaveInfo.ulHdlcDefStatus = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_STATUS_ADDR(HDLC_IP_BASE_ADDR));

    /* 收到一次中断后清除原始中断 */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_INT_CLR_ADDR(HDLC_IP_BASE_ADDR), 0xFFFFFFFFU);

    /* 释放封装完成信号量 */
    /*lint -e(455) VOS_SmV语句屏蔽, 正常机制 */
    VOS_SmV(pstConf->ulHdlcDefMasterSem);

    g_PppHdlcHardStat.ulDefIsrCnt++;


    /* drv提供的接口不关心返回值 */
    return 1; /* IRQ_HANDLED; */
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardGetPeriphClkStatus
 功能描述  : 查询HDLC时钟
 输入参数  : 无
 输出参数  : 无
 返 回 值  : VOS_TRUE:开 VOS_FALSE:关
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年1月3日
    作    者   : c00184031
    修改内容   : 新生成函数

*****************************************************************************/
VOS_BOOL PPP_Driver_HdlcHardGetPeriphClkStatus(VOS_VOID)
{
    VOS_UINT32      ulValue = 0;

    ulValue = PPP_HDLC_READ_32REG(HDLC_CRG_CLKSTA4_ADDR(PPP_DRIVER_HDLC_HARD_GET_SC_BASE_ARRD));
    ulValue &= (1 << HDLC_CRG_CLK_BITPOS);

    /* 结果为零说明当前时钟未开启 */
    if (0 == ulValue)
    {
        return VOS_FALSE;
    }
    else
    {
        return VOS_TRUE;
    }
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardPeriphClkOpen
 功能描述  : 打开HDLC时钟
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年6月13日
    作    者   : c00191211
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardPeriphClkOpen(VOS_VOID)
{
    VOS_UINT32      ulValue = 0;

    ulValue |= (1 << HDLC_CRG_CLK_BITPOS);
    PPP_HDLC_WRITE_32REG(HDLC_CRG_CLKEN4_ADDR(PPP_DRIVER_HDLC_HARD_GET_SC_BASE_ARRD), ulValue);

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardPeriphClkClose
 功能描述  : 关闭HDLC时钟
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年6月13日
    作    者   : c00191211
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardPeriphClkClose(VOS_VOID)
{
    VOS_UINT32      ulValue = 0;

    ulValue |= (1 << HDLC_CRG_CLK_BITPOS);
    PPP_HDLC_WRITE_32REG(HDLC_CRG_CLKENDIS4_ADDR(PPP_DRIVER_HDLC_HARD_GET_SC_BASE_ARRD), ulValue);

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardInit
 功能描述  : 对HDLC进行初始化: HDLC配置发生异常时, 对异常中断上报的控制
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardInit
(
    PPP_DRIVER_HDLC_HARD_FRM_CONFIG_STRU   *pstFrmConfig,
    PPP_DRIVER_HDLC_HARD_DEF_CONFIG_STRU   *pstDefConfig
)
{
    VOS_UINT_PTR                          ulBaseAddr;
    PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU  *pstHdlcConf = PPP_DRIVER_HDLC_HARD_GET_CONFIG;

    PPP_HDLC_HARD_MEM_SET(PPP_DRIVER_HDLC_HARD_GET_CONFIG, sizeof(PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU),
                          0x00, sizeof(PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU));

    /* 获取HDLC基地址 */
    ulBaseAddr              = (VOS_UINT_PTR)mdrv_misc_get_ip_baseaddr(BSP_IP_TYPE_HDLC);

    HDLC_IP_BASE_ADDR       = PPP_HDLC_HARD_IO_ADDRESS(ulBaseAddr);

    if (VOS_NULL_PTR == HDLC_IP_BASE_ADDR)
    {
        PPP_HDLC_ERROR_LOG1("HDLC base addr is null", ulBaseAddr);
        return VOS_ERR;
    }

#if ((SC_CTRL_MOD_P532 == SC_CTRL_MOD) || (SC_CTRL_MOD_6932_SFT == SC_CTRL_MOD))
    ulBaseAddr              = (VOS_UINT_PTR)mdrv_misc_get_ip_baseaddr(BSP_IP_TYPE_SYSCTRL_PD);
#elif ((SC_CTRL_MOD_6250_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_3660_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_KIRIN970_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_M533 == SC_CTRL_MOD))
    /* =========dallas/chicago/boston中使用: HDLC寄存器基地址位置======== */
    ulBaseAddr              = (VOS_UINT_PTR)mdrv_misc_get_ip_baseaddr(BSP_IP_TYPE_SYSCTRL_MDM);
#else
    ulBaseAddr              = (VOS_UINT_PTR)mdrv_misc_get_ip_baseaddr(BSP_IP_TYPE_SYSCTRL);
#endif

    pstHdlcConf->ulHdlcScCtrlBaseAddr  = PPP_HDLC_HARD_IO_ADDRESS(ulBaseAddr);

    if (VOS_NULL_PTR == pstHdlcConf->ulHdlcScCtrlBaseAddr)
    {
        PPP_HDLC_ERROR_LOG1("PPP_HDLC_HARD_Init HDLC SCCTRL base addr is null,0x%x\r\n",
                      ulBaseAddr);
        return VOS_ERR;
    }

#if ((SC_CTRL_MOD_KIRIN970_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_M533 == SC_CTRL_MOD))
    /* Boston版本后面配置最大封装寄存器时有可能由于与开时钟指令未执行完毕导致配置失败 */
    PPP_Driver_HdlcHardPeriphClkOpen();
#else
    /* 关闭HDLC时钟 */
    PPP_Driver_HdlcHardPeriphClkClose();
#endif

    /*获取HDLC解封装中断号*/
    pstHdlcConf->slHdlcISRDef   = mdrv_int_get_num(BSP_INT_TYPE_HDLC_DEF);

    /*获取HDLC封装中断号*/
    pstHdlcConf->slHdlcISRFrm   = mdrv_int_get_num(BSP_INT_TYPE_HDLC_FRM);

    if ( VOS_OK != VOS_SmBCreate("HdlcDefMasterSem", 0, VOS_SEMA4_FIFO, (VOS_SEM *)&(pstHdlcConf->ulHdlcDefMasterSem)) )
    {
        PPP_HDLC_ERROR_LOG("PPP_HDLC_HARD_Init, ERROR, Create g_ulHdlcDefMasterSem failed!\r\n");
        return VOS_ERR;
    }

    if ( VOS_OK != VOS_SmBCreate("HdlcFrmMasterSem", 0, VOS_SEMA4_FIFO, (VOS_SEM *)&(pstHdlcConf->ulHdlcFrmMasterSem)) )
    {
        PPP_HDLC_ERROR_LOG("PPP_HDLC_HARD_Init, ERROR, Create g_ulHdlcFrmMasterSem failed!\r\n");
        return VOS_ERR;
    }

    /* 中断挂接 */
    if (VOS_OK != mdrv_int_connect(pstHdlcConf->slHdlcISRDef, (VOIDFUNCPTR)PPP_Driver_HdlcHardDefIsr, 0))
    {
        PPP_HDLC_ERROR_LOG1("PPP_HDLC_HARD_Init, ERROR, Connect slHdlcISRDef %d to PPP_HDLC_HARD_DefIsr failed!\r\n",
                      pstHdlcConf->slHdlcISRDef);
        return VOS_ERR;
    }

    /* 中断使能 */
    if (VOS_OK != mdrv_int_enable(pstHdlcConf->slHdlcISRDef))
    {
        PPP_HDLC_ERROR_LOG1("PPP_HDLC_HARD_Init, ERROR, Enable slHdlcISRDef %d failed!\r\n",
                      pstHdlcConf->slHdlcISRDef);
        return VOS_ERR;
    }

    /* 中断挂接 */
    if (VOS_OK != mdrv_int_connect(pstHdlcConf->slHdlcISRFrm, (VOIDFUNCPTR)PPP_Driver_HdlcHardFrmIsr, 0))
    {
        PPP_HDLC_ERROR_LOG1("PPP_HDLC_HARD_Init, ERROR, Connect slHdlcISRFrm %d to PPP_HDLC_HARD_FrmIsr failed!\r\n",
                      pstHdlcConf->slHdlcISRFrm);
        return VOS_ERR;
    }

    if (VOS_OK != mdrv_int_enable(pstHdlcConf->slHdlcISRFrm))
    {
        PPP_HDLC_ERROR_LOG1("PPP_HDLC_HARD_Init, ERROR, Enable slHdlcISRFrm %d failed!\r\n",
                      pstHdlcConf->slHdlcISRFrm);
        return VOS_ERR;
    }

    pstHdlcConf->ulHdlcDefIntLimit = HDLC_DEF_INTERRUPT_LIMIT_DEFAULT;
    pstHdlcConf->ulHdlcFrmIntLimit = HDLC_FRM_INTERRUPT_LIMIT_DEFAULT;


    PPP_HDLC_HARD_MEM_CPY(&(pstHdlcConf->stFrmConfig), sizeof(PPP_DRIVER_HDLC_HARD_FRM_CONFIG_STRU),
                            pstFrmConfig, sizeof(PPP_DRIVER_HDLC_HARD_FRM_CONFIG_STRU));
    PPP_HDLC_HARD_MEM_CPY(&(pstHdlcConf->stDefConfig), sizeof(PPP_DRIVER_HDLC_HARD_DEF_CONFIG_STRU),
                            pstDefConfig, sizeof(PPP_DRIVER_HDLC_HARD_DEF_CONFIG_STRU));

#if ((SC_CTRL_MOD_KIRIN970_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_M533 == SC_CTRL_MOD))
    if (VOS_TRUE == PPP_Driver_HdlcHardGetPeriphClkStatus())
    {
        /* Boston版本中配置封装信息域最大长度寄存器0x5DF(1503)Bytes */
        PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_FRM_INFO_MAX_LEN_ADDR(HDLC_IP_BASE_ADDR), HDLC_MAX_FRM_DEF_INFO_LEN);
        PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_INFO_MAX_LEN_ADDR(HDLC_IP_BASE_ADDR), HDLC_MAX_FRM_DEF_INFO_LEN);
    }

    PPP_Driver_HdlcHardPeriphClkClose();

#endif

    return VOS_OK;
}    /* link_HDLCInit */


/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardWorkStatus
 功能描述  : 获取HDLC工作状态
 输入参数  : 无
 输出参数  : penFrmWork     - 封装工作状态
             penDefWork     - 解封装工作状态
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardWorkStatus
(
    VOS_BOOL                           *penFrmWork,
    VOS_BOOL                           *penDefWork
)
{
    VOS_UINT32                          ulFrmValue;
    VOS_UINT32                          ulDefValue;

    /* SoC会在处理完一套输入链表的时候自动将使能位清零 */
    ulFrmValue = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_EN_ADDR(HDLC_IP_BASE_ADDR));
    ulDefValue = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_EN_ADDR(HDLC_IP_BASE_ADDR));

    if (0x01 == (ulFrmValue & 0x01))
    {
        *penFrmWork = VOS_TRUE;
    }
    else
    {
        *penFrmWork = VOS_FALSE;
    }

    if (0x01 == (ulDefValue & 0x01))
    {
        *penDefWork = VOS_TRUE;
    }
    else
    {
        *penDefWork = VOS_FALSE;
    }

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardSetDefIntLimit
 功能描述  : 设置解封装中断水线
 输入参数  : ulIntLimit - 中断水线
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardSetDefIntLimit(VOS_UINT32 ulIntLimit)
{
    PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU  *pstHdlcConf = PPP_DRIVER_HDLC_HARD_GET_CONFIG;

    pstHdlcConf->ulHdlcDefIntLimit = ulIntLimit;

    return pstHdlcConf->ulHdlcDefIntLimit;
}


/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHradSetFrmIntLimit
 功能描述  : 设置封装中断水线
 输入参数  : ulIntLimit - 中断水线
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHradSetFrmIntLimit(VOS_UINT32 ulIntLimit)
{
    PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU  *pstHdlcConf = PPP_DRIVER_HDLC_HARD_GET_CONFIG;

    pstHdlcConf->ulHdlcFrmIntLimit = ulIntLimit;

    return pstHdlcConf->ulHdlcFrmIntLimit;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardCommCfgReg
 功能描述  : 配置通用寄存器
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardCommCfgReg(VOS_VOID)
{
    /*
    prior_timeout_ctrl(0x04)
      31  24   23                16   15  9         8             7   2    1          0
    |--------|----------------------|-------|-------------------|-------|---------------|
    |   Rsv  | axireq_timeout_value |  Rsv  | axireq_timeout_en |  Rsv  |hdlc_prior_ctrl|

    Reserved             [31:24] 8'b0   h/s R/W  保留位。读时返回0。写时无影响。
    axireq_timeout_value [23:16] 8'b0   h/s R/W  软件配置AXI总线读写请求超时的判断值
    Reserved             [15:9]  2'b0   h/s R/W  保留位。读时返回0。写时无影响。
    axireq_timeout_en    [8]     1'b0   h/s R/W  是否允许硬件判断AXI总线读写请求超时，由软件配置：
                                                   0不允许
                                                   1允许
    Reserved             [7:2]   1'b0   h/s R/W  保留位。读时返回0。写时无影响。
    hdlc_prior_ctrl      [1:0]   1'b0   h/s R/W  HDLC封装、解封装优先级配置寄存器：
                                                    00：一个在工作中，另一个也被使能情况下，先将已处于工作中的那个处理完，
                                                        即谁先被使能则先将谁处理完；
                                                    01：下行封装优先级高；
                                                    10：上行解封装优先级高；
                                                    11：无效。
                                                    (HDLC内部控制被暂停者的继续开始工作：当解封装被暂停，封装整套链表被处理完后，
                                                    解封装就开始继续工作；当封装被暂停，解封装整个数据包被处理完后，封装就开始继续工作。)
    */

    VOS_UINT32                          ulValue = 0x0;


    /* 使能AXI请求超时判断，debug时使用，由于HDLC设置超时时间过短，故正常功能模式下不开启 */
/*    SET_BIT_TO_DWORD(ulValue, 8); */

    /* 设置AXI请求超时时长，该值由SoC提供，并且保证无平台差异 */
    ulValue |= (HDLC_AXI_REQ_TIMEOUT_VALUE << 16);

    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_PRIROR_TIMEOUT_CTRL_ADDR(HDLC_IP_BASE_ADDR), ulValue);

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardCommWaitSem
 功能描述  : 等待封装解封装暂停或完成
 输入参数  : ulHdlcMasterSem    -       等待封装或解封装信号量
             ulSemTimeoutLen    -       等待封装或解封装响应中断时间
 输出参数  :
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
/*lint -e{454} VOS_SmP语句屏蔽, 正常机制 */
VOS_UINT32 PPP_Driver_HdlcHardCommWaitSem
(
    VOS_UINT32          ulHdlcMasterSem,
    VOS_UINT32          ulSemTimeoutLen
)
{
    VOS_UINT32                          ulResult;

    /* 等待封装或解封装完成 */
    ulResult = VOS_SmP(ulHdlcMasterSem, ulSemTimeoutLen);

    if (VOS_OK != ulResult)
    {
        PPP_HDLC_WARNING_LOG2("PPP_HDLC_HARD_CommWaitSem, WARNING, VOS_SmP ulHdlcMasterSem 0x%x failed! ErrorNo = 0x%x\r\n",
                      ulHdlcMasterSem, ulResult);

        g_PppHdlcHardStat.usDefExpInfo |=   (1 << HDLC_SEM_TIMEOUT_IND_BITPOS);
        g_PppHdlcHardStat.usFrmExpInfo |=   (1 << HDLC_SEM_TIMEOUT_IND_BITPOS);

        return VOS_ERR;
    }

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardFrmCfgBufReg
 功能描述  : 配置封装使用的内存至相关寄存器
 输入参数  : pstFrmBuffInfo -   封装使用的内存信息
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月20日
    作    者   : c00191211
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardFrmCfgBufReg(VOS_VOID)
{
    PPP_DRIVER_HDLC_HARD_FRM_CONFIG_STRU   *pstFrmConf;

    pstFrmConf = PPP_DRIVER_HDLC_HARD_GET_FRM_CONF;

    /* 将封装输入参数链表的起始地址配置给寄存器frm_in_lli_addr */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_FRM_IN_LLI_ADDR(HDLC_IP_BASE_ADDR),
            (VOS_UINT32)pstFrmConf->pInputAddr);

    /* 将封装输出参数链表的起始地址配置给寄存器frm_out_lli_addr */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_FRM_OUT_LLI_ADDR(HDLC_IP_BASE_ADDR),
            (VOS_UINT32)pstFrmConf->pOutputAddr);

    /* 将封装有效帧结果信息上报空间起始地址配置给寄存器frm_rpt_addr */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_FRM_RPT_ADDR(HDLC_IP_BASE_ADDR),
            (VOS_UINT32)pstFrmConf->pReportAddr);

    /* 将封装有效帧结果信息上报空间深度配置给寄存器frm_rpt_dep的[15:0]位 */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_FRM_RPT_DEP_ADDR(HDLC_IP_BASE_ADDR),
                    (VOS_UINT32)(pstFrmConf->ulRptBufLen & 0xFFFF));

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardFrmCfgReg
 功能描述  : IP模式下配置封装相关寄存器
 输入参数  : ulAccmFlag     -       同异步控制字
             ulFrmCfg       -       解封装配置
 输出参数  :
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月20日
    作    者   : c00191211
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardFrmCfgReg
(
    PPP_DRIVER_HDLC_HARD_FRM_PARA_STRU *pstDrvFrmPara
)
{
    VOS_UINT32                          ulFrmCfg = 0;

    /*
    hdlc_frm_cfg   (0x20)
      31              16 15           4 3      2   1      0
    |-------------------|--------------|--------|------|------|
    |      protocol     |      Rsv     |   Pfc  | Acfc |1dor2d|

    frm_protocol         [31:16] 16'b0   h/s R/W  封装协议值。有效协议值规定参见规格列表。
    Reserved             [15:4]  12'b0   h/s R/W  保留位。读时返回0。写时无影响。
    frm_pfc              [3:2]   2'b0    h/s R/W  P域压缩指示：00：硬件模块添加P域，P域无压缩;
                                                               01：硬件模块添加P域，P域压缩;
                                                               11：硬件模块不添加P域;
                                                               其他：无效;
    frm_acfc             [1]     1'b0    h/s R/W  AC域压缩指示：0：AC域无压缩;1：表示AC域压缩;
    frm_in_lli_1dor2d    [0]     1'b0    h/s R/W  封装输入一维或二维链表选择指示寄存器：
                                                                0为一维;1为二维;
    */

    ulFrmCfg |= (pstDrvFrmPara->ulPppPcFlag << HDLC_FRM_PFC_BITPOS);
    if (HDLC_ADDRESS_CTRL_COMPRESS == pstDrvFrmPara->ulPppAcFlag)
    {
        TTF_SET_A_BIT(ulFrmCfg, HDLC_FRM_ACFC_BITPOS);
    }
    ulFrmCfg |= ( ((VOS_UINT32)pstDrvFrmPara->usProtocol) << 16 );

    /* 将寄存器hdlc_frm_cfg的[0]位frm_in_lli_1dor2d配置为0 */

    /* 配置hdlc_frm_cfg的 P域和 AC域 */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_FRM_ACCM_ADDR(HDLC_IP_BASE_ADDR), pstDrvFrmPara->ulAccmFlag);

    /* 配置寄存器hdlc_frm_cfg的[31:16]位frm_protocol为usProtocol */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_FRM_CFG_ADDR(HDLC_IP_BASE_ADDR), ulFrmCfg);

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardTraceRegConfig
 功能描述  : 勾取寄存器配置数据
 输入参数  : ulEnable   -   封装解封装使能前还是使能后，VOS_TRUE: 使能后,VOS_FALSE: 使能前
             ulValue    -   使能寄存器配置的值
             ulEnableInterrupt - 中断方式还是轮询方式，仅在使能后勾取寄存器时生效
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月20日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardTraceFrmRegConfig
(
    VOS_UINT32                              ulEnable,
    VOS_UINT32                              ulValue,
    VOS_UINT32                              ulEnableInterrupt,
    PPP_DRIVER_HDLCHARD_FRM_REG_INFO_STRU  *pstFrmRegInfo
)
{
    HDLC_MNTN_FRM_REG_CONFIG_STRU           stRegMntn;
    PPP_DRIVER_HDLCHARD_FRM_REG_INFO_STRU  *pstRegConfig = &(stRegMntn.stFrmRegInfo);
    VOS_UINT32                              ulDataLen;

    /* 内部调用保证参数非空 */

    if (VOS_TRUE == PPP_HDLC_HARD_MntnGetConfig(PPP_HDLC_MNTN_TRACE_REG))
    {
        ulDataLen    = sizeof(HDLC_MNTN_FRM_REG_CONFIG_STRU);

        /* 拷贝全部寄存器内容 */
        PPP_HDLC_HARD_MEM_CPY(pstRegConfig, sizeof(PPP_DRIVER_HDLCHARD_FRM_REG_INFO_STRU),
                     pstFrmRegInfo, sizeof(PPP_DRIVER_HDLCHARD_FRM_REG_INFO_STRU));

        /* 使能前勾包，使能寄存器还没有配置，因为配置之后HDLC会开始工作，会改变其他寄存器的值 */
        if( VOS_FALSE == ulEnable )
        {
            pstRegConfig->ulHdlcFrmEn    = ulValue;
            PPP_HDLC_HARD_MntnTraceMsg((HDLC_MNTN_TRACE_HEAD_STRU *)&stRegMntn,
                                       ID_HDLC_MNTN_FRM_REG_BEFORE_EN, ulDataLen);
        }
        else
        {
            /* 使能后勾包时，如果采用中断方式，则RawInt和Status取g_stHdlcRegSaveInfo保存的值 */
            if( VOS_TRUE == ulEnableInterrupt )
            {
                pstRegConfig->ulHdlcFrmRawInt   = g_stHdlcRegSaveInfo.ulHdlcFrmRawInt;
                pstRegConfig->ulHdlcFrmStatus   = g_stHdlcRegSaveInfo.ulHdlcFrmStatus;
            }
            PPP_HDLC_HARD_MntnTraceMsg((HDLC_MNTN_TRACE_HEAD_STRU *)&stRegMntn,
                                       ID_HDLC_MNTN_FRM_REG_AFTER_EN, ulDataLen);
        }
    }

    return;
}


/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardFrmCfgEnReg
 功能描述  : 配置使能寄存器
 输入参数  : ulTotalLen --待封装数据包的总长度
 输出参数  :
 返 回 值  : VOS_TRUE   - 采用中断模式
             VOS_FALSE  - 采用轮询模式
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月20日
    作    者   : c00191211
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardFrmCfgEnReg(VOS_UINT32 ulTotalLen)
{
    PPP_DRIVER_HDLCHARD_FRM_REG_INFO_STRU   stRegConfig;


    /*
    1.hdlc_frm_en   (0x10)
      31   25 24  23 18 17  16  15  14  13  12  11  10   9   8  7    1  0
    |--------|---|-----|---|---|---|---|---|---|---|---|---|---|------|---|
    |   Rsv  |en | Rsv |en |en |en |en |en |en |en |en |en |en |  Rsv |en |

    Reserved            [31:25] 7'b0    h/s R/W  保留位。读时返回0。写时无影响。
    frm_over_int_en     [24]    1'b0    h/s R/W  一套链表封装结束中断使能;0：中断禁止;1：中断使能;
    Reserved            [23:18] 6'b0    h/s R/W  保留位。读时返回0。写时无影响。
    frm_rpt_dep_err_en  [17]    1'b0    h/s R/W  封装外部正确帧长度上报空间不足中断使能;0：中断禁止;1：中断使能;
    frm_out_spc_err_en  [16]    1'b0    h/s R/W  封装外部输出存储空间不足中断使能;0：中断禁止;1：中断使能
    frm_rpt_prm_err_en  [15]    1'b0    h/s R/W  封装上报空间相关参数错误中断使能;0：中断禁止;1：中断使能
    frm_out_prm_err_en  [14]    1'b0    h/s R/W  封装输出链表相关参数错误中断使能;0：中断禁止;1：中断使能
    frm_in_prm_err_en   [13]    1'b0    h/s R/W  封装输入链表相关参数错误中断使能;0：中断禁止;1：中断使能
    frm_cfg_err_en      [12]    1'b0    h/s R/W  封装协议及其压缩指示配置错误中断使能;0：中断禁止;1：中断使能
    frm_wr_timeout_en   [11]    1'b0    h/s R/W  封装时AXI总线写请求timeout中断使能;0：中断禁止;1：中断使能
    frm_rd_timeout_en   [10]    1'b0    h/s R/W  封装时AXI总线读请求timeout中断使能;0：中断禁止;1：中断使能
    frm_wr_err_en       [9]     1'b0    h/s R/W  封装时AXI总线写操作错误中断使能;0：中断禁止;1：中断使能
    frm_rd_err_en       [8]     1'b0    h/s R/W  封装时AXI总线读操作错误中断使能;0：中断禁止;1：中断使能
    Reserved            [7:1]   7'b0    h/s R/W  保留位。读时返回0。写时无影响。
    frm_en              [0]     1'b0    h/s R/W  一套链表封装使能，软件向frm_en写入1'b1启动封装工作;一套链表封装完成后，由硬件自动对frm_en清零；
                                                 封装过程出错时，硬件也会对frm_en自动清零，使内部状态机返回IDLE状态；
                                                 写时设置一套链表封装使能;0：不使能封装处理;1：使能封装处理;
                                                 读时返回一套链表封装处理状态;0：没在进行封装处理;1：正在进行封装处理。
    */

    VOS_UINT32          ulEnableInterrupt;
    VOS_UINT32          ulValue;
    const VOS_UINT32    ulInterruptValue    = 0x0103FF01;   /* 使用中断方式时配置使能寄存器的值 */
    const VOS_UINT32    ulPollValue         = 0x01;         /* 使用轮询方式时配置使能寄存器的值 */


    /* 判断待封装数据的总长度，若大于门限则使用中断方式，否则使用轮询方式 */
    if( ulTotalLen > HDLC_FRM_INTERRUPT_LIMIT )
    {
        /* 配置封装相关使能寄存器hdlc_frm_en的[31:0]位为0x0103FF01 */
        ulValue             = ulInterruptValue;
        ulEnableInterrupt   = VOS_TRUE;

        g_PppHdlcHardStat.ulFrmWaitIntCnt++;
    }
    else
    {
        /* 配置封装相关使能寄存器hdlc_frm_en的[31:0]位为0x01 */
        ulValue             = ulPollValue;
        ulEnableInterrupt   = VOS_FALSE;

        g_PppHdlcHardStat.ulFrmWaitQueryCnt++;
    }

    /* 使能前清除上次封装、解封装的原始中断 */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_INT_CLR_ADDR(HDLC_IP_BASE_ADDR), 0xFFFFFFFFU);
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_FRM_INT_CLR_ADDR(HDLC_IP_BASE_ADDR), 0xFFFFFFFFU);

    /* 上报寄存器可维可测 */
    PPP_Driver_HdlcHardGetFrmRegInfo(&stRegConfig);
    PPP_Driver_HdlcHardTraceFrmRegConfig(VOS_FALSE, ulValue, ulEnableInterrupt, &stRegConfig);

    /* 使能硬件之前先强制ARM顺序执行结束前面的指针 */
    TTF_FORCE_ARM_INSTUCTION();

    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_FRM_EN_ADDR(HDLC_IP_BASE_ADDR), ulValue);

    return ulEnableInterrupt;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardFrmWaitStatusChange
 功能描述  : 轮询状态寄存器
 输入参数  : 无
 输出参数  :
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardFrmWaitStatusChange(VOS_VOID)
{
    VOS_UINT32              ulFrmRsltWaitNum;           /* 防止硬件异常的保护变量 */
    volatile VOS_UINT32     ulFrmStatus = 0;            /* 封装状态 */


   /* 查询hdlc_frm_status (0x28)的第[0]位和第[1]位，任何一个为1或者超时则返回 */
    ulFrmRsltWaitNum = 0UL;

    while (ulFrmRsltWaitNum < HDLC_FRM_MAX_WAIT_RESULT_NUM)
    {
        /* 读取 hdlc_frm_status的[0][1]位 */
        ulFrmStatus  =   PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_STATUS_ADDR(HDLC_IP_BASE_ADDR));

        if (HDLC_FRM_ALL_PKT_DOING != (ulFrmStatus & HDLC_FRM_STATUS_MASK))
        {
            break;
        }

        ulFrmRsltWaitNum++;
    }

    if ( HDLC_FRM_MAX_WAIT_RESULT_NUM <= ulFrmRsltWaitNum )
    {
        PPP_HDLC_WARNING_LOG2("PPP_HDLC_HARD_FrmWaitStatusChange, WARNING, wait hdlc_frm_status timeout %d status 0x%x!\r\n",
                      ulFrmRsltWaitNum, ulFrmStatus);

        g_PppHdlcHardStat.usFrmExpInfo |=   (1 << HDLC_WAIT_STATUS_TIMEOUT_IND_BITPOS);

        return VOS_ERR;
    }

    g_PppHdlcHardStat.ulFrmMaxQueryCnt = TTF_MAX(g_PppHdlcHardStat.ulFrmMaxQueryCnt, ulFrmRsltWaitNum);

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardFrmWaitResult
 功能描述  : 等待封装暂停或完成
 输入参数  : ulEnableInterrupt  -   中断是否使能
 输出参数  : 无
 返 回 值  : 封装状态
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月20日
    作    者   : c00191211
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardFrmWaitResult
(
    VOS_UINT32                              ulEnableInterrupt
)
{
    VOS_UINT32                              ulFrmStatus;        /* 封装状态 */
    VOS_UINT32                              ulResult;
    PPP_DRIVER_HDLCHARD_FRM_REG_INFO_STRU   stRegConfig;
    PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU  *pstHdlcConf = PPP_DRIVER_HDLC_HARD_GET_CONFIG;


    if (VOS_TRUE == ulEnableInterrupt)
    {
        /* 等待中断得到出错或完成状态 */
        ulResult = PPP_Driver_HdlcHardCommWaitSem(pstHdlcConf->ulHdlcFrmMasterSem, HDLC_FRM_MASTER_INT_TIMER_LEN);

        /* 由于在中断服务程序中进行了清中断操作，而Status指示是否出错的bit由原始中断寄存器
           决定，故此处取保存在g_stHdlcRegSaveInfo中的状态值 */
        ulFrmStatus = g_stHdlcRegSaveInfo.ulHdlcFrmStatus;
    }
    else
    {
        /* 轮询得到出错或完成 */
        ulResult = PPP_Driver_HdlcHardFrmWaitStatusChange();

        /* 查询hdlc_frm_status (0x28)获取封装状态并将其返回 */
        ulFrmStatus  =  PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_STATUS_ADDR(HDLC_IP_BASE_ADDR));
    }

    /* 上报寄存器可维可测 */
    PPP_Driver_HdlcHardGetFrmRegInfo(&stRegConfig);
    PPP_Driver_HdlcHardTraceFrmRegConfig(VOS_TRUE, 0, ulEnableInterrupt, &stRegConfig);

    /* 等不到说明HDLC还在工作 */
    if (VOS_OK != ulResult)
    {
        return HDLC_FRM_ALL_PKT_DOING;
    }

    ulFrmStatus &=  HDLC_FRM_STATUS_MASK;

    return ulFrmStatus;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardFrmEnable
 功能描述  : 配置封装寄存器并使能封装功能
 输入参数  : pstDrvFrmPara      -   封装参数
 输出参数  : pulEnableInterrupt -   中断是否使能
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardFrmEnable
(
    PPP_DRIVER_HDLC_HARD_FRM_PARA_STRU *pstDrvFrmPara,
    VOS_UINT32                         *pulEnableInterrupt
)
{
    VOS_UINT32                          ulFrmStatus;
    VOS_UINT32                          ulEnableInterrupt;

    /* 配置封装、解封装通用寄存器 */
    PPP_Driver_HdlcHardCommCfgReg();

    /* 配置内存相关寄存器 */
    PPP_Driver_HdlcHardFrmCfgBufReg();

    /* 配置封装相关寄存器 */
    PPP_Driver_HdlcHardFrmCfgReg(pstDrvFrmPara);

    /* 配置使能寄存器，并上报使能前寄存器可维可测 */
    ulEnableInterrupt = PPP_Driver_HdlcHardFrmCfgEnReg(pstDrvFrmPara->ulInputTotalSize);

    *pulEnableInterrupt = ulEnableInterrupt;

    ulFrmStatus = PPP_Driver_HdlcHardFrmWaitResult(ulEnableInterrupt);

    return ulFrmStatus;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardGetFrmResult
 功能描述  : 获取封装结果
 输入参数  : 无
 输出参数  : pusFrmOutSegNum    -   有效帧存放占用片段个数
             pucFrmValidNum     -   有效帧个数
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月20日
    作    者   : c00191211
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardGetFrmResult
(
    VOS_UINT16                         *pusFrmOutSegNum,
    VOS_UINT8                          *pucFrmValidNum
)
{
    /* 有效帧存放占用片段个数usFrmOutSegNum= hdlc_frm_status寄存器[31:16]位的值 */
    *pusFrmOutSegNum = (VOS_UINT16)TTF_Read32RegByBit(SOC_ARM_HDLC_FRM_STATUS_ADDR(HDLC_IP_BASE_ADDR), 16, 31);

    /* 有效帧个数usFrmValidNum= hdlc_frm_status寄存器[15:8]位的值 */
    *pucFrmValidNum  = (VOS_UINT8)TTF_Read32RegByBit(SOC_ARM_HDLC_FRM_STATUS_ADDR(HDLC_IP_BASE_ADDR), 8, 15);

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardGetFrmRawInt
 功能描述  : 获取封装中断寄存器值
 输入参数  : 无
 输出参数  : 无
 返 回 值  : VOS_UINT32  封装中断寄存器值
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月20日
    作    者   : c00191211
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardGetFrmRawInt(VOS_VOID)
{
    VOS_UINT32                          ulRawInt;

    ulRawInt  =   PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_RAW_INT_ADDR(HDLC_IP_BASE_ADDR));

    return ulRawInt;
}


/************************************************************,*****************
 函 数 名  : PPP_Driver_HdlcHardDefCfgBufReg
 功能描述  : 配置解封装使用的内存至相关寄存器
 输入参数  : pstDrvDefPara    -   解封装使用的内存信息
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardDefCfgBufReg(VOS_VOID)
{
    PPP_DRIVER_HDLC_HARD_DEF_CONFIG_STRU   *pstDefConf;

    pstDefConf = PPP_DRIVER_HDLC_HARD_GET_DEF_CONF;

    /* 将封装输入参数链表的起始地址配置给寄存器def_in_lli_addr(0x90) */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_IN_LLI_ADDR(HDLC_IP_BASE_ADDR),
                    (VOS_UINT32)pstDefConf->pInputAddr);

    /* 将封装输出参数链表的起始地址配置给寄存器def_out_spc_addr(0xA0) */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_OUT_SPC_ADDR(HDLC_IP_BASE_ADDR),
                    (VOS_UINT32)pstDefConf->pOutputAddr);

    /* 将封装输出参数链表的起始地址配置给寄存器def_out_space_dep(0xA4)低16位 */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_OUT_SPACE_DEP_ADDR(HDLC_IP_BASE_ADDR),
                    (VOS_UINT32)(pstDefConf->ulOutputBufLen & 0xFFFF));

#ifndef PPPC_HDLC_NOC_ST_TEST
    /* 将封装有效帧结果信息上报空间起始地址配置给寄存器def_rpt_addr(0xA8) */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_RPT_ADDR(HDLC_IP_BASE_ADDR),
                    (VOS_UINT32)pstDefConf->pReportAddr);
#else
    /* 用于NOC测试,将CDSP的Resv空间0xE39D9000配置给HDLC */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_RPT_ADDR(HDLC_IP_BASE_ADDR), 0xE39D9000);
#endif

    /* 将封装有效帧结果信息上报空间深度配置给寄存器def_rpt_dep (0xAC)低16位 */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_RPT_DEP_ADDR(HDLC_IP_BASE_ADDR),
                    (VOS_UINT32)(pstDefConf->ulReportBufLen & 0xFFFF));

    return;
}


/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardDefCfgReg
 功能描述  : 配置解封装配置寄存器
 输入参数  : pstDrvDefPara    -   解封装参数信息
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardDefCfgReg
(
    PPP_DRIVER_HDLC_HARD_DEF_PARA_STRU *pstDrvDefPara
)
{
    PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU *pstUncompleteInfo;
    PPP_DRIVER_HDLC_HARD_DEF_CONFIG_STRU           *pstDefConf;
    VOS_UINT32                                      ulDefCfg = 0;


    /*
        hdlc_def_cfg  (0x70)
         31                           4 3     2   1     0
        |-------------------------------|-------|-----|-----|
        |              Rsv              |  Pfc  | Acfc| ago |
        Reserved             [31:4]  28'b0   h/s R/W  保留位。读时返回0。写时无影响。
        def_pfc              [3:2]   2'b0    h/s R/W  P域压缩指示：00：P域无压缩，需剥离；01：P域压缩，需剥离；11：P域不剥离；其他：无效；
        def_acfc             [1]     1'b0    h/s R/W  AC域压缩指示：0：AC域无压缩；1：表示AC域压缩；
        def_uncompleted_ago  [0]     1'b0    h/s R/W  用于指示对应当前解封装输入链表，同一PPP/IP拨号的以前最近解封装输入链表是否有解出非完整帧，
                                                      为了支持多个PPP/IP拨号而增加的配置：0，没有；1，有
        */

    pstDefConf = PPP_DRIVER_HDLC_HARD_GET_DEF_CONF;

    ulDefCfg |= pstDrvDefPara->ulPppPcFlag << HDLC_DEF_PFC_BITPOS;

    if (HDLC_ADDRESS_CTRL_COMPRESS == pstDrvDefPara->ulPppAcFlag)
    {
        TTF_SET_A_BIT(ulDefCfg, HDLC_DEF_ACFC_BITPOS);
    }

    /* 设置非完整帧相关信息 */
    pstUncompleteInfo = pstDrvDefPara->pstUncompleteInfo;
    if ((VOS_NULL_PTR != pstUncompleteInfo)
        && (HDLC_DEF_UNCOMPLETED_EXIST == pstUncompleteInfo->ucExistFlag))
    {
        /*
        def_uncompleted_len  (0x74)
         31                 16  15                  0
        |---------------------|----------------------|
        |         Rsv         |         Len          |
        Reserved             [31:16] 16'b0   h/s R/W  保留位。读时返回0。写时无影响。
        def_uncompleted_len  [15:0]  16'b0   h/s R/W  对应当前解封装输入链表，同一PPP/IP拨号的以前最近解封装输入链表解出非完整帧的长度，为了支持多个PPP/IP拨号而增加的配置
        */
        PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_UNCOMPLETED_LEN_ADDR(HDLC_IP_BASE_ADDR),
                        (VOS_UINT32)pstUncompleteInfo->usDefOutOneLen & 0xFFFF);

        /*
        def_uncompleted_pro  (0x78)
         31                 16  15                  0
        |---------------------|----------------------|
        |         Rsv         |         Pro          |
        Reserved             [31:16] 16'b0   h/s R/W  保留位。读时返回0。写时无影响。
        def_uncompleted_pro  [15:0]  16'b0   h/s R/W  对应当前解封装输入链表，同一PPP/IP拨号的以前最近解封装输入链表解出非完整帧的
                                                      协议，为了支持多个PPP/IP拨号而增加的配置（可能其中的0Byte、1Byte或2Byte有效）
        */
        PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_UNCOMPLETED_PRO_ADDR(HDLC_IP_BASE_ADDR),
                        (VOS_UINT32)pstUncompleteInfo->usDefOutOnePro & 0xFFFF);

        /*
        def_uncompleted_addr  (0x7C)
         31                  0
        |----------------------|
        |         Addr         |
        def_uncompleted_addr [31:0]  32'b0   h/s R/W  对应当前解封装输入链表，同一PPP/IP拨号的以前最近解封装输入链表解出非完整帧的
                                                      外部存储起始地址，为了支持多个PPP/IP拨号而增加的配置（该地址可能是与原来上报不同的新地址）
        */
        PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_UNCOMPLETED_ADDR(HDLC_IP_BASE_ADDR),
                        (VOS_UINT32)pstUncompleteInfo->pucDefOutOneAddr);

        /*
        def_uncomplet_st_ago  (0x80)
         31                  16 15             5 4     0
        |----------------------|----------------|-------|
        |         Ago          |       Rsv      |  Ago  |
        crc16_result_ago     [31:16] 16'b0   h/s R/W  与当前解封装输入链表同一PPP/IP拨号的以前最近那套解封装输入链表处理完解出非完整帧时的CRC校验值
        Reserved             [15:5]  11'b0   h/s R/W  保留位。读时返回0。写时无影响。
        def_data_st_curr_ago [4:0]   5'b0    h/s R/W  与当前解封装输入链表同一PPP/IP拨号的以前最近那套解封装输入链表处理完解出非完整帧时的数据状态机当前状态
        */
        PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_UNCOMPLETED_ST_AGO_ADDR(HDLC_IP_BASE_ADDR),
                        (VOS_UINT32)pstUncompleteInfo->ulDefStAgo);

        /*
        def_info_frl_cnt_ago  (0xC0)
         31        27 26                 16 15   11 10              0
        |------------|---------------------|-------|-----------------|
        |    Rsv     |         Ago         |  Rsv  |       Ago       |
        Reserved             [31:27] 5'b0    h/s R/W  保留位。读时返回0。写时无影响。
        def_framel_cnt_ago   [26:16] 11'b0   h/s R/W  与当前解封装输入链表同一PPP/IP拨号的以前最近那套解封装输入链表处理完解出非完整帧时的帧长度
        Reserved             [15:11] 5'b0    h/s R/W  保留位。读时返回0。写时无影响。
        def_info_cnt_ago     [10:0]  11'b0   h/s R/W  与当前解封装输入链表同一PPP/IP拨号的以前最近那套解封装输入链表处理完解出非完整帧时的信息长度
        */
        PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_INFO_FRL_CNT_AGO_ADDR(HDLC_IP_BASE_ADDR),
                        (VOS_UINT32)pstUncompleteInfo->ulDefInfoFrlCntAgo);

        TTF_SET_A_BIT(ulDefCfg, HDLC_DEF_IS_UNCOMPLETED_AGO_BITPOS);
    }

    /* 根据ulMode、P域和AC域是否压缩配置hdlc_def_cfg (0x70) */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_CFG_ADDR(HDLC_IP_BASE_ADDR), ulDefCfg);

    /* 设置输入数据最大单包长度 */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_IN_PKT_LEN_MAX_ADDR(HDLC_IP_BASE_ADDR),
                    (VOS_UINT32)pstDefConf->ulPerInMaxLen);

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardDefWaitStatusChange
 功能描述  : 轮询状态寄存器
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardDefWaitStatusChange(VOS_VOID)
{
    /*
    hdlc_def_status  (0x88)
      31 30   24 23   8 7 6  5   4   3   2  1  0
    |---|-------|------|---|---|---|---|---|----|
    |Rsv|  Type |  Num |Rsv|Idx|Ful|Ful|Now|Stat|
    Reserved             [31]    1'b0    h/s R/W  保留位。读时返回0。写时无影响。
    def_err_type         [30:24] 7'b0    h/s RO   有帧上报时，错误帧类型，对应的bit位为1即表明发生该类型错误：
                                                  bit 30：错误类型6，转义字符0x7D后紧接一个Flag域；
                                                  bit 29：错误类型5，当AC域无压缩时，Address域值非0xFF；
                                                  bit 28：错误类型4，当AC域无压缩时，Control域值非0x03；
                                                  bit 27：错误类型3，当P域需剥离时，收到非法的Protocol域值；
                                                  bit 26：错误类型2，解封装后帧字节数小于4bites；
                                                  bit 25：错误类型1，解封装后帧字节数大于1502bytes（PPP帧的Information域不超过1500Bytes，加上协议域不超过1502Bytes）；
                                                  bit 24：错误类型0， CRC校验错误。
    def_valid_num        [23:8]  16'b0   h/s RO   有帧上报时，有效帧数目；（不包括最后一个可能的非完整帧）
    Reserved             [7:6]   2'b0    h/s R/W  保留位。读时返回0。写时无影响。
    def_error_index      [5]     1'b0    h/s RO   解封装发生错误指示
    def_rpt_ful          [4]     1'b0    h/s RO   解封装外部正确帧信息上报空间存满暂停指示
    def_out_spc_ful      [3]     1'b0    h/s RO   解封装外部输出存储空间存满暂停指示
    def_uncompleted_now  [2]     1'b0    h/s RO   用于指示当前链表是否有解出非完整帧，为了支持多个PPP/IP拨号而增加的配置：0，没有；1，有
    def_all_pkt_pro_stat [1:0]   2'b0    h/s RO   一套输入链表处理状态：00：未完成一套输入链表处理；01：未完成一套输入链表处理，已解出LCP帧，硬件处于暂停状态；
                                                  10：完成一套输入链表处理，但无帧上报；11: 完成一套输入链表处理，且有帧上报；
    */
    VOS_UINT32              ulRsltWaitNum;           /* 防止硬件异常的保护变量 */
    volatile VOS_UINT32     ulStatus = 0;            /* 解封装状态 */

   /* 查询hdlc_frm_status (0x28)的第[0]位和第[1]位，任何一个为1或者超时则返回 */

    ulRsltWaitNum = 0UL;

    while (ulRsltWaitNum < HDLC_DEF_MAX_WAIT_RESULT_NUM)
    {
        /* 查询状态寄存器hdlc_def_status (0x88)的0-1和3-5位，任何一位变为1表示解封装模块暂停或停止 */
        ulStatus  =   PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_STATUS_ADDR(HDLC_IP_BASE_ADDR));

        if (HDLC_DEF_STATUS_DOING != (ulStatus & HDLC_DEF_STATUS_MASK))
        {
            break;
        }

        ulRsltWaitNum++;
    }

    if ( HDLC_DEF_MAX_WAIT_RESULT_NUM <= ulRsltWaitNum )
    {
        PPP_HDLC_WARNING_LOG2("PPP_HDLC_HARD_DefWaitStatusChange, WARNING, wait hdlc_def_status timeout %d status 0x%x!\r\n",
                      ulRsltWaitNum, ulStatus);

        g_PppHdlcHardStat.usDefExpInfo |=   (1 << HDLC_WAIT_STATUS_TIMEOUT_IND_BITPOS);

        return VOS_ERR;
    }

    g_PppHdlcHardStat.ulDefMaxQueryCnt = TTF_MAX(g_PppHdlcHardStat.ulDefMaxQueryCnt, ulRsltWaitNum);

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardTraceDefRegconfig
 功能描述  : 勾取解封装寄存器配置数据
 输入参数  : ulEnable   -   封装解封装使能前还是使能后，VOS_TRUE: 使能后,VOS_FALSE: 使能前
             ulValue    -   使能寄存器配置的值
             ulEnableInterrupt - 中断方式还是轮询方式，仅在使能后勾取寄存器时生效
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月20日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardTraceDefRegconfig
(
    VOS_UINT32                              ulEnable,
    VOS_UINT32                              ulValue,
    VOS_UINT32                              ulEnableInterrupt,
    PPP_DRIVER_HDLCHARD_DEF_REG_INFO_STRU  *pstDefRegInfo
)
{
    HDLC_MNTN_DEF_REG_CONFIG_STRU           stRegMntn;
    PPP_DRIVER_HDLCHARD_DEF_REG_INFO_STRU  *pstRegConfig = &(stRegMntn.stDefRegInfo);
    VOS_UINT32                              ulDataLen;

    /* 内部调用保证参数非空 */

    if (VOS_TRUE == PPP_HDLC_HARD_MntnGetConfig(PPP_HDLC_MNTN_TRACE_REG))
    {
        ulDataLen    = sizeof(HDLC_MNTN_DEF_REG_CONFIG_STRU);

        /* 拷贝全部寄存器内容 */
        PPP_HDLC_HARD_MEM_CPY(pstRegConfig, sizeof(PPP_DRIVER_HDLCHARD_DEF_REG_INFO_STRU),
                     pstDefRegInfo, sizeof(PPP_DRIVER_HDLCHARD_DEF_REG_INFO_STRU));

        /* 使能前勾包，使能寄存器还没有配置，因为配置之后HDLC会开始工作，会改变其他寄存器的值 */
        if( VOS_FALSE == ulEnable)
        {
            pstRegConfig->ulHdlcDefEn   = ulValue;
            PPP_HDLC_HARD_MntnTraceMsg((HDLC_MNTN_TRACE_HEAD_STRU *)&stRegMntn,
                                       ID_HDLC_MNTN_DEF_REG_BEFORE_EN, ulDataLen);
        }
        else
        {
            /* 使能后勾包时，如果采用中断方式，则RawInt和Status取g_stHdlcRegSaveInfo保存的值 */
            if( VOS_TRUE == ulEnableInterrupt )
            {
                pstRegConfig->ulHdlcDefRawInt   = g_stHdlcRegSaveInfo.ulHdlcDefRawInt;
                pstRegConfig->ulHdlcDefStatus   = g_stHdlcRegSaveInfo.ulHdlcDefStatus;
            }
            PPP_HDLC_HARD_MntnTraceMsg((HDLC_MNTN_TRACE_HEAD_STRU *)&stRegMntn,
                                       ID_HDLC_MNTN_DEF_REG_AFTER_EN, ulDataLen);
        }
    }

    return;
}


/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardDefWaitResult
 功能描述  : 等待解封装暂停或完成
 输入参数  : ulEnableInterrupt  -   中断是否使能
 输出参数  : 解封装状态
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardDefWaitResult
(
    VOS_UINT32                              ulEnableInterrupt
)
{
    VOS_UINT32                              ulStatus;                /* 解封装状态 */
    VOS_UINT32                              ulResult;
    PPP_DRIVER_HDLCHARD_DEF_REG_INFO_STRU   stRegConfig;
    PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU  *pstHdlcConf = PPP_DRIVER_HDLC_HARD_GET_CONFIG;


    if (VOS_TRUE == ulEnableInterrupt)
    {
        /* 等待中断得到暂停或完成状态 */
        ulResult = PPP_Driver_HdlcHardCommWaitSem(pstHdlcConf->ulHdlcDefMasterSem, HDLC_DEF_MASTER_INT_TIMER_LEN);

        /* 由于在中断服务程序中进行了清中断操作，而Status指示是否出错的bit由原始
           中断寄存器决定，故此处取保存在g_stHdlcRegSaveInfo中的状态值 */
        ulStatus = g_stHdlcRegSaveInfo.ulHdlcDefStatus;

    }
    else
    {
        /* 轮询得到暂停或完成 */
        ulResult = PPP_Driver_HdlcHardDefWaitStatusChange();

        /* 查询hdlc_def_status (0x88)获取解封装状态并将其返回 */
        ulStatus  =  PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_STATUS_ADDR(HDLC_IP_BASE_ADDR));
    }

    /* 上报寄存器可维可测 */
    PPP_Driver_HdlcHardGetDefRegInfo(&stRegConfig);
    PPP_Driver_HdlcHardTraceDefRegconfig(VOS_TRUE, 0, ulEnableInterrupt, &stRegConfig);

    /* 等不到说明HDLC还在工作 */
    if (VOS_OK != ulResult)
    {
        return HDLC_DEF_STATUS_DOING;
    }

    ulStatus &=  HDLC_DEF_STATUS_MASK;

    return ulStatus;
}


/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardDefCfgEnReg
 功能描述  : 根据本次解封装数据量大小，决定使用何况方式等待HDLC的结果
 输入参数  : ulLinkTotalSize     -   本次解封装参数链表内的总数据量(单位字节)
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardDefCfgEnReg
(
    VOS_UINT32                      ulTotalLen
)
{
    /*
    hdlc_def_en   (0x60)
      31   25 24  23 19 18  17  16  15  14  13  12  11  10   9   8   7   1  0
    |--------|---|-----|---|---|---|---|---|---|---|---|---|---|---|------|---|
    |   Rsv  |en | Rsv |en |en |en |en |en |en |en |en |en |en |en |  Rsv |en |

    Reserved            [31:25] 7'b0    h/s R/W  保留位。读时返回0。写时无影响。
    def_over_int_en     [24]    1'b0    h/s R/W  一套链表解封装结束中断使能;0：中断禁止;1：中断使能;
    Reserved            [23:19] 5'b0    h/s R/W  保留位。读时返回0。写时无影响。
    def_rpt_ful_en      [18]    1'b0    h/s R/W  解封装外部正确帧信息上报空间存满暂停中断使能;0：中断禁止;1：中断使能;
    def_out_spc_ful_en  [17]    1'b0    h/s R/W  解封装外部输出存储空间存满暂停中断使能;0：中断禁止;1：中断使能
    def_lcp_int_en      [16]    1'b0    h/s R/W  解封装解出有效LCP帧暂停中断上报使能;0：中断禁止;1：中断使能
    def_rpt_prm_err_en  [15]    1'b0    h/s R/W  解封装上报空间相关参数错误中断使能;0：中断禁止;1：中断使能
    def_out_prm_err_en  [14]    1'b0    h/s R/W  解封装输出空间相关参数错误中断使能;0：中断禁止;1：中断使能
    def_in_prm_err_en   [13]    1'b0    h/s R/W  解封装输入链表相关参数错误中断使能;0：中断禁止;1：中断使能
    def_cfg_err_en      [12]    1'b0    h/s R/W  解封装协议压缩指示配置错误中断使能;0：中断禁止;1：中断使能
    def_wr_timeout_en   [11]    1'b0    h/s R/W  解封装时AXI总线写请求timeout中断使能;0：中断禁止;1：中断使能
    def_rd_timeout _en  [10]    1'b0    h/s R/W  解封装时AXI总线读请求timeout中断使能;0：中断禁止;1：中断使能
    def_wr_err_en       [9]     1'b0    h/s R/W  解封装时AXI总线写操作错误中断使能;0：中断禁止;1：中断使能
    def_rd_err_en       [8]     1'b0    h/s R/W  解封装时AXI总线读操作错误中断使能;0：中断禁止;1：中断使能
    Reserved            [7:1]   7'b0    h/s R/W  保留位。读时返回0。写时无影响。
    def_en              [0]     1'b0    h/s R/W  一套输入链表解封装使能，软件向def_en写入1'b1启动解封装工作；一套输入链表解封装完成后，由硬件自动对def_en清零；
                                                 解封装过程出错时，硬件也会对def_en自动清零，使内部状态机返回IDLE状态；读该寄存器返回解封装处理状态。
                                                 写时设置一套输入链表解封装使能：0：不使能解封装处理；1：使能解封装处理；
                                                 读时返回一套输入链表解封装处理状态：0：没在进行解封装处理；1：正在进行解封装处理。
    */
    VOS_UINT32          ulEnableInterrupt;
    VOS_UINT32          ulValue;
    const VOS_UINT32    ulInterruptValue    = 0x0107FF01;   /* 使用中断方式时配置使能寄存器的值 */
    const VOS_UINT32    ulPollValue         = 0x01;         /* 使用轮询方式时配置使能寄存器的值 */
    PPP_DRIVER_HDLCHARD_DEF_REG_INFO_STRU   stRegConfig;


    if( ulTotalLen > HDLC_DEF_INTERRUPT_LIMIT )
    {
        /* 配置封装相关使能寄存器hdlc_def_en的[31:0]位为0x0107FF01 */
        ulValue             = ulInterruptValue;
        ulEnableInterrupt   = VOS_TRUE;

        g_PppHdlcHardStat.ulDefWaitIntCnt++;
    }
    else
    {
        /* 配置封装相关使能寄存器hdlc_frm_en的[31:0]位为0x01 */
        ulValue             = ulPollValue;
        ulEnableInterrupt   = VOS_FALSE;

        g_PppHdlcHardStat.ulDefWaitQueryCnt++;
    }

    /* 使能前清除上次封装、解封装的原始中断 */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_INT_CLR_ADDR(HDLC_IP_BASE_ADDR), 0xFFFFFFFFU);
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_FRM_INT_CLR_ADDR(HDLC_IP_BASE_ADDR), 0xFFFFFFFFU);

    /* 上报寄存器可维可测 */
    PPP_Driver_HdlcHardGetDefRegInfo(&stRegConfig);
    PPP_Driver_HdlcHardTraceDefRegconfig(VOS_FALSE, ulValue, ulEnableInterrupt, &stRegConfig);

    /* 使能硬件之前先强制ARM顺序执行结束前面的指针 */
    TTF_FORCE_ARM_INSTUCTION();

    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_EN_ADDR(HDLC_IP_BASE_ADDR), ulValue);

    return ulEnableInterrupt;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardDefEnable
 功能描述  : 配置解封装寄存器并使能解封装功能
 输入参数  : pstDrvDefPara      -   封装参数
 输出参数  : pulEnableInterrupt -   中断是否使能
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardDefEnable
(
    PPP_DRIVER_HDLC_HARD_DEF_PARA_STRU *pstDrvDefPara,
    VOS_UINT32                         *pulEnableInterrupt
)
{
    if ((VOS_NULL_PTR == pstDrvDefPara) || (VOS_NULL_PTR == pulEnableInterrupt))
    {
        PPP_HDLC_WARNING_LOG2("pstDrvDefPara or pulEnableInterrupt is NULL", pstDrvDefPara, pulEnableInterrupt);
        return VOS_ERR;
    }

    /* 配置封装、解封装通用寄存器 */
    PPP_Driver_HdlcHardCommCfgReg();

    /* 配置内存相关寄存器 */
    PPP_Driver_HdlcHardDefCfgBufReg();

    /* 配置压缩指示、非完整帧相关信息寄存器 */
    PPP_Driver_HdlcHardDefCfgReg(pstDrvDefPara);

    /* 配置使能寄存器 */
    *pulEnableInterrupt = PPP_Driver_HdlcHardDefCfgEnReg(pstDrvDefPara->ulInputTotalSize);

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardDefCfgGoOnReg
 功能描述  : 根据HDLC暂停状态，配置GO_ON寄存器对应比特位
 输入参数  : ulDefStatus  -   解封装状态
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardDefCfgGoOnReg
(
    VOS_UINT32          ulDefStatus
)
{
    /*
    hdlc_def_go_on  (0x84)
     31                  17  16  15    9   8  7   1  0
    |----------------------|----|-------|----|-----|----|
    |         Rsv          |Goon|  Rsv  |Goon| Rsv |Goon|
    Reserved             [31:17] 15'b0   h/s R/W  保留位。读时返回0。写时无影响。
    def_rpt_ful_goon     [16]    1'b0    h/s WO   外部解封装有效帧信息上报空间存满暂停解除
    Reserved             [15:9]  7'b0    h/s R/W  保留位。读时返回0。写时无影响。
    def_outspc_ful_goon  [8]     1'b0    h/s WO   外部解封装输出数据存储空间存满暂停状态清除
    Reserved             [7:1]   7'b0    h/s R/W  保留位。读时返回0。写时无影响。
    def_lcp_goon         [0]     1'b0    h/s WO   解出一个合法LCP帧导致的硬件暂停状态清除。当解封装模块未处理完一组待解封装的数据（<=2KB(def_in_pkt_len_max)），解出一个合法LCP帧，则会暂停解帧，等待此软件向此寄存器写"1"，再继续处理剩余的数据。
    */

    /* GO_ON前清除上次解封装的原始中断 */
    PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_INT_CLR_ADDR(HDLC_IP_BASE_ADDR), 0xFFFFFFFFU);

    if (HDLC_DEF_STATUS_PAUSE_RPT_SPACE_FULL == ulDefStatus )
    {
        PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_GO_ON_ADDR(HDLC_IP_BASE_ADDR),
                        (VOS_UINT32)0x10000);
    }
    else if (HDLC_DEF_STATUS_PAUSE_OUTPUT_SPACE_FULL == ulDefStatus )
    {
        PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_GO_ON_ADDR(HDLC_IP_BASE_ADDR),
                        (VOS_UINT32)0x100);
    }
    else if (HDLC_DEF_STATUS_PAUSE_LCP == ulDefStatus )
    {
        PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_GO_ON_ADDR(HDLC_IP_BASE_ADDR),
                        (VOS_UINT32)0x1);
    }
    else
    {
        PPP_HDLC_ERROR_LOG1("PPP_HDLC_HARD_DefCfgGoOnReg, ERROR, Wrong ulDefStatus %d!\r\n", ulDefStatus);
    }

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardGetDefVaildNum
 功能描述  : 获取解封装有效帧个数
 输入参数  : 无
 输出参数  : 无
 返 回 值  : VOS_UINT16 解封装有效帧个数
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT16 PPP_Driver_HdlcHardGetDefVaildNum(VOS_VOID)
{
    VOS_UINT16                          usValidFrameNum;

    usValidFrameNum = (VOS_UINT16)TTF_Read32RegByBit(SOC_ARM_HDLC_DEF_STATUS_ADDR(HDLC_IP_BASE_ADDR), 8, 23);

    return usValidFrameNum;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardGetDefUncompletInfo
 功能描述  : 获取解封装非完整帧信息
 输入参数  : 无
 输出参数  : pstUncompleteInfo  -   解封装非完整帧信息
             pucValidNum        -   解封装有效帧个数
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardGetDefUncompletInfo
(
    PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU *pstUncompleteInfo,
    VOS_UINT32                                     *pulValidNum
)
{
    VOS_UINT32                          ulStatus;                /* 解封装状态 */
    VOS_UINT32                          ulValidNum;


    ulStatus  =   PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_STATUS_ADDR(HDLC_IP_BASE_ADDR));

    /* 查询状态寄存器hdlc_def_status (0x88)的第2位
       为1表示本次解封装有非完整帧输出，
       为0表示无非完整帧输出 */
    if (0 == (ulStatus & 0x4))
    {
        pstUncompleteInfo->ucExistFlag = HDLC_DEF_UNCOMPLETED_NOT_EXIST;

        return;
    }

    g_PppHdlcHardStat.ulDefUncompleteCnt++;

    /* def_valid_num        [23:8]  16'b0   h/s RO   有帧上报时，有效帧数目；（不包括最后一个可能的非完整帧） */
    ulValidNum = (ulStatus & 0xFFFF00) >> 8;


    *pulValidNum = ulValidNum;
    /* 有非完整帧时需要读取并保存def_uncomplet_st_now(0x8C)、def_info_frl_cnt_now(0xC4)
       读取并保存上报空间有效帧之后的非完整帧长度、协议和数据地址 */
    pstUncompleteInfo->ucExistFlag = HDLC_DEF_UNCOMPLETED_EXIST;

    /* 软件只是暂存这些信息，等下解封装的时候再原样配给HDLC */
    pstUncompleteInfo->ulDefStAgo         = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_UNCOMPLETED_ST_NOW_ADDR(HDLC_IP_BASE_ADDR));
    pstUncompleteInfo->ulDefInfoFrlCntAgo = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_INFO_FRL_CNT_NOW_ADDR(HDLC_IP_BASE_ADDR));

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardGetDefErrorInfo
 功能描述  : 获取错误帧信息
 输入参数  : 无
 输出参数  : pstErrCnt      -   错误帧信息
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardGetDefErrorInfo
(
    PPP_DRIVER_HDLC_HARD_DEF_ERR_FRAMES_CNT_STRU   *pstErrCnt
)
{
    VOS_UINT8                           ucErrType;


    /* 查询状态寄存器hdlc_def_status (0x88)的第24:30对应比特位为1表示有某种错误帧输出，
       为0表示无帧输出 */
    ucErrType = (VOS_UINT8)TTF_Read32RegByBit(SOC_ARM_HDLC_DEF_STATUS_ADDR(HDLC_IP_BASE_ADDR) , 24, 30);

    if ((0 == ucErrType) || (VOS_NULL_PTR == pstErrCnt))
    {
        return;
    }

    PPP_HDLC_HARD_MEM_SET(pstErrCnt, sizeof(PPP_DRIVER_HDLC_HARD_DEF_ERR_FRAMES_CNT_STRU),
                          0x00, sizeof(PPP_DRIVER_HDLC_HARD_DEF_ERR_FRAMES_CNT_STRU));

    pstErrCnt->ucErrType = ucErrType;

    /* get fcs error count */
    if (1 == TTF_GET_A_BIT(ucErrType, PPP_DRIVER_HDLC_HARD_DEF_FCS_ERR))
    {
        pstErrCnt->usFCSErrCnt        = (VOS_UINT16)TTF_Read32RegByBit(SOC_ARM_HDLC_DEF_ERR_INFO_0_ADDR(HDLC_IP_BASE_ADDR), 0, 15);
        PPP_HDLC_WARNING_LOG("bad hdlc fcs");
    }

    /* get frame too long error count */
    if (1 == TTF_GET_A_BIT(ucErrType, PPP_DRIVER_HDLC_HARD_DEF_FRAME_TOO_LONG))
    {
        pstErrCnt->usLenLongCnt       = (VOS_UINT16)TTF_Read32RegByBit(SOC_ARM_HDLC_DEF_ERR_INFO_0_ADDR(HDLC_IP_BASE_ADDR), 16, 31);
        PPP_HDLC_WARNING_LOG("bad hdlc frame length too long");
    }

    /* get frame too short error count */
    if (1 == TTF_GET_A_BIT(ucErrType, PPP_DRIVER_HDLC_HARD_DEF_FRAME_TOO_SHORT))
    {
        pstErrCnt->usLenShortCnt      = (VOS_UINT16)TTF_Read32RegByBit(SOC_ARM_HDLC_DEF_ERR_INFO_1_ADDR(HDLC_IP_BASE_ADDR), 0, 15);
        PPP_HDLC_WARNING_LOG("bad hdlc frame length too short");
    }

    /* get error protocol count */
    if (1 == TTF_GET_A_BIT(ucErrType, PPP_DRIVER_HDLC_HARD_DEF_PROTOCOL_ERR))
    {
        pstErrCnt->usErrProtocolCnt   = (VOS_UINT16)TTF_Read32RegByBit(SOC_ARM_HDLC_DEF_ERR_INFO_1_ADDR(HDLC_IP_BASE_ADDR), 16, 31);
        PPP_HDLC_WARNING_LOG("bad hdlc frame protocol");
    }

    /* get error control count */
    if (1 == TTF_GET_A_BIT(ucErrType, PPP_DRIVER_HDLC_HARD_DEF_CTRL_ERR))
    {
        pstErrCnt->usErrCtrlCnt       = (VOS_UINT16)TTF_Read32RegByBit(SOC_ARM_HDLC_DEF_ERR_INFO_2_ADDR(HDLC_IP_BASE_ADDR), 0, 15);
        PPP_HDLC_WARNING_LOG("bad hdlc frame control");
    }

    /* get error address count */
    if (1 == TTF_GET_A_BIT(ucErrType, PPP_DRIVER_HDLC_HARD_DEF_ADDR_ERR))
    {
        pstErrCnt->usErrAddrCnt       = (VOS_UINT16)TTF_Read32RegByBit(SOC_ARM_HDLC_DEF_ERR_INFO_2_ADDR(HDLC_IP_BASE_ADDR), 16, 31);
        PPP_HDLC_WARNING_LOG("bad hdlc frame address");
    }

    /* get error flag position count */
    if (1 == TTF_GET_A_BIT(ucErrType, PPP_DRIVER_HDLC_HARD_DEF_FLAG_POS_ERR))
    {
        pstErrCnt->usFlagPosErrCnt    = (VOS_UINT16)TTF_Read32RegByBit(SOC_ARM_HDLC_DEF_ERR_INFO_3_ADDR(HDLC_IP_BASE_ADDR), 0, 15);
        PPP_HDLC_WARNING_LOG("bad hdlc frame flag position");
    }

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardGetDefRawInt
 功能描述  : 获取解封装中断寄存器值
 输入参数  : 无
 输出参数  : 无
 返 回 值  : VOS_UINT32  解封装中断寄存器值
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月20日
    作    者   : c00191211
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcHardGetDefRawInt(VOS_VOID)
{
    VOS_UINT32                          ulRawInt;

    ulRawInt  =   PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_RAW_INT_ADDR(HDLC_IP_BASE_ADDR));

    return ulRawInt;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardShowConfigInfo
 功能描述  : 打印HDLC配置信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardShowConfigInfo(VOS_VOID)
{
    PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU  *pstHdlcConf = PPP_DRIVER_HDLC_HARD_GET_CONFIG;

    /* 输出IP相关信息 */
    vos_printf("HDLC IP基地址                   = %d\n", HDLC_IP_BASE_ADDR);
    vos_printf("解封装中断信号                  = %d\n", pstHdlcConf->slHdlcISRDef);
    vos_printf("封装中断信号                    = %d\n", pstHdlcConf->slHdlcISRFrm);
    vos_printf("解封装信号量                    = %d\n", pstHdlcConf->ulHdlcDefMasterSem);
    vos_printf("封装信号量                      = %d\n", pstHdlcConf->ulHdlcFrmMasterSem);
    vos_printf("解封装中断水线                  = %d\n", pstHdlcConf->ulHdlcDefIntLimit);
    vos_printf("封装中断水线                    = %d\n", pstHdlcConf->ulHdlcFrmIntLimit);
    vos_printf("系统控制器基地址                = %d\n", pstHdlcConf->ulHdlcScCtrlBaseAddr);

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardGetFrmRegInfo
 功能描述  : 获取封装寄存器信息
 输入参数  : 无
 输出参数  : pstRegConfig   -   封装寄存器信息
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardGetFrmRegInfo(PPP_DRIVER_HDLCHARD_FRM_REG_INFO_STRU *pstRegConfig)
{
    if (VOS_NULL_PTR == pstRegConfig)
    {
        PPP_HDLC_WARNING_LOG("pstRegConfig");
        return;
    }

    /* 拷贝全部寄存器内容 */
    pstRegConfig->ulStateSwRst          = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_STATE_SW_RST_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulPriorTimeoutCtrl    = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_PRIROR_TIMEOUT_CTRL_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulRdErrCurrAddr       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_RD_ERR_CURR_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulWrErrCurrAddr       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_WR_ERR_CURR_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcFrmEn           = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_EN_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcFrmRawInt       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_RAW_INT_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcFrmIntStatus    = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_INT_STATUS_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcFrmIntClr       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_INT_CLR_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcFrmCfg          = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_CFG_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcFrmAccm         = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_ACCM_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcFrmStatus       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_STATUS_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulFrmInLliAddr        = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_IN_LLI_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulFrmInSublliAddr     = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_IN_SUBLLI_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulFrmInPktLen         = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_IN_PKT_LEN_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulFrmInBlkAddr        = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_IN_BLK_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulFrmInBlkLen         = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_IN_BLK_LEN_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulFrmOutLliAddr       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_OUT_LLI_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulFrmOutSpaceAddr     = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_OUT_SPACE_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulFrmOutSpaceDep      = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_OUT_SPACE_DEP_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulFrmRptAddr          = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_RPT_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulFrmRptDep           = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_RPT_DEP_ADDR(HDLC_IP_BASE_ADDR));

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardGetDefRegInfo
 功能描述  : 获取解封装寄存器信息
 输入参数  : 无
 输出参数  : pstRegConfig   -   解封装寄存器信息
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardGetDefRegInfo(PPP_DRIVER_HDLCHARD_DEF_REG_INFO_STRU *pstRegConfig)
{
    if (VOS_NULL_PTR == pstRegConfig)
    {
        PPP_HDLC_WARNING_LOG("pstRegConfig");
        return;
    }

    /* 拷贝全部寄存器内容 */
    pstRegConfig->ulStateSwRst             = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_STATE_SW_RST_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulPriorTimeoutCtrl       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_PRIROR_TIMEOUT_CTRL_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulRdErrCurrAddr          = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_RD_ERR_CURR_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulWrErrCurrAddr          = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_WR_ERR_CURR_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcDefEn              = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_EN_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcDefRawInt          = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_RAW_INT_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcDefIntStatus       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_INT_STATUS_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcDefIntClr          = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_INT_CLR_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcDefCfg             = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_CFG_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefUncompletedLen      = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_UNCOMPLETED_LEN_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefUncompletedPro      = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_UNCOMPLETED_PRO_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefUncompletedAddr     = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_UNCOMPLETED_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefUncompleteStAgo     = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_UNCOMPLETED_ST_AGO_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcDefGoOn            = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_GO_ON_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcDefStatus          = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_STATUS_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefUncompletStNow      = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_UNCOMPLETED_ST_NOW_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefInLliAddr           = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_IN_LLI_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefInPktAddr           = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_IN_PKT_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefInPktLen            = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_IN_PKT_LEN_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefInPktLenMax         = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_IN_PKT_LEN_MAX_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefOutSpcAddr          = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_OUT_SPC_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefOutSpaceDep         = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_OUT_SPACE_DEP_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefRptAddr             = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_RPT_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefRptDep              = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_RPT_DEP_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcDefErrInfor0       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_ERR_INFO_0_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcDefErrInfor1       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_ERR_INFO_1_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcDefErrInfor2       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_ERR_INFO_2_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulHdlcDefErrInfor3       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_ERR_INFO_3_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefInfoFr1CntAgo       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_INFO_FRL_CNT_AGO_ADDR(HDLC_IP_BASE_ADDR));
    pstRegConfig->ulDefInfoFr1CntNow       = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_INFO_FRL_CNT_NOW_ADDR(HDLC_IP_BASE_ADDR));

    return;
}


/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardShowFrmReg
 功能描述  : 打印封装寄存器当前数据
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年1月30日
    作    者   : c00191211
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardShowFrmReg(VOS_VOID)
{
    PPP_DRIVER_HDLCHARD_FRM_REG_INFO_STRU   stRegConfig;
    PPP_DRIVER_HDLCHARD_FRM_REG_INFO_STRU  *pstRegConfig = &stRegConfig;

    PPP_Driver_HdlcHardGetFrmRegInfo(pstRegConfig);

    vos_printf("\n================HDLC Hardware ShowFrmReg Begin==========================\n");

    vos_printf("ulStateSwRst                    = 0x%x\n", pstRegConfig->ulStateSwRst);
    vos_printf("ulPriorTimeoutCtrl              = 0x%x\n", pstRegConfig->ulPriorTimeoutCtrl);
    vos_printf("ulRdErrCurrAddr                 = 0x%x\n", pstRegConfig->ulRdErrCurrAddr);
    vos_printf("ulWrErrCurrAddr                 = 0x%x\n", pstRegConfig->ulWrErrCurrAddr);
    vos_printf("ulHdlcFrmEn                     = 0x%x\n", pstRegConfig->ulHdlcFrmEn);
    vos_printf("ulHdlcFrmRawInt                 = 0x%x\n", pstRegConfig->ulHdlcFrmRawInt);
    vos_printf("ulHdlcFrmIntStatus              = 0x%x\n", pstRegConfig->ulHdlcFrmIntStatus);
    vos_printf("ulHdlcFrmIntClr                 = 0x%x\n", pstRegConfig->ulHdlcFrmIntClr);
    vos_printf("ulHdlcFrmCfg                    = 0x%x\n", pstRegConfig->ulHdlcFrmCfg);
    vos_printf("ulHdlcFrmAccm                   = 0x%x\n", pstRegConfig->ulHdlcFrmAccm);
    vos_printf("ulHdlcFrmStatus                 = 0x%x\n", pstRegConfig->ulHdlcFrmStatus);
    vos_printf("ulFrmInLliAddr                  = 0x%x\n", pstRegConfig->ulFrmInLliAddr);
    vos_printf("ulFrmInSublliAddr               = 0x%x\n", pstRegConfig->ulFrmInSublliAddr);
    vos_printf("ulFrmInPktLen                   = 0x%x\n", pstRegConfig->ulFrmInPktLen);
    vos_printf("ulFrmInBlkAddr                  = 0x%x\n", pstRegConfig->ulFrmInBlkAddr);
    vos_printf("ulFrmInBlkLen                   = 0x%x\n", pstRegConfig->ulFrmInBlkLen);
    vos_printf("ulFrmOutLliAddr                 = 0x%x\n", pstRegConfig->ulFrmOutLliAddr);
    vos_printf("ulFrmOutSpaceAddr               = 0x%x\n", pstRegConfig->ulFrmOutSpaceAddr);
    vos_printf("ulFrmOutSpaceDep                = 0x%x\n", pstRegConfig->ulFrmOutSpaceDep);
    vos_printf("ulFrmRptAddr                    = 0x%x\n", pstRegConfig->ulFrmRptAddr);
    vos_printf("ulFrmRptDep                     = 0x%x\n", pstRegConfig->ulFrmRptDep);

    vos_printf("\n================HDLC Hardware ShowFrmReg End==========================\n");

    return;
}


/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcHardShowDefReg
 功能描述  : 打印解封装寄存器当前数据
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年1月30日
    作    者   : c00191211
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardShowDefReg(VOS_VOID)
{
    PPP_DRIVER_HDLCHARD_DEF_REG_INFO_STRU   stRegConfig;
    PPP_DRIVER_HDLCHARD_DEF_REG_INFO_STRU  *pstRegConfig = &stRegConfig;


    PPP_Driver_HdlcHardGetDefRegInfo(pstRegConfig);

    vos_printf("\n================HDLC Hardware ShowDefReg Begin==========================\n");

    vos_printf("ulStateSwRst             = 0x%x\n", pstRegConfig->ulStateSwRst);
    vos_printf("ulPriorTimeoutCtrl       = 0x%x\n", pstRegConfig->ulPriorTimeoutCtrl);
    vos_printf("ulRdErrCurrAddr          = 0x%x\n", pstRegConfig->ulRdErrCurrAddr);
    vos_printf("ulWrErrCurrAddr          = 0x%x\n", pstRegConfig->ulWrErrCurrAddr);
    vos_printf("ulHdlcDefEn              = 0x%x\n", pstRegConfig->ulHdlcDefEn);
    vos_printf("ulHdlcDefRawInt          = 0x%x\n", pstRegConfig->ulHdlcDefRawInt);
    vos_printf("ulHdlcDefIntStatus       = 0x%x\n", pstRegConfig->ulHdlcDefIntStatus);
    vos_printf("ulHdlcDefIntClr          = 0x%x\n", pstRegConfig->ulHdlcDefIntClr);
    vos_printf("ulHdlcDefCfg             = 0x%x\n", pstRegConfig->ulHdlcDefCfg);
    vos_printf("ulDefUncompletedLen      = 0x%x\n", pstRegConfig->ulDefUncompletedLen);
    vos_printf("ulDefUncompletedPro      = 0x%x\n", pstRegConfig->ulDefUncompletedPro);
    vos_printf("ulDefUncompletedAddr     = 0x%x\n", pstRegConfig->ulDefUncompletedAddr);
    vos_printf("ulDefUncompleteStAgo     = 0x%x\n", pstRegConfig->ulDefUncompleteStAgo);
    vos_printf("ulHdlcDefGoOn            = 0x%x\n", pstRegConfig->ulHdlcDefGoOn);
    vos_printf("ulHdlcDefStatus          = 0x%x\n", pstRegConfig->ulHdlcDefStatus);
    vos_printf("ulDefUncompletStNow      = 0x%x\n", pstRegConfig->ulDefUncompletStNow);
    vos_printf("ulDefInLliAddr           = 0x%x\n", pstRegConfig->ulDefInLliAddr);
    vos_printf("ulDefInPktAddr           = 0x%x\n", pstRegConfig->ulDefInPktAddr);
    vos_printf("ulDefInPktLen            = 0x%x\n", pstRegConfig->ulDefInPktLen);
    vos_printf("ulDefInPktLenMax         = 0x%x\n", pstRegConfig->ulDefInPktLenMax);
    vos_printf("ulDefOutSpcAddr          = 0x%x\n", pstRegConfig->ulDefOutSpcAddr);
    vos_printf("ulDefOutSpaceDep         = 0x%x\n", pstRegConfig->ulDefOutSpaceDep);
    vos_printf("ulDefRptAddr             = 0x%x\n", pstRegConfig->ulDefRptAddr);
    vos_printf("ulDefRptDep              = 0x%x\n", pstRegConfig->ulDefRptDep);
    vos_printf("ulHdlcDefErrInfor0       = 0x%x\n", pstRegConfig->ulHdlcDefErrInfor0);
    vos_printf("ulHdlcDefErrInfor1       = 0x%x\n", pstRegConfig->ulHdlcDefErrInfor1);
    vos_printf("ulHdlcDefErrInfor2       = 0x%x\n", pstRegConfig->ulHdlcDefErrInfor2);
    vos_printf("ulHdlcDefErrInfor3       = 0x%x\n", pstRegConfig->ulHdlcDefErrInfor3);
    vos_printf("ulDefInfoFr1CntAgo       = 0x%x\n", pstRegConfig->ulDefInfoFr1CntAgo);
    vos_printf("ulDefInfoFr1CntNow       = 0x%x\n", pstRegConfig->ulDefInfoFr1CntNow);

    vos_printf("\n================HDLC Hardware ShowDefReg End==========================\n");

}

#if ((SC_CTRL_MOD_KIRIN970_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_M533 == SC_CTRL_MOD))
/*****************************************************************************
 函 数 名  : PPP_Driver_HdlcGetRegValue
 功能描述  : 获取HDLC寄存器信息
 输入参数  : enHdlcRegType   寄存器类型
 输出参数  : 无
 返 回 值  : 寄存器值
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年1月4日
    作    者   : c00184031
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Driver_HdlcGetRegValue
(
    PPP_DRIVER_HDLC_REG_ENUM_UINT8      enHdlcRegType,
    VOS_UINT32                         *pulValue
)
{
    /* 调用者保证pulValue非空 */

    switch (enHdlcRegType)
    {
        case PPP_DRIVER_MAX_FRM_INFO_REG:

            *pulValue = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_FRM_INFO_MAX_LEN_ADDR(HDLC_IP_BASE_ADDR));

            break;

        case PPP_DRIVER_MAX_DEF_INFO_REG:

            *pulValue = PPP_HDLC_READ_32REG(SOC_ARM_HDLC_DEF_INFO_MAX_LEN_ADDR(HDLC_IP_BASE_ADDR));

            break;

        default:

            /* 非法的情况将值置为全f */
            *pulValue = 0xffffffff;
            PPP_HDLC_WARNING_LOG1("Invalid Hdlc Reg Type!", enHdlcRegType);

            return PS_FAIL;
    }

    return PS_SUCC;
}

/*****************************************************************************
 函 数 名  : PPP_HDLC_ReadVer
 功能描述  : 读取HDLC IP版本号,kirin970之前版本不支持kirin
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月10日
    作    者   : c00184031
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_HDLC_ReadVer(VOS_VOID)
{
    VOS_UINT32                          ulVer = 0;

    /* 开时钟 */
    PPP_Driver_HdlcHardPeriphClkOpen();

    if (VOS_TRUE == PPP_Driver_HdlcHardGetPeriphClkStatus())
    {
        /* ulVer = hdlc_version寄存器[31:0]位的值 */
        ulVer  = TTF_Read32RegByBit(SOC_ARM_HDLC_VERSION_ADDR(HDLC_IP_BASE_ADDR), 0, 31);
        vos_printf("HDLC Version %d\r\n!", ulVer);
    }

    /* 关时钟 */
    PPP_Driver_HdlcHardPeriphClkClose();

    return;
}
#endif

/*****************************************************************************
 函 数 名  : PPP_Driver_SetMaxFrmDefInfoLen
 功能描述  : 设置最大封装解封装寄存器信息，只配置一次
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年1月4日
    作    者   : c00184031
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Driver_HdlcSetMaxFrmDefInfoLen(VOS_VOID)
{
#if ((SC_CTRL_MOD_KIRIN970_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_M533 == SC_CTRL_MOD))
    /* 封装解封装信息域只配置一次 */
    static VOS_UINT8                    ucCfgHdlcMaxLenFlag = 0;
    VOS_UINT32                          ulHdlcRegValue = 0;
    VOS_UINT32                          ulResult;


    /* 防止初始化时由于开时钟慢导致配置最大长度信息域失败,只检查一次 */
    if (0 == ucCfgHdlcMaxLenFlag)
    {
        ucCfgHdlcMaxLenFlag = 1;
        ulResult = PPP_Driver_HdlcGetRegValue(PPP_DRIVER_MAX_FRM_INFO_REG, &ulHdlcRegValue);
        if (PS_SUCC != ulResult)
        {
            PPP_HDLC_WARNING_LOG2("Get Frm Reg Fail!", ulResult, ulHdlcRegValue);
        }

        /* 读寄存器失败也会强制配置一次 */
        if (HDLC_MAX_FRM_DEF_INFO_LEN != ulHdlcRegValue)
        {
            PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_FRM_INFO_MAX_LEN_ADDR(
                    HDLC_IP_BASE_ADDR), HDLC_MAX_FRM_DEF_INFO_LEN);
        }

        ulResult = PPP_Driver_HdlcGetRegValue(PPP_DRIVER_MAX_DEF_INFO_REG, &ulHdlcRegValue);
        if (PS_SUCC != ulResult)
        {
            PPP_HDLC_WARNING_LOG2("Get Def Reg Fail", ulResult, ulHdlcRegValue);
        }

        /* 读寄存器失败也会强制配置一次 */
        if (HDLC_MAX_FRM_DEF_INFO_LEN != ulHdlcRegValue)
        {
            PPP_HDLC_WRITE_32REG(SOC_ARM_HDLC_DEF_INFO_MAX_LEN_ADDR(
                    HDLC_IP_BASE_ADDR), HDLC_MAX_FRM_DEF_INFO_LEN);
        }
    }
#endif
}


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif



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
#include "hdlc_hardware_mntn.h"
#include "msp_diag_comm.h"
#include "hdlc_hardware_conf.h"

#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif

/*****************************************************************************
   协议栈打印打点方式下的.C文件宏定义
*****************************************************************************/
#define    THIS_FILE_ID        PS_FILE_ID_HDLC_HARDWARE_MNTN_C

/******************************************************************************
   2 外部函数变量声明
******************************************************************************/


/*****************************************************************************
   3 私有定义
*****************************************************************************/


/*****************************************************************************
   4 全局变量定义
*****************************************************************************/


/* 统计信息 */
PPP_HDLC_HARD_DATA_PROC_STAT_ST         g_PppHdlcHardStat   = {0};

/* 可维可测等级配置 */
VOS_UINT32                              g_ulHdlcMntnConfig = 0;

/* 保留清原始中断时的RAW_INT和STATUS值 */
HDLC_REG_SAVE_INFO_STRU                 g_stHdlcRegSaveInfo;


/******************************************************************************
   5 函数实现
******************************************************************************/

/*****************************************************************************
 函 数 名  : PPP_HDLC_HARD_MntnGetConfig
 功能描述  : 获取可维可测等级
 输入参数  : ulMod      -   可维可测勾取项
 输出参数  : 无
 返 回 值  : VOS_TRUE   -   勾取
             VOS_FALSE  -   不勾取
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_BOOL PPP_HDLC_HARD_MntnGetConfig(VOS_UINT32 ulMod)
{
    if (0 == (g_ulHdlcMntnConfig & ulMod))
    {
        return VOS_FALSE;
    }

    return VOS_TRUE;
}

/*****************************************************************************
 函 数 名  : PPP_HDLC_HARD_MntnSetConfig
 功能描述  : 设置可维可测等级
 输入参数  : ulConfig - 可维可测等级
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_HDLC_HARD_MntnSetConfig(VOS_UINT32 ulConfig)
{
    g_ulHdlcMntnConfig = ulConfig;

    return g_ulHdlcMntnConfig;
}


/*****************************************************************************
 函 数 名  : PPP_HDLC_HARD_MntnTraceMsg
 功能描述  : 基础勾包函数
 输入参数  : pstHead    - 消息首地址
             ulMsgname  - 消息ID
             ulDataLen  - 消息长度
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_HDLC_HARD_MntnTraceMsg
(
    HDLC_MNTN_TRACE_HEAD_STRU          *pstHead,
    HDLC_MNTN_EVENT_TYPE_ENUM_UINT32    ulMsgname,
    VOS_UINT32                          ulDataLen
)
{
    pstHead->ulReceiverCpuId = VOS_LOCAL_CPUID;
    pstHead->ulReceiverPid   = PS_PID_PPP_HDLC;
    pstHead->ulSenderCpuId   = VOS_LOCAL_CPUID;
    pstHead->ulSenderPid     = PS_PID_PPP_HDLC;
    pstHead->ulLength        = ulDataLen - VOS_MSG_HEAD_LENGTH;

    pstHead->ulMsgname       = ulMsgname;

    DIAG_TraceReport(pstHead);

    return;
}

/*****************************************************************************
 函 数 名  : PPP_HDLC_HARD_MntnShowStatInfo
 功能描述  : 打印统计信息
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
VOS_VOID PPP_HDLC_HARD_MntnShowStatInfo(VOS_VOID)
{
    vos_printf("\n================HDLC Hardware STAT INFO Begin==========================\n");

    vos_printf("解封装处理IP类型包个数            = %d\n", g_PppHdlcHardStat.ulDefIpDataProcCnt);
    vos_printf("解封装处理PPP类型包个数           = %d\n", g_PppHdlcHardStat.ulDefPppDataProcCnt);
    vos_printf("解封装输出非完整帧个数            = %d\n", g_PppHdlcHardStat.ulDefUncompleteCnt);
    vos_printf("解封装等待中断次数                = %d\n", g_PppHdlcHardStat.ulDefWaitIntCnt);
    vos_printf("解封装轮询次数                    = %d\n", g_PppHdlcHardStat.ulDefWaitQueryCnt);
    vos_printf("解封装中断次数                    = %d\n", g_PppHdlcHardStat.ulDefIsrCnt);
    vos_printf("解封装LCP帧暂停次数               = %d\n", g_PppHdlcHardStat.ulDefLcpPauseCnt);
    vos_printf("解封装空间满暂停次数              = %d\n", g_PppHdlcHardStat.ulDefFullPauseCnt);
    vos_printf("解封装丢弃错误数据包个数          = %d\n", g_PppHdlcHardStat.ulDefInputDiscardCnt);

    vos_printf("封装处理IP类型包个数              = %d\n", g_PppHdlcHardStat.ulFrmIpDataProcCnt);
    vos_printf("封装处理PPP类型包个数             = %d\n", g_PppHdlcHardStat.ulFrmPppDataProcCnt);
    vos_printf("封装等待中断次数                  = %d\n", g_PppHdlcHardStat.ulFrmWaitIntCnt);
    vos_printf("封装轮询次数                      = %d\n", g_PppHdlcHardStat.ulFrmWaitQueryCnt);
    vos_printf("封装中断次数                      = %d\n", g_PppHdlcHardStat.ulFrmIsrCnt);
    vos_printf("封装申请目的空间内存失败次数      = %d\n", g_PppHdlcHardStat.ulFrmAllocOutputMemFailCnt);
    vos_printf("封装申请第一个目的空间内存失败次数= %d\n", g_PppHdlcHardStat.ulFrmAllocFirstMemFailCnt);
    vos_printf("封装输出参数链表满次数            = %d\n", g_PppHdlcHardStat.ulFrmOutputLinkFullCnt);
    vos_printf("封装丢弃错误数据包个数            = %d\n", g_PppHdlcHardStat.ulFrmInputDiscardCnt);

    vos_printf("解封装输入链表最大节点数          = %d\n", g_PppHdlcHardStat.ulDefMaxInputCntOnce);
    vos_printf("解封装输入链表最大总长度          = %d\n", g_PppHdlcHardStat.ulDefMaxInputSizeOnce);
    vos_printf("解封装输出有效帧最大个数          = %d\n", g_PppHdlcHardStat.ulDefMaxValidCntOnce);
    vos_printf("解封装轮询最大次数                = %d\n", g_PppHdlcHardStat.ulDefMaxQueryCnt);

    vos_printf("封装输入链表最大节点数            = %d\n", g_PppHdlcHardStat.ulFrmMaxInputCntOnce);
    vos_printf("封装输入链表最大总长度            = %d\n", g_PppHdlcHardStat.ulFrmMaxInputSizeOnce);
    vos_printf("封装输出使用最大节点个数          = %d\n", g_PppHdlcHardStat.ulFrmMaxOutputCntOnce);
    vos_printf("封装输出使用最大节点总长度        = %d\n", g_PppHdlcHardStat.ulFrmMaxOutputCntOnce);
    vos_printf("封装轮询最大次数                  = %d\n", g_PppHdlcHardStat.ulFrmMaxQueryCnt);

    vos_printf("单次处理最大节点数                = %d\n", g_PppHdlcHardStat.ulMaxCntOnce);
    vos_printf("处理总节点数                      = %d\n", g_PppHdlcHardStat.ulHdlcHardProcCnt);
    vos_printf("continue次数                      = %d\n", g_PppHdlcHardStat.ulContinueCnt);
    vos_printf("usDefExpInfo标识                  = %d\n", g_PppHdlcHardStat.usDefExpInfo);
    vos_printf("usFrmExpInfo标识                  = %d\n", g_PppHdlcHardStat.usFrmExpInfo);

    vos_printf("规避HDLC BUG不拷贝数据次数        = %d\n", g_PppHdlcHardStat.ulForbidHdlcBugNoCpy);
    vos_printf("规避HDLC BUG拷贝数据次数          = %d\n", g_PppHdlcHardStat.ulForbidHdlcBugCpy);


    vos_printf("================HDLC Hardware STAT INFO End==========================\n");

    return;
}

/*****************************************************************************
 函 数 名  : PPP_HDLC_HARD_MntnTraceSingleData
 功能描述  : 勾取单个数据
 输入参数  : usDataLen   -   单个数据长度
             pucDataAddr -   数据首地址
             ulEventType -   数据类型
             ulNodeIndex -   数据所在链表结点的下标
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_HDLC_HARD_MntnTraceSingleData
(
    VOS_UINT16                          usDataLen,
    VOS_UINT8                          *pucDataAddr,
    HDLC_MNTN_EVENT_TYPE_ENUM_UINT32    ulEventType,
    VOS_UINT32                          ulNodeIndex
)
{
    VOS_UINT32                          ulDataLen;
    HDLC_MNTN_NODE_DATA_STRU           *pstNodeData;
    VOS_UINT32                          ulAllocDataLen;


    ulAllocDataLen = TTF_MIN(usDataLen, HDLC_MNTN_ALLOC_MEM_MAX_SIZE);

    /* 消息长度等于消息结构大小加数据内容长度 */
    ulDataLen   = ulAllocDataLen + sizeof(HDLC_MNTN_NODE_DATA_STRU);

    pstNodeData = (HDLC_MNTN_NODE_DATA_STRU *)PS_MEM_ALLOC(PS_PID_PPP_HDLC, ulDataLen);

    if (VOS_NULL_PTR == pstNodeData)
    {
        PPP_HDLC_WARNING_LOG1("Alloc mem failed", ulEventType);
        return;
    }

    /* 用于标识这是一组输入链表中的第几个IP包 */
    pstNodeData->usNodeIndex = (VOS_UINT16)ulNodeIndex;
    pstNodeData->usLen       = usDataLen;

    PPP_HDLC_HARD_MEM_CPY((VOS_UINT8 *)(pstNodeData + 1), ulAllocDataLen, pucDataAddr, ulAllocDataLen);

    PPP_HDLC_HARD_MntnTraceMsg((HDLC_MNTN_TRACE_HEAD_STRU *)pstNodeData,
                               ulEventType, ulDataLen);

    PS_MEM_FREE(PS_PID_PPP_HDLC, pstNodeData);

    return;
}

/*****************************************************************************
 函 数 名  : PPP_HDLC_HARD_MntnGetCurrentStatSum
 功能描述  : 获取当前统计值和
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 统计值和
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年10月22日
    作    者   : h00309869
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_HDLC_HARD_MntnGetCurrentStatSum(VOS_VOID)
{
    VOS_UINT32                              ulStatNum;
    VOS_UINT32                              ulLoop;
    VOS_UINT32                              ulStatSum   = 0;
    VOS_UINT32                             *pulStat     = (VOS_UINT32 *)&g_PppHdlcHardStat;


    ulStatNum = sizeof(PPP_HDLC_HARD_DATA_PROC_STAT_ST) / sizeof(VOS_UINT32);   /* 计算有多少个UINT32统计变量，两个UINT16统计变量合并成一个 */

    for ( ulLoop = 0 ; ulLoop < ulStatNum; ulLoop++ )
    {
        ulStatSum += *pulStat++;
    }

    return ulStatSum;
}

/*****************************************************************************
 函 数 名  : PPP_Help
 功能描述  : 帮助打印
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年9月25日
    作    者   : x59651
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_HDLC_HARD_Help(VOS_VOID)
{
    vos_printf("********************PPP软调信息************************\n");
    vos_printf("PPP_HDLC_HARD_MntnShowStatInfo      打印统计信息\n");
    vos_printf("PPP_INPUT_ShowStatInfo              打印 g_PppDataQCtrl信息(仅A核有效)\n");
    vos_printf("PPP_HDLC_HARD_MntnSetConfig         设置可维可测等级:\n");
    vos_printf("                                    1--参数；2--寄存器；4--数据\n");
    vos_printf("PPP_Driver_HdlcHardShowDefReg       打印解封装寄存器信息\n");
    vos_printf("PPP_Driver_HdlcHardShowFrmReg       打印封装寄存器信息\n");
    vos_printf("PPP_Driver_HdlcHardSetDefIntLimit   设置解封装中断水线\n");
    vos_printf("PPP_Driver_HdlcHradSetFrmIntLimit   设置封装中断水线\n");
    vos_printf("PPP_Driver_HdlcHardShowConfigInfo    打印配置信息\n");

    return;
}

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif


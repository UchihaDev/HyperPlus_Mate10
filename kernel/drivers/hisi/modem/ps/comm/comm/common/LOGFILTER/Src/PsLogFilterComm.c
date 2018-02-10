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
#include "PsLogFilterInterface.h"
#include "PsLib.h"
#include "PsLogFilterComm.h"





#define    THIS_FILE_ID        PS_FILE_ID_LOG_FILTER_COMM_C

/******************************************************************************
   2 外部函数变量声明
******************************************************************************/

/******************************************************************************
   3 私有定义
******************************************************************************/


/******************************************************************************
   4 全局变量定义
******************************************************************************/
PS_OM_LAYER_MSG_REPLACE_STATISTIC_STRU  g_stLayerMsgFilterStatistic = {0,0,0,0}; 


/******************************************************************************
   5 函数实现
******************************************************************************/


/*****************************************************************************
 函 数 名  : PS_OM_LocalCpuLayerMsgCommReplace
 功能描述  : 本核层间消息匹配过滤接口
 输入参数  :
             PS_OM_PER_PID_REG_CTRL_STRU    *pstLocalCpuPerPidCtrl,
             VOS_VOID                                    *pMsg

 输出参数  : 无
 返 回 值  : VOS_VOID*
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年3月22日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID* PS_OM_LocalCpuLayerMsgCommReplace
(
    PS_OM_PER_PID_REG_CTRL_STRU    *pstLocalCpuPerPidCtrl,
    VOS_VOID                                    *pMsg
)
{
    VOS_UINT32                          ulLoop;
    PS_OM_LAYER_MSG_REPLACE_CB          pFilterFun;
    VOS_VOID                           *pResult    = pMsg;


    if (VOS_NULL_PTR == pstLocalCpuPerPidCtrl)
    {
        return pResult;
    }

    /*依次循环该sendPid下注册的过滤函数*/
    for (ulLoop = 0; ulLoop < pstLocalCpuPerPidCtrl->usUseCnt; ulLoop++)
    {
        pFilterFun = pstLocalCpuPerPidCtrl->pafuncFilterEntry[ulLoop];
        if (VOS_NULL_PTR!= pFilterFun)
        {
            pResult = pFilterFun((MsgBlock*)pMsg);

            /*消息已被过滤，直接退出*/
            if (pMsg != pResult)
            {
                g_stLayerMsgFilterStatistic.ulLocalCpuFilterCnt++;
                break;
            }
        }
    }

    return pResult;
}



/*****************************************************************************
 函 数 名  : PS_OM_DiffCpuLayerMsgCommReplace
 功能描述  : 跨核层间消息匹配过滤接口
 输入参数  : PS_OM_DIFF_CPU_LAYER_MSG_FILTER_CTRL_STRU    *pstDiffCpuLayerMsgFilter,
             MsgBlock                                     *pRevMsg
 输出参数  : 无
 返 回 值  : VOS_VOID*
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年3月22日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID* PS_OM_DiffCpuLayerMsgCommReplace
(
    PS_OM_CPU_LAYER_MSG_FILTER_CTRL_STRU       *pstDiffCpuLayerMsgFilter,
    MsgBlock                                   *pRevMsg
)
{
    VOS_UINT32                          ulLoop;
    VOS_UINT32                          ulLoop2;
    PS_OM_LAYER_MSG_REPLACE_CB          pFilterFun;
    VOS_VOID                           *pResult    = pRevMsg;
    PS_OM_PER_PID_REG_CTRL_STRU        *pstDiffCpuPerPidCtrl;



    if (VOS_NULL_PTR == pstDiffCpuLayerMsgFilter)
    {
        return pResult;
    }

    /*外循环是注册的sendPid的个数，内循环是每个sendPid下注册的过滤函数的个数*/
    for (ulLoop = 0; ulLoop < pstDiffCpuLayerMsgFilter->usUseCnt; ulLoop++)
    {
        pstDiffCpuPerPidCtrl = &(pstDiffCpuLayerMsgFilter->pastPerPidMsgFilter[ulLoop]);

        /*先匹配sendPid, 找到sendpid后循环其下注册的过滤函数*/
        if (pRevMsg->ulSenderPid == pstDiffCpuPerPidCtrl->ulSendPid)
        {
            for (ulLoop2 = 0; ulLoop2 < pstDiffCpuPerPidCtrl->usUseCnt; ulLoop2++)
            {
                pFilterFun = pstDiffCpuPerPidCtrl->pafuncFilterEntry[ulLoop2];
                if (VOS_NULL_PTR != pFilterFun)
                {
                    pResult = pFilterFun(pRevMsg);
                    if (pRevMsg != pResult)
                    {
                        g_stLayerMsgFilterStatistic.ulDiffCpuFilterCnt++;
                        return pResult;
                    }
                }
            }
        }
    }

    return pResult;
}

/*****************************************************************************
 函 数 名  : PS_OM_CpuLayerMsgCommReplace
 功能描述  : C核层间消息替换接口，区分是同核消息还是跨核消息
 输入参数  :
             VOS_VOID                           *pMsg,
             PS_OM_LAYER_MSG_REPLACE_CTRL_STRU           *pstLayerMsgReplaceCtrl
 输出参数  : 无
 返 回 值  : VOS_VOID*
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年3月23日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID* PS_OM_CpuLayerMsgCommReplace
(
    VOS_VOID                                    *pMsg,
    PS_OM_LAYER_MSG_REPLACE_CTRL_STRU           *pstLayerMsgReplaceCtrl
)
{

    MsgBlock                           *pRevMsg;
    VOS_UINT16                          usSendPid;
    VOS_VOID                           *pResult    = pMsg;
    PS_OM_PER_PID_REG_CTRL_STRU        *pstLocalCpuPerPidCtrl;
    PS_OM_CPU_LAYER_MSG_FILTER_CTRL_STRU    *pstDiffCpuLayerMsgFilter;


    if ((VOS_NULL_PTR == pMsg) || (VOS_NULL_PTR == pstLayerMsgReplaceCtrl))
    {
        return pMsg;
    }

    pRevMsg = (MsgBlock *)pMsg;
    /*非跨核层间消息过滤*/
    if (pstLayerMsgReplaceCtrl->ucLocalCpuId == VOS_GET_CPU_ID(pRevMsg->ulSenderPid))
    {
        usSendPid = (VOS_UINT16)(pRevMsg->ulSenderPid);
        pstLocalCpuPerPidCtrl = &(pstLayerMsgReplaceCtrl->stLocalCpuLayerMsgFilter.pastPerPidMsgFilter[usSendPid]);
        pResult = PS_OM_LocalCpuLayerMsgCommReplace(pstLocalCpuPerPidCtrl, pMsg);
    }

    /*跨核层间消息过滤*/
    else
    {
        pstDiffCpuLayerMsgFilter = &(pstLayerMsgReplaceCtrl->stDiffCpuLayerMsgFilter);
        pResult = PS_OM_DiffCpuLayerMsgCommReplace(pstDiffCpuLayerMsgFilter, pRevMsg);
    }

    return pResult;
}



/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgReplaceMemExpand
 功能描述  : 为注册接口申请内存
 输入参数  :
             VOS_UINT32                                  ulSendPid,
             VOS_UINT16                                  usElementSize,
             VOS_UINT16                                  usExpandCnt,
             VOS_UINT16                                 *pusElementCnt,
             VOS_VOID                                  **ppStartAddr
 输出参数  : 无
 返 回 值  : PS_SUCC\PS_FAIL
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年03月20日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgReplaceMemExpand
(
    VOS_UINT32                                  ulSendPid,
    VOS_UINT16                                  usElementSize,
    VOS_UINT16                                  usExpandCnt,
    VOS_UINT16                                 *pusElementCnt,
    VOS_VOID                                  **ppStartAddr
)
{
    VOS_UINT32                              ulNewAllocLen;
    VOS_UINT32                              ulOldAllocLen;
    VOS_UINT32                              ulNewElementCnt;
    VOS_UINT32                              ulOldElementCnt;
    VOS_VOID                               *pNewAddr;
    VOS_VOID                               *pOldAddr;

    ulOldElementCnt     = *pusElementCnt;
    ulNewElementCnt     = (usExpandCnt + ulOldElementCnt);
    ulNewAllocLen       = (usElementSize * ulNewElementCnt);
    pNewAddr            = (PS_OM_PER_PID_REG_CTRL_STRU *)VOS_MemAlloc(ulSendPid, DYNAMIC_MEM_PT, ulNewAllocLen);

    if (VOS_NULL_PTR == pNewAddr)
    {
        return VOS_ERR;
    }
    VOS_MemSet_s(pNewAddr, ulNewAllocLen, 0x0, ulNewAllocLen);

    pOldAddr = *(ppStartAddr);
    if (VOS_NULL_PTR != pOldAddr)
    {
        ulOldAllocLen   = (usElementSize * ulOldElementCnt);
        VOS_MemCpy_s(pNewAddr, ulOldAllocLen, pOldAddr, ulOldAllocLen);
        VOS_MemFree(ulSendPid, pOldAddr);
    }

    *ppStartAddr    = pNewAddr;
    *pusElementCnt  = (VOS_UINT16)ulNewElementCnt;

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgCheckPara
 功能描述  : 入参合法性检查
 输入参数  : PS_OM_LAYER_MSG_REPLACE_CB                 pFunc,
             VOS_UINT32                                 ulSendPid
 输出参数  : 无
 返 回 值  : PS_ERR\PS_OK
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年03月20日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgCheckPara
(
    PS_OM_LAYER_MSG_REPLACE_CB                 pFunc,
    VOS_UINT32                                 ulSendPid
)
{
    VOS_UINT16                          usCpuId;


    if (VOS_NULL_PTR == pFunc)
    {
        return VOS_ERR;
    }
    usCpuId = VOS_GET_CPU_ID(ulSendPid);
    if (((VOS_CPU_ID_CCPU == usCpuId)&&(VOS_CPU_ID_0_PID_BUTT <= ulSendPid))
            || ((VOS_CPU_ID_ACPU == usCpuId)&&(VOS_CPU_ID_1_PID_BUTT <= ulSendPid))
            || ((VOS_CPU_ID_GUDSP == usCpuId)&&(VOS_CPU_ID_2_PID_BUTT <= ulSendPid))
            || ((VOS_CPU_ID_MEDDSP == usCpuId)&&(VOS_CPU_ID_3_PID_BUTT <= ulSendPid))
            || ((VOS_CPU_ID_MCU == usCpuId)&&(VOS_CPU_ID_4_PID_BUTT <= ulSendPid))
            || ((VOS_CPU_ID_BBE16 == usCpuId)&&(VOS_CPU_ID_5_PID_BUTT <= ulSendPid)))
    {
        return VOS_ERR;
    }

    return VOS_OK;
}



/*****************************************************************************
 函 数 名  : PS_OM_OnePidFilterFuncCommReg
 功能描述  : 过滤函数注册
 输入参数  :
             VOS_UINT32                                  ulSendPid,
             PS_OM_LAYER_MSG_REPLACE_CB                  pFunc,
             PS_OM_CPU_LAYER_MSG_FILTER_CTRL_STRU       *pstCpuFilter,
             PS_OM_PER_PID_REG_CTRL_STRU                *pstPidFilter
 输出参数  : 无
 返 回 值  : PS_ERR\PS_OK
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年03月20日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PS_OM_OnePidFilterFuncCommReg
(
    VOS_UINT32                                  ulSendPid,
    PS_OM_LAYER_MSG_REPLACE_CB                  pFunc,
    PS_OM_CPU_LAYER_MSG_FILTER_CTRL_STRU       *pstCpuFilter,
    PS_OM_PER_PID_REG_CTRL_STRU                *pstPidFilter
)
{
    VOS_UINT32                                  ulResult;

    if ((VOS_NULL_PTR == pstCpuFilter) || (VOS_NULL_PTR == pstPidFilter))
    {
        return VOS_ERR;
    }

    /* 该Pid下保存注册的过滤回调接口内存不足，先进行内存扩展，初次申请和装满都是一个逻辑 */
    if (pstPidFilter->usUseCnt == pstPidFilter->usMaxCnt)
    {
        ulResult = PS_OM_LayerMsgReplaceMemExpand(ulSendPid,
                                                  sizeof(PS_OM_LAYER_MSG_REPLACE_CB),
                                                  8,
                                                  &(pstPidFilter->usMaxCnt),
                                                  (VOS_VOID**)&(pstPidFilter->pafuncFilterEntry));
        if (VOS_OK != ulResult)
        {
            return VOS_ERR;
        }
    }

    /* 执行到这里时一切OK, 注册相应指针并修改增加计数字段 */
    if (0 == pstPidFilter->usUseCnt)
    {
        pstPidFilter->ulSendPid = ulSendPid;
        pstCpuFilter->usUseCnt++;
    }
    pstPidFilter->pafuncFilterEntry[pstPidFilter->usUseCnt] = pFunc;
    pstPidFilter->usUseCnt++;

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : PS_OM_LocalLayerMsgReplaceFuncCommReg
 功能描述  : A C核非跨核层间消息匹配过滤函数注册接口
 输入参数  :
                PS_OM_LAYER_MSG_REPLACE_CB                 pFunc,
                PS_OM_LAYER_MSG_REPLACE_CTRL_STRU         *pstLayerMsgReplaceCtrl,
                VOS_UINT32                                 ulSendPid
输入参数回调接口规则:
             1.如果注册回调内部没有对消息进行处理，则需要将入参指针返回
             2.如果注册回调内部对消息进行了处理，则返回值能够实现两个功能:
               ①返回VOS_NULL，则将此消息进行完全过滤，不会再勾取出来
               ②返回与入参指针不同的另一个指针，则勾取的消息将会使用返回的指
                 针内容替换原消息的内容。
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年3月20日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PS_OM_LocalLayerMsgReplaceFuncCommReg
(
    PS_OM_LAYER_MSG_REPLACE_CB                 pFunc,
    PS_OM_LAYER_MSG_REPLACE_CTRL_STRU         *pstLayerMsgReplaceCtrl,
    VOS_UINT32                                 ulSendPid
)
{
    VOS_UINT16                                  usPidIdx;
    VOS_UINT32                                  ulResult;
    PS_OM_CPU_LAYER_MSG_FILTER_CTRL_STRU       *pstLocalCpuFilter;
    PS_OM_PER_PID_REG_CTRL_STRU                *pstLocalPidFilter;

    pstLocalCpuFilter = &(pstLayerMsgReplaceCtrl->stLocalCpuLayerMsgFilter);

    /* 核内层间消息过滤数组只申请一次，按Pid最大个数申请，不再扩展 */
    if (0 == pstLocalCpuFilter->usUseCnt)
    {
        ulResult = PS_OM_LayerMsgReplaceMemExpand(ulSendPid,
                                                  sizeof(PS_OM_PER_PID_REG_CTRL_STRU),
                                                  pstLayerMsgReplaceCtrl->usLocalCpuMaxPidCnt,
                                                  &(pstLocalCpuFilter->usMaxCnt),
                                                  (VOS_VOID**)&(pstLocalCpuFilter->pastPerPidMsgFilter));
        if (VOS_OK != ulResult)
        {
            return VOS_ERR;
        }
    }

    usPidIdx    = (VOS_UINT16)ulSendPid;
    /* 下标保护 */
    if (usPidIdx >= pstLocalCpuFilter->usMaxCnt)
    {
        return VOS_ERR;
    }

    pstLocalPidFilter = &(pstLocalCpuFilter->pastPerPidMsgFilter[usPidIdx]);

    ulResult = PS_OM_OnePidFilterFuncCommReg(ulSendPid, pFunc, pstLocalCpuFilter, pstLocalPidFilter);

    return ulResult;
}



/*****************************************************************************
 函 数 名  : PS_OM_DiffCpuLayerMsgReplaceFuncCommReg
 功能描述  : A C核跨核层间消息匹配过滤函数注册接口
 输入参数  :
                PS_OM_LAYER_MSG_REPLACE_CB                  pFunc,
                PS_OM_LAYER_MSG_REPLACE_CTRL_STRU          *pstLayerMsgReplaceCtrl,
                VOS_UINT32                                  ulSendPid
输入参数回调接口规则:
             1.如果注册回调内部没有对消息进行处理，则需要将入参指针返回，否则
               本模块不知道是否需要将此消息传递给下一个注册回调进行处理
             2.如果注册回调内部对消息进行了处理，则返回值能够实现两个功能:
               ①返回VOS_NULL，则将此消息进行完全过滤，不会再勾取出来
               ②返回与入参指针不同的另一个指针，则勾取的消息将会使用返回的指
                 针内容替换原消息的内容。
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年3月20日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PS_OM_DiffCpuLayerMsgReplaceFuncCommReg
(
    PS_OM_LAYER_MSG_REPLACE_CB                  pFunc,
    PS_OM_LAYER_MSG_REPLACE_CTRL_STRU          *pstLayerMsgReplaceCtrl,
    VOS_UINT32                                  ulSendPid
)
{
    VOS_UINT32                                  ulLoop;
    VOS_UINT32                                  ulResult;
    PS_OM_CPU_LAYER_MSG_FILTER_CTRL_STRU       *pstDiffCpuFilter;
    PS_OM_PER_PID_REG_CTRL_STRU                *pstDiffPidFilter = VOS_NULL_PTR;

    pstDiffCpuFilter = &(pstLayerMsgReplaceCtrl->stDiffCpuLayerMsgFilter);

    /* 跨核消息交互的Pid较少，可以先用循环查找方法 */
    for (ulLoop = 0; ulLoop < pstDiffCpuFilter->usUseCnt; ulLoop++)
    {
        if (ulSendPid == pstDiffCpuFilter->pastPerPidMsgFilter[ulLoop].ulSendPid)
        {
            pstDiffPidFilter = &(pstDiffCpuFilter->pastPerPidMsgFilter[ulLoop]);
            break;
        }
    }

    /* 先进行内存扩展，初次申请和装满都是一个逻辑 */
    if ((VOS_NULL_PTR == pstDiffPidFilter))
    {
        if (pstDiffCpuFilter->usMaxCnt == pstDiffCpuFilter->usUseCnt)
        {
            ulResult = PS_OM_LayerMsgReplaceMemExpand(ulSendPid,
                sizeof(PS_OM_PER_PID_REG_CTRL_STRU),
                20,
                &(pstDiffCpuFilter->usMaxCnt),
                (VOS_VOID**)&(pstDiffCpuFilter->pastPerPidMsgFilter));
            if (VOS_OK != ulResult)
            {
                return VOS_ERR;
            }
        }

        pstDiffPidFilter = &(pstDiffCpuFilter->pastPerPidMsgFilter[pstDiffCpuFilter->usUseCnt]);
    }

    ulResult = PS_OM_OnePidFilterFuncCommReg(ulSendPid, pFunc, pstDiffCpuFilter, pstDiffPidFilter);

    return ulResult;
}

/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgReplaceCBCommReg
 功能描述  : A/C核注册层间消息匹配过滤回调接口，建议由消息发送方统一使用发送PID
             进行匹配过滤接口注册，原则上一个发送PID只允许注册一个匹配过滤接口，
             但是对跨核消息，透传转发消息等特殊场景，允许发送方或接收方使用
             发送PID注册多个匹配过滤接口
 输入参数  : PS_OM_LAYER_MSG_REPLACE_CTRL_STRU*pstLayerMsgCtrl
             VOS_UINT32                        ulSendPid
             PS_OM_LAYER_MSG_REPLACE_CB        pFunc
 输出参数  : 无
 返 回 值  : VOS_OK or VOS_ERR

 修改历史      :
  1.日    期   : 2017年3月18日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgReplaceCBCommReg
(
    PS_OM_LAYER_MSG_REPLACE_CTRL_STRU          *pstLayerMsgCtrl,
    VOS_UINT32                                  ulSendPid,
    PS_OM_LAYER_MSG_REPLACE_CB                  pFunc
)
{
    VOS_UINT32                      ulResult;

    /*入参合法性检查、PID范围检查*/
    if ((VOS_NULL_PTR == pstLayerMsgCtrl)
        || (VOS_OK != PS_OM_LayerMsgCheckPara(pFunc, ulSendPid)))
    {
        g_stLayerMsgFilterStatistic.ulRegFailCnt++;
        return VOS_ERR;
    }

    /* 核内层间消息过滤回调注册处理 */
    if (pstLayerMsgCtrl->ucLocalCpuId == VOS_GET_CPU_ID(ulSendPid))
    {
        ulResult = PS_OM_LocalLayerMsgReplaceFuncCommReg(pFunc, pstLayerMsgCtrl, ulSendPid);
    }

    else/* 跨核层间消息过滤回调注册处理 */
    {
        ulResult = PS_OM_DiffCpuLayerMsgReplaceFuncCommReg(pFunc, pstLayerMsgCtrl, ulSendPid);
    }
    if (VOS_OK == ulResult)
    {
        g_stLayerMsgFilterStatistic.ulRegSuccCnt++;
    }
    else
    {
        g_stLayerMsgFilterStatistic.ulRegFailCnt++;
    }

    return ulResult;
}

/*****************************************************************************
 函 数 名  : PS_OM_LogFilterCommShow
 功能描述  : 显示LogFilter的注册信息
 输入参数  : PS_OM_LAYER_MSG_REPLACE_CTRL_STRU*pstLayerMsgCtrl
 输出参数  : 无
 返 回 值  : 无

 修改历史      :
  1.日    期   : 2017年3月18日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PS_OM_LogFilterCommShow
(
    PS_OM_LAYER_MSG_REPLACE_CTRL_STRU           *pstLayerMsgCtrl
)
{
    if (VOS_NULL_PTR != pstLayerMsgCtrl)
    {
        vos_printf("CurCpuMaxPidCnt:   %d\n", pstLayerMsgCtrl->usLocalCpuMaxPidCnt);
        vos_printf("CurCpuId:          %d\n", pstLayerMsgCtrl->ucLocalCpuId);
        vos_printf("LocalMaxCnt:       %d\n", pstLayerMsgCtrl->stLocalCpuLayerMsgFilter.usMaxCnt);
        vos_printf("LocalUseCnt:       %d\n", pstLayerMsgCtrl->stLocalCpuLayerMsgFilter.usUseCnt);
        vos_printf("DiffMaxCnt:        %d\n", pstLayerMsgCtrl->stDiffCpuLayerMsgFilter.usMaxCnt);
        vos_printf("DiffUseCnt:        %d\n", pstLayerMsgCtrl->stDiffCpuLayerMsgFilter.usUseCnt);
        vos_printf("RegSuccCnt:        %d\n", g_stLayerMsgFilterStatistic.ulRegSuccCnt);
        vos_printf("RegFailCnt:        %d\n", g_stLayerMsgFilterStatistic.ulRegFailCnt);
        vos_printf("LocalCpuFilterCnt: %d\n", g_stLayerMsgFilterStatistic.ulLocalCpuFilterCnt);
        vos_printf("DiffCpuFilterCnt:  %d\n", g_stLayerMsgFilterStatistic.ulDiffCpuFilterCnt);
    }

    return;
}



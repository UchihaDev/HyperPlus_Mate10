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
#include "PsAcpuLogFilter.h"
#include "PsLogFilterComm.h"
#include "msp_diag_comm.h"


#define    THIS_FILE_ID        PS_FILE_ID_ACPU_LOG_FILTER_C

/******************************************************************************
   2 外部函数变量声明
******************************************************************************/

/******************************************************************************
   3 私有定义
******************************************************************************/


/******************************************************************************
   4 全局变量定义
******************************************************************************/

/*****************************************************************************
 功能描述  : 根据定义的可注册过滤函数的数量，对全局变量进行初始化操作
 修改历史      :
  1.日    期   : 2016年9月5日
    作    者   : z00383822
    修改内容   : 增加全局变量

*****************************************************************************/
PS_OM_LAYER_MSG_REPLACE_CTRL_STRU            g_stAcpuLayerMsgReplaceCtrl =
{
    (VOS_UINT16)VOS_PID_BUTT,
    (VOS_UINT8)VOS_CPU_ID_ACPU,
    {0},
    {0, 0, VOS_NULL_PTR},
    {0, 0, VOS_NULL_PTR}
};

/******************************************************************************
   5 函数实现
******************************************************************************/


/* 防止PC工程编译过程中函数多重定义 */


/*****************************************************************************
 函 数 名  : PS_OM_ACpuLayerMsgReplaceCB
 功能描述  : A核层间消息替换接口
 输入参数  : VOS_VOID                           *pMsg
 输出参数  : 无
 返 回 值  : VOS_VOID*
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年3月20日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID* PS_OM_ACpuLayerMsgReplaceCB
(
    VOS_VOID                           *pMsg
)
{
    return PS_OM_CpuLayerMsgCommReplace(pMsg, &g_stAcpuLayerMsgReplaceCtrl);
}

/*****************************************************************************
 函 数 名  : PS_OM_ACpuLayerMsgReplaceMemFreeCB
 功能描述  : A核层间消息替换内存释放函数
 输入参数  : VOS_UINT32                          ulSendPid,
             VOS_VOID                           *pAddr
 输出参数  : 无
 返 回 值  : VOS_VOID*
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年3月18日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PS_OM_ACpuLayerMsgReplaceMemFreeCB
(
    VOS_UINT32                          ulSendPid,
    VOS_VOID                           *pAddr
)
{
   return VOS_MemFree(ulSendPid, pAddr);
}


/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgReplaceCBReg
 功能描述  : 注册层间消息替换回调接口
 输入参数  : VOS_UINT32                        ulSendPid,
             PS_OM_LAYER_MSG_REPLACE_CB        pFunc,

             输入参数回调接口规则:
             1.根据发送PID进行注册
             2.注册消息过滤回调，
             如果注册回调内部对消息未进行处理，返回原入参指针；
             如果注册回调内部对消息进行了处理，则返回值能够实现两个功能:
               ①返回VOS_NULL，则将此消息进行完全过滤，不会再勾取出来
               ②返回与入参指针不同的另一个指针，则勾取的消息将会使用返回的指
                 针内容替换原消息的内容。
 输出参数  : 无
 返 回 值  : VOS_VOID

 修改历史      :
  1.日    期   : 2017年3月18日
    作    者   : c00368566
    修改内容   : 新生成函数



*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgReplaceCBReg
(
    VOS_UINT32                                    ulSendPid,
    PS_OM_LAYER_MSG_REPLACE_CB                    pFunc
)
{
    static VOS_UINT32       s_ulFirstRegFlag = 0;

    /* 初次注册，向底软注册回调函数 */
    if (0 == s_ulFirstRegFlag)
    {
        (VOS_VOID)DIAG_LayerMsgMatchFuncReg(PS_OM_ACpuLayerMsgReplaceCB);
        (VOS_VOID)DIAG_LayerMsgMatchNotifyFuncReg(PS_OM_ACpuLayerMsgReplaceMemFreeCB);
        s_ulFirstRegFlag = 0x5A5AA5A5;
    }

    return  PS_OM_LayerMsgReplaceCBCommReg(&g_stAcpuLayerMsgReplaceCtrl, ulSendPid, pFunc);
}

/*****************************************************************************
 函 数 名  : PS_OM_LogFilterShow
 功能描述  : 显示LogFilter的注册信息
 输入参数  : g_stAcpuLayerMsgReplaceCtrl
 输出参数  : 无
 返 回 值  : 无

 修改历史      :
  1.日    期   : 2017年3月18日
    作    者   : c00368566
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PS_OM_LogFilterShow
(
    VOS_VOID
)
{
    vos_printf("ACpu LogFilter:\n");
    PS_OM_LogFilterCommShow(&g_stAcpuLayerMsgReplaceCtrl);

    return;
}



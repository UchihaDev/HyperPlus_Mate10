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
#include "hdlc_hardware_conf.h"

#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif

/*****************************************************************************
   协议栈打印打点方式下的.C文件宏定义
*****************************************************************************/
#define    THIS_FILE_ID        PS_FILE_ID_HDLC_HARDWARE_CONF_C

/******************************************************************************
   2 外部函数变量声明
******************************************************************************/


/*****************************************************************************
   3 私有定义
*****************************************************************************/


/*****************************************************************************
   4 全局变量定义
*****************************************************************************/

/* HDLC配置信息 */
PPP_HDLC_HARD_CONFIG_INFO_STRU          g_stPppHdlcConfig = {0};

/*****************************************************************************
 函 数 名  : PPP_HDLC_HARD_BufPhy2Virt
 功能描述  : 将PPP中封装解封装的物理地址转换为虚地址
 输入参数  : ulPAddr   需要转换的物理地址
 输出参数  : 无
 返 回 值  : VOS_UINT8* 对应的虚地址
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2014年08月14日
    作    者   : g00178567
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT8* PPP_HDLC_HARD_BufPhy2Virt(VOS_UINT32 ulPAddr)
{
    VOS_UINT8                          *pucAddr;


    if (VOS_NULL_PTR != g_stPppHdlcConfig.pBufPhy2VirtFunc)
    {
        pucAddr = (VOS_UINT8*)g_stPppHdlcConfig.pBufPhy2VirtFunc((VOS_UINT8 *)ulPAddr,
                    (VOS_UINT8 *)g_stPppHdlcConfig.ulPppPhyAddr,
                    (VOS_UINT8 *)g_stPppHdlcConfig.ulPppVirtAddr,
                    g_stPppHdlcConfig.ulPppTotalBufLen);
    }
    else
    {
        pucAddr = (VOS_UINT8*)ulPAddr;
    }

    return pucAddr;
}

/*****************************************************************************
 函 数 名  : PPP_HDLC_HARD_BufVirt2Phy
 功能描述  : 将PPP中封装解封装的虚地址转换为物理地址
 输入参数  : ulVAddr   需要转换的虚地址
 输出参数  : 无
 返 回 值  : VOS_UINT8* 对应的物理地址
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2014年08月14日
    作    者   : g00178567
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT8* PPP_HDLC_HARD_BufVirt2Phy(VOS_UINT32 ulVAddr)
{
    VOS_UINT8                          *pucAddr;

    if (VOS_NULL_PTR != g_stPppHdlcConfig.pBufVirt2PhyFunc)
    {
        pucAddr = (VOS_UINT8*)g_stPppHdlcConfig.pBufVirt2PhyFunc((VOS_UINT8 *)ulVAddr,
                    (VOS_UINT8 *)g_stPppHdlcConfig.ulPppPhyAddr,
                    (VOS_UINT8 *)g_stPppHdlcConfig.ulPppVirtAddr,
                    g_stPppHdlcConfig.ulPppTotalBufLen);
    }
    else
    {
        pucAddr = (VOS_UINT8*)ulVAddr;
    }

    return pucAddr;
}

/*****************************************************************************
 函 数 名  : PPP_HDLC_HARD_MemPhy2Virt
 功能描述  : 将PPP中封装解封装的物理地址转换为虚地址
 输入参数  : ulPAddr   需要转换的物理地址
 输出参数  : 无
 返 回 值  : VOS_UINT8* 对应的虚地址
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2014年08月14日
    作    者   : g00178567
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT8* PPP_HDLC_HARD_MemPhy2Virt(VOS_UINT32 ulPAddr)
{
    VOS_UINT8                          *pucAddr;


    if (VOS_NULL_PTR != g_stPppHdlcConfig.pBufPhy2VirtFunc)
    {
        pucAddr = (VOS_UINT8*)g_stPppHdlcConfig.pMemPhy2VirtFunc(ulPAddr);
    }
    else
    {
        pucAddr = (VOS_UINT8*)ulPAddr;
    }

    return pucAddr;
}

/*****************************************************************************
 函 数 名  : PPP_HDLC_HARD_MemVirt2Phy
 功能描述  : 将PPP中封装解封装的虚地址转换为物理地址
 输入参数  : ulVAddr   需要转换的虚地址
 输出参数  : 无
 返 回 值  : VOS_UINT8* 对应的物理地址
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2014年08月14日
    作    者   : g00178567
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT8* PPP_HDLC_HARD_MemVirt2Phy(VOS_UINT32 ulVAddr)
{
    VOS_UINT8                          *pucAddr;

    if (VOS_NULL_PTR != g_stPppHdlcConfig.pBufVirt2PhyFunc)
    {
        pucAddr = (VOS_UINT8*)g_stPppHdlcConfig.pMemVirt2PhyFunc(ulVAddr);
    }
    else
    {
        pucAddr = (VOS_UINT8*)ulVAddr;
    }

    return pucAddr;
}

/*****************************************************************************
 函 数 名  : PPP_HDLC_HARD_IOAddrCvt
 功能描述  : IO地址转换函数
 输入参数  : ulAddr     -   原始地址
 输出参数  : 无
 返 回 值  : ulNewAddr  -   转换后的地址
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT_PTR PPP_HDLC_HARD_IOAddrCvt(VOS_UINT32 ulAddr)
{
    VOS_UINT_PTR                        ulNewAddr;

    if (VOS_NULL_PTR != g_stPppHdlcConfig.pIOAddrCvtFunc)
    {
        ulNewAddr = (VOS_UINT_PTR)g_stPppHdlcConfig.pIOAddrCvtFunc(ulAddr);
    }
    else
    {
        ulNewAddr = (VOS_UINT_PTR)ulAddr;
    }

    return ulNewAddr;
}



/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardConfig
 功能描述  : 配置HDLC相关信息
 输入参数  : pstHdlcConfig  -   配置信息
 输出参数  : 无
 返 回 值  : VOS_OK     -   配置信息合法
             VOS_ERR    -   配置信息非法
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_HdlcHardConfig(PPP_HDLC_HARD_CONFIG_INFO_STRU *pstHdlcConfig)
{
    if (VOS_NULL_PTR == pstHdlcConfig)
    {
        return VOS_ERR;
    }

    /* 如果HDLC使用内存长度为0，或者内存设置及拷贝函数为空，后续操作将无法进行 */
    if ((0 == pstHdlcConfig->ulPppTotalBufLen)
        || (VOS_NULL_PTR == pstHdlcConfig->pMemCpyFunc)
        || (VOS_NULL_PTR == pstHdlcConfig->pMemSetFunc))
    {
        return VOS_ERR;
    }

    /* 如果读写寄存器函数为空，HDLC硬件将无法正常工作 */
    if ((VOS_NULL_PTR == pstHdlcConfig->pRead32RegFunc)
        || (VOS_NULL_PTR == pstHdlcConfig->pWrite32RegFunc))
    {
        return VOS_ERR;
    }

    g_stPppHdlcConfig.pMemCpyFunc = pstHdlcConfig->pMemCpyFunc;
    PPP_HDLC_HARD_MEM_CPY(&g_stPppHdlcConfig, sizeof(PPP_HDLC_HARD_CONFIG_INFO_STRU),
                           pstHdlcConfig, sizeof(PPP_HDLC_HARD_CONFIG_INFO_STRU));

    return VOS_OK;
}


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif



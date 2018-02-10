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

#ifndef __HDLC_HRADWARE_CONF_H__
#define __HDLC_HRADWARE_CONF_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "TTFComm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/

/*内存拷贝宏定义, ulDestlen >= ulSrcLen */
#define PPP_HDLC_HARD_MEM_CPY(pucDestBuffer, ulDestlen, pucSrcBuffer, ulSrcLen) \
                    g_stPppHdlcConfig.pMemCpyFunc( pucDestBuffer, ulDestlen, pucSrcBuffer, ulSrcLen, VOS_FILE_ID, __LINE__ )

/*内存内容填充宏定义, ulDestLen >= ulFillLen */
#define PPP_HDLC_HARD_MEM_SET(pucDestBuffer, ulDestLen, ucData, ulFillLen) \
                    g_stPppHdlcConfig.pMemSetFunc( pucDestBuffer, ulDestLen, ucData, ulFillLen, VOS_FILE_ID, __LINE__ )

/* HDLC所使用的PID */
#define PS_PID_PPP_HDLC                 (g_stPppHdlcConfig.ulUserPid)

/* HDLC读写寄存器 */
#define PPP_HDLC_WRITE_32REG(pAddr, value)      g_stPppHdlcConfig.pWrite32RegFunc(pAddr, value)
#define PPP_HDLC_READ_32REG(pAddr)              g_stPppHdlcConfig.pRead32RegFunc(pAddr)
/* HDLC使用的封装解封装内存虚实地址转换 */
#define PPP_HDLC_HARD_BUF_PHY2VIRT(ulPAddr)     PPP_HDLC_HARD_BufPhy2Virt((VOS_UINT32)ulPAddr)
#define PPP_HDLC_HARD_BUF_VIRT2PHY(ulVAddr)     PPP_HDLC_HARD_BufVirt2Phy((VOS_UINT32)ulVAddr)
/* HDLC业务模块内存虚实地址转换 */
#define PPP_HDLC_HARD_MEM_PHY2VIRT(ulPAddr)     PPP_HDLC_HARD_MemPhy2Virt((VOS_UINT32)ulPAddr)
#define PPP_HDLC_HARD_MEM_VIRT2PHY(ulVAddr)     PPP_HDLC_HARD_MemVirt2Phy((VOS_UINT32)ulVAddr)
/* HDLC基地址IO转换 */
#define PPP_HDLC_HARD_IO_ADDRESS(ulAddr)        PPP_HDLC_HARD_IOAddrCvt(ulAddr)
/* HDLC解封装单个输入最大长度 */
#define HDLC_DEF_IN_PER_MAX_CNT                 (g_stPppHdlcConfig.ulDefOneMaxSize)


/*****************************************************************************
  3 枚举定义
*****************************************************************************/

/*****************************************************************************
  4 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/

/*****************************************************************************
 结构名    : PPP_HDLC_HARD_MEM_SET_FUNC
 协议表格  :
 ASN.1描述 :
 结构说明  : hdlc使用的内存设置函数
*****************************************************************************/
typedef VOS_VOID (*PPP_HDLC_HARD_MEM_SET_FUNC)
(
    VOS_VOID                           *pDest,
    VOS_SIZE_T                          ulDestSize,
    VOS_CHAR                            cChar,
    VOS_SIZE_T                          ulCount,
    VOS_INT32                           ulFileID,
    VOS_INT32                           usLineNo
);

/*****************************************************************************
 结构名    : PPP_HDLC_HARD_MEM_CPY_FUNC
 协议表格  :
 ASN.1描述 :
 结构说明  : hdlc使用的内存拷贝函数
*****************************************************************************/
typedef VOS_VOID (*PPP_HDLC_HARD_MEM_CPY_FUNC)
(
    VOS_VOID                           *pDest,
    VOS_SIZE_T                          ulDestSize,
    const VOS_VOID                     *pSrc,
    VOS_SIZE_T                          ulCount,
    VOS_INT32                           lFileID,
    VOS_INT32                           lLineNo
);

/*****************************************************************************
 结构名    : PPP_HDLC_HARD_MEM_CVT_FUNC
 协议表格  :
 ASN.1描述 :
 结构说明  : 业务模块内存虚实地址转换函数
*****************************************************************************/
typedef VOS_UINT32 (*PPP_HDLC_HARD_MEM_CVT_FUNC)
(
    VOS_UINT32                          ulAddr
);

/*****************************************************************************
 结构名    : PPP_HDLC_HARD_BUF_CVT_FUNC
 协议表格  :
 ASN.1描述 :
 结构说明  : hdlc使用的内存的虚实地址转换函数
*****************************************************************************/
typedef VOS_UINT_PTR (*PPP_HDLC_HARD_BUF_CVT_FUNC)
(
    VOS_UINT8                          *pucCurAddr,
    VOS_UINT8                          *pucStartAddr1,
    VOS_UINT8                          *pucStartAddr2,
    VOS_UINT32                          ulBufLen
);

/*****************************************************************************
 结构名    : PPP_HDLC_HARD_WRITE_REG_FUNC
 协议表格  :
 ASN.1描述 :
 结构说明  : 写32位寄存器
*****************************************************************************/
typedef VOS_VOID (*PPP_HDLC_HARD_WRITE_REG_FUNC)
(
    VOS_UINT32                          ulAddr,
    VOS_UINT32                          ulValue
);

/*****************************************************************************
 结构名    : PPP_HDLC_HARD_READ_REG_FUNC
 协议表格  :
 ASN.1描述 :
 结构说明  : 读32位寄存器
*****************************************************************************/
typedef VOS_UINT32 (*PPP_HDLC_HARD_READ_REG_FUNC)
(
    VOS_UINT32                          ulAddr
);

/*****************************************************************************
 结构名    : PPP_HDLC_HARD_IO_CVT_FUNC
 协议表格  :
 ASN.1描述 :
 结构说明  : IO地址映射函数
*****************************************************************************/
typedef VOS_UINT32 (*PPP_HDLC_HARD_IO_CVT_FUNC)
(
    VOS_UINT32                          ulAddr
);


/*****************************************************************************
 结构名    : PPP_HDLC_HARD_CONFIG_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : hdlc配置信息
                pMemPhy2VirtFunc、pMemVirt2PhyFunc、pBufPhy2VirtFunc、pBufVirt2PhyFunc、
             pIOAddrCvtFunc为空表示不需要转换
                pMemSetFunc、pMemCpyFunc、ulUserPid、ulPppTotalBufLen、pWrite32RegFunc、
             pRead32RegFunc不允许为空
                ulPppVirtAddr、ulPppPhyAddr为Service模块申请，业务层不用配置
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulPppTotalBufLen;       /* HDLC使用的内存长度，有业务模块配置 */
    VOS_UINT_PTR                        ulPppVirtAddr;          /* HDLC使用内存的虚地址，业务模块配置长度，Service申请 */
    VOS_UINT_PTR                        ulPppPhyAddr;           /* HDLC使用内存的实地址 */
    PPP_HDLC_HARD_MEM_SET_FUNC          pMemSetFunc;            /* HDLC使用的内存设置函数，业务模块配置 */
    PPP_HDLC_HARD_MEM_CPY_FUNC          pMemCpyFunc;            /* HDLC使用的内存拷贝函数，业务模块配置 */
    PPP_HDLC_HARD_MEM_CVT_FUNC          pMemPhy2VirtFunc;       /* 业务模块内存实地址转虚地址函数，业务模块配置 */
    PPP_HDLC_HARD_MEM_CVT_FUNC          pMemVirt2PhyFunc;       /* 业务模块内存虚地址转实地址函数，业务模块配置 */
    PPP_HDLC_HARD_BUF_CVT_FUNC          pBufPhy2VirtFunc;       /* HDLC内存实地址转虚地址函数，业务模块配置 */
    PPP_HDLC_HARD_BUF_CVT_FUNC          pBufVirt2PhyFunc;       /* HDLC内存虚地址转实地址函数，业务模块配置 */
    VOS_UINT32                          ulUserPid;              /* 业务模块PID */
    PPP_HDLC_HARD_WRITE_REG_FUNC        pWrite32RegFunc;        /* 写寄存器函数 */
    PPP_HDLC_HARD_READ_REG_FUNC         pRead32RegFunc;         /* 读寄存器函数 */
    PPP_HDLC_HARD_IO_CVT_FUNC           pIOAddrCvtFunc;         /* IO地址映射函数 */
    VOS_UINT32                          ulDefOneMaxSize;        /* 解封装输入单个报文最大长度 */
}PPP_HDLC_HARD_CONFIG_INFO_STRU;


/*****************************************************************************
  8 UNION定义
*****************************************************************************/



/*****************************************************************************
  9 全局变量声明
*****************************************************************************/
extern PPP_HDLC_HARD_CONFIG_INFO_STRU          g_stPppHdlcConfig;


/*****************************************************************************
  10 函数声明
*****************************************************************************/
VOS_UINT32 PPP_HdlcHardConfig(PPP_HDLC_HARD_CONFIG_INFO_STRU *pstHdlcConfig);

VOS_UINT8* PPP_HDLC_HARD_BufPhy2Virt(VOS_UINT32 ulPAddr);
VOS_UINT8* PPP_HDLC_HARD_BufVirt2Phy(VOS_UINT32 ulVAddr);

VOS_UINT8* PPP_HDLC_HARD_MemPhy2Virt(VOS_UINT32 ulPAddr);
VOS_UINT8* PPP_HDLC_HARD_MemVirt2Phy(VOS_UINT32 ulVAddr);

VOS_UINT_PTR PPP_HDLC_HARD_IOAddrCvt(VOS_UINT32 ulAddr);



#pragma pack()


#ifdef __cplusplus
    #if __cplusplus
            }
    #endif
#endif


#endif



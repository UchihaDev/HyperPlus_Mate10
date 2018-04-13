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

/*****************************************************************************/
/*                                                                           */
/*                Copyright 1999 - 2003, Huawei Tech. Co., Ltd.              */
/*                           ALL RIGHTS RESERVED                             */
/*                                                                           */
/* FileName: OmRingBuffer.h                                                  */
/*                                                                           */
/* Author: Windriver                                                         */
/*                                                                           */
/* Version: 1.0                                                              */
/*                                                                           */
/* Date: 2008-06                                                             */
/*                                                                           */
/* Description: implement ring buffer subroutine                             */
/*                                                                           */
/* Others:                                                                   */
/*                                                                           */
/* History:                                                                  */
/* 1. Date:                                                                  */
/*    Author: H59254                                                         */
/*    Modification: Adapt this file                                          */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#ifndef  _OM_RING_BUFFER_H
#define  _OM_RING_BUFFER_H

#include "vos.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */


typedef struct
{
    int  pToBuf;    /* offset from start of buffer where to write next */
    int  pFromBuf;  /* offset from start of buffer where to read next */
    int  bufSize;   /* size of ring in bytes */
    char acRsv[4];
    char *buf;      /* pointer to start of buffer */
} OM_RING;

typedef OM_RING * OM_RING_ID;

#if(FEATURE_ON == FEATURE_PTM)

typedef struct
{
    OM_RING         stOmringId;
    VOS_SPINLOCK    stSpinLock;  /* spin lock */
} PTM_RING;

typedef PTM_RING * PTM_RING_ID;

extern VOS_INT32 PTM_RingBufferCreate(PTM_RING_ID ptmringId, char *pdata, int nbytes );
extern void PTM_RingBufferFlush(PTM_RING_ID ptmringId);
extern int PTM_RingBufferFreeBytes( PTM_RING_ID ptmringId);
extern int PTM_RingBufferGet(PTM_RING_ID ptmringId, char *buffer, int maxbytes);
extern int PTM_RingBufferGetReserve( PTM_RING_ID ptmringId, char *buffer, int maxbytes );
extern VOS_BOOL PTM_RingBufferIsEmpty( PTM_RING_ID ptmringId );
extern VOS_BOOL PTM_RingBufferIsFull( PTM_RING_ID ptmringId );
extern int PTM_RingBufferNBytes( PTM_RING_ID ptmringId );
extern int PTM_RingBufferPut( PTM_RING_ID ptmringId, char *buffer, int nbytes );
extern int PTM_RingBufferRemove(PTM_RING_ID ptmringId, int maxbytes);
extern VOS_UINT32 PTM_RingBufferGetByAlarmID(
    PTM_RING_ID                         ptmringId,
    char                               *pucbuf,
    VOS_UINT32                          ulmaxbytes,
    VOS_UINT32                         *pulAlarmBuff,
    VOS_UINT32                          ulAlarmIdCount,
    VOS_UINT32                         *pulAlarmbytes
);

OM_RING_ID OM_RingBufferCreateEx(char *pdata, int nbytes );

/*****************************************************************************
 函 数 名  : OM_ErrLogRingBufferCreate --> 新提供接口
 功能描述  : 已有内存中创建一个空环形buff
 输入参数  : ringId : buff 控制块地址
             pdata  : 已有内存地址
             nbytes : 内存地址长度

 输出参数  : ringId : 初始化后的环形buffer ID

 返 回 值  : VOS_OK / VOS_ERR

 修改历史      :
  1.日    期   : 2017年04月19日
    作    者   : d00212987
    修改内容   : Err Log环形buffer修改新增
*****************************************************************************/
VOS_INT32 OM_ErrLogRingBufferCreate(OM_RING_ID   ringId, char *pdata, int nbytes );

/*****************************************************************************
 函 数 名  : OM_RingBufferGetByAlarmID
 功能描述  : 通过alarm id取出所有相关Errlog
 输入参数  : ringId         : 环形buff ID
             buffer         : Alarm ID相关Errlog存放地址
             maxbytes       : Alarm ID相关Errlog存放空间长度
             pulAlarmBuff   : Alarm ID
             ulAlarmIdCount : Alarm ID个数

 输出参数  : pulArmbytes     : 获取到的Errlog大小

 返 回 值  : VOS_OK / VOS_ERR

 修改历史      :
  1.日    期   : 2017年04月19日
    作    者   : d00212987
    修改内容   : Err Log环形buffer修改新增
*****************************************************************************/
VOS_UINT32  OM_RingBufferGetByAlarmID(
    OM_RING_ID                          rngId,
    char                               *buffer,
    VOS_UINT32                          ulmaxbytes,
    VOS_UINT32                         *pulAlarmBuff,
    VOS_UINT32                          ulAlarmIdCount,
    VOS_UINT32                         *pulArmbytes
);
#endif

extern OM_RING_ID OM_RingBufferCreate( int nbytes );

extern void OM_RingBufferFlush( OM_RING_ID ringId );

extern int OM_RingBufferGet( OM_RING_ID rngId, char *buffer, int maxbytes );

extern int OM_RingBufferRemove( OM_RING_ID rngId, int maxbytes );

extern int OM_RingBufferGetReserve( OM_RING_ID rngId, char *buffer, int maxbytes );

extern int OM_RingBufferPut( OM_RING_ID rngId, char *buffer, int nbytes );
extern VOS_BOOL OM_RingBufferIsFull( OM_RING_ID ringId );

extern VOS_BOOL OM_RingBufferIsEmpty( OM_RING_ID ringId );

extern int OM_RingBufferFreeBytes( OM_RING_ID ringId);

extern int OM_RingBufferNBytes( OM_RING_ID ringId );


#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif /* _OM_RING_BUFFER_H */


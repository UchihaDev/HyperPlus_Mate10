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
/*                Copyright 1999 - 2008, Huawei Tech. Co., Ltd.              */
/*                           ALL RIGHTS RESERVED                             */
/*                                                                           */
/* FileName: OMRingBuffer.c                                                  */
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

#include "omringbuffer.h"
#include "omprivate.h"

#include "omerrorlog.h"



#define    THIS_FILE_ID        PS_FILE_ID_OMRINGBUFFER_C


#define OM_ARM_ALIGNMENT         0x03
#define OM_EVEN_NUBER            0x01

#define OM_MIN(x, y)             (((x) < (y)) ? (x) : (y))

#define OM_RING_BUFF_EX_MAX_LEN  (1024*8)
#define OM_MAX_RING_BUFFER_NUM   (48)  /* Error log新增32*/

VOS_UINT8 g_ucOMBufferOccupiedFlag[OM_MAX_RING_BUFFER_NUM] = {0};
OM_RING   g_stOMControlBlock[OM_MAX_RING_BUFFER_NUM];

/*the location of buf which should be allocated */
VOS_UINT32 g_ulOmRingBufSuffix = 0;

/* Comes from v_blkmem.c */
extern VOS_SPINLOCK             g_stVosStaticMemSpinLock;

/*******************************************************************************
*
* OM_RealMemCopy - copy one buffer to another
*
* This routine copies the first <nbytes> characters from <source> to
* <destination>.  Overlapping buffers are handled correctly.  Copying is done
* in the most efficient way possible, which may include long-word, or even
* multiple-long-word moves on some architectures.  In general, the copy
* will be significantly faster if both buffers are long-word aligned.
* (For copying that is restricted to byte, word, or long-word moves, see
* the manual entries for bcopyBytes(), bcopyWords(), and bcopyLongs().)
*
* RETURNS: N/A
*
* ERRNO: N/A
*
* SEE ALSO:
*/
void OM_RealMemCopy( const char *source, char *destination, int nbytes )
{
    char *dstend;
    int *src;
    int *dst;
    int tmp = destination - source;

    if ( 0 == nbytes )
    {
        return;
    }

    if ( (tmp <= 0) || (tmp >= nbytes) )
    {
        /* forward copy */
        dstend = destination + nbytes;

        /* do byte copy if less than ten or alignment mismatch */
        if (nbytes < 10 || (((VOS_INT_PTR)destination ^ (VOS_INT_PTR)source) & OM_ARM_ALIGNMENT))
        {
            /*lint -e801 */
            goto byte_copy_fwd;
            /*lint +e801 */
        }

        /* if odd-aligned copy byte */
        while ((VOS_INT_PTR)destination & OM_ARM_ALIGNMENT)
        {
            *destination++ = *source++;
        }

        src = (int *) source;
        dst = (int *) destination;

        do
        {
            *dst++ = *src++;
        }while (((char *)dst + sizeof (int)) <= dstend);

        destination = (char *)dst;
        source      = (char *)src;

byte_copy_fwd:
        while (destination < dstend)
        {
            *destination++ = *source++;
        }
    }
    else
    {
        /* backward copy */
        dstend       = destination;
        destination += nbytes;
        source      += nbytes;

        /* do byte copy if less than ten or alignment mismatch */
        if (nbytes < 10 || (((VOS_INT_PTR)destination ^ (VOS_INT_PTR)source) & OM_ARM_ALIGNMENT))
        {
            /*lint -e801 */
            goto byte_copy_bwd;
            /*lint +e801 */
        }

        /* if odd-aligned copy byte */
        while ((VOS_INT_PTR)destination & OM_ARM_ALIGNMENT)
        {
            *--destination = *--source;
        }

        src = (int *) source;
        dst = (int *) destination;

        do
        {
            *--dst = *--src;
        }while (((char *)dst - sizeof(int)) >= dstend);

        destination = (char *)dst;
        source      = (char *)src;

byte_copy_bwd:
        while (destination > dstend)
        {
            *--destination = *--source;
        }
    }
}

/*****************************************************************************
 函 数 名  : PTM_RingBufferCreate
 功能描述  : 创建CHR使用的环形缓存
 输入参数  : PTM_RING_ID ptmringId
             char *pdata
             int nbytes
 输出参数  : 无
 返 回 值  : VOS_INT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年7月26日
    作    者   : lixiao 00246515
    修改内容   : 新生成函数

*****************************************************************************/
VOS_INT32 PTM_RingBufferCreate(PTM_RING_ID ptmringId, char *pdata, int nbytes )
{
    if (VOS_NULL_PTR == ptmringId)
    {
        return VOS_ERR;
    }

    if ((VOS_NULL_PTR == pdata)||(OM_RING_BUFF_EX_MAX_LEN < nbytes))
    {
        return VOS_ERR;
    }

    ptmringId->stOmringId.bufSize  = nbytes;
    ptmringId->stOmringId.buf      = pdata;
    ptmringId->stOmringId.pToBuf   = 0;
    ptmringId->stOmringId.pFromBuf = 0;

    VOS_SpinLockInit(&ptmringId->stSpinLock);

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : PTM_RingBufferFlush
 功能描述  : 对CHR使用的环形缓存进行Flush操作
 输入参数  : PTM_RING_ID ptmringId
 输出参数  : 无
 返 回 值  : VOS_INT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年7月26日
    作    者   : lixiao 00246515
    修改内容   : 新生成函数

*****************************************************************************/
void PTM_RingBufferFlush(PTM_RING_ID ptmringId)
{
    VOS_SpinLock(&ptmringId->stSpinLock);

    OM_RingBufferFlush(&ptmringId->stOmringId);

    VOS_SpinUnlock(&ptmringId->stSpinLock);

    return;
}

/*****************************************************************************
 函 数 名  : PTM_RingBufferGet
 功能描述  : 对CHR使用的环形缓存进行Get操作
 输入参数  : PTM_RING_ID ptmringId
             char *buffer
             int maxbytes
 输出参数  : 无
 返 回 值  : int
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年7月26日
    作    者   : lixiao 00246515
    修改内容   : 新生成函数

*****************************************************************************/
int PTM_RingBufferGet(PTM_RING_ID ptmringId, char *buffer, int maxbytes)
{
    int bytesgot;

    VOS_SpinLock(&ptmringId->stSpinLock);

    bytesgot = OM_RingBufferGet(&ptmringId->stOmringId, buffer, maxbytes);

    VOS_SpinUnlock(&ptmringId->stSpinLock);

    return (bytesgot);
}

/*****************************************************************************
 函 数 名  : PTM_RingBufferRemove
 功能描述  : 对CHR使用的环形缓存进行Remove操作
 输入参数  : PTM_RING_ID ptmringId
             int maxbytes
 输出参数  : 无
 返 回 值  : int
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年7月26日
    作    者   : lixiao 00246515
    修改内容   : 新生成函数

*****************************************************************************/
int PTM_RingBufferRemove(PTM_RING_ID ptmringId, int maxbytes)
{
    int bytesgot;

    VOS_SpinLock(&ptmringId->stSpinLock);

    bytesgot = OM_RingBufferRemove(&ptmringId->stOmringId, maxbytes);

    VOS_SpinUnlock(&ptmringId->stSpinLock);

    return (bytesgot);
}

/*****************************************************************************
 函 数 名  : PTM_RingBufferGetReserve
 功能描述  : 对CHR使用的环形缓存进行GetReserve操作
 输入参数  : PTM_RING_ID ptmringId
             char *buffer
             int maxbytes
 输出参数  : 无
 返 回 值  : int
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年7月26日
    作    者   : lixiao 00246515
    修改内容   : 新生成函数

*****************************************************************************/
int PTM_RingBufferGetReserve( PTM_RING_ID ptmringId, char *buffer, int maxbytes )
{
    int bytesgot;

    VOS_SpinLock(&ptmringId->stSpinLock);

    bytesgot = OM_RingBufferGetReserve(&ptmringId->stOmringId, buffer, maxbytes);

    VOS_SpinUnlock(&ptmringId->stSpinLock);

    return (bytesgot);
}


/*****************************************************************************
 函 数 名  : PTM_RingBufferPut
 功能描述  : 对CHR使用的环形缓存进行Put操作
 输入参数  : PTM_RING_ID ptmringId
             char *buffer
             int nbytes
 输出参数  : 无
 返 回 值  : int
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年7月26日
    作    者   : lixiao 00246515
    修改内容   : 新生成函数

*****************************************************************************/
int PTM_RingBufferPut( PTM_RING_ID ptmringId, char *buffer, int nbytes )
{
    int bytesput;

    VOS_SpinLock(&ptmringId->stSpinLock);

    bytesput = OM_RingBufferPut(&ptmringId->stOmringId, buffer, nbytes);

    VOS_SpinUnlock(&ptmringId->stSpinLock);

    return (bytesput);
}

/*****************************************************************************
 函 数 名  : PTM_RingBufferIsEmpty
 功能描述  : 对CHR使用的环形缓存进行IsEmpty判断
 输入参数  : PTM_RING_ID ptmringId
 输出参数  : 无
 返 回 值  : VOS_BOOL
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年7月26日
    作    者   : lixiao 00246515
    修改内容   : 新生成函数

*****************************************************************************/
VOS_BOOL PTM_RingBufferIsEmpty( PTM_RING_ID ptmringId )
{
    VOS_BOOL ulret;

    VOS_SpinLock(&ptmringId->stSpinLock);

    ulret = OM_RingBufferIsEmpty(&ptmringId->stOmringId);

    VOS_SpinUnlock(&ptmringId->stSpinLock);

    return ulret;
}

/*****************************************************************************
 函 数 名  : PTM_RingBufferIsFull
 功能描述  : 对CHR使用的环形缓存进行IsFull判断
 输入参数  : PTM_RING_ID ptmringId
 输出参数  : 无
 返 回 值  : VOS_BOOL
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年7月26日
    作    者   : lixiao 00246515
    修改内容   : 新生成函数

*****************************************************************************/
VOS_BOOL PTM_RingBufferIsFull( PTM_RING_ID ptmringId )
{
    VOS_BOOL ulret;

    VOS_SpinLock(&ptmringId->stSpinLock);

    ulret = OM_RingBufferIsFull(&ptmringId->stOmringId);

    VOS_SpinUnlock(&ptmringId->stSpinLock);

    return ulret;
}

/*****************************************************************************
 函 数 名  : PTM_RingBufferFreeBytes
 功能描述  : 对CHR使用的环形缓存进行FreeBytes判断
 输入参数  : PTM_RING_ID ptmringId
 输出参数  : 无
 返 回 值  : int
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年7月26日
    作    者   : lixiao 00246515
    修改内容   : 新生成函数

*****************************************************************************/
int PTM_RingBufferFreeBytes( PTM_RING_ID ptmringId)
{
    int bytesfree;

    VOS_SpinLock(&ptmringId->stSpinLock);

    bytesfree = OM_RingBufferFreeBytes(&ptmringId->stOmringId);

    VOS_SpinUnlock(&ptmringId->stSpinLock);

    return (bytesfree);
}

/*****************************************************************************
 函 数 名  : PTM_RingBufferNBytes
 功能描述  : 对CHR使用的环形缓存进行FreeNBytes判断
 输入参数  : PTM_RING_ID ptmringId
 输出参数  : 无
 返 回 值  : int
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年7月26日
    作    者   : lixiao 00246515
    修改内容   : 新生成函数

*****************************************************************************/
int PTM_RingBufferNBytes( PTM_RING_ID ptmringId )
{
    int bytes;

    VOS_SpinLock(&ptmringId->stSpinLock);

    bytes = OM_RingBufferNBytes(&ptmringId->stOmringId);

    VOS_SpinUnlock(&ptmringId->stSpinLock);

    return (bytes);
}

/*****************************************************************************
 函 数 名  : PTM_RingBufferGetByAlarmID
 功能描述  : 通过alarm id取出所有相关CHR,查找失败清空环形buffer
 输入参数  : ringId         : 环形buff ID
             buffer         : Alarm ID相关Errlog存放地址
             ulmaxbytes     : Alarm ID相关Errlog存放空间长度
             pulAlarmBuff   : Alarm ID
             ulAlarmIdCount : Alarm ID个数

 输出参数  : ulAlarmbytes    : 获取到的Errlog大小

 返 回 值  : VOS_OK / VOS_ERR

 修改历史      :
  1.日    期   : 2017年07月26日
    作    者   : l00246515
    修改内容   : CHR环形buffer修改新增
*****************************************************************************/
VOS_UINT32 PTM_RingBufferGetByAlarmID(
    PTM_RING_ID                         ptmringId,
    char                               *pucbuf,
    VOS_UINT32                          ulmaxbytes,
    VOS_UINT32                         *pulAlarmBuff,
    VOS_UINT32                          ulAlarmIdCount,
    VOS_UINT32                         *pulAlarmbytes
)
{
    VOS_UINT32 ulRet;

    VOS_SpinLock(&ptmringId->stSpinLock);

    ulRet = OM_RingBufferGetByAlarmID(  &ptmringId->stOmringId,
                                        pucbuf,
                                        ulmaxbytes,
                                        pulAlarmBuff,
                                        ulAlarmIdCount,
                                        pulAlarmbytes );

    VOS_SpinUnlock(&ptmringId->stSpinLock);

    return ulRet;
}

/*******************************************************************************
*
* OM_RingBufferCreateEx - create an empty ring buffer in exist buffer  --> 该接口不再使用,需使用:OM_ErrLogRingBufferCreate
*
* This routine creates a ring buffer of size <nbytes>, and initializes
* it.  Memory for the buffer is allocated by user.
*
* RETURNS
* The ID of the ring buffer, or NULL if memory cannot be allocated.
*
* ERRNO: N/A.
************************************************************************/
OM_RING_ID OM_RingBufferCreateEx(char *pdata, int nbytes )
{
    OM_RING_ID   ringId;
    VOS_INT      i;
    VOS_INT      lTempSufffix = VOS_NULL_WORD;
    VOS_ULONG    ulLockLevel;

    if ((VOS_NULL_PTR == pdata)||(OM_RING_BUFF_EX_MAX_LEN < nbytes))
    {
        return VOS_NULL_PTR;
    }

    /*lLockLevel = VOS_SplIMP();*/
    VOS_SpinLockIntLock(&g_stVosStaticMemSpinLock, ulLockLevel);

    for ( i=OM_MAX_RING_BUFFER_NUM -1; i>=0; i-- )
    {
        if ( VOS_FALSE == g_ucOMBufferOccupiedFlag[i] )
        {
            lTempSufffix = i;
            g_ucOMBufferOccupiedFlag[i] = VOS_TRUE;
            break;
        }
    }

    /*VOS_Splx(lLockLevel);*/
    VOS_SpinUnlockIntUnlock(&g_stVosStaticMemSpinLock, ulLockLevel);

    if ( VOS_NULL_WORD == lTempSufffix )
    {
        return VOS_NULL_PTR;
    }

    /*
     * bump number of bytes requested because ring buffer algorithm
     * always leaves at least one empty byte in buffer
     */

    ringId = &(g_stOMControlBlock[lTempSufffix]);

    ringId->bufSize = nbytes;
    ringId->buf     = pdata;

    OM_RingBufferFlush (ringId);

    return (ringId);

}

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
VOS_INT32 OM_ErrLogRingBufferCreate(OM_RING_ID   ringId, char *pdata, int nbytes )
{
    if ((VOS_NULL_PTR == pdata)||(OM_RING_BUFF_EX_MAX_LEN < nbytes))
    {
        return VOS_ERR;
    }

    if (VOS_NULL_PTR == ringId)
    {
        return VOS_ERR;
    }

    /*
     * bump number of bytes requested because ring buffer algorithm
     * always leaves at least one empty byte in buffer
     */

    ringId->bufSize = nbytes;
    ringId->buf     = pdata;

    OM_RingBufferFlush (ringId);

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : OM_RingBufferchFindArmID
 功能描述  : 通过alarm id取出所有相关Errlog
 输入参数  : ringId         : 环形buff ID
             buffer         : Alarm ID相关Errlog存放地址
             ulmaxbytes     : Alarm ID相关Errlog存放空间长度
             pulAlarmBuff   : Alarm ID
             ulAlarmIdCount : Alarm ID个数

 输出参数  : ulAlarmbytes    : 获取到的Errlog大小

 返 回 值  : VOS_OK / VOS_ERR

 修改历史      :
  1.日    期   : 2017年04月19日
    作    者   : d00212987
    修改内容   : Err Log环形buffer修改新增
*****************************************************************************/
VOS_UINT32 OM_RingBufferchFindArmID(
    VOS_UINT32                         *pulAlarmBuff,
    VOS_UINT32                          ulAlarmIdCount,
    VOS_UINT32                          ulFindAlarmId
)
{
    VOS_UINT32                           i;

    for (i= 0; i<ulAlarmIdCount; i++)
    {
        if (ulFindAlarmId == pulAlarmBuff[i])
        {
            return VOS_OK;
        }
    }

    return VOS_ERR;
}


/*****************************************************************************
 函 数 名  : OM_RingBufferGetByAlarmID
 功能描述  : 通过alarm id取出所有相关Errlog,查找失败清空环形buffer
 输入参数  : ringId         : 环形buff ID
             buffer         : Alarm ID相关Errlog存放地址
             ulmaxbytes     : Alarm ID相关Errlog存放空间长度
             pulAlarmBuff   : Alarm ID
             ulAlarmIdCount : Alarm ID个数

 输出参数  : ulAlarmbytes    : 获取到的Errlog大小

 返 回 值  : VOS_OK / VOS_ERR

 修改历史      :
  1.日    期   : 2017年04月19日
    作    者   : d00212987
    修改内容   : Err Log环形buffer修改新增
*****************************************************************************/
VOS_UINT32 OM_RingBufferGetByAlarmID(
    OM_RING_ID                          rngId,
    char                               *buffer,
    VOS_UINT32                          ulmaxbytes,
    VOS_UINT32                         *pulAlarmBuff,
    VOS_UINT32                          ulAlarmIdCount,
    VOS_UINT32                         *pulAlarmbytes
)
{
    int                                 bytesgot;
    int                                 bytesgottemp;
    VOS_UINT32                          ulErrlogLen;
    OM_ERR_LOG_HEADER_STRU             *pstErrlogPayload;
    VOS_UINT32                          ulReadCount = 0;
    VOS_UINT32                          ulIndex     = 0;

    /* 参数检查 */
    if (VOS_NULL_PTR == rngId)
    {
        return VOS_ERR;
    }

    /* 参数检查 */
    if (  (VOS_NULL_PTR == buffer)
       || (VOS_NULL_PTR == pulAlarmBuff)
       || (VOS_NULL_PTR == pulAlarmbytes))
    {
        return VOS_ERR;
    }

    bytesgot = OM_RingBufferNBytes(rngId);

    if (((VOS_INT32)ulmaxbytes < bytesgot) || (0 == ulAlarmIdCount))
    {
        return VOS_ERR;
    }

    while ((VOS_INT32)ulReadCount < bytesgot)
    {
        /* 读取全部环形buffer内容到 */
        /*lint -e613*/
        bytesgottemp = OM_RingBufferGet(rngId, &buffer[ulIndex], sizeof(OM_ERR_LOG_HEADER_STRU));
        /*lint +e613*/
        if (bytesgottemp != sizeof(OM_ERR_LOG_HEADER_STRU))
        {
            OM_RingBufferFlush(rngId);

            return VOS_ERR;
        }

        ulReadCount += bytesgottemp;

        pstErrlogPayload = (OM_ERR_LOG_HEADER_STRU*)&buffer[ulIndex];
        /*lint -e679 */
        bytesgottemp = OM_RingBufferGet(rngId, &buffer[ulIndex + bytesgottemp], (VOS_INT32)pstErrlogPayload->ulAlmLength);
        /*lint +e679 */
        if (bytesgottemp != pstErrlogPayload->ulAlmLength)
        {
            OM_RingBufferFlush(rngId);

            return VOS_ERR;
        }

        ulReadCount += bytesgottemp;

        ulErrlogLen = (sizeof(OM_ERR_LOG_HEADER_STRU) + pstErrlogPayload->ulAlmLength);

        /* 是否是查找Alarm ID */
        if (VOS_OK != OM_RingBufferchFindArmID(pulAlarmBuff, ulAlarmIdCount, pstErrlogPayload->usAlmId))
        {
            if (ulErrlogLen != OM_RingBufferPut(rngId, &buffer[ulIndex], (VOS_INT32)ulErrlogLen))
            {
                OM_RingBufferFlush(rngId);

                return VOS_ERR;
            }
        }
        else
        {
            ulIndex += ulErrlogLen;
        }
    }

    *pulAlarmbytes = ulIndex;

    return VOS_OK;
}


/*******************************************************************************
*
* OM_RingBufferCreate - create an empty ring buffer
*
* This routine creates a ring buffer of size <nbytes>, and initializes
* it.  Memory for the buffer is allocated from the system memory partition.
*
* RETURNS
* The ID of the ring buffer, or NULL if memory cannot be allocated.
*
* ERRNO: N/A.
************************************************************************/
OM_RING_ID OM_RingBufferCreate( int nbytes )
{
    char         *buffer;
    OM_RING_ID    ringId;
    VOS_INT       i;
    VOS_INT       lTempSufffix = VOS_NULL_WORD;
    VOS_ULONG     ulLockLevel;

    /*lLockLevel = VOS_SplIMP();*/
    VOS_SpinLockIntLock(&g_stVosStaticMemSpinLock, ulLockLevel);

    for ( i=OM_MAX_RING_BUFFER_NUM -1; i>=0; i-- )
    {
        if ( VOS_FALSE == g_ucOMBufferOccupiedFlag[i] )
        {
            lTempSufffix = i;
            g_ucOMBufferOccupiedFlag[i] = VOS_TRUE;
            break;
        }
    }

    /*VOS_Splx(lLockLevel);*/
    VOS_SpinUnlockIntUnlock(&g_stVosStaticMemSpinLock, ulLockLevel);

    if ( VOS_NULL_WORD == lTempSufffix )
    {
        return VOS_NULL_PTR;
    }

    /*
     * bump number of bytes requested because ring buffer algorithm
     * always leaves at least one empty byte in buffer
     */

    /* buffer = (char *) malloc ((unsigned) ++nbytes); */
    buffer = (char *) VOS_CacheMemAllocDebug((unsigned) ++nbytes, OM_RNG_BUFFER_ALLOC);

    if ( VOS_NULL_PTR == buffer )
    {
        /*lLockLevel = VOS_SplIMP();*/
        VOS_SpinLockIntLock(&g_stVosStaticMemSpinLock, ulLockLevel);

        g_ucOMBufferOccupiedFlag[lTempSufffix] = VOS_FALSE;

        /*VOS_Splx(lLockLevel);*/
        VOS_SpinUnlockIntUnlock(&g_stVosStaticMemSpinLock, ulLockLevel);

        OM_DRV_CACHEDMAM_ALLOC_ERROR();

        return VOS_NULL_PTR;
    }

    ringId = &(g_stOMControlBlock[lTempSufffix]);

    ringId->bufSize = nbytes;
    ringId->buf     = buffer;

    OM_RingBufferFlush (ringId);

    return (ringId);
}

/*******************************************************************************
*
* OM_RingBufferFlush - make a ring buffer empty
*
* This routine initializes a specified ring buffer to be empty.
* Any data currently in the buffer will be lost.
*
* RETURNS: N/A
*
* ERRNO: N/A.
*/
void OM_RingBufferFlush( OM_RING_ID ringId )
{
    ringId->pToBuf   = 0;
    ringId->pFromBuf = 0;
}

/*******************************************************************************
*
* OM_RingBufferGet - get characters from a ring buffer
*
* This routine copies bytes from the ring buffer <rngId> into <buffer>.
* It copies as many bytes as are available in the ring, up to <maxbytes>.
* The bytes copied will be removed from the ring.
*
* RETURNS:
* The number of bytes actually received from the ring buffer;
* it may be zero if the ring buffer is empty at the time of the call.
*
* ERRNO: N/A.
*/
int OM_RingBufferGet( OM_RING_ID rngId, char *buffer, int maxbytes )
{
    int bytesgot;
    int pToBuf;
    int bytes2;
    int pRngTmp;
    /*int lLockLevel;*/

    /*lLockLevel = VOS_SplIMP();*/

    pToBuf = rngId->pToBuf;

    if (pToBuf >= rngId->pFromBuf)
    {
        /* pToBuf has not wrapped around */
        bytesgot = OM_MIN(maxbytes, pToBuf - rngId->pFromBuf);
        OM_RealMemCopy (&rngId->buf [rngId->pFromBuf], buffer, bytesgot);
        rngId->pFromBuf += bytesgot;
    }
    else
    {
        /* pToBuf has wrapped around.  Grab chars up to the end of the
         * buffer, then wrap around if we need to. */
        /*lint -e613*/
        bytesgot = OM_MIN(maxbytes, rngId->bufSize - rngId->pFromBuf);
        /*lint +e613*/
        OM_RealMemCopy (&rngId->buf [rngId->pFromBuf], buffer, bytesgot);
        pRngTmp = rngId->pFromBuf + bytesgot;

        /* If pFromBuf is equal to bufSize, we've read the entire buffer,
         * and need to wrap now.  If bytesgot < maxbytes, copy some more chars
         * in now. */
        if (pRngTmp == rngId->bufSize)
        {
            /*lint -e613*/
            bytes2 = OM_MIN(maxbytes - bytesgot, pToBuf);
            /*lint +e613*/
            OM_RealMemCopy (rngId->buf, buffer + bytesgot, bytes2);
            rngId->pFromBuf = bytes2;
            bytesgot += bytes2;
        }
        else
        {
            rngId->pFromBuf = pRngTmp;
        }
    }

    /*VOS_Splx(lLockLevel);*/

    return (bytesgot);
}

/*******************************************************************************
*
* OM_RingBufferRemove - remove characters from a ring buffer
*
* This routine copies bytes from the ring buffer <rngId> into <buffer>.
* It copies as many bytes as are available in the ring, up to <maxbytes>.
* The bytes copied will be removed from the ring.
*
* RETURNS:
* The number of bytes actually received from the ring buffer;
* it may be zero if the ring buffer is empty at the time of the call.
*
* ERRNO: N/A.
*/
int OM_RingBufferRemove( OM_RING_ID rngId, int maxbytes )
{
    int bytesgot;
    int pToBuf;
    int bytes2;
    int pRngTmp;
    /*int lLockLevel;*/

    /*lLockLevel = VOS_SplIMP();*/

    pToBuf = rngId->pToBuf;

    if (pToBuf >= rngId->pFromBuf)
    {
        /* pToBuf has not wrapped around */
        bytesgot = OM_MIN(maxbytes, pToBuf - rngId->pFromBuf);
        rngId->pFromBuf += bytesgot;
    }
    else
    {
        /* pToBuf has wrapped around.  Grab chars up to the end of the
         * buffer, then wrap around if we need to. */
        bytesgot = OM_MIN(maxbytes, rngId->bufSize - rngId->pFromBuf);
        pRngTmp = rngId->pFromBuf + bytesgot;

        /* If pFromBuf is equal to bufSize, we've read the entire buffer,
         * and need to wrap now.  If bytesgot < maxbytes, copy some more chars
         * in now. */
        if (pRngTmp == rngId->bufSize)
        {
            bytes2 = OM_MIN(maxbytes - bytesgot, pToBuf);
            rngId->pFromBuf = bytes2;
            bytesgot += bytes2;
        }
        else
        {
            rngId->pFromBuf = pRngTmp;
        }
    }

    /*VOS_Splx(lLockLevel);*/

    return (bytesgot);
}

/*******************************************************************************
*
* OM_RingBufferGetReserve - get characters from a ring buffer
*
* This routine copies bytes from the ring buffer <rngId> into <buffer>.
* It copies as many bytes as are available in the ring, up to <maxbytes>.
* The bytes copied will be removed from the ring.
*
* RETURNS:
* The number of bytes actually received from the ring buffer;
* it may be zero if the ring buffer is empty at the time of the call.
*
* ERRNO: N/A.
*/
int OM_RingBufferGetReserve( OM_RING_ID rngId, char *buffer, int maxbytes )
{
    int bytesgot;
    int pToBuf;
    int bytes2;
    int pRngTmp;
    /*int lLockLevel;*/

    /*lLockLevel = VOS_SplIMP();*/

    pToBuf = rngId->pToBuf;

    if (pToBuf >= rngId->pFromBuf)
    {
        /* pToBuf has not wrapped around */
        bytesgot = OM_MIN(maxbytes, pToBuf - rngId->pFromBuf);
        OM_RealMemCopy (&rngId->buf [rngId->pFromBuf], buffer, bytesgot);
    }
    else
    {
        /* pToBuf has wrapped around.  Grab chars up to the end of the
         * buffer, then wrap around if we need to. */
        bytesgot = OM_MIN(maxbytes, rngId->bufSize - rngId->pFromBuf);
        OM_RealMemCopy (&rngId->buf [rngId->pFromBuf], buffer, bytesgot);
        pRngTmp = rngId->pFromBuf + bytesgot;

        /* If pFromBuf is equal to bufSize, we've read the entire buffer,
         * and need to wrap now.  If bytesgot < maxbytes, copy some more chars
         * in now. */
        if (pRngTmp == rngId->bufSize)
        {
            bytes2 = OM_MIN(maxbytes - bytesgot, pToBuf);
            OM_RealMemCopy (rngId->buf, buffer + bytesgot, bytes2);
            bytesgot += bytes2;
        }
    }

    /*VOS_Splx(lLockLevel);*/

    return (bytesgot);
}


/*******************************************************************************
*
* OM_RingBufferPut - put bytes into a ring buffer
*
* This routine puts bytes from <buffer> into ring buffer <ringId>.  The
* specified number of bytes will be put into the ring, up to the number of
* bytes available in the ring.
*
* INTERNAL
* Always leaves at least one byte empty between pToBuf and pFromBuf, to
* eliminate ambiguities which could otherwise occur when the two pointers
* are equal.
*
* RETURNS:
* The number of bytes actually put into the ring buffer;
* it may be less than number requested, even zero,
* if there is insufficient room in the ring buffer at the time of the call.
*
* ERRNO: N/A.
*/
int OM_RingBufferPut( OM_RING_ID rngId, char *buffer, int nbytes )
{
    int bytesput;
    int pFromBuf;
    int bytes2;
    int pRngTmp;
    /*int lLockLevel;*/

    /*lLockLevel = VOS_SplIMP();*/

    pFromBuf = rngId->pFromBuf;

    if (pFromBuf > rngId->pToBuf)
    {
        /* pFromBuf is ahead of pToBuf.  We can fill up to two bytes
         * before it */
        bytesput = OM_MIN(nbytes, pFromBuf - rngId->pToBuf - 1);
        OM_RealMemCopy (buffer, &rngId->buf [rngId->pToBuf], bytesput);
        rngId->pToBuf += bytesput;
    }
    else if (pFromBuf == 0)
    {
        /* pFromBuf is at the beginning of the buffer.  We can fill till
         * the next-to-last element */
        bytesput = OM_MIN(nbytes, rngId->bufSize - rngId->pToBuf - 1);
        OM_RealMemCopy (buffer, &rngId->buf [rngId->pToBuf], bytesput);
        rngId->pToBuf += bytesput;
    }
    else
    {
        /* pFromBuf has wrapped around, and its not 0, so we can fill
         * at least to the end of the ring buffer.  Do so, then see if
         * we need to wrap and put more at the beginning of the buffer. */
        bytesput = OM_MIN(nbytes, rngId->bufSize - rngId->pToBuf);
        OM_RealMemCopy (buffer, &rngId->buf [rngId->pToBuf], bytesput);
        pRngTmp = rngId->pToBuf + bytesput;

        if (pRngTmp == rngId->bufSize)
        {
            /* We need to wrap, and perhaps put some more chars */
            bytes2 = OM_MIN(nbytes - bytesput, pFromBuf - 1);
            OM_RealMemCopy (buffer + bytesput, rngId->buf, bytes2);
            rngId->pToBuf = bytes2;
            bytesput += bytes2;
        }
        else
        {
            rngId->pToBuf = pRngTmp;
        }
    }

    /*VOS_Splx(lLockLevel);*/

    return (bytesput);
}

/*******************************************************************************
*
* OM_RingBufferIsEmpty - test if a ring buffer is empty
*
* This routine determines if a specified ring buffer is empty.
*
* RETURNS:
* TRUE if empty, FALSE if not.
*
* ERRNO: N/A.
*/
VOS_BOOL OM_RingBufferIsEmpty( OM_RING_ID ringId )
{
    return (ringId->pToBuf == ringId->pFromBuf);
}

/*******************************************************************************
*
* OM_RingBufferIsFull - test if a ring buffer is full (no more room)
*
* This routine determines if a specified ring buffer is completely full.
*
* RETURNS:
* TRUE if full, FALSE if not.
*
* ERRNO: N/A.
*/
VOS_BOOL OM_RingBufferIsFull( OM_RING_ID ringId )
{
    int n = ringId->pToBuf - ringId->pFromBuf + 1;

    return ((n == 0) || (n == ringId->bufSize)); /* [false alarm]: 屏蔽Fortify 错误 */
}

/*******************************************************************************
*
* OM_RingBufferFreeBytes - determine the number of free bytes in a ring buffer
*
* This routine determines the number of bytes currently unused in a specified
* ring buffer.
*
* RETURNS: The number of unused bytes in the ring buffer.
*
* ERRNO: N/A.
*/
int OM_RingBufferFreeBytes( OM_RING_ID ringId)
{
    int n = ringId->pFromBuf - ringId->pToBuf - 1;

    if (n < 0)
    {
        n += ringId->bufSize;
    }

    return (n);
}

/*******************************************************************************
*
* OM_RingBufferNBytes - determine the number of bytes in a ring buffer
*
* This routine determines the number of bytes currently in a specified
* ring buffer.
*
* RETURNS: The number of bytes filled in the ring buffer.
*
* ERRNO: N/A.
*/
int OM_RingBufferNBytes( OM_RING_ID ringId )
{
    int n = ringId->pToBuf - ringId->pFromBuf;

    if (n < 0)
    {
        n += ringId->bufSize;
    }

    return (n);
}



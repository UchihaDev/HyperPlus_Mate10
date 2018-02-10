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

#ifndef __TAF_COMMON_H__
#define __TAF_COMMON_H__


/******************************************************************************/
#include "vos.h"
#include "PsTypeDef.h"
#include "PsCommonDef.h"
#include "v_id.h"
#include "product_config.h"
#include "TafApi.h"
#include "mdrv.h"
#include "errorlog.h"


/******************************************************************************/

/******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*========================================================*/

/* 标志无语音业务的编译开关，问题单A32D12736 */
#define  TAF_FEATURE_NO_VOICE_SERVICE
/*TAFM上报结构中option位段字节总个数，
子模块可以从结构起始地址memset TAF_EVT_OP_LEN个字节达到赋初值目的*/
#define   TAF_EVT_OP_LEN   4

/*----------TAFM公共接口----------*/
/*TAF各模块ID*/
#ifndef SUBMOD_NULL
#define  SUBMOD_NULL 0
#endif
#define  TAF_CCA     1
#define  TAF_APS     2
#define  TAF_SMA     3
#define  TAF_SSA     4
#define  TAF_MMA     5
#define   TAF_ALL_SUBMODULE   0xFF    /*所有子模块*/

/*临时，V200要删除*/
#define   TAF_TAFM             0
#define   TAF_SPEECH           1
#define   TAF_STATUS           2
#define   TAF_MAX_SPEECH_TI    14


/*打印级别，重新映射到OM定义的宏*/
#define    INFO_PRINT      PS_LOG_LEVEL_INFO
#define    NORMAL_PRINT    PS_LOG_LEVEL_NORMAL
#define    WARNING_PRINT   PS_LOG_LEVEL_WARNING
#define    ERROR_PRINT     PS_LOG_LEVEL_ERROR



#define TAF_PRINT(  Module,  PrintLevel,  Str)     \
           TAF_LOG(Module, 0, PrintLevel, Str)

#define TAFM_PRINT(Str)     \
           TAF_LOG(TAF_TAFM, 0, ERROR_PRINT, Str)

#define TAFM_PRINT1(Str, Para1)     \
           TAF_LOG1(TAF_TAFM, 0, ERROR_PRINT, Str, Para1)

#define TAFM_PRINT2(Str, Para1, Para2)    \
           TAF_LOG2(TAF_TAFM, 0, ERROR_PRINT, Str, Para1, Para2)





/*其他接口*/
/*参数设置结果上报*/
VOS_VOID Taf_ParaSetResult( VOS_UINT16           ClientId,
                        VOS_UINT8                  OpId,
                        TAF_PARA_SET_RESULT     Result,
                            TAF_PARA_TYPE     QueryPara,
                        VOS_VOID                    *pPara );


/*******************************************************************************/

#define SMA_INFO_LOG(String)            TAF_LOG(WUEPS_PID_TAF,  TAF_SMA, PS_LOG_LEVEL_INFO,    String)
#define SMA_NORM_LOG(String)            TAF_LOG(WUEPS_PID_TAF,  TAF_SMA, PS_LOG_LEVEL_NORMAL,  String)
#define SMA_WARN_LOG(String)            TAF_LOG(WUEPS_PID_TAF,  TAF_SMA, PS_LOG_LEVEL_WARNING, String)
#define SMA_ERR_LOG(String)             TAF_LOG(WUEPS_PID_TAF,  TAF_SMA, PS_LOG_LEVEL_ERROR,   String)
#define SMA_LOG1(String, Para1)         TAF_LOG1(WUEPS_PID_TAF, TAF_SMA, PS_LOG_LEVEL_INFO,    String, Para1)
#define SMA_LOG2(String, Para1, Para2)  TAF_LOG2(WUEPS_PID_TAF, TAF_SMA, PS_LOG_LEVEL_NORMAL,  String, Para1, Para2)

/*不退出当前函数的消息创建宏定义*/
#define PS_ALLOC_MSG_UNRTN(pMsg, ulPid , ulLen) \
    if(VOS_NULL_PTR == (pMsg = (VOS_VOID *)PS_ALLOC_MSG((ulPid),(ulLen) - VOS_MSG_HEAD_LENGTH))) \
    {\
        TAF_LOG1((ulPid), PS_SUBMOD_NULL, PS_LOG_LEVEL_ERROR," VOS_AllocMsg ERR! len:",(VOS_INT32)(ulLen));\
    }

/*不退出当前函数，未定义消息结构,申请消息内存,申请的内存长度不带消息报头长度*/
#define PS_ALLOC_MSG_UNRTN_WITHOUT_HEADER_LEN(pMsg, ulPid , ulLen) \
    if(VOS_NULL_PTR == (pMsg = (VOS_VOID *)PS_ALLOC_MSG((ulPid),(ulLen)))) \
    {\
        TAF_LOG1((ulPid), PS_SUBMOD_NULL, PS_LOG_LEVEL_ERROR," VOS_AllocMsg ERR! len:",(VOS_INT32)(ulLen));\
    }

/*消息释放宏定义*/
#define PS_FREEMSG(ulPID,pMsg)\
        VOS_FreeMsg((ulPID), (pMsg));

/*有返回值内存申请宏定义*/

#define TAF_COMM_BUILD_USIM_GET_FILE_INFO(pstGetfileInfo, enAppTypePara, usEfIdPara, ucRecordNumPara) \
{ \
    (pstGetfileInfo)->usEfId       = usEfIdPara; \
    (pstGetfileInfo)->ucRecordNum  = ucRecordNumPara; \
    (pstGetfileInfo)->enAppType    = enAppTypePara; \
    (pstGetfileInfo)->ucRsv        = 0; \
}

#define TAF_COMM_BUILD_USIM_SET_FILE_INFO(pstSetfileInfo, enAppTypePara, usEfIdPara, ucRecordNumPara, ulEfLenPara, pucEfPara) \
{ \
    (pstSetfileInfo)->usEfId       = usEfIdPara; \
    (pstSetfileInfo)->ucRecordNum  = ucRecordNumPara; \
    (pstSetfileInfo)->enAppType    = enAppTypePara; \
    (pstSetfileInfo)->ucRsv        = 0; \
    (pstSetfileInfo)->ulEfLen      = ulEfLenPara; \
    (pstSetfileInfo)->pucEfContent = pucEfPara; \
}

/*========================================================*/
#ifdef __cplusplus
}
#endif
/******************************************************************************/

/*============================================================================*/
#endif          /* __TAF_COMMON_H__ */


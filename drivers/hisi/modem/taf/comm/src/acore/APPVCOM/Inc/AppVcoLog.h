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
#ifndef __APPVCOM_LOG_H__
#define __APPVCOM_LOG_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"

#include "PsCommonDef.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
/*================================================*/
/* 数值宏定义 */
/*================================================*/
/* Deleted by wx270776 for OM融合, 2015-7-16, begin */
/* Deleted by wx270776 for OM融合, 2015-7-16, end */

/*================================================*/
/* 功能函数宏定义 */
/*================================================*/
#ifndef SUBMOD_NULL
#define    SUBMOD_NULL                                                  (0)
#endif

#define APPVCOM_LOG(String)\
    {\
        Print( (String) );\
        Print("\n");\
    }

#define APPVCOM_LOG1(String, Para1)\
    {\
        Print ( (String) );\
        Print1( ",%d\n",(VOS_INT32)(Para1));\
    }

#define APPVCOM_LOG2(String, Para1, Para2)\
    {\
        Print ( (String) );\
        Print2( ",%d,%d\n",(VOS_INT32)(Para1), (VOS_INT32)(Para2));\
    }

#define APPVCOM_LOG3(String, Para1, Para2, Para3)\
    {\
        Print ( (String) );\
        Print3 ( ",%d,%d,%d\n", (VOS_INT32)(Para1), (VOS_INT32)(Para2), (VOS_INT32)(Para3) );\
    }

#define APPVCOM_LOG4(String, Para1, Para2, Para3, Para4)\
    {\
        Print ( (String) );\
        Print4 ( ",%d,%d,%d,%d\n", (VOS_INT32)(Para1), (VOS_INT32)(Para2), (VOS_INT32)(Para3), (VOS_INT32)(Para4) );\
    }


#define    APPVCOM_INFO_LOG(Mod, String)                                    APPVCOM_LOG( (String) )
#define    APPVCOM_INFO_LOG1(Mod, String,Para1)                             APPVCOM_LOG1 ( (String), (VOS_INT32)(Para1) )
#define    APPVCOM_INFO_LOG2(Mod, String,Para1,Para2)                       APPVCOM_LOG2 ( (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2) )
#define    APPVCOM_INFO_LOG3(Mod, String,Para1,Para2,Para3)                 APPVCOM_LOG3 ( (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2), (VOS_INT32)(Para3) )
#define    APPVCOM_INFO_LOG4(Mod, String,Para1,Para2,Para3,Para4)           APPVCOM_LOG4 ( (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2), (VOS_INT32)(Para3), (VOS_INT32)(Para4) )

#define    APPVCOM_NORMAL_LOG(Mod, String)                                  APPVCOM_LOG ( (String) )
#define    APPVCOM_NORMAL_LOG1(Mod, String,Para1)                           APPVCOM_LOG1 ( (String), (VOS_INT32)(Para1) )
#define    APPVCOM_NORMAL_LOG2(Mod, String,Para1,Para2)                     APPVCOM_LOG2 ( (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2) )
#define    APPVCOM_NORMAL_LOG3(Mod, String,Para1,Para2,Para3)               APPVCOM_LOG3 ( (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2), (VOS_INT32)(Para3) )
#define    APPVCOM_NORMAL_LOG4(Mod, String,Para1,Para2,Para3,Para4)         APPVCOM_LOG4 ( (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2), (VOS_INT32)(Para3), (VOS_INT32)(Para4) )

#define    APPVCOM_WARNING_LOG(Mod, String)                                 APPVCOM_LOG ( (String) )
#define    APPVCOM_WARNING_LOG1(Mod, String,Para1)                          APPVCOM_LOG1 ( (String), (VOS_INT32)(Para1) )
#define    APPVCOM_WARNING_LOG2(Mod, String,Para1,Para2)                    APPVCOM_LOG2 ( (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2) )
#define    APPVCOM_WARNING_LOG3(Mod, String,Para1,Para2,Para3)              APPVCOM_LOG3 ( (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2), (VOS_INT32)(Para3) )
#define    APPVCOM_WARNING_LOG4(Mod, String,Para1,Para2,Para3,Para4)        APPVCOM_LOG4 ( (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2), (VOS_INT32)(Para3), (VOS_INT32)(Para4) )

#define    APPVCOM_ERROR_LOG(Mod, String)                                   APPVCOM_LOG ( (String) )
#define    APPVCOM_ERROR_LOG1(Mod, String,Para1)                            APPVCOM_LOG1 ( (String), (VOS_INT32)(Para1) )
#define    APPVCOM_ERROR_LOG2(Mod, String,Para1,Para2)                      APPVCOM_LOG2 ( (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2) )
#define    APPVCOM_ERROR_LOG3(Mod, String,Para1,Para2,Para3)                APPVCOM_LOG3 ( (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2), (VOS_INT32)(Para3) )
#define    APPVCOM_ERROR_LOG4(Mod, String,Para1,Para2,Para3,Para4)          APPVCOM_LOG4 ( (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2), (VOS_INT32)(Para3), (VOS_INT32)(Para4) )


/*******************************************************************************
  3 枚举定义
*******************************************************************************/

/*****************************************************************************
  4 全局变量声明
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
  8 UNION定义
*****************************************************************************/

/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/

/*****************************************************************************
  10 函数声明
*****************************************************************************/


#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* AdsLog.h */





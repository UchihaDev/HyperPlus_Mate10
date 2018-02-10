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

#ifndef __HDLC_HRADWARE_MNTN_H__
#define __HDLC_HRADWARE_MNTN_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
/* HDLC统计信息地址 */
#define PPP_HDLC_HARD_DATA_PROC_STAT    (&g_PppHdlcHardStat)

/* 定义异常信息bit位置:
        bit0代表是否进入异常处理(1是进入异常处理，0是没有进入异常处理);
        bit1代表是否是中断处理(1是中断处理，0是轮询处理);
        bit2代表是否等待信号量超时(1是，0否);
        bit3代表是否轮询超时(1是，0否); */
#define     HDLC_EXCEPTION_IND_BITPOS                           (0UL)
#define     HDLC_INTERRUPT_IND_BITPOS                           (1UL)
#define     HDLC_SEM_TIMEOUT_IND_BITPOS                         (2UL)
#define     HDLC_WAIT_STATUS_TIMEOUT_IND_BITPOS                 (3UL)

/* HDLC Warning Log信息 */
#define PPP_HDLC_WARNING_LOG(String)\
                DIAG_LogReport(DIAG_GEN_LOG_MODULE(VOS_GetModemIDFromPid(PS_PID_PPP_HDLC), DIAG_MODE_COMM, LOG_LEVEL_WARNING), (PS_PID_PPP_HDLC), __FILE__, __LINE__, "%s \r\n", String)

#define PPP_HDLC_WARNING_LOG1(String, Para1)\
                DIAG_LogReport(DIAG_GEN_LOG_MODULE(VOS_GetModemIDFromPid(PS_PID_PPP_HDLC), DIAG_MODE_COMM, LOG_LEVEL_WARNING), (PS_PID_PPP_HDLC), __FILE__, __LINE__, "%s, %d \r\n", String, Para1)

#define PPP_HDLC_WARNING_LOG2(String, Para1, Para2)\
                DIAG_LogReport(DIAG_GEN_LOG_MODULE(VOS_GetModemIDFromPid(PS_PID_PPP_HDLC), DIAG_MODE_COMM, LOG_LEVEL_WARNING), (PS_PID_PPP_HDLC), __FILE__, __LINE__, "%s, %d, %d \r\n", String, Para1, Para2)

#define PPP_HDLC_WARNING_LOG3(String, Para1, Para2, Para3)\
                DIAG_LogReport(DIAG_GEN_LOG_MODULE(VOS_GetModemIDFromPid(PS_PID_PPP_HDLC), DIAG_MODE_COMM, LOG_LEVEL_WARNING), (PS_PID_PPP_HDLC), __FILE__, __LINE__, "%s, %d, %d, %d \r\n", String, Para1, Para2, Para3)

#define PPP_HDLC_WARNING_LOG4(String, Para1, Para2, Para3, Para4)\
                DIAG_LogReport(DIAG_GEN_LOG_MODULE(VOS_GetModemIDFromPid(PS_PID_PPP_HDLC), DIAG_MODE_COMM, LOG_LEVEL_WARNING), (PS_PID_PPP_HDLC), __FILE__, __LINE__, "%s, %d, %d, %d, %d \r\n", String, Para1, Para2, Para3, Para4)


#define PPP_HDLC_ERROR_LOG(String)\
                DIAG_LogReport(DIAG_GEN_LOG_MODULE(VOS_GetModemIDFromPid(PS_PID_PPP_HDLC), DIAG_MODE_COMM, LOG_LEVEL_ERROR), (PS_PID_PPP_HDLC), __FILE__, __LINE__, "%s \r\n", String)

#define PPP_HDLC_ERROR_LOG1(String, Para1)\
                DIAG_LogReport(DIAG_GEN_LOG_MODULE(VOS_GetModemIDFromPid(PS_PID_PPP_HDLC), DIAG_MODE_COMM, LOG_LEVEL_ERROR), (PS_PID_PPP_HDLC), __FILE__, __LINE__, "%s, %d \r\n", String, Para1)

#define PPP_HDLC_ERROR_LOG2(String, Para1, Para2)\
                DIAG_LogReport(DIAG_GEN_LOG_MODULE(VOS_GetModemIDFromPid(PS_PID_PPP_HDLC), DIAG_MODE_COMM, LOG_LEVEL_ERROR), (PS_PID_PPP_HDLC), __FILE__, __LINE__, "%s, %d, %d \r\n", String, Para1, Para2)

#define PPP_HDLC_ERROR_LOG3(String, Para1, Para2, Para3)\
                DIAG_LogReport(DIAG_GEN_LOG_MODULE(VOS_GetModemIDFromPid(PS_PID_PPP_HDLC), DIAG_MODE_COMM, LOG_LEVEL_ERROR), (PS_PID_PPP_HDLC), __FILE__, __LINE__, "%s, %d, %d, %d \r\n", String, Para1, Para2, Para3)

#define PPP_HDLC_ERROR_LOG4(String, Para1, Para2, Para3, Para4)\
                DIAG_LogReport(DIAG_GEN_LOG_MODULE(VOS_GetModemIDFromPid(PS_PID_PPP_HDLC), DIAG_MODE_COMM, LOG_LEVEL_ERROR), (PS_PID_PPP_HDLC), __FILE__, __LINE__, "%s, %d, %d, %d, %d \r\n", String, Para1, Para2, Para3, Para4)

/* HDLC维测配置信息
        bit0置1表示需要勾取参数信息
        bit1置1表示需要勾取寄存器信息
        bit2置1表示需要勾取数据报文信息 */
#define     PPP_HDLC_MNTN_TRACE_PARA                            (1)
#define     PPP_HDLC_MNTN_TRACE_REG                             (2)
#define     PPP_HDLC_MNTN_TRACE_DATA                            (4)

/* 可维可测申请的内存最大长度，防止因为可维可测申请不到内存导致单板复位 */
#define     HDLC_MNTN_ALLOC_MEM_MAX_SIZE                        (2*1024)

/*****************************************************************************
  3 枚举定义
*****************************************************************************/

enum HDLC_MNTN_EVENT_TYPE_ENUM
{
    ID_HDLC_MNTN_FRM_REG_BEFORE_EN     = 101,     /* _H2ASN_MsgChoice HDLC_MNTN_FRM_REG_CONFIG_STRU */
    ID_HDLC_MNTN_FRM_REG_AFTER_EN,                /* _H2ASN_MsgChoice HDLC_MNTN_FRM_REG_CONFIG_STRU */
    ID_HDLC_MNTN_FRM_INPUT_PARA,                  /* _H2ASN_MsgChoice HDLC_MNTN_INPUT_PARA_LINK_STRU */
    ID_HDLC_MNTN_FRM_OUTPUT_PARA,                 /* _H2ASN_MsgChoice HDLC_MNTN_FRM_OUTPUT_PARA_STRU */
    ID_HDLC_MNTN_FRM_INPUT_DATA,                  /* _H2ASN_MsgChoice HDLC_MNTN_NODE_DATA_STRU */
    ID_HDLC_MNTN_FRM_OUTPUT_DATA,                 /* _H2ASN_MsgChoice HDLC_MNTN_NODE_DATA_STRU */
    ID_HDLC_MNTN_DEF_REG_BEFORE_EN,               /* _H2ASN_MsgChoice HDLC_MNTN_DEF_REG_CONFIG_STRU */
    ID_HDLC_MNTN_DEF_REG_AFTER_EN,                /* _H2ASN_MsgChoice HDLC_MNTN_DEF_REG_CONFIG_STRU */
    ID_HDLC_MNTN_DEF_INPUT_PARA,                  /* _H2ASN_MsgChoice HDLC_MNTN_INPUT_PARA_LINK_STRU */
    ID_HDLC_MNTN_DEF_OUTPUT_PARA,                 /* _H2ASN_MsgChoice HDLC_MNTN_DEF_OUTPUT_PARA_STRU */
    ID_HDLC_MNTN_DEF_INPUT_DATA,                  /* _H2ASN_MsgChoice HDLC_MNTN_NODE_DATA_STRU */
    ID_HDLC_MNTN_DEF_OUTPUT_DATA,                 /* _H2ASN_MsgChoice HDLC_MNTN_NODE_DATA_STRU */
    ID_HDLC_MNTN_DEF_UNCOMPLETED_INFO,            /* _H2ASN_MsgChoice HDLC_MNTN_DEF_UNCOMPLETED_INFO_STRU */

    ID_HDLC_MNTN_EVENT_TYPE_BUTT         = 0xFFFF
};
typedef VOS_UINT32 HDLC_MNTN_EVENT_TYPE_ENUM_UINT32;

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

/* 统计信息 */
typedef struct
{
    VOS_UINT32                  ulDefIpDataProcCnt;             /* 解封装IP数据包处理个数 */
    VOS_UINT32                  ulDefPppDataProcCnt;            /* 解封装简单PPP帧处理个数 */
    VOS_UINT32                  ulDefUncompleteCnt;             /* 解封装有非完整帧输出次数 */
    VOS_UINT32                  ulDefWaitIntCnt;                /* 解封装等待中断次数 */
    VOS_UINT32                  ulDefWaitQueryCnt;              /* 解封装等待轮询次数 */
    VOS_UINT32                  ulDefLcpPauseCnt;               /* 解封装LCP暂停次数 */
    VOS_UINT32                  ulDefFullPauseCnt;              /* 解封装输出空间或上报空间满暂停次数 */
    VOS_UINT32                  ulDefInputDiscardCnt;           /* 解封装丢弃数据包个数 */

    VOS_UINT32                  ulFrmIpDataProcCnt;             /* 封装IP数据包处理个数 */
    VOS_UINT32                  ulFrmPppDataProcCnt;            /* 封装简单PPP帧处理个数 */
    VOS_UINT32                  ulFrmWaitIntCnt;                /* 封装等待中断次数 */
    VOS_UINT32                  ulFrmWaitQueryCnt;              /* 封装等待轮询次数 */
    VOS_UINT32                  ulFrmAllocOutputMemFailCnt;     /* 封装申请目的内存失败次数 */
    VOS_UINT32                  ulFrmAllocFirstMemFailCnt;      /* 封装申请第一个节点目的内存失败次数 */
    VOS_UINT32                  ulFrmOutputLinkFullCnt;         /* 封装输出链表满次数 */
    VOS_UINT32                  ulFrmInputDiscardCnt;           /* 封装丢弃数据包个数 */

    VOS_UINT32                  ulDefMaxInputCntOnce;           /* 解封装一次最大输入数据个数 */
    VOS_UINT32                  ulDefMaxInputSizeOnce;          /* 解封装一次最大输入数据总长度 */
    VOS_UINT32                  ulDefMaxValidCntOnce;           /* 解封装一次最大输出有效帧个数 */
    VOS_UINT32                  ulDefMaxQueryCnt;               /* 解封装轮询最大次数 */

    VOS_UINT32                  ulFrmMaxInputCntOnce;           /* 封装一次最大输入数据个数 */
    VOS_UINT32                  ulFrmMaxInputSizeOnce;          /* 封装一次最大输入数据总长度 */
    VOS_UINT32                  ulFrmMaxOutputCntOnce;          /* 封装一次最大输出使用节点数个数 */
    VOS_UINT32                  ulFrmMaxOutputSizeOnce;         /* 封装一次最大输出使用节点总长度 */
    VOS_UINT32                  ulFrmMaxQueryCnt;               /* 封装轮询最大次数 */

    VOS_UINT32                  ulMaxCntOnce;                   /* PPP一次最多处理的结点个数 */
    VOS_UINT32                  ulHdlcHardProcCnt;              /* PPP一次最多处理的结点个数 */

    VOS_UINT32                  ulDefIsrCnt;                    /* 解封装中断服务程序调用次数 */
    VOS_UINT32                  ulFrmIsrCnt;                    /* 封装中断服务程序调用次数 */
    VOS_UINT32                  ulContinueCnt;                  /* 队列中的数据需要分多次处理的次数 */
    VOS_UINT16                  usDefExpInfo;                   /* 解封装异常信息 */
    VOS_UINT16                  usFrmExpInfo;                   /* 封装异常信息 */
    VOS_UINT32                  ulForbidHdlcBugNoCpy;           /* 规避HDLC BUG,不拷贝数据 */
    VOS_UINT32                  ulForbidHdlcBugCpy;             /* 规避HDLC BUG,需要拷贝数据 */
} PPP_HDLC_HARD_DATA_PROC_STAT_ST;

/* 输入参数链表可维可测结构 */
typedef struct
{
    VOS_MSG_HEADER                                              /* 消息头 */
    HDLC_MNTN_EVENT_TYPE_ENUM_UINT32    ulMsgname;
}HDLC_MNTN_TRACE_HEAD_STRU;


/* 输出和输出数据内容勾包*/
typedef struct
{
    HDLC_MNTN_TRACE_HEAD_STRU           stHead;                         /* _H2ASN_Skip */
    VOS_UINT16                          usNodeIndex;
    VOS_UINT16                          usLen;
    /* VOS_UINT8[usLen]数据内容放在这里，申请的时候由头加上数据内容长度 */
}HDLC_MNTN_NODE_DATA_STRU;


/* HDLC关键寄存器可维可测信息保存结构 */
typedef struct
{
    VOS_UINT32                          ulHdlcFrmRawInt;        /* 封装原始中断寄存器值 */
    VOS_UINT32                          ulHdlcFrmStatus;        /* 封装状态寄存器值 */
    VOS_UINT32                          ulHdlcDefRawInt;        /* 解封装原始中断寄存器值 */
    VOS_UINT32                          ulHdlcDefStatus;        /* 解封装状态寄存器值 */
}HDLC_REG_SAVE_INFO_STRU;


/*****************************************************************************
  8 UNION定义
*****************************************************************************/



/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/

/* 统计信息 */
extern PPP_HDLC_HARD_DATA_PROC_STAT_ST g_PppHdlcHardStat;

/* 保留清原始中断时的RAW_INT和STATUS值 */
extern HDLC_REG_SAVE_INFO_STRU         g_stHdlcRegSaveInfo;


extern VOS_BOOL PPP_HDLC_HARD_MntnGetConfig(VOS_UINT32 ulMod);
extern VOS_VOID PPP_HDLC_HARD_MntnTraceMsg
(
    HDLC_MNTN_TRACE_HEAD_STRU          *pstHead,
    HDLC_MNTN_EVENT_TYPE_ENUM_UINT32    ulMsgname,
    VOS_UINT32                          ulDataLen
);
extern VOS_VOID PPP_HDLC_HARD_MntnTraceSingleData
(
    VOS_UINT16                          usDataLen,
    VOS_UINT8                          *pucDataAddr,
    HDLC_MNTN_EVENT_TYPE_ENUM_UINT32    ulEventType,
    VOS_UINT32                          ulNodeIndex
);
VOS_UINT32 PPP_HDLC_HARD_MntnGetCurrentStatSum(VOS_VOID);


#pragma pack()


#ifdef __cplusplus
    #if __cplusplus
            }
    #endif
#endif


#endif



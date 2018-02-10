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

/************************************************************************
  Copyright   : 2013-2015, Huawei Tech. Co., Ltd.
  File name   : csimagent.h
  Author      : l00256032
  Version     : V900R001
  Date        : 2013-12-19
  Description : L+C共SIM卡项目头文件相关定义---
  History     :
   1.Date:2013-12-19
     Author: L47619
     Modification:create

************************************************************************/

#ifndef __CSIMAGENT_H__
#define __CSIMAGENT_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "UsimPsInterface.h"
#include "siapppih.h"
#include "usimmbase.h"
#include "siappstk.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
/* 与CBP对接的接口，不强制要求四字节对齐 */
#pragma pack(1)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
#define UIM_ERR_TIMEOUT                   (4)
#define STK_PROACTIVE_DATA_LEN            (256)
#define CSIMA_CBP_MSG_DATA_RSV            (4)
#define CSIMA_CARD_CHANEL_NULL            (0xFF)

/* CSIMA LOG宏 */
#define CSIMA_INFO_LOG(string)            PS_LOG(WUEPS_PID_CSIMA, 0, PS_PRINT_INFO,   string)
#define CSIMA_NORMAL_LOG(string)          PS_LOG(WUEPS_PID_CSIMA, 0, PS_PRINT_NORMAL, string)
#define CSIMA_WARNING_LOG(string)         PS_LOG(WUEPS_PID_CSIMA, 0, PS_PRINT_WARNING,string)
#define CSIMA_ERROR_LOG(string)           PS_LOG(WUEPS_PID_CSIMA, 0, PS_PRINT_ERROR,  string)

#define CSIMA_INFO1_LOG(string, para1)    PS_LOG1(WUEPS_PID_CSIMA, 0, PS_PRINT_INFO,   string, para1)
#define CSIMA_NORMAL1_LOG(string, para1)  PS_LOG1(WUEPS_PID_CSIMA, 0, PS_PRINT_NORMAL, string, para1)
#define CSIMA_WARNING1_LOG(string, para1) PS_LOG1(WUEPS_PID_CSIMA, 0, PS_PRINT_WARNING,string, para1)
#define CSIMA_ERROR1_LOG(string, para1)   PS_LOG1(WUEPS_PID_CSIMA, 0, PS_PRINT_ERROR,  string, para1)

/*******************************************************************************
  3 枚举定义
*******************************************************************************/
/*****************************************************************************
 枚举名    :CSIMA_ICC_MODE_ENUM
 结构说明  :CSIMA 当前卡应用模式枚举定义
*****************************************************************************/
enum CSIMA_ICC_MODE_ENUM
{
    CSIMA_ICC_MODE                      = 0x00,
    CSIMA_UICC_MODE                     = 0x01,
    CSIMA_ICC_MODE_BUTT
};
typedef VOS_UINT32     CSIMA_ICC_MODE_ENUM_UINT32;

/*****************************************************************************
 枚举名    :CSIMA_CBP_CARD_TYPE_ENUM
 结构说明  :CSIMA与CBP间卡类型定义,实际填写时按BIT或
*****************************************************************************/
enum CSIMA_CBP_CARD_TYPE_ENUM
{
    CSIMA_CBP_CARD_NONE                 = 0x00,
    CSIMA_CBP_UIM_CARD                  = 0x01,
    CSIMA_CBP_SIM_CARD                  = 0x02,
    CSIMA_CBP_UICC_CARD                 = 0x04,
    CSIMA_CBP_CSIM_CARD                 = 0x10,
    CSIMA_CBP_USIM_CARD                 = 0x20,
    CSIMA_CBP_ISIM_CARD                 = 0x40,
    CSIMA_CBP_UNKNOWN_CARD              = 0x80,
    CSIMA_CBP_CARD_TYPE_BUTT
};
typedef VOS_UINT16     CSIMA_CBP_CARD_TYPE_ENUM_UINT16;

/*****************************************************************************
 枚举名    :CSIMA_CBP_UICC_MSGID_ENUM
 结构说明  :CSIMA与CBP交互UICC消息ID枚举
*****************************************************************************/
enum CSIMA_CBP_UICC_MSGID_ENUM
{
    CSIMA_CBP_UICC_CTPDU_MSG            = 0x00, /* 访问CSIM应用请求消息 */
    CSIMA_CBP_UICC_RTPDU_MSG            = 0x01, /* 访问CSIM应用回复消息 */
    CSIMA_CBP_UICC_RST_REQ_MSG          = 0x02, /* RESET请求 */
    CSIMA_CBP_UICC_STATUS_IND_MSG       = 0x03, /* 卡状态上报 */
    CSIMA_CBP_UICC_PROACTIVE_CMD_MSG    = 0x04, /* 主动命令上报 */
    CSIMA_CBP_UICC_TERMINALRESPONSE_MSG = 0x05, /* 主动命令执行结果 */
    CSIMA_CBP_UICC_RESACC_REQ_MSG       = 0x07, /* 受限访问USIM应用请求消息 */
    CSIMA_CBP_UICC_RESACC_RSP_MSG       = 0x08, /* 受限访问USIM应用回复消息 */
    CSIMA_CBP_UICC_HANDSHAKE_MSG        = 0xee, /* VIA与BALONG握手处理 */
    CSIMA_CBP_UICC_MSGID_BUTT
};
typedef VOS_UINT32     CSIMA_CBP_UICC_MSGID_ENUM_UINT32;

/*****************************************************************************
 枚举名    :CSIMA_CBP_CARD_STATUS_ENUM
 结构说明  :CSIMA给CBP上报的卡状态枚举
*****************************************************************************/
enum CSIMA_CBP_CARD_STATUS_ENUM
{
    CSIMA_CBP_CARD_NOT_READY            = 0x00, /* 初始化失败上报 */
    CSIMA_CBP_CARD_ERROR,                       /* 暂时不需要 */
    CSIMA_CBP_CARD_REPLACED,                    /* 暂时不需要 */
    CSIMA_CBP_CARD_READY,                       /* 初始化成功上报 */
    CSIMA_CBP_CARD_BOOTUP,                      /* 初始化未完成或等待PIN校验 */
    CSIMA_CBP_CARD_LINK_FAILURE,                /* 暂时不需要 */
    CSIMA_CBP_CARD_STATUS_BUTT
};
typedef VOS_UINT16     CSIMA_CBP_CARD_STATUS_ENUM_UINT16;

/*****************************************************************************
 枚举名    :CSIMA_ICC_MODE_ENUM
 结构说明  :CSIMA 当前卡应用模式枚举定义
*****************************************************************************/
enum CSIMA_EVENTLIST_RESEND_ENUM
{
    CSIMA_EVENTLIST_RESEND_INIT           = 0x00,
    CSIMA_EVENTLIST_NEED_RESEND           = 0x01,
    CSIMA_EVENTLIST_RESENT                = 0X02,
    CSIMA_EVENTLIST_BUTT
};
typedef VOS_UINT32     CSIMA_EVENTLIST_RESEND_ENUM_UINT32;

/*****************************************************************************
  4 结构体定义
*****************************************************************************/
/*****************************************************************************
 结构名    :CSIMA_CBP_MSG_STRU
 结构说明  :CSIMA与CBP交互消息结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                               ulIPCMsgId;                     /* 消息ID */
}CSIMA_CBP_MSG_STRU;

/*****************************************************************************
 结构名    :CSIMA_CBP_STATUS_IND_MSG_STRU
 结构说明  :CSIMA给CBP上报卡状态结构
*****************************************************************************/
typedef struct
{
    CSIMA_CBP_UICC_MSGID_ENUM_UINT32        enIPCMsgId;                     /* 消息ID */
    CSIMA_CBP_CARD_STATUS_ENUM_UINT16       enStatus;                       /* 卡状态 */
    VOS_UINT16                              usCardType;                     /* 卡类型，多应用的情况，bit表示各个应用类型,这个字段在status ready时才认为有意义 */
    VOS_UINT8                               ucCSIMChanNum;                  /* CSIM通道号 */
    VOS_UINT8                               ucUSIMChanNum;                  /* USIM通道号 */
    VOS_UINT8                               ucISIMChanNum;                  /* ISIM通道号，不支持，填0xff */
    VOS_UINT8                               aucCSIMAID[USIMM_AID_LEN_MAX];  /* CSIM AID */
    VOS_UINT8                               aucUSIMAID[USIMM_AID_LEN_MAX];  /* USIM AID */
    VOS_UINT8                               aucISIMAID[USIMM_AID_LEN_MAX];  /* ISIM AID,不支持，填0xff */
    VOS_UINT32                              ulWWT;                          /* work waiting time,暂时不需要，填0 */
    VOS_UINT8                               ucATRLen;                       /* ATR长度，暂时不需要，填0 */
    VOS_UINT8                               aucATR[1];                      /* ATR数据，暂时不需要，填充一个字节0 */
}CSIMA_CBP_STATUS_IND_MSG_STRU;

/*****************************************************************************
 结构名    :CSIMA_CBP_CTPDU_MSG_STRU
 结构说明  :CBP访问CSIM应用请求数据结构
*****************************************************************************/
typedef struct
{
    CSIMA_CBP_UICC_MSGID_ENUM_UINT32        enIPCMsgId;                     /* 消息ID */
    VOS_UINT8                               aucCTPDUHdr[USIMM_APDU_HEADLEN];/* CTPDU头 */
    VOS_UINT8                               ucChanNum;                      /* 通道号 */
    VOS_UINT16                              usDataLen;                      /* 数据长度 */
    VOS_UINT8                               aucData[CSIMA_CBP_MSG_DATA_RSV];/* 数据 */
}CSIMA_CBP_CTPDU_MSG_STRU;

/*****************************************************************************
 结构名    :CSIMA_CBP_RTPDU_MSG_STRU
 结构说明  :CBP访问CSIM应用回复数据结构
*****************************************************************************/
typedef struct
{
    CSIMA_CBP_UICC_MSGID_ENUM_UINT32        enIPCMsgId;                     /* 消息ID */
    VOS_UINT16                              usSWStatus;                     /* SW1在低位，SW2在高位 */
    VOS_UINT16                              usDataLen;                      /* 数据长度 */
    VOS_UINT8                               aucData[CSIMA_CBP_MSG_DATA_RSV];/* 数据 */
}CSIMA_CBP_RTPDU_MSG_STRU;

/*****************************************************************************
 结构名    :CSIMA_CBP_PROACTIVE_CMD_MSG_STRU
 结构说明  :CSIMA给CBP发送的主动命令结构
*****************************************************************************/
typedef struct
{
    CSIMA_CBP_UICC_MSGID_ENUM_UINT32        enIPCMsgId;                     /* 消息ID */
    VOS_UINT16                              usDataLen;                      /* 数据长度 */
    VOS_UINT8                               aucData[STK_PROACTIVE_DATA_LEN];/* 数据 */
}CSIMA_CBP_PROACTIVE_CMD_MSG_STRU;

/*****************************************************************************
 结构名    :CSIMA_CBP_TERMINALRESPONSE_MSG_STRU
 结构说明  :CBP回复给CSIMA的主动命令执行结果数据结构
*****************************************************************************/
typedef struct
{
    CSIMA_CBP_UICC_MSGID_ENUM_UINT32        enIPCMsgId;                     /* 消息ID */
    VOS_UINT16                              usDataLen;                      /* 数据长度 */
    VOS_UINT8                               aucData[CSIMA_CBP_MSG_DATA_RSV];/* 数据 */
}CSIMA_CBP_TERMINALRESPONSE_MSG_STRU;

/*****************************************************************************
 结构名    :CSIMA_CBP_RESACC_REQ_MSG_STRU
 结构说明  :CBP访问USIM应用下文件请求数据结构
*****************************************************************************/
typedef struct
{
    CSIMA_CBP_UICC_MSGID_ENUM_UINT32        enIPCMsgId;                     /* 消息ID */
    VOS_UINT8                               ucChanNum;                      /* 通道号 */
    VOS_UINT8                               ucCmd;                          /* 命令类型 */
    VOS_UINT16                              usFileId;                       /* 文件ID，低位在前高位在后 */
    VOS_UINT8                               ucP1;                           /* P1参数 */
    VOS_UINT8                               ucP2;                           /* P2参数 */
    VOS_UINT8                               ucP3;                           /* P3参数 */
    VOS_UINT8                               ucLen;                          /* aucData域中数据长度，不包括路径长度 */
    VOS_UINT16                              usPathLen;                      /* 路径长度 */
    VOS_UINT8                               aucData[CSIMA_CBP_MSG_DATA_RSV];/* 数据+路径，路径中已包括文件ID */
}CSIMA_CBP_RESACC_REQ_MSG_STRU;

/*****************************************************************************
 结构名    :CSIMA_CBP_RESACC_RSP_MSG_STRU
 结构说明  :CBP访问USIM应用下文件回复数据结构
*****************************************************************************/
typedef struct
{
    CSIMA_CBP_UICC_MSGID_ENUM_UINT32        enIPCMsgId;                     /* 消息ID */
    VOS_UINT16                              usSWStatus;                     /* SW1在低位，SW2在高位 */
    VOS_UINT16                              usDataLen;                      /* 数据长度 */
    VOS_UINT8                               aucData[CSIMA_CBP_MSG_DATA_RSV];/* 数据 */
}CSIMA_CBP_RESACC_RSP_MSG_STRU;

/*****************************************************************************
 结构名    :CSIMA_STK_PROACTIVE_CMD_MSG_STRU
 结构说明  :STK与CSIMA交互主动命令的消息结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSIMA_CBP_UICC_MSGID_ENUM_UINT32        enIPCMsgId;                     /* 消息ID */
    VOS_UINT32                              ulLen;
    VOS_UINT8                               aucProactiveCmd[STK_PROACTIVE_DATA_LEN];
}CSIMA_STK_PROACTIVE_CMD_MSG_STRU;

/*****************************************************************************
 结构名    : CSIMA_CARDINFO_STRU
 结构说明  : CSIMA模块保存USIM卡信息数据结构
*****************************************************************************/
typedef struct
{
    USIMM_PHYCARD_TYPE_ENUM_UINT32      enPhyType;
}CSIMA_CARDINFO_STRU;


/*****************************************************************************
  4 函数声明
*****************************************************************************/

/*****************************************************************************
  5 全局变量声明
*****************************************************************************/


/*****************************************************************************
  6 OTHERS定义
*****************************************************************************/
#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of csimagent.h*/


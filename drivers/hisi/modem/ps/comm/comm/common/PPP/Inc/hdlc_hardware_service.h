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

#ifndef __HDLC_HRADWARE_SERVICE_H__
#define __HDLC_HRADWARE_SERVICE_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "hdlc_hardware_mntn.h"
#include "hdlc_hardware_conf.h"
#include "hdlc_hardware_driver.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/

/* ----------------HDLC优化新增内存 START---------------- */
/* HDLC Master设备使用内存基地址 */
/* 解封装单次配置最大输入参数节点个数,修改会影响HDLC_INPUT_PARA_LINK_MAX_SIZE的值 */
#define TTF_HDLC_DEF_INPUT_PARA_LINK_MAX_NUM        (20)

/* 解封装输入参数内存大小和基地址
   HDLC_DEF_INPUT_PARA_LINK_MAX_NUM * sizeof(HDLC_PARA_LINK_NODE_STRU) */
#define TTF_HDLC_DEF_INPUT_PARA_LINK_BUF_LEN        (TTF_HDLC_DEF_INPUT_PARA_LINK_MAX_NUM * 12)

/* 解封装单次配置最大输入数据总长度 */
#define TTF_HDLC_DEF_INPUT_PARA_LINK_MAX_SIZE       (13*1024)


/* 一次解封装输出IP包/简单PPP帧最大个数 = 一次解封装最大输入长度/最小IP包长度(20B) */
#define TTF_HDLC_DEF_OUTPUT_MAX_NUM                 (TTF_HDLC_DEF_INPUT_PARA_LINK_MAX_SIZE/20)

/* 解封装信息上报最大个数 */
#define TTF_HDLC_DEF_RPT_MAX_NUM                    (TTF_HDLC_DEF_OUTPUT_MAX_NUM)

/* 解封装信息上报空间内存大小和基地址
   一次解封装输出的最大IP包/简单PPP帧个数*sizeof(HDLC_FRM_RPT_NODE) */
#define TTF_HDLC_DEF_RPT_BUF_LEN                    (TTF_HDLC_DEF_RPT_MAX_NUM*8)

/* ((TTF_HDLC_DEF_INPUT_PARA_LINK_MAX_SIZE / 6 + 1) * 8)
 * 6为占用最大空间的最小有效帧
 * 8为四字节对齐
 * +1 为小数向上取整
*/

#define TTF_HDLC_DEF_OUTPUT_DATA_BUF_LEN            (18 * 1024)

    /* 供HDLC MASTER设备使用的内存总长度，当结构体HDLC_DEF_BUFF_INFO_STRU变化时，
        该宏应作相应变化 */
#define TTF_HDLC_MASTER_DEF_BUF_LEN                 (TTF_HDLC_DEF_INPUT_PARA_LINK_BUF_LEN + \
                                                        TTF_HDLC_DEF_RPT_BUF_LEN + \
                                                        TTF_HDLC_DEF_OUTPUT_DATA_BUF_LEN)

/* 封装单次配置最大输入参数节点个数，修改会影响HDLC_INPUT_PARA_LINK_MAX_SIZE的值 */
#define TTF_HDLC_FRM_INPUT_PARA_LINK_MAX_NUM        (20)

/* 封装单次配置最大输入数据总长度 */
#define TTF_HDLC_FRM_INPUT_PARA_LINK_MAX_SIZE       (15*1024)

/* 封装输入参数内存大小 = TTF_HDLC_FRM_INPUT_PARA_LINK_MAX_NUM * sizeof(HDLC_PARA_LINK_NODE_STRU) */
#define TTF_HDLC_FRM_INPUT_PARA_LINK_BUF_LEN        (TTF_HDLC_FRM_INPUT_PARA_LINK_MAX_NUM * 12)

/* 封装信息最大个数 */
#define TTF_HDLC_FRM_RPT_MAX_NUM                    (TTF_HDLC_FRM_INPUT_PARA_LINK_MAX_NUM)

/* 封装信息上报空间内存大小和基地址
   TTF_HDLC_FRM_RPT_MAX_NUM * sizeof(HDLC_DEF_RPT_NODE) */
#define TTF_HDLC_FRM_RPT_BUF_LEN                    (TTF_HDLC_FRM_RPT_MAX_NUM * 8)

/* 封装单次配置最大输出参数节点个数 */
#define TTF_HDLC_FRM_OUTPUT_PARA_LINK_MAX_NUM       (TTF_HDLC_FRM_INPUT_PARA_LINK_MAX_NUM * 2)

/* 封装输出参数内存大小和基地址
   TTF_HDLC_FRM_OUTPUT_PARA_LINK_MAX_NUM * sizeof(HDLC_PARA_LINK_NODE_STRU) */
#define TTF_HDLC_FRM_OUTPUT_PARA_LINK_BUF_LEN       (TTF_HDLC_FRM_OUTPUT_PARA_LINK_MAX_NUM * 12)

/* 供HDLC MASTER设备使用的内存总长度，当结构体HDLC_FRM_BUFF_INFO_STRU变化时，
    该宏应作相应变化 */
#define TTF_HDLC_MASTER_FRM_BUF_LEN                 (TTF_HDLC_FRM_INPUT_PARA_LINK_BUF_LEN + \
                                                        TTF_HDLC_FRM_RPT_BUF_LEN + \
                                                        TTF_HDLC_FRM_OUTPUT_PARA_LINK_BUF_LEN)

/* 供HDLC MASTER设备使用的内存总长度 */
#define TTF_HDLC_MASTER_LINK_TOTAL_LEN              (TTF_GET_32BYTE_ALIGN_VALUE((TTF_HDLC_MASTER_DEF_BUF_LEN + \
                                                        TTF_HDLC_MASTER_FRM_BUF_LEN)))

/* ----------------HDLC优化新增内存 END---------------- */

/* 由于解封装可能出现绕回现象，因此一帧数据可能会被分成2段 */
#define PPP_SERVICE_HDLC_HARD_DEF_MAX_DATA_CNT      (2)


/* LCP协议 */
#define PPP_SERVICE_HDLC_HARD_LCP                   (0xc021)

/* 根据PPP ID获取对应内存，暂时只有一路，填为定值，后续可能有多路 */
#define HDLC_DEF_GET_UNCOMPLETED_INFO(usPppId)      (&l_stUncompletedInfo)
#define HDLC_DEF_GET_BUF_INFO(usPppId)              (l_pstHdlcDefBufInfo)
#define HDLC_FRM_GET_BUF_INFO(usPppId)              (l_pstHdlcFrmBufInfo)


/* 检查结构体大小是否合法 */
#if (defined(LLT_TEST_CODE))
#define PPP_SERVICE_HDLC_HARD_STRU_SIZE_CHECK(_size, _stru) \
{ \
    char STRU_SIZE_CHECK_##_stru[((_size) == sizeof(_stru)) ? 1 : -1]; \
    (void)STRU_SIZE_CHECK_##_stru[0]; \
}
#else
#define PPP_SERVICE_HDLC_HARD_STRU_SIZE_CHECK(_size, _stru)
#endif

/* TTF_MAX(TTF_HDLC_DEF_INPUT_PARA_LINK_MAX_NUM, TTF_HDLC_FRM_INPUT_PARA_LINK_MAX_NUM) */
#define HDLC_INPUT_PARA_LINK_MAX_SIZE               (20)
#define HDLC_OUTPUT_PARA_LINK_MAX_SIZE              (TTF_HDLC_FRM_OUTPUT_PARA_LINK_MAX_NUM)


/* 解封装输出空间首、尾地址，用于判断是否绕回 */
#define HDLC_DEF_OUTPUT_BUF_START_ADDR              ((VOS_UINT8 *)(&l_pstHdlcDefBufInfo->aucOutputDataBuf[0]))
#define HDLC_DEF_OUTPUT_BUF_END_ADDR                (HDLC_DEF_OUTPUT_BUF_START_ADDR + TTF_HDLC_DEF_OUTPUT_DATA_BUF_LEN)

/* 约定软硬件, 封装一组最多提交1502字节给Framer */
#define HDLC_FRM_IN_PER_MAX_CNT                     (1502L)
#define HDLC_FRM_OUT_PER_MAX_CNT                    (3013UL)

/* 封装后内存最大值 */
#define HDLC_FRM_GET_MAX_FRAMED_LEN(usLen)          (2*usLen + 13)


/* 解封装上报每帧最长1502字节, IPv4最长1500字节, PPP模式带上协议字段2字节, 共1502字节 */
#define HDLC_DEF_OUT_PER_MAX_CNT                    (1502UL)


/* 申请封装目的空间失败定时器时长,单位毫秒 */
#define HDLC_FRM_TIME_INTERVAL                      (100)

/* 报文封装后长度最多变为原来的两倍，因此封装一个报文最多需要2块内存来存储封装结果 */
#define PPP_HDLC_MAX_OUT_NODE_FOR_ONE_INPUT         (2)

/* 解封装结果处理函数 */
#define PPP_SERVICE_HDLC_HARD_DEF_RES_PROC(pstRslt)        l_stHldcDefCallBackInfo.pDefResProcFunc(pstRslt)

/* 解封装错误信息处理函数 */
#define PPP_SERVICE_HDLC_HARD_DEF_ERR_PROC(usPppId, pstErrCnt)        l_stHldcDefCallBackInfo.pDefErrProcFunc(usPppId, pstErrCnt)

/*****************************************************************************
  3 枚举定义
*****************************************************************************/

/*****************************************************************************
 结构名    : PPP_SERVICE_HDLC_HARD_WORK_STATUS_ENUM
 协议表格  :
 ASN.1描述 :
 结构说明  : HDLC工作状态
*****************************************************************************/
enum PPP_SERVICE_HDLC_HARD_WORK_STATUS_ENUM
{
   PPP_SERVICE_HDLC_HARD_NOT_WORK   = 0,
   PPP_SERVICE_HDLC_HARD_FRM_WORK,
   PPP_SERVICE_HDLC_HARD_DEF_WORK,
   PPP_SERVICE_HDLC_HARD_BOTH_WORK,
   PPP_SERVICE_HDLC_HARD_WORK_STATUS_BUTT
};

typedef VOS_UINT8 PPP_SERVICE_HDLC_HARD_WORK_STATUS_ENUM_UINT8;

/*****************************************************************************
 结构名    : PPP_SERVICE_HDLC_HARD_MODE_ENUM
 协议表格  :
 ASN.1描述 :
 结构说明  : HDLC工作模式
*****************************************************************************/
enum PPP_SERVICE_HDLC_HARD_MODE_ENUM
{
    PPP_SERVICE_HDLC_HARD_IP_MODE    = 0,
    PPP_SERVICE_HDLC_HARD_PPP_MODE   = 1,
    PPP_SERVICE_HDLC_HARD_MODE_BUTT
};

typedef VOS_UINT8 PPP_SERVICE_HDLC_HARD_MODE_ENUM_UINT8;


/*****************************************************************************
 结构名    : PPP_HDLC_HARD_PROC_RESULT_ENUM
 协议表格  :
 ASN.1描述 :
 结构说明  : HDLC处理结果
*****************************************************************************/
enum PPP_HDLC_HARD_PROC_RESULT_ENUM
{
    PPP_HDLC_HARD_PROC_ALL_SUCC = 0,
    PPP_HDLC_HARD_PROC_PART_SUCC,
    PPP_HDLC_HARD_PROC_STATUS_ERR,
    PPP_HDLC_HARD_PROC_PARA_ERR,
    PPP_HDLC_HARD_PROC_FAIL,
    PPP_HDLC_HARD_PROC_RESULT_BUTT
};

typedef VOS_UINT32 PPP_HDLC_HARD_PROC_RESULT_ENUM_UINT32;


/*****************************************************************************
 结构名    : PPP_HDLC_PARA_CHECK_RESULT_ENUM
 协议表格  :
 ASN.1描述 :
 结构说明  : HDLC参数检查结果枚举
*****************************************************************************/
enum PPP_HDLC_PARA_CHECK_RESULT_ENUM
{
    PPP_HDLC_PARA_CHECK_PASS            = 0,      /* 参数符合要求，将该数据出队 */
    PPP_HDLC_PARA_CHECK_FAIL_DISCARD    = 1,      /* 数据包参数不符合要求，需要丢弃，但是继续处理下一个数据包 */
    PPP_HDLC_PARA_CHECK_FAIL_KEEP       = 2,      /* 数据包参数不符合要求，但需要保留，用于下次处理 */

    PPP_HDLC_PARA_CHECK_BUTT
};
typedef VOS_UINT32 PPP_HDLC_PARA_CHECK_RESULT_ENUM_UINT32;


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
 结构名    : HDLC_PARA_LINK_NODE_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 参数链表节点结构:
           软件保证解封装输入链表参数起始地址Word对齐；(参见HiHDLCV200逻辑需求规格说明书)，
           从上到下，地址增加，分别为节点内存指针、节点长度、下个节点地址；
           长度LEN有效16bits处于低Half_Word；地址ADDR 32bits
*****************************************************************************/
typedef struct _HDLC_PARA_LINK_NODE_STRU
{
    VOS_UINT8                          *pucDataAddr;            /* 该参数节点指向内存地址 */
    VOS_UINT16                          usDataLen;              /* 内存长度，单位Byte */
    VOS_UINT8                           aucReserve[2];
    struct _HDLC_PARA_LINK_NODE_STRU   *pstNextNode;            /* 指向下一个参数节点的指针 */
} HDLC_PARA_LINK_NODE_STRU;

/*****************************************************************************
 结构名    : HDLC_DEF_RPT_NODE_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 解封装上报空间结点结构:
            件保证解封装上报空间起始地址Word对齐；(参见HiHDLCV200逻辑需求规格说明书)，
            从上到下，地址增加，分别为输出数据协议类型、长度和存储地址；
            长度LEN有效16bits处于低Half_Word；协议PRO有效16bits处于高Half-Word；地址ADDR 32bits
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usDefOutOneLen;         /* 有效帧的长度 */
    VOS_UINT16                          usDefOutOnePro;         /* 有效帧的协议 */
    VOS_UINT8                          *pucDefOutOneAddr;       /* 指向解封装出的有效帧在外存储的起始地址 */
} HDLC_DEF_RPT_NODE_STRU;

/*****************************************************************************
 结构名    : HDLC_DEF_BUFF_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 保存解封装使用的内存
*****************************************************************************/
typedef struct
{
    HDLC_PARA_LINK_NODE_STRU            astInputParaLinkNodeBuf[TTF_HDLC_DEF_INPUT_PARA_LINK_MAX_NUM];/* 解封装输入参数链表使用的内存 */
    HDLC_DEF_RPT_NODE_STRU              astRptNodeBuf[TTF_HDLC_DEF_RPT_MAX_NUM];                      /* 解封装信息上报空间使用的内存 */
    VOS_UINT8                           aucOutputDataBuf[TTF_HDLC_DEF_OUTPUT_DATA_BUF_LEN];           /* 解封装目的空间使用的内存 */
} HDLC_DEF_BUFF_INFO_STRU;


/*****************************************************************************
 结构名    : HDLC_FRM_RPT_NODE_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 封装上报空间结点结构:
            软件保证封装上报空间起始地址Word对齐；(参见HiHDLCV200逻辑需求规格说明书)，
            从上到下，地址增加，分别为输出数据起始地址、数据长度；
            长度LEN有效16bits处于低Half_Word；地址ADDR 32bits
*****************************************************************************/
typedef struct
{
    VOS_UINT8                          *pucFrmOutOneAddr;       /* 指向封装出的有效帧的在外存储起始地址 */
    VOS_UINT16                          usFrmOutOneLen;         /* 有效帧的长度 */
    VOS_UINT8                           aucReserve[2];
} HDLC_FRM_RPT_NODE_STRU;

/*****************************************************************************
 结构名    : HDLC_FRM_BUFF_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 保存封装使用的内存
*****************************************************************************/
typedef struct
{
    HDLC_PARA_LINK_NODE_STRU            astInputParaLinkNodeBuf[TTF_HDLC_FRM_INPUT_PARA_LINK_MAX_NUM];  /* 封装输入参数链表使用的内存 */
    HDLC_FRM_RPT_NODE_STRU              astRptNodeBuf[TTF_HDLC_FRM_RPT_MAX_NUM];                        /* 封装信息上报空间使用的内存 */
    HDLC_PARA_LINK_NODE_STRU            astOutputParaLinkNodeBuf[TTF_HDLC_FRM_OUTPUT_PARA_LINK_MAX_NUM];/* 封装输出参数链表使用的内存 */
} HDLC_FRM_BUFF_INFO_STRU;

/*****************************************************************************
 结构名    : PPP_HDLC_HARD_NODE_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : HDLC封装及解封装节点内存参数
*****************************************************************************/
typedef struct
{
    VOS_UINT8                          *pucDataAddr;        /* 指向数据的内存地址 */
    VOS_UINT16                          usDataLen;          /* 数据长度 */
    VOS_UINT8                           aucReserve[2];
    VOS_VOID                           *pDataNode;          /* 此参数用于业务模块暂存输入输出节点信息，Service不使用此参数 */
}PPP_HDLC_HARD_NODE_PARA_STRU;

/*****************************************************************************
 结构名    : PPP_HDLC_HARD_FRM_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : HDLC封装参数
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usPppId;                /* PPP ID */
    VOS_UINT16                          usProtocol;             /* 协议类型 */
    PPP_HDLC_HARD_NODE_PARA_STRU        astInputNodePara[TTF_HDLC_FRM_INPUT_PARA_LINK_MAX_NUM];      /* 封装输入节点参数 */
    VOS_UINT32                          ulInputNodeParaCnt;     /* 封装输入节点参数个数 */
    VOS_UINT32                          ulInputTotalSize;       /* 解封装输入节点总大小 */
    PPP_HDLC_HARD_NODE_PARA_STRU        astOutputNodePara[TTF_HDLC_FRM_OUTPUT_PARA_LINK_MAX_NUM];    /* 封装输出节点参数 */
    VOS_UINT32                          ulOutputNodeParaCnt;    /* 封装输出节点参数个数 */
    VOS_UINT32                          ulPppAcFlag;            /* PPP的地址控制域压缩标识 */
    VOS_UINT32                          ulPppPcFlag;            /* PPP的协议域压缩标识 */
    VOS_UINT32                          ulAccmFlag;             /* PPP的同异步控制字标识 */
    PPP_SERVICE_HDLC_HARD_MODE_ENUM_UINT8       enPppMode;      /* PPP工作模式 */
    VOS_UINT8                           aucReserve[3];
} PPP_HDLC_HARD_FRM_PARA_STRU;

/*****************************************************************************
 结构名    : PPP_HDLC_HARD_FRM_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :  HDLC封装结果
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucFrmValidCnt;      /* 成功封装报文个数 */
    PPP_HDLC_HARD_NODE_PARA_STRU        astFrmResultNode[TTF_HDLC_FRM_RPT_MAX_NUM];
}PPP_HDLC_HARD_FRM_RESULT_STRU;

/*****************************************************************************
 结构名    : PPP_HDLC_HARD_DEF_DATA_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :  HDLC解封装数据信息
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usDataLen;        /* 解封装数据长度 */
    VOS_UINT16                          usReserve;
    VOS_UINT8                          *pucDataAddr;      /* 解封装数据地址 */
}PPP_HDLC_HARD_DEF_DATA_INFO_STRU;


/*****************************************************************************
 结构名    : PPP_HDLC_HARD_DEF_RESULT_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :  HDLC解封装结果
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usPppId;            /* PPP ID */
    VOS_UINT16                          usProtocol;         /* 协议类型 */
    PS_BOOL_ENUM_UINT8                  enSegment;          /* 数据是否被分段 */
    PPP_HDLC_HARD_DEF_DATA_INFO_STRU    astDataInfo[PPP_SERVICE_HDLC_HARD_DEF_MAX_DATA_CNT];     /* 由于解封装结果可能出现绕回，因此有可能一帧数据被分成两段 */
    VOS_UINT32                          ulPara;             /* 业务模块透传参数 */
}PPP_HDLC_HARD_DEF_RESULT_STRU;

/*****************************************************************************
 结构名    : PPP_SERVICE_HDLC_HARD_DEF_RES_PROC_FUNC
 协议表格  :
 ASN.1描述 :
 结构说明  :  业务模块处理HDLC解封装结果函数
*****************************************************************************/
typedef VOS_VOID (*PPP_SERVICE_HDLC_HARD_DEF_RES_PROC_FUNC)(PPP_HDLC_HARD_DEF_RESULT_STRU*);

/*****************************************************************************
 结构名    : PPP_SERVICE_HDLC_HARD_DEF_ERR_INFO_PROC_FUNC
 协议表格  :
 ASN.1描述 :
 结构说明  :  业务模块处理HDLC解封装错误信息函数
*****************************************************************************/
typedef VOS_VOID (*PPP_SERVICE_HDLC_HARD_DEF_ERR_INFO_PROC_FUNC)(VOS_UINT16 usPppId, PPP_DRIVER_HDLC_HARD_DEF_ERR_FRAMES_CNT_STRU *pstErrCnt);


/*****************************************************************************
 结构名    : PPP_SERVICE_HDLC_HARD_DEF_CALLBACK_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 业务模块解封装回调结构
*****************************************************************************/
typedef struct
{
    PPP_SERVICE_HDLC_HARD_DEF_RES_PROC_FUNC         pDefResProcFunc;        /* 解封装结果处理函数 */
    PPP_SERVICE_HDLC_HARD_DEF_ERR_INFO_PROC_FUNC    pDefErrProcFunc;        /* 解封装错误信息处理函数 */
}PPP_SERVICE_HDLC_HARD_DEF_CALLBACK_STRU;

/*****************************************************************************
 结构名    : PPP_HDLC_HARD_DEF_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :  HDLC解封装参数
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usPppId;                /* PPP ID */
    PPP_SERVICE_HDLC_HARD_MODE_ENUM_UINT8       enPppMode;      /* PPP工作模式 */
    VOS_UINT8                           ucReserve;
    VOS_UINT32                          ulPara;                 /* 业务模块透传参数，在结果中带回给业务模块 */
    PPP_HDLC_HARD_NODE_PARA_STRU        astInputNodePara[TTF_HDLC_DEF_INPUT_PARA_LINK_MAX_NUM];      /* 解封装输入节点参数 */
    VOS_UINT32                          ulInputNodeParaCnt;     /* 解封装输入及节点参数个数 */
    VOS_UINT32                          ulInputTotalSize;       /* 解封装输入节点总大小 */
    VOS_UINT32                          ulPppAcFlag;            /* PPP的地址控制域压缩标识 */
    VOS_UINT32                          ulPppPcFlag;            /* PPP的协议域压缩标识 */
} PPP_HDLC_HARD_DEF_PARA_STRU;


/* 维测相关结构 */

/*****************************************************************************
 结构名    : HDLC_MNTN_DEF_UNCOMPLETED_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :  解封装非完整帧可维可测结构
*****************************************************************************/
typedef struct
{
    HDLC_MNTN_TRACE_HEAD_STRU           stHead;                         /* _H2ASN_Skip */
    PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU  stUncompletedInfo;
}HDLC_MNTN_DEF_UNCOMPLETED_INFO_STRU;

/*****************************************************************************
 结构名    : HDLC_MNTN_INPUT_PARA_LINK_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :  输入参数链表可维可测结构
*****************************************************************************/
typedef struct
{
    HDLC_MNTN_TRACE_HEAD_STRU           stHead;                         /* _H2ASN_Skip */
    VOS_UINT32                          ulInputLinkNodeCnt;     /* 输入参数链表节点个数 */
    HDLC_PARA_LINK_NODE_STRU            astInputParaLinkNodeBuf[HDLC_INPUT_PARA_LINK_MAX_SIZE];
}HDLC_MNTN_INPUT_PARA_LINK_STRU;

/*****************************************************************************
 结构名    : HDLC_MNTN_FRM_OUTPUT_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :  封装输出结果可维可测结构
*****************************************************************************/
typedef struct
{
    HDLC_MNTN_TRACE_HEAD_STRU           stHead;                         /* _H2ASN_Skip */
    VOS_UINT8                           ucFrmValidNum;
    VOS_UINT8                           ucReserve1[1];
    VOS_UINT16                          usOutputNodeUsedCnt;
    VOS_UINT32                          ulOutputLinkNodeCnt;    /* 输出参数链表节点个数，只在封装有效 */
    HDLC_PARA_LINK_NODE_STRU            astOutputParaLinkNodeBuf[TTF_HDLC_FRM_OUTPUT_PARA_LINK_MAX_NUM];/* 封装输出参数链表使用的内存 */
    HDLC_FRM_RPT_NODE_STRU              astRptNodeBuf[TTF_HDLC_FRM_RPT_MAX_NUM];                        /* 封装信息上报空间使用的内存 */
}HDLC_MNTN_FRM_OUTPUT_PARA_STRU;

/*****************************************************************************
 结构名    : HDLC_MNTN_DEF_OUTPUT_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  :  解封装输出结果可维可测结构
*****************************************************************************/
typedef struct
{
    HDLC_MNTN_TRACE_HEAD_STRU           stHead;                         /* _H2ASN_Skip */
    VOS_UINT16                          usDefValidNum;
    VOS_UINT16                          usTraceNum;
    /* HDLC_DEF_RPT_NODE_STRU[usDefValidNum]此处为封装信息上报空间使用的内存，
       申请内存时由结构长度加上报空间需要的内存大小 */
}HDLC_MNTN_DEF_OUTPUT_PARA_STRU;

/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 全局变量声明
*****************************************************************************/



/*****************************************************************************
  10 函数声明
*****************************************************************************/
extern VOS_UINT32 PPP_Service_HdlcHardInit
(
    PPP_HDLC_HARD_CONFIG_INFO_STRU             *pstHdlcConfig,
    PPP_SERVICE_HDLC_HARD_DEF_CALLBACK_STRU    *pstDefCBInfo
);
extern VOS_VOID   PPP_Service_HdlcHardDisable(VOS_VOID);
extern VOS_VOID   PPP_Service_HdlcHardSetUp(VOS_UINT16 usPppId);
extern VOS_UINT32 PPP_Service_HdlcHardGetMaxDefLen(VOS_UINT16 usPppId);
extern PPP_HDLC_HARD_PROC_RESULT_ENUM_UINT32 PPP_Service_HdlcHardFrmPacket
(
    PPP_HDLC_HARD_FRM_PARA_STRU        *pstFrmPara,
    PPP_HDLC_HARD_FRM_RESULT_STRU      *pstFrmResult
);
extern PPP_HDLC_HARD_PROC_RESULT_ENUM_UINT32 PPP_Service_HdlcHardDefPacket
(
    PPP_HDLC_HARD_DEF_PARA_STRU        *pstDefPara
);
extern VOS_VOID PPP_Service_HdlcHardOpenClk(VOS_VOID);
extern VOS_VOID PPP_Service_HdlcHardCloseClk(VOS_VOID);
extern PPP_SERVICE_HDLC_HARD_WORK_STATUS_ENUM_UINT8
PPP_Service_HdlcHardGetWorkStatus(VOS_VOID);


#pragma pack()


#ifdef __cplusplus
    #if __cplusplus
            }
    #endif
#endif

#endif


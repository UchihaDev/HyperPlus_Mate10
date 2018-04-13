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

#ifndef __HDLC_HRADWARE_DRIVER_H__
#define __HDLC_HRADWARE_DRIVER_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "hdlc_hardware_mntn.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/

#if ((SC_CTRL_MOD_6250_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_3660_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_KIRIN970_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_M533 == SC_CTRL_MOD))
/* =========dallas/chicago/boston中使用: HDLC时钟在寄存器CRG_CLKEN4 和 CRG_CLKDIS4 24bit的位置======== */
#define     HDLC_CRG_CLK_BITPOS                                 (24UL)
#else
/* =========V7R2中使用: HDLC时钟在寄存器CRG_CLKEN4 和 CRG_CLKDIS4 10bit的位置======== */
#define     HDLC_CRG_CLK_BITPOS                                 (10UL)
#endif

#if (SC_CTRL_MOD_P532 == SC_CTRL_MOD)
#define     HDLC_CRG_CLKEN_OFFSET                               (0x24)      /* HDLC时钟使能OFFSET */
#define     HDLC_CRG_CLKDIS_OFFSET                              (0x28)      /* HDLC时钟关闭OFFSET */
#define     HDLC_CRG_CLKSTAT_OFFSET                             (0x2C)      /* HDLC时钟状态OFFSET */
#elif (SC_CTRL_MOD_6932_SFT == SC_CTRL_MOD)
#define     HDLC_CRG_CLKEN_OFFSET                               (0x30)      /* HDLC时钟使能OFFSET */
#define     HDLC_CRG_CLKDIS_OFFSET                              (0x34)      /* HDLC时钟关闭OFFSET */
#define     HDLC_CRG_CLKSTAT_OFFSET                             (0x38)      /* HDLC时钟状态OFFSET */
#elif ((SC_CTRL_MOD_6250_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_3660_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_KIRIN970_SFT == SC_CTRL_MOD) || (SC_CTRL_MOD_M533 == SC_CTRL_MOD))
/* =========dallas/chicago/boston中使用: HDLC时钟使能控制寄存器MDM_CRG_CLKEN0、
                          HDLC时钟关闭控制寄存器MDM_CRG_CLKDIS0、
                          HDLC时钟控制状态MDM_CRG_CLKSTAT0相对基地址的偏移======== */
#define     HDLC_CRG_CLKEN_OFFSET                               (0x00)      /* HDLC时钟使能OFFSET */
#define     HDLC_CRG_CLKDIS_OFFSET                              (0x04)      /* HDLC时钟关闭OFFSET */
#define     HDLC_CRG_CLKSTAT_OFFSET                             (0x08)      /* HDLC时钟状态OFFSET */
#else
#define     HDLC_CRG_CLKEN_OFFSET                               (0x30)      /* HDLC时钟使能OFFSET */
#define     HDLC_CRG_CLKDIS_OFFSET                              (0x34)      /* HDLC时钟关闭OFFSET */
#define     HDLC_CRG_CLKSTAT_OFFSET                             (0x38)      /* HDLC时钟状态OFFSET */
#endif


/* =========时钟使能寄存器======== */
#define     HDLC_CRG_CLKEN4_ADDR(base)                          ((base) + (HDLC_CRG_CLKEN_OFFSET))
/* =========时钟关闭寄存器======== */
#define     HDLC_CRG_CLKENDIS4_ADDR(base)                       ((base) + (HDLC_CRG_CLKDIS_OFFSET))
/* =========时钟状态寄存器======== */
#define     HDLC_CRG_CLKSTA4_ADDR(base)                         ((base) + (HDLC_CRG_CLKSTAT_OFFSET))

/* definition of bit positions and masks in a register */
/* ========================= 1.hdlc_frm_en (0x10) begin ======================= */
/*
   定义寄存器在32bit Reg中的bit位置:
        寄存器frm_en在bit0;
*/
#define     HDLC_FRM_EN_BITPOS                                  (0UL)

/* ========================= 2.hdlc_def_en (0x60) begin ======================= */
/*
   定义寄存器在32bit Reg中的bit位置:
        寄存器def_en在bit0;
*/
#define     HDLC_DEF_EN_BITPOS                                  (0UL)

/* ========================= 3.hdlc_frm_cfg (0x20) begin ======================= */
/*
   定义寄存器在32bit Reg中的bit位置:
        寄存器frm_in_lli_1dor2d在bit0;
        寄存器frm_acfc在bit1;
*/
#define     HDLC_FRM_IN_LLI_1DOR2D_BITPOS                       (0UL)
#define     HDLC_FRM_ACFC_BITPOS                                (1UL)
#define     HDLC_FRM_PFC_BITPOS                                 (2UL)

/*
   寄存器frm_pfc(2bits)各值含义:
        00b: 硬件模块添加P域, P域无压缩;
        01b: 硬件模块添加P域, P域压缩;
        11b: 硬件模块不添加P域;
*/
#define     HDLC_PROTOCOL_ADD_WITHOUT_COMPRESS                  (0x00)
#define     HDLC_PROTOCOL_ADD_WITH_COMPRESS                     (0x01)
#define     HDLC_PROTOCOL_NO_ADD                                (0x03)

/* ========================= 4.hdlc_def_cfg (0x70) begin ======================= */
/*
   定义寄存器在32bit Reg中的bit位置:
        寄存器def_uncompleted_ago在bit0;
        寄存器def_acfc在bit1;
*/
#define     HDLC_DEF_IS_UNCOMPLETED_AGO_BITPOS                  (0UL)
#define     HDLC_DEF_ACFC_BITPOS                                (1UL)
#define     HDLC_DEF_PFC_BITPOS                                 (2UL)


/* 寄存器frm_protocol(16bits)的MASK表 */
#define     HDLC_FRM_PROTOCOL_MASK                              (0x0000FFFF)

/*
   寄存器def_pfc(2bits)各值含义:
        00b: P域无压缩, 需剥离;
        01b: P域压缩, 需剥离;
        11b: P域不剥离;
*/
#define     HDLC_PROTOCOL_REMOVE_WITHOUT_COMPRESS               (0x00)
#define     HDLC_PROTOCOL_REMOVE_WITH_COMPRESS                  (0x01)
#define     HDLC_PROTOCOL_NO_REMOVE                             (0x03)

/* ========================= hdlc_prior_ctrl (0x04) begin ======================= */
/*
   寄存器hdlc_prior_ctrl(2bits)各值含义:
        00b: 谁先被使能则先将谁处理完;
        01b: 下行封装优先级高;
        10b: 上行解封装优先级高;
        11b: 无效;
*/
#define     HDLC_PRIOR_FCFS               (0x00)
#define     HDLC_PRIOR_DL_FRM_HIGHER      (0x01)
#define     HDLC_PRIOR_UL_DEF_HIGHER      (0x02)
#define     HDLC_PRIOR_INVALID            (0x03)


/* Boston版本中配置封装解封装信息域最大长度寄存器0x5DF(1503)Bytes */
#define     HDLC_MAX_FRM_DEF_INFO_LEN                           (0x000005DFU)

/* ====================== 封装状态寄存器地址 hdlc_frm_status (0x28) begin ====================== */
/* 封装模块状态寄存器地址: 相对偏移地址量0x28 */

/* 寄存器frm_out_seg_num(16bits)的MASK表 */
#define     HDLC_FRM_OUT_SEG_NUM_MASK                       (0x0000FFFF)

/* 寄存器frm_valid_num(8bits)的MASK表 */
#define     HDLC_FRM_VALID_NUM_MASK                         (0x000000FF)

/* 寄存器frm_all_pkt_done(1bit)的MASK表 */
#define     HDLC_FRM_ALL_PKT_DONE_MASK                      (0x00000001)

/* 查询封装状态信息的掩码 */
#define     HDLC_FRM_STATUS_MASK                            (0x00000003)

/*
   寄存器frm_block_done([0]位)各值含义:
        0b: 未完成一套链表数据处理;
        1b: 完成一套链表数据处理;
*/
/*
   寄存器frm_error_index([1]位)各值含义:
        1b: 封装发生错误;
*/
#define     HDLC_FRM_ALL_PKT_DOING                              (0x00)
#define     HDLC_FRM_ALL_PKT_DONE                               (0x01)
#define     HDLC_FRM_STOP_EXCEPTION_OCCUR                       (0x02)
#define     HDLC_FRM_DONE_EXCEPTION_OCCUR                       (0x03)




/* ======================= 解封装状态寄存器地址dlc_def_status (0x88) begin ===================== */
/* 寄存器dlc_def_status(5bits)的MASK表 */
#define     HDLC_DEFRAMER_BLOCK_STATUS_MASK                     (0x0000001B)

/* 查询解封装状态信息的掩码 */
#define     HDLC_DEF_STATUS_MASK                                (0x0000003B)

/*
   寄存器dlc_def_status(5bits)各值含义:
        000000b: 未完成一组数据处理;
        010000b: 未完成一组数据处理，解封装外部正确帧信息上报空间存满暂停;
        001000b: 未完成一组数据处理, 解封装外部输出存储空间存满暂停;
        000001b: 未完成一组数据处理, 已解出LCP帧, 硬件处于暂停状态;
        000010b: 完成一组数据处理, 但无帧上报;
        000011b: 完成一组数据处理, 且有帧上报;
        1xx0xxb: 有异常发生;
*/
#define     HDLC_DEF_STATUS_DOING                               (0x00)
#define     HDLC_DEF_STATUS_PAUSE_RPT_SPACE_FULL                (0x10)
#define     HDLC_DEF_STATUS_PAUSE_OUTPUT_SPACE_FULL             (0x08)
#define     HDLC_DEF_STATUS_PAUSE_LCP                           (0x01)
#define     HDLC_DEF_STATUS_DONE_WITHOUT_FRAMES                 (0x02)
#define     HDLC_DEF_STATUS_DONE_WITH_FRAMES                    (0x03)



/* 解封装是否有非完整帧标识 */
#define     HDLC_DEF_UNCOMPLETED_NOT_EXIST                      (0x0)
#define     HDLC_DEF_UNCOMPLETED_EXIST                          (0x1)

/* 轮询封装或解封装完成的次数 */
#define     HDLC_FRM_MAX_WAIT_RESULT_NUM                        (0xFFFF)
#define     HDLC_DEF_MAX_WAIT_RESULT_NUM                        (0xFFFF)

/* 等待封装或解封装响应中断时间,以毫秒为单位 */
#define     HDLC_FRM_MASTER_INT_TIMER_LEN                       (5000)
#define     HDLC_DEF_MASTER_INT_TIMER_LEN                       (5000)

/* 采用轮询还是中断使能的水线，默认值 */
#define     HDLC_DEF_INTERRUPT_LIMIT_DEFAULT                    (2*1024)
#define     HDLC_FRM_INTERRUPT_LIMIT_DEFAULT                    (2*1024)

/* AXI总线读写请求超时的判断值，该值由SoC提供，软件负责配置 */
#define     HDLC_AXI_REQ_TIMEOUT_VALUE                          (255)

/* HDLC地址控制域压缩 */
#define     HDLC_ADDRESS_CTRL_NOCOMPRESS            (0)
#define     HDLC_ADDRESS_CTRL_COMPRESS              (1)


/* HDLC硬件解封装错误z指示BIT位 */
#define PPP_DRIVER_HDLC_HARD_DEF_FCS_ERR            (0)
#define PPP_DRIVER_HDLC_HARD_DEF_FRAME_TOO_LONG     (1)
#define PPP_DRIVER_HDLC_HARD_DEF_FRAME_TOO_SHORT    (2)
#define PPP_DRIVER_HDLC_HARD_DEF_PROTOCOL_ERR       (3)
#define PPP_DRIVER_HDLC_HARD_DEF_CTRL_ERR           (4)
#define PPP_DRIVER_HDLC_HARD_DEF_ADDR_ERR           (5)
#define PPP_DRIVER_HDLC_HARD_DEF_FLAG_POS_ERR       (6)


/* 获取HDLC DRIVER配置信息 */
#define PPP_DRIVER_HDLC_HARD_GET_CONFIG             (&g_stHdlcConfigInfo)

/* 获取HDLC DRIVER封装配置信息 */
#define PPP_DRIVER_HDLC_HARD_GET_FRM_CONF           (&(PPP_DRIVER_HDLC_HARD_GET_CONFIG->stFrmConfig))

/* 获取HDLC DRIVER解封装配置信息 */
#define PPP_DRIVER_HDLC_HARD_GET_DEF_CONF           (&(PPP_DRIVER_HDLC_HARD_GET_CONFIG->stDefConfig))

/* 获取系统控制器基地址 */
#define PPP_DRIVER_HDLC_HARD_GET_SC_BASE_ARRD       (PPP_DRIVER_HDLC_HARD_GET_CONFIG->ulHdlcScCtrlBaseAddr)

/* 采用轮询还是中断使能的水线 */
#define     HDLC_DEF_INTERRUPT_LIMIT                            (PPP_DRIVER_HDLC_HARD_GET_CONFIG->ulHdlcDefIntLimit)
#define     HDLC_FRM_INTERRUPT_LIMIT                            (PPP_DRIVER_HDLC_HARD_GET_CONFIG->ulHdlcFrmIntLimit)

/* HDLC IP基地址 */
#define     HDLC_IP_BASE_ADDR                                   (PPP_DRIVER_HDLC_HARD_GET_CONFIG->ulHDLCIPBaseAddr)



/*****************************************************************************
  3 枚举定义
*****************************************************************************/
/** ****************************************************************************
 * Name        : PPP_DRIVER_HDLC_REG_ENUM_UINT8
 *
 * Description :
 *******************************************************************************/
enum PPP_DRIVER_HDLC_REG_ENUM
{
    PPP_DRIVER_MAX_FRM_INFO_REG                 = 0x00,
    PPP_DRIVER_MAX_DEF_INFO_REG                 = 0x01,

    PPP_DRIVER_HDLC_REG_BUTT
};
typedef VOS_UINT8 PPP_DRIVER_HDLC_REG_ENUM_UINT8;

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
 结构名    : PPP_DRIVER_HDLC_HARD_DEF_ERR_FRAMES_CNT_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 一组数据解出的错误帧数统计结构
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usFCSErrCnt;          /* FCS错误 */
    VOS_UINT16                          usLenLongCnt;         /* 帧长度过长, 超过1502字节 */
    VOS_UINT16                          usLenShortCnt;        /* 帧长度过短, 少于4字节 */
    VOS_UINT16                          usErrProtocolCnt;     /* 协议字段不满足xxxxxxx0, xxxxxxx1的形式 */
    VOS_UINT16                          usErrCtrlCnt;         /* 控制字段不为0xFF */
    VOS_UINT16                          usErrAddrCnt;         /* 地址字段不为0x03 */
    VOS_UINT16                          usFlagPosErrCnt;      /* 0x7D后紧接着0x7E */
    VOS_UINT8                           ucErrType;            /* 错误类型 */
    VOS_UINT8                           ucReserve;
}PPP_DRIVER_HDLC_HARD_DEF_ERR_FRAMES_CNT_STRU;

/*****************************************************************************
 结构名    : PPP_DRIVER_HDLC_HARD_FRM_CONFIG_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : HDLC封装配置相关信息结构
*****************************************************************************/
typedef struct
{
    VOS_VOID                           *pInputAddr;             /* 输入链表地址 */
    VOS_VOID                           *pOutputAddr;            /* 输出链表地址 */
    VOS_VOID                           *pReportAddr;            /* 封装结果上报地址 */
    VOS_UINT32                          ulRptBufLen;            /* 上报空间大小 */
}PPP_DRIVER_HDLC_HARD_FRM_CONFIG_STRU;

/*****************************************************************************
 结构名    : PPP_DRIVER_HDLC_HARD_DEF_CONFIG_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : HDLC解封装配置相关信息结构
*****************************************************************************/
typedef struct
{
    VOS_VOID                           *pInputAddr;             /* 输入链表地址 */
    VOS_VOID                           *pOutputAddr;            /* 输出链表地址 */
    VOS_VOID                           *pReportAddr;            /* 封装结果上报地址 */
    VOS_UINT32                          ulOutputBufLen;         /* 输出空间大小 */
    VOS_UINT32                          ulReportBufLen;         /* 上报空间大小 */
    VOS_UINT32                          ulPerInMaxLen;          /* 输入数据最大单包长度 */
}PPP_DRIVER_HDLC_HARD_DEF_CONFIG_STRU;


/*****************************************************************************
 结构名    : PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : HDLC配置相关信息结构
*****************************************************************************/
typedef struct
{
    VOS_UINT_PTR                        ulHDLCIPBaseAddr;      /* 从底软获取的HDLC基地址 */
    VOS_UINT_PTR                        ulHdlcScCtrlBaseAddr;  /* 系统控制器基地址 */
    VOS_UINT_PTR                        ulHdlcDefMasterSem;    /* 解封装信号量 */
    VOS_UINT_PTR                        ulHdlcFrmMasterSem;    /* 封装信号量 */
    VOS_INT32                           slHdlcISRDef;          /* 解封装中断号 */
    VOS_INT32                           slHdlcISRFrm;          /* 封装中断号 */
    VOS_UINT32                          ulHdlcDefIntLimit;     /* 解封装中断水线 */
    VOS_UINT32                          ulHdlcFrmIntLimit;     /* 封装中断水线 */
    PPP_DRIVER_HDLC_HARD_FRM_CONFIG_STRU    stFrmConfig;       /* 封装配置信息 */
    PPP_DRIVER_HDLC_HARD_DEF_CONFIG_STRU    stDefConfig;       /* 解封装配置信息 */
}PPP_DRIVER_HDLC_HARD_CONFIG_INFO_STRU;

/*****************************************************************************
 结构名    : PPP_DRIVER_HDLC_HARD_FRM_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : HDLC封装参数结构
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulInputTotalSize;       /* 输入链表总大小，用于判断是使用中断还是轮训方式 */
    VOS_UINT32                          ulAccmFlag;             /* 同异步控制字 */
    VOS_UINT32                          ulPppAcFlag;            /* 地址控制域压缩信息 */
    VOS_UINT32                          ulPppPcFlag;            /* 协议域压缩信息 */
    VOS_UINT16                          usProtocol;             /* 协议类型 */
    VOS_UINT8                           aucReserve[2];
}PPP_DRIVER_HDLC_HARD_FRM_PARA_STRU;

/*****************************************************************************
 结构名    : PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : HDLC解封装非完整帧信息存储结构
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucExistFlag;            /* 非完整帧是否存在标识 */
    VOS_UINT8                           aucReserve1[3];
    VOS_UINT16                          usDefOutOnePro;         /* 非完整帧的协议 */
    VOS_UINT16                          usDefOutOneLen;         /* 非完整帧的长度 */
    VOS_UINT8                          *pucDefOutOneAddr;       /* 指向解封装出的非完整帧在外存储的起始地址 */
    VOS_UINT32                          ulDefStAgo;             /* 用于保存def_uncomplet_st_now寄存器值 */
    VOS_UINT32                          ulDefInfoFrlCntAgo;     /* 用于保存def_info_frl_cnt_ago寄存器值 */
}PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU;

/*****************************************************************************
 结构名    : PPP_DRIVER_HDLC_HARD_DEF_PARA_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : HDLC解封装参数结构
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulInputTotalSize;       /* 输入链表总大小，用于判断是使用中断还是轮训方式 */
    VOS_UINT32                          ulPppPcFlag;            /* 协议域添加及压缩信息 */
    VOS_UINT32                          ulPppAcFlag;            /* 地址控制域压缩信息 */
    PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU *pstUncompleteInfo;   /*上次解封装的不完整帧信息 */
}PPP_DRIVER_HDLC_HARD_DEF_PARA_STRU;


/* 封装寄存器信息 */
typedef struct
{
    VOS_UINT32                          ulStateSwRst;
    VOS_UINT32                          ulPriorTimeoutCtrl;
    VOS_UINT32                          ulRdErrCurrAddr;
    VOS_UINT32                          ulWrErrCurrAddr;
    VOS_UINT32                          ulHdlcFrmEn;
    VOS_UINT32                          ulHdlcFrmRawInt;
    VOS_UINT32                          ulHdlcFrmIntStatus;
    VOS_UINT32                          ulHdlcFrmIntClr;
    VOS_UINT32                          ulHdlcFrmCfg;
    VOS_UINT32                          ulHdlcFrmAccm;
    VOS_UINT32                          ulHdlcFrmStatus;
    VOS_UINT32                          ulFrmInLliAddr;
    VOS_UINT32                          ulFrmInSublliAddr;
    VOS_UINT32                          ulFrmInPktLen;
    VOS_UINT32                          ulFrmInBlkAddr;
    VOS_UINT32                          ulFrmInBlkLen;
    VOS_UINT32                          ulFrmOutLliAddr;
    VOS_UINT32                          ulFrmOutSpaceAddr;
    VOS_UINT32                          ulFrmOutSpaceDep;
    VOS_UINT32                          ulFrmRptAddr;
    VOS_UINT32                          ulFrmRptDep;
}PPP_DRIVER_HDLCHARD_FRM_REG_INFO_STRU;

/* 解封装寄存器信息 */
typedef struct
{
    VOS_UINT32                          ulStateSwRst;
    VOS_UINT32                          ulPriorTimeoutCtrl;
    VOS_UINT32                          ulRdErrCurrAddr;
    VOS_UINT32                          ulWrErrCurrAddr;
    VOS_UINT32                          ulHdlcDefEn;
    VOS_UINT32                          ulHdlcDefRawInt;
    VOS_UINT32                          ulHdlcDefIntStatus;
    VOS_UINT32                          ulHdlcDefIntClr;
    VOS_UINT32                          ulHdlcDefCfg;
    VOS_UINT32                          ulDefUncompletedLen;
    VOS_UINT32                          ulDefUncompletedPro;
    VOS_UINT32                          ulDefUncompletedAddr;
    VOS_UINT32                          ulDefUncompleteStAgo;
    VOS_UINT32                          ulHdlcDefGoOn;
    VOS_UINT32                          ulHdlcDefStatus;
    VOS_UINT32                          ulDefUncompletStNow;
    VOS_UINT32                          ulDefInLliAddr;
    VOS_UINT32                          ulDefInPktAddr;
    VOS_UINT32                          ulDefInPktLen;
    VOS_UINT32                          ulDefInPktLenMax;
    VOS_UINT32                          ulDefOutSpcAddr;
    VOS_UINT32                          ulDefOutSpaceDep;
    VOS_UINT32                          ulDefRptAddr;
    VOS_UINT32                          ulDefRptDep;
    VOS_UINT32                          ulHdlcDefErrInfor0;
    VOS_UINT32                          ulHdlcDefErrInfor1;
    VOS_UINT32                          ulHdlcDefErrInfor2;
    VOS_UINT32                          ulHdlcDefErrInfor3;
    VOS_UINT32                          ulDefInfoFr1CntAgo;
    VOS_UINT32                          ulDefInfoFr1CntNow;
}PPP_DRIVER_HDLCHARD_DEF_REG_INFO_STRU;


/* 维测相关信息 */

/* 封装相关寄存器可维可测结构 */
typedef struct
{
    HDLC_MNTN_TRACE_HEAD_STRU           stHead;                     /* _H2ASN_Skip */
    PPP_DRIVER_HDLCHARD_FRM_REG_INFO_STRU   stFrmRegInfo;
} HDLC_MNTN_FRM_REG_CONFIG_STRU;

/* 解封装相关寄存器可维可测结构 */
typedef struct
{
    HDLC_MNTN_TRACE_HEAD_STRU           stHead;                     /* _H2ASN_Skip */
    PPP_DRIVER_HDLCHARD_DEF_REG_INFO_STRU   stDefRegInfo;
} HDLC_MNTN_DEF_REG_CONFIG_STRU;


/*****************************************************************************
  8 UNION定义
*****************************************************************************/



/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
VOS_VOID PPP_Driver_HdlcHardPeriphClkOpen(VOS_VOID);
VOS_VOID PPP_Driver_HdlcHardPeriphClkClose(VOS_VOID);
VOS_UINT32 PPP_Driver_HdlcHardInit
(
    PPP_DRIVER_HDLC_HARD_FRM_CONFIG_STRU   *pstFrmConfig,
    PPP_DRIVER_HDLC_HARD_DEF_CONFIG_STRU   *pstDefConfig
);
VOS_VOID PPP_Driver_HdlcHardWorkStatus
(
    VOS_BOOL                           *penFrmWork,
    VOS_BOOL                           *penDefWork
);
VOS_VOID PPP_Driver_HdlcHardGetFrmResult
(
    VOS_UINT16                         *pusFrmOutSegNum,
    VOS_UINT8                          *pucFrmValidNum
);
VOS_UINT32 PPP_Driver_HdlcHardFrmEnable
(
    PPP_DRIVER_HDLC_HARD_FRM_PARA_STRU *pstDrvFrmPara,
    VOS_UINT32                         *pulEnableInterrupt
);
VOS_UINT16 PPP_Driver_HdlcHardGetDefVaildNum(VOS_VOID);
VOS_VOID PPP_Driver_HdlcHardGetDefUncompletInfo
(
    PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU *pstUncompleteInfo,
    VOS_UINT32                                     *pucValidNum
);
VOS_VOID PPP_Driver_HdlcHardGetDefErrorInfo
(
    PPP_DRIVER_HDLC_HARD_DEF_ERR_FRAMES_CNT_STRU   *pstErrCnt
);

VOS_UINT32 PPP_Driver_HdlcHardDefWaitResult
(
    VOS_UINT32          ulEnableInterrupt
);
VOS_UINT32 PPP_Driver_HdlcHardDefEnable
(
    PPP_DRIVER_HDLC_HARD_DEF_PARA_STRU *pstDrvDefPara,
    VOS_UINT32                         *pulEnableInterrupt
);
VOS_VOID PPP_Driver_HdlcHardDefCfgGoOnReg
(
    VOS_UINT32          ulDefStatus
);
VOS_VOID PPP_Driver_HdlcHardDefCfgReg
(
    PPP_DRIVER_HDLC_HARD_DEF_PARA_STRU *pstDrvDefPara
);
VOS_VOID PPP_Driver_HdlcHardGetFrmRegInfo(PPP_DRIVER_HDLCHARD_FRM_REG_INFO_STRU *pstRegConfig);

VOS_VOID PPP_Driver_HdlcHardGetDefRegInfo(PPP_DRIVER_HDLCHARD_DEF_REG_INFO_STRU *pstRegConfig);
VOS_UINT32 PPP_Driver_HdlcHardGetDefRawInt(VOS_VOID);
VOS_UINT32 PPP_Driver_HdlcHardGetFrmRawInt(VOS_VOID);
VOS_VOID PPP_Driver_HdlcHardShowFrmReg(VOS_VOID);
VOS_VOID PPP_Driver_HdlcHardShowDefReg(VOS_VOID);
VOS_VOID PPP_Driver_HdlcHardShowConfigInfo(VOS_VOID);
VOS_VOID PPP_Driver_HdlcSetMaxFrmDefInfoLen(VOS_VOID);



#pragma pack()


#ifdef __cplusplus
    #if __cplusplus
            }
    #endif
#endif


#endif


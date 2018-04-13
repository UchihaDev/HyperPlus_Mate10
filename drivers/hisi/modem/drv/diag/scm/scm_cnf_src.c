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


/*****************************************************************************
  1 头文件包含
**************************************************************************** */
#include <product_config.h>
#include <mdrv.h>
#include <mdrv_diag_system.h>
#include <osl_sem.h>
#include <soc_socp_adapter.h>
#include <bsp_socp.h>
#include <bsp_dump.h>
#include "diag_port_manager.h"
#include "soft_decode.h"
#include "OmCommonPpm.h"
#include "scm_debug.h"
#include "scm_common.h"
#include "scm_cnf_src.h"


/* ****************************************************************************
  2 全局变量定义
**************************************************************************** */
SCM_CODER_SRC_CFG_STRU      g_astSCMCnfCoderSrcCfg=
{
    SCM_CHANNEL_UNINIT, 
    SOCP_CODER_SRC_LOM_CNF1, 
    SOCP_CODER_DST_OM_CNF,   
    SOCP_DATA_TYPE_0, 
    SOCP_ENCSRC_CHNMODE_CTSPACKET, 
    SOCP_CHAN_PRIORITY_2, 
    SCM_CODER_SRC_BDSIZE, 
    SCM_CODER_SRC_RDSIZE, 
    NULL, 
    NULL, 
    NULL, 
    NULL
};


extern SCM_CODER_SRC_DEBUG_STRU g_astScmCnfSrcDebugInfo;

u32 scm_init_cnf_src_buff(void)
{
    u32                          ulRet;


    ulRet = scm_create_cnf_src_buff(&g_astSCMCnfCoderSrcCfg.pucSrcBuf,
                                &g_astSCMCnfCoderSrcCfg.pucSrcPHY,
                                SCM_CODER_SRC_CNF_BUFFER_SIZE);
    if(BSP_OK != ulRet)
    {
        g_astSCMCnfCoderSrcCfg.enInitState   = SCM_CHANNEL_MEM_FAIL;  
        return (u32)BSP_ERROR;
    }
    g_astSCMCnfCoderSrcCfg.ulSrcBufLen   = SCM_CODER_SRC_CNF_BUFFER_SIZE;
    g_astSCMCnfCoderSrcCfg.enInitState   = SCM_CHANNEL_INIT_SUCC;  

    return BSP_OK;
}


/* ****************************************************************************
 函 数 名  : scm_create_cnf_src_buff
 功能描述  : 申请编码源buffer空间
 修改历史  :
**************************************************************************** */
u32 scm_create_cnf_src_buff(u8 **pBufVir, u8 **pBufPhy, u32 ulLen)
{
    unsigned long ulRealAddr;

    /*申请uncache的动态内存区*/
    *pBufVir = (u8*)scm_UnCacheMemAlloc(ulLen, &ulRealAddr);

    /* 分配内存失败 */
    if (NULL == *pBufVir)
    {
        return (u32)BSP_ERROR;
    }

    /* 保存buf实地址 */
    *pBufPhy = (u8*)ulRealAddr;

    return BSP_OK;
}


/*****************************************************************************
 函 数 名  : SCM_GetCoderChnSrcBuff
 功能描述  : 获取编码源通道的buffer
 输入参数  : enChanlID: 通道ID
             ulDataLen: 要获取的buffer长度
             pstCoderHeader:buffer信息
 输出参数  : 无
 返 回 值  : BSP_ERROR/BSP_OK
 调用函数  :
 被调函数  :
 修改历史  :
   1.日    期  : 2015年3月22日
     作    者  : yuyangyang
     修改内容  : Creat Function

   2.日    期  : 2015年7月12日
     作    者  : c00326366
     修改内容  : 只要总的剩余空间够就返回buffer指针
**************************************************************************** */
u32 scm_get_cnf_src_buff(
                                    u32 ulDataLen, 
                                    SCM_CODER_SRC_PACKET_HEADER_STRU** pstCoderHeader,
                                    SOCP_BUFFER_RW_STRU *pstSocpBuf)
{
    SOCP_BUFFER_RW_STRU                 stRwBuf;
    SCM_CODER_SRC_PACKET_HEADER_STRU    *pstBuff;
    u32                          *pstBuftmp;
    u32                          ulTrueLen;
    SOCP_CODER_SRC_ENUM_U32             enChanlID;

    /* 判断数据不能大于4K */
    if ((0 == ulDataLen) || (ulDataLen > SCM_CODER_SRC_MAX_LEN))
    {
        (void)scm_printf("ulDataLen %d.\n", ulDataLen);
        return (u32)BSP_ERROR;
    }

    if (g_astSCMCnfCoderSrcCfg.enInitState != SCM_CHANNEL_INIT_SUCC)/* 判断通道参数 */
    {
        scm_printf("cnf channel buff is not init\n");
        return (u32)BSP_ERROR;/* 返回失败 */
    }

    if(SOCP_ENCSRC_CHNMODE_LIST == g_astSCMCnfCoderSrcCfg.enCHMode)
    {
        scm_printf("cnf channel mode is list, error\n");
        return (u32)BSP_ERROR;
    }

    enChanlID = g_astSCMCnfCoderSrcCfg.enChannelID;
    if(BSP_OK != bsp_socp_get_write_buff(enChanlID, &stRwBuf))
    {
        g_astScmCnfSrcDebugInfo.ulGetWriteBufErr ++;
        return (u32)BSP_ERROR;/* 返回失败 */
    }

    ulTrueLen = ALIGN_DDR_WITH_8BYTE(ulDataLen);
    if((stRwBuf.u32Size + stRwBuf.u32RbSize) >= (ulTrueLen + SCM_HISI_HEADER_LENGTH))
    {
        /*需要返回虚拟地址给上层*/
        pstBuff = (SCM_CODER_SRC_PACKET_HEADER_STRU*)scm_UncacheMemPhyToVirt((u8*)stRwBuf.pBuffer,
                                    g_astSCMCnfCoderSrcCfg.pucSrcPHY,
                                    g_astSCMCnfCoderSrcCfg.pucSrcBuf,
                                    g_astSCMCnfCoderSrcCfg.ulSrcBufLen);

        if(stRwBuf.u32Size >= SCM_HISI_HEADER_LENGTH)
        {
            pstBuff->ulHisiMagic = SCM_HISI_HEADER_MAGIC;
            pstBuff->ulDataLen   = ulDataLen;
        }
        else if(stRwBuf.u32Size >= 4)
        {
            pstBuff->ulHisiMagic = SCM_HISI_HEADER_MAGIC;

            pstBuftmp = (u32*)g_astSCMCnfCoderSrcCfg.pucSrcBuf;
            *pstBuftmp      = ulDataLen;
        }
        else    /* TODO: 应该没有stRwBuf.u32Size为0的场景 */
        {
            pstBuftmp = (u32*)g_astSCMCnfCoderSrcCfg.pucSrcBuf;

            *(pstBuftmp++)  = SCM_HISI_HEADER_MAGIC;
            *pstBuftmp      = ulDataLen;
        }

        *pstCoderHeader     = pstBuff;
        /* coverity[secure_coding] */
        (void)memcpy(pstSocpBuf, &stRwBuf, sizeof(stRwBuf));

        return BSP_OK;
    }
    else
    {
        g_astScmCnfSrcDebugInfo.ulGetCoherentBuffErr++;
        return (u32)BSP_ERROR;
    }

}


/*****************************************************************************
 函 数 名  : SCM_CoderSrcMemcpy
 功能描述  : 编码源通道的memcpy
 输入参数  : pInfo:         拷贝信息
             pstSocpBuf:    之前获取的socp buffer信息
 输出参数  : 无
 修改历史  :
   1.日    期  : 2015年7月12日
     作    者  : c00326366
     修改内容  : Creat Function
**************************************************************************** */
void scm_cnf_src_buff_mempy(SCM_CODER_SRC_MEMCPY_STRU *pInfo, SOCP_BUFFER_RW_STRU *pstSocpBuf)
{
    void    *pDst;

    /* 本函数的拷贝处理流程不检查越界情况，由调用的地方保证 */
    if(pInfo->uloffset < pstSocpBuf->u32Size)
    {
        if((pInfo->uloffset + pInfo->ulLen) <= pstSocpBuf->u32Size)
        {
            /* coverity[secure_coding] */
            (void)memcpy(((u8*)pInfo->pHeader + pInfo->uloffset), pInfo->pSrc, pInfo->ulLen);          
            scm_FlushCpuWriteBuf();
        }
        else
        {
            /* coverity[secure_coding] */
            (void)memcpy(((u8*)pInfo->pHeader + pInfo->uloffset), pInfo->pSrc, (pstSocpBuf->u32Size - pInfo->uloffset));
            scm_FlushCpuWriteBuf();
            
            pDst = g_astSCMCnfCoderSrcCfg.pucSrcBuf;
            /* coverity[secure_coding] */
            (void)memcpy(pDst,
                ((u8*)pInfo->pSrc + (pstSocpBuf->u32Size - pInfo->uloffset)),
                (pInfo->uloffset + pInfo->ulLen - pstSocpBuf->u32Size));           
            scm_FlushCpuWriteBuf();
            
        }
    }
    else
    {
        pDst = g_astSCMCnfCoderSrcCfg.pucSrcBuf;

        pDst = (u8*)pDst + (pInfo->uloffset - pstSocpBuf->u32Size);
        /* coverity[secure_coding] */
        (void)memcpy(pDst, pInfo->pSrc, pInfo->ulLen);
        scm_FlushCpuWriteBuf();
        
    }
}


/* ****************************************************************************
 函 数 名  : SCM_SendCoderSrc
 功能描述  : 通过SOCP的编码源通道发送数据
 输入参数  : enChanlID: 通道ID
             pucSendDataAddr:发送数据地址，块式传虚拟地址，链式传物理地址
             ulSendLen: 发送数据长度
 输出参数  : 无
 返 回 值  : BSP_ERROR/BSP_OK
 调用函数  :
 被调函数  :
 修改历史  :
   1.日    期  : 2012年8月8日
     作    者  : zhuli
     修改内容  : Creat Function
**************************************************************************** */
u32 scm_send_cnf_src_data(u8 *pucSendDataAddr, u32 ulSendLen)
{
    SOCP_BUFFER_RW_STRU                 stRwBuf;
    u32                          ulBDNum;
    SOCP_BD_DATA_STRU                   stBDData;
    SCM_CODER_SRC_PACKET_HEADER_STRU*   pstCoderHeader;
    SOCP_CODER_SRC_ENUM_U32             enChanlID;

    /* 判断数据指针和长度的正确，长度不能大于4K */
    if ((NULL == pucSendDataAddr)
        ||(0 == ulSendLen)
        /*||(SCM_CODER_SRC_MAX_LEN < ulSendLen)*/)
    {
        return (u32)BSP_ERROR;
    }

    if (g_astSCMCnfCoderSrcCfg.enInitState != SCM_CHANNEL_INIT_SUCC)/* 判断通道参数 */
    {
        scm_printf("cnf channel buff is not init\n");
        return (u32)BSP_ERROR;/* 返回失败 */
    }

    enChanlID = g_astSCMCnfCoderSrcCfg.enChannelID;
    if (BSP_OK != bsp_socp_get_write_buff(enChanlID, &stRwBuf))
    {
        g_astScmCnfSrcDebugInfo.ulGetWriteBufErr ++;
        return (u32)BSP_ERROR;/* 返回失败 */
    }


    if(SOCP_ENCSRC_CHNMODE_LIST == g_astSCMCnfCoderSrcCfg.enCHMode)
    {
        /* 计算空闲BD的值 */
        ulBDNum = (stRwBuf.u32Size + stRwBuf.u32RbSize) / sizeof(SOCP_BD_DATA_STRU);

        /* 判断是否还有空间 */
        if (1 >= ulBDNum)
        {
            return (u32)BSP_ERROR;
        }

        stRwBuf.pBuffer = (char*)scm_UncacheMemPhyToVirt((u8*)stRwBuf.pBuffer,
                                        g_astSCMCnfCoderSrcCfg.pucSrcPHY,
                                        g_astSCMCnfCoderSrcCfg.pucSrcBuf,
                                        g_astSCMCnfCoderSrcCfg.ulSrcBufLen);

        stBDData.ulDataAddr = (u32)((unsigned long)pucSendDataAddr);
        stBDData.usMsgLen   = (u16)ulSendLen;
        stBDData.enDataType = SOCP_BD_DATA;
        /* coverity[secure_coding] */
        (void)memcpy(stRwBuf.pBuffer, &stBDData, sizeof(stBDData));    /* 复制数据到指定的地址 */
        scm_FlushCpuWriteBuf();

        if (BSP_OK != bsp_socp_write_done(enChanlID, sizeof(stBDData)))   /* 当前数据写入完毕 */
        {
            SCM_CODER_SRC_ERR("SCM_SendCoderSrc: Write Buffer is Error", enChanlID, 0);/* 记录Log */
            return (u32)BSP_ERROR;/* 返回失败 */
        }
    }
    else if(SOCP_ENCSRC_CHNMODE_CTSPACKET == g_astSCMCnfCoderSrcCfg.enCHMode)
    {
        if(stRwBuf.u32Size < SCM_HISI_HEADER_LENGTH)
        {
            g_astScmCnfSrcDebugInfo.ulSendFirstNotEnough ++;
            return (u32)BSP_ERROR;
        }

        stRwBuf.pBuffer = (char*)scm_UncacheMemPhyToVirt((u8*)stRwBuf.pBuffer,
                                        g_astSCMCnfCoderSrcCfg.pucSrcPHY,
                                        g_astSCMCnfCoderSrcCfg.pucSrcBuf,
                                        g_astSCMCnfCoderSrcCfg.ulSrcBufLen);
        if(stRwBuf.pBuffer != (char*)pucSendDataAddr)
        {
            g_astScmCnfSrcDebugInfo.ulSendAddrErr++;
            scm_printf("send addr err\n");
            return (u32)BSP_ERROR;
        }

        pstCoderHeader = (SCM_CODER_SRC_PACKET_HEADER_STRU*)pucSendDataAddr;
        if((pstCoderHeader->ulDataLen != ulSendLen)||(pstCoderHeader->ulHisiMagic != SCM_HISI_HEADER_MAGIC))
        {
            g_astScmCnfSrcDebugInfo.ulSendHeaderErr++;
            return (u32)BSP_ERROR;
        }
        scm_FlushCpuWriteBuf();
        /*第一段连续空间不足HISI包头长度*/
        ulSendLen = ALIGN_DDR_WITH_8BYTE(ulSendLen);
        if(BSP_OK != bsp_socp_write_done(enChanlID, (ulSendLen + SCM_HISI_HEADER_LENGTH)))
        {
            g_astScmCnfSrcDebugInfo.ulSendWriteDoneErr ++;
            return (u32)BSP_ERROR;
        }
        g_astScmCnfSrcDebugInfo.ulSendDataLen += ulSendLen;
        g_astScmCnfSrcDebugInfo.ulSendPacketNum ++;
    }
    else
    {
        return (u32)BSP_ERROR;
    }
    return BSP_OK;
}
/* ****************************************************************************
 函 数 名  : SCM_CoderSrcChannelInit
 功能描述  : 将ACPU/CCPU的编码源通道的配置初始化
 输入参数  : 无
 输出参数  : 无
 返 回 值  : BSP_ERROR/BSP_OK
 调用函数  :
 被调函数  :
 修改历史  :
   1.日    期  : 2012年8月8日
     作    者  : zhuli
     修改内容  : Creat Function
**************************************************************************** */
u32 scm_cnf_src_chan_init(void)
{

    if (BSP_OK != scm_cnf_src_chan_cfg(&g_astSCMCnfCoderSrcCfg))
    {
        g_astSCMCnfCoderSrcCfg.enInitState = SCM_CHANNEL_CFG_FAIL;  /* 记录通道初始化配置错误 */

        return (u32)BSP_ERROR;/* 返回失败 */
    }

    if(BSP_OK != bsp_socp_start(g_astSCMCnfCoderSrcCfg.enChannelID))
    {
        g_astSCMCnfCoderSrcCfg.enInitState = SCM_CHANNEL_START_FAIL;  /* 记录通道开启配置错误 */

        return (u32)BSP_ERROR;/* 返回失败 */
    }

    g_astSCMCnfCoderSrcCfg.enInitState = SCM_CHANNEL_INIT_SUCC;     /* 记录通道初始化配置错误 */

    return BSP_OK;/* 返回成功 */
}


/*****************************************************************************
 函 数 名  : SCM_CoderSrcChannelCfg
 功能描述  : 将ACPU/CCPU的编码源通道的配置调用SOCP接口配置到IP
 输入参数  : 无
 输出参数  : 无
 返 回 值  : BSP_ERROR/BSP_OK
 调用函数  :
 被调函数  :
 修改历史  :
   1.日    期  : 2012年8月8日
     作    者  : zhuli
     修改内容  : Creat Function
*****************************************************************************/
u32 scm_cnf_src_chan_cfg(SCM_CODER_SRC_CFG_STRU *pstCfg)
{
    SOCP_CODER_SRC_CHAN_S               stChannle;          /* 当前通道的属性信息 */

    stChannle.u32DestChanID = pstCfg->enDstCHID;            /*  目标通道ID */
    stChannle.eDataType     = pstCfg->enDataType;           /*  数据类型，指明数据封装协议，用于复用多平台 */
    stChannle.eMode         = pstCfg->enCHMode;             /*  通道数据模式 */
    stChannle.ePriority     = pstCfg->enCHLevel;            /*  通道优先级 */
    stChannle.u32BypassEn   = SOCP_HDLC_ENABLE;             /*  通道bypass使能 */
    stChannle.eDataTypeEn   = SOCP_DATA_TYPE_EN;            /*  数据类型使能位 */
    stChannle.eDebugEn      = SOCP_ENC_DEBUG_DIS;           /*  调试位使能 */

    stChannle.sCoderSetSrcBuf.pucInputStart  = pstCfg->pucSrcPHY;                             /*  输入通道起始地址 */
    stChannle.sCoderSetSrcBuf.pucInputEnd    = (pstCfg->pucSrcPHY + pstCfg->ulSrcBufLen)-1;   /*  输入通道结束地址 */
    stChannle.sCoderSetSrcBuf.pucRDStart     = pstCfg->pucRDPHY;                              /* RD buffer起始地址 */
    stChannle.sCoderSetSrcBuf.pucRDEnd       = (pstCfg->pucRDPHY + pstCfg->ulRDBufLen)-1;     /*  RD buffer结束地址 */
    stChannle.sCoderSetSrcBuf.u32RDThreshold = SCM_CODER_SRC_RD_THRESHOLD;                    /* RD buffer数据上报阈值 */

    if (BSP_OK != bsp_socp_coder_set_src_chan(pstCfg->enChannelID, &stChannle))
    {
        SCM_CODER_SRC_ERR("SCM_CoderSrcChannelCfg: Search Channel ID Error", pstCfg->enChannelID, 0);/* 打印失败 */

        return (u32)BSP_ERROR;/* 返回错误 */
    }

    pstCfg->enInitState = SCM_CHANNEL_INIT_SUCC; /* 记录通道初始化配置错误 */

    return BSP_OK;/* 返回成功 */
}






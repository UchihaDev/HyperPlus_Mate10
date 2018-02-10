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

/******************************************************************************
  1 头文件包含
******************************************************************************/
#include "hdlc_hardware_service.h"
#include "TTFComm.h"
#include "TTFUtil.h"

#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif

/*****************************************************************************
   协议栈打印打点方式下的.C文件宏定义
*****************************************************************************/
#define    THIS_FILE_ID        PS_FILE_ID_HDLC_HARDWARE_SERVICE_C


/******************************************************************************
   2 外部函数变量声明
******************************************************************************/


/*****************************************************************************
   3 私有定义
*****************************************************************************/


/*****************************************************************************
   4 全局变量定义
*****************************************************************************/


/* 解封装输出的非完整帧信息 */
PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU  l_stUncompletedInfo = {0};

/* 保存解封装使用的内存 */
HDLC_DEF_BUFF_INFO_STRU        *l_pstHdlcDefBufInfo = VOS_NULL_PTR;

/* 保存封装使用的内存 */
HDLC_FRM_BUFF_INFO_STRU        *l_pstHdlcFrmBufInfo = VOS_NULL_PTR;

/* 业务模块封装结果处理函数 */
PPP_SERVICE_HDLC_HARD_DEF_CALLBACK_STRU     l_stHldcDefCallBackInfo;

/******************************************************************************
   5 函数实现
******************************************************************************/

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardOpenClk
 功能描述  : 打开HDLC时钟
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardOpenClk(VOS_VOID)
{
    PPP_Driver_HdlcHardPeriphClkOpen();
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardCloseClk
 功能描述  : 关闭HDLC时钟
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardCloseClk(VOS_VOID)
{
    PPP_Driver_HdlcHardPeriphClkClose();
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardGetWorkStatus
 功能描述  : 获取HDLC工作状态
 输入参数  : 无
 输出参数  : 无
 返 回 值  : enWorkStatus   -   HDLC工作状态
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
PPP_SERVICE_HDLC_HARD_WORK_STATUS_ENUM_UINT8
PPP_Service_HdlcHardGetWorkStatus(VOS_VOID)
{
    VOS_BOOL                            enFrmWork;
    VOS_BOOL                            enDefWork;
    PPP_SERVICE_HDLC_HARD_WORK_STATUS_ENUM_UINT8    enWorkStatus;

    PPP_Driver_HdlcHardWorkStatus(&enFrmWork, &enDefWork);

    if ((VOS_TRUE == enFrmWork) && (VOS_TRUE == enDefWork))
    {
        enWorkStatus = PPP_SERVICE_HDLC_HARD_BOTH_WORK;
    }
    else if (VOS_TRUE == enFrmWork)
    {
        enWorkStatus = PPP_SERVICE_HDLC_HARD_FRM_WORK;
    }
    else if (VOS_TRUE == enDefWork)
    {
        enWorkStatus = PPP_SERVICE_HDLC_HARD_DEF_WORK;
    }
    else
    {
        enWorkStatus = PPP_SERVICE_HDLC_HARD_NOT_WORK;
    }

    return enWorkStatus;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardSetUp
 功能描述  : 初始化该路PPP链接，如清空非完整帧信息
 输入参数  : usPppId - PPP ID
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardSetUp(VOS_UINT16 usPppId)
{
    PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU  *pstUncompletedInfo;


    pstUncompletedInfo = HDLC_DEF_GET_UNCOMPLETED_INFO(usPppId);

    PPP_HDLC_HARD_MEM_SET(pstUncompletedInfo, sizeof(PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU),
                 0, sizeof(PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU));

    return;
}


/*****************************************************************************
 函 数 名  : PPP_HDLC_HARD_Disable
 功能描述  : 对HDLC进行去使能
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardDisable(VOS_VOID)
{
    /* 暂无操作，因为HDLC优化后，一套链表封装或解封装完成时，由硬件自动对frm_en或def_en清零；
       封装或解封装过程出错时，硬件也会自动清零，使内部状态机返回IDLE状态；*/
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardInit
 功能描述  : 初始化HDLC，完成内存申请硬件配置等工作
 输入参数  : pstHdlcConfig  -   配置信息
 输出参数  : 无
 返 回 值  : VOS_OK     -   初始化成功
             VOS_ERR    -   初始化失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Service_HdlcHardInit
(
    PPP_HDLC_HARD_CONFIG_INFO_STRU             *pstHdlcConfig,
    PPP_SERVICE_HDLC_HARD_DEF_CALLBACK_STRU    *pstDefCBInfo
)
{
    VOS_UINT_PTR                            ulPppVirtAddr         = 0;
    VOS_UINT_PTR                            ulPppPhyAddr          = 0;
    VOS_UINT32                              ulPppTotalBufLen      = 0;
    PPP_DRIVER_HDLC_HARD_FRM_CONFIG_STRU    stFrmConfig;       /* 封装配置信息 */
    PPP_DRIVER_HDLC_HARD_DEF_CONFIG_STRU    stDefConfig;       /* 解封装配置信息 */

    if (VOS_ERR == PPP_HdlcHardConfig(pstHdlcConfig))
    {
        return VOS_ERR;
    }

    if ((VOS_NULL_PTR == pstDefCBInfo) || (VOS_NULL_PTR == pstDefCBInfo->pDefErrProcFunc)
        || (VOS_NULL_PTR == pstDefCBInfo->pDefResProcFunc))
    {
        PPP_HDLC_ERROR_LOG("pDefResProcFunc is NULL");
        return VOS_ERR;
    }

    l_stHldcDefCallBackInfo.pDefResProcFunc = pstDefCBInfo->pDefResProcFunc;
    l_stHldcDefCallBackInfo.pDefErrProcFunc = pstDefCBInfo->pDefErrProcFunc;

    /* 计算内存长度，实际使用长度为0x6140，申请按照0x8000(32K)对齐 */
    ulPppTotalBufLen  = pstHdlcConfig->ulPppTotalBufLen;

    /* 内存申请 */
    ulPppVirtAddr     = (VOS_UINT_PTR)VOS_UnCacheMemAllocDebug(ulPppTotalBufLen, &ulPppPhyAddr, TTF_HDLC_UNCACHE_MEM);
    if (VOS_NULL_PTR == ulPppVirtAddr)
    {
        PPP_HDLC_ERROR_LOG("PPP_HDLC_HARD_InitBuf, ERROR, VOS_UnCacheMemAlloc Fail\r\n");
        return VOS_ERR;
    }

    PPP_HDLC_HARD_MEM_SET((void *)ulPppVirtAddr, ulPppTotalBufLen, 0, ulPppTotalBufLen);

    /* 根据TtfMemoryMap.h初始化HDLC所需内存 */
    l_pstHdlcDefBufInfo = (HDLC_DEF_BUFF_INFO_STRU *)ulPppVirtAddr;
    l_pstHdlcFrmBufInfo = (HDLC_FRM_BUFF_INFO_STRU *)(ulPppVirtAddr + sizeof(HDLC_DEF_BUFF_INFO_STRU));

    g_stPppHdlcConfig.ulPppPhyAddr = ulPppPhyAddr;
    g_stPppHdlcConfig.ulPppVirtAddr = ulPppVirtAddr;

    /* TTF_HDLC_MASTER_DEF_BUF_LEN必须与结构HDLC_DEF_BUFF_INFO_STRU的大小一致 */
    PPP_SERVICE_HDLC_HARD_STRU_SIZE_CHECK(TTF_HDLC_MASTER_DEF_BUF_LEN, HDLC_DEF_BUFF_INFO_STRU);

    /* TTF_HDLC_MASTER_FRM_BUF_LEN收必须与结构HDLC_FRM_BUFF_INFO_STRU的大小一致 */
    PPP_SERVICE_HDLC_HARD_STRU_SIZE_CHECK(TTF_HDLC_MASTER_FRM_BUF_LEN, HDLC_FRM_BUFF_INFO_STRU);

    /* 封装配置参数 */
    stFrmConfig.pInputAddr      = PPP_HDLC_HARD_BUF_VIRT2PHY(l_pstHdlcFrmBufInfo->astInputParaLinkNodeBuf);
    stFrmConfig.pOutputAddr     = PPP_HDLC_HARD_BUF_VIRT2PHY(l_pstHdlcFrmBufInfo->astOutputParaLinkNodeBuf);
    stFrmConfig.pReportAddr     = PPP_HDLC_HARD_BUF_VIRT2PHY(l_pstHdlcFrmBufInfo->astRptNodeBuf);
    stFrmConfig.ulRptBufLen     = TTF_HDLC_FRM_RPT_BUF_LEN;

    /* 解封装配置参数 */
    stDefConfig.pInputAddr      = PPP_HDLC_HARD_BUF_VIRT2PHY(l_pstHdlcDefBufInfo->astInputParaLinkNodeBuf);
    stDefConfig.pOutputAddr     = PPP_HDLC_HARD_BUF_VIRT2PHY(l_pstHdlcDefBufInfo->aucOutputDataBuf);
    stDefConfig.pReportAddr     = PPP_HDLC_HARD_BUF_VIRT2PHY(l_pstHdlcDefBufInfo->astRptNodeBuf);
    stDefConfig.ulOutputBufLen  = TTF_HDLC_DEF_OUTPUT_DATA_BUF_LEN;
    stDefConfig.ulReportBufLen  = TTF_HDLC_DEF_RPT_BUF_LEN;
    stDefConfig.ulPerInMaxLen   = HDLC_DEF_IN_PER_MAX_CNT;

    if (VOS_ERR == PPP_Driver_HdlcHardInit(&stFrmConfig, &stDefConfig))
    {
        PPP_HDLC_ERROR_LOG("HDLC Hardware Init Fail");
        return VOS_ERR;
    }

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardTraceInputPara
 功能描述  : 勾取输入参数链表内容
 输入参数  : ulEventType        - 数据类型,
             ulLinkNodeCnt      - 输入参数结点个数,
             pastLinkNodeBuf    - 输入参数链表首地址
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardTraceInputPara
(
    HDLC_MNTN_EVENT_TYPE_ENUM_UINT32    ulEventType,
    VOS_UINT32                          ulLinkNodeCnt,
    HDLC_PARA_LINK_NODE_STRU           *pastLinkNodeBuf
)
{
    HDLC_MNTN_INPUT_PARA_LINK_STRU      stInputPara;
    HDLC_MNTN_INPUT_PARA_LINK_STRU     *pstInputPara = &stInputPara;
    VOS_UINT32                          ulDataLen;


    ulDataLen = sizeof(HDLC_MNTN_INPUT_PARA_LINK_STRU);

    /* 记录并上报参数链表所有节点的信息*/
    pstInputPara->ulInputLinkNodeCnt   = ulLinkNodeCnt;

    /* 参数链表每个节点的内容 */
    PPP_HDLC_HARD_MEM_CPY(&(pstInputPara->astInputParaLinkNodeBuf[0]),
                ulLinkNodeCnt * sizeof(HDLC_PARA_LINK_NODE_STRU),
                pastLinkNodeBuf,
                ulLinkNodeCnt * sizeof(HDLC_PARA_LINK_NODE_STRU));

    PPP_HDLC_HARD_MntnTraceMsg((HDLC_MNTN_TRACE_HEAD_STRU *)pstInputPara,
                               ulEventType, ulDataLen);

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardTraceFrmInput
 功能描述  : 勾取封装输入参数链表和数据
 输入参数  : pstFrmBuffInfo -   封装使用的内存
             pstBuildInfo   -   存放输入数据
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardTraceFrmInput
(
    HDLC_FRM_BUFF_INFO_STRU            *pstFrmBuffInfo,
    PPP_HDLC_HARD_FRM_PARA_STRU        *pstFrmPara
)
{
    VOS_UINT32                          ulNodeLoop;
    HDLC_PARA_LINK_NODE_STRU           *pstParaNode;
    VOS_UINT8                          *pucDataAddr;


    if (VOS_TRUE == PPP_HDLC_HARD_MntnGetConfig(PPP_HDLC_MNTN_TRACE_PARA))
    {
        PPP_Service_HdlcHardTraceInputPara(ID_HDLC_MNTN_FRM_INPUT_PARA,
                                             pstFrmPara->ulInputNodeParaCnt,
                                             &(pstFrmBuffInfo->astInputParaLinkNodeBuf[0]));
    }

    if (VOS_TRUE == PPP_HDLC_HARD_MntnGetConfig(PPP_HDLC_MNTN_TRACE_DATA))
    {
        /* 记录并上报参数链表所有节点的数据内容，每个节点是一个IP包 */
        for ( ulNodeLoop = 0; ulNodeLoop < pstFrmPara->ulInputNodeParaCnt; ulNodeLoop++ )
        {
            pstParaNode = &(pstFrmBuffInfo->astInputParaLinkNodeBuf[ulNodeLoop]);
            pucDataAddr = (VOS_UINT8*)PPP_HDLC_HARD_MEM_PHY2VIRT((VOS_UINT32)pstParaNode->pucDataAddr);
            PPP_HDLC_HARD_MntnTraceSingleData(pstParaNode->usDataLen, pucDataAddr,
                                              ID_HDLC_MNTN_FRM_INPUT_DATA, ulNodeLoop);
        }
    }

    return;
}


/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardUpdateFrmBuffInfo
 功能描述  : 更新封装内存相关信息
 输入参数  : pstFrmPara         -   封装参数
 输出参数  : 无
 返 回 值  : VOS_OK     -   更新成功
             VOS_ERR    -   更新失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Service_HdlcHardUpdateFrmBuffInfo
(
    PPP_HDLC_HARD_FRM_PARA_STRU        *pstFrmPara
)
{
    VOS_UINT32                          ulNodeParaIndex;
    HDLC_PARA_LINK_NODE_STRU           *pstParaLinkNode;
    PPP_HDLC_HARD_NODE_PARA_STRU       *pstNodePara;
    VOS_UINT32                          ulOutputSize = 0;
    PPP_HDLC_HARD_DATA_PROC_STAT_ST    *pstHdlcStat;
    HDLC_FRM_BUFF_INFO_STRU            *pstFrmBuffInfo;

    if ((pstFrmPara->ulInputNodeParaCnt > TTF_HDLC_FRM_INPUT_PARA_LINK_MAX_NUM)
        || (pstFrmPara->ulOutputNodeParaCnt > TTF_HDLC_FRM_OUTPUT_PARA_LINK_MAX_NUM))
    {
        PPP_HDLC_WARNING_LOG2("ulInputMemParaCnt or ulOutputMemParaCnt is too big",
            pstFrmPara->ulInputNodeParaCnt, pstFrmPara->ulOutputNodeParaCnt);
        return VOS_ERR;
    }

    pstFrmBuffInfo = HDLC_FRM_GET_BUF_INFO(pstFrmPara->usPppId);

    /* 更新输入链表参数 */
    for (ulNodeParaIndex = 0; ulNodeParaIndex < pstFrmPara->ulInputNodeParaCnt; ulNodeParaIndex++)
    {
        pstParaLinkNode = &pstFrmBuffInfo->astInputParaLinkNodeBuf[ulNodeParaIndex];
        pstNodePara     = &pstFrmPara->astInputNodePara[ulNodeParaIndex];
        pstParaLinkNode->pucDataAddr    = PPP_HDLC_HARD_MEM_VIRT2PHY(pstNodePara->pucDataAddr);
        pstParaLinkNode->usDataLen      = pstNodePara->usDataLen;
        pstParaLinkNode->pstNextNode = VOS_NULL_PTR;

        if (0 != ulNodeParaIndex)
        {
            pstFrmBuffInfo->astInputParaLinkNodeBuf[ulNodeParaIndex - 1].pstNextNode =
                (HDLC_PARA_LINK_NODE_STRU*)PPP_HDLC_HARD_BUF_VIRT2PHY(pstParaLinkNode);
        }
    }

    /* 更新输出链表参数 */
    for (ulNodeParaIndex = 0; ulNodeParaIndex < pstFrmPara->ulOutputNodeParaCnt; ulNodeParaIndex++)
    {
        pstParaLinkNode = &pstFrmBuffInfo->astOutputParaLinkNodeBuf[ulNodeParaIndex];
        pstNodePara     = &pstFrmPara->astOutputNodePara[ulNodeParaIndex];
        pstParaLinkNode->pucDataAddr    = PPP_HDLC_HARD_MEM_VIRT2PHY(pstNodePara->pucDataAddr);
        pstParaLinkNode->usDataLen      = pstNodePara->usDataLen;
        pstParaLinkNode->pstNextNode    = VOS_NULL_PTR;

        if (0 != ulNodeParaIndex)
        {
            pstFrmBuffInfo->astOutputParaLinkNodeBuf[ulNodeParaIndex - 1].pstNextNode =
                    (HDLC_PARA_LINK_NODE_STRU*)PPP_HDLC_HARD_BUF_VIRT2PHY(pstParaLinkNode);
        }

        ulOutputSize += pstNodePara->usDataLen;
    }

    /* 统计信息更新 */
    pstHdlcStat = PPP_HDLC_HARD_DATA_PROC_STAT;
    pstHdlcStat->ulFrmMaxInputCntOnce   = TTF_MAX(pstHdlcStat->ulFrmMaxInputCntOnce, pstFrmPara->ulInputNodeParaCnt);
    pstHdlcStat->ulFrmMaxInputSizeOnce  = TTF_MAX(pstHdlcStat->ulFrmMaxInputSizeOnce, pstFrmPara->ulInputTotalSize);
    pstHdlcStat->ulFrmMaxOutputCntOnce  = TTF_MAX(pstHdlcStat->ulFrmMaxOutputCntOnce, pstFrmPara->ulOutputNodeParaCnt);
    pstHdlcStat->ulFrmMaxOutputSizeOnce = TTF_MAX(pstHdlcStat->ulFrmMaxOutputSizeOnce, ulOutputSize);

    /* 报输入输出参数链表内容可维可测 */
    PPP_Service_HdlcHardTraceFrmInput(pstFrmBuffInfo, pstFrmPara);

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardTraceFrmOutput
 功能描述  : 勾取封装输出参数链表和数据
 输入参数  : ucFrmValidNum  -   有效帧个数
             usFrmOutSegNum -   有效帧分段个数
             pstFrmBuffInfo -   封装相关内存地址
             pstBuildInfo   -   存放输入数据
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardTraceFrmOutput
(
    VOS_UINT8                           ucFrmValidNum,
    VOS_UINT16                          usFrmOutSegNum,
    HDLC_FRM_BUFF_INFO_STRU            *pstFrmBuffInfo,
    PPP_HDLC_HARD_FRM_PARA_STRU        *pstFrmPara
)
{
    HDLC_MNTN_FRM_OUTPUT_PARA_STRU      stOutputPara;
    HDLC_MNTN_FRM_OUTPUT_PARA_STRU     *pstOutputPara = &stOutputPara;
    VOS_UINT32                          ulDataLen;
    VOS_UINT32                          ulNodeLoop;
    HDLC_PARA_LINK_NODE_STRU           *pstParaNode;
    VOS_UINT8                          *pucDataAddr;

    if (VOS_TRUE == PPP_HDLC_HARD_MntnGetConfig(PPP_HDLC_MNTN_TRACE_PARA))
    {
        ulDataLen     = sizeof(HDLC_MNTN_FRM_OUTPUT_PARA_STRU);

        pstOutputPara->ulOutputLinkNodeCnt   = pstFrmPara->ulOutputNodeParaCnt;
        pstOutputPara->ucFrmValidNum         = ucFrmValidNum;
        pstOutputPara->usOutputNodeUsedCnt   = usFrmOutSegNum;

        PPP_HDLC_HARD_MEM_CPY(&(pstOutputPara->astOutputParaLinkNodeBuf[0]),
                    TTF_HDLC_FRM_OUTPUT_PARA_LINK_MAX_NUM * sizeof(HDLC_PARA_LINK_NODE_STRU),
                   &(pstFrmBuffInfo->astOutputParaLinkNodeBuf[0]),
                   TTF_HDLC_FRM_OUTPUT_PARA_LINK_MAX_NUM * sizeof(HDLC_PARA_LINK_NODE_STRU));

        PPP_HDLC_HARD_MEM_CPY(&(pstOutputPara->astRptNodeBuf[0]),
                    TTF_HDLC_FRM_RPT_MAX_NUM * sizeof(HDLC_FRM_RPT_NODE_STRU),
                   &(pstFrmBuffInfo->astRptNodeBuf[0]),
                   TTF_HDLC_FRM_RPT_MAX_NUM * sizeof(HDLC_FRM_RPT_NODE_STRU));

        PPP_HDLC_HARD_MntnTraceMsg((HDLC_MNTN_TRACE_HEAD_STRU *)pstOutputPara,
                                        ID_HDLC_MNTN_FRM_OUTPUT_PARA, ulDataLen);
    }

    if (VOS_TRUE == PPP_HDLC_HARD_MntnGetConfig(PPP_HDLC_MNTN_TRACE_DATA))
    {
        for ( ulNodeLoop = 0; ulNodeLoop < usFrmOutSegNum; ulNodeLoop++ )
        {
            pstParaNode = &(pstFrmBuffInfo->astOutputParaLinkNodeBuf[ulNodeLoop]);
            pucDataAddr = (VOS_UINT8*)PPP_HDLC_HARD_MEM_PHY2VIRT((VOS_UINT32)pstParaNode->pucDataAddr);
            PPP_HDLC_HARD_MntnTraceSingleData(pstParaNode->usDataLen, pucDataAddr,
                                              ID_HDLC_MNTN_FRM_OUTPUT_DATA, ulNodeLoop);
        }
    }

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardFrmResultProc
 功能描述  : 处理硬件封装结果
 输入参数  : pstFrmPara     -   封装参数
 输出参数  : pstFrmResult   -   封装结果信息
 返 回 值  : PPP_HDLC_HARD_PROC_RESULT_ENUM_UINT32  封装处理结果
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
PPP_HDLC_HARD_PROC_RESULT_ENUM_UINT32 PPP_Service_HdlcHardFrmResultProc
(
    PPP_HDLC_HARD_FRM_PARA_STRU        *pstFrmPara,
    PPP_HDLC_HARD_FRM_RESULT_STRU      *pstFrmResult
)
{
    VOS_UINT16                          usFrmOutSegNum = 0;
    VOS_UINT8                           ucFrmValidNum = 0;
    VOS_UINT8                           ucRptSpaceIndex;
    VOS_UINT32                          ulOutputLinkIndex = 0;
    VOS_UINT8                          *pucFrmOutAddr;
    VOS_UINT16                          usFrmOutLen;
    HDLC_FRM_BUFF_INFO_STRU            *pstFrmBuffInfo;
    HDLC_PARA_LINK_NODE_STRU           *pstOutputParaLink;
    HDLC_FRM_RPT_NODE_STRU             *pstFrmRptNodeStru;

    PPP_Driver_HdlcHardGetFrmResult(&usFrmOutSegNum, &ucFrmValidNum);

    pstFrmBuffInfo     = HDLC_FRM_GET_BUF_INFO(pstFrmPara->usPppId);       /* 根据usPppId找到对应的内存  */

    /* 上报封装后数据可维可测:上报空间信息、输出链表内容 */
    PPP_Service_HdlcHardTraceFrmOutput(ucFrmValidNum, usFrmOutSegNum, pstFrmBuffInfo, pstFrmPara);

    /* ucFrmValidNum肯定要小于等于使用的内存块数usFrmOutSegNum */
    if( ucFrmValidNum > usFrmOutSegNum )
    {
        PPP_HDLC_WARNING_LOG2("frm_valid_num > usFrmOutSegNum", ucFrmValidNum, usFrmOutSegNum);
        return PPP_HDLC_HARD_PROC_FAIL;
    }

    /* ucFrmValidNum应该与输入数据相同ulInputLinkNodeCnt，如果解封装出错可能会比后者小 */
    if( ucFrmValidNum > pstFrmPara->ulInputNodeParaCnt)
    {
        PPP_HDLC_WARNING_LOG2("frm_valid_num > ulInputNodeParaCnt", ucFrmValidNum, pstFrmPara->ulInputNodeParaCnt);
        return PPP_HDLC_HARD_PROC_FAIL;
    }


    /* usFrmOutSegNum使用的内存块数肯定小于等于ulOutputLinkNodeCnt */
    if( usFrmOutSegNum  > pstFrmPara->ulOutputNodeParaCnt)
    {
        PPP_HDLC_WARNING_LOG2("frm_out_seg_num > ulOutputMemParaCnt", usFrmOutSegNum, pstFrmPara->ulOutputNodeParaCnt);
        return PPP_HDLC_HARD_PROC_FAIL;
    }

    pstFrmRptNodeStru  = &(pstFrmBuffInfo->astRptNodeBuf[0]);              /* 封装上报空间首地址 */
    pstOutputParaLink  = &(pstFrmBuffInfo->astOutputParaLinkNodeBuf[0]);   /* 封装输出链表首地址 */
    for (ucRptSpaceIndex = 0; ucRptSpaceIndex < ucFrmValidNum; ucRptSpaceIndex++)
    {
        pucFrmOutAddr    = pstFrmRptNodeStru[ucRptSpaceIndex].pucFrmOutOneAddr;
        usFrmOutLen      = pstFrmRptNodeStru[ucRptSpaceIndex].usFrmOutOneLen;
        /* 封装后的长度为0或者大于封装输出最大长度的话都是异常，不能继续处理后边报文 */
        if ( (0 == usFrmOutLen) || (HDLC_FRM_OUT_PER_MAX_CNT < usFrmOutLen) )
        {
            PPP_HDLC_WARNING_LOG1("invalid usFrmOutOneLen", usFrmOutLen);
            pstFrmResult->ucFrmValidCnt = ucRptSpaceIndex;
            return PPP_HDLC_HARD_PROC_PART_SUCC;
        }

        /* 封装上报结果的地址和封装输出结果地址不一致时已经异常，不能继续处理后边报文 */
        pstOutputParaLink = &(pstFrmBuffInfo->astOutputParaLinkNodeBuf[ulOutputLinkIndex]);
        if( pucFrmOutAddr != pstOutputParaLink->pucDataAddr)
        {
            PPP_HDLC_WARNING_LOG(" SOC copy error!");
            pstFrmResult->ucFrmValidCnt= ucRptSpaceIndex;
            return PPP_HDLC_HARD_PROC_PART_SUCC;
        }

        pstFrmResult->astFrmResultNode[ucRptSpaceIndex].usDataLen = usFrmOutLen;
        pstFrmResult->astFrmResultNode[ucRptSpaceIndex].pucDataAddr = PPP_HDLC_HARD_MEM_PHY2VIRT(pucFrmOutAddr);

        /* 封装后的长度大于封装输出节点的数据长度说明该封装后的结果占用了两个输出节点 */
        ulOutputLinkIndex++;
        if (usFrmOutLen > pstOutputParaLink->usDataLen)
        {
            ulOutputLinkIndex++;
        }
    }

    pstFrmResult->ucFrmValidCnt = ucRptSpaceIndex;

    return PPP_HDLC_HARD_PROC_ALL_SUCC;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardFrmProcException
 功能描述  : 封装硬件异常处理
 输入参数  : ulStatus           -   封装寄存器状态
             ulEnableInterrupt  -   是否使用中断方式
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardFrmProcException
(
    VOS_UINT32                          ulStatus,
    VOS_UINT32                          ulEnableInterrupt
)
{
    VOS_UINT32                          ulRawInt;

    if( VOS_TRUE == ulEnableInterrupt )
    {
        /* 由于在中断服务程序中进行了清中断操作，故此处取保存在g_stHdlcRegSaveInfo中的原始中断寄存器值 */
        ulRawInt                        =   g_stHdlcRegSaveInfo.ulHdlcFrmRawInt;
        g_PppHdlcHardStat.usFrmExpInfo |=   (1 << HDLC_INTERRUPT_IND_BITPOS);
    }
    else
    {
        ulRawInt  =   PPP_Driver_HdlcHardGetFrmRawInt();
    }

    PPP_HDLC_ERROR_LOG2("Frm Exception ocurr", ulStatus, ulRawInt);

    g_PppHdlcHardStat.usFrmExpInfo |=   (1 << HDLC_EXCEPTION_IND_BITPOS);

    PPP_Driver_HdlcHardShowFrmReg();
    PPP_Driver_HdlcHardShowDefReg();
    PPP_Driver_HdlcHardShowConfigInfo();

    /* 复位前先Delay 1s保证可维可测正常输出 */
    VOS_TaskDelay(1000);

    /* 如果HDLC出现异常，则单板异常重启 */
    mdrv_om_system_error(HDLC_FRM_SYSTEM_ERROR_ID, __LINE__, (VOS_INT)ulStatus,
                         (VOS_CHAR *)&g_stHdlcRegSaveInfo,
                         sizeof(HDLC_REG_SAVE_INFO_STRU));

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardBuildFrmPara
 功能描述  : 构造硬件封装参数
 输入参数  : pstFrmPara         -   业务模块提供的封装参数
 输出参数  : pstDrvFrmPara      -   硬件使用的封装参数
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardBuildFrmPara
(
    PPP_HDLC_HARD_FRM_PARA_STRU        *pstFrmPara,
    PPP_DRIVER_HDLC_HARD_FRM_PARA_STRU *pstDrvFrmPara
)
{
    VOS_UINT32                          ulAccmFlag = 0xFFFFFFFF;

    /* 内部调用，保证入参非空 */

    /*  IP模式一定添加P域,PPP模式一定不添加P域
      LCP帧: AC域不压缩，P域不压缩 */
    if (PPP_SERVICE_HDLC_HARD_IP_MODE == pstFrmPara->enPppMode)
    {
        if (PPP_SERVICE_HDLC_HARD_LCP != pstFrmPara->usProtocol)
        {
            if ( 1 == pstFrmPara->ulPppAcFlag )
            {
                pstDrvFrmPara->ulPppAcFlag = HDLC_ADDRESS_CTRL_COMPRESS;
            }

            if ( 1 == pstFrmPara->ulPppPcFlag )
            {
                pstDrvFrmPara->ulPppPcFlag = HDLC_PROTOCOL_ADD_WITH_COMPRESS;
            }

            ulAccmFlag = pstFrmPara->ulAccmFlag;
        }
    }
    else
    {
        if (PPP_SERVICE_HDLC_HARD_LCP != pstFrmPara->usProtocol)
        {
            if ( 1 == pstFrmPara->ulPppAcFlag )
            {
                pstDrvFrmPara->ulPppAcFlag = HDLC_ADDRESS_CTRL_COMPRESS;
            }
        }
        pstDrvFrmPara->ulPppPcFlag = HDLC_PROTOCOL_NO_ADD;
    }

    pstDrvFrmPara->usProtocol = pstFrmPara->usProtocol;
    pstDrvFrmPara->ulAccmFlag   = ulAccmFlag;
    pstDrvFrmPara->ulInputTotalSize = pstFrmPara->ulInputTotalSize;

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardFrmPacket
 功能描述  : 硬件封装报文
 输入参数  : pstFrmPara         -   业务模块提供的封装参数
 输出参数  : pstFrmResult   -  封装结果信息
 返 回 值  : PPP_HDLC_HARD_PROC_RESULT_ENUM_UINT32 封装处理结果
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
PPP_HDLC_HARD_PROC_RESULT_ENUM_UINT32 PPP_Service_HdlcHardFrmPacket
(
    PPP_HDLC_HARD_FRM_PARA_STRU        *pstFrmPara,
    PPP_HDLC_HARD_FRM_RESULT_STRU      *pstFrmResult
)
{
    VOS_UINT32                          ulEnableInterrupt = 0;
    VOS_UINT32                          ulCheckParaResutl;
    VOS_UINT32                          ulFrmStatus;
    VOS_UINT32                          ulFrmResult;
    PPP_DRIVER_HDLC_HARD_FRM_PARA_STRU  stDrvFrmPara;


    if ((VOS_NULL_PTR == pstFrmPara) || (VOS_NULL_PTR == pstFrmResult))
    {
        PPP_HDLC_WARNING_LOG("pstFrmPara is NULL");
        return PPP_HDLC_HARD_PROC_PARA_ERR;
    }

    ulCheckParaResutl = PPP_Service_HdlcHardUpdateFrmBuffInfo(pstFrmPara);
    if (VOS_ERR == ulCheckParaResutl)
    {
        return PPP_HDLC_HARD_PROC_PARA_ERR;
    }

    PPP_HDLC_HARD_MEM_SET(&stDrvFrmPara, sizeof(PPP_DRIVER_HDLC_HARD_FRM_PARA_STRU),
                          0x00, sizeof(PPP_DRIVER_HDLC_HARD_FRM_PARA_STRU));
    PPP_Service_HdlcHardBuildFrmPara(pstFrmPara, &stDrvFrmPara);

    ulFrmStatus = PPP_Driver_HdlcHardFrmEnable(&stDrvFrmPara, &ulEnableInterrupt);

    /* 使能中断，则等待中断辅程序释放信号量；否则轮询解封装状态寄存器 */
    if ( HDLC_FRM_ALL_PKT_DONE != ulFrmStatus )
    {
        /* 寄存器状态异常时需要复位 */
        PPP_Service_HdlcHardFrmProcException(ulFrmStatus, ulEnableInterrupt);
        return PPP_HDLC_HARD_PROC_STATUS_ERR;
    }

    ulFrmResult = PPP_Service_HdlcHardFrmResultProc(pstFrmPara, pstFrmResult);

    return ulFrmResult;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardTraceDefInput
 功能描述  : 勾取解封装输入参数链表和数据
 输入参数  : pstFrmBuffInfo -   封装使用的内存
             pstBuildInfo   -   存放输入数据
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardTraceDefInput
(
    PPP_HDLC_HARD_DEF_PARA_STRU        *pstDefPara,
    HDLC_DEF_BUFF_INFO_STRU            *pstDefBuffInfo
)
{
    VOS_UINT32                          ulNodeLoop;
    HDLC_PARA_LINK_NODE_STRU           *pstParaNode;
    VOS_UINT8                          *pucDataAddr;


    if (VOS_TRUE == PPP_HDLC_HARD_MntnGetConfig(PPP_HDLC_MNTN_TRACE_PARA))
    {
        PPP_Service_HdlcHardTraceInputPara(ID_HDLC_MNTN_DEF_INPUT_PARA,
                                             pstDefPara->ulInputNodeParaCnt,
                                             &(pstDefBuffInfo->astInputParaLinkNodeBuf[0]));
    }

    if (VOS_TRUE == PPP_HDLC_HARD_MntnGetConfig(PPP_HDLC_MNTN_TRACE_DATA))
    {
        /* 记录并上报参数链表所有节点的数据内容，每个节点是一个IP包 */
        for ( ulNodeLoop = 0; ulNodeLoop < pstDefPara->ulInputNodeParaCnt; ulNodeLoop++ )
        {
            pstParaNode = &(pstDefBuffInfo->astInputParaLinkNodeBuf[ulNodeLoop]);

            pucDataAddr = (VOS_UINT8*)PPP_HDLC_HARD_MEM_PHY2VIRT((VOS_UINT32)pstParaNode->pucDataAddr);
            PPP_HDLC_HARD_MntnTraceSingleData(pstParaNode->usDataLen, pucDataAddr,
                            ID_HDLC_MNTN_DEF_INPUT_DATA, ulNodeLoop);
        }
    }

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardUpdateDefBuffInfo
 功能描述  : 更新解封装内存相关信息
 输入参数  : pstDefPara         -   解封装参数
 输出参数  : 无
 返 回 值  : VOS_OK     -   更新成功
             VOS_ERR    -   更新失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Service_HdlcHardUpdateDefBuffInfo
(
    PPP_HDLC_HARD_DEF_PARA_STRU        *pstDefPara
)
{
    VOS_UINT32                          ulNodeParaIndex;
    HDLC_PARA_LINK_NODE_STRU           *pstParaLinkNode;
    PPP_HDLC_HARD_NODE_PARA_STRU       *pstNodePara;
    PPP_HDLC_HARD_DATA_PROC_STAT_ST    *pstHdlcStat;
    HDLC_DEF_BUFF_INFO_STRU            *pstDefBuffInfo;

    if (pstDefPara->ulInputNodeParaCnt > TTF_HDLC_DEF_INPUT_PARA_LINK_MAX_NUM)
    {
        PPP_HDLC_WARNING_LOG1("ulInputMemParaCnt is too big", pstDefPara->ulInputNodeParaCnt);
        return VOS_ERR;
    }

    pstDefBuffInfo = HDLC_DEF_GET_BUF_INFO(pstDefPara->usPppId);

    /* 更新输入链表参数 */
    for (ulNodeParaIndex = 0; ulNodeParaIndex < pstDefPara->ulInputNodeParaCnt; ulNodeParaIndex++)
    {
        pstParaLinkNode = &pstDefBuffInfo->astInputParaLinkNodeBuf[ulNodeParaIndex];
        pstNodePara     = &pstDefPara->astInputNodePara[ulNodeParaIndex];
        pstParaLinkNode->pucDataAddr    = PPP_HDLC_HARD_MEM_VIRT2PHY(pstNodePara->pucDataAddr);
        pstParaLinkNode->usDataLen      = pstNodePara->usDataLen;
        pstParaLinkNode->pstNextNode = VOS_NULL_PTR;

        if (0 != ulNodeParaIndex)
        {
            pstDefBuffInfo->astInputParaLinkNodeBuf[ulNodeParaIndex - 1].pstNextNode =
                    (HDLC_PARA_LINK_NODE_STRU*)PPP_HDLC_HARD_BUF_VIRT2PHY(pstParaLinkNode);
        }
    }

    /* 统计信息更新 */
    pstHdlcStat = PPP_HDLC_HARD_DATA_PROC_STAT;
    pstHdlcStat->ulDefMaxInputCntOnce   = TTF_MAX(pstHdlcStat->ulDefMaxInputCntOnce, pstDefPara->ulInputNodeParaCnt);
    pstHdlcStat->ulDefMaxInputSizeOnce  = TTF_MAX(pstHdlcStat->ulDefMaxInputSizeOnce, pstDefPara->ulInputTotalSize);

    /* 上报输入参数链表内容可维可测 */
    PPP_Service_HdlcHardTraceDefInput(pstDefPara, pstDefBuffInfo);

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardBuildDefPara
 功能描述  : 构造硬件解封装参数
 输入参数  : pstDefPara         -   业务模块提供的解封装参数
 输出参数  : pstDrvDefPara      -   硬件使用的解封装参数
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardBuildDefPara
(
    PPP_HDLC_HARD_DEF_PARA_STRU        *pstDefPara,
    PPP_DRIVER_HDLC_HARD_DEF_PARA_STRU *pstDrvDefPara
)
{
    PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU *pstUncompleteInfo;

    /* 内部调用，保证入参非空 */
    pstUncompleteInfo = HDLC_DEF_GET_UNCOMPLETED_INFO(pstDefPara->usPppId);

    pstDrvDefPara->ulInputTotalSize = pstDefPara->ulInputTotalSize;


    /* IP模式下不合入协议域，PPP模式下合入 */
    if (PPP_SERVICE_HDLC_HARD_IP_MODE == pstDefPara->enPppMode)
    {
        if (1 == pstDefPara->ulPppPcFlag)
        {
            pstDrvDefPara->ulPppPcFlag = HDLC_PROTOCOL_REMOVE_WITH_COMPRESS;
        }
    }
    else
    {
        pstDrvDefPara->ulPppPcFlag = HDLC_PROTOCOL_NO_REMOVE;
    }

    if (1 == pstDefPara->ulPppAcFlag)
    {
        pstDrvDefPara->ulPppAcFlag = HDLC_ADDRESS_CTRL_COMPRESS;
    }

    pstDrvDefPara->pstUncompleteInfo = pstUncompleteInfo;

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardTraceDefOutput
 功能描述  : 勾取解封装输出数据
 输入参数  : pstBuildInfo    -   存放输入数据
             usValidFrameNum -   有效帧个数
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月10日
    作    者   : l00164359
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardTraceDefOutput
(
    VOS_UINT16                          usValidFrameNum,
    HDLC_DEF_BUFF_INFO_STRU            *pstDefBuffInfo
)
{
    HDLC_MNTN_DEF_OUTPUT_PARA_STRU     *pstOutputPara;
    VOS_UINT32                          ulDataLen;
    VOS_UINT32                          ulNodeLoop;
    HDLC_DEF_RPT_NODE_STRU             *pstRptNode;
    VOS_UINT16                          usMaxFrameNum;
    VOS_UINT8                          *pucDataAddr;


    /* 解封装上报空间可维可测 */
    if (VOS_TRUE == PPP_HDLC_HARD_MntnGetConfig(PPP_HDLC_MNTN_TRACE_PARA))
    {
        usMaxFrameNum = (HDLC_MNTN_ALLOC_MEM_MAX_SIZE - sizeof(HDLC_MNTN_DEF_OUTPUT_PARA_STRU)) /
                         sizeof(HDLC_DEF_RPT_NODE_STRU);
        usMaxFrameNum = TTF_MIN(usMaxFrameNum, usValidFrameNum);

        ulDataLen     = sizeof(HDLC_MNTN_DEF_OUTPUT_PARA_STRU) + usMaxFrameNum * sizeof(HDLC_DEF_RPT_NODE_STRU);
        pstOutputPara = (HDLC_MNTN_DEF_OUTPUT_PARA_STRU *)PS_MEM_ALLOC(PS_PID_PPP_HDLC, ulDataLen);

        if (VOS_NULL_PTR == pstOutputPara)
        {
            PPP_HDLC_WARNING_LOG1("PPP_HDLC_HARD_MntnDefTraceOutput, NORMAL, Alloc mem failed ulDataLen %d!\r\n", ulDataLen);
            return;
        }

        pstOutputPara->usDefValidNum = usValidFrameNum;
        pstOutputPara->usTraceNum    = usMaxFrameNum;

        PPP_HDLC_HARD_MEM_CPY((VOS_UINT8 *)(pstOutputPara + 1),
                    usMaxFrameNum * sizeof(HDLC_DEF_RPT_NODE_STRU),
                   (VOS_UINT8 *)(&(pstDefBuffInfo->astRptNodeBuf[0])),
                   usMaxFrameNum * sizeof(HDLC_DEF_RPT_NODE_STRU));

        PPP_HDLC_HARD_MntnTraceMsg((HDLC_MNTN_TRACE_HEAD_STRU *)pstOutputPara,
                                   ID_HDLC_MNTN_DEF_OUTPUT_PARA, ulDataLen);

        PS_MEM_FREE(PS_PID_PPP_HDLC, pstOutputPara);
    }

    /* 解封装目的空间中每个有效帧可维可测 */
    if (VOS_TRUE == PPP_HDLC_HARD_MntnGetConfig(PPP_HDLC_MNTN_TRACE_DATA))
    {
        for ( ulNodeLoop = 0; ulNodeLoop < usValidFrameNum; ulNodeLoop++ )
        {
            pstRptNode = &(pstDefBuffInfo->astRptNodeBuf[ulNodeLoop]);
            pucDataAddr = PPP_HDLC_HARD_BUF_PHY2VIRT(pstRptNode->pucDefOutOneAddr);
            PPP_HDLC_HARD_MntnTraceSingleData(pstRptNode->usDefOutOneLen, pucDataAddr,
                                              ID_HDLC_MNTN_DEF_OUTPUT_DATA, ulNodeLoop);
        }
    }

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardProcDefResult
 功能描述  : 处理硬件封装结果
 输入参数  : pstDefPara     -   业务模块提供的解封装参数
             pstErrCnt      -   解封装处理错误信息
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardProcDefResult
(
    PPP_HDLC_HARD_DEF_PARA_STRU                    *pstDefPara,
    PPP_DRIVER_HDLC_HARD_DEF_ERR_FRAMES_CNT_STRU   *pstErrCnt
)
{
    VOS_UINT16                          usValidFrameNum;
    HDLC_DEF_BUFF_INFO_STRU            *pstDefBuffInfo;
    VOS_UINT32                          ulFrameLoop;
    HDLC_DEF_RPT_NODE_STRU             *pstRptNode;
    PPP_HDLC_HARD_DEF_RESULT_STRU       stDefResult;
    VOS_UINT16                          usDefOutLen;
    VOS_UINT8                          *pucDefOutOneAddr;
    VOS_UINT16                          usFistSegLen;

    pstDefBuffInfo  = HDLC_DEF_GET_BUF_INFO(pstDefPara->usPppId);
    usValidFrameNum = PPP_Driver_HdlcHardGetDefVaildNum();

    PPP_HDLC_HARD_MEM_SET(&stDefResult, sizeof(PPP_HDLC_HARD_DEF_RESULT_STRU),
                 0x00, sizeof(PPP_HDLC_HARD_DEF_RESULT_STRU));

    /* 上报解封装后数据可维可测:上报空间信息、输出内容 */
    PPP_Service_HdlcHardTraceDefOutput(usValidFrameNum, pstDefBuffInfo);

    /* 有效帧数最大值检查 */
    if (TTF_HDLC_DEF_RPT_MAX_NUM < usValidFrameNum)
    {
        PPP_HDLC_WARNING_LOG2("PPP_HDLC_HARD_DefProcValidFrames, WARNING, usValidFrameNum = %d > TTF_HDLC_DEF_RPT_MAX_NUM = %d",
                      usValidFrameNum, TTF_HDLC_DEF_RPT_MAX_NUM);
        return;
    }

    g_PppHdlcHardStat.ulDefMaxValidCntOnce = TTF_MAX(g_PppHdlcHardStat.ulDefMaxValidCntOnce, usValidFrameNum);

    stDefResult.usPppId             = pstDefPara->usPppId;
    stDefResult.ulPara              = pstDefPara->ulPara;

    for ( ulFrameLoop = 0 ; ulFrameLoop < usValidFrameNum; ulFrameLoop++ )
    {
        pstRptNode = &(pstDefBuffInfo->astRptNodeBuf[ulFrameLoop]);
        usDefOutLen = pstRptNode->usDefOutOneLen;
        if ( (0 == usDefOutLen) || (HDLC_DEF_OUT_PER_MAX_CNT < usDefOutLen) )
        {
            PPP_HDLC_WARNING_LOG1("invalid usDefOutOneLen", usDefOutLen);
            continue;
        }

        pucDefOutOneAddr = PPP_HDLC_HARD_BUF_PHY2VIRT(pstRptNode->pucDefOutOneAddr);

        /* 判断该帧起始加长度是否超过输出空间尾部，超出后按绕回处理 */
        if ((pucDefOutOneAddr + usDefOutLen) > HDLC_DEF_OUTPUT_BUF_END_ADDR)
        {
            if (pucDefOutOneAddr <= HDLC_DEF_OUTPUT_BUF_END_ADDR)
            {
                usFistSegLen = (VOS_UINT16)(HDLC_DEF_OUTPUT_BUF_END_ADDR - pucDefOutOneAddr);
                stDefResult.enSegment = PS_TRUE;
                stDefResult.astDataInfo[0].pucDataAddr = pucDefOutOneAddr;
                stDefResult.astDataInfo[0].usDataLen = usFistSegLen;
                stDefResult.astDataInfo[1].pucDataAddr = HDLC_DEF_OUTPUT_BUF_START_ADDR;
                stDefResult.astDataInfo[1].usDataLen = usDefOutLen - usFistSegLen;
            }
            else
            {
                PPP_HDLC_WARNING_LOG2("Def Result Proc Err", pucDefOutOneAddr, HDLC_DEF_OUTPUT_BUF_END_ADDR);
                continue;
            }
        }
        else
        {
            stDefResult.enSegment = PS_FALSE;
            stDefResult.astDataInfo[0].pucDataAddr = pucDefOutOneAddr;
            stDefResult.astDataInfo[0].usDataLen = usDefOutLen;
        }
        stDefResult.usProtocol = pstRptNode->usDefOutOnePro;
        PPP_SERVICE_HDLC_HARD_DEF_RES_PROC(&stDefResult);
    }

    PPP_SERVICE_HDLC_HARD_DEF_ERR_PROC(pstDefPara->usPppId, pstErrCnt);

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardDefSaveUncompleteInfo
 功能描述  : 保存解封装非完整帧信息
 输入参数  : usPppId        -   PPP ID
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardDefSaveUncompleteInfo
(
    VOS_UINT16                          usPppId
)
{
    PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU *pstUncompleteInfo;
    HDLC_DEF_BUFF_INFO_STRU            *pstDefBuffInfo;
    VOS_UINT32                          ulValidNum = 0;
    VOS_UINT8                          *pucDefOutOneAddr;
    HDLC_DEF_RPT_NODE_STRU             *pstRptNode;
    HDLC_MNTN_DEF_UNCOMPLETED_INFO_STRU stMntnUncompletedInfo;

    pstUncompleteInfo = HDLC_DEF_GET_UNCOMPLETED_INFO(usPppId);
    pstDefBuffInfo    = HDLC_DEF_GET_BUF_INFO(usPppId);

    PPP_Driver_HdlcHardGetDefUncompletInfo(pstUncompleteInfo, &ulValidNum);

    if (HDLC_DEF_UNCOMPLETED_NOT_EXIST == pstUncompleteInfo->ucExistFlag)
    {
        return;
    }

    if (VOS_TRUE == PPP_HDLC_HARD_MntnGetConfig(PPP_HDLC_MNTN_TRACE_PARA))
    {
        /* 勾取解封装输出的非完整帧信息 */
        PPP_HDLC_HARD_MEM_CPY(&stMntnUncompletedInfo.stUncompletedInfo,
                    sizeof(PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU),
                    pstUncompleteInfo, sizeof(PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU));

        PPP_HDLC_HARD_MntnTraceMsg((HDLC_MNTN_TRACE_HEAD_STRU *)&stMntnUncompletedInfo,
                                   ID_HDLC_MNTN_DEF_UNCOMPLETED_INFO,
                                   sizeof(HDLC_MNTN_DEF_UNCOMPLETED_INFO_STRU));
    }


    /* 非完整帧的上报信息在有效帧后面，但是不算在有效帧数目内 */
    if (TTF_HDLC_DEF_RPT_MAX_NUM <= ulValidNum)
    {
        PPP_HDLC_WARNING_LOG2("ulValidNum >= TTF_HDLC_DEF_RPT_MAX_NUM ",
                     ulValidNum, TTF_HDLC_DEF_RPT_MAX_NUM);

        pstUncompleteInfo->ucExistFlag = HDLC_DEF_UNCOMPLETED_NOT_EXIST;

        return;
    }


    pstRptNode = &(pstDefBuffInfo->astRptNodeBuf[ulValidNum]);

    pucDefOutOneAddr = PPP_HDLC_HARD_BUF_PHY2VIRT(pstRptNode->pucDefOutOneAddr);

    if (pucDefOutOneAddr != HDLC_DEF_OUTPUT_BUF_START_ADDR)
    {
        if ((pucDefOutOneAddr - HDLC_DEF_OUTPUT_BUF_START_ADDR) >= pstRptNode->usDefOutOneLen)
        {
            PPP_HDLC_HARD_MEM_CPY(HDLC_DEF_OUTPUT_BUF_START_ADDR, TTF_HDLC_DEF_OUTPUT_DATA_BUF_LEN,
                    pucDefOutOneAddr, pstRptNode->usDefOutOneLen);
        }
        else
        {
            VOS_MemMove_s(HDLC_DEF_OUTPUT_BUF_START_ADDR, TTF_HDLC_DEF_OUTPUT_DATA_BUF_LEN,
                          pucDefOutOneAddr, pstRptNode->usDefOutOneLen);
        }

        pstRptNode->pucDefOutOneAddr = PPP_HDLC_HARD_BUF_VIRT2PHY(HDLC_DEF_OUTPUT_BUF_START_ADDR);

    }

    /* 非完整帧的协议、长度和在存储空间的地址，软件只是暂存这些信息，等下解封装的时候再原样配给HDLC */
    pstUncompleteInfo->usDefOutOnePro   = pstRptNode->usDefOutOnePro;
    pstUncompleteInfo->usDefOutOneLen   = pstRptNode->usDefOutOneLen;
    pstUncompleteInfo->pucDefOutOneAddr = pstRptNode->pucDefOutOneAddr;

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardDefProcException
 功能描述  : 解封装硬件异常处理
 输入参数  : ulStatus           -   解封装寄存器状态
             ulEnableInterrupt  -   是否使用中断方式
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardDefProcException
(
    VOS_UINT32          ulStatus,
    VOS_UINT32          ulEnableInterrupt
)
{
    VOS_UINT32                          ulRawInt;


    if( VOS_TRUE == ulEnableInterrupt )
    {
        /* 由于在中断服务程序中进行了清中断操作，故此处取保存在g_stHdlcRegSaveInfo中的原始中断寄存器值 */
        ulRawInt                        =   g_stHdlcRegSaveInfo.ulHdlcDefRawInt;
        g_PppHdlcHardStat.usDefExpInfo |=   (1 << HDLC_INTERRUPT_IND_BITPOS);
    }
    else
    {
        ulRawInt  =   PPP_Driver_HdlcHardGetDefRawInt();
    }

    PPP_HDLC_ERROR_LOG2("Def Exception ocurr", ulStatus, ulRawInt);

    g_PppHdlcHardStat.usDefExpInfo |=   (1 << HDLC_EXCEPTION_IND_BITPOS);

    PPP_Driver_HdlcHardShowFrmReg();
    PPP_Driver_HdlcHardShowDefReg();
    PPP_Driver_HdlcHardShowConfigInfo();

    /* 复位前先Delay 1s保证可维可测正常输出 */
    VOS_TaskDelay(1000);

    /* 如果HDLC出现异常，则单板异常重启 */
    mdrv_om_system_error(HDLC_DEF_SYSTEM_ERROR_ID, __LINE__, (VOS_INT)ulStatus,
                         (VOS_CHAR *)&g_stHdlcRegSaveInfo,
                         sizeof(HDLC_REG_SAVE_INFO_STRU));

    return;
}


/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardDefWaitAndProc
 功能描述  : 等待解封装暂停或完成，然后处理输出数据，可能会有多次停等的过程
 输入参数  : ulEnableInterrupt  -   中断是否使能
             pstDrvDefPara      -   硬件解封装参数
             pstDefPara         -   业务模块提供的解封装参数
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PPP_Service_HdlcHardDefWaitAndProc
(
    VOS_UINT32                          ulEnableInterrupt,
    PPP_DRIVER_HDLC_HARD_DEF_PARA_STRU *pstDrvDefPara,
    PPP_HDLC_HARD_DEF_PARA_STRU        *pstDefPara
)
{
    VOS_UINT32                          ulDefStatus;
    VOS_UINT32                          ulContinue;
    PPP_DRIVER_HDLC_HARD_DEF_ERR_FRAMES_CNT_STRU    stErrCnt;

    PPP_HDLC_HARD_MEM_SET(&stErrCnt, sizeof(PPP_DRIVER_HDLC_HARD_DEF_ERR_FRAMES_CNT_STRU),
                          0x00, sizeof(PPP_DRIVER_HDLC_HARD_DEF_ERR_FRAMES_CNT_STRU));

    for (; ;)
    {
        /* 使能中断，则等待中断辅程序释放信号量；否则轮询解封装状态寄存器 */
        ulDefStatus = PPP_Driver_HdlcHardDefWaitResult(ulEnableInterrupt);

        switch ( ulDefStatus )
        {
            case HDLC_DEF_STATUS_PAUSE_RPT_SPACE_FULL :
            case HDLC_DEF_STATUS_PAUSE_OUTPUT_SPACE_FULL :
                /* 处理有效帧，配置GO_ON寄存器 */
                PPP_Service_HdlcHardProcDefResult(pstDefPara, VOS_NULL_PTR);
                PPP_Driver_HdlcHardDefCfgGoOnReg(ulDefStatus);

                ulContinue = VOS_TRUE;
                g_PppHdlcHardStat.ulDefFullPauseCnt++;
                break;
            case HDLC_DEF_STATUS_PAUSE_LCP :
                /* 处理有效帧和LCP帧，更新配置寄存器，配置GO_ON寄存器 */
                PPP_Service_HdlcHardProcDefResult(pstDefPara, VOS_NULL_PTR);
                pstDrvDefPara->pstUncompleteInfo = VOS_NULL_PTR;
                PPP_Driver_HdlcHardDefCfgReg(pstDrvDefPara);
                PPP_Driver_HdlcHardDefCfgGoOnReg(ulDefStatus);

                ulContinue = VOS_TRUE;
                g_PppHdlcHardStat.ulDefLcpPauseCnt++;
                break;
            case HDLC_DEF_STATUS_DONE_WITHOUT_FRAMES :
                /* 根据非完整帧指示，保存非完整帧信息 */
                PPP_Service_HdlcHardDefSaveUncompleteInfo(pstDefPara->usPppId);

                ulContinue = VOS_FALSE;
                break;
            case HDLC_DEF_STATUS_DONE_WITH_FRAMES :
                /* 处理有效帧、错误帧和LCP帧(可能是最后一帧)，根据非完整帧指示，保存非完整帧信息 */
                PPP_Driver_HdlcHardGetDefErrorInfo(&stErrCnt);
                PPP_Service_HdlcHardProcDefResult(pstDefPara, &stErrCnt);
                PPP_Service_HdlcHardDefSaveUncompleteInfo(pstDefPara->usPppId);
                ulContinue = VOS_FALSE;
                break;
            case HDLC_DEF_STATUS_DOING :
            default:
                /* 打印异常日志，挂起PPP任务 */
                PPP_Service_HdlcHardDefProcException(ulDefStatus, ulEnableInterrupt);

                ulContinue = VOS_FALSE;
                break;
        }

        /* 暂停状态需要继续处理，其他状态解封装完成退出 */
        if (VOS_TRUE != ulContinue)
        {
            break;
        }
    }

    g_stHdlcRegSaveInfo.ulHdlcDefRawInt = 0xFFFFFFFFU;
    g_stHdlcRegSaveInfo.ulHdlcDefStatus = 0xFFFFFFFFU;

    return;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardDefPacket
 功能描述  : 硬件方式IP类型解封装
 输入参数  : pstDefPara     -   业务模块提供的解封装参数
 输出参数  : 无
 返 回 值  : PPP_HDLC_HARD_PROC_RESULT_ENUM_UINT32  硬件解封装处理结果
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
PPP_HDLC_HARD_PROC_RESULT_ENUM_UINT32 PPP_Service_HdlcHardDefPacket
(
    PPP_HDLC_HARD_DEF_PARA_STRU        *pstDefPara
)
{
    VOS_UINT32                          ulEnableInterrupt = 0;
    VOS_UINT32                          ulUpdDefBufResutl;
    PPP_DRIVER_HDLC_HARD_DEF_PARA_STRU  stDrvDefPara;

    if (VOS_NULL_PTR == pstDefPara)
    {
        PPP_HDLC_WARNING_LOG("pstFrmPara is NULL");
        return PPP_HDLC_HARD_PROC_PARA_ERR;
    }

    ulUpdDefBufResutl = PPP_Service_HdlcHardUpdateDefBuffInfo(pstDefPara);
    if (VOS_ERR == ulUpdDefBufResutl)
    {
        return PPP_HDLC_HARD_PROC_PARA_ERR;
    }

    PPP_HDLC_HARD_MEM_SET(&stDrvDefPara, sizeof(PPP_DRIVER_HDLC_HARD_DEF_PARA_STRU),
                          0x00, sizeof(PPP_DRIVER_HDLC_HARD_DEF_PARA_STRU));
    PPP_Service_HdlcHardBuildDefPara(pstDefPara, &stDrvDefPara);

    PPP_Driver_HdlcHardDefEnable(&stDrvDefPara, &ulEnableInterrupt);

    /* 等待解封装暂停或完成，然后处理输出数据，可能会有多次停等的过程 */
    PPP_Service_HdlcHardDefWaitAndProc(ulEnableInterrupt, &stDrvDefPara, pstDefPara);

    return PPP_HDLC_HARD_PROC_ALL_SUCC;
}

/*****************************************************************************
 函 数 名  : PPP_Service_HdlcHardGetMaxDefLen
 功能描述  : 获取解封装最大输入长度
 输入参数  : usPppId        -   PPP ID
 输出参数  : 无
 返 回 值  : VOS_UINT32 解封装最大输入长度
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月1日
    作    者   : t00359887
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PPP_Service_HdlcHardGetMaxDefLen(VOS_UINT16 usPppId)
{
    PPP_DRIVER_HDLC_HARD_DEF_UNCOMPLETED_INFO_STRU *pstUncompleteInfo;
    VOS_UINT32                          ulMaxDataLen1Time = TTF_HDLC_DEF_INPUT_PARA_LINK_MAX_SIZE;

    pstUncompleteInfo = HDLC_DEF_GET_UNCOMPLETED_INFO(usPppId);
    if (HDLC_DEF_UNCOMPLETED_EXIST == pstUncompleteInfo->ucExistFlag)
    {
        ulMaxDataLen1Time -= pstUncompleteInfo->usDefOutOneLen;
    }

    return ulMaxDataLen1Time;
}

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif


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
#include <mdrv_diag_system.h>
#include "diag_system_debug.h"
#include "diag_port_manager.h"
#include "dms.h"
#include "OmVcomPpm.h"




/* ****************************************************************************
  2 全局变量定义
**************************************************************************** */
/* 用于记录 VCOM 通道发送的统计信息 */
OM_VCOM_DEBUG_INFO                      g_stVComDebugInfo[3];

/*****************************************************************************
  3 外部引用声明
*****************************************************************************/


/*****************************************************************************
  4 函数实现
*****************************************************************************/

/*****************************************************************************
 函 数 名  :
 功能描述  :
 输入参数  :
 输出参数  :
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2014年5月31日
    作    者   : XXXXXXXX
    修改内容   : V8R1 OM_Optimize项目新增

*****************************************************************************/

/*****************************************************************************
 函 数 名  : PPM_VComCfgSendData
 功能描述  : 从VCOM端口发送配置数据
 输入参数  : pucVirAddr:   数据虚地址
             pucPhyAddr:   数据实地址
             ulDataLen: 数据长度
 输出参数  : 无
 返 回 值  : CPM_SEND_ERR/CPM_SEND_OK
 修改历史  :
   1.日    期  : 2014年5月26日
     作    者  : h59254
     修改内容  : Creat Function
*****************************************************************************/
u32 PPM_VComCfgSendData(u8 *pucVirAddr, u8 *pucPhyAddr, u32 ulDataLen)
{
    g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMSendNum++;
    g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMSendLen += ulDataLen;

    if (0 != PPM_VOM_SEND_DATA(PPM_VCOM_CHAN_CTRL, pucVirAddr, ulDataLen, PPM_VCOM_DATA_MODE_TRANSPARENT))

  //  if (BSP_OK != DMS_WriteOmData(DMS_VCOM_OM_CHAN_CTRL, pucVirAddr, ulDataLen))
    {
        g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMSendErrNum++;
        g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMSendErrLen += ulDataLen;
        
        (void)ppm_printf("vcom cnf cmd failed, ind sum leng 0x%x, ind err len 0x%x.\n", \
            g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMSendLen, \
            g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMSendErrLen);

        return CPM_SEND_ERR;
    }

    /* 与手机软件连接时，启动延时上报，且打印到缓存中，可以输出打印 */
    (void)ppm_printf("vcom cnf cmd success, ind sum leng 0x%x, ind err len 0x%x.\n", \
            g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMSendLen, \
            g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMSendErrLen);

    return CPM_SEND_OK;
}

/*****************************************************************************
 函 数 名  : PPM_VComCfgEvtCB
 功能描述  : 用于VCOM通道打开关闭回调
 输入参数  : ulChan :通道号
             ulEvent:   打开或者关闭
 输出参数  : 无
 返 回 值  : CPM_SEND_ERR/CPM_SEND_OK
 修改历史  :
   1.日    期  : 2014年5月26日
     作    者  : h59254
     修改内容  : Creat Function
*****************************************************************************/
void PPM_VComEvtCB(u32 ulChan, u32 ulEvent)
{
    OM_LOGIC_CHANNEL_ENUM_UINT32        enChannel;
    bool                            ulSndMsg;

    (void)ppm_printf("PPM_VComEvtCB Chan:%s Event:%s.\n", 
                     (ulChan  == PPM_VCOM_CHAN_CTRL) ? "cnf"  : "ind",
                     (ulEvent == PPM_VCOM_EVT_CHAN_OPEN)     ? "open" : "close");

    if(ulChan == PPM_VCOM_CHAN_CTRL)
    {
        enChannel = OM_LOGIC_CHANNEL_CNF;
    }
    else if(ulChan == PPM_VCOM_CHAN_DATA)
    {
        enChannel = OM_LOGIC_CHANNEL_IND;
    }
    else
    {
        (void)ppm_printf("[%s] Error channel NO %d\n",__FUNCTION__,ulChan);
        return;
    }

    /*打开操作直接返回*/
    if(ulEvent == PPM_VCOM_EVT_CHAN_OPEN)
    {
        (void)ppm_printf("PPM_VComEvtCB open, do nothing.\n");
        return;
    }
    else if(ulEvent == PPM_VCOM_EVT_CHAN_CLOSE)
    {
        ulSndMsg  = false;

        if((CPM_VCOM_CFG_PORT == CPM_QueryPhyPort(CPM_OM_CFG_COMM)) &&
           (CPM_VCOM_IND_PORT == CPM_QueryPhyPort(CPM_OM_IND_COMM)))
        {
            ulSndMsg = true;
        }
        if(ulSndMsg == true)
        {
            (void)ppm_printf("PPM_VComEvtCB close, disconnect all ports.\n");
            PPM_DisconnectAllPort(enChannel);
        }
    }
    else
    {
        (void)ppm_printf("[%s] Error Event State %d\n",__FUNCTION__,ulEvent);
    }

    return;
}

/*****************************************************************************
 函 数 名  : GU_OamVComCfgReadData
 功能描述  : NAS把收到数据调用OM 接口发走
 输入参数  :  ucDevIndex: 物理端口
              pData    : 收到数据
              uslength : 数据长度
 输出参数  : 无
 返 回 值  : BSP_ERROR/BSP_OK
 修改历史  :
  1.日    期   : 2014年5月25日
    作    者   : h59254
    修改内容   : V8R1 OM_Optimize项目新增
*****************************************************************************/
u32 PPM_VComCfgReadData(u32 ulDevIndex, u8 *pData, u32 uslength)
{
    u32 ret = 0xFFFFFFF;

    if (ulDevIndex != PPM_VCOM_CHAN_CTRL)
    {
        (void)ppm_printf("[%s]:PhyPort port is error: %d\n", __FUNCTION__, ulDevIndex);

        return ERR_MSP_FAILURE;
    }

    g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMRcvNum++;
    g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMRcvLen += uslength;

    if ((NULL == pData) || (0 == uslength))
    {
        (void)ppm_printf("PPM_VComCfgReadData:Send data is NULL\n");

        return ERR_MSP_FAILURE;
    }

    /* 与手机软件连接时，下发命令有限，且打印到缓存中，可以输出打印 */
    (void)ppm_printf("vcom receive cmd, length : 0x%x, sum length : 0x%x.\n", \
        uslength, g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMRcvLen);

    ret = CPM_ComRcv(CPM_VCOM_CFG_PORT, pData, uslength);
    if(BSP_OK != ret)
    {
        ppm_printf("CPM_ComRcv error, ret = 0x%x\n", ret);
        g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMRcvErrNum++;
        g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMRcvErrLen += uslength;
    }

    return BSP_OK;
}

/*****************************************************************************
 函 数 名  : PPM_VComIndSendData
 功能描述  : Vcom口承载的OM IND端口收到数据，调NAS接收
 输入参数  : pucVirAddr:   数据虚地址
             pucPhyAddr:   数据实地址
             ulDataLen:    数据长度
 输出参数  : 无
 返 回 值  : BSP_ERROR/BSP_OK
 调用函数  :
 被调函数  :
 修改历史  :
  1.日    期   : 2014年5月25日
    作    者   : h59254
    修改内容   : V8R1 OM_Optimize项目新增
*****************************************************************************/
u32 PPM_VComIndSendData(u8 *pucVirAddr, u8 *pucPhyAddr, u32 ulDataLen)
{
    u32          ulInSlice;
    u32          ulOutSlice;
    u32          ulWriteSlice;
    int          lRet;
    u8           ucMode;

    g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMSendNum++;
    g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMSendLen += ulDataLen;
    
    ucMode = (COMPRESS_ENABLE_STATE == mdrv_deflate_read_cur_mode()) ?
                PPM_VCOM_DATA_MODE_COMPRESSED : PPM_VCOM_DATA_MODE_TRANSPARENT;
      
    ulInSlice = mdrv_timer_get_normal_timestamp();

    lRet = PPM_VOM_SEND_DATA(PPM_VCOM_CHAN_DATA, pucVirAddr, ulDataLen, ucMode);
 
    diag_system_debug_vcom_len(ulDataLen);
    diag_system_debug_send_data_end();

    ulOutSlice = mdrv_timer_get_normal_timestamp();

    ulWriteSlice = (ulInSlice > ulOutSlice) ? (0xffffffff - ulInSlice + ulOutSlice) : (ulOutSlice - ulInSlice);

    if(ulWriteSlice > g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulMaxTimeLen)
    {
        g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulMaxTimeLen = ulWriteSlice;
    }
    
    if (0 != lRet)
    {
        g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMSendErrNum++;
        g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMSendErrLen += ulDataLen;

        diag_system_debug_vcom_fail_len(ulDataLen);

        return CPM_SEND_ERR;
    }
    diag_system_debug_vcom_sucess_len(ulDataLen);

    return CPM_SEND_OK;
}


OM_VCOM_DEBUG_INFO *PPM_VComGetIndInfo(void)
{
    return &g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND];
}


/*****************************************************************************
 函 数 名  : PPM_VComCfgPortInit
 功能描述  : 用于 Vcom 口OM CFG通道的初始化
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无

 修改历史  :
  1.日    期   : 2014年5月25日
    作    者   : h59254
    修改内容   : V8R1 OM_Optimize项目新增
*****************************************************************************/
void PPM_VComCfgPortInit(void)
{
    struct diag_vcom_cb_ops_s ops;

    ops.event_cb = PPM_VComEvtCB;
    ops.data_rx_cb = PPM_VComCfgReadData;
    diag_vcom_register_ops(PPM_VCOM_CHAN_CTRL, &ops);

    CPM_PhySendReg(CPM_VCOM_CFG_PORT, PPM_VComCfgSendData);

    return;
}


/*****************************************************************************
 函 数 名  : PPM_VComIndPortInit
 功能描述  : 用于 Vcom 口OM IND通道的初始化
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无

 修改历史  :
  1.日    期   : 2014年5月25日
    作    者   : h59254
    修改内容   : V8R1 OM_Optimize项目新增
*****************************************************************************/
void PPM_VComIndPortInit(void)
{
    struct diag_vcom_cb_ops_s ops;

    ops.event_cb = PPM_VComEvtCB;
    ops.data_rx_cb = NULL;
    diag_vcom_register_ops(PPM_VCOM_CHAN_DATA, &ops);

    CPM_PhySendReg(CPM_VCOM_IND_PORT, PPM_VComIndSendData);

    return;
}


/*****************************************************************************
 函 数 名  : PPM_VComPortInit
 功能描述  : 用于 Vcom 口各通道的初始化
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无

 修改历史  :
  1.日    期   : 2014年5月25日
    作    者   : L00256032
    修改内容   : V8R1 OM_Optimize项目新增
*****************************************************************************/
void PPM_VComPortInit(void)
{
    /* coverity[secure_coding] */
    (void)memset(&g_stVComDebugInfo[0], 0, 3*sizeof(OM_VCOM_DEBUG_INFO));

    /* Vcom 口OM IND通道的初始化 */
    PPM_VComIndPortInit();

    /* Vcom 口OM CNF通道的初始化 */
    PPM_VComCfgPortInit();


    return;
}

/*****************************************************************************
 函 数 名  : PPM_VComInfoShow
 功能描述  : 用于打印 Vcom 口通道发送信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无

 修改历史  :
  1.日    期   : 2014年5月25日
    作    者   : L00256032
    修改内容   : V8R1 OM_Optimize项目新增
*****************************************************************************/
void PPM_VComInfoShow(void)
{
    (void)ppm_printf(" VCom30 Send num is           %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CBT].ulVCOMSendNum);
    (void)ppm_printf(" VCom30 Send Len is           %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CBT].ulVCOMSendLen);

    (void)ppm_printf(" VCom30 Send Error num is         %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CBT].ulVCOMSendErrNum);
    (void)ppm_printf(" VCom30 Send Error Len is         %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CBT].ulVCOMSendErrLen);

    (void)ppm_printf(" VCom30 receive num is           %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CBT].ulVCOMRcvNum);
    (void)ppm_printf(" VCom30 receive Len is           %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CBT].ulVCOMRcvLen);

    (void)ppm_printf(" VCom30 receive Error num is         %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CBT].ulVCOMRcvErrNum);
    (void)ppm_printf(" VCom30 receive Error Len is         %d.\n\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CBT].ulVCOMRcvErrLen);


    (void)ppm_printf(" VCom28 Send num is           %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMSendNum);
    (void)ppm_printf(" VCom28 Send Len is           %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMSendLen);

    (void)ppm_printf(" VCom28 Send Error num is         %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMSendErrNum);
    (void)ppm_printf(" VCom28 Send Error Len is         %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMSendErrLen);

    (void)ppm_printf(" VCom28 receive num is           %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMRcvNum);
    (void)ppm_printf(" VCom28 receive Len is           %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMRcvLen);

    (void)ppm_printf(" VCom28 receive Error num is         %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMRcvErrNum);
    (void)ppm_printf(" VCom28 receive Error Len is         %d.\n\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_CNF].ulVCOMRcvErrLen);


    (void)ppm_printf(" VCom31 Send num is           %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMSendNum);
    (void)ppm_printf(" VCom31 Send Len is           %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMSendLen);

    (void)ppm_printf(" VCom31 Send Error num is         %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMSendErrNum);
    (void)ppm_printf(" VCom31 Send Error Len is         %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMSendErrLen);

    (void)ppm_printf(" VCom31 receive num is           %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMRcvNum);
    (void)ppm_printf(" VCom31 receive Len is           %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMRcvLen);

    (void)ppm_printf(" VCom31 receive Error num is         %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMRcvErrNum);
    (void)ppm_printf(" VCom31 receive Error Len is         %d.\n", g_stVComDebugInfo[OM_LOGIC_CHANNEL_IND].ulVCOMRcvErrLen);

    return;
}






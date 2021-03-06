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
#include "scm_ind_src.h"
#include "scm_ind_dst.h"
#include "scm_cnf_src.h"
#include "scm_cnf_dst.h"
#include "diag_port_manager.h"
#include "diag_system_debug.h"
#include "OmCommonPpm.h"
#include "OmUsbPpm.h"


/* ****************************************************************************
  2 全局变量定义
**************************************************************************** */

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
 函 数 名  : PPM_UsbCfgSendData
 功能描述  : 将输入的数据通过USB(CFG口)发送给PC侧
 输入参数  : pucVirAddr:   数据虚地址
             pucPhyAddr:   数据实地址
             ulDataLen: 数据长度
 输出参数  : 无
 返 回 值  : BSP_ERROR/BSP_OK
 修改历史  :
   1.日    期  : 2014年5月24日
     作    者  : h59254
     修改内容  : Creat Function
*****************************************************************************/
u32 PPM_UsbCfgSendData(u8 *pucVirAddr, u8 *pucPhyAddr, u32 ulDataLen)
{
    return PPM_PortSend(OM_USB_CFG_PORT_HANDLE, pucVirAddr, pucPhyAddr, ulDataLen);
}


/*****************************************************************************
 函 数 名  : PPM_UsbCfgPortClose
 功能描述  : USB承载的OM CFG端口已经消失，需要关闭CFG端口
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 修改历史  :
   1.日    期  : 2014年5月24日
     作    者  : h59254
     修改内容  : Creat Function
*****************************************************************************/
void PPM_UsbCfgPortClose(void)
{
    PPM_PortCloseProc(OM_USB_CFG_PORT_HANDLE, CPM_CFG_PORT);

    return;
}

/*****************************************************************************
 函 数 名  : GU_OamUsbCfgStatusCB
 功能描述  : 用于ACPU上面处理USB物理端口断开后的OM链接断开
 输入参数  : enPortState:端口状态
 输出参数  : 无
 返 回 值  : 无
 修改历史  :
   1.日    期  : 2014年5月24日
     作    者  : h59254
     修改内容  : V8R1 OM_Optimize项目新增
*****************************************************************************/
void PPM_UsbCfgStatusCB(ACM_EVT_E enPortState)
{
    PPM_PortStatus(OM_USB_CFG_PORT_HANDLE, CPM_CFG_PORT, enPortState);

    return;
}

/*****************************************************************************
 函 数 名  : GU_OamUsbCfgWriteDataCB
 功能描述  : 用于处理USB承载的OM CFG端口的异步发送数据的回调
 输入参数  : pucData:   需要发送的数据内容
             ulDataLen: 数据长度
 输出参数  : 无
 返 回 值  : 无
 修改历史  :
   1.日    期  : 2014年5月24日
     作    者  : h59254
     修改内容  : V8R1 OM_Optimize项目新增
*****************************************************************************/
void PPM_UsbCfgWriteDataCB(u8* pucVirData, u8* pucPhyData, s32 lLen)
{
    PPM_PortWriteAsyCB(OM_USB_CFG_PORT_HANDLE, pucVirData, lLen);

    return;
}

/*****************************************************************************
 函 数 名  : GU_OamUsbCfgReadDataCB
 功能描述  : 用于ACPU上面底软把USB承载的OM CFG端口数据通过ICC发送给OM模块
 输入参数  : enPhyPort: 物理端口
             UdiHandle:设备句柄
 输出参数  : 无
 返 回 值  : BSP_ERROR/BSP_OK
 修改历史  :
   1.日    期  : 2014年5月24日
     作    者  : h59254
     修改内容  : V8R1 OM_Optimize项目新增
*****************************************************************************/
s32 PPM_UsbCfgReadDataCB(void)
{
    return PPM_ReadPortData(CPM_CFG_PORT, g_astOMPortUDIHandle[OM_USB_CFG_PORT_HANDLE], OM_USB_CFG_PORT_HANDLE);
}

/*****************************************************************************
 函 数 名  : GU_OamUsbCfgPortOpen
 功能描述  : 用于初始化USB承载的OM CFG端口
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 修改历史  :
   1.日    期  : 2014年5月24日
     作    者  : h59254
     修改内容  : Creat Function
*****************************************************************************/
void PPM_UsbCfgPortOpen(void)
{
    PPM_ReadPortDataInit(CPM_CFG_PORT,
                            OM_USB_CFG_PORT_HANDLE,
                            PPM_UsbCfgReadDataCB,
                            PPM_UsbCfgWriteDataCB,
                            PPM_UsbCfgStatusCB);

    ppm_printf("usb cfg port open\n");
    return;
}

/*****************************************************************************
 函 数 名  : PPM_UsbIndStatusCB
 功能描述  : 用于ACPU上面处理USB物理端口断开后的OM链接断开
 输入参数  : enPortState:   端口状态
 输出参数  : 无
 返 回 值  : 无
 修改历史  :
   1.日    期  : 2014年5月24日
     作    者  : h59254
     修改内容  : Creat Function
*****************************************************************************/
void PPM_UsbIndStatusCB(ACM_EVT_E enPortState)
{
    PPM_PortStatus(OM_USB_IND_PORT_HANDLE, CPM_IND_PORT, enPortState);

    return;
}

/*****************************************************************************
 函 数 名  : GU_OamUsbIndWriteDataCB
 功能描述  : 用于处理USB OM主动上报端口的异步发送数据的回调
 输入参数  : pucData:   需要发送的数据内容
             ulDataLen: 数据长度
 输出参数  : 无
 返 回 值  : 无
 修改历史  :
   1.日    期  : 2014年5月24日
     作    者  : h59254
     修改内容  : Creat Function
*****************************************************************************/
void PPM_UsbIndWriteDataCB(u8* pucVirData, u8* pucPhyData, s32 lLen)
{

    PPM_PortWriteAsyCB(OM_USB_IND_PORT_HANDLE, pucVirData, lLen);

    return;
}

/*****************************************************************************
 函 数 名  : GU_OamUsbIndPortOpen
 功能描述  : 用于初始化USB承载的OM主动上报端口
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
   1.日    期  : 2014年5月24日
     作    者  : h59254
     修改内容  : Creat Function
*****************************************************************************/
void PPM_UsbIndPortOpen(void)
{
    PPM_ReadPortDataInit(CPM_IND_PORT,
                            OM_USB_IND_PORT_HANDLE,
                            NULL,
                            PPM_UsbIndWriteDataCB,
                            PPM_UsbIndStatusCB);
    
    ppm_printf("usb ind port open\n");
    return;
}

/*****************************************************************************
 函 数 名  : PPM_UsbIndPortClose
 功能描述  : USB承载的OM主动上报端口已经消失，需要关闭USB端口
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 修改历史  :
   1.日    期  : 2014年5月24日
     作    者  : h59254
     修改内容  : Creat Function
*****************************************************************************/
void PPM_UsbIndPortClose(void)
{
    PPM_PortCloseProc(OM_USB_IND_PORT_HANDLE, CPM_IND_PORT);

    return;
}

/*****************************************************************************
 函 数 名  : PPM_UsbIndSendData
 功能描述  : 将输入的数据通过USB主动上报端口发送给PC侧
 输入参数  : pucVirAddr:   数据虚地址
             pucPhyAddr:   数据实地址
             ulDataLen: 数据长度
 输出参数  : 无
 返 回 值  : BSP_ERROR/BSP_OK
 修改历史  :
   1.日    期  : 2014年5月24日
     作    者  : h59254
     修改内容  : Creat Function
*****************************************************************************/
u32 PPM_UsbIndSendData(u8 *pucVirAddr, u8 *pucPhyAddr, u32 ulDataLen)
{
    return PPM_PortSend(OM_USB_IND_PORT_HANDLE, pucVirAddr, pucPhyAddr, ulDataLen);
}

/*****************************************************************************
 函 数 名  : PPM_UsbCfgPortInit
 功能描述  : 用于USB上OM配置端口通道的初始化
 输入参数  : 无
 输出参数  : 无
 返 回 值  : BSP_ERROR -- 初始化失败
             BSP_OK  -- 初始化成功
 修改历史  :
   1.日    期  : 2014年5月24日
     作    者  : h59254
     修改内容  : Creat Function
*****************************************************************************/
u32 PPM_UsbCfgPortInit(void)
{
    mdrv_usb_reg_enablecb((USB_UDI_ENABLE_CB_T)PPM_UsbCfgPortOpen);

    mdrv_usb_reg_disablecb((USB_UDI_DISABLE_CB_T)PPM_UsbCfgPortClose);

    CPM_PhySendReg(CPM_CFG_PORT,  PPM_UsbCfgSendData);

    return BSP_OK;
}

/*****************************************************************************
 函 数 名  : PPM_UsbIndPortInit
 功能描述  : 用于USB 上OM主动上报端口通道的初始化
 输入参数  : 无
 输出参数  : 无
 返 回 值  : BSP_ERROR -- 初始化失败
             BSP_OK  -- 初始化成功
 修改历史  :
  1.日    期   : 2014年5月25日
    作    者   : L00256032
    修改内容   : V8R1 OM_Optimize项目新增
*****************************************************************************/
u32 PPM_UsbIndPortInit(void)
{
    mdrv_usb_reg_enablecb((USB_UDI_ENABLE_CB_T)PPM_UsbIndPortOpen);

    mdrv_usb_reg_disablecb((USB_UDI_DISABLE_CB_T)PPM_UsbIndPortClose);

    CPM_PhySendReg(CPM_IND_PORT,  PPM_UsbIndSendData);

    return BSP_OK;
}


/*****************************************************************************
 函 数 名  : PPM_UsbPortInit
 功能描述  : USB承载的虚拟端口通道的初始化:包括OM IND、OM CNF等端口
 输入参数  : 无
 输出参数  : 无
 返 回 值  : BSP_OK   - 初始化成功
             BSP_ERROR  - 初始化失败
 修改历史  :
  1.日    期   : 2014年5月25日
    作    者   : L00256032
    修改内容   : V8R1 OM_Optimize项目新增
*****************************************************************************/
u32 PPM_UsbPortInit(void)
{
    /* USB 承载的OM主动上报端口的初始化 */
    if (BSP_OK != PPM_UsbIndPortInit())
    {
        return (u32)BSP_ERROR;
    }

    /* USB 承载的OM配置端口的初始化 */
    if (BSP_OK != PPM_UsbCfgPortInit())
    {
        return (u32)BSP_ERROR;
    }

    return BSP_OK;
}






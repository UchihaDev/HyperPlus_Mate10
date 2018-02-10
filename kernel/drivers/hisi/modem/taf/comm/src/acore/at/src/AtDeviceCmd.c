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
*****************************************************************************/
#include "AtParse.h"
#include "ATCmdProc.h"
/* Added by f62575 for SMALL IMAGE, 2012-1-3, begin */
#include "AtDeviceCmd.h"
#include "AtCheckFunc.h"
#include "mdrv.h"
/* Added by f62575 for SMALL IMAGE, 2012-1-3, end   */
#include "AtCmdMsgProc.h"
#include "AtInputProc.h"
#include "AtTestParaCmd.h"

/* ADD by c64416 for V9R1/V7R1 AT, 2013/09/18 begin */
#include "at_lte_common.h"
/* ADD by c64416 for V9R1/V7R1 AT, 2013/09/18 end */
#include "nv_stru_lps.h"

#include "nv_stru_cas.h"

#include "AtCmdMiscProc.h"


#include <linux/random.h>


/*****************************************************************************
    协议栈打印打点方式下的.C文件宏定义
*****************************************************************************/
#define    THIS_FILE_ID        PS_FILE_ID_AT_DEVICECMD_C


/*****************************************************************************
  2 全局变量定义
*****************************************************************************/

/* 命令受限标志宏定义说明
#define CMD_TBL_E5_IS_LOCKED        (0x00000001)     不受E5锁定控制的命令
#define CMD_TBL_PIN_IS_LOCKED       (0x00000002)     不受PIN码锁定控制的命令
#define CMD_TBL_IS_E5_DOCK          (0x00000004)     E5 DOCK命令
#define CMD_TBL_CLAC_IS_INVISIBLE   (0x00000008)     +CLAC命令中不输出显示的命令
*/

VOS_UINT32                 g_ulNVRD = 0;
VOS_UINT32                 g_ulNVWR = 0;

AT_PAR_CMD_ELEMENT_STRU g_astAtDeviceCmdTbl[] = {
    {AT_CMD_GTIMER,
    AT_SetGTimerPara,    AT_NOT_SET_TIME,    AT_QryGTimerPara,      AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^GTIMER",   (VOS_UINT8*)"(0-429496728)"},

    {AT_CMD_RSIM,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,    AT_QryRsimPara,        AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^RSIM",     VOS_NULL_PTR},

    {AT_CMD_PHYNUM,
    AT_SetPhyNumPara,    AT_NOT_SET_TIME,    AT_QryPhyNumPara,      AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^PHYNUM",   VOS_NULL_PTR},

    {AT_CMD_CSVER,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,    At_QryCsVer,           AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^CSVER",    VOS_NULL_PTR},

    {AT_CMD_QOS,
    At_SetQosPara,       AT_NOT_SET_TIME,    At_QryQosPara,         AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
   AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^QOS",      VOS_NULL_PTR},

    {AT_CMD_SDOMAIN,
    At_SetSDomainPara,   AT_NOT_SET_TIME,    At_QrySDomainPara,     AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SDOMAIN",  VOS_NULL_PTR},

    {AT_CMD_DPACAT,
    At_SetDpaCat,        AT_NOT_SET_TIME,    At_QryDpaCat,          AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^DPACAT",   VOS_NULL_PTR},

    {AT_CMD_HSSPT,
    AT_SetHsspt  ,       AT_NOT_SET_TIME,    AT_QryHsspt,         AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^HSSPT",    (VOS_UINT8*)"(0,1,2,6)"},

    {AT_CMD_PLATFORM,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,    At_QryPlatForm,        AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^PLATFORM", VOS_NULL_PTR},

    {AT_CMD_BSN,
    At_SetBsn,           AT_NOT_SET_TIME,    At_QryBsn,             AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^BSN",      VOS_NULL_PTR},

/* Modify by c00172979 for V7代码同步, 2012-04-13, Begin   */
/* Modify by c00172979 for V7代码同步, 2012-04-13, End   */
    {AT_CMD_SFM,
    At_SetSfm,          AT_SET_PARA_TIME,   At_QrySfm,            AT_NOT_SET_TIME,    VOS_NULL_PTR , AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SFM",     (VOS_UINT8*)"(0,1)"},

    /* Added by f62575 for SMALL IMAGE, 2012-1-3, begin */
    {AT_CMD_TMODE,
    At_SetTModePara,     AT_SET_PARA_TIME,   At_QryTModePara,       AT_QRY_PARA_TIME ,  At_TestTmodePara , AT_TEST_PARA_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^TMODE",    (VOS_UINT8*)"(0,1,2,3,4,11,12,13,14,15,16,17,18,19)"},
    /* Added by f62575 for SMALL IMAGE, 2012-1-3, end   */

    /* DTS2012041801532 w00182550 NV归一化 start in 2012-04-12 */
    {AT_CMD_FCHAN,
    At_SetFChanPara,     AT_SET_PARA_TIME,   At_QryFChanPara,       AT_QRY_PARA_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_FCHAN_OTHER_ERR  ,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^FCHAN",    (VOS_UINT8*)"(0-7),(0-255),(0-4294967295),(0-1)"},
    /* DTS2012041801532 w00182550 NV归一化 end in 2012-04-12 */

    {AT_CMD_FTXON,
    At_SetFTxonPara,     AT_SET_PARA_TIME,   At_QryFTxonPara,       AT_QRY_PARA_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_FTXON_OTHER_ERR  ,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^FTXON",    (VOS_UINT8*)"(0,1,2)"},

    /* Modify by w00199382 for V7代码同步, 2012-04-07, Begin   */
    {AT_CMD_FDAC,
    AT_SetFDac,          AT_SET_PARA_TIME,   AT_QryFDac,            AT_NOT_SET_TIME,    At_TestFdacPara , AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^FDAC",     (VOS_UINT8*)"(0-65536)"},

    /* Modify by w00199382 for V7代码同步, 2012-04-07, End   */

    {AT_CMD_FRXON,
    At_SetFRxonPara,     AT_SET_PARA_TIME,   At_QryFRxonPara,       AT_QRY_PARA_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_FRXON_OTHER_ERR  ,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^FRXON",    (VOS_UINT8*)"(0-1)"},

    /* Modify by w00199382 for V7代码同步, 2012-04-07, Begin   */
    {AT_CMD_FPA,
    At_SetFpaPara,       AT_SET_PARA_TIME,   At_QryFpaPara,         AT_NOT_SET_TIME,    VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_FPA_OTHER_ERR  ,      CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^FPA",      (VOS_UINT8*)"(0-255)"},

    /* Modify by w00199382 for V7代码同步, 2012-04-07, End   */

    {AT_CMD_FLNA,
    At_SetFlnaPara,      AT_SET_PARA_TIME,   At_QryFlnaPara,        AT_QRY_PARA_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_FLNA_OTHER_ERR  ,     CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^FLNA",     (VOS_UINT8*)"(0-255)"},

    {AT_CMD_FRSSI,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,    At_QryFrssiPara,       AT_QRY_PARA_TIME,  VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^FRSSI",    VOS_NULL_PTR},

    {AT_CMD_MDATE,
    AT_SetMDatePara,     AT_NOT_SET_TIME,    AT_QryMDatePara,       AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^MDATE",    (VOS_UINT8*)"(@time)"},

    {AT_CMD_FACINFO,
    AT_SetFacInfoPara,   AT_NOT_SET_TIME,    AT_QryFacInfoPara,     AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_ERROR,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^FACINFO",  (VOS_UINT8*)"(0,1),(@valueInfo)"},


    {AT_CMD_SD,
    At_SetSD,            AT_NOT_SET_TIME,    At_QrySD,              AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_SD_CARD_OTHER_ERR ,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SD",       (VOS_UINT8*)"(0-4),(0-429496728),(0-3)"},

    {AT_CMD_GPIOPL,
    At_SetGPIOPL,        AT_SET_PARA_TIME,   At_QryGPIOPL,          AT_QRY_PARA_TIME,  VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^GPIOPL",   (VOS_UINT8*)"(@GPIOPL)"},

    /* Add by w00199382 for V7代码同步, 2012-04-07, Begin   */
    /* DTS2012041801532 w00182550 NV归一化 start in 2012-04-12 */
    {AT_CMD_GETEXBANDINFO,
    AT_SetExbandInfoPara,      AT_NOT_SET_TIME,  VOS_NULL_PTR,            AT_NOT_SET_TIME,   VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,       CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^GETEXBANDINFO",     (VOS_UINT8*)"(101-116)"},

    {AT_CMD_GETEXBANDTESTINFO,
    AT_SetExbandTestInfoPara,      AT_NOT_SET_TIME, VOS_NULL_PTR ,     AT_NOT_SET_TIME,   VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,       CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^GETEXBANDTESTINFO",      (VOS_UINT8*)"(101-116),(14,50,100,150,200)"},
    /* DTS2012041801532 w00182550 NV归一化 end in 2012-04-12 */
    /* 生产NV恢复 */
    {AT_CMD_INFORRS,
    At_SetInfoRRS,       AT_SET_PARA_TIME,    VOS_NULL_PTR,          AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^INFORRS",  VOS_NULL_PTR},
    /* Add by w00199382 for V7代码同步, 2012-04-07, End   */

    {AT_CMD_INFORBU,
    atSetNVFactoryBack,  AT_SET_PARA_TIME,    VOS_NULL_PTR,          AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^INFORBU",  VOS_NULL_PTR},

    {AT_CMD_DATALOCK,
    At_SetDataLock,      AT_SET_PARA_TIME,   At_QryDataLock,        AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^DATALOCK", (VOS_UINT8*)"(@nlockCode)"},

    {AT_CMD_VERSION,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,    At_QryVersion,         AT_QRY_PARA_TIME,  VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^VERSION",  VOS_NULL_PTR},



    {AT_CMD_SIMLOCK,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,    At_QrySimLockPlmnInfo, AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SIMLOCK",  VOS_NULL_PTR},

    {AT_CMD_MAXLCK_TIMES,
    At_SetMaxLockTimes,  AT_SET_PARA_TIME,   At_QryMaxLockTimes,    AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^MAXLCKTMS",(VOS_UINT8*)"(0-429496728)"},

    {AT_CMD_CALLSRV,
    At_SetCallSrvPara,   AT_NOT_SET_TIME,    At_QryCallSrvPara,     AT_NOT_SET_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^CALLSRV",  (VOS_UINT8*)"(0,1)"},

    {AT_CMD_CSDFLT,
    At_SetCsdfltPara,    AT_NOT_SET_TIME,    At_QryCsdfltPara,      AT_QRY_PARA_TIME,   VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_ERROR,                       CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^CSDFLT",   (VOS_UINT8*)"(0,1)"},

    {AT_CMD_SECUBOOTFEATURE,
    VOS_NULL_PTR,    AT_NOT_SET_TIME,    At_QrySecuBootFeaturePara, AT_NOT_SET_TIME,  VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SECUBOOTFEATURE",  (VOS_UINT8*)"(0-3)"},

    /* Modified by f62575 for B050 Project, 2012-2-3, begin   */
    {AT_CMD_SECUBOOT,
    At_SetSecuBootPara,  AT_SET_PARA_TIME,    At_QrySecuBootPara,    AT_QRY_PARA_TIME,  VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SECUBOOT", (VOS_UINT8*)"(0-3)"},

    {AT_CMD_SETKEY,
    At_SetKeyPara,  AT_SET_PARA_TIME,    VOS_NULL_PTR,    AT_NOT_SET_TIME,  VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SETKEY", (VOS_UINT8*)"(1-4)"},

    {AT_CMD_GETKEYINFO,
    At_GetKeyInfoPara,  AT_SET_PARA_TIME,    VOS_NULL_PTR,    AT_NOT_SET_TIME,  VOS_NULL_PTR ,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^GETKEYINFO", (VOS_UINT8*)"(1-4)"},

    /* Modified by f62575 for B050 Project, 2012-2-3, end */

    {AT_CMD_TMMI,
    AT_SetTmmiPara,      AT_NOT_SET_TIME,    AT_QryTmmiPara,        AT_NOT_SET_TIME,   At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^TMMI",  (VOS_UINT8*)"(0,1)"},

    /*DTS2012041102190 : h00135900 start in 2011-04-11 AT代码融合*/
    /* V7R1要求使用"=?"查询充电使能状态 */
    {AT_CMD_TCHRENABLE,
    AT_SetChrgEnablePara,AT_NOT_SET_TIME,    AT_QryChrgEnablePara,  AT_NOT_SET_TIME,   AT_TestChrgEnablePara, AT_SET_PARA_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^TCHRENABLE",(VOS_UINT8*)"(0,1,4)"},
    /*DTS2012041102190 : h00135900 end in 2011-04-11 AT代码融合*/

    {AT_CMD_TCHRINFO,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,    AT_QryChrgInfoPara,    AT_NOT_SET_TIME,   At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^TCHRINFO",VOS_NULL_PTR},

    {AT_CMD_TSCREEN,
    AT_SetTestScreenPara,AT_NOT_SET_TIME,    VOS_NULL_PTR,          AT_NOT_SET_TIME,   At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^TSCREEN",  (VOS_UINT8*)"(0-255),(0-255)"},

    {AT_CMD_BATVOL,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,    AT_QryBatVolPara,      AT_QRY_PARA_TIME,  At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^TBATVOLT",  VOS_NULL_PTR},

    {AT_CMD_WUPWD,
    AT_SetWebPwdPara,    AT_NOT_SET_TIME,    VOS_NULL_PTR,          AT_NOT_SET_TIME,   At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WUPWD",  (VOS_UINT8*)"(0,1),(@WUPWD)"},

    {AT_CMD_PRODTYPE,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,    AT_QryProdTypePara,    AT_QRY_PARA_TIME,  At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^PRODTYPE",  VOS_NULL_PTR},

    {AT_CMD_FEATURE,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,    AT_QryFeaturePara,     AT_QRY_PARA_TIME,  At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SFEATURE",  VOS_NULL_PTR},

    {AT_CMD_PRODNAME,
    AT_SetProdNamePara,  AT_NOT_SET_TIME,    AT_QryProdNamePara,    AT_NOT_SET_TIME,   At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^PRODNAME",  (VOS_UINT8*)"(@ProductName)"},

    {AT_CMD_FWAVE,
    AT_SetFwavePara,     AT_SET_PARA_TIME,   VOS_NULL_PTR,          AT_NOT_SET_TIME,   At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^FWAVE",  (VOS_UINT8*)"(0-7),(0-65535)"},

    {AT_CMD_EQVER,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,    AT_QryEqverPara,       AT_NOT_SET_TIME,   VOS_NULL_PTR,     AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^EQVER",  VOS_NULL_PTR},

    {AT_CMD_WIENABLE,
    AT_SetWiFiEnablePara, AT_NOT_SET_TIME, AT_QryWiFiEnablePara, AT_NOT_SET_TIME, At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WIENABLE",(VOS_UINT8*)"(0,1,2)"},

    {AT_CMD_WIMODE,
    AT_SetWiFiModePara,   AT_NOT_SET_TIME, AT_QryWiFiModePara,   AT_NOT_SET_TIME, At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WIMODE",  (VOS_UINT8*)"(0,1,2,3,4)"},

    {AT_CMD_WIBAND,
    AT_SetWiFiBandPara,   AT_NOT_SET_TIME, AT_QryWiFiBandPara,   AT_NOT_SET_TIME, At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WIBAND",  (VOS_UINT8*)"(0,1)"},

    {AT_CMD_WIFREQ,
    AT_SetWiFiFreqPara,   AT_NOT_SET_TIME, AT_QryWiFiFreqPara,   AT_NOT_SET_TIME, At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WIFREQ",  (VOS_UINT8*)"(0-65535),(@offset)"},

    {AT_CMD_WIRATE,
    AT_SetWiFiRatePara,   AT_NOT_SET_TIME, AT_QryWiFiRatePara,   AT_NOT_SET_TIME, At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WIDATARATE",  (VOS_UINT8*)"(0-65535)"},

    /* Modified by L00171473 for DTS2012020106679,AT WT工位 2012-01-17  Begin */
    {AT_CMD_WIPOW,
    AT_SetWiFiPowerPara,  AT_NOT_SET_TIME, AT_QryWiFiPowerPara,  AT_NOT_SET_TIME, At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WIPOW",    (VOS_UINT8*)"(0-65535)"},
    /* Modified by L00171473 for DTS2012020106679,AT WT工位 2012-01-17  End */

    {AT_CMD_WITX,
    AT_SetWiFiTxPara,     AT_NOT_SET_TIME, AT_QryWiFiTxPara,     AT_NOT_SET_TIME, At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WITX",     (VOS_UINT8*)"(0,1)"},

    {AT_CMD_WIRX,
    AT_SetWiFiRxPara,     AT_NOT_SET_TIME, AT_QryWiFiRxPara,     AT_NOT_SET_TIME, At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WIRX",     (VOS_UINT8*)"(0,1),(@smac),(@dmac)"},

    {AT_CMD_WIRPCKG,
    AT_SetWiFiPacketPara, AT_NOT_SET_TIME, AT_QryWiFiPacketPara, AT_NOT_SET_TIME, At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WIRPCKG",  (VOS_UINT8*)"(0)"},

/* Add by z60575 for multi_ssid, 2012-9-5 begin */
    {AT_CMD_SSID,
    AT_SetWiFiSsidPara,   AT_NOT_SET_TIME, AT_QryWiFiSsidPara,   AT_NOT_SET_TIME, AT_TestSsidPara, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SSID",  (VOS_UINT8*)"(0-3),(@SSID)"},
/* Add by z60575 for multi_ssid, 2012-9-5 end */

    {AT_CMD_WIKEY,
    AT_SetWiFiKeyPara,    AT_NOT_SET_TIME, AT_QryWiFiKeyPara,    AT_NOT_SET_TIME, AT_TestWikeyPara, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WIKEY",  (VOS_UINT8*)"(0-3),(@WIKEY)"},

    {AT_CMD_WILOG,
    AT_SetWiFiLogPara,    AT_NOT_SET_TIME, AT_QryWiFiLogPara,    AT_NOT_SET_TIME, At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WILOG",  (VOS_UINT8*)"(0,1),(@content)"},

    {AT_CMD_WIINFO,
    AT_SetWifiInfoPara,   AT_NOT_SET_TIME, VOS_NULL_PTR,         AT_NOT_SET_TIME, At_CmdTestProcERROR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_ERROR, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WIINFO",  (VOS_UINT8*)"(0,1),(0,1)"},

    {AT_CMD_WIPARANGE,
    AT_SetWifiPaRangePara, AT_NOT_SET_TIME, AT_QryWifiPaRangePara, AT_NOT_SET_TIME, AT_TestWifiPaRangePara, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^WIPARANGE",  (VOS_UINT8*)"(@gainmode)"},

    {AT_CMD_NVRD,
    AT_SetNVReadPara,     AT_SET_PARA_TIME,  VOS_NULL_PTR,        AT_NOT_SET_TIME,  VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_ERROR, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^NVRD",(VOS_UINT8*)"(0-65535)"},



    {AT_CMD_CURC,
    At_SetCurcPara,      AT_NOT_SET_TIME,     At_QryCurcPara,     AT_QRY_PARA_TIME, VOS_NULL_PTR,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_ERROR, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^CURC", (VOS_UINT8*)"(0-2)"},
    /* Added by s00217060 for 主动上报AT命令控制下移至C核, 2013-4-3, end */
    /* Added by 傅映君/f62575 for AT Project, SIM卡保护标志确认, 2011/11/15, end */

    /* Modify by w00199382 for V7代码同步, 2012-04-07, Begin   */

    {AT_CMD_SN,
    At_SetSnPara,        AT_NOT_SET_TIME,    VOS_NULL_PTR,           AT_NOT_SET_TIME,    At_CmdTestProcOK, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_DEVICE_OTHER_ERROR, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^SN",       VOS_NULL_PTR},

    /* Modify by w00199382 for V7代码同步, 2012-04-07, End   */

    /* Added by f62575 for SMALL IMAGE, 2012-1-3, begin */
    {AT_CMD_TBAT,
    AT_SetTbatPara,     AT_SET_PARA_TIME,   AT_QryTbatPara,  AT_QRY_PARA_TIME,  VOS_NULL_PTR, AT_SET_PARA_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^TBAT",    (VOS_UINT8 *)"(0,1),(0,1),(0-65535),(0-65535)"},

    {AT_CMD_PSTANDBY,
    AT_SetPstandbyPara,     AT_SET_PARA_TIME,   VOS_NULL_PTR,  AT_QRY_PARA_TIME,  VOS_NULL_PTR, AT_SET_PARA_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^PSTANDBY",    (VOS_UINT8 *)"(0-65535),(0-65535)"},

/* Add by z60575 for multi_ssid, 2012-9-5 begin */
    {AT_CMD_WIWEP,
    AT_SetWiwepPara,        AT_SET_PARA_TIME,   AT_QryWiwepPara,  AT_QRY_PARA_TIME,  AT_TestWiwepPara, AT_SET_PARA_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^WIWEP",    (VOS_UINT8 *)"(0-3),(@wifikey),(0-3)"},
/* Add by z60575 for multi_ssid, 2012-9-5 end */

    {AT_CMD_CMDLEN,
    AT_SetCmdlenPara,        AT_SET_PARA_TIME,   AT_QryCmdlenPara,  AT_QRY_PARA_TIME,  At_CmdTestProcOK, AT_SET_PARA_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^CMDLEN",    (VOS_UINT8 *)"(0-65535),(0-65535)"},

    /*DTS2012041102190 : h00135900 start in 2011-04-11 AT代码融合*/
    {AT_CMD_TSELRF,
    AT_SetTseLrfPara,        AT_SET_PARA_TIME,   AT_QryTseLrfPara,  AT_QRY_PARA_TIME,  VOS_NULL_PTR, AT_SET_PARA_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^TSELRF",    (VOS_UINT8 *)"(0-255),(0-255)"},
    /*DTS2012041102190 : h00135900 end in 2011-04-11 AT代码融合*/
    /* Added by f62575 for SMALL IMAGE, 2012-1-3, end   */

    {AT_CMD_HUK,
    AT_SetHukPara,              AT_SET_PARA_TIME,   VOS_NULL_PTR,   AT_NOT_SET_TIME,  AT_TestHsicCmdPara,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^HUK",         (VOS_UINT8 *)"(@huk)"},

    {AT_CMD_FACAUTHPUBKEYEX,
    VOS_NULL_PTR,               AT_NOT_SET_TIME,    VOS_NULL_PTR,   AT_NOT_SET_TIME,  AT_TestHsicCmdPara,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^FACAUTHPUBKEYEX",       (VOS_UINT8 *)"(1-20),(1-20),(@Pubkey)"},

    {AT_CMD_IDENTIFYSTART,
    AT_SetIdentifyStartPara,    AT_SET_PARA_TIME,   VOS_NULL_PTR,   AT_NOT_SET_TIME,  AT_TestHsicCmdPara,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^IDENTIFYSTART",       (VOS_UINT8 *)"(@Rsa)"},

    {AT_CMD_IDENTIFYEND,
    AT_SetIdentifyEndPara,      AT_SET_PARA_TIME,   VOS_NULL_PTR,   AT_NOT_SET_TIME,  AT_TestHsicCmdPara,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^IDENTIFYEND",       VOS_NULL_PTR},



    {AT_CMD_SIMLOCKDATAWRITEEX,
    VOS_NULL_PTR,               AT_NOT_SET_TIME,    VOS_NULL_PTR,   AT_NOT_SET_TIME,  AT_TestHsicCmdPara,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SIMLOCKDATAWRITEEX",    (VOS_UINT8 *)SIMLOCKDATAWRITEEX_CMD_PARA_STRING},

    {AT_CMD_SIMLOCKDATAREADEX,
    AT_SimLockDataReadExPara,  AT_SET_PARA_TIME,    VOS_NULL_PTR,   AT_NOT_SET_TIME,  AT_TestHsicCmdPara,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SIMLOCKDATAREADEX",    (VOS_UINT8 *)SIMLOCKDATAREADEX_CMD_PARA_STRING},

    {AT_CMD_SIMLOCKDATAWRITE,
    VOS_NULL_PTR,               AT_NOT_SET_TIME,    VOS_NULL_PTR,   AT_NOT_SET_TIME,  AT_TestHsicCmdPara,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SIMLOCKDATAWRITE",    (VOS_UINT8 *)"(@SimlockData)"},

    {AT_CMD_PHONESIMLOCKINFO,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,    AT_QryPhoneSimlockInfoPara, AT_QRY_PARA_TIME,  AT_TestHsicCmdPara,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^PHONESIMLOCKINFO",    VOS_NULL_PTR},

    {AT_CMD_SIMLOCKDATAREAD,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,    AT_QrySimlockDataReadPara,  AT_QRY_PARA_TIME,  AT_TestHsicCmdPara,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SIMLOCKDATAREAD",     VOS_NULL_PTR},

    {AT_CMD_PHONEPHYNUM,
    AT_SetPhonePhynumPara,  AT_SET_PARA_TIME,    AT_QryPhonePhynumPara,  AT_QRY_PARA_TIME,   AT_TestHsicCmdPara,   AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^PHONEPHYNUM",         (VOS_UINT8 *)"(@type),(@Phynum),(@Hmac)"},

    {AT_CMD_PORTCTRLTMP,
    AT_SetPortCtrlTmpPara,          AT_SET_PARA_TIME,   AT_QryPortCtrlTmpPara,  AT_NOT_SET_TIME,  AT_TestHsicCmdPara,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^PORTCTRLTMP",    (VOS_UINT8 *)"(@password)"},

    {AT_CMD_PORTATTRIBSET,
    AT_SetPortAttribSetPara,          AT_SET_PARA_TIME,   AT_QryPortAttribSetPara,  AT_QRY_PARA_TIME,  AT_TestHsicCmdPara,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^PORTATTRIBSET",    (VOS_UINT8 *)"(0,1),(@password)"},

    {AT_CMD_SIMLOCKUNLOCK,
    AT_SetSimlockUnlockPara, AT_SET_PARA_TIME,  VOS_NULL_PTR,   AT_NOT_SET_TIME,    AT_TestSimlockUnlockPara, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS,    CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SIMLOCKUNLOCK",    (VOS_UINT8 *)"(\"NET\",\"NETSUB\",\"SP\"),(pwd)"},

    {AT_CMD_FPLLSTATUS,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,    AT_QryFPllStatusPara,  AT_QRY_PARA_TIME,  VOS_NULL_PTR,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^FPLLSTATUS",     (VOS_UINT8 *)"(0,1),(0,1)"},

    {AT_CMD_FPOWDET,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,    AT_QryFpowdetTPara,  AT_QRY_PARA_TIME,  VOS_NULL_PTR,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^FPOWDET",     VOS_NULL_PTR},


    {AT_CMD_MEID,
    AT_SetMeidPara,    AT_SET_PARA_TIME,    AT_QryMeidPara,    AT_SET_PARA_TIME,    VOS_NULL_PTR,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,    AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8 *)"^MEID",   (VOS_UINT8*)"(@number)"},

    {AT_CMD_DOSYSEVENT,
    AT_SetEvdoSysEvent,    AT_SET_PARA_TIME,    VOS_NULL_PTR,    AT_NOT_SET_TIME,    VOS_NULL_PTR,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,    AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8 *)"^DOSYSEVENT",   (VOS_UINT8*)"(0-4294967295)"},

    {AT_CMD_DOSIGMASK,
    AT_SetDoSigMask,    AT_SET_PARA_TIME,    VOS_NULL_PTR,    AT_NOT_SET_TIME,    VOS_NULL_PTR,    AT_NOT_SET_TIME,
    VOS_NULL_PTR,    AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8 *)"^DOSIGMASK",   (VOS_UINT8*)"(0-4294967295)"},



    {AT_CMD_MIPIWR,
    AT_SetMipiWrPara,  AT_SET_PARA_TIME, VOS_NULL_PTR, AT_NOT_SET_TIME, VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^MIPIWR",  (TAF_UINT8*)"(0-9),(0-15),(0-255),(0-65535),(0-3)"},/*mode, slave_id,  address, data,channel*/

   {AT_CMD_MIPIRD,
    AT_SetMipiRdPara,  AT_SET_PARA_TIME, VOS_NULL_PTR, AT_NOT_SET_TIME, VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^MIPIRD",  (TAF_UINT8*)"(0-9),(0-1),(0-15),(0-255)"},

   {AT_CMD_SSIWR,
    AT_SetSSIWrPara, AT_SET_PARA_TIME, VOS_NULL_PTR, AT_QRY_PARA_TIME, VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^SSIWR",  (TAF_UINT8*)"(0-9),(0-1),(0-255),(0-65535)"}, /*mode, channel, address, data*/

    {AT_CMD_SSIRD,
    AT_SetSSIRdPara, AT_SET_PARA_TIME, VOS_NULL_PTR, AT_QRY_PARA_TIME, VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^SSIRD",  (TAF_UINT8*)"(0-9),(0-1),(0-255)"},/*mode, channel, address*/



    {AT_CMD_MIPIWREX,
    AT_SetMipiWrParaEx,  AT_SET_PARA_TIME, VOS_NULL_PTR, AT_NOT_SET_TIME, VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^MIPIWREX",  (TAF_UINT8*)"(0,1),(0-15),(0-15),(0-255),(1,2,4),(0-4294967295)"},/*extend_flag, mipi_id, slave_id, reg_addr, byte_cnt, value*/

   {AT_CMD_MIPIRDEX,
    AT_SetMipiRdParaEx,  AT_SET_PARA_TIME, VOS_NULL_PTR, AT_NOT_SET_TIME, VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^MIPIRDEX",  (TAF_UINT8*)"(0,1),(0-15),(0-15),(0-255),(1,2,4),(0-65535)"},/*extend_flag, mipi_id, slave_id, reg_addr, byte_cnt, speed_type,*/

    {AT_CMD_SECURESTATE,
    AT_SetSecureStatePara,   AT_NOT_SET_TIME,   AT_QrySecureStatePara,   AT_NOT_SET_TIME,   VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SECURESTATE", (VOS_UINT8*)"(0-2)"},

    {AT_CMD_KCE,
    AT_SetKcePara,   AT_NOT_SET_TIME,   VOS_NULL_PTR,   AT_NOT_SET_TIME,   VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^KCE", (VOS_UINT8*)"(@KceString)"},

    {AT_CMD_SOCID,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,   AT_QrySocidPara,   AT_NOT_SET_TIME,   VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SOCID", (VOS_UINT8*)"(@SocidString)"},

    {AT_CMD_DIVERSITYSWITCH,
    AT_SetCdmaAttDiversitySwitch,   AT_SET_PARA_TIME,   VOS_NULL_PTR,   AT_NOT_SET_TIME,   VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^DIVERSITYSWITCH", (VOS_UINT8*)"(0,1)"},

    {AT_CMD_SETSLAVE,
    AT_SetSlavePara,  AT_SET_PARA_TIME,   VOS_NULL_PTR,  AT_NOT_SET_TIME,   VOS_NULL_PTR,   AT_NOT_SET_TIME,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^SETSLAVE",   (VOS_UINT8*)"(0-2)"},

    {AT_CMD_RFICID,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,   AT_QryRficDieIDPara,   AT_QRY_PARA_TIME,   VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^RFICID", VOS_NULL_PTR},

    {AT_CMD_PMUDIESN,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,   AT_QryPmuDieSNPara,   AT_QRY_PARA_TIME,   VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,   AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^PMUDIESN", VOS_NULL_PTR},

    {AT_CMD_TAS_TEST,
    AT_SetTasTestCfg,   AT_SET_PARA_TIME, VOS_NULL_PTR,  AT_NOT_SET_TIME,  VOS_NULL_PTR,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^TXTASTEST",    (VOS_UINT8*)"(0-4294967295),(0-4294967295),(0-4294967295),(0-4294967295),(0-4294967295)"},

    {AT_CMD_TAS_TEST_QUERY,
    AT_QryTasTestCfgPara,   AT_SET_PARA_TIME, VOS_NULL_PTR,  AT_NOT_SET_TIME,  VOS_NULL_PTR,  AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (VOS_UINT8*)"^TXTASTESTQRY",    (VOS_UINT8*)"(0-4294967295)"},

   {AT_CMD_MIPIREAD,
    AT_SetMipiReadPara,  AT_SET_PARA_TIME, VOS_NULL_PTR, AT_NOT_SET_TIME, VOS_NULL_PTR, AT_NOT_SET_TIME,
    VOS_NULL_PTR,        AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_PIN_IS_LOCKED,
    (TAF_UINT8*)"^MIPIREAD",  (TAF_UINT8*)"(0,1),(0-15),(0-15),(0-65535),(0-2),(0-255),(0-255)"},/*read_type, mipi_id, slave_id, reg_addr, speed_type, read_bit_mask, reserved1*/

};


/* 示例: ^CMDX 命令是不受E5密码保护命令，且在+CLAC列举所有命令时不显示，第一个参数是不带双引号的字符串,
        第二个参数是带双引号的字符串，第三个参数是整数型参数

   !!!!!!!!!!!注意: param1和param2是示例，实际定义命令时应尽量定义的简短(可提高解析效率)!!!!!!!!!!!!!

    {AT_CMD_CMDX,
    At_SetCmdxPara, AT_SET_PARA_TIME, At_QryCmdxPara, AT_QRY_PARA_TIME, At_TestCmdxPara, AT_NOT_SET_TIME,
    AT_ERROR, CMD_TBL_E5_IS_LOCKED | CMD_TBL_CLAC_IS_INVISIBLE,
    (VOS_UINT8*)"^CMDX", (VOS_UINT8*)"(@param1),(param2),(0-255)"},
*/


/*****************************************************************************
  3 函数实现
*****************************************************************************/

/*****************************************************************************
 函 数 名  : At_QrySecuBootFeaturePara
 功能描述  : 查询单板软件是否是Secure Boot 版本，是否需要启动Secure Boot 功能
 输入参数  : 无
 输出参数  : 无
 返 回 值  : VOS_UINT32 AT_OK查询操作成功，AT_ERROR查询操作失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年12月18日
    作    者   : 傅映君/f62575
    修改内容   : 新生成函数

  2.日    期   : 2011年10月6日
    作    者   : 吴敏/w00181244
    修改内容   : 函数重构，将直接调用底软API改为发消息到C核调用底软API

  3.日    期   : 2012年08月08日
    作    者   : y00213812
    修改内容   : 根据DTS2012082100431修改，直接读取NV项
  4.日    期   : 2012年12月13日
    作    者   : L00171473
    修改内容   : DTS2012121802573, TQE清理
  5.日    期   : 2014年12月15日
    作    者   : Z00306637
    修改内容   : DTS2014120903868, 直接调用底软API
  6.日    期   : 2016年01月26日
    作    者   : w00249971
    修改内容   : DTS2016012510143, mbb扩展该AT，使之支持DX安全引擎加密
*****************************************************************************/
VOS_UINT32 At_QrySecuBootFeaturePara( VOS_UINT8 ucIndex )
{
    VOS_UINT8                          usSecBootSupportedFlag;
    usSecBootSupportedFlag = 0;

    /* 调用底软接口 */
    if(MDRV_OK != mdrv_crypto_secboot_supported(&usSecBootSupportedFlag))
    {
        AT_WARN_LOG("At_QrySecuBootFeaturePara: get mdrv_crypto_secboot_supported() failed");
        return AT_ERROR;
    }


    /* 打印输出 */
    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                            (VOS_CHAR *)pgucAtSndCodeAddr,
                                            (VOS_CHAR *)pgucAtSndCodeAddr,
                                            "%s: %d",
                                            g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                            usSecBootSupportedFlag);

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : AT_SetSecDbgState
 功能描述  : 按照安全产品设置指导书，设置相应debug权限
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32 AT_OK操作成功，AT_ERROR操作失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年4月14日
    作    者   : w00249971
    修改内容   : 新生成函数

*****************************************************************************/
VOS_INT32 AT_SetSecDbgState(VOS_VOID)
{
    VOS_INT32               usResult;

    /*1.执行SECUREDEBUG=3,设置安全DEBUG授权由安全证书控制*/
    usResult = mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_SET_SECUREDEBUG,
                                AT_SECUREDEBUG_VALUE,
                                NULL,
                                0);

    /*设置接口只有三种返回值，<0,执行错误；=0，执行正确；=1，重复设置；
      所以这里只判断返回错误情况*/
    if(MDRV_OK > usResult)
    {
        AT_WARN_LOG("AT_SetSecuState: set SECUREDEBUG state error.\n");
        return AT_ERROR;
    }

    /*2.执行SECDBGRESET=1和CSRESET=1,在对安全世界和Coresight调试时，
        临时复位SecEngine*/
    usResult = mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_SET_CSRESET,
                                AT_CSRESET_VALUE,
                                NULL,
                                0);
    if(MDRV_OK > usResult)
    {
        AT_WARN_LOG("AT_SetSecuState: set CSRESET state error.\n");
        return AT_ERROR;
    }

    /*3.执行DFTSEL=1 可以通过密码验证方式开启安全DFT功能*/
    usResult = mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_SET_DFTSEL,
                                AT_DFTSEL_VALUE,
                                NULL,
                                0);
    if(MDRV_OK > usResult)
    {
        AT_WARN_LOG("AT_SetSecuState: set CSRESET state error.\n");
        return AT_ERROR;
    }

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : At_SetSecuBootPara
 功能描述  : 使能Secure Boot 功能
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32 AT_OK使能操作成功，AT_ERROR使能操作失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年12月18日
    作    者   : 傅映君/f62575
    修改内容   : 新生成函数
  2.日    期   : 2011年3月21日
    作    者   : h44270
    修改内容   : DTS2011031601921,只有启动硬件加密的情况下，才能设置
  3.日    期   : 2012年02月06日
    作    者   : 傅映君/f62575
    修改内容   : 函数重构,将直接调用底软API改为发消息到C核调用底软API
  4.日    期   : 2014年12月15日
    作    者   : Z00306637
    修改内容   : DTS2014120903868, 直接调用底软API
  5.日    期   : 2016年01月21日
    作    者   : w00249971
    修改内容   : DTS2016012510143, mbb扩展该AT，使之支持DX安全引擎加密
*****************************************************************************/
VOS_UINT32 At_SetSecuBootPara(VOS_UINT8 ucIndex)
{
    if ((1 != gucAtParaIndex)
        || (0 == gastAtParaList[0].usParaLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if (AT_DX_SECURE_STATE < gastAtParaList[0].ulParaValue)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    switch(gastAtParaList[0].ulParaValue)
    {
        case AT_NO_DX_SECU_ENABLE_STATE:
        {
            if (MDRV_OK != mdrv_crypto_start_secure())
            {
                AT_WARN_LOG("At_SetSecuBootPara: mdrv_crypto_start_secure() failed");
                return AT_ERROR;
            }
            break;
        }
        case AT_DX_RMA_STATE:
        {
            /*先获取下芯片状态，如果已经设置为RMA状态，直接返回ok*/
            if(AT_DRV_STATE_RMA == mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_GET_SECURESTATE,
                                                    0, NULL, 0))
            {
                AT_WARN_LOG("At_SetSecuBootPara: chip is already set to RMA state");
                return AT_OK;
            }

            if (MDRV_OK != mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_SET_SECURESTATE,
                                            AT_SET_RMA_STATE, NULL, 0))
            {
                AT_WARN_LOG("At_SetSecuBootPara: SET_SECURE_DISABLED_STATE  failed");
                return AT_ERROR;
            }
            break;
        }
        case AT_DX_SECURE_STATE:
        {
            /*安全状态已经在Fastboot里设置，这里check下，以保证产线流程OK*/
            if(AT_DRV_STATE_SECURE != mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_GET_SECURESTATE,
                                                       0, NULL, 0))
            {
                AT_WARN_LOG("At_SetSecuBootPara: chip don't set to SECURE state");
                return AT_ERROR;
            }
            if (AT_OK != AT_SetSecDbgState())
            {
                return AT_ERROR;
            }
            break;
        }
        default:
        {
            return AT_CME_INCORRECT_PARAMETERS;
        }
    }

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : At_QrySecuBootPara
 功能描述  : 查询Secure Boot 功能使能状态
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32 AT_OK查询操作成功，AT_ERROR查询操作失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年12月18日
    作    者   : 傅映君/f62575
    修改内容   : 新生成函数

  2.日    期   : 2011年10月17日
    作    者   : 吴敏/w00181244
    修改内容   : 函数重构,将直接调用底软API改为发消息到C核调用底软API
  3.日    期   : 2014年12月15日
    作    者   : Z00306637
    修改内容   : DTS2014120903868, 直接调用底软API
  4.日    期   : 2016年01月26日
    作    者   : w00249971
    修改内容   : DTS2016012510143, mbb扩展该AT，使之支持DX安全引擎加密
*****************************************************************************/
VOS_UINT32 At_QrySecuBootPara(VOS_UINT8 ucIndex)
{
    VOS_UINT8                           usSecBootStartedFlag = 0;

    if(MDRV_OK != mdrv_crypto_sec_started(&usSecBootStartedFlag))
    {
        AT_WARN_LOG("At_QrySecuBootPara: get mdrv_crypto_sec_started() failed");
        return AT_ERROR;
    }

/*对于支持DX安全引擎的，需要查询芯片状态*/

    /* 打印输出 */
    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                            (VOS_CHAR *)pgucAtSndCodeAddr,
                                            (VOS_CHAR *)pgucAtSndCodeAddr,
                                            "%s: %d",
                                            g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                            usSecBootStartedFlag);

     return AT_OK;

}

/*****************************************************************************
 函 数 名  : At_SetKeyPara
 功能描述  : 设置key 值，具体key由参数决定
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32 AT_OK查询操作成功，AT_ERROR查询操作失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年4月14日
    作    者   : w00249971
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 At_SetKeyPara(VOS_UINT8 ucIndex)
{
    VOS_INT32                           usRet;
    VOS_UINT8                           aulKeyBuf[AT_AUTHKEY_LEN];

    if ((1 != gucAtParaIndex)
     || (0 == gastAtParaList[0].usParaLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if (AT_KEY_TYPE_BUTT <= gastAtParaList[0].ulParaValue)
    {
        AT_WARN_LOG("At_SetKeyPara: not support the para,pls check\n");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    TAF_MEM_SET_S(aulKeyBuf, (VOS_SIZE_T)sizeof(aulKeyBuf), 0x00, (VOS_SIZE_T)sizeof(aulKeyBuf));

    switch(gastAtParaList[0].ulParaValue)
    {
        case AT_KEY_TYPE_DIEID:
        case AT_KEY_TYPE_TBOX_SMS:
        case AT_KEY_TYPE_SOCID:
            break;
        case AT_KEY_TYPE_AUTHKEY:
        {
            get_random_bytes(aulKeyBuf, AT_AUTHKEY_LEN);

            usRet = mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_SET_AUTHKEY,
                                     0,
                                     aulKeyBuf,
                                     AT_AUTHKEY_LEN);
            if(MDRV_OK != usRet)
            {
                AT_WARN_LOG("At_SetKeyPara: mdrv_set_authkey error.\n");
                return AT_ERROR;
            }
            break;
        }
        default:
        {
            AT_WARN_LOG("At_SetKeyPara: para is error,pls check.\n");
            return AT_CME_INCORRECT_PARAMETERS;
        }
    }
    return AT_OK;
}

/*****************************************************************************
 函 数 名  : At_GetKeyInfoPara
 功能描述  : 查询key 值，具体key由参数决定
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32 AT_OK查询操作成功，AT_ERROR查询操作失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年4月14日
    作    者   : w00249971
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 At_GetKeyInfoPara(VOS_UINT8 ucIndex)
{
    VOS_INT                 iResult;
    VOS_UINT16              usLength;
    VOS_UINT16              usKeyLen;
    VOS_UINT8               auckeybuf[AT_KEYBUFF_LEN];
    VOS_UINT8               usHashbuf[AT_KEY_HASH_LEN];
    VOS_UINT32              i;


    if (1 != gucAtParaIndex || (0 == gastAtParaList[0].usParaLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if (AT_KEY_TYPE_BUTT <= gastAtParaList[0].ulParaValue)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* 局部变量初始化 */
    TAF_MEM_SET_S(usHashbuf, (VOS_SIZE_T)sizeof(usHashbuf), 0x00, AT_KEY_HASH_LEN);
    TAF_MEM_SET_S(auckeybuf, (VOS_SIZE_T)sizeof(auckeybuf), 0x00, AT_KEYBUFF_LEN);

    switch(gastAtParaList[0].ulParaValue)
    {
        case AT_KEY_TYPE_DIEID:
        case AT_KEY_TYPE_TBOX_SMS:
        {
            /*打桩，暂不处理*/
            return AT_OK;
        }
        case AT_KEY_TYPE_SOCID:
        {
            usKeyLen = AT_SOCID_LEN;
            iResult = mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_GET_SOCID,
                                       0,
                                       auckeybuf,
                                       AT_SOCID_LEN);

            /* 处理异常查询结果 */
            if (MDRV_OK != iResult)
            {
                AT_WARN_LOG("At_QryGetKeyInfoPara:get soc id error.\n");
                return AT_ERROR;
            }
            break;
        }
        case AT_KEY_TYPE_AUTHKEY:
        {
            usKeyLen = AT_AUTHKEY_LEN;
            iResult = mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_GET_AUTHKEY,
                                       0,
                                       auckeybuf,
                                       AT_AUTHKEY_LEN);
            if(MDRV_OK != iResult)
            {
                AT_WARN_LOG("At_QryGetKeyInfoPara:get authkey error.\n");
                return AT_ERROR;
            }
            break;
        }
        default:
        {
            return AT_CME_INCORRECT_PARAMETERS;
        }

    }

    /*计算hash值,基线打桩，产品线适配*/
    /*
    iResult = mdrv_crypto_hash256(auckeybuf, usKeyLen, usHashbuf);
    if(MDRV_OK != iResult)
    {
        AT_WARN_LOG("At_QryGetKeyInfoPara:get hash error.\n");
        return AT_ERROR;
    } */

    /* 打印输出AT名称 */
    usLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                     (VOS_CHAR *)pgucAtSndCodeAddr,
                                     (VOS_CHAR *)pgucAtSndCodeAddr,
                                      "%s:%s",
                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                     gaucAtCrLf);

    /*key info*/
    for(i = 0; i < usKeyLen; i++)
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                         (VOS_CHAR *)pgucAtSndCodeAddr,
                                         (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                          "%02X",
                                          auckeybuf[i]);

    }
    /*key len*/
    usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                         (VOS_CHAR *)pgucAtSndCodeAddr,
                                         (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                          ",%d,",
                                          usKeyLen * 2);
    /*key hash*/
    for(i = 0; i < AT_KEY_HASH_LEN; i++)
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                         (VOS_CHAR *)pgucAtSndCodeAddr,
                                         (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                          "%02x",
                                          usHashbuf[i]);

    }
    gstAtSendData.usBufLen = usLength;
    return AT_OK;
}

/*****************************************************************************
 函 数 名  : At_TestTmodePara
 功能描述  : TMODE测试函数
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年10月9日
    作    者   : w00181244
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 At_TestTmodePara(VOS_UINT8 ucIndex)
{
    VOS_UINT16                          usLength;

    usLength = 0;

    usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                  (VOS_CHAR *)pgucAtSndCodeAddr,
                                  (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                  "%s: %d",
                                  g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                  g_stAtDevCmdCtrl.ucCurrentTMode);

    gstAtSendData.usBufLen = usLength;

    return AT_OK;

}

/*****************************************************************************
 函 数 名  : At_TestFdacPara
 功能描述  : FDAC测试函数
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年10月9日
    作    者   : w00181244
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 At_TestFdacPara(VOS_UINT8 ucIndex)
{
    VOS_UINT16                          usLength;

    usLength  = 0;

    if ((AT_RAT_MODE_WCDMA == g_stAtDevCmdCtrl.ucDeviceRatMode)
     || (AT_RAT_MODE_AWS == g_stAtDevCmdCtrl.ucDeviceRatMode))
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                          (VOS_CHAR *)pgucAtSndCodeAddr,
                                          (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                          "%s: (0-2047)",
                                          g_stParseContext[ucIndex].pstCmdElement->pszCmdName);
    }
    else
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                          (VOS_CHAR *)pgucAtSndCodeAddr,
                                          (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                          "%s: (0-1023)",
                                          g_stParseContext[ucIndex].pstCmdElement->pszCmdName);
    }
    gstAtSendData.usBufLen = usLength;

    return AT_OK;

}

/*****************************************************************************
 函 数 名  : At_RegisterDeviceCmdTable
 功能描述  : 注册装备命令表
 输入参数  : VOS_VOID
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年10月21日
    作    者   : 鲁琳/l60609
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 At_RegisterDeviceCmdTable(VOS_VOID)
{
    return AT_RegisterCmdTable(g_astAtDeviceCmdTbl, sizeof(g_astAtDeviceCmdTbl)/sizeof(g_astAtDeviceCmdTbl[0]));
}

/* Added by f62575 for AT Project, 2011-10-28, begin */

/*****************************************************************************
 函 数 名  : AT_TestSsidPara
 功能描述  : SSID测试命令
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年10月28日
    作    者   : f62575
    修改内容   : 新生成函数
  2.日    期   : 2012年9月17日
    作    者   : z60575
    修改内容   : MULTI_SSID修改
*****************************************************************************/
VOS_UINT32 AT_TestSsidPara(VOS_UINT8 ucIndex)
{
    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */
    if (BSP_MODULE_UNSUPPORT == mdrv_misc_support_check(BSP_MODULE_TYPE_WIFI))
    {
        return AT_ERROR;
    }
    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */

    /* Modified by z60575 for multi_ssid, 2012-9-5 begin */
    gstAtSendData.usBufLen = (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (TAF_CHAR *)pgucAtSndCodeAddr,
                                                    (TAF_CHAR *)pgucAtSndCodeAddr,
                                                    "%s:%d",
                                                    g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                    AT_WIFI_MAX_SSID_NUM);
    /* Modified by z60575 for multi_ssid, 2012-9-5 end */
    return AT_OK;
}

/*****************************************************************************
 函 数 名  : AT_TestWikeyPara
 功能描述  : WIKEY测试命令
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年10月28日
    作    者   : f62575
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_TestWikeyPara(VOS_UINT8 ucIndex)
{
    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */
    if (BSP_MODULE_UNSUPPORT == mdrv_misc_support_check(BSP_MODULE_TYPE_WIFI) )
    {
        return AT_ERROR;
    }
    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */

    gstAtSendData.usBufLen = (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (TAF_CHAR *)pgucAtSndCodeAddr,
                                                    (TAF_CHAR *)pgucAtSndCodeAddr,
                                                    "%s:%d",
                                                    g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                    AT_WIFI_KEY_NUM);
    return AT_OK;
}

/* Added by f62575 for AT Project, 2011-10-28, end */

/* Added by f62575 for SMALL IMAGE, 2012-1-3, begin   */
/*****************************************************************************
 函 数 名  : AT_SetTbatPara
 功能描述  : ^TBAT设置命令
 输入参数  : VOS_UINT8 ucIndex      用户索引
 输出参数  : 无
 返 回 值  : VOS_UINT32             ATC返回码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月2日
    作    者   : f62575
    修改内容   : 新生成函数
 2.日    期   : 2012年03月03日
   作    者   : s62952
   修改内容   : BalongV300R002 Build优化项目:删除FEATURE_CHARGE宏

*****************************************************************************/
VOS_UINT32 AT_SetTbatPara(VOS_UINT8 ucIndex)
{
    return atSetTBATPara(ucIndex);

    /*
    根据参数不同进行下述操作:
    1.  支持用户输入AT^TBAT=1,0获取电池电压数字值；
    调用底软/OM接口获取电池数字值
    2.  支持用户输入AT^TBAT=1,1,<value1>,<value2>设置电池电压数字值，用于电池校准；
    写校准电压到NVID 90(en_NV_Item_BATTERY_ADC)，此处有疑问待确认，
    en_NV_Item_BATTERY_ADC中记录的是下述两个值，而AT命令仅一个参数，如何映射
    3.4V 电压对应的ADC值
    4.2V 电压对应的ADC值
    */
}

/*****************************************************************************
 函 数 名  : AT_QryTbatPara
 功能描述  : ^TBAT查询命令，用于获取电池的安装方式
 输入参数  : VOS_UINT8 ucIndex      用户索引
 输出参数  : 无
 返 回 值  : VOS_UINT32             ATC返回码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月2日
    作    者   : f62575
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_QryTbatPara(VOS_UINT8 ucIndex)
{
    /*
    调用底软接口获取电池安装方式:
    <mount type> 电池安装方式
    0 无电池
    1 可更换电池
    2 内置一体化电池
    */
    /*命令状态类型检查*/
    if (AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_DEVICE_OTHER_ERROR;
    }

    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */
    if (BSP_MODULE_UNSUPPORT == mdrv_misc_support_check(BSP_MODULE_TYPE_CHARGE) )
    {
        return AT_ERROR;
    }
    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */

    if (TAF_SUCCESS == AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                               gastAtClientTab[ucIndex].opId,
                                               DRV_AGENT_TBAT_QRY_REQ,
                                               VOS_NULL_PTR,
                                               0,
                                               I0_WUEPS_PID_DRV_AGENT))
    {
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_TBAT_QRY;             /*设置当前操作模式 */
        return AT_WAIT_ASYNC_RETURN;                                                              /* 等待异步事件返回 */
    }
    else
    {
        return AT_ERROR;
    }
}

/*****************************************************************************
 函 数 名  : AT_SetPstandbyPara
 功能描述  : 设置单板进入到待机状态。
 输入参数  : VOS_UINT8 ucIndex      用户索引
 输出参数  : 无
 返 回 值  : VOS_UINT32             ATC返回码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月2日
    作    者   : f62575
    修改内容   : 新生成函数

  2.日    期   : 2012年2月21日
    作    者   : w00199382
    修改内容   : B060项目增加底软相关接口调用
  3.日    期   : 2012年03月03日
    作    者   : s62952
    修改内容   : BalongV300R002 Build优化项目 :删除特性宏
  4.日    期   : 2012年04月13日
    作    者   : f62575
    修改内容   : V7代码同步: 删除WIFI_POWER_SHUTDOWN，oledPwrOff和DRV_PWRCTRL_USB_LOWPOWER_ENTER的调用，
                        替换为DRV_PWRCTRL_STANDBYSTATEACPU (BSP_PWRCTRL_StandbyStateAcpu)
  5.日    期   : 2014年2月14日
    作    者   : w00167002
    修改内容   : L-C互操作项目:开关机函数调整
*****************************************************************************/
VOS_UINT32 AT_SetPstandbyPara(VOS_UINT8 ucIndex)
{
    DRV_AGENT_PSTANDBY_REQ_STRU         stPstandbyInfo;

    /* Added by c64416 for ^PSTANDBY low power proc, 2013-9-13, Begin */

    /* Modified by w00167002 for L-C互操作项目, 2014-2-14, begin */
    TAF_MMA_PHONE_MODE_PARA_STRU        stPhoneModePara;
    /* Modified by w00167002 for L-C互操作项目, 2014-2-14, end */

    /* Added by c64416 for ^PSTANDBY low power proc, 2013-9-13, End */

    /* ^PSTANDBY设置命令有且仅有2个参数: 进入待机状态的时间长度和单板进入待机状态的切换时间 */
    if(AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if ((0 == gastAtParaList[0].usParaLen)
     || (0 == gastAtParaList[1].usParaLen)
     || (2 != gucAtParaIndex))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    At_FormatResultData(ucIndex, AT_OK); /*需要先回复OK*/

    /*保证返回数据发送完成*/
    VOS_TaskDelay(10);

    /*
    调用底软和OM接口使单板进入待机状态:
    ACPU上完成的操作：
    1、下电WIFI
    2、LED下电
    3、USB PowerOff

    发消息到C核，指示CCPU上完成的操作：
    1、通信模块下电
    2、关定时器
    3、关中断
    4、调用底软接口进入深睡
    */
    /* Modify by f62575 for V7代码同步, 2012-04-07, Begin   */
    stPstandbyInfo.ulStandbyTime = gastAtParaList[0].ulParaValue;
    stPstandbyInfo.ulSwitchTime   = gastAtParaList[1].ulParaValue;

    DRV_PWRCTRL_STANDBYSTATEACPU(stPstandbyInfo.ulStandbyTime, stPstandbyInfo.ulSwitchTime);

    /*发送消息到c核*/
    if (TAF_SUCCESS != AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                           gastAtClientTab[ucIndex].opId,
                           DRV_AGENT_PSTANDBY_SET_REQ,
                           &stPstandbyInfo,
                           sizeof(stPstandbyInfo),
                           I0_WUEPS_PID_DRV_AGENT))
    {
        AT_ERR_LOG("AT_SetPstandbyPara: AT_FillAndSndAppReqMsg fail.");
    }

    /* Added by c64416 for ^PSTANDBY low power proc, 2013-9-13, Begin */
    /* V7R2采用关机进入低功耗流程流程 */

    /* Modified by w00167002 for L-C互操作项目, 2014-2-14, begin */
    stPhoneModePara.PhMode = TAF_PH_MODE_MINI;

    if (VOS_TRUE == TAF_MMA_PhoneModeSetReq(WUEPS_PID_AT, gastAtClientTab[ucIndex].usClientId, 0, &stPhoneModePara))
    {
        /* Modified by zwx247453 for pc工程转3650, 2015-08-24, begin */
        /* 设置当前操作类型 */
        gastAtClientTab[ucIndex].CmdCurrentOpt = (AT_CMD_CURRENT_OPT_ENUM)AT_CMD_PSTANDBY_SET;
        /* Modified by zwx247453 for pc工程转3650, 2015-08-24, end */

        return AT_WAIT_ASYNC_RETURN;    /* 返回命令处理挂起状态 */
    }
    /* Modified by w00167002 for L-C互操作项目, 2014-2-14, end */
    /* Added by c64416 for ^PSTANDBY low power proc, 2013-9-13, End */

    return AT_SUCCESS;
}

/* DTS2012041801532 w00182550 NV归一化 start in 2012-04-12 */
VOS_UINT32 AT_SetExbandInfoPara(VOS_UINT8 ucIndex)
{
    LTE_COMM_NON_STANDARD_BAND_COMM_STRU stLpsNonstandBand = {0};
    VOS_UINT32 ulRet  = AT_OK;
    VOS_UINT32 ulNvId = 0;

    /* 1、AT命令类型是否正确 */
    if(AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* 2、参数个数是否符合要求 */
    if(1 != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    ulNvId = gastAtParaList[0].ulParaValue -LTE_COMM_NONSTANDARD_BAND_BEGIN  + EN_NV_ID_BANDNon1_BAND_INFO  ;
    if((ulNvId < EN_NV_ID_BANDNon1_BAND_INFO )||(ulNvId > EN_NV_ID_BANDNon16_BAND_INFO))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    ulRet = NVM_Read(ulNvId, (VOS_VOID*) &stLpsNonstandBand, sizeof(LTE_COMM_NON_STANDARD_BAND_COMM_STRU));
     if(  NV_OK != ulRet)
     {
        (VOS_VOID)vos_printf("read non stand band nv fail,ulNvId = %d,ulRet = %d!\n",ulNvId,ulRet);
        return AT_ERROR;
     }

    gstAtSendData.usBufLen = (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (TAF_CHAR *)pgucAtSndCodeAddr,
                                                    (TAF_CHAR *)pgucAtSndCodeAddr,
                                                    "%s:BANDNO:%d\r\n",
                                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                     stLpsNonstandBand.ucBandID);


    gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (TAF_CHAR *)pgucAtSndCodeAddr,
                                                    (TAF_CHAR *)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                     "%s:DUPLEX:%d\r\n",
                                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                     stLpsNonstandBand.enBandMode);

    gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                (TAF_CHAR *)pgucAtSndCodeAddr,
                                                (TAF_CHAR *)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                   "%s:FREQ:%d,%d,%d,%d\r\n",
                                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                    stLpsNonstandBand.stUlFreqInfo.usFLow,
                                                    stLpsNonstandBand.stUlFreqInfo.usFHigh,
                                                    stLpsNonstandBand.stDlFreqInfo.usFLow,
                                                    stLpsNonstandBand.stDlFreqInfo.usFHigh
                                                 );

    gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                (TAF_CHAR *)pgucAtSndCodeAddr,
                                                (TAF_CHAR *)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                   "%s:CHANNUM:%d,%d\r\n",
                                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                    stLpsNonstandBand.stUlFreqInfo.ulRangOfNLow,
                                                    stLpsNonstandBand.stDlFreqInfo.ulRangOfNLow);

     return AT_OK;
}

VOS_UINT32 AT_SetExbandTestInfoPara(VOS_UINT8 ucIndex)
{
    LTE_COMM_NON_STANDARD_BAND_COMM_STRU stLpsNonstandBand = {0};
    VOS_UINT32 ulRet  = AT_OK;
    VOS_UINT32 ulNvId = 0,ulArrayID=0 ,i=0;

    VOS_UINT32 BandWidthArray[BAND_WIDTH_NUMS]= {14,30,50,100,150,200};

    /* 1、AT命令类型是否正确 */
    if(AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* 2、参数个数是否符合要求 */
    if(2 != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    ulNvId = gastAtParaList[0].ulParaValue -LTE_COMM_NONSTANDARD_BAND_BEGIN  + EN_NV_ID_BANDNon1_BAND_INFO  ;

    if((ulNvId  < EN_NV_ID_BANDNon1_BAND_INFO ) ||(ulNvId > EN_NV_ID_BANDNon16_BAND_INFO))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    ulRet = NVM_Read(ulNvId, (VOS_VOID*) &stLpsNonstandBand, sizeof(LTE_COMM_NON_STANDARD_BAND_COMM_STRU));

    if(  NV_OK != ulRet)
    {
        (VOS_VOID)vos_printf("read non stand band nv fail,ulRet = %d!\n",ulRet);
        return AT_ERROR;
    }

    ulArrayID = BandWidthArray[BAND_WIDTH_NUMS -1];

    for(i = 0 ; i < BAND_WIDTH_NUMS; i++)
    {
        if( BandWidthArray[i] == gastAtParaList[1].ulParaValue)
        {
            ulArrayID = i;
            break;
        }
    }

    gstAtSendData.usBufLen = 0 ;

    gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (TAF_CHAR *)pgucAtSndCodeAddr,
                                                    (TAF_CHAR *)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                     "%s:FREQS:%d,%d,%d\r\n",
                                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                     stLpsNonstandBand.stTestInfo[ulArrayID].usTestFreqs[0],
                                                     stLpsNonstandBand.stTestInfo[ulArrayID].usTestFreqs[1],
                                                     stLpsNonstandBand.stTestInfo[ulArrayID].usTestFreqs[2]);

    gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                (TAF_CHAR *)pgucAtSndCodeAddr,
                                                (TAF_CHAR *)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                   "%s:MAXPOWTOLERANCE:%d,%d\r\n",
                                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                    stLpsNonstandBand.stUePowerClassInfo.sPowerToleranceHigh,
                                                    stLpsNonstandBand.stUePowerClassInfo.sPowerToleranceLow
                                                 );

    gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                (TAF_CHAR *)pgucAtSndCodeAddr,
                                                (TAF_CHAR *)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                   "%s:REFSENSPOW:%d\r\n",
                                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                   stLpsNonstandBand.stTestInfo[ulArrayID].sRxRefSensPower);
      return AT_OK;
}
/* DTS2012041801532 w00182550 NV归一化 end in 2012-04-12 */

/* Modify by z60575 for multi_ssid, 2012-9-5 begin */
/*****************************************************************************
 函 数 名  : AT_WriteWiWep
 功能描述  : 写WIFI KEY到NV项
 输入参数  : VOS_UINT32                          ulIndex        WIFI KEY在NV项中的索引
             VOS_UINT32                          ulWiWepLen     WIFI KEY长度
             VOS_UINT8                           aucWiWep[]     WIFI KEY内容
             AT_WIFI_SEC_STRU                   *pstWifiSecInfo WIFI KEY所在NV的数据结构
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月10日
    作    者   : f62575
    修改内容   : 新生成函数

  2.日    期   : 2012年4月6日
    作    者   : l60609
    修改内容   : DTS20120033007015:调整NV50012的结构四字节对齐
*****************************************************************************/
VOS_UINT32 AT_WriteWiWep(
    VOS_UINT32                          ulIndex,
    VOS_UINT8                           aucWiWep[],
    VOS_UINT16                          usWiWepLen,
    TAF_AT_MULTI_WIFI_SEC_STRU         *pstWifiSecInfo,
    VOS_UINT8                           ucGroup
)
{
    VOS_UINT32                          ulRet;
    VOS_UINT32                          ulLoop;
    VOS_UINT8                          *paucWifiWepKey;

    /* 因为仅修改en_NV_Item_WIFI_KEY中的WIFI KEY子项，所以需要先获取全部NV值，然后更新修改部分 */
    ulRet = NV_ReadEx(MODEM_ID_0, en_NV_Item_MULTI_WIFI_KEY, pstWifiSecInfo, sizeof(TAF_AT_MULTI_WIFI_SEC_STRU));
    if (NV_OK != ulRet)
    {
        AT_WARN_LOG("AT_WriteWiWep: Fail to read en_NV_Item_WIFI_KEY.");
        return AT_ERROR;
    }

    /* 根据index获取NV中保存的密码 */
    paucWifiWepKey = ((0 == ulIndex) ? pstWifiSecInfo->aucWifiWepKey1[ucGroup] :
                      ((1 == ulIndex) ? pstWifiSecInfo->aucWifiWepKey2[ucGroup] :
                      ((2 == ulIndex) ? pstWifiSecInfo->aucWifiWepKey3[ucGroup] : pstWifiSecInfo->aucWifiWepKey4[ucGroup])));

    /* 判断新的WIFI KEY与NV中记录的是否一致 */
    for (ulLoop = 0; ulLoop < AT_NV_WLKEY_LEN; ulLoop++)
    {
        if (paucWifiWepKey[ulLoop] != aucWiWep[ulLoop])
        {
            break;
        }
    }

    /* 判断新的WIFI KEY与NV中记录的一致则直接返回操作完成*/
    if (AT_NV_WLKEY_LEN == ulLoop)
    {
        return AT_OK;
    }

    /* 更新数据到NV项en_NV_Item_WIFI_KEY */
    TAF_MEM_SET_S(paucWifiWepKey, AT_WIFI_KEY_LEN_MAX, 0x00, AT_NV_WLKEY_LEN);

    TAF_MEM_CPY_S(paucWifiWepKey, AT_WIFI_KEY_LEN_MAX, aucWiWep, usWiWepLen);

    ulRet = NV_WriteEx(MODEM_ID_0, en_NV_Item_MULTI_WIFI_KEY, pstWifiSecInfo, sizeof(TAF_AT_MULTI_WIFI_SEC_STRU));
    if (NV_OK != ulRet)
    {
         AT_WARN_LOG("AT_WriteWiWep: Fail to write NV en_NV_Item_WIFI_KEY.");
         return AT_ERROR;
    }

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : AT_SetWiwepPara
 功能描述  : 设置指定INDEX的WiFi WEP（WIFI的KEY）内容
 输入参数  : VOS_UINT8 ucIndex      用户索引
 输出参数  : 无
 返 回 值  : VOS_UINT32             ATC返回码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月2日
    作    者   : f62575
    修改内容   : 新生成函数

  2.日    期   : 2012年4月6日
    作    者   : l60609
    修改内容   : DTS20120033007015:调整NV50012的结构四字节对齐

  3.日    期   : 2012年9月17日
    作    者   : z60575
    修改内容   : MULTI_SSID修改
*****************************************************************************/
VOS_UINT32 AT_SetWiwepPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                          ulIndex;
    VOS_UINT8                           ucGroup;
    VOS_UINT32                          ulRet;
    TAF_AT_MULTI_WIFI_SEC_STRU         *pstWifiSecInfo;

    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */
    if (BSP_MODULE_UNSUPPORT == mdrv_misc_support_check(BSP_MODULE_TYPE_WIFI))
    {
        return AT_ERROR;
    }
    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */

    /* 输入参数检查: 有且仅有< index >和< content >两个参数 */
    if(AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_ERROR;
    }

    if ((0 == gastAtParaList[0].usParaLen)
     || (0 == gastAtParaList[1].usParaLen)
     || (0 == gastAtParaList[2].usParaLen))
    {
        return AT_ERROR;
    }

    /* WIFI key 操作受DATALOCK保护 */
    if (VOS_TRUE == g_bAtDataLocked)
    {
        return AT_ERROR;
    }

    /* < index >必须在0-3范围内，< content >长度小于NV_WLKEY_LEN */
    ulIndex = gastAtParaList[0].ulParaValue;
    if (ulIndex > AT_WIWEP_CARD_WIFI_KEY_TOTAL)
    {
        return AT_ERROR;
    }

    if (gastAtParaList[1].usParaLen > AT_NV_WLKEY_LEN)
    {
        return AT_ERROR;
    }

    ucGroup = (VOS_UINT8)gastAtParaList[2].ulParaValue;

    if (ucGroup >= AT_WIFI_MAX_SSID_NUM)
    {
        return AT_ERROR;
    }

    /* 组装WIFI KEY到NV结构并更新数据到NV项en_NV_Item_WIFI_KEY */
    /*lint -save -e830 */
    pstWifiSecInfo = (TAF_AT_MULTI_WIFI_SEC_STRU *)PS_MEM_ALLOC(WUEPS_PID_AT,
                                                  sizeof(TAF_AT_MULTI_WIFI_SEC_STRU));
    /*lint -restore */
    if (VOS_NULL_PTR == pstWifiSecInfo)
    {
        return AT_ERROR;
    }

    ulRet = AT_WriteWiWep(ulIndex,
                          gastAtParaList[1].aucPara,
                          gastAtParaList[1].usParaLen,
                          pstWifiSecInfo,
                          ucGroup);
    /*lint -save -e830 */
    PS_MEM_FREE(WUEPS_PID_AT, pstWifiSecInfo);
    /*lint -restore */
    return ulRet;
}

/*****************************************************************************
 函 数 名  : AT_QryWiwepPara
 功能描述  : WIFI KEY信息查询
 输入参数  : VOS_UINT8 ucIndex      用户索引
 输出参数  : 无
 返 回 值  : VOS_UINT32             ATC返回码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月2日
    作    者   : f62575
    修改内容   : 新生成函数

  2.日    期   : 2012年4月6日
    作    者   : l60609
    修改内容   : DTS20120033007015:调整NV50012的结构四字节对齐
  3.日    期   : 2012年9月17日
    作    者   : z60575
    修改内容   : MULTI_SSID修改
*****************************************************************************/
VOS_UINT32 AT_QryWiwepPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                          ulRet;
    VOS_UINT32                          ulLoop;
    VOS_UINT16                          usLength;
    TAF_AT_MULTI_WIFI_SEC_STRU         *pstWifiSecInfo;
    VOS_UINT8                           aucWifiWepKey[AT_NV_WLKEY_LEN + 1];
    VOS_UINT8                           aucWepKeyLen1[AT_WIFI_MAX_SSID_NUM];
    VOS_UINT8                           aucWepKeyLen2[AT_WIFI_MAX_SSID_NUM];
    VOS_UINT8                           aucWepKeyLen3[AT_WIFI_MAX_SSID_NUM];
    VOS_UINT8                           aucWepKeyLen4[AT_WIFI_MAX_SSID_NUM];
    VOS_UINT8                           ucWepKeyNum;

    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */
    if (BSP_MODULE_UNSUPPORT == mdrv_misc_support_check(BSP_MODULE_TYPE_WIFI))
    {
        return AT_ERROR;
    }
    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */

    /* 为读取WIFI KEY申请内存，读NV项en_NV_Item_WIFI_KEY获取WIFI KEY信息 */
    pstWifiSecInfo = (TAF_AT_MULTI_WIFI_SEC_STRU *)PS_MEM_ALLOC(WUEPS_PID_AT,
                                                      sizeof(TAF_AT_MULTI_WIFI_SEC_STRU));
    if (VOS_NULL_PTR == pstWifiSecInfo)
    {
        return AT_ERROR;
    }

    ulRet = NV_ReadEx(MODEM_ID_0, en_NV_Item_MULTI_WIFI_KEY, pstWifiSecInfo, sizeof(TAF_AT_MULTI_WIFI_SEC_STRU));
    if (NV_OK != ulRet)
    {
        AT_WARN_LOG("AT_QryWiwepPara: Fail to read en_NV_Item_WIFI_KEY.");
        PS_MEM_FREE(WUEPS_PID_AT, pstWifiSecInfo);
        return AT_ERROR;
    }

    ucWepKeyNum = 0;
    TAF_MEM_SET_S(aucWepKeyLen1, sizeof(aucWepKeyLen1), 0x00, sizeof(aucWepKeyLen1));
    TAF_MEM_SET_S(aucWepKeyLen2, sizeof(aucWepKeyLen2), 0x00, sizeof(aucWepKeyLen2));
    TAF_MEM_SET_S(aucWepKeyLen3, sizeof(aucWepKeyLen3), 0x00, sizeof(aucWepKeyLen3));
    TAF_MEM_SET_S(aucWepKeyLen4, sizeof(aucWepKeyLen4), 0x00, sizeof(aucWepKeyLen4));

    for (ulLoop = 0; ulLoop < AT_WIFI_MAX_SSID_NUM; ulLoop++)
    {
        /* KEY1对应的NV不空表示KEY1有效 */
        aucWepKeyLen1[ulLoop] = (VOS_UINT8)VOS_StrLen((VOS_CHAR*)pstWifiSecInfo->aucWifiWepKey1[ulLoop]);
        if (0 != aucWepKeyLen1[ulLoop])
        {
            ucWepKeyNum++;
        }

        aucWepKeyLen2[ulLoop] = (VOS_UINT8)VOS_StrLen((VOS_CHAR*)pstWifiSecInfo->aucWifiWepKey2[ulLoop]);
        if (0 != aucWepKeyLen2[ulLoop])
        {
            ucWepKeyNum++;
        }

        aucWepKeyLen3[ulLoop] = (VOS_UINT8)VOS_StrLen((VOS_CHAR*)pstWifiSecInfo->aucWifiWepKey3[ulLoop]);
        if (0 != aucWepKeyLen3[ulLoop])
        {
            ucWepKeyNum++;
        }

        aucWepKeyLen4[ulLoop] = (VOS_UINT8)VOS_StrLen((VOS_CHAR*)pstWifiSecInfo->aucWifiWepKey4[ulLoop]);
        if (0 != aucWepKeyLen4[ulLoop])
        {
            ucWepKeyNum++;
        }
    }

    /* 未解锁时，需要返回已定制0组 */
    if (VOS_TRUE == g_bAtDataLocked)
    {
        ucWepKeyNum = 0;
        TAF_MEM_SET_S(aucWepKeyLen1, sizeof(aucWepKeyLen1), 0x00, sizeof(aucWepKeyLen1));
        TAF_MEM_SET_S(aucWepKeyLen2, sizeof(aucWepKeyLen2), 0x00, sizeof(aucWepKeyLen2));
        TAF_MEM_SET_S(aucWepKeyLen3, sizeof(aucWepKeyLen3), 0x00, sizeof(aucWepKeyLen3));
        TAF_MEM_SET_S(aucWepKeyLen4, sizeof(aucWepKeyLen4), 0x00, sizeof(aucWepKeyLen4));
    }

    /*
    满足工位对接要求，需要输出工位支持的全部数20个WiFi WEP（WIFI的KEY）
    打印四组单板支持的WIFI KEY信息
    填充16行^WIWEP: <index>,与工位要求的20个的WiFi WEP（WIFI的KEY）一致，
    */
    usLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                     (VOS_CHAR *)pgucAtSndCodeAddr,
                                     (VOS_CHAR *)pgucAtSndCodeAddr,
                                     "%s:%d%s",
                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                     ucWepKeyNum,
                                     gaucAtCrLf);

    for (ulLoop = 0; ulLoop < AT_WIFI_MAX_SSID_NUM; ulLoop++)
    {
        if (0 != aucWepKeyLen1[ulLoop])
        {
            /* wifikey1 */
            TAF_MEM_SET_S(aucWifiWepKey, sizeof(aucWifiWepKey), 0x00, (VOS_SIZE_T)(AT_NV_WLKEY_LEN + 1));

            TAF_MEM_CPY_S(aucWifiWepKey,
                       sizeof(aucWifiWepKey),
                       pstWifiSecInfo->aucWifiWepKey1[ulLoop],
                       AT_NV_WLKEY_LEN);

            usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                              (VOS_CHAR *)pgucAtSndCodeAddr,
                                              (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                              "%s:%d,%s,%d%s",
                                              g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                              0,
                                              aucWifiWepKey,
                                              ulLoop,
                                              gaucAtCrLf);
        }

        if (0 != aucWepKeyLen2[ulLoop])
        {
            /* wifikey1 */
            TAF_MEM_SET_S(aucWifiWepKey, sizeof(aucWifiWepKey), 0x00, (VOS_SIZE_T)(AT_NV_WLKEY_LEN + 1));

            TAF_MEM_CPY_S(aucWifiWepKey,
                       sizeof(aucWifiWepKey),
                       pstWifiSecInfo->aucWifiWepKey2[ulLoop],
                       AT_NV_WLKEY_LEN);

            usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                              (VOS_CHAR *)pgucAtSndCodeAddr,
                                              (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                              "%s:%d,%s,%d%s",
                                              g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                              1,
                                              aucWifiWepKey,
                                              ulLoop,
                                              gaucAtCrLf);
        }

        if (0 != aucWepKeyLen3[ulLoop])
        {
            /* wifikey1 */
            TAF_MEM_SET_S(aucWifiWepKey, sizeof(aucWifiWepKey), 0x00, (VOS_SIZE_T)(AT_NV_WLKEY_LEN + 1));

            TAF_MEM_CPY_S(aucWifiWepKey,
                       sizeof(aucWifiWepKey),
                       pstWifiSecInfo->aucWifiWepKey3[ulLoop],
                       AT_NV_WLKEY_LEN);

            usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                              (VOS_CHAR *)pgucAtSndCodeAddr,
                                              (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                              "%s:%d,%s,%d%s",
                                              g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                              2,
                                              aucWifiWepKey,
                                              ulLoop,
                                              gaucAtCrLf);
        }

        if (0 != aucWepKeyLen4[ulLoop])
        {
            /* wifikey1 */
            TAF_MEM_SET_S(aucWifiWepKey, sizeof(aucWifiWepKey), 0x00, (VOS_SIZE_T)(AT_NV_WLKEY_LEN + 1));

            TAF_MEM_CPY_S(aucWifiWepKey,
                       sizeof(aucWifiWepKey),
                       pstWifiSecInfo->aucWifiWepKey4[ulLoop],
                       AT_NV_WLKEY_LEN);

            usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                              (VOS_CHAR *)pgucAtSndCodeAddr,
                                              (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                              "%s:%d,%s,%d%s",
                                              g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                              3,
                                              aucWifiWepKey,
                                              ulLoop,
                                              gaucAtCrLf);
        }
    }

    gstAtSendData.usBufLen = usLength - (VOS_UINT16)VOS_StrLen((VOS_CHAR *)gaucAtCrLf);

    PS_MEM_FREE(WUEPS_PID_AT, pstWifiSecInfo);

    return AT_OK;
}
/* Modify by z60575 for multi_ssid, 2012-9-5 end */

/*****************************************************************************
 函 数 名  : AT_TestWiwepPara
 功能描述  : WIWEP的测试命令，输出工位支持的WIFI KEY总数
 输入参数  : VOS_UINT8 ucIndex      用户索引
 输出参数  : 无
 返 回 值  : VOS_UINT32             ATC返回码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月3日
    作    者   : f62575
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_TestWiwepPara(VOS_UINT8 ucIndex)
{
    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */
    if (BSP_MODULE_UNSUPPORT == mdrv_misc_support_check(BSP_MODULE_TYPE_WIFI) )
    {
        return AT_ERROR;
    }
    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */

    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                   (VOS_CHAR *)pgucAtSndCodeAddr,
                                                   (VOS_CHAR *)pgucAtSndCodeAddr,
                                                   "%s:%d",
                                                   g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                   AT_WIWEP_TOOLS_WIFI_KEY_TOTAL);

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : AT_TestWifiPaRangePara
 功能描述  : AT^WIPARANGE测试函数
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年02月02日
    作    者   : l00198894
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_TestWifiPaRangePara (VOS_UINT8 ucIndex)
{
    AT_WIFI_MODE_ENUM_UINT8             ucWifiMode;

    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */
    if (BSP_MODULE_UNSUPPORT == mdrv_misc_support_check(BSP_MODULE_TYPE_WIFI) )
    {
        return AT_ERROR;
    }
    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */

    /* 初始化 */
    ucWifiMode                          = (VOS_UINT8)WIFI_GET_PA_MODE();

    /* 查询单板支持的模式：如果只支持PA模式，没有NO PA模式，则只返回h即可，如果两种模式都支持，则返回h,l。*/
    if (AT_WIFI_MODE_ONLY_PA == ucWifiMode)
    {
        gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                (VOS_CHAR *)pgucAtSndCodeAddr,
                                                (VOS_CHAR *)pgucAtSndCodeAddr,
                                                "%s:%s",
                                                g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                "h");
    }
    else if (AT_WIFI_MODE_ONLY_NOPA == ucWifiMode)
    {
        gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                (VOS_CHAR *)pgucAtSndCodeAddr,
                                                (VOS_CHAR *)pgucAtSndCodeAddr,
                                                "%s:%s",
                                                g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                "l");
    }
    else if (AT_WIFI_MODE_PA_NOPA == ucWifiMode)
    {
        gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                (VOS_CHAR *)pgucAtSndCodeAddr,
                                                (VOS_CHAR *)pgucAtSndCodeAddr,
                                                "%s:%s",
                                                g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                "h,l");
    }
    else
    {
        return AT_ERROR;
    }

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : AT_GetTseLrfLoadDspInfo
 功能描述  : ^TSELRF命令是否触发LOAD DSP
 输入参数  : AT_TSELRF_PATH_ENUM_UINT32          enPath     射频通路编号
             VOS_BOOL                           *pbLoadDsp  是否触发LOAD DSP
                     VOS_FALSE                              不触发LOAD DSP操作
                     VOS_TRUE                               触发LOAD DSP操作
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月10日
    作    者   : f62575
    修改内容   : 新生成函数
  2.日    期   : 2012年01月16日
    作    者   : m00217266
    修改内容   : DSDA C核项目接口修改(load mode 修改)

*****************************************************************************/
VOS_VOID AT_GetTseLrfLoadDspInfo(
    AT_TSELRF_PATH_ENUM_UINT32          enPath,
    VOS_BOOL                           *pbLoadDsp,
    DRV_AGENT_TSELRF_SET_REQ_STRU      *pstTseLrf
)
{
    /* ^TSELRF命令设置的射频通路编号为GSM且当前已经LOAD了该通路，无需LOAD */
    if (AT_TSELRF_PATH_GSM == enPath)
    {
        if ((AT_RAT_MODE_GSM == g_stAtDevCmdCtrl.ucDeviceRatMode)
         && (VOS_TRUE == g_stAtDevCmdCtrl.bDspLoadFlag))
        {
            *pbLoadDsp = VOS_FALSE;
        }
        else
        {
            pstTseLrf->ucLoadDspMode     = VOS_RATMODE_GSM;
            pstTseLrf->ucDeviceRatMode   = AT_RAT_MODE_GSM;
            *pbLoadDsp                   = VOS_TRUE;
        }
        return;
    }

    /* ^TSELRF命令设置的射频通路编号为WCDMA主集且当前已经LOAD了该通路，无需LOAD */
    if (AT_TSELRF_PATH_WCDMA_PRI == enPath)
    {
        if (((AT_RAT_MODE_WCDMA == g_stAtDevCmdCtrl.ucDeviceRatMode)
          || (AT_RAT_MODE_AWS == g_stAtDevCmdCtrl.ucDeviceRatMode))
         && (VOS_TRUE == g_stAtDevCmdCtrl.bDspLoadFlag))
        {
            *pbLoadDsp = VOS_FALSE;
        }
        else
        {
            pstTseLrf->ucLoadDspMode     = VOS_RATMODE_WCDMA;
            pstTseLrf->ucDeviceRatMode   = AT_RAT_MODE_WCDMA;
            *pbLoadDsp                   = VOS_TRUE;
        }
        return;
    }

    *pbLoadDsp = VOS_FALSE;

    AT_WARN_LOG("AT_GetTseLrfLoadDspInfo: enPath only support GSM or WCDMA primary.");

    return;
}

/*****************************************************************************
 函 数 名  : AT_SetTseLrfPara
 功能描述  : ^TSELRF的设置操作
 输入参数  : VOS_UINT8 ucIndex  用户索引
 输出参数  : 无
 返 回 值  : VOS_UINT32 返回执行结果成功或相应错误码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月10日
    作    者   : f62575
    修改内容   : 新生成函数
  2.日    期   : 2012年4月21日
    作    者   : f62575
    修改内容   : V7代码同步: 增加PATH参数保护
  3.日    期   : 2012年05月04日
    作    者   : f62575
    修改内容   : DTS2012040600347，支持先配分集后打开接收机的新装备流程
  4.日    期   : 2012年05月05日
    作    者   : f62575
    修改内容   : DTS2012050502003，解决V7版本AT^TSELRF=1命令无响应问题

*****************************************************************************/
VOS_UINT32 AT_SetTseLrfPara(VOS_UINT8 ucIndex)
{
    DRV_AGENT_TSELRF_SET_REQ_STRU       stTseLrf;
    VOS_BOOL                            bLoadDsp;

    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_ERROR;
    }

    /*DTS2012041102190 : h00135900 start in 2011-04-11 AT代码融合*/
    if ((AT_TSELRF_PATH_WCDMA_PRI!=gastAtParaList[0].ulParaValue)
     && (AT_TSELRF_PATH_WCDMA_DIV!=gastAtParaList[0].ulParaValue)
     && (AT_TSELRF_PATH_GSM !=gastAtParaList[0].ulParaValue))
    {
        return atSetTselrfPara(ucIndex);
    }
    /*DTS2012041102190 : h00135900 end in 2011-04-11 AT代码融合*/

    if(AT_TSELRF_PATH_TD == gastAtParaList[0].ulParaValue)
    {
        return atSetTselrfPara(ucIndex);
    }

    /* 参数不符合要求 */
    if ((1 != gucAtParaIndex)
     || (0 == gastAtParaList[0].usParaLen))
    {
        return AT_ERROR;
    }

    if (AT_TSELRF_PATH_WIFI == gastAtParaList[0].ulParaValue)
    {
        /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */
        if ( BSP_MODULE_SUPPORT == mdrv_misc_support_check(BSP_MODULE_TYPE_WIFI) )
        {
            /*WIFI未Enable直接返回失败*/
            if(VOS_FALSE == (VOS_UINT32)WIFI_GET_STATUS())
            {
                return AT_ERROR;
            }

            g_stAtDevCmdCtrl.ucDeviceRatMode = AT_RAT_MODE_WIFI;

            return AT_OK;
        }
        else
        {
            return AT_ERROR;
        }
        /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, end */
    }

    if (AT_TMODE_FTM != g_stAtDevCmdCtrl.ucCurrentTMode)
    {
        return AT_ERROR;
    }

    /* 打开分集必须在FRXON之后，参考RXDIV实现 */
    if (AT_TSELRF_PATH_WCDMA_DIV == gastAtParaList[0].ulParaValue)
    {
        if (DRV_AGENT_DSP_RF_SWITCH_ON != g_stAtDevCmdCtrl.ucRxOnOff)
        {
            g_stAtDevCmdCtrl.ucPriOrDiv = AT_RX_DIV_ON;
            return AT_OK;
        }
        if (AT_FAILURE == At_SendRfCfgAntSelToHPA(AT_RX_DIV_ON, ucIndex))
        {
            return AT_ERROR;
        }

        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_TSELRF_SET;
        g_stAtDevCmdCtrl.ucIndex               = ucIndex;

        /* 返回命令处理挂起状态 */
        return AT_WAIT_ASYNC_RETURN;
    }

    /* Modify by f62575 for V7代码同步, 2012-04-07, Begin   */
    if ((AT_TSELRF_PATH_GSM != gastAtParaList[0].ulParaValue)
     && (AT_TSELRF_PATH_WCDMA_PRI != gastAtParaList[0].ulParaValue))
    {
        return AT_ERROR;
    }
    /* Modify by f62575 for V7代码同步, 2012-04-07, End   */

    if (AT_TSELRF_PATH_WCDMA_PRI == gastAtParaList[0].ulParaValue)
    {
        if (DRV_AGENT_DSP_RF_SWITCH_ON != g_stAtDevCmdCtrl.ucRxOnOff)
        {
            g_stAtDevCmdCtrl.ucPriOrDiv = AT_RX_PRI_ON;
            return AT_OK;
        }

        if (AT_FAILURE == At_SendRfCfgAntSelToHPA(AT_RX_PRI_ON, ucIndex))
        {
            return AT_ERROR;
        }

        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_TSELRF_SET;
        g_stAtDevCmdCtrl.ucIndex               = ucIndex;

        return AT_WAIT_ASYNC_RETURN;
    }

    /* 此处判断是否需要重新加载DSP: 需要则发请求到C核加载DSP，否则，直接返回OK */
    AT_GetTseLrfLoadDspInfo(gastAtParaList[0].ulParaValue, &bLoadDsp, &stTseLrf);
    if (VOS_TRUE == bLoadDsp)
    {
        if (TAF_SUCCESS == AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                                   gastAtClientTab[ucIndex].opId,
                                                   DRV_AGENT_TSELRF_SET_REQ,
                                                   &stTseLrf,
                                                   sizeof(stTseLrf),
                                                   I0_WUEPS_PID_DRV_AGENT))
        {
            gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_TSELRF_SET;             /*设置当前操作模式 */
            return AT_WAIT_ASYNC_RETURN;                                           /* 等待异步事件返回 */
        }
        else
        {
            return AT_ERROR;
        }
    }

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : AT_QryTseLrfPara
 功能描述  : 查询命令用来返回单板支持的所有情况，每种情况分行显示，每个<path>
             类型只显示一行，
             举例来说，如支持2组WIFI天线，可显示为”^TSELRF: 7,0,1”
 输入参数  : VOS_UINT8 ucIndex 用户索引
 输出参数  : 无
 返 回 值  : VOS_UINT32 返回执行结果成功或相应错误码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月10日
    作    者   : f62575
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_QryTseLrfPara(VOS_UINT8 ucIndex)
{

    /*DTS2012041102190 : h00135900 start in 2011-04-11 AT代码融合*/
    return atQryTselrfPara(ucIndex);

}

/*****************************************************************************
 函 数 名  : AT_SetCmdlenPara
 功能描述  : 告知单板PC一次期望发送的字符个数和PC期望单板一次发送的字符个数
             该命令用于支撑SIMLOCK数据的分段发送，BALONG无此需求，仅返回OK保证工
             位归一化流程正常执行
 输入参数  : VOS_UINT8 ucIndex      用户索引
 输出参数  : 无
 返 回 值  : VOS_UINT32             ATC返回码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月2日
    作    者   : f62575
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_SetCmdlenPara(VOS_UINT8 ucIndex)
{
    if(AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if ((0 == gastAtParaList[0].usParaLen)
     || (0 == gastAtParaList[1].usParaLen)
     || (2 != gucAtParaIndex))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if (gastAtParaList[0].ulParaValue > (AT_COM_BUFF_LEN - sizeof("AT")))
    {
        return AT_ERROR;
    }

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : AT_QryCmdlenPara
 功能描述  : 查询单板最大可以直接接收AT命令字符个数，以及单板通过AT一次最大
             可以响应的字符个数，该字符个数均不包含AT这两个字符。
 输入参数  : VOS_UINT8 ucIndex      用户索引
 输出参数  : 无
 返 回 值  : VOS_UINT32             ATC返回码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月2日
    作    者   : f62575
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_QryCmdlenPara(VOS_UINT8 ucIndex)
{
    /*
      输出单板最大可以直接接收AT命令字符个数(AT_CMD_MAX_LEN - sizeof("AT"))，
      该字符个数均不包含AT这两个字符，以及单板通过AT一次最大可以响应的字符个数，
      BALONG产品响应字符串长度可以分
      多次上报，没有最大值概念，工位对该值无处理，此处输出一次上报的最大值AT_CMD_MAX_LEN。
    */
    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    "%s:%d,%d",
                                                    g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                    (AT_COM_BUFF_LEN - VOS_StrLen("AT")),
                                                    AT_CMD_MAX_LEN);

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : AT_UpdateMacPara
 功能描述  : 更新MAC地址到NV
             是否支持2个MAC待确认；
 输入参数  : VOS_UINT8                           aucMac[]   MAC地址字符串首地址
             VOS_UINT16                          usMacLength    MAC地址字符串长度
 输出参数  : 无
 返 回 值  : VOS_UINT32
             操作成功，返回AT_OK
             物理号长度不合法返回AT_PHYNUM_LENGTH_ERR
             MT内部错误，返回AT_ERROR
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月3日
    作    者   : f62575
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_UpdateMacPara(
    VOS_UINT8                           aucMac[],
    VOS_UINT16                          usMacLength
)
{
    VOS_UINT32                          ulRet;
    VOS_UINT32                          ulLoop;
    VOS_UINT32                          ulWifiGlobalMacOffset;
    VOS_UINT32                          ulPhyNumMacOffset;
    VOS_UINT8                           aucWifiGlobalMac[AT_MAC_ADDR_LEN];

    /* MAC地址长度检查: 必须12位 */
    if (AT_PHYNUM_MAC_LEN != usMacLength)
    {
        return AT_PHYNUM_LENGTH_ERR;
    }

    /* MAC地址格式匹配: 7AFEE22111E4=>7A:FE:E2:21:11:E4*/
    ulWifiGlobalMacOffset = 0;
    ulPhyNumMacOffset     = 0;
    for (ulLoop = 0; ulLoop < (AT_PHYNUM_MAC_COLON_NUM + 1); ulLoop++)
    {
        TAF_MEM_CPY_S(&aucWifiGlobalMac[ulWifiGlobalMacOffset],
                   AT_MAC_ADDR_LEN - ulWifiGlobalMacOffset,
                   &aucMac[ulPhyNumMacOffset],
                   AT_WIFIGLOBAL_MAC_LEN_BETWEEN_COLONS);
        ulWifiGlobalMacOffset += AT_WIFIGLOBAL_MAC_LEN_BETWEEN_COLONS;
        ulPhyNumMacOffset     += AT_WIFIGLOBAL_MAC_LEN_BETWEEN_COLONS;
        aucWifiGlobalMac[ulWifiGlobalMacOffset] = ':';
        ulWifiGlobalMacOffset++;
    }

    aucWifiGlobalMac[AT_PHYNUM_MAC_LEN + AT_PHYNUM_MAC_COLON_NUM] = '\0';

    /* 更新MAC地址到NV */
    ulRet = NV_WriteEx(MODEM_ID_0, en_NV_Item_WIFI_MAC_ADDR, aucWifiGlobalMac, AT_MAC_ADDR_LEN);
    if (NV_OK != ulRet)
    {
         AT_WARN_LOG("AT_UpdateMacPara: Fail to write NV.");
         return AT_ERROR;
    }

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : AT_SetTmodeAutoPowerOff
 功能描述  : 自动关机的装备命令，仅E5产品形态支持，其他产品形态返回ERROR
             产线要求先通知用户AT命令已执行，满足产线的时效需求
             用户通过检测端口是否消失来确认任务是否正确执行
 输入参数  : VOS_UINT8 ucIndex      用户索引
 输出参数  : 无
 返 回 值  : VOS_UINT32             ATC返回码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月3日
    作    者   : f62575
    修改内容   : 新生成函数
  2.日    期   : 2012年12月13日
    作    者   : L00171473
    修改内容   : DTS2012121802573, TQE清理
  3.日    期   : 2014年2月14日
    作    者   : w00167002
    修改内容   : L-C互操作项目:开关机函数调整
*****************************************************************************/
VOS_UINT32 AT_SetTmodeAutoPowerOff(VOS_UINT8 ucIndex)
{
    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, begin */

    /* Modified by w00167002 for L-C互操作项目, 2014-2-14, begin */
    TAF_MMA_PHONE_MODE_PARA_STRU        stPhModeSet;
    /* Modified by w00167002 for L-C互操作项目, 2014-2-14, end */

    VOS_UINT8                             *pucSystemAppConfig;


    TAF_MEM_SET_S(&stPhModeSet, sizeof(stPhModeSet), 0x00, sizeof(TAF_MMA_PHONE_MODE_PARA_STRU));

    pucSystemAppConfig                    = AT_GetSystemAppConfigAddr();

    if ( SYSTEM_APP_WEBUI == *pucSystemAppConfig)
    {
        /* 发消息给C核通知关机并下电 */
        /* 先通知用户AT命令已执行，用户通过检测端口是否消失来确认任务是否正确执行
           此命令执行完成后已下电，无需等待异步返回
        */

        /* Modified by w00167002 for L-C互操作项目, 2014-2-14, begin */
        stPhModeSet.PhMode  = TAF_PH_MODE_POWEROFF;

        if (VOS_TRUE == TAF_MMA_PhoneModeSetReq(WUEPS_PID_AT, gastAtClientTab[ucIndex].usClientId, 0, &stPhModeSet))
        {
            return AT_OK;
        }
        /* Modified by w00167002 for L-C互操作项目, 2014-2-14, end */
        else
        {
            return AT_ERROR;
        }

    }
    /* Modified by s62952 for BalongV300R002 Build优化项目 2012-02-28, end */

    return AT_ERROR;

}
/* Added by f62575 for SMALL IMAGE, 2012-1-3, end   */

/* Add by w00199382 for V7代码同步, 2012-04-07, Begin   */

/*****************************************************************************
 函 数 名  : AT_SDParamErrCode
 功能描述  : SD命令参数错误返回错误码的处理
 输入参数  : 无
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月19日
    作    者   : c64416
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_SDParamErrCode(VOS_VOID)
{
    if(0 == g_stATParseCmd.ucParaCheckIndex)
    {
        return AT_SD_CARD_OPRT_NOT_ALLOWED;
    }
    else if(1 == g_stATParseCmd.ucParaCheckIndex)
    {
        return AT_SD_CARD_ADDR_ERR;
    }
    else
    {
        return AT_SD_CARD_OTHER_ERR;
    }
}

/* Add by w00199382 for V7代码同步, 2012-04-07, End   */

/* Added by f62575 for B050 Project, 2012-2-3, Begin   */
/*****************************************************************************
 函 数 名  : AT_GetSpecificPort
 功能描述  : 获取指定类型的端口
 输入参数  : VOS_UINT8                           ucPortType 端口类型
 输出参数  : VOS_UINT32                         *pulPortPos 端口在NV项中的偏移
             VOS_UINT32                         *pulPortNum NV项中的端口总数
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月3日
    作    者   : f62575
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID AT_GetSpecificPort(
    VOS_UINT8                           ucPortType,
    VOS_UINT8                           aucRewindPortStyle[],
    VOS_UINT32                         *pulPortPos,
    VOS_UINT32                         *pulPortNum
)
{
    VOS_UINT32                          ulLoop;

    *pulPortPos = AT_DEV_NONE;
    for (ulLoop = 0; ulLoop < AT_SETPORT_PARA_MAX_LEN; ulLoop++)
    {
        if (0 == aucRewindPortStyle[ulLoop])
        {
            break;
        }

        /* 端口值为ucPortType，表示找到指定端口，记录ulLoop为端口在NV项中的偏移 */
        if (ucPortType == aucRewindPortStyle[ulLoop])
        {
            *pulPortPos = ulLoop;
        }
    }

    /* 端口值为0或到达循环上限，ulLoop即为单板的端口总数 */
    *pulPortNum = ulLoop;

    return;
}

/*****************************************************************************
 函 数 名  : AT_ExistSpecificPort
 功能描述  : 是否存在指定类型的端口
 输入参数  : VOS_UINT8              ucPortType 端口类型
 输出参数  : 无
 返 回 值  : VOS_UINT32             VOS_TRUE    存在指定类型的端口
                                    VOS_FALSE 不存在指定类型的端口
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月3日
    作    者   : f62575
    修改内容   : 新生成函数
  2.日    期   : 2012年8月10日
    作    者   : L00171473
    修改内容   : DTS2012082204471, TQE清理
*****************************************************************************/
VOS_UINT32 AT_ExistSpecificPort(VOS_UINT8 ucPortType)
{
    AT_DYNAMIC_PID_TYPE_STRU            stDynamicPidType;
    VOS_UINT32                          ulPortPos;
    VOS_UINT32                          ulPortNum;


    TAF_MEM_SET_S(&stDynamicPidType, sizeof(stDynamicPidType), 0x00, sizeof(stDynamicPidType));

    ulPortPos = 0;
    ulPortNum = 0;


    /* 读NV项en_NV_Item_Huawei_Dynamic_PID_Type获取当前的端口状态 */
    if (NV_OK != NV_ReadEx(MODEM_ID_0, en_NV_Item_Huawei_Dynamic_PID_Type,
                        &stDynamicPidType,
                        sizeof(AT_DYNAMIC_PID_TYPE_STRU)))
    {
        AT_WARN_LOG("AT_ExistSpecificPort: Read NV fail!");
        return VOS_FALSE;
    }

    /* 判断DIAG端口是否已经打开: 已经打开则直接返回AT_OK */
    if (VOS_TRUE == stDynamicPidType.ulNvStatus)
    {
        /* 查询NV项en_NV_Item_Huawei_Dynamic_PID_Type中是否已经存在DIAG口 */
        AT_GetSpecificPort(ucPortType,
                           stDynamicPidType.aucRewindPortStyle,
                           &ulPortPos,
                           &ulPortNum);

        if (AT_DEV_NONE != ulPortPos)
        {
            return VOS_TRUE;
        }

    }

    return VOS_FALSE;
}


/*****************************************************************************
 函 数 名  : AT_OpenDiagPort
 功能描述  : 打开DIAG端口
 输入参数  : 无
 输出参数  : 无
 返 回 值  : VOS_UINT32             ATC返回码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月3日
    作    者   : f62575
    修改内容   : 新生成函数
  2.日    期   : 2012年8月10日
    作    者   : L00171473
    修改内容   : DTS2012082204471, TQE清理
*****************************************************************************/
VOS_UINT32 AT_OpenDiagPort(VOS_VOID)
{
    AT_DYNAMIC_PID_TYPE_STRU            stDynamicPidType;
    VOS_UINT32                          ulPortPos;
    VOS_UINT32                          ulPortNum;


    TAF_MEM_SET_S(&stDynamicPidType, sizeof(stDynamicPidType), 0x00, sizeof(stDynamicPidType));

    ulPortPos = 0;
    ulPortNum = 0;


    /* 读NV项en_NV_Item_Huawei_Dynamic_PID_Type获取当前的端口状态 */
    if (NV_OK != NV_ReadEx(MODEM_ID_0, en_NV_Item_Huawei_Dynamic_PID_Type,
                        &stDynamicPidType,
                        sizeof(AT_DYNAMIC_PID_TYPE_STRU)))
    {
        AT_WARN_LOG("AT_OpenDiagPort: Read NV fail!");
        return AT_ERROR;
    }

    /* 判断DIAG端口是否已经打开: 已经打开则直接返回AT_OK */
    if (VOS_TRUE == stDynamicPidType.ulNvStatus)
    {
        /* 查询NV项en_NV_Item_Huawei_Dynamic_PID_Type中是否已经存在DIAG口 */
        AT_GetSpecificPort(AT_DEV_DIAG,
                           stDynamicPidType.aucRewindPortStyle,
                           &ulPortPos,
                           &ulPortNum);

        if (AT_DEV_NONE != ulPortPos)
        {
            return AT_OK;
        }

    }
    else
    {
        AT_WARN_LOG("AT_OpenDiagPort: en_NV_Item_Huawei_Dynamic_PID_Type is inactive!");
        return AT_OK;
    }

    /* DIAG端口操作权限未获取: 直接返回AT_OK */
    if (AT_E5_RIGHT_FLAG_NO == g_enATE5RightFlag)
    {
        return AT_OK;
    }

    /* 追加DIAG端口到切换后端口集 */
    if (AT_SETPORT_PARA_MAX_LEN == ulPortNum)
    {
        return AT_OK;
    }

    stDynamicPidType.aucRewindPortStyle[ulPortNum] = AT_DEV_DIAG;

    /* 更新端口集合数据到NV项en_NV_Item_Huawei_Dynamic_PID_Type */
    if (NV_OK != NV_WriteEx(MODEM_ID_0, en_NV_Item_Huawei_Dynamic_PID_Type,
                        &stDynamicPidType,
                        sizeof(AT_DYNAMIC_PID_TYPE_STRU)))
    {
        AT_ERR_LOG("AT_OpenDiagPort: Write NV fail");
        return AT_ERROR;
    }
    else
    {
        return AT_OK;
    }
}

/*****************************************************************************
 函 数 名  : AT_CloseDiagPort
 功能描述  : 关闭DIAG端口
 输入参数  : 无
 输出参数  : 无
 返 回 值  : VOS_UINT32             ATC返回码
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月3日
    作    者   : f62575
    修改内容   : 新生成函数
  2.日    期   : 2012年8月10日
    作    者   : L00171473
    修改内容   : DTS2012082204471, TQE清理
*****************************************************************************/
VOS_UINT32 AT_CloseDiagPort(VOS_VOID)
{
    AT_DYNAMIC_PID_TYPE_STRU            stDynamicPidType;
    VOS_UINT32                          ulPortPos;
    VOS_UINT32                          ulPortNum;
    VOS_UINT32                          ulLoop;


    TAF_MEM_SET_S(&stDynamicPidType, sizeof(stDynamicPidType), 0x00, sizeof(stDynamicPidType));

    ulPortPos = 0;
    ulPortNum = 0;


    /* 读NV项en_NV_Item_Huawei_Dynamic_PID_Type获取当前的端口状态 */
    if (NV_OK != NV_ReadEx(MODEM_ID_0, en_NV_Item_Huawei_Dynamic_PID_Type,
                          &stDynamicPidType,
                          sizeof(AT_DYNAMIC_PID_TYPE_STRU)))
    {
        AT_ERR_LOG("AT_CloseDiagPort: Read NV fail!");
        return AT_ERROR;
    }

    /* 判断DIAG端口是否已经打开: 已经打开则直接返回AT_OK */
    if (VOS_TRUE == stDynamicPidType.ulNvStatus)
    {
        /* 查询NV项en_NV_Item_Huawei_Dynamic_PID_Type中是否已经存在DIAG口 */
        AT_GetSpecificPort(AT_DEV_DIAG,
                           stDynamicPidType.aucRewindPortStyle,
                           &ulPortPos,
                           &ulPortNum);

        if (AT_DEV_NONE == ulPortPos)
        {
            return AT_OK;
        }
    }
    else
    {
        return AT_OK;
    }

    /* DIAG端口操作权限未获取: 直接返回AT_OK */
    if (AT_E5_RIGHT_FLAG_NO == g_enATE5RightFlag)
    {
        return AT_OK;
    }

    /* 删除NV项中的DIAG端口 */
    stDynamicPidType.aucRewindPortStyle[ulPortPos] = 0;
    ulPortNum--;
    for (ulLoop = ulPortPos; ulLoop < ulPortNum; ulLoop++)
    {
        stDynamicPidType.aucRewindPortStyle[ulLoop] = stDynamicPidType.aucRewindPortStyle[ulLoop + 1UL];
    }
    stDynamicPidType.aucRewindPortStyle[ulPortNum] = 0;

    /* 端口异常数据保护: 切换后的设备形态中，第一个设备不能为MASS设备(0xa1,0xa2) */
    if (0 != ulPortNum)
    {
        if ((AT_DEV_CDROM == stDynamicPidType.aucRewindPortStyle[0])
         || (AT_DEV_SD == stDynamicPidType.aucRewindPortStyle[0]))
        {
            return AT_OK;
        }
    }

    /* 更新端口集合数据到NV项en_NV_Item_Huawei_Dynamic_PID_Type */
    if (NV_OK != NV_WriteEx(MODEM_ID_0, en_NV_Item_Huawei_Dynamic_PID_Type,
                          &stDynamicPidType,
                          sizeof(AT_DYNAMIC_PID_TYPE_STRU)))
    {
        AT_ERR_LOG("AT_CloseDiagPort: Write NV fail");
        return AT_ERROR;
    }
    else
    {
        return AT_OK;
    }
}

/*****************************************************************************
 函 数 名  : AT_ExistSpecificPortChange
 功能描述  : 是否存在指定类型的端口变更权限
 输入参数  : VOS_UINT8                           ucPortType 端口类型
             VOS_UINT8                           aucOldRewindPortStyle[]变更前的端口集合
             VOS_UINT8                           aucNewRewindPortStyle[]变更后的端口集合
 输出参数  : 无
 返 回 值  : VOS_UINT32             VOS_TRUE    存在指定类型的端口变更
                                    VOS_FALSE 不存在指定类型的端口变更
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月3日
    作    者   : f62575
    修改内容   : 新生成函数
  2.日    期   : 2012年8月10日
    作    者   : L00171473
    修改内容   : DTS2012082204471, TQE清理
*****************************************************************************/
VOS_UINT32 AT_ExistSpecificPortChange(
    VOS_UINT8                           ucPortType,
    VOS_UINT8                           aucOldRewindPortStyle[],
    VOS_UINT8                           aucNewRewindPortStyle[]
)
{
    VOS_UINT32                          ulOldPortPos;
    VOS_UINT32                          ulNewPortPos;
    VOS_UINT32                          ulPortNum;


    ulOldPortPos = 0;
    ulNewPortPos = 0;
    ulPortNum    = 0;

    AT_GetSpecificPort(ucPortType, aucOldRewindPortStyle, &ulOldPortPos, &ulPortNum);
    AT_GetSpecificPort(ucPortType, aucNewRewindPortStyle, &ulNewPortPos, &ulPortNum);

    /* 新增一个指定端口 */
    if ((AT_DEV_NONE == ulOldPortPos)
     && (AT_DEV_NONE != ulNewPortPos))
    {
        return VOS_TRUE;
    }

    /* 删除一个指定端口 */
    if ((AT_DEV_NONE != ulOldPortPos)
     && (AT_DEV_NONE == ulNewPortPos))
    {
        return VOS_TRUE;
    }

    return VOS_FALSE;

}

/*****************************************************************************
 函 数 名  : AT_CheckSetPortRight
 功能描述  : 是否存在指定类型的端口变更
 输入参数  : VOS_UINT8                           aucOldRewindPortStyle[]变更前的端口集合
             VOS_UINT8                           aucNewRewindPortStyle[]变更后的端口集合
 输出参数  : 无
 返 回 值  : VOS_UINT32             AT_OK       权限检查通过
                                    AT_ERROR    权限检查不通过
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月3日
    作    者   : f62575
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_CheckSetPortRight(
    VOS_UINT8                           aucOldRewindPortStyle[],
    VOS_UINT8                           aucNewRewindPortStyle[]
)
{
    VOS_UINT32                          ulRet;

    ulRet = AT_ExistSpecificPortChange(AT_DEV_DIAG,
                                       aucOldRewindPortStyle,
                                       aucNewRewindPortStyle);

    if ((VOS_TRUE == ulRet)
     && (AT_E5_RIGHT_FLAG_NO == g_enATE5RightFlag))
    {
        return AT_ERROR;
    }

    return AT_OK;
}

/* Added by f62575 for B050 Project, 2012-2-3, end   */

/*****************************************************************************
 函 数 名  : AT_SetHsspt
 功能描述  : 设置RRC版本信息,函数的参数正常性检测放在该模块做.
 输入参数  : ucIndex    - 用户索引
 输出参数  : 无
 返 回 值  : 返回出错信息或OK
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月21日
    作    者   : l60609
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_SetHsspt(VOS_UINT8 ucIndex)
{
    VOS_UINT8                           ucRRCVer;

    /* 参数检查 */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_DPAUPA_ERROR;
    }

    /* 参数过多 */
    if (gucAtParaIndex != 1)
    {
        return AT_DPAUPA_ERROR;
    }

    /* 检查是否解除数据保护,未解除时返回出错信息:ErrCode:0 */
    if (VOS_TRUE == g_bAtDataLocked)
    {
        return  AT_DATA_UNLOCK_ERROR;
    }

    ucRRCVer = (VOS_UINT8)gastAtParaList[0].ulParaValue;

    /* 调用写NV接口函数: AT_WriteRrcVerToNV,返回操作结果 */
    if (VOS_OK == AT_WriteRrcVerToNV(ucRRCVer))
    {
        return  AT_OK;
    }
    else
    {
        AT_WARN_LOG("At_SetHsspt:WARNING:Write NV failed!");
        return AT_DPAUPA_ERROR;
    }
}

/*****************************************************************************
 函 数 名  : AT_QryHsspt
 功能描述  : 查询RRC版本信息
 输入参数  : ucIndex - 用户索引
 输出参数  : 无
 返 回 值  : 返回出错信息或OK
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年4月21日
    作    者   : l60609
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_QryHsspt(VOS_UINT8 ucIndex)
{
    VOS_UINT8                           ucRRCVer;
    VOS_UINT32                          ulResult;
    VOS_UINT16                          usLength;

    /* 参数检查 */
    if (AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_DPAUPA_ERROR;
    }

    ulResult = AT_ReadRrcVerFromNV(&ucRRCVer);

    if (VOS_OK == ulResult)
    {
        usLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN, (TAF_CHAR *)pgucAtSndCodeAddr,
                                          (VOS_CHAR *)pgucAtSndCodeAddr, "%s:",
                                          g_stParseContext[ucIndex].pstCmdElement->pszCmdName);
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN, (TAF_CHAR *)pgucAtSndCodeAddr,
                                           (VOS_CHAR *)pgucAtSndCodeAddr + usLength, "%d",
                                           (VOS_UINT32)ucRRCVer);
        gstAtSendData.usBufLen = usLength;
        return  AT_OK;
    }
    else
    {
        AT_WARN_LOG("AT_QryHspaSpt:WARNING:WAS_MNTN_QueryHspaSpt failed!");
        return AT_DPAUPA_ERROR;
    }
}

/*****************************************************************************
 函 数 名  : AT_TestHsicCmdPara
 功能描述  : HSIC通道命令测试命令处理函数
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年04月19日
    作    者   : l00198894
    修改内容   : AP-Modem锁网锁卡项目新增函数
  2.日    期   : 2012年8月13日
    作    者   : l60609
    修改内容   : MUX:增加MUX通道的处理
*****************************************************************************/
VOS_UINT32 AT_TestHsicCmdPara(VOS_UINT8 ucIndex)
{
    /* 通道检查 */
    /* Modified by L60609 for MUX，2012-08-13,  Begin */
    if (VOS_FALSE == AT_IsApPort(ucIndex))
    /* Modified by L60609 for MUX，2012-08-13,  End */
    {
        return AT_ERROR;
    }

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : At_TestTdsScalibPara
 功能描述  : ^SCALIB测试命令处理函数
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年05月30日
    作    者   : z00212940
    修改内容   : TDS新增函数

*****************************************************************************/
VOS_UINT32 At_TestTdsScalibPara(VOS_UINT8 ucIndex)
{
    VOS_UINT16                           usLength;

    usLength = 0;
    usLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN, (VOS_CHAR*)pgucAtSndCodeAddr,
                                        (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                        "%s:%s", g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                        AT_TDS_SCALIB_TEST_STR);
    gstAtSendData.usBufLen = usLength;
    return AT_OK;
}

/*****************************************************************************
 函 数 名  : AT_TestSimlockUnlockPara
 功能描述  : ^SIMLOCKUNLOCK测试命令处理函数
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年9月19日
    作    者   : 李紫剑/00198894
    修改内容   : STK补充特性及DCM需求开发项目新生成函数

*****************************************************************************/
VOS_UINT32 AT_TestSimlockUnlockPara( VOS_UINT8 ucIndex )
{
    /* 通道检查 */
    if (VOS_FALSE == AT_IsApPort(ucIndex))
    {
        return AT_ERROR;
    }

    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    "%s: (\"NET\",\"NETSUB\",\"SP\")",
                                                    g_stParseContext[ucIndex].pstCmdElement->pszCmdName);

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : AT_String2Hex
 功能描述  : 完成字符串转16进制数功能
 输入参数  : nptr [in/out] 输入的字符串内容指针
             usLen [in] 输入的字符串长度
 输出参数  : pRtn [in/out] 由字符串转换所得整型值
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年06月28日
    作    者   : d00212987
    修改内容   : 移植北京原有AT 命令读写NV操作
*****************************************************************************/
VOS_UINT32 AT_String2Hex( VOS_UINT8 *nptr,VOS_UINT16 usLen, VOS_UINT32 *pRtn)
{
    VOS_UINT32                          c     = 0;         /* current Char */
    VOS_UINT32                          total = 0;         /* current total */
    VOS_UINT8                           Length = 0;        /* current Length */

    for (Length = 0; Length < usLen; Length++)
    {
        c = (VOS_UINT32)(*nptr);    /* get next Char */
        nptr++;

        if( (c  >= '0') && (c  <= '9') )
        {
            c  = c  - '0';
        }
        else if( (c  >= 'a') && (c  <= 'f') )
        {
            c  = c  - 'a' + 10;
        }
        else if( (c  >= 'A') && (c  <= 'F') )
        {
            c  = c  - 'A' + 10;
        }
        else
        {
            return VOS_ERR;
        }

        if(total > 0x0FFFFFFF)              /* 发生反转 */
        {
            return VOS_ERR;
        }
        else
        {
            total = (total << 4) + c;       /* accumulate digit */
        }
    }

     /* return result, negated if necessary */
    *pRtn = total;
    return AT_SUCCESS;
}

/*****************************************************************************
 函 数 名  : AT_NVWRGetParaInfo
 功能描述  : 获取输入参数信息
 输入参数  : *pucPara  :
             *pucValue :
             **pucParaDst

 输出参数  :
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年06月28日
    作    者   : d00212987
    修改内容   : 移植北京原有AT 命令读写NV操作
*****************************************************************************/
VOS_UINT32 AT_NVWRGetItemValue( VOS_UINT8 *pucPara,  VOS_UINT8 *pucValue,  VOS_UINT8 **pucParaDst)
{
    VOS_UINT32                          ulTmp = 0;
    VOS_UINT8                          *pucStart = pucPara;
    VOS_UINT16                          usLen = 0;
    VOS_UINT8                          *pucEnd = VOS_NULL_PTR;
    VOS_UINT32                          ulRet;

    /* 调用的地方保证pucPara,pucValue,pucParaDst不为NULL */

    /* 直到第一个不是' '的字符 */
    while(' ' == *pucStart)
    {
        pucStart++;
    }

    if(' ' == *(pucStart+1))
    {
        usLen = 1;
        pucEnd = pucStart+2;
    }
    else if(' ' == *(pucStart+2))
    {
        usLen = 2;
        pucEnd = pucStart+3;
    }
    else
    {
        return VOS_ERR;
    }

    ulRet = AT_String2Hex(pucStart, usLen, &ulTmp);
    if((VOS_OK != ulRet) || (ulTmp > 0xff))
    {
        return VOS_ERR;
    }

    *pucValue = (VOS_UINT8)ulTmp;
    *pucParaDst = pucEnd;

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : AT_NVWRGetParaInfo
 功能描述  : ^NVWRITE命令处理函数
 输入参数  :
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年06月28日
    作    者   : d00212987
    修改内容   : 移植北京原有AT 命令读写NV操作
*****************************************************************************/
VOS_UINT32 AT_NVWRGetParaInfo( AT_PARSE_PARA_TYPE_STRU * pstPara, VOS_UINT8 * pu8Data, VOS_UINT32 * pulLen)
{
    VOS_UINT32                          ulNum = 0;
    VOS_UINT8                          *pu8Start   = VOS_NULL_PTR;
    VOS_UINT8                          *pu8ParaTmp = VOS_NULL_PTR;
    VOS_UINT16                          usLen = 0;
    VOS_UINT32                          ulRet;
    VOS_UINT16                          i = 0;

    /* 调用的地方保证pstPara,pu8Data不为NULL */

    pu8Start = pstPara->aucPara;
    usLen= pstPara->usParaLen;

    if(usLen < AT_PARA_MAX_LEN)
    {
        pstPara->aucPara[usLen] = ' ';
    }
    else
    {
        return VOS_ERR;
    }

    ulNum = 0;
    for(i = 0; i < usLen; )
    {
        ulRet = AT_NVWRGetItemValue(pu8Start, (pu8Data+ulNum), &pu8ParaTmp);
        if(ERR_MSP_SUCCESS != ulRet)
        {
            return ulRet;
        }

        ulNum++;

        /* 最多128个 */
        /*MAX_NV_NUM_PER_PARA */
        if(ulNum == 128)
        {
            break;
        }

        if(pu8ParaTmp >= (pu8Start+usLen))
        {
            break;
        }

        i += (VOS_UINT16)(pu8ParaTmp - pu8Start);
        pu8Start = pu8ParaTmp;
    }

    *pulLen = ulNum;
    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : AT_SetNVReadPara
 功能描述  : ^NVREAD命令处理函数
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年06月28日
    作    者   : d00212987
    修改内容   : 移植北京原有AT 命令读写NV操作
*****************************************************************************/
VOS_UINT32 AT_SetNVReadPara(VOS_UINT8 ucIndex)
{
    VOS_UINT16                          usNvId  = 0;
    VOS_UINT32                          ulNvLen = 0;
    VOS_UINT8                          *pucData = VOS_NULL_PTR;
    VOS_UINT32                          i       = 0;
    MODEM_ID_ENUM_UINT16                enModemId = MODEM_ID_0;
    VOS_UINT32                          ulRet;

    /* 参数检查 */
    if(AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        g_ulNVRD = 1;
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* 参数过多 */
    if(gucAtParaIndex > 1)
    {
        g_ulNVRD = 2;
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* 参数为空 */
    if(0 == gastAtParaList[0].usParaLen)
    {
        g_ulNVRD = 3;
        return AT_CME_INCORRECT_PARAMETERS;
    }
    else
    {
        usNvId = (VOS_UINT16)gastAtParaList[0].ulParaValue;
    }

    ulRet = NV_GetLength(usNvId, &ulNvLen);

    if(VOS_OK != ulRet)
    {
        g_ulNVRD = 4;
        return AT_ERROR;
    }

    /* 长度大于128，只取前128个字节*/
    /*lint -save -e516 */
    pucData = (VOS_UINT8*)PS_MEM_ALLOC(WUEPS_PID_AT, ulNvLen);
    /*lint -restore */
    if(VOS_NULL_PTR == pucData)
    {
        g_ulNVRD = 5;
        return AT_ERROR;
    }

    ulRet = AT_GetModemIdFromClient(ucIndex, &enModemId);

    if (VOS_OK != ulRet)
    {
        AT_ERR_LOG("AT_SetNVReadPara:Get modem id fail");
        /*lint -save -e516 */
        PS_MEM_FREE(WUEPS_PID_AT, pucData);
        /*lint -restore */
        g_ulNVWR =8;
        return AT_ERROR;
    }

    ulRet = NV_ReadEx(enModemId, usNvId, (VOS_VOID*)pucData, ulNvLen);

    if(VOS_OK != ulRet)
    {
        /*lint -save -e516 */
        PS_MEM_FREE(WUEPS_PID_AT, pucData);
        /*lint -restore */
        g_ulNVRD = 6;
        return AT_ERROR;
    }
    gstAtSendData.usBufLen = 0;
    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN, (VOS_CHAR *)pgucAtSndCodeAddr,(VOS_CHAR*)pgucAtSndCodeAddr,
        "^NVRD: %d,", ulNvLen);

    for(i = 0; i < ulNvLen; i++)
    {
        if(0 == i)
        {
            gstAtSendData.usBufLen += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                (VOS_CHAR *)pgucAtSndCodeAddr,(VOS_CHAR*)pgucAtSndCodeAddr + gstAtSendData.usBufLen,"%02X", pucData[i]);
        }
        else
        {
            gstAtSendData.usBufLen += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                (VOS_CHAR *)pgucAtSndCodeAddr,(VOS_CHAR*)pgucAtSndCodeAddr + gstAtSendData.usBufLen," %02X", pucData[i]);
        }
    }
    /*lint -save -e516 */
    PS_MEM_FREE(WUEPS_PID_AT, pucData);
    /*lint -restore */
    g_ulNVRD = 7;
    return AT_OK;
}


/*****************************************************************************
 函 数 名  : AT_GetNvRdDebug
 功能描述  : 显示NV读写调测信息
 输入参数  :
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年06月28日
    作    者   : d00212987
    修改内容   : 移植北京原有AT 命令读写NV操作
*****************************************************************************/
VOS_VOID AT_GetNvRdDebug(VOS_VOID)
{
    (VOS_VOID)vos_printf("\n g_ulNVRD=0x%x \n",g_ulNVRD);
    (VOS_VOID)vos_printf("\n g_ulNVWR=0x%x \n",g_ulNVWR);
}

/*****************************************************************************
 函 数 名  : AT_QryFPllStatusPara
 功能描述  : 查询G或W PLL状态
 输入参数  : ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年11月29日
    作    者   : L00256032
    修改内容   : Added for PLL status query
*****************************************************************************/
VOS_UINT32 AT_QryFPllStatusPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                          ulReceiverPid;
    AT_PHY_RF_PLL_STATUS_REQ_STRU      *pstMsg;
    VOS_UINT32                          ulLength;
    VOS_UINT16                          usMsgId;
    if ((AT_RAT_MODE_FDD_LTE == g_stAtDevCmdCtrl.ucDeviceRatMode)
            ||(AT_RAT_MODE_TDD_LTE == g_stAtDevCmdCtrl.ucDeviceRatMode))
    {
        return atQryFPllStatusPara(ucIndex);
    }
    /*判断当前接入模式，只支持G/W*/
    if (AT_RAT_MODE_WCDMA == g_stAtDevCmdCtrl.ucDeviceRatMode)
    {
        ulReceiverPid = AT_GetDestPid(ucIndex, I0_DSP_PID_WPHY);
        usMsgId       = ID_AT_WPHY_RF_PLL_STATUS_REQ;
    }
    else if ( (AT_RAT_MODE_GSM == g_stAtDevCmdCtrl.ucDeviceRatMode)
            ||(AT_RAT_MODE_EDGE == g_stAtDevCmdCtrl.ucDeviceRatMode) )
    {
        ulReceiverPid = AT_GetDestPid(ucIndex, I0_DSP_PID_GPHY);
        usMsgId       = ID_AT_GPHY_RF_PLL_STATUS_REQ;
    }

    else
    {
        return AT_DEVICE_MODE_ERROR;
    }

    /* 申请AT_PHY_RF_PLL_STATUS_REQ_STRU消息 */
    ulLength = sizeof(AT_PHY_RF_PLL_STATUS_REQ_STRU) - VOS_MSG_HEAD_LENGTH;
    /*lint -save -e516 */
    pstMsg   = (AT_PHY_RF_PLL_STATUS_REQ_STRU *)PS_ALLOC_MSG(WUEPS_PID_AT, ulLength);
    /*lint -restore */
    if (VOS_NULL_PTR == pstMsg)
    {
        AT_WARN_LOG("AT_QryFPllStatusPara: Alloc msg fail!");
        return AT_ERROR;
    }

    /* 填充消息 */
    pstMsg->ulReceiverPid = ulReceiverPid;
    pstMsg->usMsgID       = usMsgId;
    pstMsg->usRsv1        = 0;
    pstMsg->usDspBand     = g_stAtDevCmdCtrl.stDspBandArfcn.usDspBand;
    pstMsg->usRsv2        = 0;

    /* 向对应PHY发送消息 */
    if (VOS_OK != PS_SEND_MSG(WUEPS_PID_AT, pstMsg))
    {
        AT_WARN_LOG("AT_QryFPllStatusPara: Send msg fail!");
        return AT_ERROR;
    }

    /* 设置当前操作类型 */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_FPLLSTATUS_QRY;
    g_stAtDevCmdCtrl.ucIndex               = ucIndex;

    /* 返回命令处理挂起状态 */
    return AT_WAIT_ASYNC_RETURN;
}

/*****************************************************************************
 函 数 名  : At_RfPllStatusCnfProc
 功能描述  : AT处理GPHY/WPHY回复的PLL状态查询响应消息
 输入参数  : pstMsg
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年11月29日
    作    者   : L00256032
    修改内容   : Added for PLL status query
*****************************************************************************/
VOS_VOID At_RfPllStatusCnfProc(PHY_AT_RF_PLL_STATUS_CNF_STRU *pstMsg)
{
    VOS_UINT8                           ucIndex;
    VOS_UINT16                          usLength;

    /* 获取本地保存的用户索引 */
    ucIndex = g_stAtDevCmdCtrl.ucIndex;

    if (AT_CMD_FPLLSTATUS_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("At_RfPllStatusCnfProc: CmdCurrentOpt is not AT_CMD_FPLLSTATUS_QRY!");
        return;
    }

    /* 复位AT状态 */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    usLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (VOS_CHAR *)pgucAtSndCodeAddr,
                                       (VOS_CHAR *)pgucAtSndCodeAddr,
                                       "%s: %d,%d",
                                       g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                       pstMsg->usTxStatus,
                                       pstMsg->usRxStatus);

    gstAtSendData.usBufLen = usLength;

    At_FormatResultData(ucIndex, AT_OK);

    return;
}

/*****************************************************************************
 函 数 名  : AT_QryFpowdetTPara
 功能描述  : 读寄存器PDEG值
 输入参数  : ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2014年5月6日
    作    者   : d00212987
    修改内容   : Added for PDEA status query
  2.日    期   : 2016年6月17日
    作    者   : w00242748
    修改内容   : DTS2016062000269:X模支持老化特性
  3.日    期   : 2016年8月19日
    作    者   : xwx377961
    修改内容   : DTS2016082403967:GSM PA口输出功率检测功能
  4.日    期   : 2017年05月08日
    作    者   : w00316404
    修改内容   : 扩展支持LTE TDD/FDD功能
*****************************************************************************/
VOS_UINT32 AT_QryFpowdetTPara(VOS_UINT8 ucIndex)
{
    AT_PHY_POWER_DET_REQ_STRU          *pstMsg;
    VOS_UINT32                          ulLength;
    VOS_UINT32                          ulResult;
    VOS_UINT8                           ucIsLteFlg;

    ucIsLteFlg = VOS_FALSE;

    /*判断当前接入模式，只支持W*/
    if ( (AT_RAT_MODE_WCDMA != g_stAtDevCmdCtrl.ucDeviceRatMode)
      && (AT_RAT_MODE_CDMA != g_stAtDevCmdCtrl.ucDeviceRatMode)
      && (AT_RAT_MODE_GSM != g_stAtDevCmdCtrl.ucDeviceRatMode)
      && (AT_RAT_MODE_FDD_LTE != g_stAtDevCmdCtrl.ucDeviceRatMode)
      && (AT_RAT_MODE_TDD_LTE != g_stAtDevCmdCtrl.ucDeviceRatMode) )
    {
        return AT_DEVICE_MODE_ERROR;
    }

    /* 申请AT_PHY_POWER_DET_REQ_STRU消息 */
    ulLength = sizeof(AT_PHY_POWER_DET_REQ_STRU) - VOS_MSG_HEAD_LENGTH;
    /*lint -save -e516 */
    pstMsg   = (AT_PHY_POWER_DET_REQ_STRU *)PS_ALLOC_MSG(WUEPS_PID_AT, ulLength);
    /*lint -restore */
    if (VOS_NULL_PTR == pstMsg)
    {
        AT_WARN_LOG("AT_QryFpowdetTPara: Alloc msg fail!");
        return AT_ERROR;
    }

    /* CDMA的话，发送给UPHY_PID_CSDR_1X_CM */
    if (AT_RAT_MODE_CDMA == g_stAtDevCmdCtrl.ucDeviceRatMode)
    {
        pstMsg->ulReceiverPid = UPHY_PID_CSDR_1X_CM;
    }
    else if (AT_RAT_MODE_GSM == g_stAtDevCmdCtrl.ucDeviceRatMode)
    {
        pstMsg->ulReceiverPid = AT_GetDestPid(ucIndex, I0_DSP_PID_GPHY);
    }
    else if (AT_RAT_MODE_WCDMA == g_stAtDevCmdCtrl.ucDeviceRatMode)
    {
        pstMsg->ulReceiverPid = AT_GetDestPid(ucIndex, I0_DSP_PID_WPHY);
    }
    else
    {
        ucIsLteFlg = VOS_TRUE;
    }

    if (VOS_FALSE == ucIsLteFlg)
    {
        pstMsg->usMsgID       = ID_AT_PHY_POWER_DET_REQ;
        pstMsg->usRsv         = 0;

        /* 向对应PHY发送消息 */
        ulResult = PS_SEND_MSG(WUEPS_PID_AT, pstMsg);
    }
    else
    {
        /*lint --e{516,830} */
        PS_FREE_MSG(WUEPS_PID_AT, pstMsg);
        ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                          gastAtClientTab[ucIndex].opId,
                                          ID_AT_MTA_POWER_DET_QRY_REQ,
                                          VOS_NULL_PTR,
                                          0,
                                          I0_UEPS_PID_MTA);
    }

    if (VOS_OK != ulResult)
    {
        AT_WARN_LOG("AT_QryFpowdetTPara: Send msg fail!");
        return AT_ERROR;
    }

    /* 设置当前操作类型 */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_FPOWDET_QRY;
    g_stAtDevCmdCtrl.ucIndex               = ucIndex;

    /* 返回命令处理挂起状态 */
    return AT_WAIT_ASYNC_RETURN;
}

/*****************************************************************************
 函 数 名  : At_RfFPOWDETCnfProc
 功能描述  : AT处理WPHY回复读到的寄存器PDEG值
 输入参数  : pstMsg
 输出参数  : 无
 返 回 值  : VOS_VOID

 修改历史      :
  1.日    期   : 2014年5月6日
    作    者   : d00212987
    修改内容   : Added for PDEA status query
*****************************************************************************/
VOS_VOID At_RfFpowdetTCnfProc(PHY_AT_POWER_DET_CNF_STRU *pstMsg)
{
    VOS_UINT8                           ucIndex;
    VOS_UINT16                          usLength;

    /* 获取本地保存的用户索引 */
    ucIndex = g_stAtDevCmdCtrl.ucIndex;

    if (AT_CMD_FPOWDET_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("At_RfFPOWDETCnfProc: CmdCurrentOpt is not AT_CMD_FPOWDET_QRY!");
        return;
    }

    /* 复位AT状态 */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* 应物理层要求，如果返回值为0x7FFF则为无效值，项查询者返回ERROR */
    if(0x7FFF == pstMsg->sPowerDet)
    {
        gstAtSendData.usBufLen = 0;
        At_FormatResultData(ucIndex, AT_ERROR);
    }
    else
    {
        usLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                           "%s: %d",
                                           g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                           pstMsg->sPowerDet);

        gstAtSendData.usBufLen = usLength;

        At_FormatResultData(ucIndex, AT_OK);
    }

    return;
}

/*****************************************************************************
 函 数 名  : AT_RcvMtaPowerDetQryCnf
 功能描述  : AT模块收到MTA回复的REFCLKFREQ_QRY_CNF消息的处理函数
 输入参数  : pMsg -- 消息内容
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年05月08日
    作    者   : w00316404
    修改内容   : 新增函数
*****************************************************************************/
VOS_UINT32 AT_RcvMtaPowerDetQryCnf(VOS_VOID *pMsg)
{
    /* 定义局部变量 */
    AT_MTA_MSG_STRU                    *pstMtaMsg;
    MTA_AT_POWER_DET_QRY_CNF_STRU      *pstPowerDetQryCnf;
    PHY_AT_POWER_DET_CNF_STRU           stPowerNetMsg;

    /* 初始化消息变量 */
    pstMtaMsg           = (AT_MTA_MSG_STRU *)pMsg;
    pstPowerDetQryCnf   = (MTA_AT_POWER_DET_QRY_CNF_STRU *)pstMtaMsg->aucContent;

    TAF_MEM_SET_S(&stPowerNetMsg, sizeof(stPowerNetMsg), 0x00, sizeof(PHY_AT_POWER_DET_CNF_STRU));

    if (MTA_AT_RESULT_NO_ERROR == pstPowerDetQryCnf->enResult)
    {
        stPowerNetMsg.sPowerDet = pstPowerDetQryCnf->sPowerDet;
    }
    else
    {
        stPowerNetMsg.sPowerDet = 0x7FFF;
    }

    At_RfFpowdetTCnfProc(&stPowerNetMsg);

    return VOS_OK;
}


/*****************************************************************************
 函 数 名  : AT_IsNVWRAllowedNvId
 功能描述  : 判断命令^NVWR、^NVWREX能否修改此NV_ID
 输入参数  : usNvId
 输出参数  : 无
 返 回 值  : VOS_TRUE   -- 允许修改
             VOS_FLASE  -- 不允许修改
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2015年04月04日
    作    者   : l00198894
    修改内容   : 新增函数
*****************************************************************************/
VOS_BOOL AT_IsNVWRAllowedNvId(VOS_UINT16 usNvId)
{
    TAF_NV_NVWR_SEC_CTRL_STRU           stNvwrSecCtrlNV;
    VOS_UINT8                           ucLoop;
    VOS_UINT8                           ucBlackListNum;

    /* 参数初始化 */
    TAF_MEM_SET_S(&stNvwrSecCtrlNV, sizeof(stNvwrSecCtrlNV), 0x00, sizeof(stNvwrSecCtrlNV));

    /* 读取安全控制NV */
    if (NV_OK != NV_ReadEx(MODEM_ID_0, en_NV_Item_NVWR_SEC_CTRL, &stNvwrSecCtrlNV, sizeof(stNvwrSecCtrlNV)))
    {
        AT_ERR_LOG("AT_IsNVWRAllowedNvId: NV_ReadEx fail!");
        return VOS_FALSE;
    }

    switch (stNvwrSecCtrlNV.ucSecType)
    {
        case AT_NVWR_SEC_TYPE_OFF:
            return VOS_TRUE;

        case AT_NVWR_SEC_TYPE_ON:
            return VOS_FALSE;

        case AT_NVWR_SEC_TYPE_BLACKLIST:
            ucBlackListNum = (stNvwrSecCtrlNV.ucBlackListNum <= TAF_NV_BLACK_LIST_MAX_NUM) ?
                             stNvwrSecCtrlNV.ucBlackListNum : TAF_NV_BLACK_LIST_MAX_NUM;
            for (ucLoop = 0; ucLoop < ucBlackListNum; ucLoop++)
            {
                if (usNvId == stNvwrSecCtrlNV.ausBlackList[ucLoop])
                {
                    return VOS_FALSE;
                }
            }
            return VOS_TRUE;

        default:
            AT_ERR_LOG1("AT_IsNVWRAllowedNvId: Error SecType:", stNvwrSecCtrlNV.ucSecType);
            break;
    }

    return VOS_FALSE;
}

/*****************************************************************************
函 数 名  :AT_AsciiToHex
功能描述  :转换字符串格式
输入参数  :

输出参数  :无
返 回 值  :VOS_OK    :失败
           VOS_ERR   :成功

修订记录  :
1. 日    期   : 2015年07月23日
   作    者   : z00316370
   修改内容   : Creat
*****************************************************************************/

VOS_UINT32 AT_AsciiToHex(
    VOS_UINT8                          *pucSrc,
    VOS_UINT8                          *pucDst
)
{

    if (( *pucSrc >= '0') && (*pucSrc <= '9')) /* the number is 0-9 */
    {
        *pucDst = (VOS_UINT8)(*pucSrc - '0');
    }
    else if ( (*pucSrc >= 'a') && (*pucSrc <= 'f') ) /* the number is a-f */
    {
        *pucDst = (VOS_UINT8)(*pucSrc - 'a') + 0x0a;
    }
    else if ( (*pucSrc >= 'A') && (*pucSrc <= 'F') ) /* the number is A-F */
    {
        *pucDst = (VOS_UINT8)(*pucSrc - 'A') + 0x0a;
    }
    else
    {
        return VOS_ERR;
    }

    return VOS_OK;
}

/*****************************************************************************
函 数 名  :AT_AsciiToHexCode
功能描述  :转换字符串格式，逆序,"1234"->0x3412
输入参数  :

输出参数  :无
返 回 值  :VOS_OK    :失败
           VOS_ERR   :成功

修订记录  :
1. 日    期   : 2015年7月23日
   作    者   : z00316370
   修改内容   : Creat
*****************************************************************************/

VOS_UINT32 AT_AsciiToHexCode_Revers(
    VOS_UINT8                          *pucSrc,
    VOS_UINT16                          usDataLen,
    VOS_UINT8                          *pucDst
)
{
    VOS_INT16                           sLoop1;
    VOS_UINT16                          usLoop2;
    VOS_UINT8                           ucTemp1;
    VOS_UINT8                           ucTemp2;
    VOS_UINT32                          ulRslt;

    sLoop1 = (VOS_INT16)(usDataLen - 1);
    for (usLoop2 = 0; sLoop1 >= 0; sLoop1--, usLoop2++)
    {
        ulRslt = AT_AsciiToHex(&(pucSrc[sLoop1]), &ucTemp1);
        if (VOS_ERR == ulRslt)
        {
            return VOS_ERR;
        }

        sLoop1--;

        if (sLoop1 < 0)
        {
            AT_ERR_LOG("AT_AsciiToHexCode_Revers: sLoop1 is invalid.");

            return VOS_ERR;
        }

        ulRslt = AT_AsciiToHex(&(pucSrc[sLoop1]), &ucTemp2);
        if (VOS_ERR == ulRslt)
        {
            return VOS_ERR;
        }

        pucDst[usLoop2] = (VOS_UINT8)((ucTemp2 << 4) | ucTemp1);
    }

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : AT_Hex2Ascii
 功能描述  : 将十六进制数字字符串转换成ASCII码表示的数字字符串,逆序,0x3412 --> "1234"
 输入参数  : VOS_UINT8  aucHex[]十进制数字字符串首地址
             VOS_UINT32 ulLength      十进制数字字符串长度
 输出参数  : VOS_UINT8  aucAscii[]    ASCII码表示的数字字符串首地址
 返 回 值  : VOS_UINT32 转换结果: VOS_OK转换成功，VOS_ERR转换失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2015年7月18日
    作    者   : z00316370
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_Hex2Ascii_Revers(
    VOS_UINT8                           aucHex[],
    VOS_UINT32                          ulLength,
    VOS_UINT8                           aucAscii[]
)
{
    VOS_INT32                           lLoopSrc;
    VOS_UINT32                          ulLoopDest;
    VOS_UINT8                           ucTemp;

    lLoopSrc = (VOS_INT32)(ulLength - 1);
    for (ulLoopDest = 0; lLoopSrc >= 0; lLoopSrc--, ulLoopDest++)
    {
        ucTemp = (aucHex[lLoopSrc]>>4) & 0x0F;
        if (ucTemp < 10)
        {
            /* 0~9 */
            aucAscii[ulLoopDest] = ucTemp + 0x30;
        }
        else
        {
            /* a~f */
            aucAscii[ulLoopDest] = ucTemp + 0x37;
        }

        ulLoopDest++;
        ucTemp = aucHex[lLoopSrc] & 0x0F;
        if (ucTemp < 10)
        {
            /* 0~9 */
            aucAscii[ulLoopDest] = ucTemp + 0x30;
        }
        else
        {
            /* a~f */
            aucAscii[ulLoopDest] = ucTemp + 0x37;
        }
    }

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : AT_SetMeidPara
 功能描述  : 设置修改MEID,命令格式%MEID=<meid number>
 输入参数  : ucIndex - 用户索引
 输出参数  : 无
 返 回 值  : AT_OK - 成功
             AT_DEVICE_OTHER_ERROR或 AT_DATA_UNLOCK_ERROR - 失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2015年7月18日
    作    者   : z00316370
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_SetMeidPara(VOS_UINT8 ucIndex)
{
    AT_MTA_MEID_SET_REQ_STRU            stMeIdReq;
    VOS_UINT32                          ulRslt;

    TAF_MEM_SET_S(&stMeIdReq, sizeof(stMeIdReq), 0x00, sizeof(AT_MTA_MEID_SET_REQ_STRU));

    /* 命令状态检查 */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* 参数个数不为1或者字符串长度不为14 */
    if ((1 != gucAtParaIndex)
     || (14 != gastAtParaList[0].usParaLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    ulRslt = AT_AsciiToHexCode_Revers(gastAtParaList[0].aucPara,
                                      gastAtParaList[0].usParaLen,
                                      stMeIdReq.aucMeid);

    if (VOS_OK != ulRslt)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    ulRslt = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                    gastAtClientTab[ucIndex].opId,
                                    ID_AT_MTA_MEID_SET_REQ,
                                    &stMeIdReq,
                                    sizeof(stMeIdReq),
                                    I0_UEPS_PID_MTA);

    if (TAF_SUCCESS == ulRslt)
    {
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_MEID_SET;

        /* 返回命令处理挂起状态 */
        return AT_WAIT_ASYNC_RETURN;
    }
    else
    {
        AT_WARN_LOG("AT_SetMeidPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

}

/*****************************************************************************
 函 数 名  : AT_QryMeidPara
 功能描述  : AT%MEID查询MEID
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2015年07月17日
    作    者   : z00316370
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_QryMeidPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                          ulResult;

    /* 参数检查 */
    if (AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_ERROR;
    }

    /* 发送消息*/
    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      gastAtClientTab[ucIndex].opId,
                                      ID_AT_MTA_MEID_QRY_REQ,
                                      VOS_NULL_PTR,
                                      0,
                                      I0_UEPS_PID_MTA);

    if (TAF_SUCCESS == ulResult)
    {
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_MEID_QRY;

        /* 返回命令处理挂起状态 */
        return AT_WAIT_ASYNC_RETURN;
    }
    else
    {
        AT_WARN_LOG("AT_QryMeidPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }
}

/*****************************************************************************
 函 数 名  : AT_RcvMtaMeidSetCnf
 功能描述  : ID_MTA_AT_MEID_SET_CNF消息处理函数,^MEID设置结果
 输入参数  : VOS_VOID *pstMsg - 消息指针
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2015年07月23日
    作    者   : z00316370
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_RcvMtaMeidSetCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                    *pstRcvMsg;
    MTA_AT_RESULT_CNF_STRU             *pstSetCnf;
    VOS_UINT8                           ucIndex;
    VOS_UINT32                          ulRslt;

    /* 初始化 */
    pstRcvMsg       = (AT_MTA_MSG_STRU *)pMsg;
    pstSetCnf       = (MTA_AT_RESULT_CNF_STRU *)pstRcvMsg->aucContent;
    ucIndex         = AT_BROADCAST_CLIENT_INDEX_MODEM_0;

    /* 通过ClientId获取ucIndex */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaMeidSetCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaMeidSetCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* 判断当前操作类型是否为AT_CMD_MEID_SET */
    if (AT_CMD_MEID_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaMeidSetCnf: NOT CURRENT CMD OPTION!");
        return VOS_ERR;
    }

    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* 格式化AT^MEID命令返回 */
    gstAtSendData.usBufLen = 0;

    switch (pstSetCnf->enResult)
    {
        case MTA_AT_RESULT_INCORRECT_PARAMETERS:
            ulRslt = AT_DEVICE_INVALID_PARAMETERS;
            break;

        case MTA_AT_RESULT_DEVICE_SEC_NV_ERROR:
            ulRslt = AT_DEVICE_NV_WRITE_FAIL_UNKNOWN;
            break;

        case MTA_AT_RESULT_NO_ERROR:
            ulRslt = AT_OK;
            break;

        default:
            ulRslt = AT_ERROR;
            break;
    }

    At_FormatResultData(ucIndex, ulRslt);

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : AT_RcvMtaMeidQryCnf
 功能描述  : ID_MTA_AT_MEID_QRY_CNF消息处理函数,^MEID设置结果
 输入参数  : VOS_VOID *pstMsg - 消息指针
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2015年12月18日
    作    者   : z00316370
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 AT_RcvMtaMeidQryCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                    *pstRcvMsg;
    MTA_AT_MEID_QRY_CNF_STRU           *pstQryCnf;
    VOS_UINT8                           ucIndex;
    VOS_UINT8                           aucMeId[2*MEID_NV_DATA_LEN_NEW + 1];
    VOS_UINT8                           aucpEsn[2*PESN_NV_DATA_LEN + 1];
    VOS_UINT8                           aucpUimID[2*UIMID_DATA_LEN + 1];

    TAF_MEM_SET_S(aucMeId, sizeof(aucMeId), 0x00, sizeof(aucMeId));

    /* 初始化 */
    pstRcvMsg       = (AT_MTA_MSG_STRU *)pMsg;
    pstQryCnf       = (MTA_AT_MEID_QRY_CNF_STRU *)pstRcvMsg->aucContent;
    ucIndex         = AT_BROADCAST_CLIENT_INDEX_MODEM_0;

    /* 通过ClientId获取ucIndex */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaMeidQryCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaMeidQryCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* 判断当前操作类型是否为AT_CMD_MEID_QRY */
    if (AT_CMD_MEID_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaMeidQryCnf: NOT CURRENT CMD OPTION!");
        return VOS_ERR;
    }

    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* 格式化AT^MEID命令返回 */
    gstAtSendData.usBufLen = 0;

    /* 读取en_NV_Item_MEID */
    if (NV_OK != pstQryCnf->ulMeIDReadRst)
    {
        AT_WARN_LOG("AT_RcvMtaMeidQryCnf:Read en_NV_Item_MEID Nvim Failed");
        return AT_DEVICE_NV_READ_FAILURE;
    }

    /* 读取en_NV_Item_PESN */
    if (NV_OK != pstQryCnf->ulPEsnReadRst)
    {
        AT_WARN_LOG("AT_RcvMtaMeidQryCnf:Read en_NV_Item_PESN Nvim Failed");
        return AT_DEVICE_NV_READ_FAILURE;
    }

    /* 读取UIMID失败 */
    if (pstQryCnf->enResult != MTA_AT_RESULT_NO_ERROR)
    {
        AT_WARN_LOG("AT_RcvMtaMeidQryCnf:Read UIMID Failed");
    }

    AT_Hex2Ascii_Revers(&(pstQryCnf->aucEFRUIMID[1]), UIMID_DATA_LEN, aucpUimID);
    aucpUimID[2*UIMID_DATA_LEN] = '\0';

    AT_Hex2Ascii_Revers(&(pstQryCnf->aucPEsn[0]), PESN_NV_DATA_LEN, aucpEsn);
    aucpEsn[2*PESN_NV_DATA_LEN] = '\0';

    AT_Hex2Ascii_Revers(&(pstQryCnf->aucMeID[0]), MEID_NV_DATA_LEN_NEW, aucMeId);
    aucMeId[2*MEID_NV_DATA_LEN_NEW] = '\0';

    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                   (VOS_CHAR *)pgucAtSndCodeAddr,
                                                   (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    "%s: %s,%s,%s",
                                                    g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                    aucMeId,
                                                    aucpEsn,
                                                    aucpUimID);

    At_FormatResultData(ucIndex, AT_OK);

    return VOS_OK;
}


/*****************************************************************************
 函 数 名  : AT_SetSlavePara
 功能描述  : 设置接入模式进入从摸，目前只支持G和W进入从摸
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32 AT_OK查询操作成功，AT_ERROR查询操作失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年7月27日
    作    者   : xwx377961
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_SetSlavePara(VOS_UINT8 ucIndex)
{
    AT_MTA_SLAVE_SET_REQ_STRU           stSlave;
    VOS_UINT32                          ulResult;

    /*局部变量初始化*/
    TAF_MEM_SET_S(&stSlave, (VOS_SIZE_T)sizeof(stSlave), 0x00, (VOS_SIZE_T)sizeof(AT_MTA_SLAVE_SET_REQ_STRU));

    /*参数检查*/
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /*参数数目过多*/
    if (1 != gucAtParaIndex )
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /*参数长度检查*/
    if (1 != gastAtParaList[0].usParaLen)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /*填写消息参数*/
    stSlave.ucRatType = gastAtParaList[0].ulParaValue;

    /*发送消息给MTA*/
    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      gastAtClientTab[ucIndex].opId,
                                      ID_AT_MTA_SLAVE_SET_REQ,
                                      &stSlave,
                                      (VOS_SIZE_T)sizeof(stSlave),
                                      I0_UEPS_PID_MTA);
    /*发送失败*/
    if (TAF_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_SetSlavePara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /*发送成功，设置当前操作模式*/
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_SETSLAVE_SET;

    /*等待异步处理时间返回*/
    return AT_WAIT_ASYNC_RETURN;
}

/*****************************************************************************
 函 数 名  : AT_SetSlavePara
 功能描述  : AT处理MTA发送ID_MTA_AT_SLAVE_SET_CNF消息的操作
 输入参数  : VOS_VOID *pMsg     -- MAT模块发送的消息
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年7月27日
    作    者   : xwx377961
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_RcvMtaSetSlaveCnf( VOS_VOID *pMsg )
{
    AT_MTA_MSG_STRU                    *pstRcvMsg;
    MTA_AT_RESULT_CNF_STRU             *pstResult;
    VOS_UINT8                           ucIndex;
    VOS_UINT32                          ulResult;

    /*初始化局部变量*/
    pstRcvMsg       = (AT_MTA_MSG_STRU *)pMsg;
    pstResult       = (MTA_AT_RESULT_CNF_STRU *)pstRcvMsg->aucContent;
    ucIndex         = AT_BROADCAST_CLIENT_INDEX_MODEM_0;

    /*通过clientid获取index */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSetSlaveCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSetSlaveCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* 判断当前操作类型是否为AT_CMD_SETSLAVE_SET */
    if (AT_CMD_SETSLAVE_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaSetSlaveCnf: NOT CURRENT CMD OPTION!");
        return VOS_ERR;
    }

    /* 复位AT状态 */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* MTA传来消息命令结果处理 */
    if (MTA_AT_RESULT_NO_ERROR == pstResult->enResult)
    {
        /*命令结果 *AT_OK*/
        ulResult    = AT_OK;
    }
    else
    {
        /*命令结果 *AT_ERROR*/
        ulResult    = AT_ERROR;
    }

    gstAtSendData.usBufLen = 0;

    /* 调用AT_FormATResultDATa发送命令结果 */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : AT_QryRficIDPara
 功能描述  : 查询RFIC IDE ID
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32 AT_OK查询操作成功，AT_ERROR查询操作失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年8月27日
    作    者   : xwx377961
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_QryRficDieIDPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                          ulRst;

    if(AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_ERROR;
    }

    /* 发送跨核消息到C核, 查询RFIC IDE ID*/
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_RFIC_DIE_ID_QRY_REQ,
                                   VOS_NULL_PTR,
                                   0,
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_QryRficDieIDPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* 设置AT模块实体的状态为等待异步返回 */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_RFIC_DIE_ID_QRY;

    return AT_WAIT_ASYNC_RETURN;
}

/*****************************************************************************
 函 数 名  : AT_RcvMtaRficDieIDQryCnf
 功能描述  : AT处理MTA发送ID_MTA_AT_RFIC_DIE_ID_QRY_CNF消息的操作
 输入参数  : VOS_VOID *pMsg     -- MAT模块发送的消息
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年8月27日
    作    者   : xwx377961
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_RcvMtaRficDieIDQryCnf( VOS_VOID *pMsg )
{
    AT_MTA_MSG_STRU                    *pstRcvMsg;
    MTA_AT_RFIC_DIE_ID_REQ_CNF_STRU    *pstRficDieIDReqCnf;
    VOS_UINT8                           ucIndex;
    VOS_UINT16                          usLength;

    /*初始化局部变量*/
    pstRcvMsg                 = (AT_MTA_MSG_STRU *)pMsg;
    pstRficDieIDReqCnf        = (MTA_AT_RFIC_DIE_ID_REQ_CNF_STRU *)pstRcvMsg->aucContent;
    ucIndex                   = AT_BROADCAST_CLIENT_INDEX_MODEM_0;
    usLength                  = 0;

    /*通过clientid获取index */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaRficDieIDQryCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaRficDieIDQryCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* 判断当前操作类型是否为AT_CMD_RFIC_DIE_ID_QRY */
    if (AT_CMD_RFIC_DIE_ID_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaRficDieIDQryCnf: NOT CURRENT CMD OPTION!");
        return VOS_ERR;
    }

    /* 复位AT状态 */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /*格式化上报命令*/
    if (MTA_AT_RESULT_NO_ERROR != pstRficDieIDReqCnf->enResult)
    {
        /*命令结果 *AT_ERROR*/
        gstAtSendData.usBufLen = 0;
        At_FormatResultData(ucIndex, AT_ERROR);
    }
    else
    {
        /*命令结果 *AT_OK*/
        if (VOS_TRUE == pstRficDieIDReqCnf->usRfic0DieIdValid)
        {
            usLength = AT_RficDieIDOut((VOS_UINT8*)pstRficDieIDReqCnf->ausRfic0DieId, 0, usLength, ucIndex);
        }

        if (VOS_TRUE == pstRficDieIDReqCnf->usRfic1DieIdValid)
        {
            usLength = AT_RficDieIDOut((VOS_UINT8*)pstRficDieIDReqCnf->ausRfic1DieId, 1, usLength, ucIndex);
        }

        if (VOS_TRUE == pstRficDieIDReqCnf->usRfic2DieIdValid)
        {
            usLength = AT_RficDieIDOut((VOS_UINT8*)pstRficDieIDReqCnf->ausRfic2DieId, 2, usLength, ucIndex);
        }
        if (VOS_TRUE == pstRficDieIDReqCnf->usRfic3DieIdValid)
        {
            usLength = AT_RficDieIDOut((VOS_UINT8*)pstRficDieIDReqCnf->ausRfic3DieId, 3, usLength, ucIndex);
        }

        gstAtSendData.usBufLen = usLength;
        At_FormatResultData(ucIndex, AT_OK);
    }

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : AT_RficDieIDOut
 功能描述  : 格式化输出RFIC DIE ID
 输入参数  : VOS_UINT16 *pMsg   -- RFIC DIE ID结果数组
             VOS_UINT32 RficNum -- 第几组RFIC DIE ID结果数组
 输出参数  : 输出长度
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年8月27日
    作    者   : xwx377961
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT16 AT_RficDieIDOut(
    VOS_UINT8                          *pMsg,
    VOS_UINT32                          RficNum,
    VOS_UINT16                          usLength,
    VOS_UINT8                           ucIndex
)
{
    VOS_UINT32                          i;           /*循环用*/
    VOS_UINT16                          usLengthtemp;

    usLengthtemp = usLength;

    usLengthtemp += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (VOS_CHAR *)pgucAtSndCodeAddr,
                                       (VOS_CHAR *)pgucAtSndCodeAddr + usLengthtemp,
                                       "%s: %d,\"",
                                       g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                       RficNum);

    /*RFIC ID 使用低八位数据*/
    for (i =  0; i < (MTA_RCM_MAX_DIE_ID_LEN * 2); i += 2)
    {
        usLengthtemp += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                           (VOS_CHAR *)pgucAtSndCodeAddr + usLengthtemp,
                                           "%02x",
                                           pMsg[i]);
    }

    usLengthtemp += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (VOS_CHAR *)pgucAtSndCodeAddr,
                                       (VOS_CHAR *)pgucAtSndCodeAddr + usLengthtemp,
                                       "\"%s",
                                       gaucAtCrLf);
    return usLengthtemp;
}

/*****************************************************************************
 函 数 名  : AT_QryPmuDieSNPara
 功能描述  : 查询PMU IDE SN
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32 AT_OK查询操作成功，AT_ERROR查询操作失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年8月29日
    作    者   : xwx377961
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_QryPmuDieSNPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                          ulRst;

    if(AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_ERROR;
    }

    /* 发送跨核消息到C核, 查询RFIC IDE ID*/
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_PMU_DIE_SN_QRY_REQ,
                                   VOS_NULL_PTR,
                                   0,
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_QryPmuDieSNPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* 设置AT模块实体的状态为等待异步返回 */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_PMU_DIE_SN_QRY;

    return AT_WAIT_ASYNC_RETURN;
}

/*****************************************************************************
 函 数 名  : AT_RcvMtaPmuDieSNQryCnf
 功能描述  : AT处理MTA发送ID_MTA_AT_PMU_DIE_SN_QRY_CNF消息的操作
 输入参数  : VOS_VOID *pMsg     -- MAT模块发送的消息
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年8月27日
    作    者   : xwx377961
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_RcvMtaPmuDieSNQryCnf( VOS_VOID *pMsg )
{
    AT_MTA_MSG_STRU                    *pstRcvMsg;
    MTA_AT_PMU_DIE_SN_REQ_CNF_STRU     *pstPmuDieSNReqCnf;
    VOS_INT32                           i;        /*循环数*/
    VOS_UINT16                          usLength;
    VOS_UINT8                           ucIndex;

    /*初始化局部变量*/
    pstRcvMsg                 = (AT_MTA_MSG_STRU *)pMsg;
    pstPmuDieSNReqCnf         = (MTA_AT_PMU_DIE_SN_REQ_CNF_STRU *)pstRcvMsg->aucContent;
    ucIndex                   = AT_BROADCAST_CLIENT_INDEX_MODEM_0;
    usLength                  = 0;

    /*通过clientid获取index */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaPmuDieSNQryCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaPmuDieSNQryCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* 判断当前操作类型是否为AT_CMD_PMU_DIE_SN_QRY */
    if (AT_CMD_PMU_DIE_SN_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaPmuDieSNQryCnf: NOT CURRENT CMD OPTION!");
        return VOS_ERR;
    }

    /* 复位AT状态 */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /*格式化上报命令*/
    if (MTA_AT_RESULT_NO_ERROR != pstPmuDieSNReqCnf->enResult)
    {
        /*命令结果 *AT_ERROR*/
        gstAtSendData.usBufLen = 0;
        At_FormatResultData(ucIndex, AT_ERROR);
    }
    else
    {
        /*命令结果 *AT_OK*/

        /* 最高位,高4 BIT置0 */
        pstPmuDieSNReqCnf->aucDieSN[MTA_PMU_MAX_DIE_SN_LEN - 1] = (pstPmuDieSNReqCnf->aucDieSN[MTA_PMU_MAX_DIE_SN_LEN - 1] & 0x0F);

        /* 格式化输出查询结果 */
        usLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                          (VOS_CHAR *)pgucAtSndCodeAddr,
                                          (VOS_CHAR *)pgucAtSndCodeAddr,
                                          "%s: 0x",
                                          g_stParseContext[ucIndex].pstCmdElement->pszCmdName);

        for (i = (MTA_PMU_MAX_DIE_SN_LEN-1); i >= 0; i--)
        {
            usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                               (VOS_CHAR *)pgucAtSndCodeAddr,
                                               (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                               "%02x",
                                               pstPmuDieSNReqCnf->aucDieSN[i]);
        }

        gstAtSendData.usBufLen = usLength;
        At_FormatResultData(ucIndex, AT_OK);
    }

    return VOS_OK;
}


/*****************************************************************************
 函 数 名  : AT_SetTasTestCfg
 功能描述  : AT发送给MTA的消息的操作，消息的用途是设置TAS命令参数
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32 AT_OK设置操作成功，AT_ERROR设置操作失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年9月27日
    作    者   : lwx331495
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_SetTasTestCfg(VOS_UINT8 ucIndex)
{
    AT_MTA_TAS_TEST_CFG_STRU            stTasParamReq;
    VOS_UINT32                          ulResult;

    /*局部变量初始化*/
    TAF_MEM_SET_S(&stTasParamReq, (VOS_SIZE_T)sizeof(stTasParamReq), 0x00, (VOS_SIZE_T)sizeof(AT_MTA_TAS_TEST_CFG_STRU));

    /*参数检查*/
    if ((5 != gucAtParaIndex)
     || (0 == gastAtParaList[0].usParaLen)
     || (0 == gastAtParaList[1].usParaLen)
     || (0 == gastAtParaList[2].usParaLen)
     || (0 == gastAtParaList[3].usParaLen)
     || (0 == gastAtParaList[4].usParaLen))
        {
            return AT_CME_INCORRECT_PARAMETERS;
        }

    /*填写消息参数*/
    stTasParamReq.enRatMode = gastAtParaList[0].ulParaValue;
    stTasParamReq.ulPara0   = gastAtParaList[1].ulParaValue;
    stTasParamReq.ulPara1   = gastAtParaList[2].ulParaValue;
    stTasParamReq.ulPara2   = gastAtParaList[3].ulParaValue;
    stTasParamReq.ulPara3   = gastAtParaList[4].ulParaValue;

    /*发送消息给MTA*/
    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      gastAtClientTab[ucIndex].opId,
                                      ID_AT_MTA_TAS_CFG_REQ,
                                      &stTasParamReq,
                                      (VOS_SIZE_T)sizeof(stTasParamReq),
                                      I0_UEPS_PID_MTA);
    /*发送失败*/
    if (TAF_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_SetTasTestCfg: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /*发送成功，设置当前操作模式*/
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_TAS_TEST_SET;

    /*等待异步处理时间返回*/
    return AT_WAIT_ASYNC_RETURN;
}

/*****************************************************************************
 函 数 名  : AT_QryTasTestCfgpara
 功能描述  : AT发送给MTA的消息的操作，消息的用途是查询TAS参数和模式
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32 AT_OK查询操作成功，AT_ERROR查询操作失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年10月21日
    作    者   : lwx331495
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_QryTasTestCfgPara(VOS_UINT8 ucIndex)
{

    VOS_UINT32                          ulResult;
    AT_MTA_TAS_TEST_QRY_STRU            stAtMtaTasTestQry;

    /*参数检查*/
    if ((1 != gucAtParaIndex)
     || (0 == gastAtParaList[0].usParaLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /*填写消息参数*/
    stAtMtaTasTestQry.enRatMode = gastAtParaList[0].ulParaValue;

    /*发送消息给MTA*/
    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      gastAtClientTab[ucIndex].opId,
                                      ID_AT_MTA_TAS_QRY_REQ,
                                      &stAtMtaTasTestQry,
                                      (VOS_SIZE_T)sizeof(stAtMtaTasTestQry),
                                      I0_UEPS_PID_MTA);
    /*发送失败*/
    if (TAF_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_QryTasTestCfgPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /*发送成功，设置当前操作模式*/
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_TAS_TEST_QRY;

    /*等待异步处理时间返回*/
    return AT_WAIT_ASYNC_RETURN;
}

/*****************************************************************************
 函 数 名  : AT_RcvMtaTasTestCfgCnf
 功能描述  : AT处理MTA发送 ID_MTA_AT_TAS_TEST_CFG_CNF 消息的操作
 输入参数  : VOS_VOID *pMsg     -- MAT模块发送的消息
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年9月28日
    作    者   : LWX331495
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_RcvMtaTasTestCfgCnf( VOS_VOID *pMsg )
{
    AT_MTA_MSG_STRU                    *pstRcvMsg;
    MTA_AT_TAS_TEST_CFG_CNF_STRU       *pstMtaAtTasTestCfgCnf = VOS_NULL_PTR;

    VOS_UINT8                           ucIndex;
    VOS_UINT32                          ulResult;

    /*初始化局部变量*/
    pstRcvMsg                 = (AT_MTA_MSG_STRU *)pMsg;
    pstMtaAtTasTestCfgCnf     = (MTA_AT_TAS_TEST_CFG_CNF_STRU *)pstRcvMsg->aucContent;
    ucIndex                   = AT_BROADCAST_CLIENT_INDEX_MODEM_0;

    /*通过clientid获取index */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaTasTestCfgCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaTasTestCfgCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* 判断当前操作类型是否为AT_CMD_TAS_TEST_CFG_SET */
    if (AT_CMD_TAS_TEST_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaTasTestCfgCnf: NOT CURRENT CMD OPTION!");
        return VOS_ERR;
    }

    /* 复位AT状态 */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /*格式化上报命令*/
    if (MTA_AT_RESULT_NO_ERROR == pstMtaAtTasTestCfgCnf->enResult)
    {
        /*命令结果 *AT_OK*/
        ulResult    = AT_OK;
    }
    else
    {
        /*命令结果 *AT_ERROR*/
        ulResult    = AT_ERROR;
    }

    gstAtSendData.usBufLen = 0;
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : AT_RcvMtaTasTestQryCnf
 功能描述  : AT处理MTA发送ID_MTA_AT_RFIC_DIE_ID_QRY_CNF消息的操作
 输入参数  : VOS_VOID *pMsg     -- MAT模块发送的消息
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年10月24日
    作    者   : lwx331495
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_RcvMtaTasTestQryCnf( VOS_VOID *pMsg )
{
    AT_MTA_MSG_STRU                    *pstRcvMsg;
    MTA_AT_TAS_TEST_QRY_CNF_STRU       *pstMtaAtTasTestReqCnf;
    VOS_UINT16                          usLength;
    VOS_UINT8                           ucIndex;

    /* 初始化局部变量 */
    pstRcvMsg                 = (AT_MTA_MSG_STRU *)pMsg;
    pstMtaAtTasTestReqCnf     = (MTA_AT_TAS_TEST_QRY_CNF_STRU *)pstRcvMsg->aucContent;
    usLength                  = 0;
    ucIndex                   = 0;

    /* 通过clientid获取index */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaTasTestQryCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaTasTestQryCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* 判断当前操作类型是否为AT_CMD_RFIC_DIE_ID_QRY */
    if (AT_CMD_TAS_TEST_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaTasTestQryCnf: NOT CURRENT CMD OPTION!");
        return VOS_ERR;
    }

    /* 复位AT状态 */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* 格式化上报命令 */
    if (MTA_AT_RESULT_NO_ERROR != pstMtaAtTasTestReqCnf->enResult)
    {
        /* 命令结果 *AT_ERROR */
        gstAtSendData.usBufLen = 0;
        At_FormatResultData(ucIndex, AT_ERROR);
    }
    else
    {
        /* 命令结果 *AT_OK */
        usLength = AT_TasTestOut(pstMtaAtTasTestReqCnf);
        gstAtSendData.usBufLen = usLength;
        At_FormatResultData(ucIndex, AT_OK);
    }

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : AT_TasTestOut
 功能描述  : 格式化输出tas test 查询结果
 输入参数  : MTA_AT_TAS_TEST_QRY_CNF_STRU   *pstMtaAtTasTestReqCnf
 输出参数  : 输出长度
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年10月24日
    作    者   : lwx331495
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT16 AT_TasTestOut(
    MTA_AT_TAS_TEST_QRY_CNF_STRU       *pstMtaAtTasTestReqCnf
)
{
    VOS_UINT32                          i;           /*循环用*/
    VOS_UINT16                          usLength;

    usLength = 0;

    usLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                      (VOS_CHAR *)pgucAtSndCodeAddr,
                                      (VOS_CHAR *)pgucAtSndCodeAddr,
                                      "level index: %d (%d, %d, %d, %d)%s",
                                       pstMtaAtTasTestReqCnf->ulCurrLevel,
                                       pstMtaAtTasTestReqCnf->stLevelInfo.uhwSrcAntTimeLength,
                                       pstMtaAtTasTestReqCnf->stLevelInfo.uhwDestAntTimeLength,
                                       pstMtaAtTasTestReqCnf->stLevelInfo.shwSrcAntTxPowerGain,
                                       pstMtaAtTasTestReqCnf->stLevelInfo.shwDestAntTxPowerGain,
                                       gaucAtCrLf);

    usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (VOS_CHAR *)pgucAtSndCodeAddr,
                                       (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                       "level table:%s",
                                       gaucAtCrLf);

    if (pstMtaAtTasTestReqCnf->stUsedTable.uhwLevelNum > MAX_STATEII_LEVEL_ITEM)
    {
        pstMtaAtTasTestReqCnf->stUsedTable.uhwLevelNum = MAX_STATEII_LEVEL_ITEM;
    }

    /* 打印表格 */
    for (i =  0; i < pstMtaAtTasTestReqCnf->stUsedTable.uhwLevelNum; i++)
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                          (VOS_CHAR *)pgucAtSndCodeAddr,
                                          (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                          "            (%d, %d, %d, %d)%s",
                                           pstMtaAtTasTestReqCnf->stUsedTable.astLevelItem[i].uhwSrcAntTimeLength,
                                           pstMtaAtTasTestReqCnf->stUsedTable.astLevelItem[i].uhwDestAntTimeLength,
                                           pstMtaAtTasTestReqCnf->stUsedTable.astLevelItem[i].shwSrcAntTxPowerGain,
                                           pstMtaAtTasTestReqCnf->stUsedTable.astLevelItem[i].shwDestAntTxPowerGain,
                                           gaucAtCrLf);
    }
    return usLength;
}

/*****************************************************************************
 函 数 名  : AT_SetCdmaAttDiversitySwitch
 功能描述  : 设置cmda DiversitySwitch开关
 输入参数  : VOS_VOID *pMsg
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年10月14日
    作    者   : h00360002
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_SetCdmaAttDiversitySwitch(VOS_UINT8 ucIndex)
{
    VOS_UINT32                          ulRet;
    VOS_UINT32                          ulNVWrTotleLen;
    VOS_UINT8                           ulNVWrLen;
    VOS_UINT8                           ucDiversitySwitch;

    if (VOS_TRUE != AT_IsNVWRAllowedNvId(en_NV_Item_CPROC_1X_NVIM_DM_THRESHOLD))
    {
        return AT_CME_OPERATION_NOT_ALLOWED;
    }

    if (0 == gastAtParaList[0].usParaLen)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    ucDiversitySwitch = (VOS_UINT8)gastAtParaList[0].ulParaValue;
    ulNVWrLen         = sizeof(ucDiversitySwitch);

    ulRet = NV_GetLength(en_NV_Item_CPROC_1X_NVIM_DM_THRESHOLD, &ulNVWrTotleLen);

    if ((ERR_MSP_SUCCESS != ulRet)
     || (ulNVWrLen > ulNVWrTotleLen) )
    {
        return AT_ERROR;
    }

    ulRet = NV_WritePartEx(MODEM_ID_0, en_NV_Item_CPROC_1X_NVIM_DM_THRESHOLD, 0, (VOS_VOID*)&ucDiversitySwitch, ulNVWrLen);
    if(ERR_MSP_SUCCESS != ulRet)
    {
        return AT_ERROR;
    }

    return AT_OK;
}

/*****************************************************************************
 函 数 名  : AT_SetMipiReadPara
 功能描述  : 设置MIPI读速率指标
 输入参数  : VOS_UINT8 ucIndex
 输出参数  : 无
 返 回 值  : VOS_UINT32 AT_OK查询操作成功，AT_ERROR查询操作失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年05月15日
    作    者   : w00316404
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_SetMipiReadPara(VOS_UINT8 ucIndex)
{
    AT_MTA_MIPI_READ_REQ_STRU           stMipiReadReq;
    VOS_UINT32                          ulResult;

    /*局部变量初始化*/
    TAF_MEM_SET_S(&stMipiReadReq, (VOS_SIZE_T)sizeof(stMipiReadReq), 0x00, (VOS_SIZE_T)sizeof(AT_MTA_MIPI_READ_REQ_STRU));

    /*参数检查*/
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /*参数数目不正确*/
    if (7 != gucAtParaIndex )
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /*不是非信令模式*/
    if (AT_TMODE_FTM != g_stAtDevCmdCtrl.ucCurrentTMode)
    {
        return AT_DEVICE_MODE_ERROR;
    }

    /*参数长度检查*/
    if ( (0 == gastAtParaList[0].usParaLen)
      || (0 == gastAtParaList[1].usParaLen)
      || (0 == gastAtParaList[2].usParaLen)
      || (0 == gastAtParaList[3].usParaLen)
      || (0 == gastAtParaList[4].usParaLen)
      || (0 == gastAtParaList[5].usParaLen)
      || (0 == gastAtParaList[6].usParaLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /*填写消息参数*/
    stMipiReadReq.usReadType    = (VOS_UINT16)gastAtParaList[0].ulParaValue;
    stMipiReadReq.usMipiId      = (VOS_UINT16)gastAtParaList[1].ulParaValue;
    stMipiReadReq.usSlaveId     = (VOS_UINT16)gastAtParaList[2].ulParaValue;
    stMipiReadReq.usRegAddr     = (VOS_UINT16)gastAtParaList[3].ulParaValue;
    stMipiReadReq.usSpeedType   = (VOS_UINT16)gastAtParaList[4].ulParaValue;
    stMipiReadReq.usReadBitMask = (VOS_UINT16)gastAtParaList[5].ulParaValue;
    stMipiReadReq.usReserved1   = (VOS_UINT16)gastAtParaList[6].ulParaValue;


    /*发送消息给MTA*/
    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      gastAtClientTab[ucIndex].opId,
                                      ID_AT_MTA_MIPIREAD_SET_REQ,
                                      &stMipiReadReq,
                                      (VOS_SIZE_T)sizeof(stMipiReadReq),
                                      I0_UEPS_PID_MTA);
    /*发送失败*/
    if (TAF_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_SetMipiReadPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /*发送成功，设置当前操作模式*/
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_MIPIREAD_SET;

    /*等待异步处理时间返回*/
    return AT_WAIT_ASYNC_RETURN;
}

/*****************************************************************************
 函 数 名  : AT_RcvMtaSetMipiReadCnf
 功能描述  : ID_MTA_AT_MIPIREAD_SET_CNF消息处理函数
 输入参数  : VOS_VOID *pstMsg - 消息指针
 输出参数  : 无
 返 回 值  : VOS_UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2017年05月15日
    作    者   : w00316404
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 AT_RcvMtaSetMipiReadCnf(VOS_VOID *pstMsg)
{
    AT_MTA_MSG_STRU                    *pRcvMsg             = VOS_NULL_PTR;
    MTA_AT_MIPI_READ_CNF_STRU          *pstSetMipiReadCnf   = VOS_NULL_PTR;
    VOS_UINT16                          ulLength;
    VOS_UINT8                           ucIndex;

    /* 初始化 */
    pRcvMsg             = (AT_MTA_MSG_STRU*)pstMsg;
    pstSetMipiReadCnf   = (MTA_AT_MIPI_READ_CNF_STRU*)pRcvMsg->aucContent;
    ucIndex             = 0;

    /* 通过clientid获取index */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSetMipiReadCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSetMipiReadCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* 当前AT是否在等待该命令返回 */
    if (AT_CMD_MIPIREAD_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaSetMipiReadCnf: NOT AT_CMD_MIPIREAD_SET.");
        return VOS_ERR;
    }

    /* 复位AT状态 */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* 判断回复消息中的错误码 */
    if (MTA_AT_RESULT_NO_ERROR == pstSetMipiReadCnf->enResult)
    {
        /* 命令结果 *AT_OK */
        ulLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                          (VOS_CHAR *)pgucAtSndCodeAddr,
                                          (VOS_CHAR *)pgucAtSndCodeAddr,
                                          "%s:%d",
                                          g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                          pstSetMipiReadCnf->ulValue);

        gstAtSendData.usBufLen = ulLength;
        At_FormatResultData(ucIndex, AT_OK);
    }
    else
    {
        /* 命令结果 *AT_ERROR */
        gstAtSendData.usBufLen = 0;
        At_FormatResultData(ucIndex, AT_ERROR);
    }

    return VOS_OK;
}



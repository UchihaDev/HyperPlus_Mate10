/*************************************************************************
*   版权所有(C) 2008-2015, 深圳华为技术有限公司.
*
*   文 件 名 :  board_trace_balong.c
*
*   作    者 :  yangzhi 00171698
*
*   描    述 :  board trace state ind
*
*   修改记录 : 2017年3月14日  v1.00  y00171698  创建
**************************************************************************/
#include "board_trace_balong.h"

BOARD_TRACE_INFO_S * g_str_board_info=NULL;
u32 bInitFlag = FALSE;

/*****************************************************************************
* 函 数 名	:  get_board_info
*
* 功能描述	:  
*
*
* 输入参数	:  
* 输出参数	:  
*
* 返 回 值	:  无
*
*****************************************************************************/
int get_board_info(BOARD_TRACE_TYPE_ENUM_U32 eType, BOARD_TRACE_TLV_S *pBoardTlvInfo)
{
    int     	iRet 	= BSP_OK;
    
    
    if(NULL == pBoardTlvInfo)
    {
        /* bsp _trace print error */
    	 bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "%s,para is Null!\n",__FUNCTION__);
    	 return BSP_ERR_BOARD_TRACE_PARA;  
    }


    /*judge etype and solve */
    switch(eType)
    {
        case BSP_BOARD_TYPE_ASIC:
            pBoardTlvInfo->uType = eType;  /*lint !e64*/
            pBoardTlvInfo->uLength = BOARD_TRACE_INFO_UDP_LENGTH;
            iRet = mdrv_efuse_get_dieid((unsigned char*)(pBoardTlvInfo->uValue), BOARD_TRACE_INFO_UDP_LENGTH*sizeof(u8));
            if (EFUSE_OK != iRet) 
            {
                bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "%s,get die id fail!\n",__FUNCTION__);
                iRet = BSP_ERR_BOARD_TRACE_GET;
            }
            break;
        case BSP_BOARD_TYPE_SFT:
        case BSP_BOARD_TYPE_PORTING:
            /*add code here */
            bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "%s, this type:%d not support currently!\n",__FUNCTION__, eType);   
            iRet = BSP_ERR_BOARD_TRACE_SUPPORT;
            break;
        default:
	     bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "%s, type:%d error!\n",__FUNCTION__, eType);
            return BSP_ERR_BOARD_TRACE_SUPPORT;
    }
    
    return iRet;
}

/*****************************************************************************
* 函 数 名	:  bsp_board_info_ind
*
* 功能描述	:  ind func 
*
*
* 输入参数	:  
* 输出参数	:  
*
* 返 回 值	:  无
*
*****************************************************************************/
u32 bsp_board_trace_ind(void)
{
    s32 slRet 	= 0;
    u32 ulSize 	= 0;
    TRANS_IND_STRU sTransInd = {0};
    
    /* 31-24:modemid,23-16:modeid */
    sTransInd.ulModule   = 0xF0000;   /* has nothing with mode, so it's 0xF000  */
    sTransInd.ulMsgId 	= BOARD_TRACE_IND_MSGID;  
    sTransInd.ulPid 		= BOARD_TRACE_IND_ULPID;
    ulSize = sizeof(BOARD_TRACE_INFO_S) + (g_str_board_info->uTlvCnt) * sizeof(BOARD_TRACE_TLV_S);
    sTransInd.ulLength	= ulSize;
    sTransInd.pData 	= (void*)(g_str_board_info);
    
    bsp_trace(BSP_LOG_LEVEL_INFO, BSP_MODU_BOARD_TRACE, "pData is %p, g_str_board_info is %p, ulSize is %d\n",sTransInd.pData, g_str_board_info, ulSize);
    bsp_trace(BSP_LOG_LEVEL_INFO, BSP_MODU_BOARD_TRACE, "ulModule: 0x%x, ulMsgId: 0x%x, ulMsgId: 0x%x, ulLength: 0x%x\n", sTransInd.ulModule, sTransInd.ulMsgId, sTransInd.ulPid, sTransInd.ulLength);
    
    /* call bsp_transport func */
    slRet = bsp_transreport(&sTransInd);
    if(slRet != HDS_TRANS_RE_SUCC)
    {
        bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "%s: bsp_transreport return: %d;\n",__FUNCTION__,slRet);
    	 return BSP_ERR_BOARD_TRACE_IND;
    }
    
    /* if success, return OK */
    return BSP_OK;
	
}

/*************************************************************************
 函 数 名	: bsp_TraceProcEntry
 功能描述	: 处理DIAG FW发过来的BSP TRACE配置命令的处理入口
 输入参数	: u8* pstReq, 
 返 回 值	:
 修改历史	:
 日    期	: 
 作    者	: 
 修改内容	:
*************************************************************************/
int bsp_TraceProcEntry(u8* pstReq)
{
    diag_frame_head_stru    *pData;
    MSP_DIAG_DATA_REQ_STRU  *pReqData;
    DIAG_BSP_COMM_CNF_STRU  stLogSetCnf = {0};
    hds_cnf_stru            stCommCnf   = {0};

    HDS_GET_MSG_DATA_CFG(pstReq, pData, pReqData);

    /*set confirm data*/
    stLogSetCnf.ulRet  = (u32)bsp_board_trace_ind();
    stLogSetCnf.ulAuid = pReqData->ulAuid;
    stLogSetCnf.ulSn   = pReqData->ulSn;

    bsp_hds_cnf_common_fill(&stCommCnf, pData);
    bsp_hds_confirm(&stCommCnf, (void*)&stLogSetCnf, sizeof(DIAG_BSP_COMM_CNF_STRU));

    return BSP_OK;
}

/*****************************************************************************
* 函 数 名	:  bsp_board_trace_init
*
* 功能描述	:  init
*
* 输入参数	:  void
* 输出参数	:  void
*
* 返 回 值	:  ok or fail
*
*****************************************************************************/
int bsp_board_trace_init(void)
{
    u32  uTlvLen   = 0;
    int   iInfoRet = 0;
    u8 * pTlvBuf  = NULL;
    const BSP_VERSION_INFO_S 	*pVersionInfo = NULL;
    BOARD_TRACE_TLV_S  		sTraceTlv = {0}; /*lint !e64*/
    
    /* init only once */
    if(bInitFlag == TRUE)
    {
        bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "%s,init already!\n",__FUNCTION__);
    	 return BSP_OK;
    }
    
    /* memset(&g_str_board_info, 0, sizeof(BOARD_TRACE_INFO_S)); */
    pVersionInfo = bsp_get_version_info();
    if(NULL == pVersionInfo)
    {
        bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "%s,get version fail!\n",__FUNCTION__);
    	 return BSP_ERR_BOARD_TRACE_NULL;
    }
    
    /* judge if type is OK */
    if(pVersionInfo->board_type >= BSP_BOARD_TYPE_MAX)
    {
    	  /* bsp _trace print error */
        bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "%s,board type is error!,type:%d\n",__FUNCTION__,pVersionInfo->board_type);
    	 return BSP_ERR_BOARD_TRACE_TYPE;  
    }

    /* get board info */
    iInfoRet = get_board_info(pVersionInfo->board_type, &sTraceTlv);
    if(BSP_ERR_BOARD_TRACE_SUPPORT == iInfoRet)
    {
        bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "%s,this board can't support info ind!\n",__FUNCTION__);
        return iInfoRet;
    }
    else if(BSP_ERR_BOARD_TRACE_GET ==iInfoRet)
    {
        bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "%s,get board trace info fail!\n",__FUNCTION__);
    	 return iInfoRet;
    }
    else
    {
        bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "%s,get board trace info OK!\n",__FUNCTION__);
    }

    uTlvLen = BOARD_TRACE_INFO_TLV_CNT;
    
    /* call get_board_info func */
    pTlvBuf = (u8 *)osl_malloc(uTlvLen * sizeof(BOARD_TRACE_TLV_S) + sizeof(BOARD_TRACE_INFO_S));
    if(NULL == pTlvBuf)
    {
    	bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "%s,malloc tlv buf fail!\n",__FUNCTION__);
    	return BSP_ERR_BOARD_TRACE_MALLOC;
    }
    
    g_str_board_info = (BOARD_TRACE_INFO_S *) pTlvBuf;
    g_str_board_info->uTlvCnt = uTlvLen;
	
    /* coverity[secure_coding] */
    memcpy((void *)(g_str_board_info->sTlvBuf), &sTraceTlv, sizeof(BOARD_TRACE_TLV_S));
    bsp_trace(BSP_LOG_LEVEL_INFO, BSP_MODU_BOARD_TRACE, "%s,uTlvCnt is %d\n",__FUNCTION__, g_str_board_info->uTlvCnt);
    
    /* register ind func */
    bsp_hds_cmd_register(DIAG_CMD_BOARD_TRACE_IND_ACORE, (bsp_hds_func)bsp_TraceProcEntry);
    
    bInitFlag = TRUE;
    
    bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BOARD_TRACE, "\n %s,init OK!\n",__FUNCTION__);
    
    return BSP_OK;
}

EXPORT_SYMBOL(get_board_info);
EXPORT_SYMBOL(bsp_board_trace_ind);
EXPORT_SYMBOL(bsp_TraceProcEntry);
EXPORT_SYMBOL(bsp_board_trace_init);

/*lint --e{528}*/
module_init(bsp_board_trace_init); /*lint !e19 */


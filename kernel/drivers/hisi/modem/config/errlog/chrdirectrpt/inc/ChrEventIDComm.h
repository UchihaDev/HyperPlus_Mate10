/******************************************************************************

  Copyright(C)2008,Hisilicon Co. LTD.

******************************************************************************
File Name       : ChrEventIDComm.h
Description     : ChrEventIDComm.h header file,所有直通事件ID在此定义。
History         :
   1.q00312157      2016-5-25     Draft Enact

******************************************************************************/

#ifndef __ERRLOGCOMM_H__
#define __ERRLOGCOMM_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
1 Include Headfile
*****************************************************************************/
#include  "product_config.h"
#include  "vos.h"

#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif

/*****************************************************************************
2 macro
*****************************************************************************/

/*DEFINE MODEM ALARMID BASE BEGIN*/
/* 直通事件枚举分段，XML定义1个字节，有效范围 0~127，共128个。 */
#define COMM_EventID_ENUM_BASE                              (0)
/* 直通事件分为关联事件与非关联事件，关联事件统一划段，非关联事件按组件分配。 */
/* 直通关联事件，0~53，共54个。 */
#define COMM_RELATION_EVENTID_ENUM_BASE                     (COMM_EventID_ENUM_BASE+0)
/* 直通非关联事件，54~127，共74个。 */
#define COMM_ABSOLUTE_EVENTID_ENUM_BASE                     (COMM_EventID_ENUM_BASE+54)
/* 直通非关联事件各组件分段起始定义, 总体PS COM :10, TLPS:20(TLRRC:12, TL2:3, LNAS:5), GUC:24, PHY:20 */
/* 新增非关联直通协议栈公共事件，事件ID从原关联事件中取10个，原非关联事件组件分配维持不变。 */
#define COMM_PSCOM_EVENTID_ENUM_BASE                        (COMM_ABSOLUTE_EVENTID_ENUM_BASE+0)
#define COMM_TLRRC_EVENTID_ENUM_BASE                        (COMM_ABSOLUTE_EVENTID_ENUM_BASE+10)
#define COMM_TL2_EVENTID_ENUM_BASE                          (COMM_ABSOLUTE_EVENTID_ENUM_BASE+22)
#define COMM_LNAS_EVENTID_ENUM_BASE                         (COMM_ABSOLUTE_EVENTID_ENUM_BASE+25)
#define COMM_GUC_EVENTID_ENUM_BASE                          (COMM_ABSOLUTE_EVENTID_ENUM_BASE+30)
#define COMM_PHY_EVENTID_ENUM_BASE                          (COMM_ABSOLUTE_EVENTID_ENUM_BASE+54)



/* 各个模块的直通子事件枚举分段 */
#define LNAS_SUBEVENTID_ENUM_BASE                           (11000)
#define GUCNAS_SUBEVENTID_ENUM_BASE                         (12000) /* GUC公共模块使用 */

#define CAS_SUBEVENTID_ENUM_BASE                            (13000)

#define LRRC_SUBEVENTID_ENUM_BASE                           (21000)
#define LL2_SUBEVENTID_ENUM_BASE                            (22000)
#define LPHY_SUBEVENTID_ENUM_BASE                           (23000)

#define TRRC_SUBEVENTID_ENUM_BASE                           (24000)
#define TL2_SUBEVENTID_ENUM_BASE                            (25000)
#define TPHY_SUBEVENTID_ENUM_BASE                           (26000)

#define WRRC_SUBEVENTID_ENUM_BASE                           (31000)
#define WL2_SUBEVENTID_ENUM_BASE                            (32000)
#define WPHY_SUBEVENTID_ENUM_BASE                           (33000)

#define GAS_SUBEVENTID_ENUM_BASE                            (34000)
#define GL2_SUBEVENTID_ENUM_BASE                            (35000)
#define GPHY_SUBEVENTID_ENUM_BASE                           (36000)

#define CRRC_SUBEVENTID_ENUM_BASE                           (37000)
#define CL2_SUBEVENTID_ENUM_BASE                            (38000)
#define CPHY_SUBEVENTID_ENUM_BASE                           (39000)

/*DEFINE MODEM ALARMID BASE END*/

/*LNAS 内部模块分组*/
#define LNAS_EMM_SUBEVENTID_ENUM_BASE          (LNAS_SUBEVENTID_ENUM_BASE)
#define LNAS_ESM_SUBEVENTID_ENUM_BASE          (LNAS_SUBEVENTID_ENUM_BASE+50)
#define LNAS_IMSA_SUBEVENTID_ENUM_BASE         (LNAS_SUBEVENTID_ENUM_BASE+100)
#define LNAS_LCS_SUBEVENTID_ENUM_BASE          (LNAS_SUBEVENTID_ENUM_BASE+150)
#define LNAS_LPP_SUBEVENTID_ENUM_BASE          (LNAS_SUBEVENTID_ENUM_BASE+170)


/*****************************************************************************
3 Massage Declare
*****************************************************************************/

/*****************************************************************************
 4 ENUM
*****************************************************************************/

/*******************************************************************************************************************
 --------------------------------------------------事件定义------------------------------------------------------
*******************************************************************************************************************/

/*****************************************************************************
 枚举名    : MODEM_COMM_ALARMID_ENUM_UINT8
 协议表格  :
 ASN.1描述 :
 枚举说明  : 公共事件告警类型枚举定义，包含两类:
            1、关联事件告警类型枚举定义
            2、非关联事件告警类型枚举类型定义(非关联事件已组件区别事件，
            该事件是多个非关联子事件的集合)

*****************************************************************************/
enum MODEM_COMM_EVENTID_ENUM
{
    /**************************************** 定义关联事件EventID**********************************************/
    TDS_OOS_INFO_REPORT_FAULTID                        = COMM_RELATION_EVENTID_ENUM_BASE+0,



    /**************************************** 定义非关联事件EventID**********************************************/
    /* 定义TLRRC非关联事件EventID */
    TRRC_STATISTIC_INFO_COLLECTION_EVENTID             = COMM_TLRRC_EVENTID_ENUM_BASE+0,
    LRRC_STATISTIC1_INFO_COLLECTION_EVENTID            = COMM_TLRRC_EVENTID_ENUM_BASE+1,
    LRRC_STATISTIC2_INFO_COLLECTION_EVENTID            = COMM_TLRRC_EVENTID_ENUM_BASE+2,
    LRRC_VOLTE_FAULT_AUTOAN_IND_EVENTID                = COMM_TLRRC_EVENTID_ENUM_BASE+3,
    LPS_VOLTE_STAT_IND_EVENTID                         = COMM_TLRRC_EVENTID_ENUM_BASE+4,

    /* 定义TL非关联事件EventID */
    TMAC_STATISTIC_INFO_COLLECTION_EVENTID             = COMM_TL2_EVENTID_ENUM_BASE+0,
    LL2_STATISTIC_INFO_COLLECTION_EVENTID              = COMM_TL2_EVENTID_ENUM_BASE+1,

    /* 定义LANS非关联事件EventID */
    LNAS_STATISTIC_INFO_COLLECTION_EVENTID             = COMM_LNAS_EVENTID_ENUM_BASE+0,

    /* 定义GAS非关联事件EventID */
    GAS_STATISTIC_INFO_COLLECTION_EVENTID              = COMM_GUC_EVENTID_ENUM_BASE+0,

    /* 定义资源核查非关联事件EventID */
    PS_RADIO_RESOURCE_CHECK_EVENTID                    = COMM_PSCOM_EVENTID_ENUM_BASE+1,
    /*Added by h00377722 for 多种场景CHR, 2017-03-14,begin*/
    /* 定义WAS非关联事件EventID */
    WAS_STATISTIC_INFO_COLLECTION_EVENTID              = COMM_GUC_EVENTID_ENUM_BASE+1,
    /*Added by h00377722 for 多种场景CHR, 2017-03-14,end*/
    /* 定义GUCNAS非关联事件EventID */
    GUCNAS_STATISTIC_INFO_COLLECTION_EVENTID           = COMM_GUC_EVENTID_ENUM_BASE+2,

    /* 其他组件非关联事件EventID在此定义 */

    COMM_ERRORLOG_EVENTID_TYPE_BUTT
};
typedef VOS_UINT8  MODEM_COMM_EVENTID_ENUM_UINT8;


/*******************************************************************************************************************
 --------------------------------------------------子事件定义------------------------------------------------------
*******************************************************************************************************************/
/*****************************************************************************
 枚举名    : MODEM_GAS_SUBEVENTID_ENUM_UINT16
 协议表格  :
 ASN.1描述 :
 枚举说明  : GAS告警类型子事件枚举定义
*****************************************************************************/
enum MODEM_GAS_SUBEVENTID_ENUM
{
    GAS_NOT_SUPP_BSS_PAGING_COOR_CHR_RPT_STRU_ALARMID     = GAS_SUBEVENTID_ENUM_BASE+1,
    GAS_RADIO_RESOURCE_CHECK_CHR_RPT_STRU_ALARMID         = GAS_SUBEVENTID_ENUM_BASE+2,
    GAS_CUSTOM_C1_CELL_CHR_RPT_STRU_ALARMID               = GAS_SUBEVENTID_ENUM_BASE+3,
    GAS_ERR_LOG_EVT_NET_WORK_FEATURE_RPT_STRU_ALARMID     = GAS_SUBEVENTID_ENUM_BASE+4,

    GAS_ERRORLOG_ALARMID_BUTT
};
typedef VOS_UINT16  MODEM_GAS_SUBEVENTID_ENUM_UINT16;

/*****************************************************************************
 枚举名    : MODEM_GUCNAS_SUBEVENTID_ENUM_UINT16
 协议表格  :
 ASN.1描述 :
 枚举说明  : GUCNAS子事件枚举定义
*****************************************************************************/
enum MODEM_GUCNAS_SUBEVENTID_ENUM
{
    GUCNAS_RADIO_RESOURCE_CHECK_CHR_RPT_STRU_ALARMID       = GUCNAS_SUBEVENTID_ENUM_BASE+1,
    GUCNAS_SS_DECODE_EXCEPT_CHR_RPT_STRU_ALARMID           = GUCNAS_SUBEVENTID_ENUM_BASE+2,

    GUCNAS_ERRORLOG_ALARMID_BUTT
};
typedef VOS_UINT16  MODEM_GUCNAS_SUBEVENTID_ENUM_UINT16;



/*****************************************************************************
 枚举名    : MODEM_CAS_SUBEVENTID_ENUM_UINT16
 协议表格  :
 ASN.1描述 :
 枚举说明  : CAS子事件枚举定义
*****************************************************************************/
enum MODEM_CAS_SUBEVENTID_ENUM
{
    CAS_1X_RADIO_RESOURCE_CHECK_CHR_RPT_STRU_ALARMID       = CAS_SUBEVENTID_ENUM_BASE+1,
    CAS_HRPD_RADIO_RESOURCE_CHECK_CHR_RPT_STRU_ALARMID     = CAS_SUBEVENTID_ENUM_BASE+2,

    CAS_ERRORLOG_ALARMID_BUTT
};
typedef VOS_UINT16  MODEM_CAS_SUBEVENTID_ENUM_UINT16;

/*Added by h00377722 for 多种场景CHR, 2017-03-14,begin*/
/*****************************************************************************
 枚举名    : MODEM_WAS_SUBEVENTID_ENUM_UINT16
 协议表格  :
 ASN.1描述 :
 枚举说明  : WAS告警类型子事件枚举定义
*****************************************************************************/
enum MODEM_WAS_SUBEVENTID_ENUM
{
    WAS_RRC_ACCESS_LONG_CHR_RPT_STRU_ALARMID          = WRRC_SUBEVENTID_ENUM_BASE+1,
    WAS_RADIO_RESOURCE_CHECK_CHR_RPT_STRU_ALARMID     = WRRC_SUBEVENTID_ENUM_BASE+2,
    WAS_RRC_STATE_LAST_TIME_CHR_RPT_STRU_ALARMID      = WRRC_SUBEVENTID_ENUM_BASE+3,
    WAS_WOOS_SEARCH_SECTION_CHR_RPT_STRU_ALARMID      = WRRC_SUBEVENTID_ENUM_BASE+4,
    WAS_W2W_RESEL_SLOW_CHR_RPT_STRU_ALARMID           = WRRC_SUBEVENTID_ENUM_BASE+5,
    WAS_NET_WORK_FEATURE_CHR_RPT_STRU_ALARMID         = WRRC_SUBEVENTID_ENUM_BASE+6,
    WAS_ERRORLOG_ALARMID_BUTT
};
typedef VOS_UINT16  MODEM_WAS_SUBEVENTID_ENUM_UINT16;
/*Added by h00377722 for 多种场景CHR, 2017-03-14,end*/

/*****************************************************************************
 枚举名    : MODEM_TRRC_SUBEVENTID_ENUM_UINT16
 协议表格  :
 ASN.1描述 :
 枚举说明  : TRRC告警类型子事件枚举定义
*****************************************************************************/
enum MODEM_TRRC_SUBEVENTID_ENUM
{
    TRRC_OUT_OF_SYNC_CELL_UPDATE_INFO_STRU_ALARMID     = TRRC_SUBEVENTID_ENUM_BASE+1,
    TRRC_OOS_INFO_STRU_ALARMID                         = TRRC_SUBEVENTID_ENUM_BASE+2,
    TRRC_APP_COLLECT_TDS_FREQ_REPORT_STRU_ALARMID      = TRRC_SUBEVENTID_ENUM_BASE+3,

    TRRC_CS_CALL_EST_CNF_INFO_STRU_ALARMID             = TRRC_SUBEVENTID_ENUM_BASE+4,
    TRRC_CS_CALL_CONN_REQ_INFO_STRU_ALARMID            = TRRC_SUBEVENTID_ENUM_BASE+5,
    TRRC_CS_CALL_AIRMSG_INFO_STRU_ALARMID              = TRRC_SUBEVENTID_ENUM_BASE+6,
    TRRC_APP_CONFIG_PCH_CELL_INFO_REPORT_STRU_ALARMID  = TRRC_SUBEVENTID_ENUM_BASE+7,

    /*Add by lilin 资源核查CHR 2017-3-13 begin*************/
    TRRC_CHR_RRM_RESOURCE_CHECK_INFO_LIST_STRU_ALARMID = TRRC_SUBEVENTID_ENUM_BASE+8,
    /*Add by lilin 资源核查CHR 2017-3-13 end*************/

    TRRC_ERRORLOG_ALARMID_BUTT
};
typedef VOS_UINT16  MODEM_TRRC_SUBEVENTID_ENUM_UINT16;

/*****************************************************************************
 枚举名    : MODEM_LNAS_SUBEVENTID_ENUM_UINT16
 协议表格  :
 ASN.1描述 :
 枚举说明  : LNAS告警类型子事件枚举定义
*****************************************************************************/
enum MODEM_LNAS_SUBEVENTID_ENUM
{
    LNAS_EMM_ERR_INFO_DSDS_RRM_RF_CHECKIN_STRU_ALARMID         = LNAS_EMM_SUBEVENTID_ENUM_BASE+1,
    LNAS_EMM_ERR_INFO_LTE_FAKE_NODEB_STRU_ALARMID              = LNAS_EMM_SUBEVENTID_ENUM_BASE+2,
    LNAS_EMM_ERR_INFO_LOAD_BALANCE_STRU_ALARMID                = LNAS_EMM_SUBEVENTID_ENUM_BASE+3,
    LNAS_EMM_ERR_INFO_DSDS_RF_RECOVER_RETRY_STRU_ALARMID       = LNAS_EMM_SUBEVENTID_ENUM_BASE+4,
    LNAS_EMM_ERR_INFO_GRADUAL_FORBIDDEN_OPTIMIZE_STRU_ALARMID  = LNAS_EMM_SUBEVENTID_ENUM_BASE+5,
    LNAS_EMM_ERR_INFO_VOLTE_WITH_TA_CHANGE_STRU_ALARMID        = LNAS_EMM_SUBEVENTID_ENUM_BASE+6,
    LNAS_EMM_ERR_INFO_NO_RAU_WITH_TAU_STRU_ALARMID             = LNAS_EMM_SUBEVENTID_ENUM_BASE+7,
    LNAS_EMM_ERR_INFO_IMS_BEARER_WITH_CN_MOD_CONFLICT_STRU_ALARMID  = LNAS_EMM_SUBEVENTID_ENUM_BASE+8,
    LNAS_EMM_ERR_INFO_3440_TIMEOUT_DO_NOT_REL_STRU_ALARMID          = LNAS_EMM_SUBEVENTID_ENUM_BASE+9,
    LNAS_EMM_ERR_INFO_CNMSG_DECODE_FAIL_STRU_ALARMID                = LNAS_EMM_SUBEVENTID_ENUM_BASE+10,
    LNAS_EMM_ERR_INFO_SMC_FAIL_STRU_ALARMID                         = LNAS_EMM_SUBEVENTID_ENUM_BASE+11,
    LNAS_EMM_ERR_INFO_LOCAL_DETACH_STRU_ALARMID                     = LNAS_EMM_SUBEVENTID_ENUM_BASE+12,
    LNAS_EMM_ERR_INFO_T3402_DEACTIVED_STRU_ALARMID                  = LNAS_EMM_SUBEVENTID_ENUM_BASE+13,
    LNAS_EMM_ERR_INFO_ATT_FAIL_ESM_NEED_DISABLE_LTE_STRU_ALARMID    = LNAS_EMM_SUBEVENTID_ENUM_BASE+14,
    LNAS_EMM_ERR_INFO_MMC_REL_DRGINIT_STRU_ALARMID                  = LNAS_EMM_SUBEVENTID_ENUM_BASE+15,
    LNAS_EMM_ERR_INFO_MO_BAR_ATTAMPT_STRU_ALARMID                   = LNAS_EMM_SUBEVENTID_ENUM_BASE+16,
    LNAS_ESM_ERR_INFO_SWITCH_APN_STRU_ALARMID                       = LNAS_EMM_SUBEVENTID_ENUM_BASE+17,
    LNAS_ESM_ERR_INFO_CNMSG_DECODE_FAIL_STRU_ALARMID                = LNAS_EMM_SUBEVENTID_ENUM_BASE+18,
    LNAS_IMSA_ERR_INFO_EMC_TCALL_TIMEOUT_STRU_ALARMID               = LNAS_EMM_SUBEVENTID_ENUM_BASE+19,
    LNAS_IMSA_ERR_INFO_DSDS_WAIT_BEAR_REL_TIMEOUT_STRU_ALARMID      = LNAS_EMM_SUBEVENTID_ENUM_BASE+20,
    LNAS_IMSA_ERR_INFO_DSDS_SMS_RF_OCCUPY_STRU_ALARMID              = LNAS_EMM_SUBEVENTID_ENUM_BASE+21,
    LNAS_IMSA_ERR_INFO_WAIT_RETRY_START_SWITCH_STRU_ALARMID         = LNAS_EMM_SUBEVENTID_ENUM_BASE+22,
    LNAS_IMSA_ERR_INFO_HANDOVER_INITIAL_PDN_CONN_STRU_ALARMID       = LNAS_EMM_SUBEVENTID_ENUM_BASE+23,
    LNAS_IMSA_ERR_INFO_REG_REJ_WAIT_RECOVERY_STRU_ALARMID           = LNAS_EMM_SUBEVENTID_ENUM_BASE+24,
    LNAS_EMM_ERR_INFO_DETACH_NO_RF_STRU_ALARMID                     = LNAS_EMM_SUBEVENTID_ENUM_BASE+25,
    LNAS_EMM_ERR_INFO_PERIODIC_TAU_WITH_CAUSE_STRU_ALARMID          = LNAS_EMM_SUBEVENTID_ENUM_BASE+26,
    LNAS_EMM_ERR_INFO_LANZHOU_CSFB_OPTIMIZE_STRU_ALARMID            = LNAS_EMM_SUBEVENTID_ENUM_BASE+27,
    LNAS_EMM_ERR_INFO_START_3402_ADD_FORB_LIST_STRU_ALARMID         = LNAS_EMM_SUBEVENTID_ENUM_BASE+28,
    LNAS_EMM_ERR_INFO_IMPROVE_CALL_SUCC_RATIO_STRU_ALARMID          = LNAS_EMM_SUBEVENTID_ENUM_BASE+29,
    LNAS_EMM_ERR_INFO_TAU_EST_WITH_CELL_SEARCHING_OPT_STRU_ALARMID  = LNAS_EMM_SUBEVENTID_ENUM_BASE+30,
    LNAS_EMM_ERR_INFO_AUTH_REJ_OPT_STRU_ALARMID                     = LNAS_EMM_SUBEVENTID_ENUM_BASE+31,
    LNAS_EMM_ERR_INFO_TAU_WITH_CONN_REL_DO_NOT_WAIT_3411_TIMEOUT_STRU_ALARMID = LNAS_EMM_SUBEVENTID_ENUM_BASE+32,
    LNAS_ESM_ERR_INFO_ESM_MSG_RETRANSMITE_STRU_ALARMID              = LNAS_EMM_SUBEVENTID_ENUM_BASE+33,
    LNAS_EMM_ERR_INFO_EMC_DATA_REQ_TAU_STRU_ALARMID                 = LNAS_EMM_SUBEVENTID_ENUM_BASE+34,
    LNAS_EMM_ERR_INFO_EMC_BERER_CN_REJ_ANYCELL_SRCH_STRU_ALARMID    = LNAS_EMM_SUBEVENTID_ENUM_BASE+35,
    LNAS_OM_ERRLOG_CSS_BAND_LIST_INFO_STRU_ALARMID                  = LNAS_EMM_SUBEVENTID_ENUM_BASE+36,
    LNAS_EMM_ERR_INFO_CSFB_TAU_RCV_MT_DETACH_STRU_ALARMID           = LNAS_EMM_SUBEVENTID_ENUM_BASE+37,
    LNAS_EMM_ERR_INFO_MT_DETACH_OPTIMIZE_STRU_ALARMID               = LNAS_EMM_SUBEVENTID_ENUM_BASE+38,
    LNAS_EMM_ERR_INFO_MT_SERVICE_RETRY_STRU_ALARMID                 = LNAS_EMM_SUBEVENTID_ENUM_BASE+39,	
    LNAS_EMM_ERR_INFO_DSDS_NO_RF_TAU_PUNISH_STRU_ALARMID                 = LNAS_EMM_SUBEVENTID_ENUM_BASE+40,
    LNAS_EMM_ERR_INFO_DSDS_BUFFER_NO_RF_TAU_REQ_STRU_ALARMID             = LNAS_EMM_SUBEVENTID_ENUM_BASE+41,
    LNAS_ERR_INFO_ALARMID_BUTT
};
typedef VOS_UINT16  MODEM_LNAS_SUBEVENTID_ENUM_UINT16;

/*****************************************************************************
 枚举名    : MODEM_TRRC_SUBEVENTID_ENUM_UINT16
 协议表格  :
 ASN.1描述 :
 枚举说明  : TRRC告警类型子事件枚举定义
*****************************************************************************/
enum MODEM_LRRC_SUBEVENTID_ENUM
{
    LPS_OM_VOLTE_FAULT_AUTOAN_INFO_STRU_ALARMID     = LRRC_SUBEVENTID_ENUM_BASE+1,
    LPS_OM_VOLTE_GENERAL_STAT_INFO_STRU_ALARMID      = LRRC_SUBEVENTID_ENUM_BASE+2,
    LRRC_OM_UE_CAP_FALL_REPORT_STRU_ALARMID          = LRRC_SUBEVENTID_ENUM_BASE+3,
    LRRC_OM_USER_PLANE_ERR_REL_REPORT_STRU_ALARMID   = LRRC_SUBEVENTID_ENUM_BASE+4,
    LRRC_CHR_RRM_RES_CHECK_INFO_LIST_STRU_ALARMID     = LRRC_SUBEVENTID_ENUM_BASE+5,
    LRRC_ERRORLOG_ALARMID_BUTT
};
typedef VOS_UINT16  MODEM_LRRC_SUBEVENTID_ENUM_UINT16;

/*****************************************************************************
 枚举名    : MODEM_TLL2_SUBEVENTID_ENUM_UINT16
 协议表格  :
 ASN.1描述 :
 枚举说明  : TLL2告警类型子事件枚举定义
*****************************************************************************/
enum MODEM_TLL2_SUBEVENTID_ENUM
{
    TLL2_OOS_INFO_STRU_ALARMID                        = TL2_SUBEVENTID_ENUM_BASE+1,
    /*niuxiufan preamble modify begin */
    LMAC_OM_PREAMBLE_SPEC_NOT_MATCH_INFO_STRU_ALARMID,         /*Preamble不匹配直通CHR */
    /*niuxiufan preamble modify end */

    TLL2_ERRORLOG_ALARMID_BUTT
};
typedef VOS_UINT16  MODEM_TLL2_SUBEVENTID_ENUM_UINT16;

/*****************************************************************************
 枚举名    : MODEM_CL2_SUBEVENTID_ENUM_UINT16
 协议表格  :
 ASN.1描述 :
 枚举说明  : CL2子事件枚举定义
*****************************************************************************/
enum MODEM_CL2_SUBEVENTID_ENUM
{
    CTTF_RADIO_RESOURCE_CHECK_CHR_DIRECT_RPT_STRU_ALARMID   = CL2_SUBEVENTID_ENUM_BASE+1,

    CTTF_ERRORLOG_ALARMID_BUTT
};
typedef VOS_UINT16  MODEM_CL2_SUBEVENTID_ENUM_UINT16;



/*****************************************************************************
 5 STRUCT
*****************************************************************************/

/*****************************************************************************
6 UNION
*****************************************************************************/

/*****************************************************************************
7 Extern Global Variable
*****************************************************************************/

/*****************************************************************************
8 Fuction Extern
*****************************************************************************/

/*****************************************************************************
9 OTHERS
*****************************************************************************/


#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif

#ifdef __cplusplus
  #if __cplusplus
      }
  #endif
#endif

#endif /* end of ErrLogComm.h */

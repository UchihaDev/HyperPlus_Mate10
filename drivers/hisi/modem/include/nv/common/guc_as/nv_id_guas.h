/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : nv_id_guas.h
  版 本 号   :
  作    者   : l00368411
  生成日期   : 2017年05月02日
  最近修改   :
  功能描述   : CCORE GUAS项目组NV项ID枚举定义
  函数列表   :
  修改历史   :
  1.日    期   : 2017年05月02日
    作    者   : l00368411
    修改内容   : 创建文件

******************************************************************************/

#ifndef __NV_ID_GUAS_H__
#define __NV_ID_GUAS_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/****************************************************************************
  1 宏定义
*****************************************************************************/

/* C核NV_ID定义 */
enum COMMON_GUAS_NV_ID_ENUM
{

/* 3223  */     en_NV_Item_GPRS_ActiveTimerLength                       = 3223,

/* 8210  */     en_NV_Item_Egprs_Multi_Slot_Class                       = 8210,
/* 8277  */     en_NV_Item_Egprs_Flag                                   = 8277,
/* 8284  */     en_NV_Item_WCDMA_PLMN_FREQ_PAIR_List                    = 8284,
/* 8326  */     en_Nv_Item_Gprs_Multi_Slot_Class                        = 8326,
/* 9008  */     en_NV_Item_WAS_RadioAccess_Capa_New                     = 9008,/* WAS新增NV项 */
/* 9009  */     en_NV_Item_GAS_High_Multislot_Class                     = 9009,

/* 9091 */      en_NV_Item_UTRAN_TDD_FREQ_BAND                          = 9091, /* 指示TDS Band信息 */

                en_NV_Item_COMMON_GUC_GUAS_NVID_BUTT
};

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif

/* end of nv_id_guas.h */


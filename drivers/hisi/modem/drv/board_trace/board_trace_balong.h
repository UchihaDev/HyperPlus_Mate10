/*************************************************************************
*   版权所有(C) 1987-2011, 深圳华为技术有限公司.
*
*   文 件 名 :  board_trace_balong.h
*
*   作    者 :   y00171698
*
*   描    述 :   board trace state ind
*
*   修改记录 :  2017年3月22日  v1.00    创建
*************************************************************************/
#ifndef __BOARD_TRACE_H__
#define __BOARD_TRACE_H__
#ifdef __cplusplus
extern "C"
{
#endif

#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/init.h>
#include <linux/module.h>

#include "product_config.h"
#include "mdrv_efuse.h"
#include "mdrv_hds_common.h"
#include "osl_types.h"
#include "osl_thread.h"
#include "osl_sem.h"
#include "osl_spinlock.h"
#include "osl_thread.h"
#include "osl_malloc.h"
#include "bsp_hds_ind.h"
#include "bsp_efuse.h"
#include "bsp_hds_service.h"
#include "bsp_hds_log.h"
#include "bsp_module.h"
#include "bsp_version.h"
#include "bsp_trace.h"


#ifndef BSP_OK
#define BSP_OK 0
#endif

#define BSP_ERR_BOARD_TRACE_BASE            	BSP_DEF_ERR(BSP_MODU_BOARD_TRACE, 0)
#define BSP_ERR_BOARD_TRACE_NULL             	(BSP_ERR_BOARD_TRACE_BASE + 0x1)
#define BSP_ERR_BOARD_TRACE_MALLOC 		(BSP_ERR_BOARD_TRACE_BASE + 0x2)
#define BSP_ERR_BOARD_TRACE_SUPPORT   	(BSP_ERR_BOARD_TRACE_BASE + 0x3)
#define BSP_ERR_BOARD_TRACE_GET        		(BSP_ERR_BOARD_TRACE_BASE + 0x4)
#define BSP_ERR_BOARD_TRACE_PARA        	(BSP_ERR_BOARD_TRACE_BASE + 0x5)
#define BSP_ERR_BOARD_TRACE_TYPE        	(BSP_ERR_BOARD_TRACE_BASE + 0x6)
#define BSP_ERR_BOARD_TRACE_IND        	(BSP_ERR_BOARD_TRACE_BASE + 0x7)

#define BOARD_TRACE_PROJECT_ADDR 	0xe1ff6204  
#define BOARD_TRACE_NUM_ADDR  		0xe1ff6200

/* baord trace ind msg id */
#define BOARD_TRACE_IND_MSGID     	       0x9f380001
#define BOARD_TRACE_IND_ULPID 		 0x8003

/* board trace info */
#define BOARD_TRACE_INFO_SIZE_MAX		20   		/* Bytes, UDP Die ID: 160bit, BBIT: 64bit, Porting: 64bit either CP or AP */
#define BOARD_TRACE_NUM_MAX				2

#define BOARD_TRACE_INFO_BBIT_LENGTH       8
#define BOARD_TRACE_INFO_UDP_LENGTH    	20

#define BOARD_TRACE_INFO_TLV_CNT    	       1

/* board type enum */
enum tagBOARD_TRACE_TYPE_E
{
    BOARD_TRACE_TYPE_PORTING     	= 0,       	/* Porting */
    BOARD_TRACE_TYPE_BBIT,                     	/* BBIT */
    BOARD_TRACE_TYPE_UDP,                      	/* UDP */
    BOARD_TRACE_TYPE_BUTT
};
typedef unsigned int BOARD_TRACE_TYPE_ENUM_U32;


/* board trace single TLV info */
typedef struct tagBOARD_TRACE_TLV_S
{
	VERSION_BOARD_TYPE_E  uType;			/** Flag **/
	UINT32  uLength;							/** Length **/
	UINT8  	uValue[BOARD_TRACE_INFO_SIZE_MAX];  /** Board Info **/
} BOARD_TRACE_TLV_S;


/* board trace total info */
typedef struct tagBOARD_TRACE_INFO_S
{
	UINT32  uTlvCnt;			/** Tlv Cnt **/
	UINT8  	sTlvBuf[0]; /*lint !e43*/		/** Board project tlv struct **/
} BOARD_TRACE_INFO_S;


/* function types */
int bsp_board_trace_init(void);
u32 bsp_board_trace_ind(void);
int get_board_info(BOARD_TRACE_TYPE_ENUM_U32 eType, BOARD_TRACE_TLV_S *pBoardTlvInfo);
int bsp_TraceProcEntry(u8* pstReq);

#ifdef __cplusplus
}
#endif
#endif


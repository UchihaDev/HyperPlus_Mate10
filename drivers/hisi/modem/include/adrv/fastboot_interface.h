/*************************************************************************
*   版权所有(C) 1987-2015, 深圳海思半导体技术有限公司.
*
*   文 件 名 :  fastboot_interface.h
*
*   描    述 :  本文件命名为"fastboot_interface.h", 给出fastboot侧底软直接对外提供API接口描述
*
*   修改记录 :  2015年4月01日  v1.00  创建
*************************************************************************/

#ifndef HISI_FASTBOOT_DRV_H
#define HISI_FASTBOOT_DRV_H

/*************************************************************************
*
*   宏定义
*
*************************************************************************/
#define PARTITION_MODEM_NVDLOAD_NAME        "modemnvm_update"
#define PARTITION_MODEM_NVDLOAD_CUST_NAME   "modemnvm_cust"
#define PARTITION_MODEM_NVDEFAULT_NAME      "modemnvm_factory"
#define PARTITION_MODEM_NVBACKUP_NAME       "modemnvm_backup"
#define PARTITION_MODEM_NVSYS_NAME          "modemnvm_system"
#define PARTITION_MODEM_NVIMG_NAME          "modemnvm_img"


typedef struct ptentry ptentry;
struct ptentry
{
    char name[32];
    unsigned start;
    unsigned length;
    unsigned flags;
};

/*****************************************************************************
* 函 数 名  : get_operators
*
* 功能描述  : 获取分区的回调函数
*
* 输入参数  : string 传入"partition"
*             
* 输出参数  : 无
*
* 返 回 值  : 无
*
* 其它说明  : fastboot
*
*****************************************************************************/
void * get_operators(char * string);

/*****************************************************************************
* 函 数 名  : storage_read
*
* 功能描述  : FASTBOOT中读取对应分区中指定位置的数据
*
* 输入参数  : ptn_name 需要操作的分区名
			  offset  相对分区起始地址的偏移
			  data 读数据存放的目的buffer
			  bytes  需要读取的字节数
*             
* 输出参数  : 无
*
* 返 回 值  : 0  读取成功
			  -1 读取失败
*
* 其它说明  : fastboot
*
*****************************************************************************/
int storage_read(const char *ptn_name, unsigned long long offset, void *data, unsigned long long bytes);

/*****************************************************************************
* 函 数 名  : Is_load_modem 
*
* 功能描述  : 是否加载modem
*
* 输入参数  : NULL
*             
* 输出参数  : NULL
*
* 返 回 值  : 0  失败
			    1 需要加载modem和dsp
*
* 其它说明  : fastboot
*
*****************************************************************************/
unsigned int bsp_need_loadmodem (void);

/*****************************************************************************
* 函 数 名  : bsp_socpmem_enable
*
* 功能描述  : 是否静态预留modem socp的内存
*
* 输入参数  : NULL
*
* 输出参数  : NULL
*
* 返 回 值  : 0 不静态预留modem socp的内存
              1 静态预留modem socp的内存
*
* 其它说明  : fastboot
*
*****************************************************************************/
unsigned int bsp_socpmem_enable(void);

#endif /* HISI_AP_DRV_H */


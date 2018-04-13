#ifndef __BSP_DFC_H__
#define __BSP_DFC_H__

#include <osl_types.h>
#include <bsp_sram.h>


/* DFC通道id分配 */
enum DFC_CHN_ID
{
	DFC_CHN_CCORE =0, 
	DFC_CHN_DSP = 1,
	DFC_CHN_DSP_1 = 2,
	DFC_CHN_DSP_2 = 3,
	DFC_CHN_DSP_3 = 4,
	DFC_CHN_DSP_4 = 5,
	DFC_CHN_DSP_5 = 6,
	DFC_CHN_DSP_6 = 7,
	DFC_CHN_DSP_7 = 8,
	DFC_CHN_DSP_8 = 9,
	DFC_CHN_ID_MAX
};

struct dfc_u64_addr{
    u32 addrL;
    u32 addrH;
};

union dfc_list_bd
{
    struct list_bd_bits
    {
        u32    user_info                 : 3; /* [2..0] user info*/
        u32    base_addrL              : 29; /* [31..3]  base_addrL*/
        u32    base_addrH             : 16; /* [47..32]  base_addrH*/
        u32    reserved                  : 16; /* [63..48] 保留 */
    } bits;
    struct dfc_u64_addr union_stru;
};  

enum dfc_cpu_id
{
    DFC_TLDSP0 = 0,
    DFC_CCPU = 1,
    DFC_NXP = 2
};

typedef u32 (*int_cb_func)(u32 chn_id, u32 level);

/* DFC addr */
#ifndef DFC_LLRAM_BASE_ADDR
#define DFC_LLRAM_BASE_ADDR           (CCPU_DFC_ADDR)
#endif

#ifndef DFC_LLRAM_SIZE
#define DFC_LLRAM_SIZE                (CCPU_DFC_SIZE)
#endif

/*define*/
#define DFC_TLDSP0_PS_DOWN_SIZE          (15 * 1024)
#define DFC_TLDSP0_PS_UP_SIZE               (10 * 1024)
#define DFC_TLDSP0_OM_DOWN_SIZE           (SZ_4K)
#define DFC_TLDSP0_OM_UP_SIZE        (SZ_16K)
#define DFC_DSP4_SIZE        (SZ_4K)

/*****************************************************************************************************************************
*通道大小和偏移量
******************************************************************************************************************************/
#define DFC_CHANNEL_OFFSET_BASE		    	        (0x0)
#define DFC_CHANNEL_TLDSP0_PS_DOWN_ADDR         (DFC_LLRAM_BASE_ADDR + DFC_TLDSP0_PS_DOWN_SIZE)
#define DFC_CHANNEL_TLDSP0_PS_UP_ADDR               (DFC_CHANNEL_TLDSP0_PS_DOWN_ADDR + DFC_TLDSP0_PS_UP_SIZE)
#define DFC_CHANNEL_TLDSP0_OM_DOWN_ADDR         (DFC_CHANNEL_TLDSP0_PS_UP_ADDR + DFC_TLDSP0_OM_DOWN_SIZE)
#define DFC_CHANNEL_TLDSP0_OM_UP_ADDR               (DFC_CHANNEL_TLDSP0_OM_DOWN_ADDR + DFC_TLDSP0_OM_UP_SIZE)

#ifdef CONFIG_DFC
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_startup
*
* 功能描述  : dfc通道启动，启动后通道状态不再是idle
*
* 输入参数  :  通道id
                         
* 输出参数  : 无
*
* 返 回 值  :     OK         保存成功
                              ERROR   保存失败
*
* 修改记录  :     
*****************************************************************************/
s32 bsp_dfc_channel_startup(u32 chn_id);

/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_shutdown
*
* 功能描述  : dfc通道启动，启动后通道状态变为idle
*
* 输入参数  :  通道id
                         
* 输出参数  : 无
*
* 返 回 值  :     OK         成功
                              ERROR   失败
*
* 修改记录  :   
*****************************************************************************/
s32 bsp_dfc_channel_shutdown(u32 chn_id);
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_register_isr
*
* 功能描述  : 通道中断注册回调
*
* 输入参数  :  通道id
                         
* 输出参数  : 无
*
* 返 回 值  :     OK         成功
                              ERROR   失败
*
* 修改记录  :  
*****************************************************************************/
s32 bsp_dfc_channel_register_isr(u32 chn_id, int_cb_func pFunc);
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_unregister_isr
*
* 功能描述  : 通道中断注销回调
*
* 输入参数  : 通道id
                         
* 输出参数  : 无
*
* 返 回 值  :     OK         成功
                              ERROR   失败
*
* 修改记录  
*****************************************************************************/
s32 bsp_dfc_channel_unregister_isr (u32 chn_id);
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_get_state
*
* 功能描述  : 获取通道状态
                             
*
* 输入参数  :  通道id
                         
* 输出参数  : 无
*
* 返 回 值  :     无
*
* 修改记录  :  
*****************************************************************************/
u32 bsp_dfc_channel_get_state (u32 chn_id);
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_int_enable
*
* 功能描述  : dfc通道中断使能
*
* 输入参数  :  通道id
*                           使能中断状态位
                         
* 输出参数  : 无
*
* 返 回 值  :     OK       成功
                              ERROR   失败
*
* 修改记录  :  
*****************************************************************************/
s32 bsp_dfc_channel_int_enable(u32 chn_id, u32 level);
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_int_disable
*
* 功能描述  :dfc通道中断去使能
*
* 输入参数  :  通道id
*                           去使能中断状态位
                         
* 输出参数  : 无
*
* 返 回 值  :     OK       成功
                              ERROR   失败
*
* 修改记录  :  
*****************************************************************************/
s32 bsp_dfc_channel_int_disable(u32 chn_id, u32 level);
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_int_clr
*
* 功能描述  :dfc通道中断写清
*
* 输入参数  :  通道id
*                           去使能中断写清
                         
* 输出参数  : 无
*
* 返 回 值  :     OK       成功
                              ERROR   失败
*
* 修改记录  :  
*****************************************************************************/
s32 bsp_dfc_channel_int_clr(u32 chn_id, u32 level);
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_read_all
*
* 功能描述  : dfc通道读取所有数据
*
* 输入参数  :  通道id,
*                           数据读取目的地址指针void * dest
                         
* 输出参数  : 无
*
* 返 回 值  :     OK       成功
                              ERROR   失败
*
* 修改记录  :  
*****************************************************************************/
s32 bsp_dfc_channel_read_all(u32 chn_id, void * dest );
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_read
*
* 功能描述  : dfc通道读数据
*
* 输入参数  :  通道id
*                           读取数据目的地址指针void * dest
*                           读取数据长度
                         
* 输出参数  : 无
*
* 返 回 值  :     OK       恢复成功
                              ERROR   恢复失败
*
* 修改记录  :  
*****************************************************************************/
u32 bsp_dfc_channel_read(u32 chn_id, void * dest, u32 data_len);
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_list_read
*
* 功能描述  : 链式数据类型通道读数据
*
* 输入参数  :  通道id
                         链式数据共用体
* 输出参数  : 无
*
* 返 回 值  :     OK       恢复成功
                              ERROR   恢复失败
*
* 修改记录  :  
*****************************************************************************/
s32 bsp_dfc_channel_list_read(u32 chn_id, union dfc_list_bd * list_rd);
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_list_data_read
*
* 功能描述  : 链式数据类型通道读数据
*
* 输入参数  :  通道id
*                         链式数据共用体
*                         读取数据目的地址void* data_dest
* 输出参数  : 无
*
* 返 回 值  :     OK       恢复成功
                              ERROR   恢复失败
*
* 修改记录  :  
*****************************************************************************/
s32 bsp_dfc_channel_list_data_read(u32 chn_id, union dfc_list_bd * list_rd, void * data_dest);
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_data_write
*
* 功能描述  : dfc通道写数据
*
* 输入参数  :  通道id
*                         无符号整形数据
* 输出参数  : 无
*
* 返 回 值  :     OK       恢复成功
                              ERROR   恢复失败
*
* 修改记录  :  
*****************************************************************************/
s32 bsp_dfc_channel_data_write(u32 chn_id, u32 data);
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_list_write
*
* 功能描述  : 链式数据类型通道写数据
*
* 输入参数  :  通道id
*                           链式数据共用体
* 输出参数  : 无
*
* 返 回 值  :     OK       恢复成功
                              ERROR   恢复失败
*
* 修改记录  :  
*****************************************************************************/
s32 bsp_dfc_channel_list_write(u32 chn_id, union dfc_list_bd bd_data);
/*****************************************************************************
* 函 数 名  :bsp_dfc_channel_write
*
* 功能描述  : dfc通道写数据
*
* 输入参数  :  通道id
*                           数据源地址
*                           数据长度
* 输出参数  : 无
*
* 返 回 值  :     OK       恢复成功
                              ERROR   恢复失败
*
* 修改记录  :  
*****************************************************************************/
s32 bsp_dfc_channel_write(u32 chn_id, void * src, u32 data_len);
/*****************************************************************************
* 函 数 名  :  bsp_dfc_channel_writebuf_space_get
*
* 功能描述  :  获取dfc通道写剩余空间
*
* 输入参数  :  dfc通道号
*
* 输出参数  :  无
*
* 返 回 值  :  剩余空间字节数
*
* 修改记录  :
*****************************************************************************/
u32 bsp_dfc_channel_writebuf_space_get(u32 chn_id);
/*****************************************************************************
* 函 数 名  :  bsp_dfc_channel_readbuf_data_count
*
* 功能描述  :  获取dfc通道未读取数据
*
* 输入参数  :  dfc通道号
*
* 输出参数  :  无
*
* 返 回 值  :  readbuf未读取的字节数
*
* 修改记录  :
*****************************************************************************/
u32 bsp_dfc_channel_readbuf_data_count(u32 chn_id);
/*****************************************************************************
* 函 数 名  :  bsp_dfc_channel_get_data
*
* 功能描述  :  dfc通道获取数据，不改读指针
*
* 输入参数  :  dfc通道号，obuf地址
*
* 输出参数  :  无
*
* 返 回 值  :  读取数据长度
*
* 修改记录  :
*****************************************************************************/
u32 bsp_dfc_channel_get_data(u32 chn_id, void * dest, u32 data_len);
#else

#endif/*CONFIG_DFC*/

#endif

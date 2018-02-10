#ifndef __SOC_ISP_DRBR_INTERFACE_H__
#define __SOC_ISP_DRBR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_DRBR_DRBR_ID_ADDR(base) ((base) + (0x0))
#define SOC_ISP_DRBR_DRBR_VERSION_ADDR(base) ((base) + (0x4))
#define SOC_ISP_DRBR_DBRB_FORCE_CLK_ON_CFG_ADDR(base) ((base) + (0x20))
#define SOC_ISP_DRBR_DRBR_EN_ADDR(base) ((base) + (0x30))
#define SOC_ISP_DRBR_DRBR_CFG_ADDR(base) ((base) + (0x34))
#define SOC_ISP_DRBR_DRBR_RD_CFG_ADDR(base) ((base) + (0x40))
#define SOC_ISP_DRBR_DRBR_RD_FIRST_BLOCK_CFG_ADDR(base) ((base) + (0x44))
#define SOC_ISP_DRBR_DRBR_RD_LAST_BLOCK_CFG_ADDR(base) ((base) + (0x48))
#define SOC_ISP_DRBR_DRBR_WR_CFG_ADDR(base) ((base) + (0x50))
#define SOC_ISP_DRBR_DRBR_WR_FIRST_BLOCK_CFG_ADDR(base) ((base) + (0x54))
#define SOC_ISP_DRBR_DRBR_WR_LAST_BLOCK_CFG_ADDR(base) ((base) + (0x58))
#define SOC_ISP_DRBR_DRBR_CROP_H_ADDR(base) ((base) + (0x60))
#define SOC_ISP_DRBR_DRBR_CROP_V_ADDR(base) ((base) + (0x64))
#define SOC_ISP_DRBR_DRBR_RD_FIRST_32K_PAGE_ADDR(base) ((base) + (0x80))
#define SOC_ISP_DRBR_DRBR_RD_LAST_32K_PAGE_ADDR(base) ((base) + (0x84))
#define SOC_ISP_DRBR_DRBR_RD_PREFETCH_CFG_ADDR(base) ((base) + (0x88))
#define SOC_ISP_DRBR_DRBR_WR_FIRST_32K_PAGE_ADDR(base) ((base) + (0xA0))
#define SOC_ISP_DRBR_DRBR_WR_LAST_32K_PAGE_ADDR(base) ((base) + (0xA4))
#define SOC_ISP_DRBR_DRBR_WR_PREFETCH_CFG_ADDR(base) ((base) + (0xA8))
#define SOC_ISP_DRBR_DRBR_RW_REG_0_ADDR(base) ((base) + (0xB0))
#define SOC_ISP_DRBR_DRBR_RW_REG_1_ADDR(base) ((base) + (0xB4))
#define SOC_ISP_DRBR_DRBR_DEBUG_0_ADDR(base) ((base) + (0x100))
#define SOC_ISP_DRBR_DRBR_DEBUG_1_ADDR(base) ((base) + (0x104))
#define SOC_ISP_DRBR_DRBR_DEBUG_2_ADDR(base) ((base) + (0x108))
#define SOC_ISP_DRBR_DRBR_DEBUG_3_ADDR(base) ((base) + (0x10c))
#define SOC_ISP_DRBR_DRBR_DEBUG_4_ADDR(base) ((base) + (0x110))
#define SOC_ISP_DRBR_DRBR_DEBUG_5_ADDR(base) ((base) + (0x114))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int drbr_ip_id : 32;
    } reg;
} SOC_ISP_DRBR_DRBR_ID_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_ID_drbr_ip_id_START (0)
#define SOC_ISP_DRBR_DRBR_ID_drbr_ip_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int drbr_ip_version : 32;
    } reg;
} SOC_ISP_DRBR_DRBR_VERSION_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_VERSION_drbr_ip_version_START (0)
#define SOC_ISP_DRBR_DRBR_VERSION_drbr_ip_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_clk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_DRBR_DBRB_FORCE_CLK_ON_CFG_UNION;
#endif
#define SOC_ISP_DRBR_DBRB_FORCE_CLK_ON_CFG_force_clk_on_START (0)
#define SOC_ISP_DRBR_DBRB_FORCE_CLK_ON_CFG_force_clk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int drbr_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_DRBR_DRBR_EN_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_EN_drbr_enable_START (0)
#define SOC_ISP_DRBR_DRBR_EN_drbr_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int drbr_data_type : 2;
        unsigned int reserved_0 : 1;
        unsigned int drbr_raster_wr_expansion : 1;
        unsigned int drbr_scrambler_ddr_channels : 1;
        unsigned int drbr_scrambler_ddr_granularity : 3;
        unsigned int drbr_rotation_enable : 1;
        unsigned int reserved_1 : 21;
        unsigned int drbr_mode : 2;
    } reg;
} SOC_ISP_DRBR_DRBR_CFG_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_CFG_drbr_data_type_START (0)
#define SOC_ISP_DRBR_DRBR_CFG_drbr_data_type_END (1)
#define SOC_ISP_DRBR_DRBR_CFG_drbr_raster_wr_expansion_START (3)
#define SOC_ISP_DRBR_DRBR_CFG_drbr_raster_wr_expansion_END (3)
#define SOC_ISP_DRBR_DRBR_CFG_drbr_scrambler_ddr_channels_START (4)
#define SOC_ISP_DRBR_DRBR_CFG_drbr_scrambler_ddr_channels_END (4)
#define SOC_ISP_DRBR_DRBR_CFG_drbr_scrambler_ddr_granularity_START (5)
#define SOC_ISP_DRBR_DRBR_CFG_drbr_scrambler_ddr_granularity_END (7)
#define SOC_ISP_DRBR_DRBR_CFG_drbr_rotation_enable_START (8)
#define SOC_ISP_DRBR_DRBR_CFG_drbr_rotation_enable_END (8)
#define SOC_ISP_DRBR_DRBR_CFG_drbr_mode_START (30)
#define SOC_ISP_DRBR_DRBR_CFG_drbr_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int drbr_rd_stride : 10;
        unsigned int reserved_1 : 4;
        unsigned int drbr_rd_flip_enable : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_ISP_DRBR_DRBR_RD_CFG_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_RD_CFG_drbr_rd_stride_START (16)
#define SOC_ISP_DRBR_DRBR_RD_CFG_drbr_rd_stride_END (25)
#define SOC_ISP_DRBR_DRBR_RD_CFG_drbr_rd_flip_enable_START (30)
#define SOC_ISP_DRBR_DRBR_RD_CFG_drbr_rd_flip_enable_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int drbr_rd_first_vertical_position : 11;
        unsigned int reserved_0 : 5;
        unsigned int drbr_rd_first_horizontal_position : 8;
        unsigned int reserved_1 : 5;
        unsigned int drbr_rd_first_horizontal_subpos : 3;
    } reg;
} SOC_ISP_DRBR_DRBR_RD_FIRST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_RD_FIRST_BLOCK_CFG_drbr_rd_first_vertical_position_START (0)
#define SOC_ISP_DRBR_DRBR_RD_FIRST_BLOCK_CFG_drbr_rd_first_vertical_position_END (10)
#define SOC_ISP_DRBR_DRBR_RD_FIRST_BLOCK_CFG_drbr_rd_first_horizontal_position_START (16)
#define SOC_ISP_DRBR_DRBR_RD_FIRST_BLOCK_CFG_drbr_rd_first_horizontal_position_END (23)
#define SOC_ISP_DRBR_DRBR_RD_FIRST_BLOCK_CFG_drbr_rd_first_horizontal_subpos_START (29)
#define SOC_ISP_DRBR_DRBR_RD_FIRST_BLOCK_CFG_drbr_rd_first_horizontal_subpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int drbr_rd_last_vertical_position : 11;
        unsigned int reserved_0 : 5;
        unsigned int drbr_rd_last_horizontal_position : 8;
        unsigned int reserved_1 : 5;
        unsigned int drbr_rd_last_horizontal_subpos : 3;
    } reg;
} SOC_ISP_DRBR_DRBR_RD_LAST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_RD_LAST_BLOCK_CFG_drbr_rd_last_vertical_position_START (0)
#define SOC_ISP_DRBR_DRBR_RD_LAST_BLOCK_CFG_drbr_rd_last_vertical_position_END (10)
#define SOC_ISP_DRBR_DRBR_RD_LAST_BLOCK_CFG_drbr_rd_last_horizontal_position_START (16)
#define SOC_ISP_DRBR_DRBR_RD_LAST_BLOCK_CFG_drbr_rd_last_horizontal_position_END (23)
#define SOC_ISP_DRBR_DRBR_RD_LAST_BLOCK_CFG_drbr_rd_last_horizontal_subpos_START (29)
#define SOC_ISP_DRBR_DRBR_RD_LAST_BLOCK_CFG_drbr_rd_last_horizontal_subpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int drbr_wr_stride : 10;
        unsigned int reserved_1 : 4;
        unsigned int drbr_wr_flip_enable : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_ISP_DRBR_DRBR_WR_CFG_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_WR_CFG_drbr_wr_stride_START (16)
#define SOC_ISP_DRBR_DRBR_WR_CFG_drbr_wr_stride_END (25)
#define SOC_ISP_DRBR_DRBR_WR_CFG_drbr_wr_flip_enable_START (30)
#define SOC_ISP_DRBR_DRBR_WR_CFG_drbr_wr_flip_enable_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int drbr_wr_first_vertical_position : 11;
        unsigned int reserved_0 : 5;
        unsigned int drbr_wr_first_horizontal_position : 8;
        unsigned int reserved_1 : 5;
        unsigned int drbr_wr_first_horizontal_subpos : 3;
    } reg;
} SOC_ISP_DRBR_DRBR_WR_FIRST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_WR_FIRST_BLOCK_CFG_drbr_wr_first_vertical_position_START (0)
#define SOC_ISP_DRBR_DRBR_WR_FIRST_BLOCK_CFG_drbr_wr_first_vertical_position_END (10)
#define SOC_ISP_DRBR_DRBR_WR_FIRST_BLOCK_CFG_drbr_wr_first_horizontal_position_START (16)
#define SOC_ISP_DRBR_DRBR_WR_FIRST_BLOCK_CFG_drbr_wr_first_horizontal_position_END (23)
#define SOC_ISP_DRBR_DRBR_WR_FIRST_BLOCK_CFG_drbr_wr_first_horizontal_subpos_START (29)
#define SOC_ISP_DRBR_DRBR_WR_FIRST_BLOCK_CFG_drbr_wr_first_horizontal_subpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int drbr_wr_last_vertical_position : 11;
        unsigned int reserved_0 : 5;
        unsigned int drbr_wr_last_horizontal_position : 8;
        unsigned int reserved_1 : 5;
        unsigned int drbr_wr_last_horizontal_subpos : 3;
    } reg;
} SOC_ISP_DRBR_DRBR_WR_LAST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_WR_LAST_BLOCK_CFG_drbr_wr_last_vertical_position_START (0)
#define SOC_ISP_DRBR_DRBR_WR_LAST_BLOCK_CFG_drbr_wr_last_vertical_position_END (10)
#define SOC_ISP_DRBR_DRBR_WR_LAST_BLOCK_CFG_drbr_wr_last_horizontal_position_START (16)
#define SOC_ISP_DRBR_DRBR_WR_LAST_BLOCK_CFG_drbr_wr_last_horizontal_position_END (23)
#define SOC_ISP_DRBR_DRBR_WR_LAST_BLOCK_CFG_drbr_wr_last_horizontal_subpos_START (29)
#define SOC_ISP_DRBR_DRBR_WR_LAST_BLOCK_CFG_drbr_wr_last_horizontal_subpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int drbr_ihleft : 13;
        unsigned int reserved_0 : 3;
        unsigned int drbr_ihright : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_DRBR_DRBR_CROP_H_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_CROP_H_drbr_ihleft_START (0)
#define SOC_ISP_DRBR_DRBR_CROP_H_drbr_ihleft_END (12)
#define SOC_ISP_DRBR_DRBR_CROP_H_drbr_ihright_START (16)
#define SOC_ISP_DRBR_DRBR_CROP_H_drbr_ihright_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int drbr_ivtop : 13;
        unsigned int reserved_0 : 3;
        unsigned int drbr_ivbottom : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_DRBR_DRBR_CROP_V_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_CROP_V_drbr_ivtop_START (0)
#define SOC_ISP_DRBR_DRBR_CROP_V_drbr_ivtop_END (12)
#define SOC_ISP_DRBR_DRBR_CROP_V_drbr_ivbottom_START (16)
#define SOC_ISP_DRBR_DRBR_CROP_V_drbr_ivbottom_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int drbr_rd_first_32k_page : 17;
    } reg;
} SOC_ISP_DRBR_DRBR_RD_FIRST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_RD_FIRST_32K_PAGE_drbr_rd_first_32k_page_START (15)
#define SOC_ISP_DRBR_DRBR_RD_FIRST_32K_PAGE_drbr_rd_first_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int drbr_rd_last_32k_page : 17;
    } reg;
} SOC_ISP_DRBR_DRBR_RD_LAST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_RD_LAST_32K_PAGE_drbr_rd_last_32k_page_START (15)
#define SOC_ISP_DRBR_DRBR_RD_LAST_32K_PAGE_drbr_rd_last_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int drbr_rd_prefetch_delay : 11;
        unsigned int reserved_0 : 5;
        unsigned int drbr_rd_prefetch_nbr_iid : 4;
        unsigned int reserved_1 : 10;
        unsigned int drbr_rd_prefetch_mode : 1;
        unsigned int drbr_rd_prefetch_enable : 1;
    } reg;
} SOC_ISP_DRBR_DRBR_RD_PREFETCH_CFG_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_RD_PREFETCH_CFG_drbr_rd_prefetch_delay_START (0)
#define SOC_ISP_DRBR_DRBR_RD_PREFETCH_CFG_drbr_rd_prefetch_delay_END (10)
#define SOC_ISP_DRBR_DRBR_RD_PREFETCH_CFG_drbr_rd_prefetch_nbr_iid_START (16)
#define SOC_ISP_DRBR_DRBR_RD_PREFETCH_CFG_drbr_rd_prefetch_nbr_iid_END (19)
#define SOC_ISP_DRBR_DRBR_RD_PREFETCH_CFG_drbr_rd_prefetch_mode_START (30)
#define SOC_ISP_DRBR_DRBR_RD_PREFETCH_CFG_drbr_rd_prefetch_mode_END (30)
#define SOC_ISP_DRBR_DRBR_RD_PREFETCH_CFG_drbr_rd_prefetch_enable_START (31)
#define SOC_ISP_DRBR_DRBR_RD_PREFETCH_CFG_drbr_rd_prefetch_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int drbr_wr_first_32k_page : 17;
    } reg;
} SOC_ISP_DRBR_DRBR_WR_FIRST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_WR_FIRST_32K_PAGE_drbr_wr_first_32k_page_START (15)
#define SOC_ISP_DRBR_DRBR_WR_FIRST_32K_PAGE_drbr_wr_first_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int drbr_wr_last_32k_page : 17;
    } reg;
} SOC_ISP_DRBR_DRBR_WR_LAST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_WR_LAST_32K_PAGE_drbr_wr_last_32k_page_START (15)
#define SOC_ISP_DRBR_DRBR_WR_LAST_32K_PAGE_drbr_wr_last_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int drbr_wr_prefetch_delay : 11;
        unsigned int reserved_0 : 5;
        unsigned int drbr_wr_prefetch_nbr_iid : 4;
        unsigned int reserved_1 : 10;
        unsigned int drbr_wr_prefetch_mode : 1;
        unsigned int drbr_wr_prefetch_enable : 1;
    } reg;
} SOC_ISP_DRBR_DRBR_WR_PREFETCH_CFG_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_WR_PREFETCH_CFG_drbr_wr_prefetch_delay_START (0)
#define SOC_ISP_DRBR_DRBR_WR_PREFETCH_CFG_drbr_wr_prefetch_delay_END (10)
#define SOC_ISP_DRBR_DRBR_WR_PREFETCH_CFG_drbr_wr_prefetch_nbr_iid_START (16)
#define SOC_ISP_DRBR_DRBR_WR_PREFETCH_CFG_drbr_wr_prefetch_nbr_iid_END (19)
#define SOC_ISP_DRBR_DRBR_WR_PREFETCH_CFG_drbr_wr_prefetch_mode_START (30)
#define SOC_ISP_DRBR_DRBR_WR_PREFETCH_CFG_drbr_wr_prefetch_mode_END (30)
#define SOC_ISP_DRBR_DRBR_WR_PREFETCH_CFG_drbr_wr_prefetch_enable_START (31)
#define SOC_ISP_DRBR_DRBR_WR_PREFETCH_CFG_drbr_wr_prefetch_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rw_reg_0 : 32;
    } reg;
} SOC_ISP_DRBR_DRBR_RW_REG_0_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_RW_REG_0_rw_reg_0_START (0)
#define SOC_ISP_DRBR_DRBR_RW_REG_0_rw_reg_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rw_reg_1 : 32;
    } reg;
} SOC_ISP_DRBR_DRBR_RW_REG_1_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_RW_REG_1_rw_reg_1_START (0)
#define SOC_ISP_DRBR_DRBR_RW_REG_1_rw_reg_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_0 : 32;
    } reg;
} SOC_ISP_DRBR_DRBR_DEBUG_0_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_DEBUG_0_debug_0_START (0)
#define SOC_ISP_DRBR_DRBR_DEBUG_0_debug_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_1 : 32;
    } reg;
} SOC_ISP_DRBR_DRBR_DEBUG_1_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_DEBUG_1_debug_1_START (0)
#define SOC_ISP_DRBR_DRBR_DEBUG_1_debug_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_2 : 32;
    } reg;
} SOC_ISP_DRBR_DRBR_DEBUG_2_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_DEBUG_2_debug_2_START (0)
#define SOC_ISP_DRBR_DRBR_DEBUG_2_debug_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_3 : 32;
    } reg;
} SOC_ISP_DRBR_DRBR_DEBUG_3_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_DEBUG_3_debug_3_START (0)
#define SOC_ISP_DRBR_DRBR_DEBUG_3_debug_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_4 : 32;
    } reg;
} SOC_ISP_DRBR_DRBR_DEBUG_4_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_DEBUG_4_debug_4_START (0)
#define SOC_ISP_DRBR_DRBR_DEBUG_4_debug_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_5 : 32;
    } reg;
} SOC_ISP_DRBR_DRBR_DEBUG_5_UNION;
#endif
#define SOC_ISP_DRBR_DRBR_DEBUG_5_debug_5_START (0)
#define SOC_ISP_DRBR_DRBR_DEBUG_5_debug_5_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

#ifndef __SOC_ISP_DGEN_INTERFACE_H__
#define __SOC_ISP_DGEN_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_DGEN_DGEN_ID_ADDR(base) ((base) + (0x0))
#define SOC_ISP_DGEN_DGEN_VERSION_ADDR(base) ((base) + (0x4))
#define SOC_ISP_DGEN_DGEN_FORCE_CLK_ON_CFG_ADDR(base) ((base) + (0x10))
#define SOC_ISP_DGEN_DGEN_EN_ADDR(base) ((base) + (0x20))
#define SOC_ISP_DGEN_DGEN_CFG_ADDR(base) ((base) + (0x24))
#define SOC_ISP_DGEN_DGEN_IMAGE_SIZE_ADDR(base) ((base) + (0x28))
#define SOC_ISP_DGEN_DGEN_IMAGE_SHIFT_ADDR(base) ((base) + (0x2C))
#define SOC_ISP_DGEN_DGEN_DISPARITY_CFG_ADDR(base) ((base) + (0x30))
#define SOC_ISP_DGEN_DGEN_MULTIPASS_ADDR(base) ((base) + (0x34))
#define SOC_ISP_DGEN_DGEN_VALLEY_A_ADDR(base) ((base) + (0x38))
#define SOC_ISP_DGEN_DGEN_VALLEY_B_ADDR(base) ((base) + (0x3C))
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_A_ADDR(base) ((base) + (0x40))
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_B_ADDR(base) ((base) + (0x44))
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_C_ADDR(base) ((base) + (0x48))
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_D_ADDR(base) ((base) + (0x4C))
#define SOC_ISP_DGEN_DGEN_WEIGHT_CFG_ADDR(base) ((base) + (0x50))
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_A_ADDR(base) ((base) + (0x54))
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_B_ADDR(base) ((base) + (0x58))
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_C_ADDR(base) ((base) + (0x5C))
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_A_ADDR(base) ((base) + (0x60))
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_B_ADDR(base) ((base) + (0x64))
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_C_ADDR(base) ((base) + (0x68))
#define SOC_ISP_DGEN_DGEN_AGGREGATE_MASK_CFG_ADDR(base) ((base) + (0x6C))
#define SOC_ISP_DGEN_DGEN_AGGREGATE_THRESHOLD_ADDR(base) ((base) + (0x70))
#define SOC_ISP_DGEN_DGEN_SCANLINE_THRESHOLD_ADDR(base) ((base) + (0x74))
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_ADDR(base) ((base) + (0x78))
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_MID_ADDR(base) ((base) + (0x7C))
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_LOW_ADDR(base) ((base) + (0x80))
#define SOC_ISP_DGEN_DGEN_LRCHECK_ADDR(base) ((base) + (0x88))
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_THR_ADDR(base) ((base) + (0x8C))
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_LOW_ADDR(base) ((base) + (0x90))
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_HIGH_ADDR(base) ((base) + (0x94))
#define SOC_ISP_DGEN_LEFT_RD_CFG_ADDR(base) ((base) + (0x100))
#define SOC_ISP_DGEN_LEFT_RD_FIRST_32K_PAGE_ADDR(base) ((base) + (0x104))
#define SOC_ISP_DGEN_LEFT_RD_LAST_32K_PAGE_ADDR(base) ((base) + (0x108))
#define SOC_ISP_DGEN_LEFT_RD_PREFETCH_CFG_ADDR(base) ((base) + (0x10C))
#define SOC_ISP_DGEN_RIGHT_RD_CFG_ADDR(base) ((base) + (0x120))
#define SOC_ISP_DGEN_RIGHT_RD_FIRST_32K_PAGE_ADDR(base) ((base) + (0x124))
#define SOC_ISP_DGEN_RIGHT_RD_LAST_32K_PAGE_ADDR(base) ((base) + (0x128))
#define SOC_ISP_DGEN_RIGHT_RD_PREFETCH_CFG_ADDR(base) ((base) + (0x12C))
#define SOC_ISP_DGEN_DISP_WR_CFG_ADDR(base) ((base) + (0x140))
#define SOC_ISP_DGEN_DISP_WR_FIRST_32K_PAGE_ADDR(base) ((base) + (0x144))
#define SOC_ISP_DGEN_DISP_WR_LAST_32K_PAGE_ADDR(base) ((base) + (0x148))
#define SOC_ISP_DGEN_DISP_WR_PREFETCH_CFG_ADDR(base) ((base) + (0x14C))
#define SOC_ISP_DGEN_CONF_WR_CFG_ADDR(base) ((base) + (0x160))
#define SOC_ISP_DGEN_CONF_WR_FIRST_32K_PAGE_ADDR(base) ((base) + (0x164))
#define SOC_ISP_DGEN_CONF_WR_LAST_32K_PAGE_ADDR(base) ((base) + (0x168))
#define SOC_ISP_DGEN_CONF_WR_PREFETCH_CFG_ADDR(base) ((base) + (0x16C))
#define SOC_ISP_DGEN_WORKING_WR_RIRST_32K_PAGE_ADDR(base) ((base) + (0x200))
#define SOC_ISP_DGEN_WORKING_WR_LAST_32K_PAGE_ADDR(base) ((base) + (0x204))
#define SOC_ISP_DGEN_WORKING_WR_STRIDE_ADDR(base) ((base) + (0x208))
#define SOC_ISP_DGEN_WORKING_WR_PREFETCH_CFG_ADDR(base) ((base) + (0x20C))
#define SOC_ISP_DGEN_WORKING_RD_FIRST_32K_PAGE_ADDR(base) ((base) + (0x220))
#define SOC_ISP_DGEN_WORKING_RD_LAST_32K_PAGE_ADDR(base) ((base) + (0x224))
#define SOC_ISP_DGEN_WORKING_RD_STRIDE_ADDR(base) ((base) + (0x228))
#define SOC_ISP_DGEN_WORKING_RD_PREFETCH_CFG_ADDR(base) ((base) + (0x22C))
#define SOC_ISP_DGEN_LEFT_RD_FIRST_BLOCK_CFG_ADDR(base) ((base) + (0x240))
#define SOC_ISP_DGEN_LEFT_RD_LAST_BLOCK_CFG_ADDR(base) ((base) + (0x244))
#define SOC_ISP_DGEN_LEFT_RD_CROP_H_ADDR(base) ((base) + (0x248))
#define SOC_ISP_DGEN_RIGHT_RD_FIRST_BLOCK_CFG_ADDR(base) ((base) + (0x250))
#define SOC_ISP_DGEN_RIGHT_RD_LAST_BLOCK_CFG_ADDR(base) ((base) + (0x254))
#define SOC_ISP_DGEN_RIGHT_RD_CROP_H_ADDR(base) ((base) + (0x258))
#define SOC_ISP_DGEN_WORKING_WR_FIRST_BLOCK_CFG_ADDR(base) ((base) + (0x260))
#define SOC_ISP_DGEN_WORKING_WR_LAST_BLOCK_CFG_ADDR(base) ((base) + (0x264))
#define SOC_ISP_DGEN_WORKING_WR_CROP_H_ADDR(base) ((base) + (0x268))
#define SOC_ISP_DGEN_WORKING_RD_FIRST_BLOCK_CFG_ADDR(base) ((base) + (0x270))
#define SOC_ISP_DGEN_WORKING_RD_LAST_BLOCK_CFG_ADDR(base) ((base) + (0x274))
#define SOC_ISP_DGEN_WORKING_RD_CROP_H_ADDR(base) ((base) + (0x278))
#define SOC_ISP_DGEN_DISP_WR_FIRST_BLOCK_CFG_ADDR(base) ((base) + (0x280))
#define SOC_ISP_DGEN_DISP_WR_LAST_BLOCK_CFG_ADDR(base) ((base) + (0x284))
#define SOC_ISP_DGEN_CONF_WR_FIRST_BLOCK_CFG_ADDR(base) ((base) + (0x290))
#define SOC_ISP_DGEN_CONF_WR_LAST_BLOCK_CFG_ADDR(base) ((base) + (0x294))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG0_ADDR(base) ((base) + (0x300))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG1_ADDR(base) ((base) + (0x304))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG2_ADDR(base) ((base) + (0x308))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG3_ADDR(base) ((base) + (0x30C))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG4_ADDR(base) ((base) + (0x310))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG5_ADDR(base) ((base) + (0x314))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG6_ADDR(base) ((base) + (0x318))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG7_ADDR(base) ((base) + (0x31C))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG8_ADDR(base) ((base) + (0x320))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG9_ADDR(base) ((base) + (0x324))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG10_ADDR(base) ((base) + (0x328))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG11_ADDR(base) ((base) + (0x32C))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG12_ADDR(base) ((base) + (0x330))
#define SOC_ISP_DGEN_DGEN_DRBR_DBG13_ADDR(base) ((base) + (0x334))
#define SOC_ISP_DGEN_DGEN_CORE_DBG0_ADDR(base) ((base) + (0x338))
#define SOC_ISP_DGEN_DGEN_CORE_DBG1_ADDR(base) ((base) + (0x33C))
#define SOC_ISP_DGEN_DGEN_CORE_DBG2_ADDR(base) ((base) + (0x340))
#define SOC_ISP_DGEN_DGEN_CORE_DBG3_ADDR(base) ((base) + (0x344))
#define SOC_ISP_DGEN_DGEN_CORE_DBG4_ADDR(base) ((base) + (0x348))
#define SOC_ISP_DGEN_DGEN_CORE_DBG5_ADDR(base) ((base) + (0x34C))
#define SOC_ISP_DGEN_DGEN_DEUBUG_RW_001_ADDR(base) ((base) + (0x350))
#define SOC_ISP_DGEN_DGEN_DEUBUG_RW_002_ADDR(base) ((base) + (0x354))
#define SOC_ISP_DGEN_DGEN_DEUBUG_RW_003_ADDR(base) ((base) + (0x358))
#define SOC_ISP_DGEN_DGEN_DEUBUG_RW_004_ADDR(base) ((base) + (0x35C))
#define SOC_ISP_DGEN_DGEN_DISP_HIST_ADDR(base,Range256) ((base) + (0x400+(Range256)*4))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dgen_ip_id : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_ID_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_ID_dgen_ip_id_START (0)
#define SOC_ISP_DGEN_DGEN_ID_dgen_ip_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dgen_ip_version : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_VERSION_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_VERSION_dgen_ip_version_START (0)
#define SOC_ISP_DGEN_DGEN_VERSION_dgen_ip_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_clk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_DGEN_DGEN_FORCE_CLK_ON_CFG_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_FORCE_CLK_ON_CFG_force_clk_on_START (0)
#define SOC_ISP_DGEN_DGEN_FORCE_CLK_ON_CFG_force_clk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 31;
        unsigned int dgen_en : 1;
    } reg;
} SOC_ISP_DGEN_DGEN_EN_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_EN_dgen_en_START (31)
#define SOC_ISP_DGEN_DGEN_EN_dgen_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int median_confidence_enable : 1;
        unsigned int variance_threshold_enable : 1;
        unsigned int variance_gray_threshold_enable : 1;
        unsigned int scanline_variance_enable : 1;
        unsigned int remove_invalid_disparities_enable : 1;
        unsigned int median_filter_enable : 1;
        unsigned int lr_check_enable : 1;
        unsigned int scanline_right_image_available : 1;
        unsigned int scanline_enable : 1;
        unsigned int search_mode : 1;
        unsigned int first_stripe : 1;
        unsigned int last_stripe : 1;
        unsigned int output_disparity_format : 2;
        unsigned int input_format : 2;
        unsigned int conf_wr_mode : 2;
        unsigned int prefetch_raster_input_mode : 1;
        unsigned int hist_en : 1;
        unsigned int conf_wr_scrambler_ddr_channels : 1;
        unsigned int conf_wr_scrambler_ddr_granularity : 3;
        unsigned int disp_wr_mode : 2;
        unsigned int reserved : 2;
        unsigned int disp_wr_scrambler_ddr_channels : 1;
        unsigned int disp_wr_scrambler_ddr_granularity : 3;
    } reg;
} SOC_ISP_DGEN_DGEN_CFG_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CFG_median_confidence_enable_START (0)
#define SOC_ISP_DGEN_DGEN_CFG_median_confidence_enable_END (0)
#define SOC_ISP_DGEN_DGEN_CFG_variance_threshold_enable_START (1)
#define SOC_ISP_DGEN_DGEN_CFG_variance_threshold_enable_END (1)
#define SOC_ISP_DGEN_DGEN_CFG_variance_gray_threshold_enable_START (2)
#define SOC_ISP_DGEN_DGEN_CFG_variance_gray_threshold_enable_END (2)
#define SOC_ISP_DGEN_DGEN_CFG_scanline_variance_enable_START (3)
#define SOC_ISP_DGEN_DGEN_CFG_scanline_variance_enable_END (3)
#define SOC_ISP_DGEN_DGEN_CFG_remove_invalid_disparities_enable_START (4)
#define SOC_ISP_DGEN_DGEN_CFG_remove_invalid_disparities_enable_END (4)
#define SOC_ISP_DGEN_DGEN_CFG_median_filter_enable_START (5)
#define SOC_ISP_DGEN_DGEN_CFG_median_filter_enable_END (5)
#define SOC_ISP_DGEN_DGEN_CFG_lr_check_enable_START (6)
#define SOC_ISP_DGEN_DGEN_CFG_lr_check_enable_END (6)
#define SOC_ISP_DGEN_DGEN_CFG_scanline_right_image_available_START (7)
#define SOC_ISP_DGEN_DGEN_CFG_scanline_right_image_available_END (7)
#define SOC_ISP_DGEN_DGEN_CFG_scanline_enable_START (8)
#define SOC_ISP_DGEN_DGEN_CFG_scanline_enable_END (8)
#define SOC_ISP_DGEN_DGEN_CFG_search_mode_START (9)
#define SOC_ISP_DGEN_DGEN_CFG_search_mode_END (9)
#define SOC_ISP_DGEN_DGEN_CFG_first_stripe_START (10)
#define SOC_ISP_DGEN_DGEN_CFG_first_stripe_END (10)
#define SOC_ISP_DGEN_DGEN_CFG_last_stripe_START (11)
#define SOC_ISP_DGEN_DGEN_CFG_last_stripe_END (11)
#define SOC_ISP_DGEN_DGEN_CFG_output_disparity_format_START (12)
#define SOC_ISP_DGEN_DGEN_CFG_output_disparity_format_END (13)
#define SOC_ISP_DGEN_DGEN_CFG_input_format_START (14)
#define SOC_ISP_DGEN_DGEN_CFG_input_format_END (15)
#define SOC_ISP_DGEN_DGEN_CFG_conf_wr_mode_START (16)
#define SOC_ISP_DGEN_DGEN_CFG_conf_wr_mode_END (17)
#define SOC_ISP_DGEN_DGEN_CFG_prefetch_raster_input_mode_START (18)
#define SOC_ISP_DGEN_DGEN_CFG_prefetch_raster_input_mode_END (18)
#define SOC_ISP_DGEN_DGEN_CFG_hist_en_START (19)
#define SOC_ISP_DGEN_DGEN_CFG_hist_en_END (19)
#define SOC_ISP_DGEN_DGEN_CFG_conf_wr_scrambler_ddr_channels_START (20)
#define SOC_ISP_DGEN_DGEN_CFG_conf_wr_scrambler_ddr_channels_END (20)
#define SOC_ISP_DGEN_DGEN_CFG_conf_wr_scrambler_ddr_granularity_START (21)
#define SOC_ISP_DGEN_DGEN_CFG_conf_wr_scrambler_ddr_granularity_END (23)
#define SOC_ISP_DGEN_DGEN_CFG_disp_wr_mode_START (24)
#define SOC_ISP_DGEN_DGEN_CFG_disp_wr_mode_END (25)
#define SOC_ISP_DGEN_DGEN_CFG_disp_wr_scrambler_ddr_channels_START (28)
#define SOC_ISP_DGEN_DGEN_CFG_disp_wr_scrambler_ddr_channels_END (28)
#define SOC_ISP_DGEN_DGEN_CFG_disp_wr_scrambler_ddr_granularity_START (29)
#define SOC_ISP_DGEN_DGEN_CFG_disp_wr_scrambler_ddr_granularity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int disparity_format_height : 13;
        unsigned int reserved_0 : 3;
        unsigned int disparity_format_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_DGEN_DGEN_IMAGE_SIZE_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_IMAGE_SIZE_disparity_format_height_START (0)
#define SOC_ISP_DGEN_DGEN_IMAGE_SIZE_disparity_format_height_END (12)
#define SOC_ISP_DGEN_DGEN_IMAGE_SIZE_disparity_format_width_START (16)
#define SOC_ISP_DGEN_DGEN_IMAGE_SIZE_disparity_format_width_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 12;
        unsigned int right_image_shift_pixels : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_ISP_DGEN_DGEN_IMAGE_SHIFT_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_IMAGE_SHIFT_right_image_shift_pixels_START (12)
#define SOC_ISP_DGEN_DGEN_IMAGE_SHIFT_right_image_shift_pixels_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int disparity_section : 3;
        unsigned int reserved_0 : 5;
        unsigned int max_disparity : 6;
        unsigned int reserved_1 : 2;
        unsigned int invalid_disparity_conf_threshold : 4;
        unsigned int reserved_2 : 4;
        unsigned int disparity_offset : 8;
    } reg;
} SOC_ISP_DGEN_DGEN_DISPARITY_CFG_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DISPARITY_CFG_disparity_section_START (0)
#define SOC_ISP_DGEN_DGEN_DISPARITY_CFG_disparity_section_END (2)
#define SOC_ISP_DGEN_DGEN_DISPARITY_CFG_max_disparity_START (8)
#define SOC_ISP_DGEN_DGEN_DISPARITY_CFG_max_disparity_END (13)
#define SOC_ISP_DGEN_DGEN_DISPARITY_CFG_invalid_disparity_conf_threshold_START (16)
#define SOC_ISP_DGEN_DGEN_DISPARITY_CFG_invalid_disparity_conf_threshold_END (19)
#define SOC_ISP_DGEN_DGEN_DISPARITY_CFG_disparity_offset_START (24)
#define SOC_ISP_DGEN_DGEN_DISPARITY_CFG_disparity_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int multipass_disparity_threshold : 10;
        unsigned int reserved_0 : 6;
        unsigned int multipass_cost_shift : 3;
        unsigned int reserved_1 : 11;
        unsigned int multipass_read_enable : 1;
        unsigned int multipass_write_enable : 1;
    } reg;
} SOC_ISP_DGEN_DGEN_MULTIPASS_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_MULTIPASS_multipass_disparity_threshold_START (0)
#define SOC_ISP_DGEN_DGEN_MULTIPASS_multipass_disparity_threshold_END (9)
#define SOC_ISP_DGEN_DGEN_MULTIPASS_multipass_cost_shift_START (16)
#define SOC_ISP_DGEN_DGEN_MULTIPASS_multipass_cost_shift_END (18)
#define SOC_ISP_DGEN_DGEN_MULTIPASS_multipass_read_enable_START (30)
#define SOC_ISP_DGEN_DGEN_MULTIPASS_multipass_read_enable_END (30)
#define SOC_ISP_DGEN_DGEN_MULTIPASS_multipass_write_enable_START (31)
#define SOC_ISP_DGEN_DGEN_MULTIPASS_multipass_write_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int valley_cost_ratio : 7;
        unsigned int reserved_0 : 1;
        unsigned int valley_cost_truncate : 8;
        unsigned int reserved_1 : 15;
        unsigned int remove_repet_enable : 1;
    } reg;
} SOC_ISP_DGEN_DGEN_VALLEY_A_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_VALLEY_A_valley_cost_ratio_START (0)
#define SOC_ISP_DGEN_DGEN_VALLEY_A_valley_cost_ratio_END (6)
#define SOC_ISP_DGEN_DGEN_VALLEY_A_valley_cost_truncate_START (8)
#define SOC_ISP_DGEN_DGEN_VALLEY_A_valley_cost_truncate_END (15)
#define SOC_ISP_DGEN_DGEN_VALLEY_A_remove_repet_enable_START (31)
#define SOC_ISP_DGEN_DGEN_VALLEY_A_remove_repet_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int valley_threshold_ratio : 7;
        unsigned int reserved : 9;
        unsigned int valley_threshold_count_low : 8;
        unsigned int valley_threshold_count_high : 8;
    } reg;
} SOC_ISP_DGEN_DGEN_VALLEY_B_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_VALLEY_B_valley_threshold_ratio_START (0)
#define SOC_ISP_DGEN_DGEN_VALLEY_B_valley_threshold_ratio_END (6)
#define SOC_ISP_DGEN_DGEN_VALLEY_B_valley_threshold_count_low_START (16)
#define SOC_ISP_DGEN_DGEN_VALLEY_B_valley_threshold_count_low_END (23)
#define SOC_ISP_DGEN_DGEN_VALLEY_B_valley_threshold_count_high_START (24)
#define SOC_ISP_DGEN_DGEN_VALLEY_B_valley_threshold_count_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int variance_threshold_low : 16;
        unsigned int variance_threshold : 16;
    } reg;
} SOC_ISP_DGEN_DGEN_CALCVARIANCE_A_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_A_variance_threshold_low_START (0)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_A_variance_threshold_low_END (15)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_A_variance_threshold_START (16)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_A_variance_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int variance_gray_threshold_low : 8;
        unsigned int variance_gray_threshold_mid : 8;
        unsigned int variance_threshold_mid : 16;
    } reg;
} SOC_ISP_DGEN_DGEN_CALCVARIANCE_B_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_B_variance_gray_threshold_low_START (0)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_B_variance_gray_threshold_low_END (7)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_B_variance_gray_threshold_mid_START (8)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_B_variance_gray_threshold_mid_END (15)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_B_variance_threshold_mid_START (16)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_B_variance_threshold_mid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int variance_gray_threshold_high : 8;
        unsigned int reserved : 8;
        unsigned int variance_threshold_high : 16;
    } reg;
} SOC_ISP_DGEN_DGEN_CALCVARIANCE_C_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_C_variance_gray_threshold_high_START (0)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_C_variance_gray_threshold_high_END (7)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_C_variance_threshold_high_START (16)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_C_variance_threshold_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int variance_gray_shift : 4;
        unsigned int reserved_0 : 12;
        unsigned int variance_gray_weight : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_DGEN_DGEN_CALCVARIANCE_D_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_D_variance_gray_shift_START (0)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_D_variance_gray_shift_END (3)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_D_variance_gray_weight_START (16)
#define SOC_ISP_DGEN_DGEN_CALCVARIANCE_D_variance_gray_weight_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int census_shift : 4;
        unsigned int reserved_0 : 12;
        unsigned int ad_uv_shift : 4;
        unsigned int ad_y_shift : 4;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_DGEN_DGEN_WEIGHT_CFG_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_WEIGHT_CFG_census_shift_START (0)
#define SOC_ISP_DGEN_DGEN_WEIGHT_CFG_census_shift_END (3)
#define SOC_ISP_DGEN_DGEN_WEIGHT_CFG_ad_uv_shift_START (16)
#define SOC_ISP_DGEN_DGEN_WEIGHT_CFG_ad_uv_shift_END (19)
#define SOC_ISP_DGEN_DGEN_WEIGHT_CFG_ad_y_shift_START (20)
#define SOC_ISP_DGEN_DGEN_WEIGHT_CFG_ad_y_shift_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int robust_ad_a : 4;
        unsigned int reserved_0 : 4;
        unsigned int robust_ad_k_a : 8;
        unsigned int robust_ad_x_a : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_A_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_A_robust_ad_a_START (0)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_A_robust_ad_a_END (3)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_A_robust_ad_k_a_START (8)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_A_robust_ad_k_a_END (15)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_A_robust_ad_x_a_START (16)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_A_robust_ad_x_a_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int robust_ad_b : 10;
        unsigned int robust_ad_k_b : 6;
        unsigned int robust_ad_x_b : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_B_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_B_robust_ad_b_START (0)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_B_robust_ad_b_END (9)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_B_robust_ad_k_b_START (10)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_B_robust_ad_k_b_END (15)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_B_robust_ad_x_b_START (16)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_B_robust_ad_x_b_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int robust_ad_c : 10;
        unsigned int robust_ad_k_c : 5;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_C_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_C_robust_ad_c_START (0)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_C_robust_ad_c_END (9)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_C_robust_ad_k_c_START (10)
#define SOC_ISP_DGEN_DGEN_ROBUST_AD_CFG_C_robust_ad_k_c_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int robust_census_a : 4;
        unsigned int reserved_0 : 4;
        unsigned int robust_census_k_a : 8;
        unsigned int robust_census_x_a : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_A_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_A_robust_census_a_START (0)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_A_robust_census_a_END (3)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_A_robust_census_k_a_START (8)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_A_robust_census_k_a_END (15)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_A_robust_census_x_a_START (16)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_A_robust_census_x_a_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int robust_census_b : 10;
        unsigned int robust_census_k_b : 6;
        unsigned int robust_census_x_b : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_B_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_B_robust_census_b_START (0)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_B_robust_census_b_END (9)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_B_robust_census_k_b_START (10)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_B_robust_census_k_b_END (15)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_B_robust_census_x_b_START (16)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_B_robust_census_x_b_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int robust_census_c : 10;
        unsigned int robust_census_k_c : 5;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_C_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_C_robust_census_c_START (0)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_C_robust_census_c_END (9)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_C_robust_census_k_c_START (10)
#define SOC_ISP_DGEN_DGEN_ROBUST_CENSUS_CFG_C_robust_census_k_c_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aggregation_h_mask_mid : 4;
        unsigned int reserved_0 : 4;
        unsigned int aggregation_v_mask_mid : 4;
        unsigned int reserved_1 : 4;
        unsigned int aggregation_h_mask_max : 4;
        unsigned int reserved_2 : 4;
        unsigned int aggregation_v_mask_max : 4;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_ISP_DGEN_DGEN_AGGREGATE_MASK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_AGGREGATE_MASK_CFG_aggregation_h_mask_mid_START (0)
#define SOC_ISP_DGEN_DGEN_AGGREGATE_MASK_CFG_aggregation_h_mask_mid_END (3)
#define SOC_ISP_DGEN_DGEN_AGGREGATE_MASK_CFG_aggregation_v_mask_mid_START (8)
#define SOC_ISP_DGEN_DGEN_AGGREGATE_MASK_CFG_aggregation_v_mask_mid_END (11)
#define SOC_ISP_DGEN_DGEN_AGGREGATE_MASK_CFG_aggregation_h_mask_max_START (16)
#define SOC_ISP_DGEN_DGEN_AGGREGATE_MASK_CFG_aggregation_h_mask_max_END (19)
#define SOC_ISP_DGEN_DGEN_AGGREGATE_MASK_CFG_aggregation_v_mask_max_START (24)
#define SOC_ISP_DGEN_DGEN_AGGREGATE_MASK_CFG_aggregation_v_mask_max_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aggregation_yuv_threshold_low : 8;
        unsigned int aggregation_yuv_threshold_edge_high : 8;
        unsigned int aggregation_yuv_threshold_high : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_ISP_DGEN_DGEN_AGGREGATE_THRESHOLD_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_AGGREGATE_THRESHOLD_aggregation_yuv_threshold_low_START (0)
#define SOC_ISP_DGEN_DGEN_AGGREGATE_THRESHOLD_aggregation_yuv_threshold_low_END (7)
#define SOC_ISP_DGEN_DGEN_AGGREGATE_THRESHOLD_aggregation_yuv_threshold_edge_high_START (8)
#define SOC_ISP_DGEN_DGEN_AGGREGATE_THRESHOLD_aggregation_yuv_threshold_edge_high_END (15)
#define SOC_ISP_DGEN_DGEN_AGGREGATE_THRESHOLD_aggregation_yuv_threshold_high_START (16)
#define SOC_ISP_DGEN_DGEN_AGGREGATE_THRESHOLD_aggregation_yuv_threshold_high_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scanline_yuv_threshold : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_DGEN_DGEN_SCANLINE_THRESHOLD_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_SCANLINE_THRESHOLD_scanline_yuv_threshold_START (0)
#define SOC_ISP_DGEN_DGEN_SCANLINE_THRESHOLD_scanline_yuv_threshold_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scanline_penalty_1 : 12;
        unsigned int reserved_0 : 4;
        unsigned int scanline_penalty_2 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_scanline_penalty_1_START (0)
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_scanline_penalty_1_END (11)
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_scanline_penalty_2_START (16)
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_scanline_penalty_2_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scanline_penalty_1_mid : 12;
        unsigned int reserved_0 : 4;
        unsigned int scanline_penalty_2_mid : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_MID_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_MID_scanline_penalty_1_mid_START (0)
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_MID_scanline_penalty_1_mid_END (11)
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_MID_scanline_penalty_2_mid_START (16)
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_MID_scanline_penalty_2_mid_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scanline_penalty_1_low : 12;
        unsigned int reserved_0 : 4;
        unsigned int scanline_penalty_2_low : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_LOW_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_LOW_scanline_penalty_1_low_START (0)
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_LOW_scanline_penalty_1_low_END (11)
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_LOW_scanline_penalty_2_low_START (16)
#define SOC_ISP_DGEN_DGEN_SCANLINE_PENALTY_LOW_scanline_penalty_2_low_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lrcheck_threshold : 5;
        unsigned int reserved_0 : 3;
        unsigned int disp_gap_ratio_shift : 4;
        unsigned int disp_gap_ratio : 4;
        unsigned int disp_gap : 3;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_ISP_DGEN_DGEN_LRCHECK_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_LRCHECK_lrcheck_threshold_START (0)
#define SOC_ISP_DGEN_DGEN_LRCHECK_lrcheck_threshold_END (4)
#define SOC_ISP_DGEN_DGEN_LRCHECK_disp_gap_ratio_shift_START (8)
#define SOC_ISP_DGEN_DGEN_LRCHECK_disp_gap_ratio_shift_END (11)
#define SOC_ISP_DGEN_DGEN_LRCHECK_disp_gap_ratio_START (12)
#define SOC_ISP_DGEN_DGEN_LRCHECK_disp_gap_ratio_END (15)
#define SOC_ISP_DGEN_DGEN_LRCHECK_disp_gap_START (16)
#define SOC_ISP_DGEN_DGEN_LRCHECK_disp_gap_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int confidence_cost_threshold : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_DGEN_DGEN_CONFIDENCE_THR_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_THR_confidence_cost_threshold_START (0)
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_THR_confidence_cost_threshold_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int confidence_slop_low : 11;
        unsigned int reserved_0 : 1;
        unsigned int confidence_intercept_low : 19;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_ISP_DGEN_DGEN_CONFIDENCE_LOW_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_LOW_confidence_slop_low_START (0)
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_LOW_confidence_slop_low_END (10)
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_LOW_confidence_intercept_low_START (12)
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_LOW_confidence_intercept_low_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int confidence_slop_high : 11;
        unsigned int reserved_0 : 1;
        unsigned int confidence_intercept_high : 19;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_ISP_DGEN_DGEN_CONFIDENCE_HIGH_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_HIGH_confidence_slop_high_START (0)
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_HIGH_confidence_slop_high_END (10)
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_HIGH_confidence_intercept_high_START (12)
#define SOC_ISP_DGEN_DGEN_CONFIDENCE_HIGH_confidence_intercept_high_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int left_rd_stride : 10;
        unsigned int reserved_1 : 4;
        unsigned int left_rd_flip_enable : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_ISP_DGEN_LEFT_RD_CFG_UNION;
#endif
#define SOC_ISP_DGEN_LEFT_RD_CFG_left_rd_stride_START (16)
#define SOC_ISP_DGEN_LEFT_RD_CFG_left_rd_stride_END (25)
#define SOC_ISP_DGEN_LEFT_RD_CFG_left_rd_flip_enable_START (30)
#define SOC_ISP_DGEN_LEFT_RD_CFG_left_rd_flip_enable_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int left_rd_first_32k_page : 17;
    } reg;
} SOC_ISP_DGEN_LEFT_RD_FIRST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DGEN_LEFT_RD_FIRST_32K_PAGE_left_rd_first_32k_page_START (15)
#define SOC_ISP_DGEN_LEFT_RD_FIRST_32K_PAGE_left_rd_first_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int left_rd_last_32k_page : 17;
    } reg;
} SOC_ISP_DGEN_LEFT_RD_LAST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DGEN_LEFT_RD_LAST_32K_PAGE_left_rd_last_32k_page_START (15)
#define SOC_ISP_DGEN_LEFT_RD_LAST_32K_PAGE_left_rd_last_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int left_rd_prefetch_delay : 11;
        unsigned int reserved : 20;
        unsigned int left_rd_prefetch_enable : 1;
    } reg;
} SOC_ISP_DGEN_LEFT_RD_PREFETCH_CFG_UNION;
#endif
#define SOC_ISP_DGEN_LEFT_RD_PREFETCH_CFG_left_rd_prefetch_delay_START (0)
#define SOC_ISP_DGEN_LEFT_RD_PREFETCH_CFG_left_rd_prefetch_delay_END (10)
#define SOC_ISP_DGEN_LEFT_RD_PREFETCH_CFG_left_rd_prefetch_enable_START (31)
#define SOC_ISP_DGEN_LEFT_RD_PREFETCH_CFG_left_rd_prefetch_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int right_rd_stride : 10;
        unsigned int reserved_1 : 4;
        unsigned int right_rd_flip_enable : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_ISP_DGEN_RIGHT_RD_CFG_UNION;
#endif
#define SOC_ISP_DGEN_RIGHT_RD_CFG_right_rd_stride_START (16)
#define SOC_ISP_DGEN_RIGHT_RD_CFG_right_rd_stride_END (25)
#define SOC_ISP_DGEN_RIGHT_RD_CFG_right_rd_flip_enable_START (30)
#define SOC_ISP_DGEN_RIGHT_RD_CFG_right_rd_flip_enable_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int right_rd_first_32k_page : 17;
    } reg;
} SOC_ISP_DGEN_RIGHT_RD_FIRST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DGEN_RIGHT_RD_FIRST_32K_PAGE_right_rd_first_32k_page_START (15)
#define SOC_ISP_DGEN_RIGHT_RD_FIRST_32K_PAGE_right_rd_first_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int right_rd_last_32k_page : 17;
    } reg;
} SOC_ISP_DGEN_RIGHT_RD_LAST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DGEN_RIGHT_RD_LAST_32K_PAGE_right_rd_last_32k_page_START (15)
#define SOC_ISP_DGEN_RIGHT_RD_LAST_32K_PAGE_right_rd_last_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int right_rd_prefetch_delay : 11;
        unsigned int reserved : 20;
        unsigned int right_rd_prefetch_enable : 1;
    } reg;
} SOC_ISP_DGEN_RIGHT_RD_PREFETCH_CFG_UNION;
#endif
#define SOC_ISP_DGEN_RIGHT_RD_PREFETCH_CFG_right_rd_prefetch_delay_START (0)
#define SOC_ISP_DGEN_RIGHT_RD_PREFETCH_CFG_right_rd_prefetch_delay_END (10)
#define SOC_ISP_DGEN_RIGHT_RD_PREFETCH_CFG_right_rd_prefetch_enable_START (31)
#define SOC_ISP_DGEN_RIGHT_RD_PREFETCH_CFG_right_rd_prefetch_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int disp_wr_stride : 10;
        unsigned int reserved_1 : 4;
        unsigned int disp_wr_flip_enable : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_ISP_DGEN_DISP_WR_CFG_UNION;
#endif
#define SOC_ISP_DGEN_DISP_WR_CFG_disp_wr_stride_START (16)
#define SOC_ISP_DGEN_DISP_WR_CFG_disp_wr_stride_END (25)
#define SOC_ISP_DGEN_DISP_WR_CFG_disp_wr_flip_enable_START (30)
#define SOC_ISP_DGEN_DISP_WR_CFG_disp_wr_flip_enable_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int disp_wr_first_32k_page : 17;
    } reg;
} SOC_ISP_DGEN_DISP_WR_FIRST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DGEN_DISP_WR_FIRST_32K_PAGE_disp_wr_first_32k_page_START (15)
#define SOC_ISP_DGEN_DISP_WR_FIRST_32K_PAGE_disp_wr_first_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int disp_wr_last_32k_page : 17;
    } reg;
} SOC_ISP_DGEN_DISP_WR_LAST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DGEN_DISP_WR_LAST_32K_PAGE_disp_wr_last_32k_page_START (15)
#define SOC_ISP_DGEN_DISP_WR_LAST_32K_PAGE_disp_wr_last_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int disp_wr_prefetch_delay : 11;
        unsigned int reserved : 20;
        unsigned int disp_wr_prefetch_enable : 1;
    } reg;
} SOC_ISP_DGEN_DISP_WR_PREFETCH_CFG_UNION;
#endif
#define SOC_ISP_DGEN_DISP_WR_PREFETCH_CFG_disp_wr_prefetch_delay_START (0)
#define SOC_ISP_DGEN_DISP_WR_PREFETCH_CFG_disp_wr_prefetch_delay_END (10)
#define SOC_ISP_DGEN_DISP_WR_PREFETCH_CFG_disp_wr_prefetch_enable_START (31)
#define SOC_ISP_DGEN_DISP_WR_PREFETCH_CFG_disp_wr_prefetch_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int conf_wr_stride : 10;
        unsigned int reserved_1 : 4;
        unsigned int conf_wr_flip_enable : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_ISP_DGEN_CONF_WR_CFG_UNION;
#endif
#define SOC_ISP_DGEN_CONF_WR_CFG_conf_wr_stride_START (16)
#define SOC_ISP_DGEN_CONF_WR_CFG_conf_wr_stride_END (25)
#define SOC_ISP_DGEN_CONF_WR_CFG_conf_wr_flip_enable_START (30)
#define SOC_ISP_DGEN_CONF_WR_CFG_conf_wr_flip_enable_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int conf_wr_first_32k_page : 17;
    } reg;
} SOC_ISP_DGEN_CONF_WR_FIRST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DGEN_CONF_WR_FIRST_32K_PAGE_conf_wr_first_32k_page_START (15)
#define SOC_ISP_DGEN_CONF_WR_FIRST_32K_PAGE_conf_wr_first_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int conf_wr_last_32k_page : 17;
    } reg;
} SOC_ISP_DGEN_CONF_WR_LAST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DGEN_CONF_WR_LAST_32K_PAGE_conf_wr_last_32k_page_START (15)
#define SOC_ISP_DGEN_CONF_WR_LAST_32K_PAGE_conf_wr_last_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int conf_wr_prefetch_delay : 11;
        unsigned int reserved : 20;
        unsigned int conf_wr_prefetch_enable : 1;
    } reg;
} SOC_ISP_DGEN_CONF_WR_PREFETCH_CFG_UNION;
#endif
#define SOC_ISP_DGEN_CONF_WR_PREFETCH_CFG_conf_wr_prefetch_delay_START (0)
#define SOC_ISP_DGEN_CONF_WR_PREFETCH_CFG_conf_wr_prefetch_delay_END (10)
#define SOC_ISP_DGEN_CONF_WR_PREFETCH_CFG_conf_wr_prefetch_enable_START (31)
#define SOC_ISP_DGEN_CONF_WR_PREFETCH_CFG_conf_wr_prefetch_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int working_wr_first_32k_page : 17;
    } reg;
} SOC_ISP_DGEN_WORKING_WR_RIRST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_WR_RIRST_32K_PAGE_working_wr_first_32k_page_START (15)
#define SOC_ISP_DGEN_WORKING_WR_RIRST_32K_PAGE_working_wr_first_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int working_wr_last_32k_page : 17;
    } reg;
} SOC_ISP_DGEN_WORKING_WR_LAST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_WR_LAST_32K_PAGE_working_wr_last_32k_page_START (15)
#define SOC_ISP_DGEN_WORKING_WR_LAST_32K_PAGE_working_wr_last_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int working_wr_line_stride : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_ISP_DGEN_WORKING_WR_STRIDE_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_WR_STRIDE_working_wr_line_stride_START (0)
#define SOC_ISP_DGEN_WORKING_WR_STRIDE_working_wr_line_stride_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int working_wr_prefetch_delay : 11;
        unsigned int reserved : 20;
        unsigned int working_wr_prefetch_enable : 1;
    } reg;
} SOC_ISP_DGEN_WORKING_WR_PREFETCH_CFG_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_WR_PREFETCH_CFG_working_wr_prefetch_delay_START (0)
#define SOC_ISP_DGEN_WORKING_WR_PREFETCH_CFG_working_wr_prefetch_delay_END (10)
#define SOC_ISP_DGEN_WORKING_WR_PREFETCH_CFG_working_wr_prefetch_enable_START (31)
#define SOC_ISP_DGEN_WORKING_WR_PREFETCH_CFG_working_wr_prefetch_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int working_rd_first_32k_page : 17;
    } reg;
} SOC_ISP_DGEN_WORKING_RD_FIRST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_RD_FIRST_32K_PAGE_working_rd_first_32k_page_START (15)
#define SOC_ISP_DGEN_WORKING_RD_FIRST_32K_PAGE_working_rd_first_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int working_rd_last_32k_page : 17;
    } reg;
} SOC_ISP_DGEN_WORKING_RD_LAST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_RD_LAST_32K_PAGE_working_rd_last_32k_page_START (15)
#define SOC_ISP_DGEN_WORKING_RD_LAST_32K_PAGE_working_rd_last_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int working_rd_line_stride : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_ISP_DGEN_WORKING_RD_STRIDE_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_RD_STRIDE_working_rd_line_stride_START (0)
#define SOC_ISP_DGEN_WORKING_RD_STRIDE_working_rd_line_stride_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int working_rd_prefetch_delay : 11;
        unsigned int reserved : 20;
        unsigned int working_rd_prefetch_enable : 1;
    } reg;
} SOC_ISP_DGEN_WORKING_RD_PREFETCH_CFG_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_RD_PREFETCH_CFG_working_rd_prefetch_delay_START (0)
#define SOC_ISP_DGEN_WORKING_RD_PREFETCH_CFG_working_rd_prefetch_delay_END (10)
#define SOC_ISP_DGEN_WORKING_RD_PREFETCH_CFG_working_rd_prefetch_enable_START (31)
#define SOC_ISP_DGEN_WORKING_RD_PREFETCH_CFG_working_rd_prefetch_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int left_rd_first_vertical_position : 11;
        unsigned int reserved_0 : 5;
        unsigned int left_rd_first_horizontal_position : 7;
        unsigned int reserved_1 : 6;
        unsigned int left_rd_first_horizontal_subpos : 3;
    } reg;
} SOC_ISP_DGEN_LEFT_RD_FIRST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_LEFT_RD_FIRST_BLOCK_CFG_left_rd_first_vertical_position_START (0)
#define SOC_ISP_DGEN_LEFT_RD_FIRST_BLOCK_CFG_left_rd_first_vertical_position_END (10)
#define SOC_ISP_DGEN_LEFT_RD_FIRST_BLOCK_CFG_left_rd_first_horizontal_position_START (16)
#define SOC_ISP_DGEN_LEFT_RD_FIRST_BLOCK_CFG_left_rd_first_horizontal_position_END (22)
#define SOC_ISP_DGEN_LEFT_RD_FIRST_BLOCK_CFG_left_rd_first_horizontal_subpos_START (29)
#define SOC_ISP_DGEN_LEFT_RD_FIRST_BLOCK_CFG_left_rd_first_horizontal_subpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int left_rd_last_vertical_position : 11;
        unsigned int reserved_0 : 5;
        unsigned int left_rd_last_horizontal_position : 7;
        unsigned int reserved_1 : 6;
        unsigned int left_rd_last_horizontal_subpos : 3;
    } reg;
} SOC_ISP_DGEN_LEFT_RD_LAST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_LEFT_RD_LAST_BLOCK_CFG_left_rd_last_vertical_position_START (0)
#define SOC_ISP_DGEN_LEFT_RD_LAST_BLOCK_CFG_left_rd_last_vertical_position_END (10)
#define SOC_ISP_DGEN_LEFT_RD_LAST_BLOCK_CFG_left_rd_last_horizontal_position_START (16)
#define SOC_ISP_DGEN_LEFT_RD_LAST_BLOCK_CFG_left_rd_last_horizontal_position_END (22)
#define SOC_ISP_DGEN_LEFT_RD_LAST_BLOCK_CFG_left_rd_last_horizontal_subpos_START (29)
#define SOC_ISP_DGEN_LEFT_RD_LAST_BLOCK_CFG_left_rd_last_horizontal_subpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int left_rd_ihleft : 13;
        unsigned int reserved_0 : 3;
        unsigned int left_rd_ihright : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_DGEN_LEFT_RD_CROP_H_UNION;
#endif
#define SOC_ISP_DGEN_LEFT_RD_CROP_H_left_rd_ihleft_START (0)
#define SOC_ISP_DGEN_LEFT_RD_CROP_H_left_rd_ihleft_END (12)
#define SOC_ISP_DGEN_LEFT_RD_CROP_H_left_rd_ihright_START (16)
#define SOC_ISP_DGEN_LEFT_RD_CROP_H_left_rd_ihright_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int right_rd_first_vertical_position : 11;
        unsigned int reserved_0 : 5;
        unsigned int right_rd_first_horizontal_position : 7;
        unsigned int reserved_1 : 6;
        unsigned int right_rd_first_horizontal_subpos : 3;
    } reg;
} SOC_ISP_DGEN_RIGHT_RD_FIRST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_RIGHT_RD_FIRST_BLOCK_CFG_right_rd_first_vertical_position_START (0)
#define SOC_ISP_DGEN_RIGHT_RD_FIRST_BLOCK_CFG_right_rd_first_vertical_position_END (10)
#define SOC_ISP_DGEN_RIGHT_RD_FIRST_BLOCK_CFG_right_rd_first_horizontal_position_START (16)
#define SOC_ISP_DGEN_RIGHT_RD_FIRST_BLOCK_CFG_right_rd_first_horizontal_position_END (22)
#define SOC_ISP_DGEN_RIGHT_RD_FIRST_BLOCK_CFG_right_rd_first_horizontal_subpos_START (29)
#define SOC_ISP_DGEN_RIGHT_RD_FIRST_BLOCK_CFG_right_rd_first_horizontal_subpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int right_rd_last_vertical_position : 11;
        unsigned int reserved_0 : 5;
        unsigned int right_rd_last_horizontal_position : 7;
        unsigned int reserved_1 : 6;
        unsigned int right_rd_last_horizontal_subpos : 3;
    } reg;
} SOC_ISP_DGEN_RIGHT_RD_LAST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_RIGHT_RD_LAST_BLOCK_CFG_right_rd_last_vertical_position_START (0)
#define SOC_ISP_DGEN_RIGHT_RD_LAST_BLOCK_CFG_right_rd_last_vertical_position_END (10)
#define SOC_ISP_DGEN_RIGHT_RD_LAST_BLOCK_CFG_right_rd_last_horizontal_position_START (16)
#define SOC_ISP_DGEN_RIGHT_RD_LAST_BLOCK_CFG_right_rd_last_horizontal_position_END (22)
#define SOC_ISP_DGEN_RIGHT_RD_LAST_BLOCK_CFG_right_rd_last_horizontal_subpos_START (29)
#define SOC_ISP_DGEN_RIGHT_RD_LAST_BLOCK_CFG_right_rd_last_horizontal_subpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int right_rd_ihleft : 13;
        unsigned int reserved_0 : 3;
        unsigned int right_rd_ihright : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_DGEN_RIGHT_RD_CROP_H_UNION;
#endif
#define SOC_ISP_DGEN_RIGHT_RD_CROP_H_right_rd_ihleft_START (0)
#define SOC_ISP_DGEN_RIGHT_RD_CROP_H_right_rd_ihleft_END (12)
#define SOC_ISP_DGEN_RIGHT_RD_CROP_H_right_rd_ihright_START (16)
#define SOC_ISP_DGEN_RIGHT_RD_CROP_H_right_rd_ihright_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int working_wr_first_vertical_position : 11;
        unsigned int reserved_0 : 5;
        unsigned int working_wr_first_horizontal_position : 7;
        unsigned int reserved_1 : 6;
        unsigned int working_wr_first_horizontal_subpos : 3;
    } reg;
} SOC_ISP_DGEN_WORKING_WR_FIRST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_WR_FIRST_BLOCK_CFG_working_wr_first_vertical_position_START (0)
#define SOC_ISP_DGEN_WORKING_WR_FIRST_BLOCK_CFG_working_wr_first_vertical_position_END (10)
#define SOC_ISP_DGEN_WORKING_WR_FIRST_BLOCK_CFG_working_wr_first_horizontal_position_START (16)
#define SOC_ISP_DGEN_WORKING_WR_FIRST_BLOCK_CFG_working_wr_first_horizontal_position_END (22)
#define SOC_ISP_DGEN_WORKING_WR_FIRST_BLOCK_CFG_working_wr_first_horizontal_subpos_START (29)
#define SOC_ISP_DGEN_WORKING_WR_FIRST_BLOCK_CFG_working_wr_first_horizontal_subpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int working_wr_last_vertical_position : 11;
        unsigned int reserved_0 : 5;
        unsigned int working_wr_last_horizontal_position : 7;
        unsigned int reserved_1 : 6;
        unsigned int working_wr_last_horizontal_subpos : 3;
    } reg;
} SOC_ISP_DGEN_WORKING_WR_LAST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_WR_LAST_BLOCK_CFG_working_wr_last_vertical_position_START (0)
#define SOC_ISP_DGEN_WORKING_WR_LAST_BLOCK_CFG_working_wr_last_vertical_position_END (10)
#define SOC_ISP_DGEN_WORKING_WR_LAST_BLOCK_CFG_working_wr_last_horizontal_position_START (16)
#define SOC_ISP_DGEN_WORKING_WR_LAST_BLOCK_CFG_working_wr_last_horizontal_position_END (22)
#define SOC_ISP_DGEN_WORKING_WR_LAST_BLOCK_CFG_working_wr_last_horizontal_subpos_START (29)
#define SOC_ISP_DGEN_WORKING_WR_LAST_BLOCK_CFG_working_wr_last_horizontal_subpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int working_wr_ihleft : 13;
        unsigned int reserved_0 : 3;
        unsigned int working_wr_ihright : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_DGEN_WORKING_WR_CROP_H_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_WR_CROP_H_working_wr_ihleft_START (0)
#define SOC_ISP_DGEN_WORKING_WR_CROP_H_working_wr_ihleft_END (12)
#define SOC_ISP_DGEN_WORKING_WR_CROP_H_working_wr_ihright_START (16)
#define SOC_ISP_DGEN_WORKING_WR_CROP_H_working_wr_ihright_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int working_rd_first_vertical_position : 11;
        unsigned int reserved_0 : 5;
        unsigned int working_rd_first_horizontal_position : 7;
        unsigned int reserved_1 : 6;
        unsigned int working_rd_first_horizontal_subpos : 3;
    } reg;
} SOC_ISP_DGEN_WORKING_RD_FIRST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_RD_FIRST_BLOCK_CFG_working_rd_first_vertical_position_START (0)
#define SOC_ISP_DGEN_WORKING_RD_FIRST_BLOCK_CFG_working_rd_first_vertical_position_END (10)
#define SOC_ISP_DGEN_WORKING_RD_FIRST_BLOCK_CFG_working_rd_first_horizontal_position_START (16)
#define SOC_ISP_DGEN_WORKING_RD_FIRST_BLOCK_CFG_working_rd_first_horizontal_position_END (22)
#define SOC_ISP_DGEN_WORKING_RD_FIRST_BLOCK_CFG_working_rd_first_horizontal_subpos_START (29)
#define SOC_ISP_DGEN_WORKING_RD_FIRST_BLOCK_CFG_working_rd_first_horizontal_subpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int working_rd_last_vertical_position : 11;
        unsigned int reserved_0 : 5;
        unsigned int working_rd_last_horizontal_position : 7;
        unsigned int reserved_1 : 6;
        unsigned int working_rd_last_horizontal_subpos : 3;
    } reg;
} SOC_ISP_DGEN_WORKING_RD_LAST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_RD_LAST_BLOCK_CFG_working_rd_last_vertical_position_START (0)
#define SOC_ISP_DGEN_WORKING_RD_LAST_BLOCK_CFG_working_rd_last_vertical_position_END (10)
#define SOC_ISP_DGEN_WORKING_RD_LAST_BLOCK_CFG_working_rd_last_horizontal_position_START (16)
#define SOC_ISP_DGEN_WORKING_RD_LAST_BLOCK_CFG_working_rd_last_horizontal_position_END (22)
#define SOC_ISP_DGEN_WORKING_RD_LAST_BLOCK_CFG_working_rd_last_horizontal_subpos_START (29)
#define SOC_ISP_DGEN_WORKING_RD_LAST_BLOCK_CFG_working_rd_last_horizontal_subpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int working_rd_ihleft : 13;
        unsigned int reserved_0 : 3;
        unsigned int working_rd_ihright : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_DGEN_WORKING_RD_CROP_H_UNION;
#endif
#define SOC_ISP_DGEN_WORKING_RD_CROP_H_working_rd_ihleft_START (0)
#define SOC_ISP_DGEN_WORKING_RD_CROP_H_working_rd_ihleft_END (12)
#define SOC_ISP_DGEN_WORKING_RD_CROP_H_working_rd_ihright_START (16)
#define SOC_ISP_DGEN_WORKING_RD_CROP_H_working_rd_ihright_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int disp_wr_first_vertical_position : 10;
        unsigned int reserved_0 : 6;
        unsigned int disp_wr_first_horizontal_position : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_DGEN_DISP_WR_FIRST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_DISP_WR_FIRST_BLOCK_CFG_disp_wr_first_vertical_position_START (0)
#define SOC_ISP_DGEN_DISP_WR_FIRST_BLOCK_CFG_disp_wr_first_vertical_position_END (9)
#define SOC_ISP_DGEN_DISP_WR_FIRST_BLOCK_CFG_disp_wr_first_horizontal_position_START (16)
#define SOC_ISP_DGEN_DISP_WR_FIRST_BLOCK_CFG_disp_wr_first_horizontal_position_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int disp_wr_last_vertical_position : 10;
        unsigned int reserved_0 : 6;
        unsigned int disp_wr_last_horizontal_position : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_DGEN_DISP_WR_LAST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_DISP_WR_LAST_BLOCK_CFG_disp_wr_last_vertical_position_START (0)
#define SOC_ISP_DGEN_DISP_WR_LAST_BLOCK_CFG_disp_wr_last_vertical_position_END (9)
#define SOC_ISP_DGEN_DISP_WR_LAST_BLOCK_CFG_disp_wr_last_horizontal_position_START (16)
#define SOC_ISP_DGEN_DISP_WR_LAST_BLOCK_CFG_disp_wr_last_horizontal_position_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int conf_wr_first_vertical_position : 10;
        unsigned int reserved_0 : 6;
        unsigned int conf_wr_first_horizontal_position : 7;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_ISP_DGEN_CONF_WR_FIRST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_CONF_WR_FIRST_BLOCK_CFG_conf_wr_first_vertical_position_START (0)
#define SOC_ISP_DGEN_CONF_WR_FIRST_BLOCK_CFG_conf_wr_first_vertical_position_END (9)
#define SOC_ISP_DGEN_CONF_WR_FIRST_BLOCK_CFG_conf_wr_first_horizontal_position_START (16)
#define SOC_ISP_DGEN_CONF_WR_FIRST_BLOCK_CFG_conf_wr_first_horizontal_position_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int conf_wr_last_vertical_position : 10;
        unsigned int reserved_0 : 6;
        unsigned int conf_wr_last_horizontal_position : 7;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_ISP_DGEN_CONF_WR_LAST_BLOCK_CFG_UNION;
#endif
#define SOC_ISP_DGEN_CONF_WR_LAST_BLOCK_CFG_conf_wr_last_vertical_position_START (0)
#define SOC_ISP_DGEN_CONF_WR_LAST_BLOCK_CFG_conf_wr_last_vertical_position_END (9)
#define SOC_ISP_DGEN_CONF_WR_LAST_BLOCK_CFG_conf_wr_last_horizontal_position_START (16)
#define SOC_ISP_DGEN_CONF_WR_LAST_BLOCK_CFG_conf_wr_last_horizontal_position_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug0 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG0_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG0_debug0_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG0_debug0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug1 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG1_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG1_debug1_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG1_debug1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug2 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG2_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG2_debug2_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG2_debug2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug3 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG3_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG3_debug3_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG3_debug3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug4 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG4_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG4_debug4_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG4_debug4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug5 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG5_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG5_debug5_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG5_debug5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug6 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG6_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG6_debug6_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG6_debug6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug7 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG7_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG7_debug7_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG7_debug7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug8 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG8_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG8_debug8_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG8_debug8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug9 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG9_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG9_debug9_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG9_debug9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug10 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG10_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG10_debug10_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG10_debug10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug11 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG11_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG11_debug11_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG11_debug11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug12 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG12_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG12_debug12_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG12_debug12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug13 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DRBR_DBG13_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DRBR_DBG13_debug13_START (0)
#define SOC_ISP_DGEN_DGEN_DRBR_DBG13_debug13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug14 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_CORE_DBG0_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CORE_DBG0_debug14_START (0)
#define SOC_ISP_DGEN_DGEN_CORE_DBG0_debug14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug15 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_CORE_DBG1_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CORE_DBG1_debug15_START (0)
#define SOC_ISP_DGEN_DGEN_CORE_DBG1_debug15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug16 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_CORE_DBG2_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CORE_DBG2_debug16_START (0)
#define SOC_ISP_DGEN_DGEN_CORE_DBG2_debug16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug17 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_CORE_DBG3_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CORE_DBG3_debug17_START (0)
#define SOC_ISP_DGEN_DGEN_CORE_DBG3_debug17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug18 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_CORE_DBG4_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CORE_DBG4_debug18_START (0)
#define SOC_ISP_DGEN_DGEN_CORE_DBG4_debug18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug19 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_CORE_DBG5_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_CORE_DBG5_debug19_START (0)
#define SOC_ISP_DGEN_DGEN_CORE_DBG5_debug19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_rw_001 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DEUBUG_RW_001_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DEUBUG_RW_001_debug_rw_001_START (0)
#define SOC_ISP_DGEN_DGEN_DEUBUG_RW_001_debug_rw_001_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_rw_002 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DEUBUG_RW_002_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DEUBUG_RW_002_debug_rw_002_START (0)
#define SOC_ISP_DGEN_DGEN_DEUBUG_RW_002_debug_rw_002_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_rw_003 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DEUBUG_RW_003_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DEUBUG_RW_003_debug_rw_003_START (0)
#define SOC_ISP_DGEN_DGEN_DEUBUG_RW_003_debug_rw_003_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_rw_004 : 32;
    } reg;
} SOC_ISP_DGEN_DGEN_DEUBUG_RW_004_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DEUBUG_RW_004_debug_rw_004_START (0)
#define SOC_ISP_DGEN_DGEN_DEUBUG_RW_004_debug_rw_004_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int disp_histogram : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_ISP_DGEN_DGEN_DISP_HIST_UNION;
#endif
#define SOC_ISP_DGEN_DGEN_DISP_HIST_disp_histogram_START (0)
#define SOC_ISP_DGEN_DGEN_DISP_HIST_disp_histogram_END (20)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

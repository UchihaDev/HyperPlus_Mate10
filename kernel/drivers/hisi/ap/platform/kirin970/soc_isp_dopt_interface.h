#ifndef __SOC_ISP_DOPT_INTERFACE_H__
#define __SOC_ISP_DOPT_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_DOPT_DOPT_ID_ADDR(base) ((base) + (0x0))
#define SOC_ISP_DOPT_DOPT_VERSION_ADDR(base) ((base) + (0x4))
#define SOC_ISP_DOPT_DOPT_FORCE_CLK_ON_CFG_ADDR(base) ((base) + (0x20))
#define SOC_ISP_DOPT_DOPT_EN_ADDR(base) ((base) + (0x30))
#define SOC_ISP_DOPT_DOPT_CFG_ADDR(base) ((base) + (0x34))
#define SOC_ISP_DOPT_DOPT_CFG_STEP_ADDR(base,Range11) ((base) + (0x38+0x4*(Range11)))
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_1_ADDR(base) ((base) + (0x70))
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_2_ADDR(base) ((base) + (0x74))
#define SOC_ISP_DOPT_DFIL_SEARCH_RANGE_ADDR(base) ((base) + (0x78))
#define SOC_ISP_DOPT_DFIL_THRESHOLD_ADDR(base) ((base) + (0x7C))
#define SOC_ISP_DOPT_DOPT_DEFAULT_ADDR(base) ((base) + (0x80))
#define SOC_ISP_DOPT_DSMT_CFG_ADDR(base) ((base) + (0x84))
#define SOC_ISP_DOPT_DSMT_LUT_ADDR(base,Range9) ((base) + (0x88+0x4*(Range9)))
#define SOC_ISP_DOPT_DSMT_SIGMA_ADDR(base) ((base) + (0xB0))
#define SOC_ISP_DOPT_DSMT_GAUSS_ADDR(base) ((base) + (0xB4))
#define SOC_ISP_DOPT_DREF_CFG_ADDR(base) ((base) + (0xC0))
#define SOC_ISP_DOPT_DREF_LUT_ADDR(base,Range64) ((base) + (0x100+0x4*(Range64)))
#define SOC_ISP_DOPT_DMAP_BUFA_FIRST_32K_PAGE_ADDR(base) ((base) + (0x210))
#define SOC_ISP_DOPT_DMAP_BUFA_LAST_32K_PAGE_ADDR(base) ((base) + (0x214))
#define SOC_ISP_DOPT_DMAP_BUFA_PREFETCH_CFG_ADDR(base) ((base) + (0x218))
#define SOC_ISP_DOPT_DMAP_FIRST_CROP_H_ADDR(base) ((base) + (0x220))
#define SOC_ISP_DOPT_DMAP_FIRST_CROP_V_ADDR(base) ((base) + (0x224))
#define SOC_ISP_DOPT_DMAP_BUFB_FIRST_32K_PAGE_ADDR(base) ((base) + (0x250))
#define SOC_ISP_DOPT_DMAP_BUFB_LAST_32K_PAGE_ADDR(base) ((base) + (0x254))
#define SOC_ISP_DOPT_DMAP_BUFB_PREFETCH_CFG_ADDR(base) ((base) + (0x25C))
#define SOC_ISP_DOPT_DEBUG_VP_0_ADDR(base) ((base) + (0x268))
#define SOC_ISP_DOPT_DEBUG_VP_1_ADDR(base) ((base) + (0x26C))
#define SOC_ISP_DOPT_DEBUG_VP_2_ADDR(base) ((base) + (0x270))
#define SOC_ISP_DOPT_DEBUG_NR_WR_ADDR(base) ((base) + (0x274))
#define SOC_ISP_DOPT_DEBUG_NR_RD_ADDR(base) ((base) + (0x278))
#define SOC_ISP_DOPT_DEBUG_PREFETCH_0_ADDR(base) ((base) + (0x27C))
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_ADDR(base) ((base) + (0x280))
#define SOC_ISP_DOPT_DEBUG_CUR_IMG_POS_ADDR(base) ((base) + (0x284))
#define SOC_ISP_DOPT_DEBUG_MEDFILTER_POS_ADDR(base) ((base) + (0x288))
#define SOC_ISP_DOPT_DEBUG_NFIL_POS_ADDR(base) ((base) + (0x28C))
#define SOC_ISP_DOPT_DEBUG_DCHECK_Y_POS_ADDR(base) ((base) + (0x290))
#define SOC_ISP_DOPT_DEBUG_PRE_IMG_POS_ADDR(base) ((base) + (0x294))
#define SOC_ISP_DOPT_DEBUG_STATE_ADDR(base) ((base) + (0x298))
#define SOC_ISP_DOPT_DEBUG_DRBR_B2R_0_ADDR(base) ((base) + (0x2A0))
#define SOC_ISP_DOPT_DEBUG_DRBR_B2R_1_ADDR(base) ((base) + (0x2A4))
#define SOC_ISP_DOPT_DEBUG_DRBR_B2R_2_ADDR(base) ((base) + (0x2A8))
#define SOC_ISP_DOPT_DEBUG_DRBR_B2R_3_ADDR(base) ((base) + (0x2AC))
#define SOC_ISP_DOPT_DEBUG_DRBR_R2B_0_ADDR(base) ((base) + (0x2B0))
#define SOC_ISP_DOPT_DEBUG_DRBR_R2B_1_ADDR(base) ((base) + (0x2B4))
#define SOC_ISP_DOPT_DEBUG_DRBR_R2B_2_ADDR(base) ((base) + (0x2B8))
#define SOC_ISP_DOPT_DEBUG_DRBR_R2B_3_ADDR(base) ((base) + (0x2BC))
#define SOC_ISP_DOPT_DEBUG_RW_0_ADDR(base) ((base) + (0x2D0))
#define SOC_ISP_DOPT_DEBUG_RW_1_ADDR(base) ((base) + (0x2D4))
#define SOC_ISP_DOPT_DISP_HIST_ADDR(base,Range8) ((base) + (0x300+0x4*(Range8)))
#define SOC_ISP_DOPT_DEPTH_C_ADDR(base) ((base) + (0x320))
#define SOC_ISP_DOPT_DEPTH_CFG_ADDR(base) ((base) + (0x324))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dopt_ip_id : 32;
    } reg;
} SOC_ISP_DOPT_DOPT_ID_UNION;
#endif
#define SOC_ISP_DOPT_DOPT_ID_dopt_ip_id_START (0)
#define SOC_ISP_DOPT_DOPT_ID_dopt_ip_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dopt_ip_version : 32;
    } reg;
} SOC_ISP_DOPT_DOPT_VERSION_UNION;
#endif
#define SOC_ISP_DOPT_DOPT_VERSION_dopt_ip_version_START (0)
#define SOC_ISP_DOPT_DOPT_VERSION_dopt_ip_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_clk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_DOPT_DOPT_FORCE_CLK_ON_CFG_UNION;
#endif
#define SOC_ISP_DOPT_DOPT_FORCE_CLK_ON_CFG_force_clk_on_START (0)
#define SOC_ISP_DOPT_DOPT_FORCE_CLK_ON_CFG_force_clk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 31;
        unsigned int dopt_en : 1;
    } reg;
} SOC_ISP_DOPT_DOPT_EN_UNION;
#endif
#define SOC_ISP_DOPT_DOPT_EN_dopt_en_START (31)
#define SOC_ISP_DOPT_DOPT_EN_dopt_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int frame_height : 10;
        unsigned int reserved_0 : 2;
        unsigned int line_width : 11;
        unsigned int reserved_1 : 3;
        unsigned int disparity_format : 1;
        unsigned int dopt_scrambler_ddr_channels : 1;
        unsigned int dopt_scrambler_ddr_granularity : 3;
        unsigned int image_format : 1;
    } reg;
} SOC_ISP_DOPT_DOPT_CFG_UNION;
#endif
#define SOC_ISP_DOPT_DOPT_CFG_frame_height_START (0)
#define SOC_ISP_DOPT_DOPT_CFG_frame_height_END (9)
#define SOC_ISP_DOPT_DOPT_CFG_line_width_START (12)
#define SOC_ISP_DOPT_DOPT_CFG_line_width_END (22)
#define SOC_ISP_DOPT_DOPT_CFG_disparity_format_START (26)
#define SOC_ISP_DOPT_DOPT_CFG_disparity_format_END (26)
#define SOC_ISP_DOPT_DOPT_CFG_dopt_scrambler_ddr_channels_START (27)
#define SOC_ISP_DOPT_DOPT_CFG_dopt_scrambler_ddr_channels_END (27)
#define SOC_ISP_DOPT_DOPT_CFG_dopt_scrambler_ddr_granularity_START (28)
#define SOC_ISP_DOPT_DOPT_CFG_dopt_scrambler_ddr_granularity_END (30)
#define SOC_ISP_DOPT_DOPT_CFG_image_format_START (31)
#define SOC_ISP_DOPT_DOPT_CFG_image_format_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int last_step : 1;
        unsigned int wr_mode : 2;
        unsigned int nr_wr_data_type : 2;
        unsigned int nr_wr_buf_sel : 1;
        unsigned int rd_mode : 1;
        unsigned int nr_rd_data_type : 2;
        unsigned int nr_rd_buf_sel : 1;
        unsigned int disparity_raster_sel : 1;
        unsigned int disparity_hv_mode : 1;
        unsigned int depth_out_en : 1;
        unsigned int dref_en : 1;
        unsigned int dsmt_en : 1;
        unsigned int dsmt_double_chech_invaliddata : 1;
        unsigned int block_search_en : 1;
        unsigned int dfil_en : 1;
        unsigned int hist_filter_en : 1;
        unsigned int refire_out : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_ISP_DOPT_DOPT_CFG_STEP_UNION;
#endif
#define SOC_ISP_DOPT_DOPT_CFG_STEP_last_step_START (0)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_last_step_END (0)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_wr_mode_START (1)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_wr_mode_END (2)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_nr_wr_data_type_START (3)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_nr_wr_data_type_END (4)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_nr_wr_buf_sel_START (5)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_nr_wr_buf_sel_END (5)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_rd_mode_START (6)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_rd_mode_END (6)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_nr_rd_data_type_START (7)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_nr_rd_data_type_END (8)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_nr_rd_buf_sel_START (9)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_nr_rd_buf_sel_END (9)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_disparity_raster_sel_START (10)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_disparity_raster_sel_END (10)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_disparity_hv_mode_START (11)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_disparity_hv_mode_END (11)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_depth_out_en_START (12)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_depth_out_en_END (12)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_dref_en_START (13)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_dref_en_END (13)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_dsmt_en_START (14)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_dsmt_en_END (14)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_dsmt_double_chech_invaliddata_START (15)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_dsmt_double_chech_invaliddata_END (15)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_block_search_en_START (16)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_block_search_en_END (16)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_dfil_en_START (17)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_dfil_en_END (17)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_hist_filter_en_START (18)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_hist_filter_en_END (18)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_refire_out_START (19)
#define SOC_ISP_DOPT_DOPT_CFG_STEP_refire_out_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int last_vertical_position_8bits : 7;
        unsigned int reserved_0 : 1;
        unsigned int last_horizontal_position_8bits : 7;
        unsigned int reserved_1 : 1;
        unsigned int last_vertical_position_10bits : 7;
        unsigned int reserved_2 : 1;
        unsigned int last_horizontal_position_10bits : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_1_UNION;
#endif
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_1_last_vertical_position_8bits_START (0)
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_1_last_vertical_position_8bits_END (6)
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_1_last_horizontal_position_8bits_START (8)
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_1_last_horizontal_position_8bits_END (14)
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_1_last_vertical_position_10bits_START (16)
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_1_last_vertical_position_10bits_END (22)
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_1_last_horizontal_position_10bits_START (24)
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_1_last_horizontal_position_10bits_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int last_vertical_position_16bits : 7;
        unsigned int reserved_0 : 1;
        unsigned int last_horizontal_position_16bits : 7;
        unsigned int reserved_1 : 17;
    } reg;
} SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_2_UNION;
#endif
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_2_last_vertical_position_16bits_START (0)
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_2_last_vertical_position_16bits_END (6)
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_2_last_horizontal_position_16bits_START (8)
#define SOC_ISP_DOPT_DRBR_LAST_BLOCK_CFG_2_last_horizontal_position_16bits_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfil_vertical_search_range : 11;
        unsigned int reserved_0 : 5;
        unsigned int dfil_horizontal_search_range : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_ISP_DOPT_DFIL_SEARCH_RANGE_UNION;
#endif
#define SOC_ISP_DOPT_DFIL_SEARCH_RANGE_dfil_vertical_search_range_START (0)
#define SOC_ISP_DOPT_DFIL_SEARCH_RANGE_dfil_vertical_search_range_END (10)
#define SOC_ISP_DOPT_DFIL_SEARCH_RANGE_dfil_horizontal_search_range_START (16)
#define SOC_ISP_DOPT_DFIL_SEARCH_RANGE_dfil_horizontal_search_range_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfil_v_threshold : 8;
        unsigned int dfil_u_threshold : 8;
        unsigned int dfil_y_threshold : 8;
        unsigned int reserved : 5;
        unsigned int dfil_v_enable : 1;
        unsigned int dfil_u_enable : 1;
        unsigned int dfil_y_enable : 1;
    } reg;
} SOC_ISP_DOPT_DFIL_THRESHOLD_UNION;
#endif
#define SOC_ISP_DOPT_DFIL_THRESHOLD_dfil_v_threshold_START (0)
#define SOC_ISP_DOPT_DFIL_THRESHOLD_dfil_v_threshold_END (7)
#define SOC_ISP_DOPT_DFIL_THRESHOLD_dfil_u_threshold_START (8)
#define SOC_ISP_DOPT_DFIL_THRESHOLD_dfil_u_threshold_END (15)
#define SOC_ISP_DOPT_DFIL_THRESHOLD_dfil_y_threshold_START (16)
#define SOC_ISP_DOPT_DFIL_THRESHOLD_dfil_y_threshold_END (23)
#define SOC_ISP_DOPT_DFIL_THRESHOLD_dfil_v_enable_START (29)
#define SOC_ISP_DOPT_DFIL_THRESHOLD_dfil_v_enable_END (29)
#define SOC_ISP_DOPT_DFIL_THRESHOLD_dfil_u_enable_START (30)
#define SOC_ISP_DOPT_DFIL_THRESHOLD_dfil_u_enable_END (30)
#define SOC_ISP_DOPT_DFIL_THRESHOLD_dfil_y_enable_START (31)
#define SOC_ISP_DOPT_DFIL_THRESHOLD_dfil_y_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfil_bs_count_threshold : 6;
        unsigned int reserved_0 : 10;
        unsigned int dopt_disp_default : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_ISP_DOPT_DOPT_DEFAULT_UNION;
#endif
#define SOC_ISP_DOPT_DOPT_DEFAULT_dfil_bs_count_threshold_START (0)
#define SOC_ISP_DOPT_DOPT_DEFAULT_dfil_bs_count_threshold_END (5)
#define SOC_ISP_DOPT_DOPT_DEFAULT_dopt_disp_default_START (16)
#define SOC_ISP_DOPT_DOPT_DEFAULT_dopt_disp_default_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 28;
        unsigned int dsmt_search_block_radius : 2;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_ISP_DOPT_DSMT_CFG_UNION;
#endif
#define SOC_ISP_DOPT_DSMT_CFG_dsmt_search_block_radius_START (28)
#define SOC_ISP_DOPT_DSMT_CFG_dsmt_search_block_radius_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsmt_temporal_smooth_weight_lut : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_DOPT_DSMT_LUT_UNION;
#endif
#define SOC_ISP_DOPT_DSMT_LUT_dsmt_temporal_smooth_weight_lut_START (0)
#define SOC_ISP_DOPT_DSMT_LUT_dsmt_temporal_smooth_weight_lut_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsmt_sigma_square : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ISP_DOPT_DSMT_SIGMA_UNION;
#endif
#define SOC_ISP_DOPT_DSMT_SIGMA_dsmt_sigma_square_START (0)
#define SOC_ISP_DOPT_DSMT_SIGMA_dsmt_sigma_square_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsmt_gauss_fix_value : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_ISP_DOPT_DSMT_GAUSS_UNION;
#endif
#define SOC_ISP_DOPT_DSMT_GAUSS_dsmt_gauss_fix_value_START (0)
#define SOC_ISP_DOPT_DSMT_GAUSS_dsmt_gauss_fix_value_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dref_jbf_jbu_windows : 6;
        unsigned int reserved_0 : 2;
        unsigned int dref_jbf_edge_pixel_numth : 5;
        unsigned int reserved_1 : 3;
        unsigned int dref_jbf_ignore_border_window : 6;
        unsigned int reserved_2 : 2;
        unsigned int dref_jbf_color_edge_graydiffth : 8;
    } reg;
} SOC_ISP_DOPT_DREF_CFG_UNION;
#endif
#define SOC_ISP_DOPT_DREF_CFG_dref_jbf_jbu_windows_START (0)
#define SOC_ISP_DOPT_DREF_CFG_dref_jbf_jbu_windows_END (5)
#define SOC_ISP_DOPT_DREF_CFG_dref_jbf_edge_pixel_numth_START (8)
#define SOC_ISP_DOPT_DREF_CFG_dref_jbf_edge_pixel_numth_END (12)
#define SOC_ISP_DOPT_DREF_CFG_dref_jbf_ignore_border_window_START (16)
#define SOC_ISP_DOPT_DREF_CFG_dref_jbf_ignore_border_window_END (21)
#define SOC_ISP_DOPT_DREF_CFG_dref_jbf_color_edge_graydiffth_START (24)
#define SOC_ISP_DOPT_DREF_CFG_dref_jbf_color_edge_graydiffth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dref_jbf_color_weight_lut : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_DOPT_DREF_LUT_UNION;
#endif
#define SOC_ISP_DOPT_DREF_LUT_dref_jbf_color_weight_lut_START (0)
#define SOC_ISP_DOPT_DREF_LUT_dref_jbf_color_weight_lut_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int dmap_bufa_first_32k_page : 17;
    } reg;
} SOC_ISP_DOPT_DMAP_BUFA_FIRST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DOPT_DMAP_BUFA_FIRST_32K_PAGE_dmap_bufa_first_32k_page_START (15)
#define SOC_ISP_DOPT_DMAP_BUFA_FIRST_32K_PAGE_dmap_bufa_first_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int dmap_bufa_last_32k_page : 17;
    } reg;
} SOC_ISP_DOPT_DMAP_BUFA_LAST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DOPT_DMAP_BUFA_LAST_32K_PAGE_dmap_bufa_last_32k_page_START (15)
#define SOC_ISP_DOPT_DMAP_BUFA_LAST_32K_PAGE_dmap_bufa_last_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmap_bufa_prefetch_delay : 11;
        unsigned int reserved_0 : 5;
        unsigned int dmap_bufa_prefetch_nbr_iid : 4;
        unsigned int reserved_1 : 11;
        unsigned int dmap_bufa_prefetch_enable : 1;
    } reg;
} SOC_ISP_DOPT_DMAP_BUFA_PREFETCH_CFG_UNION;
#endif
#define SOC_ISP_DOPT_DMAP_BUFA_PREFETCH_CFG_dmap_bufa_prefetch_delay_START (0)
#define SOC_ISP_DOPT_DMAP_BUFA_PREFETCH_CFG_dmap_bufa_prefetch_delay_END (10)
#define SOC_ISP_DOPT_DMAP_BUFA_PREFETCH_CFG_dmap_bufa_prefetch_nbr_iid_START (16)
#define SOC_ISP_DOPT_DMAP_BUFA_PREFETCH_CFG_dmap_bufa_prefetch_nbr_iid_END (19)
#define SOC_ISP_DOPT_DMAP_BUFA_PREFETCH_CFG_dmap_bufa_prefetch_enable_START (31)
#define SOC_ISP_DOPT_DMAP_BUFA_PREFETCH_CFG_dmap_bufa_prefetch_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmap_first_ihleft : 13;
        unsigned int reserved_0 : 3;
        unsigned int dmap_first_ihright : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_DOPT_DMAP_FIRST_CROP_H_UNION;
#endif
#define SOC_ISP_DOPT_DMAP_FIRST_CROP_H_dmap_first_ihleft_START (0)
#define SOC_ISP_DOPT_DMAP_FIRST_CROP_H_dmap_first_ihleft_END (12)
#define SOC_ISP_DOPT_DMAP_FIRST_CROP_H_dmap_first_ihright_START (16)
#define SOC_ISP_DOPT_DMAP_FIRST_CROP_H_dmap_first_ihright_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmap_first_ivtop : 13;
        unsigned int reserved_0 : 3;
        unsigned int dmap_first_ivbottom : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_DOPT_DMAP_FIRST_CROP_V_UNION;
#endif
#define SOC_ISP_DOPT_DMAP_FIRST_CROP_V_dmap_first_ivtop_START (0)
#define SOC_ISP_DOPT_DMAP_FIRST_CROP_V_dmap_first_ivtop_END (12)
#define SOC_ISP_DOPT_DMAP_FIRST_CROP_V_dmap_first_ivbottom_START (16)
#define SOC_ISP_DOPT_DMAP_FIRST_CROP_V_dmap_first_ivbottom_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int dmap_bufb_first_32k_page : 17;
    } reg;
} SOC_ISP_DOPT_DMAP_BUFB_FIRST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DOPT_DMAP_BUFB_FIRST_32K_PAGE_dmap_bufb_first_32k_page_START (15)
#define SOC_ISP_DOPT_DMAP_BUFB_FIRST_32K_PAGE_dmap_bufb_first_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int dmap_bufb_last_32k_page : 17;
    } reg;
} SOC_ISP_DOPT_DMAP_BUFB_LAST_32K_PAGE_UNION;
#endif
#define SOC_ISP_DOPT_DMAP_BUFB_LAST_32K_PAGE_dmap_bufb_last_32k_page_START (15)
#define SOC_ISP_DOPT_DMAP_BUFB_LAST_32K_PAGE_dmap_bufb_last_32k_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmap_bufb_prefetch_delay : 11;
        unsigned int reserved_0 : 5;
        unsigned int dmap_bufb_prefetch_nbr_iid : 4;
        unsigned int reserved_1 : 11;
        unsigned int dmap_bufb_prefetch_enable : 1;
    } reg;
} SOC_ISP_DOPT_DMAP_BUFB_PREFETCH_CFG_UNION;
#endif
#define SOC_ISP_DOPT_DMAP_BUFB_PREFETCH_CFG_dmap_bufb_prefetch_delay_START (0)
#define SOC_ISP_DOPT_DMAP_BUFB_PREFETCH_CFG_dmap_bufb_prefetch_delay_END (10)
#define SOC_ISP_DOPT_DMAP_BUFB_PREFETCH_CFG_dmap_bufb_prefetch_nbr_iid_START (16)
#define SOC_ISP_DOPT_DMAP_BUFB_PREFETCH_CFG_dmap_bufb_prefetch_nbr_iid_END (19)
#define SOC_ISP_DOPT_DMAP_BUFB_PREFETCH_CFG_dmap_bufb_prefetch_enable_START (31)
#define SOC_ISP_DOPT_DMAP_BUFB_PREFETCH_CFG_dmap_bufb_prefetch_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_vp_cur_disp_accept : 1;
        unsigned int debug_vp_cur_disp_valid : 1;
        unsigned int debug_vp_cur_disp_h_end : 1;
        unsigned int debug_vp_cur_disp_v_end : 1;
        unsigned int debug_vp_drbr_r2b_accept : 1;
        unsigned int debug_vp_drbr_r2b_valid : 1;
        unsigned int debug_vp_drbr_r2b_h_end : 1;
        unsigned int debug_vp_drbr_r2b_v_end : 1;
        unsigned int debug_vp_drbr_b2r_accept : 1;
        unsigned int debug_vp_drbr_b2r_valid : 1;
        unsigned int debug_vp_drbr_b2r_h_end : 1;
        unsigned int debug_vp_drbr_b2r_v_end : 1;
        unsigned int debug_vp_out1_accept : 1;
        unsigned int debug_vp_out1_valid : 1;
        unsigned int debug_vp_out1_h_end : 1;
        unsigned int debug_vp_out1_v_end : 1;
        unsigned int debug_vp_out0_accept : 1;
        unsigned int debug_vp_out0_valid : 1;
        unsigned int debug_vp_out0_h_end : 1;
        unsigned int debug_vp_out0_v_end : 1;
        unsigned int debug_vp_in2_accept : 1;
        unsigned int debug_vp_in2_valid : 1;
        unsigned int debug_vp_in2_h_end : 1;
        unsigned int debug_vp_in2_v_end : 1;
        unsigned int debug_vp_in1_accept : 1;
        unsigned int debug_vp_in1_valid : 1;
        unsigned int debug_vp_in1_h_end : 1;
        unsigned int debug_vp_in1_v_end : 1;
        unsigned int debug_vp_in0_accept : 1;
        unsigned int debug_vp_in0_valid : 1;
        unsigned int debug_vp_in0_h_end : 1;
        unsigned int debug_vp_in0_v_end : 1;
    } reg;
} SOC_ISP_DOPT_DEBUG_VP_0_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_cur_disp_accept_START (0)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_cur_disp_accept_END (0)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_cur_disp_valid_START (1)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_cur_disp_valid_END (1)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_cur_disp_h_end_START (2)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_cur_disp_h_end_END (2)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_cur_disp_v_end_START (3)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_cur_disp_v_end_END (3)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_r2b_accept_START (4)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_r2b_accept_END (4)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_r2b_valid_START (5)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_r2b_valid_END (5)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_r2b_h_end_START (6)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_r2b_h_end_END (6)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_r2b_v_end_START (7)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_r2b_v_end_END (7)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_b2r_accept_START (8)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_b2r_accept_END (8)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_b2r_valid_START (9)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_b2r_valid_END (9)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_b2r_h_end_START (10)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_b2r_h_end_END (10)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_b2r_v_end_START (11)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_drbr_b2r_v_end_END (11)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out1_accept_START (12)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out1_accept_END (12)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out1_valid_START (13)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out1_valid_END (13)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out1_h_end_START (14)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out1_h_end_END (14)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out1_v_end_START (15)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out1_v_end_END (15)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out0_accept_START (16)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out0_accept_END (16)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out0_valid_START (17)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out0_valid_END (17)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out0_h_end_START (18)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out0_h_end_END (18)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out0_v_end_START (19)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_out0_v_end_END (19)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in2_accept_START (20)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in2_accept_END (20)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in2_valid_START (21)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in2_valid_END (21)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in2_h_end_START (22)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in2_h_end_END (22)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in2_v_end_START (23)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in2_v_end_END (23)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in1_accept_START (24)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in1_accept_END (24)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in1_valid_START (25)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in1_valid_END (25)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in1_h_end_START (26)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in1_h_end_END (26)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in1_v_end_START (27)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in1_v_end_END (27)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in0_accept_START (28)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in0_accept_END (28)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in0_valid_START (29)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in0_valid_END (29)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in0_h_end_START (30)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in0_h_end_END (30)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in0_v_end_START (31)
#define SOC_ISP_DOPT_DEBUG_VP_0_debug_vp_in0_v_end_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_vp_dfil_out_accept : 1;
        unsigned int debug_vp_dfil_out_valid : 1;
        unsigned int debug_vp_dfil_out_h_end : 1;
        unsigned int debug_vp_dfil_out_v_end : 1;
        unsigned int debug_vp_dfil_in_accept : 1;
        unsigned int debug_vp_dfil_in_valid : 1;
        unsigned int debug_vp_dfil_in_h_end : 1;
        unsigned int debug_vp_dfil_in_v_end : 1;
        unsigned int debug_vp_datapre_in_accept : 1;
        unsigned int debug_vp_datapre_in_valid : 1;
        unsigned int debug_vp_datapre_in_h_end : 1;
        unsigned int debug_vp_datapre_in_v_end : 1;
        unsigned int debug_vp_histflt_out_accept : 1;
        unsigned int debug_vp_histflt_out_valid : 1;
        unsigned int debug_vp_histflt_out_h_end : 1;
        unsigned int debug_vp_histflt_out_v_end : 1;
        unsigned int debug_vp_histflt_in_accept : 1;
        unsigned int debug_vp_histflt_in_valid : 1;
        unsigned int debug_vp_histflt_in_h_end : 1;
        unsigned int debug_vp_histflt_in_v_end : 1;
        unsigned int debug_vp_pre_img_accept : 1;
        unsigned int debug_vp_pre_img_valid : 1;
        unsigned int debug_vp_pre_img_h_end : 1;
        unsigned int debug_vp_pre_img_v_end : 1;
        unsigned int debug_vp_cur_img_accept : 1;
        unsigned int debug_vp_cur_img_valid : 1;
        unsigned int debug_vp_cur_img_h_end : 1;
        unsigned int debug_vp_cur_img_v_end : 1;
        unsigned int debug_vp_pre_disp_accept : 1;
        unsigned int debug_vp_pre_disp_valid : 1;
        unsigned int debug_vp_pre_disp_h_end : 1;
        unsigned int debug_vp_pre_disp_v_end : 1;
    } reg;
} SOC_ISP_DOPT_DEBUG_VP_1_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_out_accept_START (0)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_out_accept_END (0)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_out_valid_START (1)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_out_valid_END (1)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_out_h_end_START (2)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_out_h_end_END (2)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_out_v_end_START (3)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_out_v_end_END (3)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_in_accept_START (4)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_in_accept_END (4)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_in_valid_START (5)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_in_valid_END (5)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_in_h_end_START (6)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_in_h_end_END (6)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_in_v_end_START (7)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_dfil_in_v_end_END (7)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_datapre_in_accept_START (8)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_datapre_in_accept_END (8)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_datapre_in_valid_START (9)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_datapre_in_valid_END (9)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_datapre_in_h_end_START (10)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_datapre_in_h_end_END (10)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_datapre_in_v_end_START (11)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_datapre_in_v_end_END (11)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_out_accept_START (12)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_out_accept_END (12)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_out_valid_START (13)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_out_valid_END (13)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_out_h_end_START (14)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_out_h_end_END (14)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_out_v_end_START (15)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_out_v_end_END (15)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_in_accept_START (16)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_in_accept_END (16)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_in_valid_START (17)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_in_valid_END (17)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_in_h_end_START (18)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_in_h_end_END (18)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_in_v_end_START (19)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_histflt_in_v_end_END (19)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_img_accept_START (20)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_img_accept_END (20)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_img_valid_START (21)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_img_valid_END (21)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_img_h_end_START (22)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_img_h_end_END (22)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_img_v_end_START (23)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_img_v_end_END (23)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_cur_img_accept_START (24)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_cur_img_accept_END (24)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_cur_img_valid_START (25)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_cur_img_valid_END (25)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_cur_img_h_end_START (26)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_cur_img_h_end_END (26)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_cur_img_v_end_START (27)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_cur_img_v_end_END (27)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_disp_accept_START (28)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_disp_accept_END (28)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_disp_valid_START (29)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_disp_valid_END (29)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_disp_h_end_START (30)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_disp_h_end_END (30)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_disp_v_end_START (31)
#define SOC_ISP_DOPT_DEBUG_VP_1_debug_vp_pre_disp_v_end_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_vp_depth_out_accept : 1;
        unsigned int debug_vp_depth_out_valid : 1;
        unsigned int debug_vp_depth_out_h_end : 1;
        unsigned int debug_vp_depth_out_v_end : 1;
        unsigned int debug_vp_depth_in_accept : 1;
        unsigned int debug_vp_depth_in_valid : 1;
        unsigned int debug_vp_depth_in_h_end : 1;
        unsigned int debug_vp_depth_in_v_end : 1;
        unsigned int debug_vp_dref2vpwr_accept : 1;
        unsigned int debug_vp_dref2vpwr_valid : 1;
        unsigned int debug_vp_dref2vpwr_h_end : 1;
        unsigned int debug_vp_dref2vpwr_v_end : 1;
        unsigned int debug_vp_histflt2vpwr_accept : 1;
        unsigned int debug_vp_histflt2vpwr_valid : 1;
        unsigned int debug_vp_histflt2vpwr_h_end : 1;
        unsigned int debug_vp_histflt2vpwr_v_end : 1;
        unsigned int debug_vp_dref_out_accept : 1;
        unsigned int debug_vp_dref_out_valid : 1;
        unsigned int debug_vp_dref_out_h_end : 1;
        unsigned int debug_vp_dref_out_v_end : 1;
        unsigned int debug_vp_dsmt_out_accept : 1;
        unsigned int debug_vp_dsmt_out_valid : 1;
        unsigned int debug_vp_dsmt_out_h_end : 1;
        unsigned int debug_vp_dsmt_out_v_end : 1;
        unsigned int debug_vp_dsmt_in_accept : 1;
        unsigned int debug_vp_dsmt_in_valid : 1;
        unsigned int debug_vp_dsmt_in_h_end : 1;
        unsigned int debug_vp_dsmt_in_v_end : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_ISP_DOPT_DEBUG_VP_2_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_out_accept_START (0)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_out_accept_END (0)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_out_valid_START (1)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_out_valid_END (1)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_out_h_end_START (2)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_out_h_end_END (2)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_out_v_end_START (3)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_out_v_end_END (3)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_in_accept_START (4)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_in_accept_END (4)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_in_valid_START (5)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_in_valid_END (5)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_in_h_end_START (6)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_in_h_end_END (6)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_in_v_end_START (7)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_depth_in_v_end_END (7)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref2vpwr_accept_START (8)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref2vpwr_accept_END (8)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref2vpwr_valid_START (9)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref2vpwr_valid_END (9)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref2vpwr_h_end_START (10)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref2vpwr_h_end_END (10)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref2vpwr_v_end_START (11)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref2vpwr_v_end_END (11)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_histflt2vpwr_accept_START (12)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_histflt2vpwr_accept_END (12)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_histflt2vpwr_valid_START (13)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_histflt2vpwr_valid_END (13)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_histflt2vpwr_h_end_START (14)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_histflt2vpwr_h_end_END (14)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_histflt2vpwr_v_end_START (15)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_histflt2vpwr_v_end_END (15)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref_out_accept_START (16)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref_out_accept_END (16)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref_out_valid_START (17)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref_out_valid_END (17)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref_out_h_end_START (18)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref_out_h_end_END (18)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref_out_v_end_START (19)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dref_out_v_end_END (19)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_out_accept_START (20)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_out_accept_END (20)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_out_valid_START (21)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_out_valid_END (21)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_out_h_end_START (22)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_out_h_end_END (22)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_out_v_end_START (23)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_out_v_end_END (23)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_in_accept_START (24)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_in_accept_END (24)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_in_valid_START (25)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_in_valid_END (25)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_in_h_end_START (26)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_in_h_end_END (26)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_in_v_end_START (27)
#define SOC_ISP_DOPT_DEBUG_VP_2_debug_vp_dsmt_in_v_end_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_nr_wr_accept : 1;
        unsigned int debug_nr_wr_mmuack_en : 1;
        unsigned int debug_nr_wr_iid : 8;
        unsigned int debug_nr_wr_sid : 7;
        unsigned int debug_nr_wr_burstsize : 3;
        unsigned int debug_nr_wr_request : 1;
        unsigned int debug_nr_wr_request_done : 1;
        unsigned int debug_nr_wr_last : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_ISP_DOPT_DEBUG_NR_WR_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_accept_START (0)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_accept_END (0)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_mmuack_en_START (1)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_mmuack_en_END (1)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_iid_START (2)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_iid_END (9)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_sid_START (10)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_sid_END (16)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_burstsize_START (17)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_burstsize_END (19)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_request_START (20)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_request_END (20)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_request_done_START (21)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_request_done_END (21)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_last_START (22)
#define SOC_ISP_DOPT_DEBUG_NR_WR_debug_nr_wr_last_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_nr_rd_accept : 1;
        unsigned int debug_nr_rd_mmuack_en : 1;
        unsigned int debug_nr_rd_iid : 8;
        unsigned int debug_nr_rd_sid : 7;
        unsigned int debug_nr_rd_burstsize : 3;
        unsigned int debug_nr_rd_request : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_ISP_DOPT_DEBUG_NR_RD_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_NR_RD_debug_nr_rd_accept_START (0)
#define SOC_ISP_DOPT_DEBUG_NR_RD_debug_nr_rd_accept_END (0)
#define SOC_ISP_DOPT_DEBUG_NR_RD_debug_nr_rd_mmuack_en_START (1)
#define SOC_ISP_DOPT_DEBUG_NR_RD_debug_nr_rd_mmuack_en_END (1)
#define SOC_ISP_DOPT_DEBUG_NR_RD_debug_nr_rd_iid_START (2)
#define SOC_ISP_DOPT_DEBUG_NR_RD_debug_nr_rd_iid_END (9)
#define SOC_ISP_DOPT_DEBUG_NR_RD_debug_nr_rd_sid_START (10)
#define SOC_ISP_DOPT_DEBUG_NR_RD_debug_nr_rd_sid_END (16)
#define SOC_ISP_DOPT_DEBUG_NR_RD_debug_nr_rd_burstsize_START (17)
#define SOC_ISP_DOPT_DEBUG_NR_RD_debug_nr_rd_burstsize_END (19)
#define SOC_ISP_DOPT_DEBUG_NR_RD_debug_nr_rd_request_START (20)
#define SOC_ISP_DOPT_DEBUG_NR_RD_debug_nr_rd_request_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_pref_addr : 17;
        unsigned int debug_pref_iid : 8;
        unsigned int debug_pref_sid : 7;
    } reg;
} SOC_ISP_DOPT_DEBUG_PREFETCH_0_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_PREFETCH_0_debug_pref_addr_START (0)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_0_debug_pref_addr_END (16)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_0_debug_pref_iid_START (17)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_0_debug_pref_iid_END (24)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_0_debug_pref_sid_START (25)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_0_debug_pref_sid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_pref_resp_iid : 8;
        unsigned int debug_pref_resp_sid : 7;
        unsigned int debug_pref_resp_rdy : 1;
        unsigned int debug_pref_resp_vld : 1;
        unsigned int debug_pref_rdy : 1;
        unsigned int debug_pref_vld : 1;
        unsigned int debug_pref_initial : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_ISP_DOPT_DEBUG_PREFETCH_1_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_resp_iid_START (0)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_resp_iid_END (7)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_resp_sid_START (8)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_resp_sid_END (14)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_resp_rdy_START (15)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_resp_rdy_END (15)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_resp_vld_START (16)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_resp_vld_END (16)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_rdy_START (17)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_rdy_END (17)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_vld_START (18)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_vld_END (18)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_initial_START (19)
#define SOC_ISP_DOPT_DEBUG_PREFETCH_1_debug_pref_initial_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_cur_image_v_pos : 11;
        unsigned int reserved_0 : 5;
        unsigned int debug_cur_image_h_pos : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_ISP_DOPT_DEBUG_CUR_IMG_POS_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_CUR_IMG_POS_debug_cur_image_v_pos_START (0)
#define SOC_ISP_DOPT_DEBUG_CUR_IMG_POS_debug_cur_image_v_pos_END (10)
#define SOC_ISP_DOPT_DEBUG_CUR_IMG_POS_debug_cur_image_h_pos_START (16)
#define SOC_ISP_DOPT_DEBUG_CUR_IMG_POS_debug_cur_image_h_pos_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_medfilter_v_pos : 11;
        unsigned int reserved_0 : 5;
        unsigned int debug_medfilter_h_pos : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_ISP_DOPT_DEBUG_MEDFILTER_POS_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_MEDFILTER_POS_debug_medfilter_v_pos_START (0)
#define SOC_ISP_DOPT_DEBUG_MEDFILTER_POS_debug_medfilter_v_pos_END (10)
#define SOC_ISP_DOPT_DEBUG_MEDFILTER_POS_debug_medfilter_h_pos_START (16)
#define SOC_ISP_DOPT_DEBUG_MEDFILTER_POS_debug_medfilter_h_pos_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_nfil_v_pos : 11;
        unsigned int reserved_0 : 5;
        unsigned int debug_nfil_h_pos : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_ISP_DOPT_DEBUG_NFIL_POS_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_NFIL_POS_debug_nfil_v_pos_START (0)
#define SOC_ISP_DOPT_DEBUG_NFIL_POS_debug_nfil_v_pos_END (10)
#define SOC_ISP_DOPT_DEBUG_NFIL_POS_debug_nfil_h_pos_START (16)
#define SOC_ISP_DOPT_DEBUG_NFIL_POS_debug_nfil_h_pos_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_dcheck_y_v_pos : 11;
        unsigned int reserved_0 : 5;
        unsigned int debug_dcheck_y_h_pos : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_ISP_DOPT_DEBUG_DCHECK_Y_POS_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_DCHECK_Y_POS_debug_dcheck_y_v_pos_START (0)
#define SOC_ISP_DOPT_DEBUG_DCHECK_Y_POS_debug_dcheck_y_v_pos_END (10)
#define SOC_ISP_DOPT_DEBUG_DCHECK_Y_POS_debug_dcheck_y_h_pos_START (16)
#define SOC_ISP_DOPT_DEBUG_DCHECK_Y_POS_debug_dcheck_y_h_pos_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_pre_image_v_pos : 11;
        unsigned int reserved_0 : 5;
        unsigned int debug_pre_image_h_pos : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_ISP_DOPT_DEBUG_PRE_IMG_POS_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_PRE_IMG_POS_debug_pre_image_v_pos_START (0)
#define SOC_ISP_DOPT_DEBUG_PRE_IMG_POS_debug_pre_image_v_pos_END (10)
#define SOC_ISP_DOPT_DEBUG_PRE_IMG_POS_debug_pre_image_h_pos_START (16)
#define SOC_ISP_DOPT_DEBUG_PRE_IMG_POS_debug_pre_image_h_pos_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_ctrl_state : 4;
        unsigned int debug_dfil_state : 5;
        unsigned int reserved_0 : 7;
        unsigned int debug_blocksearch_state : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_ISP_DOPT_DEBUG_STATE_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_STATE_debug_ctrl_state_START (0)
#define SOC_ISP_DOPT_DEBUG_STATE_debug_ctrl_state_END (3)
#define SOC_ISP_DOPT_DEBUG_STATE_debug_dfil_state_START (4)
#define SOC_ISP_DOPT_DEBUG_STATE_debug_dfil_state_END (8)
#define SOC_ISP_DOPT_DEBUG_STATE_debug_blocksearch_state_START (16)
#define SOC_ISP_DOPT_DEBUG_STATE_debug_blocksearch_state_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_drbr_b2r_0 : 32;
    } reg;
} SOC_ISP_DOPT_DEBUG_DRBR_B2R_0_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_DRBR_B2R_0_debug_drbr_b2r_0_START (0)
#define SOC_ISP_DOPT_DEBUG_DRBR_B2R_0_debug_drbr_b2r_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_drbr_b2r_1 : 32;
    } reg;
} SOC_ISP_DOPT_DEBUG_DRBR_B2R_1_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_DRBR_B2R_1_debug_drbr_b2r_1_START (0)
#define SOC_ISP_DOPT_DEBUG_DRBR_B2R_1_debug_drbr_b2r_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_drbr_b2r_2 : 32;
    } reg;
} SOC_ISP_DOPT_DEBUG_DRBR_B2R_2_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_DRBR_B2R_2_debug_drbr_b2r_2_START (0)
#define SOC_ISP_DOPT_DEBUG_DRBR_B2R_2_debug_drbr_b2r_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_drbr_b2r_3 : 32;
    } reg;
} SOC_ISP_DOPT_DEBUG_DRBR_B2R_3_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_DRBR_B2R_3_debug_drbr_b2r_3_START (0)
#define SOC_ISP_DOPT_DEBUG_DRBR_B2R_3_debug_drbr_b2r_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_drbr_r2b_0 : 32;
    } reg;
} SOC_ISP_DOPT_DEBUG_DRBR_R2B_0_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_DRBR_R2B_0_debug_drbr_r2b_0_START (0)
#define SOC_ISP_DOPT_DEBUG_DRBR_R2B_0_debug_drbr_r2b_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_drbr_r2b_1 : 32;
    } reg;
} SOC_ISP_DOPT_DEBUG_DRBR_R2B_1_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_DRBR_R2B_1_debug_drbr_r2b_1_START (0)
#define SOC_ISP_DOPT_DEBUG_DRBR_R2B_1_debug_drbr_r2b_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_drbr_r2b_2 : 32;
    } reg;
} SOC_ISP_DOPT_DEBUG_DRBR_R2B_2_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_DRBR_R2B_2_debug_drbr_r2b_2_START (0)
#define SOC_ISP_DOPT_DEBUG_DRBR_R2B_2_debug_drbr_r2b_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_drbr_r2b_3 : 32;
    } reg;
} SOC_ISP_DOPT_DEBUG_DRBR_R2B_3_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_DRBR_R2B_3_debug_drbr_r2b_3_START (0)
#define SOC_ISP_DOPT_DEBUG_DRBR_R2B_3_debug_drbr_r2b_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_rw_0 : 32;
    } reg;
} SOC_ISP_DOPT_DEBUG_RW_0_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_RW_0_debug_rw_0_START (0)
#define SOC_ISP_DOPT_DEBUG_RW_0_debug_rw_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_rw_1 : 32;
    } reg;
} SOC_ISP_DOPT_DEBUG_RW_1_UNION;
#endif
#define SOC_ISP_DOPT_DEBUG_RW_1_debug_rw_1_START (0)
#define SOC_ISP_DOPT_DEBUG_RW_1_debug_rw_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int disp_histogram : 32;
    } reg;
} SOC_ISP_DOPT_DISP_HIST_UNION;
#endif
#define SOC_ISP_DOPT_DISP_HIST_disp_histogram_START (0)
#define SOC_ISP_DOPT_DISP_HIST_disp_histogram_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int depth_c : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_ISP_DOPT_DEPTH_C_UNION;
#endif
#define SOC_ISP_DOPT_DEPTH_C_depth_c_START (0)
#define SOC_ISP_DOPT_DEPTH_C_depth_c_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int depth_max : 16;
        unsigned int depth_right_shift_pixel : 10;
        unsigned int reserved : 6;
    } reg;
} SOC_ISP_DOPT_DEPTH_CFG_UNION;
#endif
#define SOC_ISP_DOPT_DEPTH_CFG_depth_max_START (0)
#define SOC_ISP_DOPT_DEPTH_CFG_depth_max_END (15)
#define SOC_ISP_DOPT_DEPTH_CFG_depth_right_shift_pixel_START (16)
#define SOC_ISP_DOPT_DEPTH_CFG_depth_right_shift_pixel_END (25)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

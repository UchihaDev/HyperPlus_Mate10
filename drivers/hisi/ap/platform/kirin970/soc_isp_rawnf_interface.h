#ifndef __SOC_ISP_RAWNF_INTERFACE_H__
#define __SOC_ISP_RAWNF_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_RAWNF_ISP_DPF_MODE_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_RAWNF_ISP_DPF_STRENGTH_R_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_RAWNF_ISP_DPF_STRENGTH_G_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_RAWNF_ISP_DPF_STRENGTH_B_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_RAWNF_ISP_DPF_NLL_COEFF_ADDR(base,Range17) ((base) + (0x0010+0x4*(Range17)))
#define SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_R_ADDR(base) ((base) + (0x0054))
#define SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_GR_ADDR(base) ((base) + (0x0058))
#define SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_GB_ADDR(base) ((base) + (0x005C))
#define SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_B_ADDR(base) ((base) + (0x0060))
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_OFFSET_SHIFT_ADDR(base) ((base) + (0x0064))
#define SOC_ISP_RAWNF_ISP_DFF_LSC_GAIN_OFFSET_THLD_ADDR(base) ((base) + (0x0068))
#define SOC_ISP_RAWNF_ISP_DPF_GAIN_DENOISE_ADDR(base) ((base) + (0x006C))
#define SOC_ISP_RAWNF_ISP_DPF_LUMA_ADDR(base) ((base) + (0x0070))
#define SOC_ISP_RAWNF_ISP_DPF_BLEND_ADDR(base) ((base) + (0x0074))
#define SOC_ISP_RAWNF_ISP_DPF_VAR_SCALE_ADDR(base) ((base) + (0x0078))
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_ADDR(base) ((base) + (0x007C))
#define SOC_ISP_RAWNF_ISP_DPF_DIFF_THLD_ADDR(base) ((base) + (0x0080))
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_ADDR(base) ((base) + (0x0084))
#define SOC_ISP_RAWNF_ISP_DPF_HUE2_ADDR(base) ((base) + (0x0088))
#define SOC_ISP_RAWNF_ISP_DPF_HUE1_ADDR(base) ((base) + (0x008C))
#define SOC_ISP_RAWNF_ISP_DPF_HUE0_ADDR(base) ((base) + (0x0090))
#define SOC_ISP_RAWNF_ISP_DPF_SAT_ADDR(base) ((base) + (0x0094))
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_CTRL_ADDR(base) ((base) + (0x0098))
#define SOC_ISP_RAWNF_ISP_DPF_NLM_OFFSET_ADDR(base) ((base) + (0x009C))
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_OFFSET_ADDR(base) ((base) + (0x00A0))
#define SOC_ISP_RAWNF_ISP_DPF_WEIGHT_OFFSET_ADDR(base) ((base) + (0x00A4))
#define SOC_ISP_RAWNF_ISP_DPF_COLOR_CORRECT_ADDR(base,Range12) ((base) + (0x00A8+0x4*(Range12)))
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_01_ADDR(base,Range44) ((base) + (0x0100+0x4*(Range44)))
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_23_ADDR(base,Range44) ((base) + (0x0200+0x4*(Range44)))
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_45_ADDR(base,Range44) ((base) + (0x0300+0x4*(Range44)))
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_01_ADDR(base,Range44) ((base) + (0x0400+0x4*(Range44)))
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_23_ADDR(base,Range44) ((base) + (0x0500+0x4*(Range44)))
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_45_ADDR(base,Range44) ((base) + (0x0600+0x4*(Range44)))
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_67_ADDR(base,Range44) ((base) + (0x0700+0x4*(Range44)))
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G8_ADDR(base,Range44) ((base) + (0x0800+0x4*(Range44)))
#define SOC_ISP_RAWNF_ISP_DPF_NLL_COEFF_EDGEDET_ADDR(base,Range17) ((base) + (0x0900+0x4*(Range17)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpf_enable : 1;
        unsigned int b_filter_off : 1;
        unsigned int gb_filter_off : 1;
        unsigned int gr_filter_off : 1;
        unsigned int r_filter_off : 1;
        unsigned int nll_segmentation : 1;
        unsigned int nll_segmentation_edge : 1;
        unsigned int lsc_gain_comp : 1;
        unsigned int lsc_gain1_comp : 1;
        unsigned int grey_mode : 1;
        unsigned int gauss_blend_enable : 1;
        unsigned int orgn_blend_enable : 1;
        unsigned int power_en : 1;
        unsigned int center_sel : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_MODE_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_MODE_dpf_enable_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_dpf_enable_END (0)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_b_filter_off_START (1)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_b_filter_off_END (1)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_gb_filter_off_START (2)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_gb_filter_off_END (2)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_gr_filter_off_START (3)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_gr_filter_off_END (3)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_r_filter_off_START (4)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_r_filter_off_END (4)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_nll_segmentation_START (5)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_nll_segmentation_END (5)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_nll_segmentation_edge_START (6)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_nll_segmentation_edge_END (6)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_lsc_gain_comp_START (7)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_lsc_gain_comp_END (7)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_lsc_gain1_comp_START (8)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_lsc_gain1_comp_END (8)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_grey_mode_START (9)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_grey_mode_END (9)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_gauss_blend_enable_START (10)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_gauss_blend_enable_END (10)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_orgn_blend_enable_START (11)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_orgn_blend_enable_END (11)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_power_en_START (12)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_power_en_END (12)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_center_sel_START (13)
#define SOC_ISP_RAWNF_ISP_DPF_MODE_center_sel_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inv_weight_r : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_STRENGTH_R_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_STRENGTH_R_inv_weight_r_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_STRENGTH_R_inv_weight_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inv_weight_g : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_STRENGTH_G_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_STRENGTH_G_inv_weight_g_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_STRENGTH_G_inv_weight_g_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inv_weight_b : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_STRENGTH_B_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_STRENGTH_B_inv_weight_b_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_STRENGTH_B_inv_weight_b_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nll_coeff : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_NLL_COEFF_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_NLL_COEFF_nll_coeff_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_NLL_COEFF_nll_coeff_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpf_nf_gain_r : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_R_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_R_dpf_nf_gain_r_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_R_dpf_nf_gain_r_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpf_nf_gain_gr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_GR_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_GR_dpf_nf_gain_gr_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_GR_dpf_nf_gain_gr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpf_nf_gain_gb : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_GB_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_GB_dpf_nf_gain_gb_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_GB_dpf_nf_gain_gb_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpf_nf_gain_b : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_B_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_B_dpf_nf_gain_b_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_NF_GAIN_B_dpf_nf_gain_b_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gauss_offset_shift : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_GAUSS_OFFSET_SHIFT_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_OFFSET_SHIFT_gauss_offset_shift_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_OFFSET_SHIFT_gauss_offset_shift_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lsc_gain_offset_thld : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_RAWNF_ISP_DFF_LSC_GAIN_OFFSET_THLD_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DFF_LSC_GAIN_OFFSET_THLD_lsc_gain_offset_thld_START (0)
#define SOC_ISP_RAWNF_ISP_DFF_LSC_GAIN_OFFSET_THLD_lsc_gain_offset_thld_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lsc_gain_offset_slope : 8;
        unsigned int max_lsc_gain_offset : 8;
        unsigned int lsc_offset_scale : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_GAIN_DENOISE_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_GAIN_DENOISE_lsc_gain_offset_slope_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_GAIN_DENOISE_lsc_gain_offset_slope_END (7)
#define SOC_ISP_RAWNF_ISP_DPF_GAIN_DENOISE_max_lsc_gain_offset_START (8)
#define SOC_ISP_RAWNF_ISP_DPF_GAIN_DENOISE_max_lsc_gain_offset_END (15)
#define SOC_ISP_RAWNF_ISP_DPF_GAIN_DENOISE_lsc_offset_scale_START (16)
#define SOC_ISP_RAWNF_ISP_DPF_GAIN_DENOISE_lsc_offset_scale_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_offset_thld : 8;
        unsigned int luma_offset_slope : 9;
        unsigned int luma_offset_max : 8;
        unsigned int reserved : 7;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_LUMA_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_LUMA_luma_offset_thld_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_LUMA_luma_offset_thld_END (7)
#define SOC_ISP_RAWNF_ISP_DPF_LUMA_luma_offset_slope_START (8)
#define SOC_ISP_RAWNF_ISP_DPF_LUMA_luma_offset_slope_END (16)
#define SOC_ISP_RAWNF_ISP_DPF_LUMA_luma_offset_max_START (17)
#define SOC_ISP_RAWNF_ISP_DPF_LUMA_luma_offset_max_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int base_blend_min : 8;
        unsigned int diff_scale : 6;
        unsigned int reserved_0 : 2;
        unsigned int edge_scale : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_BLEND_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_BLEND_base_blend_min_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_BLEND_base_blend_min_END (7)
#define SOC_ISP_RAWNF_ISP_DPF_BLEND_diff_scale_START (8)
#define SOC_ISP_RAWNF_ISP_DPF_BLEND_diff_scale_END (13)
#define SOC_ISP_RAWNF_ISP_DPF_BLEND_edge_scale_START (16)
#define SOC_ISP_RAWNF_ISP_DPF_BLEND_edge_scale_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int var_scale : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_VAR_SCALE_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_VAR_SCALE_var_scale_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_VAR_SCALE_var_scale_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edge_low_thld : 8;
        unsigned int edge_high_thld : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_edge_low_thld_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_edge_low_thld_END (7)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_edge_high_thld_START (8)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_edge_high_thld_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int diff_low_thd : 14;
        unsigned int reserved_0 : 2;
        unsigned int diff_high_thd : 14;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_DIFF_THLD_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_DIFF_THLD_diff_low_thd_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_DIFF_THLD_diff_low_thd_END (13)
#define SOC_ISP_RAWNF_ISP_DPF_DIFF_THLD_diff_high_thd_START (16)
#define SOC_ISP_RAWNF_ISP_DPF_DIFF_THLD_diff_high_thd_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edge_offset_slope : 8;
        unsigned int max_edge_offset : 8;
        unsigned int edge_offset_thld : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_EDGE_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_edge_offset_slope_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_edge_offset_slope_END (7)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_max_edge_offset_START (8)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_max_edge_offset_END (15)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_edge_offset_thld_START (16)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_edge_offset_thld_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hue_low2 : 9;
        unsigned int hue_high2 : 9;
        unsigned int reserved : 14;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_HUE2_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_HUE2_hue_low2_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_HUE2_hue_low2_END (8)
#define SOC_ISP_RAWNF_ISP_DPF_HUE2_hue_high2_START (9)
#define SOC_ISP_RAWNF_ISP_DPF_HUE2_hue_high2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hue_low1 : 9;
        unsigned int hue_high1 : 9;
        unsigned int reserved : 14;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_HUE1_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_HUE1_hue_low1_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_HUE1_hue_low1_END (8)
#define SOC_ISP_RAWNF_ISP_DPF_HUE1_hue_high1_START (9)
#define SOC_ISP_RAWNF_ISP_DPF_HUE1_hue_high1_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hue_low0 : 9;
        unsigned int hue_high0 : 9;
        unsigned int reserved : 14;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_HUE0_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_HUE0_hue_low0_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_HUE0_hue_low0_END (8)
#define SOC_ISP_RAWNF_ISP_DPF_HUE0_hue_high0_START (9)
#define SOC_ISP_RAWNF_ISP_DPF_HUE0_hue_high0_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sat_thld0 : 9;
        unsigned int sat_thld1 : 9;
        unsigned int sat_thld2 : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_SAT_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_SAT_sat_thld0_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_SAT_sat_thld0_END (8)
#define SOC_ISP_RAWNF_ISP_DPF_SAT_sat_thld1_START (9)
#define SOC_ISP_RAWNF_ISP_DPF_SAT_sat_thld1_END (17)
#define SOC_ISP_RAWNF_ISP_DPF_SAT_sat_thld2_START (18)
#define SOC_ISP_RAWNF_ISP_DPF_SAT_sat_thld2_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edge_thld0 : 9;
        unsigned int edge_thld1 : 9;
        unsigned int edge_thld2 : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_CTRL_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_CTRL_edge_thld0_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_CTRL_edge_thld0_END (8)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_CTRL_edge_thld1_START (9)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_CTRL_edge_thld1_END (17)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_CTRL_edge_thld2_START (18)
#define SOC_ISP_RAWNF_ISP_DPF_EDGE_THLD_CTRL_edge_thld2_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nlm_offset0 : 8;
        unsigned int nlm_offset1 : 8;
        unsigned int nlm_offset2 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_NLM_OFFSET_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_NLM_OFFSET_nlm_offset0_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_NLM_OFFSET_nlm_offset0_END (7)
#define SOC_ISP_RAWNF_ISP_DPF_NLM_OFFSET_nlm_offset1_START (8)
#define SOC_ISP_RAWNF_ISP_DPF_NLM_OFFSET_nlm_offset1_END (15)
#define SOC_ISP_RAWNF_ISP_DPF_NLM_OFFSET_nlm_offset2_START (16)
#define SOC_ISP_RAWNF_ISP_DPF_NLM_OFFSET_nlm_offset2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gauss_offset0 : 6;
        unsigned int gauss_offset1 : 6;
        unsigned int gauss_offset2 : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_GAUSS_OFFSET_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_OFFSET_gauss_offset0_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_OFFSET_gauss_offset0_END (5)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_OFFSET_gauss_offset1_START (6)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_OFFSET_gauss_offset1_END (11)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_OFFSET_gauss_offset2_START (12)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_OFFSET_gauss_offset2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int weight_offset0 : 9;
        unsigned int weight_offset1 : 9;
        unsigned int weight_offset2 : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_WEIGHT_OFFSET_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_WEIGHT_OFFSET_weight_offset0_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_WEIGHT_OFFSET_weight_offset0_END (8)
#define SOC_ISP_RAWNF_ISP_DPF_WEIGHT_OFFSET_weight_offset1_START (9)
#define SOC_ISP_RAWNF_ISP_DPF_WEIGHT_OFFSET_weight_offset1_END (17)
#define SOC_ISP_RAWNF_ISP_DPF_WEIGHT_OFFSET_weight_offset2_START (18)
#define SOC_ISP_RAWNF_ISP_DPF_WEIGHT_OFFSET_weight_offset2_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorCorrectMat : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_COLOR_CORRECT_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_COLOR_CORRECT_colorCorrectMat_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_COLOR_CORRECT_colorCorrectMat_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rb_gauss_coef_0 : 6;
        unsigned int rb_gauss_coef_1 : 7;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_01_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_01_rb_gauss_coef_0_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_01_rb_gauss_coef_0_END (5)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_01_rb_gauss_coef_1_START (6)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_01_rb_gauss_coef_1_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rb_gauss_coef_2 : 9;
        unsigned int rb_gauss_coef_3 : 6;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_23_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_23_rb_gauss_coef_2_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_23_rb_gauss_coef_2_END (8)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_23_rb_gauss_coef_3_START (9)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_23_rb_gauss_coef_3_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rb_gauss_coef_4 : 8;
        unsigned int rb_gauss_coef_5 : 7;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_45_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_45_rb_gauss_coef_4_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_45_rb_gauss_coef_4_END (7)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_45_rb_gauss_coef_5_START (8)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_RB_45_rb_gauss_coef_5_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int g_gauss_coef_0 : 5;
        unsigned int g_gauss_coef_1 : 6;
        unsigned int reserved : 21;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_01_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_01_g_gauss_coef_0_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_01_g_gauss_coef_0_END (4)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_01_g_gauss_coef_1_START (5)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_01_g_gauss_coef_1_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int g_gauss_coef_2 : 7;
        unsigned int g_gauss_coef_3 : 8;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_23_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_23_g_gauss_coef_2_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_23_g_gauss_coef_2_END (6)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_23_g_gauss_coef_3_START (7)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_23_g_gauss_coef_3_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int g_gauss_coef_4 : 9;
        unsigned int g_gauss_coef_5 : 5;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_45_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_45_g_gauss_coef_4_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_45_g_gauss_coef_4_END (8)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_45_g_gauss_coef_5_START (9)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_45_g_gauss_coef_5_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int g_gauss_coef_6 : 6;
        unsigned int g_gauss_coef_7 : 7;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_67_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_67_g_gauss_coef_6_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_67_g_gauss_coef_6_END (5)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_67_g_gauss_coef_7_START (6)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G_67_g_gauss_coef_7_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int g_gauss_coef_8 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_GAUSS_G8_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G8_g_gauss_coef_8_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_GAUSS_G8_g_gauss_coef_8_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nll_coeff_edgeDet : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_RAWNF_ISP_DPF_NLL_COEFF_EDGEDET_UNION;
#endif
#define SOC_ISP_RAWNF_ISP_DPF_NLL_COEFF_EDGEDET_nll_coeff_edgeDet_START (0)
#define SOC_ISP_RAWNF_ISP_DPF_NLL_COEFF_EDGEDET_nll_coeff_edgeDet_END (9)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

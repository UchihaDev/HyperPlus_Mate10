#ifndef __SOC_ISP_BE_INTERFACE_H__
#define __SOC_ISP_BE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_BE_FCLK_EN_BE_ADDR(base) ((base) + (0x0))
#define SOC_ISP_BE_CONTROL_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_BE_CROP_H_2_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_BE_CROP_V_2_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_BE_RGB2YUV_COEFF_0_ADDR(base) ((base) + (0x0030))
#define SOC_ISP_BE_RGB2YUV_COEFF_1_ADDR(base) ((base) + (0x0034))
#define SOC_ISP_BE_RGB2YUV_COEFF_2_ADDR(base) ((base) + (0x0038))
#define SOC_ISP_BE_RGB2YUV_COEFF_3_ADDR(base) ((base) + (0x003C))
#define SOC_ISP_BE_RGB2YUV_COEFF_4_ADDR(base) ((base) + (0x0040))
#define SOC_ISP_BE_RGB2YUV_COEFF_5_ADDR(base) ((base) + (0x0044))
#define SOC_ISP_BE_RGB2YUV_COEFF_6_ADDR(base) ((base) + (0x0048))
#define SOC_ISP_BE_RGB2YUV_COEFF_7_ADDR(base) ((base) + (0x004C))
#define SOC_ISP_BE_RGB2YUV_COEFF_8_ADDR(base) ((base) + (0x0050))
#define SOC_ISP_BE_YUV2RGB_COEFF_0_ADDR(base) ((base) + (0x0060))
#define SOC_ISP_BE_YUV2RGB_COEFF_1_ADDR(base) ((base) + (0x0064))
#define SOC_ISP_BE_YUV2RGB_COEFF_2_ADDR(base) ((base) + (0x0068))
#define SOC_ISP_BE_YUV2RGB_COEFF_3_ADDR(base) ((base) + (0x006C))
#define SOC_ISP_BE_YUV2RGB_COEFF_4_ADDR(base) ((base) + (0x0070))
#define SOC_ISP_BE_YUV2RGB_COEFF_5_ADDR(base) ((base) + (0x0074))
#define SOC_ISP_BE_YUV2RGB_COEFF_6_ADDR(base) ((base) + (0x0078))
#define SOC_ISP_BE_YUV2RGB_COEFF_7_ADDR(base) ((base) + (0x007C))
#define SOC_ISP_BE_YUV2RGB_COEFF_8_ADDR(base) ((base) + (0x0080))
#define SOC_ISP_BE_PTREG_1_1_ADDR(base) ((base) + (0x0090))
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_ADDR(base) ((base) + (0x00A0))
#define SOC_ISP_BE_UVDEC_COEFF_0_ADDR(base) ((base) + (0x00B0))
#define SOC_ISP_BE_UVDEC_COEFF_1_ADDR(base) ((base) + (0x00B4))
#define SOC_ISP_BE_UVDEC_COEFF_2_ADDR(base) ((base) + (0x00B8))
#define SOC_ISP_BE_UVDEC_COEFF_3_ADDR(base) ((base) + (0x00BC))
#define SOC_ISP_BE_UVDEC_COEFF_4_ADDR(base) ((base) + (0x00C0))
#define SOC_ISP_BE_UVDEC_COEFF_5_ADDR(base) ((base) + (0x00C4))
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_0_ADDR(base) ((base) + (0x00D0))
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_1_ADDR(base) ((base) + (0x00D4))
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_2_ADDR(base) ((base) + (0x00D8))
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_3_ADDR(base) ((base) + (0x00DC))
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_4_ADDR(base) ((base) + (0x00E0))
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_5_ADDR(base) ((base) + (0x00E4))
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_6_ADDR(base) ((base) + (0x00E8))
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_7_ADDR(base) ((base) + (0x00EC))
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_8_ADDR(base) ((base) + (0x00F0))
#define SOC_ISP_BE_UVDEC_COEFF_LB_0_ADDR(base) ((base) + (0x0100))
#define SOC_ISP_BE_UVDEC_COEFF_L_1_ADDR(base) ((base) + (0x0104))
#define SOC_ISP_BE_UVDEC_COEFF_L_2_ADDR(base) ((base) + (0x0108))
#define SOC_ISP_BE_UVDEC_COEFF_L_3_ADDR(base) ((base) + (0x010C))
#define SOC_ISP_BE_UVDEC_COEFF_L_4_ADDR(base) ((base) + (0x0110))
#define SOC_ISP_BE_UVDEC_COEFF_L_5_ADDR(base) ((base) + (0x0114))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fclk_en_be : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_BE_FCLK_EN_BE_UNION;
#endif
#define SOC_ISP_BE_FCLK_EN_BE_fclk_en_be_START (0)
#define SOC_ISP_BE_FCLK_EN_BE_fclk_en_be_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bayer_pat_be : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int awb_enable : 1;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int monochrome_mode : 1;
        unsigned int reserved_6 : 19;
    } reg;
} SOC_ISP_BE_CONTROL_UNION;
#endif
#define SOC_ISP_BE_CONTROL_bayer_pat_be_START (0)
#define SOC_ISP_BE_CONTROL_bayer_pat_be_END (1)
#define SOC_ISP_BE_CONTROL_awb_enable_START (6)
#define SOC_ISP_BE_CONTROL_awb_enable_END (6)
#define SOC_ISP_BE_CONTROL_monochrome_mode_START (12)
#define SOC_ISP_BE_CONTROL_monochrome_mode_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 13;
        unsigned int reserved_3: 3;
    } reg;
} SOC_ISP_BE_CROP_H_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 13;
        unsigned int reserved_3: 3;
    } reg;
} SOC_ISP_BE_CROP_V_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int y_r : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_0_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_0_y_r_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_0_y_r_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int y_g : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_1_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_1_y_g_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_1_y_g_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int y_b : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_2_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_2_y_b_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_2_y_b_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_r : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_3_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_3_u_r_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_3_u_r_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_g : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_4_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_4_u_g_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_4_u_g_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_b : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_5_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_5_u_b_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_5_u_b_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int v_r : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_6_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_6_v_r_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_6_v_r_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int v_g : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_7_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_7_v_g_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_7_v_g_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int v_b : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_8_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_8_v_b_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_8_v_b_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 9;
        unsigned int reserved_1: 23;
    } reg;
} SOC_ISP_BE_YUV2RGB_COEFF_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 9;
        unsigned int reserved_1: 23;
    } reg;
} SOC_ISP_BE_YUV2RGB_COEFF_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 9;
        unsigned int reserved_1: 23;
    } reg;
} SOC_ISP_BE_YUV2RGB_COEFF_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 9;
        unsigned int reserved_1: 23;
    } reg;
} SOC_ISP_BE_YUV2RGB_COEFF_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 9;
        unsigned int reserved_1: 23;
    } reg;
} SOC_ISP_BE_YUV2RGB_COEFF_4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 9;
        unsigned int reserved_1: 23;
    } reg;
} SOC_ISP_BE_YUV2RGB_COEFF_5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 9;
        unsigned int reserved_1: 23;
    } reg;
} SOC_ISP_BE_YUV2RGB_COEFF_6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 9;
        unsigned int reserved_1: 23;
    } reg;
} SOC_ISP_BE_YUV2RGB_COEFF_7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 9;
        unsigned int reserved_1: 23;
    } reg;
} SOC_ISP_BE_YUV2RGB_COEFF_8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ratio : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_BE_PTREG_1_1_UNION;
#endif
#define SOC_ISP_BE_PTREG_1_1_ratio_START (0)
#define SOC_ISP_BE_PTREG_1_1_ratio_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_clk_on_awbgain_1 : 1;
        unsigned int force_clk_on_gcd_1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int force_clk_on_cc_1 : 1;
        unsigned int force_clk_on_drc_1 : 1;
        unsigned int force_clk_on_gamma_1 : 1;
        unsigned int force_clk_on_rgb2yuv_1 : 1;
        unsigned int force_clk_on_uvdec_1 : 1;
        unsigned int force_clk_on_ce_1 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int force_clk_on_tnr_1 : 1;
        unsigned int reserved_3 : 1;
        unsigned int force_clk_on_be_top : 1;
        unsigned int force_clk_on_lsc_1 : 1;
        unsigned int force_clk_on_dpcc_1 : 1;
        unsigned int force_clk_on_rawnf_1 : 1;
        unsigned int force_clk_on_blc_3 : 1;
        unsigned int force_clk_on_cgt_1 : 1;
        unsigned int force_clk_on_yuvnf_iir_1 : 1;
        unsigned int force_clk_on_rgb2yuv_2 : 1;
        unsigned int force_clk_on_gamma_2 : 1;
        unsigned int force_clk_on_uvdec_2 : 1;
        unsigned int force_clk_on_sharpen_1 : 1;
        unsigned int reserved_4 : 8;
    } reg;
} SOC_ISP_BE_FORCE_CLK_ON_CFG_UNION;
#endif
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_awbgain_1_START (0)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_awbgain_1_END (0)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_gcd_1_START (1)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_gcd_1_END (1)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_cc_1_START (3)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_cc_1_END (3)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_drc_1_START (4)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_drc_1_END (4)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_gamma_1_START (5)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_gamma_1_END (5)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_rgb2yuv_1_START (6)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_rgb2yuv_1_END (6)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_uvdec_1_START (7)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_uvdec_1_END (7)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_ce_1_START (8)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_ce_1_END (8)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_tnr_1_START (11)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_tnr_1_END (11)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_be_top_START (13)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_be_top_END (13)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_lsc_1_START (14)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_lsc_1_END (14)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_dpcc_1_START (15)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_dpcc_1_END (15)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_rawnf_1_START (16)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_rawnf_1_END (16)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_blc_3_START (17)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_blc_3_END (17)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_cgt_1_START (18)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_cgt_1_END (18)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_yuvnf_iir_1_START (19)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_yuvnf_iir_1_END (19)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_rgb2yuv_2_START (20)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_rgb2yuv_2_END (20)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_gamma_2_START (21)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_gamma_2_END (21)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_uvdec_2_START (22)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_uvdec_2_END (22)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_sharpen_1_START (23)
#define SOC_ISP_BE_FORCE_CLK_ON_CFG_force_clk_on_sharpen_1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m_filter_downsample_0 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_BE_UVDEC_COEFF_0_UNION;
#endif
#define SOC_ISP_BE_UVDEC_COEFF_0_m_filter_downsample_0_START (0)
#define SOC_ISP_BE_UVDEC_COEFF_0_m_filter_downsample_0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m_filter_downsample_1 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_BE_UVDEC_COEFF_1_UNION;
#endif
#define SOC_ISP_BE_UVDEC_COEFF_1_m_filter_downsample_1_START (0)
#define SOC_ISP_BE_UVDEC_COEFF_1_m_filter_downsample_1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m_filter_downsample_2 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_BE_UVDEC_COEFF_2_UNION;
#endif
#define SOC_ISP_BE_UVDEC_COEFF_2_m_filter_downsample_2_START (0)
#define SOC_ISP_BE_UVDEC_COEFF_2_m_filter_downsample_2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m_filter_downsample_3 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_BE_UVDEC_COEFF_3_UNION;
#endif
#define SOC_ISP_BE_UVDEC_COEFF_3_m_filter_downsample_3_START (0)
#define SOC_ISP_BE_UVDEC_COEFF_3_m_filter_downsample_3_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m_filter_downsample_4 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_BE_UVDEC_COEFF_4_UNION;
#endif
#define SOC_ISP_BE_UVDEC_COEFF_4_m_filter_downsample_4_START (0)
#define SOC_ISP_BE_UVDEC_COEFF_4_m_filter_downsample_4_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m_filter_downsample_5 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_BE_UVDEC_COEFF_5_UNION;
#endif
#define SOC_ISP_BE_UVDEC_COEFF_5_m_filter_downsample_5_START (0)
#define SOC_ISP_BE_UVDEC_COEFF_5_m_filter_downsample_5_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lb_y_r : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_LB_0_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_0_lb_y_r_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_0_lb_y_r_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lb_y_g : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_LB_1_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_1_lb_y_g_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_1_lb_y_g_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lb_y_b : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_LB_2_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_2_lb_y_b_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_2_lb_y_b_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lb_u_r : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_LB_3_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_3_lb_u_r_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_3_lb_u_r_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lb_u_g : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_LB_4_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_4_lb_u_g_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_4_lb_u_g_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lb_u_b : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_LB_5_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_5_lb_u_b_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_5_lb_u_b_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lb_v_r : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_LB_6_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_6_lb_v_r_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_6_lb_v_r_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lb_v_g : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_LB_7_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_7_lb_v_g_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_7_lb_v_g_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lb_v_b : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_BE_RGB2YUV_COEFF_LB_8_UNION;
#endif
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_8_lb_v_b_START (0)
#define SOC_ISP_BE_RGB2YUV_COEFF_LB_8_lb_v_b_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luvdec_m_filter_downsample_0 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_BE_UVDEC_COEFF_LB_0_UNION;
#endif
#define SOC_ISP_BE_UVDEC_COEFF_LB_0_luvdec_m_filter_downsample_0_START (0)
#define SOC_ISP_BE_UVDEC_COEFF_LB_0_luvdec_m_filter_downsample_0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luvdec_m_filter_downsample_1 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_BE_UVDEC_COEFF_L_1_UNION;
#endif
#define SOC_ISP_BE_UVDEC_COEFF_L_1_luvdec_m_filter_downsample_1_START (0)
#define SOC_ISP_BE_UVDEC_COEFF_L_1_luvdec_m_filter_downsample_1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luvdec_m_filter_downsample_2 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_BE_UVDEC_COEFF_L_2_UNION;
#endif
#define SOC_ISP_BE_UVDEC_COEFF_L_2_luvdec_m_filter_downsample_2_START (0)
#define SOC_ISP_BE_UVDEC_COEFF_L_2_luvdec_m_filter_downsample_2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luvdec_m_filter_downsample_3 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_BE_UVDEC_COEFF_L_3_UNION;
#endif
#define SOC_ISP_BE_UVDEC_COEFF_L_3_luvdec_m_filter_downsample_3_START (0)
#define SOC_ISP_BE_UVDEC_COEFF_L_3_luvdec_m_filter_downsample_3_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luvdec_m_filter_downsample_4 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_BE_UVDEC_COEFF_L_4_UNION;
#endif
#define SOC_ISP_BE_UVDEC_COEFF_L_4_luvdec_m_filter_downsample_4_START (0)
#define SOC_ISP_BE_UVDEC_COEFF_L_4_luvdec_m_filter_downsample_4_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luvdec_m_filter_downsample_5 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_BE_UVDEC_COEFF_L_5_UNION;
#endif
#define SOC_ISP_BE_UVDEC_COEFF_L_5_luvdec_m_filter_downsample_5_START (0)
#define SOC_ISP_BE_UVDEC_COEFF_L_5_luvdec_m_filter_downsample_5_END (9)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

#ifndef __SOC_ISP_DE_INTERFACE_H__
#define __SOC_ISP_DE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_DE_DE_CONFIG_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_DE_BLACK_NOISE_SCALE_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_DE_WHITE_NOISE_SCALE_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_DE_GLOBALGAINLF_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_DE_GLOBALGAINMF_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_DE_GLOBALGAINHF_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_DE_LUTMF5x5NOISE_ADDR(base,Range3) ((base) + (0x18+0x4*(Range3)))
#define SOC_ISP_DE_LUTMF3x3NOISE_ADDR(base,Range4) ((base) + (0x28+0x4*(Range4)))
#define SOC_ISP_DE_LUTLFNOISE_ADDR(base,Range3) ((base) + (0x38+0x4*(Range3)))
#define SOC_ISP_DE_ISO_ADDR(base) ((base) + (0x0044))
#define SOC_ISP_DE_STRIPE_SIZE_ADDR(base) ((base) + (0x0048))
#define SOC_ISP_DE_MINGAINSCALE_ADDR(base) ((base) + (0x004C))
#define SOC_ISP_DE_GAMMA_SCALE_LF_ADDR(base) ((base) + (0x0050))
#define SOC_ISP_DE_GAMMA_SCALE_MF_ADDR(base) ((base) + (0x0054))
#define SOC_ISP_DE_BIT_WIDTH_ADDR(base) ((base) + (0x0058))
#define SOC_ISP_DE_GAINSCALE_LUMAX_ADDR(base) ((base) + (0x005C))
#define SOC_ISP_DE_GAINSCALE_LUMAY_ADDR(base) ((base) + (0x0060))
#define SOC_ISP_DE_GAINSCALE_LUMASCALE_X0_ADDR(base) ((base) + (0x0064))
#define SOC_ISP_DE_GAINSCALE_LUMASCALE_X1_ADDR(base) ((base) + (0x0068))
#define SOC_ISP_DE_GAINSCALE_LUMASCALE_Y0_ADDR(base) ((base) + (0x006C))
#define SOC_ISP_DE_GAINSCALE_LUMASCALE_Y1_ADDR(base) ((base) + (0x0070))
#define SOC_ISP_DE_BLR_LUMASCALE_X1_ADDR(base) ((base) + (0x0074))
#define SOC_ISP_DE_BLR_LUMASCALE_Y_ADDR(base) ((base) + (0x0078))
#define SOC_ISP_DE_BLR_LUMA_ADDR(base) ((base) + (0x007C))
#define SOC_ISP_DE_DARKR_RATIO_ADDR(base) ((base) + (0x0080))
#define SOC_ISP_DE_DARKR_MAX_ADDR(base) ((base) + (0x0084))
#define SOC_ISP_DE_DARKR_MIN_ADDR(base) ((base) + (0x0088))
#define SOC_ISP_DE_DARKR_ADDR(base) ((base) + (0x008C))
#define SOC_ISP_DE_DARKR_ISO_X0_ADDR(base) ((base) + (0x0090))
#define SOC_ISP_DE_DARKR_ISO_X1_ADDR(base) ((base) + (0x0094))
#define SOC_ISP_DE_DARKR_ISO_X2_ADDR(base) ((base) + (0x0098))
#define SOC_ISP_DE_DARKR_ISO_X3_ADDR(base) ((base) + (0x009C))
#define SOC_ISP_DE_DISTR_MAX_ADDR(base) ((base) + (0x00A4))
#define SOC_ISP_DE_DISTR_MIN_ADDR(base) ((base) + (0x00A8))
#define SOC_ISP_DE_DISTR_DIST_X0_ADDR(base) ((base) + (0x00AC))
#define SOC_ISP_DE_DISTR_DIST_X1_ADDR(base) ((base) + (0x00B0))
#define SOC_ISP_DE_DISTR_ISO_X0_ADDR(base) ((base) + (0x00B4))
#define SOC_ISP_DE_DISTR_ISO_X1_ADDR(base) ((base) + (0x00B8))
#define SOC_ISP_DE_DISTR_ISO_X2_ADDR(base) ((base) + (0x00BC))
#define SOC_ISP_DE_DISTR_ISO_X3_ADDR(base) ((base) + (0x00C0))
#define SOC_ISP_DE_DISTR_S_X0_ADDR(base) ((base) + (0x00C4))
#define SOC_ISP_DE_DISTR_S_X1_ADDR(base) ((base) + (0x00C8))
#define SOC_ISP_DE_DISTR_LUMA_X0_ADDR(base) ((base) + (0x00CC))
#define SOC_ISP_DE_DISTR_LUMA_X1_ADDR(base) ((base) + (0x00D0))
#define SOC_ISP_DE_BRIGHTR_MAX_ADDR(base) ((base) + (0x00D4))
#define SOC_ISP_DE_BRIGHTR_MIN_ADDR(base) ((base) + (0x00D8))
#define SOC_ISP_DE_BRIGHTR_ISO_X0_ADDR(base) ((base) + (0x00DC))
#define SOC_ISP_DE_BRIGHTR_ISO_X1_ADDR(base) ((base) + (0x00E0))
#define SOC_ISP_DE_BRIGHTR_V0_ADDR(base) ((base) + (0x00E4))
#define SOC_ISP_DE_BRIGHTR_V1_ADDR(base) ((base) + (0x00E8))
#define SOC_ISP_DE_BRIGHTR_S_ADDR(base) ((base) + (0x00EC))
#define SOC_ISP_DE_COLORR_S_X_ADDR(base) ((base) + (0x00F0))
#define SOC_ISP_DE_COLORR_S_Y_ADDR(base) ((base) + (0x00F4))
#define SOC_ISP_DE_COLORV_ADDR(base) ((base) + (0x00F8))
#define SOC_ISP_DE_COLORR_H0_ADDR(base) ((base) + (0x00FC))
#define SOC_ISP_DE_COLORR_H1_ADDR(base) ((base) + (0x0100))
#define SOC_ISP_DE_COLORR_H2_X_ADDR(base) ((base) + (0x0104))
#define SOC_ISP_DE_COLORR_H2_Y_ADDR(base) ((base) + (0x0108))
#define SOC_ISP_DE_COLORR_H3_X_ADDR(base) ((base) + (0x010C))
#define SOC_ISP_DE_COLORR_ISO_ADDR(base) ((base) + (0x0110))
#define SOC_ISP_DE_COLORR_BS0_X_ADDR(base) ((base) + (0x0114))
#define SOC_ISP_DE_COLORR_BS0_Y_ADDR(base) ((base) + (0x0118))
#define SOC_ISP_DE_COLORR_BS1_X_ADDR(base) ((base) + (0x011C))
#define SOC_ISP_DE_COLORR_BS1_Y_ADDR(base) ((base) + (0x0120))
#define SOC_ISP_DE_GRAYR_ADDR(base) ((base) + (0x0124))
#define SOC_ISP_DE_GRAYR_ISO_ADDR(base) ((base) + (0x0128))
#define SOC_ISP_DE_GRAYR_S_ADDR(base) ((base) + (0x012C))
#define SOC_ISP_DE_GRAYR_V_X_ADDR(base) ((base) + (0x0130))
#define SOC_ISP_DE_NOISE_CLIP_ADDR(base) ((base) + (0x0138))
#define SOC_ISP_DE_IMGCENTER_ADDR(base) ((base) + (0x013C))
#define SOC_ISP_DE_GAMMASLOP_ADDR(base,Range256) ((base) + (0x0140+0x4*(Range256)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int uv_enable : 1;
        unsigned int force_clk_on : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_DE_DE_CONFIG_UNION;
#endif
#define SOC_ISP_DE_DE_CONFIG_bypass_START (0)
#define SOC_ISP_DE_DE_CONFIG_bypass_END (0)
#define SOC_ISP_DE_DE_CONFIG_uv_enable_START (1)
#define SOC_ISP_DE_DE_CONFIG_uv_enable_END (1)
#define SOC_ISP_DE_DE_CONFIG_force_clk_on_START (2)
#define SOC_ISP_DE_DE_CONFIG_force_clk_on_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int black_noise_scale : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_DE_BLACK_NOISE_SCALE_UNION;
#endif
#define SOC_ISP_DE_BLACK_NOISE_SCALE_black_noise_scale_START (0)
#define SOC_ISP_DE_BLACK_NOISE_SCALE_black_noise_scale_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int white_noise_scale : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_DE_WHITE_NOISE_SCALE_UNION;
#endif
#define SOC_ISP_DE_WHITE_NOISE_SCALE_white_noise_scale_START (0)
#define SOC_ISP_DE_WHITE_NOISE_SCALE_white_noise_scale_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int globalgainlf : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_DE_GLOBALGAINLF_UNION;
#endif
#define SOC_ISP_DE_GLOBALGAINLF_globalgainlf_START (0)
#define SOC_ISP_DE_GLOBALGAINLF_globalgainlf_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int globalgainmf : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_DE_GLOBALGAINMF_UNION;
#endif
#define SOC_ISP_DE_GLOBALGAINMF_globalgainmf_START (0)
#define SOC_ISP_DE_GLOBALGAINMF_globalgainmf_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int globalgainhf : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_DE_GLOBALGAINHF_UNION;
#endif
#define SOC_ISP_DE_GLOBALGAINHF_globalgainhf_START (0)
#define SOC_ISP_DE_GLOBALGAINHF_globalgainhf_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lutmf5x5noise : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_DE_LUTMF5x5NOISE_UNION;
#endif
#define SOC_ISP_DE_LUTMF5x5NOISE_lutmf5x5noise_START (0)
#define SOC_ISP_DE_LUTMF5x5NOISE_lutmf5x5noise_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lutmf3x3noise : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_DE_LUTMF3x3NOISE_UNION;
#endif
#define SOC_ISP_DE_LUTMF3x3NOISE_lutmf3x3noise_START (0)
#define SOC_ISP_DE_LUTMF3x3NOISE_lutmf3x3noise_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lutlfnoise : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_DE_LUTLFNOISE_UNION;
#endif
#define SOC_ISP_DE_LUTLFNOISE_lutlfnoise_START (0)
#define SOC_ISP_DE_LUTLFNOISE_lutlfnoise_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iso : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_DE_ISO_UNION;
#endif
#define SOC_ISP_DE_ISO_iso_START (0)
#define SOC_ISP_DE_ISO_iso_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stripe_width : 13;
        unsigned int reserved_0 : 3;
        unsigned int stripe_height : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_DE_STRIPE_SIZE_UNION;
#endif
#define SOC_ISP_DE_STRIPE_SIZE_stripe_width_START (0)
#define SOC_ISP_DE_STRIPE_SIZE_stripe_width_END (12)
#define SOC_ISP_DE_STRIPE_SIZE_stripe_height_START (16)
#define SOC_ISP_DE_STRIPE_SIZE_stripe_height_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mingainscale : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_ISP_DE_MINGAINSCALE_UNION;
#endif
#define SOC_ISP_DE_MINGAINSCALE_mingainscale_START (0)
#define SOC_ISP_DE_MINGAINSCALE_mingainscale_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_scale_lf : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_DE_GAMMA_SCALE_LF_UNION;
#endif
#define SOC_ISP_DE_GAMMA_SCALE_LF_gamma_scale_lf_START (0)
#define SOC_ISP_DE_GAMMA_SCALE_LF_gamma_scale_lf_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_scale_mf : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_DE_GAMMA_SCALE_MF_UNION;
#endif
#define SOC_ISP_DE_GAMMA_SCALE_MF_gamma_scale_mf_START (0)
#define SOC_ISP_DE_GAMMA_SCALE_MF_gamma_scale_mf_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitwidth_noise : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_DE_BIT_WIDTH_UNION;
#endif
#define SOC_ISP_DE_BIT_WIDTH_bitwidth_noise_START (0)
#define SOC_ISP_DE_BIT_WIDTH_bitwidth_noise_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainscale_luma_x0 : 8;
        unsigned int gainscale_luma_x1 : 8;
        unsigned int gainscale_luma_x2 : 8;
        unsigned int gainscale_luma_x3 : 8;
    } reg;
} SOC_ISP_DE_GAINSCALE_LUMAX_UNION;
#endif
#define SOC_ISP_DE_GAINSCALE_LUMAX_gainscale_luma_x0_START (0)
#define SOC_ISP_DE_GAINSCALE_LUMAX_gainscale_luma_x0_END (7)
#define SOC_ISP_DE_GAINSCALE_LUMAX_gainscale_luma_x1_START (8)
#define SOC_ISP_DE_GAINSCALE_LUMAX_gainscale_luma_x1_END (15)
#define SOC_ISP_DE_GAINSCALE_LUMAX_gainscale_luma_x2_START (16)
#define SOC_ISP_DE_GAINSCALE_LUMAX_gainscale_luma_x2_END (23)
#define SOC_ISP_DE_GAINSCALE_LUMAX_gainscale_luma_x3_START (24)
#define SOC_ISP_DE_GAINSCALE_LUMAX_gainscale_luma_x3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainscale_luma_y0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int gainscale_luma_y1 : 7;
        unsigned int reserved_1 : 1;
        unsigned int gainscale_luma_y2 : 7;
        unsigned int reserved_2 : 9;
    } reg;
} SOC_ISP_DE_GAINSCALE_LUMAY_UNION;
#endif
#define SOC_ISP_DE_GAINSCALE_LUMAY_gainscale_luma_y0_START (0)
#define SOC_ISP_DE_GAINSCALE_LUMAY_gainscale_luma_y0_END (6)
#define SOC_ISP_DE_GAINSCALE_LUMAY_gainscale_luma_y1_START (8)
#define SOC_ISP_DE_GAINSCALE_LUMAY_gainscale_luma_y1_END (14)
#define SOC_ISP_DE_GAINSCALE_LUMAY_gainscale_luma_y2_START (16)
#define SOC_ISP_DE_GAINSCALE_LUMAY_gainscale_luma_y2_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainscale_lumascale_x0 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_DE_GAINSCALE_LUMASCALE_X0_UNION;
#endif
#define SOC_ISP_DE_GAINSCALE_LUMASCALE_X0_gainscale_lumascale_x0_START (0)
#define SOC_ISP_DE_GAINSCALE_LUMASCALE_X0_gainscale_lumascale_x0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainscale_lumascale_x1 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_DE_GAINSCALE_LUMASCALE_X1_UNION;
#endif
#define SOC_ISP_DE_GAINSCALE_LUMASCALE_X1_gainscale_lumascale_x1_START (0)
#define SOC_ISP_DE_GAINSCALE_LUMASCALE_X1_gainscale_lumascale_x1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainscale_lumascale_y0 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_DE_GAINSCALE_LUMASCALE_Y0_UNION;
#endif
#define SOC_ISP_DE_GAINSCALE_LUMASCALE_Y0_gainscale_lumascale_y0_START (0)
#define SOC_ISP_DE_GAINSCALE_LUMASCALE_Y0_gainscale_lumascale_y0_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainscale_lumascale_y1 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_DE_GAINSCALE_LUMASCALE_Y1_UNION;
#endif
#define SOC_ISP_DE_GAINSCALE_LUMASCALE_Y1_gainscale_lumascale_y1_START (0)
#define SOC_ISP_DE_GAINSCALE_LUMASCALE_Y1_gainscale_lumascale_y1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blr_lumascale_x0 : 4;
        unsigned int blr_lumascale_x1 : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_DE_BLR_LUMASCALE_X1_UNION;
#endif
#define SOC_ISP_DE_BLR_LUMASCALE_X1_blr_lumascale_x0_START (0)
#define SOC_ISP_DE_BLR_LUMASCALE_X1_blr_lumascale_x0_END (3)
#define SOC_ISP_DE_BLR_LUMASCALE_X1_blr_lumascale_x1_START (4)
#define SOC_ISP_DE_BLR_LUMASCALE_X1_blr_lumascale_x1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blr_lumascale_y : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_ISP_DE_BLR_LUMASCALE_Y_UNION;
#endif
#define SOC_ISP_DE_BLR_LUMASCALE_Y_blr_lumascale_y_START (0)
#define SOC_ISP_DE_BLR_LUMASCALE_Y_blr_lumascale_y_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blr_luma_x0 : 8;
        unsigned int blr_luma_x1 : 8;
        unsigned int blr_luma_y0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int blr_luma_y1 : 7;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_ISP_DE_BLR_LUMA_UNION;
#endif
#define SOC_ISP_DE_BLR_LUMA_blr_luma_x0_START (0)
#define SOC_ISP_DE_BLR_LUMA_blr_luma_x0_END (7)
#define SOC_ISP_DE_BLR_LUMA_blr_luma_x1_START (8)
#define SOC_ISP_DE_BLR_LUMA_blr_luma_x1_END (15)
#define SOC_ISP_DE_BLR_LUMA_blr_luma_y0_START (16)
#define SOC_ISP_DE_BLR_LUMA_blr_luma_y0_END (22)
#define SOC_ISP_DE_BLR_LUMA_blr_luma_y1_START (24)
#define SOC_ISP_DE_BLR_LUMA_blr_luma_y1_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int darkr_ratio : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_DE_DARKR_RATIO_UNION;
#endif
#define SOC_ISP_DE_DARKR_RATIO_darkr_ratio_START (0)
#define SOC_ISP_DE_DARKR_RATIO_darkr_ratio_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int darkr_max : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_DE_DARKR_MAX_UNION;
#endif
#define SOC_ISP_DE_DARKR_MAX_darkr_max_START (0)
#define SOC_ISP_DE_DARKR_MAX_darkr_max_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int darkr_min : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_DE_DARKR_MIN_UNION;
#endif
#define SOC_ISP_DE_DARKR_MIN_darkr_min_START (0)
#define SOC_ISP_DE_DARKR_MIN_darkr_min_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int darkr_v_x0 : 8;
        unsigned int darkr_v_x1 : 8;
        unsigned int darkr_s_x0 : 8;
        unsigned int darkr_s_x1 : 8;
    } reg;
} SOC_ISP_DE_DARKR_UNION;
#endif
#define SOC_ISP_DE_DARKR_darkr_v_x0_START (0)
#define SOC_ISP_DE_DARKR_darkr_v_x0_END (7)
#define SOC_ISP_DE_DARKR_darkr_v_x1_START (8)
#define SOC_ISP_DE_DARKR_darkr_v_x1_END (15)
#define SOC_ISP_DE_DARKR_darkr_s_x0_START (16)
#define SOC_ISP_DE_DARKR_darkr_s_x0_END (23)
#define SOC_ISP_DE_DARKR_darkr_s_x1_START (24)
#define SOC_ISP_DE_DARKR_darkr_s_x1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int darkr_iso_x0 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_DE_DARKR_ISO_X0_UNION;
#endif
#define SOC_ISP_DE_DARKR_ISO_X0_darkr_iso_x0_START (0)
#define SOC_ISP_DE_DARKR_ISO_X0_darkr_iso_x0_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int darkr_iso_x1 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_DE_DARKR_ISO_X1_UNION;
#endif
#define SOC_ISP_DE_DARKR_ISO_X1_darkr_iso_x1_START (0)
#define SOC_ISP_DE_DARKR_ISO_X1_darkr_iso_x1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int darkr_iso_x2 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_DE_DARKR_ISO_X2_UNION;
#endif
#define SOC_ISP_DE_DARKR_ISO_X2_darkr_iso_x2_START (0)
#define SOC_ISP_DE_DARKR_ISO_X2_darkr_iso_x2_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int darkr_iso_x3 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_DE_DARKR_ISO_X3_UNION;
#endif
#define SOC_ISP_DE_DARKR_ISO_X3_darkr_iso_x3_START (0)
#define SOC_ISP_DE_DARKR_ISO_X3_darkr_iso_x3_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int distr_max : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_DE_DISTR_MAX_UNION;
#endif
#define SOC_ISP_DE_DISTR_MAX_distr_max_START (0)
#define SOC_ISP_DE_DISTR_MAX_distr_max_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int distr_min : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_DE_DISTR_MIN_UNION;
#endif
#define SOC_ISP_DE_DISTR_MIN_distr_min_START (0)
#define SOC_ISP_DE_DISTR_MIN_distr_min_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int distr_dist_x0 : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_DE_DISTR_DIST_X0_UNION;
#endif
#define SOC_ISP_DE_DISTR_DIST_X0_distr_dist_x0_START (0)
#define SOC_ISP_DE_DISTR_DIST_X0_distr_dist_x0_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int distr_dist_x1 : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_DE_DISTR_DIST_X1_UNION;
#endif
#define SOC_ISP_DE_DISTR_DIST_X1_distr_dist_x1_START (0)
#define SOC_ISP_DE_DISTR_DIST_X1_distr_dist_x1_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int distr_iso_x0 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_DE_DISTR_ISO_X0_UNION;
#endif
#define SOC_ISP_DE_DISTR_ISO_X0_distr_iso_x0_START (0)
#define SOC_ISP_DE_DISTR_ISO_X0_distr_iso_x0_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int distr_iso_x1 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_DE_DISTR_ISO_X1_UNION;
#endif
#define SOC_ISP_DE_DISTR_ISO_X1_distr_iso_x1_START (0)
#define SOC_ISP_DE_DISTR_ISO_X1_distr_iso_x1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int distr_iso_x2 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_DE_DISTR_ISO_X2_UNION;
#endif
#define SOC_ISP_DE_DISTR_ISO_X2_distr_iso_x2_START (0)
#define SOC_ISP_DE_DISTR_ISO_X2_distr_iso_x2_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int distr_iso_x3 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_DE_DISTR_ISO_X3_UNION;
#endif
#define SOC_ISP_DE_DISTR_ISO_X3_distr_iso_x3_START (0)
#define SOC_ISP_DE_DISTR_ISO_X3_distr_iso_x3_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int distr_s_x0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_DE_DISTR_S_X0_UNION;
#endif
#define SOC_ISP_DE_DISTR_S_X0_distr_s_x0_START (0)
#define SOC_ISP_DE_DISTR_S_X0_distr_s_x0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int distr_s_x1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_DE_DISTR_S_X1_UNION;
#endif
#define SOC_ISP_DE_DISTR_S_X1_distr_s_x1_START (0)
#define SOC_ISP_DE_DISTR_S_X1_distr_s_x1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int distr_luma_x0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_DE_DISTR_LUMA_X0_UNION;
#endif
#define SOC_ISP_DE_DISTR_LUMA_X0_distr_luma_x0_START (0)
#define SOC_ISP_DE_DISTR_LUMA_X0_distr_luma_x0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int distr_luma_x1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_DE_DISTR_LUMA_X1_UNION;
#endif
#define SOC_ISP_DE_DISTR_LUMA_X1_distr_luma_x1_START (0)
#define SOC_ISP_DE_DISTR_LUMA_X1_distr_luma_x1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brightr_max : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_ISP_DE_BRIGHTR_MAX_UNION;
#endif
#define SOC_ISP_DE_BRIGHTR_MAX_brightr_max_START (0)
#define SOC_ISP_DE_BRIGHTR_MAX_brightr_max_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brightr_min : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_ISP_DE_BRIGHTR_MIN_UNION;
#endif
#define SOC_ISP_DE_BRIGHTR_MIN_brightr_min_START (0)
#define SOC_ISP_DE_BRIGHTR_MIN_brightr_min_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brightr_iso_x0 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_DE_BRIGHTR_ISO_X0_UNION;
#endif
#define SOC_ISP_DE_BRIGHTR_ISO_X0_brightr_iso_x0_START (0)
#define SOC_ISP_DE_BRIGHTR_ISO_X0_brightr_iso_x0_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brightr_iso_x1 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_DE_BRIGHTR_ISO_X1_UNION;
#endif
#define SOC_ISP_DE_BRIGHTR_ISO_X1_brightr_iso_x1_START (0)
#define SOC_ISP_DE_BRIGHTR_ISO_X1_brightr_iso_x1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brightr_v0_x0 : 8;
        unsigned int brightr_v0_x1 : 8;
        unsigned int brightr_v0_x2 : 8;
        unsigned int brightr_v0_x3 : 8;
    } reg;
} SOC_ISP_DE_BRIGHTR_V0_UNION;
#endif
#define SOC_ISP_DE_BRIGHTR_V0_brightr_v0_x0_START (0)
#define SOC_ISP_DE_BRIGHTR_V0_brightr_v0_x0_END (7)
#define SOC_ISP_DE_BRIGHTR_V0_brightr_v0_x1_START (8)
#define SOC_ISP_DE_BRIGHTR_V0_brightr_v0_x1_END (15)
#define SOC_ISP_DE_BRIGHTR_V0_brightr_v0_x2_START (16)
#define SOC_ISP_DE_BRIGHTR_V0_brightr_v0_x2_END (23)
#define SOC_ISP_DE_BRIGHTR_V0_brightr_v0_x3_START (24)
#define SOC_ISP_DE_BRIGHTR_V0_brightr_v0_x3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brightr_v1_x0 : 8;
        unsigned int brightr_v1_x1 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_DE_BRIGHTR_V1_UNION;
#endif
#define SOC_ISP_DE_BRIGHTR_V1_brightr_v1_x0_START (0)
#define SOC_ISP_DE_BRIGHTR_V1_brightr_v1_x0_END (7)
#define SOC_ISP_DE_BRIGHTR_V1_brightr_v1_x1_START (8)
#define SOC_ISP_DE_BRIGHTR_V1_brightr_v1_x1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brightr_s_x0 : 8;
        unsigned int brightr_s_x1 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_DE_BRIGHTR_S_UNION;
#endif
#define SOC_ISP_DE_BRIGHTR_S_brightr_s_x0_START (0)
#define SOC_ISP_DE_BRIGHTR_S_brightr_s_x0_END (7)
#define SOC_ISP_DE_BRIGHTR_S_brightr_s_x1_START (8)
#define SOC_ISP_DE_BRIGHTR_S_brightr_s_x1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_s_x0 : 8;
        unsigned int colorr_s_x1 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_DE_COLORR_S_X_UNION;
#endif
#define SOC_ISP_DE_COLORR_S_X_colorr_s_x0_START (0)
#define SOC_ISP_DE_COLORR_S_X_colorr_s_x0_END (7)
#define SOC_ISP_DE_COLORR_S_X_colorr_s_x1_START (8)
#define SOC_ISP_DE_COLORR_S_X_colorr_s_x1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_s_y0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int colorr_s_y1 : 7;
        unsigned int reserved_1 : 17;
    } reg;
} SOC_ISP_DE_COLORR_S_Y_UNION;
#endif
#define SOC_ISP_DE_COLORR_S_Y_colorr_s_y0_START (0)
#define SOC_ISP_DE_COLORR_S_Y_colorr_s_y0_END (6)
#define SOC_ISP_DE_COLORR_S_Y_colorr_s_y1_START (8)
#define SOC_ISP_DE_COLORR_S_Y_colorr_s_y1_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_v_x0 : 8;
        unsigned int colorr_v_x1 : 8;
        unsigned int colorr_v_y : 7;
        unsigned int reserved : 9;
    } reg;
} SOC_ISP_DE_COLORV_UNION;
#endif
#define SOC_ISP_DE_COLORV_colorr_v_x0_START (0)
#define SOC_ISP_DE_COLORV_colorr_v_x0_END (7)
#define SOC_ISP_DE_COLORV_colorr_v_x1_START (8)
#define SOC_ISP_DE_COLORV_colorr_v_x1_END (15)
#define SOC_ISP_DE_COLORV_colorr_v_y_START (16)
#define SOC_ISP_DE_COLORV_colorr_v_y_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_h0_x0 : 8;
        unsigned int colorr_h0_x1 : 8;
        unsigned int colorr_h0_y : 7;
        unsigned int reserved : 9;
    } reg;
} SOC_ISP_DE_COLORR_H0_UNION;
#endif
#define SOC_ISP_DE_COLORR_H0_colorr_h0_x0_START (0)
#define SOC_ISP_DE_COLORR_H0_colorr_h0_x0_END (7)
#define SOC_ISP_DE_COLORR_H0_colorr_h0_x1_START (8)
#define SOC_ISP_DE_COLORR_H0_colorr_h0_x1_END (15)
#define SOC_ISP_DE_COLORR_H0_colorr_h0_y_START (16)
#define SOC_ISP_DE_COLORR_H0_colorr_h0_y_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_h1_x0 : 8;
        unsigned int colorr_h1_x1 : 8;
        unsigned int colorr_h1_y : 7;
        unsigned int reserved : 9;
    } reg;
} SOC_ISP_DE_COLORR_H1_UNION;
#endif
#define SOC_ISP_DE_COLORR_H1_colorr_h1_x0_START (0)
#define SOC_ISP_DE_COLORR_H1_colorr_h1_x0_END (7)
#define SOC_ISP_DE_COLORR_H1_colorr_h1_x1_START (8)
#define SOC_ISP_DE_COLORR_H1_colorr_h1_x1_END (15)
#define SOC_ISP_DE_COLORR_H1_colorr_h1_y_START (16)
#define SOC_ISP_DE_COLORR_H1_colorr_h1_y_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_h2_x0 : 8;
        unsigned int colorr_h2_x1 : 8;
        unsigned int colorr_h2_x2 : 8;
        unsigned int colorr_h2_x3 : 8;
    } reg;
} SOC_ISP_DE_COLORR_H2_X_UNION;
#endif
#define SOC_ISP_DE_COLORR_H2_X_colorr_h2_x0_START (0)
#define SOC_ISP_DE_COLORR_H2_X_colorr_h2_x0_END (7)
#define SOC_ISP_DE_COLORR_H2_X_colorr_h2_x1_START (8)
#define SOC_ISP_DE_COLORR_H2_X_colorr_h2_x1_END (15)
#define SOC_ISP_DE_COLORR_H2_X_colorr_h2_x2_START (16)
#define SOC_ISP_DE_COLORR_H2_X_colorr_h2_x2_END (23)
#define SOC_ISP_DE_COLORR_H2_X_colorr_h2_x3_START (24)
#define SOC_ISP_DE_COLORR_H2_X_colorr_h2_x3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_h2_y : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_ISP_DE_COLORR_H2_Y_UNION;
#endif
#define SOC_ISP_DE_COLORR_H2_Y_colorr_h2_y_START (0)
#define SOC_ISP_DE_COLORR_H2_Y_colorr_h2_y_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_h3_x0 : 8;
        unsigned int colorr_h3_x1 : 8;
        unsigned int colorr_h3_x2 : 8;
        unsigned int colorr_h3_x3 : 8;
    } reg;
} SOC_ISP_DE_COLORR_H3_X_UNION;
#endif
#define SOC_ISP_DE_COLORR_H3_X_colorr_h3_x0_START (0)
#define SOC_ISP_DE_COLORR_H3_X_colorr_h3_x0_END (7)
#define SOC_ISP_DE_COLORR_H3_X_colorr_h3_x1_START (8)
#define SOC_ISP_DE_COLORR_H3_X_colorr_h3_x1_END (15)
#define SOC_ISP_DE_COLORR_H3_X_colorr_h3_x2_START (16)
#define SOC_ISP_DE_COLORR_H3_X_colorr_h3_x2_END (23)
#define SOC_ISP_DE_COLORR_H3_X_colorr_h3_x3_START (24)
#define SOC_ISP_DE_COLORR_H3_X_colorr_h3_x3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_iso : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_DE_COLORR_ISO_UNION;
#endif
#define SOC_ISP_DE_COLORR_ISO_colorr_iso_START (0)
#define SOC_ISP_DE_COLORR_ISO_colorr_iso_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_bs0_x0 : 14;
        unsigned int colorr_bs0_x1 : 14;
        unsigned int reserved : 4;
    } reg;
} SOC_ISP_DE_COLORR_BS0_X_UNION;
#endif
#define SOC_ISP_DE_COLORR_BS0_X_colorr_bs0_x0_START (0)
#define SOC_ISP_DE_COLORR_BS0_X_colorr_bs0_x0_END (13)
#define SOC_ISP_DE_COLORR_BS0_X_colorr_bs0_x1_START (14)
#define SOC_ISP_DE_COLORR_BS0_X_colorr_bs0_x1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_bs0_y : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_ISP_DE_COLORR_BS0_Y_UNION;
#endif
#define SOC_ISP_DE_COLORR_BS0_Y_colorr_bs0_y_START (0)
#define SOC_ISP_DE_COLORR_BS0_Y_colorr_bs0_y_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_bs1_x0 : 14;
        unsigned int colorr_bs1_x1 : 14;
        unsigned int reserved : 4;
    } reg;
} SOC_ISP_DE_COLORR_BS1_X_UNION;
#endif
#define SOC_ISP_DE_COLORR_BS1_X_colorr_bs1_x0_START (0)
#define SOC_ISP_DE_COLORR_BS1_X_colorr_bs1_x0_END (13)
#define SOC_ISP_DE_COLORR_BS1_X_colorr_bs1_x1_START (14)
#define SOC_ISP_DE_COLORR_BS1_X_colorr_bs1_x1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int colorr_bs1_y : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_ISP_DE_COLORR_BS1_Y_UNION;
#endif
#define SOC_ISP_DE_COLORR_BS1_Y_colorr_bs1_y_START (0)
#define SOC_ISP_DE_COLORR_BS1_Y_colorr_bs1_y_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grayr_max : 7;
        unsigned int reserved_0: 1;
        unsigned int grayr_min : 7;
        unsigned int reserved_1: 17;
    } reg;
} SOC_ISP_DE_GRAYR_UNION;
#endif
#define SOC_ISP_DE_GRAYR_grayr_max_START (0)
#define SOC_ISP_DE_GRAYR_grayr_max_END (6)
#define SOC_ISP_DE_GRAYR_grayr_min_START (8)
#define SOC_ISP_DE_GRAYR_grayr_min_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grayr_iso_x0 : 14;
        unsigned int grayr_iso_x1 : 14;
        unsigned int reserved : 4;
    } reg;
} SOC_ISP_DE_GRAYR_ISO_UNION;
#endif
#define SOC_ISP_DE_GRAYR_ISO_grayr_iso_x0_START (0)
#define SOC_ISP_DE_GRAYR_ISO_grayr_iso_x0_END (13)
#define SOC_ISP_DE_GRAYR_ISO_grayr_iso_x1_START (14)
#define SOC_ISP_DE_GRAYR_ISO_grayr_iso_x1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grayr_s_x0 : 8;
        unsigned int grayr_s_x1 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_DE_GRAYR_S_UNION;
#endif
#define SOC_ISP_DE_GRAYR_S_grayr_s_x0_START (0)
#define SOC_ISP_DE_GRAYR_S_grayr_s_x0_END (7)
#define SOC_ISP_DE_GRAYR_S_grayr_s_x1_START (8)
#define SOC_ISP_DE_GRAYR_S_grayr_s_x1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grayr_v_x0 : 8;
        unsigned int grayr_v_x1 : 8;
        unsigned int grayr_v_x2 : 8;
        unsigned int grayr_v_x3 : 8;
    } reg;
} SOC_ISP_DE_GRAYR_V_X_UNION;
#endif
#define SOC_ISP_DE_GRAYR_V_X_grayr_v_x0_START (0)
#define SOC_ISP_DE_GRAYR_V_X_grayr_v_x0_END (7)
#define SOC_ISP_DE_GRAYR_V_X_grayr_v_x1_START (8)
#define SOC_ISP_DE_GRAYR_V_X_grayr_v_x1_END (15)
#define SOC_ISP_DE_GRAYR_V_X_grayr_v_x2_START (16)
#define SOC_ISP_DE_GRAYR_V_X_grayr_v_x2_END (23)
#define SOC_ISP_DE_GRAYR_V_X_grayr_v_x3_START (24)
#define SOC_ISP_DE_GRAYR_V_X_grayr_v_x3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int white_noise_clip : 4;
        unsigned int black_noise_clip : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_DE_NOISE_CLIP_UNION;
#endif
#define SOC_ISP_DE_NOISE_CLIP_white_noise_clip_START (0)
#define SOC_ISP_DE_NOISE_CLIP_white_noise_clip_END (3)
#define SOC_ISP_DE_NOISE_CLIP_black_noise_clip_START (4)
#define SOC_ISP_DE_NOISE_CLIP_black_noise_clip_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int imgcenterx : 13;
        unsigned int imgcentery : 13;
        unsigned int reserved : 6;
    } reg;
} SOC_ISP_DE_IMGCENTER_UNION;
#endif
#define SOC_ISP_DE_IMGCENTER_imgcenterx_START (0)
#define SOC_ISP_DE_IMGCENTER_imgcenterx_END (12)
#define SOC_ISP_DE_IMGCENTER_imgcentery_START (13)
#define SOC_ISP_DE_IMGCENTER_imgcentery_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gammaslop : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_DE_GAMMASLOP_UNION;
#endif
#define SOC_ISP_DE_GAMMASLOP_gammaslop_START (0)
#define SOC_ISP_DE_GAMMASLOP_gammaslop_END (8)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

#ifndef __SOC_ISP_CGT_INTERFACE_H__
#define __SOC_ISP_CGT_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_CGT_CFG_ADDR(base) ((base) + (0x000))
#define SOC_ISP_CGT_Y_COEFF_ADDR(base) ((base) + (0x004))
#define SOC_ISP_CGT_RGB2Y_COEFF_ADDR(base,CGT_CHNL_NUM) ((base) + (0x008+0x4*(CGT_CHNL_NUM)))
#define SOC_ISP_CGT_COLOR_GAMUT_MAT_ADDR(base,CGT_MAT_NUM) ((base) + (0x014+0x4*(CGT_MAT_NUM)))
#define SOC_ISP_CGT_RANGE_EXTEND_RATIO_ADDR(base,CGT_HLR_PARAM_NUM) ((base) + (0x038+0x4*(CGT_HLR_PARAM_NUM)))
#define SOC_ISP_CGT_Y_COM_ADDR(base,CGT_HLR_PARAM_NUM) ((base) + (0x1B8+0x4*(CGT_HLR_PARAM_NUM)))
#define SOC_ISP_CGT_CHECK_ADDR(base) ((base) + (0x338))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bcgt_frame : 1;
        unsigned int bpixyconst : 1;
        unsigned int hlr_clip_mode : 2;
        unsigned int bcgt_hlr : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_CGT_CFG_UNION;
#endif
#define SOC_ISP_CGT_CFG_bcgt_frame_START (0)
#define SOC_ISP_CGT_CFG_bcgt_frame_END (0)
#define SOC_ISP_CGT_CFG_bpixyconst_START (1)
#define SOC_ISP_CGT_CFG_bpixyconst_END (1)
#define SOC_ISP_CGT_CFG_hlr_clip_mode_START (2)
#define SOC_ISP_CGT_CFG_hlr_clip_mode_END (3)
#define SOC_ISP_CGT_CFG_bcgt_hlr_START (4)
#define SOC_ISP_CGT_CFG_bcgt_hlr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pix_ycoef_val : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ISP_CGT_Y_COEFF_UNION;
#endif
#define SOC_ISP_CGT_Y_COEFF_pix_ycoef_val_START (0)
#define SOC_ISP_CGT_Y_COEFF_pix_ycoef_val_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rgb2ycoeff : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_CGT_RGB2Y_COEFF_UNION;
#endif
#define SOC_ISP_CGT_RGB2Y_COEFF_rgb2ycoeff_START (0)
#define SOC_ISP_CGT_RGB2Y_COEFF_rgb2ycoeff_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cgt_mat : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_CGT_COLOR_GAMUT_MAT_UNION;
#endif
#define SOC_ISP_CGT_COLOR_GAMUT_MAT_cgt_mat_START (0)
#define SOC_ISP_CGT_COLOR_GAMUT_MAT_cgt_mat_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int exrange_min_ratio : 11;
        unsigned int reserved_0 : 5;
        unsigned int exrange_max_ratio : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_ISP_CGT_RANGE_EXTEND_RATIO_UNION;
#endif
#define SOC_ISP_CGT_RANGE_EXTEND_RATIO_exrange_min_ratio_START (0)
#define SOC_ISP_CGT_RANGE_EXTEND_RATIO_exrange_min_ratio_END (10)
#define SOC_ISP_CGT_RANGE_EXTEND_RATIO_exrange_max_ratio_START (16)
#define SOC_ISP_CGT_RANGE_EXTEND_RATIO_exrange_max_ratio_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clip_ycom_neg : 9;
        unsigned int reserved_0 : 7;
        unsigned int clip_ycom_pos : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_ISP_CGT_Y_COM_UNION;
#endif
#define SOC_ISP_CGT_Y_COM_clip_ycom_neg_START (0)
#define SOC_ISP_CGT_Y_COM_clip_ycom_neg_END (8)
#define SOC_ISP_CGT_Y_COM_clip_ycom_pos_START (16)
#define SOC_ISP_CGT_Y_COM_clip_ycom_pos_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int check1 : 1;
        unsigned int check2 : 1;
        unsigned int check3 : 1;
        unsigned int check4 : 1;
        unsigned int check5 : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_CGT_CHECK_UNION;
#endif
#define SOC_ISP_CGT_CHECK_check1_START (0)
#define SOC_ISP_CGT_CHECK_check1_END (0)
#define SOC_ISP_CGT_CHECK_check2_START (1)
#define SOC_ISP_CGT_CHECK_check2_END (1)
#define SOC_ISP_CGT_CHECK_check3_START (2)
#define SOC_ISP_CGT_CHECK_check3_END (2)
#define SOC_ISP_CGT_CHECK_check4_START (3)
#define SOC_ISP_CGT_CHECK_check4_END (3)
#define SOC_ISP_CGT_CHECK_check5_START (4)
#define SOC_ISP_CGT_CHECK_check5_END (4)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

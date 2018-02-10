#ifndef __SOC_ISP_CC_INTERFACE_H__
#define __SOC_ISP_CC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_CC_CCCFG_ADDR(base) ((base) + (0x000))
#define SOC_ISP_CC_RGB_MAX_CLIP_ADDR(base,CC_CHNL_NUM) ((base) + (0x004+0x4*(CC_CHNL_NUM)))
#define SOC_ISP_CC_FRAME_SIZE_ADDR(base) ((base) + (0x010))
#define SOC_ISP_CC_PIX_OFST_ADDR(base) ((base) + (0x014))
#define SOC_ISP_CC_PIX_FACTOR_ADDR(base) ((base) + (0x018))
#define SOC_ISP_CC_CCMATRIX_ADDR(base,CCM_MAT_NUM) ((base) + (0x01C+4*(CCM_MAT_NUM)))
#define SOC_ISP_CC_RGB2YCOEF_ADDR(base,CC_CHNL_NUM) ((base) + (0x040+0x4*(CC_CHNL_NUM)))
#define SOC_ISP_CC_RAD_BIT_SHIFT_ADDR(base) ((base) + (0x4C))
#define SOC_ISP_CC_FCR_CHL_CLIP_ADDR(base,CC_CHNL_NUM) ((base) + (0x50+0x4*(CC_CHNL_NUM)))
#define SOC_ISP_CC_FCR_POS_ADDR(base) ((base) + (0x5C))
#define SOC_ISP_CC_FCR_NEG_ADDR(base) ((base) + (0x60))
#define SOC_ISP_CC_FCR_RDIF_ADDR(base) ((base) + (0x64))
#define SOC_ISP_CC_FCR_BDIF_ADDR(base) ((base) + (0x68))
#define SOC_ISP_CC_PIX_YCOEF_ADDR(base) ((base) + (0x6C))
#define SOC_ISP_CC_HLR_CLIP_MODE_ADDR(base) ((base) + (0x70))
#define SOC_ISP_CC_CLIP_YCOM_ADDR(base,CC_LOCATION_RANGE) ((base) + (0x74+0x4*(CC_LOCATION_RANGE)))
#define SOC_ISP_CC_EXRANGE_RATIO_ADDR(base,CC_LOCATION_RANGE) ((base) + (0x1F4+0x4*(CC_LOCATION_RANGE)))
#define SOC_ISP_CC_RADMAXMATRIXODD01_ADDR(base,CC_RAD_SEGM_NUM) ((base) + (0x400+0x4*(CC_RAD_SEGM_NUM)))
#define SOC_ISP_CC_RADMAXMATRIXEVEN01_ADDR(base,CC_RAD_SEGM_NUM) ((base) + (0x600+0x4*(CC_RAD_SEGM_NUM)))
#define SOC_ISP_CC_RADMAXMATRIXODD2_ADDR(base,CC_RAD_SEGM_NUM) ((base) + (0x800+0x4*(CC_RAD_SEGM_NUM)))
#define SOC_ISP_CC_RADMAXMATRIXEVEN2_ADDR(base,CC_RAD_SEGM_NUM) ((base) + (0xA00+0x4*(CC_RAD_SEGM_NUM)))
#define SOC_ISP_CC_RADSCALEMATRIXODD01_ADDR(base,CC_RAD_SEGM_NUM) ((base) + (0xC00+0x4*(CC_RAD_SEGM_NUM)))
#define SOC_ISP_CC_RADSCALEMATRIXEVEN1_ADDR(base,CC_RAD_SEGM_NUM) ((base) + (0xE00+0x4*(CC_RAD_SEGM_NUM)))
#define SOC_ISP_CC_RADSCALEMATRIXODD2_ADDR(base,CC_RAD_SEGM_NUM) ((base) + (0x1000+0x4*(CC_RAD_SEGM_NUM)))
#define SOC_ISP_CC_RADSCALEMATRIXEVEN2_ADDR(base,CC_RAD_SEGM_NUM) ((base) + (0x1200+0x4*(CC_RAD_SEGM_NUM)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bcc_frame : 1;
        unsigned int bcc_clip : 1;
        unsigned int bcc_fcr : 1;
        unsigned int bpixyconst : 1;
        unsigned int bcc_hlr : 1;
        unsigned int bfcr_ykpt : 1;
        unsigned int bfcr_clip : 1;
        unsigned int reserved : 24;
        unsigned int force_clk_on : 1;
    } reg;
} SOC_ISP_CC_CCCFG_UNION;
#endif
#define SOC_ISP_CC_CCCFG_bcc_frame_START (0)
#define SOC_ISP_CC_CCCFG_bcc_frame_END (0)
#define SOC_ISP_CC_CCCFG_bcc_clip_START (1)
#define SOC_ISP_CC_CCCFG_bcc_clip_END (1)
#define SOC_ISP_CC_CCCFG_bcc_fcr_START (2)
#define SOC_ISP_CC_CCCFG_bcc_fcr_END (2)
#define SOC_ISP_CC_CCCFG_bpixyconst_START (3)
#define SOC_ISP_CC_CCCFG_bpixyconst_END (3)
#define SOC_ISP_CC_CCCFG_bcc_hlr_START (4)
#define SOC_ISP_CC_CCCFG_bcc_hlr_END (4)
#define SOC_ISP_CC_CCCFG_bfcr_ykpt_START (5)
#define SOC_ISP_CC_CCCFG_bfcr_ykpt_END (5)
#define SOC_ISP_CC_CCCFG_bfcr_clip_START (6)
#define SOC_ISP_CC_CCCFG_bfcr_clip_END (6)
#define SOC_ISP_CC_CCCFG_force_clk_on_START (31)
#define SOC_ISP_CC_CCCFG_force_clk_on_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rgb_max_clip : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_CC_RGB_MAX_CLIP_UNION;
#endif
#define SOC_ISP_CC_RGB_MAX_CLIP_rgb_max_clip_START (0)
#define SOC_ISP_CC_RGB_MAX_CLIP_rgb_max_clip_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int frame_height : 14;
        unsigned int reserved_0 : 2;
        unsigned int frame_width : 14;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_ISP_CC_FRAME_SIZE_UNION;
#endif
#define SOC_ISP_CC_FRAME_SIZE_frame_height_START (0)
#define SOC_ISP_CC_FRAME_SIZE_frame_height_END (13)
#define SOC_ISP_CC_FRAME_SIZE_frame_width_START (16)
#define SOC_ISP_CC_FRAME_SIZE_frame_width_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pix_xofst : 14;
        unsigned int reserved_0: 2;
        unsigned int pix_yofst : 14;
        unsigned int reserved_1: 2;
    } reg;
} SOC_ISP_CC_PIX_OFST_UNION;
#endif
#define SOC_ISP_CC_PIX_OFST_pix_xofst_START (0)
#define SOC_ISP_CC_PIX_OFST_pix_xofst_END (13)
#define SOC_ISP_CC_PIX_OFST_pix_yofst_START (16)
#define SOC_ISP_CC_PIX_OFST_pix_yofst_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pix_xdiv_factor : 16;
        unsigned int pix_ydiv_factor : 16;
    } reg;
} SOC_ISP_CC_PIX_FACTOR_UNION;
#endif
#define SOC_ISP_CC_PIX_FACTOR_pix_xdiv_factor_START (0)
#define SOC_ISP_CC_PIX_FACTOR_pix_xdiv_factor_END (15)
#define SOC_ISP_CC_PIX_FACTOR_pix_ydiv_factor_START (16)
#define SOC_ISP_CC_PIX_FACTOR_pix_ydiv_factor_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccm : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_CC_CCMATRIX_UNION;
#endif
#define SOC_ISP_CC_CCMATRIX_ccm_START (0)
#define SOC_ISP_CC_CCMATRIX_ccm_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rgb2ycoeff : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_CC_RGB2YCOEF_UNION;
#endif
#define SOC_ISP_CC_RGB2YCOEF_rgb2ycoeff_START (0)
#define SOC_ISP_CC_RGB2YCOEF_rgb2ycoeff_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rad_bit_shift : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_CC_RAD_BIT_SHIFT_UNION;
#endif
#define SOC_ISP_CC_RAD_BIT_SHIFT_rad_bit_shift_START (0)
#define SOC_ISP_CC_RAD_BIT_SHIFT_rad_bit_shift_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int chl_clip_ofst : 16;
        unsigned int chl_clip_factor : 13;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_CC_FCR_CHL_CLIP_UNION;
#endif
#define SOC_ISP_CC_FCR_CHL_CLIP_chl_clip_ofst_START (0)
#define SOC_ISP_CC_FCR_CHL_CLIP_chl_clip_ofst_END (15)
#define SOC_ISP_CC_FCR_CHL_CLIP_chl_clip_factor_START (16)
#define SOC_ISP_CC_FCR_CHL_CLIP_chl_clip_factor_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pos_ofst : 16;
        unsigned int pos_factor : 13;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_CC_FCR_POS_UNION;
#endif
#define SOC_ISP_CC_FCR_POS_pos_ofst_START (0)
#define SOC_ISP_CC_FCR_POS_pos_ofst_END (15)
#define SOC_ISP_CC_FCR_POS_pos_factor_START (16)
#define SOC_ISP_CC_FCR_POS_pos_factor_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int neg_ofst : 16;
        unsigned int neg_factor : 13;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_CC_FCR_NEG_UNION;
#endif
#define SOC_ISP_CC_FCR_NEG_neg_ofst_START (0)
#define SOC_ISP_CC_FCR_NEG_neg_ofst_END (15)
#define SOC_ISP_CC_FCR_NEG_neg_factor_START (16)
#define SOC_ISP_CC_FCR_NEG_neg_factor_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdif_base : 11;
        unsigned int reserved_0 : 5;
        unsigned int rdif_factor : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CC_FCR_RDIF_UNION;
#endif
#define SOC_ISP_CC_FCR_RDIF_rdif_base_START (0)
#define SOC_ISP_CC_FCR_RDIF_rdif_base_END (10)
#define SOC_ISP_CC_FCR_RDIF_rdif_factor_START (16)
#define SOC_ISP_CC_FCR_RDIF_rdif_factor_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bdif_base : 11;
        unsigned int reserved_0 : 5;
        unsigned int bdif_factor : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CC_FCR_BDIF_UNION;
#endif
#define SOC_ISP_CC_FCR_BDIF_bdif_base_START (0)
#define SOC_ISP_CC_FCR_BDIF_bdif_base_END (10)
#define SOC_ISP_CC_FCR_BDIF_bdif_factor_START (16)
#define SOC_ISP_CC_FCR_BDIF_bdif_factor_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pix_ycoef_val : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ISP_CC_PIX_YCOEF_UNION;
#endif
#define SOC_ISP_CC_PIX_YCOEF_pix_ycoef_val_START (0)
#define SOC_ISP_CC_PIX_YCOEF_pix_ycoef_val_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hlr_clip_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_ISP_CC_HLR_CLIP_MODE_UNION;
#endif
#define SOC_ISP_CC_HLR_CLIP_MODE_hlr_clip_mode_START (0)
#define SOC_ISP_CC_HLR_CLIP_MODE_hlr_clip_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clip_ycom_pos : 9;
        unsigned int reserved_0 : 7;
        unsigned int clip_ycom_neg : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_ISP_CC_CLIP_YCOM_UNION;
#endif
#define SOC_ISP_CC_CLIP_YCOM_clip_ycom_pos_START (0)
#define SOC_ISP_CC_CLIP_YCOM_clip_ycom_pos_END (8)
#define SOC_ISP_CC_CLIP_YCOM_clip_ycom_neg_START (16)
#define SOC_ISP_CC_CLIP_YCOM_clip_ycom_neg_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int exrange_max_ratio : 11;
        unsigned int reserved_0 : 5;
        unsigned int exrange_min_ratio : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_ISP_CC_EXRANGE_RATIO_UNION;
#endif
#define SOC_ISP_CC_EXRANGE_RATIO_exrange_max_ratio_START (0)
#define SOC_ISP_CC_EXRANGE_RATIO_exrange_max_ratio_END (10)
#define SOC_ISP_CC_EXRANGE_RATIO_exrange_min_ratio_START (16)
#define SOC_ISP_CC_EXRANGE_RATIO_exrange_min_ratio_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rad_max_vec_odd_0 : 16;
        unsigned int rad_max_vec_odd_1 : 16;
    } reg;
} SOC_ISP_CC_RADMAXMATRIXODD01_UNION;
#endif
#define SOC_ISP_CC_RADMAXMATRIXODD01_rad_max_vec_odd_0_START (0)
#define SOC_ISP_CC_RADMAXMATRIXODD01_rad_max_vec_odd_0_END (15)
#define SOC_ISP_CC_RADMAXMATRIXODD01_rad_max_vec_odd_1_START (16)
#define SOC_ISP_CC_RADMAXMATRIXODD01_rad_max_vec_odd_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rad_max_vec_even_0 : 16;
        unsigned int rad_max_vec_even_1 : 16;
    } reg;
} SOC_ISP_CC_RADMAXMATRIXEVEN01_UNION;
#endif
#define SOC_ISP_CC_RADMAXMATRIXEVEN01_rad_max_vec_even_0_START (0)
#define SOC_ISP_CC_RADMAXMATRIXEVEN01_rad_max_vec_even_0_END (15)
#define SOC_ISP_CC_RADMAXMATRIXEVEN01_rad_max_vec_even_1_START (16)
#define SOC_ISP_CC_RADMAXMATRIXEVEN01_rad_max_vec_even_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rad_max_vec_odd_2 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_CC_RADMAXMATRIXODD2_UNION;
#endif
#define SOC_ISP_CC_RADMAXMATRIXODD2_rad_max_vec_odd_2_START (0)
#define SOC_ISP_CC_RADMAXMATRIXODD2_rad_max_vec_odd_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rad_max_vec_even_2 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_CC_RADMAXMATRIXEVEN2_UNION;
#endif
#define SOC_ISP_CC_RADMAXMATRIXEVEN2_rad_max_vec_even_2_START (0)
#define SOC_ISP_CC_RADMAXMATRIXEVEN2_rad_max_vec_even_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rad_scale_vec_odd_0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int rad_scale_vec_odd_1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CC_RADSCALEMATRIXODD01_UNION;
#endif
#define SOC_ISP_CC_RADSCALEMATRIXODD01_rad_scale_vec_odd_0_START (0)
#define SOC_ISP_CC_RADSCALEMATRIXODD01_rad_scale_vec_odd_0_END (12)
#define SOC_ISP_CC_RADSCALEMATRIXODD01_rad_scale_vec_odd_1_START (16)
#define SOC_ISP_CC_RADSCALEMATRIXODD01_rad_scale_vec_odd_1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rad_scale_vec_even_0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int rad_scale_vec_even_1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CC_RADSCALEMATRIXEVEN1_UNION;
#endif
#define SOC_ISP_CC_RADSCALEMATRIXEVEN1_rad_scale_vec_even_0_START (0)
#define SOC_ISP_CC_RADSCALEMATRIXEVEN1_rad_scale_vec_even_0_END (12)
#define SOC_ISP_CC_RADSCALEMATRIXEVEN1_rad_scale_vec_even_1_START (16)
#define SOC_ISP_CC_RADSCALEMATRIXEVEN1_rad_scale_vec_even_1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rad_scale_vec_odd_2 : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_CC_RADSCALEMATRIXODD2_UNION;
#endif
#define SOC_ISP_CC_RADSCALEMATRIXODD2_rad_scale_vec_odd_2_START (0)
#define SOC_ISP_CC_RADSCALEMATRIXODD2_rad_scale_vec_odd_2_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rad_scale_vec_even_2 : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_CC_RADSCALEMATRIXEVEN2_UNION;
#endif
#define SOC_ISP_CC_RADSCALEMATRIXEVEN2_rad_scale_vec_even_2_START (0)
#define SOC_ISP_CC_RADSCALEMATRIXEVEN2_rad_scale_vec_even_2_END (12)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

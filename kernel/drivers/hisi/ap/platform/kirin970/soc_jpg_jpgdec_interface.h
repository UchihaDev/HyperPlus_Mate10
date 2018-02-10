#ifndef __SOC_JPG_JPGDEC_INTERFACE_H__
#define __SOC_JPG_JPGDEC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_JPG_JPGDEC_JPEG_DEC_START_ADDR(base) ((base) + (0x0))
#define SOC_JPG_JPGDEC_PREFTCH_CTRL_ADDR(base) ((base) + (0x4))
#define SOC_JPG_JPGDEC_FRAME_SIZE_ADDR(base) ((base) + (0x8))
#define SOC_JPG_JPGDEC_CROP_HORIZONTAL_ADDR(base) ((base) + (0xC))
#define SOC_JPG_JPGDEC_CROP_VERTICAL_ADDR(base) ((base) + (0x10))
#define SOC_JPG_JPGDEC_BITSTREAMS_START_ADDR(base) ((base) + (0x14))
#define SOC_JPG_JPGDEC_BITSTREAMS_END_ADDR(base) ((base) + (0x18))
#define SOC_JPG_JPGDEC_FRAME_START_Y_ADDR(base) ((base) + (0x1C))
#define SOC_JPG_JPGDEC_FRAME_STRIDE_Y_ADDR(base) ((base) + (0x20))
#define SOC_JPG_JPGDEC_FRAME_START_C_ADDR(base) ((base) + (0x24))
#define SOC_JPG_JPGDEC_FRAME_STRIDE_C_ADDR(base) ((base) + (0x28))
#define SOC_JPG_JPGDEC_LBUF_START_ADDR_ADDR(base) ((base) + (0x2C))
#define SOC_JPG_JPGDEC_OUTPUT_TYPE_ADDR(base) ((base) + (0x30))
#define SOC_JPG_JPGDEC_FREQ_SCALE_ADDR(base) ((base) + (0x34))
#define SOC_JPG_JPGDEC_MIDDLE_FILTER_ADDR(base) ((base) + (0x38))
#define SOC_JPG_JPGDEC_SAMPLING_FACTOR_ADDR(base) ((base) + (0x3C))
#define SOC_JPG_JPGDEC_DRI_ADDR(base) ((base) + (0x40))
#define SOC_JPG_JPGDEC_OVER_TIME_THD_ADDR(base) ((base) + (0x4C))
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF01_ADDR(base) ((base) + (0x80))
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF23_ADDR(base) ((base) + (0x84))
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF45_ADDR(base) ((base) + (0x88))
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF67_ADDR(base) ((base) + (0x8C))
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF01_ADDR(base) ((base) + (0x90))
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF23_ADDR(base) ((base) + (0x94))
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF45_ADDR(base) ((base) + (0x98))
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF67_ADDR(base) ((base) + (0x9C))
#define SOC_JPG_JPGDEC_VER_PHASE0_COEF01_ADDR(base) ((base) + (0xA0))
#define SOC_JPG_JPGDEC_VER_PHASE0_COEF23_ADDR(base) ((base) + (0xA4))
#define SOC_JPG_JPGDEC_VER_PHASE2_COEF01_ADDR(base) ((base) + (0xA8))
#define SOC_JPG_JPGDEC_VER_PHASE2_COEF23_ADDR(base) ((base) + (0xAC))
#define SOC_JPG_JPGDEC_CSC_IN_DC_COEF_ADDR(base) ((base) + (0xB0))
#define SOC_JPG_JPGDEC_CSC_OUT_DC_COEF_ADDR(base) ((base) + (0xB4))
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF0_ADDR(base) ((base) + (0xB8))
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF1_ADDR(base) ((base) + (0xBC))
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF2_ADDR(base) ((base) + (0xC0))
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF3_ADDR(base) ((base) + (0xC4))
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF4_ADDR(base) ((base) + (0xC8))
#define SOC_JPG_JPGDEC_QUANT_TABLE_ADDR(base,qt_range) ((base) + (0x200+0x4*(qt_range)))
#define SOC_JPG_JPGDEC_HDC_TABLE_ADDR(base,hdc_range) ((base) + (0x300+0x4*(hdc_range)))
#define SOC_JPG_JPGDEC_HAC_MIN_TABLE_ADDR(base,hac_range) ((base) + (0x340+0x4*(hac_range)))
#define SOC_JPG_JPGDEC_HAC_BASE_TABLE_ADDR(base,hac_range) ((base) + (0x380+0x4*(hac_range)))
#define SOC_JPG_JPGDEC_HAC_SYMBOL_TABLE_ADDR(base,rs_range) ((base) + (0x400+0x4*(rs_range)))
#define SOC_JPG_JPGDEC_DEBUG_ADDR(base,dbg_range) ((base) + (0x800+0x4*(dbg_range)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int decode_start : 1;
        unsigned int resume_start : 1;
        unsigned int last_resume : 1;
        unsigned int reserved : 28;
        unsigned int ck_gt_en : 1;
    } reg;
} SOC_JPG_JPGDEC_JPEG_DEC_START_UNION;
#endif
#define SOC_JPG_JPGDEC_JPEG_DEC_START_decode_start_START (0)
#define SOC_JPG_JPGDEC_JPEG_DEC_START_decode_start_END (0)
#define SOC_JPG_JPGDEC_JPEG_DEC_START_resume_start_START (1)
#define SOC_JPG_JPGDEC_JPEG_DEC_START_resume_start_END (1)
#define SOC_JPG_JPGDEC_JPEG_DEC_START_last_resume_START (2)
#define SOC_JPG_JPGDEC_JPEG_DEC_START_last_resume_END (2)
#define SOC_JPG_JPGDEC_JPEG_DEC_START_ck_gt_en_START (31)
#define SOC_JPG_JPGDEC_JPEG_DEC_START_ck_gt_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prefetch_bypass : 1;
        unsigned int reserved_0 : 15;
        unsigned int prefetch_delay : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_PREFTCH_CTRL_UNION;
#endif
#define SOC_JPG_JPGDEC_PREFTCH_CTRL_prefetch_bypass_START (0)
#define SOC_JPG_JPGDEC_PREFTCH_CTRL_prefetch_bypass_END (0)
#define SOC_JPG_JPGDEC_PREFTCH_CTRL_prefetch_delay_START (16)
#define SOC_JPG_JPGDEC_PREFTCH_CTRL_prefetch_delay_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pix_width : 16;
        unsigned int pix_height : 16;
    } reg;
} SOC_JPG_JPGDEC_FRAME_SIZE_UNION;
#endif
#define SOC_JPG_JPGDEC_FRAME_SIZE_pix_width_START (0)
#define SOC_JPG_JPGDEC_FRAME_SIZE_pix_width_END (15)
#define SOC_JPG_JPGDEC_FRAME_SIZE_pix_height_START (16)
#define SOC_JPG_JPGDEC_FRAME_SIZE_pix_height_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pix_start_hor : 16;
        unsigned int pix_end_hor : 16;
    } reg;
} SOC_JPG_JPGDEC_CROP_HORIZONTAL_UNION;
#endif
#define SOC_JPG_JPGDEC_CROP_HORIZONTAL_pix_start_hor_START (0)
#define SOC_JPG_JPGDEC_CROP_HORIZONTAL_pix_start_hor_END (15)
#define SOC_JPG_JPGDEC_CROP_HORIZONTAL_pix_end_hor_START (16)
#define SOC_JPG_JPGDEC_CROP_HORIZONTAL_pix_end_hor_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pix_start_ver : 16;
        unsigned int pix_end_ver : 16;
    } reg;
} SOC_JPG_JPGDEC_CROP_VERTICAL_UNION;
#endif
#define SOC_JPG_JPGDEC_CROP_VERTICAL_pix_start_ver_START (0)
#define SOC_JPG_JPGDEC_CROP_VERTICAL_pix_start_ver_END (15)
#define SOC_JPG_JPGDEC_CROP_VERTICAL_pix_end_ver_START (16)
#define SOC_JPG_JPGDEC_CROP_VERTICAL_pix_end_ver_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitstr_start_addr : 32;
    } reg;
} SOC_JPG_JPGDEC_BITSTREAMS_START_UNION;
#endif
#define SOC_JPG_JPGDEC_BITSTREAMS_START_bitstr_start_addr_START (0)
#define SOC_JPG_JPGDEC_BITSTREAMS_START_bitstr_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitstr_end_addr : 32;
    } reg;
} SOC_JPG_JPGDEC_BITSTREAMS_END_UNION;
#endif
#define SOC_JPG_JPGDEC_BITSTREAMS_END_bitstr_end_addr_START (0)
#define SOC_JPG_JPGDEC_BITSTREAMS_END_bitstr_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int start_addr_y : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_JPG_JPGDEC_FRAME_START_Y_UNION;
#endif
#define SOC_JPG_JPGDEC_FRAME_START_Y_start_addr_y_START (0)
#define SOC_JPG_JPGDEC_FRAME_START_Y_start_addr_y_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stride_y : 12;
        unsigned int last_page_y : 17;
        unsigned int reserved : 3;
    } reg;
} SOC_JPG_JPGDEC_FRAME_STRIDE_Y_UNION;
#endif
#define SOC_JPG_JPGDEC_FRAME_STRIDE_Y_stride_y_START (0)
#define SOC_JPG_JPGDEC_FRAME_STRIDE_Y_stride_y_END (11)
#define SOC_JPG_JPGDEC_FRAME_STRIDE_Y_last_page_y_START (12)
#define SOC_JPG_JPGDEC_FRAME_STRIDE_Y_last_page_y_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int start_addr_c : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_JPG_JPGDEC_FRAME_START_C_UNION;
#endif
#define SOC_JPG_JPGDEC_FRAME_START_C_start_addr_c_START (0)
#define SOC_JPG_JPGDEC_FRAME_START_C_start_addr_c_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stride_c : 12;
        unsigned int last_page_c : 17;
        unsigned int reserved : 3;
    } reg;
} SOC_JPG_JPGDEC_FRAME_STRIDE_C_UNION;
#endif
#define SOC_JPG_JPGDEC_FRAME_STRIDE_C_stride_c_START (0)
#define SOC_JPG_JPGDEC_FRAME_STRIDE_C_stride_c_END (11)
#define SOC_JPG_JPGDEC_FRAME_STRIDE_C_last_page_c_START (12)
#define SOC_JPG_JPGDEC_FRAME_STRIDE_C_last_page_c_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int start_addr_lb : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_JPG_JPGDEC_LBUF_START_ADDR_UNION;
#endif
#define SOC_JPG_JPGDEC_LBUF_START_ADDR_start_addr_lb_START (0)
#define SOC_JPG_JPGDEC_LBUF_START_ADDR_start_addr_lb_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int output_type : 4;
        unsigned int uv_swap : 1;
        unsigned int reserved_0 : 3;
        unsigned int rgb_alpha : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_JPG_JPGDEC_OUTPUT_TYPE_UNION;
#endif
#define SOC_JPG_JPGDEC_OUTPUT_TYPE_output_type_START (0)
#define SOC_JPG_JPGDEC_OUTPUT_TYPE_output_type_END (3)
#define SOC_JPG_JPGDEC_OUTPUT_TYPE_uv_swap_START (4)
#define SOC_JPG_JPGDEC_OUTPUT_TYPE_uv_swap_END (4)
#define SOC_JPG_JPGDEC_OUTPUT_TYPE_rgb_alpha_START (8)
#define SOC_JPG_JPGDEC_OUTPUT_TYPE_rgb_alpha_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_scale : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_JPG_JPGDEC_FREQ_SCALE_UNION;
#endif
#define SOC_JPG_JPGDEC_FREQ_SCALE_freq_scale_START (0)
#define SOC_JPG_JPGDEC_FREQ_SCALE_freq_scale_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hor_mid_en : 1;
        unsigned int ver_mid_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_JPG_JPGDEC_MIDDLE_FILTER_UNION;
#endif
#define SOC_JPG_JPGDEC_MIDDLE_FILTER_hor_mid_en_START (0)
#define SOC_JPG_JPGDEC_MIDDLE_FILTER_hor_mid_en_END (0)
#define SOC_JPG_JPGDEC_MIDDLE_FILTER_ver_mid_en_START (1)
#define SOC_JPG_JPGDEC_MIDDLE_FILTER_ver_mid_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int v_fac : 8;
        unsigned int u_fac : 8;
        unsigned int y_fac : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_JPG_JPGDEC_SAMPLING_FACTOR_UNION;
#endif
#define SOC_JPG_JPGDEC_SAMPLING_FACTOR_v_fac_START (0)
#define SOC_JPG_JPGDEC_SAMPLING_FACTOR_v_fac_END (7)
#define SOC_JPG_JPGDEC_SAMPLING_FACTOR_u_fac_START (8)
#define SOC_JPG_JPGDEC_SAMPLING_FACTOR_u_fac_END (15)
#define SOC_JPG_JPGDEC_SAMPLING_FACTOR_y_fac_START (16)
#define SOC_JPG_JPGDEC_SAMPLING_FACTOR_y_fac_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dri : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_JPG_JPGDEC_DRI_UNION;
#endif
#define SOC_JPG_JPGDEC_DRI_dri_START (0)
#define SOC_JPG_JPGDEC_DRI_dri_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int over_time_thr : 32;
    } reg;
} SOC_JPG_JPGDEC_OVER_TIME_THD_UNION;
#endif
#define SOC_JPG_JPGDEC_OVER_TIME_THD_over_time_thr_START (0)
#define SOC_JPG_JPGDEC_OVER_TIME_THD_over_time_thr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hor_phase0_coef0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hor_phase0_coef1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_HOR_PHASE0_COEF01_UNION;
#endif
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF01_hor_phase0_coef0_START (0)
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF01_hor_phase0_coef0_END (9)
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF01_hor_phase0_coef1_START (16)
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF01_hor_phase0_coef1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hor_phase0_coef2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hor_phase0_coef3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_HOR_PHASE0_COEF23_UNION;
#endif
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF23_hor_phase0_coef2_START (0)
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF23_hor_phase0_coef2_END (9)
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF23_hor_phase0_coef3_START (16)
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF23_hor_phase0_coef3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hor_phase0_coef4 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hor_phase0_coef5 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_HOR_PHASE0_COEF45_UNION;
#endif
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF45_hor_phase0_coef4_START (0)
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF45_hor_phase0_coef4_END (9)
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF45_hor_phase0_coef5_START (16)
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF45_hor_phase0_coef5_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hor_phase0_coef6 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hor_phase0_coef7 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_HOR_PHASE0_COEF67_UNION;
#endif
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF67_hor_phase0_coef6_START (0)
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF67_hor_phase0_coef6_END (9)
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF67_hor_phase0_coef7_START (16)
#define SOC_JPG_JPGDEC_HOR_PHASE0_COEF67_hor_phase0_coef7_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hor_phase2_coef0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hor_phase2_coef1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_HOR_PHASE2_COEF01_UNION;
#endif
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF01_hor_phase2_coef0_START (0)
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF01_hor_phase2_coef0_END (9)
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF01_hor_phase2_coef1_START (16)
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF01_hor_phase2_coef1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hor_phase2_coef2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hor_phase2_coef3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_HOR_PHASE2_COEF23_UNION;
#endif
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF23_hor_phase2_coef2_START (0)
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF23_hor_phase2_coef2_END (9)
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF23_hor_phase2_coef3_START (16)
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF23_hor_phase2_coef3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hor_phase2_coef4 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hor_phase2_coef5 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_HOR_PHASE2_COEF45_UNION;
#endif
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF45_hor_phase2_coef4_START (0)
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF45_hor_phase2_coef4_END (9)
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF45_hor_phase2_coef5_START (16)
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF45_hor_phase2_coef5_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hor_phase2_coef6 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hor_phase2_coef7 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_HOR_PHASE2_COEF67_UNION;
#endif
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF67_hor_phase2_coef6_START (0)
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF67_hor_phase2_coef6_END (9)
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF67_hor_phase2_coef7_START (16)
#define SOC_JPG_JPGDEC_HOR_PHASE2_COEF67_hor_phase2_coef7_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ver_phase0_coef0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int ver_phase0_coef1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_VER_PHASE0_COEF01_UNION;
#endif
#define SOC_JPG_JPGDEC_VER_PHASE0_COEF01_ver_phase0_coef0_START (0)
#define SOC_JPG_JPGDEC_VER_PHASE0_COEF01_ver_phase0_coef0_END (9)
#define SOC_JPG_JPGDEC_VER_PHASE0_COEF01_ver_phase0_coef1_START (16)
#define SOC_JPG_JPGDEC_VER_PHASE0_COEF01_ver_phase0_coef1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ver_phase0_coef2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int ver_phase0_coef3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_VER_PHASE0_COEF23_UNION;
#endif
#define SOC_JPG_JPGDEC_VER_PHASE0_COEF23_ver_phase0_coef2_START (0)
#define SOC_JPG_JPGDEC_VER_PHASE0_COEF23_ver_phase0_coef2_END (9)
#define SOC_JPG_JPGDEC_VER_PHASE0_COEF23_ver_phase0_coef3_START (16)
#define SOC_JPG_JPGDEC_VER_PHASE0_COEF23_ver_phase0_coef3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ver_phase2_coef0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int ver_phase2_coef1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_VER_PHASE2_COEF01_UNION;
#endif
#define SOC_JPG_JPGDEC_VER_PHASE2_COEF01_ver_phase2_coef0_START (0)
#define SOC_JPG_JPGDEC_VER_PHASE2_COEF01_ver_phase2_coef0_END (9)
#define SOC_JPG_JPGDEC_VER_PHASE2_COEF01_ver_phase2_coef1_START (16)
#define SOC_JPG_JPGDEC_VER_PHASE2_COEF01_ver_phase2_coef1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ver_phase2_coef2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int ver_phase2_coef3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_JPG_JPGDEC_VER_PHASE2_COEF23_UNION;
#endif
#define SOC_JPG_JPGDEC_VER_PHASE2_COEF23_ver_phase2_coef2_START (0)
#define SOC_JPG_JPGDEC_VER_PHASE2_COEF23_ver_phase2_coef2_END (9)
#define SOC_JPG_JPGDEC_VER_PHASE2_COEF23_ver_phase2_coef3_START (16)
#define SOC_JPG_JPGDEC_VER_PHASE2_COEF23_ver_phase2_coef3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_in_dc_coef0 : 9;
        unsigned int reserved_0 : 1;
        unsigned int csc_in_dc_coef1 : 9;
        unsigned int reserved_1 : 1;
        unsigned int csc_in_dc_coef2 : 9;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_JPG_JPGDEC_CSC_IN_DC_COEF_UNION;
#endif
#define SOC_JPG_JPGDEC_CSC_IN_DC_COEF_csc_in_dc_coef0_START (0)
#define SOC_JPG_JPGDEC_CSC_IN_DC_COEF_csc_in_dc_coef0_END (8)
#define SOC_JPG_JPGDEC_CSC_IN_DC_COEF_csc_in_dc_coef1_START (10)
#define SOC_JPG_JPGDEC_CSC_IN_DC_COEF_csc_in_dc_coef1_END (18)
#define SOC_JPG_JPGDEC_CSC_IN_DC_COEF_csc_in_dc_coef2_START (20)
#define SOC_JPG_JPGDEC_CSC_IN_DC_COEF_csc_in_dc_coef2_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_out_dc_coef0 : 9;
        unsigned int reserved_0 : 1;
        unsigned int csc_out_dc_coef1 : 9;
        unsigned int reserved_1 : 1;
        unsigned int csc_out_dc_coef2 : 9;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_JPG_JPGDEC_CSC_OUT_DC_COEF_UNION;
#endif
#define SOC_JPG_JPGDEC_CSC_OUT_DC_COEF_csc_out_dc_coef0_START (0)
#define SOC_JPG_JPGDEC_CSC_OUT_DC_COEF_csc_out_dc_coef0_END (8)
#define SOC_JPG_JPGDEC_CSC_OUT_DC_COEF_csc_out_dc_coef1_START (10)
#define SOC_JPG_JPGDEC_CSC_OUT_DC_COEF_csc_out_dc_coef1_END (18)
#define SOC_JPG_JPGDEC_CSC_OUT_DC_COEF_csc_out_dc_coef2_START (20)
#define SOC_JPG_JPGDEC_CSC_OUT_DC_COEF_csc_out_dc_coef2_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p_00 : 15;
        unsigned int reserved_0: 1;
        unsigned int csc_p_01 : 15;
        unsigned int reserved_1: 1;
    } reg;
} SOC_JPG_JPGDEC_CSC_TRANS_COEF0_UNION;
#endif
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF0_csc_p_00_START (0)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF0_csc_p_00_END (14)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF0_csc_p_01_START (16)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF0_csc_p_01_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p_02 : 15;
        unsigned int reserved_0: 1;
        unsigned int csc_p_10 : 15;
        unsigned int reserved_1: 1;
    } reg;
} SOC_JPG_JPGDEC_CSC_TRANS_COEF1_UNION;
#endif
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF1_csc_p_02_START (0)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF1_csc_p_02_END (14)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF1_csc_p_10_START (16)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF1_csc_p_10_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p_11 : 15;
        unsigned int reserved_0: 1;
        unsigned int csc_p_12 : 15;
        unsigned int reserved_1: 1;
    } reg;
} SOC_JPG_JPGDEC_CSC_TRANS_COEF2_UNION;
#endif
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF2_csc_p_11_START (0)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF2_csc_p_11_END (14)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF2_csc_p_12_START (16)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF2_csc_p_12_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p_20 : 15;
        unsigned int reserved_0: 1;
        unsigned int csc_p_21 : 15;
        unsigned int reserved_1: 1;
    } reg;
} SOC_JPG_JPGDEC_CSC_TRANS_COEF3_UNION;
#endif
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF3_csc_p_20_START (0)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF3_csc_p_20_END (14)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF3_csc_p_21_START (16)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF3_csc_p_21_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p_22 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_JPG_JPGDEC_CSC_TRANS_COEF4_UNION;
#endif
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF4_csc_p_22_START (0)
#define SOC_JPG_JPGDEC_CSC_TRANS_COEF4_csc_p_22_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qtab_y : 8;
        unsigned int qtab_cb : 8;
        unsigned int qtab_cr : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_JPG_JPGDEC_QUANT_TABLE_UNION;
#endif
#define SOC_JPG_JPGDEC_QUANT_TABLE_qtab_y_START (0)
#define SOC_JPG_JPGDEC_QUANT_TABLE_qtab_y_END (7)
#define SOC_JPG_JPGDEC_QUANT_TABLE_qtab_cb_START (8)
#define SOC_JPG_JPGDEC_QUANT_TABLE_qtab_cb_END (15)
#define SOC_JPG_JPGDEC_QUANT_TABLE_qtab_cr_START (16)
#define SOC_JPG_JPGDEC_QUANT_TABLE_qtab_cr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdc_lu : 12;
        unsigned int hdc_ch : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_JPG_JPGDEC_HDC_TABLE_UNION;
#endif
#define SOC_JPG_JPGDEC_HDC_TABLE_hdc_lu_START (0)
#define SOC_JPG_JPGDEC_HDC_TABLE_hdc_lu_END (11)
#define SOC_JPG_JPGDEC_HDC_TABLE_hdc_ch_START (12)
#define SOC_JPG_JPGDEC_HDC_TABLE_hdc_ch_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hac_lu_mincode_even : 8;
        unsigned int hac_lu_mincode_odd : 8;
        unsigned int hac_ch_mincode_even : 8;
        unsigned int hac_ch_mincode_odd : 8;
    } reg;
} SOC_JPG_JPGDEC_HAC_MIN_TABLE_UNION;
#endif
#define SOC_JPG_JPGDEC_HAC_MIN_TABLE_hac_lu_mincode_even_START (0)
#define SOC_JPG_JPGDEC_HAC_MIN_TABLE_hac_lu_mincode_even_END (7)
#define SOC_JPG_JPGDEC_HAC_MIN_TABLE_hac_lu_mincode_odd_START (8)
#define SOC_JPG_JPGDEC_HAC_MIN_TABLE_hac_lu_mincode_odd_END (15)
#define SOC_JPG_JPGDEC_HAC_MIN_TABLE_hac_ch_mincode_even_START (16)
#define SOC_JPG_JPGDEC_HAC_MIN_TABLE_hac_ch_mincode_even_END (23)
#define SOC_JPG_JPGDEC_HAC_MIN_TABLE_hac_ch_mincode_odd_START (24)
#define SOC_JPG_JPGDEC_HAC_MIN_TABLE_hac_ch_mincode_odd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hac_lu_base_even : 8;
        unsigned int hac_lu_base_odd : 8;
        unsigned int hac_ch_base_even : 8;
        unsigned int hac_ch_base_odd : 8;
    } reg;
} SOC_JPG_JPGDEC_HAC_BASE_TABLE_UNION;
#endif
#define SOC_JPG_JPGDEC_HAC_BASE_TABLE_hac_lu_base_even_START (0)
#define SOC_JPG_JPGDEC_HAC_BASE_TABLE_hac_lu_base_even_END (7)
#define SOC_JPG_JPGDEC_HAC_BASE_TABLE_hac_lu_base_odd_START (8)
#define SOC_JPG_JPGDEC_HAC_BASE_TABLE_hac_lu_base_odd_END (15)
#define SOC_JPG_JPGDEC_HAC_BASE_TABLE_hac_ch_base_even_START (16)
#define SOC_JPG_JPGDEC_HAC_BASE_TABLE_hac_ch_base_even_END (23)
#define SOC_JPG_JPGDEC_HAC_BASE_TABLE_hac_ch_base_odd_START (24)
#define SOC_JPG_JPGDEC_HAC_BASE_TABLE_hac_ch_base_odd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rs_lu : 8;
        unsigned int rs_ch : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_JPG_JPGDEC_HAC_SYMBOL_TABLE_UNION;
#endif
#define SOC_JPG_JPGDEC_HAC_SYMBOL_TABLE_rs_lu_START (0)
#define SOC_JPG_JPGDEC_HAC_SYMBOL_TABLE_rs_lu_END (7)
#define SOC_JPG_JPGDEC_HAC_SYMBOL_TABLE_rs_ch_START (8)
#define SOC_JPG_JPGDEC_HAC_SYMBOL_TABLE_rs_ch_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_info : 32;
    } reg;
} SOC_JPG_JPGDEC_DEBUG_UNION;
#endif
#define SOC_JPG_JPGDEC_DEBUG_debug_info_START (0)
#define SOC_JPG_JPGDEC_DEBUG_debug_info_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

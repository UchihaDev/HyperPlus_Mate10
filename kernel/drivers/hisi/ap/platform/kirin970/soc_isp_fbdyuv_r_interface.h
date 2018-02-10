#ifndef __SOC_ISP_FBDYUV_R_INTERFACE_H__
#define __SOC_ISP_FBDYUV_R_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_FBDYUV_R_FBD_CFG_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_FBDYUV_R_FBD_CROP_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_FBDYUV_R_FBD_STATUS_ADDR(base) ((base) + (0x0008))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int clk_force_on : 1;
        unsigned int color_mode : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_FBDYUV_R_FBD_CFG_UNION;
#endif
#define SOC_ISP_FBDYUV_R_FBD_CFG_bypass_START (0)
#define SOC_ISP_FBDYUV_R_FBD_CFG_bypass_END (0)
#define SOC_ISP_FBDYUV_R_FBD_CFG_clk_force_on_START (1)
#define SOC_ISP_FBDYUV_R_FBD_CFG_clk_force_on_END (1)
#define SOC_ISP_FBDYUV_R_FBD_CFG_color_mode_START (2)
#define SOC_ISP_FBDYUV_R_FBD_CFG_color_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cleft : 10;
        unsigned int reserved_0: 6;
        unsigned int cright : 11;
        unsigned int reserved_1: 5;
    } reg;
} SOC_ISP_FBDYUV_R_FBD_CROP_UNION;
#endif
#define SOC_ISP_FBDYUV_R_FBD_CROP_cleft_START (0)
#define SOC_ISP_FBDYUV_R_FBD_CROP_cleft_END (9)
#define SOC_ISP_FBDYUV_R_FBD_CROP_cright_START (16)
#define SOC_ISP_FBDYUV_R_FBD_CROP_cright_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stream_error : 1;
        unsigned int size_error : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ISP_FBDYUV_R_FBD_STATUS_UNION;
#endif
#define SOC_ISP_FBDYUV_R_FBD_STATUS_stream_error_START (0)
#define SOC_ISP_FBDYUV_R_FBD_STATUS_stream_error_END (0)
#define SOC_ISP_FBDYUV_R_FBD_STATUS_size_error_START (1)
#define SOC_ISP_FBDYUV_R_FBD_STATUS_size_error_END (1)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

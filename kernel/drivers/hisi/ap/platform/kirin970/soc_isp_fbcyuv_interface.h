#ifndef __SOC_ISP_FBCYUV_INTERFACE_H__
#define __SOC_ISP_FBCYUV_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_FBCYUV_FBC_CFG_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_FBCYUV_FBC_CROP_ADDR(base) ((base) + (0x0004))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int clk_force_on : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ISP_FBCYUV_FBC_CFG_UNION;
#endif
#define SOC_ISP_FBCYUV_FBC_CFG_bypass_START (0)
#define SOC_ISP_FBCYUV_FBC_CFG_bypass_END (0)
#define SOC_ISP_FBCYUV_FBC_CFG_clk_force_on_START (1)
#define SOC_ISP_FBCYUV_FBC_CFG_clk_force_on_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cleft : 10;
        unsigned int reserved_0: 6;
        unsigned int cright : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_ISP_FBCYUV_FBC_CROP_UNION;
#endif
#define SOC_ISP_FBCYUV_FBC_CROP_cleft_START (0)
#define SOC_ISP_FBCYUV_FBC_CROP_cleft_END (9)
#define SOC_ISP_FBCYUV_FBC_CROP_cright_START (16)
#define SOC_ISP_FBCYUV_FBC_CROP_cright_END (25)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

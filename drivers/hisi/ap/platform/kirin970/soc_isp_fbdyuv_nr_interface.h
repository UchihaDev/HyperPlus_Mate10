#ifndef __SOC_ISP_FBDYUV_NR_INTERFACE_H__
#define __SOC_ISP_FBDYUV_NR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_FBDYUV_NR_FBD_CFG_ADDR(base) ((base) + (0x0000))
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
} SOC_ISP_FBDYUV_NR_FBD_CFG_UNION;
#endif
#define SOC_ISP_FBDYUV_NR_FBD_CFG_bypass_START (0)
#define SOC_ISP_FBDYUV_NR_FBD_CFG_bypass_END (0)
#define SOC_ISP_FBDYUV_NR_FBD_CFG_clk_force_on_START (1)
#define SOC_ISP_FBDYUV_NR_FBD_CFG_clk_force_on_END (1)
#define SOC_ISP_FBDYUV_NR_FBD_CFG_color_mode_START (2)
#define SOC_ISP_FBDYUV_NR_FBD_CFG_color_mode_END (2)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

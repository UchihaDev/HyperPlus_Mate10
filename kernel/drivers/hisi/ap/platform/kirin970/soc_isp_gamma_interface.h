#ifndef __SOC_ISP_GAMMA_INTERFACE_H__
#define __SOC_ISP_GAMMA_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_GAMMA_GAMMA_CONFIG_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_GAMMA_GAMMA_OUT_R_0_ADDR(base,Range96) ((base) + (0x0100+0x4*(Range96)))
#define SOC_ISP_GAMMA_GAMMA_OUT_G_0_ADDR(base,Range96) ((base) + (0x0300+0x4*(Range96)))
#define SOC_ISP_GAMMA_GAMMA_OUT_B_0_ADDR(base,Range96) ((base) + (0x0500+0x4*(Range96)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int channel_flag : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ISP_GAMMA_GAMMA_CONFIG_UNION;
#endif
#define SOC_ISP_GAMMA_GAMMA_CONFIG_bypass_START (0)
#define SOC_ISP_GAMMA_GAMMA_CONFIG_bypass_END (0)
#define SOC_ISP_GAMMA_GAMMA_CONFIG_channel_flag_START (1)
#define SOC_ISP_GAMMA_GAMMA_CONFIG_channel_flag_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_out_r : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_GAMMA_GAMMA_OUT_R_0_UNION;
#endif
#define SOC_ISP_GAMMA_GAMMA_OUT_R_0_gamma_out_r_START (0)
#define SOC_ISP_GAMMA_GAMMA_OUT_R_0_gamma_out_r_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_out_g : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_GAMMA_GAMMA_OUT_G_0_UNION;
#endif
#define SOC_ISP_GAMMA_GAMMA_OUT_G_0_gamma_out_g_START (0)
#define SOC_ISP_GAMMA_GAMMA_OUT_G_0_gamma_out_g_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_out_b : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_GAMMA_GAMMA_OUT_B_0_UNION;
#endif
#define SOC_ISP_GAMMA_GAMMA_OUT_B_0_gamma_out_b_START (0)
#define SOC_ISP_GAMMA_GAMMA_OUT_B_0_gamma_out_b_END (9)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

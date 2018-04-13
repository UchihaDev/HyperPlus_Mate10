#ifndef __SOC_ISP_PRESCALER_INTERFACE_H__
#define __SOC_ISP_PRESCALER_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_PRESCALER_HCROP_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_PRESCALER_VCROP_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_PRESCALER_MODE_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_PRESCALER_FORCE_CLK_ON_CFG_ADDR(base) ((base) + (0x00C))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihright : 13;
        unsigned int ihleft : 13;
        unsigned int reserved : 6;
    } reg;
} SOC_ISP_PRESCALER_HCROP_UNION;
#endif
#define SOC_ISP_PRESCALER_HCROP_ihright_START (0)
#define SOC_ISP_PRESCALER_HCROP_ihright_END (12)
#define SOC_ISP_PRESCALER_HCROP_ihleft_START (13)
#define SOC_ISP_PRESCALER_HCROP_ihleft_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivbottom : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_PRESCALER_VCROP_UNION;
#endif
#define SOC_ISP_PRESCALER_VCROP_ivbottom_START (0)
#define SOC_ISP_PRESCALER_VCROP_ivbottom_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_PRESCALER_MODE_UNION;
#endif
#define SOC_ISP_PRESCALER_MODE_bypass_START (0)
#define SOC_ISP_PRESCALER_MODE_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_clk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_PRESCALER_FORCE_CLK_ON_CFG_UNION;
#endif
#define SOC_ISP_PRESCALER_FORCE_CLK_ON_CFG_force_clk_on_START (0)
#define SOC_ISP_PRESCALER_FORCE_CLK_ON_CFG_force_clk_on_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

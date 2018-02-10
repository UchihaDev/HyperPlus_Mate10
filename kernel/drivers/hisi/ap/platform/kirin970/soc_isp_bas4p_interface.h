#ifndef __SOC_ISP_BAS4P_INTERFACE_H__
#define __SOC_ISP_BAS4P_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_BAS4P_BAS_MODE_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_BAS4P_BAS_IHLEFT_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_BAS4P_BAS_IHRIGHT_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_BAS4P_BAS_IVTOP_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_BAS4P_BAS_IVBOTTOM_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_BAS4P_BAS_IHINC_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_BAS4P_BAS_IVINC_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_BAS4P_BAS_COEF_ACTIVE_ADDR(base) ((base) + (0x001C))
#define SOC_ISP_BAS4P_FORCE_CLK_ON_CFG_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_BAS4P_BAS_H_COEF_0_ADDR(base,PHASEX2) ((base) + (0x0100+0x4*(PHASEX2)))
#define SOC_ISP_BAS4P_BAS_H_COEF_1_ADDR(base,PHASEX2) ((base) + (0x0128+0x4*(PHASEX2)))
#define SOC_ISP_BAS4P_BAS_V_COEF_0_ADDR(base,PHASEX2) ((base) + (0x0200+0x4*(PHASEX2)))
#define SOC_ISP_BAS4P_BAS_V_COEF_1_ADDR(base,PHASEX2) ((base) + (0x0228+0x4*(PHASEX2)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 3;
        unsigned int demosaic_off : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_BAS4P_BAS_MODE_UNION;
#endif
#define SOC_ISP_BAS4P_BAS_MODE_mode_START (0)
#define SOC_ISP_BAS4P_BAS_MODE_mode_END (2)
#define SOC_ISP_BAS4P_BAS_MODE_demosaic_off_START (3)
#define SOC_ISP_BAS4P_BAS_MODE_demosaic_off_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihleft : 32;
    } reg;
} SOC_ISP_BAS4P_BAS_IHLEFT_UNION;
#endif
#define SOC_ISP_BAS4P_BAS_IHLEFT_ihleft_START (0)
#define SOC_ISP_BAS4P_BAS_IHLEFT_ihleft_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihright : 32;
    } reg;
} SOC_ISP_BAS4P_BAS_IHRIGHT_UNION;
#endif
#define SOC_ISP_BAS4P_BAS_IHRIGHT_ihright_START (0)
#define SOC_ISP_BAS4P_BAS_IHRIGHT_ihright_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivtop : 32;
    } reg;
} SOC_ISP_BAS4P_BAS_IVTOP_UNION;
#endif
#define SOC_ISP_BAS4P_BAS_IVTOP_ivtop_START (0)
#define SOC_ISP_BAS4P_BAS_IVTOP_ivtop_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivbottom : 32;
    } reg;
} SOC_ISP_BAS4P_BAS_IVBOTTOM_UNION;
#endif
#define SOC_ISP_BAS4P_BAS_IVBOTTOM_ivbottom_START (0)
#define SOC_ISP_BAS4P_BAS_IVBOTTOM_ivbottom_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihinc : 22;
        unsigned int reserved_0: 6;
        unsigned int padding : 2;
        unsigned int reserved_1: 2;
    } reg;
} SOC_ISP_BAS4P_BAS_IHINC_UNION;
#endif
#define SOC_ISP_BAS4P_BAS_IHINC_ihinc_START (0)
#define SOC_ISP_BAS4P_BAS_IHINC_ihinc_END (21)
#define SOC_ISP_BAS4P_BAS_IHINC_padding_START (28)
#define SOC_ISP_BAS4P_BAS_IHINC_padding_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivinc : 22;
        unsigned int reserved_0 : 1;
        unsigned int halflinemode : 1;
        unsigned int quarterlinemode : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_ISP_BAS4P_BAS_IVINC_UNION;
#endif
#define SOC_ISP_BAS4P_BAS_IVINC_ivinc_START (0)
#define SOC_ISP_BAS4P_BAS_IVINC_ivinc_END (21)
#define SOC_ISP_BAS4P_BAS_IVINC_halflinemode_START (23)
#define SOC_ISP_BAS4P_BAS_IVINC_halflinemode_END (23)
#define SOC_ISP_BAS4P_BAS_IVINC_quarterlinemode_START (24)
#define SOC_ISP_BAS4P_BAS_IVINC_quarterlinemode_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int h_coef_active : 1;
        unsigned int v_coef_active : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ISP_BAS4P_BAS_COEF_ACTIVE_UNION;
#endif
#define SOC_ISP_BAS4P_BAS_COEF_ACTIVE_h_coef_active_START (0)
#define SOC_ISP_BAS4P_BAS_COEF_ACTIVE_h_coef_active_END (0)
#define SOC_ISP_BAS4P_BAS_COEF_ACTIVE_v_coef_active_START (1)
#define SOC_ISP_BAS4P_BAS_COEF_ACTIVE_v_coef_active_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_clk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_BAS4P_FORCE_CLK_ON_CFG_UNION;
#endif
#define SOC_ISP_BAS4P_FORCE_CLK_ON_CFG_force_clk_on_START (0)
#define SOC_ISP_BAS4P_FORCE_CLK_ON_CFG_force_clk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int htap_coef0_0_7 : 8;
        unsigned int htap_coef0_1_6 : 8;
        unsigned int htap_coef0_2_5 : 8;
        unsigned int htap_coef0_3_4 : 8;
    } reg;
} SOC_ISP_BAS4P_BAS_H_COEF_0_UNION;
#endif
#define SOC_ISP_BAS4P_BAS_H_COEF_0_htap_coef0_0_7_START (0)
#define SOC_ISP_BAS4P_BAS_H_COEF_0_htap_coef0_0_7_END (7)
#define SOC_ISP_BAS4P_BAS_H_COEF_0_htap_coef0_1_6_START (8)
#define SOC_ISP_BAS4P_BAS_H_COEF_0_htap_coef0_1_6_END (15)
#define SOC_ISP_BAS4P_BAS_H_COEF_0_htap_coef0_2_5_START (16)
#define SOC_ISP_BAS4P_BAS_H_COEF_0_htap_coef0_2_5_END (23)
#define SOC_ISP_BAS4P_BAS_H_COEF_0_htap_coef0_3_4_START (24)
#define SOC_ISP_BAS4P_BAS_H_COEF_0_htap_coef0_3_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int htap_coef1_0_7 : 8;
        unsigned int htap_coef1_1_6 : 8;
        unsigned int htap_coef1_2_5 : 8;
        unsigned int htap_coef1_3_4 : 8;
    } reg;
} SOC_ISP_BAS4P_BAS_H_COEF_1_UNION;
#endif
#define SOC_ISP_BAS4P_BAS_H_COEF_1_htap_coef1_0_7_START (0)
#define SOC_ISP_BAS4P_BAS_H_COEF_1_htap_coef1_0_7_END (7)
#define SOC_ISP_BAS4P_BAS_H_COEF_1_htap_coef1_1_6_START (8)
#define SOC_ISP_BAS4P_BAS_H_COEF_1_htap_coef1_1_6_END (15)
#define SOC_ISP_BAS4P_BAS_H_COEF_1_htap_coef1_2_5_START (16)
#define SOC_ISP_BAS4P_BAS_H_COEF_1_htap_coef1_2_5_END (23)
#define SOC_ISP_BAS4P_BAS_H_COEF_1_htap_coef1_3_4_START (24)
#define SOC_ISP_BAS4P_BAS_H_COEF_1_htap_coef1_3_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vtap_coef0_0_7 : 8;
        unsigned int vtap_coef0_1_6 : 8;
        unsigned int vtap_coef0_2_5 : 8;
        unsigned int vtap_coef0_3_4 : 8;
    } reg;
} SOC_ISP_BAS4P_BAS_V_COEF_0_UNION;
#endif
#define SOC_ISP_BAS4P_BAS_V_COEF_0_vtap_coef0_0_7_START (0)
#define SOC_ISP_BAS4P_BAS_V_COEF_0_vtap_coef0_0_7_END (7)
#define SOC_ISP_BAS4P_BAS_V_COEF_0_vtap_coef0_1_6_START (8)
#define SOC_ISP_BAS4P_BAS_V_COEF_0_vtap_coef0_1_6_END (15)
#define SOC_ISP_BAS4P_BAS_V_COEF_0_vtap_coef0_2_5_START (16)
#define SOC_ISP_BAS4P_BAS_V_COEF_0_vtap_coef0_2_5_END (23)
#define SOC_ISP_BAS4P_BAS_V_COEF_0_vtap_coef0_3_4_START (24)
#define SOC_ISP_BAS4P_BAS_V_COEF_0_vtap_coef0_3_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vtap_coef1_0_7 : 8;
        unsigned int vtap_coef1_1_6 : 8;
        unsigned int vtap_coef1_2_5 : 8;
        unsigned int vtap_coef1_3_4 : 8;
    } reg;
} SOC_ISP_BAS4P_BAS_V_COEF_1_UNION;
#endif
#define SOC_ISP_BAS4P_BAS_V_COEF_1_vtap_coef1_0_7_START (0)
#define SOC_ISP_BAS4P_BAS_V_COEF_1_vtap_coef1_0_7_END (7)
#define SOC_ISP_BAS4P_BAS_V_COEF_1_vtap_coef1_1_6_START (8)
#define SOC_ISP_BAS4P_BAS_V_COEF_1_vtap_coef1_1_6_END (15)
#define SOC_ISP_BAS4P_BAS_V_COEF_1_vtap_coef1_2_5_START (16)
#define SOC_ISP_BAS4P_BAS_V_COEF_1_vtap_coef1_2_5_END (23)
#define SOC_ISP_BAS4P_BAS_V_COEF_1_vtap_coef1_3_4_START (24)
#define SOC_ISP_BAS4P_BAS_V_COEF_1_vtap_coef1_3_4_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

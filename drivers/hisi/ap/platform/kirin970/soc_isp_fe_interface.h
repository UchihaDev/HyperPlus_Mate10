#ifndef __SOC_ISP_FE_INTERFACE_H__
#define __SOC_ISP_FE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_FE_FCLK_EN_FE_ADDR(base) ((base) + (0x0))
#define SOC_ISP_FE_CONTROL_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_FE_BRIDGE_4TO2_CONTROL_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_FE_CROP_H_1_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_FE_CROP_V_1_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_FE_ACQ_H_OFFSET_ADDR(base) ((base) + (0x0030))
#define SOC_ISP_FE_ACQ_V_OFFSET_ADDR(base) ((base) + (0x0034))
#define SOC_ISP_FE_ACQ_H_SIZE_ADDR(base) ((base) + (0x0038))
#define SOC_ISP_FE_ACQ_V_SIZE_ADDR(base) ((base) + (0x003C))
#define SOC_ISP_FE_OUT_H_OFFSET_ADDR(base) ((base) + (0x0040))
#define SOC_ISP_FE_OUT_V_OFFSET_ADDR(base) ((base) + (0x0044))
#define SOC_ISP_FE_OUT_H_SIZE_ADDR(base) ((base) + (0x0048))
#define SOC_ISP_FE_OUT_V_SIZE_ADDR(base) ((base) + (0x004C))
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_ADDR(base) ((base) + (0x0050))
#define SOC_ISP_FE_RAWNF_DS_1_CONTROL_ADDR(base) ((base) + (0x0060))
#define SOC_ISP_FE_RAWNF_DS_1_DBG_ADDR(base) ((base) + (0x0064))
#define SOC_ISP_FE_RAWNF_DS_2_CONTROL_ADDR(base) ((base) + (0x0070))
#define SOC_ISP_FE_RAWNF_DS_2_DBG_ADDR(base) ((base) + (0x0074))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fclk_en_fe : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_FE_FCLK_EN_FE_UNION;
#endif
#define SOC_ISP_FE_FCLK_EN_FE_fclk_en_fe_START (0)
#define SOC_ISP_FE_FCLK_EN_FE_fclk_en_fe_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 2;
        unsigned int bayer_pat_fe : 2;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ff_before_pdaf : 1;
        unsigned int reserved_4 : 24;
    } reg;
} SOC_ISP_FE_CONTROL_UNION;
#endif
#define SOC_ISP_FE_CONTROL_bayer_pat_fe_START (3)
#define SOC_ISP_FE_CONTROL_bayer_pat_fe_END (4)
#define SOC_ISP_FE_CONTROL_ff_before_pdaf_START (7)
#define SOC_ISP_FE_CONTROL_ff_before_pdaf_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int B4TO2_2_enable : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_ISP_FE_BRIDGE_4TO2_CONTROL_UNION;
#endif
#define SOC_ISP_FE_BRIDGE_4TO2_CONTROL_B4TO2_2_enable_START (1)
#define SOC_ISP_FE_BRIDGE_4TO2_CONTROL_B4TO2_2_enable_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihleft : 13;
        unsigned int reserved_0: 3;
        unsigned int ihright : 13;
        unsigned int reserved_1: 3;
    } reg;
} SOC_ISP_FE_CROP_H_1_UNION;
#endif
#define SOC_ISP_FE_CROP_H_1_ihleft_START (0)
#define SOC_ISP_FE_CROP_H_1_ihleft_END (12)
#define SOC_ISP_FE_CROP_H_1_ihright_START (16)
#define SOC_ISP_FE_CROP_H_1_ihright_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivtop : 13;
        unsigned int reserved_0: 3;
        unsigned int ivbottom : 13;
        unsigned int reserved_1: 3;
    } reg;
} SOC_ISP_FE_CROP_V_1_UNION;
#endif
#define SOC_ISP_FE_CROP_V_1_ivtop_START (0)
#define SOC_ISP_FE_CROP_V_1_ivtop_END (12)
#define SOC_ISP_FE_CROP_V_1_ivbottom_START (16)
#define SOC_ISP_FE_CROP_V_1_ivbottom_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_ACQ_H_OFFSET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_ACQ_V_OFFSET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_ACQ_H_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_ACQ_V_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_OUT_H_OFFSET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_OUT_V_OFFSET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_OUT_H_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_OUT_V_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_clk_on_blc_1 : 1;
        unsigned int force_clk_on_dgamma_1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int force_clk_on_stat3a_1 : 1;
        unsigned int force_clk_on_statdis_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int force_clk_on_bas_1 : 1;
        unsigned int force_clk_on_fe_top : 1;
        unsigned int force_clk_on_pdaf_1 : 1;
        unsigned int force_clk_on_autocls_1 : 1;
        unsigned int force_clk_on_blc_2 : 1;
        unsigned int force_clk_on_rawnf_ds_1 : 1;
        unsigned int force_clk_on_rawnf_ds_2 : 1;
        unsigned int reserved_3 : 18;
    } reg;
} SOC_ISP_FE_FORCE_CLK_ON_CFG_UNION;
#endif
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_blc_1_START (0)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_blc_1_END (0)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_dgamma_1_START (1)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_dgamma_1_END (1)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_stat3a_1_START (4)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_stat3a_1_END (4)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_statdis_1_START (5)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_statdis_1_END (5)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_bas_1_START (7)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_bas_1_END (7)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_fe_top_START (8)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_fe_top_END (8)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_pdaf_1_START (9)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_pdaf_1_END (9)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_autocls_1_START (10)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_autocls_1_END (10)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_blc_2_START (11)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_blc_2_END (11)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_rawnf_ds_1_START (12)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_rawnf_ds_1_END (12)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_rawnf_ds_2_START (13)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_rawnf_ds_2_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Enable : 1;
        unsigned int mono : 1;
        unsigned int reserved_0: 14;
        unsigned int height : 13;
        unsigned int reserved_1: 3;
    } reg;
} SOC_ISP_FE_RAWNF_DS_1_CONTROL_UNION;
#endif
#define SOC_ISP_FE_RAWNF_DS_1_CONTROL_Enable_START (0)
#define SOC_ISP_FE_RAWNF_DS_1_CONTROL_Enable_END (0)
#define SOC_ISP_FE_RAWNF_DS_1_CONTROL_mono_START (1)
#define SOC_ISP_FE_RAWNF_DS_1_CONTROL_mono_END (1)
#define SOC_ISP_FE_RAWNF_DS_1_CONTROL_height_START (16)
#define SOC_ISP_FE_RAWNF_DS_1_CONTROL_height_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int error : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_FE_RAWNF_DS_1_DBG_UNION;
#endif
#define SOC_ISP_FE_RAWNF_DS_1_DBG_error_START (0)
#define SOC_ISP_FE_RAWNF_DS_1_DBG_error_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Enable : 1;
        unsigned int mono : 1;
        unsigned int reserved_0: 14;
        unsigned int height : 13;
        unsigned int reserved_1: 3;
    } reg;
} SOC_ISP_FE_RAWNF_DS_2_CONTROL_UNION;
#endif
#define SOC_ISP_FE_RAWNF_DS_2_CONTROL_Enable_START (0)
#define SOC_ISP_FE_RAWNF_DS_2_CONTROL_Enable_END (0)
#define SOC_ISP_FE_RAWNF_DS_2_CONTROL_mono_START (1)
#define SOC_ISP_FE_RAWNF_DS_2_CONTROL_mono_END (1)
#define SOC_ISP_FE_RAWNF_DS_2_CONTROL_height_START (16)
#define SOC_ISP_FE_RAWNF_DS_2_CONTROL_height_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int error : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_FE_RAWNF_DS_2_DBG_UNION;
#endif
#define SOC_ISP_FE_RAWNF_DS_2_DBG_error_START (0)
#define SOC_ISP_FE_RAWNF_DS_2_DBG_error_END (4)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

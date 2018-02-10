#ifndef __SOC_ISP_SCALER_INTERFACE_H__
#define __SOC_ISP_SCALER_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_SCALER_IHLEFT_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_SCALER_IHRIGHT_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_SCALER_UV_HOFFSET_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_SCALER_IVTOP_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_SCALER_IVBOTTOM_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_SCALER_UV_VOFFSET_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_SCALER_IHINC_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_SCALER_IVINC_ADDR(base) ((base) + (0x001C))
#define SOC_ISP_SCALER_BYPASS_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_SCALER_FORMAT_ADDR(base) ((base) + (0x0028))
#define SOC_ISP_SCALER_IH_HPOS_ADDR(base) ((base) + (0x0034))
#define SOC_ISP_SCALER_IV_HPOS_ADDR(base) ((base) + (0x0038))
#define SOC_ISP_SCALER_IH_VPOS_ADDR(base) ((base) + (0x003C))
#define SOC_ISP_SCALER_IV_VPOS_ADDR(base) ((base) + (0x0040))
#define SOC_ISP_SCALER_FORCE_CLK_ON_CFG_ADDR(base) ((base) + (0x50))
#define SOC_ISP_SCALER_COEFF_H_Y0_ADDR(base,range8) ((base) + (0x60+0x4*(range8)))
#define SOC_ISP_SCALER_COEFF_H_Y1_ADDR(base,range8) ((base) + (0x80+0x4*(range8)))
#define SOC_ISP_SCALER_COEFF_V_Y0_ADDR(base,range8) ((base) + (0xA0+0x4*(range8)))
#define SOC_ISP_SCALER_COEFF_V_Y1_ADDR(base,range8) ((base) + (0xC0+0x4*(range8)))
#define SOC_ISP_SCALER_COEFF_H_UV0_ADDR(base,range8) ((base) + (0xE0+0x4*(range8)))
#define SOC_ISP_SCALER_COEFF_H_UV1_ADDR(base,range8) ((base) + (0x100+0x4*(range8)))
#define SOC_ISP_SCALER_COEFF_V_UV0_ADDR(base,range8) ((base) + (0x120+0x4*(range8)))
#define SOC_ISP_SCALER_COEFF_V_UV1_ADDR(base,range8) ((base) + (0x140+0x4*(range8)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihleft : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_SCALER_IHLEFT_UNION;
#endif
#define SOC_ISP_SCALER_IHLEFT_ihleft_START (0)
#define SOC_ISP_SCALER_IHLEFT_ihleft_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihright : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_SCALER_IHRIGHT_UNION;
#endif
#define SOC_ISP_SCALER_IHRIGHT_ihright_START (0)
#define SOC_ISP_SCALER_IHRIGHT_ihright_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uv_hoffset : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_SCALER_UV_HOFFSET_UNION;
#endif
#define SOC_ISP_SCALER_UV_HOFFSET_uv_hoffset_START (0)
#define SOC_ISP_SCALER_UV_HOFFSET_uv_hoffset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivtop : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_SCALER_IVTOP_UNION;
#endif
#define SOC_ISP_SCALER_IVTOP_ivtop_START (0)
#define SOC_ISP_SCALER_IVTOP_ivtop_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivbottom : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_SCALER_IVBOTTOM_UNION;
#endif
#define SOC_ISP_SCALER_IVBOTTOM_ivbottom_START (0)
#define SOC_ISP_SCALER_IVBOTTOM_ivbottom_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uv_voffset : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_SCALER_UV_VOFFSET_UNION;
#endif
#define SOC_ISP_SCALER_UV_VOFFSET_uv_voffset_START (0)
#define SOC_ISP_SCALER_UV_VOFFSET_uv_voffset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihinc : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ISP_SCALER_IHINC_UNION;
#endif
#define SOC_ISP_SCALER_IHINC_ihinc_START (0)
#define SOC_ISP_SCALER_IHINC_ihinc_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivinc : 20;
        unsigned int halflinemode : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_ISP_SCALER_IVINC_UNION;
#endif
#define SOC_ISP_SCALER_IVINC_ivinc_START (0)
#define SOC_ISP_SCALER_IVINC_ivinc_END (19)
#define SOC_ISP_SCALER_IVINC_halflinemode_START (20)
#define SOC_ISP_SCALER_IVINC_halflinemode_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_ISP_SCALER_BYPASS_UNION;
#endif
#define SOC_ISP_SCALER_BYPASS_bypass_START (0)
#define SOC_ISP_SCALER_BYPASS_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int outformat : 2;
        unsigned int swapout : 1;
        unsigned int swapin : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_SCALER_FORMAT_UNION;
#endif
#define SOC_ISP_SCALER_FORMAT_outformat_START (0)
#define SOC_ISP_SCALER_FORMAT_outformat_END (1)
#define SOC_ISP_SCALER_FORMAT_swapout_START (2)
#define SOC_ISP_SCALER_FORMAT_swapout_END (2)
#define SOC_ISP_SCALER_FORMAT_swapin_START (3)
#define SOC_ISP_SCALER_FORMAT_swapin_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ih_hpos : 32;
    } reg;
} SOC_ISP_SCALER_IH_HPOS_UNION;
#endif
#define SOC_ISP_SCALER_IH_HPOS_ih_hpos_START (0)
#define SOC_ISP_SCALER_IH_HPOS_ih_hpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iv_hpos : 32;
    } reg;
} SOC_ISP_SCALER_IV_HPOS_UNION;
#endif
#define SOC_ISP_SCALER_IV_HPOS_iv_hpos_START (0)
#define SOC_ISP_SCALER_IV_HPOS_iv_hpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ih_vpos : 32;
    } reg;
} SOC_ISP_SCALER_IH_VPOS_UNION;
#endif
#define SOC_ISP_SCALER_IH_VPOS_ih_vpos_START (0)
#define SOC_ISP_SCALER_IH_VPOS_ih_vpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iv_vpos : 32;
    } reg;
} SOC_ISP_SCALER_IV_VPOS_UNION;
#endif
#define SOC_ISP_SCALER_IV_VPOS_iv_vpos_START (0)
#define SOC_ISP_SCALER_IV_VPOS_iv_vpos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_clk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_SCALER_FORCE_CLK_ON_CFG_UNION;
#endif
#define SOC_ISP_SCALER_FORCE_CLK_ON_CFG_force_clk_on_START (0)
#define SOC_ISP_SCALER_FORCE_CLK_ON_CFG_force_clk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hcoeff0y : 9;
        unsigned int hcoeff1y : 9;
        unsigned int hcoeff2y : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_SCALER_COEFF_H_Y0_UNION;
#endif
#define SOC_ISP_SCALER_COEFF_H_Y0_hcoeff0y_START (0)
#define SOC_ISP_SCALER_COEFF_H_Y0_hcoeff0y_END (8)
#define SOC_ISP_SCALER_COEFF_H_Y0_hcoeff1y_START (9)
#define SOC_ISP_SCALER_COEFF_H_Y0_hcoeff1y_END (17)
#define SOC_ISP_SCALER_COEFF_H_Y0_hcoeff2y_START (18)
#define SOC_ISP_SCALER_COEFF_H_Y0_hcoeff2y_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hcoeff3y : 9;
        unsigned int hcoeff4y : 9;
        unsigned int hcoeff5y : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_SCALER_COEFF_H_Y1_UNION;
#endif
#define SOC_ISP_SCALER_COEFF_H_Y1_hcoeff3y_START (0)
#define SOC_ISP_SCALER_COEFF_H_Y1_hcoeff3y_END (8)
#define SOC_ISP_SCALER_COEFF_H_Y1_hcoeff4y_START (9)
#define SOC_ISP_SCALER_COEFF_H_Y1_hcoeff4y_END (17)
#define SOC_ISP_SCALER_COEFF_H_Y1_hcoeff5y_START (18)
#define SOC_ISP_SCALER_COEFF_H_Y1_hcoeff5y_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vcoeff0y : 9;
        unsigned int vcoeff1y : 9;
        unsigned int vcoeff2y : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_SCALER_COEFF_V_Y0_UNION;
#endif
#define SOC_ISP_SCALER_COEFF_V_Y0_vcoeff0y_START (0)
#define SOC_ISP_SCALER_COEFF_V_Y0_vcoeff0y_END (8)
#define SOC_ISP_SCALER_COEFF_V_Y0_vcoeff1y_START (9)
#define SOC_ISP_SCALER_COEFF_V_Y0_vcoeff1y_END (17)
#define SOC_ISP_SCALER_COEFF_V_Y0_vcoeff2y_START (18)
#define SOC_ISP_SCALER_COEFF_V_Y0_vcoeff2y_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vcoeff3y : 9;
        unsigned int vcoeff4y : 9;
        unsigned int vcoeff5y : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_SCALER_COEFF_V_Y1_UNION;
#endif
#define SOC_ISP_SCALER_COEFF_V_Y1_vcoeff3y_START (0)
#define SOC_ISP_SCALER_COEFF_V_Y1_vcoeff3y_END (8)
#define SOC_ISP_SCALER_COEFF_V_Y1_vcoeff4y_START (9)
#define SOC_ISP_SCALER_COEFF_V_Y1_vcoeff4y_END (17)
#define SOC_ISP_SCALER_COEFF_V_Y1_vcoeff5y_START (18)
#define SOC_ISP_SCALER_COEFF_V_Y1_vcoeff5y_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hcoeff0uv : 9;
        unsigned int hcoeff1uv : 9;
        unsigned int hcoeff2uv : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_SCALER_COEFF_H_UV0_UNION;
#endif
#define SOC_ISP_SCALER_COEFF_H_UV0_hcoeff0uv_START (0)
#define SOC_ISP_SCALER_COEFF_H_UV0_hcoeff0uv_END (8)
#define SOC_ISP_SCALER_COEFF_H_UV0_hcoeff1uv_START (9)
#define SOC_ISP_SCALER_COEFF_H_UV0_hcoeff1uv_END (17)
#define SOC_ISP_SCALER_COEFF_H_UV0_hcoeff2uv_START (18)
#define SOC_ISP_SCALER_COEFF_H_UV0_hcoeff2uv_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hcoeff3uv : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_SCALER_COEFF_H_UV1_UNION;
#endif
#define SOC_ISP_SCALER_COEFF_H_UV1_hcoeff3uv_START (0)
#define SOC_ISP_SCALER_COEFF_H_UV1_hcoeff3uv_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vcoeff0uv : 9;
        unsigned int vcoeff1uv : 9;
        unsigned int vcoeff2uv : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_SCALER_COEFF_V_UV0_UNION;
#endif
#define SOC_ISP_SCALER_COEFF_V_UV0_vcoeff0uv_START (0)
#define SOC_ISP_SCALER_COEFF_V_UV0_vcoeff0uv_END (8)
#define SOC_ISP_SCALER_COEFF_V_UV0_vcoeff1uv_START (9)
#define SOC_ISP_SCALER_COEFF_V_UV0_vcoeff1uv_END (17)
#define SOC_ISP_SCALER_COEFF_V_UV0_vcoeff2uv_START (18)
#define SOC_ISP_SCALER_COEFF_V_UV0_vcoeff2uv_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vcoeff3uv : 9;
        unsigned int vcoeff4uv : 9;
        unsigned int vcoeff5uv : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_SCALER_COEFF_V_UV1_UNION;
#endif
#define SOC_ISP_SCALER_COEFF_V_UV1_vcoeff3uv_START (0)
#define SOC_ISP_SCALER_COEFF_V_UV1_vcoeff3uv_END (8)
#define SOC_ISP_SCALER_COEFF_V_UV1_vcoeff4uv_START (9)
#define SOC_ISP_SCALER_COEFF_V_UV1_vcoeff4uv_END (17)
#define SOC_ISP_SCALER_COEFF_V_UV1_vcoeff5uv_START (18)
#define SOC_ISP_SCALER_COEFF_V_UV1_vcoeff5uv_END (26)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

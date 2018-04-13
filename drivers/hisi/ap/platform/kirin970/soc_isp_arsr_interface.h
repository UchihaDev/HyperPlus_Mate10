#ifndef __SOC_ISP_ARSR_INTERFACE_H__
#define __SOC_ISP_ARSR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_ARSR_IHLEFT_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_ARSR_IHRIGHT_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_ARSR_IHLEFT1_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_ARSR_IHRIGHT1_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_ARSR_IVTOP_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_ARSR_IVBOTTOM_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_ARSR_UV_OFFSET_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_ARSR_IHINC_ADDR(base) ((base) + (0x001C))
#define SOC_ISP_ARSR_IVINC_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_ARSR_MODE_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_ARSR_FORMAT_ADDR(base) ((base) + (0x0028))
#define SOC_ISP_ARSR_SKIN_THRES_Y_ADDR(base) ((base) + (0x002C))
#define SOC_ISP_ARSR_SKIN_THRES_U_ADDR(base) ((base) + (0x0030))
#define SOC_ISP_ARSR_SKIN_THRES_V_ADDR(base) ((base) + (0x0034))
#define SOC_ISP_ARSR_SKIN_EXPECTED_ADDR(base) ((base) + (0x0038))
#define SOC_ISP_ARSR_SKIN_CFG_ADDR(base) ((base) + (0x003C))
#define SOC_ISP_ARSR_SHOOT_CFG1_ADDR(base) ((base) + (0x0040))
#define SOC_ISP_ARSR_SHOOT_CFG2_ADDR(base) ((base) + (0x0044))
#define SOC_ISP_ARSR_SHARP_CFG1_ADDR(base) ((base) + (0x0048))
#define SOC_ISP_ARSR_SHARP_CFG2_ADDR(base) ((base) + (0x004C))
#define SOC_ISP_ARSR_SHARP_CFG3_ADDR(base) ((base) + (0x0050))
#define SOC_ISP_ARSR_SHARP_CFG4_ADDR(base) ((base) + (0x0054))
#define SOC_ISP_ARSR_SHARP_CFG5_ADDR(base) ((base) + (0x0058))
#define SOC_ISP_ARSR_SHARP_CFG6_ADDR(base) ((base) + (0x005C))
#define SOC_ISP_ARSR_SHARP_CFG7_ADDR(base) ((base) + (0x0060))
#define SOC_ISP_ARSR_SHARP_CFG8_ADDR(base) ((base) + (0x0064))
#define SOC_ISP_ARSR_SHARP_CFG9_ADDR(base) ((base) + (0x0068))
#define SOC_ISP_ARSR_SHARP_CFG10_ADDR(base) ((base) + (0x006C))
#define SOC_ISP_ARSR_SHARP_CFG11_ADDR(base) ((base) + (0x0070))
#define SOC_ISP_ARSR_DIFF_CTRL_ADDR(base) ((base) + (0x0074))
#define SOC_ISP_ARSR_LSC_CFG1_ADDR(base) ((base) + (0x0078))
#define SOC_ISP_ARSR_LSC_CFG2_ADDR(base) ((base) + (0x007C))
#define SOC_ISP_ARSR_LSC_CFG3_ADDR(base) ((base) + (0x0080))
#define SOC_ISP_ARSR_LSC_GAIN_ADDR(base,range27) ((base) + (0x0084+0x4*(range27)))
#define SOC_ISP_ARSR_COEFF_H_Y0_ADDR(base,range9) ((base) + (0xF0+0x4*(range9)))
#define SOC_ISP_ARSR_COEFF_H_Y1_ADDR(base,range9) ((base) + (0x114+0x4*(range9)))
#define SOC_ISP_ARSR_COEFF_V_Y0_ADDR(base,range9) ((base) + (0x138+0x4*(range9)))
#define SOC_ISP_ARSR_COEFF_V_Y1_ADDR(base,range9) ((base) + (0x15C+0x4*(range9)))
#define SOC_ISP_ARSR_COEFF_H_UV0_ADDR(base,range9) ((base) + (0x180+0x4*(range9)))
#define SOC_ISP_ARSR_COEFF_H_UV1_ADDR(base,range9) ((base) + (0x1A4+0x4*(range9)))
#define SOC_ISP_ARSR_COEFF_V_UV0_ADDR(base,range9) ((base) + (0x1C8+0x4*(range9)))
#define SOC_ISP_ARSR_COEFF_V_UV1_ADDR(base,range9) ((base) + (0x1EC+0x4*(range9)))
#define SOC_ISP_ARSR_FORCE_CLK_ON_CFG_ADDR(base) ((base) + (0x0300))
#define SOC_ISP_ARSR_DEBUG_RW_0_ADDR(base) ((base) + (0x304))
#define SOC_ISP_ARSR_DEBUG_RW_1_ADDR(base) ((base) + (0x308))
#define SOC_ISP_ARSR_DEBUG_RW_2_ADDR(base) ((base) + (0x30c))
#define SOC_ISP_ARSR_DEBUG_RO_0_ADDR(base) ((base) + (0x310))
#define SOC_ISP_ARSR_DEBUG_RO_1_ADDR(base) ((base) + (0x314))
#define SOC_ISP_ARSR_DEBUG_RO_2_ADDR(base) ((base) + (0x318))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihleft : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_ARSR_IHLEFT_UNION;
#endif
#define SOC_ISP_ARSR_IHLEFT_ihleft_START (0)
#define SOC_ISP_ARSR_IHLEFT_ihleft_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihright : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_ARSR_IHRIGHT_UNION;
#endif
#define SOC_ISP_ARSR_IHRIGHT_ihright_START (0)
#define SOC_ISP_ARSR_IHRIGHT_ihright_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihleft1 : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_ARSR_IHLEFT1_UNION;
#endif
#define SOC_ISP_ARSR_IHLEFT1_ihleft1_START (0)
#define SOC_ISP_ARSR_IHLEFT1_ihleft1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihright1 : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_ARSR_IHRIGHT1_UNION;
#endif
#define SOC_ISP_ARSR_IHRIGHT1_ihright1_START (0)
#define SOC_ISP_ARSR_IHRIGHT1_ihright1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivtop : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_ARSR_IVTOP_UNION;
#endif
#define SOC_ISP_ARSR_IVTOP_ivtop_START (0)
#define SOC_ISP_ARSR_IVTOP_ivtop_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivbottom : 29;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_ARSR_IVBOTTOM_UNION;
#endif
#define SOC_ISP_ARSR_IVBOTTOM_ivbottom_START (0)
#define SOC_ISP_ARSR_IVBOTTOM_ivbottom_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uv_hoffset : 6;
        unsigned int reserved_0 : 2;
        unsigned int uv_voffset : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_ARSR_UV_OFFSET_UNION;
#endif
#define SOC_ISP_ARSR_UV_OFFSET_uv_hoffset_START (0)
#define SOC_ISP_ARSR_UV_OFFSET_uv_hoffset_END (5)
#define SOC_ISP_ARSR_UV_OFFSET_uv_voffset_START (8)
#define SOC_ISP_ARSR_UV_OFFSET_uv_voffset_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihinc : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ISP_ARSR_IHINC_UNION;
#endif
#define SOC_ISP_ARSR_IHINC_ihinc_START (0)
#define SOC_ISP_ARSR_IHINC_ihinc_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivinc : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ISP_ARSR_IVINC_UNION;
#endif
#define SOC_ISP_ARSR_IVINC_ivinc_START (0)
#define SOC_ISP_ARSR_IVINC_ivinc_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int sharpenen : 1;
        unsigned int shootdetecten : 1;
        unsigned int skinctrlen : 1;
        unsigned int diintplen : 1;
        unsigned int textureanalysisen : 1;
        unsigned int nointplen : 1;
        unsigned int anti_aliasing_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_ARSR_MODE_UNION;
#endif
#define SOC_ISP_ARSR_MODE_bypass_START (0)
#define SOC_ISP_ARSR_MODE_bypass_END (0)
#define SOC_ISP_ARSR_MODE_sharpenen_START (1)
#define SOC_ISP_ARSR_MODE_sharpenen_END (1)
#define SOC_ISP_ARSR_MODE_shootdetecten_START (2)
#define SOC_ISP_ARSR_MODE_shootdetecten_END (2)
#define SOC_ISP_ARSR_MODE_skinctrlen_START (3)
#define SOC_ISP_ARSR_MODE_skinctrlen_END (3)
#define SOC_ISP_ARSR_MODE_diintplen_START (4)
#define SOC_ISP_ARSR_MODE_diintplen_END (4)
#define SOC_ISP_ARSR_MODE_textureanalysisen_START (5)
#define SOC_ISP_ARSR_MODE_textureanalysisen_END (5)
#define SOC_ISP_ARSR_MODE_nointplen_START (6)
#define SOC_ISP_ARSR_MODE_nointplen_END (6)
#define SOC_ISP_ARSR_MODE_anti_aliasing_en_START (7)
#define SOC_ISP_ARSR_MODE_anti_aliasing_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int outformat : 2;
        unsigned int uv_ordering : 1;
        unsigned int swapout : 1;
        unsigned int swapin : 1;
        unsigned int informat : 1;
        unsigned int yuv422_semi_planar : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_ISP_ARSR_FORMAT_UNION;
#endif
#define SOC_ISP_ARSR_FORMAT_outformat_START (0)
#define SOC_ISP_ARSR_FORMAT_outformat_END (1)
#define SOC_ISP_ARSR_FORMAT_uv_ordering_START (2)
#define SOC_ISP_ARSR_FORMAT_uv_ordering_END (2)
#define SOC_ISP_ARSR_FORMAT_swapout_START (3)
#define SOC_ISP_ARSR_FORMAT_swapout_END (3)
#define SOC_ISP_ARSR_FORMAT_swapin_START (4)
#define SOC_ISP_ARSR_FORMAT_swapin_END (4)
#define SOC_ISP_ARSR_FORMAT_informat_START (5)
#define SOC_ISP_ARSR_FORMAT_informat_END (5)
#define SOC_ISP_ARSR_FORMAT_yuv422_semi_planar_START (6)
#define SOC_ISP_ARSR_FORMAT_yuv422_semi_planar_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ythresl : 8;
        unsigned int ythresh : 8;
        unsigned int yslop : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_ISP_ARSR_SKIN_THRES_Y_UNION;
#endif
#define SOC_ISP_ARSR_SKIN_THRES_Y_ythresl_START (0)
#define SOC_ISP_ARSR_SKIN_THRES_Y_ythresl_END (7)
#define SOC_ISP_ARSR_SKIN_THRES_Y_ythresh_START (8)
#define SOC_ISP_ARSR_SKIN_THRES_Y_ythresh_END (15)
#define SOC_ISP_ARSR_SKIN_THRES_Y_yslop_START (16)
#define SOC_ISP_ARSR_SKIN_THRES_Y_yslop_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uthresl : 8;
        unsigned int uthresh : 8;
        unsigned int uslop : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_ISP_ARSR_SKIN_THRES_U_UNION;
#endif
#define SOC_ISP_ARSR_SKIN_THRES_U_uthresl_START (0)
#define SOC_ISP_ARSR_SKIN_THRES_U_uthresl_END (7)
#define SOC_ISP_ARSR_SKIN_THRES_U_uthresh_START (8)
#define SOC_ISP_ARSR_SKIN_THRES_U_uthresh_END (15)
#define SOC_ISP_ARSR_SKIN_THRES_U_uslop_START (16)
#define SOC_ISP_ARSR_SKIN_THRES_U_uslop_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vthresl : 8;
        unsigned int vthresh : 8;
        unsigned int vslop : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_ISP_ARSR_SKIN_THRES_V_UNION;
#endif
#define SOC_ISP_ARSR_SKIN_THRES_V_vthresl_START (0)
#define SOC_ISP_ARSR_SKIN_THRES_V_vthresl_END (7)
#define SOC_ISP_ARSR_SKIN_THRES_V_vthresh_START (8)
#define SOC_ISP_ARSR_SKIN_THRES_V_vthresh_END (15)
#define SOC_ISP_ARSR_SKIN_THRES_V_vslop_START (16)
#define SOC_ISP_ARSR_SKIN_THRES_V_vslop_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int yexpectvalue : 8;
        unsigned int uexpectvalue : 8;
        unsigned int vexpectvalue : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_ISP_ARSR_SKIN_EXPECTED_UNION;
#endif
#define SOC_ISP_ARSR_SKIN_EXPECTED_yexpectvalue_START (0)
#define SOC_ISP_ARSR_SKIN_EXPECTED_yexpectvalue_END (7)
#define SOC_ISP_ARSR_SKIN_EXPECTED_uexpectvalue_START (8)
#define SOC_ISP_ARSR_SKIN_EXPECTED_uexpectvalue_END (15)
#define SOC_ISP_ARSR_SKIN_EXPECTED_vexpectvalue_START (16)
#define SOC_ISP_ARSR_SKIN_EXPECTED_vexpectvalue_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int skinthresl : 5;
        unsigned int reserved_0 : 3;
        unsigned int skinthresh : 5;
        unsigned int reserved_1 : 3;
        unsigned int clipdata : 8;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_ISP_ARSR_SKIN_CFG_UNION;
#endif
#define SOC_ISP_ARSR_SKIN_CFG_skinthresl_START (0)
#define SOC_ISP_ARSR_SKIN_CFG_skinthresl_END (4)
#define SOC_ISP_ARSR_SKIN_CFG_skinthresh_START (8)
#define SOC_ISP_ARSR_SKIN_CFG_skinthresh_END (12)
#define SOC_ISP_ARSR_SKIN_CFG_clipdata_START (16)
#define SOC_ISP_ARSR_SKIN_CFG_clipdata_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shootgradalpha : 6;
        unsigned int reserved : 18;
        unsigned int intplshootctrl : 8;
    } reg;
} SOC_ISP_ARSR_SHOOT_CFG1_UNION;
#endif
#define SOC_ISP_ARSR_SHOOT_CFG1_shootgradalpha_START (0)
#define SOC_ISP_ARSR_SHOOT_CFG1_shootgradalpha_END (5)
#define SOC_ISP_ARSR_SHOOT_CFG1_intplshootctrl_START (24)
#define SOC_ISP_ARSR_SHOOT_CFG1_intplshootctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shootgradsubthrl : 9;
        unsigned int shootgradsubthrh : 9;
        unsigned int shootslop1 : 13;
        unsigned int reserved : 1;
    } reg;
} SOC_ISP_ARSR_SHOOT_CFG2_UNION;
#endif
#define SOC_ISP_ARSR_SHOOT_CFG2_shootgradsubthrl_START (0)
#define SOC_ISP_ARSR_SHOOT_CFG2_shootgradsubthrl_END (8)
#define SOC_ISP_ARSR_SHOOT_CFG2_shootgradsubthrh_START (9)
#define SOC_ISP_ARSR_SHOOT_CFG2_shootgradsubthrh_END (17)
#define SOC_ISP_ARSR_SHOOT_CFG2_shootslop1_START (18)
#define SOC_ISP_ARSR_SHOOT_CFG2_shootslop1_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edgeshpgainvarlow0 : 8;
        unsigned int edgeshpgainvarlow1 : 8;
        unsigned int edgeshpgainvarhigh0 : 8;
        unsigned int edgeshpgainvarhigh1 : 8;
    } reg;
} SOC_ISP_ARSR_SHARP_CFG1_UNION;
#endif
#define SOC_ISP_ARSR_SHARP_CFG1_edgeshpgainvarlow0_START (0)
#define SOC_ISP_ARSR_SHARP_CFG1_edgeshpgainvarlow0_END (7)
#define SOC_ISP_ARSR_SHARP_CFG1_edgeshpgainvarlow1_START (8)
#define SOC_ISP_ARSR_SHARP_CFG1_edgeshpgainvarlow1_END (15)
#define SOC_ISP_ARSR_SHARP_CFG1_edgeshpgainvarhigh0_START (16)
#define SOC_ISP_ARSR_SHARP_CFG1_edgeshpgainvarhigh0_END (23)
#define SOC_ISP_ARSR_SHARP_CFG1_edgeshpgainvarhigh1_START (24)
#define SOC_ISP_ARSR_SHARP_CFG1_edgeshpgainvarhigh1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shpgainvarlow0 : 8;
        unsigned int shpgainvarlow1 : 8;
        unsigned int shpgainvarhigh0 : 8;
        unsigned int shpgainvarhigh1 : 8;
    } reg;
} SOC_ISP_ARSR_SHARP_CFG2_UNION;
#endif
#define SOC_ISP_ARSR_SHARP_CFG2_shpgainvarlow0_START (0)
#define SOC_ISP_ARSR_SHARP_CFG2_shpgainvarlow0_END (7)
#define SOC_ISP_ARSR_SHARP_CFG2_shpgainvarlow1_START (8)
#define SOC_ISP_ARSR_SHARP_CFG2_shpgainvarlow1_END (15)
#define SOC_ISP_ARSR_SHARP_CFG2_shpgainvarhigh0_START (16)
#define SOC_ISP_ARSR_SHARP_CFG2_shpgainvarhigh0_END (23)
#define SOC_ISP_ARSR_SHARP_CFG2_shpgainvarhigh1_START (24)
#define SOC_ISP_ARSR_SHARP_CFG2_shpgainvarhigh1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edgeshpgainhigh : 12;
        unsigned int reserved_0 : 4;
        unsigned int shpgainhigh : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_ARSR_SHARP_CFG3_UNION;
#endif
#define SOC_ISP_ARSR_SHARP_CFG3_edgeshpgainhigh_START (0)
#define SOC_ISP_ARSR_SHARP_CFG3_edgeshpgainhigh_END (11)
#define SOC_ISP_ARSR_SHARP_CFG3_shpgainhigh_START (16)
#define SOC_ISP_ARSR_SHARP_CFG3_shpgainhigh_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edgeshpgainlow : 12;
        unsigned int reserved_0 : 4;
        unsigned int edgeshpgainmid : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_ARSR_SHARP_CFG4_UNION;
#endif
#define SOC_ISP_ARSR_SHARP_CFG4_edgeshpgainlow_START (0)
#define SOC_ISP_ARSR_SHARP_CFG4_edgeshpgainlow_END (11)
#define SOC_ISP_ARSR_SHARP_CFG4_edgeshpgainmid_START (16)
#define SOC_ISP_ARSR_SHARP_CFG4_edgeshpgainmid_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shpgainlow : 12;
        unsigned int reserved_0 : 4;
        unsigned int shpgainmid : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_ARSR_SHARP_CFG5_UNION;
#endif
#define SOC_ISP_ARSR_SHARP_CFG5_shpgainlow_START (0)
#define SOC_ISP_ARSR_SHARP_CFG5_shpgainlow_END (11)
#define SOC_ISP_ARSR_SHARP_CFG5_shpgainmid_START (16)
#define SOC_ISP_ARSR_SHARP_CFG5_shpgainmid_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sharpshootctrll : 8;
        unsigned int sharpshootctrlh : 8;
        unsigned int shptocuthigh0 : 8;
        unsigned int shptocuthigh1 : 8;
    } reg;
} SOC_ISP_ARSR_SHARP_CFG6_UNION;
#endif
#define SOC_ISP_ARSR_SHARP_CFG6_sharpshootctrll_START (0)
#define SOC_ISP_ARSR_SHARP_CFG6_sharpshootctrll_END (7)
#define SOC_ISP_ARSR_SHARP_CFG6_sharpshootctrlh_START (8)
#define SOC_ISP_ARSR_SHARP_CFG6_sharpshootctrlh_END (15)
#define SOC_ISP_ARSR_SHARP_CFG6_shptocuthigh0_START (16)
#define SOC_ISP_ARSR_SHARP_CFG6_shptocuthigh0_END (23)
#define SOC_ISP_ARSR_SHARP_CFG6_shptocuthigh1_START (24)
#define SOC_ISP_ARSR_SHARP_CFG6_shptocuthigh1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int linearshratiol : 8;
        unsigned int shootctrlselect : 1;
        unsigned int maxminselect : 1;
        unsigned int reserved : 6;
        unsigned int linearshratioh : 8;
        unsigned int sharpcoring : 8;
    } reg;
} SOC_ISP_ARSR_SHARP_CFG7_UNION;
#endif
#define SOC_ISP_ARSR_SHARP_CFG7_linearshratiol_START (0)
#define SOC_ISP_ARSR_SHARP_CFG7_linearshratiol_END (7)
#define SOC_ISP_ARSR_SHARP_CFG7_shootctrlselect_START (8)
#define SOC_ISP_ARSR_SHARP_CFG7_shootctrlselect_END (8)
#define SOC_ISP_ARSR_SHARP_CFG7_maxminselect_START (9)
#define SOC_ISP_ARSR_SHARP_CFG7_maxminselect_END (9)
#define SOC_ISP_ARSR_SHARP_CFG7_linearshratioh_START (16)
#define SOC_ISP_ARSR_SHARP_CFG7_linearshratioh_END (23)
#define SOC_ISP_ARSR_SHARP_CFG7_sharpcoring_START (24)
#define SOC_ISP_ARSR_SHARP_CFG7_sharpcoring_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainctrlsloph : 21;
        unsigned int sharplevel : 4;
        unsigned int reserved : 7;
    } reg;
} SOC_ISP_ARSR_SHARP_CFG8_UNION;
#endif
#define SOC_ISP_ARSR_SHARP_CFG8_gainctrlsloph_START (0)
#define SOC_ISP_ARSR_SHARP_CFG8_gainctrlsloph_END (20)
#define SOC_ISP_ARSR_SHARP_CFG8_sharplevel_START (21)
#define SOC_ISP_ARSR_SHARP_CFG8_sharplevel_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainctrlslopl : 21;
        unsigned int reserved : 3;
        unsigned int blendshshootctrl : 8;
    } reg;
} SOC_ISP_ARSR_SHARP_CFG9_UNION;
#endif
#define SOC_ISP_ARSR_SHARP_CFG9_gainctrlslopl_START (0)
#define SOC_ISP_ARSR_SHARP_CFG9_gainctrlslopl_END (20)
#define SOC_ISP_ARSR_SHARP_CFG9_blendshshootctrl_START (24)
#define SOC_ISP_ARSR_SHARP_CFG9_blendshshootctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edgegainctrlsloph : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_ISP_ARSR_SHARP_CFG10_UNION;
#endif
#define SOC_ISP_ARSR_SHARP_CFG10_edgegainctrlsloph_START (0)
#define SOC_ISP_ARSR_SHARP_CFG10_edgegainctrlsloph_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edgegainctrlslopl : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_ISP_ARSR_SHARP_CFG11_UNION;
#endif
#define SOC_ISP_ARSR_SHARP_CFG11_edgegainctrlslopl_START (0)
#define SOC_ISP_ARSR_SHARP_CFG11_edgegainctrlslopl_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int difflow : 5;
        unsigned int reserved_0: 3;
        unsigned int diffhigh : 5;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_ARSR_DIFF_CTRL_UNION;
#endif
#define SOC_ISP_ARSR_DIFF_CTRL_difflow_START (0)
#define SOC_ISP_ARSR_DIFF_CTRL_difflow_END (4)
#define SOC_ISP_ARSR_DIFF_CTRL_diffhigh_START (8)
#define SOC_ISP_ARSR_DIFF_CTRL_diffhigh_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int centerx : 13;
        unsigned int centery : 13;
        unsigned int shiftn : 5;
        unsigned int reserved : 1;
    } reg;
} SOC_ISP_ARSR_LSC_CFG1_UNION;
#endif
#define SOC_ISP_ARSR_LSC_CFG1_centerx_START (0)
#define SOC_ISP_ARSR_LSC_CFG1_centerx_END (12)
#define SOC_ISP_ARSR_LSC_CFG1_centery_START (13)
#define SOC_ISP_ARSR_LSC_CFG1_centery_END (25)
#define SOC_ISP_ARSR_LSC_CFG1_shiftn_START (26)
#define SOC_ISP_ARSR_LSC_CFG1_shiftn_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 16;
        unsigned int lscslope : 9;
        unsigned int reserved_1: 7;
    } reg;
} SOC_ISP_ARSR_LSC_CFG2_UNION;
#endif
#define SOC_ISP_ARSR_LSC_CFG2_lscslope_START (16)
#define SOC_ISP_ARSR_LSC_CFG2_lscslope_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lscoffsetthd : 13;
        unsigned int reserved_0 : 3;
        unsigned int lscoffsetmax : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_ARSR_LSC_CFG3_UNION;
#endif
#define SOC_ISP_ARSR_LSC_CFG3_lscoffsetthd_START (0)
#define SOC_ISP_ARSR_LSC_CFG3_lscoffsetthd_END (12)
#define SOC_ISP_ARSR_LSC_CFG3_lscoffsetmax_START (16)
#define SOC_ISP_ARSR_LSC_CFG3_lscoffsetmax_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pgainlsc0 : 13;
        unsigned int reserved_0: 3;
        unsigned int pgainlsc1 : 13;
        unsigned int reserved_1: 3;
    } reg;
} SOC_ISP_ARSR_LSC_GAIN_UNION;
#endif
#define SOC_ISP_ARSR_LSC_GAIN_pgainlsc0_START (0)
#define SOC_ISP_ARSR_LSC_GAIN_pgainlsc0_END (12)
#define SOC_ISP_ARSR_LSC_GAIN_pgainlsc1_START (16)
#define SOC_ISP_ARSR_LSC_GAIN_pgainlsc1_END (28)
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
} SOC_ISP_ARSR_COEFF_H_Y0_UNION;
#endif
#define SOC_ISP_ARSR_COEFF_H_Y0_hcoeff0y_START (0)
#define SOC_ISP_ARSR_COEFF_H_Y0_hcoeff0y_END (8)
#define SOC_ISP_ARSR_COEFF_H_Y0_hcoeff1y_START (9)
#define SOC_ISP_ARSR_COEFF_H_Y0_hcoeff1y_END (17)
#define SOC_ISP_ARSR_COEFF_H_Y0_hcoeff2y_START (18)
#define SOC_ISP_ARSR_COEFF_H_Y0_hcoeff2y_END (26)
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
} SOC_ISP_ARSR_COEFF_H_Y1_UNION;
#endif
#define SOC_ISP_ARSR_COEFF_H_Y1_hcoeff3y_START (0)
#define SOC_ISP_ARSR_COEFF_H_Y1_hcoeff3y_END (8)
#define SOC_ISP_ARSR_COEFF_H_Y1_hcoeff4y_START (9)
#define SOC_ISP_ARSR_COEFF_H_Y1_hcoeff4y_END (17)
#define SOC_ISP_ARSR_COEFF_H_Y1_hcoeff5y_START (18)
#define SOC_ISP_ARSR_COEFF_H_Y1_hcoeff5y_END (26)
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
} SOC_ISP_ARSR_COEFF_V_Y0_UNION;
#endif
#define SOC_ISP_ARSR_COEFF_V_Y0_vcoeff0y_START (0)
#define SOC_ISP_ARSR_COEFF_V_Y0_vcoeff0y_END (8)
#define SOC_ISP_ARSR_COEFF_V_Y0_vcoeff1y_START (9)
#define SOC_ISP_ARSR_COEFF_V_Y0_vcoeff1y_END (17)
#define SOC_ISP_ARSR_COEFF_V_Y0_vcoeff2y_START (18)
#define SOC_ISP_ARSR_COEFF_V_Y0_vcoeff2y_END (26)
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
} SOC_ISP_ARSR_COEFF_V_Y1_UNION;
#endif
#define SOC_ISP_ARSR_COEFF_V_Y1_vcoeff3y_START (0)
#define SOC_ISP_ARSR_COEFF_V_Y1_vcoeff3y_END (8)
#define SOC_ISP_ARSR_COEFF_V_Y1_vcoeff4y_START (9)
#define SOC_ISP_ARSR_COEFF_V_Y1_vcoeff4y_END (17)
#define SOC_ISP_ARSR_COEFF_V_Y1_vcoeff5y_START (18)
#define SOC_ISP_ARSR_COEFF_V_Y1_vcoeff5y_END (26)
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
} SOC_ISP_ARSR_COEFF_H_UV0_UNION;
#endif
#define SOC_ISP_ARSR_COEFF_H_UV0_hcoeff0uv_START (0)
#define SOC_ISP_ARSR_COEFF_H_UV0_hcoeff0uv_END (8)
#define SOC_ISP_ARSR_COEFF_H_UV0_hcoeff1uv_START (9)
#define SOC_ISP_ARSR_COEFF_H_UV0_hcoeff1uv_END (17)
#define SOC_ISP_ARSR_COEFF_H_UV0_hcoeff2uv_START (18)
#define SOC_ISP_ARSR_COEFF_H_UV0_hcoeff2uv_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hcoeff3uv : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_ARSR_COEFF_H_UV1_UNION;
#endif
#define SOC_ISP_ARSR_COEFF_H_UV1_hcoeff3uv_START (0)
#define SOC_ISP_ARSR_COEFF_H_UV1_hcoeff3uv_END (8)
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
} SOC_ISP_ARSR_COEFF_V_UV0_UNION;
#endif
#define SOC_ISP_ARSR_COEFF_V_UV0_vcoeff0uv_START (0)
#define SOC_ISP_ARSR_COEFF_V_UV0_vcoeff0uv_END (8)
#define SOC_ISP_ARSR_COEFF_V_UV0_vcoeff1uv_START (9)
#define SOC_ISP_ARSR_COEFF_V_UV0_vcoeff1uv_END (17)
#define SOC_ISP_ARSR_COEFF_V_UV0_vcoeff2uv_START (18)
#define SOC_ISP_ARSR_COEFF_V_UV0_vcoeff2uv_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vcoeff3uv : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_ARSR_COEFF_V_UV1_UNION;
#endif
#define SOC_ISP_ARSR_COEFF_V_UV1_vcoeff3uv_START (0)
#define SOC_ISP_ARSR_COEFF_V_UV1_vcoeff3uv_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_clk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_ARSR_FORCE_CLK_ON_CFG_UNION;
#endif
#define SOC_ISP_ARSR_FORCE_CLK_ON_CFG_force_clk_on_START (0)
#define SOC_ISP_ARSR_FORCE_CLK_ON_CFG_force_clk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_rw_0 : 32;
    } reg;
} SOC_ISP_ARSR_DEBUG_RW_0_UNION;
#endif
#define SOC_ISP_ARSR_DEBUG_RW_0_debug_rw_0_START (0)
#define SOC_ISP_ARSR_DEBUG_RW_0_debug_rw_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_rw_1 : 32;
    } reg;
} SOC_ISP_ARSR_DEBUG_RW_1_UNION;
#endif
#define SOC_ISP_ARSR_DEBUG_RW_1_debug_rw_1_START (0)
#define SOC_ISP_ARSR_DEBUG_RW_1_debug_rw_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_rw_2 : 32;
    } reg;
} SOC_ISP_ARSR_DEBUG_RW_2_UNION;
#endif
#define SOC_ISP_ARSR_DEBUG_RW_2_debug_rw_2_START (0)
#define SOC_ISP_ARSR_DEBUG_RW_2_debug_rw_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_ro_0 : 32;
    } reg;
} SOC_ISP_ARSR_DEBUG_RO_0_UNION;
#endif
#define SOC_ISP_ARSR_DEBUG_RO_0_debug_ro_0_START (0)
#define SOC_ISP_ARSR_DEBUG_RO_0_debug_ro_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_ro_1 : 32;
    } reg;
} SOC_ISP_ARSR_DEBUG_RO_1_UNION;
#endif
#define SOC_ISP_ARSR_DEBUG_RO_1_debug_ro_1_START (0)
#define SOC_ISP_ARSR_DEBUG_RO_1_debug_ro_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_ro_2 : 32;
    } reg;
} SOC_ISP_ARSR_DEBUG_RO_2_UNION;
#endif
#define SOC_ISP_ARSR_DEBUG_RO_2_debug_ro_2_START (0)
#define SOC_ISP_ARSR_DEBUG_RO_2_debug_ro_2_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

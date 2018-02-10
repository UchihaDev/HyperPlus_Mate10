#ifndef __SOC_ISP_3DLUT_INTERFACE_H__
#define __SOC_ISP_3DLUT_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_3DLUT_CFG_ADDR(base) ((base) + (0x0))
#define SOC_ISP_3DLUT_CLK_FORCE_ON_ADDR(base) ((base) + (0x4))
#define SOC_ISP_3DLUT_DLUT_2D_0_ADDR(base,Range64) ((base) + (0x8+0x4*(Range64)))
#define SOC_ISP_3DLUT_DLUT_2D_1_ADDR(base,Range64) ((base) + (0x108+0x4*(Range64)))
#define SOC_ISP_3DLUT_DLUT_2D_2_ADDR(base,Range64) ((base) + (0x208+0x4*(Range64)))
#define SOC_ISP_3DLUT_DLUT_2D_3_ADDR(base,Range64) ((base) + (0x308+0x4*(Range64)))
#define SOC_ISP_3DLUT_DLUT_2D_4_ADDR(base,Range64) ((base) + (0x408+0x4*(Range64)))
#define SOC_ISP_3DLUT_DLUT_3D_ADDR(base,Range4913) ((base) + (0x508+0x4*(Range4913)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int reserved_0 : 3;
        unsigned int gray_grid_en : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_ISP_3DLUT_CFG_UNION;
#endif
#define SOC_ISP_3DLUT_CFG_bypass_START (0)
#define SOC_ISP_3DLUT_CFG_bypass_END (0)
#define SOC_ISP_3DLUT_CFG_gray_grid_en_START (4)
#define SOC_ISP_3DLUT_CFG_gray_grid_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_force_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_3DLUT_CLK_FORCE_ON_UNION;
#endif
#define SOC_ISP_3DLUT_CLK_FORCE_ON_clk_force_on_START (0)
#define SOC_ISP_3DLUT_CLK_FORCE_ON_clk_force_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grid_0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_3DLUT_DLUT_2D_0_UNION;
#endif
#define SOC_ISP_3DLUT_DLUT_2D_0_grid_0_START (0)
#define SOC_ISP_3DLUT_DLUT_2D_0_grid_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grid_1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_3DLUT_DLUT_2D_1_UNION;
#endif
#define SOC_ISP_3DLUT_DLUT_2D_1_grid_1_START (0)
#define SOC_ISP_3DLUT_DLUT_2D_1_grid_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grid_2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_3DLUT_DLUT_2D_2_UNION;
#endif
#define SOC_ISP_3DLUT_DLUT_2D_2_grid_2_START (0)
#define SOC_ISP_3DLUT_DLUT_2D_2_grid_2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grid_3 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_3DLUT_DLUT_2D_3_UNION;
#endif
#define SOC_ISP_3DLUT_DLUT_2D_3_grid_3_START (0)
#define SOC_ISP_3DLUT_DLUT_2D_3_grid_3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grid_4 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_3DLUT_DLUT_2D_4_UNION;
#endif
#define SOC_ISP_3DLUT_DLUT_2D_4_grid_4_START (0)
#define SOC_ISP_3DLUT_DLUT_2D_4_grid_4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int b : 8;
        unsigned int g : 8;
        unsigned int r : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_ISP_3DLUT_DLUT_3D_UNION;
#endif
#define SOC_ISP_3DLUT_DLUT_3D_b_START (0)
#define SOC_ISP_3DLUT_DLUT_3D_b_END (7)
#define SOC_ISP_3DLUT_DLUT_3D_g_START (8)
#define SOC_ISP_3DLUT_DLUT_3D_g_END (15)
#define SOC_ISP_3DLUT_DLUT_3D_r_START (16)
#define SOC_ISP_3DLUT_DLUT_3D_r_END (23)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

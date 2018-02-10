#ifndef __SOC_ISP_FBDRAW_INTERFACE_H__
#define __SOC_ISP_FBDRAW_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_FBDRAW_FBD_CFG1_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_FBDRAW_FBD_COMPAND_0_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_FBDRAW_FBD_COMPAND_1_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_FBDRAW_FBD_COMPAND_2_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_FBDRAW_FBD_COMPAND_3_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_FBDRAW_FBD_COMPAND_4_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_FBDRAW_FBD_STATUS_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_FBDRAW_CROPLR_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_FBDRAW_VP_RD_CFG_ADDR(base) ((base) + (0x24))
#define SOC_ISP_FBDRAW_VP_RD_LWG_ADDR(base) ((base) + (0x28))
#define SOC_ISP_FBDRAW_VP_RD_FHG_ADDR(base) ((base) + (0x2C))
#define SOC_ISP_FBDRAW_VP_RD_AXI_FS_ADDR(base) ((base) + (0x30))
#define SOC_ISP_FBDRAW_VP_RD_AXI_LINE_ADDR(base) ((base) + (0x34))
#define SOC_ISP_FBDRAW_VP_RD_PREFETCH_ADDR(base) ((base) + (0x38))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int clk_force_on : 1;
        unsigned int pix_size : 2;
        unsigned int reserved_0 : 4;
        unsigned int budget : 7;
        unsigned int color_mode : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ISP_FBDRAW_FBD_CFG1_UNION;
#endif
#define SOC_ISP_FBDRAW_FBD_CFG1_bypass_START (0)
#define SOC_ISP_FBDRAW_FBD_CFG1_bypass_END (0)
#define SOC_ISP_FBDRAW_FBD_CFG1_clk_force_on_START (1)
#define SOC_ISP_FBDRAW_FBD_CFG1_clk_force_on_END (1)
#define SOC_ISP_FBDRAW_FBD_CFG1_pix_size_START (2)
#define SOC_ISP_FBDRAW_FBD_CFG1_pix_size_END (3)
#define SOC_ISP_FBDRAW_FBD_CFG1_budget_START (8)
#define SOC_ISP_FBDRAW_FBD_CFG1_budget_END (14)
#define SOC_ISP_FBDRAW_FBD_CFG1_color_mode_START (15)
#define SOC_ISP_FBDRAW_FBD_CFG1_color_mode_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end0 : 14;
        unsigned int compand_end0 : 14;
        unsigned int slope0 : 4;
    } reg;
} SOC_ISP_FBDRAW_FBD_COMPAND_0_UNION;
#endif
#define SOC_ISP_FBDRAW_FBD_COMPAND_0_end0_START (0)
#define SOC_ISP_FBDRAW_FBD_COMPAND_0_end0_END (13)
#define SOC_ISP_FBDRAW_FBD_COMPAND_0_compand_end0_START (14)
#define SOC_ISP_FBDRAW_FBD_COMPAND_0_compand_end0_END (27)
#define SOC_ISP_FBDRAW_FBD_COMPAND_0_slope0_START (28)
#define SOC_ISP_FBDRAW_FBD_COMPAND_0_slope0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end1 : 14;
        unsigned int compand_end1 : 14;
        unsigned int slope1 : 4;
    } reg;
} SOC_ISP_FBDRAW_FBD_COMPAND_1_UNION;
#endif
#define SOC_ISP_FBDRAW_FBD_COMPAND_1_end1_START (0)
#define SOC_ISP_FBDRAW_FBD_COMPAND_1_end1_END (13)
#define SOC_ISP_FBDRAW_FBD_COMPAND_1_compand_end1_START (14)
#define SOC_ISP_FBDRAW_FBD_COMPAND_1_compand_end1_END (27)
#define SOC_ISP_FBDRAW_FBD_COMPAND_1_slope1_START (28)
#define SOC_ISP_FBDRAW_FBD_COMPAND_1_slope1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end2 : 14;
        unsigned int compand_end2 : 14;
        unsigned int slope2 : 4;
    } reg;
} SOC_ISP_FBDRAW_FBD_COMPAND_2_UNION;
#endif
#define SOC_ISP_FBDRAW_FBD_COMPAND_2_end2_START (0)
#define SOC_ISP_FBDRAW_FBD_COMPAND_2_end2_END (13)
#define SOC_ISP_FBDRAW_FBD_COMPAND_2_compand_end2_START (14)
#define SOC_ISP_FBDRAW_FBD_COMPAND_2_compand_end2_END (27)
#define SOC_ISP_FBDRAW_FBD_COMPAND_2_slope2_START (28)
#define SOC_ISP_FBDRAW_FBD_COMPAND_2_slope2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end3 : 14;
        unsigned int compand_end3 : 14;
        unsigned int slope3 : 4;
    } reg;
} SOC_ISP_FBDRAW_FBD_COMPAND_3_UNION;
#endif
#define SOC_ISP_FBDRAW_FBD_COMPAND_3_end3_START (0)
#define SOC_ISP_FBDRAW_FBD_COMPAND_3_end3_END (13)
#define SOC_ISP_FBDRAW_FBD_COMPAND_3_compand_end3_START (14)
#define SOC_ISP_FBDRAW_FBD_COMPAND_3_compand_end3_END (27)
#define SOC_ISP_FBDRAW_FBD_COMPAND_3_slope3_START (28)
#define SOC_ISP_FBDRAW_FBD_COMPAND_3_slope3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end4 : 14;
        unsigned int compand_end4 : 14;
        unsigned int slope4 : 4;
    } reg;
} SOC_ISP_FBDRAW_FBD_COMPAND_4_UNION;
#endif
#define SOC_ISP_FBDRAW_FBD_COMPAND_4_end4_START (0)
#define SOC_ISP_FBDRAW_FBD_COMPAND_4_end4_END (13)
#define SOC_ISP_FBDRAW_FBD_COMPAND_4_compand_end4_START (14)
#define SOC_ISP_FBDRAW_FBD_COMPAND_4_compand_end4_END (27)
#define SOC_ISP_FBDRAW_FBD_COMPAND_4_slope4_START (28)
#define SOC_ISP_FBDRAW_FBD_COMPAND_4_slope4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stream_error : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_FBDRAW_FBD_STATUS_UNION;
#endif
#define SOC_ISP_FBDRAW_FBD_STATUS_stream_error_START (0)
#define SOC_ISP_FBDRAW_FBD_STATUS_stream_error_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cleft : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_FBDRAW_CROPLR_UNION;
#endif
#define SOC_ISP_FBDRAW_CROPLR_cleft_START (0)
#define SOC_ISP_FBDRAW_CROPLR_cleft_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_pixel_format : 3;
        unsigned int reserved_0 : 1;
        unsigned int vprd_pixel_expansion : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_ISP_FBDRAW_VP_RD_CFG_UNION;
#endif
#define SOC_ISP_FBDRAW_VP_RD_CFG_vprd_pixel_format_START (0)
#define SOC_ISP_FBDRAW_VP_RD_CFG_vprd_pixel_format_END (2)
#define SOC_ISP_FBDRAW_VP_RD_CFG_vprd_pixel_expansion_START (4)
#define SOC_ISP_FBDRAW_VP_RD_CFG_vprd_pixel_expansion_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_size : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_FBDRAW_VP_RD_LWG_UNION;
#endif
#define SOC_ISP_FBDRAW_VP_RD_LWG_vprd_line_size_START (0)
#define SOC_ISP_FBDRAW_VP_RD_LWG_vprd_line_size_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_frame_size : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_FBDRAW_VP_RD_FHG_UNION;
#endif
#define SOC_ISP_FBDRAW_VP_RD_FHG_vprd_frame_size_START (0)
#define SOC_ISP_FBDRAW_VP_RD_FHG_vprd_frame_size_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vprd_axi_frame_start : 28;
    } reg;
} SOC_ISP_FBDRAW_VP_RD_AXI_FS_UNION;
#endif
#define SOC_ISP_FBDRAW_VP_RD_AXI_FS_vprd_axi_frame_start_START (4)
#define SOC_ISP_FBDRAW_VP_RD_AXI_FS_vprd_axi_frame_start_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_stride : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_FBDRAW_VP_RD_AXI_LINE_UNION;
#endif
#define SOC_ISP_FBDRAW_VP_RD_AXI_LINE_vprd_line_stride_START (0)
#define SOC_ISP_FBDRAW_VP_RD_AXI_LINE_vprd_line_stride_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 31;
        unsigned int vprd_prefetch_bypass : 1;
    } reg;
} SOC_ISP_FBDRAW_VP_RD_PREFETCH_UNION;
#endif
#define SOC_ISP_FBDRAW_VP_RD_PREFETCH_vprd_prefetch_bypass_START (31)
#define SOC_ISP_FBDRAW_VP_RD_PREFETCH_vprd_prefetch_bypass_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

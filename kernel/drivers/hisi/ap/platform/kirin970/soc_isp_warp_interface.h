#ifndef __SOC_ISP_WARP_INTERFACE_H__
#define __SOC_ISP_WARP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_WARP_WARP_START_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_WARP_WARP_CONFIG_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_WARP_FIFO_LIMIT_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_WARP_BASE_ADDR_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_WARP_INPUT_IMAGE_SIZE_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_WARP_OUTPUT_IMAGE_SIZE_ADDR(base) ((base) + (0x001C))
#define SOC_ISP_WARP_I_OFFSET_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_WARP_RGRID_OFFSET_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_WARP_RGRID_SIZE_EXP_ADDR(base) ((base) + (0x0028))
#define SOC_ISP_WARP_RGRID_X_Y_ADDR(base,Range4) ((base) + (0x002C+0x4*(Range4)))
#define SOC_ISP_WARP_SGRID_OFFSET_ADDR(base) ((base) + (0x003C))
#define SOC_ISP_WARP_SGRID_SIZE_EXP_ADDR(base) ((base) + (0x0040))
#define SOC_ISP_WARP_SGRID_X_Y_ADDR(base,Range16) ((base) + (0x0044+0x4*(Range16)))
#define SOC_ISP_WARP_CGRID_OFFSET_ADDR(base) ((base) + (0x0084))
#define SOC_ISP_WARP_CGRID_SIZE_EXP_ADDR(base) ((base) + (0x0088))
#define SOC_ISP_WARP_CGNB_SECTOR_ADDR(base) ((base) + (0x008C))
#define SOC_ISP_WARP_LINE_STRIDE_ADDR(base) ((base) + (0x0090))
#define SOC_ISP_WARP_DMAP_CTRL_ADDR(base) ((base) + (0x0094))
#define SOC_ISP_WARP_CGRID_X_Y_ADDR(base,Range1050) ((base) + (0x0100+0x4*(Range1050)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_WARP_WARP_START_UNION;
#endif
#define SOC_ISP_WARP_WARP_START_start_START (0)
#define SOC_ISP_WARP_WARP_START_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grid0_bypass : 1;
        unsigned int grid1_bypass : 1;
        unsigned int grid2_bypass : 1;
        unsigned int grid_order : 1;
        unsigned int dmap_mode : 1;
        unsigned int dmap_warp : 1;
        unsigned int dmap_mode_xy : 2;
        unsigned int prefetch : 1;
        unsigned int smmu_pref_thresh_en : 1;
        unsigned int smmu_pref_thresh : 2;
        unsigned int prefetch_delay : 11;
        unsigned int yuv_420_uv : 1;
        unsigned int mono_420_single : 1;
        unsigned int fix_pt_precision : 2;
        unsigned int reserved : 1;
        unsigned int compressed : 1;
        unsigned int grid_dump : 1;
        unsigned int clk_force_on : 1;
        unsigned int mono_yuv422 : 1;
    } reg;
} SOC_ISP_WARP_WARP_CONFIG_UNION;
#endif
#define SOC_ISP_WARP_WARP_CONFIG_grid0_bypass_START (0)
#define SOC_ISP_WARP_WARP_CONFIG_grid0_bypass_END (0)
#define SOC_ISP_WARP_WARP_CONFIG_grid1_bypass_START (1)
#define SOC_ISP_WARP_WARP_CONFIG_grid1_bypass_END (1)
#define SOC_ISP_WARP_WARP_CONFIG_grid2_bypass_START (2)
#define SOC_ISP_WARP_WARP_CONFIG_grid2_bypass_END (2)
#define SOC_ISP_WARP_WARP_CONFIG_grid_order_START (3)
#define SOC_ISP_WARP_WARP_CONFIG_grid_order_END (3)
#define SOC_ISP_WARP_WARP_CONFIG_dmap_mode_START (4)
#define SOC_ISP_WARP_WARP_CONFIG_dmap_mode_END (4)
#define SOC_ISP_WARP_WARP_CONFIG_dmap_warp_START (5)
#define SOC_ISP_WARP_WARP_CONFIG_dmap_warp_END (5)
#define SOC_ISP_WARP_WARP_CONFIG_dmap_mode_xy_START (6)
#define SOC_ISP_WARP_WARP_CONFIG_dmap_mode_xy_END (7)
#define SOC_ISP_WARP_WARP_CONFIG_prefetch_START (8)
#define SOC_ISP_WARP_WARP_CONFIG_prefetch_END (8)
#define SOC_ISP_WARP_WARP_CONFIG_smmu_pref_thresh_en_START (9)
#define SOC_ISP_WARP_WARP_CONFIG_smmu_pref_thresh_en_END (9)
#define SOC_ISP_WARP_WARP_CONFIG_smmu_pref_thresh_START (10)
#define SOC_ISP_WARP_WARP_CONFIG_smmu_pref_thresh_END (11)
#define SOC_ISP_WARP_WARP_CONFIG_prefetch_delay_START (12)
#define SOC_ISP_WARP_WARP_CONFIG_prefetch_delay_END (22)
#define SOC_ISP_WARP_WARP_CONFIG_yuv_420_uv_START (23)
#define SOC_ISP_WARP_WARP_CONFIG_yuv_420_uv_END (23)
#define SOC_ISP_WARP_WARP_CONFIG_mono_420_single_START (24)
#define SOC_ISP_WARP_WARP_CONFIG_mono_420_single_END (24)
#define SOC_ISP_WARP_WARP_CONFIG_fix_pt_precision_START (25)
#define SOC_ISP_WARP_WARP_CONFIG_fix_pt_precision_END (26)
#define SOC_ISP_WARP_WARP_CONFIG_compressed_START (28)
#define SOC_ISP_WARP_WARP_CONFIG_compressed_END (28)
#define SOC_ISP_WARP_WARP_CONFIG_grid_dump_START (29)
#define SOC_ISP_WARP_WARP_CONFIG_grid_dump_END (29)
#define SOC_ISP_WARP_WARP_CONFIG_clk_force_on_START (30)
#define SOC_ISP_WARP_WARP_CONFIG_clk_force_on_END (30)
#define SOC_ISP_WARP_WARP_CONFIG_mono_yuv422_START (31)
#define SOC_ISP_WARP_WARP_CONFIG_mono_yuv422_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fifo_limit : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_WARP_FIFO_LIMIT_UNION;
#endif
#define SOC_ISP_WARP_FIFO_LIMIT_fifo_limit_START (0)
#define SOC_ISP_WARP_FIFO_LIMIT_fifo_limit_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 7;
        unsigned int base_addr : 25;
    } reg;
} SOC_ISP_WARP_BASE_ADDR_UNION;
#endif
#define SOC_ISP_WARP_BASE_ADDR_base_addr_START (7)
#define SOC_ISP_WARP_BASE_ADDR_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inputheight : 13;
        unsigned int reserved_0 : 3;
        unsigned int inputwidth : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_WARP_INPUT_IMAGE_SIZE_UNION;
#endif
#define SOC_ISP_WARP_INPUT_IMAGE_SIZE_inputheight_START (0)
#define SOC_ISP_WARP_INPUT_IMAGE_SIZE_inputheight_END (12)
#define SOC_ISP_WARP_INPUT_IMAGE_SIZE_inputwidth_START (16)
#define SOC_ISP_WARP_INPUT_IMAGE_SIZE_inputwidth_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int outputheight : 13;
        unsigned int reserved_0 : 3;
        unsigned int outputwidth : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_WARP_OUTPUT_IMAGE_SIZE_UNION;
#endif
#define SOC_ISP_WARP_OUTPUT_IMAGE_SIZE_outputheight_START (0)
#define SOC_ISP_WARP_OUTPUT_IMAGE_SIZE_outputheight_END (12)
#define SOC_ISP_WARP_OUTPUT_IMAGE_SIZE_outputwidth_START (16)
#define SOC_ISP_WARP_OUTPUT_IMAGE_SIZE_outputwidth_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int i_offset_v : 13;
        unsigned int reserved_0 : 3;
        unsigned int i_offset_h : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_WARP_I_OFFSET_UNION;
#endif
#define SOC_ISP_WARP_I_OFFSET_i_offset_v_START (0)
#define SOC_ISP_WARP_I_OFFSET_i_offset_v_END (12)
#define SOC_ISP_WARP_I_OFFSET_i_offset_h_START (16)
#define SOC_ISP_WARP_I_OFFSET_i_offset_h_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rgrid_offset_v : 13;
        unsigned int reserved_0 : 3;
        unsigned int rgrid_offset_h : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_WARP_RGRID_OFFSET_UNION;
#endif
#define SOC_ISP_WARP_RGRID_OFFSET_rgrid_offset_v_START (0)
#define SOC_ISP_WARP_RGRID_OFFSET_rgrid_offset_v_END (12)
#define SOC_ISP_WARP_RGRID_OFFSET_rgrid_offset_h_START (16)
#define SOC_ISP_WARP_RGRID_OFFSET_rgrid_offset_h_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rgsize_exp_v : 4;
        unsigned int rgsize_exp_h : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_WARP_RGRID_SIZE_EXP_UNION;
#endif
#define SOC_ISP_WARP_RGRID_SIZE_EXP_rgsize_exp_v_START (0)
#define SOC_ISP_WARP_RGRID_SIZE_EXP_rgsize_exp_v_END (3)
#define SOC_ISP_WARP_RGRID_SIZE_EXP_rgsize_exp_h_START (4)
#define SOC_ISP_WARP_RGRID_SIZE_EXP_rgsize_exp_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rgdx : 14;
        unsigned int reserved_0: 2;
        unsigned int rgdy : 14;
        unsigned int reserved_1: 2;
    } reg;
} SOC_ISP_WARP_RGRID_X_Y_UNION;
#endif
#define SOC_ISP_WARP_RGRID_X_Y_rgdx_START (0)
#define SOC_ISP_WARP_RGRID_X_Y_rgdx_END (13)
#define SOC_ISP_WARP_RGRID_X_Y_rgdy_START (16)
#define SOC_ISP_WARP_RGRID_X_Y_rgdy_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sgrid_offset_v : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_WARP_SGRID_OFFSET_UNION;
#endif
#define SOC_ISP_WARP_SGRID_OFFSET_sgrid_offset_v_START (0)
#define SOC_ISP_WARP_SGRID_OFFSET_sgrid_offset_v_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sgsize_exp_v : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_WARP_SGRID_SIZE_EXP_UNION;
#endif
#define SOC_ISP_WARP_SGRID_SIZE_EXP_sgsize_exp_v_START (0)
#define SOC_ISP_WARP_SGRID_SIZE_EXP_sgsize_exp_v_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sgdx : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_WARP_SGRID_X_Y_UNION;
#endif
#define SOC_ISP_WARP_SGRID_X_Y_sgdx_START (0)
#define SOC_ISP_WARP_SGRID_X_Y_sgdx_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cgrid_offset_v : 13;
        unsigned int reserved_0 : 3;
        unsigned int cgrid_offset_h : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_WARP_CGRID_OFFSET_UNION;
#endif
#define SOC_ISP_WARP_CGRID_OFFSET_cgrid_offset_v_START (0)
#define SOC_ISP_WARP_CGRID_OFFSET_cgrid_offset_v_END (12)
#define SOC_ISP_WARP_CGRID_OFFSET_cgrid_offset_h_START (16)
#define SOC_ISP_WARP_CGRID_OFFSET_cgrid_offset_h_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cgsize_exp_v : 4;
        unsigned int cgsize_exp_h : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_WARP_CGRID_SIZE_EXP_UNION;
#endif
#define SOC_ISP_WARP_CGRID_SIZE_EXP_cgsize_exp_v_START (0)
#define SOC_ISP_WARP_CGRID_SIZE_EXP_cgsize_exp_v_END (3)
#define SOC_ISP_WARP_CGRID_SIZE_EXP_cgsize_exp_h_START (4)
#define SOC_ISP_WARP_CGRID_SIZE_EXP_cgsize_exp_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cgnb_sectors_v : 5;
        unsigned int reserved_0 : 11;
        unsigned int cgnb_sectors_h : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_ISP_WARP_CGNB_SECTOR_UNION;
#endif
#define SOC_ISP_WARP_CGNB_SECTOR_cgnb_sectors_v_START (0)
#define SOC_ISP_WARP_CGNB_SECTOR_cgnb_sectors_v_END (4)
#define SOC_ISP_WARP_CGNB_SECTOR_cgnb_sectors_h_START (16)
#define SOC_ISP_WARP_CGNB_SECTOR_cgnb_sectors_h_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 7;
        unsigned int line_stride : 8;
        unsigned int line_stridectrl : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ISP_WARP_LINE_STRIDE_UNION;
#endif
#define SOC_ISP_WARP_LINE_STRIDE_line_stride_START (7)
#define SOC_ISP_WARP_LINE_STRIDE_line_stride_END (14)
#define SOC_ISP_WARP_LINE_STRIDE_line_stridectrl_START (15)
#define SOC_ISP_WARP_LINE_STRIDE_line_stridectrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hvmode : 1;
        unsigned int disp_direction : 1;
        unsigned int shift_disp : 10;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_WARP_DMAP_CTRL_UNION;
#endif
#define SOC_ISP_WARP_DMAP_CTRL_hvmode_START (0)
#define SOC_ISP_WARP_DMAP_CTRL_hvmode_END (0)
#define SOC_ISP_WARP_DMAP_CTRL_disp_direction_START (1)
#define SOC_ISP_WARP_DMAP_CTRL_disp_direction_END (1)
#define SOC_ISP_WARP_DMAP_CTRL_shift_disp_START (2)
#define SOC_ISP_WARP_DMAP_CTRL_shift_disp_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cgdx : 10;
        unsigned int reserved_0: 6;
        unsigned int cgdy : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_ISP_WARP_CGRID_X_Y_UNION;
#endif
#define SOC_ISP_WARP_CGRID_X_Y_cgdx_START (0)
#define SOC_ISP_WARP_CGRID_X_Y_cgdx_END (9)
#define SOC_ISP_WARP_CGRID_X_Y_cgdy_START (16)
#define SOC_ISP_WARP_CGRID_X_Y_cgdy_END (25)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

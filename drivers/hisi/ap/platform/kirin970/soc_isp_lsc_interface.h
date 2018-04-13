#ifndef __SOC_ISP_LSC_INTERFACE_H__
#define __SOC_ISP_LSC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_LSC_LSC_CTRL_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_LSC_LSC_R_TABLE_ADDR_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_LSC_LSC_GR_TABLE_ADDR_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_LSC_LSC_B_TABLE_ADDR_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_LSC_LSC_GB_TABLE_ADDR_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_LSC_LSC_R_TABLE_DATA_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_LSC_LSC_GR_TABLE_DATA_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_LSC_LSC_B_TABLE_DATA_ADDR(base) ((base) + (0x001C))
#define SOC_ISP_LSC_LSC_GB_TABLE_DATA_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_LSC_LSC_XGRAD_0_1_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_LSC_LSC_XGRAD_2_3_ADDR(base) ((base) + (0x0028))
#define SOC_ISP_LSC_LSC_XGRAD_4_5_ADDR(base) ((base) + (0x002C))
#define SOC_ISP_LSC_LSC_XGRAD_6_7_ADDR(base) ((base) + (0x0030))
#define SOC_ISP_LSC_LSC_XGRAD_8_9_ADDR(base) ((base) + (0x0034))
#define SOC_ISP_LSC_LSC_XGRAD_10_11_ADDR(base) ((base) + (0x0038))
#define SOC_ISP_LSC_LSC_XGRAD_12_13_ADDR(base) ((base) + (0x003C))
#define SOC_ISP_LSC_LSC_XGRAD_14_15_ADDR(base) ((base) + (0x0040))
#define SOC_ISP_LSC_LSC_XGRAD_16_17_ADDR(base) ((base) + (0x0044))
#define SOC_ISP_LSC_LSC_XGRAD_18_19_ADDR(base) ((base) + (0x0048))
#define SOC_ISP_LSC_LSC_YGRAD_0_1_ADDR(base) ((base) + (0x004C))
#define SOC_ISP_LSC_LSC_YGRAD_2_3_ADDR(base) ((base) + (0x0050))
#define SOC_ISP_LSC_LSC_YGRAD_4_5_ADDR(base) ((base) + (0x0054))
#define SOC_ISP_LSC_LSC_YGRAD_6_7_ADDR(base) ((base) + (0x0058))
#define SOC_ISP_LSC_LSC_YGRAD_8_9_ADDR(base) ((base) + (0x005C))
#define SOC_ISP_LSC_LSC_YGRAD_10_11_ADDR(base) ((base) + (0x0060))
#define SOC_ISP_LSC_LSC_YGRAD_12_13_ADDR(base) ((base) + (0x0064))
#define SOC_ISP_LSC_LSC_YGRAD_14_ADDR(base) ((base) + (0x0068))
#define SOC_ISP_LSC_LSC_XSIZE_0_1_ADDR(base) ((base) + (0x006C))
#define SOC_ISP_LSC_LSC_XSIZE_2_3_ADDR(base) ((base) + (0x0070))
#define SOC_ISP_LSC_LSC_XSIZE_4_5_ADDR(base) ((base) + (0x0074))
#define SOC_ISP_LSC_LSC_XSIZE_6_7_ADDR(base) ((base) + (0x0078))
#define SOC_ISP_LSC_LSC_XSIZE_8_9_ADDR(base) ((base) + (0x007C))
#define SOC_ISP_LSC_LSC_XSIZE_10_11_ADDR(base) ((base) + (0x0080))
#define SOC_ISP_LSC_LSC_XSIZE_12_13_ADDR(base) ((base) + (0x0084))
#define SOC_ISP_LSC_LSC_XSIZE_14_15_ADDR(base) ((base) + (0x0088))
#define SOC_ISP_LSC_LSC_XSIZE_16_17_ADDR(base) ((base) + (0x008C))
#define SOC_ISP_LSC_LSC_XSIZE_18_19_ADDR(base) ((base) + (0x0090))
#define SOC_ISP_LSC_LSC_YSIZE_0_1_ADDR(base) ((base) + (0x0094))
#define SOC_ISP_LSC_LSC_YSIZE_2_3_ADDR(base) ((base) + (0x0098))
#define SOC_ISP_LSC_LSC_YSIZE_4_5_ADDR(base) ((base) + (0x009C))
#define SOC_ISP_LSC_LSC_YSIZE_6_7_ADDR(base) ((base) + (0x00A0))
#define SOC_ISP_LSC_LSC_YSIZE_8_9_ADDR(base) ((base) + (0x00A4))
#define SOC_ISP_LSC_LSC_YSIZE_10_11_ADDR(base) ((base) + (0x00A8))
#define SOC_ISP_LSC_LSC_YSIZE_12_13_ADDR(base) ((base) + (0x00AC))
#define SOC_ISP_LSC_LSC_YSIZE_14_15_ADDR(base) ((base) + (0x00B0))
#define SOC_ISP_LSC_LSC_IMAGE_BLOCK_OFFSET_ADDR(base) ((base) + (0x00B4))
#define SOC_ISP_LSC_LSC_START_BLOCK_LOC_ADDR(base) ((base) + (0x00B8))
#define SOC_ISP_LSC_LSC_BLACK_LEVEL_A_B_ADDR(base) ((base) + (0x00BC))
#define SOC_ISP_LSC_LSC_BLACK_LEVEL_C_D_ADDR(base) ((base) + (0x00C0))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lsc_en : 1;
        unsigned int mono_sensor : 1;
        unsigned int bls_enable_mode : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_LSC_LSC_CTRL_UNION;
#endif
#define SOC_ISP_LSC_LSC_CTRL_lsc_en_START (0)
#define SOC_ISP_LSC_LSC_CTRL_lsc_en_END (0)
#define SOC_ISP_LSC_LSC_CTRL_mono_sensor_START (1)
#define SOC_ISP_LSC_LSC_CTRL_mono_sensor_END (1)
#define SOC_ISP_LSC_LSC_CTRL_bls_enable_mode_START (2)
#define SOC_ISP_LSC_LSC_CTRL_bls_enable_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_ram_addr : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_LSC_LSC_R_TABLE_ADDR_UNION;
#endif
#define SOC_ISP_LSC_LSC_R_TABLE_ADDR_r_ram_addr_START (0)
#define SOC_ISP_LSC_LSC_R_TABLE_ADDR_r_ram_addr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gr_ram_addr : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_LSC_LSC_GR_TABLE_ADDR_UNION;
#endif
#define SOC_ISP_LSC_LSC_GR_TABLE_ADDR_gr_ram_addr_START (0)
#define SOC_ISP_LSC_LSC_GR_TABLE_ADDR_gr_ram_addr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int b_ram_addr : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_LSC_LSC_B_TABLE_ADDR_UNION;
#endif
#define SOC_ISP_LSC_LSC_B_TABLE_ADDR_b_ram_addr_START (0)
#define SOC_ISP_LSC_LSC_B_TABLE_ADDR_b_ram_addr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gb_ram_addr : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_LSC_LSC_GB_TABLE_ADDR_UNION;
#endif
#define SOC_ISP_LSC_LSC_GB_TABLE_ADDR_gb_ram_addr_START (0)
#define SOC_ISP_LSC_LSC_GB_TABLE_ADDR_gb_ram_addr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_sample_0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int r_sample_1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_LSC_LSC_R_TABLE_DATA_UNION;
#endif
#define SOC_ISP_LSC_LSC_R_TABLE_DATA_r_sample_0_START (0)
#define SOC_ISP_LSC_LSC_R_TABLE_DATA_r_sample_0_END (12)
#define SOC_ISP_LSC_LSC_R_TABLE_DATA_r_sample_1_START (16)
#define SOC_ISP_LSC_LSC_R_TABLE_DATA_r_sample_1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gr_sample_0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int gr_sample_1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_LSC_LSC_GR_TABLE_DATA_UNION;
#endif
#define SOC_ISP_LSC_LSC_GR_TABLE_DATA_gr_sample_0_START (0)
#define SOC_ISP_LSC_LSC_GR_TABLE_DATA_gr_sample_0_END (12)
#define SOC_ISP_LSC_LSC_GR_TABLE_DATA_gr_sample_1_START (16)
#define SOC_ISP_LSC_LSC_GR_TABLE_DATA_gr_sample_1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int b_sample_0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int b_sample_1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_LSC_LSC_B_TABLE_DATA_UNION;
#endif
#define SOC_ISP_LSC_LSC_B_TABLE_DATA_b_sample_0_START (0)
#define SOC_ISP_LSC_LSC_B_TABLE_DATA_b_sample_0_END (12)
#define SOC_ISP_LSC_LSC_B_TABLE_DATA_b_sample_1_START (16)
#define SOC_ISP_LSC_LSC_B_TABLE_DATA_b_sample_1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gb_sample_0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int gb_sample_1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_LSC_LSC_GB_TABLE_DATA_UNION;
#endif
#define SOC_ISP_LSC_LSC_GB_TABLE_DATA_gb_sample_0_START (0)
#define SOC_ISP_LSC_LSC_GB_TABLE_DATA_gb_sample_0_END (12)
#define SOC_ISP_LSC_LSC_GB_TABLE_DATA_gb_sample_1_START (16)
#define SOC_ISP_LSC_LSC_GB_TABLE_DATA_gb_sample_1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xgrad_0 : 12;
        unsigned int reserved_0: 4;
        unsigned int xgrad_1 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_XGRAD_0_1_UNION;
#endif
#define SOC_ISP_LSC_LSC_XGRAD_0_1_xgrad_0_START (0)
#define SOC_ISP_LSC_LSC_XGRAD_0_1_xgrad_0_END (11)
#define SOC_ISP_LSC_LSC_XGRAD_0_1_xgrad_1_START (16)
#define SOC_ISP_LSC_LSC_XGRAD_0_1_xgrad_1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xgrad_2 : 12;
        unsigned int reserved_0: 4;
        unsigned int xgrad_3 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_XGRAD_2_3_UNION;
#endif
#define SOC_ISP_LSC_LSC_XGRAD_2_3_xgrad_2_START (0)
#define SOC_ISP_LSC_LSC_XGRAD_2_3_xgrad_2_END (11)
#define SOC_ISP_LSC_LSC_XGRAD_2_3_xgrad_3_START (16)
#define SOC_ISP_LSC_LSC_XGRAD_2_3_xgrad_3_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xgrad_4 : 12;
        unsigned int reserved_0: 4;
        unsigned int xgrad_5 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_XGRAD_4_5_UNION;
#endif
#define SOC_ISP_LSC_LSC_XGRAD_4_5_xgrad_4_START (0)
#define SOC_ISP_LSC_LSC_XGRAD_4_5_xgrad_4_END (11)
#define SOC_ISP_LSC_LSC_XGRAD_4_5_xgrad_5_START (16)
#define SOC_ISP_LSC_LSC_XGRAD_4_5_xgrad_5_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xgrad_6 : 12;
        unsigned int reserved_0: 4;
        unsigned int xgrad_7 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_XGRAD_6_7_UNION;
#endif
#define SOC_ISP_LSC_LSC_XGRAD_6_7_xgrad_6_START (0)
#define SOC_ISP_LSC_LSC_XGRAD_6_7_xgrad_6_END (11)
#define SOC_ISP_LSC_LSC_XGRAD_6_7_xgrad_7_START (16)
#define SOC_ISP_LSC_LSC_XGRAD_6_7_xgrad_7_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xgrad_8 : 12;
        unsigned int reserved_0: 4;
        unsigned int xgrad_9 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_XGRAD_8_9_UNION;
#endif
#define SOC_ISP_LSC_LSC_XGRAD_8_9_xgrad_8_START (0)
#define SOC_ISP_LSC_LSC_XGRAD_8_9_xgrad_8_END (11)
#define SOC_ISP_LSC_LSC_XGRAD_8_9_xgrad_9_START (16)
#define SOC_ISP_LSC_LSC_XGRAD_8_9_xgrad_9_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xgrad_10 : 12;
        unsigned int reserved_0: 4;
        unsigned int xgrad_11 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_XGRAD_10_11_UNION;
#endif
#define SOC_ISP_LSC_LSC_XGRAD_10_11_xgrad_10_START (0)
#define SOC_ISP_LSC_LSC_XGRAD_10_11_xgrad_10_END (11)
#define SOC_ISP_LSC_LSC_XGRAD_10_11_xgrad_11_START (16)
#define SOC_ISP_LSC_LSC_XGRAD_10_11_xgrad_11_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xgrad_12 : 12;
        unsigned int reserved_0: 4;
        unsigned int xgrad_13 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_XGRAD_12_13_UNION;
#endif
#define SOC_ISP_LSC_LSC_XGRAD_12_13_xgrad_12_START (0)
#define SOC_ISP_LSC_LSC_XGRAD_12_13_xgrad_12_END (11)
#define SOC_ISP_LSC_LSC_XGRAD_12_13_xgrad_13_START (16)
#define SOC_ISP_LSC_LSC_XGRAD_12_13_xgrad_13_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xgrad_14 : 12;
        unsigned int reserved_0: 4;
        unsigned int xgrad_15 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_XGRAD_14_15_UNION;
#endif
#define SOC_ISP_LSC_LSC_XGRAD_14_15_xgrad_14_START (0)
#define SOC_ISP_LSC_LSC_XGRAD_14_15_xgrad_14_END (11)
#define SOC_ISP_LSC_LSC_XGRAD_14_15_xgrad_15_START (16)
#define SOC_ISP_LSC_LSC_XGRAD_14_15_xgrad_15_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xgrad_16 : 12;
        unsigned int reserved_0: 4;
        unsigned int xgrad_17 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_XGRAD_16_17_UNION;
#endif
#define SOC_ISP_LSC_LSC_XGRAD_16_17_xgrad_16_START (0)
#define SOC_ISP_LSC_LSC_XGRAD_16_17_xgrad_16_END (11)
#define SOC_ISP_LSC_LSC_XGRAD_16_17_xgrad_17_START (16)
#define SOC_ISP_LSC_LSC_XGRAD_16_17_xgrad_17_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xgrad_18 : 12;
        unsigned int reserved_0: 4;
        unsigned int xgrad_19 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_XGRAD_18_19_UNION;
#endif
#define SOC_ISP_LSC_LSC_XGRAD_18_19_xgrad_18_START (0)
#define SOC_ISP_LSC_LSC_XGRAD_18_19_xgrad_18_END (11)
#define SOC_ISP_LSC_LSC_XGRAD_18_19_xgrad_19_START (16)
#define SOC_ISP_LSC_LSC_XGRAD_18_19_xgrad_19_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ygrad_0 : 12;
        unsigned int reserved_0: 4;
        unsigned int ygrad_1 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_YGRAD_0_1_UNION;
#endif
#define SOC_ISP_LSC_LSC_YGRAD_0_1_ygrad_0_START (0)
#define SOC_ISP_LSC_LSC_YGRAD_0_1_ygrad_0_END (11)
#define SOC_ISP_LSC_LSC_YGRAD_0_1_ygrad_1_START (16)
#define SOC_ISP_LSC_LSC_YGRAD_0_1_ygrad_1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ygrad_2 : 12;
        unsigned int reserved_0: 4;
        unsigned int ygrad_3 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_YGRAD_2_3_UNION;
#endif
#define SOC_ISP_LSC_LSC_YGRAD_2_3_ygrad_2_START (0)
#define SOC_ISP_LSC_LSC_YGRAD_2_3_ygrad_2_END (11)
#define SOC_ISP_LSC_LSC_YGRAD_2_3_ygrad_3_START (16)
#define SOC_ISP_LSC_LSC_YGRAD_2_3_ygrad_3_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ygrad_4 : 12;
        unsigned int reserved_0: 4;
        unsigned int ygrad_5 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_YGRAD_4_5_UNION;
#endif
#define SOC_ISP_LSC_LSC_YGRAD_4_5_ygrad_4_START (0)
#define SOC_ISP_LSC_LSC_YGRAD_4_5_ygrad_4_END (11)
#define SOC_ISP_LSC_LSC_YGRAD_4_5_ygrad_5_START (16)
#define SOC_ISP_LSC_LSC_YGRAD_4_5_ygrad_5_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ygrad_6 : 12;
        unsigned int reserved_0: 4;
        unsigned int ygrad_7 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_YGRAD_6_7_UNION;
#endif
#define SOC_ISP_LSC_LSC_YGRAD_6_7_ygrad_6_START (0)
#define SOC_ISP_LSC_LSC_YGRAD_6_7_ygrad_6_END (11)
#define SOC_ISP_LSC_LSC_YGRAD_6_7_ygrad_7_START (16)
#define SOC_ISP_LSC_LSC_YGRAD_6_7_ygrad_7_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ygrad_8 : 12;
        unsigned int reserved_0: 4;
        unsigned int ygrad_9 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_YGRAD_8_9_UNION;
#endif
#define SOC_ISP_LSC_LSC_YGRAD_8_9_ygrad_8_START (0)
#define SOC_ISP_LSC_LSC_YGRAD_8_9_ygrad_8_END (11)
#define SOC_ISP_LSC_LSC_YGRAD_8_9_ygrad_9_START (16)
#define SOC_ISP_LSC_LSC_YGRAD_8_9_ygrad_9_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ygrad_10 : 12;
        unsigned int reserved_0: 4;
        unsigned int ygrad_11 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_YGRAD_10_11_UNION;
#endif
#define SOC_ISP_LSC_LSC_YGRAD_10_11_ygrad_10_START (0)
#define SOC_ISP_LSC_LSC_YGRAD_10_11_ygrad_10_END (11)
#define SOC_ISP_LSC_LSC_YGRAD_10_11_ygrad_11_START (16)
#define SOC_ISP_LSC_LSC_YGRAD_10_11_ygrad_11_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ygrad_12 : 12;
        unsigned int reserved_0: 4;
        unsigned int ygrad_13 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_ISP_LSC_LSC_YGRAD_12_13_UNION;
#endif
#define SOC_ISP_LSC_LSC_YGRAD_12_13_ygrad_12_START (0)
#define SOC_ISP_LSC_LSC_YGRAD_12_13_ygrad_12_END (11)
#define SOC_ISP_LSC_LSC_YGRAD_12_13_ygrad_13_START (16)
#define SOC_ISP_LSC_LSC_YGRAD_12_13_ygrad_13_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ygrad_14 : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_LSC_LSC_YGRAD_14_UNION;
#endif
#define SOC_ISP_LSC_LSC_YGRAD_14_ygrad_14_START (0)
#define SOC_ISP_LSC_LSC_YGRAD_14_ygrad_14_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_sect_size_0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int x_sect_size_1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_XSIZE_0_1_UNION;
#endif
#define SOC_ISP_LSC_LSC_XSIZE_0_1_x_sect_size_0_START (0)
#define SOC_ISP_LSC_LSC_XSIZE_0_1_x_sect_size_0_END (9)
#define SOC_ISP_LSC_LSC_XSIZE_0_1_x_sect_size_1_START (16)
#define SOC_ISP_LSC_LSC_XSIZE_0_1_x_sect_size_1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_sect_size_2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int x_sect_size_3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_XSIZE_2_3_UNION;
#endif
#define SOC_ISP_LSC_LSC_XSIZE_2_3_x_sect_size_2_START (0)
#define SOC_ISP_LSC_LSC_XSIZE_2_3_x_sect_size_2_END (9)
#define SOC_ISP_LSC_LSC_XSIZE_2_3_x_sect_size_3_START (16)
#define SOC_ISP_LSC_LSC_XSIZE_2_3_x_sect_size_3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_sect_size_4 : 10;
        unsigned int reserved_0 : 6;
        unsigned int x_sect_size_5 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_XSIZE_4_5_UNION;
#endif
#define SOC_ISP_LSC_LSC_XSIZE_4_5_x_sect_size_4_START (0)
#define SOC_ISP_LSC_LSC_XSIZE_4_5_x_sect_size_4_END (9)
#define SOC_ISP_LSC_LSC_XSIZE_4_5_x_sect_size_5_START (16)
#define SOC_ISP_LSC_LSC_XSIZE_4_5_x_sect_size_5_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_sect_size_6 : 10;
        unsigned int reserved_0 : 6;
        unsigned int x_sect_size_7 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_XSIZE_6_7_UNION;
#endif
#define SOC_ISP_LSC_LSC_XSIZE_6_7_x_sect_size_6_START (0)
#define SOC_ISP_LSC_LSC_XSIZE_6_7_x_sect_size_6_END (9)
#define SOC_ISP_LSC_LSC_XSIZE_6_7_x_sect_size_7_START (16)
#define SOC_ISP_LSC_LSC_XSIZE_6_7_x_sect_size_7_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_sect_size_8 : 10;
        unsigned int reserved_0 : 6;
        unsigned int x_sect_size_9 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_XSIZE_8_9_UNION;
#endif
#define SOC_ISP_LSC_LSC_XSIZE_8_9_x_sect_size_8_START (0)
#define SOC_ISP_LSC_LSC_XSIZE_8_9_x_sect_size_8_END (9)
#define SOC_ISP_LSC_LSC_XSIZE_8_9_x_sect_size_9_START (16)
#define SOC_ISP_LSC_LSC_XSIZE_8_9_x_sect_size_9_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_sect_size_10 : 10;
        unsigned int reserved_0 : 6;
        unsigned int x_sect_size_11 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_XSIZE_10_11_UNION;
#endif
#define SOC_ISP_LSC_LSC_XSIZE_10_11_x_sect_size_10_START (0)
#define SOC_ISP_LSC_LSC_XSIZE_10_11_x_sect_size_10_END (9)
#define SOC_ISP_LSC_LSC_XSIZE_10_11_x_sect_size_11_START (16)
#define SOC_ISP_LSC_LSC_XSIZE_10_11_x_sect_size_11_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_sect_size_12 : 10;
        unsigned int reserved_0 : 6;
        unsigned int x_sect_size_13 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_XSIZE_12_13_UNION;
#endif
#define SOC_ISP_LSC_LSC_XSIZE_12_13_x_sect_size_12_START (0)
#define SOC_ISP_LSC_LSC_XSIZE_12_13_x_sect_size_12_END (9)
#define SOC_ISP_LSC_LSC_XSIZE_12_13_x_sect_size_13_START (16)
#define SOC_ISP_LSC_LSC_XSIZE_12_13_x_sect_size_13_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_sect_size_14 : 10;
        unsigned int reserved_0 : 6;
        unsigned int x_sect_size_15 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_XSIZE_14_15_UNION;
#endif
#define SOC_ISP_LSC_LSC_XSIZE_14_15_x_sect_size_14_START (0)
#define SOC_ISP_LSC_LSC_XSIZE_14_15_x_sect_size_14_END (9)
#define SOC_ISP_LSC_LSC_XSIZE_14_15_x_sect_size_15_START (16)
#define SOC_ISP_LSC_LSC_XSIZE_14_15_x_sect_size_15_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_sect_size_16 : 10;
        unsigned int reserved_0 : 6;
        unsigned int x_sect_size_17 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_XSIZE_16_17_UNION;
#endif
#define SOC_ISP_LSC_LSC_XSIZE_16_17_x_sect_size_16_START (0)
#define SOC_ISP_LSC_LSC_XSIZE_16_17_x_sect_size_16_END (9)
#define SOC_ISP_LSC_LSC_XSIZE_16_17_x_sect_size_17_START (16)
#define SOC_ISP_LSC_LSC_XSIZE_16_17_x_sect_size_17_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_sect_size_18 : 10;
        unsigned int reserved_0 : 6;
        unsigned int x_sect_size_19 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_XSIZE_18_19_UNION;
#endif
#define SOC_ISP_LSC_LSC_XSIZE_18_19_x_sect_size_18_START (0)
#define SOC_ISP_LSC_LSC_XSIZE_18_19_x_sect_size_18_END (9)
#define SOC_ISP_LSC_LSC_XSIZE_18_19_x_sect_size_19_START (16)
#define SOC_ISP_LSC_LSC_XSIZE_18_19_x_sect_size_19_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int y_sect_size_0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int y_sect_size_1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_YSIZE_0_1_UNION;
#endif
#define SOC_ISP_LSC_LSC_YSIZE_0_1_y_sect_size_0_START (0)
#define SOC_ISP_LSC_LSC_YSIZE_0_1_y_sect_size_0_END (9)
#define SOC_ISP_LSC_LSC_YSIZE_0_1_y_sect_size_1_START (16)
#define SOC_ISP_LSC_LSC_YSIZE_0_1_y_sect_size_1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int y_sect_size_2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int y_sect_size_3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_YSIZE_2_3_UNION;
#endif
#define SOC_ISP_LSC_LSC_YSIZE_2_3_y_sect_size_2_START (0)
#define SOC_ISP_LSC_LSC_YSIZE_2_3_y_sect_size_2_END (9)
#define SOC_ISP_LSC_LSC_YSIZE_2_3_y_sect_size_3_START (16)
#define SOC_ISP_LSC_LSC_YSIZE_2_3_y_sect_size_3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int y_sect_size_4 : 10;
        unsigned int reserved_0 : 6;
        unsigned int y_sect_size_5 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_YSIZE_4_5_UNION;
#endif
#define SOC_ISP_LSC_LSC_YSIZE_4_5_y_sect_size_4_START (0)
#define SOC_ISP_LSC_LSC_YSIZE_4_5_y_sect_size_4_END (9)
#define SOC_ISP_LSC_LSC_YSIZE_4_5_y_sect_size_5_START (16)
#define SOC_ISP_LSC_LSC_YSIZE_4_5_y_sect_size_5_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int y_sect_size_6 : 10;
        unsigned int reserved_0 : 6;
        unsigned int y_sect_size_7 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_YSIZE_6_7_UNION;
#endif
#define SOC_ISP_LSC_LSC_YSIZE_6_7_y_sect_size_6_START (0)
#define SOC_ISP_LSC_LSC_YSIZE_6_7_y_sect_size_6_END (9)
#define SOC_ISP_LSC_LSC_YSIZE_6_7_y_sect_size_7_START (16)
#define SOC_ISP_LSC_LSC_YSIZE_6_7_y_sect_size_7_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int y_sect_size_8 : 10;
        unsigned int reserved_0 : 6;
        unsigned int y_sect_size_9 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_YSIZE_8_9_UNION;
#endif
#define SOC_ISP_LSC_LSC_YSIZE_8_9_y_sect_size_8_START (0)
#define SOC_ISP_LSC_LSC_YSIZE_8_9_y_sect_size_8_END (9)
#define SOC_ISP_LSC_LSC_YSIZE_8_9_y_sect_size_9_START (16)
#define SOC_ISP_LSC_LSC_YSIZE_8_9_y_sect_size_9_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int y_sect_size_10 : 10;
        unsigned int reserved_0 : 6;
        unsigned int y_sect_size_11 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_YSIZE_10_11_UNION;
#endif
#define SOC_ISP_LSC_LSC_YSIZE_10_11_y_sect_size_10_START (0)
#define SOC_ISP_LSC_LSC_YSIZE_10_11_y_sect_size_10_END (9)
#define SOC_ISP_LSC_LSC_YSIZE_10_11_y_sect_size_11_START (16)
#define SOC_ISP_LSC_LSC_YSIZE_10_11_y_sect_size_11_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int y_sect_size_12 : 10;
        unsigned int reserved_0 : 6;
        unsigned int y_sect_size_13 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_YSIZE_12_13_UNION;
#endif
#define SOC_ISP_LSC_LSC_YSIZE_12_13_y_sect_size_12_START (0)
#define SOC_ISP_LSC_LSC_YSIZE_12_13_y_sect_size_12_END (9)
#define SOC_ISP_LSC_LSC_YSIZE_12_13_y_sect_size_13_START (16)
#define SOC_ISP_LSC_LSC_YSIZE_12_13_y_sect_size_13_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int y_sect_size_14 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_LSC_LSC_YSIZE_14_15_UNION;
#endif
#define SOC_ISP_LSC_LSC_YSIZE_14_15_y_sect_size_14_START (0)
#define SOC_ISP_LSC_LSC_YSIZE_14_15_y_sect_size_14_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_start_offset : 10;
        unsigned int reserved_0 : 6;
        unsigned int y_start_offset : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_LSC_LSC_IMAGE_BLOCK_OFFSET_UNION;
#endif
#define SOC_ISP_LSC_LSC_IMAGE_BLOCK_OFFSET_x_start_offset_START (0)
#define SOC_ISP_LSC_LSC_IMAGE_BLOCK_OFFSET_x_start_offset_END (9)
#define SOC_ISP_LSC_LSC_IMAGE_BLOCK_OFFSET_y_start_offset_START (16)
#define SOC_ISP_LSC_LSC_IMAGE_BLOCK_OFFSET_y_start_offset_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_start_block : 6;
        unsigned int reserved_0 : 10;
        unsigned int y_start_block : 5;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_ISP_LSC_LSC_START_BLOCK_LOC_UNION;
#endif
#define SOC_ISP_LSC_LSC_START_BLOCK_LOC_x_start_block_START (0)
#define SOC_ISP_LSC_LSC_START_BLOCK_LOC_x_start_block_END (5)
#define SOC_ISP_LSC_LSC_START_BLOCK_LOC_y_start_block_START (16)
#define SOC_ISP_LSC_LSC_START_BLOCK_LOC_y_start_block_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bls_a_fixed : 13;
        unsigned int reserved_0 : 3;
        unsigned int bls_b_fixed : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_LSC_LSC_BLACK_LEVEL_A_B_UNION;
#endif
#define SOC_ISP_LSC_LSC_BLACK_LEVEL_A_B_bls_a_fixed_START (0)
#define SOC_ISP_LSC_LSC_BLACK_LEVEL_A_B_bls_a_fixed_END (12)
#define SOC_ISP_LSC_LSC_BLACK_LEVEL_A_B_bls_b_fixed_START (16)
#define SOC_ISP_LSC_LSC_BLACK_LEVEL_A_B_bls_b_fixed_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bls_c_fixed : 13;
        unsigned int reserved_0 : 3;
        unsigned int bls_d_fixed : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_LSC_LSC_BLACK_LEVEL_C_D_UNION;
#endif
#define SOC_ISP_LSC_LSC_BLACK_LEVEL_C_D_bls_c_fixed_START (0)
#define SOC_ISP_LSC_LSC_BLACK_LEVEL_C_D_bls_c_fixed_END (12)
#define SOC_ISP_LSC_LSC_BLACK_LEVEL_C_D_bls_d_fixed_START (16)
#define SOC_ISP_LSC_LSC_BLACK_LEVEL_C_D_bls_d_fixed_END (28)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

#ifndef __SOC_ISP_AUTOCLS_INTERFACE_H__
#define __SOC_ISP_AUTOCLS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_AUTOCLS_CLS_CFG_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_AUTOCLS_CLS_WIN_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_AUTOCLS_CLS_XSIZE_0_1_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_AUTOCLS_CLS_XSIZE_2_3_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_AUTOCLS_CLS_XSIZE_4_5_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_AUTOCLS_CLS_XSIZE_6_7_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_AUTOCLS_CLS_XSIZE_8_9_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_AUTOCLS_CLS_XSIZE_10_11_ADDR(base) ((base) + (0x001C))
#define SOC_ISP_AUTOCLS_CLS_XSIZE_12_13_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_AUTOCLS_CLS_XSIZE_14_15_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_AUTOCLS_CLS_XSIZE_16_17_ADDR(base) ((base) + (0x0028))
#define SOC_ISP_AUTOCLS_CLS_XSIZE_18_19_ADDR(base) ((base) + (0x002C))
#define SOC_ISP_AUTOCLS_CLS_YSIZE_0_1_ADDR(base) ((base) + (0x0030))
#define SOC_ISP_AUTOCLS_CLS_YSIZE_2_3_ADDR(base) ((base) + (0x0034))
#define SOC_ISP_AUTOCLS_CLS_YSIZE_4_5_ADDR(base) ((base) + (0x0038))
#define SOC_ISP_AUTOCLS_CLS_YSIZE_6_7_ADDR(base) ((base) + (0x003C))
#define SOC_ISP_AUTOCLS_CLS_YSIZE_8_9_ADDR(base) ((base) + (0x0040))
#define SOC_ISP_AUTOCLS_CLS_YSIZE_10_11_ADDR(base) ((base) + (0x0044))
#define SOC_ISP_AUTOCLS_CLS_YSIZE_12_13_ADDR(base) ((base) + (0x0048))
#define SOC_ISP_AUTOCLS_CLS_YSIZE_14_ADDR(base) ((base) + (0x04C))
#define SOC_ISP_AUTOCLS_CLS_IMAGE_BLOCK_OFFSET_ADDR(base) ((base) + (0x0050))
#define SOC_ISP_AUTOCLS_CLS_START_BLOCK_LOC_ADDR(base) ((base) + (0x0054))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_AUTOCLS_CLS_CFG_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_CFG_bypass_START (0)
#define SOC_ISP_AUTOCLS_CLS_CFG_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_winh : 5;
        unsigned int reserved_0: 3;
        unsigned int stat_winw : 5;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_AUTOCLS_CLS_WIN_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_WIN_stat_winh_START (0)
#define SOC_ISP_AUTOCLS_CLS_WIN_stat_winh_END (4)
#define SOC_ISP_AUTOCLS_CLS_WIN_stat_winw_START (8)
#define SOC_ISP_AUTOCLS_CLS_WIN_stat_winw_END (12)
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
} SOC_ISP_AUTOCLS_CLS_XSIZE_0_1_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_XSIZE_0_1_x_sect_size_0_START (0)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_0_1_x_sect_size_0_END (9)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_0_1_x_sect_size_1_START (16)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_0_1_x_sect_size_1_END (25)
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
} SOC_ISP_AUTOCLS_CLS_XSIZE_2_3_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_XSIZE_2_3_x_sect_size_2_START (0)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_2_3_x_sect_size_2_END (9)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_2_3_x_sect_size_3_START (16)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_2_3_x_sect_size_3_END (25)
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
} SOC_ISP_AUTOCLS_CLS_XSIZE_4_5_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_XSIZE_4_5_x_sect_size_4_START (0)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_4_5_x_sect_size_4_END (9)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_4_5_x_sect_size_5_START (16)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_4_5_x_sect_size_5_END (25)
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
} SOC_ISP_AUTOCLS_CLS_XSIZE_6_7_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_XSIZE_6_7_x_sect_size_6_START (0)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_6_7_x_sect_size_6_END (9)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_6_7_x_sect_size_7_START (16)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_6_7_x_sect_size_7_END (25)
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
} SOC_ISP_AUTOCLS_CLS_XSIZE_8_9_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_XSIZE_8_9_x_sect_size_8_START (0)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_8_9_x_sect_size_8_END (9)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_8_9_x_sect_size_9_START (16)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_8_9_x_sect_size_9_END (25)
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
} SOC_ISP_AUTOCLS_CLS_XSIZE_10_11_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_XSIZE_10_11_x_sect_size_10_START (0)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_10_11_x_sect_size_10_END (9)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_10_11_x_sect_size_11_START (16)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_10_11_x_sect_size_11_END (25)
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
} SOC_ISP_AUTOCLS_CLS_XSIZE_12_13_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_XSIZE_12_13_x_sect_size_12_START (0)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_12_13_x_sect_size_12_END (9)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_12_13_x_sect_size_13_START (16)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_12_13_x_sect_size_13_END (25)
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
} SOC_ISP_AUTOCLS_CLS_XSIZE_14_15_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_XSIZE_14_15_x_sect_size_14_START (0)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_14_15_x_sect_size_14_END (9)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_14_15_x_sect_size_15_START (16)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_14_15_x_sect_size_15_END (25)
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
} SOC_ISP_AUTOCLS_CLS_XSIZE_16_17_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_XSIZE_16_17_x_sect_size_16_START (0)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_16_17_x_sect_size_16_END (9)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_16_17_x_sect_size_17_START (16)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_16_17_x_sect_size_17_END (25)
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
} SOC_ISP_AUTOCLS_CLS_XSIZE_18_19_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_XSIZE_18_19_x_sect_size_18_START (0)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_18_19_x_sect_size_18_END (9)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_18_19_x_sect_size_19_START (16)
#define SOC_ISP_AUTOCLS_CLS_XSIZE_18_19_x_sect_size_19_END (25)
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
} SOC_ISP_AUTOCLS_CLS_YSIZE_0_1_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_YSIZE_0_1_y_sect_size_0_START (0)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_0_1_y_sect_size_0_END (9)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_0_1_y_sect_size_1_START (16)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_0_1_y_sect_size_1_END (25)
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
} SOC_ISP_AUTOCLS_CLS_YSIZE_2_3_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_YSIZE_2_3_y_sect_size_2_START (0)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_2_3_y_sect_size_2_END (9)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_2_3_y_sect_size_3_START (16)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_2_3_y_sect_size_3_END (25)
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
} SOC_ISP_AUTOCLS_CLS_YSIZE_4_5_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_YSIZE_4_5_y_sect_size_4_START (0)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_4_5_y_sect_size_4_END (9)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_4_5_y_sect_size_5_START (16)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_4_5_y_sect_size_5_END (25)
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
} SOC_ISP_AUTOCLS_CLS_YSIZE_6_7_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_YSIZE_6_7_y_sect_size_6_START (0)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_6_7_y_sect_size_6_END (9)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_6_7_y_sect_size_7_START (16)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_6_7_y_sect_size_7_END (25)
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
} SOC_ISP_AUTOCLS_CLS_YSIZE_8_9_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_YSIZE_8_9_y_sect_size_8_START (0)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_8_9_y_sect_size_8_END (9)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_8_9_y_sect_size_9_START (16)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_8_9_y_sect_size_9_END (25)
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
} SOC_ISP_AUTOCLS_CLS_YSIZE_10_11_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_YSIZE_10_11_y_sect_size_10_START (0)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_10_11_y_sect_size_10_END (9)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_10_11_y_sect_size_11_START (16)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_10_11_y_sect_size_11_END (25)
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
} SOC_ISP_AUTOCLS_CLS_YSIZE_12_13_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_YSIZE_12_13_y_sect_size_12_START (0)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_12_13_y_sect_size_12_END (9)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_12_13_y_sect_size_13_START (16)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_12_13_y_sect_size_13_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int y_sect_size_14 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_AUTOCLS_CLS_YSIZE_14_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_YSIZE_14_y_sect_size_14_START (0)
#define SOC_ISP_AUTOCLS_CLS_YSIZE_14_y_sect_size_14_END (9)
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
} SOC_ISP_AUTOCLS_CLS_IMAGE_BLOCK_OFFSET_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_IMAGE_BLOCK_OFFSET_x_start_offset_START (0)
#define SOC_ISP_AUTOCLS_CLS_IMAGE_BLOCK_OFFSET_x_start_offset_END (9)
#define SOC_ISP_AUTOCLS_CLS_IMAGE_BLOCK_OFFSET_y_start_offset_START (16)
#define SOC_ISP_AUTOCLS_CLS_IMAGE_BLOCK_OFFSET_y_start_offset_END (25)
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
} SOC_ISP_AUTOCLS_CLS_START_BLOCK_LOC_UNION;
#endif
#define SOC_ISP_AUTOCLS_CLS_START_BLOCK_LOC_x_start_block_START (0)
#define SOC_ISP_AUTOCLS_CLS_START_BLOCK_LOC_x_start_block_END (5)
#define SOC_ISP_AUTOCLS_CLS_START_BLOCK_LOC_y_start_block_START (16)
#define SOC_ISP_AUTOCLS_CLS_START_BLOCK_LOC_y_start_block_END (20)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

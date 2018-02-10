#ifndef __SOC_CORE_OCLDO_INTERFACE_H__
#define __SOC_CORE_OCLDO_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_CORE_OCLDO_OCLDO_COMM_CFG_ADDR(base) ((base) + (0x0000))
#define SOC_CORE_OCLDO_OCLDO_RESV_CFG_ADDR(base) ((base) + (0x0004))
#define SOC_CORE_OCLDO_OCLDO_VOUT_TRIM_ADDR(base) ((base) + (0x0008))
#define SOC_CORE_OCLDO_OCLDO_IO_MUX_ADDR(base) ((base) + (0x000c))
#define SOC_CORE_OCLDO_OCLDO_MREGC_HW_TRIM_CFG_ADDR(base) ((base) + (0x0010))
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ADDR(base) ((base) + (0x0014))
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ADDR(base) ((base) + (0x0018))
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ADDR(base) ((base) + (0x001c))
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ADDR(base) ((base) + (0x0100))
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ADDR(base) ((base) + (0x0104))
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ADDR(base) ((base) + (0x0110))
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ADDR(base) ((base) + (0x0114))
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ADDR(base) ((base) + (0x0120))
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ADDR(base) ((base) + (0x0200))
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ADDR(base) ((base) + (0x0204))
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ADDR(base) ((base) + (0x0210))
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ADDR(base) ((base) + (0x0214))
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ADDR(base) ((base) + (0x0220))
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ADDR(base) ((base) + (0x0300))
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ADDR(base) ((base) + (0x0304))
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ADDR(base) ((base) + (0x0310))
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ADDR(base) ((base) + (0x0314))
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ADDR(base) ((base) + (0x0320))
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ADDR(base) ((base) + (0x0400))
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ADDR(base) ((base) + (0x0404))
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ADDR(base) ((base) + (0x0410))
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ADDR(base) ((base) + (0x0414))
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ADDR(base) ((base) + (0x0420))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo_pro_det : 2;
        unsigned int ocldo_rip_opt : 3;
        unsigned int ocldo_vregc_resv_in_15_6 : 10;
        unsigned int reserved : 17;
    } reg;
} SOC_CORE_OCLDO_OCLDO_COMM_CFG_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO_COMM_CFG_ocldo_pro_det_START (0)
#define SOC_CORE_OCLDO_OCLDO_COMM_CFG_ocldo_pro_det_END (1)
#define SOC_CORE_OCLDO_OCLDO_COMM_CFG_ocldo_rip_opt_START (2)
#define SOC_CORE_OCLDO_OCLDO_COMM_CFG_ocldo_rip_opt_END (4)
#define SOC_CORE_OCLDO_OCLDO_COMM_CFG_ocldo_vregc_resv_in_15_6_START (5)
#define SOC_CORE_OCLDO_OCLDO_COMM_CFG_ocldo_vregc_resv_in_15_6_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo0_vregc_resv_in_5_0 : 6;
        unsigned int ocldo1_vregc_resv_in_5_0 : 6;
        unsigned int ocldo2_vregc_resv_in_5_0 : 6;
        unsigned int ocldo3_vregc_resv_in_5_0 : 6;
        unsigned int reserved : 8;
    } reg;
} SOC_CORE_OCLDO_OCLDO_RESV_CFG_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO_RESV_CFG_ocldo0_vregc_resv_in_5_0_START (0)
#define SOC_CORE_OCLDO_OCLDO_RESV_CFG_ocldo0_vregc_resv_in_5_0_END (5)
#define SOC_CORE_OCLDO_OCLDO_RESV_CFG_ocldo1_vregc_resv_in_5_0_START (6)
#define SOC_CORE_OCLDO_OCLDO_RESV_CFG_ocldo1_vregc_resv_in_5_0_END (11)
#define SOC_CORE_OCLDO_OCLDO_RESV_CFG_ocldo2_vregc_resv_in_5_0_START (12)
#define SOC_CORE_OCLDO_OCLDO_RESV_CFG_ocldo2_vregc_resv_in_5_0_END (17)
#define SOC_CORE_OCLDO_OCLDO_RESV_CFG_ocldo3_vregc_resv_in_5_0_START (18)
#define SOC_CORE_OCLDO_OCLDO_RESV_CFG_ocldo3_vregc_resv_in_5_0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo0_vout_trim : 4;
        unsigned int ocldo1_vout_trim : 4;
        unsigned int ocldo2_vout_trim : 4;
        unsigned int ocldo3_vout_trim : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_OCLDO_OCLDO_VOUT_TRIM_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO_VOUT_TRIM_ocldo0_vout_trim_START (0)
#define SOC_CORE_OCLDO_OCLDO_VOUT_TRIM_ocldo0_vout_trim_END (3)
#define SOC_CORE_OCLDO_OCLDO_VOUT_TRIM_ocldo1_vout_trim_START (4)
#define SOC_CORE_OCLDO_OCLDO_VOUT_TRIM_ocldo1_vout_trim_END (7)
#define SOC_CORE_OCLDO_OCLDO_VOUT_TRIM_ocldo2_vout_trim_START (8)
#define SOC_CORE_OCLDO_OCLDO_VOUT_TRIM_ocldo2_vout_trim_END (11)
#define SOC_CORE_OCLDO_OCLDO_VOUT_TRIM_ocldo3_vout_trim_START (12)
#define SOC_CORE_OCLDO_OCLDO_VOUT_TRIM_ocldo3_vout_trim_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dig_io_mux : 6;
        unsigned int reserved_0 : 10;
        unsigned int io_mux_en : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_CORE_OCLDO_OCLDO_IO_MUX_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO_IO_MUX_dig_io_mux_START (0)
#define SOC_CORE_OCLDO_OCLDO_IO_MUX_dig_io_mux_END (5)
#define SOC_CORE_OCLDO_OCLDO_IO_MUX_io_mux_en_START (16)
#define SOC_CORE_OCLDO_OCLDO_IO_MUX_io_mux_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo_mregc_trim_time : 8;
        unsigned int reserved_0 : 8;
        unsigned int ocldo_mregc_hw_trim : 1;
        unsigned int hw_clkgt_byp : 1;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_CORE_OCLDO_OCLDO_MREGC_HW_TRIM_CFG_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO_MREGC_HW_TRIM_CFG_ocldo_mregc_trim_time_START (0)
#define SOC_CORE_OCLDO_OCLDO_MREGC_HW_TRIM_CFG_ocldo_mregc_trim_time_END (7)
#define SOC_CORE_OCLDO_OCLDO_MREGC_HW_TRIM_CFG_ocldo_mregc_hw_trim_START (16)
#define SOC_CORE_OCLDO_OCLDO_MREGC_HW_TRIM_CFG_ocldo_mregc_hw_trim_END (16)
#define SOC_CORE_OCLDO_OCLDO_MREGC_HW_TRIM_CFG_hw_clkgt_byp_START (17)
#define SOC_CORE_OCLDO_OCLDO_MREGC_HW_TRIM_CFG_hw_clkgt_byp_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo0_mregc1_en_trim : 1;
        unsigned int ocldo0_mregc2_en_trim : 1;
        unsigned int ocldo0_mregc3_en_trim : 1;
        unsigned int ocldo0_mregc4_en_trim : 1;
        unsigned int ocldo1_mregc1_en_trim : 1;
        unsigned int ocldo1_mregc2_en_trim : 1;
        unsigned int ocldo1_mregc3_en_trim : 1;
        unsigned int ocldo1_mregc4_en_trim : 1;
        unsigned int ocldo2_mregc1_en_trim : 1;
        unsigned int ocldo2_mregc2_en_trim : 1;
        unsigned int ocldo2_mregc3_en_trim : 1;
        unsigned int ocldo2_mregc4_en_trim : 1;
        unsigned int ocldo3_mregc1_en_trim : 1;
        unsigned int ocldo3_mregc2_en_trim : 1;
        unsigned int ocldo3_mregc3_en_trim : 1;
        unsigned int ocldo3_mregc4_en_trim : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo0_mregc1_en_trim_START (0)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo0_mregc1_en_trim_END (0)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo0_mregc2_en_trim_START (1)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo0_mregc2_en_trim_END (1)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo0_mregc3_en_trim_START (2)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo0_mregc3_en_trim_END (2)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo0_mregc4_en_trim_START (3)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo0_mregc4_en_trim_END (3)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo1_mregc1_en_trim_START (4)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo1_mregc1_en_trim_END (4)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo1_mregc2_en_trim_START (5)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo1_mregc2_en_trim_END (5)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo1_mregc3_en_trim_START (6)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo1_mregc3_en_trim_END (6)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo1_mregc4_en_trim_START (7)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo1_mregc4_en_trim_END (7)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo2_mregc1_en_trim_START (8)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo2_mregc1_en_trim_END (8)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo2_mregc2_en_trim_START (9)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo2_mregc2_en_trim_END (9)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo2_mregc3_en_trim_START (10)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo2_mregc3_en_trim_END (10)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo2_mregc4_en_trim_START (11)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo2_mregc4_en_trim_END (11)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo3_mregc1_en_trim_START (12)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo3_mregc1_en_trim_END (12)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo3_mregc2_en_trim_START (13)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo3_mregc2_en_trim_END (13)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo3_mregc3_en_trim_START (14)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo3_mregc3_en_trim_END (14)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo3_mregc4_en_trim_START (15)
#define SOC_CORE_OCLDO_OCLDO_MREGC_EN_TRIM_ocldo3_mregc4_en_trim_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo0_mregc1_trim_set : 4;
        unsigned int ocldo0_mregc2_trim_set : 4;
        unsigned int ocldo0_mregc3_trim_set : 4;
        unsigned int ocldo0_mregc4_trim_set : 4;
        unsigned int ocldo1_mregc1_trim_set : 4;
        unsigned int ocldo1_mregc2_trim_set : 4;
        unsigned int ocldo1_mregc3_trim_set : 4;
        unsigned int ocldo1_mregc4_trim_set : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo0_mregc1_trim_set_START (0)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo0_mregc1_trim_set_END (3)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo0_mregc2_trim_set_START (4)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo0_mregc2_trim_set_END (7)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo0_mregc3_trim_set_START (8)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo0_mregc3_trim_set_END (11)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo0_mregc4_trim_set_START (12)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo0_mregc4_trim_set_END (15)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo1_mregc1_trim_set_START (16)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo1_mregc1_trim_set_END (19)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo1_mregc2_trim_set_START (20)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo1_mregc2_trim_set_END (23)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo1_mregc3_trim_set_START (24)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo1_mregc3_trim_set_END (27)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo1_mregc4_trim_set_START (28)
#define SOC_CORE_OCLDO_OCLDO01_SW_MREGC_TRIM_SET_ocldo1_mregc4_trim_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo2_mregc1_trim_set : 4;
        unsigned int ocldo2_mregc2_trim_set : 4;
        unsigned int ocldo2_mregc3_trim_set : 4;
        unsigned int ocldo2_mregc4_trim_set : 4;
        unsigned int ocldo3_mregc1_trim_set : 4;
        unsigned int ocldo3_mregc2_trim_set : 4;
        unsigned int ocldo3_mregc3_trim_set : 4;
        unsigned int ocldo3_mregc4_trim_set : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo2_mregc1_trim_set_START (0)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo2_mregc1_trim_set_END (3)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo2_mregc2_trim_set_START (4)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo2_mregc2_trim_set_END (7)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo2_mregc3_trim_set_START (8)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo2_mregc3_trim_set_END (11)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo2_mregc4_trim_set_START (12)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo2_mregc4_trim_set_END (15)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo3_mregc1_trim_set_START (16)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo3_mregc1_trim_set_END (19)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo3_mregc2_trim_set_START (20)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo3_mregc2_trim_set_END (23)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo3_mregc3_trim_set_START (24)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo3_mregc3_trim_set_END (27)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo3_mregc4_trim_set_START (28)
#define SOC_CORE_OCLDO_OCLDO23_SW_MREGC_TRIM_SET_ocldo3_mregc4_trim_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo0_mregc1_trim_comp1_in : 4;
        unsigned int ocldo0_mregc1_trim_comp2_in : 4;
        unsigned int ocldo0_mregc1_trim_comp3_in : 4;
        unsigned int ocldo0_mregc1_trim_comp4_in : 4;
        unsigned int ocldo0_mregc2_trim_comp1_in : 4;
        unsigned int ocldo0_mregc2_trim_comp2_in : 4;
        unsigned int ocldo0_mregc2_trim_comp3_in : 4;
        unsigned int ocldo0_mregc2_trim_comp4_in : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc1_trim_comp1_in_START (0)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc1_trim_comp1_in_END (3)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc1_trim_comp2_in_START (4)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc1_trim_comp2_in_END (7)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc1_trim_comp3_in_START (8)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc1_trim_comp3_in_END (11)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc1_trim_comp4_in_START (12)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc1_trim_comp4_in_END (15)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc2_trim_comp1_in_START (16)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc2_trim_comp1_in_END (19)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc2_trim_comp2_in_START (20)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc2_trim_comp2_in_END (23)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc2_trim_comp3_in_START (24)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc2_trim_comp3_in_END (27)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc2_trim_comp4_in_START (28)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM1_ocldo0_mregc2_trim_comp4_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo0_mregc3_trim_comp1_in : 4;
        unsigned int ocldo0_mregc3_trim_comp2_in : 4;
        unsigned int ocldo0_mregc3_trim_comp3_in : 4;
        unsigned int ocldo0_mregc3_trim_comp4_in : 4;
        unsigned int ocldo0_mregc4_trim_comp1_in : 4;
        unsigned int ocldo0_mregc4_trim_comp2_in : 4;
        unsigned int ocldo0_mregc4_trim_comp3_in : 4;
        unsigned int ocldo0_mregc4_trim_comp4_in : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc3_trim_comp1_in_START (0)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc3_trim_comp1_in_END (3)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc3_trim_comp2_in_START (4)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc3_trim_comp2_in_END (7)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc3_trim_comp3_in_START (8)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc3_trim_comp3_in_END (11)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc3_trim_comp4_in_START (12)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc3_trim_comp4_in_END (15)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc4_trim_comp1_in_START (16)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc4_trim_comp1_in_END (19)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc4_trim_comp2_in_START (20)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc4_trim_comp2_in_END (23)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc4_trim_comp3_in_START (24)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc4_trim_comp3_in_END (27)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc4_trim_comp4_in_START (28)
#define SOC_CORE_OCLDO_OCLDO0_SW_MREGC_TRIM2_ocldo0_mregc4_trim_comp4_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo0_mregc1_trim_comp1_dat : 4;
        unsigned int ocldo0_mregc1_trim_comp2_dat : 4;
        unsigned int ocldo0_mregc1_trim_comp3_dat : 4;
        unsigned int ocldo0_mregc1_trim_comp4_dat : 4;
        unsigned int ocldo0_mregc2_trim_comp1_dat : 4;
        unsigned int ocldo0_mregc2_trim_comp2_dat : 4;
        unsigned int ocldo0_mregc2_trim_comp3_dat : 4;
        unsigned int ocldo0_mregc2_trim_comp4_dat : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc1_trim_comp1_dat_START (0)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc1_trim_comp1_dat_END (3)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc1_trim_comp2_dat_START (4)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc1_trim_comp2_dat_END (7)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc1_trim_comp3_dat_START (8)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc1_trim_comp3_dat_END (11)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc1_trim_comp4_dat_START (12)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc1_trim_comp4_dat_END (15)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc2_trim_comp1_dat_START (16)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc2_trim_comp1_dat_END (19)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc2_trim_comp2_dat_START (20)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc2_trim_comp2_dat_END (23)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc2_trim_comp3_dat_START (24)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc2_trim_comp3_dat_END (27)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc2_trim_comp4_dat_START (28)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT1_ocldo0_mregc2_trim_comp4_dat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo0_mregc3_trim_comp1_dat : 4;
        unsigned int ocldo0_mregc3_trim_comp2_dat : 4;
        unsigned int ocldo0_mregc3_trim_comp3_dat : 4;
        unsigned int ocldo0_mregc3_trim_comp4_dat : 4;
        unsigned int ocldo0_mregc4_trim_comp1_dat : 4;
        unsigned int ocldo0_mregc4_trim_comp2_dat : 4;
        unsigned int ocldo0_mregc4_trim_comp3_dat : 4;
        unsigned int ocldo0_mregc4_trim_comp4_dat : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc3_trim_comp1_dat_START (0)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc3_trim_comp1_dat_END (3)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc3_trim_comp2_dat_START (4)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc3_trim_comp2_dat_END (7)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc3_trim_comp3_dat_START (8)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc3_trim_comp3_dat_END (11)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc3_trim_comp4_dat_START (12)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc3_trim_comp4_dat_END (15)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc4_trim_comp1_dat_START (16)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc4_trim_comp1_dat_END (19)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc4_trim_comp2_dat_START (20)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc4_trim_comp2_dat_END (23)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc4_trim_comp3_dat_START (24)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc4_trim_comp3_dat_END (27)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc4_trim_comp4_dat_START (28)
#define SOC_CORE_OCLDO_OCLDO0_MREGC_TRIM_STAT2_ocldo0_mregc4_trim_comp4_dat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo0_en_m_out : 4;
        unsigned int ocldo0_pset : 4;
        unsigned int ocldo0_vregc_resv_out : 4;
        unsigned int reserved : 4;
        unsigned int ocldo0_mregc1_trim_ok : 4;
        unsigned int ocldo0_mregc2_trim_ok : 4;
        unsigned int ocldo0_mregc3_trim_ok : 4;
        unsigned int ocldo0_mregc4_trim_ok : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO0_ANA_STAT_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_en_m_out_START (0)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_en_m_out_END (3)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_pset_START (4)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_pset_END (7)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_vregc_resv_out_START (8)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_vregc_resv_out_END (11)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_mregc1_trim_ok_START (16)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_mregc1_trim_ok_END (19)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_mregc2_trim_ok_START (20)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_mregc2_trim_ok_END (23)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_mregc3_trim_ok_START (24)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_mregc3_trim_ok_END (27)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_mregc4_trim_ok_START (28)
#define SOC_CORE_OCLDO_OCLDO0_ANA_STAT_ocldo0_mregc4_trim_ok_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo1_mregc1_trim_comp1_in : 4;
        unsigned int ocldo1_mregc1_trim_comp2_in : 4;
        unsigned int ocldo1_mregc1_trim_comp3_in : 4;
        unsigned int ocldo1_mregc1_trim_comp4_in : 4;
        unsigned int ocldo1_mregc2_trim_comp1_in : 4;
        unsigned int ocldo1_mregc2_trim_comp2_in : 4;
        unsigned int ocldo1_mregc2_trim_comp3_in : 4;
        unsigned int ocldo1_mregc2_trim_comp4_in : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc1_trim_comp1_in_START (0)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc1_trim_comp1_in_END (3)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc1_trim_comp2_in_START (4)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc1_trim_comp2_in_END (7)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc1_trim_comp3_in_START (8)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc1_trim_comp3_in_END (11)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc1_trim_comp4_in_START (12)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc1_trim_comp4_in_END (15)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc2_trim_comp1_in_START (16)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc2_trim_comp1_in_END (19)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc2_trim_comp2_in_START (20)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc2_trim_comp2_in_END (23)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc2_trim_comp3_in_START (24)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc2_trim_comp3_in_END (27)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc2_trim_comp4_in_START (28)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM1_ocldo1_mregc2_trim_comp4_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo1_mregc3_trim_comp1_in : 4;
        unsigned int ocldo1_mregc3_trim_comp2_in : 4;
        unsigned int ocldo1_mregc3_trim_comp3_in : 4;
        unsigned int ocldo1_mregc3_trim_comp4_in : 4;
        unsigned int ocldo1_mregc4_trim_comp1_in : 4;
        unsigned int ocldo1_mregc4_trim_comp2_in : 4;
        unsigned int ocldo1_mregc4_trim_comp3_in : 4;
        unsigned int ocldo1_mregc4_trim_comp4_in : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc3_trim_comp1_in_START (0)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc3_trim_comp1_in_END (3)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc3_trim_comp2_in_START (4)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc3_trim_comp2_in_END (7)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc3_trim_comp3_in_START (8)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc3_trim_comp3_in_END (11)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc3_trim_comp4_in_START (12)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc3_trim_comp4_in_END (15)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc4_trim_comp1_in_START (16)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc4_trim_comp1_in_END (19)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc4_trim_comp2_in_START (20)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc4_trim_comp2_in_END (23)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc4_trim_comp3_in_START (24)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc4_trim_comp3_in_END (27)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc4_trim_comp4_in_START (28)
#define SOC_CORE_OCLDO_OCLDO1_SW_MREGC_TRIM2_ocldo1_mregc4_trim_comp4_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo1_mregc1_trim_comp1_dat : 4;
        unsigned int ocldo1_mregc1_trim_comp2_dat : 4;
        unsigned int ocldo1_mregc1_trim_comp3_dat : 4;
        unsigned int ocldo1_mregc1_trim_comp4_dat : 4;
        unsigned int ocldo1_mregc2_trim_comp1_dat : 4;
        unsigned int ocldo1_mregc2_trim_comp2_dat : 4;
        unsigned int ocldo1_mregc2_trim_comp3_dat : 4;
        unsigned int ocldo1_mregc2_trim_comp4_dat : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc1_trim_comp1_dat_START (0)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc1_trim_comp1_dat_END (3)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc1_trim_comp2_dat_START (4)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc1_trim_comp2_dat_END (7)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc1_trim_comp3_dat_START (8)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc1_trim_comp3_dat_END (11)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc1_trim_comp4_dat_START (12)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc1_trim_comp4_dat_END (15)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc2_trim_comp1_dat_START (16)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc2_trim_comp1_dat_END (19)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc2_trim_comp2_dat_START (20)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc2_trim_comp2_dat_END (23)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc2_trim_comp3_dat_START (24)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc2_trim_comp3_dat_END (27)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc2_trim_comp4_dat_START (28)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT1_ocldo1_mregc2_trim_comp4_dat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo1_mregc3_trim_comp1_dat : 4;
        unsigned int ocldo1_mregc3_trim_comp2_dat : 4;
        unsigned int ocldo1_mregc3_trim_comp3_dat : 4;
        unsigned int ocldo1_mregc3_trim_comp4_dat : 4;
        unsigned int ocldo1_mregc4_trim_comp1_dat : 4;
        unsigned int ocldo1_mregc4_trim_comp2_dat : 4;
        unsigned int ocldo1_mregc4_trim_comp3_dat : 4;
        unsigned int ocldo1_mregc4_trim_comp4_dat : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc3_trim_comp1_dat_START (0)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc3_trim_comp1_dat_END (3)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc3_trim_comp2_dat_START (4)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc3_trim_comp2_dat_END (7)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc3_trim_comp3_dat_START (8)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc3_trim_comp3_dat_END (11)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc3_trim_comp4_dat_START (12)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc3_trim_comp4_dat_END (15)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc4_trim_comp1_dat_START (16)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc4_trim_comp1_dat_END (19)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc4_trim_comp2_dat_START (20)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc4_trim_comp2_dat_END (23)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc4_trim_comp3_dat_START (24)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc4_trim_comp3_dat_END (27)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc4_trim_comp4_dat_START (28)
#define SOC_CORE_OCLDO_OCLDO1_MREGC_TRIM_STAT2_ocldo1_mregc4_trim_comp4_dat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo1_en_m_out : 4;
        unsigned int ocldo1_pset : 4;
        unsigned int ocldo1_vregc_resv_out : 4;
        unsigned int reserved : 4;
        unsigned int ocldo1_mregc1_trim_ok : 4;
        unsigned int ocldo1_mregc2_trim_ok : 4;
        unsigned int ocldo1_mregc3_trim_ok : 4;
        unsigned int ocldo1_mregc4_trim_ok : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO1_ANA_STAT_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_en_m_out_START (0)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_en_m_out_END (3)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_pset_START (4)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_pset_END (7)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_vregc_resv_out_START (8)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_vregc_resv_out_END (11)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_mregc1_trim_ok_START (16)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_mregc1_trim_ok_END (19)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_mregc2_trim_ok_START (20)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_mregc2_trim_ok_END (23)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_mregc3_trim_ok_START (24)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_mregc3_trim_ok_END (27)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_mregc4_trim_ok_START (28)
#define SOC_CORE_OCLDO_OCLDO1_ANA_STAT_ocldo1_mregc4_trim_ok_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo2_mregc1_trim_comp1_in : 4;
        unsigned int ocldo2_mregc1_trim_comp2_in : 4;
        unsigned int ocldo2_mregc1_trim_comp3_in : 4;
        unsigned int ocldo2_mregc1_trim_comp4_in : 4;
        unsigned int ocldo2_mregc2_trim_comp1_in : 4;
        unsigned int ocldo2_mregc2_trim_comp2_in : 4;
        unsigned int ocldo2_mregc2_trim_comp3_in : 4;
        unsigned int ocldo2_mregc2_trim_comp4_in : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc1_trim_comp1_in_START (0)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc1_trim_comp1_in_END (3)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc1_trim_comp2_in_START (4)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc1_trim_comp2_in_END (7)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc1_trim_comp3_in_START (8)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc1_trim_comp3_in_END (11)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc1_trim_comp4_in_START (12)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc1_trim_comp4_in_END (15)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc2_trim_comp1_in_START (16)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc2_trim_comp1_in_END (19)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc2_trim_comp2_in_START (20)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc2_trim_comp2_in_END (23)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc2_trim_comp3_in_START (24)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc2_trim_comp3_in_END (27)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc2_trim_comp4_in_START (28)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM1_ocldo2_mregc2_trim_comp4_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo2_mregc3_trim_comp1_in : 4;
        unsigned int ocldo2_mregc3_trim_comp2_in : 4;
        unsigned int ocldo2_mregc3_trim_comp3_in : 4;
        unsigned int ocldo2_mregc3_trim_comp4_in : 4;
        unsigned int ocldo2_mregc4_trim_comp1_in : 4;
        unsigned int ocldo2_mregc4_trim_comp2_in : 4;
        unsigned int ocldo2_mregc4_trim_comp3_in : 4;
        unsigned int ocldo2_mregc4_trim_comp4_in : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc3_trim_comp1_in_START (0)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc3_trim_comp1_in_END (3)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc3_trim_comp2_in_START (4)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc3_trim_comp2_in_END (7)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc3_trim_comp3_in_START (8)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc3_trim_comp3_in_END (11)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc3_trim_comp4_in_START (12)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc3_trim_comp4_in_END (15)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc4_trim_comp1_in_START (16)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc4_trim_comp1_in_END (19)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc4_trim_comp2_in_START (20)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc4_trim_comp2_in_END (23)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc4_trim_comp3_in_START (24)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc4_trim_comp3_in_END (27)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc4_trim_comp4_in_START (28)
#define SOC_CORE_OCLDO_OCLDO2_SW_MREGC_TRIM2_ocldo2_mregc4_trim_comp4_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo2_mregc1_trim_comp1_dat : 4;
        unsigned int ocldo2_mregc1_trim_comp2_dat : 4;
        unsigned int ocldo2_mregc1_trim_comp3_dat : 4;
        unsigned int ocldo2_mregc1_trim_comp4_dat : 4;
        unsigned int ocldo2_mregc2_trim_comp1_dat : 4;
        unsigned int ocldo2_mregc2_trim_comp2_dat : 4;
        unsigned int ocldo2_mregc2_trim_comp3_dat : 4;
        unsigned int ocldo2_mregc2_trim_comp4_dat : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc1_trim_comp1_dat_START (0)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc1_trim_comp1_dat_END (3)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc1_trim_comp2_dat_START (4)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc1_trim_comp2_dat_END (7)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc1_trim_comp3_dat_START (8)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc1_trim_comp3_dat_END (11)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc1_trim_comp4_dat_START (12)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc1_trim_comp4_dat_END (15)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc2_trim_comp1_dat_START (16)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc2_trim_comp1_dat_END (19)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc2_trim_comp2_dat_START (20)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc2_trim_comp2_dat_END (23)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc2_trim_comp3_dat_START (24)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc2_trim_comp3_dat_END (27)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc2_trim_comp4_dat_START (28)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT1_ocldo2_mregc2_trim_comp4_dat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo2_mregc3_trim_comp1_dat : 4;
        unsigned int ocldo2_mregc3_trim_comp2_dat : 4;
        unsigned int ocldo2_mregc3_trim_comp3_dat : 4;
        unsigned int ocldo2_mregc3_trim_comp4_dat : 4;
        unsigned int ocldo2_mregc4_trim_comp1_dat : 4;
        unsigned int ocldo2_mregc4_trim_comp2_dat : 4;
        unsigned int ocldo2_mregc4_trim_comp3_dat : 4;
        unsigned int ocldo2_mregc4_trim_comp4_dat : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc3_trim_comp1_dat_START (0)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc3_trim_comp1_dat_END (3)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc3_trim_comp2_dat_START (4)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc3_trim_comp2_dat_END (7)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc3_trim_comp3_dat_START (8)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc3_trim_comp3_dat_END (11)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc3_trim_comp4_dat_START (12)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc3_trim_comp4_dat_END (15)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc4_trim_comp1_dat_START (16)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc4_trim_comp1_dat_END (19)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc4_trim_comp2_dat_START (20)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc4_trim_comp2_dat_END (23)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc4_trim_comp3_dat_START (24)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc4_trim_comp3_dat_END (27)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc4_trim_comp4_dat_START (28)
#define SOC_CORE_OCLDO_OCLDO2_MREGC_TRIM_STAT2_ocldo2_mregc4_trim_comp4_dat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo2_en_m_out : 4;
        unsigned int ocldo2_pset : 4;
        unsigned int ocldo2_vregc_resv_out : 4;
        unsigned int reserved : 4;
        unsigned int ocldo2_mregc1_trim_ok : 4;
        unsigned int ocldo2_mregc2_trim_ok : 4;
        unsigned int ocldo2_mregc3_trim_ok : 4;
        unsigned int ocldo2_mregc4_trim_ok : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO2_ANA_STAT_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_en_m_out_START (0)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_en_m_out_END (3)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_pset_START (4)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_pset_END (7)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_vregc_resv_out_START (8)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_vregc_resv_out_END (11)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_mregc1_trim_ok_START (16)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_mregc1_trim_ok_END (19)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_mregc2_trim_ok_START (20)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_mregc2_trim_ok_END (23)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_mregc3_trim_ok_START (24)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_mregc3_trim_ok_END (27)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_mregc4_trim_ok_START (28)
#define SOC_CORE_OCLDO_OCLDO2_ANA_STAT_ocldo2_mregc4_trim_ok_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo3_mregc1_trim_comp1_in : 4;
        unsigned int ocldo3_mregc1_trim_comp2_in : 4;
        unsigned int ocldo3_mregc1_trim_comp3_in : 4;
        unsigned int ocldo3_mregc1_trim_comp4_in : 4;
        unsigned int ocldo3_mregc2_trim_comp1_in : 4;
        unsigned int ocldo3_mregc2_trim_comp2_in : 4;
        unsigned int ocldo3_mregc2_trim_comp3_in : 4;
        unsigned int ocldo3_mregc2_trim_comp4_in : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc1_trim_comp1_in_START (0)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc1_trim_comp1_in_END (3)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc1_trim_comp2_in_START (4)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc1_trim_comp2_in_END (7)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc1_trim_comp3_in_START (8)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc1_trim_comp3_in_END (11)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc1_trim_comp4_in_START (12)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc1_trim_comp4_in_END (15)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc2_trim_comp1_in_START (16)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc2_trim_comp1_in_END (19)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc2_trim_comp2_in_START (20)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc2_trim_comp2_in_END (23)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc2_trim_comp3_in_START (24)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc2_trim_comp3_in_END (27)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc2_trim_comp4_in_START (28)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM1_ocldo3_mregc2_trim_comp4_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo3_mregc3_trim_comp1_in : 4;
        unsigned int ocldo3_mregc3_trim_comp2_in : 4;
        unsigned int ocldo3_mregc3_trim_comp3_in : 4;
        unsigned int ocldo3_mregc3_trim_comp4_in : 4;
        unsigned int ocldo3_mregc4_trim_comp1_in : 4;
        unsigned int ocldo3_mregc4_trim_comp2_in : 4;
        unsigned int ocldo3_mregc4_trim_comp3_in : 4;
        unsigned int ocldo3_mregc4_trim_comp4_in : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc3_trim_comp1_in_START (0)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc3_trim_comp1_in_END (3)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc3_trim_comp2_in_START (4)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc3_trim_comp2_in_END (7)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc3_trim_comp3_in_START (8)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc3_trim_comp3_in_END (11)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc3_trim_comp4_in_START (12)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc3_trim_comp4_in_END (15)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc4_trim_comp1_in_START (16)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc4_trim_comp1_in_END (19)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc4_trim_comp2_in_START (20)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc4_trim_comp2_in_END (23)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc4_trim_comp3_in_START (24)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc4_trim_comp3_in_END (27)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc4_trim_comp4_in_START (28)
#define SOC_CORE_OCLDO_OCLDO3_SW_MREGC_TRIM2_ocldo3_mregc4_trim_comp4_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo3_mregc1_trim_comp1_dat : 4;
        unsigned int ocldo3_mregc1_trim_comp2_dat : 4;
        unsigned int ocldo3_mregc1_trim_comp3_dat : 4;
        unsigned int ocldo3_mregc1_trim_comp4_dat : 4;
        unsigned int ocldo3_mregc2_trim_comp1_dat : 4;
        unsigned int ocldo3_mregc2_trim_comp2_dat : 4;
        unsigned int ocldo3_mregc2_trim_comp3_dat : 4;
        unsigned int ocldo3_mregc2_trim_comp4_dat : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc1_trim_comp1_dat_START (0)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc1_trim_comp1_dat_END (3)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc1_trim_comp2_dat_START (4)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc1_trim_comp2_dat_END (7)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc1_trim_comp3_dat_START (8)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc1_trim_comp3_dat_END (11)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc1_trim_comp4_dat_START (12)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc1_trim_comp4_dat_END (15)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc2_trim_comp1_dat_START (16)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc2_trim_comp1_dat_END (19)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc2_trim_comp2_dat_START (20)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc2_trim_comp2_dat_END (23)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc2_trim_comp3_dat_START (24)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc2_trim_comp3_dat_END (27)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc2_trim_comp4_dat_START (28)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT1_ocldo3_mregc2_trim_comp4_dat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo3_mregc3_trim_comp1_dat : 4;
        unsigned int ocldo3_mregc3_trim_comp2_dat : 4;
        unsigned int ocldo3_mregc3_trim_comp3_dat : 4;
        unsigned int ocldo3_mregc3_trim_comp4_dat : 4;
        unsigned int ocldo3_mregc4_trim_comp1_dat : 4;
        unsigned int ocldo3_mregc4_trim_comp2_dat : 4;
        unsigned int ocldo3_mregc4_trim_comp3_dat : 4;
        unsigned int ocldo3_mregc4_trim_comp4_dat : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc3_trim_comp1_dat_START (0)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc3_trim_comp1_dat_END (3)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc3_trim_comp2_dat_START (4)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc3_trim_comp2_dat_END (7)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc3_trim_comp3_dat_START (8)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc3_trim_comp3_dat_END (11)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc3_trim_comp4_dat_START (12)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc3_trim_comp4_dat_END (15)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc4_trim_comp1_dat_START (16)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc4_trim_comp1_dat_END (19)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc4_trim_comp2_dat_START (20)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc4_trim_comp2_dat_END (23)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc4_trim_comp3_dat_START (24)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc4_trim_comp3_dat_END (27)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc4_trim_comp4_dat_START (28)
#define SOC_CORE_OCLDO_OCLDO3_MREGC_TRIM_STAT2_ocldo3_mregc4_trim_comp4_dat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocldo3_en_m_out : 4;
        unsigned int ocldo3_pset : 4;
        unsigned int ocldo3_vregc_resv_out : 4;
        unsigned int reserved : 4;
        unsigned int ocldo3_mregc1_trim_ok : 4;
        unsigned int ocldo3_mregc2_trim_ok : 4;
        unsigned int ocldo3_mregc3_trim_ok : 4;
        unsigned int ocldo3_mregc4_trim_ok : 4;
    } reg;
} SOC_CORE_OCLDO_OCLDO3_ANA_STAT_UNION;
#endif
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_en_m_out_START (0)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_en_m_out_END (3)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_pset_START (4)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_pset_END (7)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_vregc_resv_out_START (8)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_vregc_resv_out_END (11)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_mregc1_trim_ok_START (16)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_mregc1_trim_ok_END (19)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_mregc2_trim_ok_START (20)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_mregc2_trim_ok_END (23)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_mregc3_trim_ok_START (24)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_mregc3_trim_ok_END (27)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_mregc4_trim_ok_START (28)
#define SOC_CORE_OCLDO_OCLDO3_ANA_STAT_ocldo3_mregc4_trim_ok_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

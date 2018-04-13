#ifndef __SOC_REMAPCTRL_INTERFACE_H__
#define __SOC_REMAPCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_REMAPCTRL_REMAP_CFG_ADDR(base) ((base) + (0x000))
#define SOC_REMAPCTRL_MAP_TABLE_WP_ADDR(base) ((base) + (0x004))
#define SOC_REMAPCTRL_LP_CTRL_ADDR(base) ((base) + (0x008))
#define SOC_REMAPCTRL_LP_CTRL_1_ADDR(base) ((base) + (0x00C))
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY0_ADDR(base) ((base) + (0x010))
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY1_ADDR(base) ((base) + (0x014))
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY2_ADDR(base) ((base) + (0x018))
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY3_ADDR(base) ((base) + (0x01C))
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY4_ADDR(base) ((base) + (0x020))
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY5_ADDR(base) ((base) + (0x024))
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY6_ADDR(base) ((base) + (0x028))
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY7_ADDR(base) ((base) + (0x02C))
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY0_ADDR(base) ((base) + (0x030))
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY1_ADDR(base) ((base) + (0x034))
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY2_ADDR(base) ((base) + (0x038))
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY3_ADDR(base) ((base) + (0x03C))
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY4_ADDR(base) ((base) + (0x040))
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY5_ADDR(base) ((base) + (0x044))
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY6_ADDR(base) ((base) + (0x048))
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY7_ADDR(base) ((base) + (0x04C))
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY0_ADDR(base) ((base) + (0x050))
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY1_ADDR(base) ((base) + (0x054))
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY2_ADDR(base) ((base) + (0x058))
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY3_ADDR(base) ((base) + (0x05C))
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY4_ADDR(base) ((base) + (0x060))
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY5_ADDR(base) ((base) + (0x064))
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY6_ADDR(base) ((base) + (0x068))
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY7_ADDR(base) ((base) + (0x06C))
#define SOC_REMAPCTRL_ITCM_HIT_CNT_ADDR(base) ((base) + (0x070))
#define SOC_REMAPCTRL_ITCM_MISS_CNT_ADDR(base) ((base) + (0x074))
#define SOC_REMAPCTRL_D0TCM_HIT_CNT_ADDR(base) ((base) + (0x078))
#define SOC_REMAPCTRL_D0TCM_MISS_CNT_ADDR(base) ((base) + (0x07C))
#define SOC_REMAPCTRL_D1TCM_HIT_CNT_ADDR(base) ((base) + (0x080))
#define SOC_REMAPCTRL_D1TCM_MISS_CNT_ADDR(base) ((base) + (0x084))
#define SOC_REMAPCTRL_BANK_MEM_CTRL_3_ADDR(base) ((base) + (0x088))
#define SOC_REMAPCTRL_BANK_MEM_CTRL_ADDR(base) ((base) + (0x08C))
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_ADDR(base) ((base) + (0x090))
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_ADDR(base) ((base) + (0x094))
#define SOC_REMAPCTRL_LP_CTRL_2_ADDR(base) ((base) + (0x098))
#define SOC_REMAPCTRL_TCM_ERR_TYPE_ADDR(base) ((base) + (0x09C))
#define SOC_REMAPCTRL_BANK_SEL_ADDR(base) ((base) + (0x0A0))
#define SOC_REMAPCTRL_ITCM_ERR_ADDR_ADDR(base) ((base) + (0x0A8))
#define SOC_REMAPCTRL_D0TCM_ERR_ADDR_ADDR(base) ((base) + (0x0AC))
#define SOC_REMAPCTRL_D1TCM_ERR_ADDR_ADDR(base) ((base) + (0x0B0))
#define SOC_REMAPCTRL_ITCM_ERR_CNT_ADDR(base) ((base) + (0x0B4))
#define SOC_REMAPCTRL_D0TCM_ERR_CNT_ADDR(base) ((base) + (0x0B8))
#define SOC_REMAPCTRL_D1TCM_ERR_CNT_ADDR(base) ((base) + (0x0BC))
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B0_ADDR(base) ((base) + (0x0C0))
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B1_ADDR(base) ((base) + (0x0C4))
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B2_ADDR(base) ((base) + (0x0C8))
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B3_ADDR(base) ((base) + (0x0CC))
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B4_ADDR(base) ((base) + (0x0D0))
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B5_ADDR(base) ((base) + (0x0D4))
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B6_ADDR(base) ((base) + (0x0D8))
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B7_ADDR(base) ((base) + (0x0DC))
#define SOC_REMAPCTRL_DY_LOAD_EN_ADDR(base) ((base) + (0x0E0))
#define SOC_REMAPCTRL_DY_LOAD_CLR_ADDR(base) ((base) + (0x0E4))
#define SOC_REMAPCTRL_ENTRY_CNT15_ADDR(base) ((base) + (0x100))
#define SOC_REMAPCTRL_ENTRY_CNT14_ADDR(base) ((base) + (0x104))
#define SOC_REMAPCTRL_ENTRY_CNT13_ADDR(base) ((base) + (0x108))
#define SOC_REMAPCTRL_ENTRY_CNT12_ADDR(base) ((base) + (0x10C))
#define SOC_REMAPCTRL_ENTRY_CNT11_ADDR(base) ((base) + (0x110))
#define SOC_REMAPCTRL_ENTRY_CNT10_ADDR(base) ((base) + (0x114))
#define SOC_REMAPCTRL_ENTRY_CNT9_ADDR(base) ((base) + (0x118))
#define SOC_REMAPCTRL_ENTRY_CNT8_ADDR(base) ((base) + (0x11C))
#define SOC_REMAPCTRL_ENTRY_CNT7_ADDR(base) ((base) + (0x120))
#define SOC_REMAPCTRL_ENTRY_CNT6_ADDR(base) ((base) + (0x124))
#define SOC_REMAPCTRL_ENTRY_CNT5_ADDR(base) ((base) + (0x128))
#define SOC_REMAPCTRL_ENTRY_CNT4_ADDR(base) ((base) + (0x12C))
#define SOC_REMAPCTRL_ENTRY_CNT3_ADDR(base) ((base) + (0x130))
#define SOC_REMAPCTRL_ENTRY_CNT2_ADDR(base) ((base) + (0x134))
#define SOC_REMAPCTRL_ENTRY_CNT1_ADDR(base) ((base) + (0x138))
#define SOC_REMAPCTRL_ENTRY_CNT0_ADDR(base) ((base) + (0x13C))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int invalid : 1;
        unsigned int itcm_cnt_clr : 1;
        unsigned int d0tcm_cnt_clr : 1;
        unsigned int d1tcm_cnt_clr : 1;
        unsigned int itcm_err_cnt_clr : 1;
        unsigned int d0tcm_err_cnt_clr : 1;
        unsigned int d1tcm_err_cnt_clr : 1;
        unsigned int itcm_err_clr : 1;
        unsigned int d0tcm_err_clr : 1;
        unsigned int d1tcm_err_clr : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_REMAPCTRL_REMAP_CFG_UNION;
#endif
#define SOC_REMAPCTRL_REMAP_CFG_bypass_START (0)
#define SOC_REMAPCTRL_REMAP_CFG_bypass_END (0)
#define SOC_REMAPCTRL_REMAP_CFG_invalid_START (1)
#define SOC_REMAPCTRL_REMAP_CFG_invalid_END (1)
#define SOC_REMAPCTRL_REMAP_CFG_itcm_cnt_clr_START (2)
#define SOC_REMAPCTRL_REMAP_CFG_itcm_cnt_clr_END (2)
#define SOC_REMAPCTRL_REMAP_CFG_d0tcm_cnt_clr_START (3)
#define SOC_REMAPCTRL_REMAP_CFG_d0tcm_cnt_clr_END (3)
#define SOC_REMAPCTRL_REMAP_CFG_d1tcm_cnt_clr_START (4)
#define SOC_REMAPCTRL_REMAP_CFG_d1tcm_cnt_clr_END (4)
#define SOC_REMAPCTRL_REMAP_CFG_itcm_err_cnt_clr_START (5)
#define SOC_REMAPCTRL_REMAP_CFG_itcm_err_cnt_clr_END (5)
#define SOC_REMAPCTRL_REMAP_CFG_d0tcm_err_cnt_clr_START (6)
#define SOC_REMAPCTRL_REMAP_CFG_d0tcm_err_cnt_clr_END (6)
#define SOC_REMAPCTRL_REMAP_CFG_d1tcm_err_cnt_clr_START (7)
#define SOC_REMAPCTRL_REMAP_CFG_d1tcm_err_cnt_clr_END (7)
#define SOC_REMAPCTRL_REMAP_CFG_itcm_err_clr_START (8)
#define SOC_REMAPCTRL_REMAP_CFG_itcm_err_clr_END (8)
#define SOC_REMAPCTRL_REMAP_CFG_d0tcm_err_clr_START (9)
#define SOC_REMAPCTRL_REMAP_CFG_d0tcm_err_clr_END (9)
#define SOC_REMAPCTRL_REMAP_CFG_d1tcm_err_clr_START (10)
#define SOC_REMAPCTRL_REMAP_CFG_d1tcm_err_clr_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mt_wp : 32;
    } reg;
} SOC_REMAPCTRL_MAP_TABLE_WP_UNION;
#endif
#define SOC_REMAPCTRL_MAP_TABLE_WP_mt_wp_START (0)
#define SOC_REMAPCTRL_MAP_TABLE_WP_mt_wp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int auto_gate_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int auto_gate_cnt : 8;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_REMAPCTRL_LP_CTRL_UNION;
#endif
#define SOC_REMAPCTRL_LP_CTRL_auto_gate_en_START (0)
#define SOC_REMAPCTRL_LP_CTRL_auto_gate_en_END (0)
#define SOC_REMAPCTRL_LP_CTRL_auto_gate_cnt_START (4)
#define SOC_REMAPCTRL_LP_CTRL_auto_gate_cnt_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcm128_gate_en_soft : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_REMAPCTRL_LP_CTRL_1_UNION;
#endif
#define SOC_REMAPCTRL_LP_CTRL_1_tcm128_gate_en_soft_START (0)
#define SOC_REMAPCTRL_LP_CTRL_1_tcm128_gate_en_soft_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_tlb_entry0 : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_REMAPCTRL_ITCM_TLB_ENTRY0_UNION;
#endif
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY0_itcm_tlb_entry0_START (0)
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY0_itcm_tlb_entry0_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_tlb_entry1 : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_REMAPCTRL_ITCM_TLB_ENTRY1_UNION;
#endif
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY1_itcm_tlb_entry1_START (0)
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY1_itcm_tlb_entry1_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_tlb_entry2 : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_REMAPCTRL_ITCM_TLB_ENTRY2_UNION;
#endif
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY2_itcm_tlb_entry2_START (0)
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY2_itcm_tlb_entry2_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_tlb_entry3 : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_REMAPCTRL_ITCM_TLB_ENTRY3_UNION;
#endif
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY3_itcm_tlb_entry3_START (0)
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY3_itcm_tlb_entry3_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_tlb_entry4 : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_REMAPCTRL_ITCM_TLB_ENTRY4_UNION;
#endif
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY4_itcm_tlb_entry4_START (0)
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY4_itcm_tlb_entry4_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_tlb_entry5 : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_REMAPCTRL_ITCM_TLB_ENTRY5_UNION;
#endif
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY5_itcm_tlb_entry5_START (0)
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY5_itcm_tlb_entry5_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_tlb_entry6 : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_REMAPCTRL_ITCM_TLB_ENTRY6_UNION;
#endif
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY6_itcm_tlb_entry6_START (0)
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY6_itcm_tlb_entry6_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_tlb_entry7 : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_REMAPCTRL_ITCM_TLB_ENTRY7_UNION;
#endif
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY7_itcm_tlb_entry7_START (0)
#define SOC_REMAPCTRL_ITCM_TLB_ENTRY7_itcm_tlb_entry7_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d0tcm_tlb_entry0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D0TCM_TLB_ENTRY0_UNION;
#endif
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY0_d0tcm_tlb_entry0_START (0)
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY0_d0tcm_tlb_entry0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d0tcm_tlb_entry1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D0TCM_TLB_ENTRY1_UNION;
#endif
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY1_d0tcm_tlb_entry1_START (0)
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY1_d0tcm_tlb_entry1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d0tcm_tlb_entry2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D0TCM_TLB_ENTRY2_UNION;
#endif
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY2_d0tcm_tlb_entry2_START (0)
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY2_d0tcm_tlb_entry2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d0tcm_tlb_entry3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D0TCM_TLB_ENTRY3_UNION;
#endif
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY3_d0tcm_tlb_entry3_START (0)
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY3_d0tcm_tlb_entry3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d0tcm_tlb_entry4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D0TCM_TLB_ENTRY4_UNION;
#endif
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY4_d0tcm_tlb_entry4_START (0)
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY4_d0tcm_tlb_entry4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d0tcm_tlb_entry5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D0TCM_TLB_ENTRY5_UNION;
#endif
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY5_d0tcm_tlb_entry5_START (0)
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY5_d0tcm_tlb_entry5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d0tcm_tlb_entry6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D0TCM_TLB_ENTRY6_UNION;
#endif
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY6_d0tcm_tlb_entry6_START (0)
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY6_d0tcm_tlb_entry6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d0tcm_tlb_entry7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D0TCM_TLB_ENTRY7_UNION;
#endif
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY7_d0tcm_tlb_entry7_START (0)
#define SOC_REMAPCTRL_D0TCM_TLB_ENTRY7_d0tcm_tlb_entry7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d1tcm_tlb_entry0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D1TCM_TLB_ENTRY0_UNION;
#endif
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY0_d1tcm_tlb_entry0_START (0)
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY0_d1tcm_tlb_entry0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d1tcm_tlb_entry1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D1TCM_TLB_ENTRY1_UNION;
#endif
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY1_d1tcm_tlb_entry1_START (0)
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY1_d1tcm_tlb_entry1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d1tcm_tlb_entry2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D1TCM_TLB_ENTRY2_UNION;
#endif
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY2_d1tcm_tlb_entry2_START (0)
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY2_d1tcm_tlb_entry2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d1tcm_tlb_entry3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D1TCM_TLB_ENTRY3_UNION;
#endif
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY3_d1tcm_tlb_entry3_START (0)
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY3_d1tcm_tlb_entry3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d1tcm_tlb_entry4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D1TCM_TLB_ENTRY4_UNION;
#endif
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY4_d1tcm_tlb_entry4_START (0)
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY4_d1tcm_tlb_entry4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d1tcm_tlb_entry5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D1TCM_TLB_ENTRY5_UNION;
#endif
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY5_d1tcm_tlb_entry5_START (0)
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY5_d1tcm_tlb_entry5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d1tcm_tlb_entry6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D1TCM_TLB_ENTRY6_UNION;
#endif
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY6_d1tcm_tlb_entry6_START (0)
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY6_d1tcm_tlb_entry6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d1tcm_tlb_entry7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_REMAPCTRL_D1TCM_TLB_ENTRY7_UNION;
#endif
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY7_d1tcm_tlb_entry7_START (0)
#define SOC_REMAPCTRL_D1TCM_TLB_ENTRY7_d1tcm_tlb_entry7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_hit_cnt : 32;
    } reg;
} SOC_REMAPCTRL_ITCM_HIT_CNT_UNION;
#endif
#define SOC_REMAPCTRL_ITCM_HIT_CNT_itcm_hit_cnt_START (0)
#define SOC_REMAPCTRL_ITCM_HIT_CNT_itcm_hit_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_miss_cnt : 32;
    } reg;
} SOC_REMAPCTRL_ITCM_MISS_CNT_UNION;
#endif
#define SOC_REMAPCTRL_ITCM_MISS_CNT_itcm_miss_cnt_START (0)
#define SOC_REMAPCTRL_ITCM_MISS_CNT_itcm_miss_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d0tcm_hit_cnt : 32;
    } reg;
} SOC_REMAPCTRL_D0TCM_HIT_CNT_UNION;
#endif
#define SOC_REMAPCTRL_D0TCM_HIT_CNT_d0tcm_hit_cnt_START (0)
#define SOC_REMAPCTRL_D0TCM_HIT_CNT_d0tcm_hit_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d0tcm_miss_cnt : 32;
    } reg;
} SOC_REMAPCTRL_D0TCM_MISS_CNT_UNION;
#endif
#define SOC_REMAPCTRL_D0TCM_MISS_CNT_d0tcm_miss_cnt_START (0)
#define SOC_REMAPCTRL_D0TCM_MISS_CNT_d0tcm_miss_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d1tcm_hit_cnt : 32;
    } reg;
} SOC_REMAPCTRL_D1TCM_HIT_CNT_UNION;
#endif
#define SOC_REMAPCTRL_D1TCM_HIT_CNT_d1tcm_hit_cnt_START (0)
#define SOC_REMAPCTRL_D1TCM_HIT_CNT_d1tcm_hit_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d1tcm_miss_cnt : 32;
    } reg;
} SOC_REMAPCTRL_D1TCM_MISS_CNT_UNION;
#endif
#define SOC_REMAPCTRL_D1TCM_MISS_CNT_d1tcm_miss_cnt_START (0)
#define SOC_REMAPCTRL_D1TCM_MISS_CNT_d1tcm_miss_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bank14_mem_ctrl_s : 3;
        unsigned int reserved_0 : 1;
        unsigned int bank15_mem_ctrl_s : 3;
        unsigned int reserved_1 : 1;
        unsigned int bank16_mem_ctrl_s : 3;
        unsigned int reserved_2 : 1;
        unsigned int bank17_mem_ctrl_s : 3;
        unsigned int reserved_3 : 17;
    } reg;
} SOC_REMAPCTRL_BANK_MEM_CTRL_3_UNION;
#endif
#define SOC_REMAPCTRL_BANK_MEM_CTRL_3_bank14_mem_ctrl_s_START (0)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_3_bank14_mem_ctrl_s_END (2)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_3_bank15_mem_ctrl_s_START (4)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_3_bank15_mem_ctrl_s_END (6)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_3_bank16_mem_ctrl_s_START (8)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_3_bank16_mem_ctrl_s_END (10)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_3_bank17_mem_ctrl_s_START (12)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_3_bank17_mem_ctrl_s_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bank0_mem_ctrl_s : 3;
        unsigned int reserved_0 : 1;
        unsigned int bank1_mem_ctrl_s : 3;
        unsigned int reserved_1 : 1;
        unsigned int bank2_mem_ctrl_s : 3;
        unsigned int reserved_2 : 1;
        unsigned int bank3_mem_ctrl_s : 3;
        unsigned int reserved_3 : 1;
        unsigned int bank4_mem_ctrl_s : 3;
        unsigned int reserved_4 : 1;
        unsigned int bank5_mem_ctrl_s : 3;
        unsigned int reserved_5 : 1;
        unsigned int bank6_mem_ctrl_s : 3;
        unsigned int reserved_6 : 5;
    } reg;
} SOC_REMAPCTRL_BANK_MEM_CTRL_UNION;
#endif
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank0_mem_ctrl_s_START (0)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank0_mem_ctrl_s_END (2)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank1_mem_ctrl_s_START (4)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank1_mem_ctrl_s_END (6)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank2_mem_ctrl_s_START (8)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank2_mem_ctrl_s_END (10)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank3_mem_ctrl_s_START (12)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank3_mem_ctrl_s_END (14)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank4_mem_ctrl_s_START (16)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank4_mem_ctrl_s_END (18)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank5_mem_ctrl_s_START (20)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank5_mem_ctrl_s_END (22)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank6_mem_ctrl_s_START (24)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_bank6_mem_ctrl_s_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bank7_mem_ctrl_s : 3;
        unsigned int reserved_0 : 1;
        unsigned int bank8_mem_ctrl_s : 3;
        unsigned int reserved_1 : 1;
        unsigned int bank9_mem_ctrl_s : 3;
        unsigned int reserved_2 : 1;
        unsigned int bank10_mem_ctrl_s : 3;
        unsigned int reserved_3 : 1;
        unsigned int bank11_mem_ctrl_s : 3;
        unsigned int reserved_4 : 1;
        unsigned int bank12_mem_ctrl_s : 3;
        unsigned int reserved_5 : 1;
        unsigned int bank13_mem_ctrl_s : 3;
        unsigned int reserved_6 : 5;
    } reg;
} SOC_REMAPCTRL_BANK_MEM_CTRL_1_UNION;
#endif
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank7_mem_ctrl_s_START (0)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank7_mem_ctrl_s_END (2)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank8_mem_ctrl_s_START (4)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank8_mem_ctrl_s_END (6)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank9_mem_ctrl_s_START (8)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank9_mem_ctrl_s_END (10)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank10_mem_ctrl_s_START (12)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank10_mem_ctrl_s_END (14)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank11_mem_ctrl_s_START (16)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank11_mem_ctrl_s_END (18)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank12_mem_ctrl_s_START (20)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank12_mem_ctrl_s_END (22)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank13_mem_ctrl_s_START (24)
#define SOC_REMAPCTRL_BANK_MEM_CTRL_1_bank13_mem_ctrl_s_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_err_bank7 : 1;
        unsigned int itcm_err_bank8 : 1;
        unsigned int itcm_err_bank9 : 1;
        unsigned int itcm_err_bank10 : 1;
        unsigned int d0tcm_err_bank7 : 1;
        unsigned int d0tcm_err_bank8 : 1;
        unsigned int d0tcm_err_bank9 : 1;
        unsigned int d0tcm_err_bank10 : 1;
        unsigned int d1tcm_err_bank7 : 1;
        unsigned int d1tcm_err_bank8 : 1;
        unsigned int d1tcm_err_bank9 : 1;
        unsigned int d1tcm_err_bank10 : 1;
        unsigned int itcm_err_bank11 : 1;
        unsigned int d0tcm_err_bank11 : 1;
        unsigned int d1tcm_err_bank11 : 1;
        unsigned int itcm_err_bank12 : 1;
        unsigned int d0tcm_err_bank12 : 1;
        unsigned int d1tcm_err_bank12 : 1;
        unsigned int itcm_err_bank13 : 1;
        unsigned int d0tcm_err_bank13 : 1;
        unsigned int d1tcm_err_bank13 : 1;
        unsigned int itcm_err_bank14 : 1;
        unsigned int d0tcm_err_bank14 : 1;
        unsigned int d1tcm_err_bank14 : 1;
        unsigned int itcm_err_bank15 : 1;
        unsigned int d0tcm_err_bank15 : 1;
        unsigned int d1tcm_err_bank15 : 1;
        unsigned int itcm_err_bank16 : 1;
        unsigned int d0tcm_err_bank16 : 1;
        unsigned int d1tcm_err_bank16 : 1;
        unsigned int d0tcm_err_bank17 : 1;
        unsigned int d1tcm_err_bank17 : 1;
    } reg;
} SOC_REMAPCTRL_TCM_ERR_TYPE_1_UNION;
#endif
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank7_START (0)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank7_END (0)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank8_START (1)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank8_END (1)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank9_START (2)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank9_END (2)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank10_START (3)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank10_END (3)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank7_START (4)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank7_END (4)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank8_START (5)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank8_END (5)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank9_START (6)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank9_END (6)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank10_START (7)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank10_END (7)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank7_START (8)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank7_END (8)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank8_START (9)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank8_END (9)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank9_START (10)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank9_END (10)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank10_START (11)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank10_END (11)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank11_START (12)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank11_END (12)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank11_START (13)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank11_END (13)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank11_START (14)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank11_END (14)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank12_START (15)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank12_END (15)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank12_START (16)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank12_END (16)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank12_START (17)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank12_END (17)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank13_START (18)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank13_END (18)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank13_START (19)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank13_END (19)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank13_START (20)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank13_END (20)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank14_START (21)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank14_END (21)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank14_START (22)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank14_END (22)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank14_START (23)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank14_END (23)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank15_START (24)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank15_END (24)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank15_START (25)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank15_END (25)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank15_START (26)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank15_END (26)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank16_START (27)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_itcm_err_bank16_END (27)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank16_START (28)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank16_END (28)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank16_START (29)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank16_END (29)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank17_START (30)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d0tcm_err_bank17_END (30)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank17_START (31)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_1_d1tcm_err_bank17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcmaddr_boundary_check_bypass : 1;
        unsigned int bank_collision_check_bypass : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_REMAPCTRL_LP_CTRL_2_UNION;
#endif
#define SOC_REMAPCTRL_LP_CTRL_2_tcmaddr_boundary_check_bypass_START (0)
#define SOC_REMAPCTRL_LP_CTRL_2_tcmaddr_boundary_check_bypass_END (0)
#define SOC_REMAPCTRL_LP_CTRL_2_bank_collision_check_bypass_START (1)
#define SOC_REMAPCTRL_LP_CTRL_2_bank_collision_check_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_page_err : 1;
        unsigned int itcmaddr_out_576k_err : 1;
        unsigned int reserved_0 : 2;
        unsigned int d0tcm_page_err : 1;
        unsigned int d0tcmaddr_out_576k_err : 1;
        unsigned int reserved_1 : 2;
        unsigned int d1tcm_page_err : 1;
        unsigned int d1tcmaddr_out_576k_err : 1;
        unsigned int itcm_err_bank0 : 1;
        unsigned int itcm_err_bank1 : 1;
        unsigned int itcm_err_bank2 : 1;
        unsigned int itcm_err_bank3 : 1;
        unsigned int itcm_err_bank4 : 1;
        unsigned int itcm_err_bank5 : 1;
        unsigned int itcm_err_bank6 : 1;
        unsigned int d0tcm_err_bank0 : 1;
        unsigned int d0tcm_err_bank1 : 1;
        unsigned int d0tcm_err_bank2 : 1;
        unsigned int d0tcm_err_bank3 : 1;
        unsigned int d0tcm_err_bank4 : 1;
        unsigned int d0tcm_err_bank5 : 1;
        unsigned int d0tcm_err_bank6 : 1;
        unsigned int d1tcm_err_bank0 : 1;
        unsigned int d1tcm_err_bank1 : 1;
        unsigned int d1tcm_err_bank2 : 1;
        unsigned int d1tcm_err_bank3 : 1;
        unsigned int d1tcm_err_bank4 : 1;
        unsigned int d1tcm_err_bank5 : 1;
        unsigned int d1tcm_err_bank6 : 1;
        unsigned int itcm_err_bank17 : 1;
    } reg;
} SOC_REMAPCTRL_TCM_ERR_TYPE_UNION;
#endif
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_page_err_START (0)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_page_err_END (0)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcmaddr_out_576k_err_START (1)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcmaddr_out_576k_err_END (1)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_page_err_START (4)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_page_err_END (4)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcmaddr_out_576k_err_START (5)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcmaddr_out_576k_err_END (5)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_page_err_START (8)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_page_err_END (8)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcmaddr_out_576k_err_START (9)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcmaddr_out_576k_err_END (9)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank0_START (10)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank0_END (10)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank1_START (11)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank1_END (11)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank2_START (12)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank2_END (12)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank3_START (13)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank3_END (13)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank4_START (14)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank4_END (14)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank5_START (15)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank5_END (15)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank6_START (16)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank6_END (16)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank0_START (17)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank0_END (17)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank1_START (18)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank1_END (18)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank2_START (19)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank2_END (19)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank3_START (20)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank3_END (20)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank4_START (21)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank4_END (21)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank5_START (22)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank5_END (22)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank6_START (23)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d0tcm_err_bank6_END (23)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank0_START (24)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank0_END (24)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank1_START (25)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank1_END (25)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank2_START (26)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank2_END (26)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank3_START (27)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank3_END (27)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank4_START (28)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank4_END (28)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank5_START (29)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank5_END (29)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank6_START (30)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_d1tcm_err_bank6_END (30)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank17_START (31)
#define SOC_REMAPCTRL_TCM_ERR_TYPE_itcm_err_bank17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bank0_sel : 1;
        unsigned int bank1_sel : 1;
        unsigned int bank2_sel : 1;
        unsigned int bank3_sel : 1;
        unsigned int bank4_sel : 1;
        unsigned int bank5_sel : 1;
        unsigned int bank6_sel : 1;
        unsigned int bank7_sel : 1;
        unsigned int bank8_sel : 1;
        unsigned int bank9_sel : 1;
        unsigned int bank10_sel : 1;
        unsigned int bank11_sel : 1;
        unsigned int bank12_sel : 1;
        unsigned int bank13_sel : 1;
        unsigned int bank14_sel : 1;
        unsigned int bank15_sel : 1;
        unsigned int bank16_sel : 1;
        unsigned int bank17_sel : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_REMAPCTRL_BANK_SEL_UNION;
#endif
#define SOC_REMAPCTRL_BANK_SEL_bank0_sel_START (0)
#define SOC_REMAPCTRL_BANK_SEL_bank0_sel_END (0)
#define SOC_REMAPCTRL_BANK_SEL_bank1_sel_START (1)
#define SOC_REMAPCTRL_BANK_SEL_bank1_sel_END (1)
#define SOC_REMAPCTRL_BANK_SEL_bank2_sel_START (2)
#define SOC_REMAPCTRL_BANK_SEL_bank2_sel_END (2)
#define SOC_REMAPCTRL_BANK_SEL_bank3_sel_START (3)
#define SOC_REMAPCTRL_BANK_SEL_bank3_sel_END (3)
#define SOC_REMAPCTRL_BANK_SEL_bank4_sel_START (4)
#define SOC_REMAPCTRL_BANK_SEL_bank4_sel_END (4)
#define SOC_REMAPCTRL_BANK_SEL_bank5_sel_START (5)
#define SOC_REMAPCTRL_BANK_SEL_bank5_sel_END (5)
#define SOC_REMAPCTRL_BANK_SEL_bank6_sel_START (6)
#define SOC_REMAPCTRL_BANK_SEL_bank6_sel_END (6)
#define SOC_REMAPCTRL_BANK_SEL_bank7_sel_START (7)
#define SOC_REMAPCTRL_BANK_SEL_bank7_sel_END (7)
#define SOC_REMAPCTRL_BANK_SEL_bank8_sel_START (8)
#define SOC_REMAPCTRL_BANK_SEL_bank8_sel_END (8)
#define SOC_REMAPCTRL_BANK_SEL_bank9_sel_START (9)
#define SOC_REMAPCTRL_BANK_SEL_bank9_sel_END (9)
#define SOC_REMAPCTRL_BANK_SEL_bank10_sel_START (10)
#define SOC_REMAPCTRL_BANK_SEL_bank10_sel_END (10)
#define SOC_REMAPCTRL_BANK_SEL_bank11_sel_START (11)
#define SOC_REMAPCTRL_BANK_SEL_bank11_sel_END (11)
#define SOC_REMAPCTRL_BANK_SEL_bank12_sel_START (12)
#define SOC_REMAPCTRL_BANK_SEL_bank12_sel_END (12)
#define SOC_REMAPCTRL_BANK_SEL_bank13_sel_START (13)
#define SOC_REMAPCTRL_BANK_SEL_bank13_sel_END (13)
#define SOC_REMAPCTRL_BANK_SEL_bank14_sel_START (14)
#define SOC_REMAPCTRL_BANK_SEL_bank14_sel_END (14)
#define SOC_REMAPCTRL_BANK_SEL_bank15_sel_START (15)
#define SOC_REMAPCTRL_BANK_SEL_bank15_sel_END (15)
#define SOC_REMAPCTRL_BANK_SEL_bank16_sel_START (16)
#define SOC_REMAPCTRL_BANK_SEL_bank16_sel_END (16)
#define SOC_REMAPCTRL_BANK_SEL_bank17_sel_START (17)
#define SOC_REMAPCTRL_BANK_SEL_bank17_sel_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_err_addr : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_REMAPCTRL_ITCM_ERR_ADDR_UNION;
#endif
#define SOC_REMAPCTRL_ITCM_ERR_ADDR_itcm_err_addr_START (0)
#define SOC_REMAPCTRL_ITCM_ERR_ADDR_itcm_err_addr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d0tcm_err_addr : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_REMAPCTRL_D0TCM_ERR_ADDR_UNION;
#endif
#define SOC_REMAPCTRL_D0TCM_ERR_ADDR_d0tcm_err_addr_START (0)
#define SOC_REMAPCTRL_D0TCM_ERR_ADDR_d0tcm_err_addr_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d1tcm_err_addr : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_REMAPCTRL_D1TCM_ERR_ADDR_UNION;
#endif
#define SOC_REMAPCTRL_D1TCM_ERR_ADDR_d1tcm_err_addr_START (0)
#define SOC_REMAPCTRL_D1TCM_ERR_ADDR_d1tcm_err_addr_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_err_cnt : 32;
    } reg;
} SOC_REMAPCTRL_ITCM_ERR_CNT_UNION;
#endif
#define SOC_REMAPCTRL_ITCM_ERR_CNT_itcm_err_cnt_START (0)
#define SOC_REMAPCTRL_ITCM_ERR_CNT_itcm_err_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d0tcm_err_cnt : 32;
    } reg;
} SOC_REMAPCTRL_D0TCM_ERR_CNT_UNION;
#endif
#define SOC_REMAPCTRL_D0TCM_ERR_CNT_d0tcm_err_cnt_START (0)
#define SOC_REMAPCTRL_D0TCM_ERR_CNT_d0tcm_err_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d1tcm_err_cnt : 32;
    } reg;
} SOC_REMAPCTRL_D1TCM_ERR_CNT_UNION;
#endif
#define SOC_REMAPCTRL_D1TCM_ERR_CNT_d1tcm_err_cnt_START (0)
#define SOC_REMAPCTRL_D1TCM_ERR_CNT_d1tcm_err_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dy_load_addr0 : 11;
        unsigned int dy_load_addr1 : 11;
        unsigned int reserved : 10;
    } reg;
} SOC_REMAPCTRL_DY_LOAD_ADDR_B0_UNION;
#endif
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B0_dy_load_addr0_START (0)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B0_dy_load_addr0_END (10)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B0_dy_load_addr1_START (11)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B0_dy_load_addr1_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dy_load_addr2 : 11;
        unsigned int dy_load_addr3 : 11;
        unsigned int reserved : 10;
    } reg;
} SOC_REMAPCTRL_DY_LOAD_ADDR_B1_UNION;
#endif
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B1_dy_load_addr2_START (0)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B1_dy_load_addr2_END (10)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B1_dy_load_addr3_START (11)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B1_dy_load_addr3_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dy_load_addr4 : 11;
        unsigned int dy_load_addr5 : 11;
        unsigned int reserved : 10;
    } reg;
} SOC_REMAPCTRL_DY_LOAD_ADDR_B2_UNION;
#endif
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B2_dy_load_addr4_START (0)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B2_dy_load_addr4_END (10)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B2_dy_load_addr5_START (11)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B2_dy_load_addr5_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dy_load_addr6 : 11;
        unsigned int dy_load_addr7 : 11;
        unsigned int reserved : 10;
    } reg;
} SOC_REMAPCTRL_DY_LOAD_ADDR_B3_UNION;
#endif
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B3_dy_load_addr6_START (0)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B3_dy_load_addr6_END (10)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B3_dy_load_addr7_START (11)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B3_dy_load_addr7_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dy_load_addr8 : 11;
        unsigned int dy_load_addr9 : 11;
        unsigned int reserved : 10;
    } reg;
} SOC_REMAPCTRL_DY_LOAD_ADDR_B4_UNION;
#endif
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B4_dy_load_addr8_START (0)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B4_dy_load_addr8_END (10)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B4_dy_load_addr9_START (11)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B4_dy_load_addr9_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dy_load_addr10 : 11;
        unsigned int dy_load_addr11 : 11;
        unsigned int reserved : 10;
    } reg;
} SOC_REMAPCTRL_DY_LOAD_ADDR_B5_UNION;
#endif
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B5_dy_load_addr10_START (0)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B5_dy_load_addr10_END (10)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B5_dy_load_addr11_START (11)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B5_dy_load_addr11_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dy_load_addr12 : 11;
        unsigned int dy_load_addr13 : 11;
        unsigned int reserved : 10;
    } reg;
} SOC_REMAPCTRL_DY_LOAD_ADDR_B6_UNION;
#endif
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B6_dy_load_addr12_START (0)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B6_dy_load_addr12_END (10)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B6_dy_load_addr13_START (11)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B6_dy_load_addr13_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dy_load_addr14 : 11;
        unsigned int dy_load_addr15 : 11;
        unsigned int reserved : 10;
    } reg;
} SOC_REMAPCTRL_DY_LOAD_ADDR_B7_UNION;
#endif
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B7_dy_load_addr14_START (0)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B7_dy_load_addr14_END (10)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B7_dy_load_addr15_START (11)
#define SOC_REMAPCTRL_DY_LOAD_ADDR_B7_dy_load_addr15_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dy_load_en0 : 1;
        unsigned int dy_load_en1 : 1;
        unsigned int dy_load_en2 : 1;
        unsigned int dy_load_en3 : 1;
        unsigned int dy_load_en4 : 1;
        unsigned int dy_load_en5 : 1;
        unsigned int dy_load_en6 : 1;
        unsigned int dy_load_en7 : 1;
        unsigned int dy_load_en8 : 1;
        unsigned int dy_load_en9 : 1;
        unsigned int dy_load_en10 : 1;
        unsigned int dy_load_en11 : 1;
        unsigned int dy_load_en12 : 1;
        unsigned int dy_load_en13 : 1;
        unsigned int dy_load_en14 : 1;
        unsigned int dy_load_en15 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_REMAPCTRL_DY_LOAD_EN_UNION;
#endif
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en0_START (0)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en0_END (0)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en1_START (1)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en1_END (1)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en2_START (2)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en2_END (2)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en3_START (3)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en3_END (3)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en4_START (4)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en4_END (4)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en5_START (5)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en5_END (5)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en6_START (6)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en6_END (6)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en7_START (7)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en7_END (7)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en8_START (8)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en8_END (8)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en9_START (9)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en9_END (9)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en10_START (10)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en10_END (10)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en11_START (11)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en11_END (11)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en12_START (12)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en12_END (12)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en13_START (13)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en13_END (13)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en14_START (14)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en14_END (14)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en15_START (15)
#define SOC_REMAPCTRL_DY_LOAD_EN_dy_load_en15_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dy_load_clr0 : 1;
        unsigned int dy_load_clr1 : 1;
        unsigned int dy_load_clr2 : 1;
        unsigned int dy_load_clr3 : 1;
        unsigned int dy_load_clr4 : 1;
        unsigned int dy_load_clr5 : 1;
        unsigned int dy_load_clr6 : 1;
        unsigned int dy_load_clr7 : 1;
        unsigned int dy_load_clr8 : 1;
        unsigned int dy_load_clr9 : 1;
        unsigned int dy_load_clr10 : 1;
        unsigned int dy_load_clr11 : 1;
        unsigned int dy_load_clr12 : 1;
        unsigned int dy_load_clr13 : 1;
        unsigned int dy_load_clr14 : 1;
        unsigned int dy_load_clr15 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_REMAPCTRL_DY_LOAD_CLR_UNION;
#endif
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr0_START (0)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr0_END (0)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr1_START (1)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr1_END (1)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr2_START (2)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr2_END (2)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr3_START (3)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr3_END (3)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr4_START (4)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr4_END (4)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr5_START (5)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr5_END (5)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr6_START (6)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr6_END (6)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr7_START (7)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr7_END (7)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr8_START (8)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr8_END (8)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr9_START (9)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr9_END (9)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr10_START (10)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr10_END (10)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr11_START (11)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr11_END (11)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr12_START (12)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr12_END (12)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr13_START (13)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr13_END (13)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr14_START (14)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr14_END (14)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr15_START (15)
#define SOC_REMAPCTRL_DY_LOAD_CLR_dy_load_clr15_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt15 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT15_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT15_entry_cnt15_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT15_entry_cnt15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt14 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT14_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT14_entry_cnt14_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT14_entry_cnt14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt13 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT13_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT13_entry_cnt13_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT13_entry_cnt13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt12 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT12_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT12_entry_cnt12_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT12_entry_cnt12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt11 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT11_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT11_entry_cnt11_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT11_entry_cnt11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt10 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT10_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT10_entry_cnt10_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT10_entry_cnt10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt9 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT9_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT9_entry_cnt9_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT9_entry_cnt9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt8 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT8_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT8_entry_cnt8_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT8_entry_cnt8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt7 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT7_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT7_entry_cnt7_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT7_entry_cnt7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt6 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT6_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT6_entry_cnt6_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT6_entry_cnt6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt5 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT5_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT5_entry_cnt5_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT5_entry_cnt5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt4 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT4_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT4_entry_cnt4_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT4_entry_cnt4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt3 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT3_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT3_entry_cnt3_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT3_entry_cnt3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt2 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT2_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT2_entry_cnt2_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT2_entry_cnt2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt1 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT1_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT1_entry_cnt1_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT1_entry_cnt1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int entry_cnt0 : 32;
    } reg;
} SOC_REMAPCTRL_ENTRY_CNT0_UNION;
#endif
#define SOC_REMAPCTRL_ENTRY_CNT0_entry_cnt0_START (0)
#define SOC_REMAPCTRL_ENTRY_CNT0_entry_cnt0_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

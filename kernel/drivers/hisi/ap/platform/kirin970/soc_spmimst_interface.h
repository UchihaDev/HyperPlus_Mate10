#ifndef __SOC_SPMIMST_INTERFACE_H__
#define __SOC_SPMIMST_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_SPMIMST_CLK_CONFIG_ADDR(base) ((base) + (0x0000))
#define SOC_SPMIMST_INT_EN_ADDR(base) ((base) + (0x0004))
#define SOC_SPMIMST_AVS_PRI_ADDR(base) ((base) + (0x0010))
#define SOC_SPMIMST_AVS0_DBG_ADDR(base) ((base) + (0x0014))
#define SOC_SPMIMST_AVS1_DBG_ADDR(base) ((base) + (0x0018))
#define SOC_SPMIMST_AVS2_DBG_ADDR(base) ((base) + (0x001C))
#define SOC_SPMIMST_AVS3_DBG_ADDR(base) ((base) + (0x0020))
#define SOC_SPMIMST_AVS4_DBG_ADDR(base) ((base) + (0x0024))
#define SOC_SPMIMST_AVS5_DBG_ADDR(base) ((base) + (0x0028))
#define SOC_SPMIMST_AVS6_DBG_ADDR(base) ((base) + (0x002C))
#define SOC_SPMIMST_AVS7_DBG_ADDR(base) ((base) + (0x0030))
#define SOC_SPMIMST_AVS8_DBG_ADDR(base) ((base) + (0x0034))
#define SOC_SPMIMST_AVS9_DBG_ADDR(base) ((base) + (0x0038))
#define SOC_SPMIMST_AVS10_DBG_ADDR(base) ((base) + (0x003C))
#define SOC_SPMIMST_AVS11_DBG_ADDR(base) ((base) + (0x0040))
#define SOC_SPMIMST_AVS_STATUS_ADDR(base) ((base) + (0x0044))
#define SOC_SPMIMST_VIC_SPMI_CMD_ADDR(base) ((base) + (0x0050))
#define SOC_SPMIMST_VIC_WDATA0_ADDR(base) ((base) + (0x0054))
#define SOC_SPMIMST_VIC_WDATA1_ADDR(base) ((base) + (0x0058))
#define SOC_SPMIMST_VIC_WDATA2_ADDR(base) ((base) + (0x005C))
#define SOC_SPMIMST_VIC_WDATA3_ADDR(base) ((base) + (0x0060))
#define SOC_SPMIMST_VIC_STATUS_ADDR(base) ((base) + (0x0064))
#define SOC_SPMIMST_VIC_RDATA0_ADDR(base) ((base) + (0x0068))
#define SOC_SPMIMST_VIC_RDATA1_ADDR(base) ((base) + (0x006C))
#define SOC_SPMIMST_VIC_RDATA2_ADDR(base) ((base) + (0x0070))
#define SOC_SPMIMST_VIC_RDATA3_ADDR(base) ((base) + (0x0074))
#define SOC_SPMIMST_APB_SPMI_CMD_ADDR(base,cn) ((base) + (0x0100+0x300*(cn)))
#define SOC_SPMIMST_APB_SPMI_WDATA0_ADDR(base,cn) ((base) + (0x0104+0x300*(cn)))
#define SOC_SPMIMST_APB_SPMI_WDATA1_ADDR(base,cn) ((base) + (0x0108+0x300*(cn)))
#define SOC_SPMIMST_APB_SPMI_WDATA2_ADDR(base,cn) ((base) + (0x010C+0x300*(cn)))
#define SOC_SPMIMST_APB_SPMI_WDATA3_ADDR(base,cn) ((base) + (0x0110+0x300*(cn)))
#define SOC_SPMIMST_INT_STAT_ADDR(base,cn) ((base) + (0x0114+0x300*(cn)))
#define SOC_SPMIMST_INT_END_ADDR(base,cn) ((base) + (0x0118+0x300*(cn)))
#define SOC_SPMIMST_INT_TRANS_ERR_ADDR(base,cn) ((base) + (0x011C+0x300*(cn)))
#define SOC_SPMIMST_INT_CMD_ERR_ADDR(base,cn) ((base) + (0x0120+0x300*(cn)))
#define SOC_SPMIMST_INT_END_MASK_ADDR(base,cn) ((base) + (0x0124+0x300*(cn)))
#define SOC_SPMIMST_INT_TRANS_ERR_MASK_ADDR(base,cn) ((base) + (0x0128+0x300*(cn)))
#define SOC_SPMIMST_INT_CMD_ERR_MASK_ADDR(base,cn) ((base) + (0x012C+0x300*(cn)))
#define SOC_SPMIMST_INT_END_RAW_ADDR(base,cn) ((base) + (0x0130+0x300*(cn)))
#define SOC_SPMIMST_INT_TRANS_ERR_RAW_ADDR(base,cn) ((base) + (0x0134+0x300*(cn)))
#define SOC_SPMIMST_INT_CMD_ERR_RAW_ADDR(base,cn) ((base) + (0x0138+0x300*(cn)))
#define SOC_SPMIMST_INT_END_CLR_ADDR(base,cn) ((base) + (0x013C+0x300*(cn)))
#define SOC_SPMIMST_INT_TRANS_ERR_CLR_ADDR(base,cn) ((base) + (0x0140+0x300*(cn)))
#define SOC_SPMIMST_INT_CMD_ERR_CLR_ADDR(base,cn) ((base) + (0x0144+0x300*(cn)))
#define SOC_SPMIMST_APB_SPMI_STATUS_ADDR(base,cn,pn) ((base) + (0x0200+0x300*(cn)+0x20*(pn)))
#define SOC_SPMIMST_APB_SPMI_RDATA0_ADDR(base,cn,pn) ((base) + (0x0204+0x300*(cn)+0x20*(pn)))
#define SOC_SPMIMST_APB_SPMI_RDATA1_ADDR(base,cn,pn) ((base) + (0x0208+0x300*(cn)+0x20*(pn)))
#define SOC_SPMIMST_APB_SPMI_RDATA2_ADDR(base,cn,pn) ((base) + (0x020C+0x300*(cn)+0x20*(pn)))
#define SOC_SPMIMST_APB_SPMI_RDATA3_ADDR(base,cn,pn) ((base) + (0x0210+0x300*(cn)+0x20*(pn)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sclk_div : 6;
        unsigned int reserved_0 : 10;
        unsigned int sclk_gt_en : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_SPMIMST_CLK_CONFIG_UNION;
#endif
#define SOC_SPMIMST_CLK_CONFIG_sclk_div_START (0)
#define SOC_SPMIMST_CLK_CONFIG_sclk_div_END (5)
#define SOC_SPMIMST_CLK_CONFIG_sclk_gt_en_START (16)
#define SOC_SPMIMST_CLK_CONFIG_sclk_gt_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SPMIMST_INT_EN_UNION;
#endif
#define SOC_SPMIMST_INT_EN_int_en_START (0)
#define SOC_SPMIMST_INT_EN_int_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs0_pri : 2;
        unsigned int avs1_pri : 2;
        unsigned int avs2_pri : 2;
        unsigned int avs3_pri : 2;
        unsigned int avs4_pri : 2;
        unsigned int avs5_pri : 2;
        unsigned int avs6_pri : 2;
        unsigned int avs7_pri : 2;
        unsigned int avs8_pri : 2;
        unsigned int avs9_pri : 2;
        unsigned int avs10_pri : 2;
        unsigned int avs11_pri : 2;
        unsigned int reserved : 8;
    } reg;
} SOC_SPMIMST_AVS_PRI_UNION;
#endif
#define SOC_SPMIMST_AVS_PRI_avs0_pri_START (0)
#define SOC_SPMIMST_AVS_PRI_avs0_pri_END (1)
#define SOC_SPMIMST_AVS_PRI_avs1_pri_START (2)
#define SOC_SPMIMST_AVS_PRI_avs1_pri_END (3)
#define SOC_SPMIMST_AVS_PRI_avs2_pri_START (4)
#define SOC_SPMIMST_AVS_PRI_avs2_pri_END (5)
#define SOC_SPMIMST_AVS_PRI_avs3_pri_START (6)
#define SOC_SPMIMST_AVS_PRI_avs3_pri_END (7)
#define SOC_SPMIMST_AVS_PRI_avs4_pri_START (8)
#define SOC_SPMIMST_AVS_PRI_avs4_pri_END (9)
#define SOC_SPMIMST_AVS_PRI_avs5_pri_START (10)
#define SOC_SPMIMST_AVS_PRI_avs5_pri_END (11)
#define SOC_SPMIMST_AVS_PRI_avs6_pri_START (12)
#define SOC_SPMIMST_AVS_PRI_avs6_pri_END (13)
#define SOC_SPMIMST_AVS_PRI_avs7_pri_START (14)
#define SOC_SPMIMST_AVS_PRI_avs7_pri_END (15)
#define SOC_SPMIMST_AVS_PRI_avs8_pri_START (16)
#define SOC_SPMIMST_AVS_PRI_avs8_pri_END (17)
#define SOC_SPMIMST_AVS_PRI_avs9_pri_START (18)
#define SOC_SPMIMST_AVS_PRI_avs9_pri_END (19)
#define SOC_SPMIMST_AVS_PRI_avs10_pri_START (20)
#define SOC_SPMIMST_AVS_PRI_avs10_pri_END (21)
#define SOC_SPMIMST_AVS_PRI_avs11_pri_START (22)
#define SOC_SPMIMST_AVS_PRI_avs11_pri_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs0_transerr_addr : 16;
        unsigned int avs0_transerr_slvid : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_SPMIMST_AVS0_DBG_UNION;
#endif
#define SOC_SPMIMST_AVS0_DBG_avs0_transerr_addr_START (0)
#define SOC_SPMIMST_AVS0_DBG_avs0_transerr_addr_END (15)
#define SOC_SPMIMST_AVS0_DBG_avs0_transerr_slvid_START (16)
#define SOC_SPMIMST_AVS0_DBG_avs0_transerr_slvid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs1_transerr_addr : 16;
        unsigned int avs1_transerr_slvid : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_SPMIMST_AVS1_DBG_UNION;
#endif
#define SOC_SPMIMST_AVS1_DBG_avs1_transerr_addr_START (0)
#define SOC_SPMIMST_AVS1_DBG_avs1_transerr_addr_END (15)
#define SOC_SPMIMST_AVS1_DBG_avs1_transerr_slvid_START (16)
#define SOC_SPMIMST_AVS1_DBG_avs1_transerr_slvid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs2_transerr_addr : 16;
        unsigned int avs2_transerr_slvid : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_SPMIMST_AVS2_DBG_UNION;
#endif
#define SOC_SPMIMST_AVS2_DBG_avs2_transerr_addr_START (0)
#define SOC_SPMIMST_AVS2_DBG_avs2_transerr_addr_END (15)
#define SOC_SPMIMST_AVS2_DBG_avs2_transerr_slvid_START (16)
#define SOC_SPMIMST_AVS2_DBG_avs2_transerr_slvid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs3_transerr_addr : 16;
        unsigned int avs3_transerr_slvid : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_SPMIMST_AVS3_DBG_UNION;
#endif
#define SOC_SPMIMST_AVS3_DBG_avs3_transerr_addr_START (0)
#define SOC_SPMIMST_AVS3_DBG_avs3_transerr_addr_END (15)
#define SOC_SPMIMST_AVS3_DBG_avs3_transerr_slvid_START (16)
#define SOC_SPMIMST_AVS3_DBG_avs3_transerr_slvid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs4_transerr_addr : 16;
        unsigned int avs4_transerr_slvid : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_SPMIMST_AVS4_DBG_UNION;
#endif
#define SOC_SPMIMST_AVS4_DBG_avs4_transerr_addr_START (0)
#define SOC_SPMIMST_AVS4_DBG_avs4_transerr_addr_END (15)
#define SOC_SPMIMST_AVS4_DBG_avs4_transerr_slvid_START (16)
#define SOC_SPMIMST_AVS4_DBG_avs4_transerr_slvid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs5_transerr_addr : 16;
        unsigned int avs5_transerr_slvid : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_SPMIMST_AVS5_DBG_UNION;
#endif
#define SOC_SPMIMST_AVS5_DBG_avs5_transerr_addr_START (0)
#define SOC_SPMIMST_AVS5_DBG_avs5_transerr_addr_END (15)
#define SOC_SPMIMST_AVS5_DBG_avs5_transerr_slvid_START (16)
#define SOC_SPMIMST_AVS5_DBG_avs5_transerr_slvid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs6_transerr_addr : 16;
        unsigned int avs6_transerr_slvid : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_SPMIMST_AVS6_DBG_UNION;
#endif
#define SOC_SPMIMST_AVS6_DBG_avs6_transerr_addr_START (0)
#define SOC_SPMIMST_AVS6_DBG_avs6_transerr_addr_END (15)
#define SOC_SPMIMST_AVS6_DBG_avs6_transerr_slvid_START (16)
#define SOC_SPMIMST_AVS6_DBG_avs6_transerr_slvid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs7_transerr_addr : 16;
        unsigned int avs7_transerr_slvid : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_SPMIMST_AVS7_DBG_UNION;
#endif
#define SOC_SPMIMST_AVS7_DBG_avs7_transerr_addr_START (0)
#define SOC_SPMIMST_AVS7_DBG_avs7_transerr_addr_END (15)
#define SOC_SPMIMST_AVS7_DBG_avs7_transerr_slvid_START (16)
#define SOC_SPMIMST_AVS7_DBG_avs7_transerr_slvid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs8_transerr_addr : 16;
        unsigned int avs8_transerr_slvid : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_SPMIMST_AVS8_DBG_UNION;
#endif
#define SOC_SPMIMST_AVS8_DBG_avs8_transerr_addr_START (0)
#define SOC_SPMIMST_AVS8_DBG_avs8_transerr_addr_END (15)
#define SOC_SPMIMST_AVS8_DBG_avs8_transerr_slvid_START (16)
#define SOC_SPMIMST_AVS8_DBG_avs8_transerr_slvid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs9_transerr_addr : 16;
        unsigned int avs9_transerr_slvid : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_SPMIMST_AVS9_DBG_UNION;
#endif
#define SOC_SPMIMST_AVS9_DBG_avs9_transerr_addr_START (0)
#define SOC_SPMIMST_AVS9_DBG_avs9_transerr_addr_END (15)
#define SOC_SPMIMST_AVS9_DBG_avs9_transerr_slvid_START (16)
#define SOC_SPMIMST_AVS9_DBG_avs9_transerr_slvid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs10_transerr_addr : 16;
        unsigned int avs10_transerr_slvid : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_SPMIMST_AVS10_DBG_UNION;
#endif
#define SOC_SPMIMST_AVS10_DBG_avs10_transerr_addr_START (0)
#define SOC_SPMIMST_AVS10_DBG_avs10_transerr_addr_END (15)
#define SOC_SPMIMST_AVS10_DBG_avs10_transerr_slvid_START (16)
#define SOC_SPMIMST_AVS10_DBG_avs10_transerr_slvid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs11_transerr_addr : 16;
        unsigned int avs11_transerr_slvid : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_SPMIMST_AVS11_DBG_UNION;
#endif
#define SOC_SPMIMST_AVS11_DBG_avs11_transerr_addr_START (0)
#define SOC_SPMIMST_AVS11_DBG_avs11_transerr_addr_END (15)
#define SOC_SPMIMST_AVS11_DBG_avs11_transerr_slvid_START (16)
#define SOC_SPMIMST_AVS11_DBG_avs11_transerr_slvid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avs_trans_done : 12;
        unsigned int avs_trans_fail : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_SPMIMST_AVS_STATUS_UNION;
#endif
#define SOC_SPMIMST_AVS_STATUS_avs_trans_done_START (0)
#define SOC_SPMIMST_AVS_STATUS_avs_trans_done_END (11)
#define SOC_SPMIMST_AVS_STATUS_avs_trans_fail_START (12)
#define SOC_SPMIMST_AVS_STATUS_avs_trans_fail_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int slave_addr : 16;
        unsigned int slvid : 4;
        unsigned int byte_cnt : 4;
        unsigned int cmd_type : 4;
        unsigned int reserved : 3;
        unsigned int cmd_en : 1;
    } reg;
} SOC_SPMIMST_VIC_SPMI_CMD_UNION;
#endif
#define SOC_SPMIMST_VIC_SPMI_CMD_slave_addr_START (0)
#define SOC_SPMIMST_VIC_SPMI_CMD_slave_addr_END (15)
#define SOC_SPMIMST_VIC_SPMI_CMD_slvid_START (16)
#define SOC_SPMIMST_VIC_SPMI_CMD_slvid_END (19)
#define SOC_SPMIMST_VIC_SPMI_CMD_byte_cnt_START (20)
#define SOC_SPMIMST_VIC_SPMI_CMD_byte_cnt_END (23)
#define SOC_SPMIMST_VIC_SPMI_CMD_cmd_type_START (24)
#define SOC_SPMIMST_VIC_SPMI_CMD_cmd_type_END (27)
#define SOC_SPMIMST_VIC_SPMI_CMD_cmd_en_START (31)
#define SOC_SPMIMST_VIC_SPMI_CMD_cmd_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_wdata0 : 32;
    } reg;
} SOC_SPMIMST_VIC_WDATA0_UNION;
#endif
#define SOC_SPMIMST_VIC_WDATA0_apb_spmi_wdata0_START (0)
#define SOC_SPMIMST_VIC_WDATA0_apb_spmi_wdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_wdata1 : 32;
    } reg;
} SOC_SPMIMST_VIC_WDATA1_UNION;
#endif
#define SOC_SPMIMST_VIC_WDATA1_apb_spmi_wdata1_START (0)
#define SOC_SPMIMST_VIC_WDATA1_apb_spmi_wdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_wdata2 : 32;
    } reg;
} SOC_SPMIMST_VIC_WDATA2_UNION;
#endif
#define SOC_SPMIMST_VIC_WDATA2_apb_spmi_wdata2_START (0)
#define SOC_SPMIMST_VIC_WDATA2_apb_spmi_wdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_wdata3 : 32;
    } reg;
} SOC_SPMIMST_VIC_WDATA3_UNION;
#endif
#define SOC_SPMIMST_VIC_WDATA3_apb_spmi_wdata3_START (0)
#define SOC_SPMIMST_VIC_WDATA3_apb_spmi_wdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_trans_done : 1;
        unsigned int apb_trans_busy : 1;
        unsigned int apb_trans_fail : 1;
        unsigned int reserved : 1;
        unsigned int err_sid : 4;
        unsigned int err_slave_addr : 16;
        unsigned int err_byte_cnt : 4;
        unsigned int err_cmd_type : 4;
    } reg;
} SOC_SPMIMST_VIC_STATUS_UNION;
#endif
#define SOC_SPMIMST_VIC_STATUS_apb_trans_done_START (0)
#define SOC_SPMIMST_VIC_STATUS_apb_trans_done_END (0)
#define SOC_SPMIMST_VIC_STATUS_apb_trans_busy_START (1)
#define SOC_SPMIMST_VIC_STATUS_apb_trans_busy_END (1)
#define SOC_SPMIMST_VIC_STATUS_apb_trans_fail_START (2)
#define SOC_SPMIMST_VIC_STATUS_apb_trans_fail_END (2)
#define SOC_SPMIMST_VIC_STATUS_err_sid_START (4)
#define SOC_SPMIMST_VIC_STATUS_err_sid_END (7)
#define SOC_SPMIMST_VIC_STATUS_err_slave_addr_START (8)
#define SOC_SPMIMST_VIC_STATUS_err_slave_addr_END (23)
#define SOC_SPMIMST_VIC_STATUS_err_byte_cnt_START (24)
#define SOC_SPMIMST_VIC_STATUS_err_byte_cnt_END (27)
#define SOC_SPMIMST_VIC_STATUS_err_cmd_type_START (28)
#define SOC_SPMIMST_VIC_STATUS_err_cmd_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_rdata0 : 32;
    } reg;
} SOC_SPMIMST_VIC_RDATA0_UNION;
#endif
#define SOC_SPMIMST_VIC_RDATA0_apb_spmi_rdata0_START (0)
#define SOC_SPMIMST_VIC_RDATA0_apb_spmi_rdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_rdata1 : 32;
    } reg;
} SOC_SPMIMST_VIC_RDATA1_UNION;
#endif
#define SOC_SPMIMST_VIC_RDATA1_apb_spmi_rdata1_START (0)
#define SOC_SPMIMST_VIC_RDATA1_apb_spmi_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_rdata2 : 32;
    } reg;
} SOC_SPMIMST_VIC_RDATA2_UNION;
#endif
#define SOC_SPMIMST_VIC_RDATA2_apb_spmi_rdata2_START (0)
#define SOC_SPMIMST_VIC_RDATA2_apb_spmi_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_rdata3 : 32;
    } reg;
} SOC_SPMIMST_VIC_RDATA3_UNION;
#endif
#define SOC_SPMIMST_VIC_RDATA3_apb_spmi_rdata3_START (0)
#define SOC_SPMIMST_VIC_RDATA3_apb_spmi_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int slave_addr : 16;
        unsigned int slvid : 4;
        unsigned int byte_cnt : 4;
        unsigned int cmd_type : 4;
        unsigned int reserved : 3;
        unsigned int apb_spmi_cmd_en : 1;
    } reg;
} SOC_SPMIMST_APB_SPMI_CMD_UNION;
#endif
#define SOC_SPMIMST_APB_SPMI_CMD_slave_addr_START (0)
#define SOC_SPMIMST_APB_SPMI_CMD_slave_addr_END (15)
#define SOC_SPMIMST_APB_SPMI_CMD_slvid_START (16)
#define SOC_SPMIMST_APB_SPMI_CMD_slvid_END (19)
#define SOC_SPMIMST_APB_SPMI_CMD_byte_cnt_START (20)
#define SOC_SPMIMST_APB_SPMI_CMD_byte_cnt_END (23)
#define SOC_SPMIMST_APB_SPMI_CMD_cmd_type_START (24)
#define SOC_SPMIMST_APB_SPMI_CMD_cmd_type_END (27)
#define SOC_SPMIMST_APB_SPMI_CMD_apb_spmi_cmd_en_START (31)
#define SOC_SPMIMST_APB_SPMI_CMD_apb_spmi_cmd_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_wdata0 : 32;
    } reg;
} SOC_SPMIMST_APB_SPMI_WDATA0_UNION;
#endif
#define SOC_SPMIMST_APB_SPMI_WDATA0_apb_spmi_wdata0_START (0)
#define SOC_SPMIMST_APB_SPMI_WDATA0_apb_spmi_wdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_wdata1 : 32;
    } reg;
} SOC_SPMIMST_APB_SPMI_WDATA1_UNION;
#endif
#define SOC_SPMIMST_APB_SPMI_WDATA1_apb_spmi_wdata1_START (0)
#define SOC_SPMIMST_APB_SPMI_WDATA1_apb_spmi_wdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_wdata2 : 32;
    } reg;
} SOC_SPMIMST_APB_SPMI_WDATA2_UNION;
#endif
#define SOC_SPMIMST_APB_SPMI_WDATA2_apb_spmi_wdata2_START (0)
#define SOC_SPMIMST_APB_SPMI_WDATA2_apb_spmi_wdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_wdata3 : 32;
    } reg;
} SOC_SPMIMST_APB_SPMI_WDATA3_UNION;
#endif
#define SOC_SPMIMST_APB_SPMI_WDATA3_apb_spmi_wdata3_START (0)
#define SOC_SPMIMST_APB_SPMI_WDATA3_apb_spmi_wdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_stat : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_SPMIMST_INT_STAT_UNION;
#endif
#define SOC_SPMIMST_INT_STAT_int_stat_START (0)
#define SOC_SPMIMST_INT_STAT_int_stat_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_end : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_SPMIMST_INT_END_UNION;
#endif
#define SOC_SPMIMST_INT_END_int_end_START (0)
#define SOC_SPMIMST_INT_END_int_end_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_trans_err : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_SPMIMST_INT_TRANS_ERR_UNION;
#endif
#define SOC_SPMIMST_INT_TRANS_ERR_int_trans_err_START (0)
#define SOC_SPMIMST_INT_TRANS_ERR_int_trans_err_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_cmd_err : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SPMIMST_INT_CMD_ERR_UNION;
#endif
#define SOC_SPMIMST_INT_CMD_ERR_int_cmd_err_START (0)
#define SOC_SPMIMST_INT_CMD_ERR_int_cmd_err_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_end_mask : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_SPMIMST_INT_END_MASK_UNION;
#endif
#define SOC_SPMIMST_INT_END_MASK_int_end_mask_START (0)
#define SOC_SPMIMST_INT_END_MASK_int_end_mask_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_trans_err_mask : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_SPMIMST_INT_TRANS_ERR_MASK_UNION;
#endif
#define SOC_SPMIMST_INT_TRANS_ERR_MASK_int_trans_err_mask_START (0)
#define SOC_SPMIMST_INT_TRANS_ERR_MASK_int_trans_err_mask_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_cmd_err_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SPMIMST_INT_CMD_ERR_MASK_UNION;
#endif
#define SOC_SPMIMST_INT_CMD_ERR_MASK_int_cmd_err_mask_START (0)
#define SOC_SPMIMST_INT_CMD_ERR_MASK_int_cmd_err_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_end_raw : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_SPMIMST_INT_END_RAW_UNION;
#endif
#define SOC_SPMIMST_INT_END_RAW_int_end_raw_START (0)
#define SOC_SPMIMST_INT_END_RAW_int_end_raw_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_trans_err_raw : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_SPMIMST_INT_TRANS_ERR_RAW_UNION;
#endif
#define SOC_SPMIMST_INT_TRANS_ERR_RAW_int_trans_err_raw_START (0)
#define SOC_SPMIMST_INT_TRANS_ERR_RAW_int_trans_err_raw_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_cmd_err_raw : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SPMIMST_INT_CMD_ERR_RAW_UNION;
#endif
#define SOC_SPMIMST_INT_CMD_ERR_RAW_int_cmd_err_raw_START (0)
#define SOC_SPMIMST_INT_CMD_ERR_RAW_int_cmd_err_raw_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_end_clr : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_SPMIMST_INT_END_CLR_UNION;
#endif
#define SOC_SPMIMST_INT_END_CLR_int_end_clr_START (0)
#define SOC_SPMIMST_INT_END_CLR_int_end_clr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_trans_err_clr : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_SPMIMST_INT_TRANS_ERR_CLR_UNION;
#endif
#define SOC_SPMIMST_INT_TRANS_ERR_CLR_int_trans_err_clr_START (0)
#define SOC_SPMIMST_INT_TRANS_ERR_CLR_int_trans_err_clr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_cmd_err_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SPMIMST_INT_CMD_ERR_CLR_UNION;
#endif
#define SOC_SPMIMST_INT_CMD_ERR_CLR_int_cmd_err_clr_START (0)
#define SOC_SPMIMST_INT_CMD_ERR_CLR_int_cmd_err_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_trans_done : 1;
        unsigned int apb_trans_busy : 1;
        unsigned int apb_trans_fail : 1;
        unsigned int apb_trans_denied : 1;
        unsigned int reserved : 4;
        unsigned int err_slave_addr : 16;
        unsigned int err_byte_cnt : 4;
        unsigned int err_cmd_type : 4;
    } reg;
} SOC_SPMIMST_APB_SPMI_STATUS_UNION;
#endif
#define SOC_SPMIMST_APB_SPMI_STATUS_apb_trans_done_START (0)
#define SOC_SPMIMST_APB_SPMI_STATUS_apb_trans_done_END (0)
#define SOC_SPMIMST_APB_SPMI_STATUS_apb_trans_busy_START (1)
#define SOC_SPMIMST_APB_SPMI_STATUS_apb_trans_busy_END (1)
#define SOC_SPMIMST_APB_SPMI_STATUS_apb_trans_fail_START (2)
#define SOC_SPMIMST_APB_SPMI_STATUS_apb_trans_fail_END (2)
#define SOC_SPMIMST_APB_SPMI_STATUS_apb_trans_denied_START (3)
#define SOC_SPMIMST_APB_SPMI_STATUS_apb_trans_denied_END (3)
#define SOC_SPMIMST_APB_SPMI_STATUS_err_slave_addr_START (8)
#define SOC_SPMIMST_APB_SPMI_STATUS_err_slave_addr_END (23)
#define SOC_SPMIMST_APB_SPMI_STATUS_err_byte_cnt_START (24)
#define SOC_SPMIMST_APB_SPMI_STATUS_err_byte_cnt_END (27)
#define SOC_SPMIMST_APB_SPMI_STATUS_err_cmd_type_START (28)
#define SOC_SPMIMST_APB_SPMI_STATUS_err_cmd_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_rdata0 : 32;
    } reg;
} SOC_SPMIMST_APB_SPMI_RDATA0_UNION;
#endif
#define SOC_SPMIMST_APB_SPMI_RDATA0_apb_spmi_rdata0_START (0)
#define SOC_SPMIMST_APB_SPMI_RDATA0_apb_spmi_rdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_rdata1 : 32;
    } reg;
} SOC_SPMIMST_APB_SPMI_RDATA1_UNION;
#endif
#define SOC_SPMIMST_APB_SPMI_RDATA1_apb_spmi_rdata1_START (0)
#define SOC_SPMIMST_APB_SPMI_RDATA1_apb_spmi_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_rdata2 : 32;
    } reg;
} SOC_SPMIMST_APB_SPMI_RDATA2_UNION;
#endif
#define SOC_SPMIMST_APB_SPMI_RDATA2_apb_spmi_rdata2_START (0)
#define SOC_SPMIMST_APB_SPMI_RDATA2_apb_spmi_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_spmi_rdata3 : 32;
    } reg;
} SOC_SPMIMST_APB_SPMI_RDATA3_UNION;
#endif
#define SOC_SPMIMST_APB_SPMI_RDATA3_apb_spmi_rdata3_START (0)
#define SOC_SPMIMST_APB_SPMI_RDATA3_apb_spmi_rdata3_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

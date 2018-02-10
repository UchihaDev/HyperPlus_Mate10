#ifndef __SOC_PIMON_INTERFACE_H__
#define __SOC_PIMON_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_PIMON_GLB_STAT_ADDR(base) ((base) + (0x040))
#define SOC_PIMON_INT_STAT_ADDR(base) ((base) + (0x080))
#define SOC_PIMON_INT_MASK_ADDR(base) ((base) + (0x084))
#define SOC_PIMON_INT_CLR_ADDR(base) ((base) + (0x088))
#define SOC_PIMON_CTRL_ADDR(base) ((base) + (0x100))
#define SOC_PIMON_STAT_ADDR(base) ((base) + (0x104))
#define SOC_PIMON_ANA_CFG_ADDR(base) ((base) + (0x108))
#define SOC_PIMON_ANA_SET_ADDR(base) ((base) + (0x10C))
#define SOC_PIMON_ANA_CTRL_ADDR(base) ((base) + (0x110))
#define SOC_PIMON_TIMER_ADDR(base) ((base) + (0x114))
#define SOC_PIMON_MEM_CTRL_ADDR(base) ((base) + (0x118))
#define SOC_PIMON_SMPL_TIMING_ADDR(base) ((base) + (0x11C))
#define SOC_PIMON_RSVD_CTRL_ADDR(base) ((base) + (0x120))
#define SOC_PIMON_RSVD_STAT_ADDR(base) ((base) + (0x124))
#define SOC_PIMON_LAST_WADDR_LO_ADDR(base) ((base) + (0x134))
#define SOC_PIMON_BLK0_DEST_ADDR_ADDR(base) ((base) + (0x140))
#define SOC_PIMON_BLK0_SIZE_ADDR(base) ((base) + (0x144))
#define SOC_PIMON_BLK1_DEST_ADDR_ADDR(base) ((base) + (0x148))
#define SOC_PIMON_BLK1_SIZE_ADDR(base) ((base) + (0x14C))
#define SOC_PIMON_BLK2_DEST_ADDR_ADDR(base) ((base) + (0x150))
#define SOC_PIMON_BLK2_SIZE_ADDR(base) ((base) + (0x154))
#define SOC_PIMON_BLK3_DEST_ADDR_ADDR(base) ((base) + (0x158))
#define SOC_PIMON_BLK3_SIZE_ADDR(base) ((base) + (0x15C))
#define SOC_PIMON_TH_REG_ADDR(base) ((base) + (0x160))
#define SOC_PIMON_TRIG_CNT_REG_ADDR(base) ((base) + (0x164))
#define SOC_PIMON_MAX_STAT_REG_ADDR(base) ((base) + (0x168))
#define SOC_PIMON_TRIG_STAT_REG_ADDR(base) ((base) + (0x16C))
#define SOC_PIMON_SVFD_MON_CFG_ADDR(base) ((base) + (0x170))
#define SOC_PIMON_FIFO_STAT_ADDR(base) ((base) + (0x174))
#define SOC_PIMON_SOCP_HEAD1_ADDR(base) ((base) + (0x178))
#define SOC_PIMON_SOCP_HEAD2_ADDR(base) ((base) + (0x17C))
#define SOC_PIMON_CTRL_2_ADDR(base) ((base) + (0x204))
#define SOC_PIMON_FRAG_SW_REQ_ADDR(base) ((base) + (0x208))
#define SOC_PIMON_FRAG_ADDR_ADDR(base) ((base) + (0x20c))
#define SOC_PIMON_RST_TH_REG_ADDR(base) ((base) + (0x224))
#define SOC_PIMON_RST_CNT_REG_ADDR(base) ((base) + (0x228))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_busy_stat : 1;
        unsigned int bresp_stat : 2;
        unsigned int blks_fsm_stat : 3;
        unsigned int reserved : 26;
    } reg;
} SOC_PIMON_GLB_STAT_UNION;
#endif
#define SOC_PIMON_GLB_STAT_axi_busy_stat_START (0)
#define SOC_PIMON_GLB_STAT_axi_busy_stat_END (0)
#define SOC_PIMON_GLB_STAT_bresp_stat_START (1)
#define SOC_PIMON_GLB_STAT_bresp_stat_END (2)
#define SOC_PIMON_GLB_STAT_blks_fsm_stat_START (3)
#define SOC_PIMON_GLB_STAT_blks_fsm_stat_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fifo_full_int : 1;
        unsigned int blks_err_int : 1;
        unsigned int blks_full_int : 4;
        unsigned int axi_wrerr_int : 1;
        unsigned int ov_int : 1;
        unsigned int uv_int : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_PIMON_INT_STAT_UNION;
#endif
#define SOC_PIMON_INT_STAT_fifo_full_int_START (0)
#define SOC_PIMON_INT_STAT_fifo_full_int_END (0)
#define SOC_PIMON_INT_STAT_blks_err_int_START (1)
#define SOC_PIMON_INT_STAT_blks_err_int_END (1)
#define SOC_PIMON_INT_STAT_blks_full_int_START (2)
#define SOC_PIMON_INT_STAT_blks_full_int_END (5)
#define SOC_PIMON_INT_STAT_axi_wrerr_int_START (6)
#define SOC_PIMON_INT_STAT_axi_wrerr_int_END (6)
#define SOC_PIMON_INT_STAT_ov_int_START (7)
#define SOC_PIMON_INT_STAT_ov_int_END (7)
#define SOC_PIMON_INT_STAT_uv_int_START (8)
#define SOC_PIMON_INT_STAT_uv_int_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fifo_full_mask : 1;
        unsigned int blks_err_mask : 1;
        unsigned int blks_full_mask : 4;
        unsigned int axi_wrerr_mask : 1;
        unsigned int ov_mask : 1;
        unsigned int uv_mask : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_PIMON_INT_MASK_UNION;
#endif
#define SOC_PIMON_INT_MASK_fifo_full_mask_START (0)
#define SOC_PIMON_INT_MASK_fifo_full_mask_END (0)
#define SOC_PIMON_INT_MASK_blks_err_mask_START (1)
#define SOC_PIMON_INT_MASK_blks_err_mask_END (1)
#define SOC_PIMON_INT_MASK_blks_full_mask_START (2)
#define SOC_PIMON_INT_MASK_blks_full_mask_END (5)
#define SOC_PIMON_INT_MASK_axi_wrerr_mask_START (6)
#define SOC_PIMON_INT_MASK_axi_wrerr_mask_END (6)
#define SOC_PIMON_INT_MASK_ov_mask_START (7)
#define SOC_PIMON_INT_MASK_ov_mask_END (7)
#define SOC_PIMON_INT_MASK_uv_mask_START (8)
#define SOC_PIMON_INT_MASK_uv_mask_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fifo_full_clr : 1;
        unsigned int blks_err_clr : 1;
        unsigned int blks_full_clr : 4;
        unsigned int axi_wrerr_clr : 1;
        unsigned int ov_clr : 1;
        unsigned int uv_clr : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_PIMON_INT_CLR_UNION;
#endif
#define SOC_PIMON_INT_CLR_fifo_full_clr_START (0)
#define SOC_PIMON_INT_CLR_fifo_full_clr_END (0)
#define SOC_PIMON_INT_CLR_blks_err_clr_START (1)
#define SOC_PIMON_INT_CLR_blks_err_clr_END (1)
#define SOC_PIMON_INT_CLR_blks_full_clr_START (2)
#define SOC_PIMON_INT_CLR_blks_full_clr_END (5)
#define SOC_PIMON_INT_CLR_axi_wrerr_clr_START (6)
#define SOC_PIMON_INT_CLR_axi_wrerr_clr_END (6)
#define SOC_PIMON_INT_CLR_ov_clr_START (7)
#define SOC_PIMON_INT_CLR_ov_clr_END (7)
#define SOC_PIMON_INT_CLR_uv_clr_START (8)
#define SOC_PIMON_INT_CLR_uv_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pimon_en : 1;
        unsigned int fifo_en : 1;
        unsigned int fifo_flush : 1;
        unsigned int blks_wrap_en : 1;
        unsigned int blks_en : 4;
        unsigned int burst_length : 2;
        unsigned int hw_crg_byp : 1;
        unsigned int trigger_en : 1;
        unsigned int max_dat_clr : 1;
        unsigned int socp_dump_en : 1;
        unsigned int svfd_mon_en : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_PIMON_CTRL_UNION;
#endif
#define SOC_PIMON_CTRL_pimon_en_START (0)
#define SOC_PIMON_CTRL_pimon_en_END (0)
#define SOC_PIMON_CTRL_fifo_en_START (1)
#define SOC_PIMON_CTRL_fifo_en_END (1)
#define SOC_PIMON_CTRL_fifo_flush_START (2)
#define SOC_PIMON_CTRL_fifo_flush_END (2)
#define SOC_PIMON_CTRL_blks_wrap_en_START (3)
#define SOC_PIMON_CTRL_blks_wrap_en_END (3)
#define SOC_PIMON_CTRL_blks_en_START (4)
#define SOC_PIMON_CTRL_blks_en_END (7)
#define SOC_PIMON_CTRL_burst_length_START (8)
#define SOC_PIMON_CTRL_burst_length_END (9)
#define SOC_PIMON_CTRL_hw_crg_byp_START (10)
#define SOC_PIMON_CTRL_hw_crg_byp_END (10)
#define SOC_PIMON_CTRL_trigger_en_START (11)
#define SOC_PIMON_CTRL_trigger_en_END (11)
#define SOC_PIMON_CTRL_max_dat_clr_START (12)
#define SOC_PIMON_CTRL_max_dat_clr_END (12)
#define SOC_PIMON_CTRL_socp_dump_en_START (13)
#define SOC_PIMON_CTRL_socp_dump_en_END (13)
#define SOC_PIMON_CTRL_svfd_mon_en_START (14)
#define SOC_PIMON_CTRL_svfd_mon_en_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pimon_data_valid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PIMON_STAT_UNION;
#endif
#define SOC_PIMON_STAT_pimon_data_valid_START (0)
#define SOC_PIMON_STAT_pimon_data_valid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pimon_cfg : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_PIMON_ANA_CFG_UNION;
#endif
#define SOC_PIMON_ANA_CFG_pimon_cfg_START (0)
#define SOC_PIMON_ANA_CFG_pimon_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pimon_set : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_PIMON_ANA_SET_UNION;
#endif
#define SOC_PIMON_ANA_SET_pimon_set_START (0)
#define SOC_PIMON_ANA_SET_pimon_set_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pimon_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_PIMON_ANA_CTRL_UNION;
#endif
#define SOC_PIMON_ANA_CTRL_pimon_ctrl_START (0)
#define SOC_PIMON_ANA_CTRL_pimon_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int start_cnt_en : 1;
        unsigned int start_cnt : 31;
    } reg;
} SOC_PIMON_TIMER_UNION;
#endif
#define SOC_PIMON_TIMER_start_cnt_en_START (0)
#define SOC_PIMON_TIMER_start_cnt_en_END (0)
#define SOC_PIMON_TIMER_start_cnt_START (1)
#define SOC_PIMON_TIMER_start_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_PIMON_MEM_CTRL_UNION;
#endif
#define SOC_PIMON_MEM_CTRL_mem_ctrl_START (0)
#define SOC_PIMON_MEM_CTRL_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smpl_edge : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PIMON_SMPL_TIMING_UNION;
#endif
#define SOC_PIMON_SMPL_TIMING_smpl_edge_START (0)
#define SOC_PIMON_SMPL_TIMING_smpl_edge_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ana_rsvd_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_PIMON_RSVD_CTRL_UNION;
#endif
#define SOC_PIMON_RSVD_CTRL_ana_rsvd_ctrl_START (0)
#define SOC_PIMON_RSVD_CTRL_ana_rsvd_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ana_rsvd_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_PIMON_RSVD_STAT_UNION;
#endif
#define SOC_PIMON_RSVD_STAT_ana_rsvd_stat_START (0)
#define SOC_PIMON_RSVD_STAT_ana_rsvd_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int last_blk_waddr : 28;
        unsigned int selected_blk : 4;
    } reg;
} SOC_PIMON_LAST_WADDR_LO_UNION;
#endif
#define SOC_PIMON_LAST_WADDR_LO_last_blk_waddr_START (0)
#define SOC_PIMON_LAST_WADDR_LO_last_blk_waddr_END (27)
#define SOC_PIMON_LAST_WADDR_LO_selected_blk_START (28)
#define SOC_PIMON_LAST_WADDR_LO_selected_blk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk0_dest_addr : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_PIMON_BLK0_DEST_ADDR_UNION;
#endif
#define SOC_PIMON_BLK0_DEST_ADDR_blk0_dest_addr_START (0)
#define SOC_PIMON_BLK0_DEST_ADDR_blk0_dest_addr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk0_size : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_PIMON_BLK0_SIZE_UNION;
#endif
#define SOC_PIMON_BLK0_SIZE_blk0_size_START (0)
#define SOC_PIMON_BLK0_SIZE_blk0_size_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk1_dest_addr : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_PIMON_BLK1_DEST_ADDR_UNION;
#endif
#define SOC_PIMON_BLK1_DEST_ADDR_blk1_dest_addr_START (0)
#define SOC_PIMON_BLK1_DEST_ADDR_blk1_dest_addr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk1_size : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_PIMON_BLK1_SIZE_UNION;
#endif
#define SOC_PIMON_BLK1_SIZE_blk1_size_START (0)
#define SOC_PIMON_BLK1_SIZE_blk1_size_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk2_dest_addr : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_PIMON_BLK2_DEST_ADDR_UNION;
#endif
#define SOC_PIMON_BLK2_DEST_ADDR_blk2_dest_addr_START (0)
#define SOC_PIMON_BLK2_DEST_ADDR_blk2_dest_addr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk2_size : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_PIMON_BLK2_SIZE_UNION;
#endif
#define SOC_PIMON_BLK2_SIZE_blk2_size_START (0)
#define SOC_PIMON_BLK2_SIZE_blk2_size_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk3_dest_addr : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_PIMON_BLK3_DEST_ADDR_UNION;
#endif
#define SOC_PIMON_BLK3_DEST_ADDR_blk3_dest_addr_START (0)
#define SOC_PIMON_BLK3_DEST_ADDR_blk3_dest_addr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk3_size : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_PIMON_BLK3_SIZE_UNION;
#endif
#define SOC_PIMON_BLK3_SIZE_blk3_size_START (0)
#define SOC_PIMON_BLK3_SIZE_blk3_size_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_th : 5;
        unsigned int reserved_0: 11;
        unsigned int uv_th : 5;
        unsigned int reserved_1: 11;
    } reg;
} SOC_PIMON_TH_REG_UNION;
#endif
#define SOC_PIMON_TH_REG_ov_th_START (0)
#define SOC_PIMON_TH_REG_ov_th_END (4)
#define SOC_PIMON_TH_REG_uv_th_START (16)
#define SOC_PIMON_TH_REG_uv_th_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_cnt : 16;
        unsigned int uv_cnt : 16;
    } reg;
} SOC_PIMON_TRIG_CNT_REG_UNION;
#endif
#define SOC_PIMON_TRIG_CNT_REG_ov_cnt_START (0)
#define SOC_PIMON_TRIG_CNT_REG_ov_cnt_END (15)
#define SOC_PIMON_TRIG_CNT_REG_uv_cnt_START (16)
#define SOC_PIMON_TRIG_CNT_REG_uv_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_ov_dat : 5;
        unsigned int reserved_0 : 11;
        unsigned int min_uv_dat : 5;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_PIMON_MAX_STAT_REG_UNION;
#endif
#define SOC_PIMON_MAX_STAT_REG_max_ov_dat_START (0)
#define SOC_PIMON_MAX_STAT_REG_max_ov_dat_END (4)
#define SOC_PIMON_MAX_STAT_REG_min_uv_dat_START (16)
#define SOC_PIMON_MAX_STAT_REG_min_uv_dat_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_num_stat : 16;
        unsigned int uv_num_stat : 16;
    } reg;
} SOC_PIMON_TRIG_STAT_REG_UNION;
#endif
#define SOC_PIMON_TRIG_STAT_REG_ov_num_stat_START (0)
#define SOC_PIMON_TRIG_STAT_REG_ov_num_stat_END (15)
#define SOC_PIMON_TRIG_STAT_REG_uv_num_stat_START (16)
#define SOC_PIMON_TRIG_STAT_REG_uv_num_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svfd_fill_delay : 8;
        unsigned int svfd_frq_dn_pat : 10;
        unsigned int svfd_frq_up_pat : 10;
        unsigned int reserved : 4;
    } reg;
} SOC_PIMON_SVFD_MON_CFG_UNION;
#endif
#define SOC_PIMON_SVFD_MON_CFG_svfd_fill_delay_START (0)
#define SOC_PIMON_SVFD_MON_CFG_svfd_fill_delay_END (7)
#define SOC_PIMON_SVFD_MON_CFG_svfd_frq_dn_pat_START (8)
#define SOC_PIMON_SVFD_MON_CFG_svfd_frq_dn_pat_END (17)
#define SOC_PIMON_SVFD_MON_CFG_svfd_frq_up_pat_START (18)
#define SOC_PIMON_SVFD_MON_CFG_svfd_frq_up_pat_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fifo_full_lvl : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_PIMON_FIFO_STAT_UNION;
#endif
#define SOC_PIMON_FIFO_STAT_fifo_full_lvl_START (0)
#define SOC_PIMON_FIFO_STAT_fifo_full_lvl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socp_dump_h1 : 32;
    } reg;
} SOC_PIMON_SOCP_HEAD1_UNION;
#endif
#define SOC_PIMON_SOCP_HEAD1_socp_dump_h1_START (0)
#define SOC_PIMON_SOCP_HEAD1_socp_dump_h1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socp_dump_h2 : 32;
    } reg;
} SOC_PIMON_SOCP_HEAD2_UNION;
#endif
#define SOC_PIMON_SOCP_HEAD2_socp_dump_h2_START (0)
#define SOC_PIMON_SOCP_HEAD2_socp_dump_h2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode_sel : 1;
        unsigned int frag_buf_en : 1;
        unsigned int frag_uv_en : 1;
        unsigned int frag_ov_en : 1;
        unsigned int ram_clk_off : 1;
        unsigned int rst_mon_en : 1;
        unsigned int rst_uv_en : 1;
        unsigned int rst_ov_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_PIMON_CTRL_2_UNION;
#endif
#define SOC_PIMON_CTRL_2_mode_sel_START (0)
#define SOC_PIMON_CTRL_2_mode_sel_END (0)
#define SOC_PIMON_CTRL_2_frag_buf_en_START (1)
#define SOC_PIMON_CTRL_2_frag_buf_en_END (1)
#define SOC_PIMON_CTRL_2_frag_uv_en_START (2)
#define SOC_PIMON_CTRL_2_frag_uv_en_END (2)
#define SOC_PIMON_CTRL_2_frag_ov_en_START (3)
#define SOC_PIMON_CTRL_2_frag_ov_en_END (3)
#define SOC_PIMON_CTRL_2_ram_clk_off_START (4)
#define SOC_PIMON_CTRL_2_ram_clk_off_END (4)
#define SOC_PIMON_CTRL_2_rst_mon_en_START (5)
#define SOC_PIMON_CTRL_2_rst_mon_en_END (5)
#define SOC_PIMON_CTRL_2_rst_uv_en_START (6)
#define SOC_PIMON_CTRL_2_rst_uv_en_END (6)
#define SOC_PIMON_CTRL_2_rst_ov_en_START (7)
#define SOC_PIMON_CTRL_2_rst_ov_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int frag_sw_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PIMON_FRAG_SW_REQ_UNION;
#endif
#define SOC_PIMON_FRAG_SW_REQ_frag_sw_req_START (0)
#define SOC_PIMON_FRAG_SW_REQ_frag_sw_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int frag_ram_addr : 8;
        unsigned int frag_buf_done : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_PIMON_FRAG_ADDR_UNION;
#endif
#define SOC_PIMON_FRAG_ADDR_frag_ram_addr_START (0)
#define SOC_PIMON_FRAG_ADDR_frag_ram_addr_END (7)
#define SOC_PIMON_FRAG_ADDR_frag_buf_done_START (8)
#define SOC_PIMON_FRAG_ADDR_frag_buf_done_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_ov_th : 5;
        unsigned int reserved_0: 11;
        unsigned int rst_uv_th : 5;
        unsigned int reserved_1: 11;
    } reg;
} SOC_PIMON_RST_TH_REG_UNION;
#endif
#define SOC_PIMON_RST_TH_REG_rst_ov_th_START (0)
#define SOC_PIMON_RST_TH_REG_rst_ov_th_END (4)
#define SOC_PIMON_RST_TH_REG_rst_uv_th_START (16)
#define SOC_PIMON_RST_TH_REG_rst_uv_th_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_ov_cnt : 16;
        unsigned int rst_uv_cnt : 16;
    } reg;
} SOC_PIMON_RST_CNT_REG_UNION;
#endif
#define SOC_PIMON_RST_CNT_REG_rst_ov_cnt_START (0)
#define SOC_PIMON_RST_CNT_REG_rst_ov_cnt_END (15)
#define SOC_PIMON_RST_CNT_REG_rst_uv_cnt_START (16)
#define SOC_PIMON_RST_CNT_REG_rst_uv_cnt_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

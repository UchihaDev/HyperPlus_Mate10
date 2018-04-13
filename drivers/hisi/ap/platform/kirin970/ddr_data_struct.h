#ifndef __DDR_ASIC_3670_DATASTRUCT_H__
#define __DDR_ASIC_3670_DATASTRUCT_H__ 
#include <types.h>
#include <ddr_define.h>
typedef struct {
 int density;
 int size;
 int bank;
 int row;
 int col;
} ddr_density_rbc_str;
typedef struct {
 unsigned int rank_num;
 ddr_density_rbc_str rank_info[MAX_RANK_NUM_PER_DMC];
} ddr_rank_info_str;
typedef struct {
 u32 acaddrbdl0[CHANNEL_LPDDR4_MAX_NR];
 u32 acaddrbdl1[CHANNEL_LPDDR4_MAX_NR];
 u32 acaddrbdl2[CHANNEL_LPDDR4_MAX_NR];
 u32 addrphbound[CHANNEL_LPDDR4_MAX_NR];
 u32 dxnwdqnbdl0[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxnwdqnbdl1[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxnwdqnbdl2[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxnrdqnbdl0[CHANNEL_LPDDR4_MAX_NR][EDGETYPE_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxnrdqnbdl1[CHANNEL_LPDDR4_MAX_NR][EDGETYPE_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxnrdqnbdl2[CHANNEL_LPDDR4_MAX_NR][EDGETYPE_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxnoebdl[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxnrdqsdly[CHANNEL_LPDDR4_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxnrdqsdlysub[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxnwdqsdly[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxnwdqdly[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxnwlsl[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxngds[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 dxnrdqsgdly[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 hvreft_status[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR][BYTELANE_LPDDR4_MAX_NR];
 u32 advref_status[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR];
 u32 dvreft_status[CHANNEL_LPDDR4_MAX_NR][RANK_MAX_NR];
 u32 ck_dcc_status[CHANNEL_LPDDR4_MAX_NR];
 u32 wdqs_dcc_status[CHANNEL_LPDDR4_MAX_NR];
 u32 cs_bdl[CHANNEL_LPDDR4_MAX_NR];
 u32 posedge_cs[CHANNEL_LPDDR4_MAX_NR];
 u32 posedge_cs1[CHANNEL_LPDDR4_MAX_NR];
} ddr_train_param;
#define DMC_LOWPOWER_ASREF (1 << 0)
#define DMC_LOWPOWER_PD (1 << 1)
#define DMC_DFS (1 << 2)
#define DMC_AFS (1 << 3)
#define DMC_TMON_MONITOR (1 << 4)
#define DMC_TMON_RECORD (1 << 5)
#define DMC_TMON_REBOOT (1 << 6)
#define DDR_SREF_ABORT (1 << 7)
#define DMC_CFG_BL (1 << 8)
#define DMC_CFG_AREF_OPT (1 << 10)
#define PACK_PPFIFO (1 << 11)
#define PACK_PLL_UNLOCK (1 << 12)
#define PACK_ZCALRT (1 << 13)
#define DMSS_DYN_CKG (1 << 14)
#define UCE_INIT (1 << 15)
#define UCE_RETRAIN (1 << 16)
#define UCE_DFS (1 << 17)
#define DDR_AUTOFSGT_MODE (1 << 18)
#define PPFIFO_SYNC_MODE (1 << 19)
#define PACK_RX_PPFIFO (1 << 20)
#define WL_ENHANCEMENT_EN (1 << 21)
#define PER_BIT_TRACK_EN (1 << 22)
#define MARGIN_CAL_EN (1 << 23)
#define ASYNC_MODEM_EN (1 << 24)
#define DDR_12_PHASE_EN (1 << 25)
#define WDET_2ND_PAT_EN (1 << 26)
#define PACK_DYNAMIC_TRACK (1 << 27)
#define PHYIO_CLOSE (1 << 28)
#define RD_PEAMBLE (1 << 29)
#define WR_3TPREAMBLE (1 << 30)
#define CAT_EYET_RB_OPT (1 << 31)
#define RETRAIN_DISABLE (0)
#define RETRAIN_NORMAL (1)
#define RETRAIN_SOFTWARE (2)
#define RETRAIN_TRFC (3)
typedef struct {
 u32 dmc_lp_asref: 1;
 u32 dmc_lp_pd: 1;
 u32 ddr_dfs: 1;
 u32 ddr_afs: 1;
 u32 dmc_tmon_monitor: 1;
 u32 dmc_tmon_record: 1;
 u32 dmc_tmon_reboot: 1;
 u32 ddr_sref_abort: 1;
 u32 dmc_cfg_bl: 2;
 u32 dmc_cfg_aref_opt: 1;
 u32 pack_ppfifo: 1;
 u32 pack_pll_unlock: 1;
 u32 pack_zcalrt: 1;
 u32 dmss_dyn_ckg: 1;
 u32 uce_init: 1;
 u32 uce_retrain: 1;
 u32 uce_dfs: 1;
 u32 ddr_autofsgt_mode: 1;
 u32 ppfifo_sync_mode: 1;
 u32 pack_rx_ppfifo: 1;
 u32 wl_enhancement_en: 1;
 u32 per_bit_track_en: 1;
 u32 margin_cal_en: 1;
 u32 async_mode_en: 1;
 u32 ddr_12_phase_en: 1;
 u32 wdet_2nd_pat_en: 1;
 u32 dynamic_track_en: 1;
 u32 phyio_close: 1;
 u32 rd_preamble: 1;
 u32 wr_3tpreamble: 1;
 u32 cat_eyet_rb_opt: 1;
} ddr_feature;
typedef struct {
 u8 host_dq_vref;
 u8 dram_ca_vref;
 u8 dram_dq_vref;
}ddr_default_vref_str;
typedef struct {
 u16 core_base_vol;
 u8 vddq_base_vol;
 u8 vdd2_base_vol;
 u8 vdd1_base_vol;
 u8 pll_base_vol;
}ddr_vol_base_cfg_str;
typedef struct {
 u32 target_freq: 3;
 u32 min_freq: 3;
 u32 max_freq: 3;
 u32 init_mode: 1;
 u32 training_mode: 1;
 u32 read_mode: 1;
 u32 bl_data: 4;
 u32 phyif_tim_wden: 8;
 u32 phyif_tim_wdda: 8;
 u32 trdlat: 4;
 u32 phyif_tim_oven: 7;
 u16 asref_period;
 u16 pd_period;
 u8 tmon_period;
 u32 reserved: 24;
 ddr_vol_base_cfg_str vol_base_cfg;
} ddr_init_info;
typedef struct {
 u32 weak_pulldown_on: 1;
 u32 ca_odt_on: 1;
 u32 ck_odt_on: 2;
 u32 cs_odt_on: 1;
 u32 dq_odt_on: 2;
 u32 host_odt_on: 2;
 u32 pu_cal: 1;
 u32 pdds: 3;
 u32 dram_ca_odt: 3;
 u32 dram_dq_odt: 3;
 u32 soc_odt: 3;
 u32 ck_ron_n: 3;
 u32 ck_ron_p: 3;
 u32 cs_ron_n: 3;
 u32 cs_ron_p: 3;
 u32 cke_ron_p: 3;
 u32 cke_ron_n: 3;
 u32 ca_ron_n: 3;
 u32 ca_ron_p: 3;
 u32 ck_PRE_P: 2;
 u32 ck_PRE_N: 2;
 u32 ac1t_PRE_P: 2;
 u32 ac1t_PRE_N: 2;
 u32 ac2t_PRE_P: 2;
 u32 ac2t_PRE_N: 2;
 u32 rx_dq_odt_sel: 3;
 u32 rx_dqs_odt_sel: 3;
 u32 tx_dq_ron_n: 3;
 u32 tx_dq_ron_p: 3;
 u32 tx_dqs_ron_n: 3;
 u32 tx_dqs_ron_p: 3;
 u32 dq_pre_p: 2;
 u32 dq_pre_n: 2;
 u32 dqs_pre_p: 2;
 u32 dqs_pre_n: 2;
}ddr_io_driver_cfg_str;
typedef struct {
 u8 core_vol_bitmap;
#if 0
 s8 vddq_work_vol;
 s8 vdd2_work_vol;
 s8 vdd1_work_vol;
 s8 pll_work_vol;
#endif
}ddr_vol_cfg_str;
typedef struct {
 u32 cbt_en: 1;
 u32 sw_hw_eyet_en: 2;
 u32 sw_hw_vreft_en: 2;
 u32 sw_hw_cst_en: 2;
 u32 reserved0: 1;
 u32 cat_ph_fine_step: 3;
 u32 cat_open_ph_jstep: 5;
 u32 cat_open_bdl_jstep: 4;
 u32 cat_ph_step: 4;
 u32 cat_samp_num_ph: 6;
 u32 vreft_no_dec: 1;
 u32 vreft_dborg: 1;
 u32 cat_lb_backtap: 5;
 u32 cat_rb_backtap: 5;
 u32 dvreft_hckpts: 6;
 u32 cat_bdl_of_one_phase: 8;
 u32 cat_bdl_of_half_phase: 8;
 u32 cat_re_deskew_en: 1;
 u32 cat_rb2nd_fine_en: 1;
 u32 cat_samp_num_bdl: 6;
 u32 cat_ds_en: 1;
 u32 cat_ct_en: 1;
}cat_step_cfg_str;
typedef struct {
 u32 dram_vref_thres: 4;
 u32 host_vref_thres: 4;
 u32 host_dq_train_en: 2;
 u32 dram_dq_train_en: 2;
 u32 rdet_by_uce: 1;
 u32 wdet_by_uce: 1;
 u32 wdqs_dcc: 1;
 u32 wl_single_rank: 1;
 u32 host_dq_dcc_en: 1;
 u32 wl_ph_fine_step: 3;
 u32 gt_ph_step: 4;
 u32 gds_margin_sel: 3;
 u32 reserved2: 1;
 u32 gt_ph_fine_step: 3;
 u32 rbound_sfal_en: 1;
 u32 wl_ph_step: 4;
 u32 row_react_period: 8;
 u32 rdet_rb_backtap: 9;
 u32 rdet_ct_dqs_en: 1;
 u32 row_react_period_offset: 2;
 u32 rdet_open_jstep: 4;
 u32 rdet_lb_backtap: 4;
 u32 rdet_lb_ctdone_stop: 1;
 u32 evenodd_en: 1;
 u32 rdet_bdl_step: 2;
 u32 rdet_samp_num: 8;
 u32 rdet_trysamp_num: 8;
 u32 rdet_ph_step: 2;
 u32 rdet_fine_step: 2;
 u32 wdet_ph_step: 4;
 u32 wdet_open_ph_jstep: 5;
 u32 wdet_ph_fine_step: 3;
 u32 wdet_samp_num: 8;
 u32 wdet_trysamp_num: 8;
 u32 wdet_lb_backtap: 5;
 u32 wdet_bdl_step: 2;
 u32 wdet_lb_ctdone_stop: 1;
 u32 wdet_rb_backtap: 5;
 u32 cfg_upd_scandq_en: 1;
 u32 wdet_ct_dqs_en: 1;
 u32 wdet_ds_en: 1;
 u32 wdet_open_bdl_jstep: 4;
 u32 half_ph_bdl_en: 1;
 u32 wdet_rb2nd_fine_en: 1;
 u32 reserved5: 2;
 u32 wdet_bdl_of_one_phase: 8;
 u32 wdet_bdl_of_half_phase: 8;
 u32 wdet_one_phase_code: 6;
 u32 wl_en: 2;
 u32 wl_ph_delta: 6;
 u32 bdlcarry_done: 1;
 u32 reserved6: 1;
 u32 wl_falledge_ph_jstep_r: 5;
 u32 reserved7: 3;
 u32 wl_bdl_step: 4;
}dqt_cfg_str;
typedef struct {
 u32 one_phase_code: 6;
 u32 wdert_check_step: 4;
 u32 wdert_shift_step: 4;
 u32 wdert_bdl_check_step: 4;
 u32 wdert_bdl_shift_step: 6;
 u32 rdert_step: 4;
 u32 wdert_mpc_cnt: 4;
 u32 wdert_bdl_mode: 1;
} retrain_cfg_str;
typedef struct
{
 u32 pll_lt;
 u32 pll_sp;
 u32 pll_cpi;
}ddrc_pll_cfg_str;
typedef struct {
 u32 hdr: 1;
 u32 mission: 1;
 u32 dlymeas_type: 1;
 u32 rd_dbi: 1;
 u32 wr_dbi: 1;
 u32 fast_wdet_en:1;
 u32 fast_rdet_en:1;
 u32 fast_gt_en:1;
 u32 fast_gds_en:1;
 u32 fast_train_method:1;
 u32 rd_retrain: 2;
 u32 wr_retrain: 2;
 u32 dynamic_track: 2;
 u32 rd_preamble: 1;
 u32 dmc_cfg_phy_gt: 1;
 u32 dmc_cfg_pack_gt: 1;
 u32 dmc_cfg_dmc_gt: 1;
 u32 sys_clk_gt: 1;
 u32 dmc_cfg_aref_intlv: 1;
 u32 aref_intlv_en: 1;
 u32 dmc_global_clkon: 1;
 u32 dyn_dfi_wakeup: 1;
 u32 aggressive_mode: 1;
 u32 lmtr_en: 1;
 u32 reserved: 5;
 u32 lmtr_modem;
 u32 lmtr_vivo;
 u32 lmtr_vcodec;
 u32 lmtr_ivp;
} freq_info;
typedef struct{
        unsigned char div_ddrc:5;
        unsigned char div_ddrcfg:3;
        unsigned char reserved1:2;
        unsigned char div_ddrsys:2;
        unsigned char reserved2:4;
} ddr_clkdiv;
typedef struct {
 u16 freq;
 u16 misc;
 u32 pllctrl0;
 u32 pllctrl1;
 ddr_clkdiv clk_div;
 u16 pll_sel: 2;
 u16 reserved: 14;
 u32 timing[9];
 u32 dtimer[6];
 u32 ctimer[2];
 u32 modereg[2];
 freq_info freq_info;
 retrain_cfg_str retrain_cfg;
 ddr_io_driver_cfg_str ddr_io_driver_cfg;
 ddrc_pll_cfg_str ddrc_pll_cfg;
 ddr_vol_cfg_str ddr_vol_cfg;
 ddr_default_vref_str ddr_default_vref;
} ddr_profile;
typedef struct {
 cat_step_cfg_str cat_step_cfg;
 dqt_cfg_str dqt_cfg;
}ddr_init_training_cfg;
typedef struct {
 unsigned int offset_addr;
 unsigned int reg_val[AXI_MAX_PORT];
} dmss_port_cfg_str;
typedef struct {
 int offset_addr;
 int value;
} common_cfg_str;
enum {
 SEGNUM_DDR_INIT = 0,
 SEGNUM_DDR_DDR_PROFILE,
 SEGNUM_DDR_TRAINING_PARA,
 SEGNUM_DMSS_GLOBAL,
 SEGNUM_DMSS_AXI,
 SEGNUM_DMSS_SEC,
 SEGNUM_QOS_CFG,
 SEGNUM_DDR_FEATURE,
 SEGNUM_ADJUST_TACTIC,
 SEGNUM_UCE_CTRL,
 SEGNUM_DDR_MAX = 16,
};
typedef struct {
 u32 number_of_seg;
 u32 reserved;
 u32 offset_seg[SEGNUM_DDR_MAX][2];
} segment_info;
typedef struct {
 u32 magic_num;
 u32 reserved;
 u32 para_version;
 u32 valid_seg;
 segment_info segment_info;
} ddr_para_head_str;
typedef struct {
 u32 rank_num;
 u16 io_width[2];
 u32 density[2];
 u32 manufactery_id;
 u32 ddr_size;
}ddr_init_target_info_str;
typedef struct {
 u32 uce_id: 3;
 u32 wdt_en: 1;
 u32 reserved1: 1;
 u32 uart_dis: 1;
 u32 info_pack_en: 1;
 u32 ddr_train_track_dis: 1;
 u32 print_level: 4;
 u32 reserved: 20;
}uce_ctrl_str;
typedef struct {
 u32 cmd_load_prd;
 u32 cmd_load_max;
 u32 cmd_load_hold_max;
 u32 cmd_load_trigger_max;
 u32 dat_load_prd;
 u32 dat_load_max;
 u32 dat_load_hold_max;
 u32 dat_load_trigger_max;
 u32 flux_prd;
 u32 flux_min;
 u32 flux_trigger_max;
}ddr_tactic;
typedef struct {
 signed int left_bdl:16;
 signed int center_bdl:16;
 unsigned int best_margin:16;
 unsigned int vref: 8;
 unsigned int best_idx: 1;
 unsigned int valid: 1;
} BOUNDARY_BDL_RECORD_STR;
typedef struct {
 u8 hdr;
 u8 bit_map;
 u16 freq;
} restore_ddr_init_info ;
typedef struct {
 u32 crc_code;
 u32 vension;
 u32 error_id;
 u32 number_of_freq;
 restore_ddr_init_info init_info[FREQ_NUM_MAX];
} ddr_restore_para_head;
typedef struct {
 u32 bk_offset;
} ddr_restore_head;
typedef struct {
 u32 is_not_save: 4;
 u32 is_first_restore:4;
 u32 reserved:4;
 u32 error_id:20;
} ddr_restore_status;
#ifndef __FASTBOOT__
typedef struct {
 ddr_init_target_info_str *ddr_target_info;
 ddr_feature* feature;
 ddr_init_info* ddr_init_info;
 u32 number_of_ddr_profile;
 ddr_profile* ddr_profile;
 uce_ctrl_str* uce_ctrl_cfg;
 u32 number_of_ddr_init_training_cfg;
 ddr_init_training_cfg* init_training_cfg;
 ddr_train_param* ddr_train_param;
 u32 number_of_ddr_train;
 ddr_tactic* ddr_adjust_tactic;
 u32 number_of_ddr_ddr_train;
 u32 number_of_dmss_axi_cfg;
 u32 number_of_dmss_global_cfg;
 u32 number_of_qos_cfg;
 dmss_port_cfg_str* sec_bypass_cfg;
 dmss_port_cfg_str* dmss_axi_cfg;
 common_cfg_str* dmss_global_cfg;
 common_cfg_str* qos_cfg;
 u32* uce_firmware_addr;
 u32 uce_firmware_size;
 u8* trainig_result_idx_map_addr;
 u32 trainig_result_idx_map_size;
 ddr_restore_status restore_status;
} ddr_para_entry_str;
#else
typedef struct {
 unsigned int ddr_target_info;
 unsigned int feature;
 unsigned int ddr_init_info;
 u32 number_of_ddr_profile;
 unsigned int ddr_profile;
 unsigned int uce_ctrl_cfg;
 u32 number_of_ddr_init_training_cfg;
 unsigned int init_training_cfg;
 unsigned int ddr_train_param;
 u32 number_of_ddr_train;
 unsigned int ddr_adjust_tactic;
 u32 number_of_ddr_ddr_train;
 u32 number_of_dmss_axi_cfg;
 u32 number_of_dmss_global_cfg;
 u32 number_of_qos_cfg;
 unsigned int sec_bypass_cfg;
 unsigned int dmss_axi_cfg;
 unsigned int dmss_global_cfg;
 unsigned int qos_cfg;
 unsigned int uce_firmware_addr;
 unsigned int uce_firmware_size;
 unsigned int trainig_result_idx_map_addr;
 unsigned int trainig_result_idx_map_size;
 ddr_restore_status restore_status;
} ddr_para_entry_str;
#endif
#define DDR_SEG_MAGIC 0xA55A7F3C
#define DDR_PARA_VERSION 0x3670000A
#endif

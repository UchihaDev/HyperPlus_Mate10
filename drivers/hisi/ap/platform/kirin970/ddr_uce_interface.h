

#ifndef __KIRIN970_DDR_UCE_INTERFACE__H__
#define __KIRIN970_DDR_UCE_INTERFACE__H__ 
typedef struct {
 unsigned int rdet_en: 1;
 unsigned int wdet_en: 1;
 unsigned int ct_dqs_en: 1;
 unsigned int av_en: 1;
 unsigned int cat_en: 1;
 unsigned int byte_swap: 1;
 unsigned int cat_eyet_rb_opt: 1;
 unsigned int reserved0: 1;
 unsigned int target_freq_idx: 4;
        unsigned int wl_en: 1;
        unsigned int wl2_en: 1;
 unsigned int cst_en: 1;
 unsigned int rdet_bdl_normalize:1 ;
 unsigned int reserved2: 16;
} init_train_ctrl_str;
typedef struct {
 unsigned int reserved: 8;
 unsigned int target_freq_idx: 4;
 unsigned int reserved1: 19;
 unsigned int trfc_stop: 1;
} retrain_ctrl_str;
typedef struct {
 unsigned int step1: 1;
 unsigned int step2: 1;
 unsigned int reserved: 6;
 unsigned int target_freq_idx: 4;
 unsigned int current_freq_idx: 4;
 unsigned int ck_sel: 1;
 unsigned int ck_inc: 1;
 unsigned int ck_en: 1;
 unsigned int wr_sel: 1;
 unsigned int op_sel: 1;
 unsigned int wdqs_dcc_sel: 2;
 unsigned int wdqs_dcc_inc: 2;
 unsigned int wdqs_dcc_en: 2;
 unsigned int reserved2: 5;
} dfs_ctrl_str;
typedef union {
 unsigned int value;
 init_train_ctrl_str init_train_ctrl;
 retrain_ctrl_str retrain_ctrl;
 dfs_ctrl_str dfs_ctrl;
} lpm3_uce_proc_ctrl_union;
typedef struct {
 unsigned char det_finished: 1;
 unsigned char det_result: 5;
 unsigned char reserved: 2;
} init_train_stat_str;
typedef struct {
 unsigned char reserved: 5;
 unsigned char trfc_process: 1;
 unsigned char reserved1: 2;
} retrain_stat_str;
typedef struct {
 unsigned char step1_finished: 1;
 unsigned char step2_finished: 1;
 unsigned char reserved: 6;
} dfs_stat_str;
typedef union {
 unsigned int value;
 init_train_stat_str init_train_stat;
 retrain_stat_str retrain_stat;
 dfs_stat_str dfs_stat;
} uce_proc_stat_union;
typedef union {
 unsigned int value;
 init_train_stat_str init_train_stat[PACK_MAX_NUM];
 retrain_stat_str retrain_stat[PACK_MAX_NUM];
 dfs_stat_str dfs_stat[PACK_MAX_NUM];
} lpm3_proc_stat_union;
typedef struct {
 unsigned char lb_bytelane[2];
 unsigned char lb_bit0_byte[2];
} det_lb_str;
typedef struct {
 unsigned short rb_bytelane[2];
} det_rb_str;
typedef struct {
 unsigned char phase;
 unsigned char bit_bdl[2];
} cat_boundary_str;
typedef struct {
 unsigned char bit_bdl[4];
} wdet_bdl_str;
typedef union {
 unsigned int value;
 det_lb_str det_lb;
 det_rb_str det_rb;
 cat_boundary_str cat_boundary;
 cat_boundary_str cst_boundary;
 wdet_bdl_str wdet_bdl;
} uce_train_result_union;
#define RDERT_RESULT_MB_CH (0)
#define WDERT_RESULT_MB_CH (1)
#define RDET_BOUNDARY_MB_CH (0)
#define WDET_BOUNDARY_MB_CH (1)
#define WDET_BDL_MB_CH (2)
#define CAT_BOUNDARY_MB_CH (0)
#define RDERT_RESULT_DATA_IDX (0)
#define WDERT_RESULT_DATA_IDX (0)
#define WDET_LB_DATA_IDX (0)
#define WDET_RB_DATA_IDX (1)
#define RDET_LB_DATA_IDX (0)
#define RDET_RB_DATA_IDX (1)
#define CAT_LB_DATA_IDX (0)
#define CAT_RB_DATA_IDX (1)
#endif

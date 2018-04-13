

#ifndef CHROMATIX_RAWNF_kirin970_H_INCLUDED
#define CHROMATIX_RAWNF_kirin970_H_INCLUDED

#define RAWNF_MAX_GROUP      16
#define RAWNF_NLL_SIZE       17
#define ALGO_SWITCH_LEN      4

typedef struct
{
    //gain is the real gain of the raw by calibration tool
    unsigned int gain;
    //calibration data, ISP_DPF_NLL_COEFF, reg 0x10-0x50
    unsigned int data[RAWNF_NLL_SIZE];
} rawnf_calibration_t;

typedef struct _rawnf_reg_filter_t
{

    unsigned int isp_dpf_strength_r;
    unsigned int isp_dpf_strength_g;
    unsigned int isp_dpf_strength_b;

    unsigned int var_scale;
    unsigned int diff_scale;
    unsigned int base_blend_min;
    unsigned int edge_high_thld;
    unsigned int edge_low_thld;
    unsigned int diff_high_thd;
    unsigned int diff_low_thd;
    unsigned int orgn_blend_enable;

    unsigned int lsc_gain_offset_thld;
    unsigned int lsc_gain_offset_slope;
    unsigned int max_lsc_gain_offset;
    unsigned int gauss_offset_shift;

    unsigned int edge_offset_thld;
    unsigned int edge_offset_slope;
    unsigned int max_edge_offset;

    unsigned int hue_low0;
    unsigned int hue_high0;
    unsigned int sat_thld0;
    unsigned int edge_thld0;
    int  nlm_offset0;
    int  gauss_offset0;
    int  weight_offset0;

    unsigned int hue_low1;
    unsigned int hue_high1;
    unsigned int sat_thld1;
    unsigned int edge_thld1;
    int  nlm_offset1;
    int  gauss_offset1;
    int  weight_offset1;

    unsigned int hue_low2;
    unsigned int hue_high2;
    unsigned int sat_thld2;
    unsigned int edge_thld2;
    int  nlm_offset2;
    int  gauss_offset2;
    int  weight_offset2;
    unsigned int grey_mode;
}rawnf_reg_filter_t; //modify for chicago

// typedef struct _rawnf_cfg_t
// {
//     unsigned int calib_data[17];//对应标定数据中的calib_data某个gain的数组
//     unsigned int calib_data_edge_det[17];//对应标定数据中的cali_data_edge_det某个gain的数组
//     rawnf_reg_filter_t rawnf_reg_filter;
//     unsigned int rawnf_gauss_sigma[44];
// } rawnf_cfg_t;

typedef struct _rawnf_cfg_t{
    int lf_strength;
    int lf_gdnrscale[4];
    int lf_nrs_subs[4];
    int lf_hs_nrs[4];
    int lf_luma_nrs[4];
    int lf_centerw_lumaiso[4];
    int lf_centerw_ds[2];
    int lf_nondirw_nrs[4];
    int lf_cplf_nrs[7];
    int lf_blend_gf_luma[7];
    int lf_blend_gf_ds[4];
    int lf_blend_gf_lr[4];
    int lf_bloi_nsigma[2];
    int lf_ds_blr[4];
    int lf_benableblend;
    int lf_nondirw_dsth;
    int lf_nondirw_lumath;
    int lf_curdownscaleidx;
    int lf_dirstrengthth_x0;
    int lf_dirstrengthth_x1;
    int lf_blacklevel;
    int lf_rawnr_grey_mode;
    int lf_scaler_grey_mode;
    int lf_kernal_mode;
    int lf_lfport_enable;
    int lf_bypass_hfscaler;
    int lf_bypass_core;
    int lf_bypass;

    int hf_strength;
    int hf_gdnrscale[4];
    int hf_nrs_subs[4];
    int hf_hs_nrs[4];
    int hf_luma_nrs[4];
    int hf_centerw_lumaiso[4];
    int hf_centerw_ds[2];
    int hf_nondirw_nrs[4];
    int hf_cplf_nrs[7];
    int hf_blend_gf_luma[7];
    int hf_blend_gf_ds[4];
    int hf_blend_gf_lr[4];
    int hf_bloi_nsigma[2];
    int hf_ds_blr[4];
    int hf_benableblend;
    int hf_nondirw_dsth;
    int hf_nondirw_lumath;
    int hf_curdownscaleidx;
    int hf_dirstrengthth_x0;
    int hf_dirstrengthth_x1;
    int hf_blacklevel;
    int hf_rawnr_grey_mode;
    int hf_scaler_grey_mode;
    int hf_kernal_mode;
    int hf_lfport_enable;
    int hf_bypass_hfscaler;
    int hf_bypass_core;
    int hf_bypass;
} rawnf_cfg_t;

typedef struct _rawnf_manual_cfg_t
{
    unsigned int use_manual;
    int rawnf_switch[ALGO_SWITCH_LEN];
    rawnf_cfg_t rawnfCfg;
} rawnf_manual_cfg_t;

typedef struct
{
    //gain is the standard gain
    unsigned int gain;
    //setting data
    rawnf_reg_filter_t reg_filter;
} rawnf_filter_t;

typedef struct
{
    unsigned int cali_num;
    rawnf_calibration_t cali_data[RAWNF_MAX_GROUP];

    unsigned int filter_num;
    rawnf_filter_t filter_data[RAWNF_MAX_GROUP];
} rawnf_config_t;

typedef struct {
    unsigned char RDN_curve_idx;
    unsigned char RDN_filter_idx;
    unsigned char Reserved_0;
    unsigned char Reserved_1;
    unsigned char Reserved_2;
    unsigned char Reserved_3;
    unsigned char Reserved_4;
    unsigned char Reserved_5;
} RDN_DEBUG_INFO;

typedef struct {
    unsigned int reg_nll[RAWNF_NLL_SIZE];
    rawnf_reg_filter_t reg_filter;
} rawnf_reg_out_struct;

typedef struct
{
    unsigned int manual[2]; /*0 -AUTO 1-manual */
    rawnf_reg_out_struct rawnf_params[2];
} rawnf_cap_manual_param_t;

#endif /*CHROMATIX_RAWNF_H_INCLUDED*/

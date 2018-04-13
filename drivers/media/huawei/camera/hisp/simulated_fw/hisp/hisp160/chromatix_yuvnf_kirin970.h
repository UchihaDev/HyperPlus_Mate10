#ifndef CHROMATIX_YUVNF_kirin970_H_INCLUDED
#define CHROMATIX_YUVNF_kirin970_H_INCLUDED

#define YUVNF_MAX_GROUP            16
//#define YUVNF_MAX_GROUP_UV          18
#define ALGO_SWITCH_LEN            4

typedef struct yuv2dnr_param_y {
    unsigned int   bypass_symfilter;
    unsigned int   inv_sad;
    unsigned int   shift_sad;
    unsigned int   off_sad;

    unsigned int   gainMaxOff;
    unsigned int   edgeMaxoff;
    unsigned int   edgeTH;
    unsigned int   shift_textrue;
    unsigned int   blendLow;

    unsigned int   noiseScale;
    double           smoothW;
    unsigned int   edgeBlendLow;
    unsigned int   noEBlendLow;

    unsigned char pG3[2];
    unsigned char pG7[4];
    unsigned char pG9[5];

    unsigned int mult_gauss_en;
    unsigned int blend_x0;
    unsigned int blend_x1;
    unsigned int blend_y0;
    unsigned int blend_y1;

    unsigned int sigmaU_r;                  // range domain
    unsigned int sigmaV_r;
    unsigned int U_desaturation_TH;         // desaturation threshold, U
    unsigned int V_desaturation_TH;         // desaturation threshold, V
    unsigned int m_UV_impulsive_th;
}yuv2dnr_param;

typedef struct
{
    //gain is the standard gain
    unsigned int gain;
    //setting data
    yuv2dnr_param reg_filter;
}yuvnf_filter_t;
/*
typedef struct
{
    //gain is the standard gain
    unsigned int gain;
    //setting data
    yuv2dnr_param_uv reg_filter_uv;
} yuvnf_filter_uv_t;
*/
typedef struct
{
    int filter_num;
    yuvnf_filter_t filter_data[YUVNF_MAX_GROUP];
  //  yuvnf_filter_uv_t filter_data_uv[YUVNF_MAX_GROUP_UV];
} yuvnf_config_t;

typedef struct
{
    unsigned int manual[2]; /*0 -AUTO 1-manual */
    yuv2dnr_param  yuvnf_params[2];
} yuvnf_cap_manual_param_t;


#if 0
typedef struct _yuvnf_reg_filter_t
{
    unsigned int   bypass_symfilter;
    unsigned int   inv_sad;
    unsigned int   shift_sad;
    unsigned int   off_sad;

    unsigned int   gain_max_off;
    unsigned int   edge_max_off;
    unsigned int   edge_th;
    unsigned int   shift_textrue;
    unsigned int   blend_low;

    unsigned int   noise_scale;
    double         smooth_w;
    unsigned int   edge_blend_low;
    unsigned int   no_eblend_low;

    unsigned char pg3[2];
    unsigned char pg7[4];
    unsigned char pg9[5];

    unsigned int mult_gauss_en;
    unsigned int blend_x0;
    unsigned int blend_x1;
    unsigned int blend_y0;
    unsigned int blend_y1;

    unsigned int sigma_u_r;                  // range domain
    unsigned int sigma_v_r;
    unsigned int u_desaturation_th;         // desaturation threshold, U
    unsigned int v_desaturation_th;         // desaturation threshold, V
    unsigned int m_uv_impulsive_th;
}yuvnf_reg_filter_t; //add for chicago
#endif

typedef struct y_calib_param{
    unsigned int   bypass_symfilter;
    unsigned int   inv_sad;
    unsigned int   shift_sad;
    unsigned int   off_sad;

    unsigned int   gain_max_off;
    unsigned int   edge_max_off;
    unsigned int   edge_th;
    unsigned int   shift_textrue;
    unsigned int   blend_low;

    unsigned int   noise_scale;
    double         smooth_w;
    unsigned int   edge_blend_low;
    unsigned int   no_eblend_low;

    unsigned char pg3[2];
    unsigned char pg7[4];
    unsigned char pg9[5];

    unsigned int mult_gauss_en;
    unsigned int blend_x0;
    unsigned int blend_x1;
    unsigned int blend_y0;
    unsigned int blend_y1;
} y_calib_param;

typedef struct layer0_uv_calib_param
{
    int soft_thr_w;
    int soft_thr;
    int sa0_nr_strength;
    int sa1_nr_strength;
    int sa2_nr_strength;
    int sa3_nr_strength;

}layer0_uv_calib_param;

typedef struct layer3_uv_calib_param
{
    int soft_thr_w;
    int soft_thr;
    int sa0_nr_strength;
    int sa1_nr_strength;
    int sa2_nr_strength;
    int sa3_nr_strength;

}layer3_uv_calib_param;

typedef struct layer_lap_uv_calib_param
{
    int soft_thr_w;
    int soft_thr;
    int sa0_nr_strength;
    int sa1_nr_strength;
    int sa2_nr_strength;
    int sa3_nr_strength;
    int lsc_scale;
}layer_lap_uv_calib_param;
typedef struct layer0_uv_common_calib_param
{
    int sa0_cb_thr0;
    int sa0_cb_thr1;
    int sa0_cr_thr0;
    int sa0_cr_thr1;

    int sa1_cb_thr0;
    int sa1_cb_thr1;
    int sa1_cr_thr0;
    int sa1_cr_thr1;

    int sa2_cb_thr0;
    int sa2_cb_thr1;
    int sa2_cr_thr0;
    int sa2_cr_thr1;

    int sa3_cb_thr0;
    int sa3_cb_thr1;
    int sa3_cr_thr0;
    int sa3_cr_thr1;
    unsigned int sa_num;
    int median_bypass;
    int edge_thr_u;
    int edge_thr_v;
    unsigned int median_thr0;
    unsigned int median_thr1;
    unsigned int med_wb;
    int lsc_scale;
}layer0_uv_common_calib_param;

typedef struct layer3_uv_common_calib_param
{
    int lsc_scale;

}layer3_uv_common_calib_param;

typedef struct yuvnf_reg_filter_t{
    y_calib_param y_params;

    int lap_layer_uv_bypass;
    int offline_bypass;
    int layer0_uv_bypass;
    int layer1_uv_bypass;
    int layer2_uv_bypass;
    int layer3_uv_bypass;
    int layer4_uv_bypass;
    int layer5_uv_bypass;

    unsigned int layer0_u_denlut[64];
    unsigned int layer0_u_gaulut[2];
    unsigned int layer0_u_denreflut[64];
    unsigned int layer1_u_denlut[64];
    unsigned int layer1_u_gaulut[2];
    unsigned int layer1_u_denreflut[64];
    unsigned int layer2_u_denlut[64];
    unsigned int layer2_u_gaulut[2];
    unsigned int layer2_u_denreflut[64];
    unsigned int layer3_u_denlut[64];
    unsigned int layer3_u_gaulut[2];
    unsigned int layer3_u_denreflut[64];
    unsigned int layer4_u_denlut[64];
    unsigned int layer4_u_gaulut[5];
    unsigned int layer4_u_denreflut[64];
    unsigned int layer5_u_denlut[64];
    unsigned int layer5_u_gaulut[5];
    unsigned int layer5_u_denreflut[64];

    layer0_uv_calib_param layer0_u_params;
    layer0_uv_calib_param layer1_u_params;
    layer0_uv_calib_param layer2_u_params;
    layer3_uv_calib_param layer3_u_params;
    layer3_uv_calib_param layer4_u_params;
    layer3_uv_calib_param layer5_u_params;
    layer_lap_uv_calib_param layer_lap_u_params;

    unsigned int layer0_v_denlut[64];
    unsigned int layer0_v_gaulut[2];
    unsigned int layer0_v_denreflut[64];
    unsigned int layer1_v_denlut[64];
    unsigned int layer1_v_gaulut[2];
    unsigned int layer1_v_denreflut[64];
    unsigned int layer2_v_denlut[64];
    unsigned int layer2_v_gaulut[2];
    unsigned int layer2_v_denreflut[64];
    unsigned int layer3_v_denlut[64];
    unsigned int layer3_v_gaulut[2];
    unsigned int layer3_v_denreflut[64];
    unsigned int layer4_v_denlut[64];
    unsigned int layer4_v_gaulut[5];
    unsigned int layer4_v_denreflut[64];
    unsigned int layer5_v_denlut[64];
    unsigned int layer5_v_gaulut[5];
    unsigned int layer5_v_denreflut[64];

    layer0_uv_calib_param layer0_v_params;
    layer0_uv_calib_param layer1_v_params;
    layer0_uv_calib_param layer2_v_params;
    layer3_uv_calib_param layer3_v_params;
    layer3_uv_calib_param layer4_v_params;
    layer3_uv_calib_param layer5_v_params;
    layer_lap_uv_calib_param layer_lap_v_params;

    layer0_uv_common_calib_param layer0_uv_params;
    layer0_uv_common_calib_param layer1_uv_params;
    layer0_uv_common_calib_param layer2_uv_params;
    layer3_uv_common_calib_param layer3_uv_params;
    layer3_uv_common_calib_param layer4_uv_params;
    layer3_uv_common_calib_param layer5_uv_params;
} yuvnf_reg_filter_t;

typedef struct _yuvnf_manual_cfg_t
{
    unsigned int use_manual;
    int yuvnf_switch[ALGO_SWITCH_LEN];
    yuvnf_reg_filter_t yuvnf_reg_filter;
}yuvnf_manual_cfg_t;

/////////////////////////////////////yuvnf_iir/////////////////////
typedef struct special_calib_params
{

    /********special area detection**********/
    unsigned int sa_num;
    unsigned int sa0_cb_thr0;//for special area ie.red area;
    unsigned int sa0_cb_thr1;
    unsigned int sa0_cr_thr0;
    unsigned int sa0_cr_thr1;
    unsigned int sa0_nr_strength;

    unsigned int sa1_cb_thr0;//for special area ie.blue area;
    unsigned int sa1_cb_thr1;
    unsigned int sa1_cr_thr0;
    unsigned int sa1_cr_thr1;
    unsigned int sa1_nr_strength;

    unsigned int sa2_cb_thr0;
    unsigned int sa2_cb_thr1;
    unsigned int sa2_cr_thr0;
    unsigned int sa2_cr_thr1;
    unsigned int sa2_nr_strength;

    unsigned int sa3_cb_thr0;
    unsigned int sa3_cb_thr1;
    unsigned int sa3_cr_thr0;
    unsigned int sa3_cr_thr1;
    unsigned int sa3_nr_strength;

} special_calib_params;

typedef struct y_component_calib_params
{

    /********Y NR*********/
    unsigned int thr0;
    unsigned int cof0;
    unsigned int thr1;
    unsigned int cof1;
    unsigned int thr2;
    unsigned int cof2;
    unsigned int sk_thr;

    double sig;
    //int max_luma;
    unsigned int sa0_y_nr_strength;
    unsigned int sa1_y_nr_strength;
    unsigned int sa2_y_nr_strength;
    unsigned int sa3_y_nr_strength;

} y_component_calib_params;

typedef struct add_back_params
{
    unsigned int add_back[64];
} add_back_params;

typedef struct _yuvnf_iir_reg_filter
{
    double chromaStren; //250 max
    unsigned int chromaDetailRatio;//13bit fix point(max 8192)

    unsigned int sat_thr_u;
    unsigned int delta_thr_u;
    unsigned int sat_thr_v;
    unsigned int delta_thr_v;

    unsigned int ipr_mode;
    unsigned int ipr_thr;
    unsigned int ipr_thr0;
    unsigned int ipr_thr1;
    unsigned int ipr_thr2;
    unsigned int ipr_thr3;
    unsigned int ipr_fw;
    unsigned int ipr_cnt;

    unsigned int edge_stren_thr_u;
    unsigned int edge_stren_thr_v;

    special_calib_params special_calib_paras;
    y_component_calib_params y_component_calib_paras;
    add_back_params add_back_calib_paras;

} yuvnf_iir_reg_filter_t;

typedef struct _yuvnf_iir_manual_cfg_t
{
    unsigned int use_manual;
    int yuvnfIIR_switch[ALGO_SWITCH_LEN];
    yuvnf_iir_reg_filter_t yuvnfIirCfg;
}yuvnf_iir_manual_cfg_t;

#endif /*CHROMATIX_YUVNF_H_INCLUDED*/


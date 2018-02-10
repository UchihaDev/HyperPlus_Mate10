#ifndef CHROMATIX_DE_kirin970_H_INCLUDED
#define CHROMATIX_DE_kirin970_H_INCLUDED

#define ALGO_SWITCH_LEN    4
typedef struct
{
    unsigned int black_noise_scale;//153, [0, 255]
    unsigned int white_noise_scale;//102, [0, 255]

    unsigned int black_noise_clip;//3, [0, 15]
    unsigned int white_noise_clip;//2, [0, 15]

    //unsigned int globalgainLF;//128, [0, 255] pReg->globalgainLF = _linearinter_i(iso, 400,1600, 128, 64);
    unsigned int globalgainLF_x0;
    unsigned int globalgainLF_x1;
    unsigned int globalgainLF_y0;
    unsigned int globalgainLF_y1;

    //unsigned int globalgainMF;//255, [0, 255]
    unsigned int globalgainHF_x0;
    unsigned int globalgainHF_x1;
    unsigned int globalgainHF_y0;
    unsigned int globalgainHF_y1;

    unsigned int globalgainMF_x0;//128, [0, 255]
    unsigned int globalgainMF_x1;
    unsigned int globalgainMF_y0;
    unsigned int globalgainMF_y1;

    //unsigned int lutMFNoise[3][3];//[0, 1023]//0:org size; 1:down scale 2; 2:down scale 4
    //For LPF3x3: (1<<G_PRECISION) >= lut[1]+2*lut[0]; if sigma=0.7, lut[2]={214, 596}
    //For LPF5x5: (1<<G_PRECISION) >= lut[2]+2*lut[1]+2*lut[0]; if sigma=0.9, lut[3]={38, 246,456}
    //unsigned int lutMFNoise5x5LPF[3];//[0, 1023]
    //unsigned int lutMFNoise3x3LPF[2][2];//[0, 1023]//0:down scale 2; 1:down scale 4
    //unsigned int lutLFNoise[3];//[0, 1023]
    float q_sigma_mf5x5;
    float q_sigma_mf3x3_1;
    float q_sigma_mf3x3_2;
    float q_sigma_lf;

    //
    unsigned int gamma_scale_lf;//19, [0, 31]
    unsigned int gamma_scale_mf;//4,  [0, 7]

    //unsigned int minGainScale; //127, [0, 127] minGainScale = _linearinter_i(iso, 0, 400, 127, 102);
    unsigned int minGainScale_x0;
    unsigned int minGainScale_x1;
    unsigned int minGainScale_y0;
    unsigned int minGainScale_y1;

    //gainScale
    unsigned int gainScale_luma_x0;//64, [0, 255]
    unsigned int gainScale_luma_x1;//128,[0, 255]
    unsigned int gainScale_luma_x2;//196,[0, 255]
    unsigned int gainScale_luma_x3;//240,[0, 255]

    //unsigned int gainScale_luma_y0;//102,[0, 127] pReg->gainScale_luma_y0 = _linearinter_i(iso, 400,1600, 102, 38);
    unsigned int gainScale_luma_y0_x0;
    unsigned int gainScale_luma_y0_x1;
    unsigned int gainScale_luma_y0_y0;
    unsigned int gainScale_luma_y0_y1;

    unsigned int gainScale_luma_y1;//127,[0, 127]
    //unsigned int gainScale_luma_y2;//102,[0, 127]
    unsigned int gainScale_luma_y2_x0;
    unsigned int gainScale_luma_y2_x1;
    unsigned int gainScale_luma_y2_y0;
    unsigned int gainScale_luma_y2_y1;

    unsigned int gainScale_lumaScale_x0;//3*128,[0, 1023]
    unsigned int gainScale_lumaScale_x1;//7*128,[0, 1023]
    unsigned int gainScale_lumaScale_y0;//128,  [0, 511]
    unsigned int gainScale_lumaScale_y1;//256,  [0, 511]

    //blr
    unsigned int blr_lumaScale_x0;//3, [0, 15]
    unsigned int blr_lumaScale_x1;//7, [0, 15]
    unsigned int blr_lumaScale_y; //26,[0, 127]

    unsigned int blr_luma_x0;//64, [0, 255]
    unsigned int blr_luma_x1;//192,[0, 255]
    //unsigned int blr_luma_y0;//0,  [0, 127] pReg->blr_luma_y0 = _linearinter_i(iso, 1600, 3200, 76, 102);
    unsigned int blr_luma_y0_x0;
    unsigned int blr_luma_y0_x1;
    unsigned int blr_luma_y0_y0;
    unsigned int blr_luma_y0_y1;

    unsigned int blr_luma_y1;//127,[0, 127]

    //darkR
    unsigned int darkR_ratio;//341, [0, 1023], 1==512
    unsigned int darkR_max;//3*128, [0, 1023]
    unsigned int darkR_min;//1*128, [0, 1023]

    unsigned int darkR_v_x0;//24, [0, 255]
    unsigned int darkR_v_x1;//64, [0, 255]

    unsigned int darkR_s_x0;//150, [0, 255]
    unsigned int darkR_s_x1;//200, [0, 255]

    unsigned int darkR_iso_x0;//100, [0, max_iso], 14bits
    unsigned int darkR_iso_x1;//200, [0, max_iso], 14bits
    unsigned int darkR_iso_x2;//200, [0, max_iso], 14bits
    unsigned int darkR_iso_x3;//600, [0, max_iso], 14bits

    //distR
    //unsigned int distMax;  //2304,[0, max(width/2,height/2)]
    unsigned int distR_max;//358, [0, 1023]
    unsigned int distR_min;//128, [0, 1023]

    //distR_dist_x0 = (INT32)(distMax * distR_dist_x0_coef);
    float   distR_dist_x0_coef;//1152,[0, max(width/2,height/2)]
    float   distR_dist_x1_coef;//1728,[0, max(width/2,height/2)]

    unsigned int distR_iso_x0;//100, [0, max_iso], 14bits
    unsigned int distR_iso_x1;//200, [0, max_iso], 14bits
    unsigned int distR_iso_x2;//200, [0, max_iso], 14bits
    unsigned int distR_iso_x3;//600, [0, max_iso], 14bits

    unsigned int distR_s_x0;//128, [0, 255]
    unsigned int distR_s_x1;//192, [0, 255]

    unsigned int distR_luma_x0;//32, [0, 255]
    unsigned int distR_luma_x1;//96, [0, 255]

    //brightR
    unsigned int brightR_max;//127, [0, 127]
    unsigned int brightR_min;//64,  [0, 127]

    unsigned int brightR_iso_x0;//450, [0, max_iso], 14bits
    unsigned int brightR_iso_x1;//600, [0, max_iso], 14bits

    unsigned int brightR_v0_x0;//50, [0, 255]
    unsigned int brightR_v0_x1;//100,[0, 255]
    unsigned int brightR_v0_x2;//150,[0, 255]
    unsigned int brightR_v0_x3;//200,[0, 255]

    unsigned int brightR_v1_x0;//230, [0, 255]
    unsigned int brightR_v1_x1;//250, [0, 255]

    unsigned int brightR_s_x0;//60, [0, 255]
    unsigned int brightR_s_x1;//80, [0, 255]

    //colorR
    unsigned int colorR_s_x0;//5, [0, 255]
    unsigned int colorR_s_x1;//20,[0, 255]
    unsigned int colorR_s_y0;//64,[0, 127]
    unsigned int colorR_s_y1;//102[0, 127]

    unsigned int colorR_v_x0;//80,[0, 255]
    unsigned int colorR_v_x1;//160[0, 255]
    unsigned int colorR_v_y; //38,[0, 127]

    unsigned int colorR_h0_x0;//20, [0, 255]
    unsigned int colorR_h0_x1;//50, [0, 255]
    unsigned int colorR_h0_y; //89, [0, 127]

    unsigned int colorR_h1_x0;//210, [0, 255]
    unsigned int colorR_h1_x1;//240, [0, 255]
    unsigned int colorR_h1_y; //89,  [0, 127]

    unsigned int colorR_h2_x0;//42, [0, 255]
    unsigned int colorR_h2_x1;//60, [0, 255]
    unsigned int colorR_h2_x2;//105,[0, 255]
    unsigned int colorR_h2_x3;//127,[0, 255]
    unsigned int colorR_h2_y; //102,[0, 127]

    unsigned int colorR_h3_x0;//110, [0, 255]
    unsigned int colorR_h3_x1;//140, [0, 255]
    unsigned int colorR_h3_x2;//200, [0, 255]
    unsigned int colorR_h3_x3;//235, [0, 255]

    unsigned int colorR_iso;//100, [0, max_iso], 14bits

    unsigned int colorR_bs0_x0;//5*128, [0, 16383]
    unsigned int colorR_bs0_x1;//20*128,[0, 16383]
    unsigned int colorR_bs0_y; //25,    [0, 127]

    unsigned int colorR_bs1_x0;//20*128,[0, 16383]
    unsigned int colorR_bs1_x1;//100*128[0, 16383]
    unsigned int colorR_bs1_y; //25,    [0, 127]

    //grayR
    unsigned int grayR_max;//128, [0, 127]
    unsigned int grayR_min;//51,  [0, 127]

    unsigned int grayR_iso_x0;//450, [0, max_iso]; 14bits
    unsigned int grayR_iso_x1;//600, [0, max_iso]; 14bits

    unsigned int grayR_s_x0;//60, [0, 255]
    unsigned int grayR_s_x1;//80, [0, 255]

    unsigned int grayR_v_x0;//50, [0, 255]
    unsigned int grayR_v_x1;//100,[0, 255]
    unsigned int grayR_v_x2;//150,[0, 255]
    unsigned int grayR_v_x3;//200,[0, 255]
} detail_enhance_calib_param;

typedef struct _de_manual_cfg_t
{
    unsigned int use_manual;
    int de_switch[ALGO_SWITCH_LEN];
    detail_enhance_calib_param deCfg;
}de_manual_cfg_t;


#endif /*CHROMATIX_DE_H_INCLUDED*/


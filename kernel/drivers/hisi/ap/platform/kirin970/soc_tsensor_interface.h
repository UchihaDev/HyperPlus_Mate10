#ifndef __SOC_TSENSOR_INTERFACE_H__
#define __SOC_TSENSOR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_TSENSOR_CALIBRATION1_ADDR(base,m) ((base) + (0x0000+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION2_ADDR(base,m) ((base) + (0x0004+0x100*(m)))
#define SOC_TSENSOR_TEMP_CONFIG_ADDR(base,m) ((base) + (0x0008+0x100*(m)))
#define SOC_TSENSOR_TEMP_DET_EN_ADDR(base,m) ((base) + (0x000C+0x100*(m)))
#define SOC_TSENSOR_TEMP_WAIT_BYPASS_ADDR(base,m) ((base) + (0x0010+0x100*(m)))
#define SOC_TSENSOR_TEMP_WAIT_TIME_ADDR(base,m) ((base) + (0x0014+0x100*(m)))
#define SOC_TSENSOR_TEMP_FSMSTAT_ADDR(base,m) ((base) + (0x0018+0x100*(m)))
#define SOC_TSENSOR_TEMP_ADDR(base,m) ((base) + (0x001C+0x100*(m)))
#define SOC_TSENSOR_TEMP_TH_ADDR(base,m) ((base) + (0x0020+0x100*(m)))
#define SOC_TSENSOR_TEMP_RST_TH_ADDR(base,m) ((base) + (0x0024+0x100*(m)))
#define SOC_TSENSOR_TEMP_LAG_ADDR(base,m) ((base) + (0x0028+0x100*(m)))
#define SOC_TSENSOR_TEMP_LOW_TH_ADDR(base,m) ((base) + (0x002C+0x100*(m)))
#define SOC_TSENSOR_TEMP_INT_CLR_ADDR(base,m) ((base) + (0x0030+0x100*(m)))
#define SOC_TSENSOR_TEMP_SOFTCTRL_ADDR(base,m) ((base) + (0x0034+0x100*(m)))
#define SOC_TSENSOR_TEMP_SOFT_ADDR(base,m) ((base) + (0x0038+0x100*(m)))
#define SOC_TSENSOR_T_SENSOR_EN2DIS_MSK_ADDR(base,m) ((base) + (0x003C+0x100*(m)))
#define SOC_TSENSOR_T_SENSOR_EN2DIS_CLR_ADDR(base,m) ((base) + (0x0040+0x100*(m)))
#define SOC_TSENSOR_TS_CTRL_EN2DIS_MSK_ADDR(base,m) ((base) + (0x0044+0x100*(m)))
#define SOC_TSENSOR_TS_CTRL_EN2DIS_CLR_ADDR(base,m) ((base) + (0x0048+0x100*(m)))
#define SOC_TSENSOR_TEMP_RST_MSK_ADDR(base,m) ((base) + (0x04C+0x100*(m)))
#define SOC_TSENSOR_TEMP_RAWINT_H_ADDR(base,m) ((base) + (0x050+0x100*(m)))
#define SOC_TSENSOR_TEMP_MSKINT_H_ADDR(base,m) ((base) + (0x054+0x100*(m)))
#define SOC_TSENSOR_TEMP_RAWINT_L_ADDR(base,m) ((base) + (0x058+0x100*(m)))
#define SOC_TSENSOR_TEMP_MSKINT_L_ADDR(base,m) ((base) + (0x05C+0x100*(m)))
#define SOC_TSENSOR_TEMP_TRIM_CFG_ADDR(base,m) ((base) + (0x060+0x100*(m)))
#define SOC_TSENSOR_TEMP_INT_MSK_ADDR(base,m) ((base) + (0x064+0x100*(m)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int local_sensorerror : 10;
        unsigned int remote_sensor1error : 6;
        unsigned int remote_sensor2error : 8;
        unsigned int remote_sensor3error : 8;
    } reg;
} SOC_TSENSOR_CALIBRATION1_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION1_local_sensorerror_START (0)
#define SOC_TSENSOR_CALIBRATION1_local_sensorerror_END (9)
#define SOC_TSENSOR_CALIBRATION1_remote_sensor1error_START (10)
#define SOC_TSENSOR_CALIBRATION1_remote_sensor1error_END (15)
#define SOC_TSENSOR_CALIBRATION1_remote_sensor2error_START (16)
#define SOC_TSENSOR_CALIBRATION1_remote_sensor2error_END (23)
#define SOC_TSENSOR_CALIBRATION1_remote_sensor3error_START (24)
#define SOC_TSENSOR_CALIBRATION1_remote_sensor3error_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remote_sensor4error : 10;
        unsigned int remote_sensor5error : 6;
        unsigned int remote_sensor6error : 8;
        unsigned int remote_sensor7error : 8;
    } reg;
} SOC_TSENSOR_CALIBRATION2_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION2_remote_sensor4error_START (0)
#define SOC_TSENSOR_CALIBRATION2_remote_sensor4error_END (9)
#define SOC_TSENSOR_CALIBRATION2_remote_sensor5error_START (10)
#define SOC_TSENSOR_CALIBRATION2_remote_sensor5error_END (15)
#define SOC_TSENSOR_CALIBRATION2_remote_sensor6error_START (16)
#define SOC_TSENSOR_CALIBRATION2_remote_sensor6error_END (23)
#define SOC_TSENSOR_CALIBRATION2_remote_sensor7error_START (24)
#define SOC_TSENSOR_CALIBRATION2_remote_sensor7error_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_num : 3;
        unsigned int channel_sel : 4;
        unsigned int temp_mode : 2;
        unsigned int sample_num : 8;
        unsigned int temp_ct_sel_apb : 2;
        unsigned int reserved : 13;
    } reg;
} SOC_TSENSOR_TEMP_CONFIG_UNION;
#endif
#define SOC_TSENSOR_TEMP_CONFIG_channel_num_START (0)
#define SOC_TSENSOR_TEMP_CONFIG_channel_num_END (2)
#define SOC_TSENSOR_TEMP_CONFIG_channel_sel_START (3)
#define SOC_TSENSOR_TEMP_CONFIG_channel_sel_END (6)
#define SOC_TSENSOR_TEMP_CONFIG_temp_mode_START (7)
#define SOC_TSENSOR_TEMP_CONFIG_temp_mode_END (8)
#define SOC_TSENSOR_TEMP_CONFIG_sample_num_START (9)
#define SOC_TSENSOR_TEMP_CONFIG_sample_num_END (16)
#define SOC_TSENSOR_TEMP_CONFIG_temp_ct_sel_apb_START (17)
#define SOC_TSENSOR_TEMP_CONFIG_temp_ct_sel_apb_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_det_en : 1;
        unsigned int temp_calib : 1;
        unsigned int temp_calib_vmode_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_TSENSOR_TEMP_DET_EN_UNION;
#endif
#define SOC_TSENSOR_TEMP_DET_EN_temp_det_en_START (0)
#define SOC_TSENSOR_TEMP_DET_EN_temp_det_en_END (0)
#define SOC_TSENSOR_TEMP_DET_EN_temp_calib_START (1)
#define SOC_TSENSOR_TEMP_DET_EN_temp_calib_END (1)
#define SOC_TSENSOR_TEMP_DET_EN_temp_calib_vmode_en_START (2)
#define SOC_TSENSOR_TEMP_DET_EN_temp_calib_vmode_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_wait_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TEMP_WAIT_BYPASS_UNION;
#endif
#define SOC_TSENSOR_TEMP_WAIT_BYPASS_temp_wait_bypass_START (0)
#define SOC_TSENSOR_TEMP_WAIT_BYPASS_temp_wait_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_wait_time : 32;
    } reg;
} SOC_TSENSOR_TEMP_WAIT_TIME_UNION;
#endif
#define SOC_TSENSOR_TEMP_WAIT_TIME_temp_wait_time_START (0)
#define SOC_TSENSOR_TEMP_WAIT_TIME_temp_wait_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m_fsm_stat : 4;
        unsigned int s_fsm_stat : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_FSMSTAT_UNION;
#endif
#define SOC_TSENSOR_TEMP_FSMSTAT_m_fsm_stat_START (0)
#define SOC_TSENSOR_TEMP_FSMSTAT_m_fsm_stat_END (3)
#define SOC_TSENSOR_TEMP_FSMSTAT_s_fsm_stat_START (4)
#define SOC_TSENSOR_TEMP_FSMSTAT_s_fsm_stat_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_TEMP_UNION;
#endif
#define SOC_TSENSOR_TEMP_temp_START (0)
#define SOC_TSENSOR_TEMP_temp_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_0th : 10;
        unsigned int temp_1th : 10;
        unsigned int temp_2th : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_TSENSOR_TEMP_TH_UNION;
#endif
#define SOC_TSENSOR_TEMP_TH_temp_0th_START (0)
#define SOC_TSENSOR_TEMP_TH_temp_0th_END (9)
#define SOC_TSENSOR_TEMP_TH_temp_1th_START (10)
#define SOC_TSENSOR_TEMP_TH_temp_1th_END (19)
#define SOC_TSENSOR_TEMP_TH_temp_2th_START (20)
#define SOC_TSENSOR_TEMP_TH_temp_2th_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_rst_th : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_TEMP_RST_TH_UNION;
#endif
#define SOC_TSENSOR_TEMP_RST_TH_temp_rst_th_START (0)
#define SOC_TSENSOR_TEMP_RST_TH_temp_rst_th_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_lag : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_TSENSOR_TEMP_LAG_UNION;
#endif
#define SOC_TSENSOR_TEMP_LAG_temp_lag_START (0)
#define SOC_TSENSOR_TEMP_LAG_temp_lag_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_low_th : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_TEMP_LOW_TH_UNION;
#endif
#define SOC_TSENSOR_TEMP_LOW_TH_temp_low_th_START (0)
#define SOC_TSENSOR_TEMP_LOW_TH_temp_low_th_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TEMP_INT_CLR_UNION;
#endif
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr_START (0)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_soft : 1;
        unsigned int temp_en_soft : 1;
        unsigned int ct_sel_soft : 2;
        unsigned int test_soft : 8;
        unsigned int calib_soft : 1;
        unsigned int calib_en_soft : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_TSENSOR_TEMP_SOFTCTRL_UNION;
#endif
#define SOC_TSENSOR_TEMP_SOFTCTRL_sel_soft_START (0)
#define SOC_TSENSOR_TEMP_SOFTCTRL_sel_soft_END (0)
#define SOC_TSENSOR_TEMP_SOFTCTRL_temp_en_soft_START (1)
#define SOC_TSENSOR_TEMP_SOFTCTRL_temp_en_soft_END (1)
#define SOC_TSENSOR_TEMP_SOFTCTRL_ct_sel_soft_START (2)
#define SOC_TSENSOR_TEMP_SOFTCTRL_ct_sel_soft_END (3)
#define SOC_TSENSOR_TEMP_SOFTCTRL_test_soft_START (4)
#define SOC_TSENSOR_TEMP_SOFTCTRL_test_soft_END (11)
#define SOC_TSENSOR_TEMP_SOFTCTRL_calib_soft_START (12)
#define SOC_TSENSOR_TEMP_SOFTCTRL_calib_soft_END (12)
#define SOC_TSENSOR_TEMP_SOFTCTRL_calib_en_soft_START (13)
#define SOC_TSENSOR_TEMP_SOFTCTRL_calib_en_soft_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_soft : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_TEMP_SOFT_UNION;
#endif
#define SOC_TSENSOR_TEMP_SOFT_temp_soft_START (0)
#define SOC_TSENSOR_TEMP_SOFT_temp_soft_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_sensor_en2dis_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_T_SENSOR_EN2DIS_MSK_UNION;
#endif
#define SOC_TSENSOR_T_SENSOR_EN2DIS_MSK_t_sensor_en2dis_msk_START (0)
#define SOC_TSENSOR_T_SENSOR_EN2DIS_MSK_t_sensor_en2dis_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_sensor_en2dis_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_T_SENSOR_EN2DIS_CLR_UNION;
#endif
#define SOC_TSENSOR_T_SENSOR_EN2DIS_CLR_t_sensor_en2dis_clr_START (0)
#define SOC_TSENSOR_T_SENSOR_EN2DIS_CLR_t_sensor_en2dis_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_ctrl_en2dis_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TS_CTRL_EN2DIS_MSK_UNION;
#endif
#define SOC_TSENSOR_TS_CTRL_EN2DIS_MSK_ts_ctrl_en2dis_msk_START (0)
#define SOC_TSENSOR_TS_CTRL_EN2DIS_MSK_ts_ctrl_en2dis_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_ctrl_en2dis_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TS_CTRL_EN2DIS_CLR_UNION;
#endif
#define SOC_TSENSOR_TS_CTRL_EN2DIS_CLR_ts_ctrl_en2dis_clr_START (0)
#define SOC_TSENSOR_TS_CTRL_EN2DIS_CLR_ts_ctrl_en2dis_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_rst_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TEMP_RST_MSK_UNION;
#endif
#define SOC_TSENSOR_TEMP_RST_MSK_temp_rst_msk_START (0)
#define SOC_TSENSOR_TEMP_RST_MSK_temp_rst_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_rawint_h : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TEMP_RAWINT_H_UNION;
#endif
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h_START (0)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_mskint_h : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TEMP_MSKINT_H_UNION;
#endif
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h_START (0)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_rawint_l : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TEMP_RAWINT_L_UNION;
#endif
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l_START (0)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_mskint_l : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TEMP_MSKINT_L_UNION;
#endif
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l_START (0)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_ready_sel : 1;
        unsigned int temp_cfg : 8;
        unsigned int reserved : 23;
    } reg;
} SOC_TSENSOR_TEMP_TRIM_CFG_UNION;
#endif
#define SOC_TSENSOR_TEMP_TRIM_CFG_temp_ready_sel_START (0)
#define SOC_TSENSOR_TEMP_TRIM_CFG_temp_ready_sel_END (0)
#define SOC_TSENSOR_TEMP_TRIM_CFG_temp_cfg_START (1)
#define SOC_TSENSOR_TEMP_TRIM_CFG_temp_cfg_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_int_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TEMP_INT_MSK_UNION;
#endif
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk_START (0)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

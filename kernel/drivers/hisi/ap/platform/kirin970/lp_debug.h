





#ifndef __LP_DEBUG_H__
#define __LP_DEBUG_H__ 



#define LP_DBG_DDR_FT "DDR"
#define LP_DBG_ACPU_FT "AP"
#define LP_DBG_MDDRFREQ_FT "DPL"
#define LP_DBG_MACPUFEQ_FT "APL"
#define LP_DBG_PERIVOL_FT "PERIP"


#define LP_DBG_MAGIC_BEGIN 0x5D5E5A5D
#define LP_DBG_MAGIC_BEGIN_EX 0xD5A5E5D5
#define LP_DBG_MAGIC_END 0x5A5B5C5D
#define LP_DBG_MAGIC_END_EX 0xD5C5B5A5


typedef struct LP_DBG_DDR_PARA {

 unsigned int valid : 1;
 unsigned int startprofile_vld : 1;
 unsigned int timing_vld : 1;
 unsigned int lp_vld : 1;
 unsigned int min_vld : 1;
 unsigned int max_vld : 1;
 unsigned int vcore_vld : 1;
 unsigned int vio_vld : 1;
 unsigned int vpll_vld : 1;
 unsigned int reserved : 23;

 unsigned int startprofile;
 unsigned int timing;
 unsigned int lp;
 unsigned int min;
 unsigned int max;
 signed int vcore;
 signed int vio;
 signed int vpll;
} LP_DBG_DDR_PARA_T;

#define LCORE_FREQ_NUM 6
#define BCORE_FREQ_NUM 8

typedef struct LP_DBG_ACPU_PARA {

 unsigned int valid : 1;
 unsigned int startprofile_vld : 1;
 unsigned int startcore_vld : 1;
 unsigned int lcore_vol_vld : 1;
 unsigned int bcore_vol_vld : 1;
 unsigned int reserved : 27;

 unsigned int startprofile;
 unsigned int startcore;
 signed int lcore_vol[LCORE_FREQ_NUM];
 signed int bcore_vol[BCORE_FREQ_NUM];
} LP_DBG_ACPU_PARA_T;

typedef struct LP_DBG_MDDRFREQ_PARA {

 unsigned int valid : 1;
 unsigned int ppll_vld : 1;
 unsigned int ppllctrl0_vld : 1;
 unsigned int ppllctrl1_vld : 1;
 unsigned int reserved : 28;

 unsigned int ppll;
 unsigned int ppllctrl0;
 unsigned int ppllctrl1;
} LP_DBG_MDDRFREQ_PARA_T;

typedef struct LP_DBG_MACPUFEQ_PARA {

 unsigned int valid : 1;
 unsigned int profile_vld : 1;
 unsigned int cluster_vld : 1;
 unsigned int apllctrl0_vld : 1;
 unsigned int apllctrl1_vld : 1;
 unsigned int clkdiv_vld : 1;
 unsigned int phase_vld : 1;
 unsigned int reserved : 25;

 unsigned int profile;
 unsigned int cluster;
 unsigned int apllctrl0;
 unsigned int apllctrl1;
 unsigned int clkdiv;
 unsigned int phase;
} LP_DBG_MACPUFEQ_PARA_T;

#define PERIL_VOLT_LEVEL_NUM (4)
#define PERIL_INIT_FLAG (0x5A)
typedef struct LP_DBG_PERIL_DVFS {
 short volt_bias[PERIL_VOLT_LEVEL_NUM];
 unsigned int init_flag;
} LP_DBG_PERIL_DVFS_T;

typedef struct LP_DBG_SHARED_S {
 unsigned int magic_begin;
 unsigned int magic_begin_ex;


 unsigned int lpddr_profile[8][32];
 unsigned int lpddr_training_para_addr;
 LP_DBG_ACPU_PARA_T xl2fsb_dbg_acpu_para;
 LP_DBG_MACPUFEQ_PARA_T xl2fsb_dbg_macpufreq_para;
 unsigned int cluster_volt[3][10][2];
 unsigned int l2_test_result;
 LP_DBG_PERIL_DVFS_T peril_para;


 unsigned int magic_end;
 unsigned int magic_end_ex;
} LP_DBG_SHARED_T;

typedef struct LP_DBG_PERIVOL_PARA {

 unsigned int valid : 1;
 unsigned int vol_vld : 1;
 unsigned int reserved : 30;

 unsigned int vol;
} LP_DBG_PERIVOL_PARA_T;


typedef struct LP_DBG_NV_MAP {
 char *feature;
 unsigned int nv_num;
 char **items_addr;
 unsigned int items_num;
} LP_DBG_NV_MAP_T;

#endif

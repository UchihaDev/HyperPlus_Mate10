#ifndef __MDRV_MSP_SLEEP_COMMON_H__ 
#define __MDRV_MSP_SLEEP_COMMON_H__
#ifdef __cplusplus
extern "C"
{
#endif

#include "mdrv_pm_common.h"

#define SLAVE_MODE_BUTT (PWC_COMM_MODE_NUMBER)
#define DSP_WAIT_IDLE_FLAG (0xa5)

enum MasterMode_Enum
{
    MASTER_MODE_LTE = 0,
    MASTER_MODE_TDS = 1,
    MASTER_MODE_BUTT
};

enum TLSLEEP_RttForceAwake_Type
{
    TLSLEEP_MAILBOX = 0,
    TLSLEEP_OTHERS
};

typedef enum cpm_mode_e
{
    CPM_LTE0,
    CPM_LTE1,
    CPM_TDS,
    CPM_COMMON,
    CPM_1X,
    CPM_HRPD,
    BUTT_MODE,
    CPM_MAX = 10
}CPM_MODE_E;

typedef enum cpm_req_e
{
    IDLE_REQ = 0 /*0代表idle，允许dsp睡眠*/
                 /*非0代表busy，禁止dsp睡眠*/
}CPM_REQ_E;

typedef enum cpm_phy_state_e
{
    PHY_LOW_POWER_STATE = 0,
    PHY_NORMAL_STATE 
}CPM_PHY_STATE_E;
 
struct MasterAwakeSlaveFlag
{
    unsigned int SlaveAwakeFlag[MASTER_MODE_BUTT][SLAVE_MODE_BUTT];
};

struct DspDvsFlag
{
    unsigned int DspDvsReq;            /*bit0-bit7:BBP调压请求 01高压 00低压;bit8-bit15:BBE16调压请求 01高压 00低压;
                                         bit16-bit23:请求序列号(由BBE16产生);bit24-bit31:调压请求有效标志(0x55)*/
    unsigned int DspDvsReq_timestamp;   
    unsigned int DspDvsRespond;        /*bit0-bit7:BBP电压状态 01高压 00低压;bit8-bit15:BBE16电压状态 01高压 00低压;
                                         bit16-bit23:调压应答序列号(等于调压请求序列号);bit24-bit31:调压应答有效标志(0xAA)*/   
    unsigned int DspDvsRespond_timestamp;
    unsigned int ddr_freq;
};

typedef struct
{
    unsigned int ulLightSleepFlag;    /*DSP深睡浅睡的标志*/
    unsigned int ulTdsPreSfn;         /*DSP锁存的子贞号*/
    unsigned int ulRfTime;            /*RF稳定时间需要1ms*/
    unsigned int dspState;            /*DSP是睡眠还是醒，0:睡 1:醒*/
    unsigned int dspTime;             /*DSP对应着dspState打的时间戳*/ 
}RTT_SLEEP_INFO_STRU;

struct sleep_state_req
{
    unsigned int  mode_req[CPM_MAX];
    unsigned int  core_req[2];
    unsigned char dsp_state[CPM_MAX];  
    unsigned char core_state[2];
};

struct mst_awake_slv
{
    unsigned char awake_flag[PWC_COMM_MODEM_2][SLAVE_MODE_BUTT];
};

struct rtt_info
{
    unsigned int  rf_time[4];       /*成员[0]保存rfic0的tcrv_on的时间
                                      成员[1]保存rfic1的tcrv_on的时间
                                      成员[2]保存rfic2的tcrv_on的时间
                                      成员[3]保存rfic3的tcrv_on的时间 */                                    
};

typedef struct{
    RTT_SLEEP_INFO_STRU PstRttSleepInfo;     /* 由于物理层是通过首地址偏移方式使用该结构，所以如果要调整该结构及其内部成员顺序，请知会物理层同事 */
    struct DspDvsFlag DvsFlag;
    struct MasterAwakeSlaveFlag AwakeFlag;
    struct sleep_state_req   state_req;
    struct mst_awake_slv     mst_awake_slv;
    struct rtt_info          rtt_sleep_info;
    unsigned char dsp_wait_idle_flag;
    unsigned char reserve[3];
}SRAM_SOC_TLDSP_INTERACTION_STRU;

#ifdef __cplusplus
}
#endif
#endif
  

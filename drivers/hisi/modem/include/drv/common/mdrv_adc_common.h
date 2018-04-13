#ifndef __MDRV_ADC_COMMON_H__
#define __MDRV_ADC_COMMON_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*共享区域数据边界魔幻数*/
#define ADC_MAGIC_DATA (0x5A5A5A5A)

/* 支持的物理通道号列表 */
typedef enum ADC_CHANNEL_ID{
    ADC_CHANNEL_MIN = 0,                    /*0*/
    /**********HKADC**********/
    HKADC_CHANNEL_MIN = ADC_CHANNEL_MIN,    /*0*/
    HKADC_CHANNEL_0 = HKADC_CHANNEL_MIN,    /*0*/
    HKADC_CHANNEL_1,                        /*1*/
    HKADC_CHANNEL_2,                        /*2*/
    HKADC_CHANNEL_3,                        /*3*/
    HKADC_CHANNEL_4,                        /*4*/
    HKADC_CHANNEL_5,                        /*5*/
    HKADC_CHANNEL_6,                        /*6*/
    HKADC_CHANNEL_7,                        /*7*/
    HKADC_CHANNEL_8,                        /*8*/
    HKADC_CHANNEL_9,                        /*9*/
    HKADC_CHANNEL_10,                       /*10*/
    HKADC_CHANNEL_11,                       /*11*/
    HKADC_CHANNEL_12,                       /*12*/
    HKADC_CHANNEL_13,                       /*13*/
    HKADC_CHANNEL_14,                       /*14*/
    HKADC_CHANNEL_MAX,                      /*15*/
    /********HKADC END********/
    /**********XOADC**********/
    XOADC_CHANNEL_MIN = HKADC_CHANNEL_MAX,  /*15*/
    XOADC_CHANNEL_0 = XOADC_CHANNEL_MIN,    /*15*/
    XOADC_CHANNEL_MAX,                      /*16*/
    /********XOADC END********/
    ADC_CHANNEL_MAX = XOADC_CHANNEL_MAX,    /*16*/
    ADC_CHANNEL_NUM = ADC_CHANNEL_MAX,      /*16*/
} ADC_CHANNEL_ID;

typedef struct adc_data
{
    unsigned short code;       /*adc转换的码值*/
    unsigned short code_r;     /*adc转换的码值按位取反*/
    unsigned short voltage;    /*adc转换的电压值*/
    unsigned short voltage_r;  /*adc转换的电压值按位取反*/
} adc_data;

/* 共享区域数据排布结构体 */
typedef struct adc_data_shm
{
    unsigned int magic_start;   /*其值为ADC_MAGIC_DATA*/
    struct adc_data data[ADC_CHANNEL_NUM];
    unsigned int magic_end;     /*其值为ADC_MAGIC_DATA*/
} adc_data_shm;

/* 支持的逻辑通道号列表 */
typedef enum ADC_LOGIC_CHANNEL
{
    ADC_LOGIC_CHANNEL_MIN = 0,
    ADC_LOGIC_CHANNEL_BATTERY = 0,
    ADC_LOGIC_CHANNEL_PA0 = 1,
    ADC_LOGIC_CHANNEL_PA1 = 2,
    ADC_LOGIC_CHANNEL_XO  = 3,
    ADC_LOGIC_CHANNEL_PA2 = 4,
    ADC_LOGIC_CHANNEL_SIM_CARD = 8,
    ADC_LOGIC_CHANNEL_BAT_ET = 16,
    ADC_LOGIC_CHANNEL_MAX
} ADC_LOGIC_CHANNEL;

typedef enum ADC_GET_MODE
{
    ADC_GET_ICC = 0,            /*icc通信方式，实时获取*/
    ADC_GET_SHM,                /*共享区域方式，延时获取*/
} ADC_GET_MODE;

typedef struct adc_cvt
{
    unsigned short code;        /*adc转换的码值*/
    unsigned short voltage;     /*adc转换的电压值*/
    int            temperature; /*adc转换的温度值*/
} adc_cvt;

#ifdef __cplusplus
}
#endif

#endif


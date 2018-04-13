#ifndef __MDRV_ACORE_ADC_H__
#define __MDRV_ACORE_ADC_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "common/mdrv_adc_common.h"

/*******************************************************************************
* 函 数 名  : mdrv_adc_logic2phy
* 功能描述  : 将逻辑通道号转换为物理通道号。
* 输入参数  : logic_channel_id--逻辑通道号，其取值范围参见枚举变量ADC_LOGIC_CHANNEL，
*             取值区间[ADC_LOGIC_CHANNEL_XO, ADC_LOGIC_CHANNEL_MAX)，终端可根据具体
*             需求自行增加所支持的逻辑通道号。
* 输出参数  : 无
* 返 回 值  : < 0 时，表示函数执行失败。
*             >=0 时，表示函数执行成功，其值表示逻辑通道号所对应的物理通道号。
* 其它说明  : 当调用该函数失败时请打印该函数返回值，便于问题定位。
*******************************************************************************/
int mdrv_adc_logic2phy(ADC_LOGIC_CHANNEL logic_channel_id);

/*******************************************************************************
* 函 数 名  : mdrv_adc_get
* 功能描述  : 获取物理通道号为phy_channel_id的ADC转换码值、电压值、温度值。
* 输入参数  : phy_channel_id--物理通道号。
*             mode          --指定获取ADC转换码值、电压值、温度值的方式，其取值参见
*             枚举变量ADC_GET_MODE。
* 输出参数  : cvt           --用于向调用者返回ADC转换码值、电压值、温度值。
* 返 回 值  : 0 时，表示函数执行成功。
*             其他，表示函数执行失败。
* 其它说明  : 当调用该函数失败时请打印该函数返回值，便于问题定位。
*******************************************************************************/
int mdrv_adc_get(int phy_channel_id, ADC_GET_MODE mode, struct adc_cvt* cvt);

#ifdef __cplusplus
}
#endif

#endif


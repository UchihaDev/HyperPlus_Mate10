/*
 * vdec regulator manager
 *
 * Copyright (c) 2017 Hisilicon Limited
 *
 * Author: gaoyajun<gaoyajun@hisilicon.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation.
 *
 */
#include "omxvdec.h"
#include "regulator.h"
#include "platform.h"

#include <linux/hisi/hisi-iommu.h>
#include <linux/iommu.h>
#include <linux/platform_device.h>
#include <linux/regulator/consumer.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/of_address.h>
#include <linux/clk.h>

/*lint -e774*/
#define VDEC_REGULATOR_NAME     "ldo_vdec"
#define MEDIA_REGULATOR_NAME    "ldo_media"
#define VCODEC_CLOCK_NAME       "clk_vdec"
#define VCODEC_CLK_RATE         "dec_clk_rate"

static HI_U32  g_clock_values[] = {450000000, 300000000, 185000000};
static HI_U32  g_VdecClkRate_l  = 185000000;
static HI_U32  g_VdecClkRate_n  = 300000000;
static HI_U32  g_VdecClkRate_h  = 450000000;
static HI_U32  g_CurClkRate     = 0;
static HI_BOOL g_VdecPowerOn    = HI_FALSE;

static struct  clk          *g_PvdecClk        = HI_NULL;
static struct  regulator    *g_VdecRegulator   = HI_NULL;
static struct  regulator    *g_MediaRegulator  = HI_NULL;
static struct  iommu_domain *g_VdecSmmuDomain  = HI_NULL;

struct mutex g_RegulatorMutex;
static VFMW_DTS_CONFIG_S g_DtsConfig;

#ifdef HIVDEC_SMMU_SUPPORT

/*----------------------------------------
    func: iommu enable intf
 ----------------------------------------*/
static HI_S32 VDEC_Enable_Iommu(VOID)
{
	g_VdecSmmuDomain = hisi_ion_enable_iommu(NULL);

	return (g_VdecSmmuDomain == HI_NULL ? HI_FAILURE : HI_SUCCESS);
}

static HI_VOID VDEC_Disable_Iommu(VOID)
{
	g_VdecSmmuDomain = NULL;
}

static HI_U64 VDEC_GetSmmuBasePhy(VOID)
{
	struct iommu_domain_data *domain_data = HI_NULL;

	if (VDEC_Enable_Iommu() == HI_FAILURE)
		return 0;

	domain_data = (struct iommu_domain_data *)(g_VdecSmmuDomain->priv);

	return (HI_U64) (domain_data->phy_pgd_base);
}

#endif

static HI_S32 read_clock_rate_value(struct device_node *np, HI_U32 index, HI_U32 *clock)
{
	HI_S32 ret;
	ret = of_property_read_u32_index(np, VCODEC_CLK_RATE, index, clock);
	if (ret) {
		dprint(PRN_FATAL,"read clock rate[%d] failed\n", index);
		*clock = g_clock_values[index];
		return HI_FAILURE;
	}

	return HI_SUCCESS;
}

static HI_S32 VDEC_Init_ClockRate(struct device *dev)
{
	HI_S32 ret;
	struct clk *pvdec_clk  = HI_NULL;

	pvdec_clk = devm_clk_get(dev, VCODEC_CLOCK_NAME);
	if (IS_ERR_OR_NULL(pvdec_clk)) {
		dprint(PRN_FATAL, "%s can not get clock\n", __func__);
		return HI_FAILURE;
	}

	g_PvdecClk = pvdec_clk;
	ret  = read_clock_rate_value(dev->of_node, 0, &g_VdecClkRate_h);
	ret += read_clock_rate_value(dev->of_node, 1, &g_VdecClkRate_n);
	ret += read_clock_rate_value(dev->of_node, 2, &g_VdecClkRate_l);
	RETURN_FAIL_IF_COND_IS_TRUE(ret, "read clock failed");

	g_CurClkRate = g_VdecClkRate_l;

	return HI_SUCCESS;
}

static HI_S32 VDEC_GetDtsConfigInfo(struct device *dev, VFMW_DTS_CONFIG_S *pDtsConfig)
{
	HI_S32 ret;
	struct device_node *np_crg = HI_NULL;
	struct device_node *np     = dev->of_node;
	struct resource res;

	RETURN_FAIL_IF_COND_IS_TRUE(dev->of_node == HI_NULL, "device node is null");
	RETURN_FAIL_IF_COND_IS_TRUE(pDtsConfig == HI_NULL, "dts config is null");

	pDtsConfig->VdecIrqNumNorm = irq_of_parse_and_map(np, 0);
	RETURN_FAIL_IF_COND_IS_TRUE(pDtsConfig->VdecIrqNumNorm == 0, "get irq num failed");

	/*
	 FIXME irq_of_parse_and_map(np, 1);
	 FIXME irq_of_parse_and_map(np, 2);
	*/
	pDtsConfig->VdecIrqNumProt = 323;
	pDtsConfig->VdecIrqNumSafe = 324;

	/* Get reg base addr & size, return 0 if success */
	ret = of_address_to_resource(np, 0, &res);
	RETURN_FAIL_IF_COND_IS_TRUE(ret, "of_address_to_resource failed");

	pDtsConfig->VdhRegBaseAddr = res.start;
	pDtsConfig->VdhRegRange = resource_size(&res);

#ifdef HIVDEC_SMMU_SUPPORT
	/* Get reg base addr, return 0 if failed */
	pDtsConfig->SmmuPageBaseAddr = VDEC_GetSmmuBasePhy();
	RETURN_FAIL_IF_COND_IS_TRUE(pDtsConfig->SmmuPageBaseAddr == 0, "get smmu base addr failed");
#endif

	np_crg = of_find_compatible_node(HI_NULL, HI_NULL, "hisilicon,crgctrl");
	RETURN_FAIL_IF_COND_IS_TRUE(!np_crg, "can't find crgctrl node");

	ret = of_address_to_resource(np_crg, 0, &res);
	RETURN_FAIL_IF_COND_IS_TRUE(ret, "of_address_to_resource failed");
	pDtsConfig->PERICRG_RegBaseAddr = res.start;

	/*Check if is FPGA platform*/
	ret = of_property_read_u32(np, "vdec_fpga", &pDtsConfig->IsFPGA);
	if (ret) {
		pDtsConfig->IsFPGA = 0;
		dprint(PRN_ALWS, "current is not fpga\n");
	}

	ret = VDEC_Init_ClockRate(dev);
	RETURN_FAIL_IF_COND_IS_TRUE(ret != HI_SUCCESS, "init clock failed");

	return HI_SUCCESS;
}

/******************************** SHARE FUNC **********************************/

/*----------------------------------------
    func: regulator probe entry
 ----------------------------------------*/
HI_S32 VDEC_Regulator_Probe(struct device *dev)
{
	HI_S32 ret;

	g_VdecRegulator = HI_NULL;
	g_MediaRegulator = HI_NULL;

	if (dev == HI_NULL) {
		dprint(PRN_FATAL, "%s, invalid params", __func__);
		return HI_FAILURE;
	}

	g_MediaRegulator = devm_regulator_get(dev, MEDIA_REGULATOR_NAME);
	if (g_MediaRegulator == HI_NULL) {
		dprint(PRN_FATAL, "%s get media regulator failed\n", __func__);
		return HI_FAILURE;
	} else if (IS_ERR(g_MediaRegulator)) {
		dprint(PRN_FATAL, "%s get media regulator failed, error no :%ld\n", __func__, PTR_ERR(g_MediaRegulator));
		g_MediaRegulator = HI_NULL;
		return HI_FAILURE;
	}

	g_VdecRegulator = devm_regulator_get(dev, VDEC_REGULATOR_NAME);
	if (g_VdecRegulator == HI_NULL) {
		dprint(PRN_FATAL, "%s get regulator failed\n", __func__);
		return HI_FAILURE;
	} else if (IS_ERR(g_VdecRegulator)) {
		dprint(PRN_FATAL, "%s get regulator failed, error no :%ld\n", __func__, PTR_ERR(g_VdecRegulator));
		g_VdecRegulator = HI_NULL;
		return HI_FAILURE;
	}

	memset(&g_DtsConfig, 0, sizeof(g_DtsConfig)); /* unsafe_function_ignore: memset */
	ret = VDEC_GetDtsConfigInfo(dev, &g_DtsConfig);
	if (ret != HI_SUCCESS) {
		dprint(PRN_FATAL, "%s Regulator_GetDtsConfigInfo failed\n", __func__);
		return HI_FAILURE;
	}

	ret = VFMW_SetDtsConfig(&g_DtsConfig);
	if (ret != HI_SUCCESS) {
		dprint(PRN_FATAL, "%s VFMW_SetDtsConfig failed\n", __func__);
		return HI_FAILURE;
	}
	VDEC_INIT_MUTEX(&g_RegulatorMutex);

	return HI_SUCCESS;
}

/*----------------------------------------
    func: regulator deinitialize
 ----------------------------------------*/
HI_S32 VDEC_Regulator_Remove(struct device * dev)
{
	VDEC_MUTEX_LOCK(&g_RegulatorMutex);

	VDEC_Disable_Iommu();
	g_VdecRegulator = HI_NULL;
	g_MediaRegulator = HI_NULL;
	g_PvdecClk      = HI_NULL;

	VDEC_MUTEX_UNLOCK(&g_RegulatorMutex);

	return HI_SUCCESS;
}

/*----------------------------------------
    func: enable regulator
 ----------------------------------------*/
HI_S32 VDEC_Regulator_Enable(HI_VOID)
{
	HI_S32 ret;

	VDEC_MUTEX_LOCK(&g_RegulatorMutex);

	if (g_VdecPowerOn == HI_TRUE) {
		VDEC_MUTEX_UNLOCK(&g_RegulatorMutex);
		return HI_SUCCESS;
	}

	if (g_PvdecClk == HI_NULL) {
		dprint(PRN_FATAL, "%s: invalid g_PvdecClk is NULL\n", __func__);
		goto error_exit;
	}

	if (IS_ERR_OR_NULL(g_MediaRegulator)) {
		dprint(PRN_FATAL, "%s : g_MediaRegulator is NULL", __func__);
		goto error_exit;
	}

	if (IS_ERR_OR_NULL(g_VdecRegulator)) {
		dprint(PRN_FATAL, "%s : g_VdecRegulator is NULL", __func__);
		goto error_exit;
	}
	ret = regulator_enable(g_MediaRegulator);
	if (ret != 0) {
		dprint(PRN_FATAL, "%s enable media regulator failed\n", __func__);
		goto error_exit;
	}
	ret = clk_prepare_enable(g_PvdecClk);
	if (ret != 0) {
		dprint(PRN_FATAL, "%s clk_prepare_enable failed\n", __func__);
		goto error_regulator_disable;
	}
	ret  = clk_set_rate(g_PvdecClk, g_VdecClkRate_l);
	if (ret)
	{
		dprint(PRN_FATAL, "%s Failed to clk_set_rate:%u, return %d\n", __func__, g_VdecClkRate_l, ret);
		goto error_unprepare_clk;
	}
	ret = regulator_enable(g_VdecRegulator);
	if (ret != 0) {
		dprint(PRN_FATAL, "%s enable regulator failed\n", __func__);
		goto error_unprepare_clk;
	}

	dprint(PRN_ALWS, "vdec regulator enable\n");

	g_VdecPowerOn = HI_TRUE;

	VDEC_MUTEX_UNLOCK(&g_RegulatorMutex);

	return HI_SUCCESS;

error_unprepare_clk:
	clk_disable_unprepare(g_PvdecClk);

error_regulator_disable:
	if (regulator_disable(g_MediaRegulator))
		dprint(PRN_ALWS, "%s disable media regulator failed\n", __func__);
error_exit:
	VDEC_MUTEX_UNLOCK(&g_RegulatorMutex);

	return HI_FAILURE;
}

/*----------------------------------------
    func: disable regulator
 ----------------------------------------*/
HI_S32 VDEC_Regulator_Disable(HI_VOID)
{
	HI_S32 ret;

	VDEC_MUTEX_LOCK(&g_RegulatorMutex);

	if (g_VdecPowerOn == HI_FALSE) {
		VDEC_MUTEX_UNLOCK(&g_RegulatorMutex);
		return HI_SUCCESS;
	}

	if (g_PvdecClk == HI_NULL) {
		dprint(PRN_FATAL, "%s g_PvdecClk is NULL\n", __func__);
		goto error_exit;
	}

	if (IS_ERR_OR_NULL(g_MediaRegulator)) {
		dprint(PRN_FATAL, "%s : g_MediaRegulator is NULL", __func__);
		goto error_exit;
	}

	if (IS_ERR_OR_NULL(g_VdecRegulator)) {
		dprint(PRN_FATAL, "%s : g_VdecRegulator is NULL", __func__);
		goto error_exit;
	}

	ret = regulator_disable(g_VdecRegulator);
	if (ret != 0) {
		dprint(PRN_FATAL, "%s disable regulator failed\n", __func__);
	}

	ret = clk_set_rate(g_PvdecClk, g_VdecClkRate_l);
	if (ret) {
		dprint(PRN_FATAL, "%s Failed to clk_set_rate:%u, return %d\n", __func__, g_VdecClkRate_l, ret);
		//goto error_exit;//continue, no return
	}

	clk_disable_unprepare(g_PvdecClk);

	ret = regulator_disable(g_MediaRegulator);
	if (ret != 0) {
		dprint(PRN_FATAL, "%s disable media regulator failed\n", __func__);
		goto error_exit;
	}

	g_VdecPowerOn = HI_FALSE;

	dprint(PRN_ALWS, "vdec regulator disable\n");

	VDEC_MUTEX_UNLOCK(&g_RegulatorMutex);

	return HI_SUCCESS;

error_exit:
	VDEC_MUTEX_UNLOCK(&g_RegulatorMutex);

	return HI_FAILURE;
}

/*----------------------------------------
    func: get decoder clock rate
 ----------------------------------------*/
HI_S32 VDEC_Regulator_GetClkRate(CLK_RATE_E *pClkRate)
{
	VDEC_MUTEX_LOCK(&g_RegulatorMutex);

	if (g_CurClkRate == g_VdecClkRate_h) {
		*pClkRate = VDEC_CLK_RATE_HIGH;
	} else if (g_CurClkRate == g_VdecClkRate_n) {
		*pClkRate = VDEC_CLK_RATE_NORMAL;
	} else if (g_CurClkRate == g_VdecClkRate_l) {
		*pClkRate = VDEC_CLK_RATE_LOW;
	} else {
		dprint(PRN_ERROR, "%s: unkown clk rate %d, return VDEC_CLK_RATE_HIGH\n", __func__, g_CurClkRate);
		*pClkRate = VDEC_CLK_RATE_HIGH;
	}
	VDEC_MUTEX_UNLOCK(&g_RegulatorMutex);

	return HI_SUCCESS;
}

HI_S32 VDEC_Regulator_SetClkRate(CLK_RATE_E eClkRate)
{
	HI_S32 ret          = 0;
	HI_U32 rate         = 0;
	HI_U8 need_set_flag = 1;

	VDEC_MUTEX_LOCK(&g_RegulatorMutex);

	if (g_DtsConfig.IsFPGA) {
		VDEC_MUTEX_UNLOCK(&g_RegulatorMutex);
		return HI_SUCCESS;
	}

	if (IS_ERR_OR_NULL(g_PvdecClk)) {
		dprint(PRN_ERROR,  "Couldn't get clk [%s]\n", __func__);
		goto error_exit;
	}

	rate = (HI_U32) clk_get_rate(g_PvdecClk);
	switch (eClkRate) {
	case VDEC_CLK_RATE_LOW:
		if (g_VdecClkRate_l == rate) {
			need_set_flag = 0;
		} else {
			rate = g_VdecClkRate_l;
			need_set_flag = 1;
		}
		break;

	case VDEC_CLK_RATE_NORMAL:
		if (g_VdecClkRate_n == rate) {
			need_set_flag = 0;
		}
		else {
			rate = g_VdecClkRate_n;
			need_set_flag = 1;
		}
		break;

	case VDEC_CLK_RATE_HIGH:
		if (g_VdecClkRate_h == rate) {
			need_set_flag = 0;
		} else {
			rate = g_VdecClkRate_h;
			need_set_flag = 1;
		}
		break;

	default:
		dprint(PRN_ERROR,  "[%s] unsupport clk rate enum %d\n", __func__, eClkRate);
		goto error_exit;
	}

	if (need_set_flag == 1) {
		ret = clk_set_rate(g_PvdecClk, rate);
		if (ret != 0) {
			dprint(PRN_ERROR,  "Failed to clk_set_rate %u HZ[%s] ret : %d\n", rate, __func__, ret);
			goto error_exit;
		}
		g_CurClkRate = rate;
	}

	VDEC_MUTEX_UNLOCK(&g_RegulatorMutex);

	return HI_SUCCESS;

error_exit:
	VDEC_MUTEX_UNLOCK(&g_RegulatorMutex);

	return HI_FAILURE;
}

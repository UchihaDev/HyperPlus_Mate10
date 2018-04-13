/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/clk-provider.h>
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 13, 0))
#include <linux/clk-private.h>
#endif
#include <linux/clkdev.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/slab.h>
#include <linux/clk.h>
#include <soc_crgperiph_interface.h>
#include "hisi-clk-mailbox.h"
#include "clk-kirin-common.h"
#ifdef CONFIG_HISI_PERIDVFS
#include "dvfs/peri_volt_poll.h"
#endif
#define MAX_FREQ_NUM    	2
/*lint -e750 -esym(750,*) */
#define MAX_TRY_NUM    		40
/*lint -e750 +esym(750,*) */
#define MUX_SOURCE_NUM			4
#define DIV_MUX_DATA_LENGTH 	3
#define MUX_MAX_BIT					15
#define FOUR_BITS						0xf
#define NOUSE_READ_REG		0
#define FREQ_OFFSET_ADD		1000000 /*For 184.444M to 185M*/

#ifdef CONFIG_HISI_PERIDVFS
static DEFINE_MUTEX(dvfs_lock);
struct peri_dvfs_switch_up {
	struct work_struct		updata;
	struct clk			*clk;
	struct clk			*linkage;
	struct peri_volt_poll		*pvp;
	unsigned int			target_volt;
	unsigned long			target_freq;
	unsigned long			divider_rate;
	const char			*enable_pll_name;
};
#endif

struct peri_dvfs_clk {
	struct clk_hw			hw;
	void __iomem			*reg_base;	/* ctrl register */
	u32				id;
	unsigned long			freq_table[MAX_FREQ_NUM];
	u32				volt[MAX_FREQ_NUM];
	const char 			*link;
	unsigned long			rate;
	unsigned long			sensitive_freq[DVFS_MAX_FREQ_NUM];
	unsigned int			sensitive_volt[DVFS_MAX_VOLT_NUM];
	u32					sensitive_level;
	u32					block_mode;
	u32					div;
	u32					div_bits;
	u32					div_bits_offset;
	u32					mux;
	u32					mux_bits;
	u32					recal_mode;
	u32					divider;/*sw clock need to div 2 or 3 when set_rate*/
	/*whether need to enable pll before set rate when clk is enabled*/
	const char			*enable_pll_name;
	u32					mux_bits_offset;
	const char			**parent_names;
#ifdef CONFIG_HISI_PERIDVFS
	struct peri_dvfs_switch_up sw_up;
#endif
};

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 13, 0))
extern int __clk_prepare(struct clk *clk);
extern void __clk_unprepare(struct clk *clk);
#else
extern int clk_core_prepare(struct clk_core *clk_core);
extern void clk_core_unprepare(struct clk_core *clk_core);
#endif
extern int clk_set_rate_nolock(struct clk *clk, unsigned long rate);
extern int clk_get_rate_nolock(struct clk *clk);
extern int __clk_enable(struct clk *clk);
extern void __clk_disable(struct clk *clk);
extern int IS_FPGA(void);

#ifdef CONFIG_HISI_PERIDVFS
static int peri_dvfs_set_rate_nolock(struct clk *friend_clk, unsigned long divider_rate, unsigned long rate, unsigned int dev_id)
{
	int ret = 0;
	/*rate div 2 or 3 for SW switch high freq problem*/
	ret = clk_set_rate_nolock(friend_clk, divider_rate);
	if (ret < 0)
		pr_err("[%s]set half rate failed in set rate, ret = %d, poll id = %d, divider_rate = %lu!\n", __func__, ret, dev_id, divider_rate);
	ret = clk_set_rate_nolock(friend_clk, rate);
	if (ret < 0)
		pr_err("[%s] fail to updata rate, ret = %d!\n", __func__, ret);
	return ret;
}

static int peri_dvfs_set_rate_lock(struct clk *friend_clk, unsigned long divider_rate, unsigned long rate, unsigned int dev_id)
{
	int ret = 0;
	/*rate div 2 or 3 for SW switch high freq problem*/
	ret = clk_set_rate(friend_clk, divider_rate);
	if (ret < 0)
		pr_err("[%s]set half rate failed in set rate, ret = %d, poll id = %d, divider_rate = %lu!\n", __func__, ret, dev_id, divider_rate);
	ret = clk_set_rate(friend_clk, rate);
	if (ret < 0)
		pr_err("[%s] set linkage failed, ret = %d!\n", __func__, ret);
	return ret;
}

/* func: async dvfs func
*/
static int dvfs_block_func(struct peri_volt_poll *pvp, u32 volt)
{
	unsigned int volt_get = 0;
	int loop = PERI_AVS_LOOP_MAX;
	int ret = 0;
	if (!pvp) {
		pr_err("[%s]pvp get failed!\n", __func__);
		return -EINVAL;
	}

	do {
		volt_get = peri_get_volt(pvp);
		if(volt_get > DVFS_MAX_VOLT_NUM){
			pr_err("[%s]get volt illegal volt=%d!\n", __func__, volt_get);
			return -EINVAL;
		}
		if (volt_get < volt) {
			loop--;
			usleep_range(1500, 3000);
		}
	} while (volt_get < volt && loop > 0);
	if (volt_get < volt) {
		pr_err("[%s]schedule up volt failed, volt_get = %d, target_volt = %d!\n", __func__, volt_get, volt);
	}
	return ret;
}

static void updata_freq_volt_up_fn(struct work_struct *work)
{
	struct peri_dvfs_switch_up *sw = container_of(work, struct peri_dvfs_switch_up, updata);
	int ret = 0;
	unsigned long freq_old = 0;
	unsigned long target_freq = 0;
	unsigned int target_volt = 0;
	unsigned long divider_rate = 0;
	const char *enable_pll_name;
	struct peri_volt_poll *pvp;
	struct clk *friend_clk;
	struct clk *ppll_ap;
	mutex_lock(&dvfs_lock);
	pvp = sw->pvp;
	friend_clk = sw->linkage;
	target_freq = sw->target_freq;
	target_volt = sw->target_volt;
	divider_rate = sw->divider_rate;
	enable_pll_name = sw->enable_pll_name;
	mutex_unlock(&dvfs_lock);

	if(enable_pll_name){
		ppll_ap = clk_get(NULL, enable_pll_name);
		if (IS_ERR_OR_NULL(ppll_ap))
		{
			pr_err("[%s]cannot get ppll ap clock!", __func__);
			return;
		}
		ret = clk_prepare_enable(ppll_ap);
		if (ret != 0)
		{
			pr_err("[%s]prepare enable ppll clock fail!\n", __func__);
			goto err_dvfs;
		}
	}
	freq_old = clk_get_rate(friend_clk);
	/*rasing rate first set volt ,then set rate  and droping rate first set rate ,then set volt!*/
	if(target_freq > freq_old){
		ret = peri_set_volt(pvp, target_volt);
		if (ret < 0) {
			pr_err("[%s]set volt failed ret=%d!\n", __func__, ret);
			goto err_clk_unprepare;
		}
		ret = dvfs_block_func(pvp, target_volt);
		if(0 != ret)
			goto err_clk_unprepare;
		else{
			/*rate div 2 or 3 for SW switch high freq problem*/
			ret = peri_dvfs_set_rate_lock(friend_clk, divider_rate, target_freq, pvp->dev_id);
			if(ret < 0)
				pr_err("[%s]fail to updata rate int rasing rate, ret = %d!\n", __func__, ret);
		}
	}else{
		ret = peri_dvfs_set_rate_lock(friend_clk, divider_rate, target_freq, pvp->dev_id);
		if(ret < 0){
			pr_err("[%s]fail to updata rate in droping rate, ret = %d!\n", __func__, ret);
			goto err_clk_unprepare;
		}
		ret = peri_set_volt(pvp, target_volt);
		if (ret < 0) {
			pr_err("[%s]set volt failed ret=%d in droping volt!\n", __func__, ret);
			ret = clk_set_rate(friend_clk, freq_old);
			if (ret < 0)
				pr_err("[%s] fail to reback async, ret = %d!\n", __func__, ret);
		}
	}

err_clk_unprepare:
	if(enable_pll_name){
		clk_disable_unprepare(ppll_ap);//lint !e644
	}
err_dvfs:
	if(enable_pll_name){
		clk_put(ppll_ap);
	}
}
#endif

static long peri_dvfs_clk_round_rate(struct clk_hw *hw, unsigned long rate,
				     unsigned long *prate)
{
	return rate;
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 13, 0))
static long peri_dvfs_clk_determine_rate(struct clk_hw *hw, unsigned long rate,
					unsigned long *best_parent_rate,
					struct clk **best_parent_clk)
{
	return rate;
}
#elif (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 4, 0))
static int peri_dvfs_clk_determine_rate(struct clk_hw *hw,
			     struct clk_rate_request *req)
{
	return 0;
}
#else
static long peri_dvfs_clk_determine_rate(struct clk_hw *hw, unsigned long rate,
					unsigned long min_rate, unsigned long max_rate,
					unsigned long *best_parent_rate, struct clk_hw **best_parent_hw)
{
	return rate;
}
#endif

/* func: get cur freq
*/
static unsigned long peri_dvfs_clk_recalc_rate(struct clk_hw *hw,
					       unsigned long parent_rate)
{
	struct peri_dvfs_clk *dfclk = container_of(hw, struct peri_dvfs_clk, hw);
	struct clk *ppll;
	struct clk *clk_friend;
	const char *source_name;
	const char *clk_name;
	u32 rate = 0;
	u32 ppll_rate;
	u32 value = 0;
	u32 mux_value = 0;
	u32 div_value = 0;
	int ret;

	clk_friend = __clk_lookup(dfclk->link);
	if (IS_ERR_OR_NULL(clk_friend)) {
		pr_err("[%s] %s get failed!\n", __func__, dfclk->link);
		return -ENODEV;//lint !e570
	}
	clk_name = __clk_get_name(hw->clk);
	if(IS_ERR_OR_NULL(clk_name)){
		pr_err("[%s] clk name get failed!\n", __func__);
		return -ENODEV;//lint !e570
	}
	if(NOUSE_READ_REG == dfclk->recal_mode){
		rate = clk_get_rate(clk_friend);
		return rate;
	}
	value = (unsigned int)readl(dfclk->reg_base + dfclk->div);
	div_value = ((value & dfclk->div_bits) >> dfclk->div_bits_offset) + 1;/*lint !e838 */

	value = (unsigned int)readl(dfclk->reg_base + dfclk->mux);
	mux_value = (value & dfclk->mux_bits) >> dfclk->mux_bits_offset;/*lint !e838 */
	/*
	 * MUX may have 2-bits or 4-bits or others
	 * if MUX has 2-bits(00/01/10/11), the index is the mux's value
	 * if MUX has 4-bits(0001/0010/0100/1000), the index should divide 2
	 */
	if(FOUR_BITS == (dfclk->mux_bits >> dfclk->mux_bits_offset)) {
		mux_value = mux_value / 2;
		if(4 == mux_value)
			mux_value = 3;
	}

	source_name = dfclk->parent_names[mux_value];
	if(0 == strncmp(source_name, "clk_ppll1", sizeof("clk_ppll1"))) {
		pr_err("%s: vdec chose the wrong ppll: ppll1\n", __func__);
		return -ENODEV;/*lint !e570 */
	}
	ppll = __clk_lookup(source_name);
	if (IS_ERR_OR_NULL(ppll)) {
		pr_err("[%s] %s get failed!\n", __func__, source_name);
		return -ENODEV;/*lint !e570 */
	}
	ppll_rate = __clk_get_rate(ppll);
	rate = ppll_rate/div_value;
	dfclk->rate = rate;


	ret = clk_set_rate_nolock(clk_friend, rate);
	if (ret < 0)
		pr_err("[%s]set friend failed, ret = %d!\n", __func__, ret);

	return rate;
}

#ifdef CONFIG_HISI_PERIDVFS
static int peri_dvfs_set(struct peri_dvfs_clk *dfclk, unsigned long rate, unsigned int volt)
{
	struct peri_volt_poll *pvp = NULL;
	int ret = 0;
	unsigned long divider_rate = rate;
	unsigned long freq_old = 0;
	struct clk *friend_clk;
	const char *enable_pll_name;

	friend_clk = __clk_lookup(dfclk->link);
	if (IS_ERR_OR_NULL(friend_clk)) {
		pr_err("[%s] %s get failed!\n", __func__, dfclk->link);
		return -ENODEV;
	}
	enable_pll_name = dfclk->enable_pll_name;
	pvp = peri_volt_poll_get(dfclk->id, NULL);
	if (!pvp) {
		pr_err("[%s]pvp get failed!\n", __func__);
		return -EINVAL;
	}

	freq_old = clk_get_rate(friend_clk);
	if (!freq_old)
		pr_err("[%s]soft rate: must not be 0,please check!\n", __func__);
	else{
		if(dfclk->divider)
			divider_rate = freq_old/dfclk->divider;
		if(dfclk->divider && (freq_old % dfclk->divider))
			divider_rate = divider_rate + FREQ_OFFSET_ADD; 	/*Example:For 184.444M to 185M*/
	}
/*1、非阻塞方式直接起work执行;解决非阻塞方式频率和电压不匹配的问题；
   2、阻塞方式需要判断是升频还是降频
   	升频：先升压，后设频；
	降频：先降频，再设压*/

	/*unblock mode*/
	if(HS_UNBLOCK_MODE == dfclk->block_mode){
		/*rasing or dropping rate and volt*/
		mutex_lock(&dvfs_lock);
		dfclk->sw_up.target_freq = rate;
		dfclk->sw_up.target_volt = volt;
		dfclk->sw_up.pvp = pvp;
		dfclk->sw_up.linkage = friend_clk;
		dfclk->sw_up.divider_rate = divider_rate;
		dfclk->sw_up.enable_pll_name = enable_pll_name;
		mutex_unlock(&dvfs_lock);
		schedule_work(&dfclk->sw_up.updata);
	}else{
		//block mode
		if(rate > freq_old){
			ret = peri_set_volt(pvp, volt);
			if (ret < 0) {
				pr_err("[%s]set volt failed ret=%d!\n", __func__, ret);
				return ret;
			}
			ret = dvfs_block_func(pvp, volt);
			if(0 != ret)
				return -EINVAL;
			else{
				ret = peri_dvfs_set_rate_nolock(friend_clk, divider_rate, rate, pvp->dev_id);
				if (ret < 0)
					return ret;
			}
		}else{
			ret = peri_dvfs_set_rate_nolock(friend_clk, divider_rate, rate, pvp->dev_id);
			if (ret < 0)
				return ret;
			ret = peri_set_volt(pvp, volt);
			if (ret < 0) {
				pr_err("[%s]set volt failed ret=%d!\n", __func__, ret);
				ret = clk_set_rate_nolock(friend_clk, freq_old);
				if (ret < 0)
					pr_err("[%s] fail to reback, ret = %d!\n", __func__, ret);
				return ret;
			}
		}
	}
	return ret;
}
#endif

/*func: dvfs set rate main func*/
static int peri_dvfs_clk_set_rate(struct clk_hw *hw, unsigned long rate,
				  unsigned long parent_rate)
{
	struct peri_dvfs_clk *dfclk = container_of(hw, struct peri_dvfs_clk, hw);
#ifdef CONFIG_HISI_PERIDVFS
	unsigned int i = 0;
	unsigned int level = dfclk->sensitive_level;
#endif
	struct clk *friend_clk;
	int ret = 0;

	friend_clk = __clk_lookup(dfclk->link);
	if (IS_ERR_OR_NULL(friend_clk)) {
		pr_err("[%s] %s get failed!\n", __func__, dfclk->link);
		return -ENODEV;
	}
#ifndef CONFIG_HISI_PERIDVFS
	ret = clk_set_rate_nolock(friend_clk, rate);
	if (ret < 0) {
		pr_err("[%s] fail to set rate, ret = %d, %d!\n",
						__func__, ret, __LINE__);
	}
#else
	if (__clk_is_enabled(friend_clk) == false) {
		ret = clk_set_rate_nolock(friend_clk, rate);
		if (ret < 0)
			pr_err("[%s] fail to set rate, ret = %d, %d!\n",
						__func__, ret, __LINE__);
		goto now;
	}

	for(i = 0; i < level; i++){
		if(rate > dfclk->sensitive_freq[i] * 1000)//lint !e574
			continue;
		else{
			ret = peri_dvfs_set(dfclk, rate, dfclk->sensitive_volt[i]);
			if(ret < 0){
				pr_err("[%s]pvp set volt failed ret =%d!\n", __func__, ret);
			}
			return ret;
		}
	}
	if( i == level){
		ret = peri_dvfs_set(dfclk, rate, dfclk->sensitive_volt[i]);
		if(ret < 0){
			pr_err("[%s]pvp set volt failed ret =%d!\n", __func__, ret);
		}
	}
now:
#endif
	dfclk->rate = rate;
	return ret;
}

#ifdef CONFIG_HISI_PERIDVFS
static int peri_volt_change(u32 id, u32 volt)
{
	struct peri_volt_poll *pvp = NULL;
	int ret = 0;

	pvp = peri_volt_poll_get(id, NULL);
	if (!pvp) {
		pr_err("[%s]pvp get failed!\n", __func__);
		return -EINVAL;
	}
	ret = peri_set_volt(pvp, volt);
	if (ret < 0) {
		pr_err("[%s]set volt failed ret=%u!\n", __func__, ret);
		return ret;
	}
	ret = dvfs_block_func(pvp, volt);
	return ret;
}
static int hisi_peri_dvfs_prepare(struct peri_dvfs_clk *pclk)
{
	unsigned long cur_rate = 0;
	int ret = 0;
	unsigned int i = 0;
	unsigned int level = pclk->sensitive_level;

	if(pclk->sensitive_freq[0] > 0){
		cur_rate = clk_get_rate(pclk->hw.clk);
		if (!cur_rate)
			pr_err("[%s]soft rate: must not be 0,please check!\n", __func__);

		for(i = 0; i < level; i++){
			if(cur_rate > pclk->sensitive_freq[i] * 1000)
				continue;
			else{
				ret = peri_volt_change(pclk->id, pclk->sensitive_volt[i]);
				if(ret < 0){
					pr_err("[%s]pvp set volt failed ret =%d!\n", __func__, ret);
				}
				return ret;
			}
		}
		if( i == level){
			ret = peri_volt_change(pclk->id, pclk->sensitive_volt[i]);
			if(ret < 0){
				pr_err("[%s]pvp set volt failed ret =%d!\n", __func__, ret);
			}
		}
	}else if(0 == pclk->sensitive_freq[0]){
		ret = peri_volt_change(pclk->id, pclk->sensitive_volt[level]);
		if(ret < 0){
			pr_err("[%s]pvp up volt failed ret =%d!\n", __func__, ret);
		}
	}else{
		pr_err("[%s]soft level: freq must not be less than 0,please check!\n", __func__);
	}
	return ret;
}

static void hisi_peri_dvfs_unprepare(struct peri_dvfs_clk *pclk)
{
	int ret = 0;
	ret = peri_volt_change(pclk->id, PERI_VOLT_0);
	if(ret < 0){
		pr_err("[%s]peri volt change failed ret =%d!\n", __func__, ret);
	}
}
#endif

static int peri_dvfs_clk_prepare(struct clk_hw *hw)
{
	struct peri_dvfs_clk *dfclk = container_of(hw, struct peri_dvfs_clk, hw);
	struct clk *friend_clk;
	int ret = 0;

	friend_clk = __clk_lookup(dfclk->link);
	if (IS_ERR_OR_NULL(friend_clk)) {
		pr_err("[%s] %s get failed!\n", __func__, dfclk->link);
		return -ENODEV;
	}
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 13, 0))
	ret = __clk_prepare(friend_clk);
#else
	ret = clk_core_prepare(friend_clk->core);
#endif
	if (ret) {
		pr_err("[%s], friend clock prepare faild!", __func__);
		return ret;
	}
#ifdef CONFIG_HISI_PERIDVFS
	ret = hisi_peri_dvfs_prepare(dfclk);
#endif
	return ret;
}

/*func: dvfs clk enable func
*/
static int peri_dvfs_clk_enable(struct clk_hw *hw)
{
	struct peri_dvfs_clk *dfclk = container_of(hw, struct peri_dvfs_clk, hw);
	struct clk *friend_clk;
	int ret = 0;

	friend_clk = __clk_lookup(dfclk->link);
	if (IS_ERR_OR_NULL(friend_clk)) {
		pr_err("[%s] %s get failed!\n", __func__, dfclk->link);
		return -ENODEV;
	}
	ret = __clk_enable(friend_clk);
	if (ret) {
		pr_err("[%s], friend clock enable faild!", __func__);
		return ret;
	}
	return ret;
}

/*func: dvfs clk disable func
*/
static void peri_dvfs_clk_disable(struct clk_hw *hw)
{
	struct peri_dvfs_clk *dfclk = container_of(hw, struct peri_dvfs_clk, hw);
	struct clk *friend_clk;

	friend_clk = __clk_lookup(dfclk->link);
	if (IS_ERR_OR_NULL(friend_clk))
		pr_err("[%s] %s get failed!\n", __func__, dfclk->link);
	__clk_disable(friend_clk);
}

static void peri_dvfs_clk_unprepare(struct clk_hw *hw)
{
	struct peri_dvfs_clk *dfclk = container_of(hw, struct peri_dvfs_clk, hw);
	struct clk *friend_clk;

	friend_clk = __clk_lookup(dfclk->link);
	if (IS_ERR_OR_NULL(friend_clk)) {
		pr_err("[%s] %s get failed!\n", __func__, dfclk->link);
        return;
    }
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 13, 0))
	__clk_unprepare(friend_clk);
#else
	clk_core_unprepare(friend_clk->core);
#endif

#ifdef CONFIG_HISI_PERIDVFS
	hisi_peri_dvfs_unprepare(dfclk);
#endif
	return;
}

static struct clk_ops peri_dvfs_clk_ops = {
	.recalc_rate	= peri_dvfs_clk_recalc_rate,
	.set_rate	= peri_dvfs_clk_set_rate,
	.determine_rate = peri_dvfs_clk_determine_rate,
	.round_rate	= peri_dvfs_clk_round_rate,
	.prepare	= peri_dvfs_clk_prepare,
	.unprepare	= peri_dvfs_clk_unprepare,
	.enable		= peri_dvfs_clk_enable,
	.disable	= peri_dvfs_clk_disable,
};

/*
 *.setup is for vdec or edc
 */

static void __init hisi_peri_dvfs_clk_setup(struct device_node *np)
{
	struct clk *clk;
	const char *clk_name, *clk_friend, *enable_pll_name;
	const char		**parent_names;
	struct clk_init_data *init;
	struct peri_dvfs_clk *devfreq_clk;
	int i = 0;
	u32 device_id = 0;
	u32 sensitive_freq[DVFS_MAX_FREQ_NUM] = {0};
	u32 sensitive_volt[DVFS_MAX_VOLT_NUM] = {0};
	u32 sensitive_level = 0;
	u32 block_mode = 0;
	u32 recal_mode = 0;
	u32 divider = 0;

	unsigned int base_addr_type = HS_CRGCTRL;
	void __iomem *reg_base;
	u32 data[3] = {0};
	unsigned long data_length;
	int ret;

	if (of_property_read_u32(np, "hisilicon,clk-recal-rate", &recal_mode)) {
		pr_err("[%s] node %s doesn't have clk-recal-rate property!\n",
			__func__, np->name);
		goto err_prop;
	}

	if (of_property_read_string(np, "clock-output-names", &clk_name)) {
		pr_err("[%s] node %s doesn't have clock-output-names property!\n",
			__func__, np->name);
		goto err_prop;
	}
	if (of_property_read_u32(np, "hisilicon,clk-devfreq-id", &device_id)) {
		pr_err("[%s] node %s doesn't have clk-devfreq-id property!\n",
			__func__, np->name);
		goto err_prop;
	}
	if (of_property_read_u32(np, "hisilicon,clk-dvfs-level", &sensitive_level)) {
		pr_err("[%s] node %s doesn't have clk-dvfs-level property!\n",
			__func__, np->name);
		goto err_prop;
	}
	if(sensitive_level > DVFS_MAX_FREQ_NUM){
		pr_err("[%s] sensitive level can not bigger than DVFS_MAX_FREQ_NUM!\n",
			__func__);
		goto err_prop;
	}
	if (of_property_read_u32(np, "hisilicon,clk-block-mode", &block_mode)) {
		pr_err("[%s] node %s doesn't have clk-block-mode property!\n",
			__func__, np->name);
		goto err_prop;
	}
	if (of_property_read_string(np, "clock-friend-names", &clk_friend))
		clk_friend = NULL;
	if (of_property_read_u32(np, "hisilicon,set_divider_rate", &divider))
		divider = 0;
	if (of_property_read_string(np, "hisilicon,enable_pll_names", &enable_pll_name))
		enable_pll_name = NULL;
	devfreq_clk = kzalloc(sizeof(struct peri_dvfs_clk), GFP_KERNEL);
	if (!devfreq_clk) {
		pr_err("[%s] fail to alloc devfreq_clk!\n", __func__);
		goto err_prop;
	}
	init = kzalloc(sizeof(struct clk_init_data), GFP_KERNEL);
	if (!init) {
		pr_err("[%s] fail to alloc init!\n", __func__);
		goto err_init;
	}
	init->name = kstrdup(clk_name, GFP_KERNEL);
	init->ops = &peri_dvfs_clk_ops;
	init->parent_names = NULL;
	init->num_parents = 0;
	init->flags = CLK_IS_ROOT | CLK_GET_RATE_NOCACHE;

	if (of_property_read_u32_array(np, "hisilicon,sensitive-freq", &sensitive_freq[0], sensitive_level)) {
		pr_err("[%s] node %s doesn't have sensitive-freq property!\n", __func__, np->name);
		goto err_clk;
	}
	if (of_property_read_u32_array(np, "hisilicon,sensitive-volt", &sensitive_volt[0], sensitive_level+1)) {
		pr_err("[%s] node %s doesn't have sensitive-volt property!\n", __func__, np->name);
		goto err_clk;
	}
	parent_names = kzalloc(sizeof(char *) * MUX_SOURCE_NUM, GFP_KERNEL);
	if (!parent_names) {
		pr_err("[%s] fail to alloc parent_names!\n", __func__);
		goto err_clk;
	}

	if(1 == recal_mode){
		if (of_property_read_u32(np, "base_addr_type", &base_addr_type)) {
			pr_err("[%s] %s node doesn't have crgctrl property!\n", __func__, np->name);
			goto err_parent_name;
		}
		data_length = MUX_SOURCE_NUM;
		if ((ret = of_property_read_string_array(np, "mux-table", parent_names, data_length)) < 0) {
			pr_err("[%s] Failed : of_property_read_string_array.%d\n", __func__, ret);
			goto err_parent_name;
		}
		devfreq_clk->parent_names = parent_names;
		data_length = DIV_MUX_DATA_LENGTH;
		if (of_property_read_u32_array(np, "div-reg", &data[0], data_length)) {
			pr_err("[%s] node have no div-reg\n", __func__);
			goto err_parent_name;
		}
		devfreq_clk->div = data[0];
		devfreq_clk->div_bits = data[1];
		devfreq_clk->div_bits_offset = data[2];

		if (of_property_read_u32_array(np, "mux-reg", &data[0], data_length)) {
			pr_err("[%s] node have no mux-reg\n", __func__);
			goto err_parent_name;
		}
		devfreq_clk->mux = data[0];
		devfreq_clk->mux_bits = data[1];
		devfreq_clk->mux_bits_offset = data[2];
	}
	reg_base = hs_clk_base(base_addr_type);
	if (!reg_base) {
		pr_err("[%s] fail to get reg_base!\n", __func__);
		goto err_parent_name;
	}
	devfreq_clk->hw.init = init;
	devfreq_clk->id = device_id;
	devfreq_clk->sensitive_level = sensitive_level;
	devfreq_clk->block_mode= block_mode;
	devfreq_clk->link = clk_friend;
	devfreq_clk->reg_base = reg_base;
	devfreq_clk->rate = 0;
	devfreq_clk->recal_mode = recal_mode;
	devfreq_clk->divider = divider;
	devfreq_clk->enable_pll_name = enable_pll_name;

	for (i = 0; i < DVFS_MAX_FREQ_NUM; i++){
		devfreq_clk->sensitive_freq[i] = sensitive_freq[i];
		devfreq_clk->sensitive_volt[i] = sensitive_volt[i];
	}
	devfreq_clk->sensitive_volt[i] = sensitive_volt[i];

	clk = clk_register(NULL, &devfreq_clk->hw);
	if (IS_ERR(clk)) {
		pr_err("[%s] fail to register devfreq_clk %s!\n",
				__func__, clk_name);
		goto err_parent_name;
	}
#ifdef CONFIG_HISI_PERIDVFS
	INIT_WORK(&devfreq_clk->sw_up.updata, updata_freq_volt_up_fn);
#endif
	of_clk_add_provider(np, of_clk_src_simple_get, clk);
	clk_register_clkdev(clk, clk_name, NULL);
	return;/*lint !e429 !e593 */

err_parent_name:
	kfree(parent_names);
	parent_names = NULL;
err_clk:
	kfree(init);
	init = NULL;
err_init:
	kfree(devfreq_clk);
	devfreq_clk = NULL;
err_prop:
	return;
}

CLK_OF_DECLARE(hisi_peri_dvfs, "hisilicon,clkdev-dvfs", hisi_peri_dvfs_clk_setup);/*lint !e611 */

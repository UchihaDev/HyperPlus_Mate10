#include <linux/errno.h>
#include <linux/wakelock.h>
#include <linux/clk-provider.h>
#include "ipu_clock.h"

/* this func use mutex, for interface only, and SHOULD NOT be called by other ipu_clock functions */
int ipu_clock_init(struct device *dev, struct ics_clock *clk)
{
	int ret;

	mutex_lock(&clk->clk_mutex);

	/* get clock of "clk-ics" from CLK API */
	clk->ipu_clk_ptr = devm_clk_get(dev, "clk-ics");
	clk->vcodecbus_clk_ptr = devm_clk_get(dev, "clk_vcodecbus");
	clk->vote_high_volt = devm_clk_get(dev, "ics_volt_high");
	clk->vote_normal_volt = devm_clk_get(dev, "ics_volt_middle");

	if (IS_ERR_OR_NULL(clk->ipu_clk_ptr)) {
		printk(KERN_ERR"[%s]: IPU_ERROR:get clock failed, ipu_clk_ptr is %pK\n", __func__, clk->ipu_clk_ptr);
		mutex_unlock(&clk->clk_mutex);
		return -ENODEV;
	}

	if (IS_ERR_OR_NULL(clk->vcodecbus_clk_ptr)) {
		printk(KERN_ERR"[%s]: IPU_ERROR:get clock failed, vcodecbus_clk_ptr is %pK\n", __func__, clk->vcodecbus_clk_ptr);
		mutex_unlock(&clk->clk_mutex);
		return -ENODEV;
	}

	if (IS_ERR_OR_NULL(clk->vote_high_volt)) {
		/* not return here when error occured, because this clock is non-essential, check it before use */
		printk(KERN_ERR"[%s]: IPU_ERROR:get clock failed, vote_high_ptr is %pK\n", __func__, clk->vote_high_volt);
	}

	if (IS_ERR_OR_NULL(clk->vote_normal_volt)) {
		/* not return here when error occured, because this clock is non-essential, check it before use */
		printk(KERN_ERR"[%s]: IPU_ERROR:get clock failed, vote_normal_ptr is %pK\n", __func__, clk->vote_normal_volt);
	}

	/* read start clock rate from dtsi by "ics-clk-start-rate" */
	ret = of_property_read_u32(dev->of_node, "ics-clk-start-rate", &clk->start_rate); /*lint -save -e838*/
	if (ret) {
		printk(KERN_ERR"[%s]: IPU_ERROR:get start rate failed, ret:%d\n", __func__, ret);
		mutex_unlock(&clk->clk_mutex);
		return -ENODEV;
	}

	/* read stop clock rate from dtsi by "ics-clk-stop-rate" */
	ret = of_property_read_u32(dev->of_node, "ics-clk-stop-rate", &clk->stop_rate); /*lint -save -e838*/
	if (ret) {
		printk(KERN_ERR"[%s]: IPU_ERROR:get stop rate failed, ret:%d\n", __func__, ret);
		mutex_unlock(&clk->clk_mutex);
		return -ENODEV;
	}

	printk(KERN_DEBUG"[%s]: get clk rate done, start clk rate:%u, stop clk rate:%u\n",
		__func__, clk->start_rate, clk->stop_rate);

	clk->curr_rate = IPU_CLOCK_UNSET;
	mutex_unlock(&clk->clk_mutex);
	return ret;
}

/* this func use mutex, for interface only, and SHOULD NOT be called by other ipu_clock functions */
int ipu_vote_peri(struct ics_clock *clk)
{
	int ret = 0;

	if (IPU_CLOCK_HIGH == clk->voted_peri_volt || IPU_CLOCK_NORMAL == clk->voted_peri_volt) {
		printk(KERN_ERR"[%s]: IPU_ERROR:ipu has already voted peri voltage: %d, ignore\n",
			__func__, clk->voted_peri_volt);
		return -EBUSY;
	}

	/* to vote PERI by "clk start rate", which is configed by:
	(1) read from DTSI when system start;
	(2) set by user using IOCTL */
	if (IPU_CLOCK_HIGH == clk->start_rate) {
		printk(KERN_DEBUG"[%s]: vote buck0 HIGH voltage\n", __func__);

		if (IS_ERR_OR_NULL(clk->vote_high_volt)) {
			printk(KERN_ERR"[%s]: IPU_ERROR:get clock failed, vote_high_volt is %pK\n", __func__, clk->vote_high_volt);
			return -EBUSY;
		}
		ret = clk_prepare_enable(clk->vote_high_volt);

		if (0 == ret) {
			clk->voted_peri_volt = IPU_CLOCK_HIGH;
		} else {
			printk(KERN_ERR"[%s]: IPU_ERROR:clk prepare enable for peri-HIGH failed,ret=%d\n", __func__, ret);
		}

	} else if (IPU_CLOCK_NORMAL == clk->start_rate) {
		printk(KERN_DEBUG"[%s]: vote buck0 MIDDLE voltage\n", __func__);

		if (IS_ERR_OR_NULL(clk->vote_normal_volt)) {
			printk(KERN_ERR"[%s]: IPU_ERROR:get clock failed, vote_normal_volt is %pK\n", __func__, clk->vote_normal_volt);
			return -EBUSY;
		}
		ret = clk_prepare_enable(clk->vote_normal_volt);

		if (0 == ret) {
			clk->voted_peri_volt = IPU_CLOCK_NORMAL;
		} else {
			printk(KERN_ERR"[%s]: IPU_ERROR:clk prepare enable for peri-NORMAL failed,ret=%d\n", __func__, ret);
		}

	} else {
		clk->voted_peri_volt = IPU_CLOCK_LOW;
	}

	return ret;
}

/* this func use mutex, for interface only, and SHOULD NOT be called by other ipu_clock functions */
void ipu_vote_peri_withdraw(struct ics_clock *clk)
{
	/* to withdraw vote PERI by "voted_peri_volt" but "clk start rate", because clk start rate might
	be modified by user at some time, but "clk" MUST withdraw the one opened before */

	if (IPU_CLOCK_HIGH == clk->voted_peri_volt) {
		printk(KERN_DEBUG"[%s]: to withdraw vote buck0 HIGH voltage\n", __func__);
		if (IS_ERR_OR_NULL(clk->vote_high_volt)) {
			printk(KERN_ERR"[%s]: IPU_ERROR:get clock failed, vote_high_volt is %pK\n", __func__, clk->vote_high_volt);
			return;
		}
		clk_disable_unprepare(clk->vote_high_volt);
		clk->voted_peri_volt = IPU_CLOCK_LOW;

	} else if (IPU_CLOCK_NORMAL == clk->voted_peri_volt) {
		printk(KERN_DEBUG"[%s]: to withdraw vote buck0 MIDDLE voltage\n", __func__);
		if (IS_ERR_OR_NULL(clk->vote_normal_volt)) {
			printk(KERN_ERR"[%s]: IPU_ERROR:get clock failed, vote_normal_volt is %pK\n", __func__, clk->vote_normal_volt);
			return;
		}
		clk_disable_unprepare(clk->vote_normal_volt);
		clk->voted_peri_volt = IPU_CLOCK_LOW;

	} else {
		/* do nothing */
	}
}

static int ipu_clock_set(struct ics_clock *clk, unsigned int new_rate)
{
	int ret;
	unsigned int target_rate = new_rate;

	if (new_rate == clk->curr_rate) {
		printk(KERN_ERR"[%s]: IPU_WARN:set some IPU clock rate %d, ignored\n", __func__, target_rate);
		return 0;
	}

	if (IPU_CLOCK_HIGH == target_rate) {
		/* for HIGH, set IPU clock to 960M */
		ret = clk_set_rate(clk->ipu_clk_ptr, (unsigned long)target_rate);
		if (ret) {
			/* in low temperature, clk set rate to 960M will fail, in this case try to set rate to 640M */
			printk(KERN_ERR"[%s]: IPU_ERROR:set ipu rate %d fail (possible in low temperature), ret:%d\n",
				__func__, target_rate, ret);
			target_rate = IPU_CLOCK_NORMAL;
			ret = clk_set_rate(clk->ipu_clk_ptr, (unsigned long)target_rate);
			if (ret) {
				printk(KERN_ERR"[%s]: IPU_ERROR:set ipu rate %d fail, ret:%d\n", __func__, target_rate, ret);
				return ret;
			}
		} else {
			/* for HIGH set IPU rate ok, set VCODECBUS to 640M, because clock source PPLL2 is enabled, so set rate is valid */
			ret = clk_set_rate(clk->vcodecbus_clk_ptr, VCODECBUS_CLOCK_EXCEED);
			if (ret) {
				printk(KERN_ERR"[%s]: IPU_ERROR:set vcodec rate %d fail, ret:%d, ignore\n",
					__func__, VCODECBUS_CLOCK_EXCEED, ret);
			}
		}
	} else {
		/* for MIDDLE or LOW, set VCODECBUS to default if necessary (when alter from HIGH) */
		if (IPU_CLOCK_HIGH == clk->curr_rate) {
			/* set vcodec bus to "VCODECBUS_CLOCK_DEFAULT", which is used as the default rate for VENC/VDEC */
			ret = clk_set_rate(clk->vcodecbus_clk_ptr, VCODECBUS_CLOCK_HIGH2DEFAULT);
			if (ret) {
				printk(KERN_ERR"[%s]: IPU_ERROR:set vcodec rate %d fail, ret:%d, ignore\n", __func__, VCODECBUS_CLOCK_HIGH2DEFAULT, ret);
			}

			ret = clk_set_rate(clk->vcodecbus_clk_ptr, VCODECBUS_CLOCK_DEFAULT);
			if (ret) {
				printk(KERN_ERR"[%s]: IPU_ERROR:set vcodec rate %d fail, ret:%d, ignore\n", __func__, VCODECBUS_CLOCK_DEFAULT, ret);
			}
		}

		ret = clk_set_rate(clk->ipu_clk_ptr, (unsigned long)target_rate);
		if (ret) {
			/* in low temperature, clk set rate to 960M will fail, in this case try to set rate to 640M */
			printk(KERN_ERR"[%s]: IPU_ERROR:set ipu rate %d fail, ret:%d\n", __func__, target_rate, ret);
			return ret;
		}
	}

	printk(KERN_ERR"[%s]: IPU_NOTE: set clock done, ipu clock(try/actually/clk_get)=%d/%d/%ld, vcodecbus clock=%ld\n",
		__func__, new_rate, target_rate, clk_get_rate(clk->ipu_clk_ptr), clk_get_rate(clk->vcodecbus_clk_ptr));

	clk->curr_rate = target_rate;

	return 0;
}

/* this func use mutex, for interface only, and SHOULD NOT be called by other ipu_clock functions */
int ipu_clock_start(struct ics_clock *clk)
{
	int ret;

	mutex_lock(&clk->clk_mutex);

	/* WARNING: clk_prepare_enable should NOT be called in interrupt because it contains mutex.
	   If needed in furture, use API: clk_prepare and clk_enable instead of clk_prepare_enable
	   in interrupt functions. */
	ret = clk_prepare_enable(clk->ipu_clk_ptr);
	if (ret) {
		printk(KERN_ERR"[%s]: IPU_ERROR:clk prepare enable failed,ret=%d\n", __func__, ret);
		mutex_unlock(&clk->clk_mutex);
		return ret;
	}

	/* NOTE: here need not call "clk_prepare_enable(clk->vcodecbus_clk_ptr)" because because it is used by both IPU and VCODEC
	   process can guarentee it!! */

	clk->curr_rate = IPU_CLOCK_UNSET;
	ret = ipu_clock_set(clk, clk->start_rate);
	if (ret) {
		printk(KERN_ERR"[%s]: IPU_ERROR:ipu_clock_set_rate failed,ret=%d\n", __func__, ret);
		mutex_unlock(&clk->clk_mutex);
		return ret;
	}
	mutex_unlock(&clk->clk_mutex);
	return 0;
}

/* this func use mutex, for interface only, and SHOULD NOT be called by other ipu_clock functions */
int ipu_clock_set_start_rate(struct ics_clock *clk, unsigned int new_rate)
{
	int ret;

	mutex_lock(&clk->clk_mutex);

	if (IPU_CLOCK_HIGH == new_rate ||
		IPU_CLOCK_NORMAL == new_rate ||
		IPU_CLOCK_LOW == new_rate) {

		/* withdraw voltage hold lock if neccessary */
		ipu_vote_peri_withdraw(clk);

		/* vote voltage hold lock if neccessary */
		clk->start_rate = new_rate;
		ret = ipu_vote_peri(clk);
		if (ret) {
			/* ignore vote peri here */
			printk(KERN_ERR"[%s]: IPU_ERROR:ipu_vote_peri fail\n", __func__);
		}

		mutex_unlock(&clk->clk_mutex);
		return ret;
	} else {
		printk(KERN_ERR"[%s]: IPU_ERROR:invalid start rate=%u\n", __func__, new_rate);
		mutex_unlock(&clk->clk_mutex);
		return -EINVAL;
	}
}

/* this func use mutex, for interface only, and SHOULD NOT be called by other ipu_clock functions */
int ipu_clock_set_rate(struct ics_clock *clk, unsigned int new_rate)
{
	int ret;

	mutex_lock(&clk->clk_mutex);
	ret = ipu_clock_set(clk, new_rate);
	mutex_unlock(&clk->clk_mutex);

	return ret;
}

/* this func use mutex, for interface only, and SHOULD NOT be called by other ipu_clock functions */
void ipu_clock_stop(struct ics_clock *clk)
{
	mutex_lock(&clk->clk_mutex);
	clk_disable_unprepare(clk->ipu_clk_ptr);

	/* NOTE: here need not call "clk_disable_unprepare(clk->vcodecbus_clk_ptr)" because it is used by both IPU and VCODEC
	   process can guarentee it!! */
	mutex_unlock(&clk->clk_mutex);
}


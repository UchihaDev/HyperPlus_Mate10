#include <linux/sched.h>
#include <linux/module.h>
#include <linux/poll.h>
#include <linux/slab.h>
#include <linux/time.h>
#include <linux/vmalloc.h>
#include <linux/aio.h>
#include <uapi/linux/uio.h>
#include <chipset_common/hwzrhung/zrhung.h>
#include "../zrhung_common.h"
#include "zrhung_wp_sochalt.h"

static int is_soc_halt;

#define SOCHALT_INFO         "press10s"

static int __init wp_reboot_reason_cmdline(char *reboot_reason_cmdline)
{
	if (!strcmp(reboot_reason_cmdline, SOCHALT_INFO)) {  /*lint !e421*/
		is_soc_halt = 1;
	}

	return 0;
}

early_param("reboot_reason", wp_reboot_reason_cmdline);

int wp_get_sochalt(zrhung_write_event* we)
{
	if (!we) {
		printk(KERN_ERR "%s %d: param error\n", __FUNCTION__, __LINE__);
		return -1;
	}

	memset(we, 0, sizeof(*we));

	if (is_soc_halt) {
		we->magic = MAGIC_NUM;
		we->len = sizeof(*we);
		we->wp_id = ZRHUNG_WP_SR;

		printk(KERN_ERR "%s %d: soc halt\n", __FUNCTION__, __LINE__);
	}

	return 0;
}


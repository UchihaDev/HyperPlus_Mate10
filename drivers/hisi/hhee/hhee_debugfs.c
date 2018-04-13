/*
* HHEE general communication and test driver
*
*/

#include <linux/module.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/debugfs.h>
#include <linux/kernel.h>
#include <asm/compiler.h>
#include <asm/io.h>
#include "hhee.h"

static struct dentry *dir = 0;
static u32 sum = 0;

/*following functions are used for log read*/
static int hhee_log_open(struct inode *inode, struct file *pfile)
{
	pfile->private_data = inode->i_private;
	return 0;
}

static ssize_t hhee_log_read(struct file *file, char __user *buf,
	size_t count, loff_t *offp)
{
	int logtype =  (int)(unsigned long)file->private_data;

	pr_info("hhee log read, logtype is %d\n", logtype);
	return hhee_copy_logs(buf, count, offp, logtype);
}

static ssize_t hhee_log_write(struct file *file, const char __user *buf,
	size_t count, loff_t *offp)
{
	int logtype = (int)(unsigned long)file->private_data;
	ssize_t ret = 0;

	if (CRASH_LOG == logtype) {
		pr_info("before %s send.\n", __func__);
		ret = (ssize_t)hhee_fn_hvc((unsigned long)HHEE_HVC_NOTIFY, 0ul, 0ul, 0ul);
		pr_info("after %s, ret = 0x%lx.\n", __func__, ret);
	}

	return ret;
}/*lint !e715*/

const struct file_operations tzdbg_fops = {
	.owner   = THIS_MODULE,   /*lint !e64*/
	.read    = hhee_log_read,
	.write   = hhee_log_write,
	.open    = hhee_log_open,
};/*lint !e785*/

int hhee_init_debugfs(void)
{
	struct dentry *junk;
	int ret;

	dir = debugfs_create_dir("hhee", NULL);
	if (!dir) {
		printk(KERN_ALERT "HHEE: failed to create /sys/kernel/debug/hhee\n");
		return -1;
	}

	junk = debugfs_create_file(
			"log",
			0220,
			dir,
			(void *)NORMAL_LOG,
			&tzdbg_fops);
	if (!junk) {
		pr_err("HHEE: failed to create /sys/kernel/debug/hhee/log\n");
		ret = -1;
		goto out;
	}

	junk = debugfs_create_file(
			"crashlog",
			0220,
			dir,
			(void *)CRASH_LOG,
			&tzdbg_fops);
	if (!junk) {
		pr_err("HHEE: failed to create /sys/kernel/debug/hhee/crashlog\n");
		ret = -1;
		goto out;
	}

	junk = debugfs_create_file(
			"monitorlog",
			0220,
			dir,
			(void *)MONITOR_LOG,
			&tzdbg_fops);
	if (!junk) {
		pr_err("HHEE: failed to create /sys/kernel/debug/hhee/monitorlog\n");
		ret = -1;
		goto out;
	}

	junk = debugfs_create_u32("sum", 0444, dir, &sum);
	if (!junk) {
		pr_err("HHEE: failed to create /sys/kernel/debug/hhee/sum\n");
		ret = -1;
		goto out;
	}

	return 0;
out:
	debugfs_remove_recursive(dir);
	return ret;

}

// This is called when the module is removed.
void hhee_cleanup_debugfs(void)
{
	debugfs_remove_recursive(dir);
}

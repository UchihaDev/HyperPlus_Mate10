/*
 * hisi_test_get_spinlock.c
 *
 * This file is used for testing clear exclusive monitor with spinlock which
 * does not send sev using spin_unlock.
 *
 * Copyright (c) 2001-2021, Huawei Tech. Co., Ltd. All rights reserved.
 *
 * shenchen <shenchen4@huawei.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include <linux/kthread.h>
#include <linux/spinlock.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <global_ddr_map.h>

#define CPU_A53 0
#define CPU_A57 1
#define DDR_CACHEABLE_TEST
/*
#define DDR_UNCACHEABLE_TEST
*/

static long task_count [2] = {0, 0};
static spinlock_t *test_lock;
static struct task_struct *task1, *task2, *task3;

static int get_spinlock_task(int task_num)
{
	printk(KERN_ALERT"THIS IS THREAD %d\n", task_num);
	while (1) {
		spin_lock(test_lock);
		task_count[task_num]++;
		spin_unlock(test_lock); /*lint !e527 */
	}
	return 0; /*lint !e527 */
}

static int print_task(void *unused)
{
#ifdef DDR_CACHEABLE_TEST
	static spinlock_t testlock;
	test_lock = &testlock;
#endif

#ifdef DDR_UNCACHEABLE_TEST
	static void __iomem *spin_addr;
	spin_addr = ioremap_wc(HISI_SUB_RESERVED_UNUSED_PHYMEM_BASE, 1024);
	test_lock = (spinlock_t *) spin_addr;
#endif
	spin_lock_init(test_lock);
	msleep (180 * 1000);
	wake_up_process(task1);
	wake_up_process(task2);
	while(1) {
		msleep(10 * 1000);
		spin_lock(test_lock);
		/*lint -e866 -e774 -e712 */
		printk(KERN_ALERT"task1 gets %lu times lock, \
			task2 gets %lu times lock, the gap is %lu\n", \
			task_count[0], task_count[1], abs(task_count[0] - task_count[1]));
		/*lint +e866 +e774 +e712 */
		spin_unlock(test_lock); /*lint !e527 */
	} /*lint !e715 */
	return 0; /*lint !e527 */
}/*lint !e715 */

static int __init test_spinlock_init(void)
{
	int ret;

	printk(KERN_ALERT"TEST SPIN LOCK\n");

	task1 = kthread_create((int (*)(void *))get_spinlock_task, (void *)0, "test_task1");
	if (IS_ERR(task1)) {
		ret = (int)PTR_ERR(task1);
		task1 = NULL;
		printk(KERN_ALERT"TASK1 FAIL\n");
		goto out;
	}
	kthread_bind(task1, CPU_A53);

	task2 = kthread_create((int (*)(void *))get_spinlock_task, (void *)1, "test_task2");
	if (IS_ERR(task2)) {
		ret = (int)PTR_ERR(task2);
		printk(KERN_ALERT"TASK2 FAIL\n");
		task2 = NULL;
		goto out;
	}
	kthread_bind(task2, CPU_A57);

	task3 = kthread_create(print_task, NULL, "print_task");
	if (IS_ERR(task3)) {
		ret = (int)PTR_ERR(task3);
		task1 = NULL;
		printk(KERN_ALERT"TASK3 FAIL\n");
		goto out;
	}

	wake_up_process(task3);
	return 0;
out:
	return ret;
}

module_init(test_spinlock_init);/*lint -e(528) */

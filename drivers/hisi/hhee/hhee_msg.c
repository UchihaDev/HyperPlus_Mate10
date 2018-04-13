/*
 * Hisilicon HHEE exception driver .
 *
 * Copyright (c) 2012-2013 Linaro Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/io.h>
#include <asm/compiler.h>
#include <linux/mutex.h>
#include "hhee.h"
#include "hhee_msg.h"

static hhee_msg_type *hhee_msg = NULL;
static hhee_msg_state *msg_head = NULL;
static unsigned long buf_base;
static unsigned long buf_size;
static unsigned int max_pool;
static struct mutex mutex;

static unsigned long get_curr_msg_base(unsigned int count)
{
	return ((unsigned long)msg_head + count * HHEE_MSG_SIZE);/*lint !e647*/
}
static void handle_message(unsigned int ack)
{
	char *buf;
	char *str;
	msg_list *head;
	unsigned short handle;
	unsigned long curr_base;
	size_t buffer_size;

	curr_base = get_curr_msg_base(ack);

	head = (msg_list *)curr_base;
	handle = head->handle;
	if(!(handle) || (handle >= MAX_MSG_TYPES) || !(hhee_msg[handle].fn)){
		pr_err("invalid handle(%d).\n", handle);
		return;
	}
	if(!head->len){
		hhee_msg[handle].fn(handle, 0, NULL);
		pr_err("msg(%d) handled OK.\n", handle);
		return;
	}
	buf = (char *)((unsigned long)head + sizeof(msg_list));
	buffer_size = HHEE_MSG_SIZE - sizeof(msg_list);

	if(head->len > buffer_size){
		pr_err("message (0x%lx) is too long, info will be lost.\n",
			buffer_size);
		head->len = buffer_size;
	}
	str = (char *)kmalloc((head->len) * sizeof(char), GFP_ATOMIC);
	if(!str){
		pr_err("out of mem, msg(%d) send failed\n", handle);
		return;
	}
	memcpy(str, buf, head->len);/* unsafe_function_ignore: memcpy */

	hhee_msg[handle].fn(handle, head->len, str);
	kfree(str);

	return;
}
static void hhee_msg_handle(unsigned int send, unsigned int ack)
{
	unsigned int i = 0;

	/*if ack count from 0, send count from 1
	 *if send = 2, max(ack) == 1
	 *ack should be always < send*/
	do{
		/*check empty*/
		if((ack + 1) % (max_pool - 1) == send % (max_pool - 1)){
			pr_err("msg handled OK, send(%d),ack(%d).\n", send, ack);
			break;
		}
		ack += 1;
		/*ack count roll back*/
		if(ack >= max_pool){
			ack = 1;
		}
		handle_message(ack);
	}while((i++) < max_pool);

	msg_head->ack_count = ack;
	return;
}
irqreturn_t hhee_irq_handle(int irq, void *data)
{
	unsigned int send;
	unsigned int ack;

	if(!hhee_msg || !msg_head){
		return IRQ_HANDLED;
	}
	send = msg_head->send_count;
	ack = msg_head->ack_count;

	hhee_msg_handle(send, ack);
	return IRQ_HANDLED;
}/*lint !e715*/

static int hhee_msg_buffer_init(void)
{
	struct arm_smccc_res ret_res;
	size_t len;

	ret_res = _hhee_fn_hvc((unsigned long)HHEE_IRQ_INFOBUF, 0ul, 0ul, 0ul);
	buf_base = ret_res.a0;
	buf_size = ret_res.a1;

	if(!buf_base || !buf_size){
		pr_err("buffer info is abnormal(0x%lx, 0x%lx)!\n", buf_base, buf_size);
		return -ENOMEM;
	}
	max_pool = (buf_size / HHEE_MSG_SIZE);
	len = sizeof(hhee_msg_state);
	msg_head = (hhee_msg_state *)ioremap_cache(buf_base, buf_size);
	msg_head->ack_count = max_pool - 1;
	hhee_msg = (hhee_msg_type *)(msg_head + 1);

	pr_err("msg buffer init done(%d).\n", max_pool);

	return 0;
}
unsigned short hhee_open_msg(char *name, callback_t fn)
{
	struct arm_smccc_res ret_res;
	unsigned short handle = 0;
	size_t len;

	if(!hhee_msg || !msg_head){
		mutex_init(&mutex);
		if(hhee_msg_buffer_init()){
			pr_err("msg buffer init failed\n");
			return 0;
		}
	}
	/*double check hhee_msg & msg_head for coverity warning*/
	if(!fn || !hhee_msg || !msg_head){
		pr_err("cb func or head  is NULL.\n");
		return 0;
	}
	len = strlen(name);
	if(!len || (len > (MAX_MSG_NAME - 1 ))){
		pr_err("invalid task name!\n");
		return 0;
	}
	mutex_lock(&mutex);

	/*make sure their r nobody change the name during EL2 alloca handle ID*/
	msg_head->len = len;
	strncpy(msg_head->str, name, len);/* unsafe_function_ignore: strncpy */
	msg_head->str[len] = '\0';/*lint !e661*/
	ret_res = _hhee_fn_hvc((unsigned long)HHEE_MSG_HANDLE_GET, 0ul, 0ul, 0ul);

	handle = ret_res.a0;
	if(!handle || (handle >= MAX_MSG_TYPES)){
		pr_err("hhee register failed\n");
		mutex_unlock(&mutex);
		return 0;
	}
	hhee_msg[handle].fn = fn;
	mutex_unlock(&mutex);
	pr_err("hhee message open success(%s, %d)!\n", name, handle);
	return handle;
}

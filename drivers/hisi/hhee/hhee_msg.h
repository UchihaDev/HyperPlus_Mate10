/*
 * Copyright (c) 2017, Huawei Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __HHEE_MSG_H__
#define __HHEE_MSG_H__

#include <linux/hisi/hisi_hhee.h>

/*Support max message types 31*/
#define MAX_MSG_TYPES (31)
/*1k for each msg*/
#define HHEE_MSG_SIZE 0x400
#define MAX_MSG_NAME (16)

typedef struct msg_type {
	char name[MAX_MSG_NAME];
	unsigned short handle; /*msg ID*/
	callback_t fn;
}hhee_msg_type __attribute__((aligned(sizeof(long))));

typedef struct head {
	unsigned short handle;
	unsigned int len;
}msg_list __attribute__((aligned(sizeof(long))));

typedef struct msg_info{
	unsigned short type; /*service count*/
	unsigned int send_count;
	unsigned int ack_count;
	char str[MAX_MSG_NAME]; /*El1 to El2 register name*/
	int len; /*name len*/
}hhee_msg_state __attribute__((aligned(sizeof(long))));

#endif
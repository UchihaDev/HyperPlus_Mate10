/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef __BSP_CBOOT_DUMP_H__
#define __BSP_CBOOT_DUMP_H__

#include <mntn_interface.h>
#ifndef __ASSEMBLY__
#include <osl_bio.h>
#endif

#ifdef MNTN_AREA_CBOOT_ADDR

#define CBOOT_DUMP_ADDR         (MNTN_AREA_CBOOT_ADDR)
#define RANGE_SIZE (0x10)

#define CBOOT_DUMP_ASM_HEAD     (CBOOT_DUMP_ADDR )
#define CBOOT_DUMP_ASM_MASTER   (CBOOT_DUMP_ASM_HEAD     + RANGE_SIZE)
#define CBOOT_DUMP_ASM_SLAVE    (CBOOT_DUMP_ASM_MASTER   + RANGE_SIZE)
#define CBOOT_DUMP_HARD_BOOT    (CBOOT_DUMP_ASM_SLAVE    + RANGE_SIZE)
#define CBOOT_DUMP_HARD_DRV     (CBOOT_DUMP_HARD_BOOT    + RANGE_SIZE)
#define CBOOT_DUMP_APP_INIT     (CBOOT_DUMP_HARD_DRV     + RANGE_SIZE)
#define CBOOT_DUMP_RTOSCK       (CBOOT_DUMP_APP_INIT     + RANGE_SIZE)

#if (defined __ASSEMBLY__)||(defined _ASMLANGUAGE)
/* offset = 0/4/8... */
    .macro  cboot_dump_asm_head, offset , val
    ldr r0,= \CBOOT_DUMP_ASM_HEAD
    ldr r1,= \offset
    add r0, r0, r1
    ldr r1,= \val
    str r1,[r0]
    .endm
    
    .macro  cboot_dump_asm_master, offset , val
    ldr r0,= \CBOOT_DUMP_ASM_MASTER
    ldr r1,= \offset
    add r0, r0, r1
    ldr r1,= \val
    str r1,[r0]
    .endm
    
    .macro  cboot_dump_asm_slave, offset , val
    ldr r0,= \CBOOT_DUMP_ASM_SLAVE
    ldr r1,= \offset
    add r0, r0, r1
    ldr r1,= \val
    str r1,[r0]
    .endm

#else
/* pos = 0,1,2.. < RANGE_SIZE/sizeof(unsigned) */
static inline void cboot_dump(void* base, unsigned pos, unsigned val)
{
    if(pos < RANGE_SIZE/sizeof(unsigned))
    {
        writel(val, (void*)((unsigned)base+pos*sizeof(unsigned)));
    }
}
#define cboot_dump_hard_boot(pos,val)  cboot_dump((void*)CBOOT_DUMP_HARD_BOOT, pos, val)
#define cboot_dump_hard_drv(pos,val)   cboot_dump((void*)CBOOT_DUMP_HARD_DRV , pos, val)
#define cboot_dump_app_init(pos,val)   cboot_dump((void*)CBOOT_DUMP_APP_INIT , pos, val)
#endif

#else /* MNTN_AREA_CBOOT_ADDR */
    
#ifdef __ASSEMBLY__
    .macro  cboot_dump_asm_head, offset , val
    .endm

    .macro  cboot_dump_asm_master, offset , val
    .endm

    .macro  cboot_dump_asm_slave, offset , val
    .endm
#else
#define cboot_dump_hard_boot(pos,val)
#define cboot_dump_hard_drv(pos,val)
#define cboot_dump_app_init(pos,val)
#endif

#endif /* MNTN_AREA_CBOOT_ADDR */

#endif /*__BSP_CBOOT_DUMP_H__*/


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

#ifndef __BSP_BUSFREQ_H__
#define __BSP_BUSFREQ_H__

#ifdef __cplusplus /* __cplusplus */
extern "C"
{
#endif /* __cplusplus */

#include <osl_types.h>
#include "bsp_sram.h"
#include "bsp_trace.h"
#include "bsp_notifier.h"
#include "bsp_regulator.h"

#define  busfreq_err(fmt,...)		(bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_BUS_FREQ, "<%s> <%d>"fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__))
#define  busfreq_warn(fmt,...)		(bsp_trace(BSP_LOG_LEVEL_WARNING, BSP_MODU_BUS_FREQ, "<%s> <%d>"fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__))
#define  busfreq_info(fmt,...)		(bsp_trace(BSP_LOG_LEVEL_INFO, BSP_MODU_BUS_FREQ, "<%s> <%d>"fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__))
#define  busfreq_debug(fmt,...)		(bsp_trace(BSP_LOG_LEVEL_DEBUG, BSP_MODU_BUS_FREQ, "<%s> <%d>"fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__))

#define BUSFREQ_PRECHANGE		(0)
#define BUSFREQ_POSTCHANGE		(1)

struct busfreq_info_s
{
    unsigned int index;
    unsigned int bus_freq;
    unsigned int volt_vlaue;
    unsigned int reg_value;
    unsigned int reg_sw_value;
    unsigned int use_abb_pll;
};

struct busfreq_ctrl_s
{
    int cur_freq;
    int cur_index;
    int new_freq;
    int max_profile_count;
    int enable_flag;
    unsigned int last_freq_time;
    unsigned int reg_value_offset;
    unsigned int reg_value_mask;
    unsigned int reg_sw_offset;
    unsigned int reg_sw_mask;
    void* freq_sysctrl_base_addr;
    struct regulator *bus_regu;
};

void bsp_slowbus_set_freq(int new_freq);
int bsp_slowbus_get_freq(void);
int bsp_fastbus_get_freq(void);
void bsp_fastbus_set_freq(int new_freq);
int bsp_busfreq_notifier_register(struct notifier_block *nb);
int bsp_busfreq_notifier_unregister(struct notifier_block *nb);

#ifdef __cplusplus /* __cplusplus */
}
#endif /* __cplusplus */

#endif    /*  __BSP_BUSFREQ_H__ */


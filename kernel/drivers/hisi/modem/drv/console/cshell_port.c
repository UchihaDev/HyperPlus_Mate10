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

#include <linux/slab.h>
#include <linux/semaphore.h>
#include <linux/kthread.h>
#include <mdrv_udi.h>
#include <mdrv_usb.h>
#include <nv_stru_drv.h>
#include <bsp_nvim.h>
#include <bsp_cshell.h>
#include <adrv.h>
#include "console.h"
#include "virtshell.h"
#include "cshell_logger.h"
/*lint --e{64}*/
void * g_acm_chn_handle = NULL;
struct semaphore g_recv_sem;
struct semaphore g_send_sem;

void cshell_starttx(struct console * con);
struct console bluetooth_con =
{
	.name = "cshell_con",
	.data = NULL,
	.start_tx = cshell_starttx,
	.start_shell = virtshl_start_shell,
	.coreid = CON_CCORE,
	.inflags = CON_INFLG_AGENT | CON_INFLG_ICC | CON_INFLG_CONSTANT,
	.icchn = NULL,
	.predecessor = NULL
};/*lint !e785*/
EXPORT_SYMBOL(bluetooth_con);

unsigned char bluetooth_logbuf[1U << LOG_BUF_SHIFT];
unsigned char bluetooth_cmdbuf[1U << CMD_BUF_SHIFT];

int legal_chr(char chr)
{
	if(chr >= 0x20 && chr <= 0x7E)/* visible character */
		return 1;
	if('\r' == chr  ||
		'\n' == chr ||
		0x8  == chr ||  /* backspace */
		0x7F == chr ||  /* del */
		0x1B == chr ||  /* esc(1b) for up(1b 5b 41)/down(1b 5b 42)/left(1b 5b 44)/right(1b 5b 43)*/
		0x4  == chr ||  /* ctrl+d */
		'\t' == chr
		)
		return 1;

	return 0;
}

int recv_func(void * data)
{
	ACM_WR_ASYNC_INFO acm_wt_info = {0};
	int i = 0;

	/* coverity[no_escape] */
	while(1)
	{
		down(&g_recv_sem);

		if(NULL == g_acm_chn_handle)
			continue;

		if(bsp_acm_ioctl(g_acm_chn_handle, ACM_IOCTL_GET_RD_BUFF, &acm_wt_info))
			continue;

		for(i = 0; i < acm_wt_info.u32Size; i++)/*lint !e737*//*lint !e574*/
		{
			if(!legal_chr(acm_wt_info.pVirAddr[i]))
			{
				printk("[bluetooth port]input contains unvisible data\n");
				break;
			}
		}
		if(i < acm_wt_info.u32Size)/*lint !e737*//*lint !e574*/
		{
			(void)bsp_acm_ioctl(g_acm_chn_handle, ACM_IOCTL_RETURN_BUFF, &acm_wt_info);
			continue;
		}

		bluetooth_con.rx(&bluetooth_con, acm_wt_info.pVirAddr, acm_wt_info.u32Size);

		(void)bsp_acm_ioctl(g_acm_chn_handle, ACM_IOCTL_RETURN_BUFF, &acm_wt_info);
	}

	return 0;/*lint !e527*/
}/*lint !e715*/

static int tsk_send_func(void * data)
{
	unsigned char tmpbuf[128] = {0,};
	int len = 0;

	/* coverity[no_escape] */
	while(1)
	{
		down(&g_send_sem);
              /*lint -e732*/
		while((len = bluetooth_con.tx(&bluetooth_con, tmpbuf, sizeof(tmpbuf))) > 0)/*lint !e747*/
		{       
			if(g_acm_chn_handle && (0 > bsp_acm_write(/*lint -epu*/g_acm_chn_handle, tmpbuf, len)))
				printk("bsp_acm_write fail in tsk_send_func\n");
			a_cshell_write(len, tmpbuf);
		}
	}      /*lint +e732*/

	return 0;/*lint !e527*/

}/*lint !e715*/

void cshell_starttx(struct console * con)
{
	up(&g_send_sem);
}/*lint !e715*/
EXPORT_SYMBOL(cshell_starttx);

void acm_event_cb(void)
{
	up(&g_recv_sem);
}
EXPORT_SYMBOL(acm_event_cb);

void acm_open_cb(void)
{
    void * acm_chn_handle = NULL;
	int retval ;
	struct cshell_open_s flags;
	printk("acm_open_cb called\n");

	acm_chn_handle = bsp_acm_open(UDI_USB_ACM_SHELL);/*lint !e838*/
    if (!acm_chn_handle)
    {
        printk("A:cshell_udi_open_cb acm open fail: [%pK]\n", acm_chn_handle);
        return;
    }

    retval = bsp_acm_ioctl(acm_chn_handle, ACM_IOCTL_SET_READ_CB, acm_event_cb);
    if (retval)
    {
        printk("A:cshell_udi_open_cb cb register fail: [0x%x]\n", retval);
        return;
    }

	g_acm_chn_handle = acm_chn_handle;
	flags.cshell_open_flags=(((u32)0x1<<(u32)CSHELL_USB)<<16)|((u32)0x1<<CSHELL_USB);
	retval = bsp_icc_send((u32)ICC_CPU_MODEM ,(u32)((ICC_CHN_IFC << 16) | IFC_RECV_FUNC_CSHELL),(u8*)&flags,(u32)sizeof(struct cshell_open_s));
	if(retval!=(int)sizeof(struct cshell_open_s))
	{
		printk("acm_open_cb failed,icc send fail,ret=0x%x\n", retval);
		return ;
	}
	
}
EXPORT_SYMBOL(acm_open_cb);

void acm_close_cb(void)
{
	int retval ;
	void * acm_chn_handle = g_acm_chn_handle;
	struct cshell_open_s flags ;
	printk("acm_close_cb called\n");

	retval =  bsp_acm_ioctl(acm_chn_handle, ACM_IOCTL_SET_READ_CB, NULL);
	retval += bsp_acm_close(acm_chn_handle);
	g_acm_chn_handle = NULL;
	flags.cshell_open_flags=(((u32)((u32)0x1<<(u32)CSHELL_USB))<<16)&0xFFFF0000;
	retval = bsp_icc_send((u32)ICC_CPU_MODEM ,(u32)((ICC_CHN_IFC << 16) | IFC_RECV_FUNC_CSHELL),(u8*)&flags,(u32)sizeof(struct cshell_open_s));/*lint !e838*/
	if(retval!=(int)sizeof(struct cshell_open_s))
	{
		printk("acm_close_cb failed,icc send fail,ret=0x%x\n", retval);
		return ;
	}
}
EXPORT_SYMBOL(acm_close_cb);

int cshell_connect(void)
{
	return establish_icc_chn(CON_CCORE, &bluetooth_con);/*lint !e713*/
}
EXPORT_SYMBOL(cshell_connect);

int cshell_port_init(void)
{
	struct task_struct * tsk_hdl = NULL;
	DRV_UART_SHELL_FLAG uartcshell_nv = {.extendedbits = 0};

	if(bsp_nvm_read(NV_ID_DRV_UART_SHELL_FLAG, (u8 *)&uartcshell_nv, sizeof(DRV_UART_SHELL_FLAG)))/*lint !e747*/
    {
        printk("[A:CSHELL]:bsp_nvm_read fails  line:%d uartcshell_nv.cshell_to_auart:%d\n", __LINE__, uartcshell_nv.extendedbits);
    }

	sema_init(&g_recv_sem, 0);
	sema_init(&g_send_sem, 0);
	tsk_hdl = kthread_run(recv_func, NULL, "cshell_recv_thread");/*lint !e838*/
	if(IS_ERR(tsk_hdl))
		;
	tsk_hdl = kthread_run(tsk_send_func, NULL, "cshell_send_thread");/*lint !e548*/

	BSP_USB_RegUdiEnableCB(acm_open_cb);
	BSP_USB_RegUdiDisableCB(acm_close_cb);

	con_ring_init(&bluetooth_con.cmdbuf, bluetooth_cmdbuf, 1U << CMD_BUF_SHIFT);/*lint !e747*/
	con_ring_init(&bluetooth_con.logbuf, bluetooth_logbuf, 1U << LOG_BUF_SHIFT);/*lint !e747*/
	con_register(&bluetooth_con);

	if(uartcshell_nv.c_shell)
		cshell_connect();

	return 0;/*lint !e438*/
}
/*lint -e528*/
module_init(cshell_port_init);

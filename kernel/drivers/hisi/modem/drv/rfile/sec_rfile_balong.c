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
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/io.h>

#include <product_config.h>
#include <osl_common.h>
#include <osl_thread.h>
#include <osl_sem.h>
#include <bsp_trace.h>

#include <teek_client_api.h>
#include <teek_client_id.h>

#define  rfile_print_error(fmt, ...)    (bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_RFILE, "[rfile]: <%s> <%d> "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__))
//#define  rfile_print_info(fmt, ...)     (bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_RFILE, "[rfile]: "fmt, ##__VA_ARGS__))

struct rfile_icc_ctrl
{
    TEEC_UUID svc_uuid;
    char svc_name[32];
    u32  session_cmd_id;
    u32  task_priority;
};

OSL_TASK_ID  rfile_ca_task_id;

/******************************************************************************
Function:       TEEK_ca_rfile_init
Description:    TEEK初始化
Input:          session
                context
                svc_uuid
                svc_name
Output:         none
Return:         0: OK  其他: ERROR码
******************************************************************************/
static int TEEK_ca_rfile_init(TEEC_Session *session, TEEC_Context *context, TEEC_UUID *svc_uuid, const char *svc_name)
{/*lint --e{845} */
    TEEC_Result result;
    TEEC_Operation operation = {0};
    u32 root_id = 0;

    result = TEEK_InitializeContext(NULL, context);

    if(result != TEEC_SUCCESS) {
        rfile_print_error("TEEK_InitializeContext failed,result = 0x%x!\n",result);
        return BSP_ERROR;
    }

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramTypes = TEEC_PARAM_TYPES(
            TEEC_NONE,
            TEEC_NONE,
            TEEC_MEMREF_TEMP_INPUT,
            TEEC_MEMREF_TEMP_INPUT);
    operation.params[2].tmpref.buffer = (void *)(&root_id);
    operation.params[2].tmpref.size = sizeof(root_id);
    operation.params[3].tmpref.buffer = (void *)svc_name;
    operation.params[3].tmpref.size = strlen(svc_name) + 1;
    result = TEEK_OpenSession(
                context,
                session,
                svc_uuid,
                TEEC_LOGIN_IDENTIFY,
                NULL,
                &operation,
                NULL);

    if (result != TEEC_SUCCESS)
    {
        rfile_print_error("TEEK_OpenSession failed,result = 0x%x!\n",result);
        TEEK_FinalizeContext(context);
        return BSP_ERROR;
    }
    rfile_print_error("TEEK_OpenSession  TEEC_SUCCESS!!!\n");
    return BSP_OK;
}

/******************************************************************************
Function:        TEEK_ca_rfile_session
Description:     通过session传入命令字或值
Input:
        cmd_id      - 传送给安全OS的cmd_id
Output:          none
Return:          0: OK  其他: ERROR码
******************************************************************************/
static int TEEK_ca_rfile_session(TEEC_Session *session, u32 cmd_id)
{/*lint --e{845} */
    TEEC_Result result;
    TEEC_Operation operation;
    unsigned int   origin;

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramTypes = TEEC_PARAM_TYPES(
                           TEEC_NONE,
                           TEEC_NONE,
                           TEEC_NONE,
                           TEEC_NONE);

    result = TEEK_InvokeCommand(
                           session,
                           cmd_id,
                           &operation,
                           &origin);
    if (result != TEEC_SUCCESS) {
        rfile_print_error("invoke failed!result = 0x%x!\n",result);
        return BSP_ERROR;
    }
    rfile_print_error("TEEK_InvokeCommand  TEEC_SUCCESS!!!\n");
    return (int)result;
}

static int ca_rfile_task_func(void* data)
{
    int ret;
    TEEC_Session session;
    TEEC_Context context;
    struct rfile_icc_ctrl *ca_icc_control = (struct rfile_icc_ctrl *)data;

    ret = TEEK_ca_rfile_init(&session, &context, &ca_icc_control->svc_uuid, ca_icc_control->svc_name);
    if(ret)
    {
        rfile_print_error("TEEK_InitializeContext failed, ret %d!\n", ret);
        return ret;
    }

    /* can not return!! */
    ret = TEEK_ca_rfile_session(&session, ca_icc_control->session_cmd_id);
    if(ret)
    {
        rfile_print_error("TEEK_ca_rfile_session fail, ret %d!\n", ret);
        return ret;
    }

    rfile_print_error("ca rfile never come here!!!!\n");

    TEEK_CloseSession(&session);
    TEEK_FinalizeContext(&context);

    return ret;
}


static struct rfile_icc_ctrl sec_rfile_ca_cfg = {
    .svc_uuid = TEE_SERVICE_SECBOOT,
    .svc_name = "sec_boot",
    .session_cmd_id = SECBOOT_CMD_ID_BSP_RFILE_RW_THREAD,
    .task_priority = 90,
};

unsigned int is_sec_rfile_init = 0;

int modem_sec_rfile_init(void)
{
    int ret;

    if(is_sec_rfile_init)
        return 0;

    ret = osl_task_init("sec_rfile_ca", sec_rfile_ca_cfg.task_priority, 0x1000, (OSL_TASK_FUNC)ca_rfile_task_func,(void *)&sec_rfile_ca_cfg, &rfile_ca_task_id);
    if(ret)
    {
        rfile_print_error("ca icc task init fail, ret %d!\n", ret);
        return -1;
    }

    is_sec_rfile_init = 1;
    rfile_print_error("ok\n");

    return 0;
}



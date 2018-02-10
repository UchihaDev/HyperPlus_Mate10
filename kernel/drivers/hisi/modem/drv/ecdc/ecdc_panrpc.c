#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#include <ecdc_panrpc.h>

static ecdc_panrpc_debug g_ecdc_panrpc_debug = {0};

int ecdc_panrpc_send_to_ccore(unsigned int len, void * buf)
{
    int result; 

    result = bsp_icc_send(ICC_CPU_MODEM, ECDC_PANRPC_ICC_CHN_ID, (u8*)buf,len);
    if(result != len)
    {
        ecdc_panrpc_error_printf("bsp_icc_send fail to send req_msg,result is %d!\n",result);
        return ECDC_ERROR;
    }

    g_ecdc_panrpc_debug.send_cnt++;

    return ECDC_OK;
}

int ecdc_panrpc_acore_callback(u32 channel_id , u32 len, void* context)
{
    s32 result = 0;
    u8 *msg;

    if(channel_id != ECDC_PANRPC_ICC_CHN_ID)
    {
        ecdc_panrpc_error_printf("channel_id != ECDC_PANRPC_ICC_CHN_ID!\n");
        return ECDC_ERROR;
    }

    msg = (u8 *)kmalloc(len, GFP_KERNEL);
    if(!msg){
        ecdc_panrpc_error_printf("kmalloc failed at %s\n",__FUNCTION__);
        return ECDC_ERROR;
    }

    g_ecdc_panrpc_debug.recv_cnt++;

    result = bsp_icc_read(ECDC_PANRPC_ICC_CHN_ID, msg, len);
    if(result != len)
    {
        ecdc_panrpc_error_printf("bsp_icc_read fail to read ack_msg!result = %d\n",result);
        kfree((void *)msg);
        return ECDC_ERROR;
    }

    g_ecdc_panrpc_debug.rslt_cnt++;
    ecdc_panrpc_debug_printf("ecdc_panrpc_acore_callback SUCCESS!\n");

    ecdc_service_response((void *)msg, len);

    kfree((void *)msg);

    return ECDC_OK;
}

void ecdc_panrpc_acore_debug(void)
{
    ecdc_panrpc_printf("******recv_cnt = %d******\n", g_ecdc_panrpc_debug.recv_cnt);
    ecdc_panrpc_printf("******send_cnt = %d******\n", g_ecdc_panrpc_debug.send_cnt);
    ecdc_panrpc_printf("******rslt_cnt = %d******\n", g_ecdc_panrpc_debug.rslt_cnt);
}


int ecdc_panrpc_init(void)
{
    s32 result = 0;

    result = bsp_icc_event_register(ECDC_PANRPC_ICC_CHN_ID, ecdc_panrpc_acore_callback, NULL, NULL, NULL);
    if(ICC_OK != result) {
        ecdc_panrpc_error_printf("fatal:register icc channel failed!\n");
        return ECDC_ERROR;
    }

    ecdc_panrpc_printf("ecdc_panrpc_acore_init SUCCESS!\n");

    return ECDC_OK;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

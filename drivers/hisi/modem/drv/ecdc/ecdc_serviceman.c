
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/string.h>
#include "ecdc_serviceman.h"

struct service_info serviceman[ECDC_SERVICE_MAX];
static struct ecdc_packet_resp ecdc_error_resp_packet = {
    0x4849ffff,16,ECDC_PACKET_TYPE(ECDC_PACKET_RESPONSE),
    0xffffffff,0xffffffff,0};

int ecdc_serviceman_init(void)
{
	return 0;
}

int ecdc_send_to_ccore(unsigned int len, void *params)
{
    ecdc_panrpc_send_to_ccore(len,params);
    return ECDC_OK;
}

void ecdc_service_response(void *params, int size)
{
	//send to client
	ecdc_send_to_user((char * )params, size);
}

/* construct special error result packet to reply when error occured at the ecdc layer */
void ecdc_process_error_response(void)
{
    ecdc_service_response((void *)&ecdc_error_resp_packet,sizeof(struct ecdc_packet_resp));
}




int ecdc_register_service(struct service_info * service)
{
	/* input parameter valid check */
	//unsigned int type = service->service_type - HISI_SERVICE_TYPE;

	if (service->service_type >= (unsigned int)ECDC_SERVICE_MAX)
		return ECDC_ERROR;
	/* register the service */
	if (serviceman[service->service_type].ops)
		return ECDC_ERROR;

	serviceman[service->service_type] = * service;

	return ECDC_OK;
}

int ecdc_unregister_service(unsigned int service_type)
{
	//unsigned int type = service_type - HISI_SERVICE_TYPE;
	if (serviceman[service_type].ops)
	{
		memset(&(serviceman[service_type]), 0, sizeof(struct service_info));
	}
	return 0;
}

int ecdc_service_distribute(void *params)
{
	//没必要memcpy，消费部分数据即可
	unsigned int* request = (unsigned int *)params;
	unsigned int req_service_type = request[0];
	int result = 0;
	printk(KERN_DEBUG "[ecdc_service_distribute] req_service_type is %4x",req_service_type);
	req_service_type = req_service_type - HISI_SERVICE_TYPE;
	printk(KERN_DEBUG "[ecdc_service_distribute] req_service_type is %4x",req_service_type);
	if ( req_service_type >= ECDC_SERVICE_MAX)
	    goto ecdc_service_distribute_error;
	if (!serviceman[req_service_type].ops)
	    goto ecdc_service_distribute_error;
	result = serviceman[req_service_type].ops(params);
	if (result != 0)
	{
		//printk("return value is error!\n");
	}
	return ECDC_OK;
ecdc_service_distribute_error:
    ecdc_process_error_response();
    return ECDC_ERROR;
}
	

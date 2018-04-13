#ifndef __ECDC_SERVICEMAN_H_
#define __ECDC_SERVICEMAN_H_

#include "bsp_ecdc_common.h"
#include <ecdc_netserver.h>
#include "ecdc_panrpc.h"

struct service_info {
	unsigned int service_type;
	service_ops ops;
};


int ecdc_register_service(struct service_info * service);
int ecdc_service_distribute(void *params);
int ecdc_serviceman_init(void);
void ecdc_service_response(void *params, int size);
int ecdc_send_to_ccore(unsigned int len, void *params);

#endif

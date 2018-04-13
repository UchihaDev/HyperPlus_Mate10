#ifndef __BSP_ECDC_COMMON_H_
#define __BSP_ECDC_COMMON_H_

typedef int (*service_ops)(void *);

#define ECDC_ERROR (-1)
#define ECDC_OK (0)
#define HISI_SERVICE_TYPE 0X48490000

//取service type后四位
typedef enum {
	ECDC_SERVICE_RFVERIFY = 0x0000,
	/* add registered service here */

	/* end of registered service */
	ECDC_SERVICE_MAX ,
}ecdc_service_type;

#define ECDC_PANRPC_ICC_CHN_ID       (ICC_CHN_AC_PANRPC << 16 | ECDC_PANRPC_ID)
typedef enum {
    ECDC_PACKET_REQUEST = 0,
    ECDC_PACKET_RESPONSE = 1,
}ecdc_packet_type;

#define ECDC_SERVICE_MAGIC_BITS 16
#define ECDC_SERVICE_TYPE(n) (unsigned int)(HISI_SERVICE_TYPE | (n & (1 << ECDC_SERVICE_MAGIC_BITS)))
#define ECDC_SERVICE_ENUM_TYPE(n) (unsigned int)(n & ((1<<ECDC_SERVICE_MAGIC_BITS) - 1))
#define ECDC_PACKET_TYPE(n) (unsigned int)(n)

/* the packet should be word aligned */
#pragma pack(push,4)
struct ecdc_packet_req {
    unsigned int service_type;
    unsigned int data_len;
    unsigned int packet_type;
    unsigned int operation_id;
    unsigned int para_len;
    unsigned int para_data[0];
};
struct ecdc_packet_resp {
    unsigned int service_type;
    unsigned int data_len;
    unsigned int packet_type;
    unsigned int operation_id;
    unsigned int status;
    unsigned int result_len;
    unsigned int result_data[0];
};
#pragma pack(pop)
#endif

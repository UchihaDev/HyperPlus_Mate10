
#ifndef __BSP_ecdc_panrpc_H__
#define __BSP_ecdc_panrpc_H__

#ifdef __KERNEL__
#include <linux/kernel.h>
#endif

#include <osl_malloc.h>
#include <osl_spinlock.h>
#include <osl_list.h>
#include <osl_malloc.h>
#include <osl_types.h>
#include <osl_sem.h>
#include <bsp_shared_ddr.h>
#include <bsp_icc.h>
#include <bsp_dump.h>
#include <bsp_om_enum.h>

#include <bsp_ecdc_common.h>
#include "ecdc_serviceman.h"

#ifndef ecdc_panrpc_OK
#define ecdc_panrpc_OK               (0)
#endif

#ifndef ecdc_panrpc_ERROR
#define ecdc_panrpc_ERROR            (-1)
#endif

#ifndef ecdc_panrpc_NOSYMBOL
#define ecdc_panrpc_NOSYMBOL         (0xc0)
#endif

#ifndef ecdc_panrpc_TIMEOUT
#define ecdc_panrpc_TIMEOUT          (0xc1)
#endif

#ifdef __KERNEL__
#define ecdc_panrpc_error_printf(fmt, ...) \
    printk(KERN_ERR"[PAN_RPC]: <%s> line = %d  "fmt, __FUNCTION__,__LINE__, ##__VA_ARGS__)
#define ecdc_panrpc_debug_printf(fmt, ...) \
    printk(KERN_DEBUG"[PAN_RPC]: <%s> line = %d  "fmt, __FUNCTION__,__LINE__, ##__VA_ARGS__)
#define ecdc_panrpc_printf(fmt, ...) \
        printk(KERN_EMERG"[PAN_RPC]: <%s> line = %d  "fmt, __FUNCTION__,__LINE__, ##__VA_ARGS__)
#endif

typedef struct __ecdc_panrpc_debug_
{
    u32 send_cnt;
    u32 rslt_cnt;
    u32 recv_cnt;
} ecdc_panrpc_debug;

typedef enum
{
    WAIT,   /* µÈ´ý */
    DONE,   /* ½áÊø */
    MAX
}ecdc_panrpc_STAT_ENUM;


static inline void ecdc_panrpc_addnode(struct list_head *new, struct list_head *head,
    spinlock_t *spinlock)
{
    unsigned long flags;

    spin_lock_irqsave(spinlock, flags); /*lint !e123 */
    list_add_tail(new, head);
    spin_unlock_irqrestore(spinlock, flags); /*lint !e123 */
}


static inline void ecdc_panrpc_delnode(struct list_head *node, spinlock_t *spinlock)
{
    unsigned long flags;

    spin_lock_irqsave(spinlock, flags); /*lint !e123 */
    list_del(node);
    spin_unlock_irqrestore(spinlock, flags); /*lint !e123 */
}
int ecdc_panrpc_send_to_ccore(unsigned int len, void * buf);
int ecdc_panrpc_init(void);


#endif /* __BSP_ecdc_panrpc_H__ */


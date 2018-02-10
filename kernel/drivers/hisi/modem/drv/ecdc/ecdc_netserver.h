#ifndef __ECDC_NETSERVER_H_
#define __ECDC_NETSERVER_H_

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/sched.h>
#include <net/sock.h>
#include <linux/netlink.h>

#include <ecdc_panrpc.h>

int ecdc_send_to_user(char *info, int size);

#endif

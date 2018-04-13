#include "ecdc_serviceman.h"

#define NETLINK_TEST 17
struct {
    __u32 pid;
}user_process;

static struct sock *netlinkfd = NULL;

int ecdc_send_to_user(char *info, int size) //发送到用户空间
{
    struct sk_buff *skb;
    unsigned char *old_tail;
    struct nlmsghdr *nlh; //报文头

    int retval = 0;
//报文大小
    printk(KERN_DEBUG "[kernel space] data is : %s , data size : %d\n",info, size);
    skb = alloc_skb(size, GFP_ATOMIC); //分配一个新的套接字缓存,使用GFP_ATOMIC标志进程不>会被置为睡眠

    old_tail = skb->tail;
    //初始化一个netlink消息首部
    nlh = nlmsg_put(skb, 0, 0, 0, NLMSG_SPACE(size)-sizeof(struct nlmsghdr), 0); 
    memcpy(NLMSG_DATA(nlh), info, size); //填充数据区
    nlh->nlmsg_len = skb->tail - old_tail; //设置消息长度
    printk(KERN_DEBUG "[kernel space] size1:%d size2:%d\n", (NLMSG_SPACE(size)-sizeof(struct nlmsghdr)), nlh->nlmsg_len);

    //设置控制字段
    NETLINK_CB(skb).dst_group = 0;

    printk(KERN_DEBUG "[kernel space] skb->data:%s\n", (char *)NLMSG_DATA((struct nlmsghdr *)skb->data));

    //发送数据
    retval = netlink_unicast(netlinkfd, skb, user_process.pid, MSG_DONTWAIT);
    printk(KERN_DEBUG "[kernel space] netlink_unicast return: %d\n", retval);
    return 0;
}

void kernel_receive(struct sk_buff *__skb) //内核从用户空间接收数据
{
    //struct sk_buff *skb;
    struct nlmsghdr *nlh = NULL;

    //char *data = "This is test message from kernel";
    //void* response = "Error";
    int result = 0;
    char *data;

    printk(KERN_DEBUG "[kernel space] begin kernel_receiveskb len:%d\n",__skb->len);

    /* ??ȡ netlink ??Ϣ */
    nlh = nlmsg_hdr(__skb);

    /* ???? netlink ??Ϣ?Ƿ??Ϸ? */
    if (!NLMSG_OK(nlh, __skb->len))
    {
        printk("wrong skb len:%d\n", __skb->len);
        return;
    }
    user_process.pid = nlh->nlmsg_pid;
    data = nlmsg_data(nlh);
    printk("kernel rcv : %s: %s\n", __func__, data);
    printk(KERN_DEBUG "[kernel space] data receive from user are:%s\n", data);
    result = ecdc_service_distribute((void*)NLMSG_DATA(nlh));
    //ʧ??ֱ?ӷ??????ݣ????򽻸?ecdc????
    if (result == -1)
    {
        //????ʧ?ܵ????ݰ?0xFFFFFFFF
        //ecdc_send_to_user(response, 20);
    }

}

int ecdc_netlink_init(void)
{    
    struct netlink_kernel_cfg cfg = {
        .input		= kernel_receive,
    };
    netlinkfd = netlink_kernel_create(&init_net, NETLINK_TEST, &cfg);
    if(!netlinkfd){
        printk(KERN_ERR "can not create a netlink socket\n");
        return -1;
    }
    return 0;
	
}
	
int __init ecdc_init(void)
{
    int result = 0;
/* create netlinke socket */
    result = ecdc_netlink_init();
    if(0 != result){
        return -1;
    }

/* inter-core communication channel init */
    ecdc_panrpc_init();
    //ecdc_panrpc_init();

/* prepare to accept service register */
    ecdc_serviceman_init();

    return 0;
}

void __exit ecdc_exit(void)
{
    sock_release(netlinkfd->sk_socket);
    printk(KERN_DEBUG "test_netlink_exit!!\n");
}

module_init(ecdc_init);
module_exit(ecdc_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("eric.hu");


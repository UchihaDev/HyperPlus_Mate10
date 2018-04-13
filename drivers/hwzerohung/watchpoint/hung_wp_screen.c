#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/string.h>
#include <linux/spinlock.h>
#include <linux/workqueue.h>
#include <linux/time.h>
#include <linux/input.h>

#include <linux/hisi/hisi_powerkey_event.h>

#ifdef CONFIG_HW_ZEROHUNG
#include "chipset_common/hwzrhung/zrhung.h"
#include "chipset_common/hwzrhung/hung_wp_screen.h"
#endif

#ifdef CONFIG_HISI_BB
#include <linux/hisi/rdr_hisi_platform.h>
#include <linux/hisi/rdr_pub.h>
#endif

#define DEFAULT_TIMEOUT 10000
#define CONFIG_LEN_MAX  64
#define COMAND_LEN_MAX  128
#define CMD_BUF_FMT "T=WindowManager,T=PowerManagerService,n=system_server,d=%d,e=%lu"
#define BUFFER_TIME_END (1)
#define BUFFER_TIME_START (BUFFER_TIME_END+10)
#define NANOS_PER_MILLISECOND (1000000)
#define NANOS_PER_SECOND (NANOS_PER_MILLISECOND * 1000)

typedef struct _hung_wp_screen_config {
    int enable;
    uint32_t timeout;
} hung_wp_screen_config;

typedef struct _hung_wp_screen_data {
    hung_wp_screen_config *config;
    struct timer_list timer;
    struct workqueue_struct *workq;
    struct work_struct config_work;
    struct work_struct send_work;
    spinlock_t lock;
    int bl_level;
    int check_id;
    int tag_id;
} hung_wp_screen_data;

static bool config_done = false;
static bool init_done= false;
static hung_wp_screen_config on_config;
static hung_wp_screen_config off_config;
static hung_wp_screen_data data;

static struct notifier_block hung_wp_screen_powerkey_nb;


/*===========================================================================
** Function : hung_wp_screen_get_config
* @brief
*  Get configuration from zerohung_config.xml
** ==========================================================================*/
static int hung_wp_screen_get_config(int id, hung_wp_screen_config *cfg)
{
    int ret = 0;
    char _config[CONFIG_LEN_MAX] = {0};
    ret = zrhung_get_config(id, _config, CONFIG_LEN_MAX);
    if (0 != ret) {
        printk(KERN_ERR "%s: read config:%d fail: %d\n",
                 __func__, id, ret);
        cfg->enable = 0;
        cfg->timeout = DEFAULT_TIMEOUT;
        return ret;
    }
    sscanf(_config,"%d,%d", &cfg->enable, &cfg->timeout);
    printk(KERN_ERR "%s: id=%d, enable=%d, timeout=%d\n",
             __func__, id, cfg->enable, cfg->timeout);
    if (cfg->timeout <= 0) {
        cfg->timeout = DEFAULT_TIMEOUT;
    }
    return ret;
}


/*===========================================================================
** Function : hung_wp_screen_config_work
* @brief
*  Get configuration from zerohung_config.xml
** ==========================================================================*/
static void hung_wp_screen_config_work(struct work_struct *work)
{
    int ret_on = 0;
    int ret_off = 0;
    ret_on = hung_wp_screen_get_config(ZRHUNG_WP_SCREENON,&on_config);
    ret_off = hung_wp_screen_get_config(ZRHUNG_WP_SCREENOFF,&off_config);
    if (ret_on <= 0 && ret_off <= 0) {
        config_done = true;
        printk(KERN_ERR "%s: init done!\n", __func__);
    }
}


/*===========================================================================
** Function : hung_wp_screen_setbl
* @brief
* Called from lcd driver when setting backlight for mark:
*   For hisi platform, it's "hisifb_set_backlight" in hisi_fb_bl.c
** ==========================================================================*/
void hung_wp_screen_setbl(int level)
{
#ifndef HUNG_WP_FACTORY_MODE
    unsigned long flags;

    if (!init_done) {
        return;
    }

    spin_lock_irqsave(&(data.lock), flags);
    data.bl_level = level;
    if (!config_done) {
        spin_unlock_irqrestore(&(data.lock), flags);
        return;
    }
    if ((ZRHUNG_WP_SCREENON == data.check_id && 0 != level) ||
       (ZRHUNG_WP_SCREENOFF == data.check_id && 0 == level)) {
        printk(KERN_ERR "%s: check_id=%d, level=%d\n", __func__,
            data.check_id, data.bl_level);
        del_timer(&data.timer);
        data.check_id = ZRHUNG_WP_NONE;
    }
    spin_unlock_irqrestore(&(data.lock), flags);
#endif
}


/*===========================================================================
** Function : hung_wp_screen_send_work
* @brief
* Send envent through zrhung_send_event
** ==========================================================================*/
void hung_wp_screen_send_work(struct work_struct *work)
{
    unsigned long flags;
    char cmd_buf[COMAND_LEN_MAX] = {'\0'};
    u64 cur_stamp = 0;

#ifdef CONFIG_HISI_TIME
    cur_stamp = hisi_getcurtime() / NANOS_PER_SECOND;
#else
    cur_stamp = local_clock() / NANOS_PER_SECOND;
#endif
    printk(KERN_ERR "%s: cur_stamp=%d\n", __func__, cur_stamp);
    snprintf(cmd_buf, COMAND_LEN_MAX, CMD_BUF_FMT,
        data.config->timeout+BUFFER_TIME_START, cur_stamp+BUFFER_TIME_END);
    printk(KERN_ERR "%s: cmd_buf: %s\n", __func__, cmd_buf);
    zrhung_send_event(data.check_id, cmd_buf, "none");
    printk(KERN_ERR "%s: send event: %d\n",__func__,data.check_id);
    spin_lock_irqsave(&(data.lock), flags);
    data.check_id = ZRHUNG_WP_NONE;
    spin_unlock_irqrestore(&(data.lock), flags);
}


/*===========================================================================
** Function : hung_wp_screen_send
* @brief
* Send event when timeout
** ==========================================================================*/
static void hung_wp_screen_send(unsigned long pdata)
{
    del_timer(&data.timer);
    show_state_filter(TASK_UNINTERRUPTIBLE);
    printk(KERN_ERR "%s: hung_wp_screen_%d end !\n", __func__,data.tag_id);
    queue_work(data.workq, &data.send_work);
}


/*===========================================================================
** Function : hung_wp_screen_start
* @brief
* Start up the timer work for screen on delay check.
** ==========================================================================*/
void hung_wp_screen_start(int check_id)
{
    //if already in a check, return...
    if (ZRHUNG_WP_NONE != data.check_id) {
        printk(KERN_ERR "%s: already in check_id: %d\n",
            __func__,data.check_id);
        return;
    }

    //check config everytime
    data.config = (check_id == ZRHUNG_WP_SCREENON) ? &on_config : &off_config;
    if (!data.config->enable) {
        printk(KERN_ERR "%s: id=%d, enable=%d\n", __func__,
            check_id, data.config->enable);
        return;
    }

    data.check_id = check_id;
    //start up the check timer
    data.timer.expires = jiffies + msecs_to_jiffies(data.config->timeout*1000);
    add_timer(&data.timer);
    printk(KERN_ERR "%s: going to check ID=%d timeout=%d\n",
        __func__,check_id, data.config->timeout);

    return;

}


/*===========================================================================
** Function : hung_wp_screen_powerkey_ncb
* @brief
* Call back from powerkey driver.
** ==========================================================================*/
void hung_wp_screen_powerkey_ncb(unsigned long event)
{
#ifndef HUNG_WP_FACTORY_MODE
    static int check_off = 0;
    int volkeys = 0;
    unsigned long flags;

    if (!init_done) {
        return;
    }

    //return if not init
    if (!config_done) {
        printk(KERN_ERR "%s: config_done=%d, read config first!\n",
                        __func__, config_done);
        queue_work(data.workq, &data.config_work);
        return;
    }

    volkeys = gpio_key_vol_updown_press_get();
    spin_lock_irqsave(&(data.lock), flags);
    if (WP_SCREEN_PWK_PRESS == event) {
        printk(KERN_ERR "%s: hung_wp_screen_%d start ! "
            "bllevel=%d, volkeys=%d\n", __func__,
            ++data.tag_id, data.bl_level, volkeys);
        check_off = 0;
        if (0 == data.bl_level) {
            hung_wp_screen_start(ZRHUNG_WP_SCREENON);
        } else if (0 == volkeys) {
            check_off = 1;
        }
    } else if (check_off){
        check_off = 0;
        if (WP_SCREEN_PWK_RELEASE == event && 0 == volkeys) {
            hung_wp_screen_start(ZRHUNG_WP_SCREENOFF);
        }
    }
    spin_unlock_irqrestore(&(data.lock), flags);
#endif
}


static int hung_wp_screen_powerkey_reg_ncb(struct notifier_block *powerkey_nb,
 unsigned long event, void *data)
{
    if (event == HISI_PRESS_KEY_DOWN) {
        hung_wp_screen_powerkey_ncb(WP_SCREEN_PWK_PRESS);
    } else if (event == HISI_PRESS_KEY_UP) {
        hung_wp_screen_powerkey_ncb(WP_SCREEN_PWK_RELEASE);
    } else if (event == HISI_PRESS_KEY_1S) {
        hung_wp_screen_powerkey_ncb(WP_SCREEN_PWK_LONGPRESS);
    }
    return 0;
}


/*===========================================================================
** Function : hung_wp_screen_init
* @brief
*  Configuration init....
** ==========================================================================*/
static int __init hung_wp_screen_init(void)
{
    init_done = false;
    config_done = false;
#ifdef HUNG_WP_FACTORY_MODE
    printk(KERN_ERR "%s: factory mode, not init!\n", __func__);
#else
    printk(KERN_ERR "%s: +\n", __func__);
    data.bl_level = 1;
    data.tag_id = 0;
    data.check_id = ZRHUNG_WP_NONE;
    spin_lock_init(&(data.lock));
    init_timer(&data.timer);
    data.timer.function = hung_wp_screen_send;
    data.timer.data = 0;
    data.workq = create_workqueue("hung_wp_screen_workq");
    if (NULL == data.workq) {
        printk(KERN_ERR "%s: create workq failed!\n", __func__);
        return -1;
    }
    INIT_WORK(&data.config_work, hung_wp_screen_config_work);
    INIT_WORK(&data.send_work, hung_wp_screen_send_work);
    hung_wp_screen_powerkey_nb.notifier_call = hung_wp_screen_powerkey_reg_ncb;
    hisi_powerkey_register_notifier(&hung_wp_screen_powerkey_nb);
    init_done = true;
    printk(KERN_ERR "%s: -\n", __func__);
#endif
    return 0;
}

module_init(hung_wp_screen_init);

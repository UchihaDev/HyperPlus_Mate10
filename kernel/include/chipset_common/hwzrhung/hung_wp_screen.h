#ifndef __LINUX_HUNG_WP_SCREEN_H__
#define __LINUX_HUNG_WP_SCREEN_H__

#define WP_SCREEN_PWK_PRESS 0
#define WP_SCREEN_PWK_RELEASE 1
#define WP_SCREEN_PWK_LONGPRESS 2

void hung_wp_screen_powerkey_ncb(unsigned long);
void hung_wp_screen_setbl(int level);
#endif

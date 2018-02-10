/* Copyright (c) 2008-2014, Hisilicon Tech. Co., Ltd. All rights reserved.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 and
* only version 2 as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
* GNU General Public License for more details.
*
*/

#include "hisi_fb.h"

#define DTS_COMP_SAMSUNG_S6E3FA3X01 "hisilicon,mipi_samsung_S6E3FA3X01"

/*while used as ext lcd, use cmd mode and disable te_hard_en*/
#define AS_EXT_LCD

#ifndef AS_EXT_LCD
#define AMOLED_CHECK_INT
#endif

#if 0
#include <linux/hisi/hw_cmdline_parse.h>
#include <huawei_platform/touthscreen/huawei_touchscreen.h>
#include <huawei_platform/log/log_jank.h>
#endif

static bool g_debug_enable = false;
extern int fastboot_set_needed;

/*******************************************************************************
** Power ON Sequence(sleep mode to Normal mode)
*/
/*lint -save -e569 -e527*/
static char caset_data[] = {
	0x2A,
	0x00,0x00,0x04, 0x37,
};

static char paset_data[] = {
	0x2B,
	0x00,0x00,0x07,0x7f,
};

static char tear_on[] = {
	0x35,
	0x00,
};

static char bl_enable[] = {
	0x53,
	0x24,
};

static char delay_te[] = {
	0x44,
	0x03, 0x80,
};

static char exit_sleep[] = {
	0x11,
};

static char display_on[] = {
	0x29,
};

static char acl_mode[] = {
	0x55,
	0x00,
};

static char unlock_setting[] = {
	0xF0,
	0x5A, 0x5A,
};

/*normal H, when pcd happened,trigle to L, and always L*/
static char setting_pcd[] = {
	0xCC,
	0x5C, 0x51,
};

static char setting_errflag_mipi_err[] = {
	0xED,
	0x44,
};

static char setting_sdc[] = {
	0xC0,
	0x40, 0x00, 0x9c, 0x9c,
};

static char lock_setting[] = {
	0xF0,
	0xA5, 0xA5,
};

static char level3_unlock_setting[] = {
	0xFC,
	0x5A, 0x5A,
};

static char setting_avc1[] = {
	0xB0,
	0x1E,
};

static char setting_avc2[] = {
	0xFD,
	0x9E,
};

static char level3_lock_setting[] = {
	0xFC,
	0xA5, 0xA5,
};

/*******************************************************************************
** Power OFF Sequence(Normal to power off)
*/
static char display_off[] = {
	0x28,
};

static char enter_sleep[] = {
	0x10,
};

static struct dsi_cmd_desc display_on_cmds[] = {
	{DTYPE_DCS_WRITE, 0, 25, WAIT_TYPE_MS,
		sizeof(exit_sleep), exit_sleep},
	{DTYPE_DCS_WRITE1, 0, 200, WAIT_TYPE_US,
		sizeof(tear_on), tear_on},
	{DTYPE_GEN_LWRITE, 0, 200, WAIT_TYPE_US,
		sizeof(delay_te), delay_te},
	{DTYPE_DCS_LWRITE, 0,10, WAIT_TYPE_US,
		sizeof(caset_data), caset_data},
	{DTYPE_DCS_LWRITE, 0,10, WAIT_TYPE_US,
		sizeof(paset_data), paset_data},
	{DTYPE_GEN_LWRITE, 0, 200, WAIT_TYPE_US,
		sizeof(unlock_setting), unlock_setting},
	{DTYPE_GEN_LWRITE, 0, 200, WAIT_TYPE_US,
		sizeof(setting_pcd), setting_pcd},
	{DTYPE_DCS_WRITE1, 0, 200, WAIT_TYPE_US,
		sizeof(setting_errflag_mipi_err), setting_errflag_mipi_err},
	{DTYPE_GEN_LWRITE, 0, 200, WAIT_TYPE_US,
		sizeof(setting_sdc), setting_sdc},
	{DTYPE_GEN_LWRITE, 0, 200, WAIT_TYPE_US,
		sizeof(lock_setting), lock_setting},
	{DTYPE_GEN_LWRITE, 0, 200, WAIT_TYPE_US,
		sizeof(level3_unlock_setting), level3_unlock_setting},
	{DTYPE_DCS_WRITE1, 0, 200, WAIT_TYPE_US,
		sizeof(setting_avc1), setting_avc1},
	{DTYPE_DCS_WRITE1, 0, 200, WAIT_TYPE_US,
		sizeof(setting_avc2), setting_avc2},
	{DTYPE_GEN_LWRITE, 0, 200, WAIT_TYPE_US,
		sizeof(level3_lock_setting), level3_lock_setting},
	{DTYPE_DCS_WRITE1, 0, 200, WAIT_TYPE_US,
		sizeof(bl_enable), bl_enable},
	{DTYPE_DCS_WRITE1, 0, 90, WAIT_TYPE_MS,
		sizeof(acl_mode), acl_mode},
	//{DTYPE_DCS_WRITE, 0, 20, WAIT_TYPE_MS,
		//sizeof(display_on), display_on},
};

static struct dsi_cmd_desc display_on_cmd[] = {
		{DTYPE_DCS_WRITE, 0, 20, WAIT_TYPE_MS,
		sizeof(display_on), display_on},
};


static struct dsi_cmd_desc display_off_cmds[] = {
	{DTYPE_DCS_WRITE, 0, 40, WAIT_TYPE_MS,
		sizeof(display_off), display_off},
	{DTYPE_DCS_WRITE, 0, 160, WAIT_TYPE_MS,
		sizeof(enter_sleep), enter_sleep}
};

/*******************************************************************************
** LCD VCC
*/
#define VCC_LCDIO_NAME		"lcdio-vcc"
#define VCC_LCDANALOG_NAME	"lcdanalog-vcc"

static struct regulator *vcc_io;
static struct regulator *vcc_analog;

static struct vcc_desc samsung_s6e3fa3x01_vcc_init_cmds[] = {
	/* vcc get */
	{DTYPE_VCC_GET, VCC_LCDIO_NAME, &vcc_io, 0, 0, WAIT_TYPE_MS, 0},
	{DTYPE_VCC_GET, VCC_LCDANALOG_NAME, &vcc_analog, 0, 0, WAIT_TYPE_MS, 0},
#if 0
	/* vcc set voltage */
	{DTYPE_VCC_SET_VOLTAGE, VCC_LCDANALOG_NAME, &vcc_analog, 3300000, 3300000, WAIT_TYPE_MS, 0},
#endif
};

static struct vcc_desc samsung_s6e3fa3x01_vcc_finit_cmds[] = {
	/* vcc put */
	{DTYPE_VCC_PUT, VCC_LCDIO_NAME, &vcc_io, 0, 0, WAIT_TYPE_MS, 0},
	{DTYPE_VCC_PUT, VCC_LCDANALOG_NAME, &vcc_analog, 0, 0, WAIT_TYPE_MS, 0},
};

static struct vcc_desc samsung_s6e3fa3x01_vcc_enable_cmds[] = {
	/* vcc enable */
	{DTYPE_VCC_ENABLE, VCC_LCDANALOG_NAME, &vcc_analog, 0, 0, WAIT_TYPE_MS, 3},
	{DTYPE_VCC_ENABLE, VCC_LCDIO_NAME, &vcc_io, 0, 0, WAIT_TYPE_MS, 10},
};

static struct vcc_desc samsung_s6e3fa3x01_vcc_disable_cmds[] = {
	/* vcc disable */
	{DTYPE_VCC_DISABLE, VCC_LCDIO_NAME, &vcc_io, 0, 0, WAIT_TYPE_MS, 3},
	{DTYPE_VCC_DISABLE, VCC_LCDANALOG_NAME, &vcc_analog, 0, 0, WAIT_TYPE_MS, 3},
};

/*******************************************************************************
** LCD IOMUX
*/
static struct pinctrl_data pctrl;

static struct pinctrl_cmd_desc samsung_s6e3fa3x01_pinctrl_init_cmds[] = {
	{DTYPE_PINCTRL_GET, &pctrl, 0},
	{DTYPE_PINCTRL_STATE_GET, &pctrl, DTYPE_PINCTRL_STATE_DEFAULT},
	{DTYPE_PINCTRL_STATE_GET, &pctrl, DTYPE_PINCTRL_STATE_IDLE},
};

static struct pinctrl_cmd_desc samsung_s6e3fa3x01_pinctrl_normal_cmds[] = {
	{DTYPE_PINCTRL_SET, &pctrl, DTYPE_PINCTRL_STATE_DEFAULT},
};

static struct pinctrl_cmd_desc samsung_s6e3fa3x01_pinctrl_lowpower_cmds[] = {
	{DTYPE_PINCTRL_SET, &pctrl, DTYPE_PINCTRL_STATE_IDLE},
};

static struct pinctrl_cmd_desc samsung_s6e3fa3x01_pinctrl_finit_cmds[] = {
	{DTYPE_PINCTRL_PUT, &pctrl, 0},
};

/*******************************************************************************
** GPIO
*/
#define GPIO_RESET_NAME	"gpio_lcd_reset"
#define GPIO_ID_NAME	"gpio_lcd_id0"
#define GPIO_VDDIO_ENABLE_NAME "gpio_lcd_tp1v8"
#define GPIO_PCD_NAME  "gpio_amoled_pcd"
#define GPIO_ERR_FLAG  "gpio_amoled_err_flag"
#define GPIO_VCC_3V3  "gpio_lcd_vcc3v3"


static uint32_t gpio_reset;  /*gpio_4_5, gpio_037*/
static uint32_t gpio_id;  /*gpio_4_6, gpio_038*/
static uint32_t gpio_vddio_enable; /*gpio_15_4, gpio_124*/
static uint32_t gpio_pcd; /*UL:gpio_039;CL:codec_gpio_024*/
static uint32_t gpio_err_flag; /*gpio_5_1, gpio_041*/
static uint32_t gpio_lcd_vcc3v3;

#ifndef AS_EXT_LCD
/***panel on**/
static struct gpio_desc samsung_s6e3fa3x01_gpio_request_cmds[] = {
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_VCC_3V3, &gpio_lcd_vcc3v3, 0},
	/*pcd*/
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_PCD_NAME, &gpio_pcd, 0},
	/*err flag*/
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_ERR_FLAG, &gpio_err_flag, 0},
	/* reset */
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_RESET_NAME, &gpio_reset, 0},
	/* id */
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_ID_NAME, &gpio_id, 0},
	/*vddio_enable*/
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_VDDIO_ENABLE_NAME, &gpio_vddio_enable, 0},
};

static struct gpio_desc samsung_s6e3fa3x01_gpio_sleep_request_cmds[] = {
	/*pcd*/
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_PCD_NAME, &gpio_pcd, 0},
	/*err flag*/
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_ERR_FLAG, &gpio_err_flag, 0},
	/* reset */
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_RESET_NAME, &gpio_reset, 0},
	/* id */
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_ID_NAME, &gpio_id, 0},
};

static struct gpio_desc samsung_s6e3fa3x01_gpio_normal_cmds[] = {
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 50,
		GPIO_VDDIO_ENABLE_NAME, &gpio_vddio_enable, 1},
	/*vddio enable*/
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 15,
		GPIO_VDDIO_ENABLE_NAME, &gpio_vddio_enable, 0},
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 20,
		GPIO_VCC_3V3, &gpio_lcd_vcc3v3, 1},
	/* reset */
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 15,
		GPIO_RESET_NAME, &gpio_reset, 1},
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5,
		GPIO_RESET_NAME, &gpio_reset, 0},
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 15,
		GPIO_RESET_NAME, &gpio_reset, 1},
	/* id */
	{DTYPE_GPIO_INPUT, WAIT_TYPE_MS, 1,
		GPIO_ID_NAME, &gpio_id, 0},
	/*pcd*/
	{DTYPE_GPIO_INPUT, WAIT_TYPE_MS, 1,
		GPIO_PCD_NAME, &gpio_pcd, 0},
	/*err flag*/
	{DTYPE_GPIO_INPUT, WAIT_TYPE_MS, 1,
		GPIO_ERR_FLAG, &gpio_err_flag, 0},
};

/***panel off***/
static struct gpio_desc samsung_s6e3fa3x01_gpio_lowpower_cmds[] = {
	/* reset */
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5,
		GPIO_RESET_NAME, &gpio_reset, 0},
	/*vddio disable*/
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 15,
		GPIO_VDDIO_ENABLE_NAME, &gpio_vddio_enable, 0},
	/* reset input */
	{DTYPE_GPIO_INPUT, WAIT_TYPE_US, 100,
		GPIO_RESET_NAME, &gpio_reset, 0},
	/*vddio_enable input*/
	{DTYPE_GPIO_INPUT, WAIT_TYPE_US, 100,
		GPIO_VDDIO_ENABLE_NAME, &gpio_vddio_enable, 0},
};

static struct gpio_desc samsung_s6e3fa3x01_gpio_sleep_lowpower_cmds[] = {
	/* reset */
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5,
		GPIO_RESET_NAME, &gpio_reset, 0},
	/* reset input */
	{DTYPE_GPIO_INPUT, WAIT_TYPE_US, 100,
		GPIO_RESET_NAME, &gpio_reset, 0},
};

static struct gpio_desc samsung_s6e3fa3x01_gpio_free_cmds[] = {
	/* reset */
	{DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
		GPIO_RESET_NAME, &gpio_reset, 0},
	/* id */
	{DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
		GPIO_ID_NAME, &gpio_id, 0},
	/*pcd*/
	{DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
		GPIO_PCD_NAME, &gpio_pcd, 0},
	/*err flag*/
	{DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
		GPIO_ERR_FLAG, &gpio_err_flag, 0},
	/*vddio_enable*/
	{DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
		GPIO_VDDIO_ENABLE_NAME, &gpio_vddio_enable, 0},
};

static struct gpio_desc samsung_s6e3fa3x01_gpio_sleep_free_cmds[] = {
	/* reset */
	{DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
		GPIO_RESET_NAME, &gpio_reset, 0},
	/* id */
	{DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
		GPIO_ID_NAME, &gpio_id, 0},
	/*pcd*/
	{DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
		GPIO_PCD_NAME, &gpio_pcd, 0},
	/*err flag*/
	{DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
		GPIO_ERR_FLAG, &gpio_err_flag, 0},
};

#else
/***panel on**/
static struct gpio_desc samsung_s6e3fa3x01_gpio_request_cmds[] = {
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_VCC_3V3, &gpio_lcd_vcc3v3, 0},
	/* reset */
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_RESET_NAME, &gpio_reset, 0},
};

static struct gpio_desc samsung_s6e3fa3x01_gpio_normal_cmds[] = {
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 20,
		GPIO_VCC_3V3, &gpio_lcd_vcc3v3, 1},
	/* reset */
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 15,
		GPIO_RESET_NAME, &gpio_reset, 1},
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5,
		GPIO_RESET_NAME, &gpio_reset, 0},
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 15,
		GPIO_RESET_NAME, &gpio_reset, 1},
};

/***panel off***/
static struct gpio_desc samsung_s6e3fa3x01_gpio_lowpower_cmds[] = {
	/* reset */
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5,
		GPIO_RESET_NAME, &gpio_reset, 0},
	/* reset input */
	{DTYPE_GPIO_INPUT, WAIT_TYPE_US, 100,
		GPIO_RESET_NAME, &gpio_reset, 0},
};

static struct gpio_desc samsung_s6e3fa3x01_gpio_free_cmds[] = {
	/* reset */
	{DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
		GPIO_RESET_NAME, &gpio_reset, 0},
	{DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
		GPIO_VCC_3V3, &gpio_lcd_vcc3v3, 0},
};

#endif

#ifdef AMOLED_CHECK_INT
static irqreturn_t pcd_irq_isr_func(int irq, void *handle)
{
	if(gpio_get_value_cansleep(gpio_pcd) == 0)
		HISI_FB_INFO("pcd irq!\n");
	else
		HISI_FB_DEBUG("bad pcd irq!\n");

	return IRQ_HANDLED;
}

static irqreturn_t errflag_irq_isr_func(int irq, void *handle)
{
	if(gpio_get_value_cansleep(gpio_err_flag) == 1)
		HISI_FB_INFO("err_flag irq!\n");
	else
		HISI_FB_DEBUG("bad err_flag irq!\n");

	return IRQ_HANDLED;
}

static void amoled_irq_enable(void)
{
	enable_irq(gpio_to_irq(gpio_pcd));
	enable_irq(gpio_to_irq(gpio_err_flag));
}

static void amoled_irq_disable(void)
{
	disable_irq(gpio_to_irq(gpio_pcd));
	disable_irq(gpio_to_irq(gpio_err_flag));
}
#endif

/*******************************************************************************
**
*/
static int mipi_samsung_s6e3fa3x01_set_fastboot(struct platform_device *pdev)
{
	struct hisi_fb_data_type *hisifd = NULL;

	BUG_ON(pdev == NULL);
	hisifd = platform_get_drvdata(pdev);
	BUG_ON(hisifd == NULL);

	HISI_FB_DEBUG("fb%d, +.\n", hisifd->index);

	/* pinctrl normal */
	pinctrl_cmds_tx(pdev, samsung_s6e3fa3x01_pinctrl_normal_cmds,
		ARRAY_SIZE(samsung_s6e3fa3x01_pinctrl_normal_cmds));

	/* gpio request */
	gpio_cmds_tx(samsung_s6e3fa3x01_gpio_request_cmds,
		ARRAY_SIZE(samsung_s6e3fa3x01_gpio_request_cmds));

	/* backlight on */
	hisi_lcd_backlight_on(pdev);

	HISI_FB_DEBUG("fb%d, -.\n", hisifd->index);

	return 0;
}

static int mipi_samsung_s6e3fa3x01_on(struct platform_device *pdev)
{
	struct hisi_fb_data_type *hisifd = NULL;
	struct hisi_panel_info *pinfo = NULL;
	char __iomem *mipi_dsi0_base = NULL;

	BUG_ON(pdev == NULL);
	hisifd = platform_get_drvdata(pdev);
	BUG_ON(hisifd == NULL);

	HISI_FB_ERR("fb%d, +!\n", hisifd->index);

	pinfo = &(hisifd->panel_info);
#ifndef AS_EXT_LCD
	mipi_dsi0_base = hisifd->mipi_dsi0_base;
#else
	mipi_dsi0_base = hisifd->mipi_dsi1_base;
#endif

	if (pinfo->lcd_init_step == LCD_INIT_POWER_ON) {
		//LOG_JANK_D(JLID_KERNEL_LCD_POWER_ON, "%s", "JL_KERNEL_LCD_POWER_ON");

		pinfo->lcd_init_step = LCD_INIT_MIPI_LP_SEND_SEQUENCE;
	} else if (pinfo->lcd_init_step == LCD_INIT_MIPI_LP_SEND_SEQUENCE) {
		/* pinctrl normal */
		pinctrl_cmds_tx(pdev, samsung_s6e3fa3x01_pinctrl_normal_cmds,
			ARRAY_SIZE(samsung_s6e3fa3x01_pinctrl_normal_cmds));
		/* gpio request */
		gpio_cmds_tx(samsung_s6e3fa3x01_gpio_request_cmds, \
			ARRAY_SIZE(samsung_s6e3fa3x01_gpio_request_cmds));

		/* gpio normal */
		gpio_cmds_tx(samsung_s6e3fa3x01_gpio_normal_cmds, \
			ARRAY_SIZE(samsung_s6e3fa3x01_gpio_normal_cmds));

		mipi_dsi_cmds_tx(display_on_cmds, \
			ARRAY_SIZE(display_on_cmds), mipi_dsi0_base);

		pinfo->lcd_init_step = LCD_INIT_MIPI_HS_SEND_SEQUENCE;
	} else if (pinfo->lcd_init_step == LCD_INIT_MIPI_HS_SEND_SEQUENCE) {
		/* backlight on */
		hisi_lcd_backlight_on(pdev);
		g_debug_enable = true;
#ifdef AMOLED_CHECK_INT
		amoled_irq_enable();
#endif
	} else {
		HISI_FB_ERR("failed to init!\n");
	}

	HISI_FB_INFO("fb%d, -!\n", hisifd->index);

	return 0;
}

static int mipi_samsung_s6e3fa3x01_off(struct platform_device *pdev)
{
	struct hisi_fb_data_type *hisifd = NULL;
	char __iomem *mipi_dsi0_base = NULL;

	BUG_ON(pdev == NULL);
	hisifd = platform_get_drvdata(pdev);
	BUG_ON(hisifd == NULL);

	HISI_FB_INFO("fb%d, +!\n", hisifd->index);
#ifndef AS_EXT_LCD
	mipi_dsi0_base = hisifd->mipi_dsi0_base;
#else
	mipi_dsi0_base = hisifd->mipi_dsi1_base;
#endif

#ifdef AMOLED_CHECK_INT
	amoled_irq_disable();
#endif
	/* display off sequence */
	mipi_dsi_cmds_tx(display_off_cmds, \
		ARRAY_SIZE(display_off_cmds), mipi_dsi0_base);

	/* gpio lowpower */
	gpio_cmds_tx(samsung_s6e3fa3x01_gpio_lowpower_cmds, \
		ARRAY_SIZE(samsung_s6e3fa3x01_gpio_lowpower_cmds));
	/* gpio free */
	gpio_cmds_tx(samsung_s6e3fa3x01_gpio_free_cmds, \
		ARRAY_SIZE(samsung_s6e3fa3x01_gpio_free_cmds));

	/* pinctrl lowpower */
	pinctrl_cmds_tx(pdev, samsung_s6e3fa3x01_pinctrl_lowpower_cmds,
		ARRAY_SIZE(samsung_s6e3fa3x01_pinctrl_lowpower_cmds));
	/* vcc disable */
	vcc_cmds_tx(pdev, samsung_s6e3fa3x01_vcc_disable_cmds,
		ARRAY_SIZE(samsung_s6e3fa3x01_vcc_disable_cmds));


	HISI_FB_INFO("fb%d, -!\n", hisifd->index);

	return 0;
}

static int mipi_samsung_s6e3fa3x01_remove(struct platform_device *pdev)
{
	struct hisi_fb_data_type *hisifd = NULL;

	BUG_ON(pdev == NULL);
	hisifd = platform_get_drvdata(pdev);

	if (!hisifd) {
		return 0;
	}

	HISI_FB_DEBUG("fb%d, +.\n", hisifd->index);

	/* vcc finit */
	vcc_cmds_tx(pdev, samsung_s6e3fa3x01_vcc_finit_cmds,
		ARRAY_SIZE(samsung_s6e3fa3x01_vcc_finit_cmds));

	/* pinctrl finit */
	pinctrl_cmds_tx(pdev, samsung_s6e3fa3x01_pinctrl_finit_cmds,
		ARRAY_SIZE(samsung_s6e3fa3x01_pinctrl_finit_cmds));

	HISI_FB_DEBUG("fb%d, -.\n", hisifd->index);

	return 0;
}

static int mipi_samsung_s6e3fa3x01_set_brightness(struct platform_device *pdev, uint32_t bl_level)
{
	struct hisi_fb_data_type *hisifd = NULL;
	char __iomem *mipi_dsi0_base = NULL;
	int ret = 0;

	char payload[2] = {0, 0};
	struct dsi_cmd_desc bl_cmd[] = {
		{DTYPE_DCS_WRITE1, 0, 500, WAIT_TYPE_US,
			sizeof(payload), payload},
	};

	BUG_ON(pdev == NULL);
	hisifd = platform_get_drvdata(pdev);
	BUG_ON(hisifd == NULL);

#ifndef AS_EXT_LCD
	mipi_dsi0_base = hisifd->mipi_dsi0_base;
#else
	mipi_dsi0_base = hisifd->mipi_dsi1_base;
#endif

	HISI_FB_DEBUG("fb%d, +.\n", hisifd->index);
	hisifd->bl_level = bl_level;

	if (unlikely(g_debug_enable)) {
		HISI_FB_INFO("Set brightness to %d\n", hisifd->bl_level);
		//LOG_JANK_D(JLID_KERNEL_LCD_BACKLIGHT_ON, "JL_KERNEL_LCD_BACKLIGHT_ON,%u", hisifd->bl_level);
		mipi_dsi_cmds_tx(display_on_cmd, ARRAY_SIZE(display_on_cmd), mipi_dsi0_base);
		//g_display_on = true;
		g_debug_enable = false;
	}

	if (hisifd->panel_info.bl_set_type & BL_SET_BY_PWM) {
		ret = hisi_pwm_set_backlight(hisifd, hisifd->bl_level);
	} else if (hisifd->panel_info.bl_set_type & BL_SET_BY_BLPWM) {
		ret = hisi_blpwm_set_backlight(hisifd, hisifd->bl_level);
	} else if (hisifd->panel_info.bl_set_type & BL_SET_BY_MIPI) {
		HISI_FB_DEBUG("set brightness by mipi\n");
		bl_cmd[0].payload[0] = 0x51;
		if(hisifd->bl_level>0&&hisifd->bl_level<hisifd->panel_info.bl_min){
		    bl_cmd[0].payload[1] = hisifd->panel_info.bl_min;
		}else{
		    bl_cmd[0].payload[1] = hisifd->bl_level;
		}

		mipi_dsi_cmds_tx(bl_cmd, ARRAY_SIZE(bl_cmd), mipi_dsi0_base);
	} else {
		HISI_FB_ERR("No such bl_set_type!\n");
	}

	HISI_FB_DEBUG("fb%d, -.\n", hisifd->index);

	return ret;
}

/******************************************************************************/
static ssize_t mipi_samsung_s6e3fa3x01_model_show(struct platform_device *pdev,
	char *buf)
{
	ssize_t ret = 0;

	ret = snprintf(buf, PAGE_SIZE, "Amoled-s6e3fa3x01\n");
	return ret;
}

static ssize_t mipi_samsung_pcd_errflag_check(struct platform_device *pdev,
	char *buf)
{
	int pcd_gpio = 0;
	int errflag_gpio = 0;
	ssize_t ret = 0;
	u8 result_value = 0;

	struct hisi_fb_data_type *hisifd = NULL;

	BUG_ON(pdev == NULL);
	hisifd = platform_get_drvdata(pdev);

	if (!hisifd) {
		HISI_FB_ERR("hisifd is null\n");
		ret = snprintf(buf, PAGE_SIZE, "%d\n", result_value);
		return ret;
	}

	if (!hisifd->panel_power_on){
		HISI_FB_INFO("panel is poweroff\n");
		ret = snprintf(buf, PAGE_SIZE, "%d\n", result_value);
		return ret;
	}
#ifdef AS_EXT_LCD
	return 0;
#endif
	pcd_gpio = gpio_get_value_cansleep(gpio_pcd);
	errflag_gpio = gpio_get_value_cansleep(gpio_err_flag);

	HISI_FB_INFO("pcd:%d, errflag:%d\n", pcd_gpio, errflag_gpio);

	if ((pcd_gpio == 1) && (errflag_gpio == 0)) {
		result_value = 0; // PCD_ERR_FLAG_SUCCESS
	} else if ((pcd_gpio == 0) && (errflag_gpio == 0)) {
		result_value = 1; //only  PCD_FAIL
	} else if ((pcd_gpio == 1) && (errflag_gpio == 1)) {
		result_value = 2; //only ERRFLAG FAIL
	} else if ((pcd_gpio == 0) && (errflag_gpio == 1)) {
		result_value = 3; //PCD_ERR_FLAG_FAIL
	} else
		result_value = 0;

	ret = snprintf(buf, PAGE_SIZE, "%d\n", result_value);
	return ret;
}

static int mipi_samsung_s6e3fa3x01_set_display_region(struct platform_device *pdev,
	struct dss_rect *dirty)
{
	struct hisi_fb_data_type *hisifd = NULL;

	BUG_ON(pdev == NULL || dirty == NULL);
	hisifd = platform_get_drvdata(pdev);
	BUG_ON(hisifd == NULL);

	return 0;
}

static struct hisi_panel_info samsung_s6e3fa3x01_panel_info = {0};
static struct hisi_fb_panel_data samsung_s6e3fa3x01_panel_data = {
	.panel_info = &samsung_s6e3fa3x01_panel_info,
	.set_fastboot = mipi_samsung_s6e3fa3x01_set_fastboot,
	.on = mipi_samsung_s6e3fa3x01_on,
	.off = mipi_samsung_s6e3fa3x01_off,
	.remove = mipi_samsung_s6e3fa3x01_remove,
	.set_backlight = mipi_samsung_s6e3fa3x01_set_brightness,

	.lcd_model_show = mipi_samsung_s6e3fa3x01_model_show,
	.amoled_pcd_errflag_check = mipi_samsung_pcd_errflag_check,
	.set_display_region = mipi_samsung_s6e3fa3x01_set_display_region,
};

/*******************************************************************************
**
*/
static int mipi_samsung_s6e3fa3x01_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct hisi_panel_info *pinfo = NULL;
	struct device_node *np = NULL;

	if (NULL == pdev) {
		HISI_FB_ERR("pdev is null .\n");
		return 0;
	}

	if (hisi_fb_device_probe_defer(PANEL_MIPI_CMD, 8))
		goto err_probe_defer;

	np = of_find_compatible_node(NULL, NULL, DTS_COMP_SAMSUNG_S6E3FA3X01);
	if (!np) {
		HISI_FB_ERR("NOT FOUND device node %s!\n", DTS_COMP_SAMSUNG_S6E3FA3X01);
		goto err_return;
	}

#ifndef AS_EXT_LCD
	gpio_reset = of_get_named_gpio(np, "gpios", 3);  /*gpio_055*/
	gpio_id = of_get_named_gpio(np, "gpios", 4);  /*gpio_0*/
	gpio_vddio_enable = of_get_named_gpio(np, "gpios", 0);  /*gpio_0*/
	gpio_pcd = of_get_named_gpio(np, "gpios", 7);	/*gpio_0*/
	gpio_err_flag = of_get_named_gpio(np, "gpios", 8); /*gpio_0*/
	gpio_lcd_vcc3v3 = of_get_named_gpio(np, "gpios", 9);/*gpio_029*/
#else
	gpio_reset = of_get_named_gpio(np, "gpios", 2);  /*gpio_055*/
	gpio_lcd_vcc3v3 = of_get_named_gpio(np, "gpios", 3);/*gpio_029*/
#endif
	HISI_FB_INFO("gpio_reset:%d\n",gpio_reset);
	HISI_FB_INFO("gpio_id:%d\n",gpio_id);
	HISI_FB_INFO("gpio_vddio_enable:%d\n",gpio_vddio_enable);
	HISI_FB_INFO("gpio_err_flag:%d\n",gpio_err_flag);
	HISI_FB_INFO("gpio_lcd_vcc3v3:%d\n",gpio_lcd_vcc3v3);

	/* init panel info */
	pinfo = samsung_s6e3fa3x01_panel_data.panel_info;
	memset(pinfo, 0, sizeof(struct hisi_panel_info));

#ifndef AS_EXT_LCD
	pdev->id = 1;
	pinfo->type = PANEL_MIPI_CMD;
#else
	pdev->id = 2;
	pinfo->type = PANEL_MIPI_CMD;
#endif

    pinfo->xres = 1080;
	pinfo->yres = 1920;
	pinfo->width  = 68;  //mm
	pinfo->height = 121; //mm
	pinfo->orientation = LCD_PORTRAIT;
	pinfo->bpp = LCD_RGB888;
	pinfo->bgr_fmt = LCD_RGB;
	pinfo->bl_set_type = BL_SET_BY_MIPI;

	pinfo->bl_min = 4;
	pinfo->bl_max = 255;
	pinfo->mipi.max_tx_esc_clk = 10 * 1000000;
	pinfo->vsync_ctrl_type = 0;// (VSYNC_CTRL_ISR_OFF | VSYNC_CTRL_MIPI_ULPS | VSYNC_CTRL_CLK_OFF);
	HISI_FB_INFO("vsync_ctrl_type enable clk off\n");

	pinfo->frc_enable = 0;
	pinfo->esd_enable = 0;
	pinfo->dirty_region_updt_support = 0;



	pinfo->ifbc_type = 0;//IFBC_TYPE_NON

	pinfo->ldi.h_back_porch = 23;
	pinfo->ldi.h_front_porch = 50;
	pinfo->ldi.h_pulse_width = 20;
	pinfo->ldi.v_back_porch = 12;
	pinfo->ldi.v_front_porch = 14;
	pinfo->ldi.v_pulse_width = 4;

	pinfo->mipi.lane_nums = DSI_4_LANES;
	pinfo->mipi.color_mode = DSI_24BITS_1;
	pinfo->mipi.vc = 0;
	pinfo->mipi.dsi_bit_clk = 480;
	pinfo->dsi_bit_clk_upt_support = 0;
	pinfo->mipi.dsi_bit_clk_upt = pinfo->mipi.dsi_bit_clk;

	pinfo->pxl_clk_rate = 238*1000000UL;

	/* vcc init */
	ret = vcc_cmds_tx(pdev, samsung_s6e3fa3x01_vcc_init_cmds,
		ARRAY_SIZE(samsung_s6e3fa3x01_vcc_init_cmds));
	if (ret != 0) {
		HISI_FB_ERR("vcc init failed!\n");
		goto err_return;
	}

#ifdef AMOLED_CHECK_INT
	ret = request_threaded_irq(gpio_to_irq(gpio_pcd), NULL, pcd_irq_isr_func,
			IRQF_ONESHOT | IRQF_TRIGGER_FALLING,
			"pcd_irq", (void *)pdev);
	if (ret != 0) {
		HISI_FB_ERR("request_irq failed, irq_no=%d error=%d!\n", gpio_to_irq(gpio_pcd), ret);
	}

	ret = request_threaded_irq(gpio_to_irq(gpio_err_flag), NULL, errflag_irq_isr_func,
			IRQF_ONESHOT | IRQF_TRIGGER_RISING,
			"errflag_irq", (void *)pdev);
	if (ret != 0) {
		HISI_FB_ERR("request_irq failed, irq_no=%d error=%d!\n", gpio_to_irq(gpio_err_flag), ret);
	}
#endif

	if (fastboot_set_needed) {
		vcc_cmds_tx(pdev, samsung_s6e3fa3x01_vcc_enable_cmds,
			ARRAY_SIZE(samsung_s6e3fa3x01_vcc_enable_cmds));
	}

	/* pinctrl init */
	ret = pinctrl_cmds_tx(pdev, samsung_s6e3fa3x01_pinctrl_init_cmds,
			ARRAY_SIZE(samsung_s6e3fa3x01_pinctrl_init_cmds));
	if (ret != 0) {
	        HISI_FB_ERR("Init pinctrl failed, defer\n");
		goto err_return;
	}

	/* alloc panel device data */
	ret = platform_device_add_data(pdev, &samsung_s6e3fa3x01_panel_data,
		sizeof(struct hisi_fb_panel_data));
	if (ret) {
		HISI_FB_ERR("platform_device_add_data failed!\n");
		goto err_device_put;
	}

	hisi_fb_add_device(pdev);

	HISI_FB_INFO("-.\n");

	return 0;

err_device_put:
	platform_device_put(pdev);
err_return:
	return ret;
err_probe_defer:
	return -EPROBE_DEFER;

	return ret;
}
/*lint -restore*/
static const struct of_device_id hisi_panel_match_table[] = {
    {
        .compatible = DTS_COMP_SAMSUNG_S6E3FA3X01,
        .data = NULL,
    },
    {},
};
MODULE_DEVICE_TABLE(of, hisi_panel_match_table);

static struct platform_driver this_driver = {
	.probe = mipi_samsung_s6e3fa3x01_probe,
	.remove = NULL,
	.suspend = NULL,
	.resume = NULL,
	.shutdown = NULL,
	.driver = {
		.name = "mipi_samsung_S6E3FA3X01",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(hisi_panel_match_table),
	},
};

static int __init mipi_samsung_s6e3fa3x01_init(void)
{
	int ret = 0;

	ret = platform_driver_register(&this_driver);
	if (ret) {
		HISI_FB_ERR("platform_driver_register failed, error=%d!\n", ret);
		return ret;
	}

	return ret;
}

module_init(mipi_samsung_s6e3fa3x01_init);

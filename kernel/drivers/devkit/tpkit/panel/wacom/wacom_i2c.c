/*
 * Wacom Penabled Driver for I2C
 *
 * Copyright (c) 2011-2014 Tatsunosuke Tobita, Wacom.
 * <tobita.tatsunosuke@wacom.co.jp>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software
 * Foundation; either version of 2 of the License,
 * or (at your option) any later version.
 */
#include "wacom.h"
#include "wac_flash.h"
#include <linux/ctype.h>
#include "../../../lcdkit/include/lcdkit_panel.h"
#include "wac_test.h"
//dts
#define WACOM_IRQ_GPIO "attn_gpio"
#define WACOM_RST_GPIO "reset_gpio"
#define WACOM_VDDIO_GPIO_CTRL "vddio_ctrl_gpio"
#define WACOM_VCI_GPIO_CTRL "vci_ctrl_gpio"
#define WACOM_IRQ_CFG "irq_config"
#define WACOM_ALGO_ID "algo_id"
#define WACOM_VCI	 "wacom_vci"
#define WACOM_VDDIO	 "wacom_vddio"
#define WACOM_VCI_GPIO_TYPE	 "vci_gpio_type"
#define WACOM_VCI_REGULATOR_TYPE	 "vci_regulator_type"
#define WACOM_VDDIO_GPIO_TYPE	 "vddio_gpio_type"
#define WACOM_VDDIO_REGULATOR_TYPE	 "vddio_regulator_type"
#define WACOM_VDDIO_LDO_VALUE	 "vddio_ldo_value"
#define WACOM_VCI_LDO_VALUE	 "vci_ldo_value"
//#define WACOM_VCI_LDO_NEED_SET  "vci_ldo_need_set"
#define WACOM_VDDIO_LDO_NEED_SET  "vddio_ldo_need_set"
#define WACOM_SLAVE_ADDR			"slave_address"
#define WACOM_TP_IC_TYPE	 "ic_type"
#define WACOM_TP_DOZE_ENABLE 	"doze_mode_enable"

#define WACOM_X_MAX "x_max"
#define WACOM_Y_MAX "y_max"
#define WACOM_TOUCH_REPORT_X_MAX "touch_report_x_max"
#define WACOM_TOUCH_REPORT_Y_MAX "touch_report_y_max"
#define WACOM_PEN_REPORT_X_MAX "pen_report_x_max"
#define WACOM_PEN_REPORT_Y_MAX "pen_report_y_max"
#define WACOM_PEN_MAX_PRESSURE "pen_max_pressure"
#define WACOM_PID_NUM "pid_num"
#define WACOM_PID "pid"

#define WACOM_PEN_MODE_SUPPORTED		"pen_mode_supported"

#define WACOM_WAKELOCK_NAME		 "wacom_tp"

#define CHECK_RETRY_TIMES     3

#define GPIO_OUTPUT_LOW  0
#define GPIO_OUTPUT_HIGH 1

#define GPIO_TYPE  1
#define REGULATOR_TYPE 1

#define WACOM_RESET_DELAY  150

#define PRODUCT_NAME_IN_PROJECT_ID_LEN 4


extern struct lcdkit_panel_data lcdkit_info;
#define LCD_MODULE_INX "inx"
#define LCD_MODULE_BOE "boe"
struct wacom_i2c *wac_data = NULL;


static DEFINE_MUTEX(ts_power_gpio_sem);
static int ts_power_gpio_ref = 0;

extern struct ts_kit_platform_data g_ts_kit_platform_data;

atomic_t wacom_mmi_test_status = ATOMIC_INIT(WACOM_CAP_TEST_INIT_OR_END);
atomic_t wacom_fw_updating_status = ATOMIC_INIT(WACOM_FW_UPDATE_INIT_OR_END);

static int wacom_gpio_free(void);
static void wacom_regulator_put(void);
static int wacom_chip_detect(struct ts_kit_platform_data *platform_data);
static int wacom_init_chip(void);
int wacom_parse_dts(struct device_node * device, struct ts_kit_device_data * chip_data);
static int wacom_input_config(struct input_dev *input);
static int wacom_pen_config(struct input_dev *input );
static int wacom_irq_top_half(struct ts_cmd_node *cmd);
static int wacom_irq_bottom_half(struct ts_cmd_node *in_cmd, struct ts_cmd_node *out_cmd);
static int wacom_gpio_reset(void);
static void wacom_power_on(void);
static void wacom_power_off(void);
static int wacom_suspend(void);
static int wacom_resume(void);
static void wacom_shutdown(void);

static int wacom_get_rawdata(struct ts_rawdata_info *info, struct ts_cmd_node *out_cmd);
static int wacom_fw_update_boot(char *file_name);
static int wacom_fw_update_sd(void);
static int wacom_set_info_flag(struct ts_kit_platform_data *info);
static int wacom_chip_get_info(struct ts_chip_info_param *info);
int wacom_fw_update(const u8 *fw_filename);
int wacom_gather_info(u16 *pid, u16 *fw_version);
int wacom_get_hw_pinid(unsigned char *pin_id);
static int wacom_chip_get_capacitance_test_type(struct ts_test_type_info *info);


struct ts_device_ops ts_kit_wacom_ops= {
	.chip_detect = wacom_chip_detect,
	.chip_init = wacom_init_chip,
	.chip_parse_config = wacom_parse_dts,
	.chip_input_config = wacom_input_config,
	.chip_input_pen_config = wacom_pen_config,
	.chip_irq_top_half = wacom_irq_top_half,
	.chip_irq_bottom_half = wacom_irq_bottom_half,
	.chip_reset = wacom_gpio_reset,
	.chip_shutdown = wacom_shutdown,
	.chip_suspend = wacom_suspend,
	.chip_resume = wacom_resume,
	.chip_fw_update_boot = wacom_fw_update_boot,
	.chip_fw_update_sd = wacom_fw_update_sd,
	.chip_get_info = wacom_chip_get_info,
	.chip_get_rawdata = wacom_get_rawdata,
	.chip_get_capacitance_test_type = wacom_chip_get_capacitance_test_type,
};
static int wacom_chip_get_capacitance_test_type(struct ts_test_type_info *info)
{
	int error = NO_ERR;
	struct wacom_i2c *data = wac_data;

	if (!info || !data) {
		TS_LOG_ERR("%s:info=%ld\n", __func__, PTR_ERR(info));
		error = -ENOMEM;
		return error;
	}
	switch (info->op_action) {
	case TS_ACTION_READ:
		memcpy(info->tp_test_type, data->wacom_chip_data->tp_test_type,
		       TS_CAP_TEST_TYPE_LEN);
		TS_LOG_INFO("read_chip_get_test_type=%s, \n",
			    info->tp_test_type);
		break;
	case TS_ACTION_WRITE:
		break;
	default:
		TS_LOG_ERR("invalid status: %s", info->tp_test_type);
		error = -EINVAL;
		break;
	}
	return error;
}


static int wacom_get_rawdata(struct ts_rawdata_info *info, struct ts_cmd_node *out_cmd)
{
	int retval = NO_ERR;
	if( (!info ) || (!out_cmd ) )
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}
	if(atomic_read(&wacom_mmi_test_status)){
		TS_LOG_ERR("%s factory test already has been called.\n",__func__);
		return -EINVAL;
	}
	atomic_set(&wacom_mmi_test_status, WACOM_CAP_TEST_DOING);

	retval = wacom_fac_test(info, out_cmd);

	atomic_set(&wacom_mmi_test_status, WACOM_CAP_TEST_INIT_OR_END);
	return retval;
}

//ok return 0 , fail return minus number.
int read_lcd_module(void)
{
	int retval = NO_ERR;

	if( !wac_data ) {
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}

	TS_LOG_INFO("%s: lcd module name is %s.\n", __func__, wac_data->lcd_panel_info);

	if (NULL != strstr(wac_data->lcd_panel_info, LCD_MODULE_INX)){
		strncpy(wac_data->lcd_module_name, "inx", MAX_STR_LEN-1);
	} else if (NULL != strstr(wac_data->lcd_panel_info, LCD_MODULE_BOE)){
		strncpy(wac_data->lcd_module_name, "boe", MAX_STR_LEN-1);
	}else{
		TS_LOG_ERR("%s: lcd module name is ERROR!\n", __func__);
		//return -EINVAL;
		strncpy(wac_data->lcd_module_name, "inx", MAX_STR_LEN-1);
	}
	return retval;
}

//ok return 0 , fail return minus number.
static int wacom_get_project_IC_id(void)
{
	int retval = NO_ERR;
	int chip_id = CHIP_UNKNOWN_ID;
	int i = 0;
	char tmp_buff[PRODUCT_NAME_IN_PROJECT_ID_LEN + 1 ] = {0};

	if( !wac_data )
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}

	/*get product name*/
	for (i = 0; g_ts_kit_platform_data.product_name[i] && i < PRODUCT_NAME_IN_PROJECT_ID_LEN; i++) 	{
		tmp_buff[i] = toupper(g_ts_kit_platform_data.product_name[i]); //exchange name to upper
	}

	/* get chip id */
	if(!strcmp("W9015", wac_data->chip_name)) {
		chip_id = CHIP_W9015_ID;
	}else {
		retval =  -EINVAL;
		TS_LOG_ERR("%s: get chip id failed!\n", __func__);
		goto out;
	}

	/* create project id: AAAABBCCC, CAME58  */
	snprintf(wac_data->project_id, MAX_STR_LEN-1, "%s%02d",
			tmp_buff, chip_id);
	TS_LOG_INFO("%s: create project ic id successful: %s!\n", __func__, wac_data->project_id);

out:
	return retval;
}

//ok return 0 , fail return minus number.
static int wacom_get_LCM_panel_id(u16 pid)
{
	int retval = NO_ERR;
	int chip_id = CHIP_UNKNOWN_ID;
	int i = 0;

	if( !wac_data )
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}

	wac_data->tp_pin_id = HW_PINID_UNKNOWN;
	wac_data->project_id_reserved_bit = UNKNOWN_BIT;
	wac_data->panel_id = MODULE_UNKNOW_ID;


	if(pid == LCM_PID_UNKNOWN ) {
		/*get module name*/
		retval = wacom_get_hw_pinid(&(wac_data->tp_pin_id));
		if(retval != NO_ERR){
			retval =  -EINVAL;
			TS_LOG_ERR("%s: get hw pin id failed!\n", __func__);
			goto out;
		}
	} else{
		switch (pid) {
			case LCM_OFILM_FUJIMESH_BOE:
			case LCM_OFILM_FUJIMESH_INX:
				wac_data->tp_pin_id = HW_PINID_OFILM_FUJIMESH;
				break;
			case LCM_OFILM_OFILMMESH_BOE:
			case LCM_OFILM_OFILMMESH_INX:
				wac_data->tp_pin_id = HW_PINID_OFILM_OFILMMESH;
				break;
			case LCM_JUNDA_FUJIMESH_BOE:
			case LCM_JUNDA_FUJIMESH_INX:
				wac_data->tp_pin_id = HW_PINID_JUNDA_FUJIMESH;
				break;
			default:
				TS_LOG_ERR("%s: pid  %x is invalid!\n", __func__, pid);
				break;
		}
	}

	TS_LOG_INFO("%s: hw pinid is %d\n", __func__, wac_data->tp_pin_id);

	switch (wac_data->tp_pin_id) {
		case HW_PINID_OFILM_FUJIMESH:
			strncpy(wac_data->tp_module_name, "ofilm", MAX_STR_LEN-1);
			wac_data->panel_id = MODULE_OFILM_ID;
			wac_data->project_id_reserved_bit = RESERVED_BIT_ZERO;
			break;
		case HW_PINID_JUNDA_FUJIMESH:
			strncpy(wac_data->tp_module_name, "junda", MAX_STR_LEN-1);
			wac_data->panel_id = MODULE_JUNDA_ID;
			wac_data->project_id_reserved_bit = RESERVED_BIT_ZERO;
			break;
		case HW_PINID_OFILM_OFILMMESH:
			strncpy(wac_data->tp_module_name, "ofilm", MAX_STR_LEN-1);
			wac_data->panel_id = MODULE_OFILM_ID;
			wac_data->project_id_reserved_bit = RESERVED_BIT_ONE;
			break;
		default:
			strncpy(wac_data->tp_module_name, "junda", MAX_STR_LEN-1);
			wac_data->panel_id = MODULE_JUNDA_ID;
			wac_data->project_id_reserved_bit = RESERVED_BIT_ZERO;
			break;
	}

	if(retval < 0) {
		TS_LOG_ERR("%s: get module name failed!\n", __func__);
		goto out;
	}

	/* create project id: AAAABBCCC, CAME58000  */
	snprintf(wac_data->project_id + strlen(wac_data->project_id), MAX_STR_LEN-1, "%02d%d",	wac_data->panel_id, wac_data->project_id_reserved_bit);
	TS_LOG_INFO("%s: create project id successful: %s!\n", __func__, wac_data->project_id);

out:
	return retval;
}

static void wacom_get_fw_name(char *file_name)
{
	if( !file_name || !wac_data )
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return;
	}
	strncat(file_name, wac_data->project_id, MAX_STR_LEN);
	strncat(file_name, "_", 1);
	strncat(file_name, wac_data->tp_module_name, MAX_STR_LEN);
	strncat(file_name, "_", 1);
	strncat(file_name, wac_data->lcd_module_name, MAX_STR_LEN);

	//firmware name is like:cameron_W9015_CAME58000_ofilm_inx
	TS_LOG_INFO("%s, firmware name: %s\n",__func__,file_name);
}

static int wacom_refresh_tp_info(void)
{
	if((!wac_data) || (!wac_data->wacom_chip_data) ){
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}

	wacom_gather_info(&wac_data->dev_pid, &wac_data->dev_fw_version);
	memset(wac_data->wacom_chip_data->version_name, 0, MAX_STR_LEN);
	snprintf(wac_data->wacom_chip_data->version_name, MAX_STR_LEN -1, "0x%x",wac_data->dev_fw_version);
	memset(wac_data->wacom_chip_data->module_name, 0, MAX_STR_LEN);
	snprintf(wac_data->wacom_chip_data->module_name, MAX_STR_LEN -1, "%s",wac_data->tp_module_name);
	return NO_ERR;
}

static int wacom_fw_update_boot(char *file_name)
{
	int rc = NO_ERR;
	int retry = CHECK_RETRY_TIMES;
	u16 pid = LCM_PID_UNKNOWN;

	if( !file_name || !wac_data )
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}

	atomic_set(&wacom_fw_updating_status, WACOM_FW_UPDATE_DOING);

	wac_data->dev_pid = 0;
	wac_data->dev_fw_version = 0;
	wac_data->fw_restore = false;

upgrade_firmware_again:
	rc = wacom_gather_info(&wac_data->dev_pid, &wac_data->dev_fw_version);
	TS_LOG_INFO("dev_pid:0x%x, dev_fw_version:0x%x \n", wac_data->dev_pid, wac_data->dev_fw_version);

	if(wac_data->dev_pid == UBL_G11T_UBL_PID){
		wac_data->is_firmware_broken = true;

		strncat(file_name, "cameron_wacom", MAX_STR_LEN-1);
		TS_LOG_INFO("%s: tp firmware is broken,use default fw name %s.\n", __func__,file_name);

		#if defined (CONFIG_HUAWEI_DSM)
			wac_data->wacom_chip_data->ts_platform_data->dsm_info.constraints_UPDATE_status = FWU_FW_CRC_ERROR;
			ts_dmd_report(DSM_TP_FW_CRC_ERROR_NO, "wacom ts CRC error.\n");
		#endif
	}else{
		wac_data->is_firmware_broken = false;

		if(wac_data->fw_restore == false){
			//first firmware is ok
			pid = wac_data->dev_pid;
		} else {
			//first firmware is not ok,need check second firmware update status
			pid = LCM_PID_UNKNOWN;
		}

		rc = wacom_get_project_IC_id();
		if (rc < 0) {
			TS_LOG_ERR("%s: get project id failed!\n", __func__);
			goto  err_out;
		}

		rc = wacom_get_LCM_panel_id(pid);
		if (rc < 0) {
			TS_LOG_ERR("%s: get project id failed!\n", __func__);
			goto  err_out;
		}

		rc = read_lcd_module();
		if (rc < 0) {
			TS_LOG_ERR("%s: read lcd module failed!\n", __func__);
			goto  err_out;
		}

		wacom_get_fw_name(file_name);
	}

	rc = wacom_fw_update(file_name);
	if(rc != NO_ERR) {
		TS_LOG_ERR("%s: wacom fw update failed!\n", __func__);
		goto err_out;
	}

	if(wac_data->is_firmware_broken && retry > 0){
		retry--;
		wac_data->fw_restore = true;
		TS_LOG_INFO("%s, wacom firmware is broken,upgrade again:%d.\n",__func__,retry);
		goto upgrade_firmware_again;
	}

	rc = NO_ERR;
err_out:
	wacom_refresh_tp_info();
	TS_LOG_INFO("%s, end\n", __func__);
	atomic_set(&wacom_fw_updating_status, WACOM_FW_UPDATE_INIT_OR_END);
	return rc;
}
static int wacom_fw_update_sd(void)
{
	int rc = NO_ERR;

	TS_LOG_INFO("%s, enter\n", __func__);
	if(!wac_data){
		TS_LOG_ERR("%s , wac_data invalid\n", __func__);
		return -EINVAL;
	}

	atomic_set(&wacom_fw_updating_status, WACOM_FW_UPDATE_DOING);
	wac_data->wacom_update_firmware_from_sd_flag = true;
	rc = wacom_fw_update("sdcard_cmr_wacom");
	if(rc != NO_ERR)
	{
		TS_LOG_ERR("%s: wacom fw update failed!\n", __func__);
	}
	TS_LOG_INFO("%s, end\n", __func__);
	wac_data->wacom_update_firmware_from_sd_flag = false;
	atomic_set(&wacom_fw_updating_status, WACOM_FW_UPDATE_INIT_OR_END);
	return rc;
}

static int wacom_chip_get_info(struct ts_chip_info_param *info)
{
	if( (!info) || (!wac_data) )
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}

	snprintf(info->ic_vendor, CHIP_INFO_LENGTH * 2-1, "%s-%s-%s-%s",g_ts_kit_platform_data.product_name,\
		wac_data->chip_vendor,wac_data->chip_name, wac_data->project_id);
	snprintf(info->mod_vendor, CHIP_INFO_LENGTH, "%s-%s", wac_data->tp_module_name, wac_data->lcd_module_name);
	snprintf(info->fw_vendor, CHIP_INFO_LENGTH, "0x%x", wac_data->dev_fw_version);
	return NO_ERR;

}


static int wacom_suspend(void)
{
	if(atomic_read(&wacom_mmi_test_status)) {
		TS_LOG_INFO("%s: tp mmi is testing, return\n", __func__);
		return NO_ERR;
	}
	if(atomic_read(&wacom_fw_updating_status))
	{
		TS_LOG_INFO("%s: tp fw is updating, return. \n", __func__);
		return NO_ERR;
	}

	wacom_power_off();
	return NO_ERR;
}

static int wacom_resume(void)
{
	if(atomic_read(&wacom_mmi_test_status)) {
		TS_LOG_INFO("%s: tp mmi is testing, return\n", __func__);
		return NO_ERR;
	}
	if(atomic_read(&wacom_fw_updating_status))
	{
		TS_LOG_INFO("%s: tp fw is updating, return. \n", __func__);
		return NO_ERR;
	}

	TS_LOG_INFO("wacom resume\n");

	wacom_power_on();
	wacom_gpio_reset();
	msleep(600);//delay for v2
	return NO_ERR;
}

static void wacom_shutdown(void)
{
	if( (!wac_data) || (!wac_data->wacom_chip_data) )
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return;
	}

	if(atomic_read(&wacom_mmi_test_status)) {
		TS_LOG_INFO("%s: tp mmi is testing, return\n", __func__);
		return;
	}
	if(atomic_read(&wacom_fw_updating_status))
	{
		TS_LOG_INFO("%s: tp fw is updating, return. \n", __func__);
		return;
	}

	TS_LOG_INFO("wacom_shutdown\n");

	if ((GPIO_TYPE== wac_data->wacom_chip_data->vci_gpio_type) && (GPIO_TYPE == wac_data->wacom_chip_data->vddio_gpio_type)) {
		TS_LOG_INFO("Both  vci and vddio were need to output 0\n");
		if (wac_data->wacom_chip_data->vci_gpio_ctrl == wac_data->wacom_chip_data->vddio_gpio_ctrl) {
			gpio_direction_output(wac_data->wacom_chip_data->vci_gpio_ctrl, GPIO_OUTPUT_LOW);
		} else {
			gpio_direction_output(wac_data->wacom_chip_data->vddio_gpio_ctrl, GPIO_OUTPUT_LOW);
			msleep(2);
			gpio_direction_output(wac_data->wacom_chip_data->vci_gpio_ctrl, GPIO_OUTPUT_LOW);
		}
	} else if (GPIO_TYPE == wac_data->wacom_chip_data->vci_gpio_type){
		TS_LOG_INFO("Only vci was need to output 0\n");
		gpio_direction_output(wac_data->wacom_chip_data->vci_gpio_ctrl, GPIO_OUTPUT_LOW);
	} else if (GPIO_TYPE == wac_data->wacom_chip_data->vddio_gpio_type) {
	TS_LOG_INFO("Only vddio was need to output 0\n");
		gpio_direction_output(wac_data->wacom_chip_data->vddio_gpio_ctrl, GPIO_OUTPUT_LOW);
	}
	wacom_gpio_free();
	wacom_regulator_put();
	return;
}

static int wacom_regulator_get(void)
{
	if( (!wac_data) || (!wac_data->wacom_chip_data) || (!wac_data->wacom_dev) )
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}

	if (REGULATOR_TYPE == wac_data->wacom_chip_data->vci_regulator_type) {
		wac_data->tp_vci = regulator_get(&wac_data->wacom_dev->dev, WACOM_VCI);
		if (IS_ERR(wac_data->tp_vci)) {
			TS_LOG_ERR("regulator tp vci not used\n");
			return  -EINVAL;
		}
	}

	if (REGULATOR_TYPE == wac_data->wacom_chip_data->vddio_regulator_type) {
		wac_data->tp_vddio = regulator_get(&wac_data->wacom_dev->dev, WACOM_VDDIO);
		if (IS_ERR(wac_data->tp_vddio)) {
			TS_LOG_ERR("regulator tp vddio not used\n");
			regulator_put(wac_data->tp_vci);
			return -EINVAL;
		}
	}

	return NO_ERR;
}

static int wacom_gpio_request(void)
{
	int retval = NO_ERR;

	if( (!wac_data ) || (!wac_data->wacom_chip_data) )
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}

	TS_LOG_INFO("wacom_gpio_request\n");

	if ((GPIO_TYPE == wac_data->wacom_chip_data->vci_gpio_type) && (GPIO_TYPE == wac_data->wacom_chip_data->vddio_gpio_type)) {
		if (wac_data->wacom_chip_data->vci_gpio_ctrl == wac_data->wacom_chip_data->vddio_gpio_ctrl) {
			retval = gpio_request(wac_data->wacom_chip_data->vci_gpio_ctrl, "ts_vci_gpio");
			if (retval) {
				TS_LOG_ERR("unable to request vci_gpio_ctrl firset:%d\n", wac_data->wacom_chip_data->vci_gpio_ctrl);
				goto ts_vci_out;
			}
		} else {
			retval = gpio_request(wac_data->wacom_chip_data->vci_gpio_ctrl, "ts_vci_gpio");
			if (retval) {
				TS_LOG_ERR("unable to request vci_gpio_ctrl:%d\n", wac_data->wacom_chip_data->vci_gpio_ctrl);
				goto ts_vci_out;
			}
			retval = gpio_request(wac_data->wacom_chip_data->vddio_gpio_ctrl, "ts_vddio_gpio");
			if (retval) {
				TS_LOG_ERR("unable to request vddio_gpio_ctrl:%d\n", wac_data->wacom_chip_data->vddio_gpio_ctrl);
				goto ts_vddio_out;
			}
		}
	} else {
		if (GPIO_TYPE == wac_data->wacom_chip_data->vci_gpio_type) {
			retval = gpio_request(wac_data->wacom_chip_data->vci_gpio_ctrl, "ts_vci_gpio");
			if (retval) {
				TS_LOG_ERR("unable to request vci_gpio_ctrl:%d\n", wac_data->wacom_chip_data->vci_gpio_ctrl);
				goto ts_vci_out;
			}
		}
		if (GPIO_TYPE == wac_data->wacom_chip_data->vddio_gpio_type) {
			retval = gpio_request(wac_data->wacom_chip_data->vddio_gpio_ctrl, "ts_vddio_gpio");
			if (retval) {
				TS_LOG_ERR("unable to request vddio_gpio_ctrl:%d\n", wac_data->wacom_chip_data->vddio_gpio_ctrl);
				goto ts_vddio_out;
			}
		}
	}

	return retval;
ts_vddio_out:
	gpio_free(wac_data->wacom_chip_data->vci_gpio_ctrl);
ts_vci_out:
	return retval;
}

static int wacom_pinctrl_get_init(void)
{
	int ret = NO_ERR;

	if( !wac_data )
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}

	wac_data->pctrl = devm_pinctrl_get(&wac_data->wacom_dev->dev);
	if (IS_ERR(wac_data->pctrl) || (!wac_data->pctrl)) {
		TS_LOG_ERR("failed to devm pinctrl get\n");
		ret = -EINVAL;
		return ret;
	}

	wac_data->pins_default = pinctrl_lookup_state(wac_data->pctrl, "default");
	if (IS_ERR(wac_data->pins_default)) {
		TS_LOG_ERR("failed to pinctrl lookup state default\n");
		ret = -EINVAL;
		goto err_pinctrl_put;
	}

	wac_data->pins_idle = pinctrl_lookup_state(wac_data->pctrl, "idle");
	if (IS_ERR(wac_data->pins_idle)) {
		TS_LOG_ERR("failed to pinctrl lookup state idle\n");
		ret = -EINVAL;
		goto err_pinctrl_put;
	}
	return 0;

err_pinctrl_put:
	devm_pinctrl_put(wac_data->pctrl);
	return ret;
}

static int wacom_pinctrl_select_normal(void)
{
	int retval = NO_ERR;

	if( !wac_data )
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}

	retval = pinctrl_select_state(wac_data->pctrl, wac_data->pins_default);
	if (retval < 0) {
		TS_LOG_ERR("set iomux normal error, %d\n", retval);
	}
	return retval;
}

static int wacom_pinctrl_select_lowpower(void)
{
	int retval = NO_ERR;

	if( !wac_data )
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}

	retval = pinctrl_select_state(wac_data->pctrl, wac_data->pins_idle);
	if (retval < 0) {
		TS_LOG_ERR("set iomux lowpower error, %d\n", retval);
	}
	return retval;
}

static int wacom_gpio_free(void)
{
	if( (!wac_data ) || (!wac_data->wacom_chip_data) )
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return -EINVAL;
	}

	TS_LOG_INFO("wacom_gpio_free\n");

	/*1 is power supplied by gpio, 0 is power supplied by ldo*/
	if (GPIO_TYPE== wac_data->wacom_chip_data->vci_gpio_type) {
		if (wac_data->wacom_chip_data->vci_gpio_ctrl)
			gpio_free(wac_data->wacom_chip_data->vci_gpio_ctrl);
	}
	if (GPIO_TYPE == wac_data->wacom_chip_data->vddio_gpio_type) {
		if (wac_data->wacom_chip_data->vddio_gpio_ctrl)
			gpio_free(wac_data->wacom_chip_data->vddio_gpio_ctrl);
	}
	return NO_ERR;
}

static int wacom_power_on_gpio_set(void)
{
	struct ts_kit_platform_data* ts_pdata = NULL;

	if( (!wac_data ) || (!wac_data->wacom_chip_data) || (!wac_data->wacom_chip_data->ts_platform_data))
	{
		TS_LOG_ERR("%s :wacom data is null\n", __func__);
		return -EINVAL;
	}
	ts_pdata = wac_data->wacom_chip_data->ts_platform_data;

	wacom_pinctrl_select_normal();
	gpio_direction_input(ts_pdata->irq_gpio);
	gpio_direction_output(ts_pdata->reset_gpio, GPIO_OUTPUT_HIGH);
	return NO_ERR;
}

static void wacom_ts_power_gpio_enable(void)
{
	if( (!wac_data ) || (!wac_data->wacom_chip_data) )
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return;
	}

	mutex_lock(&ts_power_gpio_sem);
	if (ts_power_gpio_ref == 0) {
		gpio_direction_output(wac_data->wacom_chip_data->vddio_gpio_ctrl, GPIO_OUTPUT_HIGH);
		TS_LOG_INFO("%s, pull high vdd gpio\n",__func__);
	}
	ts_power_gpio_ref++;
	mutex_unlock(&ts_power_gpio_sem);
}

static void wacom_ts_power_gpio_disable(void)
{
	if( (!wac_data ) || (!wac_data->wacom_chip_data) )
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return;
	}

	mutex_lock(&ts_power_gpio_sem);
	if (ts_power_gpio_ref == 1) {
		gpio_direction_output(wac_data->wacom_chip_data->vddio_gpio_ctrl, GPIO_OUTPUT_LOW);
	}
	if(ts_power_gpio_ref > 0) {
		ts_power_gpio_ref--;
	}
	mutex_unlock(&ts_power_gpio_sem);
}

static void wacom_regulator_put(void)
{
	if( (!wac_data ) || (!wac_data->wacom_chip_data) )
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return;
	}

	if (REGULATOR_TYPE == wac_data->wacom_chip_data->vci_regulator_type) {
		if (!IS_ERR(wac_data->tp_vci)) {
			regulator_put(wac_data->tp_vci);
		}
	}
	if (REGULATOR_TYPE == wac_data->wacom_chip_data->vddio_regulator_type) {
		if (!IS_ERR(wac_data->tp_vddio)) {
			regulator_put(wac_data->tp_vddio);
		}
	}
}

static int wacom_vddio_enable(void)
{
	int retval = NO_ERR;
	int need_set_vddio_value = 0;
	int vol_vlaue = 0;

	if( (!wac_data ) || (!wac_data->wacom_chip_data) )
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return -EINVAL;
	}

	if (IS_ERR(wac_data->tp_vddio)) {
		TS_LOG_ERR("tp_vddio is err\n");
		return -EINVAL;
	}
	TS_LOG_INFO("set vddio is called\n");

	need_set_vddio_value = wac_data->wacom_chip_data->regulator_ctr.need_set_vddio_value;
	if(need_set_vddio_value){
		vol_vlaue = wac_data->wacom_chip_data->regulator_ctr.vddio_value;
		retval = regulator_set_voltage(wac_data->tp_vddio, vol_vlaue, vol_vlaue);
		if (retval < 0) {
			TS_LOG_ERR("failed to set voltage regulator tp_vddio error: %d\n", retval);
			return -EINVAL;
		}
	}

	retval = regulator_enable(wac_data->tp_vddio);
	if (retval < 0) {
		TS_LOG_ERR("failed to enable regulator tp_vddio\n");
		return -EINVAL;
	}
	TS_LOG_INFO("enable vddio success\n");
	return NO_ERR;
}

static int wacom_vddio_disable(void)
{
	int retval;

	if( !wac_data )
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return -EINVAL;
	}

	if (IS_ERR(wac_data->tp_vddio)) {
		TS_LOG_ERR("tp_vddio is err\n");
		return -EINVAL;
	}

	retval = regulator_disable(wac_data->tp_vddio);
	if (retval < 0) {
		TS_LOG_ERR("failed to disable regulator tp_vddio\n");
		return -EINVAL;
	}

	return 0;
}

static int wacom_vci_enable(void)
{
	int retval = NO_ERR;
	int vol_vlaue = 0;

	if( (!wac_data) || (!wac_data->wacom_chip_data) )
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return -EINVAL;
	}

	if (IS_ERR(wac_data->tp_vci)) {
		TS_LOG_ERR("tp_vci is err\n");
		return  -EINVAL;
	}
	TS_LOG_INFO("set vci is called\n");

	vol_vlaue = wac_data->wacom_chip_data->regulator_ctr.vci_value;
	retval = regulator_set_voltage(wac_data->tp_vci, vol_vlaue, vol_vlaue);
	if (retval < 0) {
		TS_LOG_ERR("failed to set voltage regulator tp_vci error: %d\n", retval);
		return -EINVAL;
	}
	TS_LOG_INFO("set vci enable called\n");
	retval = regulator_enable(wac_data->tp_vci);
	if (retval < 0) {
		TS_LOG_ERR("failed to enable regulator tp_vci\n");
		return -EINVAL;
	}
	TS_LOG_INFO("wacom_vci_enable success\n");
	return NO_ERR;
}

static int wacom_vci_disable(void)
{
	int retval = NO_ERR;

	if( !wac_data )
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return -EINVAL;
	}

	if (IS_ERR(wac_data->tp_vci)) {
		TS_LOG_ERR("tp_vci is err\n");
		return  -EINVAL;
	}

	retval = regulator_disable(wac_data->tp_vci);
	if (retval < 0) {
		TS_LOG_ERR("failed to disable regulator tp_vci\n");
		return -EINVAL;
	}

	return NO_ERR;
}
static void wacom_regulator_enable(void)
{
	if( (!wac_data) || (!wac_data->wacom_chip_data) )
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return;
	}

	TS_LOG_INFO("wacom_regulator_enable is called\n");
	if (REGULATOR_TYPE == wac_data->wacom_chip_data->vci_regulator_type) {
		if (!IS_ERR(wac_data->tp_vci)) {
			TS_LOG_INFO("vci enable is called\n");
			wacom_vci_enable();
			if (wac_data->wacom_chip_data->vci_gpio_type) {
				gpio_direction_output(wac_data->wacom_chip_data->vci_gpio_ctrl, GPIO_OUTPUT_HIGH);
			}
		}
	}
	mdelay(5);
	if(REGULATOR_TYPE == wac_data->wacom_chip_data->vddio_regulator_type) {
		if (!IS_ERR(wac_data->tp_vddio)) {
			TS_LOG_INFO("vddio enable is called\n");
			wacom_vddio_enable();
			if (wac_data->wacom_chip_data->vddio_gpio_type) {
			if (wac_data->wacom_chip_data->vci_gpio_ctrl != wac_data->wacom_chip_data->vddio_gpio_ctrl)
				gpio_direction_output(wac_data->wacom_chip_data->vddio_gpio_ctrl, GPIO_OUTPUT_HIGH);
			}
		}
	}
}

static void wacom_regulator_disable(void)
{
	if( (!wac_data) || (!wac_data->wacom_chip_data) )
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return;
	}

	if (REGULATOR_TYPE == wac_data->wacom_chip_data->vddio_regulator_type) {
		if (!IS_ERR(wac_data->tp_vddio) ) {
			wacom_vddio_disable();
		}
	}

	mdelay(2);//delay 2 ms

	if(REGULATOR_TYPE == wac_data->wacom_chip_data->vci_regulator_type) {
		if (!IS_ERR(wac_data->tp_vci) ) {
			wacom_vci_disable();
		}
	}

	mdelay(30);//delay 30 ms
}

static void wacom_power_on(void)
{
	if( (!wac_data) || (!wac_data->wacom_chip_data) )
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return;
	}

	TS_LOG_INFO("wacom_power_on called\n");
	/*1 is power supplied by gpio, 0 is power supplied by ldo*/
	wacom_regulator_enable();
	if ((GPIO_TYPE == wac_data->wacom_chip_data->vci_gpio_type) && (GPIO_TYPE == wac_data->wacom_chip_data->vddio_gpio_type)) {
		TS_LOG_INFO("Both  vci and vddio were controlled by gpio\n");
		if (wac_data->wacom_chip_data->vci_gpio_ctrl == wac_data->wacom_chip_data->vddio_gpio_ctrl) {
			gpio_direction_output(wac_data->wacom_chip_data->vci_gpio_ctrl, GPIO_OUTPUT_HIGH);
			msleep(1);
		} else {
			gpio_direction_output(wac_data->wacom_chip_data->vci_gpio_ctrl, GPIO_OUTPUT_HIGH);
			msleep(5);
			gpio_direction_output(wac_data->wacom_chip_data->vddio_gpio_ctrl, GPIO_OUTPUT_HIGH);
		}
	} else if (GPIO_TYPE == wac_data->wacom_chip_data->vci_gpio_type){
		TS_LOG_INFO("Only vci was controlled by gpio\n");
		gpio_direction_output(wac_data->wacom_chip_data->vci_gpio_ctrl, GPIO_OUTPUT_HIGH);
	} else if (GPIO_TYPE == wac_data->wacom_chip_data->vddio_gpio_type) {
		TS_LOG_INFO("Only vddio was controlled by gpio\n");
		wacom_ts_power_gpio_enable();
	}
	msleep(2);
	wacom_power_on_gpio_set();
}

static int wacom_power_off_gpio_set(void)
{
	if( (!wac_data ) || (!wac_data->wacom_chip_data) || (!wac_data->wacom_chip_data->ts_platform_data))
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return -EINVAL;
	}

	TS_LOG_INFO("suspend RST out L\n");

	gpio_direction_output(wac_data->wacom_chip_data->ts_platform_data->reset_gpio, GPIO_OUTPUT_LOW);
	wacom_pinctrl_select_lowpower();
	return NO_ERR;
}

static void wacom_power_off(void)//delay need check
{
	if( (!wac_data) || (!wac_data->wacom_chip_data) )
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return;
	}

	wacom_power_off_gpio_set();
	msleep(2);
	/*1 is power supplied by gpio, 0 is power supplied by ldo*/
	if ((GPIO_TYPE == wac_data->wacom_chip_data->vci_gpio_type) && (GPIO_TYPE == wac_data->wacom_chip_data->vddio_gpio_type)) {
		TS_LOG_INFO("Both  vci and vddio were need to output 0\n");
		if (wac_data->wacom_chip_data->vci_gpio_ctrl == wac_data->wacom_chip_data->vddio_gpio_ctrl) {
			gpio_direction_output(wac_data->wacom_chip_data->vci_gpio_ctrl, GPIO_OUTPUT_LOW);
		} else {
			gpio_direction_output(wac_data->wacom_chip_data->vddio_gpio_ctrl, GPIO_OUTPUT_LOW);
			msleep(2);
			gpio_direction_output(wac_data->wacom_chip_data->vci_gpio_ctrl, GPIO_OUTPUT_LOW);
		}
	} else if (GPIO_TYPE == wac_data->wacom_chip_data->vci_gpio_type){
		TS_LOG_INFO("Only vci was need to output 0\n");
		gpio_direction_output(wac_data->wacom_chip_data->vci_gpio_ctrl, GPIO_OUTPUT_LOW);
	} else if (GPIO_TYPE == wac_data->wacom_chip_data->vddio_gpio_type) {
		TS_LOG_INFO("Only vddio was need to output 0\n");
		wacom_ts_power_gpio_disable();
	}
	wacom_regulator_disable();
}


static int wacom_chip_detect(struct ts_kit_platform_data *platform_data)
{
	int retry = 0;
	int retval = NO_ERR;
	TS_LOG_INFO("%s enter\n", __func__);

	if( (!platform_data) || (!wac_data) || (!wac_data->wacom_chip_data) || (!platform_data->ts_dev))
	{
		TS_LOG_ERR("%s : data is null\n", __func__);
		return -EINVAL;
	}

	wac_data->wacom_dev = platform_data->ts_dev;
	wac_data->wacom_chip_data->is_in_cell = false;
	wac_data->wacom_dev->dev.of_node = wac_data->wacom_chip_data->cnode;
	wac_data->client = g_ts_kit_platform_data.client;

	wac_data->wacom_chip_data->ts_platform_data = platform_data;
	wac_data->wacom_chip_data->easy_wakeup_info.sleep_mode = TS_POWER_OFF_MODE;
	wac_data->wacom_chip_data->easy_wakeup_info.easy_wakeup_gesture = false;
	wac_data->wacom_chip_data->easy_wakeup_info.easy_wakeup_flag = false;
	wac_data->wacom_chip_data->easy_wakeup_info.palm_cover_flag = false;
	wac_data->wacom_chip_data->easy_wakeup_info.palm_cover_control = false;
	wac_data->wacom_chip_data->easy_wakeup_info.off_motion_on = false;
	wac_data->wacom_chip_data->is_i2c_one_byte = false;
	wac_data->wacom_chip_data->is_new_oem_structure= 0;
	wac_data->wacom_chip_data->is_parade_solution= 0;

	wac_data->features = kzalloc(sizeof(struct wacom_features), GFP_KERNEL);
	if (!(wac_data->features)) {
		TS_LOG_ERR("%s:features malloc fail!\n",__func__);
		retval = -ENOMEM;
		goto err_free;
	}

	wac_data->ts_cache_fingers = kzalloc(sizeof(struct ts_fingers), GFP_KERNEL);
	if (!(wac_data->ts_cache_fingers)) {
		TS_LOG_ERR("%s:features malloc fail!\n",__func__);
		retval = -ENOMEM;
		goto err_get_regulator;
	}

	wac_data->ts_cache_pens = kzalloc(sizeof(struct ts_pens), GFP_KERNEL);
	if (!(wac_data->ts_cache_pens)) {
		TS_LOG_ERR("%s:features malloc fail!\n",__func__);
		retval = -ENOMEM;
		goto err_get_regulator;
	}
	wac_data->ts_cache_pens->tool.tool_type = BTN_TOOL_PEN;//default is pen
	wac_data->next_pen_tool = BTN_TOOL_RUBBER;//first tool is PEN, first changed tool is RUBBRR.

	retval = wacom_parse_dts(wac_data->wacom_dev->dev.of_node,wac_data->wacom_chip_data);
	if(0 != retval)
	{
		TS_LOG_ERR("%s, wacom parse dts error.\n", __func__);
		goto err_get_regulator;
	}

	retval = wacom_regulator_get();
	if (retval < 0) {
		goto err_get_regulator;
	}

	retval = wacom_gpio_request();
	if (retval < 0) {
		goto err_request_gpio;
	}

	retval = wacom_pinctrl_get_init();
	if (retval < 0) {
		goto err_pinctrl_get;
	}

	/*power up the chip*/
	wacom_power_on();

	/*reset the chip*/
	wacom_gpio_reset();
	//msleep(WACOM_RESET_DELAY);
	msleep(600);//delay for v2

	/*i2c check, if it failed, retry 2 times*/
	for(retry = 0; retry < CHECK_RETRY_TIMES; retry++) {
		retval = wacom_query_device(g_ts_kit_platform_data.client, wac_data->features);
		if (retval >= 0) {
			TS_LOG_INFO("find wacom device\n");
			break;
		} else {
			TS_LOG_ERR( "wacom i2c check failed.try again.retry=%d\n", retry+1);
			wacom_gpio_reset();
			msleep(WACOM_RESET_DELAY);
		}
	}

	if (retval < 0) {
		TS_LOG_ERR( "%s:wacom_query_device failed.\n", __func__);
		goto err_i2c_check;
	}

	wake_lock_init(&wac_data->ts_wake_lock, WAKE_LOCK_SUSPEND, WACOM_WAKELOCK_NAME);

out:
	TS_LOG_INFO("wacom chip detect done\n");
	return NO_ERR;

err_i2c_check:
	wacom_power_off();
err_pinctrl_get:
	wacom_gpio_free();
err_request_gpio:
	wacom_regulator_put();
err_get_regulator:
	if(wac_data->ts_cache_pens)
	{
		kfree(wac_data->ts_cache_pens);
		wac_data->ts_cache_pens = NULL;
	}

	if(wac_data->ts_cache_fingers)
	{
		kfree(wac_data->ts_cache_fingers);
		wac_data->ts_cache_fingers = NULL;
	}

	if(wac_data->features)
	{
		kfree(wac_data->features);
		wac_data->features = NULL;
	}
err_free:
	if(wac_data->wacom_chip_data) {
		kfree(wac_data->wacom_chip_data);
		wac_data->wacom_chip_data = NULL;/*Fix the DTS parse error cause panic bug*/
	}

	if (wac_data) {
		kfree(wac_data);
		wac_data = NULL;
	}
	return retval;
}

static int wacom_get_lcd_panel_info(void)
{
	struct device_node *dev_node = NULL;
	char *lcd_type = NULL;
	if( !wac_data )
	{
		TS_LOG_ERR("%s : wacom data is null.\n", __func__);
		return -EINVAL;
	}

	dev_node = of_find_compatible_node(NULL, NULL, WACOM_LCD_PANEL_TYPE_DEVICE_NODE_NAME);
	if (!dev_node) {
		TS_LOG_ERR("%s: NOT found device node[%s]!\n", __func__, WACOM_LCD_PANEL_TYPE_DEVICE_NODE_NAME);
		return -EINVAL;
	}
	lcd_type = (char*)of_get_property(dev_node, "lcd_panel_type", NULL);
	if(!lcd_type){
		TS_LOG_ERR("%s: Get lcd panel type faile!\n", __func__);
		return -EINVAL ;
	}

	strncpy(wac_data->lcd_panel_info, lcd_type, WACOM_LCD_PANEL_INFO_MAX_LEN-1);
	TS_LOG_INFO("lcd_panel_info = %s.\n", wac_data->lcd_panel_info);
	return NO_ERR;
}

/*  query the configure from dts and store in prv_data */
int wacom_parse_dts(struct device_node * device, struct ts_kit_device_data * chip_data)
{
	int retval  = NO_ERR;
	u32 pid_value[16] = {0};
	int i = 0;
	struct ts_kit_platform_data* ts_pdata = NULL;
	TS_LOG_INFO(" wacom_parse_dts called here.\n");

	if( (!wac_data ) || (!wac_data->wacom_chip_data) || (!wac_data->wacom_chip_data->ts_platform_data) || (!wac_data->wacom_chip_data->ts_platform_data->client))
	{
		TS_LOG_ERR("%s : wacom data is null.\n", __func__);
		return -EINVAL;
	}
	ts_pdata = wac_data->wacom_chip_data->ts_platform_data;

	retval = of_property_read_u32(device, WACOM_SLAVE_ADDR, (u32*)&ts_pdata->client->addr);
	if (retval) {
		TS_LOG_ERR("%s,get wacom i2c slave_address failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	TS_LOG_INFO("%s,slave_address = 0x%x\n", __func__,ts_pdata->client->addr);

	retval = of_property_read_u32(device, "rawdata_get_timeout", &chip_data->rawdata_get_timeout);
	if (!retval) {
		TS_LOG_INFO("get chip rawdata limit time = %d\n", chip_data->rawdata_get_timeout);
	} else {
		TS_LOG_INFO("can not get chip rawdata limit time, use default\n");
		chip_data->rawdata_get_timeout = 0;
		retval = 0;
	}
	retval =
	    of_property_read_string(device, "tp_test_type",
				 (const char **)&chip_data->tp_test_type);
	if (retval) {
		TS_LOG_INFO
		    ("get device tp_test_type not exit,use default value\n");
		strncpy(chip_data->tp_test_type,
			"Normalize_type:judge_different_reslut",
			TS_CAP_TEST_TYPE_LEN);
		retval = 0;
	}
	retval = of_property_read_u32(device,WACOM_TP_DOZE_ENABLE, &chip_data->touch_switch_flag);
	if (retval) {
		chip_data->touch_switch_flag  = 0;
		TS_LOG_INFO("%s, not support doze mode.\n",__func__);
	}
	TS_LOG_INFO("%s, touch_switch_flag = %d.\n", __func__, chip_data->touch_switch_flag);

	retval = of_property_read_u32(device, WACOM_TP_IC_TYPE, &chip_data->ic_type);
	if (retval) {
		chip_data->ic_type = HYBRID;
		TS_LOG_INFO("%s,not define device ic_type in dts\n",__func__);
	} else {
		g_tskit_ic_type = chip_data->ic_type;
	}
	TS_LOG_INFO("%s,get g_tskit_ic_type = %d.\n",__func__, g_tskit_ic_type);


	retval = of_property_read_u32(device, WACOM_PEN_MODE_SUPPORTED, (u32*)&g_ts_kit_platform_data.feature_info.pen_info.pen_supported);
	if (retval) {
		TS_LOG_ERR("get pen supported failed\n");
		retval = -EINVAL;
		g_ts_kit_platform_data.feature_info.pen_info.pen_supported = 0;
	}
	TS_LOG_INFO("pen supported value is  0x%x, (1:support, 0: not supported)\n", g_ts_kit_platform_data.feature_info.pen_info.pen_supported);

	retval = of_property_read_u32(device, WACOM_IRQ_CFG, &chip_data->irq_config);
	if (retval) {
		TS_LOG_ERR("%s,get irq config failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	retval = of_property_read_u32(device, WACOM_ALGO_ID, &chip_data->algo_id);
	if (retval) {
		TS_LOG_ERR("%s,get algo id failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	retval = of_property_read_u32(device, WACOM_VCI_GPIO_TYPE, &chip_data->vci_gpio_type);
	if (retval) {
		TS_LOG_ERR("%s,get vci gpio type failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	retval = of_property_read_u32(device, WACOM_VCI_REGULATOR_TYPE, &chip_data->vci_regulator_type);
	if (retval) {
		TS_LOG_ERR("%s,get vci regulator type failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	retval = of_property_read_u32(device, WACOM_VDDIO_GPIO_TYPE, &chip_data->vddio_gpio_type);
	if (retval) {
		TS_LOG_ERR("%s,get vddio gpio type failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	TS_LOG_INFO("%s,vddio gpio type is: %d\n",__func__, chip_data->vddio_gpio_type);

	retval = of_property_read_u32(device, WACOM_VDDIO_REGULATOR_TYPE, &chip_data->vddio_regulator_type);
	if (retval) {
		TS_LOG_ERR("%s,get vddio regulator type failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	retval = of_property_read_u32(device, WACOM_VDDIO_LDO_NEED_SET, &chip_data->regulator_ctr.need_set_vddio_value);
	if (retval) {
		TS_LOG_ERR("%s,get vddio value need set failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	retval = of_property_read_u32(device, WACOM_VCI_LDO_VALUE, &chip_data->regulator_ctr.vci_value);
	if (retval) {
		TS_LOG_ERR("%s,get vci value failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	TS_LOG_INFO("%s, regulator_ctr.vci_value = %d \n", __func__, chip_data->regulator_ctr.vci_value);

	if (GPIO_TYPE == chip_data->vci_gpio_type) {
		chip_data->vci_gpio_ctrl = of_get_named_gpio(device, WACOM_VCI_GPIO_CTRL, 0);
		if (!gpio_is_valid(chip_data->vci_gpio_ctrl)) {
			TS_LOG_ERR("%s,vci ctrl gpio is not valid\n",__func__);
		}
	}
	if (GPIO_TYPE == chip_data->vddio_gpio_type) {
		chip_data->vddio_gpio_ctrl = of_get_named_gpio(device, WACOM_VDDIO_GPIO_CTRL, 0);
		if (!gpio_is_valid(chip_data->vddio_gpio_ctrl)) {
			TS_LOG_ERR("%s,vddio ctrl gpio is not valid\n",__func__);
		}
	}

	if(chip_data->regulator_ctr.need_set_vddio_value){
		retval = of_property_read_u32(device, WACOM_VDDIO_LDO_VALUE, &chip_data->regulator_ctr.vddio_value);
		if (retval) {
			TS_LOG_ERR("%s,get vddio value failed\n",__func__);
			retval = -EINVAL;
			goto err;
		}
		TS_LOG_INFO("%s, regulator_ctr.vddio_value = %d \n", __func__, chip_data->regulator_ctr.vddio_value);
	}

	/*project id*/
	char *tmp_buff = NULL;
	retval = of_property_read_string(device, "project_id", (const char**)&tmp_buff);
	if (retval ||tmp_buff == NULL){
		TS_LOG_ERR("%s, project_id read failed:%d\n",__func__ , retval);
		retval = -EINVAL;
		goto err;
	}
	strncpy(wac_data->project_id,tmp_buff,MAX_STR_LEN-1);
	TS_LOG_INFO("%s, the default project_id %s\n",__func__ , wac_data->project_id);

	/*chip name*/
	retval = of_property_read_string(device, "chip_name", (const char**)&tmp_buff);
	if (retval ||tmp_buff == NULL){
		TS_LOG_ERR("%s, chip_name read failed:%d\n",__func__ , retval);
		retval = -EINVAL;
		goto err;
	}
	strncpy(wac_data->chip_name,tmp_buff,MAX_STR_LEN-1);
	strncpy(g_ts_kit_platform_data.chip_data->chip_name,tmp_buff,MAX_STR_LEN-1);
	TS_LOG_INFO("%s, chip_name %s\n",__func__ , wac_data->chip_name);

	/*chip vendor*/
	retval = of_property_read_string(device, "chip_vendor", (const char**)&tmp_buff);
	if (retval ||tmp_buff == NULL){
		TS_LOG_ERR("%s, chip_vendor read failed:%d\n",__func__ , retval);
		retval = -EINVAL;
		goto err;
	}
	strncpy(wac_data->chip_vendor,tmp_buff,MAX_STR_LEN-1);
	TS_LOG_INFO("%s, chip_name %s\n",__func__ , wac_data->chip_vendor);

	/*module vendor*/
	retval = of_property_read_string(device, "module_vendor", (const char**)&tmp_buff);
	if (retval ||tmp_buff == NULL){
       TS_LOG_ERR("%s, module_vendor read failed:%d\n",__func__ , retval);
		retval = -EINVAL;
		goto err;
	}
	strncpy(wac_data->tp_module_name,tmp_buff,MAX_STR_LEN-1);
	TS_LOG_INFO("%s, the default module_vendor %s\n",__func__ , wac_data->tp_module_name);

	/*coordinate info*/
	retval = of_property_read_u32(device, WACOM_X_MAX, &wac_data->coordinate_info.x_max);
	if (retval) {
		TS_LOG_ERR("%s,get x_max failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	retval = of_property_read_u32(device, WACOM_Y_MAX, &wac_data->coordinate_info.y_max);
	if (retval) {
		TS_LOG_ERR("%s,get y_max failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	retval = of_property_read_u32(device, WACOM_TOUCH_REPORT_X_MAX, &wac_data->coordinate_info.touch_report_x_max);
	if (retval) {
		TS_LOG_ERR("%s,get touch_report_x_max failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	retval = of_property_read_u32(device, WACOM_TOUCH_REPORT_Y_MAX, &wac_data->coordinate_info.touch_report_y_max);
	if (retval) {
		TS_LOG_ERR("%s,get touch_report_y_max failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	retval = of_property_read_u32(device, WACOM_PEN_REPORT_X_MAX, &wac_data->coordinate_info.pen_report_x_max);
	if (retval) {
		TS_LOG_ERR("%s,get pen_report_x_max failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	retval = of_property_read_u32(device, WACOM_PEN_REPORT_Y_MAX, &wac_data->coordinate_info.pen_report_y_max);
	if (retval) {
		TS_LOG_ERR("%s,get pen_report_y_max failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	TS_LOG_INFO("%s,x_max = %d, y_max = %d, touch_report_x_max = %d, touch_report_y_max = %d, \
		pen_report_x_max = %d, pen_report_y_max = %d\n", __func__,wac_data->coordinate_info.x_max,\
		wac_data->coordinate_info.y_max,  wac_data->coordinate_info.touch_report_x_max,\
		wac_data->coordinate_info.touch_report_y_max, wac_data->coordinate_info.pen_report_x_max,\
		wac_data->coordinate_info.pen_report_y_max);

	/*pen pressure*/
	retval = of_property_read_u32(device, WACOM_PEN_MAX_PRESSURE, &wac_data->pen_max_pressure);
	if (retval) {
		TS_LOG_ERR("%s,get pen_max_pressure failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}
	TS_LOG_INFO("%s, pen_max_pressure is %d\n",__func__ , wac_data->pen_max_pressure);

	/*pid info*/
	retval = of_property_read_u32(device, WACOM_PID_NUM, &wac_data->pid_info.pid_num);
	if (retval) {
		TS_LOG_ERR("%s,get pid_num failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}

	 retval = of_property_read_u32_array(device,WACOM_PID, &pid_value[0], wac_data->pid_info.pid_num);
	if (retval) {
		TS_LOG_ERR("%s,get pid  failed\n",__func__);
		retval = -EINVAL;
		goto err;
	}else {
		for (i = 0; i < wac_data->pid_info.pid_num; i++) {
			wac_data->pid_info.pid[i] = pid_value[i];
			TS_LOG_INFO("%s,pid[%d] = 0x%x\n",__func__, i, pid_value[i]);
		}
	}

	//get lcd panel info, if fail, TP can continue.
	wacom_get_lcd_panel_info();

	TS_LOG_INFO("%s,reset_gpio = %d, irq_gpio = %d, irq_config = %d, algo_id = %d\n", __func__,\
		ts_pdata->reset_gpio, ts_pdata->irq_gpio, chip_data->irq_config, chip_data->algo_id);
err:
	return retval;
}


/*static ssize_t wacom_hw_reset_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned int value;
	int error;

	if ((dev == NULL) || (buf == NULL)) {
		TS_LOG_ERR("date is null\n");
		error = -EINVAL;
		goto out;
	}

	error = sscanf(buf, "%u", &value);
	if (!error) {
		TS_LOG_ERR("sscanf return invaild :%d\n", error);
		error = -EINVAL;
		goto out;
	}
	if(value == 1){
		wacom_gpio_reset();
	}else{
		TS_LOG_INFO("gpio rest input error.\n");
	}
out:
	TS_LOG_INFO("gpio reset done\n");
	return count;
}

static DEVICE_ATTR(gpio_reset,  (S_IWUSR | S_IWGRP), NULL, wacom_hw_reset_store);

static struct attribute *wacom_attributes[] = {
	&dev_attr_gpio_reset.attr,
	NULL
};

static const struct attribute_group wacom_attr_group = {
	.attrs = wacom_attributes,
};

static int wacom_sysfs_create(void)
{
	int ret = 0;

	if (g_ts_kit_platform_data.ts_dev == NULL) {
		TS_LOG_ERR("date is null\n");
		ret = -EINVAL;
		return ret;
	}

	ret = sysfs_create_group(&g_ts_kit_platform_data.ts_dev->dev.kobj, &wacom_attr_group);
	if (ret) {
		TS_LOG_ERR("%s: Error, could not create wacom_attr_group\n", __func__);
	}
	return ret;
}*/

static int wacom_init_chip(void)
{
	int retval= NO_ERR;

	//wacom_sysfs_create();
	TS_LOG_INFO("init chip done.\n");
	return retval;
}

static int wacom_pen_config(struct input_dev *input_dev )
{
	struct input_dev *input =  g_ts_kit_platform_data.pen_dev;

	if (input_dev == NULL) {
		TS_LOG_ERR("date is null\n");
		return -EINVAL;
	}

	TS_LOG_INFO("wacom_pen_input_config called\n");

	input->evbit[0] |= BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
	__set_bit(ABS_X, input->absbit);
	__set_bit(ABS_Y, input->absbit);
	__set_bit(BTN_TOOL_RUBBER, input->keybit);
	__set_bit(BTN_STYLUS, input->keybit);
	__set_bit(BTN_STYLUS2, input->keybit);
	__set_bit(BTN_TOUCH, input->keybit);
	__set_bit(BTN_TOOL_PEN, input->keybit);
	__set_bit(INPUT_PROP_DIRECT, input->propbit);
	input_set_abs_params(input, ABS_X, 0, wac_data->coordinate_info.x_max, 0, 0);
	input_set_abs_params(input, ABS_Y, 0, wac_data->coordinate_info.y_max, 0, 0);
	input_set_abs_params(input, ABS_PRESSURE, 0, wac_data->pen_max_pressure, 0, 0);
	input_set_abs_params(input, ABS_TILT_X, 0, REPORT_ABS_TILT_DEGREE_MAX, 0, 0);
	input_set_abs_params(input, ABS_TILT_Y, 0, REPORT_ABS_TILT_DEGREE_MAX, 0, 0);

	wac_data->input_pen = input;
	return NO_ERR;
}

static int wacom_input_config(struct input_dev *input)
{
	if (input == NULL) {
		TS_LOG_ERR("date is null\n");
		return -EINVAL;
	}

	TS_LOG_INFO("wacom_input_config called\n");

	TS_LOG_INFO("wacom_touchscreen_input_config called\n");
	wac_data->input =  input;
	input->evbit[0] |= BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
	__set_bit(BTN_TOUCH, input->keybit);
	__set_bit(INPUT_PROP_DIRECT, input->propbit);

	input_set_abs_params(input, ABS_MT_POSITION_X, 0, wac_data->coordinate_info.x_max, 0, 0);
	input_set_abs_params(input, ABS_MT_POSITION_Y, 0, wac_data->coordinate_info.y_max, 0, 0);
	input_set_abs_params(input, ABS_MT_PRESSURE, 0, WACOM_ABS_PRESSURE, 0, 0);
	return NO_ERR;
}

void wacom_report_pen_data(struct wacom_i2c *wac_i2c,u8 *data, struct ts_cmd_node *out_cmd)
{
	unsigned int x, y, pressure;
	int tmp = 0;
	u32 down_button_status = 0, up_button_status = 0, pen_inrange_status=0, tip_status=0;
	int last_tool = wac_data->ts_cache_pens->tool.tool_type;
	int next_pen_tool = 0;
	struct ts_pens *info = NULL;

	if ((!wac_i2c) || (!data) || (!out_cmd) || (!wac_data) || (!wac_data->ts_cache_pens) || (!(&out_cmd->cmd_param.pub_params.report_pen_info))) {
		TS_LOG_ERR("date is null\n");
		return;
	}

	info = &out_cmd->cmd_param.pub_params.report_pen_info;
	info->tool.tool_type = WACOM_TOOL_TYPE_NONE;

	pen_inrange_status = data[PEN_TOOLTYPE_BYTE_OFFSET] & WACOM_RDY;
	down_button_status = data[PEN_TOOLTYPE_BYTE_OFFSET] & WACOM_SIDE_SWITCH;
	up_button_status     = data[PEN_TOOLTYPE_BYTE_OFFSET] & WACOM_2ND_SIDE_SWITCH;
	tip_status = data[PEN_TOOLTYPE_BYTE_OFFSET] & WACOM_TIP_SWITCH;


	y = le16_to_cpup((__le16 *)&data[PEN_Y_BYTE_OFFSET]);
	x = le16_to_cpup((__le16 *)&data[PEN_X_BYTE_OFFSET]);

	tmp = x;
	x = y;
	y = tmp;

	x = wac_data->coordinate_info.pen_report_x_max - x;
	x = (int)(x * wac_data->coordinate_info.x_max) / wac_data->coordinate_info.pen_report_x_max;
	y = (int)(y * wac_data->coordinate_info.y_max) / wac_data->coordinate_info.pen_report_y_max;

	pressure = le16_to_cpup((__le16 *)&data[PEN_PRESSURE_BYTE_OFFSET]);

	info->tool.pen_inrange_status = pen_inrange_status;
	info->tool.tip_status = tip_status;
	info->tool.x = x;
	info->tool.y = y;
	info->tool.pressure = pressure;
	info->tool.tilt_x = data[PEN_TILT_X_BYTE_OFFSET];
	info->tool.tilt_y = data[PEN_TILT_Y_BYTE_OFFSET];

	/*0x80 means minus*/
	if( info->tool.tilt_x & 0x80 ) {
			info->tool.tilt_x -= 0x80;
	}
	if( info->tool.tilt_y & 0x80 ) {
			info->tool.tilt_y -= 0x80;
	}

	TS_LOG_DEBUG("report pen coord: x= %d, y= %d, pressure=%d, tilt_x=%d, tilt_y=%d\n", x, y, pressure, info->tool.tilt_x, info->tool.tilt_y);
	TS_LOG_DEBUG("pen tool: down_button_status=%d, up_button_status=%d, pen_inrange_status=%d, tip_status=%d\n", down_button_status, up_button_status, pen_inrange_status, tip_status);

	if(down_button_status){
		info->buttons[WACOM_DOWN_BUTTON_INDEX].status = TS_FINGER_PRESS;
		info->buttons[WACOM_DOWN_BUTTON_INDEX].key = BTN_STYLUS;
	}else{
		//if last time is down, then this is realease
		if(wac_data->ts_cache_pens->buttons[WACOM_DOWN_BUTTON_INDEX].status == TS_FINGER_PRESS){
			info->buttons[WACOM_DOWN_BUTTON_INDEX].status = TS_FINGER_RELEASE;
			info->buttons[WACOM_DOWN_BUTTON_INDEX].key = BTN_STYLUS;
		}
	}

	//first to check the tool type
	if(last_tool == BTN_TOOL_PEN ){
		if( up_button_status && tip_status) //only current is pen, up button dowm & tip down, we can change the tool type
		{
			TS_LOG_DEBUG("WACOM_PEN_TO_RUBBER\n");
			//pen to rubber
			info->tool.tool_type = WACOM_PEN_TO_RUBBER;
			next_pen_tool = BTN_TOOL_RUBBER;
		}
	} else {//last tool is BTN_TOOL_RUBBER
		if( !(up_button_status && tip_status))
		{
		    	TS_LOG_DEBUG("WACOM_RUBBER_TO_PEN\n");
			// rubber to pen
			info->tool.tool_type = WACOM_RUBBER_TO_PEN;
			next_pen_tool = BTN_TOOL_PEN;
		}
	}

	TS_LOG_DEBUG("tool_type is %d,  last type is %d\n", info->tool.tool_type, last_tool);
	 if( info->tool.tool_type == WACOM_TOOL_TYPE_NONE)// don't need to change the tool type
	 {
	 	info->tool.tool_type = last_tool;
		if((last_tool ==WACOM_PEN_TO_RUBBER ) || (last_tool ==WACOM_RUBBER_TO_PEN))//last change
		{
			info->tool.tool_type = wac_data->next_pen_tool;
			TS_LOG_DEBUG("next_pen_tool is %d\n", wac_data->next_pen_tool);
		}
	 } else{//remember the next report tool
		wac_data->next_pen_tool = next_pen_tool;
	 }

    memcpy(wac_data->ts_cache_pens, info, sizeof(struct ts_pens));
    out_cmd->command = TS_REPORT_PEN;

    TS_LOG_DEBUG("report type: info->tool.tool_type= %d, out_cmd->command=%d\n", info->tool.tool_type, out_cmd->command);

    return;
}


static void  wacom_report_tp_data(struct wacom_i2c *wac_i2c, u8 *data, struct ts_cmd_node *out_cmd)
{
	struct ts_fingers *info = NULL;
	int frame_num=0;
	int finger_num = 0;
	int i=0,id=0;
	int finger_down = 0;
	int x=0, y=0, tmp=0;
	bool is_all_message_received = false;
	int up_finger_num = 0;

	if ((!wac_i2c) || (!data) || (!out_cmd) || (!wac_data) || (!wac_data->ts_cache_fingers) || (!(&out_cmd->cmd_param.pub_params.algo_param.info))) {
		TS_LOG_ERR("date is null\n");
		return;
	}

	info = &out_cmd->cmd_param.pub_params.algo_param.info;
	finger_num = data[TP_FINGER_NUM_OFFSET];

	TS_LOG_DEBUG("%s, data[TP_FINGER_NUM_OFFSET]: %d\n", __func__, data[TP_FINGER_NUM_OFFSET]);

	/*when finger number > 5, wacom will split data into 2 frame.
	the first frame data[4] will store finger number, the next frame value is 0.*/
	/*When data[4] has a value, then it is the first finger packet.*/
	if (finger_num != 0) {
		//wac_data->ts_cache_fingers used for store the first frame
        	memset(wac_data->ts_cache_fingers, 0, sizeof(struct ts_fingers));

		//in first frame, store the finger number for next frame
		is_all_message_received = false;
		frame_num = 0;
		if ( (finger_num <= 0) || (finger_num > TS_MAX_FINGER) ) {
			TS_LOG_ERR("don't support less than 0 finger or more than 10 fingers\n");
			return;
		} else if(finger_num <= WACOM_MAX_FINGER_NUM_PER_FRAME){
			is_all_message_received = true;
		}
		info->cur_finger_number = finger_num;
	}
	else
	{
		memcpy(info, wac_data->ts_cache_fingers, sizeof(struct ts_fingers));
		is_all_message_received = true;
		frame_num = 1;
		finger_num = info->cur_finger_number;
	}

	TS_LOG_DEBUG("%s, frame_num: %d, finger_num %d\n", __func__, frame_num, finger_num);

	/*One packet holds the status for two fingers.*/
	for (i = 0; i < FINGERNUM_IN_PACKET; i++) {
			finger_down = data[TP_FINGER_F1_STATUS_OFFSET + (i * ONE_FINGER_SIZE_PER_FRAME)] & WACOM_TP_TIP_SWITCH;
			x =le16_to_cpup((__le16 *)&data[TP_FINGER_F1_X_COOR_OFFSET + (i * ONE_FINGER_SIZE_PER_FRAME)]);
			y = le16_to_cpup((__le16 *)&data[TP_FINGER_F1_Y_COOR_OFFSET + (i * ONE_FINGER_SIZE_PER_FRAME)]);

			// x <=====> y //
			tmp = x;
			x = y;
			y = tmp;

			x = wac_data->coordinate_info.touch_report_x_max - x;
			x = (int)(x * wac_data->coordinate_info.x_max) / wac_data->coordinate_info.touch_report_x_max;
			y = (int)(y * wac_data->coordinate_info.y_max) / wac_data->coordinate_info.touch_report_y_max;

			id = i+frame_num*WACOM_MAX_FINGER_NUM_PER_FRAME;
			info->fingers[id].x = x;
			info->fingers[id].y = y;

			if (finger_down){
				info->fingers[id].status = TS_FINGER_PRESS;
				info->fingers[id].pressure = WACOM_ABS_PRESSURE;
			} else {
				info->fingers[id].status = TS_FINGER_RELEASE;
				info->fingers[id].pressure = 0;
				up_finger_num++;
			}

			TS_LOG_DEBUG(" %s, finger ID: %d, status: %d; x:%d; y:%d; pressure: %d\n",__func__, id,
			info->fingers[id].status, info->fingers[id].x, info->fingers[id].y, info->fingers[id].pressure);

			finger_num--;
			if (finger_num == 0) {
				break;
			}
	}

	info->cur_finger_number -= up_finger_num;

	//store the first frame info, wait next frame to report.
	if (is_all_message_received) {
		out_cmd->command = TS_INPUT_ALGO;
	} else{
		memcpy(wac_data->ts_cache_fingers, info, sizeof(struct ts_fingers));
		out_cmd->command =  TS_INVAILD_CMD;
	}

	return;
}

static int wacom_irq_top_half(struct ts_cmd_node *cmd)
{
	if (!cmd) {
		TS_LOG_ERR("date is null\n");
		return -EINVAL;
	}
	cmd->command = TS_INT_PROCESS;
	TS_LOG_DEBUG("wacom irq top half called\n");
	return NO_ERR;
}

static int wacom_irq_bottom_half(struct ts_cmd_node *in_cmd, struct ts_cmd_node *out_cmd)
{
	u8 *data = wac_data->data;
	int retval = NO_ERR;
	u8 reg_addr = WACOM_REG_BASE;

	if ((!in_cmd) || (!out_cmd) || (!wac_data) || (!wac_data->wacom_chip_data)) {
		TS_LOG_ERR("date is null\n");
		return -EINVAL;
	}

	out_cmd->cmd_param.pub_params.algo_param.algo_order = wac_data->wacom_chip_data->algo_id;
	out_cmd->command = TS_INVAILD_CMD;

	TS_LOG_DEBUG("reportid %d\n", data[HID_REPORTID_BYTE_OFFSET]);

	//retval = i2c_master_recv(wac_data->client,
		//		wac_data->data, WACOM_TOUCH_INPUTSIZE);//read length is 42.
	//retval = wacom_ioread(wac_data->data, WACOM_TOUCH_INPUTSIZE);
	//INVALID_REG_LENGTH used for don't write i2c address before read data.
	retval = g_ts_kit_platform_data.bops->bus_read(&reg_addr, INVALID_REG_LENGTH, data, WACOM_TOUCH_INPUTSIZE);
	if(retval != NO_ERR)//need to add DMD
	{
		TS_LOG_ERR("%s, I2C read fail, return value is %d\n", __func__, retval);
		return -EINVAL;
	}

	if (data[HID_REPORTID_BYTE_OFFSET] ==  WACOM_PEN_REPORTID)
		wacom_report_pen_data(wac_data, data, out_cmd);
	else if (data[HID_REPORTID_BYTE_OFFSET] ==  WACOM_TP_REPORTID)
		wacom_report_tp_data(wac_data, data, out_cmd);
	else{//need to add DMD
		//TS_LOG_ERR("wrong reportid %d\n", data[HID_REPORTID_BYTE_OFFSET]);
		//ts_dmd_report(DSM_TP_I2C_RW_ERROR_NO, "wrong reportid.\n");
		return -EINVAL;
	}

	return NO_ERR;
}

static int wacom_gpio_reset(void)
{
	struct ts_kit_platform_data* ts_pdata = NULL;
	if( (!wac_data ) || (!wac_data->wacom_chip_data) || (!wac_data->wacom_chip_data->ts_platform_data))
	{
		TS_LOG_ERR("%s : wacom data is null\n", __func__);
		return -EINVAL;
	}
	ts_pdata = wac_data->wacom_chip_data->ts_platform_data;

	TS_LOG_DEBUG("wacom_gpio_reset\n");
	gpio_direction_output(ts_pdata->reset_gpio, GPIO_OUTPUT_HIGH);
	msleep(5);
	gpio_direction_output(ts_pdata->reset_gpio, GPIO_OUTPUT_LOW);
	msleep(5);
	gpio_direction_output(ts_pdata->reset_gpio, GPIO_OUTPUT_HIGH);
	msleep(2);
	return NO_ERR;
}


static int __init wacom_module_init(void)
{
	bool found = false;
	struct device_node* child = NULL;
	struct device_node* root = NULL;
	int error = NO_ERR;

	TS_LOG_INFO(" wacom_module_init called here.\n");

	wac_data = kzalloc(sizeof(struct wacom_i2c), GFP_KERNEL);
	if (!wac_data) {
		TS_LOG_ERR("Failed to alloc mem for struct wac_data\n");
		return -ENOMEM;
	}

	wac_data->wacom_chip_data = kzalloc(sizeof(struct ts_kit_device_data), GFP_KERNEL);
	if (!wac_data->wacom_chip_data ) {
		TS_LOG_ERR("Failed to alloc mem for struct wacom_chip_data\n");
		error =  -ENOMEM;
		goto out;
	}
	root = of_find_compatible_node(NULL, NULL, "huawei,ts_kit");
	if (!root)
	{
		TS_LOG_ERR("huawei_ts, find_compatible_node huawei,ts_kit error\n");
		 error = -EINVAL;
		goto out;
	}

	for_each_child_of_node(root, child)  //find the chip node
	{
		if (of_device_is_compatible(child, WACOM_VENDER_NAME))
		{
			found = true;
			break;
		}
    }
    if (!found){
		TS_LOG_ERR(" not found chip wacom child node!\n");
		error = -EINVAL;
		goto out;
    }

    wac_data->wacom_chip_data->cnode = child;
    wac_data->wacom_chip_data->ops = &ts_kit_wacom_ops;

    error = huawei_ts_chip_register(wac_data->wacom_chip_data);
    if(error)
    {
		TS_LOG_ERR(" wacom chip register fail !\n");
		goto out;
    }
    TS_LOG_INFO("wacom chip_register! err=%d\n", error);
    return error;
out:
    if(wac_data->wacom_chip_data) {
		kfree(wac_data->wacom_chip_data);
		wac_data->wacom_chip_data = NULL;/*Fix the DTS parse error cause panic bug*/
	}

    if (wac_data) {
		kfree(wac_data);
		wac_data = NULL;
    }
    return error;
}

static void __exit wacom_module_exit(void)
{

   TS_LOG_INFO("wacom_module_exit called here\n");
    return;
}

late_initcall(wacom_module_init);
module_exit(wacom_module_exit);
MODULE_AUTHOR("Huawei Device Company");
MODULE_DESCRIPTION("Huawei TouchScreen Driver");
MODULE_LICENSE("GPL");






 


#include <linux/module.h>
#include <linux/printk.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/rpmsg.h>

#include "hwsensor.h"
#include "sensor_commom.h"
#include "hw_csi.h"
#include "../pmic/hw_pmic.h"
//lint -save -e650 -e31

#define I2S(i) container_of(i, sensor_t, intf)

extern struct hw_csi_pad hw_csi_pad;
static hwsensor_vtbl_t s_imx258_vtbl;

struct sensor_power_setting hw_imx258_power_setting[] = {

	//set camera reset gpio 146 to low
/*	{
		.seq_type = SENSOR_SUSPEND,
		.config_val = SENSOR_GPIO_LOW,
		.sensor_index = SENSOR_INDEX_INVALID,
		.delay = 0,
	},*/

	//enable gpio51 output iovdd 1.8v
	{
		.seq_type = SENSOR_LDO_EN,
		.config_val = SENSOR_GPIO_LOW,
		.sensor_index = SENSOR_INDEX_INVALID,
		.delay = 0,
	},

   {
        .seq_type = SENSOR_VCM_AVDD,
        .data = (void*)"cameravcm-vcc",
        .config_val = LDO_VOLTAGE_V2P85V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },

	//enable gpio34 output ois af vdd 2.95v
	{
		.seq_type = SENSOR_VCM_PWDN,
		.config_val = SENSOR_GPIO_LOW,
		.sensor_index = SENSOR_INDEX_INVALID,
		.delay = 0,
	},

	//MCAM AVDD VOUT19 2.8V
	{
		.seq_type = SENSOR_AVDD2,
		.data = (void*)"main-sensor-avdd",
		.config_val = LDO_VOLTAGE_V2P8V,
		.sensor_index = SENSOR_INDEX_INVALID,
		.delay = 0,
	},

	//MCAM0 DVDD VLDO1.2V
	{
		.seq_type = SENSOR_DVDD2,
		.data = (void*)"main-sensor-dvdd",
		.config_val = LDO_VOLTAGE_1P2V,
		.sensor_index = SENSOR_INDEX_INVALID,
		.delay = 0,
	},

	//MCAM ISP_CLK0 16M
	{
		.seq_type = SENSOR_MCLK,
		.sensor_index = SENSOR_INDEX_INVALID,
		.delay = 1,
	},

	//MCAM Reset GPIO_052
	{
		.seq_type = SENSOR_RST,
		.config_val = SENSOR_GPIO_LOW,
		.sensor_index = SENSOR_INDEX_INVALID,
		.delay = 1,
	},
};

static sensor_t s_imx258 =
{
    .intf = { .vtbl = &s_imx258_vtbl, },
    .power_setting_array = {
            .size = ARRAY_SIZE(hw_imx258_power_setting),
            .power_setting = hw_imx258_power_setting,
     },
};

static const struct of_device_id
s_imx258_dt_match[] =
{
	{
        .compatible = "huawei,imx258",
        .data = &s_imx258.intf,
    },
	{
    },
};

MODULE_DEVICE_TABLE(of, s_imx258_dt_match);

static struct platform_driver
s_imx258_driver =
{
	.driver =
    {
		.name = "huawei,imx258",
		.owner = THIS_MODULE,
		.of_match_table = s_imx258_dt_match,
	},
};

char const*
imx258_get_name(
        hwsensor_intf_t* si)
{
    sensor_t* sensor = I2S(si);
    return sensor->board_info->name;
}
static int
imx258_power_up(
        hwsensor_intf_t* si)
{
    int ret = 0;
    sensor_t* sensor = NULL;
    sensor = I2S(si);
   cam_info("enter %s. index = %d name = %s", __func__, sensor->board_info->sensor_index, sensor->board_info->name);
   if (hw_is_fpga_board()) {
		ret = do_sensor_power_on(sensor->board_info->sensor_index, sensor->board_info->name);
	} else {
		ret = hw_sensor_power_up(sensor);
	}
    if (0 == ret )
    {
        cam_info("%s. power up sensor success.", __func__);
    }
    else
    {
        cam_err("%s. power up sensor fail.", __func__);
    }
    return ret;
}

static int
imx258_power_down(
        hwsensor_intf_t* si)
{
	int ret = 0;
	sensor_t* sensor = NULL;
	sensor = I2S(si);
	cam_info("enter %s. index = %d name = %s", __func__, sensor->board_info->sensor_index, sensor->board_info->name);
	if (hw_is_fpga_board()) {
		ret = do_sensor_power_off(sensor->board_info->sensor_index, sensor->board_info->name);
	} else {
		ret = hw_sensor_power_down(sensor);
	}
    if (0 == ret )
    {
        cam_info("%s. power down sensor success.", __func__);
    }
    else
    {
        cam_err("%s. power down sensor fail.", __func__);
    }

	return ret;
}

static int imx258_csi_enable(hwsensor_intf_t* si)
{
    int ret = 0;
    sensor_t* sensor = NULL;

    sensor = I2S(si);

    ret = hw_csi_pad.hw_csi_enable((csi_index_t)0, sensor->board_info->csi_lane, sensor->board_info->csi_mipi_clk);
    if(ret)
    {
        cam_err("failed to csi enable index 0 ");
        return ret;
    }

    return 0;
}

int imx258_csi_disable(hwsensor_intf_t* si)
{
    int ret = 0;
    sensor_t* sensor = NULL;

    sensor = I2S(si);

    ret = hw_csi_pad.hw_csi_disable((csi_index_t)0);
    if(ret)
    {
        cam_err("failed to csi disable index 0 ");
        return ret;
    }

    return 0;
}

static int
imx258_match_id(
        hwsensor_intf_t* si, void * data)
{
    sensor_t* sensor = NULL;
    struct sensor_cfg_data *cdata = NULL;

    cam_info("%s enter.", __func__);

    if ((NULL == si)||(NULL == data)) {
        cam_err("%s. si is NULL.", __func__);
        return -EINVAL;
    }

    sensor = I2S(si);
    if ((NULL == sensor->board_info) || (NULL == sensor->board_info->name)){
        cam_err("%s. sensor->board_info or sensor->board_info->name is NULL .", __func__);
        return -EINVAL;
    }
    cdata  = (struct sensor_cfg_data *)data;
    cdata->data = sensor->board_info->sensor_index;
    cam_info("%s name:%s", __func__, sensor->board_info->name);

    return 0;
}

static int
imx258_config(
        hwsensor_intf_t* si,
        void  *argp)
{
	struct sensor_cfg_data *data;

	int ret =0;
	static bool imx258_power_on = false;

    if (NULL == si || NULL == argp){
        cam_err("%s si or argp is null.\n", __func__);
        return -1;
    }

	data = (struct sensor_cfg_data *)argp;
	cam_debug("imx258 cfgtype = %d",data->cfgtype);
	switch(data->cfgtype){
		case SEN_CONFIG_POWER_ON:
			if (!imx258_power_on) {
				ret = si->vtbl->power_up(si);
				imx258_power_on = true;
			}
			break;
		case SEN_CONFIG_POWER_OFF:
			if (imx258_power_on) {
				ret = si->vtbl->power_down(si);
				imx258_power_on = false;
			}
			break;
		case SEN_CONFIG_WRITE_REG:
			break;
		case SEN_CONFIG_READ_REG:
			break;
		case SEN_CONFIG_WRITE_REG_SETTINGS:
			break;
		case SEN_CONFIG_READ_REG_SETTINGS:
			break;
		case SEN_CONFIG_ENABLE_CSI:
			break;
		case SEN_CONFIG_DISABLE_CSI:
			break;
		/* case SEN_CONFIG_MATCH_ID_EXT: */
			/* break; */
		case SEN_CONFIG_MATCH_ID:
			ret = si->vtbl->match_id(si,argp);
			break;
		default:
            cam_err("%s cfgtype(%d) is error", __func__, data->cfgtype);
			break;
	}
	cam_debug("%s exit",__func__);
	return ret;
}

static hwsensor_vtbl_t
s_imx258_vtbl =
{
	.get_name = imx258_get_name,
	.config = imx258_config,
	.power_up = imx258_power_up,
	.power_down = imx258_power_down,
	.match_id = imx258_match_id,
	.csi_enable = imx258_csi_enable,
	.csi_disable = imx258_csi_disable,
};
static int32_t
imx258_platform_probe(
        struct platform_device* pdev)
{
	int rc = 0;

    if (NULL == pdev){
        cam_err("%s pdev is null.\n", __func__);
        return -1;
    }
	cam_notice("enter %s",__func__);
	if (pdev->dev.of_node) {
		rc = hw_sensor_get_dt_data(pdev, &s_imx258);
		if (rc < 0) {
			cam_err("%s failed line %d\n", __func__, __LINE__);
			goto imx258_sensor_probe_fail;
		}
	} else {
		cam_err("%s imx258 of_node is NULL.\n", __func__);
		goto imx258_sensor_probe_fail;
	}

    s_imx258.dev = &pdev->dev;

	rc = hwsensor_register(pdev, &s_imx258.intf);
    if (0 != rc){
        cam_err("%s hwsensor_register fail.\n", __func__);
        goto imx258_sensor_probe_fail;
    }
    rc = rpmsg_sensor_register(pdev, (void *)&s_imx258);
    if (0 != rc){
        cam_err("%s rpmsg_sensor_register fail.\n", __func__);
        hwsensor_unregister(&s_imx258.intf);
        goto imx258_sensor_probe_fail;
    }

imx258_sensor_probe_fail:
	return rc;
}

static int __init
imx258_init_module(void)
{
    cam_notice("enter %s",__func__);
    return platform_driver_probe(&s_imx258_driver,
            imx258_platform_probe);
}

static void __exit
imx258_exit_module(void)
{
    rpmsg_sensor_unregister((void *)&s_imx258);
    hwsensor_unregister(&s_imx258.intf);
    platform_driver_unregister(&s_imx258_driver);
}

module_init(imx258_init_module);
module_exit(imx258_exit_module);
MODULE_DESCRIPTION("imx258");
MODULE_LICENSE("GPL v2");
//lint -restore


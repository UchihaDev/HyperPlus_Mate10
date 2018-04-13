#ifndef __SENSOR_DEBUG_H__
#define __SENSOR_DEBUG_H__


struct led_config_data {
	struct device* dev;
	struct class*  led_config_class;
	struct platform_device *pdev;
};

#define LED_CONFIG    "led_config"


#endif

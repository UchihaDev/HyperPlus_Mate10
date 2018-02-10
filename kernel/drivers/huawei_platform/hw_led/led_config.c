#include <linux/module.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <huawei_platform/log/hw_log.h>
#include "led_config.h"
#include <linux/platform_device.h>

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif
#define HWLOG_TAG  led_config
static int led_config_flag = 0;
HWLOG_REGIST();
#define LED_CONFIG_EXIST    "led_config_support"

static ssize_t led_config_status_show(struct device *dev,
					  struct device_attribute *attr,
					  char *buf)
{
	return snprintf(buf, PAGE_SIZE, "%d\n", led_config_flag);
}

/*files create*/
static DEVICE_ATTR(led_config_status, 0660, led_config_status_show,
		NULL);

static struct attribute *led_config_attrs[] = {
	&dev_attr_led_config_status.attr,
	NULL
};

static const struct attribute_group led_config_attrs_group = {
	.attrs = led_config_attrs,
};

static const struct of_device_id led_config_match_table[] = {
	{.compatible = "huawei,led_config",},
	{},
};

MODULE_DEVICE_TABLE(of, led_config_match_table);

static int led_config_probe(struct platform_device *pdev)
{
	int ret = 0;
	int temp = 0;
	struct led_config_data* data = NULL;
	struct device_node *led_node = NULL;

	data = devm_kzalloc(&pdev->dev,sizeof(struct led_config_data),
					       GFP_KERNEL);
	if (!data) {
		hwlog_err("%s Failed to allocate memory for data\n", __func__);
		return -ENOMEM;
	}

	data->pdev = pdev;

	led_node = pdev->dev.of_node;
	if(!led_node){
		hwlog_err("%s failed to find dts node led_alwayson\n", __func__);
		ret = -ENODEV;
		goto free_devm;
	}
	if (of_property_read_u32(led_node, LED_CONFIG_EXIST, &temp))
		hwlog_err("%s:read led_config_support fail\n", __func__);
	else
		led_config_flag = temp;
	data->led_config_class = class_create(THIS_MODULE, "led_config");
	if (IS_ERR(data->led_config_class)){
		ret = PTR_ERR(data->led_config_class);
		goto free_devm;
	}
	data->dev = device_create(data->led_config_class, NULL,
			0, NULL, "led_config");
	if (NULL == data->dev) {
		hwlog_err("%s device_create Failed", __func__);
		ret = -1;
		goto free_class;
	}

	ret = sysfs_create_group(&data->dev->kobj, &led_config_attrs_group);
	if (ret){
		hwlog_err("%s sysfs_create_group failed ret=%d.\n", __func__, ret);
		ret = -1;
		goto free_device;
	}
	hwlog_info("%s succ.\n", __func__);
	return ret;

free_device:
	device_destroy(data->led_config_class, 0);
free_class:
	class_destroy(data->led_config_class);
free_devm:
	devm_kfree(&pdev->dev, data);
	return ret;
}

static int led_config_remove(struct platform_device *pdev)
{
	struct  led_config_data* data = dev_get_drvdata(&pdev->dev);
	if (NULL == data)
		return -EINVAL;
	sysfs_remove_group(&data->dev->kobj, &led_config_attrs_group);
	device_destroy(data->led_config_class, 0);
	class_destroy(data->led_config_class);
	devm_kfree(&pdev->dev, data);
	hwlog_info("%s\n", __func__);
	return 0;
}

struct platform_driver led_config_driver = {
	.probe = led_config_probe,
	.remove = led_config_remove,
	.driver = {
		   .name = LED_CONFIG,
		   .owner = THIS_MODULE,
		   .of_match_table = of_match_ptr(led_config_match_table),
		   },
};

static int __init led_config_init(void)
{
	hwlog_info("init!\n");
	return platform_driver_register(&led_config_driver);
}

static void __exit led_config_exit(void)
{
	hwlog_info("exit!\n");
	platform_driver_unregister(&led_config_driver);
}

module_init(led_config_init);
module_exit(led_config_exit);

MODULE_AUTHOR("HUAWEI");
MODULE_DESCRIPTION("Led config driver");
MODULE_LICENSE("GPL");

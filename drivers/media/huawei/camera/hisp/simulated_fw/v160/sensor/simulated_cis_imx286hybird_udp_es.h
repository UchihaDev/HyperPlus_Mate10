

#include "../../metadata/isp_metadata_vendor_tag.h"
#include "../../metadata/camera_metadata_tags.h"
#include  "../../metadata/simulated_utils.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

static unsigned int imx286hybird_udp_es_position;
static unsigned char imx286hybird_udp_es_lens_facing = ANDROID_LENS_FACING_BACK;
static unsigned int imx286hybird_udp_es_orientation = 90;
static unsigned int imx286hybird_udp_es_jpeg_orientation = 90;
static unsigned char imx286hybird_udp_es_flash_available = 1;
static float imx286hybird_udp_es_focal_lengths = 4.5f;	/*< 2.38mm */
static float imx286hybird_udp_es_aperture = 2.2f;
static unsigned int imx286hybird_udp_es_eq_focus = 27;	/* mm */
static float imx286hybird_udp_es_min_focus_distance = 10.0;	/* mm */

static unsigned char imx286hybird_udp_es_availableAfModesBack[] = {
    ANDROID_CONTROL_AF_MODE_OFF,
	ANDROID_CONTROL_AF_MODE_AUTO,
	/* CAMERA_FOCUS_INFINITY, */
	ANDROID_CONTROL_AF_MODE_MACRO,
	ANDROID_CONTROL_AF_MODE_CONTINUOUS_VIDEO,
	ANDROID_CONTROL_AF_MODE_CONTINUOUS_PICTURE
};

static int imx286hybird_udp_es_resolution[2] = {
	3968, 2976
};

static int imx286hybird_udp_es_availableRawSize[2] = {
	3968, 2976
};

static unsigned int imx286hybird_udp_es_availableProcessedSizesBack[] = {
	3968, 2976,
	2976, 2976,
	3840, 2160,
	3280, 2448,
	3264, 2448,
	3264, 1840,
	2448, 2448,
	2592, 1952,
	2048, 1536,
	1920, 1080,
	1440,1080,
	1536, 864,
	1280,960,
	1280, 720,
	960, 720,
	720, 720,
	640, 480,
	736, 412,
	544, 408,
	400, 400,
	352, 288,
	320, 240,
	208, 144,
	176, 144,
};

static unsigned int imx286hybird_udp_es_availableJpegSizesBack[] = {
	320, 240,
	640, 480,
	1280, 720,
	1920, 1080,


	3264, 1840,
	3264, 2448,
	3968, 2976,
	2048, 1536,
	2976, 2976,
	3968, 2240,
};

static float imx286hybird_udp_es_sensorPhysicalSize[] = {
	4.60f,
	3.40f,
};				/* mm */

static const unsigned int imx286hybird_udp_es_videoFPSRange[] = { 120, 60 };

cis_capability imx286hybird_udp_es_capability[] = {
	{(unsigned int)ANDROID_SENSOR_INFO_PHYSICAL_SIZE,
	 imx286hybird_udp_es_sensorPhysicalSize, sizeof(float),
	 sizeof(imx286hybird_udp_es_sensorPhysicalSize) / sizeof(float)},
	{(unsigned int)ANDROID_HUAWEI_DEVICE_SENSOR_POSITION,
	 &imx286hybird_udp_es_position, sizeof(unsigned int),
	 sizeof(imx286hybird_udp_es_position) / sizeof(unsigned int)},
	{(unsigned int)ANDROID_LENS_FACING, &imx286hybird_udp_es_lens_facing,
	 sizeof(unsigned char),
	 sizeof(imx286hybird_udp_es_lens_facing) / sizeof(unsigned char)},
	{(unsigned int)ANDROID_SCALER_AVAILABLE_RAW_SIZES,
	 imx286hybird_udp_es_availableRawSize, sizeof(int),
	 sizeof(imx286hybird_udp_es_availableRawSize) / sizeof(int)},
	{(unsigned int)ANDROID_SCALER_AVAILABLE_PROCESSED_SIZES,
	 imx286hybird_udp_es_availableProcessedSizesBack, sizeof(unsigned int),
	 sizeof(imx286hybird_udp_es_availableProcessedSizesBack) / sizeof(unsigned int)},
	{(unsigned int)ANDROID_SCALER_AVAILABLE_JPEG_SIZES,
	 imx286hybird_udp_es_availableJpegSizesBack, sizeof(unsigned int),
	 sizeof(imx286hybird_udp_es_availableJpegSizesBack) / sizeof(unsigned int)},
	{(unsigned int)ANDROID_SENSOR_ORIENTATION, &imx286hybird_udp_es_orientation,
	 sizeof(unsigned int),
	 sizeof(imx286hybird_udp_es_orientation) / sizeof(unsigned int)},
	{(unsigned int)ANDROID_JPEG_ORIENTATION, &imx286hybird_udp_es_jpeg_orientation,
	 sizeof(unsigned int),
	 sizeof(imx286hybird_udp_es_jpeg_orientation) / sizeof(unsigned int)},
	{(unsigned int)ANDROID_FLASH_INFO_AVAILABLE,
	 &imx286hybird_udp_es_flash_available, sizeof(unsigned char),
	 sizeof(imx286hybird_udp_es_flash_available) / sizeof(unsigned char)},
	{(unsigned int)ANDROID_CONTROL_AF_AVAILABLE_MODES,
	 imx286hybird_udp_es_availableAfModesBack, sizeof(unsigned char),
	 sizeof(imx286hybird_udp_es_availableAfModesBack) / sizeof(unsigned char)},
	{(unsigned int)ANDROID_LENS_APERTURE, &imx286hybird_udp_es_aperture,
	 sizeof(float), sizeof(imx286hybird_udp_es_aperture) / sizeof(float)},
	{(unsigned int)ANDROID_LENS_INFO_AVAILABLE_FOCAL_LENGTHS,
	 &imx286hybird_udp_es_focal_lengths, sizeof(float),
	 sizeof(imx286hybird_udp_es_focal_lengths) / sizeof(float)},
	{(unsigned int)ANDROID_HW_EQUIVALENT_FOCUS, &imx286hybird_udp_es_eq_focus,
	 sizeof(unsigned int),
	 sizeof(imx286hybird_udp_es_eq_focus) / sizeof(unsigned int)},
	{(unsigned int)ANDROID_LENS_INFO_MINIMUM_FOCUS_DISTANCE,
	 &imx286hybird_udp_es_min_focus_distance, sizeof(float),
	 sizeof(imx286hybird_udp_es_min_focus_distance) / sizeof(float)},
	{(unsigned int)ANDROID_HW_VIDEO_FPS_SUPPORTED,
	 &imx286hybird_udp_es_videoFPSRange, sizeof(unsigned int),
	 sizeof(imx286hybird_udp_es_videoFPSRange) / sizeof(unsigned int)},
};

int imx286hybird_udp_es_cis_get_capability(isp_metadata_t *metadata)
{
	if (NULL == metadata)
		return -1;

	unsigned int i = 0;

	for (i = 0; i < array_count(imx286hybird_udp_es_capability); i++) {
		isp_metadata_set(metadata,
				 imx286hybird_udp_es_capability[i].tag,
				 imx286hybird_udp_es_capability[i].value,
				 imx286hybird_udp_es_capability[i].type_size,
				 imx286hybird_udp_es_capability[i].count);
	}

	return 0;
}



#include "../../metadata/isp_metadata_vendor_tag.h"
#include "../../metadata/camera_metadata_tags.h"
#include  "../../metadata/simulated_utils.h"
uint8_t ov8865_udp_es_lensFacing = ANDROID_LENS_FACING_FRONT;

float ov8865_udp_es_minFocusDistance = 1.0/0.05;

int ov8865_udp_es_mOrientation = 270;

int ov8865_udp_es_mJpegOrientation = 270;

float ov8865_udp_es_focalLength = 2.38f;	/* mm */

uint8_t ov8865_udp_es_flashAvailable;

uint8_t ov8865_udp_es_availableAfModesFront[] = {
	ANDROID_CONTROL_AF_MODE_OFF,
	ANDROID_CONTROL_AF_MODE_AUTO,
	ANDROID_CONTROL_AF_MODE_MACRO,
	ANDROID_CONTROL_AF_MODE_CONTINUOUS_VIDEO,
	ANDROID_CONTROL_AF_MODE_CONTINUOUS_PICTURE,
};

float ov8865_udp_es_sensorPhysicalSize[2] = { 3.20f, 2.40f };	/* mm */

uint32_t ov8865_udp_es_kAvailableJpegSizesFront[] = {
	640,480,
	320, 240,
	1280, 720,
	1920, 1080,
	3264, 2448,
	2448, 2448,
	3264, 1840,
	1536, 864,
};

uint32_t ov8865_udp_es_kAvailableProcessedSizesFront[] = {
	3264, 2448,
	2448, 2448,
	3264, 1840,
	1920, 1080,
	1440, 1080,
	1536, 864,
	1280, 960,
	1280, 720,
	960, 720,
	720, 720,
/* cts testDigitalZoomPreviewCombinations wil failed . because AR is 1.32*/
/* 720, 544, */
	640,480,
	352, 288,
	320, 240,
	208, 144,
	176, 144,
};

cis_capability ov8865_udp_es_capability[] = {
	{(unsigned int)ANDROID_LENS_FACING, &ov8865_udp_es_lensFacing, sizeof(uint8_t),
	 sizeof(ov8865_udp_es_lensFacing) / sizeof(uint8_t)}
	,
	{(unsigned int)ANDROID_LENS_INFO_MINIMUM_FOCUS_DISTANCE,
	 &ov8865_udp_es_minFocusDistance, sizeof(float),
	 sizeof(ov8865_udp_es_minFocusDistance) / sizeof(float)},
	{(unsigned int)ANDROID_SENSOR_ORIENTATION, &ov8865_udp_es_mOrientation,
	 sizeof(unsigned int),
	 sizeof(ov8865_udp_es_mOrientation) / sizeof(unsigned int)},
	{(unsigned int)ANDROID_JPEG_ORIENTATION, &ov8865_udp_es_mJpegOrientation,
	 sizeof(unsigned int),
	 sizeof(ov8865_udp_es_mJpegOrientation) / sizeof(unsigned int)},
	{(unsigned int)ANDROID_LENS_INFO_AVAILABLE_FOCAL_LENGTHS,
	 &ov8865_udp_es_focalLength, sizeof(float),
	 sizeof(ov8865_udp_es_focalLength) / sizeof(float)},
	{(unsigned int)ANDROID_FLASH_INFO_AVAILABLE, &ov8865_udp_es_flashAvailable,
	 sizeof(unsigned char),
	 sizeof(ov8865_udp_es_flashAvailable) / sizeof(unsigned char)},
	{(unsigned int)ANDROID_CONTROL_AF_AVAILABLE_MODES,
	 ov8865_udp_es_availableAfModesFront, sizeof(unsigned char),
	 sizeof(ov8865_udp_es_availableAfModesFront) / sizeof(unsigned char)},
	{(unsigned int)ANDROID_SENSOR_INFO_PHYSICAL_SIZE,
	 ov8865_udp_es_sensorPhysicalSize, sizeof(float),
	 sizeof(ov8865_udp_es_sensorPhysicalSize) / sizeof(float)},
	{(unsigned int)ANDROID_SCALER_AVAILABLE_JPEG_SIZES,
	 ov8865_udp_es_kAvailableJpegSizesFront, sizeof(unsigned int),
	 sizeof(ov8865_udp_es_kAvailableJpegSizesFront) / sizeof(unsigned int)},
	{(unsigned int)ANDROID_SCALER_AVAILABLE_PROCESSED_SIZES,
	 ov8865_udp_es_kAvailableProcessedSizesFront, sizeof(unsigned int),
	 sizeof(ov8865_udp_es_kAvailableProcessedSizesFront) / sizeof(unsigned int)},

};

int ov8865_udp_es_cis_get_capability(isp_metadata_t *metadata)
{
	if (NULL == metadata)
		return -1;

	unsigned int i = 0;

	for (i = 0; i < array_count(ov8865_udp_es_capability); i++) {
		isp_metadata_set(metadata,
				 ov8865_udp_es_capability[i].tag,
				 ov8865_udp_es_capability[i].value,
				 ov8865_udp_es_capability[i].type_size,
				 ov8865_udp_es_capability[i].count);
	}
	return 0;
}

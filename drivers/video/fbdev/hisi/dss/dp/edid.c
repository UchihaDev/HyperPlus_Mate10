/* Copyright (c) 2013-2014, Hisilicon Tech. Co., Ltd. All rights reserved.
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

#include "edid.h"

static const uint8_t edid_v1_other_descriptor_flag[2] = {0x00, 0x00};

int parse_edid(struct dp_ctrl *dptx, uint16_t len)
{
	int16_t i, ext_block_num;
	int ret;
	uint8_t* edid_t;

	if (dptx == NULL) {
		HISI_FB_ERR("dptx is NULL pointer\n");
		return -EINVAL;
	}

	edid_t = dptx->edid;
	HISI_FB_INFO("parse_edid +\n");
	/*Check if data has any error*/
	if (edid_t == NULL) {
		HISI_FB_ERR("Raw Data is invalid!(NULL error)\n");
		return -EINVAL;
	}

	if (((len/EDID_LENGTH) > 5) || ((len%EDID_LENGTH) != 0) || (len < EDID_LENGTH)) {
		HISI_FB_ERR("Raw Data length is invalid(not the size of (128 x N , N = [1-5]) uint8_t!");
		return -EINVAL;
	}

	/*Parse the EDID main part, check how many(count as ' ext_block_num ') Extension blocks there are to follow.*/
	ext_block_num = parse_main(dptx);

	if (ext_block_num > 0) {
		dptx->edid_info.Audio.extACount = 0;
		dptx->edid_info.Audio.extSpeaker = 0;
		dptx->edid_info.Audio.basicAudio = 0;
		dptx->edid_info.Audio.spec = NULL;
		/*Parse all Extension blocks */
		for (i = 0; i < ext_block_num; i++) {
			ret = parse_extension(dptx, edid_t + (EDID_LENGTH * (i + 1)));
			if ( ret != 0 ) {
				HISI_FB_ERR("Extension Parsing failed!Only returning the Main Part of this EDID!\n");
				break;
			}
		}
	} else if (ext_block_num < 0) {
		HISI_FB_ERR("Error occured while parsing, returning with NULL!");
		return -EINVAL;
	}
	HISI_FB_INFO("parse_edid -\n");
	return 0;
}

int check_main_edid(uint8_t* edid)
{
	uint32_t checksum = 0;
	int32_t i;
	if(edid == NULL) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}
	/*Verify 0 checksum*/
	for (i = 0; i < EDID_LENGTH; i++)
		checksum += edid[i];
	if (checksum & 0xFF) {
		HISI_FB_ERR("EDID checksum failed - data is corrupt. Continuing anyway.\n");
		return -EINVAL;
	}

	/*Verify Header*/
	for(i = 0; i < EDID_HEADER_END + 1; i++)
	{
		if(edid[i] != edid_v1_header[i]) {
			HISI_FB_INFO("first uint8_ts don't match EDID version 1 header\n");
			return -EINVAL;
		}
	}

	return 0;
}

int parse_main(struct dp_ctrl *dptx)
{
	int16_t i;
	int ret;
	uint8_t* block;
	uint8_t* edid_t;
	struct edid_video *vid_info;

	if (dptx == NULL) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}
	if (dptx->edid == NULL) {
		HISI_FB_ERR("The edid pointer is NULL.\n");
		return -EINVAL;
	}

	dptx->edid_info.Video.TimingInfo = NULL;
	dptx->edid_info.Video.extTiming = NULL;
	dptx->edid_info.Video.dp_monitor_descriptor = NULL;
	dptx->edid_info.Video.extVCount = 0;
	edid_t = dptx->edid;
	/*Initialize some fields*/
	vid_info = &(dptx->edid_info.Video);
	vid_info->mainVCount = 0;
	vid_info->maxPixelClock = 0;

	if (check_main_edid(edid_t)) {
		HISI_FB_ERR("The main edid block is wrong.\n");
		return -EINVAL;
	}
	/*Check EDID version (usually 1.3)*/
	HISI_FB_DEBUG("EDID version %d revision %d\n", (int)edid_t[EDID_STRUCT_VERSION],
										(int)edid_t[EDID_STRUCT_REVISION]);

	/*Check Display Image Size(Physical)*/
	vid_info->maxHImageSize = (uint16_t)edid_t[H_MAX_IMAGE_SIZE];
	vid_info->maxVImageSize = (uint16_t)edid_t[V_MAX_IMAGE_SIZE];
	/*Alloc the name memory*/
	vid_info->dp_monitor_descriptor = (char *)kzalloc((MONTIOR_NAME_DESCRIPTION_SIZE + 1) * sizeof(char), GFP_KERNEL);
	if (vid_info->dp_monitor_descriptor == NULL) {
		HISI_FB_ERR("dp_monitor_descriptor memory alloc fail\n");
		return -EINVAL;
	}
	/*Parse the EDID Detailed Timing Descriptor*/
	block = edid_t + DETAILED_TIMING_DESCRIPTIONS_START;
	/*EDID main part has a total of four Descriptor Block*/
	for (i = 0; i < DETAILED_TIMING_DESCRIPTION_COUNT; i++,
                            block += DETAILED_TIMING_DESCRIPTION_SIZE)
	{
		switch (block_type(block))
		{
			case DETAILED_TIMING_BLOCK :
				if (i == 0) {
					ret = parse_timing_description(dptx, block, true);
				} else {
					ret = parse_timing_description(dptx, block, false);
				}
				if (ret != 0) {
					HISI_FB_INFO("Timing Description Parsing failed!\n");
					return ret;
				}
				break;
			case MONITOR_LIMITS :
				parse_monitor_limits(dptx, block);
				break;
			case MONITOR_NAME :
				ret = parse_monitor_name(dptx, block, DETAILED_TIMING_DESCRIPTION_SIZE);
				if (ret != 0) {
					HISI_FB_ERR("The monitor name parsing failed.\n");
					return ret;
				}
				break;
			default :
				break;
		}
	}

	HISI_FB_DEBUG( "Extensions to follow:\t%d\n", (int)edid_t[EXTENSION_FLAG]);
	/*Return the number of following extension blocks*/
	return (int)edid_t[EXTENSION_FLAG];
}

int check_exten_edid(uint8_t* exten)
{
	uint32_t i, checksum;
	checksum = 0;
	if (exten == NULL) {
		HISI_FB_ERR("The pointer is null.\n");
		return -EINVAL;
	}

	for (i = 0; i < EDID_LENGTH; i++)
		checksum += exten[i];
	if (checksum & 0xFF) {
		HISI_FB_ERR("Extension Data checksum failed - data is corrupt. Continuing anyway.\n");
		return -EINVAL;
	}
	/*Check Extension Tag*/
	/*( Header Tag stored in the first uint8_t )*/
	if (exten[0] != EXTENSION_HEADER) {
		HISI_FB_ERR("Not CEA-EDID Timing Extension, Extension-Parsing will not continue!\n");
		return -EINVAL;
	}
	return 0;
}

int parse_extension_timing_description(struct dp_ctrl * dptx, uint8_t* dtdBlock, uint32_t dtdBegin, uint16_t DTDtotal)
{
	uint32_t i;
	int ret;

	if ((dptx == NULL) || (dtdBlock == NULL)) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}

	if ((dtdBegin + 1 + DTDtotal * DETAILED_TIMING_DESCRIPTION_SIZE) > EDID_LENGTH) {
		HISI_FB_ERR("The dtd total number 0x%x is out of the limit\n", DTDtotal);
		return -EINVAL;
	}

	for (i = 0; i < DTDtotal; i++, dtdBlock += DETAILED_TIMING_DESCRIPTION_SIZE)
	{
		switch (block_type(dtdBlock))
		{
			case DETAILED_TIMING_BLOCK:
				ret = parse_timing_description(dptx, dtdBlock, false);
				if (ret != 0) {
					HISI_FB_ERR("Timing Description Parsing failed!");
					return ret;
				}
				break;
			case MONITOR_LIMITS :
				parse_monitor_limits(dptx, dtdBlock);
				break;
			default :
				break;
		}
	}
	return 0;
}

int parse_extension(struct dp_ctrl * dptx, uint8_t* exten)
{
	int ret;
	uint8_t* dtdBlock;
	uint8_t* ceaBlock;
	uint8_t dtd_start_byte = 0;
	uint8_t cea_data_block_collection = 0;
	uint16_t DTDtotal =0;
	struct edid_video *vid_info;
	struct edid_audio *aud_info;

	if ((dptx == NULL) || (exten == NULL)) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}

	vid_info = &(dptx->edid_info.Video);
	aud_info = &(dptx->edid_info.Audio);

	ret = check_exten_edid(exten);
	if (ret) {
		HISI_FB_ERR("The check_exten_edid failed.\n");
		return ret;
	}
	/*
	* Get uint8_t number (decimal) within this block where the 18-uint8_t DTDs begin.
	* ( Number data stored in the third uint8_t )
	*/

	if (exten[2] == 0x00) {
		HISI_FB_INFO("There are no DTDs present in this extension block and no non-DTD data.\n");
		return -EINVAL;
	} else if (exten[2] == 0x04) {
		dtd_start_byte = 0x04;
	} else {
		cea_data_block_collection = 0x04;
		dtd_start_byte = exten[2];
	}
	/*
	  *  Get Number of Native DTDs present, other Version 2+ information
	  *  DTD Total stored in the fourth uint8_t )
	  */
	if(1 != aud_info->basicAudio) {
		aud_info->basicAudio = (0x40 & exten[3] ) >> 6;
	}

	DTDtotal = LOWER_NIBBLE(exten[3]);
	//Parse DTD in Extension
	dtdBlock = exten + dtd_start_byte;
	if (DTDtotal != (EDID_LENGTH - dtd_start_byte - 1)/DETAILED_TIMING_DESCRIPTION_SIZE) {
		HISI_FB_INFO("The number of native DTDs is not equal the size\n");
		DTDtotal = (EDID_LENGTH - dtd_start_byte - 1)/DETAILED_TIMING_DESCRIPTION_SIZE;
	}

	ret = parse_extension_timing_description(dptx, dtdBlock, dtd_start_byte, DTDtotal);
	if (ret) {
		HISI_FB_ERR("Parse the extension block timing information fail.\n");
		return ret;
	}
	/*Parse CEA Data Block Collection*/
	if (cea_data_block_collection == 0x04) {
		ceaBlock = exten + cea_data_block_collection;
		ret = parse_cea_data_block(dptx, ceaBlock, dtd_start_byte);
		if (ret != 0) {
			HISI_FB_ERR("CEA data block Parsing failed!\n");
			return ret;
		}
	}

	return 0;
}

int parse_timing_description(struct dp_ctrl *dptx, uint8_t *dtd, bool preferred)
{
	int i;
	void *temp_ptr;
	struct edid_video *vid_info;
	if ((dptx == NULL) || (dtd == NULL)) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}

	vid_info = &(dptx->edid_info.Video);
	/*Set preferred Timing and search the Maximum pixels & lines*/
	if (preferred) {
		vid_info->mainVCount = 1;
		/*Initial Max Value*/
		vid_info->maxHPixels = H_ACTIVE;
		vid_info->maxVPixels = V_ACTIVE;
		/*Initial Memory Set*/
		vid_info->TimingInfo = kzalloc(sizeof(struct timing_info), GFP_KERNEL);
		if (vid_info->TimingInfo == NULL ) {
			HISI_FB_ERR("Initialize TimingInfo part failed!\n");
			return -EINVAL;
		}
	} else {
		/*Get Max Value by comparing all values*/
		if (H_ACTIVE > vid_info->maxHPixels)
			vid_info->maxHPixels = H_ACTIVE;
		if (V_ACTIVE > vid_info->maxVPixels)
			vid_info->maxVPixels = V_ACTIVE;
		/*Add memory as needed with error handling*/
		temp_ptr= kzalloc((vid_info->mainVCount + 1) * sizeof(struct timing_info), GFP_KERNEL);

		if (temp_ptr == NULL) {
			HISI_FB_ERR( "Realloc TimingInfo part failed!\n");
			return -EINVAL;
		} else {
			if (vid_info->TimingInfo){
				memcpy(temp_ptr, vid_info->TimingInfo, vid_info->mainVCount * sizeof(struct timing_info));
				kfree(vid_info->TimingInfo);
				vid_info->TimingInfo = NULL;
			}
			vid_info->TimingInfo = temp_ptr;
		}
		vid_info->mainVCount += 1;
	}

	/*set value of ' i ' (for counting)*/
	i = vid_info->mainVCount -1;

	/*Set up Video Timing fields in edid_info( global struct variable: edid_info )*/
	vid_info->TimingInfo[i].hActivePixels = H_ACTIVE;
	vid_info->TimingInfo[i].hBlanking = H_BLANKING;
	vid_info->TimingInfo[i].hSyncOffset = H_SYNC_OFFSET;
	vid_info->TimingInfo[i].hSyncPulseWidth = H_SYNC_WIDTH;
	vid_info->TimingInfo[i].hBorder = H_BORDER;
	vid_info->TimingInfo[i].hSize = H_SIZE;

	vid_info->TimingInfo[i].vActivePixels = V_ACTIVE;
	vid_info->TimingInfo[i].vBlanking = V_BLANKING;
	vid_info->TimingInfo[i].vSyncOffset = V_SYNC_OFFSET;
	vid_info->TimingInfo[i].vSyncPulseWidth = V_SYNC_WIDTH;
	vid_info->TimingInfo[i].vBorder = V_BORDER;
	vid_info->TimingInfo[i].vSize = V_SIZE;

	vid_info->TimingInfo[i].pixelClock = PIXEL_CLOCK;

	vid_info->TimingInfo[i].inputType = INPUT_TYPE;//need to modify later
	vid_info->TimingInfo[i].interlaced = INTERLACED;
	vid_info->TimingInfo[i].vSyncPolarity = V_SYNC_POLARITY;
	vid_info->TimingInfo[i].hSyncPolarity = H_SYNC_POLARITY;
	vid_info->TimingInfo[i].syncScheme = SYNC_SCHEME;
	vid_info->TimingInfo[i].schemeDetail = SCHEME_DETAIL;
	HISI_FB_INFO("The timinginfo %d : hActivePixels is %d, vActivePixels is %d\n", i,
					vid_info->TimingInfo[i].hActivePixels, vid_info->TimingInfo[i].vActivePixels);

	return 0;
}

int parse_audio_spec_info(struct edid_audio *aud_info, struct edid_audio_info *spec_info, uint8_t* cDblock)
{
	if ((cDblock == NULL) || (spec_info == NULL)) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}
	if ((EXTEN_AUDIO_FORMAT <= 8) && (EXTEN_AUDIO_FORMAT >= 1)) {
		/*Set up SAD fields*/
		spec_info->format = EXTEN_AUDIO_FORMAT;
		spec_info->channels =  EXTEN_AUDIO_MAX_CHANNELS;
		spec_info->sampling = EXTEN_AUDIO_SAMPLING;
		if (EXTEN_AUDIO_FORMAT == 1)
			spec_info->bitrate = EXTEN_AUDIO_LPCM_BIT;
		else
			spec_info->bitrate = EXTEN_AUDIO_BITRATE;
		aud_info->extACount += 1;
	}
	return 0;
}

int parse_extension_audio_tag(struct edid_audio *aud_info, uint8_t* cDblock, uint8_t tempL)
{
	uint8_t i, xa;
	void *temp_ptr;
	if ((aud_info == NULL) ||(cDblock == NULL)) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}

	if(tempL < 1) {
		return -EINVAL;
	}

	for (i = 0; i <= (tempL - 1) / 3; i++) {
		xa = aud_info->extACount;

		if (xa == 0) {
			/*Initial audio part*/
			if (aud_info->spec != NULL) {
				HISI_FB_ERR("The spec of audio is error.\n");
				return -EINVAL;
			}
			aud_info->spec = kzalloc(sizeof(struct edid_audio_info), GFP_KERNEL);
			if (aud_info->spec == NULL) {
				HISI_FB_ERR( "malloc Audio Spec part failed!\n");
				return -EINVAL;
			}
		} else {
			/*Add memory as needed with error handling*/
			temp_ptr = kzalloc((xa + 1) * sizeof(struct edid_audio_info), GFP_KERNEL);
			if (temp_ptr == NULL) {
				HISI_FB_ERR( "Realloc Audio Spec part failed!\n");
				return -EINVAL;
			} else {
				if(aud_info->spec == NULL) {
					HISI_FB_ERR("The spec is NULL.\n");
					kfree(temp_ptr);
					return -EINVAL;
				}
				memcpy(temp_ptr, aud_info->spec, xa * sizeof(struct edid_audio_info));
				kfree(aud_info->spec);
				aud_info->spec = NULL;
				aud_info->spec = temp_ptr;
			}
		}
		if (parse_audio_spec_info(aud_info, &(aud_info->spec[xa]), cDblock)) {
			HISI_FB_ERR("parse the audio spec info fail.\n");
			return -EINVAL;
		}

		cDblock += 3;
	}
	return 0;
}

int parse_extension_video_tag(struct edid_video *vid_info, uint8_t* cDblock, uint8_t tempL)
{
	uint8_t i, xv;
	void *temp_ptr;
	if ((vid_info == NULL) || (cDblock == NULL)) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}

	if(tempL < 1) {
		return -EINVAL;
	}

	for (i = 1; i < tempL; i++) {
		if (EXTEN_VIDEO_CODE != 0 && EXTEN_VIDEO_CODE <= 108
			&& EXTEN_VIDEO_CODE == 16) {
			xv = vid_info->extVCount;
			if (xv == 0) {
				/*Initial extTiming part*/
				vid_info->extTiming = kzalloc(sizeof(struct ext_timing), GFP_KERNEL);
				if (vid_info->extTiming == NULL) {
					HISI_FB_ERR( "malloc extTiming part failed!\n");
					return -EINVAL;
				}
			} else {
				/*Add memory as needed with error handling*/
				temp_ptr = kzalloc((xv + 1) * sizeof(struct ext_timing), GFP_KERNEL);
				if (temp_ptr == NULL) {
					HISI_FB_ERR("Realloc extTiming part failed!\n");
					//kfree( vid_info->extTiming );
					return -EINVAL;
				} else {
					if (vid_info->extTiming == NULL) {
						HISI_FB_ERR("The extTiming is NULL.\n");
						kfree(temp_ptr);
						temp_ptr = NULL;
						return -EINVAL;
					}
					memcpy(temp_ptr, vid_info->extTiming, xv  * sizeof(struct ext_timing));
					kfree(vid_info->extTiming);
					vid_info->extTiming = NULL;
					vid_info->extTiming = temp_ptr;
				}
			}
			/*Set up SVD fields*/
			vid_info->extTiming[xv].extFormatCode = EXTEN_VIDEO_CODE;
			vid_info->extVCount += 1;
		}
		cDblock += 1;
	}
	return 0;
}

int parse_cea_data_block(struct dp_ctrl *dptx, uint8_t* ceaData, uint8_t dtdStart)
{
	uint8_t totalLength, tempL;
	uint8_t* cDblock = ceaData;
	struct edid_video *vid_info;
	struct edid_audio *aud_info;
	/* exTlist *extlist; */
	/*Initialize some fields*/
	if ((dptx == NULL) || (ceaData == NULL)) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}
	if (dtdStart > (EDID_LENGTH - 1)) {
		HISI_FB_ERR("The start of dtd is out of limit.\n");
		return -EINVAL;
	}

	totalLength = 4;
	vid_info = &(dptx->edid_info.Video);
	aud_info = &(dptx->edid_info.Audio);
	/*Parse CEA Data Block Collection*/
	do
	{
		/*Get length(total number of following uint8_ts of a certain tag)*/
		tempL = GET_CEA_DATA_BLOCK_LEN(cDblock);
		/*Get tag code*/
		switch (GET_CEA_DATA_BLOCK_TAG(cDblock))
		{
			case EXTENSION_AUDIO_TAG:
				/* Block type tag combined with data length takes 1 uint8_t*/
				cDblock += 1;
				/* Each Short Audio Descriptor(SAD) takes 3 uint8_ts*/
				if (parse_extension_audio_tag(aud_info, cDblock, tempL)) {
					HISI_FB_ERR("parse_extension_audio_tag fail.\n");
					return -EINVAL;
				}
				break;
			case EXTENSION_VIDEO_TAG:
				/* Block type tag combined with data length takes 1 uint8_t*/
				cDblock += 1;
				/* Each Short Video Descriptor(SVD) takes 1 uint8_t*/
				if (parse_extension_video_tag(vid_info, cDblock, tempL)) {
					HISI_FB_ERR("parse_extension_video_tag fail.\n");
					return -EINVAL;
				}
				break;
			case EXTENSION_SPEAKER_TAG:
				/*
				  * If the extension has Speaker Allocation Data,
				  * there should only be one
				  */
				cDblock += 1;
				aud_info->extSpeaker = EXTEN_SPEAKER;
				/*Speaker Allocation Data takes 3 uint8_ts*/
				cDblock += 3;
				break;
			default:
				cDblock += tempL;
				break;
		}
		totalLength = totalLength + tempL + 1;
	}while(totalLength < dtdStart);

	return 0;
}

int block_type(uint8_t* block)
{
	if (block == NULL) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}
	if ((block[0] == 0) && (block[1] == 0)) {
		/*Other descriptor*/
		if ((block[2] != 0) || (block[4] != 0))
			return UNKNOWN_DESCRIPTOR;
		return block[3];
	} else {
		/*Detailed timing block*/
		return DETAILED_TIMING_BLOCK;
	}
}

int parse_monitor_limits(struct dp_ctrl* dptx, uint8_t* block)
{
	struct edid_video *vid_info;
	if ((dptx == NULL) || (block == NULL)) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}

	vid_info = &(dptx->edid_info.Video);
	/*Set up limit fields*/
	vid_info->maxHFreq = H_MAX_RATE;
	vid_info->minHFreq = H_MIN_RATE;
	vid_info->maxVFreq = V_MAX_RATE;
	vid_info->minVFreq = V_MIN_RATE;
	vid_info->maxPixelClock = (int)MAX_PIXEL_CLOCK;

	return 0;
}

int parse_monitor_name(struct dp_ctrl* dptx, uint8_t* blockname, uint32_t size)
{
	uint32_t i, data0, data1, data2;
	uint32_t str_start, str_end;

	str_start = 5;
	str_end = 0;
	if ((dptx == NULL) || (blockname == NULL)) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}
	if (size != DETAILED_TIMING_DESCRIPTION_SIZE) {
		HISI_FB_ERR("The length of monitor name is wrong.\n");
		return -EINVAL;
	}
	if (size >= 7) {
		data0 = blockname[5];
		data1 = blockname[6];
		for (i = 7; i < size; i++)
		{
			data2 = blockname[i];
			if(((data0== 0x0A) && (data1 == 0x20)) && (data2 == 0x20)) {
				str_end = i - 2;
				break;
			}
			data0 = data1;
			data1 = data2;
		}
	}
	if (str_end < str_start) {
		return 0;
	}

	if (((str_end - str_start) > 0) && (dptx->edid_info.Video.dp_monitor_descriptor != NULL)) {
		memcpy(dptx->edid_info.Video.dp_monitor_descriptor, blockname + 5, (str_end - str_start));
		dptx->edid_info.Video.dp_monitor_descriptor[str_end - str_start] = '\0';
	}

	return 0;
}

int release_edid_info(struct dp_ctrl *dptx)
{
	if (dptx == NULL) {
		HISI_FB_ERR("The pointer is NULL.\n");
		return -EINVAL;
	}

	if (dptx->edid_info.Video.TimingInfo != NULL) {
		kfree(dptx->edid_info.Video.TimingInfo);
		dptx->edid_info.Video.TimingInfo = NULL;
	}

	if (dptx->edid_info.Video.extTiming != NULL) {
		kfree(dptx->edid_info.Video.extTiming);
		dptx->edid_info.Video.extTiming = NULL;
	}

	if (dptx->edid_info.Video.dp_monitor_descriptor !=NULL) {
		kfree(dptx->edid_info.Video.dp_monitor_descriptor);
		dptx->edid_info.Video.dp_monitor_descriptor = NULL;
	}

	if (dptx->edid_info.Audio.spec != NULL) {
		kfree(dptx->edid_info.Audio.spec);
		dptx->edid_info.Audio.spec = NULL;
	}

	memset(&(dptx->edid_info), 0, sizeof(struct edid_information));

	return 0;
}

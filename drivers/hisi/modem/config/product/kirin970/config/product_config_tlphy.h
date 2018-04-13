/* MD5: 8c14251b60c651ce05048a90c698e60f*/
#if !defined(__PRODUCT_CONFIG_TLPHY_H__)
#define __PRODUCT_CONFIG_TLPHY_H__

#ifdef lphy_porting 
#ifndef XTENSA_CORE
#define XTENSA_CORE Boston_NX_SWUP 
#endif 

#ifndef XTENSA_SYSTEM
#define XTENSA_SYSTEM $(ROOT_XTENSA_PATH_W)/XtDevTools/install/builds/RH-2016.1.2-linux/$(CFG_XTENSA_CORE)/config 
#endif 

#ifndef TENSILICA_BUILDS
#define TENSILICA_BUILDS $(ROOT_XTENSA_PATH_W)/XtDevTools/install/builds/RH-2016.1.2-linux 
#endif 

#ifndef TENSILICA_TOOLS
#define TENSILICA_TOOLS $(ROOT_XTENSA_PATH_W)/XtDevTools/install/tools/RH-2016.1.2-linux 
#endif 

#ifndef TENSILICA_BUILDS_HIFI
#define TENSILICA_BUILDS_HIFI $(ROOT_XTENSA_PATH_W)/XtDevTools/install/builds/RH-2016.1.2-linux 
#endif 

#ifndef TENSILICA_TOOLS_HIFI
#define TENSILICA_TOOLS_HIFI $(ROOT_XTENSA_PATH_W)/XtDevTools/install/tools/RH-2016.1.2-linux 
#endif 

#else
#ifndef XTENSA_CORE
#define XTENSA_CORE Boston_NX_SWUP 
#endif 

#ifndef XTENSA_SYSTEM
#define XTENSA_SYSTEM $(ROOT_XTENSA_PATH_W)/XtDevTools/install/builds/RH-2017.2-linux/$(CFG_XTENSA_CORE)/config 
#endif 

#ifndef TENSILICA_BUILDS
#define TENSILICA_BUILDS $(ROOT_XTENSA_PATH_W)/XtDevTools/install/builds/RH-2017.2-linux 
#endif 

#ifndef TENSILICA_TOOLS
#define TENSILICA_TOOLS $(ROOT_XTENSA_PATH_W)/XtDevTools/install/tools/RH-2017.2-linux 
#endif 

#ifndef TENSILICA_BUILDS_HIFI
#define TENSILICA_BUILDS_HIFI $(ROOT_XTENSA_PATH_W)/XtDevTools/install/builds/RH-2017.2-linux 
#endif 

#ifndef TENSILICA_TOOLS_HIFI
#define TENSILICA_TOOLS_HIFI $(ROOT_XTENSA_PATH_W)/XtDevTools/install/tools/RH-2017.2-linux 
#endif 

#endif
#ifdef LPHY_LATE_MODE 
#ifndef XTENSA_PREDICT_BUG
#endif 

#ifndef XTENSA_INST_PREFETCH_BUG
#define XTENSA_INST_PREFETCH_BUG 
#endif 

#ifndef LPHY_DDR_HAVE_DMSS
#endif 

#ifndef LPHY_DTCM_BASE
#define LPHY_DTCM_BASE 0xE3400000 
#endif 

#ifndef LPHY_ITCM_BASE
#define LPHY_ITCM_BASE 0xE3500000 
#endif 

#ifndef LPHY_DTCM_SIZE
#define LPHY_DTCM_SIZE 0x80000 
#endif 

#ifndef LPHY_ITCM_SIZE
#define LPHY_ITCM_SIZE 0x80000 
#endif 

#ifndef LPHY_L2M_BASE
#define LPHY_L2M_BASE 0xE36C0000 
#endif 

#ifndef LPHY_L2M_SIZE
#define LPHY_L2M_SIZE 0xC0000 
#endif 

#ifndef LPHY_L2C_BASE
#define LPHY_L2C_BASE 0xE3780000 
#endif 

#ifndef LPHY_L2C_SIZE
#define LPHY_L2C_SIZE 0x80000 
#endif 

#else
#ifndef XTENSA_PREDICT_BUG
#endif 

#ifndef XTENSA_INST_PREFETCH_BUG
#define XTENSA_INST_PREFETCH_BUG 
#endif 

#ifndef LPHY_DDR_HAVE_DMSS
#define LPHY_DDR_HAVE_DMSS 
#endif 

#ifndef LPHY_DTCM_BASE
#define LPHY_DTCM_BASE 0xE3400000 
#endif 

#ifndef LPHY_ITCM_BASE
#define LPHY_ITCM_BASE 0xE3500000 
#endif 

#ifndef LPHY_DTCM_SIZE
#define LPHY_DTCM_SIZE 0x80000 
#endif 

#ifndef LPHY_ITCM_SIZE
#define LPHY_ITCM_SIZE 0x80000 
#endif 

#ifndef LPHY_L2M_BASE
#define LPHY_L2M_BASE 0xE36C0000 
#endif 

#ifndef LPHY_L2M_SIZE
#define LPHY_L2M_SIZE 0xC0000 
#endif 

#ifndef LPHY_L2C_BASE
#define LPHY_L2C_BASE 0xE3780000 
#endif 

#ifndef LPHY_L2C_SIZE
#define LPHY_L2C_SIZE 0x80000 
#endif 

#endif
#ifndef LPHY_SRAM_BASE
#define LPHY_SRAM_BASE 0x0 
#endif 

#ifndef LPHY_SRAM_SIZE
#define LPHY_SRAM_SIZE 0x0 
#endif 

#ifndef LPHY_DDR_BASE
#define LPHY_DDR_BASE (DDR_TLPHY_IMAGE_ADDR + 0x1000) 
#endif 

#ifndef LPHY_DDR_BASE
#define LPHY_DDR_BASE $(CFG_DDR_TLPHY_IMAGE_ADDR)+0x1000 
#endif 

#ifndef LPHY_DDR_SIZE
#define LPHY_DDR_SIZE 0x200000 
#endif 

#ifndef LPHY_TOTAL_IMG_SIZE
#define LPHY_TOTAL_IMG_SIZE ((LPHY_DTCM_SIZE)+(LPHY_ITCM_SIZE)+(LPHY_L2M_SIZE)+(LPHY_DDR_SIZE)) 
#endif 

#ifndef TL_PHY_ASIC
#define TL_PHY_ASIC 
#endif 

#ifndef TL_PHY_V760
#define TL_PHY_V760 
#endif 

#ifndef TL_PHY_HI3670
#define TL_PHY_HI3670 
#endif 

#ifndef TL_PHY_BBE16_CACHE
#endif 

#ifndef TL_PHY_SUPPORT_DUAL_MODEM
#define TL_PHY_SUPPORT_DUAL_MODEM 
#endif 

#ifndef TL_PHY_SUPPORT_IMAGE_HEADER
#define TL_PHY_SUPPORT_IMAGE_HEADER 
#endif 

#ifndef FEATURE_LTE_4RX
#define FEATURE_LTE_4RX FEATURE_OFF 
#endif 

#ifndef BBPCONFIG_VERIOSN
#define BBPCONFIG_VERIOSN bbp_config_hi6960 
#endif 

#ifndef TL_PHY_FEATURE_LTE_LCS
#endif 

#ifndef FEATURE_TLPHY_SINGLE_XO
#define FEATURE_TLPHY_SINGLE_XO 
#endif 

#ifndef MULTI_PHY_CO_PROCESSOR
#endif 

#ifndef MULTI_PHY_CO_PROCEDURE
#define MULTI_PHY_CO_PROCEDURE 
#endif 

#ifdef CHIP_TYPE_CS 
#ifndef FEATURE_TLPHY_ET
#define FEATURE_TLPHY_ET FEATURE_ON 
#endif 

#ifndef FEATURE_TLPHY_DPD
#define FEATURE_TLPHY_DPD FEATURE_ON 
#endif 

#else
#ifndef FEATURE_TLPHY_ET
#define FEATURE_TLPHY_ET FEATURE_ON 
#endif 

#ifndef FEATURE_TLPHY_DPD
#define FEATURE_TLPHY_DPD FEATURE_OFF 
#endif 

#endif
#ifndef TL_PHY_FEATURE_SCELL_USE_LISTEN
#define TL_PHY_FEATURE_SCELL_USE_LISTEN 
#endif 

#ifndef TLPHY_DSDS_OPTIMIZE_ENABLE
#define TLPHY_DSDS_OPTIMIZE_ENABLE 
#endif 

#ifndef FEATURE_TLPHY_WTC_SWTICH
#define FEATURE_TLPHY_WTC_SWTICH FEATURE_ON 
#endif 

#endif /*__PRODUCT_CONFIG_H__*/ 

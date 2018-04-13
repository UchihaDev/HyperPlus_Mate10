#ifndef __SOC_ISP_YUVNF_INTERFACE_H__
#define __SOC_ISP_YUVNF_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_YUVNF_YUVNF_CONFIG_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_YUVNF_CROP_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_YUVNF_L0_UV_SA0_CB_THR0_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_YUVNF_L0_UV_SA0_CB_THR1_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_YUVNF_L0_UV_SA0_CR_THR0_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_YUVNF_L0_UV_SA0_CR_THR1_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_YUVNF_L0_UV_SA1_CB_THR0_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_YUVNF_L0_UV_SA1_CB_THR1_ADDR(base) ((base) + (0x001C))
#define SOC_ISP_YUVNF_L0_UV_SA1_CR_THR0_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_YUVNF_L0_UV_SA1_CR_THR1_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_YUVNF_L0_UV_SA2_CB_THR0_ADDR(base) ((base) + (0x0028))
#define SOC_ISP_YUVNF_L0_UV_SA2_CB_THR1_ADDR(base) ((base) + (0x002C))
#define SOC_ISP_YUVNF_L0_UV_SA2_CR_THR0_ADDR(base) ((base) + (0x0030))
#define SOC_ISP_YUVNF_L0_UV_SA2_CR_THR1_ADDR(base) ((base) + (0x0034))
#define SOC_ISP_YUVNF_L0_UV_SA3_CB_THR0_ADDR(base) ((base) + (0x0038))
#define SOC_ISP_YUVNF_L0_UV_SA3_CB_THR1_ADDR(base) ((base) + (0x003C))
#define SOC_ISP_YUVNF_L0_UV_SA3_CR_THR0_ADDR(base) ((base) + (0x0040))
#define SOC_ISP_YUVNF_L0_UV_SA3_CR_THR1_ADDR(base) ((base) + (0x0044))
#define SOC_ISP_YUVNF_L0_UV_SA_NUM_ADDR(base) ((base) + (0x0048))
#define SOC_ISP_YUVNF_L0_UV_MEDIAN_BYPASS_ADDR(base) ((base) + (0x004C))
#define SOC_ISP_YUVNF_L0_UV_EDGE_THR_U_ADDR(base) ((base) + (0x0050))
#define SOC_ISP_YUVNF_L0_UV_EDGE_THR_V_ADDR(base) ((base) + (0x0054))
#define SOC_ISP_YUVNF_L0_UV_MEDIAN_THR0_ADDR(base) ((base) + (0x0058))
#define SOC_ISP_YUVNF_L0_UV_MEDIAN_THR1_ADDR(base) ((base) + (0x005C))
#define SOC_ISP_YUVNF_L0_UV_MED_WB_ADDR(base) ((base) + (0x0060))
#define SOC_ISP_YUVNF_L0_UV_LSC_SCALE_ADDR(base) ((base) + (0x006C))
#define SOC_ISP_YUVNF_L1_UV_SA0_CB_THR0_ADDR(base) ((base) + (0x0070))
#define SOC_ISP_YUVNF_L1_UV_SA0_CB_THR1_ADDR(base) ((base) + (0x0074))
#define SOC_ISP_YUVNF_L1_UV_SA0_CR_THR0_ADDR(base) ((base) + (0x0078))
#define SOC_ISP_YUVNF_L1_UV_SA0_CR_THR1_ADDR(base) ((base) + (0x007C))
#define SOC_ISP_YUVNF_L1_UV_SA1_CB_THR0_ADDR(base) ((base) + (0x0080))
#define SOC_ISP_YUVNF_L1_UV_SA1_CB_THR1_ADDR(base) ((base) + (0x0084))
#define SOC_ISP_YUVNF_L1_UV_SA1_CR_THR0_ADDR(base) ((base) + (0x0088))
#define SOC_ISP_YUVNF_L1_UV_SA1_CR_THR1_ADDR(base) ((base) + (0x008C))
#define SOC_ISP_YUVNF_L1_UV_SA2_CB_THR0_ADDR(base) ((base) + (0x0090))
#define SOC_ISP_YUVNF_L1_UV_SA2_CB_THR1_ADDR(base) ((base) + (0x0094))
#define SOC_ISP_YUVNF_L1_UV_SA2_CR_THR0_ADDR(base) ((base) + (0x0098))
#define SOC_ISP_YUVNF_L1_UV_SA2_CR_THR1_ADDR(base) ((base) + (0x009C))
#define SOC_ISP_YUVNF_L1_UV_SA3_CB_THR0_ADDR(base) ((base) + (0x00A0))
#define SOC_ISP_YUVNF_L1_UV_SA3_CB_THR1_ADDR(base) ((base) + (0x00A4))
#define SOC_ISP_YUVNF_L1_UV_SA3_CR_THR0_ADDR(base) ((base) + (0x00A8))
#define SOC_ISP_YUVNF_L1_UV_SA3_CR_THR1_ADDR(base) ((base) + (0x00AC))
#define SOC_ISP_YUVNF_L1_UV_SA_NUM_ADDR(base) ((base) + (0x00B0))
#define SOC_ISP_YUVNF_L1_UV_MEDIAN_BYPASS_ADDR(base) ((base) + (0x00B4))
#define SOC_ISP_YUVNF_L1_UV_EDGE_THR_U_ADDR(base) ((base) + (0x00B8))
#define SOC_ISP_YUVNF_L1_UV_EDGE_THR_V_ADDR(base) ((base) + (0x00BC))
#define SOC_ISP_YUVNF_L1_UV_MEDIAN_THR0_ADDR(base) ((base) + (0x00C0))
#define SOC_ISP_YUVNF_L1_UV_MEDIAN_THR1_ADDR(base) ((base) + (0x00C4))
#define SOC_ISP_YUVNF_L1_UV_MED_WB_ADDR(base) ((base) + (0x00C8))
#define SOC_ISP_YUVNF_L1_UV_LSC_SCALE_ADDR(base) ((base) + (0x00D4))
#define SOC_ISP_YUVNF_L2_UV_SA0_CB_THR0_ADDR(base) ((base) + (0x00D8))
#define SOC_ISP_YUVNF_L2_UV_SA0_CB_THR1_ADDR(base) ((base) + (0x00DC))
#define SOC_ISP_YUVNF_L2_UV_SA0_CR_THR0_ADDR(base) ((base) + (0x00E0))
#define SOC_ISP_YUVNF_L2_UV_SA0_CR_THR1_ADDR(base) ((base) + (0x00E4))
#define SOC_ISP_YUVNF_L2_UV_SA1_CB_THR0_ADDR(base) ((base) + (0x00E8))
#define SOC_ISP_YUVNF_L2_UV_SA1_CB_THR1_ADDR(base) ((base) + (0x00EC))
#define SOC_ISP_YUVNF_L2_UV_SA1_CR_THR0_ADDR(base) ((base) + (0x00F0))
#define SOC_ISP_YUVNF_L2_UV_SA1_CR_THR1_ADDR(base) ((base) + (0x00F4))
#define SOC_ISP_YUVNF_L2_UV_SA2_CB_THR0_ADDR(base) ((base) + (0x00F8))
#define SOC_ISP_YUVNF_L2_UV_SA2_CB_THR1_ADDR(base) ((base) + (0x00FC))
#define SOC_ISP_YUVNF_L2_UV_SA2_CR_THR0_ADDR(base) ((base) + (0x0100))
#define SOC_ISP_YUVNF_L2_UV_SA2_CR_THR1_ADDR(base) ((base) + (0x0104))
#define SOC_ISP_YUVNF_L2_UV_SA3_CB_THR0_ADDR(base) ((base) + (0x0108))
#define SOC_ISP_YUVNF_L2_UV_SA3_CB_THR1_ADDR(base) ((base) + (0x010C))
#define SOC_ISP_YUVNF_L2_UV_SA3_CR_THR0_ADDR(base) ((base) + (0x0110))
#define SOC_ISP_YUVNF_L2_UV_SA3_CR_THR1_ADDR(base) ((base) + (0x0114))
#define SOC_ISP_YUVNF_L2_UV_SA_NUM_ADDR(base) ((base) + (0x0118))
#define SOC_ISP_YUVNF_L2_UV_MEDIAN_BYPASS_ADDR(base) ((base) + (0x011C))
#define SOC_ISP_YUVNF_L2_UV_EDGE_THR_U_ADDR(base) ((base) + (0x0120))
#define SOC_ISP_YUVNF_L2_UV_EDGE_THR_V_ADDR(base) ((base) + (0x0124))
#define SOC_ISP_YUVNF_L2_UV_MEDIAN_THR0_ADDR(base) ((base) + (0x0128))
#define SOC_ISP_YUVNF_L2_UV_MEDIAN_THR1_ADDR(base) ((base) + (0x012C))
#define SOC_ISP_YUVNF_L2_UV_MED_WB_ADDR(base) ((base) + (0x0130))
#define SOC_ISP_YUVNF_L2_UV_LSC_SCALE_ADDR(base) ((base) + (0x013C))
#define SOC_ISP_YUVNF_L3_UV_LSC_SCALE_ADDR(base) ((base) + (0x0140))
#define SOC_ISP_YUVNF_L4_UV_LSC_SCALE_ADDR(base) ((base) + (0x0144))
#define SOC_ISP_YUVNF_L5_UV_LSC_SCALE_ADDR(base) ((base) + (0x0148))
#define SOC_ISP_YUVNF_L0_U_SOFTTHRW_ADDR(base) ((base) + (0x014C))
#define SOC_ISP_YUVNF_L0_U_SOFTTHR_ADDR(base) ((base) + (0x0150))
#define SOC_ISP_YUVNF_L0_U_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x0154))
#define SOC_ISP_YUVNF_L0_U_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x0158))
#define SOC_ISP_YUVNF_L0_U_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x015C))
#define SOC_ISP_YUVNF_L0_U_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x0160))
#define SOC_ISP_YUVNF_L0_V_SOFTTHRW_ADDR(base) ((base) + (0x0164))
#define SOC_ISP_YUVNF_L0_V_SOFTTHR_ADDR(base) ((base) + (0x0168))
#define SOC_ISP_YUVNF_L0_V_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x016C))
#define SOC_ISP_YUVNF_L0_V_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x0170))
#define SOC_ISP_YUVNF_L0_V_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x0174))
#define SOC_ISP_YUVNF_L0_V_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x0178))
#define SOC_ISP_YUVNF_L1_U_SOFTTHRW_ADDR(base) ((base) + (0x017C))
#define SOC_ISP_YUVNF_L1_U_SOFTTHR_ADDR(base) ((base) + (0x0180))
#define SOC_ISP_YUVNF_L1_U_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x0184))
#define SOC_ISP_YUVNF_L1_U_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x0188))
#define SOC_ISP_YUVNF_L1_U_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x018C))
#define SOC_ISP_YUVNF_L1_U_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x0190))
#define SOC_ISP_YUVNF_L1_V_SOFTTHRW_ADDR(base) ((base) + (0x0194))
#define SOC_ISP_YUVNF_L1_V_SOFTTHR_ADDR(base) ((base) + (0x0198))
#define SOC_ISP_YUVNF_L1_V_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x019C))
#define SOC_ISP_YUVNF_L1_V_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x01A0))
#define SOC_ISP_YUVNF_L1_V_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x01A4))
#define SOC_ISP_YUVNF_L1_V_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x01A8))
#define SOC_ISP_YUVNF_L2_U_SOFTTHRW_ADDR(base) ((base) + (0x01AC))
#define SOC_ISP_YUVNF_L2_U_SOFTTHR_ADDR(base) ((base) + (0x01B0))
#define SOC_ISP_YUVNF_L2_U_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x01B4))
#define SOC_ISP_YUVNF_L2_U_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x01B8))
#define SOC_ISP_YUVNF_L2_U_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x01BC))
#define SOC_ISP_YUVNF_L2_U_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x01C0))
#define SOC_ISP_YUVNF_L2_V_SOFTTHRW_ADDR(base) ((base) + (0x01C4))
#define SOC_ISP_YUVNF_L2_V_SOFTTHR_ADDR(base) ((base) + (0x01C8))
#define SOC_ISP_YUVNF_L2_V_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x01CC))
#define SOC_ISP_YUVNF_L2_V_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x01D0))
#define SOC_ISP_YUVNF_L2_V_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x01D4))
#define SOC_ISP_YUVNF_L2_V_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x01D8))
#define SOC_ISP_YUVNF_L3_U_SOFTTHRW_ADDR(base) ((base) + (0x01DC))
#define SOC_ISP_YUVNF_L3_U_SOFTTHR_ADDR(base) ((base) + (0x01E0))
#define SOC_ISP_YUVNF_L3_U_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x01E4))
#define SOC_ISP_YUVNF_L3_U_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x01E8))
#define SOC_ISP_YUVNF_L3_U_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x01EC))
#define SOC_ISP_YUVNF_L3_U_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x01F0))
#define SOC_ISP_YUVNF_L3_V_SOFTTHRW_ADDR(base) ((base) + (0x01F4))
#define SOC_ISP_YUVNF_L3_V_SOFTTHR_ADDR(base) ((base) + (0x01F8))
#define SOC_ISP_YUVNF_L3_V_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x01FC))
#define SOC_ISP_YUVNF_L3_V_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x0200))
#define SOC_ISP_YUVNF_L3_V_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x0204))
#define SOC_ISP_YUVNF_L3_V_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x0208))
#define SOC_ISP_YUVNF_L4_U_SOFTTHRW_ADDR(base) ((base) + (0x020C))
#define SOC_ISP_YUVNF_L4_U_SOFTTHR_ADDR(base) ((base) + (0x0210))
#define SOC_ISP_YUVNF_L4_U_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x0214))
#define SOC_ISP_YUVNF_L4_U_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x0218))
#define SOC_ISP_YUVNF_L4_U_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x021C))
#define SOC_ISP_YUVNF_L4_U_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x0220))
#define SOC_ISP_YUVNF_L4_V_SOFTTHRW_ADDR(base) ((base) + (0x0224))
#define SOC_ISP_YUVNF_L4_V_SOFTTHR_ADDR(base) ((base) + (0x0228))
#define SOC_ISP_YUVNF_L4_V_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x022C))
#define SOC_ISP_YUVNF_L4_V_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x0230))
#define SOC_ISP_YUVNF_L4_V_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x0234))
#define SOC_ISP_YUVNF_L4_V_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x0238))
#define SOC_ISP_YUVNF_L5_U_SOFTTHRW_ADDR(base) ((base) + (0x023C))
#define SOC_ISP_YUVNF_L5_U_SOFTTHR_ADDR(base) ((base) + (0x0240))
#define SOC_ISP_YUVNF_L5_U_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x0244))
#define SOC_ISP_YUVNF_L5_U_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x0248))
#define SOC_ISP_YUVNF_L5_U_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x024C))
#define SOC_ISP_YUVNF_L5_U_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x0250))
#define SOC_ISP_YUVNF_L5_V_SOFTTHRW_ADDR(base) ((base) + (0x0254))
#define SOC_ISP_YUVNF_L5_V_SOFTTHR_ADDR(base) ((base) + (0x0258))
#define SOC_ISP_YUVNF_L5_V_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x025C))
#define SOC_ISP_YUVNF_L5_V_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x0260))
#define SOC_ISP_YUVNF_L5_V_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x0264))
#define SOC_ISP_YUVNF_L5_V_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x0268))
#define SOC_ISP_YUVNF_LAP_U_SOFTTHRW_ADDR(base) ((base) + (0x026C))
#define SOC_ISP_YUVNF_LAP_U_SOFTTHR_ADDR(base) ((base) + (0x0270))
#define SOC_ISP_YUVNF_LAP_U_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x0274))
#define SOC_ISP_YUVNF_LAP_U_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x0278))
#define SOC_ISP_YUVNF_LAP_U_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x027C))
#define SOC_ISP_YUVNF_LAP_U_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x0280))
#define SOC_ISP_YUVNF_LAP_U_LSC_SCALE_ADDR(base) ((base) + (0x0284))
#define SOC_ISP_YUVNF_LAP_V_SOFTTHRW_ADDR(base) ((base) + (0x0288))
#define SOC_ISP_YUVNF_LAP_V_SOFTTHR_ADDR(base) ((base) + (0x028C))
#define SOC_ISP_YUVNF_LAP_V_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x0290))
#define SOC_ISP_YUVNF_LAP_V_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x0294))
#define SOC_ISP_YUVNF_LAP_V_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x0298))
#define SOC_ISP_YUVNF_LAP_V_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x029C))
#define SOC_ISP_YUVNF_LAP_V_LSC_SCALE_ADDR(base) ((base) + (0x02A0))
#define SOC_ISP_YUVNF_SHIFTN_ADDR(base) ((base) + (0x02A4))
#define SOC_ISP_YUVNF_START_H_ADDR(base) ((base) + (0x02A8))
#define SOC_ISP_YUVNF_START_W_ADDR(base) ((base) + (0x02AC))
#define SOC_ISP_YUVNF_START_X_ADDR(base) ((base) + (0x02B0))
#define SOC_ISP_YUVNF_START_Y_ADDR(base) ((base) + (0x02B4))
#define SOC_ISP_YUVNF_SAD_INFO_ADDR(base) ((base) + (0x0508))
#define SOC_ISP_YUVNF_NOISE_REDUC_STRENGH_ADDR(base) ((base) + (0x050C))
#define SOC_ISP_YUVNF_SHIFT_TEXTRUE_ADDR(base) ((base) + (0x0510))
#define SOC_ISP_YUVNF_RECOVER_STRENGH_PARAM_ADDR(base) ((base) + (0x0514))
#define SOC_ISP_YUVNF_PGAUSSIANLUT_ADDR(base) ((base) + (0x0518))
#define SOC_ISP_YUVNF_BLEND_X_ADDR(base) ((base) + (0x051C))
#define SOC_ISP_YUVNF_BLEND_Y_ADDR(base) ((base) + (0x0520))
#define SOC_ISP_YUVNF_PGAUSSLUT_3_ADDR(base) ((base) + (0x0524))
#define SOC_ISP_YUVNF_PGAUSSLUT_7_ADDR(base) ((base) + (0x0528))
#define SOC_ISP_YUVNF_PGAUSSLUT_9_ADDR(base) ((base) + (0x052C))
#define SOC_ISP_YUVNF_BLENDLOW_ADDR(base) ((base) + (0x0530))
#define SOC_ISP_YUVNF_L012_U_DENLUT_ADDR(base,Range64) ((base) + (0x0600+0x4*(Range64)))
#define SOC_ISP_YUVNF_L012_U_DENREFLUT_ADDR(base,Range64) ((base) + (0x0700+0x4*(Range64)))
#define SOC_ISP_YUVNF_L012_V_DENLUT_ADDR(base,Range64) ((base) + (0x0800+0x4*(Range64)))
#define SOC_ISP_YUVNF_L012_V_DENREFLUT_ADDR(base,Range64) ((base) + (0x0900+0x4*(Range64)))
#define SOC_ISP_YUVNF_L345_U_DENLUT_ADDR(base,Range64) ((base) + (0x0A00+0x4*(Range64)))
#define SOC_ISP_YUVNF_L345_U_DENREFLUT_ADDR(base,Range64) ((base) + (0x0B00+0x4*(Range64)))
#define SOC_ISP_YUVNF_L345_V_DENLUT_ADDR(base,Range64) ((base) + (0x0C00+0x4*(Range64)))
#define SOC_ISP_YUVNF_L345_V_DENREFLUT_ADDR(base,Range64) ((base) + (0x0D00+0x4*(Range64)))
#define SOC_ISP_YUVNF_L0123_U_GAULUT_ADDR(base,Range2) ((base) + (0x0E00+0x4*(Range2)))
#define SOC_ISP_YUVNF_L0123_V_GAULUT_ADDR(base,Range2) ((base) + (0x0E08+0x4*(Range2)))
#define SOC_ISP_YUVNF_L45_U_GAULUT5_ADDR(base,Range5) ((base) + (0x0E10+0x4*(Range5)))
#define SOC_ISP_YUVNF_L45_V_GAULUT5_ADDR(base,Range5) ((base) + (0x0E30+0x4*(Range5)))
#define SOC_ISP_YUVNF_GAINLSC_ADDR(base,Range53) ((base) + (0x0E50+0x4*(Range53)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int full_bypass : 1;
        unsigned int off_line_bypass : 1;
        unsigned int lap_layer_uv_bypass : 1;
        unsigned int force_clk_on : 1;
        unsigned int uv_enable : 1;
        unsigned int reserved_0 : 3;
        unsigned int l0_uv_bypass : 1;
        unsigned int l1_uv_bypass : 1;
        unsigned int l2_uv_bypass : 1;
        unsigned int l3_uv_bypass : 1;
        unsigned int l4_uv_bypass : 1;
        unsigned int l5_uv_bypass : 1;
        unsigned int y_bypass : 1;
        unsigned int mult_gauss_en : 1;
        unsigned int bypass_symfilter : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_ISP_YUVNF_YUVNF_CONFIG_UNION;
#endif
#define SOC_ISP_YUVNF_YUVNF_CONFIG_full_bypass_START (0)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_full_bypass_END (0)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_off_line_bypass_START (1)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_off_line_bypass_END (1)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_lap_layer_uv_bypass_START (2)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_lap_layer_uv_bypass_END (2)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_force_clk_on_START (3)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_force_clk_on_END (3)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_uv_enable_START (4)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_uv_enable_END (4)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_l0_uv_bypass_START (8)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_l0_uv_bypass_END (8)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_l1_uv_bypass_START (9)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_l1_uv_bypass_END (9)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_l2_uv_bypass_START (10)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_l2_uv_bypass_END (10)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_l3_uv_bypass_START (11)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_l3_uv_bypass_END (11)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_l4_uv_bypass_START (12)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_l4_uv_bypass_END (12)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_l5_uv_bypass_START (13)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_l5_uv_bypass_END (13)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_y_bypass_START (14)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_y_bypass_END (14)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_mult_gauss_en_START (15)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_mult_gauss_en_END (15)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_bypass_symfilter_START (16)
#define SOC_ISP_YUVNF_YUVNF_CONFIG_bypass_symfilter_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihright : 10;
        unsigned int reserved_0: 6;
        unsigned int ivbottom : 13;
        unsigned int reserved_1: 3;
    } reg;
} SOC_ISP_YUVNF_CROP_UNION;
#endif
#define SOC_ISP_YUVNF_CROP_ihright_START (0)
#define SOC_ISP_YUVNF_CROP_ihright_END (9)
#define SOC_ISP_YUVNF_CROP_ivbottom_START (16)
#define SOC_ISP_YUVNF_CROP_ivbottom_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa0_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA0_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA0_CB_THR0_l0_uv_sa0_cb_thr0_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA0_CB_THR0_l0_uv_sa0_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa0_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA0_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA0_CB_THR1_l0_uv_sa0_cb_thr1_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA0_CB_THR1_l0_uv_sa0_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa0_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA0_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA0_CR_THR0_l0_uv_sa0_cr_thr0_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA0_CR_THR0_l0_uv_sa0_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa0_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA0_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA0_CR_THR1_l0_uv_sa0_cr_thr1_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA0_CR_THR1_l0_uv_sa0_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa1_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA1_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA1_CB_THR0_l0_uv_sa1_cb_thr0_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA1_CB_THR0_l0_uv_sa1_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa1_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA1_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA1_CB_THR1_l0_uv_sa1_cb_thr1_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA1_CB_THR1_l0_uv_sa1_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa1_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA1_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA1_CR_THR0_l0_uv_sa1_cr_thr0_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA1_CR_THR0_l0_uv_sa1_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa1_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA1_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA1_CR_THR1_l0_uv_sa1_cr_thr1_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA1_CR_THR1_l0_uv_sa1_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa2_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA2_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA2_CB_THR0_l0_uv_sa2_cb_thr0_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA2_CB_THR0_l0_uv_sa2_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa2_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA2_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA2_CB_THR1_l0_uv_sa2_cb_thr1_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA2_CB_THR1_l0_uv_sa2_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa2_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA2_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA2_CR_THR0_l0_uv_sa2_cr_thr0_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA2_CR_THR0_l0_uv_sa2_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa2_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA2_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA2_CR_THR1_l0_uv_sa2_cr_thr1_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA2_CR_THR1_l0_uv_sa2_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa3_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA3_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA3_CB_THR0_l0_uv_sa3_cb_thr0_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA3_CB_THR0_l0_uv_sa3_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa3_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA3_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA3_CB_THR1_l0_uv_sa3_cb_thr1_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA3_CB_THR1_l0_uv_sa3_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa3_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA3_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA3_CR_THR0_l0_uv_sa3_cr_thr0_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA3_CR_THR0_l0_uv_sa3_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa3_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA3_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA3_CR_THR1_l0_uv_sa3_cr_thr1_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA3_CR_THR1_l0_uv_sa3_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_sa_num : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_YUVNF_L0_UV_SA_NUM_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_SA_NUM_l0_uv_sa_num_START (0)
#define SOC_ISP_YUVNF_L0_UV_SA_NUM_l0_uv_sa_num_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_median_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_YUVNF_L0_UV_MEDIAN_BYPASS_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_MEDIAN_BYPASS_l0_uv_median_bypass_START (0)
#define SOC_ISP_YUVNF_L0_UV_MEDIAN_BYPASS_l0_uv_median_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_edge_thr_u : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_YUVNF_L0_UV_EDGE_THR_U_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_EDGE_THR_U_l0_uv_edge_thr_u_START (0)
#define SOC_ISP_YUVNF_L0_UV_EDGE_THR_U_l0_uv_edge_thr_u_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_edge_thr_v : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_YUVNF_L0_UV_EDGE_THR_V_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_EDGE_THR_V_l0_uv_edge_thr_v_START (0)
#define SOC_ISP_YUVNF_L0_UV_EDGE_THR_V_l0_uv_edge_thr_v_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_median_thr0 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_YUVNF_L0_UV_MEDIAN_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_MEDIAN_THR0_l0_uv_median_thr0_START (0)
#define SOC_ISP_YUVNF_L0_UV_MEDIAN_THR0_l0_uv_median_thr0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_median_thr1 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_YUVNF_L0_UV_MEDIAN_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_MEDIAN_THR1_l0_uv_median_thr1_START (0)
#define SOC_ISP_YUVNF_L0_UV_MEDIAN_THR1_l0_uv_median_thr1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_med_wb : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_YUVNF_L0_UV_MED_WB_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_MED_WB_l0_uv_med_wb_START (0)
#define SOC_ISP_YUVNF_L0_UV_MED_WB_l0_uv_med_wb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_uv_lsc_scale : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_L0_UV_LSC_SCALE_UNION;
#endif
#define SOC_ISP_YUVNF_L0_UV_LSC_SCALE_l0_uv_lsc_scale_START (0)
#define SOC_ISP_YUVNF_L0_UV_LSC_SCALE_l0_uv_lsc_scale_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa0_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA0_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA0_CB_THR0_l1_uv_sa0_cb_thr0_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA0_CB_THR0_l1_uv_sa0_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa0_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA0_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA0_CB_THR1_l1_uv_sa0_cb_thr1_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA0_CB_THR1_l1_uv_sa0_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa0_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA0_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA0_CR_THR0_l1_uv_sa0_cr_thr0_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA0_CR_THR0_l1_uv_sa0_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa0_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA0_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA0_CR_THR1_l1_uv_sa0_cr_thr1_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA0_CR_THR1_l1_uv_sa0_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa1_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA1_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA1_CB_THR0_l1_uv_sa1_cb_thr0_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA1_CB_THR0_l1_uv_sa1_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa1_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA1_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA1_CB_THR1_l1_uv_sa1_cb_thr1_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA1_CB_THR1_l1_uv_sa1_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa1_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA1_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA1_CR_THR0_l1_uv_sa1_cr_thr0_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA1_CR_THR0_l1_uv_sa1_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa1_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA1_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA1_CR_THR1_l1_uv_sa1_cr_thr1_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA1_CR_THR1_l1_uv_sa1_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa2_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA2_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA2_CB_THR0_l1_uv_sa2_cb_thr0_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA2_CB_THR0_l1_uv_sa2_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa2_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA2_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA2_CB_THR1_l1_uv_sa2_cb_thr1_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA2_CB_THR1_l1_uv_sa2_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa2_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA2_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA2_CR_THR0_l1_uv_sa2_cr_thr0_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA2_CR_THR0_l1_uv_sa2_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa2_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA2_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA2_CR_THR1_l1_uv_sa2_cr_thr1_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA2_CR_THR1_l1_uv_sa2_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa3_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA3_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA3_CB_THR0_l1_uv_sa3_cb_thr0_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA3_CB_THR0_l1_uv_sa3_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa3_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA3_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA3_CB_THR1_l1_uv_sa3_cb_thr1_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA3_CB_THR1_l1_uv_sa3_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa3_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA3_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA3_CR_THR0_l1_uv_sa3_cr_thr0_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA3_CR_THR0_l1_uv_sa3_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa3_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA3_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA3_CR_THR1_l1_uv_sa3_cr_thr1_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA3_CR_THR1_l1_uv_sa3_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_sa_num : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_YUVNF_L1_UV_SA_NUM_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_SA_NUM_l1_uv_sa_num_START (0)
#define SOC_ISP_YUVNF_L1_UV_SA_NUM_l1_uv_sa_num_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_median_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_YUVNF_L1_UV_MEDIAN_BYPASS_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_MEDIAN_BYPASS_l1_uv_median_bypass_START (0)
#define SOC_ISP_YUVNF_L1_UV_MEDIAN_BYPASS_l1_uv_median_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_edge_thr_u : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_YUVNF_L1_UV_EDGE_THR_U_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_EDGE_THR_U_l1_uv_edge_thr_u_START (0)
#define SOC_ISP_YUVNF_L1_UV_EDGE_THR_U_l1_uv_edge_thr_u_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_edge_thr_v : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_YUVNF_L1_UV_EDGE_THR_V_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_EDGE_THR_V_l1_uv_edge_thr_v_START (0)
#define SOC_ISP_YUVNF_L1_UV_EDGE_THR_V_l1_uv_edge_thr_v_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_median_thr0 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_YUVNF_L1_UV_MEDIAN_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_MEDIAN_THR0_l1_uv_median_thr0_START (0)
#define SOC_ISP_YUVNF_L1_UV_MEDIAN_THR0_l1_uv_median_thr0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_median_thr1 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_YUVNF_L1_UV_MEDIAN_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_MEDIAN_THR1_l1_uv_median_thr1_START (0)
#define SOC_ISP_YUVNF_L1_UV_MEDIAN_THR1_l1_uv_median_thr1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_med_wb : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_YUVNF_L1_UV_MED_WB_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_MED_WB_l1_uv_med_wb_START (0)
#define SOC_ISP_YUVNF_L1_UV_MED_WB_l1_uv_med_wb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_uv_lsc_scale : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_L1_UV_LSC_SCALE_UNION;
#endif
#define SOC_ISP_YUVNF_L1_UV_LSC_SCALE_l1_uv_lsc_scale_START (0)
#define SOC_ISP_YUVNF_L1_UV_LSC_SCALE_l1_uv_lsc_scale_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa0_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA0_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA0_CB_THR0_l2_uv_sa0_cb_thr0_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA0_CB_THR0_l2_uv_sa0_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa0_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA0_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA0_CB_THR1_l2_uv_sa0_cb_thr1_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA0_CB_THR1_l2_uv_sa0_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa0_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA0_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA0_CR_THR0_l2_uv_sa0_cr_thr0_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA0_CR_THR0_l2_uv_sa0_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa0_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA0_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA0_CR_THR1_l2_uv_sa0_cr_thr1_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA0_CR_THR1_l2_uv_sa0_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa1_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA1_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA1_CB_THR0_l2_uv_sa1_cb_thr0_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA1_CB_THR0_l2_uv_sa1_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa1_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA1_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA1_CB_THR1_l2_uv_sa1_cb_thr1_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA1_CB_THR1_l2_uv_sa1_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa1_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA1_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA1_CR_THR0_l2_uv_sa1_cr_thr0_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA1_CR_THR0_l2_uv_sa1_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa1_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA1_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA1_CR_THR1_l2_uv_sa1_cr_thr1_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA1_CR_THR1_l2_uv_sa1_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa2_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA2_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA2_CB_THR0_l2_uv_sa2_cb_thr0_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA2_CB_THR0_l2_uv_sa2_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa2_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA2_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA2_CB_THR1_l2_uv_sa2_cb_thr1_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA2_CB_THR1_l2_uv_sa2_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa2_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA2_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA2_CR_THR0_l2_uv_sa2_cr_thr0_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA2_CR_THR0_l2_uv_sa2_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa2_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA2_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA2_CR_THR1_l2_uv_sa2_cr_thr1_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA2_CR_THR1_l2_uv_sa2_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa3_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA3_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA3_CB_THR0_l2_uv_sa3_cb_thr0_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA3_CB_THR0_l2_uv_sa3_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa3_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA3_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA3_CB_THR1_l2_uv_sa3_cb_thr1_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA3_CB_THR1_l2_uv_sa3_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa3_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA3_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA3_CR_THR0_l2_uv_sa3_cr_thr0_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA3_CR_THR0_l2_uv_sa3_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa3_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA3_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA3_CR_THR1_l2_uv_sa3_cr_thr1_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA3_CR_THR1_l2_uv_sa3_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_sa_num : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_YUVNF_L2_UV_SA_NUM_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_SA_NUM_l2_uv_sa_num_START (0)
#define SOC_ISP_YUVNF_L2_UV_SA_NUM_l2_uv_sa_num_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_median_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_YUVNF_L2_UV_MEDIAN_BYPASS_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_MEDIAN_BYPASS_l2_uv_median_bypass_START (0)
#define SOC_ISP_YUVNF_L2_UV_MEDIAN_BYPASS_l2_uv_median_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_edge_thr_u : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_YUVNF_L2_UV_EDGE_THR_U_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_EDGE_THR_U_l2_uv_edge_thr_u_START (0)
#define SOC_ISP_YUVNF_L2_UV_EDGE_THR_U_l2_uv_edge_thr_u_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_edge_thr_v : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_YUVNF_L2_UV_EDGE_THR_V_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_EDGE_THR_V_l2_uv_edge_thr_v_START (0)
#define SOC_ISP_YUVNF_L2_UV_EDGE_THR_V_l2_uv_edge_thr_v_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_median_thr0 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_YUVNF_L2_UV_MEDIAN_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_MEDIAN_THR0_l2_uv_median_thr0_START (0)
#define SOC_ISP_YUVNF_L2_UV_MEDIAN_THR0_l2_uv_median_thr0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_median_thr1 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_ISP_YUVNF_L2_UV_MEDIAN_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_MEDIAN_THR1_l2_uv_median_thr1_START (0)
#define SOC_ISP_YUVNF_L2_UV_MEDIAN_THR1_l2_uv_median_thr1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_med_wb : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_YUVNF_L2_UV_MED_WB_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_MED_WB_l2_uv_med_wb_START (0)
#define SOC_ISP_YUVNF_L2_UV_MED_WB_l2_uv_med_wb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_uv_lsc_scale : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_L2_UV_LSC_SCALE_UNION;
#endif
#define SOC_ISP_YUVNF_L2_UV_LSC_SCALE_l2_uv_lsc_scale_START (0)
#define SOC_ISP_YUVNF_L2_UV_LSC_SCALE_l2_uv_lsc_scale_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_uv_lsc_scale : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_L3_UV_LSC_SCALE_UNION;
#endif
#define SOC_ISP_YUVNF_L3_UV_LSC_SCALE_l3_uv_lsc_scale_START (0)
#define SOC_ISP_YUVNF_L3_UV_LSC_SCALE_l3_uv_lsc_scale_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_uv_lsc_scale : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_L4_UV_LSC_SCALE_UNION;
#endif
#define SOC_ISP_YUVNF_L4_UV_LSC_SCALE_l4_uv_lsc_scale_START (0)
#define SOC_ISP_YUVNF_L4_UV_LSC_SCALE_l4_uv_lsc_scale_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_uv_lsc_scale : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_L5_UV_LSC_SCALE_UNION;
#endif
#define SOC_ISP_YUVNF_L5_UV_LSC_SCALE_l5_uv_lsc_scale_START (0)
#define SOC_ISP_YUVNF_L5_UV_LSC_SCALE_l5_uv_lsc_scale_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_u_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_U_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_L0_U_SOFTTHRW_l0_u_softthrw_START (0)
#define SOC_ISP_YUVNF_L0_U_SOFTTHRW_l0_u_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_u_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L0_U_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_L0_U_SOFTTHR_l0_u_softthr_START (0)
#define SOC_ISP_YUVNF_L0_U_SOFTTHR_l0_u_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_u_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L0_U_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L0_U_SA0_NR_STRENGTH_l0_u_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_L0_U_SA0_NR_STRENGTH_l0_u_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_u_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L0_U_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L0_U_SA1_NR_STRENGTH_l0_u_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_L0_U_SA1_NR_STRENGTH_l0_u_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_u_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L0_U_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L0_U_SA2_NR_STRENGTH_l0_u_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_L0_U_SA2_NR_STRENGTH_l0_u_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_u_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L0_U_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L0_U_SA3_NR_STRENGTH_l0_u_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_L0_U_SA3_NR_STRENGTH_l0_u_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_v_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L0_V_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_L0_V_SOFTTHRW_l0_v_softthrw_START (0)
#define SOC_ISP_YUVNF_L0_V_SOFTTHRW_l0_v_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_v_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L0_V_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_L0_V_SOFTTHR_l0_v_softthr_START (0)
#define SOC_ISP_YUVNF_L0_V_SOFTTHR_l0_v_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_v_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L0_V_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L0_V_SA0_NR_STRENGTH_l0_v_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_L0_V_SA0_NR_STRENGTH_l0_v_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_v_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L0_V_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L0_V_SA1_NR_STRENGTH_l0_v_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_L0_V_SA1_NR_STRENGTH_l0_v_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_v_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L0_V_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L0_V_SA2_NR_STRENGTH_l0_v_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_L0_V_SA2_NR_STRENGTH_l0_v_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_v_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L0_V_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L0_V_SA3_NR_STRENGTH_l0_v_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_L0_V_SA3_NR_STRENGTH_l0_v_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_u_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_U_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_L1_U_SOFTTHRW_l1_u_softthrw_START (0)
#define SOC_ISP_YUVNF_L1_U_SOFTTHRW_l1_u_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_u_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L1_U_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_L1_U_SOFTTHR_l1_u_softthr_START (0)
#define SOC_ISP_YUVNF_L1_U_SOFTTHR_l1_u_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_u_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L1_U_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L1_U_SA0_NR_STRENGTH_l1_u_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_L1_U_SA0_NR_STRENGTH_l1_u_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_u_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L1_U_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L1_U_SA1_NR_STRENGTH_l1_u_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_L1_U_SA1_NR_STRENGTH_l1_u_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_u_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L1_U_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L1_U_SA2_NR_STRENGTH_l1_u_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_L1_U_SA2_NR_STRENGTH_l1_u_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_u_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L1_U_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L1_U_SA3_NR_STRENGTH_l1_u_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_L1_U_SA3_NR_STRENGTH_l1_u_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_v_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L1_V_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_L1_V_SOFTTHRW_l1_v_softthrw_START (0)
#define SOC_ISP_YUVNF_L1_V_SOFTTHRW_l1_v_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_v_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L1_V_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_L1_V_SOFTTHR_l1_v_softthr_START (0)
#define SOC_ISP_YUVNF_L1_V_SOFTTHR_l1_v_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_v_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L1_V_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L1_V_SA0_NR_STRENGTH_l1_v_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_L1_V_SA0_NR_STRENGTH_l1_v_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_v_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L1_V_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L1_V_SA1_NR_STRENGTH_l1_v_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_L1_V_SA1_NR_STRENGTH_l1_v_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_v_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L1_V_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L1_V_SA2_NR_STRENGTH_l1_v_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_L1_V_SA2_NR_STRENGTH_l1_v_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l1_v_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L1_V_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L1_V_SA3_NR_STRENGTH_l1_v_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_L1_V_SA3_NR_STRENGTH_l1_v_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_u_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_U_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_L2_U_SOFTTHRW_l2_u_softthrw_START (0)
#define SOC_ISP_YUVNF_L2_U_SOFTTHRW_l2_u_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_u_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L2_U_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_L2_U_SOFTTHR_l2_u_softthr_START (0)
#define SOC_ISP_YUVNF_L2_U_SOFTTHR_l2_u_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_u_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L2_U_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L2_U_SA0_NR_STRENGTH_l2_u_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_L2_U_SA0_NR_STRENGTH_l2_u_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_u_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L2_U_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L2_U_SA1_NR_STRENGTH_l2_u_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_L2_U_SA1_NR_STRENGTH_l2_u_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_u_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L2_U_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L2_U_SA2_NR_STRENGTH_l2_u_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_L2_U_SA2_NR_STRENGTH_l2_u_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_u_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L2_U_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L2_U_SA3_NR_STRENGTH_l2_u_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_L2_U_SA3_NR_STRENGTH_l2_u_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_v_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L2_V_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_L2_V_SOFTTHRW_l2_v_softthrw_START (0)
#define SOC_ISP_YUVNF_L2_V_SOFTTHRW_l2_v_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_v_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L2_V_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_L2_V_SOFTTHR_l2_v_softthr_START (0)
#define SOC_ISP_YUVNF_L2_V_SOFTTHR_l2_v_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_v_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L2_V_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L2_V_SA0_NR_STRENGTH_l2_v_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_L2_V_SA0_NR_STRENGTH_l2_v_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_v_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L2_V_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L2_V_SA1_NR_STRENGTH_l2_v_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_L2_V_SA1_NR_STRENGTH_l2_v_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_v_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L2_V_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L2_V_SA2_NR_STRENGTH_l2_v_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_L2_V_SA2_NR_STRENGTH_l2_v_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_v_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L2_V_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L2_V_SA3_NR_STRENGTH_l2_v_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_L2_V_SA3_NR_STRENGTH_l2_v_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_u_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L3_U_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_L3_U_SOFTTHRW_l3_u_softthrw_START (0)
#define SOC_ISP_YUVNF_L3_U_SOFTTHRW_l3_u_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_u_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L3_U_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_L3_U_SOFTTHR_l3_u_softthr_START (0)
#define SOC_ISP_YUVNF_L3_U_SOFTTHR_l3_u_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_u_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L3_U_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L3_U_SA0_NR_STRENGTH_l3_u_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_L3_U_SA0_NR_STRENGTH_l3_u_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_u_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L3_U_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L3_U_SA1_NR_STRENGTH_l3_u_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_L3_U_SA1_NR_STRENGTH_l3_u_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_u_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L3_U_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L3_U_SA2_NR_STRENGTH_l3_u_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_L3_U_SA2_NR_STRENGTH_l3_u_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_u_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L3_U_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L3_U_SA3_NR_STRENGTH_l3_u_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_L3_U_SA3_NR_STRENGTH_l3_u_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_v_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L3_V_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_L3_V_SOFTTHRW_l3_v_softthrw_START (0)
#define SOC_ISP_YUVNF_L3_V_SOFTTHRW_l3_v_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_v_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L3_V_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_L3_V_SOFTTHR_l3_v_softthr_START (0)
#define SOC_ISP_YUVNF_L3_V_SOFTTHR_l3_v_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_v_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L3_V_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L3_V_SA0_NR_STRENGTH_l3_v_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_L3_V_SA0_NR_STRENGTH_l3_v_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_v_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L3_V_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L3_V_SA1_NR_STRENGTH_l3_v_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_L3_V_SA1_NR_STRENGTH_l3_v_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_v_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L3_V_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L3_V_SA2_NR_STRENGTH_l3_v_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_L3_V_SA2_NR_STRENGTH_l3_v_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_v_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L3_V_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L3_V_SA3_NR_STRENGTH_l3_v_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_L3_V_SA3_NR_STRENGTH_l3_v_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_u_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L4_U_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_L4_U_SOFTTHRW_l4_u_softthrw_START (0)
#define SOC_ISP_YUVNF_L4_U_SOFTTHRW_l4_u_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_u_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L4_U_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_L4_U_SOFTTHR_l4_u_softthr_START (0)
#define SOC_ISP_YUVNF_L4_U_SOFTTHR_l4_u_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_u_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L4_U_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L4_U_SA0_NR_STRENGTH_l4_u_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_L4_U_SA0_NR_STRENGTH_l4_u_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_u_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L4_U_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L4_U_SA1_NR_STRENGTH_l4_u_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_L4_U_SA1_NR_STRENGTH_l4_u_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_u_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L4_U_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L4_U_SA2_NR_STRENGTH_l4_u_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_L4_U_SA2_NR_STRENGTH_l4_u_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_u_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L4_U_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L4_U_SA3_NR_STRENGTH_l4_u_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_L4_U_SA3_NR_STRENGTH_l4_u_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_v_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L4_V_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_L4_V_SOFTTHRW_l4_v_softthrw_START (0)
#define SOC_ISP_YUVNF_L4_V_SOFTTHRW_l4_v_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_v_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L4_V_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_L4_V_SOFTTHR_l4_v_softthr_START (0)
#define SOC_ISP_YUVNF_L4_V_SOFTTHR_l4_v_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_v_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L4_V_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L4_V_SA0_NR_STRENGTH_l4_v_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_L4_V_SA0_NR_STRENGTH_l4_v_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_v_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L4_V_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L4_V_SA1_NR_STRENGTH_l4_v_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_L4_V_SA1_NR_STRENGTH_l4_v_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_v_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L4_V_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L4_V_SA2_NR_STRENGTH_l4_v_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_L4_V_SA2_NR_STRENGTH_l4_v_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_v_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L4_V_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L4_V_SA3_NR_STRENGTH_l4_v_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_L4_V_SA3_NR_STRENGTH_l4_v_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_u_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L5_U_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_L5_U_SOFTTHRW_l5_u_softthrw_START (0)
#define SOC_ISP_YUVNF_L5_U_SOFTTHRW_l5_u_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_u_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L5_U_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_L5_U_SOFTTHR_l5_u_softthr_START (0)
#define SOC_ISP_YUVNF_L5_U_SOFTTHR_l5_u_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_u_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L5_U_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L5_U_SA0_NR_STRENGTH_l5_u_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_L5_U_SA0_NR_STRENGTH_l5_u_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_u_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L5_U_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L5_U_SA1_NR_STRENGTH_l5_u_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_L5_U_SA1_NR_STRENGTH_l5_u_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_u_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L5_U_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L5_U_SA2_NR_STRENGTH_l5_u_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_L5_U_SA2_NR_STRENGTH_l5_u_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_u_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L5_U_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L5_U_SA3_NR_STRENGTH_l5_u_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_L5_U_SA3_NR_STRENGTH_l5_u_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_v_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_L5_V_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_L5_V_SOFTTHRW_l5_v_softthrw_START (0)
#define SOC_ISP_YUVNF_L5_V_SOFTTHRW_l5_v_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_v_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L5_V_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_L5_V_SOFTTHR_l5_v_softthr_START (0)
#define SOC_ISP_YUVNF_L5_V_SOFTTHR_l5_v_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_v_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L5_V_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L5_V_SA0_NR_STRENGTH_l5_v_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_L5_V_SA0_NR_STRENGTH_l5_v_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_v_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L5_V_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L5_V_SA1_NR_STRENGTH_l5_v_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_L5_V_SA1_NR_STRENGTH_l5_v_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_v_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L5_V_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L5_V_SA2_NR_STRENGTH_l5_v_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_L5_V_SA2_NR_STRENGTH_l5_v_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l5_v_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_L5_V_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_L5_V_SA3_NR_STRENGTH_l5_v_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_L5_V_SA3_NR_STRENGTH_l5_v_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_u_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_LAP_U_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_U_SOFTTHRW_lap_u_softthrw_START (0)
#define SOC_ISP_YUVNF_LAP_U_SOFTTHRW_lap_u_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_u_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_LAP_U_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_U_SOFTTHR_lap_u_softthr_START (0)
#define SOC_ISP_YUVNF_LAP_U_SOFTTHR_lap_u_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_u_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_LAP_U_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_U_SA0_NR_STRENGTH_lap_u_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_LAP_U_SA0_NR_STRENGTH_lap_u_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_u_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_LAP_U_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_U_SA1_NR_STRENGTH_lap_u_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_LAP_U_SA1_NR_STRENGTH_lap_u_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_u_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_LAP_U_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_U_SA2_NR_STRENGTH_lap_u_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_LAP_U_SA2_NR_STRENGTH_lap_u_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_u_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_LAP_U_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_U_SA3_NR_STRENGTH_lap_u_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_LAP_U_SA3_NR_STRENGTH_lap_u_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_u_lsc_scale : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_LAP_U_LSC_SCALE_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_U_LSC_SCALE_lap_u_lsc_scale_START (0)
#define SOC_ISP_YUVNF_LAP_U_LSC_SCALE_lap_u_lsc_scale_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_v_softthrw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_LAP_V_SOFTTHRW_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_V_SOFTTHRW_lap_v_softthrw_START (0)
#define SOC_ISP_YUVNF_LAP_V_SOFTTHRW_lap_v_softthrw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_v_softthr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_LAP_V_SOFTTHR_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_V_SOFTTHR_lap_v_softthr_START (0)
#define SOC_ISP_YUVNF_LAP_V_SOFTTHR_lap_v_softthr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_v_sa0_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_LAP_V_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_V_SA0_NR_STRENGTH_lap_v_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_LAP_V_SA0_NR_STRENGTH_lap_v_sa0_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_v_sa1_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_LAP_V_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_V_SA1_NR_STRENGTH_lap_v_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_LAP_V_SA1_NR_STRENGTH_lap_v_sa1_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_v_sa2_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_LAP_V_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_V_SA2_NR_STRENGTH_lap_v_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_LAP_V_SA2_NR_STRENGTH_lap_v_sa2_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_v_sa3_nr_strength : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_LAP_V_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_V_SA3_NR_STRENGTH_lap_v_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_LAP_V_SA3_NR_STRENGTH_lap_v_sa3_nr_strength_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lap_v_lsc_scale : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_LAP_V_LSC_SCALE_UNION;
#endif
#define SOC_ISP_YUVNF_LAP_V_LSC_SCALE_lap_v_lsc_scale_START (0)
#define SOC_ISP_YUVNF_LAP_V_LSC_SCALE_lap_v_lsc_scale_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shiftn : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_SHIFTN_UNION;
#endif
#define SOC_ISP_YUVNF_SHIFTN_shiftn_START (0)
#define SOC_ISP_YUVNF_SHIFTN_shiftn_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int starth : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_YUVNF_START_H_UNION;
#endif
#define SOC_ISP_YUVNF_START_H_starth_START (0)
#define SOC_ISP_YUVNF_START_H_starth_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int startw : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_YUVNF_START_W_UNION;
#endif
#define SOC_ISP_YUVNF_START_W_startw_START (0)
#define SOC_ISP_YUVNF_START_W_startw_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int startx : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_YUVNF_START_X_UNION;
#endif
#define SOC_ISP_YUVNF_START_X_startx_START (0)
#define SOC_ISP_YUVNF_START_X_startx_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int starty : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_YUVNF_START_Y_UNION;
#endif
#define SOC_ISP_YUVNF_START_Y_starty_START (0)
#define SOC_ISP_YUVNF_START_Y_starty_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int off_sad : 8;
        unsigned int shift_sad : 2;
        unsigned int reserved_0: 6;
        unsigned int inv_sad : 11;
        unsigned int reserved_1: 5;
    } reg;
} SOC_ISP_YUVNF_SAD_INFO_UNION;
#endif
#define SOC_ISP_YUVNF_SAD_INFO_off_sad_START (0)
#define SOC_ISP_YUVNF_SAD_INFO_off_sad_END (7)
#define SOC_ISP_YUVNF_SAD_INFO_shift_sad_START (8)
#define SOC_ISP_YUVNF_SAD_INFO_shift_sad_END (9)
#define SOC_ISP_YUVNF_SAD_INFO_inv_sad_START (16)
#define SOC_ISP_YUVNF_SAD_INFO_inv_sad_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edgeth : 8;
        unsigned int edgemaxoff : 6;
        unsigned int reserved_0 : 2;
        unsigned int gainmaxoff : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_YUVNF_NOISE_REDUC_STRENGH_UNION;
#endif
#define SOC_ISP_YUVNF_NOISE_REDUC_STRENGH_edgeth_START (0)
#define SOC_ISP_YUVNF_NOISE_REDUC_STRENGH_edgeth_END (7)
#define SOC_ISP_YUVNF_NOISE_REDUC_STRENGH_edgemaxoff_START (8)
#define SOC_ISP_YUVNF_NOISE_REDUC_STRENGH_edgemaxoff_END (13)
#define SOC_ISP_YUVNF_NOISE_REDUC_STRENGH_gainmaxoff_START (16)
#define SOC_ISP_YUVNF_NOISE_REDUC_STRENGH_gainmaxoff_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shift_textrue : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_SHIFT_TEXTRUE_UNION;
#endif
#define SOC_ISP_YUVNF_SHIFT_TEXTRUE_shift_textrue_START (0)
#define SOC_ISP_YUVNF_SHIFT_TEXTRUE_shift_textrue_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noeblendlow : 8;
        unsigned int edgeblendlow : 8;
        unsigned int noisescale : 7;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_YUVNF_RECOVER_STRENGH_PARAM_UNION;
#endif
#define SOC_ISP_YUVNF_RECOVER_STRENGH_PARAM_noeblendlow_START (0)
#define SOC_ISP_YUVNF_RECOVER_STRENGH_PARAM_noeblendlow_END (7)
#define SOC_ISP_YUVNF_RECOVER_STRENGH_PARAM_edgeblendlow_START (8)
#define SOC_ISP_YUVNF_RECOVER_STRENGH_PARAM_edgeblendlow_END (15)
#define SOC_ISP_YUVNF_RECOVER_STRENGH_PARAM_noisescale_START (16)
#define SOC_ISP_YUVNF_RECOVER_STRENGH_PARAM_noisescale_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pgaussianlut_0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int pgaussianlut_1 : 7;
        unsigned int reserved_1 : 1;
        unsigned int pgaussianlut_2 : 7;
        unsigned int reserved_2 : 9;
    } reg;
} SOC_ISP_YUVNF_PGAUSSIANLUT_UNION;
#endif
#define SOC_ISP_YUVNF_PGAUSSIANLUT_pgaussianlut_0_START (0)
#define SOC_ISP_YUVNF_PGAUSSIANLUT_pgaussianlut_0_END (6)
#define SOC_ISP_YUVNF_PGAUSSIANLUT_pgaussianlut_1_START (8)
#define SOC_ISP_YUVNF_PGAUSSIANLUT_pgaussianlut_1_END (14)
#define SOC_ISP_YUVNF_PGAUSSIANLUT_pgaussianlut_2_START (16)
#define SOC_ISP_YUVNF_PGAUSSIANLUT_pgaussianlut_2_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blend_x0 : 8;
        unsigned int blend_x1 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_YUVNF_BLEND_X_UNION;
#endif
#define SOC_ISP_YUVNF_BLEND_X_blend_x0_START (0)
#define SOC_ISP_YUVNF_BLEND_X_blend_x0_END (7)
#define SOC_ISP_YUVNF_BLEND_X_blend_x1_START (8)
#define SOC_ISP_YUVNF_BLEND_X_blend_x1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blend_y0 : 8;
        unsigned int blend_y1 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_YUVNF_BLEND_Y_UNION;
#endif
#define SOC_ISP_YUVNF_BLEND_Y_blend_y0_START (0)
#define SOC_ISP_YUVNF_BLEND_Y_blend_y0_END (7)
#define SOC_ISP_YUVNF_BLEND_Y_blend_y1_START (8)
#define SOC_ISP_YUVNF_BLEND_Y_blend_y1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pg3lut_0 : 7;
        unsigned int reserved_0: 1;
        unsigned int pg3lut_1 : 7;
        unsigned int reserved_1: 1;
        unsigned int pg9lut_4 : 7;
        unsigned int reserved_2: 9;
    } reg;
} SOC_ISP_YUVNF_PGAUSSLUT_3_UNION;
#endif
#define SOC_ISP_YUVNF_PGAUSSLUT_3_pg3lut_0_START (0)
#define SOC_ISP_YUVNF_PGAUSSLUT_3_pg3lut_0_END (6)
#define SOC_ISP_YUVNF_PGAUSSLUT_3_pg3lut_1_START (8)
#define SOC_ISP_YUVNF_PGAUSSLUT_3_pg3lut_1_END (14)
#define SOC_ISP_YUVNF_PGAUSSLUT_3_pg9lut_4_START (16)
#define SOC_ISP_YUVNF_PGAUSSLUT_3_pg9lut_4_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pg7lut_0 : 7;
        unsigned int reserved_0: 1;
        unsigned int pg7lut_1 : 7;
        unsigned int reserved_1: 1;
        unsigned int pg7lut_2 : 7;
        unsigned int reserved_2: 1;
        unsigned int pg7lut_3 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ISP_YUVNF_PGAUSSLUT_7_UNION;
#endif
#define SOC_ISP_YUVNF_PGAUSSLUT_7_pg7lut_0_START (0)
#define SOC_ISP_YUVNF_PGAUSSLUT_7_pg7lut_0_END (6)
#define SOC_ISP_YUVNF_PGAUSSLUT_7_pg7lut_1_START (8)
#define SOC_ISP_YUVNF_PGAUSSLUT_7_pg7lut_1_END (14)
#define SOC_ISP_YUVNF_PGAUSSLUT_7_pg7lut_2_START (16)
#define SOC_ISP_YUVNF_PGAUSSLUT_7_pg7lut_2_END (22)
#define SOC_ISP_YUVNF_PGAUSSLUT_7_pg7lut_3_START (24)
#define SOC_ISP_YUVNF_PGAUSSLUT_7_pg7lut_3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pg9lut_0 : 7;
        unsigned int reserved_0: 1;
        unsigned int pg9lut_1 : 7;
        unsigned int reserved_1: 1;
        unsigned int pg9lut_2 : 7;
        unsigned int reserved_2: 1;
        unsigned int pg9lut_3 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ISP_YUVNF_PGAUSSLUT_9_UNION;
#endif
#define SOC_ISP_YUVNF_PGAUSSLUT_9_pg9lut_0_START (0)
#define SOC_ISP_YUVNF_PGAUSSLUT_9_pg9lut_0_END (6)
#define SOC_ISP_YUVNF_PGAUSSLUT_9_pg9lut_1_START (8)
#define SOC_ISP_YUVNF_PGAUSSLUT_9_pg9lut_1_END (14)
#define SOC_ISP_YUVNF_PGAUSSLUT_9_pg9lut_2_START (16)
#define SOC_ISP_YUVNF_PGAUSSLUT_9_pg9lut_2_END (22)
#define SOC_ISP_YUVNF_PGAUSSLUT_9_pg9lut_3_START (24)
#define SOC_ISP_YUVNF_PGAUSSLUT_9_pg9lut_3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blendlow : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_YUVNF_BLENDLOW_UNION;
#endif
#define SOC_ISP_YUVNF_BLENDLOW_blendlow_START (0)
#define SOC_ISP_YUVNF_BLENDLOW_blendlow_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_u_denlut : 6;
        unsigned int l1_u_denlut : 6;
        unsigned int l2_u_denlut : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_ISP_YUVNF_L012_U_DENLUT_UNION;
#endif
#define SOC_ISP_YUVNF_L012_U_DENLUT_l0_u_denlut_START (0)
#define SOC_ISP_YUVNF_L012_U_DENLUT_l0_u_denlut_END (5)
#define SOC_ISP_YUVNF_L012_U_DENLUT_l1_u_denlut_START (6)
#define SOC_ISP_YUVNF_L012_U_DENLUT_l1_u_denlut_END (11)
#define SOC_ISP_YUVNF_L012_U_DENLUT_l2_u_denlut_START (12)
#define SOC_ISP_YUVNF_L012_U_DENLUT_l2_u_denlut_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_u_denreflut : 6;
        unsigned int l1_u_denreflut : 6;
        unsigned int l2_u_denreflut : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_ISP_YUVNF_L012_U_DENREFLUT_UNION;
#endif
#define SOC_ISP_YUVNF_L012_U_DENREFLUT_l0_u_denreflut_START (0)
#define SOC_ISP_YUVNF_L012_U_DENREFLUT_l0_u_denreflut_END (5)
#define SOC_ISP_YUVNF_L012_U_DENREFLUT_l1_u_denreflut_START (6)
#define SOC_ISP_YUVNF_L012_U_DENREFLUT_l1_u_denreflut_END (11)
#define SOC_ISP_YUVNF_L012_U_DENREFLUT_l2_u_denreflut_START (12)
#define SOC_ISP_YUVNF_L012_U_DENREFLUT_l2_u_denreflut_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_v_denlut : 6;
        unsigned int l1_v_denlut : 6;
        unsigned int l2_v_denlut : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_ISP_YUVNF_L012_V_DENLUT_UNION;
#endif
#define SOC_ISP_YUVNF_L012_V_DENLUT_l0_v_denlut_START (0)
#define SOC_ISP_YUVNF_L012_V_DENLUT_l0_v_denlut_END (5)
#define SOC_ISP_YUVNF_L012_V_DENLUT_l1_v_denlut_START (6)
#define SOC_ISP_YUVNF_L012_V_DENLUT_l1_v_denlut_END (11)
#define SOC_ISP_YUVNF_L012_V_DENLUT_l2_v_denlut_START (12)
#define SOC_ISP_YUVNF_L012_V_DENLUT_l2_v_denlut_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_v_denreflut : 6;
        unsigned int l1_v_denreflut : 6;
        unsigned int l2_v_denreflut : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_ISP_YUVNF_L012_V_DENREFLUT_UNION;
#endif
#define SOC_ISP_YUVNF_L012_V_DENREFLUT_l0_v_denreflut_START (0)
#define SOC_ISP_YUVNF_L012_V_DENREFLUT_l0_v_denreflut_END (5)
#define SOC_ISP_YUVNF_L012_V_DENREFLUT_l1_v_denreflut_START (6)
#define SOC_ISP_YUVNF_L012_V_DENREFLUT_l1_v_denreflut_END (11)
#define SOC_ISP_YUVNF_L012_V_DENREFLUT_l2_v_denreflut_START (12)
#define SOC_ISP_YUVNF_L012_V_DENREFLUT_l2_v_denreflut_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_u_denlut : 6;
        unsigned int l4_u_denlut : 6;
        unsigned int l5_u_denlut : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_ISP_YUVNF_L345_U_DENLUT_UNION;
#endif
#define SOC_ISP_YUVNF_L345_U_DENLUT_l3_u_denlut_START (0)
#define SOC_ISP_YUVNF_L345_U_DENLUT_l3_u_denlut_END (5)
#define SOC_ISP_YUVNF_L345_U_DENLUT_l4_u_denlut_START (6)
#define SOC_ISP_YUVNF_L345_U_DENLUT_l4_u_denlut_END (11)
#define SOC_ISP_YUVNF_L345_U_DENLUT_l5_u_denlut_START (12)
#define SOC_ISP_YUVNF_L345_U_DENLUT_l5_u_denlut_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_u_denreflut : 6;
        unsigned int l4_u_denreflut : 6;
        unsigned int l5_u_denreflut : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_ISP_YUVNF_L345_U_DENREFLUT_UNION;
#endif
#define SOC_ISP_YUVNF_L345_U_DENREFLUT_l3_u_denreflut_START (0)
#define SOC_ISP_YUVNF_L345_U_DENREFLUT_l3_u_denreflut_END (5)
#define SOC_ISP_YUVNF_L345_U_DENREFLUT_l4_u_denreflut_START (6)
#define SOC_ISP_YUVNF_L345_U_DENREFLUT_l4_u_denreflut_END (11)
#define SOC_ISP_YUVNF_L345_U_DENREFLUT_l5_u_denreflut_START (12)
#define SOC_ISP_YUVNF_L345_U_DENREFLUT_l5_u_denreflut_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_v_denlut : 6;
        unsigned int l4_v_denlut : 6;
        unsigned int l5_v_denlut : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_ISP_YUVNF_L345_V_DENLUT_UNION;
#endif
#define SOC_ISP_YUVNF_L345_V_DENLUT_l3_v_denlut_START (0)
#define SOC_ISP_YUVNF_L345_V_DENLUT_l3_v_denlut_END (5)
#define SOC_ISP_YUVNF_L345_V_DENLUT_l4_v_denlut_START (6)
#define SOC_ISP_YUVNF_L345_V_DENLUT_l4_v_denlut_END (11)
#define SOC_ISP_YUVNF_L345_V_DENLUT_l5_v_denlut_START (12)
#define SOC_ISP_YUVNF_L345_V_DENLUT_l5_v_denlut_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_v_denreflut : 6;
        unsigned int l4_v_denreflut : 6;
        unsigned int l5_v_denreflut : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_ISP_YUVNF_L345_V_DENREFLUT_UNION;
#endif
#define SOC_ISP_YUVNF_L345_V_DENREFLUT_l3_v_denreflut_START (0)
#define SOC_ISP_YUVNF_L345_V_DENREFLUT_l3_v_denreflut_END (5)
#define SOC_ISP_YUVNF_L345_V_DENREFLUT_l4_v_denreflut_START (6)
#define SOC_ISP_YUVNF_L345_V_DENREFLUT_l4_v_denreflut_END (11)
#define SOC_ISP_YUVNF_L345_V_DENREFLUT_l5_v_denreflut_START (12)
#define SOC_ISP_YUVNF_L345_V_DENREFLUT_l5_v_denreflut_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_u_gaulut : 6;
        unsigned int l1_u_gaulut : 6;
        unsigned int l2_u_gaulut : 6;
        unsigned int l3_u_gaulut : 6;
        unsigned int reserved : 8;
    } reg;
} SOC_ISP_YUVNF_L0123_U_GAULUT_UNION;
#endif
#define SOC_ISP_YUVNF_L0123_U_GAULUT_l0_u_gaulut_START (0)
#define SOC_ISP_YUVNF_L0123_U_GAULUT_l0_u_gaulut_END (5)
#define SOC_ISP_YUVNF_L0123_U_GAULUT_l1_u_gaulut_START (6)
#define SOC_ISP_YUVNF_L0123_U_GAULUT_l1_u_gaulut_END (11)
#define SOC_ISP_YUVNF_L0123_U_GAULUT_l2_u_gaulut_START (12)
#define SOC_ISP_YUVNF_L0123_U_GAULUT_l2_u_gaulut_END (17)
#define SOC_ISP_YUVNF_L0123_U_GAULUT_l3_u_gaulut_START (18)
#define SOC_ISP_YUVNF_L0123_U_GAULUT_l3_u_gaulut_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l0_v_gaulut : 6;
        unsigned int l1_v_gaulut : 6;
        unsigned int l2_v_gaulut : 6;
        unsigned int l3_v_gaulut : 6;
        unsigned int reserved : 8;
    } reg;
} SOC_ISP_YUVNF_L0123_V_GAULUT_UNION;
#endif
#define SOC_ISP_YUVNF_L0123_V_GAULUT_l0_v_gaulut_START (0)
#define SOC_ISP_YUVNF_L0123_V_GAULUT_l0_v_gaulut_END (5)
#define SOC_ISP_YUVNF_L0123_V_GAULUT_l1_v_gaulut_START (6)
#define SOC_ISP_YUVNF_L0123_V_GAULUT_l1_v_gaulut_END (11)
#define SOC_ISP_YUVNF_L0123_V_GAULUT_l2_v_gaulut_START (12)
#define SOC_ISP_YUVNF_L0123_V_GAULUT_l2_v_gaulut_END (17)
#define SOC_ISP_YUVNF_L0123_V_GAULUT_l3_v_gaulut_START (18)
#define SOC_ISP_YUVNF_L0123_V_GAULUT_l3_v_gaulut_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_u_gaulut5 : 6;
        unsigned int l5_u_gaulut5 : 6;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L45_U_GAULUT5_UNION;
#endif
#define SOC_ISP_YUVNF_L45_U_GAULUT5_l4_u_gaulut5_START (0)
#define SOC_ISP_YUVNF_L45_U_GAULUT5_l4_u_gaulut5_END (5)
#define SOC_ISP_YUVNF_L45_U_GAULUT5_l5_u_gaulut5_START (6)
#define SOC_ISP_YUVNF_L45_U_GAULUT5_l5_u_gaulut5_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l4_v_gaulut5 : 6;
        unsigned int l5_v_gaulut5 : 6;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_YUVNF_L45_V_GAULUT5_UNION;
#endif
#define SOC_ISP_YUVNF_L45_V_GAULUT5_l4_v_gaulut5_START (0)
#define SOC_ISP_YUVNF_L45_V_GAULUT5_l4_v_gaulut5_END (5)
#define SOC_ISP_YUVNF_L45_V_GAULUT5_l5_v_gaulut5_START (6)
#define SOC_ISP_YUVNF_L45_V_GAULUT5_l5_v_gaulut5_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainlsc : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_YUVNF_GAINLSC_UNION;
#endif
#define SOC_ISP_YUVNF_GAINLSC_gainlsc_START (0)
#define SOC_ISP_YUVNF_GAINLSC_gainlsc_END (12)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

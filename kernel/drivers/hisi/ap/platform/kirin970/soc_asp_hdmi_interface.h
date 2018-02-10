#ifndef __SOC_ASP_HDMI_INTERFACE_H__
#define __SOC_ASP_HDMI_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ASP_HDMI_ASP_TX3_ADDR(base) ((base) + (0x000))
#define SOC_ASP_HDMI_ASP_DER_ADDR(base) ((base) + (0x004))
#define SOC_ASP_HDMI_ASP_DSTOP_ADDR(base) ((base) + (0x008))
#define SOC_ASP_HDMI_ASP_ASS_ISR_ADDR(base) ((base) + (0x00C))
#define SOC_ASP_HDMI_ASP_IRSR_ADDR(base) ((base) + (0x010))
#define SOC_ASP_HDMI_ASP_IER_ADDR(base) ((base) + (0x014))
#define SOC_ASP_HDMI_ASP_IMSR_ADDR(base) ((base) + (0x018))
#define SOC_ASP_HDMI_ASP_ICR_ADDR(base) ((base) + (0x01C))
#define SOC_ASP_HDMI_ASP_PCMNSSR_ADDR(base) ((base) + (0x020))
#define SOC_ASP_HDMI_ASP_P30CGR_ADDR(base) ((base) + (0x028))
#define SOC_ASP_HDMI_ASP_P31CGR_ADDR(base) ((base) + (0x02C))
#define SOC_ASP_HDMI_ASP_P32CGR_ADDR(base) ((base) + (0x030))
#define SOC_ASP_HDMI_ASP_P33CGR_ADDR(base) ((base) + (0x034))
#define SOC_ASP_HDMI_ASP_P34CGR_ADDR(base) ((base) + (0x038))
#define SOC_ASP_HDMI_ASP_P35CGR_ADDR(base) ((base) + (0x03C))
#define SOC_ASP_HDMI_ASP_P36CGR_ADDR(base) ((base) + (0x040))
#define SOC_ASP_HDMI_ASP_P37CGR_ADDR(base) ((base) + (0x044))
#define SOC_ASP_HDMI_ASP_P3ASAR_ADDR(base) ((base) + (0x048))
#define SOC_ASP_HDMI_ASP_P3ADLR_ADDR(base) ((base) + (0x04C))
#define SOC_ASP_HDMI_ASP_P3BSAR_ADDR(base) ((base) + (0x050))
#define SOC_ASP_HDMI_ASP_P3BDLR_ADDR(base) ((base) + (0x054))
#define SOC_ASP_HDMI_ASP_SPDIFSEL_ADDR(base) ((base) + (0x058))
#define SOC_ASP_HDMI_ASP_P3ADLS_ADDR(base) ((base) + (0x05C))
#define SOC_ASP_HDMI_ASP_P3BDLS_ADDR(base) ((base) + (0x060))
#define SOC_ASP_HDMI_ASP_FDS_ADDR(base) ((base) + (0x064))
#define SOC_ASP_HDMI_ASP_P3ADL_ADDR(base) ((base) + (0x068))
#define SOC_ASP_HDMI_ASP_P3BDL_ADDR(base) ((base) + (0x06C))
#define SOC_ASP_HDMI_ASP_SECURE_ADDR(base) ((base) + (0x070))
#define SOC_ASP_HDMI_SIO1_ASPIF_SEL_ADDR(base) ((base) + (0x400))
#define SOC_ASP_HDMI_SIO1_RAW_INT_ADDR(base) ((base) + (0x408))
#define SOC_ASP_HDMI_SIO1_INT_CLR_ADDR(base) ((base) + (0x40C))
#define SOC_ASP_HDMI_SIO1_INT_ENABLE_ADDR(base) ((base) + (0x410))
#define SOC_ASP_HDMI_SIO1_INT_MASKED_STATUS_ADDR(base) ((base) + (0x414))
#define SOC_ASP_HDMI_SIO1_I2S_SET_ADDR(base) ((base) + (0x41C))
#define SOC_ASP_HDMI_SIO1_I2S_CLR_ADDR(base) ((base) + (0x420))
#define SOC_ASP_HDMI_SIO1_TX_STA_ADDR(base) ((base) + (0x42C))
#define SOC_ASP_HDMI_SIO1_CLR_ADDR(base) ((base) + (0x438))
#define SOC_ASP_HDMI_SIO_CH_DATA_VLD_ADDR(base) ((base) + (0x444))
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_ADDR(base) ((base) + (0x448))
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_L_ADDR(base) ((base) + (0x44C))
#define SOC_ASP_HDMI_SIO_CH0_STATUS3_L_ADDR(base) ((base) + (0x450))
#define SOC_ASP_HDMI_SIO_CH0_STATUS4_L_ADDR(base) ((base) + (0x454))
#define SOC_ASP_HDMI_SIO_CH0_STATUS5_L_ADDR(base) ((base) + (0x458))
#define SOC_ASP_HDMI_SIO_CH0_STATUS6_L_ADDR(base) ((base) + (0x45C))
#define SOC_ASP_HDMI_SIO1_USER0_DATA1_L_ADDR(base) ((base) + (0x460))
#define SOC_ASP_HDMI_SIO1_USER0_DATA2_L_ADDR(base) ((base) + (0x464))
#define SOC_ASP_HDMI_SIO1_USER0_DATA3_L_ADDR(base) ((base) + (0x468))
#define SOC_ASP_HDMI_SIO1_USER0_DATA4_L_ADDR(base) ((base) + (0x46C))
#define SOC_ASP_HDMI_SIO1_USER0_DATA5_L_ADDR(base) ((base) + (0x470))
#define SOC_ASP_HDMI_SIO1_USER0_DATA6_L_ADDR(base) ((base) + (0x474))
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_ADDR(base) ((base) + (0x478))
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_R_ADDR(base) ((base) + (0x47C))
#define SOC_ASP_HDMI_SIO_CH0_STATUS3_R_ADDR(base) ((base) + (0x480))
#define SOC_ASP_HDMI_SIO_CH0_STATUS4_R_ADDR(base) ((base) + (0x484))
#define SOC_ASP_HDMI_SIO_CH0_STATUS5_R_ADDR(base) ((base) + (0x488))
#define SOC_ASP_HDMI_SIO_CH0_STATUS6_R_ADDR(base) ((base) + (0x48C))
#define SOC_ASP_HDMI_SIO1_USER0_DATA1_R_ADDR(base) ((base) + (0x490))
#define SOC_ASP_HDMI_SIO1_USER0_DATA2_R_ADDR(base) ((base) + (0x494))
#define SOC_ASP_HDMI_SIO1_USER0_DATA3_R_ADDR(base) ((base) + (0x498))
#define SOC_ASP_HDMI_SIO1_USER0_DATA4_R_ADDR(base) ((base) + (0x49C))
#define SOC_ASP_HDMI_SIO1_USER0_DATA5_R_ADDR(base) ((base) + (0x4A0))
#define SOC_ASP_HDMI_SIO1_USER0_DATA6_R_ADDR(base) ((base) + (0x4A4))
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_ADDR(base) ((base) + (0x4A8))
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_L_ADDR(base) ((base) + (0x4AC))
#define SOC_ASP_HDMI_SIO_CH1_STATUS3_L_ADDR(base) ((base) + (0x4B0))
#define SOC_ASP_HDMI_SIO_CH1_STATUS4_L_ADDR(base) ((base) + (0x4B4))
#define SOC_ASP_HDMI_SIO_CH1_STATUS5_L_ADDR(base) ((base) + (0x4B8))
#define SOC_ASP_HDMI_SIO_CH1_STATUS6_L_ADDR(base) ((base) + (0x4BC))
#define SOC_ASP_HDMI_SIO1_USER1_DATA1_L_ADDR(base) ((base) + (0x4C0))
#define SOC_ASP_HDMI_SIO1_USER1_DATA2_L_ADDR(base) ((base) + (0x4C4))
#define SOC_ASP_HDMI_SIO1_USER1_DATA3_L_ADDR(base) ((base) + (0x4C8))
#define SOC_ASP_HDMI_SIO1_USER1_DATA4_L_ADDR(base) ((base) + (0x4CC))
#define SOC_ASP_HDMI_SIO1_USER1_DATA5_L_ADDR(base) ((base) + (0x4D0))
#define SOC_ASP_HDMI_SIO1_USER1_DATA6_L_ADDR(base) ((base) + (0x4D4))
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_ADDR(base) ((base) + (0x4D8))
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_R_ADDR(base) ((base) + (0x4DC))
#define SOC_ASP_HDMI_SIO_CH1_STATUS3_R_ADDR(base) ((base) + (0x4E0))
#define SOC_ASP_HDMI_SIO_CH1_STATUS4_R_ADDR(base) ((base) + (0x4E4))
#define SOC_ASP_HDMI_SIO_CH1_STATUS5_R_ADDR(base) ((base) + (0x4E8))
#define SOC_ASP_HDMI_SIO_CH1_STATUS6_R_ADDR(base) ((base) + (0x4EC))
#define SOC_ASP_HDMI_SIO1_USER1_DATA1_R_ADDR(base) ((base) + (0x4F0))
#define SOC_ASP_HDMI_SIO1_USER1_DATA2_R_ADDR(base) ((base) + (0x4F4))
#define SOC_ASP_HDMI_SIO1_USER1_DATA3_R_ADDR(base) ((base) + (0x4F8))
#define SOC_ASP_HDMI_SIO1_USER1_DATA4_R_ADDR(base) ((base) + (0x4FC))
#define SOC_ASP_HDMI_SIO1_USER1_DATA5_R_ADDR(base) ((base) + (0x500))
#define SOC_ASP_HDMI_SIO1_USER1_DATA6_R_ADDR(base) ((base) + (0x504))
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_ADDR(base) ((base) + (0x508))
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_L_ADDR(base) ((base) + (0x50C))
#define SOC_ASP_HDMI_SIO_CH2_STATUS3_L_ADDR(base) ((base) + (0x510))
#define SOC_ASP_HDMI_SIO_CH2_STATUS4_L_ADDR(base) ((base) + (0x514))
#define SOC_ASP_HDMI_SIO_CH2_STATUS5_L_ADDR(base) ((base) + (0x518))
#define SOC_ASP_HDMI_SIO_CH2_STATUS6_L_ADDR(base) ((base) + (0x51C))
#define SOC_ASP_HDMI_SIO1_USER2_DATA1_L_ADDR(base) ((base) + (0x520))
#define SOC_ASP_HDMI_SIO1_USER2_DATA2_L_ADDR(base) ((base) + (0x524))
#define SOC_ASP_HDMI_SIO1_USER2_DATA3_L_ADDR(base) ((base) + (0x528))
#define SOC_ASP_HDMI_SIO1_USER2_DATA4_L_ADDR(base) ((base) + (0x52C))
#define SOC_ASP_HDMI_SIO1_USER2_DATA5_L_ADDR(base) ((base) + (0x530))
#define SOC_ASP_HDMI_SIO1_USER2_DATA6_L_ADDR(base) ((base) + (0x534))
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_ADDR(base) ((base) + (0x538))
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_R_ADDR(base) ((base) + (0x53C))
#define SOC_ASP_HDMI_SIO_CH2_STATUS3_R_ADDR(base) ((base) + (0x540))
#define SOC_ASP_HDMI_SIO_CH2_STATUS4_R_ADDR(base) ((base) + (0x544))
#define SOC_ASP_HDMI_SIO_CH2_STATUS5_R_ADDR(base) ((base) + (0x548))
#define SOC_ASP_HDMI_SIO_CH2_STATUS6_R_ADDR(base) ((base) + (0x54C))
#define SOC_ASP_HDMI_SIO1_USER2_DATA1_R_ADDR(base) ((base) + (0x550))
#define SOC_ASP_HDMI_SIO1_USER2_DATA2_R_ADDR(base) ((base) + (0x554))
#define SOC_ASP_HDMI_SIO1_USER2_DATA3_R_ADDR(base) ((base) + (0x558))
#define SOC_ASP_HDMI_SIO1_USER2_DATA4_R_ADDR(base) ((base) + (0x55C))
#define SOC_ASP_HDMI_SIO1_USER2_DATA5_R_ADDR(base) ((base) + (0x560))
#define SOC_ASP_HDMI_SIO1_USER2_DATA6_R_ADDR(base) ((base) + (0x564))
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_ADDR(base) ((base) + (0x568))
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_L_ADDR(base) ((base) + (0x56C))
#define SOC_ASP_HDMI_SIO_CH3_STATUS3_L_ADDR(base) ((base) + (0x570))
#define SOC_ASP_HDMI_SIO_CH3_STATUS4_L_ADDR(base) ((base) + (0x574))
#define SOC_ASP_HDMI_SIO_CH3_STATUS5_L_ADDR(base) ((base) + (0x578))
#define SOC_ASP_HDMI_SIO_CH3_STATUS6_L_ADDR(base) ((base) + (0x57C))
#define SOC_ASP_HDMI_SIO1_USER3_DATA1_L_ADDR(base) ((base) + (0x580))
#define SOC_ASP_HDMI_SIO1_USER3_DATA2_L_ADDR(base) ((base) + (0x584))
#define SOC_ASP_HDMI_SIO1_USER3_DATA3_L_ADDR(base) ((base) + (0x588))
#define SOC_ASP_HDMI_SIO1_USER3_DATA4_L_ADDR(base) ((base) + (0x58C))
#define SOC_ASP_HDMI_SIO1_USER3_DATA5_L_ADDR(base) ((base) + (0x590))
#define SOC_ASP_HDMI_SIO1_USER3_DATA6_L_ADDR(base) ((base) + (0x594))
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_ADDR(base) ((base) + (0x598))
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_R_ADDR(base) ((base) + (0x59C))
#define SOC_ASP_HDMI_SIO_CH3_STATUS3_R_ADDR(base) ((base) + (0x5A0))
#define SOC_ASP_HDMI_SIO_CH3_STATUS4_R_ADDR(base) ((base) + (0x5A4))
#define SOC_ASP_HDMI_SIO_CH3_STATUS5_R_ADDR(base) ((base) + (0x5A8))
#define SOC_ASP_HDMI_SIO_CH3_STATUS6_R_ADDR(base) ((base) + (0x5AC))
#define SOC_ASP_HDMI_SIO1_USER3_DATA1_R_ADDR(base) ((base) + (0x5B0))
#define SOC_ASP_HDMI_SIO1_USER3_DATA2_R_ADDR(base) ((base) + (0x5B4))
#define SOC_ASP_HDMI_SIO1_USER3_DATA3_R_ADDR(base) ((base) + (0x5B8))
#define SOC_ASP_HDMI_SIO1_USER3_DATA4_R_ADDR(base) ((base) + (0x5BC))
#define SOC_ASP_HDMI_SIO1_USER3_DATA5_R_ADDR(base) ((base) + (0x5C0))
#define SOC_ASP_HDMI_SIO1_USER3_DATA6_R_ADDR(base) ((base) + (0x5C4))
#define SOC_ASP_HDMI_SPDIF_CTRL_ADDR(base) ((base) + (0x800))
#define SOC_ASP_HDMI_SPDIF_CONFIG_ADDR(base) ((base) + (0x804))
#define SOC_ASP_HDMI_SPDIF_INTRUPT_ADDR(base) ((base) + (0x808))
#define SOC_ASP_HDMI_SPDIF_INTR_MASK_ADDR(base) ((base) + (0x80C))
#define SOC_ASP_HDMI_SPDIF_FIFO_STATE_ADDR(base) ((base) + (0x810))
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_ADDR(base) ((base) + (0x820))
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_L_ADDR(base) ((base) + (0x824))
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS3_L_ADDR(base) ((base) + (0x828))
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS4_L_ADDR(base) ((base) + (0x82C))
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS5_L_ADDR(base) ((base) + (0x830))
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS6_L_ADDR(base) ((base) + (0x834))
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA1_L_ADDR(base) ((base) + (0x838))
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA2_L_ADDR(base) ((base) + (0x83C))
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA3_L_ADDR(base) ((base) + (0x840))
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA4_L_ADDR(base) ((base) + (0x844))
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA5_L_ADDR(base) ((base) + (0x848))
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA6_L_ADDR(base) ((base) + (0x84C))
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_ADDR(base) ((base) + (0x850))
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_R_ADDR(base) ((base) + (0x854))
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS3_R_ADDR(base) ((base) + (0x858))
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS4_R_ADDR(base) ((base) + (0x85C))
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS5_R_ADDR(base) ((base) + (0x860))
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS6_R_ADDR(base) ((base) + (0x864))
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA1_R_ADDR(base) ((base) + (0x868))
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA2_R_ADDR(base) ((base) + (0x86C))
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA3_R_ADDR(base) ((base) + (0x870))
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA4_R_ADDR(base) ((base) + (0x874))
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA5_R_ADDR(base) ((base) + (0x878))
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA6_R_ADDR(base) ((base) + (0x87C))
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_ADDR(base) ((base) + (0x880))
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_L_ADDR(base) ((base) + (0x884))
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS3_L_ADDR(base) ((base) + (0x888))
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS4_L_ADDR(base) ((base) + (0x88C))
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS5_L_ADDR(base) ((base) + (0x890))
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS6_L_ADDR(base) ((base) + (0x894))
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA1_L_ADDR(base) ((base) + (0x898))
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA2_L_ADDR(base) ((base) + (0x89C))
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA3_L_ADDR(base) ((base) + (0x8A0))
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA4_L_ADDR(base) ((base) + (0x8A4))
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA5_L_ADDR(base) ((base) + (0x8A8))
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA6_L_ADDR(base) ((base) + (0x8AC))
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_ADDR(base) ((base) + (0x8B0))
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_R_ADDR(base) ((base) + (0x8B4))
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS3_R_ADDR(base) ((base) + (0x8B8))
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS4_R_ADDR(base) ((base) + (0x8BC))
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS5_R_ADDR(base) ((base) + (0x8C0))
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS6_R_ADDR(base) ((base) + (0x8C4))
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA1_R_ADDR(base) ((base) + (0x8C8))
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA2_R_ADDR(base) ((base) + (0x8CC))
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA3_R_ADDR(base) ((base) + (0x8D0))
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA4_R_ADDR(base) ((base) + (0x8D4))
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA5_R_ADDR(base) ((base) + (0x8D8))
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA6_R_ADDR(base) ((base) + (0x8DC))
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_ADDR(base) ((base) + (0x8E0))
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_L_ADDR(base) ((base) + (0x8E4))
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS3_L_ADDR(base) ((base) + (0x8E8))
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS4_L_ADDR(base) ((base) + (0x8EC))
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS5_L_ADDR(base) ((base) + (0x8F0))
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS6_L_ADDR(base) ((base) + (0x8F4))
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA1_L_ADDR(base) ((base) + (0x8F8))
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA2_L_ADDR(base) ((base) + (0x8FC))
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA3_L_ADDR(base) ((base) + (0x900))
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA4_L_ADDR(base) ((base) + (0x904))
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA5_L_ADDR(base) ((base) + (0x908))
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA6_L_ADDR(base) ((base) + (0x90C))
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_ADDR(base) ((base) + (0x910))
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_R_ADDR(base) ((base) + (0x914))
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS3_R_ADDR(base) ((base) + (0x918))
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS4_R_ADDR(base) ((base) + (0x91C))
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS5_R_ADDR(base) ((base) + (0x920))
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS6_R_ADDR(base) ((base) + (0x924))
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA1_R_ADDR(base) ((base) + (0x928))
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA2_R_ADDR(base) ((base) + (0x92C))
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA3_R_ADDR(base) ((base) + (0x930))
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA4_R_ADDR(base) ((base) + (0x934))
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA5_R_ADDR(base) ((base) + (0x938))
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA6_R_ADDR(base) ((base) + (0x93C))
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_ADDR(base) ((base) + (0x940))
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_L_ADDR(base) ((base) + (0x944))
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS3_L_ADDR(base) ((base) + (0x948))
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS4_L_ADDR(base) ((base) + (0x94C))
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS5_L_ADDR(base) ((base) + (0x950))
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS6_L_ADDR(base) ((base) + (0x954))
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA1_L_ADDR(base) ((base) + (0x958))
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA2_L_ADDR(base) ((base) + (0x95C))
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA3_L_ADDR(base) ((base) + (0x960))
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA4_L_ADDR(base) ((base) + (0x964))
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA5_L_ADDR(base) ((base) + (0x968))
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA6_L_ADDR(base) ((base) + (0x96C))
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_ADDR(base) ((base) + (0x970))
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_R_ADDR(base) ((base) + (0x974))
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS3_R_ADDR(base) ((base) + (0x978))
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS4_R_ADDR(base) ((base) + (0x97C))
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS5_R_ADDR(base) ((base) + (0x980))
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS6_R_ADDR(base) ((base) + (0x984))
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA1_R_ADDR(base) ((base) + (0x988))
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA2_R_ADDR(base) ((base) + (0x98C))
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA3_R_ADDR(base) ((base) + (0x990))
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA4_R_ADDR(base) ((base) + (0x994))
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA5_R_ADDR(base) ((base) + (0x998))
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA6_R_ADDR(base) ((base) + (0x99C))
#define SOC_ASP_HDMI_SPDIF_EDITION_ADDR(base) ((base) + (0x9F0))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcm3_ch_en : 1;
        unsigned int pcm3_gain_en : 1;
        unsigned int pcm3_ts_en : 1;
        unsigned int pcm3_data_in_width : 4;
        unsigned int pcm3_halfword_align_en : 1;
        unsigned int pcm3_ch_num : 3;
        unsigned int reserved_0 : 1;
        unsigned int pcm3_big_endian : 1;
        unsigned int pcm3_switch_order : 1;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ASP_HDMI_ASP_TX3_UNION;
#endif
#define SOC_ASP_HDMI_ASP_TX3_pcm3_ch_en_START (0)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_ch_en_END (0)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_gain_en_START (1)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_gain_en_END (1)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_ts_en_START (2)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_ts_en_END (2)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_data_in_width_START (3)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_data_in_width_END (6)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_halfword_align_en_START (7)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_halfword_align_en_END (7)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_ch_num_START (8)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_ch_num_END (10)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_big_endian_START (12)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_big_endian_END (12)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_switch_order_START (13)
#define SOC_ASP_HDMI_ASP_TX3_pcm3_switch_order_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcm3ade : 1;
        unsigned int pcm3bde : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ASP_HDMI_ASP_DER_UNION;
#endif
#define SOC_ASP_HDMI_ASP_DER_pcm3ade_START (0)
#define SOC_ASP_HDMI_ASP_DER_pcm3ade_END (0)
#define SOC_ASP_HDMI_ASP_DER_pcm3bde_START (1)
#define SOC_ASP_HDMI_ASP_DER_pcm3bde_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcm3ads : 1;
        unsigned int pcm3bds : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ASP_HDMI_ASP_DSTOP_UNION;
#endif
#define SOC_ASP_HDMI_ASP_DSTOP_pcm3ads_START (0)
#define SOC_ASP_HDMI_ASP_DSTOP_pcm3ads_END (0)
#define SOC_ASP_HDMI_ASP_DSTOP_pcm3bds_START (1)
#define SOC_ASP_HDMI_ASP_DSTOP_pcm3bds_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sio1is : 1;
        unsigned int spdifis : 1;
        unsigned int aspis : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ASP_HDMI_ASP_ASS_ISR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_ASS_ISR_sio1is_START (0)
#define SOC_ASP_HDMI_ASP_ASS_ISR_sio1is_END (0)
#define SOC_ASP_HDMI_ASP_ASS_ISR_spdifis_START (1)
#define SOC_ASP_HDMI_ASP_ASS_ISR_spdifis_END (1)
#define SOC_ASP_HDMI_ASP_ASS_ISR_aspis_START (2)
#define SOC_ASP_HDMI_ASP_ASS_ISR_aspis_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3adfirs : 1;
        unsigned int p3bdfirs : 1;
        unsigned int aberirs : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ASP_HDMI_ASP_IRSR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_IRSR_p3adfirs_START (0)
#define SOC_ASP_HDMI_ASP_IRSR_p3adfirs_END (0)
#define SOC_ASP_HDMI_ASP_IRSR_p3bdfirs_START (1)
#define SOC_ASP_HDMI_ASP_IRSR_p3bdfirs_END (1)
#define SOC_ASP_HDMI_ASP_IRSR_aberirs_START (2)
#define SOC_ASP_HDMI_ASP_IRSR_aberirs_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3adfie : 1;
        unsigned int p3bdfie : 1;
        unsigned int aberie : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ASP_HDMI_ASP_IER_UNION;
#endif
#define SOC_ASP_HDMI_ASP_IER_p3adfie_START (0)
#define SOC_ASP_HDMI_ASP_IER_p3adfie_END (0)
#define SOC_ASP_HDMI_ASP_IER_p3bdfie_START (1)
#define SOC_ASP_HDMI_ASP_IER_p3bdfie_END (1)
#define SOC_ASP_HDMI_ASP_IER_aberie_START (2)
#define SOC_ASP_HDMI_ASP_IER_aberie_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3adfims : 1;
        unsigned int p3bdfims : 1;
        unsigned int aberims : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ASP_HDMI_ASP_IMSR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_IMSR_p3adfims_START (0)
#define SOC_ASP_HDMI_ASP_IMSR_p3adfims_END (0)
#define SOC_ASP_HDMI_ASP_IMSR_p3bdfims_START (1)
#define SOC_ASP_HDMI_ASP_IMSR_p3bdfims_END (1)
#define SOC_ASP_HDMI_ASP_IMSR_aberims_START (2)
#define SOC_ASP_HDMI_ASP_IMSR_aberims_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3adficr : 1;
        unsigned int p3bdficr : 1;
        unsigned int abericr : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ASP_HDMI_ASP_ICR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_ICR_p3adficr_START (0)
#define SOC_ASP_HDMI_ASP_ICR_p3adficr_END (0)
#define SOC_ASP_HDMI_ASP_ICR_p3bdficr_START (1)
#define SOC_ASP_HDMI_ASP_ICR_p3bdficr_END (1)
#define SOC_ASP_HDMI_ASP_ICR_abericr_START (2)
#define SOC_ASP_HDMI_ASP_ICR_abericr_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3dsr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_HDMI_ASP_PCMNSSR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_PCMNSSR_p3dsr_START (0)
#define SOC_ASP_HDMI_ASP_PCMNSSR_p3dsr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p30cgr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_HDMI_ASP_P30CGR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P30CGR_p30cgr_START (0)
#define SOC_ASP_HDMI_ASP_P30CGR_p30cgr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p31cgr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_HDMI_ASP_P31CGR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P31CGR_p31cgr_START (0)
#define SOC_ASP_HDMI_ASP_P31CGR_p31cgr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p32cgr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_HDMI_ASP_P32CGR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P32CGR_p32cgr_START (0)
#define SOC_ASP_HDMI_ASP_P32CGR_p32cgr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p33cgr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_HDMI_ASP_P33CGR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P33CGR_p33cgr_START (0)
#define SOC_ASP_HDMI_ASP_P33CGR_p33cgr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p34cgr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_HDMI_ASP_P34CGR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P34CGR_p34cgr_START (0)
#define SOC_ASP_HDMI_ASP_P34CGR_p34cgr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p35cgr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_HDMI_ASP_P35CGR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P35CGR_p35cgr_START (0)
#define SOC_ASP_HDMI_ASP_P35CGR_p35cgr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p36cgr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_HDMI_ASP_P36CGR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P36CGR_p36cgr_START (0)
#define SOC_ASP_HDMI_ASP_P36CGR_p36cgr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p37cgr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_HDMI_ASP_P37CGR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P37CGR_p37cgr_START (0)
#define SOC_ASP_HDMI_ASP_P37CGR_p37cgr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3asar : 32;
    } reg;
} SOC_ASP_HDMI_ASP_P3ASAR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P3ASAR_p3asar_START (0)
#define SOC_ASP_HDMI_ASP_P3ASAR_p3asar_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3adlr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ASP_HDMI_ASP_P3ADLR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P3ADLR_p3adlr_START (0)
#define SOC_ASP_HDMI_ASP_P3ADLR_p3adlr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3bsar : 32;
    } reg;
} SOC_ASP_HDMI_ASP_P3BSAR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P3BSAR_p3bsar_START (0)
#define SOC_ASP_HDMI_ASP_P3BSAR_p3bsar_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3bdlr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ASP_HDMI_ASP_P3BDLR_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P3BDLR_p3bdlr_START (0)
#define SOC_ASP_HDMI_ASP_P3BDLR_p3bdlr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spdifsel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_HDMI_ASP_SPDIFSEL_UNION;
#endif
#define SOC_ASP_HDMI_ASP_SPDIFSEL_spdifsel_START (0)
#define SOC_ASP_HDMI_ASP_SPDIFSEL_spdifsel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3adls : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ASP_HDMI_ASP_P3ADLS_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P3ADLS_p3adls_START (0)
#define SOC_ASP_HDMI_ASP_P3ADLS_p3adls_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3bdls : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ASP_HDMI_ASP_P3BDLS_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P3BDLS_p3bdls_START (0)
#define SOC_ASP_HDMI_ASP_P3BDLS_p3bdls_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcm3_fds : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ASP_HDMI_ASP_FDS_UNION;
#endif
#define SOC_ASP_HDMI_ASP_FDS_pcm3_fds_START (0)
#define SOC_ASP_HDMI_ASP_FDS_pcm3_fds_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3adl : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ASP_HDMI_ASP_P3ADL_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P3ADL_p3adl_START (0)
#define SOC_ASP_HDMI_ASP_P3ADL_p3adl_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p3bdl : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ASP_HDMI_ASP_P3BDL_UNION;
#endif
#define SOC_ASP_HDMI_ASP_P3BDL_p3bdl_START (0)
#define SOC_ASP_HDMI_ASP_P3BDL_p3bdl_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int asp_secure_en_n : 1;
        unsigned int asp_addr_secure_en_n : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ASP_HDMI_ASP_SECURE_UNION;
#endif
#define SOC_ASP_HDMI_ASP_SECURE_asp_secure_en_n_START (0)
#define SOC_ASP_HDMI_ASP_SECURE_asp_secure_en_n_END (0)
#define SOC_ASP_HDMI_ASP_SECURE_asp_addr_secure_en_n_START (1)
#define SOC_ASP_HDMI_ASP_SECURE_asp_addr_secure_en_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int access_ctrl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_HDMI_SIO1_ASPIF_SEL_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_ASPIF_SEL_access_ctrl_START (0)
#define SOC_ASP_HDMI_SIO1_ASPIF_SEL_access_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int tx_int : 1;
        unsigned int reserved_1: 30;
    } reg;
} SOC_ASP_HDMI_SIO1_RAW_INT_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_RAW_INT_tx_int_START (1)
#define SOC_ASP_HDMI_SIO1_RAW_INT_tx_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int tx_int_clr : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_ASP_HDMI_SIO1_INT_CLR_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_INT_CLR_tx_int_clr_START (1)
#define SOC_ASP_HDMI_SIO1_INT_CLR_tx_int_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int tx_int_enable : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_ASP_HDMI_SIO1_INT_ENABLE_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_INT_ENABLE_tx_int_enable_START (1)
#define SOC_ASP_HDMI_SIO1_INT_ENABLE_tx_int_enable_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int tx_int_mask : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_ASP_HDMI_SIO1_INT_MASKED_STATUS_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_INT_MASKED_STATUS_tx_int_mask_START (1)
#define SOC_ASP_HDMI_SIO1_INT_MASKED_STATUS_tx_int_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int tx_ws_sel : 1;
        unsigned int tx_clk_sel : 1;
        unsigned int tx_fifo_threshold : 5;
        unsigned int reserved_1 : 5;
        unsigned int tx_fifo_disable : 1;
        unsigned int reserved_2 : 1;
        unsigned int tx_enable : 1;
        unsigned int reserved_3 : 1;
        unsigned int dsp_mode : 1;
        unsigned int tx_rx_reset_n : 1;
        unsigned int reserved_4 : 12;
    } reg;
} SOC_ASP_HDMI_SIO1_I2S_SET_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_I2S_SET_tx_ws_sel_START (2)
#define SOC_ASP_HDMI_SIO1_I2S_SET_tx_ws_sel_END (2)
#define SOC_ASP_HDMI_SIO1_I2S_SET_tx_clk_sel_START (3)
#define SOC_ASP_HDMI_SIO1_I2S_SET_tx_clk_sel_END (3)
#define SOC_ASP_HDMI_SIO1_I2S_SET_tx_fifo_threshold_START (4)
#define SOC_ASP_HDMI_SIO1_I2S_SET_tx_fifo_threshold_END (8)
#define SOC_ASP_HDMI_SIO1_I2S_SET_tx_fifo_disable_START (14)
#define SOC_ASP_HDMI_SIO1_I2S_SET_tx_fifo_disable_END (14)
#define SOC_ASP_HDMI_SIO1_I2S_SET_tx_enable_START (16)
#define SOC_ASP_HDMI_SIO1_I2S_SET_tx_enable_END (16)
#define SOC_ASP_HDMI_SIO1_I2S_SET_dsp_mode_START (18)
#define SOC_ASP_HDMI_SIO1_I2S_SET_dsp_mode_END (18)
#define SOC_ASP_HDMI_SIO1_I2S_SET_tx_rx_reset_n_START (19)
#define SOC_ASP_HDMI_SIO1_I2S_SET_tx_rx_reset_n_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int tx_ws_sel_clr : 1;
        unsigned int tx_clk_sel_clr : 1;
        unsigned int tx_fifo_threshold_clr : 5;
        unsigned int reserved_1 : 5;
        unsigned int tx_fifo_disable_clr : 1;
        unsigned int reserved_2 : 1;
        unsigned int tx_enable_clr : 1;
        unsigned int reserved_3 : 1;
        unsigned int dsp_mode_clr : 1;
        unsigned int tx_rx_reset_n_clr : 1;
        unsigned int reserved_4 : 12;
    } reg;
} SOC_ASP_HDMI_SIO1_I2S_CLR_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_I2S_CLR_tx_ws_sel_clr_START (2)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_tx_ws_sel_clr_END (2)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_tx_clk_sel_clr_START (3)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_tx_clk_sel_clr_END (3)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_tx_fifo_threshold_clr_START (4)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_tx_fifo_threshold_clr_END (8)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_tx_fifo_disable_clr_START (14)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_tx_fifo_disable_clr_END (14)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_tx_enable_clr_START (16)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_tx_enable_clr_END (16)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_dsp_mode_clr_START (18)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_dsp_mode_clr_END (18)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_tx_rx_reset_n_clr_START (19)
#define SOC_ASP_HDMI_SIO1_I2S_CLR_tx_rx_reset_n_clr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tx_rfifo_over : 1;
        unsigned int tx_lfifo_over : 1;
        unsigned int tx_rfifo_depth : 6;
        unsigned int tx_lfifo_depth : 6;
        unsigned int reserved : 18;
    } reg;
} SOC_ASP_HDMI_SIO1_TX_STA_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_TX_STA_tx_rfifo_over_START (0)
#define SOC_ASP_HDMI_SIO1_TX_STA_tx_rfifo_over_END (0)
#define SOC_ASP_HDMI_SIO1_TX_STA_tx_lfifo_over_START (1)
#define SOC_ASP_HDMI_SIO1_TX_STA_tx_lfifo_over_END (1)
#define SOC_ASP_HDMI_SIO1_TX_STA_tx_rfifo_depth_START (2)
#define SOC_ASP_HDMI_SIO1_TX_STA_tx_rfifo_depth_END (7)
#define SOC_ASP_HDMI_SIO1_TX_STA_tx_lfifo_depth_START (8)
#define SOC_ASP_HDMI_SIO1_TX_STA_tx_lfifo_depth_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tx_clr : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 30;
    } reg;
} SOC_ASP_HDMI_SIO1_CLR_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_CLR_tx_clr_START (0)
#define SOC_ASP_HDMI_SIO1_CLR_tx_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int validity_ch0 : 1;
        unsigned int validity_ch1 : 1;
        unsigned int validity_ch2 : 1;
        unsigned int validity_ch3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ASP_HDMI_SIO_CH_DATA_VLD_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH_DATA_VLD_validity_ch0_START (0)
#define SOC_ASP_HDMI_SIO_CH_DATA_VLD_validity_ch0_END (0)
#define SOC_ASP_HDMI_SIO_CH_DATA_VLD_validity_ch1_START (1)
#define SOC_ASP_HDMI_SIO_CH_DATA_VLD_validity_ch1_END (1)
#define SOC_ASP_HDMI_SIO_CH_DATA_VLD_validity_ch2_START (2)
#define SOC_ASP_HDMI_SIO_CH_DATA_VLD_validity_ch2_END (2)
#define SOC_ASP_HDMI_SIO_CH_DATA_VLD_validity_ch3_START (3)
#define SOC_ASP_HDMI_SIO_CH_DATA_VLD_validity_ch3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch0_l_0 : 1;
        unsigned int status1_ch0_l_1 : 1;
        unsigned int status1_ch0_l_2 : 1;
        unsigned int status1_ch0_l_3 : 3;
        unsigned int status1_ch0_l_4 : 2;
        unsigned int status1_ch0_l_5 : 8;
        unsigned int status1_ch0_l_6 : 4;
        unsigned int status1_ch0_l_7 : 4;
        unsigned int status1_ch0_l_8 : 4;
        unsigned int status1_ch0_l_9 : 2;
        unsigned int status1_ch0_l_10 : 2;
    } reg;
} SOC_ASP_HDMI_SIO_CH0_STATUS1_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_0_START (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_0_END (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_1_START (1)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_1_END (1)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_2_START (2)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_2_END (2)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_3_START (3)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_3_END (5)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_4_START (6)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_4_END (7)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_5_START (8)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_5_END (15)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_6_START (16)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_6_END (19)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_7_START (20)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_7_END (23)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_8_START (24)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_8_END (27)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_9_START (28)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_9_END (29)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_10_START (30)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_L_status1_ch0_l_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch0_l_0 : 1;
        unsigned int status2_ch0_l_1 : 3;
        unsigned int status2_ch0_l_2 : 4;
        unsigned int status2_ch0_l_3 : 2;
        unsigned int status2_ch0_l_4 : 22;
    } reg;
} SOC_ASP_HDMI_SIO_CH0_STATUS2_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_L_status2_ch0_l_0_START (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_L_status2_ch0_l_0_END (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_L_status2_ch0_l_1_START (1)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_L_status2_ch0_l_1_END (3)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_L_status2_ch0_l_2_START (4)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_L_status2_ch0_l_2_END (7)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_L_status2_ch0_l_3_START (8)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_L_status2_ch0_l_3_END (9)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_L_status2_ch0_l_4_START (10)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_L_status2_ch0_l_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch0_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH0_STATUS3_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH0_STATUS3_L_status3_ch0_l_START (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS3_L_status3_ch0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch0_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH0_STATUS4_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH0_STATUS4_L_status4_ch0_l_START (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS4_L_status4_ch0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch0_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH0_STATUS5_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH0_STATUS5_L_status5_ch0_l_START (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS5_L_status5_ch0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch0_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH0_STATUS6_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH0_STATUS6_L_status6_ch0_l_START (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS6_L_status6_ch0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data1_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER0_DATA1_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER0_DATA1_L_user0_data1_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER0_DATA1_L_user0_data1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data2_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER0_DATA2_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER0_DATA2_L_user0_data2_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER0_DATA2_L_user0_data2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data3_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER0_DATA3_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER0_DATA3_L_user0_data3_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER0_DATA3_L_user0_data3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data4_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER0_DATA4_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER0_DATA4_L_user0_data4_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER0_DATA4_L_user0_data4_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data5_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER0_DATA5_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER0_DATA5_L_user0_data5_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER0_DATA5_L_user0_data5_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data6_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER0_DATA6_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER0_DATA6_L_user0_data6_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER0_DATA6_L_user0_data6_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch0_r_0 : 1;
        unsigned int status1_ch0_r_1 : 1;
        unsigned int status1_ch0_r_2 : 1;
        unsigned int status1_ch0_r_3 : 3;
        unsigned int status1_ch0_r_4 : 2;
        unsigned int status1_ch0_r_5 : 8;
        unsigned int status1_ch0_r_6 : 4;
        unsigned int status1_ch0_r_7 : 4;
        unsigned int status1_ch0_r_8 : 4;
        unsigned int status1_ch0_r_9 : 2;
        unsigned int status1_ch0_r_10 : 2;
    } reg;
} SOC_ASP_HDMI_SIO_CH0_STATUS1_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_0_START (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_0_END (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_1_START (1)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_1_END (1)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_2_START (2)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_2_END (2)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_3_START (3)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_3_END (5)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_4_START (6)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_4_END (7)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_5_START (8)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_5_END (15)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_6_START (16)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_6_END (19)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_7_START (20)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_7_END (23)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_8_START (24)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_8_END (27)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_9_START (28)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_9_END (29)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_10_START (30)
#define SOC_ASP_HDMI_SIO_CH0_STATUS1_R_status1_ch0_r_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch0_r_0 : 1;
        unsigned int status2_ch0_r_1 : 3;
        unsigned int status2_ch0_r_2 : 4;
        unsigned int status2_ch0_r_3 : 2;
        unsigned int status2_ch0_r_4 : 22;
    } reg;
} SOC_ASP_HDMI_SIO_CH0_STATUS2_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_R_status2_ch0_r_0_START (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_R_status2_ch0_r_0_END (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_R_status2_ch0_r_1_START (1)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_R_status2_ch0_r_1_END (3)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_R_status2_ch0_r_2_START (4)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_R_status2_ch0_r_2_END (7)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_R_status2_ch0_r_3_START (8)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_R_status2_ch0_r_3_END (9)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_R_status2_ch0_r_4_START (10)
#define SOC_ASP_HDMI_SIO_CH0_STATUS2_R_status2_ch0_r_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch0_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH0_STATUS3_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH0_STATUS3_R_status3_ch0_r_START (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS3_R_status3_ch0_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch0_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH0_STATUS4_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH0_STATUS4_R_status4_ch0_r_START (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS4_R_status4_ch0_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch0_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH0_STATUS5_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH0_STATUS5_R_status5_ch0_r_START (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS5_R_status5_ch0_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch0_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH0_STATUS6_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH0_STATUS6_R_status6_ch0_r_START (0)
#define SOC_ASP_HDMI_SIO_CH0_STATUS6_R_status6_ch0_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data1_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER0_DATA1_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER0_DATA1_R_user0_data1_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER0_DATA1_R_user0_data1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data2_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER0_DATA2_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER0_DATA2_R_user0_data2_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER0_DATA2_R_user0_data2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data3_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER0_DATA3_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER0_DATA3_R_user0_data3_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER0_DATA3_R_user0_data3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data4_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER0_DATA4_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER0_DATA4_R_user0_data4_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER0_DATA4_R_user0_data4_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data5_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER0_DATA5_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER0_DATA5_R_user0_data5_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER0_DATA5_R_user0_data5_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data6_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER0_DATA6_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER0_DATA6_R_user0_data6_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER0_DATA6_R_user0_data6_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch1_l_0 : 1;
        unsigned int status1_ch1_l_1 : 1;
        unsigned int status1_ch1_l_2 : 1;
        unsigned int status1_ch1_l_3 : 3;
        unsigned int status1_ch1_l_4 : 2;
        unsigned int status1_ch1_l_5 : 8;
        unsigned int status1_ch1_l_6 : 4;
        unsigned int status1_ch1_l_7 : 4;
        unsigned int status1_ch1_l_8 : 4;
        unsigned int status1_ch1_l_9 : 2;
        unsigned int status1_ch1_l_10 : 2;
    } reg;
} SOC_ASP_HDMI_SIO_CH1_STATUS1_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_0_START (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_0_END (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_1_START (1)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_1_END (1)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_2_START (2)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_2_END (2)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_3_START (3)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_3_END (5)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_4_START (6)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_4_END (7)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_5_START (8)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_5_END (15)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_6_START (16)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_6_END (19)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_7_START (20)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_7_END (23)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_8_START (24)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_8_END (27)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_9_START (28)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_9_END (29)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_10_START (30)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_L_status1_ch1_l_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch1_l_0 : 1;
        unsigned int status2_ch1_l_1 : 3;
        unsigned int status2_ch1_l_2 : 4;
        unsigned int status2_ch1_l_3 : 2;
        unsigned int status2_ch1_l_4 : 22;
    } reg;
} SOC_ASP_HDMI_SIO_CH1_STATUS2_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_L_status2_ch1_l_0_START (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_L_status2_ch1_l_0_END (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_L_status2_ch1_l_1_START (1)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_L_status2_ch1_l_1_END (3)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_L_status2_ch1_l_2_START (4)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_L_status2_ch1_l_2_END (7)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_L_status2_ch1_l_3_START (8)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_L_status2_ch1_l_3_END (9)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_L_status2_ch1_l_4_START (10)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_L_status2_ch1_l_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch1_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH1_STATUS3_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH1_STATUS3_L_status3_ch1_l_START (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS3_L_status3_ch1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch1_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH1_STATUS4_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH1_STATUS4_L_status4_ch1_l_START (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS4_L_status4_ch1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch1_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH1_STATUS5_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH1_STATUS5_L_status5_ch1_l_START (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS5_L_status5_ch1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch1_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH1_STATUS6_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH1_STATUS6_L_status6_ch1_l_START (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS6_L_status6_ch1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data1_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER1_DATA1_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER1_DATA1_L_user1_data1_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER1_DATA1_L_user1_data1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data2_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER1_DATA2_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER1_DATA2_L_user1_data2_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER1_DATA2_L_user1_data2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data3_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER1_DATA3_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER1_DATA3_L_user1_data3_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER1_DATA3_L_user1_data3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data4_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER1_DATA4_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER1_DATA4_L_user1_data4_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER1_DATA4_L_user1_data4_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data5_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER1_DATA5_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER1_DATA5_L_user1_data5_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER1_DATA5_L_user1_data5_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data6_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER1_DATA6_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER1_DATA6_L_user1_data6_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER1_DATA6_L_user1_data6_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch1_r_0 : 1;
        unsigned int status1_ch1_r_1 : 1;
        unsigned int status1_ch1_r_2 : 1;
        unsigned int status1_ch1_r_3 : 3;
        unsigned int status1_ch1_r_4 : 2;
        unsigned int status1_ch1_r_5 : 8;
        unsigned int status1_ch1_r_6 : 4;
        unsigned int status1_ch1_r_7 : 4;
        unsigned int status1_ch1_r_8 : 4;
        unsigned int status1_ch1_r_9 : 2;
        unsigned int status1_ch1_r_10 : 2;
    } reg;
} SOC_ASP_HDMI_SIO_CH1_STATUS1_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_0_START (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_0_END (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_1_START (1)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_1_END (1)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_2_START (2)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_2_END (2)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_3_START (3)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_3_END (5)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_4_START (6)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_4_END (7)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_5_START (8)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_5_END (15)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_6_START (16)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_6_END (19)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_7_START (20)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_7_END (23)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_8_START (24)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_8_END (27)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_9_START (28)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_9_END (29)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_10_START (30)
#define SOC_ASP_HDMI_SIO_CH1_STATUS1_R_status1_ch1_r_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch1_r_0 : 1;
        unsigned int status2_ch1_r_1 : 3;
        unsigned int status2_ch1_r_2 : 4;
        unsigned int status2_ch1_r_3 : 2;
        unsigned int status2_ch1_r_4 : 22;
    } reg;
} SOC_ASP_HDMI_SIO_CH1_STATUS2_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_R_status2_ch1_r_0_START (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_R_status2_ch1_r_0_END (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_R_status2_ch1_r_1_START (1)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_R_status2_ch1_r_1_END (3)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_R_status2_ch1_r_2_START (4)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_R_status2_ch1_r_2_END (7)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_R_status2_ch1_r_3_START (8)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_R_status2_ch1_r_3_END (9)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_R_status2_ch1_r_4_START (10)
#define SOC_ASP_HDMI_SIO_CH1_STATUS2_R_status2_ch1_r_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch1_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH1_STATUS3_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH1_STATUS3_R_status3_ch1_r_START (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS3_R_status3_ch1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch1_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH1_STATUS4_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH1_STATUS4_R_status4_ch1_r_START (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS4_R_status4_ch1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch1_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH1_STATUS5_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH1_STATUS5_R_status5_ch1_r_START (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS5_R_status5_ch1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch1_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH1_STATUS6_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH1_STATUS6_R_status6_ch1_r_START (0)
#define SOC_ASP_HDMI_SIO_CH1_STATUS6_R_status6_ch1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data1_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER1_DATA1_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER1_DATA1_R_user1_data1_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER1_DATA1_R_user1_data1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data2_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER1_DATA2_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER1_DATA2_R_user1_data2_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER1_DATA2_R_user1_data2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data3_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER1_DATA3_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER1_DATA3_R_user1_data3_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER1_DATA3_R_user1_data3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data4_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER1_DATA4_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER1_DATA4_R_user1_data4_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER1_DATA4_R_user1_data4_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data5_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER1_DATA5_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER1_DATA5_R_user1_data5_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER1_DATA5_R_user1_data5_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data6_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER1_DATA6_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER1_DATA6_R_user1_data6_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER1_DATA6_R_user1_data6_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch2_l_0 : 1;
        unsigned int status1_ch2_l_1 : 1;
        unsigned int status1_ch2_l_2 : 1;
        unsigned int status1_ch2_l_3 : 3;
        unsigned int status1_ch2_l_4 : 2;
        unsigned int status1_ch2_l_5 : 8;
        unsigned int status1_ch2_l_6 : 4;
        unsigned int status1_ch2_l_7 : 4;
        unsigned int status1_ch2_l_8 : 4;
        unsigned int status1_ch2_l_9 : 2;
        unsigned int status1_ch2_l_10 : 2;
    } reg;
} SOC_ASP_HDMI_SIO_CH2_STATUS1_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_0_START (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_0_END (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_1_START (1)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_1_END (1)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_2_START (2)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_2_END (2)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_3_START (3)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_3_END (5)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_4_START (6)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_4_END (7)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_5_START (8)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_5_END (15)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_6_START (16)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_6_END (19)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_7_START (20)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_7_END (23)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_8_START (24)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_8_END (27)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_9_START (28)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_9_END (29)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_10_START (30)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_L_status1_ch2_l_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch2_l_0 : 1;
        unsigned int status2_ch2_l_1 : 3;
        unsigned int status2_ch2_l_2 : 4;
        unsigned int status2_ch2_l_3 : 2;
        unsigned int status2_ch2_l_4 : 22;
    } reg;
} SOC_ASP_HDMI_SIO_CH2_STATUS2_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_L_status2_ch2_l_0_START (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_L_status2_ch2_l_0_END (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_L_status2_ch2_l_1_START (1)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_L_status2_ch2_l_1_END (3)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_L_status2_ch2_l_2_START (4)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_L_status2_ch2_l_2_END (7)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_L_status2_ch2_l_3_START (8)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_L_status2_ch2_l_3_END (9)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_L_status2_ch2_l_4_START (10)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_L_status2_ch2_l_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch2_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH2_STATUS3_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH2_STATUS3_L_status3_ch2_l_START (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS3_L_status3_ch2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch2_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH2_STATUS4_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH2_STATUS4_L_status4_ch2_l_START (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS4_L_status4_ch2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch2_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH2_STATUS5_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH2_STATUS5_L_status5_ch2_l_START (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS5_L_status5_ch2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch2_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH2_STATUS6_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH2_STATUS6_L_status6_ch2_l_START (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS6_L_status6_ch2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data1_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER2_DATA1_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER2_DATA1_L_user2_data1_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER2_DATA1_L_user2_data1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data2_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER2_DATA2_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER2_DATA2_L_user2_data2_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER2_DATA2_L_user2_data2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data3_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER2_DATA3_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER2_DATA3_L_user2_data3_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER2_DATA3_L_user2_data3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data4_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER2_DATA4_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER2_DATA4_L_user2_data4_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER2_DATA4_L_user2_data4_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data5_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER2_DATA5_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER2_DATA5_L_user2_data5_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER2_DATA5_L_user2_data5_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data6_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER2_DATA6_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER2_DATA6_L_user2_data6_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER2_DATA6_L_user2_data6_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch2_r_0 : 1;
        unsigned int status1_ch2_r_1 : 1;
        unsigned int status1_ch2_r_2 : 1;
        unsigned int status1_ch2_r_3 : 3;
        unsigned int status1_ch2_r_4 : 2;
        unsigned int status1_ch2_r_5 : 8;
        unsigned int status1_ch2_r_6 : 4;
        unsigned int status1_ch2_r_7 : 4;
        unsigned int status1_ch2_r_8 : 4;
        unsigned int status1_ch2_r_9 : 2;
        unsigned int status1_ch2_r_10 : 2;
    } reg;
} SOC_ASP_HDMI_SIO_CH2_STATUS1_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_0_START (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_0_END (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_1_START (1)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_1_END (1)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_2_START (2)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_2_END (2)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_3_START (3)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_3_END (5)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_4_START (6)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_4_END (7)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_5_START (8)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_5_END (15)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_6_START (16)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_6_END (19)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_7_START (20)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_7_END (23)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_8_START (24)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_8_END (27)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_9_START (28)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_9_END (29)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_10_START (30)
#define SOC_ASP_HDMI_SIO_CH2_STATUS1_R_status1_ch2_r_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch2_r_0 : 1;
        unsigned int status2_ch2_r_1 : 3;
        unsigned int status2_ch2_r_2 : 4;
        unsigned int status2_ch2_r_3 : 2;
        unsigned int status2_ch2_r_4 : 22;
    } reg;
} SOC_ASP_HDMI_SIO_CH2_STATUS2_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_R_status2_ch2_r_0_START (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_R_status2_ch2_r_0_END (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_R_status2_ch2_r_1_START (1)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_R_status2_ch2_r_1_END (3)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_R_status2_ch2_r_2_START (4)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_R_status2_ch2_r_2_END (7)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_R_status2_ch2_r_3_START (8)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_R_status2_ch2_r_3_END (9)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_R_status2_ch2_r_4_START (10)
#define SOC_ASP_HDMI_SIO_CH2_STATUS2_R_status2_ch2_r_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch2_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH2_STATUS3_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH2_STATUS3_R_status3_ch2_r_START (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS3_R_status3_ch2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch2_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH2_STATUS4_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH2_STATUS4_R_status4_ch2_r_START (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS4_R_status4_ch2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch2_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH2_STATUS5_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH2_STATUS5_R_status5_ch2_r_START (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS5_R_status5_ch2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch2_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH2_STATUS6_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH2_STATUS6_R_status6_ch2_r_START (0)
#define SOC_ASP_HDMI_SIO_CH2_STATUS6_R_status6_ch2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data1_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER2_DATA1_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER2_DATA1_R_user2_data1_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER2_DATA1_R_user2_data1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data2_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER2_DATA2_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER2_DATA2_R_user2_data2_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER2_DATA2_R_user2_data2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data3_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER2_DATA3_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER2_DATA3_R_user2_data3_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER2_DATA3_R_user2_data3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data4_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER2_DATA4_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER2_DATA4_R_user2_data4_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER2_DATA4_R_user2_data4_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data5_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER2_DATA5_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER2_DATA5_R_user2_data5_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER2_DATA5_R_user2_data5_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data6_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER2_DATA6_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER2_DATA6_R_user2_data6_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER2_DATA6_R_user2_data6_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch3_l_0 : 1;
        unsigned int status1_ch3_l_1 : 1;
        unsigned int status1_ch3_l_2 : 1;
        unsigned int status1_ch3_l_3 : 3;
        unsigned int status1_ch3_l_4 : 2;
        unsigned int status1_ch3_l_5 : 8;
        unsigned int status1_ch3_l_6 : 4;
        unsigned int status1_ch3_l_7 : 4;
        unsigned int status1_ch3_l_8 : 4;
        unsigned int status1_ch3_l_9 : 2;
        unsigned int status1_ch3_l_10 : 2;
    } reg;
} SOC_ASP_HDMI_SIO_CH3_STATUS1_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_0_START (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_0_END (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_1_START (1)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_1_END (1)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_2_START (2)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_2_END (2)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_3_START (3)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_3_END (5)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_4_START (6)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_4_END (7)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_5_START (8)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_5_END (15)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_6_START (16)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_6_END (19)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_7_START (20)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_7_END (23)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_8_START (24)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_8_END (27)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_9_START (28)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_9_END (29)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_10_START (30)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_L_status1_ch3_l_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch3_l_0 : 1;
        unsigned int status2_ch3_l_1 : 3;
        unsigned int status2_ch3_l_2 : 4;
        unsigned int status2_ch3_l_3 : 2;
        unsigned int status2_ch3_l_4 : 22;
    } reg;
} SOC_ASP_HDMI_SIO_CH3_STATUS2_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_L_status2_ch3_l_0_START (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_L_status2_ch3_l_0_END (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_L_status2_ch3_l_1_START (1)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_L_status2_ch3_l_1_END (3)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_L_status2_ch3_l_2_START (4)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_L_status2_ch3_l_2_END (7)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_L_status2_ch3_l_3_START (8)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_L_status2_ch3_l_3_END (9)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_L_status2_ch3_l_4_START (10)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_L_status2_ch3_l_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch3_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH3_STATUS3_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH3_STATUS3_L_status3_ch3_l_START (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS3_L_status3_ch3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch3_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH3_STATUS4_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH3_STATUS4_L_status4_ch3_l_START (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS4_L_status4_ch3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch3_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH3_STATUS5_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH3_STATUS5_L_status5_ch3_l_START (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS5_L_status5_ch3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch3_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH3_STATUS6_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH3_STATUS6_L_status6_ch3_l_START (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS6_L_status6_ch3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data1_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER3_DATA1_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER3_DATA1_L_user3_data1_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER3_DATA1_L_user3_data1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data2_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER3_DATA2_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER3_DATA2_L_user3_data2_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER3_DATA2_L_user3_data2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data3_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER3_DATA3_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER3_DATA3_L_user3_data3_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER3_DATA3_L_user3_data3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data4_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER3_DATA4_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER3_DATA4_L_user3_data4_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER3_DATA4_L_user3_data4_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data5_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER3_DATA5_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER3_DATA5_L_user3_data5_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER3_DATA5_L_user3_data5_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data6_l : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER3_DATA6_L_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER3_DATA6_L_user3_data6_l_START (0)
#define SOC_ASP_HDMI_SIO1_USER3_DATA6_L_user3_data6_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch3_r_0 : 1;
        unsigned int status1_ch3_r_1 : 1;
        unsigned int status1_ch3_r_2 : 1;
        unsigned int status1_ch3_r_3 : 3;
        unsigned int status1_ch3_r_4 : 2;
        unsigned int status1_ch3_r_5 : 8;
        unsigned int status1_ch3_r_6 : 4;
        unsigned int status1_ch3_r_7 : 4;
        unsigned int status1_ch3_r_8 : 4;
        unsigned int status1_ch3_r_9 : 2;
        unsigned int status1_ch3_r_10 : 2;
    } reg;
} SOC_ASP_HDMI_SIO_CH3_STATUS1_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_0_START (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_0_END (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_1_START (1)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_1_END (1)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_2_START (2)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_2_END (2)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_3_START (3)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_3_END (5)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_4_START (6)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_4_END (7)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_5_START (8)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_5_END (15)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_6_START (16)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_6_END (19)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_7_START (20)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_7_END (23)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_8_START (24)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_8_END (27)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_9_START (28)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_9_END (29)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_10_START (30)
#define SOC_ASP_HDMI_SIO_CH3_STATUS1_R_status1_ch3_r_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch3_r_0 : 1;
        unsigned int status2_ch3_r_1 : 3;
        unsigned int status2_ch3_r_2 : 4;
        unsigned int status2_ch3_r_3 : 2;
        unsigned int status2_ch3_r_4 : 22;
    } reg;
} SOC_ASP_HDMI_SIO_CH3_STATUS2_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_R_status2_ch3_r_0_START (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_R_status2_ch3_r_0_END (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_R_status2_ch3_r_1_START (1)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_R_status2_ch3_r_1_END (3)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_R_status2_ch3_r_2_START (4)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_R_status2_ch3_r_2_END (7)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_R_status2_ch3_r_3_START (8)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_R_status2_ch3_r_3_END (9)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_R_status2_ch3_r_4_START (10)
#define SOC_ASP_HDMI_SIO_CH3_STATUS2_R_status2_ch3_r_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch3_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH3_STATUS3_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH3_STATUS3_R_status3_ch3_r_START (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS3_R_status3_ch3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch3_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH3_STATUS4_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH3_STATUS4_R_status4_ch3_r_START (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS4_R_status4_ch3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch3_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH3_STATUS5_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH3_STATUS5_R_status5_ch3_r_START (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS5_R_status5_ch3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch3_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO_CH3_STATUS6_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO_CH3_STATUS6_R_status6_ch3_r_START (0)
#define SOC_ASP_HDMI_SIO_CH3_STATUS6_R_status6_ch3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data1_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER3_DATA1_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER3_DATA1_R_user3_data1_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER3_DATA1_R_user3_data1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data2_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER3_DATA2_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER3_DATA2_R_user3_data2_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER3_DATA2_R_user3_data2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data3_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER3_DATA3_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER3_DATA3_R_user3_data3_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER3_DATA3_R_user3_data3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data4_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER3_DATA4_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER3_DATA4_R_user3_data4_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER3_DATA4_R_user3_data4_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data5_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER3_DATA5_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER3_DATA5_R_user3_data5_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER3_DATA5_R_user3_data5_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data6_r : 32;
    } reg;
} SOC_ASP_HDMI_SIO1_USER3_DATA6_R_UNION;
#endif
#define SOC_ASP_HDMI_SIO1_USER3_DATA6_R_user3_data6_r_START (0)
#define SOC_ASP_HDMI_SIO1_USER3_DATA6_R_user3_data6_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spdif_en : 1;
        unsigned int afifo_wlevel : 3;
        unsigned int intr_en : 1;
        unsigned int dma_en : 1;
        unsigned int spdif_ch0_en : 1;
        unsigned int spdif_ch1_en : 1;
        unsigned int spdif_ch2_en : 1;
        unsigned int spdif_ch3_en : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_ASP_HDMI_SPDIF_CTRL_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CTRL_spdif_en_START (0)
#define SOC_ASP_HDMI_SPDIF_CTRL_spdif_en_END (0)
#define SOC_ASP_HDMI_SPDIF_CTRL_afifo_wlevel_START (1)
#define SOC_ASP_HDMI_SPDIF_CTRL_afifo_wlevel_END (3)
#define SOC_ASP_HDMI_SPDIF_CTRL_intr_en_START (4)
#define SOC_ASP_HDMI_SPDIF_CTRL_intr_en_END (4)
#define SOC_ASP_HDMI_SPDIF_CTRL_dma_en_START (5)
#define SOC_ASP_HDMI_SPDIF_CTRL_dma_en_END (5)
#define SOC_ASP_HDMI_SPDIF_CTRL_spdif_ch0_en_START (6)
#define SOC_ASP_HDMI_SPDIF_CTRL_spdif_ch0_en_END (6)
#define SOC_ASP_HDMI_SPDIF_CTRL_spdif_ch1_en_START (7)
#define SOC_ASP_HDMI_SPDIF_CTRL_spdif_ch1_en_END (7)
#define SOC_ASP_HDMI_SPDIF_CTRL_spdif_ch2_en_START (8)
#define SOC_ASP_HDMI_SPDIF_CTRL_spdif_ch2_en_END (8)
#define SOC_ASP_HDMI_SPDIF_CTRL_spdif_ch3_en_START (9)
#define SOC_ASP_HDMI_SPDIF_CTRL_spdif_ch3_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int validity_info_ch0 : 1;
        unsigned int validity_info_ch1 : 1;
        unsigned int validity_info_ch2 : 1;
        unsigned int validity_info_ch3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ASP_HDMI_SPDIF_CONFIG_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CONFIG_validity_info_ch0_START (0)
#define SOC_ASP_HDMI_SPDIF_CONFIG_validity_info_ch0_END (0)
#define SOC_ASP_HDMI_SPDIF_CONFIG_validity_info_ch1_START (1)
#define SOC_ASP_HDMI_SPDIF_CONFIG_validity_info_ch1_END (1)
#define SOC_ASP_HDMI_SPDIF_CONFIG_validity_info_ch2_START (2)
#define SOC_ASP_HDMI_SPDIF_CONFIG_validity_info_ch2_END (2)
#define SOC_ASP_HDMI_SPDIF_CONFIG_validity_info_ch3_START (3)
#define SOC_ASP_HDMI_SPDIF_CONFIG_validity_info_ch3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afifo_empty_intr : 1;
        unsigned int afifo_single_intr : 1;
        unsigned int dma_burstintr : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ASP_HDMI_SPDIF_INTRUPT_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_INTRUPT_afifo_empty_intr_START (0)
#define SOC_ASP_HDMI_SPDIF_INTRUPT_afifo_empty_intr_END (0)
#define SOC_ASP_HDMI_SPDIF_INTRUPT_afifo_single_intr_START (1)
#define SOC_ASP_HDMI_SPDIF_INTRUPT_afifo_single_intr_END (1)
#define SOC_ASP_HDMI_SPDIF_INTRUPT_dma_burstintr_START (2)
#define SOC_ASP_HDMI_SPDIF_INTRUPT_dma_burstintr_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afifo_empty_intr_mask : 1;
        unsigned int afifo_single_intr_mask : 1;
        unsigned int dma_burstintr_mask : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ASP_HDMI_SPDIF_INTR_MASK_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_INTR_MASK_afifo_empty_intr_mask_START (0)
#define SOC_ASP_HDMI_SPDIF_INTR_MASK_afifo_empty_intr_mask_END (0)
#define SOC_ASP_HDMI_SPDIF_INTR_MASK_afifo_single_intr_mask_START (1)
#define SOC_ASP_HDMI_SPDIF_INTR_MASK_afifo_single_intr_mask_END (1)
#define SOC_ASP_HDMI_SPDIF_INTR_MASK_dma_burstintr_mask_START (2)
#define SOC_ASP_HDMI_SPDIF_INTR_MASK_dma_burstintr_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afifo_empty_intr_state : 1;
        unsigned int afifo_single_intr_state : 1;
        unsigned int dma_burstintr_state : 1;
        unsigned int afifo_depth : 5;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_HDMI_SPDIF_FIFO_STATE_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_FIFO_STATE_afifo_empty_intr_state_START (0)
#define SOC_ASP_HDMI_SPDIF_FIFO_STATE_afifo_empty_intr_state_END (0)
#define SOC_ASP_HDMI_SPDIF_FIFO_STATE_afifo_single_intr_state_START (1)
#define SOC_ASP_HDMI_SPDIF_FIFO_STATE_afifo_single_intr_state_END (1)
#define SOC_ASP_HDMI_SPDIF_FIFO_STATE_dma_burstintr_state_START (2)
#define SOC_ASP_HDMI_SPDIF_FIFO_STATE_dma_burstintr_state_END (2)
#define SOC_ASP_HDMI_SPDIF_FIFO_STATE_afifo_depth_START (3)
#define SOC_ASP_HDMI_SPDIF_FIFO_STATE_afifo_depth_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch0_l_0 : 1;
        unsigned int status1_ch0_l_1 : 1;
        unsigned int status1_ch0_l_2 : 1;
        unsigned int status1_ch0_l_3 : 3;
        unsigned int status1_ch0_l_4 : 2;
        unsigned int status1_ch0_l_5 : 8;
        unsigned int status1_ch0_l_6 : 4;
        unsigned int status1_ch0_l_7 : 4;
        unsigned int status1_ch0_l_8 : 4;
        unsigned int status1_ch0_l_9 : 2;
        unsigned int status1_ch0_l_10 : 2;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_1_END (1)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_2_START (2)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_2_END (2)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_3_START (3)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_3_END (5)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_4_START (6)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_4_END (7)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_5_START (8)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_5_END (15)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_6_START (16)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_6_END (19)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_7_START (20)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_7_END (23)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_8_START (24)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_8_END (27)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_9_START (28)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_9_END (29)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_10_START (30)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_L_status1_ch0_l_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch0_l_0 : 1;
        unsigned int status2_ch0_l_1 : 3;
        unsigned int status2_ch0_l_2 : 4;
        unsigned int status2_ch0_l_3 : 2;
        unsigned int status2_ch0_l_4 : 22;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH0_STATUS2_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_L_status2_ch0_l_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_L_status2_ch0_l_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_L_status2_ch0_l_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_L_status2_ch0_l_1_END (3)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_L_status2_ch0_l_2_START (4)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_L_status2_ch0_l_2_END (7)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_L_status2_ch0_l_3_START (8)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_L_status2_ch0_l_3_END (9)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_L_status2_ch0_l_4_START (10)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_L_status2_ch0_l_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch0_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH0_STATUS3_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS3_L_status3_ch0_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS3_L_status3_ch0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch0_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH0_STATUS4_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS4_L_status4_ch0_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS4_L_status4_ch0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch0_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH0_STATUS5_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS5_L_status5_ch0_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS5_L_status5_ch0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch0_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH0_STATUS6_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS6_L_status6_ch0_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS6_L_status6_ch0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data1_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER0_DATA1_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA1_L_user0_data1_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA1_L_user0_data1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data2_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER0_DATA2_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA2_L_user0_data2_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA2_L_user0_data2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data3_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER0_DATA3_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA3_L_user0_data3_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA3_L_user0_data3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data4_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER0_DATA4_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA4_L_user0_data4_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA4_L_user0_data4_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data5_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER0_DATA5_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA5_L_user0_data5_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA5_L_user0_data5_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data6_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER0_DATA6_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA6_L_user0_data6_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA6_L_user0_data6_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch0_r_0 : 1;
        unsigned int status1_ch0_r_1 : 1;
        unsigned int status1_ch0_r_2 : 1;
        unsigned int status1_ch0_r_3 : 3;
        unsigned int status1_ch0_r_4 : 2;
        unsigned int status1_ch0_r_5 : 8;
        unsigned int status1_ch0_r_6 : 4;
        unsigned int status1_ch0_r_7 : 4;
        unsigned int status1_ch0_r_8 : 4;
        unsigned int status1_ch0_r_9 : 2;
        unsigned int status1_ch0_r_10 : 2;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_1_END (1)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_2_START (2)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_2_END (2)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_3_START (3)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_3_END (5)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_4_START (6)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_4_END (7)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_5_START (8)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_5_END (15)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_6_START (16)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_6_END (19)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_7_START (20)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_7_END (23)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_8_START (24)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_8_END (27)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_9_START (28)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_9_END (29)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_10_START (30)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS1_R_status1_ch0_r_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch0_r_0 : 1;
        unsigned int status2_ch0_r_1 : 3;
        unsigned int status2_ch0_r_2 : 4;
        unsigned int status2_ch0_r_3 : 2;
        unsigned int status2_ch0_r_4 : 22;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH0_STATUS2_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_R_status2_ch0_r_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_R_status2_ch0_r_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_R_status2_ch0_r_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_R_status2_ch0_r_1_END (3)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_R_status2_ch0_r_2_START (4)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_R_status2_ch0_r_2_END (7)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_R_status2_ch0_r_3_START (8)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_R_status2_ch0_r_3_END (9)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_R_status2_ch0_r_4_START (10)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS2_R_status2_ch0_r_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch0_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH0_STATUS3_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS3_R_status3_ch0_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS3_R_status3_ch0_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch0_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH0_STATUS4_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS4_R_status4_ch0_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS4_R_status4_ch0_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch0_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH0_STATUS5_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS5_R_status5_ch0_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS5_R_status5_ch0_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch0_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH0_STATUS6_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS6_R_status6_ch0_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH0_STATUS6_R_status6_ch0_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data1_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER0_DATA1_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA1_R_user0_data1_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA1_R_user0_data1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data2_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER0_DATA2_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA2_R_user0_data2_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA2_R_user0_data2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data3_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER0_DATA3_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA3_R_user0_data3_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA3_R_user0_data3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data4_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER0_DATA4_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA4_R_user0_data4_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA4_R_user0_data4_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data5_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER0_DATA5_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA5_R_user0_data5_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA5_R_user0_data5_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user0_data6_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER0_DATA6_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA6_R_user0_data6_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER0_DATA6_R_user0_data6_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch1_l_0 : 1;
        unsigned int status1_ch1_l_1 : 1;
        unsigned int status1_ch1_l_2 : 1;
        unsigned int status1_ch1_l_3 : 3;
        unsigned int status1_ch1_l_4 : 2;
        unsigned int status1_ch1_l_5 : 8;
        unsigned int status1_ch1_l_6 : 4;
        unsigned int status1_ch1_l_7 : 4;
        unsigned int status1_ch1_l_8 : 4;
        unsigned int status1_ch1_l_9 : 2;
        unsigned int status1_ch1_l_10 : 2;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_1_END (1)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_2_START (2)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_2_END (2)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_3_START (3)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_3_END (5)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_4_START (6)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_4_END (7)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_5_START (8)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_5_END (15)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_6_START (16)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_6_END (19)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_7_START (20)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_7_END (23)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_8_START (24)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_8_END (27)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_9_START (28)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_9_END (29)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_10_START (30)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_L_status1_ch1_l_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch1_l_0 : 1;
        unsigned int status2_ch1_l_1 : 3;
        unsigned int status2_ch1_l_2 : 4;
        unsigned int status2_ch1_l_3 : 2;
        unsigned int status2_ch1_l_4 : 22;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH1_STATUS2_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_L_status2_ch1_l_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_L_status2_ch1_l_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_L_status2_ch1_l_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_L_status2_ch1_l_1_END (3)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_L_status2_ch1_l_2_START (4)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_L_status2_ch1_l_2_END (7)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_L_status2_ch1_l_3_START (8)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_L_status2_ch1_l_3_END (9)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_L_status2_ch1_l_4_START (10)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_L_status2_ch1_l_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch1_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH1_STATUS3_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS3_L_status3_ch1_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS3_L_status3_ch1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch1_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH1_STATUS4_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS4_L_status4_ch1_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS4_L_status4_ch1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch1_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH1_STATUS5_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS5_L_status5_ch1_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS5_L_status5_ch1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch1_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH1_STATUS6_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS6_L_status6_ch1_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS6_L_status6_ch1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data1_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER1_DATA1_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA1_L_user1_data1_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA1_L_user1_data1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data2_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER1_DATA2_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA2_L_user1_data2_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA2_L_user1_data2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data3_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER1_DATA3_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA3_L_user1_data3_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA3_L_user1_data3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data4_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER1_DATA4_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA4_L_user1_data4_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA4_L_user1_data4_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data5_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER1_DATA5_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA5_L_user1_data5_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA5_L_user1_data5_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data6_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER1_DATA6_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA6_L_user1_data6_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA6_L_user1_data6_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch1_r_0 : 1;
        unsigned int status1_ch1_r_1 : 1;
        unsigned int status1_ch1_r_2 : 1;
        unsigned int status1_ch1_r_3 : 3;
        unsigned int status1_ch1_r_4 : 2;
        unsigned int status1_ch1_r_5 : 8;
        unsigned int status1_ch1_r_6 : 4;
        unsigned int status1_ch1_r_7 : 4;
        unsigned int status1_ch1_r_8 : 4;
        unsigned int status1_ch1_r_9 : 2;
        unsigned int status1_ch1_r_10 : 2;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_1_END (1)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_2_START (2)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_2_END (2)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_3_START (3)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_3_END (5)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_4_START (6)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_4_END (7)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_5_START (8)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_5_END (15)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_6_START (16)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_6_END (19)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_7_START (20)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_7_END (23)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_8_START (24)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_8_END (27)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_9_START (28)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_9_END (29)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_10_START (30)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS1_R_status1_ch1_r_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch1_r_0 : 1;
        unsigned int status2_ch1_r_1 : 3;
        unsigned int status2_ch1_r_2 : 4;
        unsigned int status2_ch1_r_3 : 2;
        unsigned int status2_ch1_r_4 : 22;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH1_STATUS2_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_R_status2_ch1_r_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_R_status2_ch1_r_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_R_status2_ch1_r_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_R_status2_ch1_r_1_END (3)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_R_status2_ch1_r_2_START (4)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_R_status2_ch1_r_2_END (7)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_R_status2_ch1_r_3_START (8)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_R_status2_ch1_r_3_END (9)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_R_status2_ch1_r_4_START (10)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS2_R_status2_ch1_r_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch1_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH1_STATUS3_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS3_R_status3_ch1_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS3_R_status3_ch1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch1_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH1_STATUS4_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS4_R_status4_ch1_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS4_R_status4_ch1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch1_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH1_STATUS5_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS5_R_status5_ch1_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS5_R_status5_ch1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch1_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH1_STATUS6_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS6_R_status6_ch1_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH1_STATUS6_R_status6_ch1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data1_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER1_DATA1_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA1_R_user1_data1_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA1_R_user1_data1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data2_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER1_DATA2_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA2_R_user1_data2_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA2_R_user1_data2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data3_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER1_DATA3_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA3_R_user1_data3_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA3_R_user1_data3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data4_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER1_DATA4_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA4_R_user1_data4_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA4_R_user1_data4_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data5_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER1_DATA5_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA5_R_user1_data5_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA5_R_user1_data5_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user1_data6_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER1_DATA6_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA6_R_user1_data6_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER1_DATA6_R_user1_data6_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch2_l_0 : 1;
        unsigned int status1_ch2_l_1 : 1;
        unsigned int status1_ch2_l_2 : 1;
        unsigned int status1_ch2_l_3 : 3;
        unsigned int status1_ch2_l_4 : 2;
        unsigned int status1_ch2_l_5 : 8;
        unsigned int status1_ch2_l_6 : 4;
        unsigned int status1_ch2_l_7 : 4;
        unsigned int status1_ch2_l_8 : 4;
        unsigned int status1_ch2_l_9 : 2;
        unsigned int status1_ch2_l_10 : 2;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_1_END (1)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_2_START (2)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_2_END (2)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_3_START (3)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_3_END (5)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_4_START (6)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_4_END (7)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_5_START (8)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_5_END (15)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_6_START (16)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_6_END (19)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_7_START (20)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_7_END (23)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_8_START (24)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_8_END (27)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_9_START (28)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_9_END (29)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_10_START (30)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_L_status1_ch2_l_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch2_l_0 : 1;
        unsigned int status2_ch2_l_1 : 3;
        unsigned int status2_ch2_l_2 : 4;
        unsigned int status2_ch2_l_3 : 2;
        unsigned int status2_ch2_l_4 : 22;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH2_STATUS2_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_L_status2_ch2_l_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_L_status2_ch2_l_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_L_status2_ch2_l_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_L_status2_ch2_l_1_END (3)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_L_status2_ch2_l_2_START (4)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_L_status2_ch2_l_2_END (7)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_L_status2_ch2_l_3_START (8)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_L_status2_ch2_l_3_END (9)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_L_status2_ch2_l_4_START (10)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_L_status2_ch2_l_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch2_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH2_STATUS3_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS3_L_status3_ch2_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS3_L_status3_ch2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch2_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH2_STATUS4_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS4_L_status4_ch2_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS4_L_status4_ch2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch2_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH2_STATUS5_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS5_L_status5_ch2_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS5_L_status5_ch2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch2_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH2_STATUS6_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS6_L_status6_ch2_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS6_L_status6_ch2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data1_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER2_DATA1_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA1_L_user2_data1_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA1_L_user2_data1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data2_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER2_DATA2_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA2_L_user2_data2_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA2_L_user2_data2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data3_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER2_DATA3_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA3_L_user2_data3_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA3_L_user2_data3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data4_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER2_DATA4_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA4_L_user2_data4_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA4_L_user2_data4_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data5_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER2_DATA5_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA5_L_user2_data5_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA5_L_user2_data5_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data6_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER2_DATA6_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA6_L_user2_data6_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA6_L_user2_data6_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch2_r_0 : 1;
        unsigned int status1_ch2_r_1 : 1;
        unsigned int status1_ch2_r_2 : 1;
        unsigned int status1_ch2_r_3 : 3;
        unsigned int status1_ch2_r_4 : 2;
        unsigned int status1_ch2_r_5 : 8;
        unsigned int status1_ch2_r_6 : 4;
        unsigned int status1_ch2_r_7 : 4;
        unsigned int status1_ch2_r_8 : 4;
        unsigned int status1_ch2_r_9 : 2;
        unsigned int status1_ch2_r_10 : 2;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_1_END (1)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_2_START (2)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_2_END (2)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_3_START (3)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_3_END (5)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_4_START (6)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_4_END (7)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_5_START (8)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_5_END (15)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_6_START (16)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_6_END (19)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_7_START (20)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_7_END (23)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_8_START (24)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_8_END (27)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_9_START (28)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_9_END (29)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_10_START (30)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS1_R_status1_ch2_r_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch2_r_0 : 1;
        unsigned int status2_ch2_r_1 : 3;
        unsigned int status2_ch2_r_2 : 4;
        unsigned int status2_ch2_r_3 : 2;
        unsigned int status2_ch2_r_4 : 22;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH2_STATUS2_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_R_status2_ch2_r_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_R_status2_ch2_r_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_R_status2_ch2_r_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_R_status2_ch2_r_1_END (3)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_R_status2_ch2_r_2_START (4)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_R_status2_ch2_r_2_END (7)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_R_status2_ch2_r_3_START (8)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_R_status2_ch2_r_3_END (9)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_R_status2_ch2_r_4_START (10)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS2_R_status2_ch2_r_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch2_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH2_STATUS3_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS3_R_status3_ch2_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS3_R_status3_ch2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch2_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH2_STATUS4_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS4_R_status4_ch2_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS4_R_status4_ch2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch2_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH2_STATUS5_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS5_R_status5_ch2_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS5_R_status5_ch2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch2_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH2_STATUS6_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS6_R_status6_ch2_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH2_STATUS6_R_status6_ch2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data1_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER2_DATA1_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA1_R_user2_data1_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA1_R_user2_data1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data2_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER2_DATA2_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA2_R_user2_data2_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA2_R_user2_data2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data3_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER2_DATA3_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA3_R_user2_data3_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA3_R_user2_data3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data4_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER2_DATA4_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA4_R_user2_data4_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA4_R_user2_data4_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data5_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER2_DATA5_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA5_R_user2_data5_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA5_R_user2_data5_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user2_data6_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER2_DATA6_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA6_R_user2_data6_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER2_DATA6_R_user2_data6_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch3_l_0 : 1;
        unsigned int status1_ch3_l_1 : 1;
        unsigned int status1_ch3_l_2 : 1;
        unsigned int status1_ch3_l_3 : 3;
        unsigned int status1_ch3_l_4 : 2;
        unsigned int status1_ch3_l_5 : 8;
        unsigned int status1_ch3_l_6 : 4;
        unsigned int status1_ch3_l_7 : 4;
        unsigned int status1_ch3_l_8 : 4;
        unsigned int status1_ch3_l_9 : 2;
        unsigned int status1_ch3_l_10 : 2;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_1_END (1)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_2_START (2)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_2_END (2)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_3_START (3)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_3_END (5)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_4_START (6)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_4_END (7)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_5_START (8)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_5_END (15)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_6_START (16)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_6_END (19)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_7_START (20)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_7_END (23)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_8_START (24)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_8_END (27)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_9_START (28)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_9_END (29)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_10_START (30)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_L_status1_ch3_l_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch3_l_0 : 1;
        unsigned int status2_ch3_l_1 : 3;
        unsigned int status2_ch3_l_2 : 4;
        unsigned int status2_ch3_l_3 : 2;
        unsigned int status2_ch3_l_4 : 22;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH3_STATUS2_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_L_status2_ch3_l_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_L_status2_ch3_l_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_L_status2_ch3_l_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_L_status2_ch3_l_1_END (3)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_L_status2_ch3_l_2_START (4)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_L_status2_ch3_l_2_END (7)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_L_status2_ch3_l_3_START (8)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_L_status2_ch3_l_3_END (9)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_L_status2_ch3_l_4_START (10)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_L_status2_ch3_l_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch3_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH3_STATUS3_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS3_L_status3_ch3_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS3_L_status3_ch3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch3_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH3_STATUS4_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS4_L_status4_ch3_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS4_L_status4_ch3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch3_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH3_STATUS5_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS5_L_status5_ch3_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS5_L_status5_ch3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch3_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH3_STATUS6_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS6_L_status6_ch3_l_START (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS6_L_status6_ch3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data1_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER3_DATA1_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA1_L_user3_data1_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA1_L_user3_data1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data2_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER3_DATA2_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA2_L_user3_data2_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA2_L_user3_data2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data3_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER3_DATA3_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA3_L_user3_data3_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA3_L_user3_data3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data4_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER3_DATA4_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA4_L_user3_data4_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA4_L_user3_data4_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data5_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER3_DATA5_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA5_L_user3_data5_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA5_L_user3_data5_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data6_l : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER3_DATA6_L_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA6_L_user3_data6_l_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA6_L_user3_data6_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status1_ch3_r_0 : 1;
        unsigned int status1_ch3_r_1 : 1;
        unsigned int status1_ch3_r_2 : 1;
        unsigned int status1_ch3_r_3 : 3;
        unsigned int status1_ch3_r_4 : 2;
        unsigned int status1_ch3_r_5 : 8;
        unsigned int status1_ch3_r_6 : 4;
        unsigned int status1_ch3_r_7 : 4;
        unsigned int status1_ch3_r_8 : 4;
        unsigned int status1_ch3_r_9 : 2;
        unsigned int status1_ch3_r_10 : 2;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_1_END (1)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_2_START (2)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_2_END (2)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_3_START (3)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_3_END (5)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_4_START (6)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_4_END (7)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_5_START (8)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_5_END (15)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_6_START (16)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_6_END (19)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_7_START (20)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_7_END (23)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_8_START (24)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_8_END (27)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_9_START (28)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_9_END (29)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_10_START (30)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS1_R_status1_ch3_r_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status2_ch3_r_0 : 1;
        unsigned int status2_ch3_r_1 : 3;
        unsigned int status2_ch3_r_2 : 4;
        unsigned int status2_ch3_r_3 : 2;
        unsigned int status2_ch3_r_4 : 22;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH3_STATUS2_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_R_status2_ch3_r_0_START (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_R_status2_ch3_r_0_END (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_R_status2_ch3_r_1_START (1)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_R_status2_ch3_r_1_END (3)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_R_status2_ch3_r_2_START (4)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_R_status2_ch3_r_2_END (7)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_R_status2_ch3_r_3_START (8)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_R_status2_ch3_r_3_END (9)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_R_status2_ch3_r_4_START (10)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS2_R_status2_ch3_r_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status3_ch3_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH3_STATUS3_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS3_R_status3_ch3_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS3_R_status3_ch3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status4_ch3_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH3_STATUS4_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS4_R_status4_ch3_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS4_R_status4_ch3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status5_ch3_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH3_STATUS5_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS5_R_status5_ch3_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS5_R_status5_ch3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status6_ch3_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF_CH3_STATUS6_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS6_R_status6_ch3_r_START (0)
#define SOC_ASP_HDMI_SPDIF_CH3_STATUS6_R_status6_ch3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data1_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER3_DATA1_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA1_R_user3_data1_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA1_R_user3_data1_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data2_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER3_DATA2_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA2_R_user3_data2_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA2_R_user3_data2_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data3_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER3_DATA3_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA3_R_user3_data3_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA3_R_user3_data3_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data4_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER3_DATA4_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA4_R_user3_data4_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA4_R_user3_data4_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data5_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER3_DATA5_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA5_R_user3_data5_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA5_R_user3_data5_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user3_data6_r : 32;
    } reg;
} SOC_ASP_HDMI_SPDIF1_USER3_DATA6_R_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA6_R_user3_data6_r_START (0)
#define SOC_ASP_HDMI_SPDIF1_USER3_DATA6_R_user3_data6_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spdif_edition : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_HDMI_SPDIF_EDITION_UNION;
#endif
#define SOC_ASP_HDMI_SPDIF_EDITION_spdif_edition_START (0)
#define SOC_ASP_HDMI_SPDIF_EDITION_spdif_edition_END (7)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

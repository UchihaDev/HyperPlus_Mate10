#ifndef __SOC_MEDIA_CRG_INTERFACE_H__
#define __SOC_MEDIA_CRG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_MEDIA_CRG_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_MEDIA_CRG_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_MEDIA_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_MEDIA_CRG_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_MEDIA_CRG_PEREN1_ADDR(base) ((base) + (0x010))
#define SOC_MEDIA_CRG_PERDIS1_ADDR(base) ((base) + (0x014))
#define SOC_MEDIA_CRG_PERCLKEN1_ADDR(base) ((base) + (0x018))
#define SOC_MEDIA_CRG_PERSTAT1_ADDR(base) ((base) + (0x01C))
#define SOC_MEDIA_CRG_PERRSTEN0_ADDR(base) ((base) + (0x030))
#define SOC_MEDIA_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x034))
#define SOC_MEDIA_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x038))
#define SOC_MEDIA_CRG_PERRSTEN1_ADDR(base) ((base) + (0x03C))
#define SOC_MEDIA_CRG_PERRSTDIS1_ADDR(base) ((base) + (0x040))
#define SOC_MEDIA_CRG_PERRSTSTAT1_ADDR(base) ((base) + (0x044))
#define SOC_MEDIA_CRG_CLKDIV0_ADDR(base) ((base) + (0x060))
#define SOC_MEDIA_CRG_CLKDIV1_ADDR(base) ((base) + (0x064))
#define SOC_MEDIA_CRG_CLKDIV2_ADDR(base) ((base) + (0x068))
#define SOC_MEDIA_CRG_CLKDIV3_ADDR(base) ((base) + (0x06C))
#define SOC_MEDIA_CRG_CLKDIV4_ADDR(base) ((base) + (0x070))
#define SOC_MEDIA_CRG_CLKDIV5_ADDR(base) ((base) + (0x074))
#define SOC_MEDIA_CRG_CLKDIV6_ADDR(base) ((base) + (0x078))
#define SOC_MEDIA_CRG_CLKDIV7_ADDR(base) ((base) + (0x07C))
#define SOC_MEDIA_CRG_CLKDIV8_ADDR(base) ((base) + (0x080))
#define SOC_MEDIA_CRG_CLKDIV9_ADDR(base) ((base) + (0x084))
#define SOC_MEDIA_CRG_PERI_STAT0_ADDR(base) ((base) + (0x0A0))
#define SOC_MEDIA_CRG_PERI_STAT1_ADDR(base) ((base) + (0x0A4))
#define SOC_MEDIA_CRG_PERI_STAT2_ADDR(base) ((base) + (0x0A8))
#define SOC_MEDIA_CRG_ISOEN_ADDR(base) ((base) + (0x100))
#define SOC_MEDIA_CRG_ISODIS_ADDR(base) ((base) + (0x104))
#define SOC_MEDIA_CRG_ISOSTAT_ADDR(base) ((base) + (0x108))
#define SOC_MEDIA_CRG_IPCLKRST_BYPASS_ADDR(base) ((base) + (0x130))
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_ADDR(base) ((base) + (0x140))
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_ADDR(base) ((base) + (0x144))
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_ADDR(base) ((base) + (0x148))
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_ADDR(base) ((base) + (0x14C))
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_ADDR(base) ((base) + (0x150))
#define SOC_MEDIA_CRG_ISP_CPU_STATE1_ADDR(base) ((base) + (0x154))
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x160))
#define SOC_MEDIA_CRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x164))
#define SOC_MEDIA_CRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x168))
#define SOC_MEDIA_CRG_PERI_AUTODIV3_ADDR(base) ((base) + (0x16C))
#define SOC_MEDIA_CRG_PERI_AUTODIV4_ADDR(base) ((base) + (0x170))
#define SOC_MEDIA_CRG_PERI_AUTODIV5_ADDR(base) ((base) + (0x174))
#define SOC_MEDIA_CRG_PERI_AUTODIV6_ADDR(base) ((base) + (0x178))
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_ADDR(base) ((base) + (0x190))
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ADDR(base) ((base) + (0x800))
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ADDR(base) ((base) + (0x804))
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ADDR(base) ((base) + (0x808))
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_ADDR(base) ((base) + (0x810))
#define SOC_MEDIA_CRG_PERRSTEN_SEC_IVP_ADDR(base) ((base) + (0x900))
#define SOC_MEDIA_CRG_PERRSTDIS_SEC_IVP_ADDR(base) ((base) + (0x904))
#define SOC_MEDIA_CRG_PERRSTSTAT_SEC_IVP_ADDR(base) ((base) + (0x908))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_venc : 1;
        unsigned int gt_clk_venc : 1;
        unsigned int gt_pclk_vdec : 1;
        unsigned int gt_clk_vdec : 1;
        unsigned int gt_clk_vcodecbus2ddrc : 1;
        unsigned int gt_clk_vcodecbus_cfg : 1;
        unsigned int gt_clk_vivobus2ddrc : 1;
        unsigned int gt_clk_vivobus_cfg : 1;
        unsigned int gt_clk_ivp32dsp_tcxo : 1;
        unsigned int gt_clk_isp_i2c : 1;
        unsigned int gt_clk_ivp32dsp_core_crg : 1;
        unsigned int gt_clk_isp_sys : 1;
        unsigned int gt_clk_isp_cpu : 1;
        unsigned int gt_clk_ispfunc : 1;
        unsigned int gt_pclk_dss : 1;
        unsigned int gt_clk_edc0 : 1;
        unsigned int gt_clk_ldi0 : 1;
        unsigned int gt_clk_ldi1 : 1;
        unsigned int gt_clk_vivobus : 1;
        unsigned int gt_aclk_dss : 1;
        unsigned int gt_aclk_isp : 1;
        unsigned int gt_clk_vcodecbus : 1;
        unsigned int gt_aclk_venc : 1;
        unsigned int gt_aclk_vdec : 1;
        unsigned int gt_pclk_atgm_dss : 1;
        unsigned int gt_pclk_atgm_isp : 1;
        unsigned int gt_pclk_atgm_vdec : 1;
        unsigned int gt_clk_vivobus2ddrc_core : 1;
        unsigned int gt_clk_vcodecbus2ddrc_core : 1;
        unsigned int gt_clk_isp_cfgtoisp : 1;
        unsigned int gt_clk_isp_cputocfg : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_MEDIA_CRG_PEREN0_UNION;
#endif
#define SOC_MEDIA_CRG_PEREN0_gt_pclk_venc_START (0)
#define SOC_MEDIA_CRG_PEREN0_gt_pclk_venc_END (0)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_venc_START (1)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_venc_END (1)
#define SOC_MEDIA_CRG_PEREN0_gt_pclk_vdec_START (2)
#define SOC_MEDIA_CRG_PEREN0_gt_pclk_vdec_END (2)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vdec_START (3)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vdec_END (3)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vcodecbus2ddrc_START (4)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vcodecbus2ddrc_END (4)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vcodecbus_cfg_START (5)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vcodecbus_cfg_END (5)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vivobus2ddrc_START (6)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vivobus2ddrc_END (6)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vivobus_cfg_START (7)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vivobus_cfg_END (7)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_ivp32dsp_tcxo_START (8)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_ivp32dsp_tcxo_END (8)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_isp_i2c_START (9)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_isp_i2c_END (9)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_ivp32dsp_core_crg_START (10)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_ivp32dsp_core_crg_END (10)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_isp_sys_START (11)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_isp_sys_END (11)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_isp_cpu_START (12)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_isp_cpu_END (12)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_ispfunc_START (13)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_ispfunc_END (13)
#define SOC_MEDIA_CRG_PEREN0_gt_pclk_dss_START (14)
#define SOC_MEDIA_CRG_PEREN0_gt_pclk_dss_END (14)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_edc0_START (15)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_edc0_END (15)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_ldi0_START (16)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_ldi0_END (16)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_ldi1_START (17)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_ldi1_END (17)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vivobus_START (18)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vivobus_END (18)
#define SOC_MEDIA_CRG_PEREN0_gt_aclk_dss_START (19)
#define SOC_MEDIA_CRG_PEREN0_gt_aclk_dss_END (19)
#define SOC_MEDIA_CRG_PEREN0_gt_aclk_isp_START (20)
#define SOC_MEDIA_CRG_PEREN0_gt_aclk_isp_END (20)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vcodecbus_START (21)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vcodecbus_END (21)
#define SOC_MEDIA_CRG_PEREN0_gt_aclk_venc_START (22)
#define SOC_MEDIA_CRG_PEREN0_gt_aclk_venc_END (22)
#define SOC_MEDIA_CRG_PEREN0_gt_aclk_vdec_START (23)
#define SOC_MEDIA_CRG_PEREN0_gt_aclk_vdec_END (23)
#define SOC_MEDIA_CRG_PEREN0_gt_pclk_atgm_dss_START (24)
#define SOC_MEDIA_CRG_PEREN0_gt_pclk_atgm_dss_END (24)
#define SOC_MEDIA_CRG_PEREN0_gt_pclk_atgm_isp_START (25)
#define SOC_MEDIA_CRG_PEREN0_gt_pclk_atgm_isp_END (25)
#define SOC_MEDIA_CRG_PEREN0_gt_pclk_atgm_vdec_START (26)
#define SOC_MEDIA_CRG_PEREN0_gt_pclk_atgm_vdec_END (26)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vivobus2ddrc_core_START (27)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vivobus2ddrc_core_END (27)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vcodecbus2ddrc_core_START (28)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_vcodecbus2ddrc_core_END (28)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_isp_cfgtoisp_START (29)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_isp_cfgtoisp_END (29)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_isp_cputocfg_START (30)
#define SOC_MEDIA_CRG_PEREN0_gt_clk_isp_cputocfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_venc : 1;
        unsigned int gt_clk_venc : 1;
        unsigned int gt_pclk_vdec : 1;
        unsigned int gt_clk_vdec : 1;
        unsigned int gt_clk_vcodecbus2ddrc : 1;
        unsigned int gt_clk_vcodecbus_cfg : 1;
        unsigned int gt_clk_vivobus2ddrc : 1;
        unsigned int gt_clk_vivobus_cfg : 1;
        unsigned int gt_clk_ivp32dsp_tcxo : 1;
        unsigned int gt_clk_isp_i2c : 1;
        unsigned int gt_clk_ivp32dsp_core_crg : 1;
        unsigned int gt_clk_isp_sys : 1;
        unsigned int gt_clk_isp_cpu : 1;
        unsigned int gt_clk_ispfunc : 1;
        unsigned int gt_pclk_dss : 1;
        unsigned int gt_clk_edc0 : 1;
        unsigned int gt_clk_ldi0 : 1;
        unsigned int gt_clk_ldi1 : 1;
        unsigned int gt_clk_vivobus : 1;
        unsigned int gt_aclk_dss : 1;
        unsigned int gt_aclk_isp : 1;
        unsigned int gt_clk_vcodecbus : 1;
        unsigned int gt_aclk_venc : 1;
        unsigned int gt_aclk_vdec : 1;
        unsigned int gt_pclk_atgm_dss : 1;
        unsigned int gt_pclk_atgm_isp : 1;
        unsigned int gt_pclk_atgm_vdec : 1;
        unsigned int gt_clk_vivobus2ddrc_core : 1;
        unsigned int gt_clk_vcodecbus2ddrc_core : 1;
        unsigned int gt_clk_isp_cfgtoisp : 1;
        unsigned int gt_clk_isp_cputocfg : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_MEDIA_CRG_PERDIS0_UNION;
#endif
#define SOC_MEDIA_CRG_PERDIS0_gt_pclk_venc_START (0)
#define SOC_MEDIA_CRG_PERDIS0_gt_pclk_venc_END (0)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_venc_START (1)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_venc_END (1)
#define SOC_MEDIA_CRG_PERDIS0_gt_pclk_vdec_START (2)
#define SOC_MEDIA_CRG_PERDIS0_gt_pclk_vdec_END (2)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vdec_START (3)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vdec_END (3)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vcodecbus2ddrc_START (4)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vcodecbus2ddrc_END (4)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vcodecbus_cfg_START (5)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vcodecbus_cfg_END (5)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vivobus2ddrc_START (6)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vivobus2ddrc_END (6)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vivobus_cfg_START (7)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vivobus_cfg_END (7)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_ivp32dsp_tcxo_START (8)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_ivp32dsp_tcxo_END (8)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_isp_i2c_START (9)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_isp_i2c_END (9)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_ivp32dsp_core_crg_START (10)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_ivp32dsp_core_crg_END (10)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_isp_sys_START (11)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_isp_sys_END (11)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_isp_cpu_START (12)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_isp_cpu_END (12)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_ispfunc_START (13)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_ispfunc_END (13)
#define SOC_MEDIA_CRG_PERDIS0_gt_pclk_dss_START (14)
#define SOC_MEDIA_CRG_PERDIS0_gt_pclk_dss_END (14)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_edc0_START (15)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_edc0_END (15)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_ldi0_START (16)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_ldi0_END (16)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_ldi1_START (17)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_ldi1_END (17)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vivobus_START (18)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vivobus_END (18)
#define SOC_MEDIA_CRG_PERDIS0_gt_aclk_dss_START (19)
#define SOC_MEDIA_CRG_PERDIS0_gt_aclk_dss_END (19)
#define SOC_MEDIA_CRG_PERDIS0_gt_aclk_isp_START (20)
#define SOC_MEDIA_CRG_PERDIS0_gt_aclk_isp_END (20)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vcodecbus_START (21)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vcodecbus_END (21)
#define SOC_MEDIA_CRG_PERDIS0_gt_aclk_venc_START (22)
#define SOC_MEDIA_CRG_PERDIS0_gt_aclk_venc_END (22)
#define SOC_MEDIA_CRG_PERDIS0_gt_aclk_vdec_START (23)
#define SOC_MEDIA_CRG_PERDIS0_gt_aclk_vdec_END (23)
#define SOC_MEDIA_CRG_PERDIS0_gt_pclk_atgm_dss_START (24)
#define SOC_MEDIA_CRG_PERDIS0_gt_pclk_atgm_dss_END (24)
#define SOC_MEDIA_CRG_PERDIS0_gt_pclk_atgm_isp_START (25)
#define SOC_MEDIA_CRG_PERDIS0_gt_pclk_atgm_isp_END (25)
#define SOC_MEDIA_CRG_PERDIS0_gt_pclk_atgm_vdec_START (26)
#define SOC_MEDIA_CRG_PERDIS0_gt_pclk_atgm_vdec_END (26)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vivobus2ddrc_core_START (27)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vivobus2ddrc_core_END (27)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vcodecbus2ddrc_core_START (28)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_vcodecbus2ddrc_core_END (28)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_isp_cfgtoisp_START (29)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_isp_cfgtoisp_END (29)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_isp_cputocfg_START (30)
#define SOC_MEDIA_CRG_PERDIS0_gt_clk_isp_cputocfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_venc : 1;
        unsigned int gt_clk_venc : 1;
        unsigned int gt_pclk_vdec : 1;
        unsigned int gt_clk_vdec : 1;
        unsigned int gt_clk_vcodecbus2ddrc : 1;
        unsigned int gt_clk_vcodecbus_cfg : 1;
        unsigned int gt_clk_vivobus2ddrc : 1;
        unsigned int gt_clk_vivobus_cfg : 1;
        unsigned int gt_clk_ivp32dsp_tcxo : 1;
        unsigned int gt_clk_isp_i2c : 1;
        unsigned int gt_clk_ivp32dsp_core_crg : 1;
        unsigned int gt_clk_isp_sys : 1;
        unsigned int gt_clk_isp_cpu : 1;
        unsigned int gt_clk_ispfunc : 1;
        unsigned int gt_pclk_dss : 1;
        unsigned int gt_clk_edc0 : 1;
        unsigned int gt_clk_ldi0 : 1;
        unsigned int gt_clk_ldi1 : 1;
        unsigned int gt_clk_vivobus : 1;
        unsigned int gt_aclk_dss : 1;
        unsigned int gt_aclk_isp : 1;
        unsigned int gt_clk_vcodecbus : 1;
        unsigned int gt_aclk_venc : 1;
        unsigned int gt_aclk_vdec : 1;
        unsigned int gt_pclk_atgm_dss : 1;
        unsigned int gt_pclk_atgm_isp : 1;
        unsigned int gt_pclk_atgm_vdec : 1;
        unsigned int gt_clk_vivobus2ddrc_core : 1;
        unsigned int gt_clk_vcodecbus2ddrc_core : 1;
        unsigned int gt_clk_isp_cfgtoisp : 1;
        unsigned int gt_clk_isp_cputocfg : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_MEDIA_CRG_PERCLKEN0_UNION;
#endif
#define SOC_MEDIA_CRG_PERCLKEN0_gt_pclk_venc_START (0)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_pclk_venc_END (0)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_venc_START (1)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_venc_END (1)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_pclk_vdec_START (2)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_pclk_vdec_END (2)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vdec_START (3)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vdec_END (3)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vcodecbus2ddrc_START (4)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vcodecbus2ddrc_END (4)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vcodecbus_cfg_START (5)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vcodecbus_cfg_END (5)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vivobus2ddrc_START (6)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vivobus2ddrc_END (6)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vivobus_cfg_START (7)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vivobus_cfg_END (7)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_ivp32dsp_tcxo_START (8)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_ivp32dsp_tcxo_END (8)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_isp_i2c_START (9)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_isp_i2c_END (9)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_ivp32dsp_core_crg_START (10)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_ivp32dsp_core_crg_END (10)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_isp_sys_START (11)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_isp_sys_END (11)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_isp_cpu_START (12)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_isp_cpu_END (12)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_ispfunc_START (13)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_ispfunc_END (13)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_pclk_dss_START (14)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_pclk_dss_END (14)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_edc0_START (15)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_edc0_END (15)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_ldi0_START (16)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_ldi0_END (16)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_ldi1_START (17)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_ldi1_END (17)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vivobus_START (18)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vivobus_END (18)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_aclk_dss_START (19)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_aclk_dss_END (19)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_aclk_isp_START (20)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_aclk_isp_END (20)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vcodecbus_START (21)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vcodecbus_END (21)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_aclk_venc_START (22)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_aclk_venc_END (22)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_aclk_vdec_START (23)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_aclk_vdec_END (23)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_pclk_atgm_dss_START (24)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_pclk_atgm_dss_END (24)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_pclk_atgm_isp_START (25)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_pclk_atgm_isp_END (25)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_pclk_atgm_vdec_START (26)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_pclk_atgm_vdec_END (26)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vivobus2ddrc_core_START (27)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vivobus2ddrc_core_END (27)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vcodecbus2ddrc_core_START (28)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_vcodecbus2ddrc_core_END (28)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_isp_cfgtoisp_START (29)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_isp_cfgtoisp_END (29)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_isp_cputocfg_START (30)
#define SOC_MEDIA_CRG_PERCLKEN0_gt_clk_isp_cputocfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_pclk_venc : 1;
        unsigned int st_clk_venc : 1;
        unsigned int st_pclk_vdec : 1;
        unsigned int st_clk_vdec : 1;
        unsigned int st_clk_vcodecbus2ddrc : 1;
        unsigned int st_clk_vcodecbus_cfg : 1;
        unsigned int st_clk_vivobus2ddrc : 1;
        unsigned int st_clk_vivobus_cfg : 1;
        unsigned int st_clk_ivp32dsp_tcxo : 1;
        unsigned int st_clk_isp_i2c : 1;
        unsigned int st_clk_ivp32dsp_core_crg : 1;
        unsigned int st_clk_isp_sys : 1;
        unsigned int st_clk_isp_cpu : 1;
        unsigned int st_clk_ispfunc : 1;
        unsigned int st_pclk_dss : 1;
        unsigned int st_clk_edc0 : 1;
        unsigned int st_clk_ldi0 : 1;
        unsigned int st_clk_ldi1 : 1;
        unsigned int st_clk_vivobus : 1;
        unsigned int st_aclk_dss : 1;
        unsigned int st_aclk_isp : 1;
        unsigned int st_clk_vcodecbus : 1;
        unsigned int st_aclk_venc : 1;
        unsigned int st_aclk_vdec : 1;
        unsigned int st_pclk_atgm_dss : 1;
        unsigned int st_pclk_atgm_isp : 1;
        unsigned int st_pclk_atgm_vdec : 1;
        unsigned int st_clk_vivobus2ddrc_core : 1;
        unsigned int st_clk_vcodecbus2ddrc_core : 1;
        unsigned int st_clk_isp_cfgtoisp : 1;
        unsigned int st_clk_isp_cputocfg : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_MEDIA_CRG_PERSTAT0_UNION;
#endif
#define SOC_MEDIA_CRG_PERSTAT0_st_pclk_venc_START (0)
#define SOC_MEDIA_CRG_PERSTAT0_st_pclk_venc_END (0)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_venc_START (1)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_venc_END (1)
#define SOC_MEDIA_CRG_PERSTAT0_st_pclk_vdec_START (2)
#define SOC_MEDIA_CRG_PERSTAT0_st_pclk_vdec_END (2)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vdec_START (3)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vdec_END (3)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vcodecbus2ddrc_START (4)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vcodecbus2ddrc_END (4)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vcodecbus_cfg_START (5)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vcodecbus_cfg_END (5)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vivobus2ddrc_START (6)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vivobus2ddrc_END (6)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vivobus_cfg_START (7)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vivobus_cfg_END (7)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_ivp32dsp_tcxo_START (8)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_ivp32dsp_tcxo_END (8)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_isp_i2c_START (9)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_isp_i2c_END (9)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_ivp32dsp_core_crg_START (10)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_ivp32dsp_core_crg_END (10)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_isp_sys_START (11)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_isp_sys_END (11)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_isp_cpu_START (12)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_isp_cpu_END (12)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_ispfunc_START (13)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_ispfunc_END (13)
#define SOC_MEDIA_CRG_PERSTAT0_st_pclk_dss_START (14)
#define SOC_MEDIA_CRG_PERSTAT0_st_pclk_dss_END (14)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_edc0_START (15)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_edc0_END (15)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_ldi0_START (16)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_ldi0_END (16)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_ldi1_START (17)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_ldi1_END (17)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vivobus_START (18)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vivobus_END (18)
#define SOC_MEDIA_CRG_PERSTAT0_st_aclk_dss_START (19)
#define SOC_MEDIA_CRG_PERSTAT0_st_aclk_dss_END (19)
#define SOC_MEDIA_CRG_PERSTAT0_st_aclk_isp_START (20)
#define SOC_MEDIA_CRG_PERSTAT0_st_aclk_isp_END (20)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vcodecbus_START (21)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vcodecbus_END (21)
#define SOC_MEDIA_CRG_PERSTAT0_st_aclk_venc_START (22)
#define SOC_MEDIA_CRG_PERSTAT0_st_aclk_venc_END (22)
#define SOC_MEDIA_CRG_PERSTAT0_st_aclk_vdec_START (23)
#define SOC_MEDIA_CRG_PERSTAT0_st_aclk_vdec_END (23)
#define SOC_MEDIA_CRG_PERSTAT0_st_pclk_atgm_dss_START (24)
#define SOC_MEDIA_CRG_PERSTAT0_st_pclk_atgm_dss_END (24)
#define SOC_MEDIA_CRG_PERSTAT0_st_pclk_atgm_isp_START (25)
#define SOC_MEDIA_CRG_PERSTAT0_st_pclk_atgm_isp_END (25)
#define SOC_MEDIA_CRG_PERSTAT0_st_pclk_atgm_vdec_START (26)
#define SOC_MEDIA_CRG_PERSTAT0_st_pclk_atgm_vdec_END (26)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vivobus2ddrc_core_START (27)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vivobus2ddrc_core_END (27)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vcodecbus2ddrc_core_START (28)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_vcodecbus2ddrc_core_END (28)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_isp_cfgtoisp_START (29)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_isp_cfgtoisp_END (29)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_isp_cputocfg_START (30)
#define SOC_MEDIA_CRG_PERSTAT0_st_clk_isp_cputocfg_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_autodiv_vcodecbus : 1;
        unsigned int gt_pclk_autodiv_vivobus : 1;
        unsigned int gt_pclk_autodiv_vdec : 1;
        unsigned int gt_pclk_autodiv_venc : 1;
        unsigned int gt_pclk_autodiv_ispcpu : 1;
        unsigned int gt_pclk_autodiv_ivp : 1;
        unsigned int gt_clk_noc_cnn : 1;
        unsigned int gt_clk_cnn : 1;
        unsigned int gt_clk_noc_cnn_cfg : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_MEDIA_CRG_PEREN1_UNION;
#endif
#define SOC_MEDIA_CRG_PEREN1_gt_pclk_autodiv_vcodecbus_START (0)
#define SOC_MEDIA_CRG_PEREN1_gt_pclk_autodiv_vcodecbus_END (0)
#define SOC_MEDIA_CRG_PEREN1_gt_pclk_autodiv_vivobus_START (1)
#define SOC_MEDIA_CRG_PEREN1_gt_pclk_autodiv_vivobus_END (1)
#define SOC_MEDIA_CRG_PEREN1_gt_pclk_autodiv_vdec_START (2)
#define SOC_MEDIA_CRG_PEREN1_gt_pclk_autodiv_vdec_END (2)
#define SOC_MEDIA_CRG_PEREN1_gt_pclk_autodiv_venc_START (3)
#define SOC_MEDIA_CRG_PEREN1_gt_pclk_autodiv_venc_END (3)
#define SOC_MEDIA_CRG_PEREN1_gt_pclk_autodiv_ispcpu_START (4)
#define SOC_MEDIA_CRG_PEREN1_gt_pclk_autodiv_ispcpu_END (4)
#define SOC_MEDIA_CRG_PEREN1_gt_pclk_autodiv_ivp_START (5)
#define SOC_MEDIA_CRG_PEREN1_gt_pclk_autodiv_ivp_END (5)
#define SOC_MEDIA_CRG_PEREN1_gt_clk_noc_cnn_START (6)
#define SOC_MEDIA_CRG_PEREN1_gt_clk_noc_cnn_END (6)
#define SOC_MEDIA_CRG_PEREN1_gt_clk_cnn_START (7)
#define SOC_MEDIA_CRG_PEREN1_gt_clk_cnn_END (7)
#define SOC_MEDIA_CRG_PEREN1_gt_clk_noc_cnn_cfg_START (8)
#define SOC_MEDIA_CRG_PEREN1_gt_clk_noc_cnn_cfg_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_autodiv_vcodecbus : 1;
        unsigned int gt_pclk_autodiv_vivobus : 1;
        unsigned int gt_pclk_autodiv_vdec : 1;
        unsigned int gt_pclk_autodiv_venc : 1;
        unsigned int gt_pclk_autodiv_ispcpu : 1;
        unsigned int gt_pclk_autodiv_ivp : 1;
        unsigned int gt_clk_noc_cnn : 1;
        unsigned int gt_clk_cnn : 1;
        unsigned int gt_clk_noc_cnn_cfg : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_MEDIA_CRG_PERDIS1_UNION;
#endif
#define SOC_MEDIA_CRG_PERDIS1_gt_pclk_autodiv_vcodecbus_START (0)
#define SOC_MEDIA_CRG_PERDIS1_gt_pclk_autodiv_vcodecbus_END (0)
#define SOC_MEDIA_CRG_PERDIS1_gt_pclk_autodiv_vivobus_START (1)
#define SOC_MEDIA_CRG_PERDIS1_gt_pclk_autodiv_vivobus_END (1)
#define SOC_MEDIA_CRG_PERDIS1_gt_pclk_autodiv_vdec_START (2)
#define SOC_MEDIA_CRG_PERDIS1_gt_pclk_autodiv_vdec_END (2)
#define SOC_MEDIA_CRG_PERDIS1_gt_pclk_autodiv_venc_START (3)
#define SOC_MEDIA_CRG_PERDIS1_gt_pclk_autodiv_venc_END (3)
#define SOC_MEDIA_CRG_PERDIS1_gt_pclk_autodiv_ispcpu_START (4)
#define SOC_MEDIA_CRG_PERDIS1_gt_pclk_autodiv_ispcpu_END (4)
#define SOC_MEDIA_CRG_PERDIS1_gt_pclk_autodiv_ivp_START (5)
#define SOC_MEDIA_CRG_PERDIS1_gt_pclk_autodiv_ivp_END (5)
#define SOC_MEDIA_CRG_PERDIS1_gt_clk_noc_cnn_START (6)
#define SOC_MEDIA_CRG_PERDIS1_gt_clk_noc_cnn_END (6)
#define SOC_MEDIA_CRG_PERDIS1_gt_clk_cnn_START (7)
#define SOC_MEDIA_CRG_PERDIS1_gt_clk_cnn_END (7)
#define SOC_MEDIA_CRG_PERDIS1_gt_clk_noc_cnn_cfg_START (8)
#define SOC_MEDIA_CRG_PERDIS1_gt_clk_noc_cnn_cfg_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_autodiv_vcodecbus : 1;
        unsigned int gt_pclk_autodiv_vivobus : 1;
        unsigned int gt_pclk_autodiv_vdec : 1;
        unsigned int gt_pclk_autodiv_venc : 1;
        unsigned int gt_pclk_autodiv_ispcpu : 1;
        unsigned int gt_pclk_autodiv_ivp : 1;
        unsigned int gt_clk_noc_cnn : 1;
        unsigned int gt_clk_cnn : 1;
        unsigned int gt_clk_noc_cnn_cfg : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_MEDIA_CRG_PERCLKEN1_UNION;
#endif
#define SOC_MEDIA_CRG_PERCLKEN1_gt_pclk_autodiv_vcodecbus_START (0)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_pclk_autodiv_vcodecbus_END (0)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_pclk_autodiv_vivobus_START (1)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_pclk_autodiv_vivobus_END (1)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_pclk_autodiv_vdec_START (2)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_pclk_autodiv_vdec_END (2)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_pclk_autodiv_venc_START (3)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_pclk_autodiv_venc_END (3)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_pclk_autodiv_ispcpu_START (4)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_pclk_autodiv_ispcpu_END (4)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_pclk_autodiv_ivp_START (5)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_pclk_autodiv_ivp_END (5)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_clk_noc_cnn_START (6)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_clk_noc_cnn_END (6)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_clk_cnn_START (7)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_clk_cnn_END (7)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_clk_noc_cnn_cfg_START (8)
#define SOC_MEDIA_CRG_PERCLKEN1_gt_clk_noc_cnn_cfg_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_pclk_autodiv_vcodecbus : 1;
        unsigned int st_pclk_autodiv_vivobus : 1;
        unsigned int st_pclk_autodiv_vdec : 1;
        unsigned int st_pclk_autodiv_venc : 1;
        unsigned int st_pclk_autodiv_ispcpu : 1;
        unsigned int st_pclk_autodiv_ivp : 1;
        unsigned int st_clk_noc_cnn : 1;
        unsigned int st_clk_cnn : 1;
        unsigned int st_clk_noc_cnn_cfg : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_MEDIA_CRG_PERSTAT1_UNION;
#endif
#define SOC_MEDIA_CRG_PERSTAT1_st_pclk_autodiv_vcodecbus_START (0)
#define SOC_MEDIA_CRG_PERSTAT1_st_pclk_autodiv_vcodecbus_END (0)
#define SOC_MEDIA_CRG_PERSTAT1_st_pclk_autodiv_vivobus_START (1)
#define SOC_MEDIA_CRG_PERSTAT1_st_pclk_autodiv_vivobus_END (1)
#define SOC_MEDIA_CRG_PERSTAT1_st_pclk_autodiv_vdec_START (2)
#define SOC_MEDIA_CRG_PERSTAT1_st_pclk_autodiv_vdec_END (2)
#define SOC_MEDIA_CRG_PERSTAT1_st_pclk_autodiv_venc_START (3)
#define SOC_MEDIA_CRG_PERSTAT1_st_pclk_autodiv_venc_END (3)
#define SOC_MEDIA_CRG_PERSTAT1_st_pclk_autodiv_ispcpu_START (4)
#define SOC_MEDIA_CRG_PERSTAT1_st_pclk_autodiv_ispcpu_END (4)
#define SOC_MEDIA_CRG_PERSTAT1_st_pclk_autodiv_ivp_START (5)
#define SOC_MEDIA_CRG_PERSTAT1_st_pclk_autodiv_ivp_END (5)
#define SOC_MEDIA_CRG_PERSTAT1_st_clk_noc_cnn_START (6)
#define SOC_MEDIA_CRG_PERSTAT1_st_clk_noc_cnn_END (6)
#define SOC_MEDIA_CRG_PERSTAT1_st_clk_cnn_START (7)
#define SOC_MEDIA_CRG_PERSTAT1_st_clk_cnn_END (7)
#define SOC_MEDIA_CRG_PERSTAT1_st_clk_noc_cnn_cfg_START (8)
#define SOC_MEDIA_CRG_PERSTAT1_st_clk_noc_cnn_cfg_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_venc : 1;
        unsigned int ip_rst_vdec : 1;
        unsigned int ip_rst_vcodecbus : 1;
        unsigned int ip_rst_vcodecbus_cfg : 1;
        unsigned int ip_rst_vivobus : 1;
        unsigned int ip_rst_vivobus_cfg : 1;
        unsigned int ip_rst_dss : 1;
        unsigned int ip_prst_dss : 1;
        unsigned int ip_prst_atgm_vdec : 1;
        unsigned int ip_prst_atgm_dss : 1;
        unsigned int ip_prst_atgm_isp : 1;
        unsigned int ip_rst_noc_cnn : 1;
        unsigned int ip_rst_cnn : 1;
        unsigned int ip_rst_noc_cnn_cfg : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MEDIA_CRG_PERRSTEN0_UNION;
#endif
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_venc_START (0)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_venc_END (0)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_vdec_START (1)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_vdec_END (1)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_vcodecbus_START (2)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_vcodecbus_END (2)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_vcodecbus_cfg_START (3)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_vcodecbus_cfg_END (3)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_vivobus_START (4)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_vivobus_END (4)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_vivobus_cfg_START (5)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_vivobus_cfg_END (5)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_dss_START (6)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_dss_END (6)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_prst_dss_START (7)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_prst_dss_END (7)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_prst_atgm_vdec_START (8)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_prst_atgm_vdec_END (8)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_prst_atgm_dss_START (9)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_prst_atgm_dss_END (9)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_prst_atgm_isp_START (10)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_prst_atgm_isp_END (10)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_noc_cnn_START (11)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_noc_cnn_END (11)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_cnn_START (12)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_cnn_END (12)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_noc_cnn_cfg_START (13)
#define SOC_MEDIA_CRG_PERRSTEN0_ip_rst_noc_cnn_cfg_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_venc : 1;
        unsigned int ip_rst_vdec : 1;
        unsigned int ip_rst_vcodecbus : 1;
        unsigned int ip_rst_vcodecbus_cfg : 1;
        unsigned int ip_rst_vivobus : 1;
        unsigned int ip_rst_vivobus_cfg : 1;
        unsigned int ip_rst_dss : 1;
        unsigned int ip_prst_dss : 1;
        unsigned int ip_prst_atgm_vdec : 1;
        unsigned int ip_prst_atgm_dss : 1;
        unsigned int ip_prst_atgm_isp : 1;
        unsigned int ip_rst_noc_cnn : 1;
        unsigned int ip_rst_cnn : 1;
        unsigned int ip_rst_noc_cnn_cfg : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MEDIA_CRG_PERRSTDIS0_UNION;
#endif
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_venc_START (0)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_venc_END (0)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_vdec_START (1)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_vdec_END (1)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_vcodecbus_START (2)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_vcodecbus_END (2)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_vcodecbus_cfg_START (3)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_vcodecbus_cfg_END (3)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_vivobus_START (4)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_vivobus_END (4)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_vivobus_cfg_START (5)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_vivobus_cfg_END (5)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_dss_START (6)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_dss_END (6)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_prst_dss_START (7)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_prst_dss_END (7)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_prst_atgm_vdec_START (8)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_prst_atgm_vdec_END (8)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_prst_atgm_dss_START (9)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_prst_atgm_dss_END (9)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_prst_atgm_isp_START (10)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_prst_atgm_isp_END (10)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_noc_cnn_START (11)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_noc_cnn_END (11)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_cnn_START (12)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_cnn_END (12)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_noc_cnn_cfg_START (13)
#define SOC_MEDIA_CRG_PERRSTDIS0_ip_rst_noc_cnn_cfg_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_venc : 1;
        unsigned int ip_rst_vdec : 1;
        unsigned int ip_rst_vcodecbus : 1;
        unsigned int ip_rst_vcodecbus_cfg : 1;
        unsigned int ip_rst_vivobus : 1;
        unsigned int ip_rst_vivobus_cfg : 1;
        unsigned int ip_rst_dss : 1;
        unsigned int ip_prst_dss : 1;
        unsigned int ip_prst_atgm_vdec : 1;
        unsigned int ip_prst_atgm_dss : 1;
        unsigned int ip_prst_atgm_isp : 1;
        unsigned int ip_rst_noc_cnn : 1;
        unsigned int ip_rst_cnn : 1;
        unsigned int ip_rst_noc_cnn_cfg : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MEDIA_CRG_PERRSTSTAT0_UNION;
#endif
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_venc_START (0)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_venc_END (0)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_vdec_START (1)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_vdec_END (1)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_vcodecbus_START (2)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_vcodecbus_END (2)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_vcodecbus_cfg_START (3)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_vcodecbus_cfg_END (3)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_vivobus_START (4)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_vivobus_END (4)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_vivobus_cfg_START (5)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_vivobus_cfg_END (5)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_dss_START (6)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_dss_END (6)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_prst_dss_START (7)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_prst_dss_END (7)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_prst_atgm_vdec_START (8)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_prst_atgm_vdec_END (8)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_prst_atgm_dss_START (9)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_prst_atgm_dss_END (9)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_prst_atgm_isp_START (10)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_prst_atgm_isp_END (10)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_noc_cnn_START (11)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_noc_cnn_END (11)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_cnn_START (12)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_cnn_END (12)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_noc_cnn_cfg_START (13)
#define SOC_MEDIA_CRG_PERRSTSTAT0_ip_rst_noc_cnn_cfg_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_MEDIA_CRG_PERRSTEN1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_MEDIA_CRG_PERRSTDIS1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_MEDIA_CRG_PERRSTSTAT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_ldi0 : 6;
        unsigned int sel_ldi0_pll : 4;
        unsigned int sel_vdec_pll : 4;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_MEDIA_CRG_CLKDIV0_UNION;
#endif
#define SOC_MEDIA_CRG_CLKDIV0_div_ldi0_START (0)
#define SOC_MEDIA_CRG_CLKDIV0_div_ldi0_END (5)
#define SOC_MEDIA_CRG_CLKDIV0_sel_ldi0_pll_START (6)
#define SOC_MEDIA_CRG_CLKDIV0_sel_ldi0_pll_END (9)
#define SOC_MEDIA_CRG_CLKDIV0_sel_vdec_pll_START (10)
#define SOC_MEDIA_CRG_CLKDIV0_sel_vdec_pll_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_ldi1 : 6;
        unsigned int sel_ldi1_pll : 4;
        unsigned int sel_vcodecbus_pll : 4;
        unsigned int sel_ivp32dsp_core_pll : 2;
        unsigned int reserved : 16;
    } reg;
} SOC_MEDIA_CRG_CLKDIV1_UNION;
#endif
#define SOC_MEDIA_CRG_CLKDIV1_div_ldi1_START (0)
#define SOC_MEDIA_CRG_CLKDIV1_div_ldi1_END (5)
#define SOC_MEDIA_CRG_CLKDIV1_sel_ldi1_pll_START (6)
#define SOC_MEDIA_CRG_CLKDIV1_sel_ldi1_pll_END (9)
#define SOC_MEDIA_CRG_CLKDIV1_sel_vcodecbus_pll_START (10)
#define SOC_MEDIA_CRG_CLKDIV1_sel_vcodecbus_pll_END (13)
#define SOC_MEDIA_CRG_CLKDIV1_sel_ivp32dsp_core_pll_START (14)
#define SOC_MEDIA_CRG_CLKDIV1_sel_ivp32dsp_core_pll_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_edc0 : 6;
        unsigned int sel_edc0_pll : 4;
        unsigned int div_ivp32dsp_core : 6;
        unsigned int reserved : 16;
    } reg;
} SOC_MEDIA_CRG_CLKDIV2_UNION;
#endif
#define SOC_MEDIA_CRG_CLKDIV2_div_edc0_START (0)
#define SOC_MEDIA_CRG_CLKDIV2_div_edc0_END (5)
#define SOC_MEDIA_CRG_CLKDIV2_sel_edc0_pll_START (6)
#define SOC_MEDIA_CRG_CLKDIV2_sel_edc0_pll_END (9)
#define SOC_MEDIA_CRG_CLKDIV2_div_ivp32dsp_core_START (10)
#define SOC_MEDIA_CRG_CLKDIV2_div_ivp32dsp_core_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_ispfunc : 6;
        unsigned int sel_ispfunc_pll : 4;
        unsigned int div_venc : 6;
        unsigned int reserved : 16;
    } reg;
} SOC_MEDIA_CRG_CLKDIV3_UNION;
#endif
#define SOC_MEDIA_CRG_CLKDIV3_div_ispfunc_START (0)
#define SOC_MEDIA_CRG_CLKDIV3_div_ispfunc_END (5)
#define SOC_MEDIA_CRG_CLKDIV3_sel_ispfunc_pll_START (6)
#define SOC_MEDIA_CRG_CLKDIV3_sel_ispfunc_pll_END (9)
#define SOC_MEDIA_CRG_CLKDIV3_div_venc_START (10)
#define SOC_MEDIA_CRG_CLKDIV3_div_venc_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_isp_cpu : 6;
        unsigned int sel_isp_cpu_pll : 2;
        unsigned int reserved_0 : 2;
        unsigned int div_vdec : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_MEDIA_CRG_CLKDIV4_UNION;
#endif
#define SOC_MEDIA_CRG_CLKDIV4_div_isp_cpu_START (0)
#define SOC_MEDIA_CRG_CLKDIV4_div_isp_cpu_END (5)
#define SOC_MEDIA_CRG_CLKDIV4_sel_isp_cpu_pll_START (6)
#define SOC_MEDIA_CRG_CLKDIV4_sel_isp_cpu_pll_END (7)
#define SOC_MEDIA_CRG_CLKDIV4_div_vdec_START (10)
#define SOC_MEDIA_CRG_CLKDIV4_div_vdec_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_vivobus : 6;
        unsigned int sel_vivobus_pll : 4;
        unsigned int div_vcodecbus : 6;
        unsigned int reserved : 16;
    } reg;
} SOC_MEDIA_CRG_CLKDIV5_UNION;
#endif
#define SOC_MEDIA_CRG_CLKDIV5_div_vivobus_START (0)
#define SOC_MEDIA_CRG_CLKDIV5_div_vivobus_END (5)
#define SOC_MEDIA_CRG_CLKDIV5_sel_vivobus_pll_START (6)
#define SOC_MEDIA_CRG_CLKDIV5_sel_vivobus_pll_END (9)
#define SOC_MEDIA_CRG_CLKDIV5_div_vcodecbus_START (10)
#define SOC_MEDIA_CRG_CLKDIV5_div_vcodecbus_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_venc_pll : 2;
        unsigned int sel_isp_i2c : 1;
        unsigned int div_cnn : 6;
        unsigned int sel_cnn_pll : 4;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_MEDIA_CRG_CLKDIV6_UNION;
#endif
#define SOC_MEDIA_CRG_CLKDIV6_sel_venc_pll_START (0)
#define SOC_MEDIA_CRG_CLKDIV6_sel_venc_pll_END (1)
#define SOC_MEDIA_CRG_CLKDIV6_sel_isp_i2c_START (2)
#define SOC_MEDIA_CRG_CLKDIV6_sel_isp_i2c_END (2)
#define SOC_MEDIA_CRG_CLKDIV6_div_cnn_START (3)
#define SOC_MEDIA_CRG_CLKDIV6_div_cnn_END (8)
#define SOC_MEDIA_CRG_CLKDIV6_sel_cnn_pll_START (9)
#define SOC_MEDIA_CRG_CLKDIV6_sel_cnn_pll_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_MEDIA_CRG_CLKDIV7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_MEDIA_CRG_CLKDIV8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_gt_clk_venc : 1;
        unsigned int sc_gt_clk_vdec : 1;
        unsigned int sc_gt_clk_vcodecbus : 1;
        unsigned int sc_gt_clk_vivobus : 1;
        unsigned int sc_gt_clk_ivp32dsp_core : 1;
        unsigned int sc_gt_clk_isp_cpu : 1;
        unsigned int sc_gt_clk_ispfunc : 1;
        unsigned int sc_gt_clk_edc0 : 1;
        unsigned int sc_gt_clk_ldi1 : 1;
        unsigned int sc_gt_clk_ldi0 : 1;
        unsigned int sc_gt_clk_cnn : 1;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_MEDIA_CRG_CLKDIV9_UNION;
#endif
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_venc_START (0)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_venc_END (0)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_vdec_START (1)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_vdec_END (1)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_vcodecbus_START (2)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_vcodecbus_END (2)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_vivobus_START (3)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_vivobus_END (3)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_ivp32dsp_core_START (4)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_ivp32dsp_core_END (4)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_isp_cpu_START (5)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_isp_cpu_END (5)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_ispfunc_START (6)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_ispfunc_END (6)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_edc0_START (7)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_edc0_END (7)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_ldi1_START (8)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_ldi1_END (8)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_ldi0_START (9)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_ldi0_END (9)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_cnn_START (10)
#define SOC_MEDIA_CRG_CLKDIV9_sc_gt_clk_cnn_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int swdone_clk_venc_div : 1;
        unsigned int swdone_clk_vdec_div : 1;
        unsigned int swdone_clk_vcodecbus_div : 1;
        unsigned int swdone_clk_vivobus_div : 1;
        unsigned int swdone_clk_ivp32dsp_core_div : 1;
        unsigned int swdone_clk_isp_cpu_div : 1;
        unsigned int swdone_clk_ispfunc_div : 1;
        unsigned int swdone_clk_edc0_div : 1;
        unsigned int swdone_clk_ldi1_div : 1;
        unsigned int swdone_clk_ldi0_div : 1;
        unsigned int swdone_clk_cnn_div : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_MEDIA_CRG_PERI_STAT0_UNION;
#endif
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_venc_div_START (0)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_venc_div_END (0)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_vdec_div_START (1)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_vdec_div_END (1)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_vcodecbus_div_START (2)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_vcodecbus_div_END (2)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_vivobus_div_START (3)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_vivobus_div_END (3)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_ivp32dsp_core_div_START (4)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_ivp32dsp_core_div_END (4)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_isp_cpu_div_START (5)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_isp_cpu_div_END (5)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_ispfunc_div_START (6)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_ispfunc_div_END (6)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_edc0_div_START (7)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_edc0_div_END (7)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_ldi1_div_START (8)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_ldi1_div_END (8)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_ldi0_div_START (9)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_ldi0_div_END (9)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_cnn_div_START (10)
#define SOC_MEDIA_CRG_PERI_STAT0_swdone_clk_cnn_div_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ldi0_pll_sw_ack : 4;
        unsigned int ldi1_pll_sw_ack : 4;
        unsigned int edc0_pll_sw_ack : 4;
        unsigned int ispfunc_pll_sw_ack : 4;
        unsigned int vivobus_pll_sw_ack : 4;
        unsigned int vcodecbus_pll_sw_ack : 4;
        unsigned int vdec_pll_sw_ack : 4;
        unsigned int venc_pll_sw_ack : 3;
        unsigned int reserved : 1;
    } reg;
} SOC_MEDIA_CRG_PERI_STAT1_UNION;
#endif
#define SOC_MEDIA_CRG_PERI_STAT1_ldi0_pll_sw_ack_START (0)
#define SOC_MEDIA_CRG_PERI_STAT1_ldi0_pll_sw_ack_END (3)
#define SOC_MEDIA_CRG_PERI_STAT1_ldi1_pll_sw_ack_START (4)
#define SOC_MEDIA_CRG_PERI_STAT1_ldi1_pll_sw_ack_END (7)
#define SOC_MEDIA_CRG_PERI_STAT1_edc0_pll_sw_ack_START (8)
#define SOC_MEDIA_CRG_PERI_STAT1_edc0_pll_sw_ack_END (11)
#define SOC_MEDIA_CRG_PERI_STAT1_ispfunc_pll_sw_ack_START (12)
#define SOC_MEDIA_CRG_PERI_STAT1_ispfunc_pll_sw_ack_END (15)
#define SOC_MEDIA_CRG_PERI_STAT1_vivobus_pll_sw_ack_START (16)
#define SOC_MEDIA_CRG_PERI_STAT1_vivobus_pll_sw_ack_END (19)
#define SOC_MEDIA_CRG_PERI_STAT1_vcodecbus_pll_sw_ack_START (20)
#define SOC_MEDIA_CRG_PERI_STAT1_vcodecbus_pll_sw_ack_END (23)
#define SOC_MEDIA_CRG_PERI_STAT1_vdec_pll_sw_ack_START (24)
#define SOC_MEDIA_CRG_PERI_STAT1_vdec_pll_sw_ack_END (27)
#define SOC_MEDIA_CRG_PERI_STAT1_venc_pll_sw_ack_START (28)
#define SOC_MEDIA_CRG_PERI_STAT1_venc_pll_sw_ack_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnn_pll_sw_ack : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MEDIA_CRG_PERI_STAT2_UNION;
#endif
#define SOC_MEDIA_CRG_PERI_STAT2_cnn_pll_sw_ack_START (0)
#define SOC_MEDIA_CRG_PERI_STAT2_cnn_pll_sw_ack_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_iso_en : 1;
        unsigned int isp_srt_iso_en : 1;
        unsigned int isp_bpe_iso_en : 1;
        unsigned int ivp32dsp_iso_en : 1;
        unsigned int venc_iso_en : 1;
        unsigned int vdec_iso_en : 1;
        unsigned int cnn_iso_en : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MEDIA_CRG_ISOEN_UNION;
#endif
#define SOC_MEDIA_CRG_ISOEN_isp_iso_en_START (0)
#define SOC_MEDIA_CRG_ISOEN_isp_iso_en_END (0)
#define SOC_MEDIA_CRG_ISOEN_isp_srt_iso_en_START (1)
#define SOC_MEDIA_CRG_ISOEN_isp_srt_iso_en_END (1)
#define SOC_MEDIA_CRG_ISOEN_isp_bpe_iso_en_START (2)
#define SOC_MEDIA_CRG_ISOEN_isp_bpe_iso_en_END (2)
#define SOC_MEDIA_CRG_ISOEN_ivp32dsp_iso_en_START (3)
#define SOC_MEDIA_CRG_ISOEN_ivp32dsp_iso_en_END (3)
#define SOC_MEDIA_CRG_ISOEN_venc_iso_en_START (4)
#define SOC_MEDIA_CRG_ISOEN_venc_iso_en_END (4)
#define SOC_MEDIA_CRG_ISOEN_vdec_iso_en_START (5)
#define SOC_MEDIA_CRG_ISOEN_vdec_iso_en_END (5)
#define SOC_MEDIA_CRG_ISOEN_cnn_iso_en_START (6)
#define SOC_MEDIA_CRG_ISOEN_cnn_iso_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_iso_en : 1;
        unsigned int isp_srt_iso_en : 1;
        unsigned int isp_bpe_iso_en : 1;
        unsigned int ivp32dsp_iso_en : 1;
        unsigned int venc_iso_en : 1;
        unsigned int vdec_iso_en : 1;
        unsigned int cnn_iso_en : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MEDIA_CRG_ISODIS_UNION;
#endif
#define SOC_MEDIA_CRG_ISODIS_isp_iso_en_START (0)
#define SOC_MEDIA_CRG_ISODIS_isp_iso_en_END (0)
#define SOC_MEDIA_CRG_ISODIS_isp_srt_iso_en_START (1)
#define SOC_MEDIA_CRG_ISODIS_isp_srt_iso_en_END (1)
#define SOC_MEDIA_CRG_ISODIS_isp_bpe_iso_en_START (2)
#define SOC_MEDIA_CRG_ISODIS_isp_bpe_iso_en_END (2)
#define SOC_MEDIA_CRG_ISODIS_ivp32dsp_iso_en_START (3)
#define SOC_MEDIA_CRG_ISODIS_ivp32dsp_iso_en_END (3)
#define SOC_MEDIA_CRG_ISODIS_venc_iso_en_START (4)
#define SOC_MEDIA_CRG_ISODIS_venc_iso_en_END (4)
#define SOC_MEDIA_CRG_ISODIS_vdec_iso_en_START (5)
#define SOC_MEDIA_CRG_ISODIS_vdec_iso_en_END (5)
#define SOC_MEDIA_CRG_ISODIS_cnn_iso_en_START (6)
#define SOC_MEDIA_CRG_ISODIS_cnn_iso_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_iso_en : 1;
        unsigned int isp_srt_iso_en : 1;
        unsigned int isp_bpe_iso_en : 1;
        unsigned int ivp32dsp_iso_en : 1;
        unsigned int venc_iso_en : 1;
        unsigned int vdec_iso_en : 1;
        unsigned int cnn_iso_en : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MEDIA_CRG_ISOSTAT_UNION;
#endif
#define SOC_MEDIA_CRG_ISOSTAT_isp_iso_en_START (0)
#define SOC_MEDIA_CRG_ISOSTAT_isp_iso_en_END (0)
#define SOC_MEDIA_CRG_ISOSTAT_isp_srt_iso_en_START (1)
#define SOC_MEDIA_CRG_ISOSTAT_isp_srt_iso_en_END (1)
#define SOC_MEDIA_CRG_ISOSTAT_isp_bpe_iso_en_START (2)
#define SOC_MEDIA_CRG_ISOSTAT_isp_bpe_iso_en_END (2)
#define SOC_MEDIA_CRG_ISOSTAT_ivp32dsp_iso_en_START (3)
#define SOC_MEDIA_CRG_ISOSTAT_ivp32dsp_iso_en_END (3)
#define SOC_MEDIA_CRG_ISOSTAT_venc_iso_en_START (4)
#define SOC_MEDIA_CRG_ISOSTAT_venc_iso_en_END (4)
#define SOC_MEDIA_CRG_ISOSTAT_vdec_iso_en_START (5)
#define SOC_MEDIA_CRG_ISOSTAT_vdec_iso_en_END (5)
#define SOC_MEDIA_CRG_ISOSTAT_cnn_iso_en_START (6)
#define SOC_MEDIA_CRG_ISOSTAT_cnn_iso_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vcodecbus_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_MEDIA_CRG_IPCLKRST_BYPASS_UNION;
#endif
#define SOC_MEDIA_CRG_IPCLKRST_BYPASS_vcodecbus_clkrst_bypass_START (0)
#define SOC_MEDIA_CRG_IPCLKRST_BYPASS_vcodecbus_clkrst_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clkinen : 1;
        unsigned int atclkoff_n : 1;
        unsigned int pclkdbg_to_asyn_bri_clkoff_n : 1;
        unsigned int atclk_to_asyn_bri_clkoff_n : 1;
        unsigned int pclkdbg_to_cs_clkoff_n : 1;
        unsigned int aclkenm_sel : 1;
        unsigned int sys_cnt_en_dly : 4;
        unsigned int periphclk_div : 3;
        unsigned int axi_clkoff_n : 1;
        unsigned int periphclkoff_n : 1;
        unsigned int reserved : 1;
        unsigned int clkmasken : 16;
    } reg;
} SOC_MEDIA_CRG_ISPCPU_CLKEN_UNION;
#endif
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_clkinen_START (0)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_clkinen_END (0)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_atclkoff_n_START (1)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_atclkoff_n_END (1)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_pclkdbg_to_asyn_bri_clkoff_n_START (2)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_pclkdbg_to_asyn_bri_clkoff_n_END (2)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_atclk_to_asyn_bri_clkoff_n_START (3)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_atclk_to_asyn_bri_clkoff_n_END (3)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_pclkdbg_to_cs_clkoff_n_START (4)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_pclkdbg_to_cs_clkoff_n_END (4)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_aclkenm_sel_START (5)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_aclkenm_sel_END (5)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_sys_cnt_en_dly_START (6)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_sys_cnt_en_dly_END (9)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_periphclk_div_START (10)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_periphclk_div_END (12)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_axi_clkoff_n_START (13)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_axi_clkoff_n_END (13)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_periphclkoff_n_START (14)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_periphclkoff_n_END (14)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_clkmasken_START (16)
#define SOC_MEDIA_CRG_ISPCPU_CLKEN_clkmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_por_rst_req : 1;
        unsigned int rst_software_req : 1;
        unsigned int core_rst_software_req : 1;
        unsigned int debug_all_rst_req : 1;
        unsigned int core_debug_rst_req : 1;
        unsigned int coresight_soft_rst_req : 1;
        unsigned int dbgrstreq : 1;
        unsigned int reserved_0 : 1;
        unsigned int wdreset_req : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_MEDIA_CRG_ISPCPU_RSTEN_UNION;
#endif
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_core_por_rst_req_START (0)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_core_por_rst_req_END (0)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_rst_software_req_START (1)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_rst_software_req_END (1)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_core_rst_software_req_START (2)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_core_rst_software_req_END (2)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_debug_all_rst_req_START (3)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_debug_all_rst_req_END (3)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_core_debug_rst_req_START (4)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_core_debug_rst_req_END (4)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_coresight_soft_rst_req_START (5)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_coresight_soft_rst_req_END (5)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_dbgrstreq_START (6)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_dbgrstreq_END (6)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_wdreset_req_START (8)
#define SOC_MEDIA_CRG_ISPCPU_RSTEN_wdreset_req_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_por_rst_req : 1;
        unsigned int rst_software_req : 1;
        unsigned int core_rst_software_req : 1;
        unsigned int debug_all_rst_req : 1;
        unsigned int core_debug_rst_req : 1;
        unsigned int coresight_soft_rst_req : 1;
        unsigned int dbgrstreq : 1;
        unsigned int reserved_0 : 1;
        unsigned int wdreset_req : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_MEDIA_CRG_ISPCPU_RSTDIS_UNION;
#endif
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_core_por_rst_req_START (0)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_core_por_rst_req_END (0)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_rst_software_req_START (1)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_rst_software_req_END (1)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_core_rst_software_req_START (2)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_core_rst_software_req_END (2)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_debug_all_rst_req_START (3)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_debug_all_rst_req_END (3)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_core_debug_rst_req_START (4)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_core_debug_rst_req_END (4)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_coresight_soft_rst_req_START (5)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_coresight_soft_rst_req_END (5)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_dbgrstreq_START (6)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_dbgrstreq_END (6)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_wdreset_req_START (8)
#define SOC_MEDIA_CRG_ISPCPU_RSTDIS_wdreset_req_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_por_rst_req : 1;
        unsigned int rst_software_req : 1;
        unsigned int core_rst_software_req : 1;
        unsigned int debug_all_rst_req : 1;
        unsigned int core_debug_rst_req : 1;
        unsigned int coresight_soft_rst_req : 1;
        unsigned int dbgrstreq : 1;
        unsigned int reserved_0 : 1;
        unsigned int wdreset_req : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_MEDIA_CRG_ISPCPU_RSTSTAT_UNION;
#endif
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_core_por_rst_req_START (0)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_core_por_rst_req_END (0)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_rst_software_req_START (1)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_rst_software_req_END (1)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_core_rst_software_req_START (2)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_core_rst_software_req_END (2)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_debug_all_rst_req_START (3)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_debug_all_rst_req_END (3)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_core_debug_rst_req_START (4)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_core_debug_rst_req_END (4)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_coresight_soft_rst_req_START (5)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_coresight_soft_rst_req_END (5)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_dbgrstreq_START (6)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_dbgrstreq_END (6)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_wdreset_req_START (8)
#define SOC_MEDIA_CRG_ISPCPU_RSTSTAT_wdreset_req_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int standbywfi : 1;
        unsigned int standbywfe : 1;
        unsigned int smpnamp : 1;
        unsigned int scuidle : 1;
        unsigned int dbgack : 1;
        unsigned int dbgcpudone : 1;
        unsigned int pmupirv : 1;
        unsigned int fpuflags0 : 6;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_MEDIA_CRG_ISP_CPU_STATE0_UNION;
#endif
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_standbywfi_START (0)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_standbywfi_END (0)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_standbywfe_START (1)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_standbywfe_END (1)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_smpnamp_START (2)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_smpnamp_END (2)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_scuidle_START (3)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_scuidle_END (3)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_dbgack_START (4)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_dbgack_END (4)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_dbgcpudone_START (5)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_dbgcpudone_END (5)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_pmupirv_START (6)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_pmupirv_END (6)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_fpuflags0_START (7)
#define SOC_MEDIA_CRG_ISP_CPU_STATE0_fpuflags0_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_MEDIA_CRG_ISP_CPU_STATE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp_div_auto_reduce_bypass : 1;
        unsigned int ivp_auto_waitcfg_in : 10;
        unsigned int ivp_auto_waitcfg_out : 9;
        unsigned int ivp_dw_axi_m5_st_bypass : 1;
        unsigned int ivp_div_auto_cfg : 6;
        unsigned int ivp_pwaitmode_bypass : 1;
        unsigned int ivp_dw_axi_m1_st_bypass : 1;
        unsigned int ivp_dw_axi_m2_st_bypass : 1;
        unsigned int ivp_dw_axi_m3_st_bypass : 1;
        unsigned int ivp_dw_axi_m4_st_bypass : 1;
    } reg;
} SOC_MEDIA_CRG_PERI_AUTODIV0_UNION;
#endif
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_auto_waitcfg_in_START (1)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_auto_waitcfg_in_END (10)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_auto_waitcfg_out_START (11)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_auto_waitcfg_out_END (19)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_dw_axi_m5_st_bypass_START (20)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_dw_axi_m5_st_bypass_END (20)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_div_auto_cfg_START (21)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_div_auto_cfg_END (26)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_pwaitmode_bypass_START (27)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_pwaitmode_bypass_END (27)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_dw_axi_m1_st_bypass_START (28)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_dw_axi_m1_st_bypass_END (28)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_dw_axi_m2_st_bypass_START (29)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_dw_axi_m2_st_bypass_END (29)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_dw_axi_m3_st_bypass_START (30)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_dw_axi_m3_st_bypass_END (30)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_dw_axi_m4_st_bypass_START (31)
#define SOC_MEDIA_CRG_PERI_AUTODIV0_ivp_dw_axi_m4_st_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isapcpu_div_auto_reduce_bypass : 1;
        unsigned int isapcpu_auto_waitcfg_in : 10;
        unsigned int isapcpu_auto_waitcfg_out : 10;
        unsigned int isapcpu_div_auto_cfg : 6;
        unsigned int reserved : 5;
    } reg;
} SOC_MEDIA_CRG_PERI_AUTODIV1_UNION;
#endif
#define SOC_MEDIA_CRG_PERI_AUTODIV1_isapcpu_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA_CRG_PERI_AUTODIV1_isapcpu_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA_CRG_PERI_AUTODIV1_isapcpu_auto_waitcfg_in_START (1)
#define SOC_MEDIA_CRG_PERI_AUTODIV1_isapcpu_auto_waitcfg_in_END (10)
#define SOC_MEDIA_CRG_PERI_AUTODIV1_isapcpu_auto_waitcfg_out_START (11)
#define SOC_MEDIA_CRG_PERI_AUTODIV1_isapcpu_auto_waitcfg_out_END (20)
#define SOC_MEDIA_CRG_PERI_AUTODIV1_isapcpu_div_auto_cfg_START (21)
#define SOC_MEDIA_CRG_PERI_AUTODIV1_isapcpu_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int venc_div_auto_reduce_bypass : 1;
        unsigned int venc_auto_waitcfg_in : 10;
        unsigned int venc_auto_waitcfg_out : 10;
        unsigned int venc_div_auto_cfg : 6;
        unsigned int venc_vcodecbus_cfg_bypass : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_MEDIA_CRG_PERI_AUTODIV2_UNION;
#endif
#define SOC_MEDIA_CRG_PERI_AUTODIV2_venc_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA_CRG_PERI_AUTODIV2_venc_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA_CRG_PERI_AUTODIV2_venc_auto_waitcfg_in_START (1)
#define SOC_MEDIA_CRG_PERI_AUTODIV2_venc_auto_waitcfg_in_END (10)
#define SOC_MEDIA_CRG_PERI_AUTODIV2_venc_auto_waitcfg_out_START (11)
#define SOC_MEDIA_CRG_PERI_AUTODIV2_venc_auto_waitcfg_out_END (20)
#define SOC_MEDIA_CRG_PERI_AUTODIV2_venc_div_auto_cfg_START (21)
#define SOC_MEDIA_CRG_PERI_AUTODIV2_venc_div_auto_cfg_END (26)
#define SOC_MEDIA_CRG_PERI_AUTODIV2_venc_vcodecbus_cfg_bypass_START (27)
#define SOC_MEDIA_CRG_PERI_AUTODIV2_venc_vcodecbus_cfg_bypass_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdec_div_auto_reduce_bypass : 1;
        unsigned int vdec_auto_waitcfg_in : 10;
        unsigned int vdec_auto_waitcfg_out : 10;
        unsigned int vdec_div_auto_cfg : 6;
        unsigned int vdec_vcodecbus_cfg_bypass : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_MEDIA_CRG_PERI_AUTODIV3_UNION;
#endif
#define SOC_MEDIA_CRG_PERI_AUTODIV3_vdec_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA_CRG_PERI_AUTODIV3_vdec_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA_CRG_PERI_AUTODIV3_vdec_auto_waitcfg_in_START (1)
#define SOC_MEDIA_CRG_PERI_AUTODIV3_vdec_auto_waitcfg_in_END (10)
#define SOC_MEDIA_CRG_PERI_AUTODIV3_vdec_auto_waitcfg_out_START (11)
#define SOC_MEDIA_CRG_PERI_AUTODIV3_vdec_auto_waitcfg_out_END (20)
#define SOC_MEDIA_CRG_PERI_AUTODIV3_vdec_div_auto_cfg_START (21)
#define SOC_MEDIA_CRG_PERI_AUTODIV3_vdec_div_auto_cfg_END (26)
#define SOC_MEDIA_CRG_PERI_AUTODIV3_vdec_vcodecbus_cfg_bypass_START (27)
#define SOC_MEDIA_CRG_PERI_AUTODIV3_vdec_vcodecbus_cfg_bypass_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vivobus_div_auto_reduce_bypass : 1;
        unsigned int vivobus_auto_waitcfg_in : 10;
        unsigned int vivobus_auto_waitcfg_out : 8;
        unsigned int vivobus_isp1_bypass : 1;
        unsigned int vivobus_ispcpu_wfi_bypass : 1;
        unsigned int vivobus_div_auto_cfg : 6;
        unsigned int vivobus_vivo_cfg_bypass : 1;
        unsigned int vivobus_dss0_bypass : 1;
        unsigned int vivobus_dss1_bypass : 1;
        unsigned int vivobus_isp0_bypass : 1;
        unsigned int vivobus_ispcpu_bypass : 1;
    } reg;
} SOC_MEDIA_CRG_PERI_AUTODIV4_UNION;
#endif
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_auto_waitcfg_in_START (1)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_auto_waitcfg_in_END (10)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_auto_waitcfg_out_START (11)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_auto_waitcfg_out_END (18)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_isp1_bypass_START (19)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_isp1_bypass_END (19)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_ispcpu_wfi_bypass_START (20)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_ispcpu_wfi_bypass_END (20)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_div_auto_cfg_START (21)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_div_auto_cfg_END (26)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_vivo_cfg_bypass_START (27)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_vivo_cfg_bypass_END (27)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_dss0_bypass_START (28)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_dss0_bypass_END (28)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_dss1_bypass_START (29)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_dss1_bypass_END (29)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_isp0_bypass_START (30)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_isp0_bypass_END (30)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_ispcpu_bypass_START (31)
#define SOC_MEDIA_CRG_PERI_AUTODIV4_vivobus_ispcpu_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vcodecbus_div_auto_reduce_bypass : 1;
        unsigned int vcodecbus_auto_waitcfg_in : 10;
        unsigned int vcodecbus_auto_waitcfg_out : 9;
        unsigned int vcodecbus_cnn_bypass : 1;
        unsigned int vcodecbus_div_auto_cfg : 6;
        unsigned int vcodecbus_vcodec_cfg_bypass : 1;
        unsigned int vcodecbus_venc_idle_bypass : 1;
        unsigned int vcodecbus_vdec_idle_bypass : 1;
        unsigned int vcodecbus_venc_bypass : 1;
        unsigned int vcodecbus_vdec_bypass : 1;
    } reg;
} SOC_MEDIA_CRG_PERI_AUTODIV5_UNION;
#endif
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_auto_waitcfg_in_START (1)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_auto_waitcfg_in_END (10)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_auto_waitcfg_out_START (11)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_auto_waitcfg_out_END (19)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_cnn_bypass_START (20)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_cnn_bypass_END (20)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_div_auto_cfg_START (21)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_div_auto_cfg_END (26)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_vcodec_cfg_bypass_START (27)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_vcodec_cfg_bypass_END (27)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_venc_idle_bypass_START (28)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_venc_idle_bypass_END (28)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_vdec_idle_bypass_START (29)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_vdec_idle_bypass_END (29)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_venc_bypass_START (30)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_venc_bypass_END (30)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_vdec_bypass_START (31)
#define SOC_MEDIA_CRG_PERI_AUTODIV5_vcodecbus_vdec_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 30;
    } reg;
} SOC_MEDIA_CRG_PERI_AUTODIV6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int autodiv_ispcpu_stat : 1;
        unsigned int autodiv_vdec_stat : 1;
        unsigned int autodiv_venc_stat : 1;
        unsigned int autodiv_vivobus_stat : 1;
        unsigned int autodiv_vcodecbus_stat : 1;
        unsigned int autodiv_ivp32dsp_stat : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_UNION;
#endif
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_autodiv_ispcpu_stat_START (0)
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_autodiv_ispcpu_stat_END (0)
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_autodiv_vdec_stat_START (1)
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_autodiv_vdec_stat_END (1)
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_autodiv_venc_stat_START (2)
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_autodiv_venc_stat_END (2)
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_autodiv_vivobus_stat_START (3)
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_autodiv_vivobus_stat_END (3)
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_autodiv_vcodecbus_stat_START (4)
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_autodiv_vcodecbus_stat_END (4)
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_autodiv_ivp32dsp_stat_START (5)
#define SOC_MEDIA_CRG_MEDIA_AUTODIV_STAT_autodiv_ivp32dsp_stat_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_isp : 1;
        unsigned int ip_arst_isp : 1;
        unsigned int ip_rst_isp_cfgtoisp : 1;
        unsigned int ip_rst_isp_cputocfg : 1;
        unsigned int ip_rst_isp_cpu : 1;
        unsigned int ip_rst_isp_sys : 1;
        unsigned int ip_rst_isp_i2c : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_UNION;
#endif
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_START (0)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_END (0)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_arst_isp_START (1)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_arst_isp_END (1)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_cfgtoisp_START (2)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_cfgtoisp_END (2)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_cputocfg_START (3)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_cputocfg_END (3)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_cpu_START (4)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_cpu_END (4)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_sys_START (5)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_sys_END (5)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_i2c_START (6)
#define SOC_MEDIA_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_i2c_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_isp : 1;
        unsigned int ip_arst_isp : 1;
        unsigned int ip_rst_isp_cfgtoisp : 1;
        unsigned int ip_rst_isp_cputocfg : 1;
        unsigned int ip_rst_isp_cpu : 1;
        unsigned int ip_rst_isp_sys : 1;
        unsigned int ip_rst_isp_i2c : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_UNION;
#endif
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_START (0)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_END (0)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_arst_isp_START (1)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_arst_isp_END (1)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_cfgtoisp_START (2)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_cfgtoisp_END (2)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_cputocfg_START (3)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_cputocfg_END (3)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_cpu_START (4)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_cpu_END (4)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_sys_START (5)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_sys_END (5)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_i2c_START (6)
#define SOC_MEDIA_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_i2c_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_isp : 1;
        unsigned int ip_arst_isp : 1;
        unsigned int ip_rst_isp_cfgtoisp : 1;
        unsigned int ip_rst_isp_cputocfg : 1;
        unsigned int ip_rst_isp_cpu : 1;
        unsigned int ip_rst_isp_sys : 1;
        unsigned int ip_rst_isp_i2c : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_UNION;
#endif
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_START (0)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_END (0)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_arst_isp_START (1)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_arst_isp_END (1)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_cfgtoisp_START (2)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_cfgtoisp_END (2)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_cputocfg_START (3)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_cputocfg_END (3)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_cpu_START (4)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_cpu_END (4)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_sys_START (5)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_sys_END (5)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_i2c_START (6)
#define SOC_MEDIA_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_i2c_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfgend : 1;
        unsigned int vinithi : 1;
        unsigned int initram0 : 1;
        unsigned int cfgnmfi : 1;
        unsigned int cpuhalt : 1;
        unsigned int reserved : 11;
        unsigned int mem_ctrl_s : 16;
    } reg;
} SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_UNION;
#endif
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_cfgend_START (0)
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_cfgend_END (0)
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_vinithi_START (1)
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_vinithi_END (1)
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_initram0_START (2)
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_initram0_END (2)
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_cfgnmfi_START (3)
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_cfgnmfi_END (3)
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_cpuhalt_START (4)
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_cpuhalt_END (4)
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_mem_ctrl_s_START (16)
#define SOC_MEDIA_CRG_ISPCPU_CTRL0_SEC_mem_ctrl_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_ivp32dsp_subsys_crg : 1;
        unsigned int ip_rst_ivp32dsp_subsys : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MEDIA_CRG_PERRSTEN_SEC_IVP_UNION;
#endif
#define SOC_MEDIA_CRG_PERRSTEN_SEC_IVP_ip_rst_ivp32dsp_subsys_crg_START (0)
#define SOC_MEDIA_CRG_PERRSTEN_SEC_IVP_ip_rst_ivp32dsp_subsys_crg_END (0)
#define SOC_MEDIA_CRG_PERRSTEN_SEC_IVP_ip_rst_ivp32dsp_subsys_START (1)
#define SOC_MEDIA_CRG_PERRSTEN_SEC_IVP_ip_rst_ivp32dsp_subsys_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_ivp32dsp_subsys_crg : 1;
        unsigned int ip_rst_ivp32dsp_subsys : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MEDIA_CRG_PERRSTDIS_SEC_IVP_UNION;
#endif
#define SOC_MEDIA_CRG_PERRSTDIS_SEC_IVP_ip_rst_ivp32dsp_subsys_crg_START (0)
#define SOC_MEDIA_CRG_PERRSTDIS_SEC_IVP_ip_rst_ivp32dsp_subsys_crg_END (0)
#define SOC_MEDIA_CRG_PERRSTDIS_SEC_IVP_ip_rst_ivp32dsp_subsys_START (1)
#define SOC_MEDIA_CRG_PERRSTDIS_SEC_IVP_ip_rst_ivp32dsp_subsys_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_ivp32dsp_subsys_crg : 1;
        unsigned int ip_rst_ivp32dsp_subsys : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MEDIA_CRG_PERRSTSTAT_SEC_IVP_UNION;
#endif
#define SOC_MEDIA_CRG_PERRSTSTAT_SEC_IVP_ip_rst_ivp32dsp_subsys_crg_START (0)
#define SOC_MEDIA_CRG_PERRSTSTAT_SEC_IVP_ip_rst_ivp32dsp_subsys_crg_END (0)
#define SOC_MEDIA_CRG_PERRSTSTAT_SEC_IVP_ip_rst_ivp32dsp_subsys_START (1)
#define SOC_MEDIA_CRG_PERRSTSTAT_SEC_IVP_ip_rst_ivp32dsp_subsys_END (1)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

#ifndef __SOC_ISP_SUBCTRL_INTERFACE_H__
#define __SOC_ISP_SUBCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_ADDR(base) ((base) + (0x0))
#define SOC_ISP_SUBCTRL_ISP_CORE_CFG_ADDR(base) ((base) + (0x4))
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_0_ADDR(base) ((base) + (0x8))
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_1_ADDR(base) ((base) + (0xC))
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_2_ADDR(base) ((base) + (0x10))
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_3_ADDR(base) ((base) + (0x14))
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_4_ADDR(base) ((base) + (0x18))
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_5_ADDR(base) ((base) + (0x1C))
#define SOC_ISP_SUBCTRL_ISP_CORE_CTRL_0_ADDR(base) ((base) + (0x20))
#define SOC_ISP_SUBCTRL_VIC0_OUT0_ADDR(base) ((base) + (0x28))
#define SOC_ISP_SUBCTRL_VIC0_IN0_ADDR(base) ((base) + (0x2C))
#define SOC_ISP_SUBCTRL_VIC0_IN1_ADDR(base) ((base) + (0x30))
#define SOC_ISP_SUBCTRL_VIC1_OUT0_ADDR(base) ((base) + (0x34))
#define SOC_ISP_SUBCTRL_VIC1_IN0_ADDR(base) ((base) + (0x38))
#define SOC_ISP_SUBCTRL_VIC1_IN1_ADDR(base) ((base) + (0x3C))
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_0_ADDR(base) ((base) + (0x40))
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_1_ADDR(base) ((base) + (0x44))
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG0_ADDR(base) ((base) + (0x50))
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG1_ADDR(base) ((base) + (0x54))
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG2_ADDR(base) ((base) + (0x58))
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG3_ADDR(base) ((base) + (0x5C))
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ0_ADDR(base) ((base) + (0x60))
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ1_ADDR(base) ((base) + (0x64))
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ2_ADDR(base) ((base) + (0x68))
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ3_ADDR(base) ((base) + (0x6C))
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ_VEC_ADDR(base) ((base) + (0x70))
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_2_ADDR(base) ((base) + (0x100))
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_3_ADDR(base) ((base) + (0x104))
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_4_ADDR(base) ((base) + (0x108))
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_5_ADDR(base) ((base) + (0x10C))
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_6_ADDR(base) ((base) + (0x110))
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_7_ADDR(base) ((base) + (0x114))
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_8_ADDR(base) ((base) + (0x118))
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_9_ADDR(base) ((base) + (0x120))
#define SOC_ISP_SUBCTRL_ISP_SMMU_MEM_CTRL_ADDR(base) ((base) + (0x124))
#define SOC_ISP_SUBCTRL_ISP_SMMU_CTRL_ADDR(base) ((base) + (0x128))
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL0_0_ADDR(base) ((base) + (0x180))
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL0_1_ADDR(base) ((base) + (0x184))
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL1_0_ADDR(base) ((base) + (0x188))
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL1_1_ADDR(base) ((base) + (0x18C))
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL2_0_ADDR(base) ((base) + (0x190))
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL2_1_ADDR(base) ((base) + (0x194))
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL3_0_ADDR(base) ((base) + (0x198))
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL3_1_ADDR(base) ((base) + (0x19C))
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL4_0_ADDR(base) ((base) + (0x1A0))
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL4_1_ADDR(base) ((base) + (0x1A4))
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL5_0_ADDR(base) ((base) + (0x1A8))
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL5_1_ADDR(base) ((base) + (0x1AC))
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_ADDR(base) ((base) + (0x1B0))
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_1_ADDR(base) ((base) + (0x1B4))
#define SOC_ISP_SUBCTRL_ISP_mon_addr_0_ADDR(base) ((base) + (0x1B8))
#define SOC_ISP_SUBCTRL_ISP_mon_addr_1_ADDR(base) ((base) + (0x1BC))
#define SOC_ISP_SUBCTRL_ISP_mon_addr_2_ADDR(base) ((base) + (0x1C0))
#define SOC_ISP_SUBCTRL_ISP_mon_addr_3_ADDR(base) ((base) + (0x1C4))
#define SOC_ISP_SUBCTRL_ISP_addr_hit_stat_ADDR(base) ((base) + (0x1C8))
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_0_ADDR(base) ((base) + (0x1CC))
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_1_ADDR(base) ((base) + (0x1D0))
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_2_ADDR(base) ((base) + (0x1D4))
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_3_ADDR(base) ((base) + (0x1D8))
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_0_ADDR(base) ((base) + (0x1DC))
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_1_ADDR(base) ((base) + (0x1E0))
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_2_ADDR(base) ((base) + (0x1E4))
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_3_ADDR(base) ((base) + (0x1E8))
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_0_ADDR(base) ((base) + (0x1EC))
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_1_ADDR(base) ((base) + (0x1F0))
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_2_ADDR(base) ((base) + (0x1F4))
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_3_ADDR(base) ((base) + (0x1F8))
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_0_ADDR(base) ((base) + (0x1FC))
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_1_ADDR(base) ((base) + (0x200))
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_2_ADDR(base) ((base) + (0x204))
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_3_ADDR(base) ((base) + (0x208))
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_0_ADDR(base) ((base) + (0x20C))
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_1_ADDR(base) ((base) + (0x210))
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_2_ADDR(base) ((base) + (0x214))
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_3_ADDR(base) ((base) + (0x218))
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_0_ADDR(base) ((base) + (0x21C))
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_1_ADDR(base) ((base) + (0x220))
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_2_ADDR(base) ((base) + (0x224))
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_3_ADDR(base) ((base) + (0x228))
#define SOC_ISP_SUBCTRL_VIC2_OUT0_ADDR(base) ((base) + (0x22c))
#define SOC_ISP_SUBCTRL_VIC2_IN0_ADDR(base) ((base) + (0x230))
#define SOC_ISP_SUBCTRL_VIC2_IN1_ADDR(base) ((base) + (0x234))
#define SOC_ISP_SUBCTRL_P2P_CTRL_ADDR(base) ((base) + (0x238))
#define SOC_ISP_SUBCTRL_RESERVED_REG_ADDR(base) ((base) + (0x6fc))
#define SOC_ISP_SUBCTRL_ISP_CORE_CTRL_1_ADDR(base) ((base) + (0x700))
#define SOC_ISP_SUBCTRL_ISP_CORE_CTRL_S_ADDR(base) ((base) + (0x800))
#define SOC_ISP_SUBCTRL_ISP_SUB_CTRL_S_ADDR(base) ((base) + (0x804))
#define SOC_ISP_SUBCTRL_ISP_CPU_SMMU_CTRL_S_ADDR(base) ((base) + (0x808))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_wdt_clken : 1;
        unsigned int isp_ipc_clken : 1;
        unsigned int isp_tim_clken : 1;
        unsigned int sub_ctrl_reg0_7to3b : 5;
        unsigned int sub_ctrl_reg0_15to8b : 8;
        unsigned int sub_ctrl_reg0_23to16b : 8;
        unsigned int sub_ctrl_reg0_28to24b : 5;
        unsigned int isp_wdt_soft_rst : 1;
        unsigned int isp_ipc_soft_rst : 1;
        unsigned int isp_tim_soft_rst : 1;
    } reg;
} SOC_ISP_SUBCTRL_SUBSYS_CFG_UNION;
#endif
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_isp_wdt_clken_START (0)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_isp_wdt_clken_END (0)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_isp_ipc_clken_START (1)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_isp_ipc_clken_END (1)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_isp_tim_clken_START (2)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_isp_tim_clken_END (2)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_sub_ctrl_reg0_7to3b_START (3)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_sub_ctrl_reg0_7to3b_END (7)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_sub_ctrl_reg0_15to8b_START (8)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_sub_ctrl_reg0_15to8b_END (15)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_sub_ctrl_reg0_23to16b_START (16)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_sub_ctrl_reg0_23to16b_END (23)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_sub_ctrl_reg0_28to24b_START (24)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_sub_ctrl_reg0_28to24b_END (28)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_isp_wdt_soft_rst_START (29)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_isp_wdt_soft_rst_END (29)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_isp_ipc_soft_rst_START (30)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_isp_ipc_soft_rst_END (30)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_isp_tim_soft_rst_START (31)
#define SOC_ISP_SUBCTRL_SUBSYS_CFG_isp_tim_soft_rst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub_ctrl_reg1_7to0b : 8;
        unsigned int sub_ctrl_reg1_15to8b : 8;
        unsigned int isp_dec_bus_err_irq_msk : 1;
        unsigned int sub_ctrl_reg1_23to17b : 7;
        unsigned int sub_ctrl_reg1_31to24b : 8;
    } reg;
} SOC_ISP_SUBCTRL_ISP_CORE_CFG_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_CORE_CFG_sub_ctrl_reg1_7to0b_START (0)
#define SOC_ISP_SUBCTRL_ISP_CORE_CFG_sub_ctrl_reg1_7to0b_END (7)
#define SOC_ISP_SUBCTRL_ISP_CORE_CFG_sub_ctrl_reg1_15to8b_START (8)
#define SOC_ISP_SUBCTRL_ISP_CORE_CFG_sub_ctrl_reg1_15to8b_END (15)
#define SOC_ISP_SUBCTRL_ISP_CORE_CFG_isp_dec_bus_err_irq_msk_START (16)
#define SOC_ISP_SUBCTRL_ISP_CORE_CFG_isp_dec_bus_err_irq_msk_END (16)
#define SOC_ISP_SUBCTRL_ISP_CORE_CFG_sub_ctrl_reg1_23to17b_START (17)
#define SOC_ISP_SUBCTRL_ISP_CORE_CFG_sub_ctrl_reg1_23to17b_END (23)
#define SOC_ISP_SUBCTRL_ISP_CORE_CFG_sub_ctrl_reg1_31to24b_START (24)
#define SOC_ISP_SUBCTRL_ISP_CORE_CFG_sub_ctrl_reg1_31to24b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_axi_m1_waddr_err : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_AXI_BUS_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_0_isp_axi_m1_waddr_err_START (0)
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_0_isp_axi_m1_waddr_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_axi_m1_raddr_err : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_AXI_BUS_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_1_isp_axi_m1_raddr_err_START (0)
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_1_isp_axi_m1_raddr_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_axi_m2_waddr_err : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_AXI_BUS_2_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_2_isp_axi_m2_waddr_err_START (0)
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_2_isp_axi_m2_waddr_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_axi_m2_raddr_err : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_AXI_BUS_3_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_3_isp_axi_m2_raddr_err_START (0)
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_3_isp_axi_m2_raddr_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_axi_mst_err_srst_req_apm : 1;
        unsigned int isp_dec_bus_err_irq_clr : 1;
        unsigned int isp_dec_bus_err_irq_force : 1;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_ISP_SUBCTRL_ISP_AXI_BUS_4_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_4_isp_axi_mst_err_srst_req_apm_START (0)
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_4_isp_axi_mst_err_srst_req_apm_END (0)
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_4_isp_dec_bus_err_irq_clr_START (1)
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_4_isp_dec_bus_err_irq_clr_END (1)
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_4_isp_dec_bus_err_irq_force_START (2)
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_4_isp_dec_bus_err_irq_force_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub_ctrl_ro_reg : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_AXI_BUS_5_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_5_sub_ctrl_ro_reg_START (0)
#define SOC_ISP_SUBCTRL_ISP_AXI_BUS_5_sub_ctrl_ro_reg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int subctrl_to_core_grp0 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_CORE_CTRL_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_CORE_CTRL_0_subctrl_to_core_grp0_START (0)
#define SOC_ISP_SUBCTRL_ISP_CORE_CTRL_0_subctrl_to_core_grp0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic0_out_irq_mask : 32;
    } reg;
} SOC_ISP_SUBCTRL_VIC0_OUT0_UNION;
#endif
#define SOC_ISP_SUBCTRL_VIC0_OUT0_vic0_out_irq_mask_START (0)
#define SOC_ISP_SUBCTRL_VIC0_OUT0_vic0_out_irq_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic0_in_irq_level_mask : 32;
    } reg;
} SOC_ISP_SUBCTRL_VIC0_IN0_UNION;
#endif
#define SOC_ISP_SUBCTRL_VIC0_IN0_vic0_in_irq_level_mask_START (0)
#define SOC_ISP_SUBCTRL_VIC0_IN0_vic0_in_irq_level_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic0_in_irq_level_force : 32;
    } reg;
} SOC_ISP_SUBCTRL_VIC0_IN1_UNION;
#endif
#define SOC_ISP_SUBCTRL_VIC0_IN1_vic0_in_irq_level_force_START (0)
#define SOC_ISP_SUBCTRL_VIC0_IN1_vic0_in_irq_level_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic1_out_irq_mask : 32;
    } reg;
} SOC_ISP_SUBCTRL_VIC1_OUT0_UNION;
#endif
#define SOC_ISP_SUBCTRL_VIC1_OUT0_vic1_out_irq_mask_START (0)
#define SOC_ISP_SUBCTRL_VIC1_OUT0_vic1_out_irq_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic1_in_irq_level_mask : 32;
    } reg;
} SOC_ISP_SUBCTRL_VIC1_IN0_UNION;
#endif
#define SOC_ISP_SUBCTRL_VIC1_IN0_vic1_in_irq_level_mask_START (0)
#define SOC_ISP_SUBCTRL_VIC1_IN0_vic1_in_irq_level_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic1_in_irq_level_force : 32;
    } reg;
} SOC_ISP_SUBCTRL_VIC1_IN1_UNION;
#endif
#define SOC_ISP_SUBCTRL_VIC1_IN1_vic1_in_irq_level_force_START (0)
#define SOC_ISP_SUBCTRL_VIC1_IN1_vic1_in_irq_level_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int a7_sub_ctrl0 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_A7_CTRL_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_0_a7_sub_ctrl0_START (0)
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_0_a7_sub_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int a7_sub_ctrl1 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_A7_CTRL_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_1_a7_sub_ctrl1_START (0)
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_1_a7_sub_ctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp_to_isp_irq_msk : 4;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 7;
        unsigned int reserved_3 : 8;
    } reg;
} SOC_ISP_SUBCTRL_ISP_IVP_CFG0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG0_ivp_to_isp_irq_msk_START (0)
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG0_ivp_to_isp_irq_msk_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_to_ivp_irq_set : 4;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_ISP_SUBCTRL_ISP_IVP_CFG1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG1_isp_to_ivp_irq_set_START (0)
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG1_isp_to_ivp_irq_set_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp_to_isp_irq_force : 4;
        unsigned int reserved_0 : 12;
        unsigned int ivp_to_isp_irq_clr : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_ISP_SUBCTRL_ISP_IVP_CFG2_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG2_ivp_to_isp_irq_force_START (0)
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG2_ivp_to_isp_irq_force_END (3)
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG2_ivp_to_isp_irq_clr_START (16)
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG2_ivp_to_isp_irq_clr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp_to_isp_irq_raw_status : 4;
        unsigned int reserved_0 : 12;
        unsigned int ivp_to_isp_irq_mask_status : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_ISP_SUBCTRL_ISP_IVP_CFG3_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG3_ivp_to_isp_irq_raw_status_START (0)
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG3_ivp_to_isp_irq_raw_status_END (3)
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG3_ivp_to_isp_irq_mask_status_START (16)
#define SOC_ISP_SUBCTRL_ISP_IVP_CFG3_ivp_to_isp_irq_mask_status_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_to_ivp_irq0_vec : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_IVP_IRQ0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ0_isp_to_ivp_irq0_vec_START (0)
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ0_isp_to_ivp_irq0_vec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_to_ivp_irq1_vec : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_IVP_IRQ1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ1_isp_to_ivp_irq1_vec_START (0)
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ1_isp_to_ivp_irq1_vec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp_to_isp_irq_vec0 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_IVP_IRQ2_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ2_ivp_to_isp_irq_vec0_START (0)
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ2_ivp_to_isp_irq_vec0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp_to_isp_irq_vec1 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_IVP_IRQ3_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ3_ivp_to_isp_irq_vec1_START (0)
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ3_ivp_to_isp_irq_vec1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp_to_isp_irq_vec : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_IVP_IRQ_VEC_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ_VEC_ivp_to_isp_irq_vec_START (0)
#define SOC_ISP_SUBCTRL_ISP_IVP_IRQ_VEC_ivp_to_isp_irq_vec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int a7_sub_ctrl2 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_A7_CTRL_2_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_2_a7_sub_ctrl2_START (0)
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_2_a7_sub_ctrl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int a7_sub_ctrl3 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_A7_CTRL_3_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_3_a7_sub_ctrl3_START (0)
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_3_a7_sub_ctrl3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int a7_sub_ctrl4 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_A7_CTRL_4_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_4_a7_sub_ctrl4_START (0)
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_4_a7_sub_ctrl4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int a7_sub_ctrl5 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_A7_CTRL_5_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_5_a7_sub_ctrl5_START (0)
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_5_a7_sub_ctrl5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int a7_sub_ctrl6 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_A7_CTRL_6_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_6_a7_sub_ctrl6_START (0)
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_6_a7_sub_ctrl6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int a7_sub_ctrl7 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_A7_CTRL_7_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_7_a7_sub_ctrl7_START (0)
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_7_a7_sub_ctrl7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int a7_sub_ctrl8 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_A7_CTRL_8_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_8_a7_sub_ctrl8_START (0)
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_8_a7_sub_ctrl8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int a7_sub_ctrl9 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_A7_CTRL_9_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_9_a7_sub_ctrl9_START (0)
#define SOC_ISP_SUBCTRL_ISP_A7_CTRL_9_a7_sub_ctrl9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_smmu_mem_ctrl : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_SMMU_MEM_CTRL_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_SMMU_MEM_CTRL_isp_smmu_mem_ctrl_START (0)
#define SOC_ISP_SUBCTRL_ISP_SMMU_MEM_CTRL_isp_smmu_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_smmu_ctrl : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_SMMU_CTRL_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_SMMU_CTRL_isp_smmu_ctrl_START (0)
#define SOC_ISP_SUBCTRL_ISP_SMMU_CTRL_isp_smmu_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl0_cvdr_rt_r : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_FLUX_CTRL0_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL0_0_flux_ctrl0_cvdr_rt_r_START (0)
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL0_0_flux_ctrl0_cvdr_rt_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl1_cvdr_rt_r : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_FLUX_CTRL0_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL0_1_flux_ctrl1_cvdr_rt_r_START (0)
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL0_1_flux_ctrl1_cvdr_rt_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl0_cvdr_rt_w : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_FLUX_CTRL1_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL1_0_flux_ctrl0_cvdr_rt_w_START (0)
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL1_0_flux_ctrl0_cvdr_rt_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl1_cvdr_rt_w : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_FLUX_CTRL1_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL1_1_flux_ctrl1_cvdr_rt_w_START (0)
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL1_1_flux_ctrl1_cvdr_rt_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl0_cvdr_srt_r : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_FLUX_CTRL2_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL2_0_flux_ctrl0_cvdr_srt_r_START (0)
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL2_0_flux_ctrl0_cvdr_srt_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl1_cvdr_srt_r : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_FLUX_CTRL2_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL2_1_flux_ctrl1_cvdr_srt_r_START (0)
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL2_1_flux_ctrl1_cvdr_srt_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl0_cvdr_srt_w : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_FLUX_CTRL3_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL3_0_flux_ctrl0_cvdr_srt_w_START (0)
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL3_0_flux_ctrl0_cvdr_srt_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl1_cvdr_srt_w : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_FLUX_CTRL3_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL3_1_flux_ctrl1_cvdr_srt_w_START (0)
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL3_1_flux_ctrl1_cvdr_srt_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl0_a7_r : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_FLUX_CTRL4_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL4_0_flux_ctrl0_a7_r_START (0)
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL4_0_flux_ctrl0_a7_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl1_a7_r : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_FLUX_CTRL4_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL4_1_flux_ctrl1_a7_r_START (0)
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL4_1_flux_ctrl1_a7_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl0_a7_w : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_FLUX_CTRL5_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL5_0_flux_ctrl0_a7_w_START (0)
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL5_0_flux_ctrl0_a7_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl1_a7_w : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_FLUX_CTRL5_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL5_1_flux_ctrl1_a7_w_START (0)
#define SOC_ISP_SUBCTRL_ISP_FLUX_CTRL5_1_flux_ctrl1_a7_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_addr_mon0_en : 4;
        unsigned int isp_addr_mon1_en : 4;
        unsigned int isp_addr_mon2_en : 4;
        unsigned int isp_addr_mon3_en : 4;
        unsigned int isp_addr_mon0_irq_mask : 4;
        unsigned int isp_addr_mon1_irq_mask : 4;
        unsigned int isp_addr_mon2_irq_mask : 4;
        unsigned int isp_addr_mon3_irq_mask : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon0_en_START (0)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon0_en_END (3)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon1_en_START (4)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon1_en_END (7)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon2_en_START (8)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon2_en_END (11)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon3_en_START (12)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon3_en_END (15)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon0_irq_mask_START (16)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon0_irq_mask_END (19)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon1_irq_mask_START (20)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon1_irq_mask_END (23)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon2_irq_mask_START (24)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon2_irq_mask_END (27)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon3_irq_mask_START (28)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_0_isp_addr_mon3_irq_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_addr_mon_clr : 1;
        unsigned int isp_addr_mon0_sel : 1;
        unsigned int isp_addr_mon1_sel : 1;
        unsigned int isp_addr_mon2_sel : 1;
        unsigned int isp_addr_mon3_sel : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_1_isp_addr_mon_clr_START (0)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_1_isp_addr_mon_clr_END (0)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_1_isp_addr_mon0_sel_START (1)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_1_isp_addr_mon0_sel_END (1)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_1_isp_addr_mon1_sel_START (2)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_1_isp_addr_mon1_sel_END (2)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_1_isp_addr_mon2_sel_START (3)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_1_isp_addr_mon2_sel_END (3)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_1_isp_addr_mon3_sel_START (4)
#define SOC_ISP_SUBCTRL_ISP_ADDR_MON_CTRL_1_isp_addr_mon3_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon_addr_0 : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_ISP_SUBCTRL_ISP_mon_addr_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_mon_addr_0_isp_mon_addr_0_START (0)
#define SOC_ISP_SUBCTRL_ISP_mon_addr_0_isp_mon_addr_0_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon_addr_1 : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_ISP_SUBCTRL_ISP_mon_addr_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_mon_addr_1_isp_mon_addr_1_START (0)
#define SOC_ISP_SUBCTRL_ISP_mon_addr_1_isp_mon_addr_1_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon_addr_2 : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_ISP_SUBCTRL_ISP_mon_addr_2_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_mon_addr_2_isp_mon_addr_2_START (0)
#define SOC_ISP_SUBCTRL_ISP_mon_addr_2_isp_mon_addr_2_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon_addr_3 : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_ISP_SUBCTRL_ISP_mon_addr_3_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_mon_addr_3_isp_mon_addr_3_START (0)
#define SOC_ISP_SUBCTRL_ISP_mon_addr_3_isp_mon_addr_3_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_addr_hit_stat : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_addr_hit_stat_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_addr_hit_stat_isp_addr_hit_stat_START (0)
#define SOC_ISP_SUBCTRL_ISP_addr_hit_stat_isp_addr_hit_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon0_addr_0_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon0_addr_0_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON0_addr_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_0_isp_mon0_addr_0_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_0_isp_mon0_addr_0_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_0_isp_mon0_addr_0_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_0_isp_mon0_addr_0_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon0_addr_1_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon0_addr_1_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON0_addr_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_1_isp_mon0_addr_1_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_1_isp_mon0_addr_1_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_1_isp_mon0_addr_1_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_1_isp_mon0_addr_1_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon0_addr_2_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon0_addr_2_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON0_addr_2_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_2_isp_mon0_addr_2_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_2_isp_mon0_addr_2_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_2_isp_mon0_addr_2_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_2_isp_mon0_addr_2_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon0_addr_3_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon0_addr_3_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON0_addr_3_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_3_isp_mon0_addr_3_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_3_isp_mon0_addr_3_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_3_isp_mon0_addr_3_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON0_addr_3_isp_mon0_addr_3_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon1_addr_0_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon1_addr_0_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON1_addr_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_0_isp_mon1_addr_0_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_0_isp_mon1_addr_0_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_0_isp_mon1_addr_0_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_0_isp_mon1_addr_0_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon1_addr_1_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon1_addr_1_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON1_addr_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_1_isp_mon1_addr_1_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_1_isp_mon1_addr_1_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_1_isp_mon1_addr_1_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_1_isp_mon1_addr_1_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon1_addr_2_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon1_addr_2_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON1_addr_2_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_2_isp_mon1_addr_2_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_2_isp_mon1_addr_2_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_2_isp_mon1_addr_2_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_2_isp_mon1_addr_2_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon1_addr_3_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon1_addr_3_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON1_addr_3_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_3_isp_mon1_addr_3_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_3_isp_mon1_addr_3_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_3_isp_mon1_addr_3_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON1_addr_3_isp_mon1_addr_3_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon2_addr_0_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon2_addr_0_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON2_addr_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_0_isp_mon2_addr_0_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_0_isp_mon2_addr_0_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_0_isp_mon2_addr_0_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_0_isp_mon2_addr_0_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon2_addr_1_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon2_addr_1_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON2_addr_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_1_isp_mon2_addr_1_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_1_isp_mon2_addr_1_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_1_isp_mon2_addr_1_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_1_isp_mon2_addr_1_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon2_addr_2_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon2_addr_2_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON2_addr_2_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_2_isp_mon2_addr_2_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_2_isp_mon2_addr_2_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_2_isp_mon2_addr_2_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_2_isp_mon2_addr_2_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon2_addr_3_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon2_addr_3_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON2_addr_3_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_3_isp_mon2_addr_3_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_3_isp_mon2_addr_3_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_3_isp_mon2_addr_3_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON2_addr_3_isp_mon2_addr_3_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon3_addr_0_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon3_addr_0_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON3_addr_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_0_isp_mon3_addr_0_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_0_isp_mon3_addr_0_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_0_isp_mon3_addr_0_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_0_isp_mon3_addr_0_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon3_addr_1_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon3_addr_1_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON3_addr_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_1_isp_mon3_addr_1_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_1_isp_mon3_addr_1_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_1_isp_mon3_addr_1_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_1_isp_mon3_addr_1_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon3_addr_2_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon3_addr_2_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON3_addr_2_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_2_isp_mon3_addr_2_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_2_isp_mon3_addr_2_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_2_isp_mon3_addr_2_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_2_isp_mon3_addr_2_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon3_addr_3_rd : 12;
        unsigned int reserved_0 : 4;
        unsigned int isp_mon3_addr_3_wr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON3_addr_3_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_3_isp_mon3_addr_3_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_3_isp_mon3_addr_3_rd_END (11)
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_3_isp_mon3_addr_3_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON3_addr_3_isp_mon3_addr_3_wr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon0_sid_0_rd : 7;
        unsigned int reserved_0 : 9;
        unsigned int isp_mon0_sid_0_wr : 7;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON0_SID_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_0_isp_mon0_sid_0_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_0_isp_mon0_sid_0_rd_END (6)
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_0_isp_mon0_sid_0_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_0_isp_mon0_sid_0_wr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon0_sid_1_rd : 7;
        unsigned int reserved_0 : 9;
        unsigned int isp_mon0_sid_1_wr : 7;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON0_SID_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_1_isp_mon0_sid_1_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_1_isp_mon0_sid_1_rd_END (6)
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_1_isp_mon0_sid_1_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_1_isp_mon0_sid_1_wr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon0_sid_2_rd : 7;
        unsigned int reserved_0 : 9;
        unsigned int isp_mon0_sid_2_wr : 7;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON0_SID_2_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_2_isp_mon0_sid_2_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_2_isp_mon0_sid_2_rd_END (6)
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_2_isp_mon0_sid_2_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_2_isp_mon0_sid_2_wr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon0_sid_3_rd : 7;
        unsigned int reserved_0 : 9;
        unsigned int isp_mon0_sid_3_wr : 7;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON0_SID_3_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_3_isp_mon0_sid_3_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_3_isp_mon0_sid_3_rd_END (6)
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_3_isp_mon0_sid_3_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON0_SID_3_isp_mon0_sid_3_wr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon1_sid_0_rd : 7;
        unsigned int reserved_0 : 9;
        unsigned int isp_mon1_sid_0_wr : 7;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON1_SID_0_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_0_isp_mon1_sid_0_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_0_isp_mon1_sid_0_rd_END (6)
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_0_isp_mon1_sid_0_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_0_isp_mon1_sid_0_wr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon1_sid_1_rd : 7;
        unsigned int reserved_0 : 9;
        unsigned int isp_mon1_sid_1_wr : 7;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON1_SID_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_1_isp_mon1_sid_1_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_1_isp_mon1_sid_1_rd_END (6)
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_1_isp_mon1_sid_1_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_1_isp_mon1_sid_1_wr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon1_sid_2_rd : 7;
        unsigned int reserved_0 : 9;
        unsigned int isp_mon1_sid_2_wr : 7;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON1_SID_2_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_2_isp_mon1_sid_2_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_2_isp_mon1_sid_2_rd_END (6)
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_2_isp_mon1_sid_2_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_2_isp_mon1_sid_2_wr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_mon1_sid_3_rd : 7;
        unsigned int reserved_0 : 9;
        unsigned int isp_mon1_sid_3_wr : 7;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_ISP_SUBCTRL_ISP_MON1_SID_3_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_3_isp_mon1_sid_3_rd_START (0)
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_3_isp_mon1_sid_3_rd_END (6)
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_3_isp_mon1_sid_3_wr_START (16)
#define SOC_ISP_SUBCTRL_ISP_MON1_SID_3_isp_mon1_sid_3_wr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic2_out_irq_mask : 32;
    } reg;
} SOC_ISP_SUBCTRL_VIC2_OUT0_UNION;
#endif
#define SOC_ISP_SUBCTRL_VIC2_OUT0_vic2_out_irq_mask_START (0)
#define SOC_ISP_SUBCTRL_VIC2_OUT0_vic2_out_irq_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic2_in_irq_level_mask : 32;
    } reg;
} SOC_ISP_SUBCTRL_VIC2_IN0_UNION;
#endif
#define SOC_ISP_SUBCTRL_VIC2_IN0_vic2_in_irq_level_mask_START (0)
#define SOC_ISP_SUBCTRL_VIC2_IN0_vic2_in_irq_level_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic2_in_irq_level_force : 32;
    } reg;
} SOC_ISP_SUBCTRL_VIC2_IN1_UNION;
#endif
#define SOC_ISP_SUBCTRL_VIC2_IN1_vic2_in_irq_level_force_START (0)
#define SOC_ISP_SUBCTRL_VIC2_IN1_vic2_in_irq_level_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p2p_swap_ctrl : 1;
        unsigned int force_p2p_ready : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ISP_SUBCTRL_P2P_CTRL_UNION;
#endif
#define SOC_ISP_SUBCTRL_P2P_CTRL_p2p_swap_ctrl_START (0)
#define SOC_ISP_SUBCTRL_P2P_CTRL_p2p_swap_ctrl_END (0)
#define SOC_ISP_SUBCTRL_P2P_CTRL_force_p2p_ready_START (1)
#define SOC_ISP_SUBCTRL_P2P_CTRL_force_p2p_ready_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_ISP_SUBCTRL_RESERVED_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int subctrl_to_core_grp1 : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_CORE_CTRL_1_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_CORE_CTRL_1_subctrl_to_core_grp1_START (0)
#define SOC_ISP_SUBCTRL_ISP_CORE_CTRL_1_subctrl_to_core_grp1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int subctrl_to_core_grps : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_CORE_CTRL_S_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_CORE_CTRL_S_subctrl_to_core_grps_START (0)
#define SOC_ISP_SUBCTRL_ISP_CORE_CTRL_S_subctrl_to_core_grps_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int subctrl_to_sub_grps : 32;
    } reg;
} SOC_ISP_SUBCTRL_ISP_SUB_CTRL_S_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_SUB_CTRL_S_subctrl_to_sub_grps_START (0)
#define SOC_ISP_SUBCTRL_ISP_SUB_CTRL_S_subctrl_to_sub_grps_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r8_trusted_nsaid_en : 1;
        unsigned int r8_protected_nsaid_en : 1;
        unsigned int mmu_sec_override : 1;
        unsigned int r8_sec_access_tcm_ctrl : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_SUBCTRL_ISP_CPU_SMMU_CTRL_S_UNION;
#endif
#define SOC_ISP_SUBCTRL_ISP_CPU_SMMU_CTRL_S_r8_trusted_nsaid_en_START (0)
#define SOC_ISP_SUBCTRL_ISP_CPU_SMMU_CTRL_S_r8_trusted_nsaid_en_END (0)
#define SOC_ISP_SUBCTRL_ISP_CPU_SMMU_CTRL_S_r8_protected_nsaid_en_START (1)
#define SOC_ISP_SUBCTRL_ISP_CPU_SMMU_CTRL_S_r8_protected_nsaid_en_END (1)
#define SOC_ISP_SUBCTRL_ISP_CPU_SMMU_CTRL_S_mmu_sec_override_START (2)
#define SOC_ISP_SUBCTRL_ISP_CPU_SMMU_CTRL_S_mmu_sec_override_END (2)
#define SOC_ISP_SUBCTRL_ISP_CPU_SMMU_CTRL_S_r8_sec_access_tcm_ctrl_START (3)
#define SOC_ISP_SUBCTRL_ISP_CPU_SMMU_CTRL_S_r8_sec_access_tcm_ctrl_END (3)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

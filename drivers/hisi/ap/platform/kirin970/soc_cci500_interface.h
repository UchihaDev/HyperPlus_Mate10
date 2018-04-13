#ifndef __SOC_CCI500_INTERFACE_H__
#define __SOC_CCI500_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_CCI500_CTRL_OVR_ADDR(base) ((base) + (0x00000))
#define SOC_CCI500_SECR_ACC_ADDR(base) ((base) + (0x00008))
#define SOC_CCI500_STATUS_ADDR(base) ((base) + (0x0000C))
#define SOC_CCI500_IMPR_ERR_ADDR(base) ((base) + (0x00010))
#define SOC_CCI500_QOS_THRESHOLD_ADDR(base) ((base) + (0x00014))
#define SOC_CCI500_PMU_CTRL_ADDR(base) ((base) + (0x00100))
#define SOC_CCI500_DEBUG_CTRL_ADDR(base) ((base) + (0x00104))
#define SOC_CCI500_PERIPHERAL_ID4_ADDR(base) ((base) + (0x00FD0))
#define SOC_CCI500_PERIPHERAL_ID5_ADDR(base) ((base) + (0x00FD4))
#define SOC_CCI500_PERIPHERAL_ID6_ADDR(base) ((base) + (0x00FD8))
#define SOC_CCI500_PERIPHERAL_ID7_ADDR(base) ((base) + (0x00FDC))
#define SOC_CCI500_PERIPHERAL_ID0_ADDR(base) ((base) + (0x00FE0))
#define SOC_CCI500_PERIPHERAL_ID1_ADDR(base) ((base) + (0x00FE4))
#define SOC_CCI500_PERIPHERAL_ID2_ADDR(base) ((base) + (0x00FE8))
#define SOC_CCI500_PERIPHERAL_ID3_ADDR(base) ((base) + (0x00FEC))
#define SOC_CCI500_COMPONENT_ID0_ADDR(base) ((base) + (0x00FF0))
#define SOC_CCI500_COMPONENT_ID1_ADDR(base) ((base) + (0x00FF4))
#define SOC_CCI500_COMPONENT_ID2_ADDR(base) ((base) + (0x00FF8))
#define SOC_CCI500_COMPONENT_ID3_ADDR(base) ((base) + (0x00FFC))
#define SOC_CCI500_SNOOP_CTRL_S0_ADDR(base) ((base) + (0x01000))
#define SOC_CCI500_SHARE_OVR_S0_ADDR(base) ((base) + (0x01004))
#define SOC_CCI500_ARQOS_OVR_S0_ADDR(base) ((base) + (0x01100))
#define SOC_CCI500_AWQOS_OVR_S0_ADDR(base) ((base) + (0x01104))
#define SOC_CCI500_QOS_MAX_OT_S0_ADDR(base) ((base) + (0x01110))
#define SOC_CCI500_SNOOP_CTRL_S1_ADDR(base) ((base) + (0x02000))
#define SOC_CCI500_SHARE_OVR_S1_ADDR(base) ((base) + (0x02004))
#define SOC_CCI500_ARQOS_OVR_S1_ADDR(base) ((base) + (0x02100))
#define SOC_CCI500_AWQOS_OVR_S1_ADDR(base) ((base) + (0x02104))
#define SOC_CCI500_QOS_MAX_OT_S1_ADDR(base) ((base) + (0x02110))
#define SOC_CCI500_SNOOP_CTRL_S2_ADDR(base) ((base) + (0x03000))
#define SOC_CCI500_SHARE_OVR_S2_ADDR(base) ((base) + (0x03004))
#define SOC_CCI500_ARQOS_OVR_S2_ADDR(base) ((base) + (0x03100))
#define SOC_CCI500_AWQOS_OVR_S2_ADDR(base) ((base) + (0x03104))
#define SOC_CCI500_QOS_MAX_OT_S2_ADDR(base) ((base) + (0x03110))
#define SOC_CCI500_SNOOP_CTRL_S3_ADDR(base) ((base) + (0x04000))
#define SOC_CCI500_SHARE_OVR_S3_ADDR(base) ((base) + (0x04004))
#define SOC_CCI500_ARQOS_OVR_S3_ADDR(base) ((base) + (0x04100))
#define SOC_CCI500_AWQOS_OVR_S3_ADDR(base) ((base) + (0x04104))
#define SOC_CCI500_QOS_MAX_OT_S3_ADDR(base) ((base) + (0x04110))
#define SOC_CCI500_EVNT_SEL_0_ADDR(base) ((base) + (0x10000))
#define SOC_CCI500_ECNT_DATA_0_ADDR(base) ((base) + (0x10004))
#define SOC_CCI500_ECNT_CTRL_0_ADDR(base) ((base) + (0x10008))
#define SOC_CCI500_ECNT_CLR_OVFL_0_ADDR(base) ((base) + (0x1000C))
#define SOC_CCI500_EVNT_SEL_1_ADDR(base) ((base) + (0x20000))
#define SOC_CCI500_ECNT_DATA_1_ADDR(base) ((base) + (0x20004))
#define SOC_CCI500_ECNT_CTRL_1_ADDR(base) ((base) + (0x20008))
#define SOC_CCI500_ECNT_CLR_OVFL_1_ADDR(base) ((base) + (0x2000C))
#define SOC_CCI500_EVNT_SEL_2_ADDR(base) ((base) + (0x30000))
#define SOC_CCI500_ECNT_DATA_2_ADDR(base) ((base) + (0x30004))
#define SOC_CCI500_ECNT_CTRL_2_ADDR(base) ((base) + (0x30008))
#define SOC_CCI500_ECNT_CLR_OVFL_2_ADDR(base) ((base) + (0x3000C))
#define SOC_CCI500_EVNT_SEL_3_ADDR(base) ((base) + (0x40000))
#define SOC_CCI500_ECNT_DATA_3_ADDR(base) ((base) + (0x40004))
#define SOC_CCI500_ECNT_CTRL_3_ADDR(base) ((base) + (0x40008))
#define SOC_CCI500_ECNT_CLR_OVFL_3_ADDR(base) ((base) + (0x4000C))
#define SOC_CCI500_EVNT_SEL_4_ADDR(base) ((base) + (0x50000))
#define SOC_CCI500_ECNT_DATA_4_ADDR(base) ((base) + (0x50004))
#define SOC_CCI500_ECNT_CTRL_4_ADDR(base) ((base) + (0x50008))
#define SOC_CCI500_ECNT_CLR_OVFL_4_ADDR(base) ((base) + (0x5000C))
#define SOC_CCI500_EVNT_SEL_5_ADDR(base) ((base) + (0x60000))
#define SOC_CCI500_ECNT_DATA_5_ADDR(base) ((base) + (0x60004))
#define SOC_CCI500_ECNT_CTRL_5_ADDR(base) ((base) + (0x60008))
#define SOC_CCI500_ECNT_CLR_OVFL_5_ADDR(base) ((base) + (0x6000C))
#define SOC_CCI500_EVNT_SEL_6_ADDR(base) ((base) + (0x70000))
#define SOC_CCI500_ECNT_DATA_6_ADDR(base) ((base) + (0x70004))
#define SOC_CCI500_ECNT_CTRL_6_ADDR(base) ((base) + (0x70008))
#define SOC_CCI500_ECNT_CLR_OVFL_6_ADDR(base) ((base) + (0x7000C))
#define SOC_CCI500_EVNT_SEL_7_ADDR(base) ((base) + (0x80000))
#define SOC_CCI500_ECNT_DATA_7_ADDR(base) ((base) + (0x80004))
#define SOC_CCI500_ECNT_CTRL_7_ADDR(base) ((base) + (0x80008))
#define SOC_CCI500_ECNT_CLR_OVFL_7_ADDR(base) ((base) + (0x8000C))
#define SOC_CCI500_SLAVE_DEBUG_0_ADDR(base) ((base) + (0x90000))
#define SOC_CCI500_SLAVE_DEBUG_1_ADDR(base) ((base) + (0x90004))
#define SOC_CCI500_SLAVE_DEBUG_2_ADDR(base) ((base) + (0x90008))
#define SOC_CCI500_SLAVE_DEBUG_3_ADDR(base) ((base) + (0x9000C))
#define SOC_CCI500_MASTER_DEBUG_0_ADDR(base) ((base) + (0x90100))
#define SOC_CCI500_MASTER_DEBUG_1_ADDR(base) ((base) + (0x90104))
#define SOC_CCI500_MASTER_DEBUG_2_ADDR(base) ((base) + (0x90108))
#define SOC_CCI500_MASTER_DEBUG_3_ADDR(base) ((base) + (0x9010C))
#define SOC_CCI500_MASTER_DEBUG_4_ADDR(base) ((base) + (0x90110))
#define SOC_CCI500_A57_CPUMEM_CTRL0_ADDR(base) ((base) + (0xFC000))
#define SOC_CCI500_A57_CPUMEM_CTRL1_ADDR(base) ((base) + (0xFC004))
#define SOC_CCI500_A57_CPUMEM_CTRL2_ADDR(base) ((base) + (0xFC008))
#define SOC_CCI500_A57_CPUMEM_CTRL3_ADDR(base) ((base) + (0xFC00C))
#define SOC_CCI500_A57_CPUMEM_CTRL4_ADDR(base) ((base) + (0xFC010))
#define SOC_CCI500_A53_CPUMEM_CTRL0_ADDR(base) ((base) + (0xFC018))
#define SOC_CCI500_A53_CPUMEM_CTRL1_ADDR(base) ((base) + (0xFC01C))
#define SOC_CCI500_A53_CPUMEM_CTRL2_ADDR(base) ((base) + (0xFC020))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int snoop_disable : 1;
        unsigned int dvm_message_disable : 1;
        unsigned int disable_snoop_filter : 1;
        unsigned int disable_clock_gating : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_CCI500_CTRL_OVR_UNION;
#endif
#define SOC_CCI500_CTRL_OVR_snoop_disable_START (0)
#define SOC_CCI500_CTRL_OVR_snoop_disable_END (0)
#define SOC_CCI500_CTRL_OVR_dvm_message_disable_START (1)
#define SOC_CCI500_CTRL_OVR_dvm_message_disable_END (1)
#define SOC_CCI500_CTRL_OVR_disable_snoop_filter_START (2)
#define SOC_CCI500_CTRL_OVR_disable_snoop_filter_END (2)
#define SOC_CCI500_CTRL_OVR_disable_clock_gating_START (3)
#define SOC_CCI500_CTRL_OVR_disable_clock_gating_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int non_secure_register_access_override : 1;
        unsigned int debug_monitor_security_override : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CCI500_SECR_ACC_UNION;
#endif
#define SOC_CCI500_SECR_ACC_non_secure_register_access_override_START (0)
#define SOC_CCI500_SECR_ACC_non_secure_register_access_override_END (0)
#define SOC_CCI500_SECR_ACC_debug_monitor_security_override_START (1)
#define SOC_CCI500_SECR_ACC_debug_monitor_security_override_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int change_pending : 1;
        unsigned int sf_ram_initialization : 1;
        unsigned int sf_ram_state : 3;
        unsigned int sf_ram_state_request : 3;
        unsigned int sf_ram_state_change_pending : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_STATUS_UNION;
#endif
#define SOC_CCI500_STATUS_change_pending_START (0)
#define SOC_CCI500_STATUS_change_pending_END (0)
#define SOC_CCI500_STATUS_sf_ram_initialization_START (1)
#define SOC_CCI500_STATUS_sf_ram_initialization_END (1)
#define SOC_CCI500_STATUS_sf_ram_state_START (2)
#define SOC_CCI500_STATUS_sf_ram_state_END (4)
#define SOC_CCI500_STATUS_sf_ram_state_request_START (5)
#define SOC_CCI500_STATUS_sf_ram_state_request_END (7)
#define SOC_CCI500_STATUS_sf_ram_state_change_pending_START (8)
#define SOC_CCI500_STATUS_sf_ram_state_change_pending_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int imprecise_error_indicator_mi0 : 1;
        unsigned int imprecise_error_indicator_mi1 : 1;
        unsigned int imprecise_error_indicator_mi2 : 1;
        unsigned int imprecise_error_indicator_mi3 : 1;
        unsigned int imprecise_error_indicator_mi4 : 1;
        unsigned int imprecise_error_indicator_mi5 : 1;
        unsigned int imprecise_error_indicator_mi6 : 1;
        unsigned int reserved_0 : 9;
        unsigned int imprecise_error_indicator_si0 : 1;
        unsigned int imprecise_error_indicator_si1 : 1;
        unsigned int imprecise_error_indicator_si2 : 1;
        unsigned int imprecise_error_indicator_si3 : 1;
        unsigned int imprecise_error_indicator_si4 : 1;
        unsigned int imprecise_error_indicator_si5 : 1;
        unsigned int imprecise_error_indicator_si6 : 1;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_CCI500_IMPR_ERR_UNION;
#endif
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi0_START (0)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi0_END (0)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi1_START (1)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi1_END (1)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi2_START (2)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi2_END (2)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi3_START (3)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi3_END (3)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi4_START (4)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi4_END (4)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi5_START (5)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi5_END (5)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi6_START (6)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi6_END (6)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si0_START (16)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si0_END (16)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si1_START (17)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si1_END (17)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si2_START (18)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si2_END (18)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si3_START (19)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si3_END (19)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si4_START (20)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si4_END (20)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si5_START (21)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si5_END (21)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si6_START (22)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si6_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_qv_thresh_high : 4;
        unsigned int reserved_0 : 12;
        unsigned int w_qv_thresh_high : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_CCI500_QOS_THRESHOLD_UNION;
#endif
#define SOC_CCI500_QOS_THRESHOLD_r_qv_thresh_high_START (0)
#define SOC_CCI500_QOS_THRESHOLD_r_qv_thresh_high_END (3)
#define SOC_CCI500_QOS_THRESHOLD_w_qv_thresh_high_START (16)
#define SOC_CCI500_QOS_THRESHOLD_w_qv_thresh_high_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CEN : 1;
        unsigned int RST : 1;
        unsigned int reserved_0 : 2;
        unsigned int EX : 1;
        unsigned int reserved_1 : 6;
        unsigned int number_of_counters : 5;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_CCI500_PMU_CTRL_UNION;
#endif
#define SOC_CCI500_PMU_CTRL_CEN_START (0)
#define SOC_CCI500_PMU_CTRL_CEN_END (0)
#define SOC_CCI500_PMU_CTRL_RST_START (1)
#define SOC_CCI500_PMU_CTRL_RST_END (1)
#define SOC_CCI500_PMU_CTRL_EX_START (4)
#define SOC_CCI500_PMU_CTRL_EX_END (4)
#define SOC_CCI500_PMU_CTRL_number_of_counters_START (11)
#define SOC_CCI500_PMU_CTRL_number_of_counters_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enable_interface_monitors : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_DEBUG_CTRL_UNION;
#endif
#define SOC_CCI500_DEBUG_CTRL_enable_interface_monitors_START (0)
#define SOC_CCI500_DEBUG_CTRL_enable_interface_monitors_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peri_id4 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID4_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID4_peri_id4_START (0)
#define SOC_CCI500_PERIPHERAL_ID4_peri_id4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peri_id5 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID5_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID5_peri_id5_START (0)
#define SOC_CCI500_PERIPHERAL_ID5_peri_id5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peri_id6 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID6_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID6_peri_id6_START (0)
#define SOC_CCI500_PERIPHERAL_ID6_peri_id6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peri_id7 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID7_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID7_peri_id7_START (0)
#define SOC_CCI500_PERIPHERAL_ID7_peri_id7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peri_id0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID0_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID0_peri_id0_START (0)
#define SOC_CCI500_PERIPHERAL_ID0_peri_id0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peri_id1_num : 4;
        unsigned int jep106_id_l : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID1_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID1_peri_id1_num_START (0)
#define SOC_CCI500_PERIPHERAL_ID1_peri_id1_num_END (3)
#define SOC_CCI500_PERIPHERAL_ID1_jep106_id_l_START (4)
#define SOC_CCI500_PERIPHERAL_ID1_jep106_id_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jep106_id_h : 3;
        unsigned int manu_id_code : 1;
        unsigned int ccr_rev : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID2_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID2_jep106_id_h_START (0)
#define SOC_CCI500_PERIPHERAL_ID2_jep106_id_h_END (2)
#define SOC_CCI500_PERIPHERAL_ID2_manu_id_code_START (3)
#define SOC_CCI500_PERIPHERAL_ID2_manu_id_code_END (3)
#define SOC_CCI500_PERIPHERAL_ID2_ccr_rev_START (4)
#define SOC_CCI500_PERIPHERAL_ID2_ccr_rev_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mod_num : 4;
        unsigned int eco_num : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID3_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID3_mod_num_START (0)
#define SOC_CCI500_PERIPHERAL_ID3_mod_num_END (3)
#define SOC_CCI500_PERIPHERAL_ID3_eco_num_START (4)
#define SOC_CCI500_PERIPHERAL_ID3_eco_num_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int component_id0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_COMPONENT_ID0_UNION;
#endif
#define SOC_CCI500_COMPONENT_ID0_component_id0_START (0)
#define SOC_CCI500_COMPONENT_ID0_component_id0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int component_id1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_COMPONENT_ID1_UNION;
#endif
#define SOC_CCI500_COMPONENT_ID1_component_id1_START (0)
#define SOC_CCI500_COMPONENT_ID1_component_id1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int component_id2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_COMPONENT_ID2_UNION;
#endif
#define SOC_CCI500_COMPONENT_ID2_component_id2_START (0)
#define SOC_CCI500_COMPONENT_ID2_component_id2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int component_id3 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_COMPONENT_ID3_UNION;
#endif
#define SOC_CCI500_COMPONENT_ID3_component_id3_START (0)
#define SOC_CCI500_COMPONENT_ID3_component_id3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int snoop_en : 1;
        unsigned int dvm_en : 1;
        unsigned int reserved : 28;
        unsigned int snoop_support : 1;
        unsigned int dvm_support : 1;
    } reg;
} SOC_CCI500_SNOOP_CTRL_S0_UNION;
#endif
#define SOC_CCI500_SNOOP_CTRL_S0_snoop_en_START (0)
#define SOC_CCI500_SNOOP_CTRL_S0_snoop_en_END (0)
#define SOC_CCI500_SNOOP_CTRL_S0_dvm_en_START (1)
#define SOC_CCI500_SNOOP_CTRL_S0_dvm_en_END (1)
#define SOC_CCI500_SNOOP_CTRL_S0_snoop_support_START (30)
#define SOC_CCI500_SNOOP_CTRL_S0_snoop_support_END (30)
#define SOC_CCI500_SNOOP_CTRL_S0_dvm_support_START (31)
#define SOC_CCI500_SNOOP_CTRL_S0_dvm_support_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shareable_override : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CCI500_SHARE_OVR_S0_UNION;
#endif
#define SOC_CCI500_SHARE_OVR_S0_shareable_override_START (0)
#define SOC_CCI500_SHARE_OVR_S0_shareable_override_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qv_max : 4;
        unsigned int qv_min : 4;
        unsigned int reserved_0 : 8;
        unsigned int bandwidth_allocation : 4;
        unsigned int reserved_1 : 4;
        unsigned int excess_bytes_per_qv : 3;
        unsigned int reserved_2 : 4;
        unsigned int reg_enable : 1;
    } reg;
} SOC_CCI500_ARQOS_OVR_S0_UNION;
#endif
#define SOC_CCI500_ARQOS_OVR_S0_qv_max_START (0)
#define SOC_CCI500_ARQOS_OVR_S0_qv_max_END (3)
#define SOC_CCI500_ARQOS_OVR_S0_qv_min_START (4)
#define SOC_CCI500_ARQOS_OVR_S0_qv_min_END (7)
#define SOC_CCI500_ARQOS_OVR_S0_bandwidth_allocation_START (16)
#define SOC_CCI500_ARQOS_OVR_S0_bandwidth_allocation_END (19)
#define SOC_CCI500_ARQOS_OVR_S0_excess_bytes_per_qv_START (24)
#define SOC_CCI500_ARQOS_OVR_S0_excess_bytes_per_qv_END (26)
#define SOC_CCI500_ARQOS_OVR_S0_reg_enable_START (31)
#define SOC_CCI500_ARQOS_OVR_S0_reg_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qv_max : 4;
        unsigned int qv_min : 4;
        unsigned int reserved_0 : 8;
        unsigned int bandwidth_allocation : 4;
        unsigned int reserved_1 : 4;
        unsigned int excess_bytes_per_qv : 3;
        unsigned int reserved_2 : 4;
        unsigned int reg_enable : 1;
    } reg;
} SOC_CCI500_AWQOS_OVR_S0_UNION;
#endif
#define SOC_CCI500_AWQOS_OVR_S0_qv_max_START (0)
#define SOC_CCI500_AWQOS_OVR_S0_qv_max_END (3)
#define SOC_CCI500_AWQOS_OVR_S0_qv_min_START (4)
#define SOC_CCI500_AWQOS_OVR_S0_qv_min_END (7)
#define SOC_CCI500_AWQOS_OVR_S0_bandwidth_allocation_START (16)
#define SOC_CCI500_AWQOS_OVR_S0_bandwidth_allocation_END (19)
#define SOC_CCI500_AWQOS_OVR_S0_excess_bytes_per_qv_START (24)
#define SOC_CCI500_AWQOS_OVR_S0_excess_bytes_per_qv_END (26)
#define SOC_CCI500_AWQOS_OVR_S0_reg_enable_START (31)
#define SOC_CCI500_AWQOS_OVR_S0_reg_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_ot : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_QOS_MAX_OT_S0_UNION;
#endif
#define SOC_CCI500_QOS_MAX_OT_S0_max_ot_START (0)
#define SOC_CCI500_QOS_MAX_OT_S0_max_ot_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int snoop_en : 1;
        unsigned int dvm_en : 1;
        unsigned int reserved : 28;
        unsigned int snoop_support : 1;
        unsigned int dvm_support : 1;
    } reg;
} SOC_CCI500_SNOOP_CTRL_S1_UNION;
#endif
#define SOC_CCI500_SNOOP_CTRL_S1_snoop_en_START (0)
#define SOC_CCI500_SNOOP_CTRL_S1_snoop_en_END (0)
#define SOC_CCI500_SNOOP_CTRL_S1_dvm_en_START (1)
#define SOC_CCI500_SNOOP_CTRL_S1_dvm_en_END (1)
#define SOC_CCI500_SNOOP_CTRL_S1_snoop_support_START (30)
#define SOC_CCI500_SNOOP_CTRL_S1_snoop_support_END (30)
#define SOC_CCI500_SNOOP_CTRL_S1_dvm_support_START (31)
#define SOC_CCI500_SNOOP_CTRL_S1_dvm_support_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shareable_override : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CCI500_SHARE_OVR_S1_UNION;
#endif
#define SOC_CCI500_SHARE_OVR_S1_shareable_override_START (0)
#define SOC_CCI500_SHARE_OVR_S1_shareable_override_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qv_max : 4;
        unsigned int qv_min : 4;
        unsigned int reserved_0 : 8;
        unsigned int bandwidth_allocation : 4;
        unsigned int reserved_1 : 4;
        unsigned int excess_bytes_per_qv : 3;
        unsigned int reserved_2 : 4;
        unsigned int reg_enable : 1;
    } reg;
} SOC_CCI500_ARQOS_OVR_S1_UNION;
#endif
#define SOC_CCI500_ARQOS_OVR_S1_qv_max_START (0)
#define SOC_CCI500_ARQOS_OVR_S1_qv_max_END (3)
#define SOC_CCI500_ARQOS_OVR_S1_qv_min_START (4)
#define SOC_CCI500_ARQOS_OVR_S1_qv_min_END (7)
#define SOC_CCI500_ARQOS_OVR_S1_bandwidth_allocation_START (16)
#define SOC_CCI500_ARQOS_OVR_S1_bandwidth_allocation_END (19)
#define SOC_CCI500_ARQOS_OVR_S1_excess_bytes_per_qv_START (24)
#define SOC_CCI500_ARQOS_OVR_S1_excess_bytes_per_qv_END (26)
#define SOC_CCI500_ARQOS_OVR_S1_reg_enable_START (31)
#define SOC_CCI500_ARQOS_OVR_S1_reg_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qv_max : 4;
        unsigned int qv_min : 4;
        unsigned int reserved_0 : 8;
        unsigned int bandwidth_allocation : 4;
        unsigned int reserved_1 : 4;
        unsigned int excess_bytes_per_qv : 3;
        unsigned int reserved_2 : 4;
        unsigned int reg_enable : 1;
    } reg;
} SOC_CCI500_AWQOS_OVR_S1_UNION;
#endif
#define SOC_CCI500_AWQOS_OVR_S1_qv_max_START (0)
#define SOC_CCI500_AWQOS_OVR_S1_qv_max_END (3)
#define SOC_CCI500_AWQOS_OVR_S1_qv_min_START (4)
#define SOC_CCI500_AWQOS_OVR_S1_qv_min_END (7)
#define SOC_CCI500_AWQOS_OVR_S1_bandwidth_allocation_START (16)
#define SOC_CCI500_AWQOS_OVR_S1_bandwidth_allocation_END (19)
#define SOC_CCI500_AWQOS_OVR_S1_excess_bytes_per_qv_START (24)
#define SOC_CCI500_AWQOS_OVR_S1_excess_bytes_per_qv_END (26)
#define SOC_CCI500_AWQOS_OVR_S1_reg_enable_START (31)
#define SOC_CCI500_AWQOS_OVR_S1_reg_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_ot : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_QOS_MAX_OT_S1_UNION;
#endif
#define SOC_CCI500_QOS_MAX_OT_S1_max_ot_START (0)
#define SOC_CCI500_QOS_MAX_OT_S1_max_ot_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int snoop_en : 1;
        unsigned int dvm_en : 1;
        unsigned int reserved : 28;
        unsigned int snoop_support : 1;
        unsigned int dvm_support : 1;
    } reg;
} SOC_CCI500_SNOOP_CTRL_S2_UNION;
#endif
#define SOC_CCI500_SNOOP_CTRL_S2_snoop_en_START (0)
#define SOC_CCI500_SNOOP_CTRL_S2_snoop_en_END (0)
#define SOC_CCI500_SNOOP_CTRL_S2_dvm_en_START (1)
#define SOC_CCI500_SNOOP_CTRL_S2_dvm_en_END (1)
#define SOC_CCI500_SNOOP_CTRL_S2_snoop_support_START (30)
#define SOC_CCI500_SNOOP_CTRL_S2_snoop_support_END (30)
#define SOC_CCI500_SNOOP_CTRL_S2_dvm_support_START (31)
#define SOC_CCI500_SNOOP_CTRL_S2_dvm_support_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shareable_override : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CCI500_SHARE_OVR_S2_UNION;
#endif
#define SOC_CCI500_SHARE_OVR_S2_shareable_override_START (0)
#define SOC_CCI500_SHARE_OVR_S2_shareable_override_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qv_max : 4;
        unsigned int qv_min : 4;
        unsigned int reserved_0 : 8;
        unsigned int bandwidth_allocation : 4;
        unsigned int reserved_1 : 4;
        unsigned int excess_bytes_per_qv : 3;
        unsigned int reserved_2 : 4;
        unsigned int reg_enable : 1;
    } reg;
} SOC_CCI500_ARQOS_OVR_S2_UNION;
#endif
#define SOC_CCI500_ARQOS_OVR_S2_qv_max_START (0)
#define SOC_CCI500_ARQOS_OVR_S2_qv_max_END (3)
#define SOC_CCI500_ARQOS_OVR_S2_qv_min_START (4)
#define SOC_CCI500_ARQOS_OVR_S2_qv_min_END (7)
#define SOC_CCI500_ARQOS_OVR_S2_bandwidth_allocation_START (16)
#define SOC_CCI500_ARQOS_OVR_S2_bandwidth_allocation_END (19)
#define SOC_CCI500_ARQOS_OVR_S2_excess_bytes_per_qv_START (24)
#define SOC_CCI500_ARQOS_OVR_S2_excess_bytes_per_qv_END (26)
#define SOC_CCI500_ARQOS_OVR_S2_reg_enable_START (31)
#define SOC_CCI500_ARQOS_OVR_S2_reg_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qv_max : 4;
        unsigned int qv_min : 4;
        unsigned int reserved_0 : 8;
        unsigned int bandwidth_allocation : 4;
        unsigned int reserved_1 : 4;
        unsigned int excess_bytes_per_qv : 3;
        unsigned int reserved_2 : 4;
        unsigned int reg_enable : 1;
    } reg;
} SOC_CCI500_AWQOS_OVR_S2_UNION;
#endif
#define SOC_CCI500_AWQOS_OVR_S2_qv_max_START (0)
#define SOC_CCI500_AWQOS_OVR_S2_qv_max_END (3)
#define SOC_CCI500_AWQOS_OVR_S2_qv_min_START (4)
#define SOC_CCI500_AWQOS_OVR_S2_qv_min_END (7)
#define SOC_CCI500_AWQOS_OVR_S2_bandwidth_allocation_START (16)
#define SOC_CCI500_AWQOS_OVR_S2_bandwidth_allocation_END (19)
#define SOC_CCI500_AWQOS_OVR_S2_excess_bytes_per_qv_START (24)
#define SOC_CCI500_AWQOS_OVR_S2_excess_bytes_per_qv_END (26)
#define SOC_CCI500_AWQOS_OVR_S2_reg_enable_START (31)
#define SOC_CCI500_AWQOS_OVR_S2_reg_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_ot : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_QOS_MAX_OT_S2_UNION;
#endif
#define SOC_CCI500_QOS_MAX_OT_S2_max_ot_START (0)
#define SOC_CCI500_QOS_MAX_OT_S2_max_ot_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int snoop_en : 1;
        unsigned int dvm_en : 1;
        unsigned int reserved : 28;
        unsigned int snoop_support : 1;
        unsigned int dvm_support : 1;
    } reg;
} SOC_CCI500_SNOOP_CTRL_S3_UNION;
#endif
#define SOC_CCI500_SNOOP_CTRL_S3_snoop_en_START (0)
#define SOC_CCI500_SNOOP_CTRL_S3_snoop_en_END (0)
#define SOC_CCI500_SNOOP_CTRL_S3_dvm_en_START (1)
#define SOC_CCI500_SNOOP_CTRL_S3_dvm_en_END (1)
#define SOC_CCI500_SNOOP_CTRL_S3_snoop_support_START (30)
#define SOC_CCI500_SNOOP_CTRL_S3_snoop_support_END (30)
#define SOC_CCI500_SNOOP_CTRL_S3_dvm_support_START (31)
#define SOC_CCI500_SNOOP_CTRL_S3_dvm_support_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shareable_override : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CCI500_SHARE_OVR_S3_UNION;
#endif
#define SOC_CCI500_SHARE_OVR_S3_shareable_override_START (0)
#define SOC_CCI500_SHARE_OVR_S3_shareable_override_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qv_max : 4;
        unsigned int qv_min : 4;
        unsigned int reserved_0 : 8;
        unsigned int bandwidth_allocation : 4;
        unsigned int reserved_1 : 4;
        unsigned int excess_bytes_per_qv : 3;
        unsigned int reserved_2 : 4;
        unsigned int reg_enable : 1;
    } reg;
} SOC_CCI500_ARQOS_OVR_S3_UNION;
#endif
#define SOC_CCI500_ARQOS_OVR_S3_qv_max_START (0)
#define SOC_CCI500_ARQOS_OVR_S3_qv_max_END (3)
#define SOC_CCI500_ARQOS_OVR_S3_qv_min_START (4)
#define SOC_CCI500_ARQOS_OVR_S3_qv_min_END (7)
#define SOC_CCI500_ARQOS_OVR_S3_bandwidth_allocation_START (16)
#define SOC_CCI500_ARQOS_OVR_S3_bandwidth_allocation_END (19)
#define SOC_CCI500_ARQOS_OVR_S3_excess_bytes_per_qv_START (24)
#define SOC_CCI500_ARQOS_OVR_S3_excess_bytes_per_qv_END (26)
#define SOC_CCI500_ARQOS_OVR_S3_reg_enable_START (31)
#define SOC_CCI500_ARQOS_OVR_S3_reg_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qv_max : 4;
        unsigned int qv_min : 4;
        unsigned int reserved_0 : 8;
        unsigned int bandwidth_allocation : 4;
        unsigned int reserved_1 : 4;
        unsigned int excess_bytes_per_qv : 3;
        unsigned int reserved_2 : 4;
        unsigned int reg_enable : 1;
    } reg;
} SOC_CCI500_AWQOS_OVR_S3_UNION;
#endif
#define SOC_CCI500_AWQOS_OVR_S3_qv_max_START (0)
#define SOC_CCI500_AWQOS_OVR_S3_qv_max_END (3)
#define SOC_CCI500_AWQOS_OVR_S3_qv_min_START (4)
#define SOC_CCI500_AWQOS_OVR_S3_qv_min_END (7)
#define SOC_CCI500_AWQOS_OVR_S3_bandwidth_allocation_START (16)
#define SOC_CCI500_AWQOS_OVR_S3_bandwidth_allocation_END (19)
#define SOC_CCI500_AWQOS_OVR_S3_excess_bytes_per_qv_START (24)
#define SOC_CCI500_AWQOS_OVR_S3_excess_bytes_per_qv_END (26)
#define SOC_CCI500_AWQOS_OVR_S3_reg_enable_START (31)
#define SOC_CCI500_AWQOS_OVR_S3_reg_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_ot : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_QOS_MAX_OT_S3_UNION;
#endif
#define SOC_CCI500_QOS_MAX_OT_S3_max_ot_START (0)
#define SOC_CCI500_QOS_MAX_OT_S3_max_ot_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_0_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_0_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_0_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_0_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_0_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_0_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_0_counter_START (0)
#define SOC_CCI500_ECNT_DATA_0_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_0_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_0_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_0_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_0_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_0_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_0_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_1_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_1_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_1_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_1_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_1_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_1_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_1_counter_START (0)
#define SOC_CCI500_ECNT_DATA_1_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_1_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_1_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_1_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_1_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_1_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_1_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_2_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_2_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_2_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_2_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_2_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_2_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_2_counter_START (0)
#define SOC_CCI500_ECNT_DATA_2_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_2_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_2_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_2_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_2_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_2_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_2_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_3_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_3_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_3_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_3_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_3_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_3_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_3_counter_START (0)
#define SOC_CCI500_ECNT_DATA_3_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_3_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_3_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_3_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_3_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_3_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_3_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_4_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_4_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_4_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_4_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_4_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_4_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_4_counter_START (0)
#define SOC_CCI500_ECNT_DATA_4_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_4_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_4_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_4_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_4_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_4_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_4_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_5_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_5_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_5_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_5_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_5_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_5_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_5_counter_START (0)
#define SOC_CCI500_ECNT_DATA_5_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_5_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_5_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_5_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_5_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_5_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_5_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_6_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_6_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_6_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_6_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_6_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_6_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_6_counter_START (0)
#define SOC_CCI500_ECNT_DATA_6_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_6_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_6_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_6_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_6_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_6_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_6_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_7_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_7_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_7_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_7_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_7_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_7_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_7_counter_START (0)
#define SOC_CCI500_ECNT_DATA_7_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_7_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_7_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_7_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_7_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_7_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_7_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int stalled_ac_channel : 1;
        unsigned int stalled_cr_channel : 1;
        unsigned int stalled_cd_channel : 1;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int outstanding_snoops : 8;
    } reg;
} SOC_CCI500_SLAVE_DEBUG_0_UNION;
#endif
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_ar_channel_START (0)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_ar_channel_END (0)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_r_channel_START (1)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_r_channel_END (1)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_aw_channel_START (2)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_aw_channel_END (2)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_w_channel_START (3)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_w_channel_END (3)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_b_channel_START (4)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_b_channel_END (4)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_ac_channel_START (5)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_ac_channel_END (5)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_cr_channel_START (6)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_cr_channel_END (6)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_cd_channel_START (7)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_cd_channel_END (7)
#define SOC_CCI500_SLAVE_DEBUG_0_outstanding_reads_START (8)
#define SOC_CCI500_SLAVE_DEBUG_0_outstanding_reads_END (15)
#define SOC_CCI500_SLAVE_DEBUG_0_outstanding_writes_START (16)
#define SOC_CCI500_SLAVE_DEBUG_0_outstanding_writes_END (23)
#define SOC_CCI500_SLAVE_DEBUG_0_outstanding_snoops_START (24)
#define SOC_CCI500_SLAVE_DEBUG_0_outstanding_snoops_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int stalled_ac_channel : 1;
        unsigned int stalled_cr_channel : 1;
        unsigned int stalled_cd_channel : 1;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int outstanding_snoops : 8;
    } reg;
} SOC_CCI500_SLAVE_DEBUG_1_UNION;
#endif
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_ar_channel_START (0)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_ar_channel_END (0)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_r_channel_START (1)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_r_channel_END (1)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_aw_channel_START (2)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_aw_channel_END (2)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_w_channel_START (3)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_w_channel_END (3)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_b_channel_START (4)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_b_channel_END (4)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_ac_channel_START (5)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_ac_channel_END (5)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_cr_channel_START (6)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_cr_channel_END (6)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_cd_channel_START (7)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_cd_channel_END (7)
#define SOC_CCI500_SLAVE_DEBUG_1_outstanding_reads_START (8)
#define SOC_CCI500_SLAVE_DEBUG_1_outstanding_reads_END (15)
#define SOC_CCI500_SLAVE_DEBUG_1_outstanding_writes_START (16)
#define SOC_CCI500_SLAVE_DEBUG_1_outstanding_writes_END (23)
#define SOC_CCI500_SLAVE_DEBUG_1_outstanding_snoops_START (24)
#define SOC_CCI500_SLAVE_DEBUG_1_outstanding_snoops_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int stalled_ac_channel : 1;
        unsigned int stalled_cr_channel : 1;
        unsigned int stalled_cd_channel : 1;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int outstanding_snoops : 8;
    } reg;
} SOC_CCI500_SLAVE_DEBUG_2_UNION;
#endif
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_ar_channel_START (0)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_ar_channel_END (0)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_r_channel_START (1)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_r_channel_END (1)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_aw_channel_START (2)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_aw_channel_END (2)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_w_channel_START (3)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_w_channel_END (3)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_b_channel_START (4)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_b_channel_END (4)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_ac_channel_START (5)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_ac_channel_END (5)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_cr_channel_START (6)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_cr_channel_END (6)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_cd_channel_START (7)
#define SOC_CCI500_SLAVE_DEBUG_2_stalled_cd_channel_END (7)
#define SOC_CCI500_SLAVE_DEBUG_2_outstanding_reads_START (8)
#define SOC_CCI500_SLAVE_DEBUG_2_outstanding_reads_END (15)
#define SOC_CCI500_SLAVE_DEBUG_2_outstanding_writes_START (16)
#define SOC_CCI500_SLAVE_DEBUG_2_outstanding_writes_END (23)
#define SOC_CCI500_SLAVE_DEBUG_2_outstanding_snoops_START (24)
#define SOC_CCI500_SLAVE_DEBUG_2_outstanding_snoops_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int stalled_ac_channel : 1;
        unsigned int stalled_cr_channel : 1;
        unsigned int stalled_cd_channel : 1;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int outstanding_snoops : 8;
    } reg;
} SOC_CCI500_SLAVE_DEBUG_3_UNION;
#endif
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_ar_channel_START (0)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_ar_channel_END (0)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_r_channel_START (1)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_r_channel_END (1)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_aw_channel_START (2)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_aw_channel_END (2)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_w_channel_START (3)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_w_channel_END (3)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_b_channel_START (4)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_b_channel_END (4)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_ac_channel_START (5)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_ac_channel_END (5)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_cr_channel_START (6)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_cr_channel_END (6)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_cd_channel_START (7)
#define SOC_CCI500_SLAVE_DEBUG_3_stalled_cd_channel_END (7)
#define SOC_CCI500_SLAVE_DEBUG_3_outstanding_reads_START (8)
#define SOC_CCI500_SLAVE_DEBUG_3_outstanding_reads_END (15)
#define SOC_CCI500_SLAVE_DEBUG_3_outstanding_writes_START (16)
#define SOC_CCI500_SLAVE_DEBUG_3_outstanding_writes_END (23)
#define SOC_CCI500_SLAVE_DEBUG_3_outstanding_snoops_START (24)
#define SOC_CCI500_SLAVE_DEBUG_3_outstanding_snoops_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int reserved_0 : 3;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_CCI500_MASTER_DEBUG_0_UNION;
#endif
#define SOC_CCI500_MASTER_DEBUG_0_stalled_ar_channel_START (0)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_ar_channel_END (0)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_r_channel_START (1)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_r_channel_END (1)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_aw_channel_START (2)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_aw_channel_END (2)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_w_channel_START (3)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_w_channel_END (3)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_b_channel_START (4)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_b_channel_END (4)
#define SOC_CCI500_MASTER_DEBUG_0_outstanding_reads_START (8)
#define SOC_CCI500_MASTER_DEBUG_0_outstanding_reads_END (15)
#define SOC_CCI500_MASTER_DEBUG_0_outstanding_writes_START (16)
#define SOC_CCI500_MASTER_DEBUG_0_outstanding_writes_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int reserved_0 : 3;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_CCI500_MASTER_DEBUG_1_UNION;
#endif
#define SOC_CCI500_MASTER_DEBUG_1_stalled_ar_channel_START (0)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_ar_channel_END (0)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_r_channel_START (1)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_r_channel_END (1)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_aw_channel_START (2)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_aw_channel_END (2)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_w_channel_START (3)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_w_channel_END (3)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_b_channel_START (4)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_b_channel_END (4)
#define SOC_CCI500_MASTER_DEBUG_1_outstanding_reads_START (8)
#define SOC_CCI500_MASTER_DEBUG_1_outstanding_reads_END (15)
#define SOC_CCI500_MASTER_DEBUG_1_outstanding_writes_START (16)
#define SOC_CCI500_MASTER_DEBUG_1_outstanding_writes_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int reserved_0 : 3;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_CCI500_MASTER_DEBUG_2_UNION;
#endif
#define SOC_CCI500_MASTER_DEBUG_2_stalled_ar_channel_START (0)
#define SOC_CCI500_MASTER_DEBUG_2_stalled_ar_channel_END (0)
#define SOC_CCI500_MASTER_DEBUG_2_stalled_r_channel_START (1)
#define SOC_CCI500_MASTER_DEBUG_2_stalled_r_channel_END (1)
#define SOC_CCI500_MASTER_DEBUG_2_stalled_aw_channel_START (2)
#define SOC_CCI500_MASTER_DEBUG_2_stalled_aw_channel_END (2)
#define SOC_CCI500_MASTER_DEBUG_2_stalled_w_channel_START (3)
#define SOC_CCI500_MASTER_DEBUG_2_stalled_w_channel_END (3)
#define SOC_CCI500_MASTER_DEBUG_2_stalled_b_channel_START (4)
#define SOC_CCI500_MASTER_DEBUG_2_stalled_b_channel_END (4)
#define SOC_CCI500_MASTER_DEBUG_2_outstanding_reads_START (8)
#define SOC_CCI500_MASTER_DEBUG_2_outstanding_reads_END (15)
#define SOC_CCI500_MASTER_DEBUG_2_outstanding_writes_START (16)
#define SOC_CCI500_MASTER_DEBUG_2_outstanding_writes_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int reserved_0 : 3;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_CCI500_MASTER_DEBUG_3_UNION;
#endif
#define SOC_CCI500_MASTER_DEBUG_3_stalled_ar_channel_START (0)
#define SOC_CCI500_MASTER_DEBUG_3_stalled_ar_channel_END (0)
#define SOC_CCI500_MASTER_DEBUG_3_stalled_r_channel_START (1)
#define SOC_CCI500_MASTER_DEBUG_3_stalled_r_channel_END (1)
#define SOC_CCI500_MASTER_DEBUG_3_stalled_aw_channel_START (2)
#define SOC_CCI500_MASTER_DEBUG_3_stalled_aw_channel_END (2)
#define SOC_CCI500_MASTER_DEBUG_3_stalled_w_channel_START (3)
#define SOC_CCI500_MASTER_DEBUG_3_stalled_w_channel_END (3)
#define SOC_CCI500_MASTER_DEBUG_3_stalled_b_channel_START (4)
#define SOC_CCI500_MASTER_DEBUG_3_stalled_b_channel_END (4)
#define SOC_CCI500_MASTER_DEBUG_3_outstanding_reads_START (8)
#define SOC_CCI500_MASTER_DEBUG_3_outstanding_reads_END (15)
#define SOC_CCI500_MASTER_DEBUG_3_outstanding_writes_START (16)
#define SOC_CCI500_MASTER_DEBUG_3_outstanding_writes_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int reserved_0 : 3;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_CCI500_MASTER_DEBUG_4_UNION;
#endif
#define SOC_CCI500_MASTER_DEBUG_4_stalled_ar_channel_START (0)
#define SOC_CCI500_MASTER_DEBUG_4_stalled_ar_channel_END (0)
#define SOC_CCI500_MASTER_DEBUG_4_stalled_r_channel_START (1)
#define SOC_CCI500_MASTER_DEBUG_4_stalled_r_channel_END (1)
#define SOC_CCI500_MASTER_DEBUG_4_stalled_aw_channel_START (2)
#define SOC_CCI500_MASTER_DEBUG_4_stalled_aw_channel_END (2)
#define SOC_CCI500_MASTER_DEBUG_4_stalled_w_channel_START (3)
#define SOC_CCI500_MASTER_DEBUG_4_stalled_w_channel_END (3)
#define SOC_CCI500_MASTER_DEBUG_4_stalled_b_channel_START (4)
#define SOC_CCI500_MASTER_DEBUG_4_stalled_b_channel_END (4)
#define SOC_CCI500_MASTER_DEBUG_4_outstanding_reads_START (8)
#define SOC_CCI500_MASTER_DEBUG_4_outstanding_reads_END (15)
#define SOC_CCI500_MASTER_DEBUG_4_outstanding_writes_START (16)
#define SOC_CCI500_MASTER_DEBUG_4_outstanding_writes_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int L1_dtag_chn0_tsel : 3;
        unsigned int L1_dtag_chn0_test : 3;
        unsigned int L1_dtag_chn0_twlpa : 1;
        unsigned int L1_dtag_chn1_tsel : 3;
        unsigned int L1_dtag_chn1_test : 3;
        unsigned int L1_dtag_chn1_twlpa : 1;
        unsigned int L1_itag_tsel : 3;
        unsigned int L1_itag_test : 3;
        unsigned int L1_itag_twlpa : 1;
        unsigned int L1_idata_tsel : 3;
        unsigned int L1_idata_test : 3;
        unsigned int L1_idata_twlpa : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_CCI500_A57_CPUMEM_CTRL0_UNION;
#endif
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_dtag_chn0_tsel_START (0)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_dtag_chn0_tsel_END (2)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_dtag_chn0_test_START (3)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_dtag_chn0_test_END (5)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_dtag_chn0_twlpa_START (6)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_dtag_chn0_twlpa_END (6)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_dtag_chn1_tsel_START (7)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_dtag_chn1_tsel_END (9)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_dtag_chn1_test_START (10)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_dtag_chn1_test_END (12)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_dtag_chn1_twlpa_START (13)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_dtag_chn1_twlpa_END (13)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_itag_tsel_START (14)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_itag_tsel_END (16)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_itag_test_START (17)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_itag_test_END (19)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_itag_twlpa_START (20)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_itag_twlpa_END (20)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_idata_tsel_START (21)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_idata_tsel_END (23)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_idata_test_START (24)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_idata_test_END (26)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_idata_twlpa_START (27)
#define SOC_CCI500_A57_CPUMEM_CTRL0_L1_idata_twlpa_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int btac_tsel : 3;
        unsigned int btac_test : 3;
        unsigned int btac_twlpa : 1;
        unsigned int pred0_tsel : 3;
        unsigned int pred0_test : 3;
        unsigned int pred0_twlpa : 1;
        unsigned int pred1_4_tsel : 3;
        unsigned int pred1_4_test : 3;
        unsigned int pred1_4_twlpa : 1;
        unsigned int ipred_tsel : 3;
        unsigned int ipred_test : 3;
        unsigned int ipred_twlpa : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_CCI500_A57_CPUMEM_CTRL1_UNION;
#endif
#define SOC_CCI500_A57_CPUMEM_CTRL1_btac_tsel_START (0)
#define SOC_CCI500_A57_CPUMEM_CTRL1_btac_tsel_END (2)
#define SOC_CCI500_A57_CPUMEM_CTRL1_btac_test_START (3)
#define SOC_CCI500_A57_CPUMEM_CTRL1_btac_test_END (5)
#define SOC_CCI500_A57_CPUMEM_CTRL1_btac_twlpa_START (6)
#define SOC_CCI500_A57_CPUMEM_CTRL1_btac_twlpa_END (6)
#define SOC_CCI500_A57_CPUMEM_CTRL1_pred0_tsel_START (7)
#define SOC_CCI500_A57_CPUMEM_CTRL1_pred0_tsel_END (9)
#define SOC_CCI500_A57_CPUMEM_CTRL1_pred0_test_START (10)
#define SOC_CCI500_A57_CPUMEM_CTRL1_pred0_test_END (12)
#define SOC_CCI500_A57_CPUMEM_CTRL1_pred0_twlpa_START (13)
#define SOC_CCI500_A57_CPUMEM_CTRL1_pred0_twlpa_END (13)
#define SOC_CCI500_A57_CPUMEM_CTRL1_pred1_4_tsel_START (14)
#define SOC_CCI500_A57_CPUMEM_CTRL1_pred1_4_tsel_END (16)
#define SOC_CCI500_A57_CPUMEM_CTRL1_pred1_4_test_START (17)
#define SOC_CCI500_A57_CPUMEM_CTRL1_pred1_4_test_END (19)
#define SOC_CCI500_A57_CPUMEM_CTRL1_pred1_4_twlpa_START (20)
#define SOC_CCI500_A57_CPUMEM_CTRL1_pred1_4_twlpa_END (20)
#define SOC_CCI500_A57_CPUMEM_CTRL1_ipred_tsel_START (21)
#define SOC_CCI500_A57_CPUMEM_CTRL1_ipred_tsel_END (23)
#define SOC_CCI500_A57_CPUMEM_CTRL1_ipred_test_START (24)
#define SOC_CCI500_A57_CPUMEM_CTRL1_ipred_test_END (26)
#define SOC_CCI500_A57_CPUMEM_CTRL1_ipred_twlpa_START (27)
#define SOC_CCI500_A57_CPUMEM_CTRL1_ipred_twlpa_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tlb_4kpage_tsel : 3;
        unsigned int tlb_4kpage_test : 3;
        unsigned int tlb_4kpage_twlpa : 1;
        unsigned int tlb_1mpage_tsel : 3;
        unsigned int tlb_1mpage_test : 3;
        unsigned int tlb_1mpage_twlpa : 1;
        unsigned int L1_ddata_tsel : 3;
        unsigned int L1_ddata_test : 3;
        unsigned int L1_ddata_twlpa : 1;
        unsigned int L2_linefill_tsel : 3;
        unsigned int L2_linefill_test : 3;
        unsigned int L2_linefill_twlpa : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_CCI500_A57_CPUMEM_CTRL2_UNION;
#endif
#define SOC_CCI500_A57_CPUMEM_CTRL2_tlb_4kpage_tsel_START (0)
#define SOC_CCI500_A57_CPUMEM_CTRL2_tlb_4kpage_tsel_END (2)
#define SOC_CCI500_A57_CPUMEM_CTRL2_tlb_4kpage_test_START (3)
#define SOC_CCI500_A57_CPUMEM_CTRL2_tlb_4kpage_test_END (5)
#define SOC_CCI500_A57_CPUMEM_CTRL2_tlb_4kpage_twlpa_START (6)
#define SOC_CCI500_A57_CPUMEM_CTRL2_tlb_4kpage_twlpa_END (6)
#define SOC_CCI500_A57_CPUMEM_CTRL2_tlb_1mpage_tsel_START (7)
#define SOC_CCI500_A57_CPUMEM_CTRL2_tlb_1mpage_tsel_END (9)
#define SOC_CCI500_A57_CPUMEM_CTRL2_tlb_1mpage_test_START (10)
#define SOC_CCI500_A57_CPUMEM_CTRL2_tlb_1mpage_test_END (12)
#define SOC_CCI500_A57_CPUMEM_CTRL2_tlb_1mpage_twlpa_START (13)
#define SOC_CCI500_A57_CPUMEM_CTRL2_tlb_1mpage_twlpa_END (13)
#define SOC_CCI500_A57_CPUMEM_CTRL2_L1_ddata_tsel_START (14)
#define SOC_CCI500_A57_CPUMEM_CTRL2_L1_ddata_tsel_END (16)
#define SOC_CCI500_A57_CPUMEM_CTRL2_L1_ddata_test_START (17)
#define SOC_CCI500_A57_CPUMEM_CTRL2_L1_ddata_test_END (19)
#define SOC_CCI500_A57_CPUMEM_CTRL2_L1_ddata_twlpa_START (20)
#define SOC_CCI500_A57_CPUMEM_CTRL2_L1_ddata_twlpa_END (20)
#define SOC_CCI500_A57_CPUMEM_CTRL2_L2_linefill_tsel_START (21)
#define SOC_CCI500_A57_CPUMEM_CTRL2_L2_linefill_tsel_END (23)
#define SOC_CCI500_A57_CPUMEM_CTRL2_L2_linefill_test_START (24)
#define SOC_CCI500_A57_CPUMEM_CTRL2_L2_linefill_test_END (26)
#define SOC_CCI500_A57_CPUMEM_CTRL2_L2_linefill_twlpa_START (27)
#define SOC_CCI500_A57_CPUMEM_CTRL2_L2_linefill_twlpa_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int L2_store_tsel : 3;
        unsigned int L2_store_test : 3;
        unsigned int L2_store_twlpa : 1;
        unsigned int L2_eviction_tsel : 3;
        unsigned int L2_eviction_test : 3;
        unsigned int L2_eviction_twlpa : 1;
        unsigned int L2_spatial_prefetch_tsel : 3;
        unsigned int L2_spatial_prefetch_test : 3;
        unsigned int L2_spatial_prefetch_twlpa : 1;
        unsigned int L2_tag_tsel : 3;
        unsigned int L2_tag_test : 3;
        unsigned int L2_tag_twlpa : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_CCI500_A57_CPUMEM_CTRL3_UNION;
#endif
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_store_tsel_START (0)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_store_tsel_END (2)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_store_test_START (3)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_store_test_END (5)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_store_twlpa_START (6)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_store_twlpa_END (6)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_eviction_tsel_START (7)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_eviction_tsel_END (9)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_eviction_test_START (10)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_eviction_test_END (12)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_eviction_twlpa_START (13)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_eviction_twlpa_END (13)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_spatial_prefetch_tsel_START (14)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_spatial_prefetch_tsel_END (16)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_spatial_prefetch_test_START (17)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_spatial_prefetch_test_END (19)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_spatial_prefetch_twlpa_START (20)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_spatial_prefetch_twlpa_END (20)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_tag_tsel_START (21)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_tag_tsel_END (23)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_tag_test_START (24)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_tag_test_END (26)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_tag_twlpa_START (27)
#define SOC_CCI500_A57_CPUMEM_CTRL3_L2_tag_twlpa_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int L2_replacement_tsel : 3;
        unsigned int L2_replacement_test : 3;
        unsigned int L2_replacement_twlpa : 1;
        unsigned int scu_tag_tsel : 3;
        unsigned int scu_tag_test : 3;
        unsigned int scu_tag_twlpa : 1;
        unsigned int L2_data_wtsel : 2;
        unsigned int L2_data_rtsel : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_CCI500_A57_CPUMEM_CTRL4_UNION;
#endif
#define SOC_CCI500_A57_CPUMEM_CTRL4_L2_replacement_tsel_START (0)
#define SOC_CCI500_A57_CPUMEM_CTRL4_L2_replacement_tsel_END (2)
#define SOC_CCI500_A57_CPUMEM_CTRL4_L2_replacement_test_START (3)
#define SOC_CCI500_A57_CPUMEM_CTRL4_L2_replacement_test_END (5)
#define SOC_CCI500_A57_CPUMEM_CTRL4_L2_replacement_twlpa_START (6)
#define SOC_CCI500_A57_CPUMEM_CTRL4_L2_replacement_twlpa_END (6)
#define SOC_CCI500_A57_CPUMEM_CTRL4_scu_tag_tsel_START (7)
#define SOC_CCI500_A57_CPUMEM_CTRL4_scu_tag_tsel_END (9)
#define SOC_CCI500_A57_CPUMEM_CTRL4_scu_tag_test_START (10)
#define SOC_CCI500_A57_CPUMEM_CTRL4_scu_tag_test_END (12)
#define SOC_CCI500_A57_CPUMEM_CTRL4_scu_tag_twlpa_START (13)
#define SOC_CCI500_A57_CPUMEM_CTRL4_scu_tag_twlpa_END (13)
#define SOC_CCI500_A57_CPUMEM_CTRL4_L2_data_wtsel_START (14)
#define SOC_CCI500_A57_CPUMEM_CTRL4_L2_data_wtsel_END (15)
#define SOC_CCI500_A57_CPUMEM_CTRL4_L2_data_rtsel_START (16)
#define SOC_CCI500_A57_CPUMEM_CTRL4_L2_data_rtsel_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int btac_stg1_tsel : 3;
        unsigned int btac_stg1_test : 3;
        unsigned int btac_stg1_twlpa : 1;
        unsigned int btac_stg0_tsel : 3;
        unsigned int btac_stg0_test : 3;
        unsigned int btac_stg0_twlpa : 1;
        unsigned int tlb_tsel : 3;
        unsigned int tlb_test : 3;
        unsigned int tlb_twlpa : 1;
        unsigned int L1_ddirty_tsel : 3;
        unsigned int L1_ddirty_test : 3;
        unsigned int L1_ddirty_twlpa : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_CCI500_A53_CPUMEM_CTRL0_UNION;
#endif
#define SOC_CCI500_A53_CPUMEM_CTRL0_btac_stg1_tsel_START (0)
#define SOC_CCI500_A53_CPUMEM_CTRL0_btac_stg1_tsel_END (2)
#define SOC_CCI500_A53_CPUMEM_CTRL0_btac_stg1_test_START (3)
#define SOC_CCI500_A53_CPUMEM_CTRL0_btac_stg1_test_END (5)
#define SOC_CCI500_A53_CPUMEM_CTRL0_btac_stg1_twlpa_START (6)
#define SOC_CCI500_A53_CPUMEM_CTRL0_btac_stg1_twlpa_END (6)
#define SOC_CCI500_A53_CPUMEM_CTRL0_btac_stg0_tsel_START (7)
#define SOC_CCI500_A53_CPUMEM_CTRL0_btac_stg0_tsel_END (9)
#define SOC_CCI500_A53_CPUMEM_CTRL0_btac_stg0_test_START (10)
#define SOC_CCI500_A53_CPUMEM_CTRL0_btac_stg0_test_END (12)
#define SOC_CCI500_A53_CPUMEM_CTRL0_btac_stg0_twlpa_START (13)
#define SOC_CCI500_A53_CPUMEM_CTRL0_btac_stg0_twlpa_END (13)
#define SOC_CCI500_A53_CPUMEM_CTRL0_tlb_tsel_START (14)
#define SOC_CCI500_A53_CPUMEM_CTRL0_tlb_tsel_END (16)
#define SOC_CCI500_A53_CPUMEM_CTRL0_tlb_test_START (17)
#define SOC_CCI500_A53_CPUMEM_CTRL0_tlb_test_END (19)
#define SOC_CCI500_A53_CPUMEM_CTRL0_tlb_twlpa_START (20)
#define SOC_CCI500_A53_CPUMEM_CTRL0_tlb_twlpa_END (20)
#define SOC_CCI500_A53_CPUMEM_CTRL0_L1_ddirty_tsel_START (21)
#define SOC_CCI500_A53_CPUMEM_CTRL0_L1_ddirty_tsel_END (23)
#define SOC_CCI500_A53_CPUMEM_CTRL0_L1_ddirty_test_START (24)
#define SOC_CCI500_A53_CPUMEM_CTRL0_L1_ddirty_test_END (26)
#define SOC_CCI500_A53_CPUMEM_CTRL0_L1_ddirty_twlpa_START (27)
#define SOC_CCI500_A53_CPUMEM_CTRL0_L1_ddirty_twlpa_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int L1_dtag_tsel : 3;
        unsigned int L1_dtag_test : 3;
        unsigned int L1_dtag_twlpa : 1;
        unsigned int L1_ddata_tsel : 3;
        unsigned int L1_ddata_test : 3;
        unsigned int L1_ddata_twlpa : 1;
        unsigned int L1_itag_tsel : 3;
        unsigned int L1_itag_test : 3;
        unsigned int L1_itag_twlpa : 1;
        unsigned int L1_idata_tsel : 3;
        unsigned int L1_idata_test : 3;
        unsigned int L1_idata_twlpa : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_CCI500_A53_CPUMEM_CTRL1_UNION;
#endif
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_dtag_tsel_START (0)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_dtag_tsel_END (2)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_dtag_test_START (3)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_dtag_test_END (5)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_dtag_twlpa_START (6)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_dtag_twlpa_END (6)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_ddata_tsel_START (7)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_ddata_tsel_END (9)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_ddata_test_START (10)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_ddata_test_END (12)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_ddata_twlpa_START (13)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_ddata_twlpa_END (13)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_itag_tsel_START (14)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_itag_tsel_END (16)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_itag_test_START (17)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_itag_test_END (19)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_itag_twlpa_START (20)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_itag_twlpa_END (20)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_idata_tsel_START (21)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_idata_tsel_END (23)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_idata_test_START (24)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_idata_test_END (26)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_idata_twlpa_START (27)
#define SOC_CCI500_A53_CPUMEM_CTRL1_L1_idata_twlpa_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scul1d_tag_tsel : 3;
        unsigned int scul1d_tag_test : 3;
        unsigned int scul1d_tag_twlpa : 1;
        unsigned int L2_tag_tsel : 3;
        unsigned int L2_tag_test : 3;
        unsigned int L2_tag_twlpa : 1;
        unsigned int L2_victim_tsel : 3;
        unsigned int L2_victim_test : 3;
        unsigned int L2_victim_twlpa : 1;
        unsigned int L2_data_wtsel : 2;
        unsigned int L2_data_rtsel : 2;
        unsigned int reserved : 7;
    } reg;
} SOC_CCI500_A53_CPUMEM_CTRL2_UNION;
#endif
#define SOC_CCI500_A53_CPUMEM_CTRL2_scul1d_tag_tsel_START (0)
#define SOC_CCI500_A53_CPUMEM_CTRL2_scul1d_tag_tsel_END (2)
#define SOC_CCI500_A53_CPUMEM_CTRL2_scul1d_tag_test_START (3)
#define SOC_CCI500_A53_CPUMEM_CTRL2_scul1d_tag_test_END (5)
#define SOC_CCI500_A53_CPUMEM_CTRL2_scul1d_tag_twlpa_START (6)
#define SOC_CCI500_A53_CPUMEM_CTRL2_scul1d_tag_twlpa_END (6)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_tag_tsel_START (7)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_tag_tsel_END (9)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_tag_test_START (10)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_tag_test_END (12)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_tag_twlpa_START (13)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_tag_twlpa_END (13)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_victim_tsel_START (14)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_victim_tsel_END (16)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_victim_test_START (17)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_victim_test_END (19)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_victim_twlpa_START (20)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_victim_twlpa_END (20)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_data_wtsel_START (21)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_data_wtsel_END (22)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_data_rtsel_START (23)
#define SOC_CCI500_A53_CPUMEM_CTRL2_L2_data_rtsel_END (24)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

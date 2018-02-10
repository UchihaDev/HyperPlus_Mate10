#ifndef __SOC_ISP_YUVNF_IIR_INTERFACE_H__
#define __SOC_ISP_YUVNF_IIR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_YUVNF_IIR_YUVNF_IIR_CONFIG_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_YUVNF_IIR_SA_NUM_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_YUVNF_IIR_SA0_CB_THR0_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_YUVNF_IIR_SA0_CB_THR1_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_YUVNF_IIR_SA0_CR_THR0_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_YUVNF_IIR_SA0_CR_THR1_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_YUVNF_IIR_SA0_NR_STRENGTH_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_YUVNF_IIR_SA1_CB_THR0_ADDR(base) ((base) + (0x001C))
#define SOC_ISP_YUVNF_IIR_SA1_CB_THR1_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_YUVNF_IIR_SA1_CR_THR0_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_YUVNF_IIR_SA1_CR_THR1_ADDR(base) ((base) + (0x0028))
#define SOC_ISP_YUVNF_IIR_SA1_NR_STRENGTH_ADDR(base) ((base) + (0x002C))
#define SOC_ISP_YUVNF_IIR_SA2_CB_THR0_ADDR(base) ((base) + (0x0030))
#define SOC_ISP_YUVNF_IIR_SA2_CB_THR1_ADDR(base) ((base) + (0x0034))
#define SOC_ISP_YUVNF_IIR_SA2_CR_THR0_ADDR(base) ((base) + (0x0038))
#define SOC_ISP_YUVNF_IIR_SA2_CR_THR1_ADDR(base) ((base) + (0x003C))
#define SOC_ISP_YUVNF_IIR_SA2_NR_STRENGTH_ADDR(base) ((base) + (0x0040))
#define SOC_ISP_YUVNF_IIR_SA3_CB_THR0_ADDR(base) ((base) + (0x0044))
#define SOC_ISP_YUVNF_IIR_SA3_CB_THR1_ADDR(base) ((base) + (0x0048))
#define SOC_ISP_YUVNF_IIR_SA3_CR_THR0_ADDR(base) ((base) + (0x004C))
#define SOC_ISP_YUVNF_IIR_SA3_CR_THR1_ADDR(base) ((base) + (0x0050))
#define SOC_ISP_YUVNF_IIR_SA3_NR_STRENGTH_ADDR(base) ((base) + (0x0054))
#define SOC_ISP_YUVNF_IIR_SAT_THR_U_ADDR(base) ((base) + (0x0058))
#define SOC_ISP_YUVNF_IIR_SAT_THR_V_ADDR(base) ((base) + (0x005C))
#define SOC_ISP_YUVNF_IIR_DELTA_THR_U_ADDR(base) ((base) + (0x0060))
#define SOC_ISP_YUVNF_IIR_DELTA_THR_V_ADDR(base) ((base) + (0x0064))
#define SOC_ISP_YUVNF_IIR_EDGE_STREN_THR_U_ADDR(base) ((base) + (0x0068))
#define SOC_ISP_YUVNF_IIR_EDGE_STREN_THR_V_ADDR(base) ((base) + (0x006C))
#define SOC_ISP_YUVNF_IIR_WEIGHTLUT_ADDR(base,Range128) ((base) + (0x0070+0x4*(Range128)))
#define SOC_ISP_YUVNF_IIR_NR_LUMA_CONTROL_ADDR(base,Range64) ((base) + (0x0270+0x4*(Range64)))
#define SOC_ISP_YUVNF_IIR_THR0_ADDR(base) ((base) + (0x0370))
#define SOC_ISP_YUVNF_IIR_THR1_ADDR(base) ((base) + (0x0374))
#define SOC_ISP_YUVNF_IIR_THR2_ADDR(base) ((base) + (0x0378))
#define SOC_ISP_YUVNF_IIR_COF0_ADDR(base) ((base) + (0x037C))
#define SOC_ISP_YUVNF_IIR_COF1_ADDR(base) ((base) + (0x0380))
#define SOC_ISP_YUVNF_IIR_COF2_ADDR(base) ((base) + (0x0384))
#define SOC_ISP_YUVNF_IIR_SK_THR_ADDR(base) ((base) + (0x0388))
#define SOC_ISP_YUVNF_IIR_SA0_Y_NR_STRENGTH_ADDR(base) ((base) + (0x038C))
#define SOC_ISP_YUVNF_IIR_SA1_Y_NR_STRENGTH_ADDR(base) ((base) + (0x0390))
#define SOC_ISP_YUVNF_IIR_SA2_Y_NR_STRENGTH_ADDR(base) ((base) + (0x0394))
#define SOC_ISP_YUVNF_IIR_SA3_Y_NR_STRENGTH_ADDR(base) ((base) + (0x0398))
#define SOC_ISP_YUVNF_IIR_IPR_THR_ADDR(base) ((base) + (0x039C))
#define SOC_ISP_YUVNF_IIR_IPR_THR0_ADDR(base) ((base) + (0x03A0))
#define SOC_ISP_YUVNF_IIR_IPR_THR1_ADDR(base) ((base) + (0x03A4))
#define SOC_ISP_YUVNF_IIR_IPR_THR2_ADDR(base) ((base) + (0x03A8))
#define SOC_ISP_YUVNF_IIR_IPR_THR3_ADDR(base) ((base) + (0x03AC))
#define SOC_ISP_YUVNF_IIR_IPR_FW_ADDR(base) ((base) + (0x03B0))
#define SOC_ISP_YUVNF_IIR_IPR_CNT_ADDR(base) ((base) + (0x03B4))
#define SOC_ISP_YUVNF_IIR_SEGPOINT_ADDR(base,Range32) ((base) + (0x03B8+0x4*(Range32)))
#define SOC_ISP_YUVNF_IIR_K_ADDR(base,Range32) ((base) + (0x04B8+0x4*(Range32)))
#define SOC_ISP_YUVNF_IIR_B_ADDR(base,Range32) ((base) + (0x05B8+0x4*(Range32)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int full_bypass : 1;
        unsigned int uv_enable : 1;
        unsigned int ipr_mode : 1;
        unsigned int force_clk_on : 1;
        unsigned int active_bypass : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_YUVNF_IIR_YUVNF_IIR_CONFIG_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_YUVNF_IIR_CONFIG_full_bypass_START (0)
#define SOC_ISP_YUVNF_IIR_YUVNF_IIR_CONFIG_full_bypass_END (0)
#define SOC_ISP_YUVNF_IIR_YUVNF_IIR_CONFIG_uv_enable_START (1)
#define SOC_ISP_YUVNF_IIR_YUVNF_IIR_CONFIG_uv_enable_END (1)
#define SOC_ISP_YUVNF_IIR_YUVNF_IIR_CONFIG_ipr_mode_START (2)
#define SOC_ISP_YUVNF_IIR_YUVNF_IIR_CONFIG_ipr_mode_END (2)
#define SOC_ISP_YUVNF_IIR_YUVNF_IIR_CONFIG_force_clk_on_START (3)
#define SOC_ISP_YUVNF_IIR_YUVNF_IIR_CONFIG_force_clk_on_END (3)
#define SOC_ISP_YUVNF_IIR_YUVNF_IIR_CONFIG_active_bypass_START (4)
#define SOC_ISP_YUVNF_IIR_YUVNF_IIR_CONFIG_active_bypass_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa_num : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_YUVNF_IIR_SA_NUM_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA_NUM_sa_num_START (0)
#define SOC_ISP_YUVNF_IIR_SA_NUM_sa_num_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa0_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA0_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA0_CB_THR0_sa0_cb_thr0_START (0)
#define SOC_ISP_YUVNF_IIR_SA0_CB_THR0_sa0_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa0_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA0_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA0_CB_THR1_sa0_cb_thr1_START (0)
#define SOC_ISP_YUVNF_IIR_SA0_CB_THR1_sa0_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa0_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA0_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA0_CR_THR0_sa0_cr_thr0_START (0)
#define SOC_ISP_YUVNF_IIR_SA0_CR_THR0_sa0_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa0_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA0_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA0_CR_THR1_sa0_cr_thr1_START (0)
#define SOC_ISP_YUVNF_IIR_SA0_CR_THR1_sa0_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa0_nr_strength : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_YUVNF_IIR_SA0_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA0_NR_STRENGTH_sa0_nr_strength_START (0)
#define SOC_ISP_YUVNF_IIR_SA0_NR_STRENGTH_sa0_nr_strength_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa1_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA1_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA1_CB_THR0_sa1_cb_thr0_START (0)
#define SOC_ISP_YUVNF_IIR_SA1_CB_THR0_sa1_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa1_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA1_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA1_CB_THR1_sa1_cb_thr1_START (0)
#define SOC_ISP_YUVNF_IIR_SA1_CB_THR1_sa1_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa1_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA1_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA1_CR_THR0_sa1_cr_thr0_START (0)
#define SOC_ISP_YUVNF_IIR_SA1_CR_THR0_sa1_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa1_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA1_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA1_CR_THR1_sa1_cr_thr1_START (0)
#define SOC_ISP_YUVNF_IIR_SA1_CR_THR1_sa1_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa1_nr_strength : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_YUVNF_IIR_SA1_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA1_NR_STRENGTH_sa1_nr_strength_START (0)
#define SOC_ISP_YUVNF_IIR_SA1_NR_STRENGTH_sa1_nr_strength_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa2_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA2_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA2_CB_THR0_sa2_cb_thr0_START (0)
#define SOC_ISP_YUVNF_IIR_SA2_CB_THR0_sa2_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa2_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA2_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA2_CB_THR1_sa2_cb_thr1_START (0)
#define SOC_ISP_YUVNF_IIR_SA2_CB_THR1_sa2_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa2_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA2_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA2_CR_THR0_sa2_cr_thr0_START (0)
#define SOC_ISP_YUVNF_IIR_SA2_CR_THR0_sa2_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa2_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA2_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA2_CR_THR1_sa2_cr_thr1_START (0)
#define SOC_ISP_YUVNF_IIR_SA2_CR_THR1_sa2_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa2_nr_strength : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_YUVNF_IIR_SA2_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA2_NR_STRENGTH_sa2_nr_strength_START (0)
#define SOC_ISP_YUVNF_IIR_SA2_NR_STRENGTH_sa2_nr_strength_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa3_cb_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA3_CB_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA3_CB_THR0_sa3_cb_thr0_START (0)
#define SOC_ISP_YUVNF_IIR_SA3_CB_THR0_sa3_cb_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa3_cb_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA3_CB_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA3_CB_THR1_sa3_cb_thr1_START (0)
#define SOC_ISP_YUVNF_IIR_SA3_CB_THR1_sa3_cb_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa3_cr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA3_CR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA3_CR_THR0_sa3_cr_thr0_START (0)
#define SOC_ISP_YUVNF_IIR_SA3_CR_THR0_sa3_cr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa3_cr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SA3_CR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA3_CR_THR1_sa3_cr_thr1_START (0)
#define SOC_ISP_YUVNF_IIR_SA3_CR_THR1_sa3_cr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa3_nr_strength : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_YUVNF_IIR_SA3_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA3_NR_STRENGTH_sa3_nr_strength_START (0)
#define SOC_ISP_YUVNF_IIR_SA3_NR_STRENGTH_sa3_nr_strength_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sat_thr_u : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_ISP_YUVNF_IIR_SAT_THR_U_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SAT_THR_U_sat_thr_u_START (0)
#define SOC_ISP_YUVNF_IIR_SAT_THR_U_sat_thr_u_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sat_thr_v : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_ISP_YUVNF_IIR_SAT_THR_V_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SAT_THR_V_sat_thr_v_START (0)
#define SOC_ISP_YUVNF_IIR_SAT_THR_V_sat_thr_v_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int delta_thr_u : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_DELTA_THR_U_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_DELTA_THR_U_delta_thr_u_START (0)
#define SOC_ISP_YUVNF_IIR_DELTA_THR_U_delta_thr_u_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int delta_thr_v : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_DELTA_THR_V_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_DELTA_THR_V_delta_thr_v_START (0)
#define SOC_ISP_YUVNF_IIR_DELTA_THR_V_delta_thr_v_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edge_stren_thr_u : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ISP_YUVNF_IIR_EDGE_STREN_THR_U_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_EDGE_STREN_THR_U_edge_stren_thr_u_START (0)
#define SOC_ISP_YUVNF_IIR_EDGE_STREN_THR_U_edge_stren_thr_u_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edge_stren_thr_v : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ISP_YUVNF_IIR_EDGE_STREN_THR_V_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_EDGE_STREN_THR_V_edge_stren_thr_v_START (0)
#define SOC_ISP_YUVNF_IIR_EDGE_STREN_THR_V_edge_stren_thr_v_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int weightlut : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_YUVNF_IIR_WEIGHTLUT_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_WEIGHTLUT_weightlut_START (0)
#define SOC_ISP_YUVNF_IIR_WEIGHTLUT_weightlut_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int add_back : 8;
        unsigned int nr_luma_control : 6;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_YUVNF_IIR_NR_LUMA_CONTROL_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_NR_LUMA_CONTROL_add_back_START (0)
#define SOC_ISP_YUVNF_IIR_NR_LUMA_CONTROL_add_back_END (7)
#define SOC_ISP_YUVNF_IIR_NR_LUMA_CONTROL_nr_luma_control_START (8)
#define SOC_ISP_YUVNF_IIR_NR_LUMA_CONTROL_nr_luma_control_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_THR0_thr0_START (0)
#define SOC_ISP_YUVNF_IIR_THR0_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_THR1_thr1_START (0)
#define SOC_ISP_YUVNF_IIR_THR1_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thr2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_THR2_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_THR2_thr2_START (0)
#define SOC_ISP_YUVNF_IIR_THR2_thr2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cof0 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_YUVNF_IIR_COF0_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_COF0_cof0_START (0)
#define SOC_ISP_YUVNF_IIR_COF0_cof0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cof1 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_YUVNF_IIR_COF1_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_COF1_cof1_START (0)
#define SOC_ISP_YUVNF_IIR_COF1_cof1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cof2 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_YUVNF_IIR_COF2_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_COF2_cof2_START (0)
#define SOC_ISP_YUVNF_IIR_COF2_cof2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sk_thr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_SK_THR_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SK_THR_sk_thr_START (0)
#define SOC_ISP_YUVNF_IIR_SK_THR_sk_thr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa0_y_nr_strength : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_IIR_SA0_Y_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA0_Y_NR_STRENGTH_sa0_y_nr_strength_START (0)
#define SOC_ISP_YUVNF_IIR_SA0_Y_NR_STRENGTH_sa0_y_nr_strength_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa1_y_nr_strength : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_IIR_SA1_Y_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA1_Y_NR_STRENGTH_sa1_y_nr_strength_START (0)
#define SOC_ISP_YUVNF_IIR_SA1_Y_NR_STRENGTH_sa1_y_nr_strength_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa2_y_nr_strength : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_IIR_SA2_Y_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA2_Y_NR_STRENGTH_sa2_y_nr_strength_START (0)
#define SOC_ISP_YUVNF_IIR_SA2_Y_NR_STRENGTH_sa2_y_nr_strength_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sa3_y_nr_strength : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_IIR_SA3_Y_NR_STRENGTH_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SA3_Y_NR_STRENGTH_sa3_y_nr_strength_START (0)
#define SOC_ISP_YUVNF_IIR_SA3_Y_NR_STRENGTH_sa3_y_nr_strength_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipr_thr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_IPR_THR_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_IPR_THR_ipr_thr_START (0)
#define SOC_ISP_YUVNF_IIR_IPR_THR_ipr_thr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipr_thr0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_IPR_THR0_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_IPR_THR0_ipr_thr0_START (0)
#define SOC_ISP_YUVNF_IIR_IPR_THR0_ipr_thr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipr_thr1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_IPR_THR1_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_IPR_THR1_ipr_thr1_START (0)
#define SOC_ISP_YUVNF_IIR_IPR_THR1_ipr_thr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipr_thr2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_IPR_THR2_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_IPR_THR2_ipr_thr2_START (0)
#define SOC_ISP_YUVNF_IIR_IPR_THR2_ipr_thr2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipr_thr3 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_IPR_THR3_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_IPR_THR3_ipr_thr3_START (0)
#define SOC_ISP_YUVNF_IIR_IPR_THR3_ipr_thr3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipr_fw : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_YUVNF_IIR_IPR_FW_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_IPR_FW_ipr_fw_START (0)
#define SOC_ISP_YUVNF_IIR_IPR_FW_ipr_fw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipr_cnt : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_YUVNF_IIR_IPR_CNT_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_IPR_CNT_ipr_cnt_START (0)
#define SOC_ISP_YUVNF_IIR_IPR_CNT_ipr_cnt_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int segpoint : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_YUVNF_IIR_SEGPOINT_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_SEGPOINT_segpoint_START (0)
#define SOC_ISP_YUVNF_IIR_SEGPOINT_segpoint_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int k : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_YUVNF_IIR_K_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_K_k_START (0)
#define SOC_ISP_YUVNF_IIR_K_k_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int b : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_YUVNF_IIR_B_UNION;
#endif
#define SOC_ISP_YUVNF_IIR_B_b_START (0)
#define SOC_ISP_YUVNF_IIR_B_b_END (15)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

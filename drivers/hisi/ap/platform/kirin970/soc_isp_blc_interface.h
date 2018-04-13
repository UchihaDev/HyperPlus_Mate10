#ifndef __SOC_ISP_BLC_INTERFACE_H__
#define __SOC_ISP_BLC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_BLC_BLC_CTRL_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_BLC_BLC_SAMPLES_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_BLC_BLC_H1_START_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_BLC_BLC_H1_STOP_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_BLC_BLC_V1_START_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_BLC_BLC_V1_STOP_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_BLC_BLC_H2_START_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_BLC_BLC_H2_STOP_ADDR(base) ((base) + (0x001C))
#define SOC_ISP_BLC_BLC_V2_START_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_BLC_BLC_V2_STOP_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_BLC_BLC_A_FIXED_ADDR(base) ((base) + (0x0028))
#define SOC_ISP_BLC_BLC_B_FIXED_ADDR(base) ((base) + (0x002C))
#define SOC_ISP_BLC_BLC_C_FIXED_ADDR(base) ((base) + (0x0030))
#define SOC_ISP_BLC_BLC_D_FIXED_ADDR(base) ((base) + (0x0034))
#define SOC_ISP_BLC_BLC_A_MEASURED_ADDR(base) ((base) + (0x0038))
#define SOC_ISP_BLC_BLC_B_MEASURED_ADDR(base) ((base) + (0x003C))
#define SOC_ISP_BLC_BLC_C_MEASURED_ADDR(base) ((base) + (0x0040))
#define SOC_ISP_BLC_BLC_D_MEASURED_ADDR(base) ((base) + (0x0044))
#define SOC_ISP_BLC_MEAS_IHLEFT_ADDR(base) ((base) + (0x0048))
#define SOC_ISP_BLC_MEAS_IVTOP_ADDR(base) ((base) + (0x004C))
#define SOC_ISP_BLC_MEAS_IHRIGHT_ADDR(base) ((base) + (0x0050))
#define SOC_ISP_BLC_MEAS_IVBOTTOM_ADDR(base) ((base) + (0x0054))
#define SOC_ISP_BLC_SUB_IHLEFT_ADDR(base) ((base) + (0x0058))
#define SOC_ISP_BLC_SUB_IVTOP_ADDR(base) ((base) + (0x005C))
#define SOC_ISP_BLC_SUB_IHRIGHT_ADDR(base) ((base) + (0x0060))
#define SOC_ISP_BLC_SUB_IVBOTTOM_ADDR(base) ((base) + (0x0064))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_enable : 1;
        unsigned int reserved_0 : 1;
        unsigned int blc_win_en : 2;
        unsigned int blc_measure_enable : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_ISP_BLC_BLC_CTRL_UNION;
#endif
#define SOC_ISP_BLC_BLC_CTRL_blc_enable_START (0)
#define SOC_ISP_BLC_BLC_CTRL_blc_enable_END (0)
#define SOC_ISP_BLC_BLC_CTRL_blc_win_en_START (2)
#define SOC_ISP_BLC_BLC_CTRL_blc_win_en_END (3)
#define SOC_ISP_BLC_BLC_CTRL_blc_measure_enable_START (4)
#define SOC_ISP_BLC_BLC_CTRL_blc_measure_enable_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_samples : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_BLC_BLC_SAMPLES_UNION;
#endif
#define SOC_ISP_BLC_BLC_SAMPLES_blc_samples_START (0)
#define SOC_ISP_BLC_BLC_SAMPLES_blc_samples_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_h1_start : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_BLC_H1_START_UNION;
#endif
#define SOC_ISP_BLC_BLC_H1_START_blc_h1_start_START (0)
#define SOC_ISP_BLC_BLC_H1_START_blc_h1_start_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_h1_stop : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_BLC_H1_STOP_UNION;
#endif
#define SOC_ISP_BLC_BLC_H1_STOP_blc_h1_stop_START (0)
#define SOC_ISP_BLC_BLC_H1_STOP_blc_h1_stop_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_v1_start : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_BLC_V1_START_UNION;
#endif
#define SOC_ISP_BLC_BLC_V1_START_blc_v1_start_START (0)
#define SOC_ISP_BLC_BLC_V1_START_blc_v1_start_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_v1_stop : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_BLC_V1_STOP_UNION;
#endif
#define SOC_ISP_BLC_BLC_V1_STOP_blc_v1_stop_START (0)
#define SOC_ISP_BLC_BLC_V1_STOP_blc_v1_stop_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_h2_start : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_BLC_H2_START_UNION;
#endif
#define SOC_ISP_BLC_BLC_H2_START_blc_h2_start_START (0)
#define SOC_ISP_BLC_BLC_H2_START_blc_h2_start_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_h2_stop : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_BLC_H2_STOP_UNION;
#endif
#define SOC_ISP_BLC_BLC_H2_STOP_blc_h2_stop_START (0)
#define SOC_ISP_BLC_BLC_H2_STOP_blc_h2_stop_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_v2_start : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_BLC_V2_START_UNION;
#endif
#define SOC_ISP_BLC_BLC_V2_START_blc_v2_start_START (0)
#define SOC_ISP_BLC_BLC_V2_START_blc_v2_start_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_v2_stop : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_BLC_V2_STOP_UNION;
#endif
#define SOC_ISP_BLC_BLC_V2_STOP_blc_v2_stop_START (0)
#define SOC_ISP_BLC_BLC_V2_STOP_blc_v2_stop_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_a_fixed : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_BLC_BLC_A_FIXED_UNION;
#endif
#define SOC_ISP_BLC_BLC_A_FIXED_blc_a_fixed_START (0)
#define SOC_ISP_BLC_BLC_A_FIXED_blc_a_fixed_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_b_fixed : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_BLC_BLC_B_FIXED_UNION;
#endif
#define SOC_ISP_BLC_BLC_B_FIXED_blc_b_fixed_START (0)
#define SOC_ISP_BLC_BLC_B_FIXED_blc_b_fixed_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_c_fixed : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_BLC_BLC_C_FIXED_UNION;
#endif
#define SOC_ISP_BLC_BLC_C_FIXED_blc_c_fixed_START (0)
#define SOC_ISP_BLC_BLC_C_FIXED_blc_c_fixed_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_d_fixed : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_BLC_BLC_D_FIXED_UNION;
#endif
#define SOC_ISP_BLC_BLC_D_FIXED_blc_d_fixed_START (0)
#define SOC_ISP_BLC_BLC_D_FIXED_blc_d_fixed_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_a_measured : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_BLC_A_MEASURED_UNION;
#endif
#define SOC_ISP_BLC_BLC_A_MEASURED_blc_a_measured_START (0)
#define SOC_ISP_BLC_BLC_A_MEASURED_blc_a_measured_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_b_measured : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_BLC_B_MEASURED_UNION;
#endif
#define SOC_ISP_BLC_BLC_B_MEASURED_blc_b_measured_START (0)
#define SOC_ISP_BLC_BLC_B_MEASURED_blc_b_measured_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_c_measured : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_BLC_C_MEASURED_UNION;
#endif
#define SOC_ISP_BLC_BLC_C_MEASURED_blc_c_measured_START (0)
#define SOC_ISP_BLC_BLC_C_MEASURED_blc_c_measured_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_d_measured : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_BLC_D_MEASURED_UNION;
#endif
#define SOC_ISP_BLC_BLC_D_MEASURED_blc_d_measured_START (0)
#define SOC_ISP_BLC_BLC_D_MEASURED_blc_d_measured_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int meas_ihleft : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_MEAS_IHLEFT_UNION;
#endif
#define SOC_ISP_BLC_MEAS_IHLEFT_meas_ihleft_START (0)
#define SOC_ISP_BLC_MEAS_IHLEFT_meas_ihleft_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int meas_ivtop : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_MEAS_IVTOP_UNION;
#endif
#define SOC_ISP_BLC_MEAS_IVTOP_meas_ivtop_START (0)
#define SOC_ISP_BLC_MEAS_IVTOP_meas_ivtop_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int meas_ihright : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_MEAS_IHRIGHT_UNION;
#endif
#define SOC_ISP_BLC_MEAS_IHRIGHT_meas_ihright_START (0)
#define SOC_ISP_BLC_MEAS_IHRIGHT_meas_ihright_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int meas_ivbottom : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_MEAS_IVBOTTOM_UNION;
#endif
#define SOC_ISP_BLC_MEAS_IVBOTTOM_meas_ivbottom_START (0)
#define SOC_ISP_BLC_MEAS_IVBOTTOM_meas_ivbottom_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub_ihleft : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_SUB_IHLEFT_UNION;
#endif
#define SOC_ISP_BLC_SUB_IHLEFT_sub_ihleft_START (0)
#define SOC_ISP_BLC_SUB_IHLEFT_sub_ihleft_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub_ivtop : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_SUB_IVTOP_UNION;
#endif
#define SOC_ISP_BLC_SUB_IVTOP_sub_ivtop_START (0)
#define SOC_ISP_BLC_SUB_IVTOP_sub_ivtop_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub_ihright : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_SUB_IHRIGHT_UNION;
#endif
#define SOC_ISP_BLC_SUB_IHRIGHT_sub_ihright_START (0)
#define SOC_ISP_BLC_SUB_IHRIGHT_sub_ihright_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub_ivbottom : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_ISP_BLC_SUB_IVBOTTOM_UNION;
#endif
#define SOC_ISP_BLC_SUB_IVBOTTOM_sub_ivbottom_START (0)
#define SOC_ISP_BLC_SUB_IVBOTTOM_sub_ivbottom_END (13)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

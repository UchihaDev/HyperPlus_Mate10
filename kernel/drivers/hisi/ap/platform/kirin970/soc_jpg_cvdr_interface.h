#ifndef __SOC_JPG_CVDR_INTERFACE_H__
#define __SOC_JPG_CVDR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_ADDR(base) ((base) + (0x0))
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_DEBUG_EN_ADDR(base) ((base) + (0x4))
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_DEBUG_ADDR(base) ((base) + (0x8))
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_ADDR(base) ((base) + (0xC))
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_ADDR(base) ((base) + (0x10))
#define SOC_JPG_CVDR_AXI_JPEG_OTHER_RO_ADDR(base) ((base) + (0x14))
#define SOC_JPG_CVDR_AXI_JPEG_OTHER_RW_ADDR(base) ((base) + (0x18))
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_CFG_0_ADDR(base) ((base) + (0x1C))
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_AXI_FS_0_ADDR(base) ((base) + (0x20))
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_AXI_LINE_0_ADDR(base) ((base) + (0x24))
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_ADDR(base) ((base) + (0x28))
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_VP_WR_0_ADDR(base) ((base) + (0x400))
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_ADDR(base) ((base) + (0x900))
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_DEBUG_0_ADDR(base) ((base) + (0x904))
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_0_ADDR(base) ((base) + (0x908))
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_ADDR(base) ((base) + (0x910))
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_DEBUG_1_ADDR(base) ((base) + (0x914))
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_1_ADDR(base) ((base) + (0x918))
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_ADDR(base) ((base) + (0xA00))
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_DEBUG_0_ADDR(base) ((base) + (0xA04))
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_0_ADDR(base) ((base) + (0xA08))
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_ADDR(base) ((base) + (0xA10))
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_DEBUG_1_ADDR(base) ((base) + (0xA14))
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_1_ADDR(base) ((base) + (0xA18))
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_ADDR(base) ((base) + (0xA20))
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_DEBUG_2_ADDR(base) ((base) + (0xA24))
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_2_ADDR(base) ((base) + (0xA28))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_0_ADDR(base) ((base) + (0xB00))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_1_ADDR(base) ((base) + (0xB04))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_2_ADDR(base) ((base) + (0xB08))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_3_ADDR(base) ((base) + (0xB0C))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_4_ADDR(base) ((base) + (0xB10))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_5_ADDR(base) ((base) + (0xB14))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_6_ADDR(base) ((base) + (0xB18))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_7_ADDR(base) ((base) + (0xB1C))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_8_ADDR(base) ((base) + (0xB20))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_9_ADDR(base) ((base) + (0xB24))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_10_ADDR(base) ((base) + (0xB28))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_11_ADDR(base) ((base) + (0xB2C))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_12_ADDR(base) ((base) + (0xB30))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_13_ADDR(base) ((base) + (0xB34))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_14_ADDR(base) ((base) + (0xB38))
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_15_ADDR(base) ((base) + (0xB3C))
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_WR_0_ADDR(base) ((base) + (0xC00))
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_WR_1_ADDR(base) ((base) + (0xC04))
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_RD_0_ADDR(base) ((base) + (0xC40))
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_RD_1_ADDR(base) ((base) + (0xC44))
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_RD_2_ADDR(base) ((base) + (0xC48))
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_VP_WR_0_ADDR(base) ((base) + (0xC80))
#define SOC_JPG_CVDR_AXI_JPEG_SPARE_0_ADDR(base) ((base) + (0xE00))
#define SOC_JPG_CVDR_AXI_JPEG_SPARE_1_ADDR(base) ((base) + (0xE04))
#define SOC_JPG_CVDR_AXI_JPEG_SPARE_2_ADDR(base) ((base) + (0xE08))
#define SOC_JPG_CVDR_AXI_JPEG_SPARE_3_ADDR(base) ((base) + (0xE0C))
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_DEBUG_0_ADDR(base) ((base) + (0xF00))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axiwrite_du_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int du_threshold_reached : 8;
        unsigned int max_axiread_id : 5;
        unsigned int reserved_1 : 3;
        unsigned int max_axiwrite_id : 5;
        unsigned int reserved_2 : 1;
        unsigned int force_rd_clk_on : 1;
        unsigned int force_wr_clk_on : 1;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_axiwrite_du_threshold_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_axiwrite_du_threshold_END (5)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_du_threshold_reached_START (8)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_du_threshold_reached_END (15)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_max_axiread_id_START (16)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_max_axiread_id_END (20)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_max_axiwrite_id_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_max_axiwrite_id_END (28)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_force_rd_clk_on_START (30)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_force_rd_clk_on_END (30)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_force_wr_clk_on_START (31)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_CFG_force_wr_clk_on_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_peak_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int rd_peak_en : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_CVDR_DEBUG_EN_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_DEBUG_EN_wr_peak_en_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_DEBUG_EN_wr_peak_en_END (0)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_DEBUG_EN_rd_peak_en_START (8)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_DEBUG_EN_rd_peak_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_peak : 8;
        unsigned int rd_peak : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_CVDR_DEBUG_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_DEBUG_wr_peak_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_DEBUG_wr_peak_END (7)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_DEBUG_rd_peak_START (8)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_DEBUG_rd_peak_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_qos_threshold_01_stop : 4;
        unsigned int wr_qos_threshold_01_start : 4;
        unsigned int wr_qos_threshold_10_stop : 4;
        unsigned int wr_qos_threshold_10_start : 4;
        unsigned int wr_qos_threshold_11_stop : 4;
        unsigned int wr_qos_threshold_11_start : 4;
        unsigned int reserved : 2;
        unsigned int wr_qos_min : 2;
        unsigned int wr_qos_max : 2;
        unsigned int wr_qos_sr : 2;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_threshold_01_stop_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_threshold_01_stop_END (3)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_threshold_01_start_START (4)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_threshold_01_start_END (7)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_threshold_10_stop_START (8)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_threshold_10_stop_END (11)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_threshold_10_start_START (12)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_threshold_10_start_END (15)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_threshold_11_stop_START (16)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_threshold_11_stop_END (19)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_threshold_11_start_START (20)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_threshold_11_start_END (23)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_min_START (26)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_min_END (27)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_max_START (28)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_max_END (29)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_sr_START (30)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_WR_QOS_CFG_wr_qos_sr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_qos_threshold_01_stop : 4;
        unsigned int rd_qos_threshold_01_start : 4;
        unsigned int rd_qos_threshold_10_stop : 4;
        unsigned int rd_qos_threshold_10_start : 4;
        unsigned int rd_qos_threshold_11_stop : 4;
        unsigned int rd_qos_threshold_11_start : 4;
        unsigned int reserved : 2;
        unsigned int rd_qos_min : 2;
        unsigned int rd_qos_max : 2;
        unsigned int rd_qos_sr : 2;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_threshold_01_stop_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_threshold_01_stop_END (3)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_threshold_01_start_START (4)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_threshold_01_start_END (7)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_threshold_10_stop_START (8)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_threshold_10_stop_END (11)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_threshold_10_start_START (12)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_threshold_10_start_END (15)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_threshold_11_stop_START (16)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_threshold_11_stop_END (19)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_threshold_11_start_START (20)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_threshold_11_start_END (23)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_min_START (26)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_min_END (27)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_max_START (28)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_max_END (29)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_sr_START (30)
#define SOC_JPG_CVDR_AXI_JPEG_CVDR_RD_QOS_CFG_rd_qos_sr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int other_ro : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_OTHER_RO_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_OTHER_RO_other_ro_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_OTHER_RO_other_ro_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int other_rw : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_OTHER_RW_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_OTHER_RW_other_rw_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_OTHER_RW_other_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_0 : 4;
        unsigned int vpwr_pixel_expansion_0 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_0 : 17;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_VP_WR_CFG_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_CFG_0_vpwr_pixel_format_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_CFG_0_vpwr_pixel_format_0_END (3)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_CFG_0_vpwr_pixel_expansion_0_START (4)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_CFG_0_vpwr_pixel_expansion_0_END (4)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_CFG_0_vpwr_last_page_0_START (15)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_CFG_0_vpwr_last_page_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_0 : 28;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_VP_WR_AXI_FS_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_AXI_FS_0_vpwr_address_frame_start_0_START (4)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_AXI_FS_0_vpwr_address_frame_start_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_0 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_0 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_VP_WR_AXI_LINE_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_AXI_LINE_0_vpwr_line_stride_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_AXI_LINE_0_vpwr_line_stride_0_END (9)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_AXI_LINE_0_vpwr_line_wrap_0_START (15)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_AXI_LINE_0_vpwr_line_wrap_0_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int vp_wr_stop_enable_du_threshold_reached_0 : 1;
        unsigned int vp_wr_stop_enable_flux_ctrl_0 : 1;
        unsigned int vp_wr_stop_enable_pressure_0 : 1;
        unsigned int reserved_1 : 5;
        unsigned int vp_wr_stop_ok_0 : 1;
        unsigned int vp_wr_stop_0 : 1;
        unsigned int reserved_2 : 5;
        unsigned int vpwr_prefetch_bypass_0 : 1;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_vp_wr_stop_enable_du_threshold_reached_0_START (16)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_vp_wr_stop_enable_du_threshold_reached_0_END (16)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_vp_wr_stop_enable_flux_ctrl_0_START (17)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_vp_wr_stop_enable_flux_ctrl_0_END (17)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_vp_wr_stop_enable_pressure_0_START (18)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_vp_wr_stop_enable_pressure_0_END (18)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_vp_wr_stop_ok_0_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_vp_wr_stop_ok_0_END (24)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_vp_wr_stop_0_START (25)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_vp_wr_stop_0_END (25)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_vpwr_prefetch_bypass_0_START (31)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_IF_CFG_0_vpwr_prefetch_bypass_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_0 : 4;
        unsigned int vpwr_access_limiter_1_0 : 4;
        unsigned int vpwr_access_limiter_2_0 : 4;
        unsigned int vpwr_access_limiter_3_0 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_0 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_LIMITER_VP_WR_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_VP_WR_0_vpwr_access_limiter_0_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_VP_WR_0_vpwr_access_limiter_0_0_END (3)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_VP_WR_0_vpwr_access_limiter_1_0_START (4)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_VP_WR_0_vpwr_access_limiter_1_0_END (7)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_VP_WR_0_vpwr_access_limiter_2_0_START (8)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_VP_WR_0_vpwr_access_limiter_2_0_END (11)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_VP_WR_0_vpwr_access_limiter_3_0_START (12)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_VP_WR_0_vpwr_access_limiter_3_0_END (15)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_VP_WR_0_vpwr_access_limiter_reload_0_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_VP_WR_0_vpwr_access_limiter_reload_0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int nr_wr_stop_enable_du_threshold_reached_0 : 1;
        unsigned int nr_wr_stop_enable_flux_ctrl_0 : 1;
        unsigned int nr_wr_stop_enable_pressure_0 : 1;
        unsigned int reserved_1 : 5;
        unsigned int nr_wr_stop_ok_0 : 1;
        unsigned int nr_wr_stop_0 : 1;
        unsigned int reserved_2 : 5;
        unsigned int nrwr_enable_0 : 1;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_nr_wr_stop_enable_du_threshold_reached_0_START (16)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_nr_wr_stop_enable_du_threshold_reached_0_END (16)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_nr_wr_stop_enable_flux_ctrl_0_START (17)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_nr_wr_stop_enable_flux_ctrl_0_END (17)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_nr_wr_stop_enable_pressure_0_START (18)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_nr_wr_stop_enable_pressure_0_END (18)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_nr_wr_stop_ok_0_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_nr_wr_stop_ok_0_END (24)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_nr_wr_stop_0_START (25)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_nr_wr_stop_0_END (25)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_nrwr_enable_0_START (31)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_0_nrwr_enable_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_wr_debug_0 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_NR_WR_DEBUG_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_DEBUG_0_nr_wr_debug_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_DEBUG_0_nr_wr_debug_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nrwr_access_limiter_0_0 : 4;
        unsigned int nrwr_access_limiter_1_0 : 4;
        unsigned int nrwr_access_limiter_2_0 : 4;
        unsigned int nrwr_access_limiter_3_0 : 4;
        unsigned int reserved_0 : 8;
        unsigned int nrwr_access_limiter_reload_0 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_0_nrwr_access_limiter_0_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_0_nrwr_access_limiter_0_0_END (3)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_0_nrwr_access_limiter_1_0_START (4)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_0_nrwr_access_limiter_1_0_END (7)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_0_nrwr_access_limiter_2_0_START (8)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_0_nrwr_access_limiter_2_0_END (11)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_0_nrwr_access_limiter_3_0_START (12)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_0_nrwr_access_limiter_3_0_END (15)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_0_nrwr_access_limiter_reload_0_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_0_nrwr_access_limiter_reload_0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int nr_wr_stop_enable_du_threshold_reached_1 : 1;
        unsigned int nr_wr_stop_enable_flux_ctrl_1 : 1;
        unsigned int nr_wr_stop_enable_pressure_1 : 1;
        unsigned int reserved_1 : 5;
        unsigned int nr_wr_stop_ok_1 : 1;
        unsigned int nr_wr_stop_1 : 1;
        unsigned int reserved_2 : 5;
        unsigned int nrwr_enable_1 : 1;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_nr_wr_stop_enable_du_threshold_reached_1_START (16)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_nr_wr_stop_enable_du_threshold_reached_1_END (16)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_nr_wr_stop_enable_flux_ctrl_1_START (17)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_nr_wr_stop_enable_flux_ctrl_1_END (17)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_nr_wr_stop_enable_pressure_1_START (18)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_nr_wr_stop_enable_pressure_1_END (18)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_nr_wr_stop_ok_1_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_nr_wr_stop_ok_1_END (24)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_nr_wr_stop_1_START (25)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_nr_wr_stop_1_END (25)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_nrwr_enable_1_START (31)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_CFG_1_nrwr_enable_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_wr_debug_1 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_NR_WR_DEBUG_1_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_DEBUG_1_nr_wr_debug_1_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_NR_WR_DEBUG_1_nr_wr_debug_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nrwr_access_limiter_0_1 : 4;
        unsigned int nrwr_access_limiter_1_1 : 4;
        unsigned int nrwr_access_limiter_2_1 : 4;
        unsigned int nrwr_access_limiter_3_1 : 4;
        unsigned int reserved_0 : 8;
        unsigned int nrwr_access_limiter_reload_1 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_1_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_1_nrwr_access_limiter_0_1_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_1_nrwr_access_limiter_0_1_END (3)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_1_nrwr_access_limiter_1_1_START (4)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_1_nrwr_access_limiter_1_1_END (7)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_1_nrwr_access_limiter_2_1_START (8)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_1_nrwr_access_limiter_2_1_END (11)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_1_nrwr_access_limiter_3_1_START (12)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_1_nrwr_access_limiter_3_1_END (15)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_1_nrwr_access_limiter_reload_1_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_WR_1_nrwr_access_limiter_reload_1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int nrrd_allocated_du_0 : 5;
        unsigned int reserved_1 : 6;
        unsigned int nr_rd_stop_enable_du_threshold_reached_0 : 1;
        unsigned int nr_rd_stop_enable_flux_ctrl_0 : 1;
        unsigned int nr_rd_stop_enable_pressure_0 : 1;
        unsigned int reserved_2 : 5;
        unsigned int nr_rd_stop_ok_0 : 1;
        unsigned int nr_rd_stop_0 : 1;
        unsigned int reserved_3 : 5;
        unsigned int nrrd_enable_0 : 1;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nrrd_allocated_du_0_START (5)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nrrd_allocated_du_0_END (9)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nr_rd_stop_enable_du_threshold_reached_0_START (16)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nr_rd_stop_enable_du_threshold_reached_0_END (16)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nr_rd_stop_enable_flux_ctrl_0_START (17)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nr_rd_stop_enable_flux_ctrl_0_END (17)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nr_rd_stop_enable_pressure_0_START (18)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nr_rd_stop_enable_pressure_0_END (18)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nr_rd_stop_ok_0_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nr_rd_stop_ok_0_END (24)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nr_rd_stop_0_START (25)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nr_rd_stop_0_END (25)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nrrd_enable_0_START (31)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_0_nrrd_enable_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_rd_debug_0 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_NR_RD_DEBUG_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_DEBUG_0_nr_rd_debug_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_DEBUG_0_nr_rd_debug_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nrrd_access_limiter_0_0 : 4;
        unsigned int nrrd_access_limiter_1_0 : 4;
        unsigned int nrrd_access_limiter_2_0 : 4;
        unsigned int nrrd_access_limiter_3_0 : 4;
        unsigned int reserved_0 : 8;
        unsigned int nrrd_access_limiter_reload_0 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_0_nrrd_access_limiter_0_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_0_nrrd_access_limiter_0_0_END (3)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_0_nrrd_access_limiter_1_0_START (4)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_0_nrrd_access_limiter_1_0_END (7)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_0_nrrd_access_limiter_2_0_START (8)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_0_nrrd_access_limiter_2_0_END (11)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_0_nrrd_access_limiter_3_0_START (12)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_0_nrrd_access_limiter_3_0_END (15)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_0_nrrd_access_limiter_reload_0_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_0_nrrd_access_limiter_reload_0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int nrrd_allocated_du_1 : 5;
        unsigned int reserved_1 : 6;
        unsigned int nr_rd_stop_enable_du_threshold_reached_1 : 1;
        unsigned int nr_rd_stop_enable_flux_ctrl_1 : 1;
        unsigned int nr_rd_stop_enable_pressure_1 : 1;
        unsigned int reserved_2 : 5;
        unsigned int nr_rd_stop_ok_1 : 1;
        unsigned int nr_rd_stop_1 : 1;
        unsigned int reserved_3 : 5;
        unsigned int nrrd_enable_1 : 1;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nrrd_allocated_du_1_START (5)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nrrd_allocated_du_1_END (9)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nr_rd_stop_enable_du_threshold_reached_1_START (16)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nr_rd_stop_enable_du_threshold_reached_1_END (16)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nr_rd_stop_enable_flux_ctrl_1_START (17)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nr_rd_stop_enable_flux_ctrl_1_END (17)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nr_rd_stop_enable_pressure_1_START (18)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nr_rd_stop_enable_pressure_1_END (18)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nr_rd_stop_ok_1_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nr_rd_stop_ok_1_END (24)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nr_rd_stop_1_START (25)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nr_rd_stop_1_END (25)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nrrd_enable_1_START (31)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_1_nrrd_enable_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_rd_debug_1 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_NR_RD_DEBUG_1_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_DEBUG_1_nr_rd_debug_1_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_DEBUG_1_nr_rd_debug_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nrrd_access_limiter_0_1 : 4;
        unsigned int nrrd_access_limiter_1_1 : 4;
        unsigned int nrrd_access_limiter_2_1 : 4;
        unsigned int nrrd_access_limiter_3_1 : 4;
        unsigned int reserved_0 : 8;
        unsigned int nrrd_access_limiter_reload_1 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_1_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_1_nrrd_access_limiter_0_1_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_1_nrrd_access_limiter_0_1_END (3)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_1_nrrd_access_limiter_1_1_START (4)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_1_nrrd_access_limiter_1_1_END (7)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_1_nrrd_access_limiter_2_1_START (8)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_1_nrrd_access_limiter_2_1_END (11)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_1_nrrd_access_limiter_3_1_START (12)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_1_nrrd_access_limiter_3_1_END (15)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_1_nrrd_access_limiter_reload_1_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_1_nrrd_access_limiter_reload_1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int nrrd_allocated_du_2 : 5;
        unsigned int reserved_1 : 6;
        unsigned int nr_rd_stop_enable_du_threshold_reached_2 : 1;
        unsigned int nr_rd_stop_enable_flux_ctrl_2 : 1;
        unsigned int nr_rd_stop_enable_pressure_2 : 1;
        unsigned int reserved_2 : 5;
        unsigned int nr_rd_stop_ok_2 : 1;
        unsigned int nr_rd_stop_2 : 1;
        unsigned int reserved_3 : 5;
        unsigned int nrrd_enable_2 : 1;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nrrd_allocated_du_2_START (5)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nrrd_allocated_du_2_END (9)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nr_rd_stop_enable_du_threshold_reached_2_START (16)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nr_rd_stop_enable_du_threshold_reached_2_END (16)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nr_rd_stop_enable_flux_ctrl_2_START (17)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nr_rd_stop_enable_flux_ctrl_2_END (17)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nr_rd_stop_enable_pressure_2_START (18)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nr_rd_stop_enable_pressure_2_END (18)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nr_rd_stop_ok_2_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nr_rd_stop_ok_2_END (24)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nr_rd_stop_2_START (25)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nr_rd_stop_2_END (25)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nrrd_enable_2_START (31)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_CFG_2_nrrd_enable_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_rd_debug_2 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_NR_RD_DEBUG_2_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_DEBUG_2_nr_rd_debug_2_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_NR_RD_DEBUG_2_nr_rd_debug_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nrrd_access_limiter_0_2 : 4;
        unsigned int nrrd_access_limiter_1_2 : 4;
        unsigned int nrrd_access_limiter_2_2 : 4;
        unsigned int nrrd_access_limiter_3_2 : 4;
        unsigned int reserved_0 : 8;
        unsigned int nrrd_access_limiter_reload_2 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_2_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_2_nrrd_access_limiter_0_2_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_2_nrrd_access_limiter_0_2_END (3)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_2_nrrd_access_limiter_1_2_START (4)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_2_nrrd_access_limiter_1_2_END (7)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_2_nrrd_access_limiter_2_2_START (8)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_2_nrrd_access_limiter_2_2_END (11)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_2_nrrd_access_limiter_3_2_START (12)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_2_nrrd_access_limiter_3_2_END (15)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_2_nrrd_access_limiter_reload_2_START (24)
#define SOC_JPG_CVDR_AXI_JPEG_LIMITER_NR_RD_2_nrrd_access_limiter_reload_2_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_0 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_0_debug_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_0_debug_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_1 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_1_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_1_debug_1_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_1_debug_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_2 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_2_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_2_debug_2_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_2_debug_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_3 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_3_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_3_debug_3_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_3_debug_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_4 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_4_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_4_debug_4_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_4_debug_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_5 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_5_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_5_debug_5_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_5_debug_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_6 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_6_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_6_debug_6_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_6_debug_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_7 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_7_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_7_debug_7_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_7_debug_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_8 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_8_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_8_debug_8_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_8_debug_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_9 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_9_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_9_debug_9_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_9_debug_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_10 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_10_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_10_debug_10_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_10_debug_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_11 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_11_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_11_debug_11_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_11_debug_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_12 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_12_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_12_debug_12_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_12_debug_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_13 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_13_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_13_debug_13_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_13_debug_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_14 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_14_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_14_debug_14_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_14_debug_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_15 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_DEBUG_15_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_15_debug_15_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_DEBUG_15_debug_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_wr_mid_0 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_WR_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_WR_0_nr_wr_mid_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_WR_0_nr_wr_mid_0_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_wr_mid_1 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_WR_1_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_WR_1_nr_wr_mid_1_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_WR_1_nr_wr_mid_1_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_rd_mid_0 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_RD_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_RD_0_nr_rd_mid_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_RD_0_nr_rd_mid_0_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_rd_mid_1 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_RD_1_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_RD_1_nr_rd_mid_1_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_RD_1_nr_rd_mid_1_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_rd_mid_2 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_RD_2_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_RD_2_nr_rd_mid_2_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_NR_RD_2_nr_rd_mid_2_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_0 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_VP_WR_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_VP_WR_0_vp_wr_mid_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_AXI_CFG_VP_WR_0_vp_wr_mid_0_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spare_0 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_SPARE_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_SPARE_0_spare_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_SPARE_0_spare_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spare_1 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_SPARE_1_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_SPARE_1_spare_1_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_SPARE_1_spare_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spare_2 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_SPARE_2_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_SPARE_2_spare_2_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_SPARE_2_spare_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spare_3 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_SPARE_3_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_SPARE_3_spare_3_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_SPARE_3_spare_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_0 : 32;
    } reg;
} SOC_JPG_CVDR_AXI_JPEG_VP_WR_DEBUG_0_UNION;
#endif
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_DEBUG_0_vp_wr_debug_0_START (0)
#define SOC_JPG_CVDR_AXI_JPEG_VP_WR_DEBUG_0_vp_wr_debug_0_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

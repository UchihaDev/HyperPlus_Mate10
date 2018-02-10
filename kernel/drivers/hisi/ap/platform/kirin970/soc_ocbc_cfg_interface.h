#ifndef __SOC_OCBC_CFG_INTERFACE_H__
#define __SOC_OCBC_CFG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_OCBC_CFG_CG_SET_ADDR(base) ((base) + (0x0000))
#define SOC_OCBC_CFG_CG_CLR_ADDR(base) ((base) + (0x0004))
#define SOC_OCBC_CFG_CG_STATUS_ADDR(base) ((base) + (0x0008))
#define SOC_OCBC_CFG_RST_SET_ADDR(base) ((base) + (0x0010))
#define SOC_OCBC_CFG_RST_CLR_ADDR(base) ((base) + (0x0014))
#define SOC_OCBC_CFG_RST_STATUS_ADDR(base) ((base) + (0x0018))
#define SOC_OCBC_CFG_SECURE_SET_ADDR(base) ((base) + (0x0020))
#define SOC_OCBC_CFG_SECURE_CLR_ADDR(base) ((base) + (0x0024))
#define SOC_OCBC_CFG_SECURE_STA_ADDR(base) ((base) + (0x0028))
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_ADDR(base) ((base) + (0x0030))
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_ADDR(base) ((base) + (0x0034))
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_ADDR(base) ((base) + (0x0038))
#define SOC_OCBC_CFG_DLOCK_BYPASS_ADDR(base) ((base) + (0x0040))
#define SOC_OCBC_CFG_MEM_CTRL_ADDR(base) ((base) + (0x0044))
#define SOC_OCBC_CFG_MEM_DELSEL_ADDR(base) ((base) + (0x0048))
#define SOC_OCBC_CFG_EXT_INTR_MASK_ADDR(base) ((base) + (0x004C))
#define SOC_OCBC_CFG_INTER_INTR_SET_ADDR(base) ((base) + (0x0050))
#define SOC_OCBC_CFG_INTER_INTR_CLR_ADDR(base) ((base) + (0x0054))
#define SOC_OCBC_CFG_INTER_INTR_STA_ADDR(base) ((base) + (0x0058))
#define SOC_OCBC_CFG_MD_IRM_SEL_CTRL_ADDR(base) ((base) + (0x0060))
#define SOC_OCBC_CFG_MD_PWR_CTRL_ADDR(base) ((base) + (0x0064))
#define SOC_OCBC_CFG_MD_IRM_CTRL_0_ADDR(base) ((base) + (0x0070))
#define SOC_OCBC_CFG_MD_IRM_CTRL_1_ADDR(base) ((base) + (0x0074))
#define SOC_OCBC_CFG_MD_IRM_CTRL_2_ADDR(base) ((base) + (0x0078))
#define SOC_OCBC_CFG_MD_IRM_CTRL_3_ADDR(base) ((base) + (0x007C))
#define SOC_OCBC_CFG_M3_CTRL_ADDR(base) ((base) + (0x0080))
#define SOC_OCBC_CFG_M3_ACCESS_WIN_ADDR(base) ((base) + (0x0088))
#define SOC_OCBC_CFG_M3_RST_FLAG_ADDR(base) ((base) + (0x008C))
#define SOC_OCBC_CFG_M3_RST_SET_ADDR(base) ((base) + (0x0090))
#define SOC_OCBC_CFG_M3_RST_CLR_ADDR(base) ((base) + (0x0094))
#define SOC_OCBC_CFG_M3_RST_STA_ADDR(base) ((base) + (0x0098))
#define SOC_OCBC_CFG_TXEV_EXT_ADDR_ADDR(base) ((base) + (0x00A0))
#define SOC_OCBC_CFG_MONITOR_CTRL_ADDR_ADDR(base) ((base) + (0x00A8))
#define SOC_OCBC_CFG_PE_INTR_MASK_ADDR(base) ((base) + (0x00B0))
#define SOC_OCBC_CFG_WAKEUP_MASK_ADDR(base) ((base) + (0x00C0))
#define SOC_OCBC_CFG_SYS_WAKEUP_ADDR(base) ((base) + (0x00C4))
#define SOC_OCBC_CFG_INT_STATUS_ADDR(base) ((base) + (0x00C8))
#define SOC_OCBC_CFG_BACKUP_REG_ADDR(base) ((base) + (0x00CC))
#define SOC_OCBC_CFG_AO_FLL_REQ_ADDR(base) ((base) + (0x00D0))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_clk_on : 1;
        unsigned int reserved_0 : 1;
        unsigned int wdg_clk_on : 1;
        unsigned int timer_clk_on : 1;
        unsigned int mbox_clk_on : 4;
        unsigned int dapclk_on : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_OCBC_CFG_CG_SET_UNION;
#endif
#define SOC_OCBC_CFG_CG_SET_ram_clk_on_START (0)
#define SOC_OCBC_CFG_CG_SET_ram_clk_on_END (0)
#define SOC_OCBC_CFG_CG_SET_wdg_clk_on_START (2)
#define SOC_OCBC_CFG_CG_SET_wdg_clk_on_END (2)
#define SOC_OCBC_CFG_CG_SET_timer_clk_on_START (3)
#define SOC_OCBC_CFG_CG_SET_timer_clk_on_END (3)
#define SOC_OCBC_CFG_CG_SET_mbox_clk_on_START (4)
#define SOC_OCBC_CFG_CG_SET_mbox_clk_on_END (7)
#define SOC_OCBC_CFG_CG_SET_dapclk_on_START (8)
#define SOC_OCBC_CFG_CG_SET_dapclk_on_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_clk_on : 1;
        unsigned int reserved_0 : 1;
        unsigned int wdg_clk_on : 1;
        unsigned int timer_clk_on : 1;
        unsigned int mbox_clk_on : 4;
        unsigned int dapclk_on : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_OCBC_CFG_CG_CLR_UNION;
#endif
#define SOC_OCBC_CFG_CG_CLR_ram_clk_on_START (0)
#define SOC_OCBC_CFG_CG_CLR_ram_clk_on_END (0)
#define SOC_OCBC_CFG_CG_CLR_wdg_clk_on_START (2)
#define SOC_OCBC_CFG_CG_CLR_wdg_clk_on_END (2)
#define SOC_OCBC_CFG_CG_CLR_timer_clk_on_START (3)
#define SOC_OCBC_CFG_CG_CLR_timer_clk_on_END (3)
#define SOC_OCBC_CFG_CG_CLR_mbox_clk_on_START (4)
#define SOC_OCBC_CFG_CG_CLR_mbox_clk_on_END (7)
#define SOC_OCBC_CFG_CG_CLR_dapclk_on_START (8)
#define SOC_OCBC_CFG_CG_CLR_dapclk_on_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_clk_on : 1;
        unsigned int reserved_0 : 1;
        unsigned int wdg_clk_on : 1;
        unsigned int timer_clk_on : 1;
        unsigned int mbox_clk_on : 4;
        unsigned int dapclk_on : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_OCBC_CFG_CG_STATUS_UNION;
#endif
#define SOC_OCBC_CFG_CG_STATUS_ram_clk_on_START (0)
#define SOC_OCBC_CFG_CG_STATUS_ram_clk_on_END (0)
#define SOC_OCBC_CFG_CG_STATUS_wdg_clk_on_START (2)
#define SOC_OCBC_CFG_CG_STATUS_wdg_clk_on_END (2)
#define SOC_OCBC_CFG_CG_STATUS_timer_clk_on_START (3)
#define SOC_OCBC_CFG_CG_STATUS_timer_clk_on_END (3)
#define SOC_OCBC_CFG_CG_STATUS_mbox_clk_on_START (4)
#define SOC_OCBC_CFG_CG_STATUS_mbox_clk_on_END (7)
#define SOC_OCBC_CFG_CG_STATUS_dapclk_on_START (8)
#define SOC_OCBC_CFG_CG_STATUS_dapclk_on_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_rst_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int wdg_rst_req : 1;
        unsigned int timer_rst_req : 1;
        unsigned int mbox_rst_req : 4;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_OCBC_CFG_RST_SET_UNION;
#endif
#define SOC_OCBC_CFG_RST_SET_ram_rst_req_START (0)
#define SOC_OCBC_CFG_RST_SET_ram_rst_req_END (0)
#define SOC_OCBC_CFG_RST_SET_wdg_rst_req_START (2)
#define SOC_OCBC_CFG_RST_SET_wdg_rst_req_END (2)
#define SOC_OCBC_CFG_RST_SET_timer_rst_req_START (3)
#define SOC_OCBC_CFG_RST_SET_timer_rst_req_END (3)
#define SOC_OCBC_CFG_RST_SET_mbox_rst_req_START (4)
#define SOC_OCBC_CFG_RST_SET_mbox_rst_req_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_rst_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int wdg_rst_req : 1;
        unsigned int timer_rst_req : 1;
        unsigned int mbox_rst_req : 4;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_OCBC_CFG_RST_CLR_UNION;
#endif
#define SOC_OCBC_CFG_RST_CLR_ram_rst_req_START (0)
#define SOC_OCBC_CFG_RST_CLR_ram_rst_req_END (0)
#define SOC_OCBC_CFG_RST_CLR_wdg_rst_req_START (2)
#define SOC_OCBC_CFG_RST_CLR_wdg_rst_req_END (2)
#define SOC_OCBC_CFG_RST_CLR_timer_rst_req_START (3)
#define SOC_OCBC_CFG_RST_CLR_timer_rst_req_END (3)
#define SOC_OCBC_CFG_RST_CLR_mbox_rst_req_START (4)
#define SOC_OCBC_CFG_RST_CLR_mbox_rst_req_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_rst_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int wdg_rst_req : 1;
        unsigned int timer_rst_req : 1;
        unsigned int mbox_rst_req : 4;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_OCBC_CFG_RST_STATUS_UNION;
#endif
#define SOC_OCBC_CFG_RST_STATUS_ram_rst_req_START (0)
#define SOC_OCBC_CFG_RST_STATUS_ram_rst_req_END (0)
#define SOC_OCBC_CFG_RST_STATUS_wdg_rst_req_START (2)
#define SOC_OCBC_CFG_RST_STATUS_wdg_rst_req_END (2)
#define SOC_OCBC_CFG_RST_STATUS_timer_rst_req_START (3)
#define SOC_OCBC_CFG_RST_STATUS_timer_rst_req_END (3)
#define SOC_OCBC_CFG_RST_STATUS_mbox_rst_req_START (4)
#define SOC_OCBC_CFG_RST_STATUS_mbox_rst_req_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_sec_n : 1;
        unsigned int cfg_sec_n : 1;
        unsigned int wdg_sec_n : 1;
        unsigned int timer_sec_n : 1;
        unsigned int mbox_sec_n : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_OCBC_CFG_SECURE_SET_UNION;
#endif
#define SOC_OCBC_CFG_SECURE_SET_ram_sec_n_START (0)
#define SOC_OCBC_CFG_SECURE_SET_ram_sec_n_END (0)
#define SOC_OCBC_CFG_SECURE_SET_cfg_sec_n_START (1)
#define SOC_OCBC_CFG_SECURE_SET_cfg_sec_n_END (1)
#define SOC_OCBC_CFG_SECURE_SET_wdg_sec_n_START (2)
#define SOC_OCBC_CFG_SECURE_SET_wdg_sec_n_END (2)
#define SOC_OCBC_CFG_SECURE_SET_timer_sec_n_START (3)
#define SOC_OCBC_CFG_SECURE_SET_timer_sec_n_END (3)
#define SOC_OCBC_CFG_SECURE_SET_mbox_sec_n_START (4)
#define SOC_OCBC_CFG_SECURE_SET_mbox_sec_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_sec_n : 1;
        unsigned int cfg_sec_n : 1;
        unsigned int wdg_sec_n : 1;
        unsigned int timer_sec_n : 1;
        unsigned int mbox_sec_n : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_OCBC_CFG_SECURE_CLR_UNION;
#endif
#define SOC_OCBC_CFG_SECURE_CLR_ram_sec_n_START (0)
#define SOC_OCBC_CFG_SECURE_CLR_ram_sec_n_END (0)
#define SOC_OCBC_CFG_SECURE_CLR_cfg_sec_n_START (1)
#define SOC_OCBC_CFG_SECURE_CLR_cfg_sec_n_END (1)
#define SOC_OCBC_CFG_SECURE_CLR_wdg_sec_n_START (2)
#define SOC_OCBC_CFG_SECURE_CLR_wdg_sec_n_END (2)
#define SOC_OCBC_CFG_SECURE_CLR_timer_sec_n_START (3)
#define SOC_OCBC_CFG_SECURE_CLR_timer_sec_n_END (3)
#define SOC_OCBC_CFG_SECURE_CLR_mbox_sec_n_START (4)
#define SOC_OCBC_CFG_SECURE_CLR_mbox_sec_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_sec_n : 1;
        unsigned int cfg_sec_n : 1;
        unsigned int wdg_sec_n : 1;
        unsigned int timer_sec_n : 1;
        unsigned int mbox_sec_n : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_OCBC_CFG_SECURE_STA_UNION;
#endif
#define SOC_OCBC_CFG_SECURE_STA_ram_sec_n_START (0)
#define SOC_OCBC_CFG_SECURE_STA_ram_sec_n_END (0)
#define SOC_OCBC_CFG_SECURE_STA_cfg_sec_n_START (1)
#define SOC_OCBC_CFG_SECURE_STA_cfg_sec_n_END (1)
#define SOC_OCBC_CFG_SECURE_STA_wdg_sec_n_START (2)
#define SOC_OCBC_CFG_SECURE_STA_wdg_sec_n_END (2)
#define SOC_OCBC_CFG_SECURE_STA_timer_sec_n_START (3)
#define SOC_OCBC_CFG_SECURE_STA_timer_sec_n_END (3)
#define SOC_OCBC_CFG_SECURE_STA_mbox_sec_n_START (4)
#define SOC_OCBC_CFG_SECURE_STA_mbox_sec_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_hclk_dcm_off : 1;
        unsigned int cfg_pclk_dcm_off : 1;
        unsigned int wdg_pclk_dcm_off : 1;
        unsigned int timer_pclk_dcm_off : 1;
        unsigned int mbox_pclk_dcm_off : 4;
        unsigned int peri_hclk_dcm_off : 1;
        unsigned int bus_hclk_dcm_off : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_OCBC_CFG_PCLK_DCMOFF_SET_UNION;
#endif
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_ram_hclk_dcm_off_START (0)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_ram_hclk_dcm_off_END (0)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_cfg_pclk_dcm_off_START (1)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_cfg_pclk_dcm_off_END (1)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_wdg_pclk_dcm_off_START (2)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_wdg_pclk_dcm_off_END (2)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_timer_pclk_dcm_off_START (3)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_timer_pclk_dcm_off_END (3)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_mbox_pclk_dcm_off_START (4)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_mbox_pclk_dcm_off_END (7)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_peri_hclk_dcm_off_START (8)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_peri_hclk_dcm_off_END (8)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_bus_hclk_dcm_off_START (9)
#define SOC_OCBC_CFG_PCLK_DCMOFF_SET_bus_hclk_dcm_off_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_hclk_dcm_off : 1;
        unsigned int cfg_pclk_dcm_off : 1;
        unsigned int wdg_pclk_dcm_off : 1;
        unsigned int timer_pclk_dcm_off : 1;
        unsigned int mbox_pclk_dcm_off : 4;
        unsigned int peri_hclk_dcm_off : 1;
        unsigned int bus_hclk_dcm_off : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_OCBC_CFG_PCLK_DCMOFF_CLR_UNION;
#endif
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_ram_hclk_dcm_off_START (0)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_ram_hclk_dcm_off_END (0)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_cfg_pclk_dcm_off_START (1)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_cfg_pclk_dcm_off_END (1)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_wdg_pclk_dcm_off_START (2)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_wdg_pclk_dcm_off_END (2)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_timer_pclk_dcm_off_START (3)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_timer_pclk_dcm_off_END (3)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_mbox_pclk_dcm_off_START (4)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_mbox_pclk_dcm_off_END (7)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_peri_hclk_dcm_off_START (8)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_peri_hclk_dcm_off_END (8)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_bus_hclk_dcm_off_START (9)
#define SOC_OCBC_CFG_PCLK_DCMOFF_CLR_bus_hclk_dcm_off_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_hclk_dcm_off : 1;
        unsigned int cfg_pclk_dcm_off : 1;
        unsigned int wdg_pclk_dcm_off : 1;
        unsigned int timer_pclk_dcm_off : 1;
        unsigned int mbox_pclk_dcm_off : 4;
        unsigned int peri_hclk_dcm_off : 1;
        unsigned int bus_hclk_dcm_off : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_OCBC_CFG_PCLK_DCMOFF_STA_UNION;
#endif
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_ram_hclk_dcm_off_START (0)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_ram_hclk_dcm_off_END (0)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_cfg_pclk_dcm_off_START (1)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_cfg_pclk_dcm_off_END (1)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_wdg_pclk_dcm_off_START (2)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_wdg_pclk_dcm_off_END (2)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_timer_pclk_dcm_off_START (3)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_timer_pclk_dcm_off_END (3)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_mbox_pclk_dcm_off_START (4)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_mbox_pclk_dcm_off_END (7)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_peri_hclk_dcm_off_START (8)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_peri_hclk_dcm_off_END (8)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_bus_hclk_dcm_off_START (9)
#define SOC_OCBC_CFG_PCLK_DCMOFF_STA_bus_hclk_dcm_off_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dlock_bypass_ram : 1;
        unsigned int reserved_0 : 15;
        unsigned int dlock_avoid : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_OCBC_CFG_DLOCK_BYPASS_UNION;
#endif
#define SOC_OCBC_CFG_DLOCK_BYPASS_dlock_bypass_ram_START (0)
#define SOC_OCBC_CFG_DLOCK_BYPASS_dlock_bypass_ram_END (0)
#define SOC_OCBC_CFG_DLOCK_BYPASS_dlock_avoid_START (16)
#define SOC_OCBC_CFG_DLOCK_BYPASS_dlock_avoid_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spsram_slp : 1;
        unsigned int spsram_dslp : 1;
        unsigned int spsram_sd : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_OCBC_CFG_MEM_CTRL_UNION;
#endif
#define SOC_OCBC_CFG_MEM_CTRL_spsram_slp_START (0)
#define SOC_OCBC_CFG_MEM_CTRL_spsram_slp_END (0)
#define SOC_OCBC_CFG_MEM_CTRL_spsram_dslp_START (1)
#define SOC_OCBC_CFG_MEM_CTRL_spsram_dslp_END (1)
#define SOC_OCBC_CFG_MEM_CTRL_spsram_sd_START (2)
#define SOC_OCBC_CFG_MEM_CTRL_spsram_sd_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_wtsel : 2;
        unsigned int mem_rtsel : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_OCBC_CFG_MEM_DELSEL_UNION;
#endif
#define SOC_OCBC_CFG_MEM_DELSEL_mem_wtsel_START (0)
#define SOC_OCBC_CFG_MEM_DELSEL_mem_wtsel_END (1)
#define SOC_OCBC_CFG_MEM_DELSEL_mem_rtsel_START (2)
#define SOC_OCBC_CFG_MEM_DELSEL_mem_rtsel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ext_intr_mask : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_OCBC_CFG_EXT_INTR_MASK_UNION;
#endif
#define SOC_OCBC_CFG_EXT_INTR_MASK_ext_intr_mask_START (0)
#define SOC_OCBC_CFG_EXT_INTR_MASK_ext_intr_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inter_int : 32;
    } reg;
} SOC_OCBC_CFG_INTER_INTR_SET_UNION;
#endif
#define SOC_OCBC_CFG_INTER_INTR_SET_inter_int_START (0)
#define SOC_OCBC_CFG_INTER_INTR_SET_inter_int_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inter_int : 32;
    } reg;
} SOC_OCBC_CFG_INTER_INTR_CLR_UNION;
#endif
#define SOC_OCBC_CFG_INTER_INTR_CLR_inter_int_START (0)
#define SOC_OCBC_CFG_INTER_INTR_CLR_inter_int_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inter_int : 32;
    } reg;
} SOC_OCBC_CFG_INTER_INTR_STA_UNION;
#endif
#define SOC_OCBC_CFG_INTER_INTR_STA_inter_int_START (0)
#define SOC_OCBC_CFG_INTER_INTR_STA_inter_int_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_OCBC_CFG_MD_IRM_SEL_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_OCBC_CFG_MD_PWR_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_OCBC_CFG_MD_IRM_CTRL_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_OCBC_CFG_MD_IRM_CTRL_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_OCBC_CFG_MD_IRM_CTRL_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_OCBC_CFG_MD_IRM_CTRL_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sysresetreq_en : 1;
        unsigned int halt_bypass : 1;
        unsigned int timclken_bypass : 1;
        unsigned int testpin_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_OCBC_CFG_M3_CTRL_UNION;
#endif
#define SOC_OCBC_CFG_M3_CTRL_sysresetreq_en_START (0)
#define SOC_OCBC_CFG_M3_CTRL_sysresetreq_en_END (0)
#define SOC_OCBC_CFG_M3_CTRL_halt_bypass_START (1)
#define SOC_OCBC_CFG_M3_CTRL_halt_bypass_END (1)
#define SOC_OCBC_CFG_M3_CTRL_timclken_bypass_START (2)
#define SOC_OCBC_CFG_M3_CTRL_timclken_bypass_END (2)
#define SOC_OCBC_CFG_M3_CTRL_testpin_en_START (3)
#define SOC_OCBC_CFG_M3_CTRL_testpin_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 28;
        unsigned int access_win : 4;
    } reg;
} SOC_OCBC_CFG_M3_ACCESS_WIN_UNION;
#endif
#define SOC_OCBC_CFG_M3_ACCESS_WIN_access_win_START (28)
#define SOC_OCBC_CFG_M3_ACCESS_WIN_access_win_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sysresetreq_flag : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OCBC_CFG_M3_RST_FLAG_UNION;
#endif
#define SOC_OCBC_CFG_M3_RST_FLAG_sysresetreq_flag_START (0)
#define SOC_OCBC_CFG_M3_RST_FLAG_sysresetreq_flag_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int poreset : 1;
        unsigned int sysreset : 1;
        unsigned int coresight : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_OCBC_CFG_M3_RST_SET_UNION;
#endif
#define SOC_OCBC_CFG_M3_RST_SET_poreset_START (0)
#define SOC_OCBC_CFG_M3_RST_SET_poreset_END (0)
#define SOC_OCBC_CFG_M3_RST_SET_sysreset_START (1)
#define SOC_OCBC_CFG_M3_RST_SET_sysreset_END (1)
#define SOC_OCBC_CFG_M3_RST_SET_coresight_START (2)
#define SOC_OCBC_CFG_M3_RST_SET_coresight_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int poreset : 1;
        unsigned int sysreset : 1;
        unsigned int coresight : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_OCBC_CFG_M3_RST_CLR_UNION;
#endif
#define SOC_OCBC_CFG_M3_RST_CLR_poreset_START (0)
#define SOC_OCBC_CFG_M3_RST_CLR_poreset_END (0)
#define SOC_OCBC_CFG_M3_RST_CLR_sysreset_START (1)
#define SOC_OCBC_CFG_M3_RST_CLR_sysreset_END (1)
#define SOC_OCBC_CFG_M3_RST_CLR_coresight_START (2)
#define SOC_OCBC_CFG_M3_RST_CLR_coresight_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int poreset : 1;
        unsigned int sysreset : 1;
        unsigned int coresight : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_OCBC_CFG_M3_RST_STA_UNION;
#endif
#define SOC_OCBC_CFG_M3_RST_STA_poreset_START (0)
#define SOC_OCBC_CFG_M3_RST_STA_poreset_END (0)
#define SOC_OCBC_CFG_M3_RST_STA_sysreset_START (1)
#define SOC_OCBC_CFG_M3_RST_STA_sysreset_END (1)
#define SOC_OCBC_CFG_M3_RST_STA_coresight_START (2)
#define SOC_OCBC_CFG_M3_RST_STA_coresight_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int txev_ext_cycle : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_OCBC_CFG_TXEV_EXT_ADDR_UNION;
#endif
#define SOC_OCBC_CFG_TXEV_EXT_ADDR_txev_ext_cycle_START (0)
#define SOC_OCBC_CFG_TXEV_EXT_ADDR_txev_ext_cycle_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int monitor_sel : 3;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_OCBC_CFG_MONITOR_CTRL_ADDR_UNION;
#endif
#define SOC_OCBC_CFG_MONITOR_CTRL_ADDR_monitor_en_START (0)
#define SOC_OCBC_CFG_MONITOR_CTRL_ADDR_monitor_en_END (0)
#define SOC_OCBC_CFG_MONITOR_CTRL_ADDR_monitor_sel_START (4)
#define SOC_OCBC_CFG_MONITOR_CTRL_ADDR_monitor_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pe_intr_mask : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_OCBC_CFG_PE_INTR_MASK_UNION;
#endif
#define SOC_OCBC_CFG_PE_INTR_MASK_pe_intr_mask_START (0)
#define SOC_OCBC_CFG_PE_INTR_MASK_pe_intr_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wakeup_mask : 3;
        unsigned int reserved_0 : 5;
        unsigned int ao_crg_mask : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_OCBC_CFG_WAKEUP_MASK_UNION;
#endif
#define SOC_OCBC_CFG_WAKEUP_MASK_wakeup_mask_START (0)
#define SOC_OCBC_CFG_WAKEUP_MASK_wakeup_mask_END (2)
#define SOC_OCBC_CFG_WAKEUP_MASK_ao_crg_mask_START (8)
#define SOC_OCBC_CFG_WAKEUP_MASK_ao_crg_mask_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocbc_wakeup_reg : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OCBC_CFG_SYS_WAKEUP_UNION;
#endif
#define SOC_OCBC_CFG_SYS_WAKEUP_ocbc_wakeup_reg_START (0)
#define SOC_OCBC_CFG_SYS_WAKEUP_ocbc_wakeup_reg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mbox_intr : 16;
        unsigned int timint1 : 1;
        unsigned int timint2 : 1;
        unsigned int intr_wdog : 1;
        unsigned int intr_wdog_res : 1;
        unsigned int ocbc_pe_npintr : 4;
        unsigned int ext_intr : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_OCBC_CFG_INT_STATUS_UNION;
#endif
#define SOC_OCBC_CFG_INT_STATUS_mbox_intr_START (0)
#define SOC_OCBC_CFG_INT_STATUS_mbox_intr_END (15)
#define SOC_OCBC_CFG_INT_STATUS_timint1_START (16)
#define SOC_OCBC_CFG_INT_STATUS_timint1_END (16)
#define SOC_OCBC_CFG_INT_STATUS_timint2_START (17)
#define SOC_OCBC_CFG_INT_STATUS_timint2_END (17)
#define SOC_OCBC_CFG_INT_STATUS_intr_wdog_START (18)
#define SOC_OCBC_CFG_INT_STATUS_intr_wdog_END (18)
#define SOC_OCBC_CFG_INT_STATUS_intr_wdog_res_START (19)
#define SOC_OCBC_CFG_INT_STATUS_intr_wdog_res_END (19)
#define SOC_OCBC_CFG_INT_STATUS_ocbc_pe_npintr_START (20)
#define SOC_OCBC_CFG_INT_STATUS_ocbc_pe_npintr_END (23)
#define SOC_OCBC_CFG_INT_STATUS_ext_intr_START (24)
#define SOC_OCBC_CFG_INT_STATUS_ext_intr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int backup_reg : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_OCBC_CFG_BACKUP_REG_UNION;
#endif
#define SOC_OCBC_CFG_BACKUP_REG_backup_reg_START (0)
#define SOC_OCBC_CFG_BACKUP_REG_backup_reg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ao_sclk_fll_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OCBC_CFG_AO_FLL_REQ_UNION;
#endif
#define SOC_OCBC_CFG_AO_FLL_REQ_ao_sclk_fll_req_START (0)
#define SOC_OCBC_CFG_AO_FLL_REQ_ao_sclk_fll_req_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

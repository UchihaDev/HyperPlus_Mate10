#ifndef __SOC_TCP_INTERFACE_H__
#define __SOC_TCP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_TCP_TCPC_CTRL_ADDR(base) ((base) + (0x0))
#define SOC_TCP_TCP_FLUSH_ADDR(base) ((base) + (0x4))
#define SOC_TCP_TCPC_STAT_ADDR(base) ((base) + (0x8))
#define SOC_TCP_PC_STAT_ADDR(base) ((base) + (0xC))
#define SOC_TCP_PC_STACK_0_STAT_ADDR(base) ((base) + (0x10))
#define SOC_TCP_PC_STACK_1_STAT_ADDR(base) ((base) + (0x14))
#define SOC_TCP_PC_STACK_2_STAT_ADDR(base) ((base) + (0x18))
#define SOC_TCP_PC_STACK_3_STAT_ADDR(base) ((base) + (0x1C))
#define SOC_TCP_PC_STACK_4_STAT_ADDR(base) ((base) + (0x20))
#define SOC_TCP_PC_STACK_5_STAT_ADDR(base) ((base) + (0x24))
#define SOC_TCP_SP_STAT_ADDR(base) ((base) + (0x28))
#define SOC_TCP_PAUSE_REQ_ADDR(base) ((base) + (0x2c))
#define SOC_TCP_CLK_CTRL_ADDR(base) ((base) + (0x30))
#define SOC_TCP_AHB_CTRL_ADDR(base) ((base) + (0x34))
#define SOC_TCP_ERR_TCPC_STAT_ADDR(base) ((base) + (0x40))
#define SOC_TCP_ERR_PC_STAT_ADDR(base) ((base) + (0x44))
#define SOC_TCP_ERR_AHB_ADDR_STAT_ADDR(base) ((base) + (0x48))
#define SOC_TCP_ERR_AHB_CTRL_STAT_ADDR(base) ((base) + (0x4C))
#define SOC_TCP_MEM_CTRL0_ADDR(base) ((base) + (0x60))
#define SOC_TCP_MEM_CTRL1_ADDR(base) ((base) + (0x64))
#define SOC_TCP_IRAM_LOCK_ADDR(base) ((base) + (0x70))
#define SOC_TCP_MOVE_MUTEX_CFG_ADDR(base) ((base) + (0x80))
#define SOC_TCP_BASEADDR_ADDR(base) ((base) + (0x84))
#define SOC_TCP_SP_BASEADDR_ADDR(base) ((base) + (0x88))
#define SOC_TCP_INSTR_SIZE_CFG_ADDR(base) ((base) + (0x8C))
#define SOC_TCP_IRQ_STAT_ADDR(base) ((base) + (0xA0))
#define SOC_TCP_IRQ_MASK_ADDR(base) ((base) + (0xA4))
#define SOC_TCP_IRQ_CLR_ADDR(base) ((base) + (0xA8))
#define SOC_TCP_TASK_DONE_IRQ_STAT_ADDR(base) ((base) + (0xAC))
#define SOC_TCP_TASK_DONE_IRQ_MASK_ADDR(base) ((base) + (0xB4))
#define SOC_TCP_TASK_DONE_IRQ_CLR_ADDR(base) ((base) + (0xBC))
#define SOC_TCP_DBG_CTRL_ADDR(base) ((base) + (0xD0))
#define SOC_TCP_DBG_BKP_ADDR(base) ((base) + (0xD4))
#define SOC_TCP_DBG_STEP_ADDR(base) ((base) + (0xD8))
#define SOC_TCP_DBG_CONTINUE_ADDR(base) ((base) + (0xDC))
#define SOC_TCP_WDT_CFG_ADDR(base) ((base) + (0xF0))
#define SOC_TCP_WDT_STAT_ADDR(base) ((base) + (0xF4))
#define SOC_TCP_TASK_START_ADDR_ADDR(base,TN) ((base) + (0x100+(TN)*4))
#define SOC_TCP_EXT_IRQ_TASK_SEL_ADDR(base,EIN) ((base) + (0x200+(EIN)*4))
#define SOC_TCP_EXT_IRQ_EN_ADDR(base) ((base) + (0x300))
#define SOC_TCP_SOFT_REQ_ADDR(base) ((base) + (0x310))
#define SOC_TCP_ERR_TASK_REQ_CFG_ADDR(base) ((base) + (0x320))
#define SOC_TCP_TIM_TASK_REQ_CFG_ADDR(base,TMN) ((base) + (0x400+4*(TMN)))
#define SOC_TCP_TASK_REQ_STAT_ADDR(base) ((base) + (0x500))
#define SOC_TCP_TASK_STAT_ADDR(base) ((base) + (0x510))
#define SOC_TCP_SOFT_IRQ_SET_ADDR(base,SIN) ((base) + (0x600+(SIN)*4))
#define SOC_TCP_SOFT_IRQ_CLR_ADDR(base,SIN) ((base) + (0x640+(SIN)*4))
#define SOC_TCP_SOFT_IRQ_MASK_ADDR(base,SIN) ((base) + (0x680+(SIN)*4))
#define SOC_TCP_SOFT_IRQ_STAT_ADDR(base,SIN) ((base) + (0x6C0+(SIN)*4))
#define SOC_TCP_TCPC_AHB_ADDR_CHN_ADDR(base,CHN) ((base) + (0x700+(CHN)*4))
#define SOC_TCP_TIM_CFG_ADDR(base,TMN) ((base) + (0x800+4*(TMN)))
#define SOC_TCP_TIM_STAT_ADDR(base,TMN) ((base) + (0x880+4*(TMN)))
#define SOC_TCP_GENERAL_REG_ADDR(base,GRN) ((base) + (0x900+4*(GRN)))
#define SOC_TCP_COMMON_REG_ADDR(base,CRN) ((base) + (0xA00+4*(CRN)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TCP_TCPC_CTRL_UNION;
#endif
#define SOC_TCP_TCPC_CTRL_tcp_flush_en_START (0)
#define SOC_TCP_TCPC_CTRL_tcp_flush_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcpc_flush : 1;
        unsigned int task_req_flush : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_TCP_TCP_FLUSH_UNION;
#endif
#define SOC_TCP_TCP_FLUSH_tcpc_flush_START (0)
#define SOC_TCP_TCP_FLUSH_tcpc_flush_END (0)
#define SOC_TCP_TCP_FLUSH_task_req_flush_START (1)
#define SOC_TCP_TCP_FLUSH_task_req_flush_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcpc_stat : 32;
    } reg;
} SOC_TCP_TCPC_STAT_UNION;
#endif
#define SOC_TCP_TCPC_STAT_tcpc_stat_START (0)
#define SOC_TCP_TCPC_STAT_tcpc_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pc_stat : 32;
    } reg;
} SOC_TCP_PC_STAT_UNION;
#endif
#define SOC_TCP_PC_STAT_pc_stat_START (0)
#define SOC_TCP_PC_STAT_pc_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pc_stack0_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_PC_STACK_0_STAT_UNION;
#endif
#define SOC_TCP_PC_STACK_0_STAT_pc_stack0_stat_START (0)
#define SOC_TCP_PC_STACK_0_STAT_pc_stack0_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pc_stack1_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_PC_STACK_1_STAT_UNION;
#endif
#define SOC_TCP_PC_STACK_1_STAT_pc_stack1_stat_START (0)
#define SOC_TCP_PC_STACK_1_STAT_pc_stack1_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pc_stack2_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_PC_STACK_2_STAT_UNION;
#endif
#define SOC_TCP_PC_STACK_2_STAT_pc_stack2_stat_START (0)
#define SOC_TCP_PC_STACK_2_STAT_pc_stack2_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pc_stack3_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_PC_STACK_3_STAT_UNION;
#endif
#define SOC_TCP_PC_STACK_3_STAT_pc_stack3_stat_START (0)
#define SOC_TCP_PC_STACK_3_STAT_pc_stack3_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pc_stack4_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_PC_STACK_4_STAT_UNION;
#endif
#define SOC_TCP_PC_STACK_4_STAT_pc_stack4_stat_START (0)
#define SOC_TCP_PC_STACK_4_STAT_pc_stack4_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pc_stack5_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_PC_STACK_5_STAT_UNION;
#endif
#define SOC_TCP_PC_STACK_5_STAT_pc_stack5_stat_START (0)
#define SOC_TCP_PC_STACK_5_STAT_pc_stack5_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sp_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_SP_STAT_UNION;
#endif
#define SOC_TCP_SP_STAT_sp_stat_START (0)
#define SOC_TCP_SP_STAT_sp_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp_pause_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TCP_PAUSE_REQ_UNION;
#endif
#define SOC_TCP_PAUSE_REQ_tcp_pause_req_START (0)
#define SOC_TCP_PAUSE_REQ_tcp_pause_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp_clk_on : 1;
        unsigned int hw_clk_byp : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_TCP_CLK_CTRL_UNION;
#endif
#define SOC_TCP_CLK_CTRL_tcp_clk_on_START (0)
#define SOC_TCP_CLK_CTRL_tcp_clk_on_END (0)
#define SOC_TCP_CLK_CTRL_hw_clk_byp_START (1)
#define SOC_TCP_CLK_CTRL_hw_clk_byp_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hprot01_ctrl : 4;
        unsigned int hsel_ctrl : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_TCP_AHB_CTRL_UNION;
#endif
#define SOC_TCP_AHB_CTRL_hprot01_ctrl_START (0)
#define SOC_TCP_AHB_CTRL_hprot01_ctrl_END (3)
#define SOC_TCP_AHB_CTRL_hsel_ctrl_START (4)
#define SOC_TCP_AHB_CTRL_hsel_ctrl_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int err_tcpc_stat : 32;
    } reg;
} SOC_TCP_ERR_TCPC_STAT_UNION;
#endif
#define SOC_TCP_ERR_TCPC_STAT_err_tcpc_stat_START (0)
#define SOC_TCP_ERR_TCPC_STAT_err_tcpc_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int err_pc_stat : 32;
    } reg;
} SOC_TCP_ERR_PC_STAT_UNION;
#endif
#define SOC_TCP_ERR_PC_STAT_err_pc_stat_START (0)
#define SOC_TCP_ERR_PC_STAT_err_pc_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int err_haddr_stat : 32;
    } reg;
} SOC_TCP_ERR_AHB_ADDR_STAT_UNION;
#endif
#define SOC_TCP_ERR_AHB_ADDR_STAT_err_haddr_stat_START (0)
#define SOC_TCP_ERR_AHB_ADDR_STAT_err_haddr_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int err_ahb_ctrl_stat : 32;
    } reg;
} SOC_TCP_ERR_AHB_CTRL_STAT_UNION;
#endif
#define SOC_TCP_ERR_AHB_CTRL_STAT_err_ahb_ctrl_stat_START (0)
#define SOC_TCP_ERR_AHB_CTRL_STAT_err_ahb_ctrl_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram0_dslp : 1;
        unsigned int ram0_sd : 1;
        unsigned int reserved_0: 14;
        unsigned int rtsel : 2;
        unsigned int wtsel : 2;
        unsigned int reserved_1: 12;
    } reg;
} SOC_TCP_MEM_CTRL0_UNION;
#endif
#define SOC_TCP_MEM_CTRL0_ram0_dslp_START (0)
#define SOC_TCP_MEM_CTRL0_ram0_dslp_END (0)
#define SOC_TCP_MEM_CTRL0_ram0_sd_START (1)
#define SOC_TCP_MEM_CTRL0_ram0_sd_END (1)
#define SOC_TCP_MEM_CTRL0_rtsel_START (16)
#define SOC_TCP_MEM_CTRL0_rtsel_END (17)
#define SOC_TCP_MEM_CTRL0_wtsel_START (18)
#define SOC_TCP_MEM_CTRL0_wtsel_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram1_dslp : 1;
        unsigned int ram1_sd : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_TCP_MEM_CTRL1_UNION;
#endif
#define SOC_TCP_MEM_CTRL1_ram1_dslp_START (0)
#define SOC_TCP_MEM_CTRL1_ram1_dslp_END (0)
#define SOC_TCP_MEM_CTRL1_ram1_sd_START (1)
#define SOC_TCP_MEM_CTRL1_ram1_sd_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iram_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TCP_IRAM_LOCK_UNION;
#endif
#define SOC_TCP_IRAM_LOCK_iram_lock_START (0)
#define SOC_TCP_IRAM_LOCK_iram_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int en_reg_offset : 8;
        unsigned int dis_reg_offset : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_MOVE_MUTEX_CFG_UNION;
#endif
#define SOC_TCP_MOVE_MUTEX_CFG_en_reg_offset_START (0)
#define SOC_TCP_MOVE_MUTEX_CFG_en_reg_offset_END (7)
#define SOC_TCP_MOVE_MUTEX_CFG_dis_reg_offset_START (8)
#define SOC_TCP_MOVE_MUTEX_CFG_dis_reg_offset_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int tcp_base_addr : 17;
    } reg;
} SOC_TCP_BASEADDR_UNION;
#endif
#define SOC_TCP_BASEADDR_tcp_base_addr_START (15)
#define SOC_TCP_BASEADDR_tcp_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 2;
        unsigned int sp_base_addr : 30;
    } reg;
} SOC_TCP_SP_BASEADDR_UNION;
#endif
#define SOC_TCP_SP_BASEADDR_sp_base_addr_START (2)
#define SOC_TCP_SP_BASEADDR_sp_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int instr_code_size : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_TCP_INSTR_SIZE_CFG_UNION;
#endif
#define SOC_TCP_INSTR_SIZE_CFG_instr_code_size_START (0)
#define SOC_TCP_INSTR_SIZE_CFG_instr_code_size_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inval_instr_stat : 1;
        unsigned int tcpcaddr_err_stat : 1;
        unsigned int add_carry_stat : 1;
        unsigned int task_timeout_stat : 1;
        unsigned int ahb_err_stat : 1;
        unsigned int ahb_addr_err_stat : 1;
        unsigned int pc_stack_err_stat : 1;
        unsigned int sp_err_stat : 1;
        unsigned int reserved_0 : 8;
        unsigned int soft_irq_stat : 3;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_TCP_IRQ_STAT_UNION;
#endif
#define SOC_TCP_IRQ_STAT_inval_instr_stat_START (0)
#define SOC_TCP_IRQ_STAT_inval_instr_stat_END (0)
#define SOC_TCP_IRQ_STAT_tcpcaddr_err_stat_START (1)
#define SOC_TCP_IRQ_STAT_tcpcaddr_err_stat_END (1)
#define SOC_TCP_IRQ_STAT_add_carry_stat_START (2)
#define SOC_TCP_IRQ_STAT_add_carry_stat_END (2)
#define SOC_TCP_IRQ_STAT_task_timeout_stat_START (3)
#define SOC_TCP_IRQ_STAT_task_timeout_stat_END (3)
#define SOC_TCP_IRQ_STAT_ahb_err_stat_START (4)
#define SOC_TCP_IRQ_STAT_ahb_err_stat_END (4)
#define SOC_TCP_IRQ_STAT_ahb_addr_err_stat_START (5)
#define SOC_TCP_IRQ_STAT_ahb_addr_err_stat_END (5)
#define SOC_TCP_IRQ_STAT_pc_stack_err_stat_START (6)
#define SOC_TCP_IRQ_STAT_pc_stack_err_stat_END (6)
#define SOC_TCP_IRQ_STAT_sp_err_stat_START (7)
#define SOC_TCP_IRQ_STAT_sp_err_stat_END (7)
#define SOC_TCP_IRQ_STAT_soft_irq_stat_START (16)
#define SOC_TCP_IRQ_STAT_soft_irq_stat_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inval_instr_mask : 1;
        unsigned int tcpcaddr_err_mask : 1;
        unsigned int add_carry_mask : 1;
        unsigned int task_timeout_mask : 1;
        unsigned int ahb_err_mask : 1;
        unsigned int ahb_addr_err_mask : 1;
        unsigned int pc_stack_err_mask : 1;
        unsigned int sp_err_mask : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TCP_IRQ_MASK_UNION;
#endif
#define SOC_TCP_IRQ_MASK_inval_instr_mask_START (0)
#define SOC_TCP_IRQ_MASK_inval_instr_mask_END (0)
#define SOC_TCP_IRQ_MASK_tcpcaddr_err_mask_START (1)
#define SOC_TCP_IRQ_MASK_tcpcaddr_err_mask_END (1)
#define SOC_TCP_IRQ_MASK_add_carry_mask_START (2)
#define SOC_TCP_IRQ_MASK_add_carry_mask_END (2)
#define SOC_TCP_IRQ_MASK_task_timeout_mask_START (3)
#define SOC_TCP_IRQ_MASK_task_timeout_mask_END (3)
#define SOC_TCP_IRQ_MASK_ahb_err_mask_START (4)
#define SOC_TCP_IRQ_MASK_ahb_err_mask_END (4)
#define SOC_TCP_IRQ_MASK_ahb_addr_err_mask_START (5)
#define SOC_TCP_IRQ_MASK_ahb_addr_err_mask_END (5)
#define SOC_TCP_IRQ_MASK_pc_stack_err_mask_START (6)
#define SOC_TCP_IRQ_MASK_pc_stack_err_mask_END (6)
#define SOC_TCP_IRQ_MASK_sp_err_mask_START (7)
#define SOC_TCP_IRQ_MASK_sp_err_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inval_instr_clr : 1;
        unsigned int tcpcaddr_err_clr : 1;
        unsigned int add_carry_clr : 1;
        unsigned int task_timeout_clr : 1;
        unsigned int ahb_err_clr : 1;
        unsigned int ahb_addr_err_clr : 1;
        unsigned int pc_stack_err_clr : 1;
        unsigned int sp_err_clr : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TCP_IRQ_CLR_UNION;
#endif
#define SOC_TCP_IRQ_CLR_inval_instr_clr_START (0)
#define SOC_TCP_IRQ_CLR_inval_instr_clr_END (0)
#define SOC_TCP_IRQ_CLR_tcpcaddr_err_clr_START (1)
#define SOC_TCP_IRQ_CLR_tcpcaddr_err_clr_END (1)
#define SOC_TCP_IRQ_CLR_add_carry_clr_START (2)
#define SOC_TCP_IRQ_CLR_add_carry_clr_END (2)
#define SOC_TCP_IRQ_CLR_task_timeout_clr_START (3)
#define SOC_TCP_IRQ_CLR_task_timeout_clr_END (3)
#define SOC_TCP_IRQ_CLR_ahb_err_clr_START (4)
#define SOC_TCP_IRQ_CLR_ahb_err_clr_END (4)
#define SOC_TCP_IRQ_CLR_ahb_addr_err_clr_START (5)
#define SOC_TCP_IRQ_CLR_ahb_addr_err_clr_END (5)
#define SOC_TCP_IRQ_CLR_pc_stack_err_clr_START (6)
#define SOC_TCP_IRQ_CLR_pc_stack_err_clr_END (6)
#define SOC_TCP_IRQ_CLR_sp_err_clr_START (7)
#define SOC_TCP_IRQ_CLR_sp_err_clr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_done_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TASK_DONE_IRQ_STAT_UNION;
#endif
#define SOC_TCP_TASK_DONE_IRQ_STAT_task_done_stat_START (0)
#define SOC_TCP_TASK_DONE_IRQ_STAT_task_done_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_done_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TASK_DONE_IRQ_MASK_UNION;
#endif
#define SOC_TCP_TASK_DONE_IRQ_MASK_task_done_mask_START (0)
#define SOC_TCP_TASK_DONE_IRQ_MASK_task_done_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_done_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TASK_DONE_IRQ_CLR_UNION;
#endif
#define SOC_TCP_TASK_DONE_IRQ_CLR_task_done_clr_START (0)
#define SOC_TCP_TASK_DONE_IRQ_CLR_task_done_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TCP_DBG_CTRL_UNION;
#endif
#define SOC_TCP_DBG_CTRL_dbg_en_START (0)
#define SOC_TCP_DBG_CTRL_dbg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_bk_addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_DBG_BKP_UNION;
#endif
#define SOC_TCP_DBG_BKP_dbg_bk_addr_START (0)
#define SOC_TCP_DBG_BKP_dbg_bk_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_step : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TCP_DBG_STEP_UNION;
#endif
#define SOC_TCP_DBG_STEP_dbg_step_START (0)
#define SOC_TCP_DBG_STEP_dbg_step_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_continue : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TCP_DBG_CONTINUE_UNION;
#endif
#define SOC_TCP_DBG_CONTINUE_dbg_continue_START (0)
#define SOC_TCP_DBG_CONTINUE_dbg_continue_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdt_cnt : 18;
        unsigned int reserved_0: 6;
        unsigned int wdt_en : 1;
        unsigned int reserved_1: 7;
    } reg;
} SOC_TCP_WDT_CFG_UNION;
#endif
#define SOC_TCP_WDT_CFG_wdt_cnt_START (0)
#define SOC_TCP_WDT_CFG_wdt_cnt_END (17)
#define SOC_TCP_WDT_CFG_wdt_en_START (24)
#define SOC_TCP_WDT_CFG_wdt_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdt_cnt_stat : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_TCP_WDT_STAT_UNION;
#endif
#define SOC_TCP_WDT_STAT_wdt_cnt_stat_START (0)
#define SOC_TCP_WDT_STAT_wdt_cnt_stat_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_start_addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TASK_START_ADDR_UNION;
#endif
#define SOC_TCP_TASK_START_ADDR_task_start_addr_START (0)
#define SOC_TCP_TASK_START_ADDR_task_start_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_sel_ext_irq : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TCP_EXT_IRQ_TASK_SEL_UNION;
#endif
#define SOC_TCP_EXT_IRQ_TASK_SEL_task_sel_ext_irq_START (0)
#define SOC_TCP_EXT_IRQ_TASK_SEL_task_sel_ext_irq_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ext_irq_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_EXT_IRQ_EN_UNION;
#endif
#define SOC_TCP_EXT_IRQ_EN_ext_irq_en_START (0)
#define SOC_TCP_EXT_IRQ_EN_ext_irq_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int soft_req : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_SOFT_REQ_UNION;
#endif
#define SOC_TCP_SOFT_REQ_soft_req_START (0)
#define SOC_TCP_SOFT_REQ_soft_req_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_sel_err_irq : 4;
        unsigned int reserved_0 : 4;
        unsigned int err_req_en : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_TCP_ERR_TASK_REQ_CFG_UNION;
#endif
#define SOC_TCP_ERR_TASK_REQ_CFG_task_sel_err_irq_START (0)
#define SOC_TCP_ERR_TASK_REQ_CFG_task_sel_err_irq_END (3)
#define SOC_TCP_ERR_TASK_REQ_CFG_err_req_en_START (8)
#define SOC_TCP_ERR_TASK_REQ_CFG_err_req_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_sel_tim_tick : 4;
        unsigned int reserved_0 : 4;
        unsigned int tim_tick_req_en : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_TCP_TIM_TASK_REQ_CFG_UNION;
#endif
#define SOC_TCP_TIM_TASK_REQ_CFG_task_sel_tim_tick_START (0)
#define SOC_TCP_TIM_TASK_REQ_CFG_task_sel_tim_tick_END (3)
#define SOC_TCP_TIM_TASK_REQ_CFG_tim_tick_req_en_START (8)
#define SOC_TCP_TIM_TASK_REQ_CFG_tim_tick_req_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_req_stat : 32;
    } reg;
} SOC_TCP_TASK_REQ_STAT_UNION;
#endif
#define SOC_TCP_TASK_REQ_STAT_task_req_stat_START (0)
#define SOC_TCP_TASK_REQ_STAT_task_req_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_stat : 32;
    } reg;
} SOC_TCP_TASK_STAT_UNION;
#endif
#define SOC_TCP_TASK_STAT_task_stat_START (0)
#define SOC_TCP_TASK_STAT_task_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_soft_irq_set : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_TCP_SOFT_IRQ_SET_UNION;
#endif
#define SOC_TCP_SOFT_IRQ_SET_l2_soft_irq_set_START (0)
#define SOC_TCP_SOFT_IRQ_SET_l2_soft_irq_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_soft_irq_clr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_TCP_SOFT_IRQ_CLR_UNION;
#endif
#define SOC_TCP_SOFT_IRQ_CLR_l2_soft_irq_clr_START (0)
#define SOC_TCP_SOFT_IRQ_CLR_l2_soft_irq_clr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_soft_irq_mask : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_TCP_SOFT_IRQ_MASK_UNION;
#endif
#define SOC_TCP_SOFT_IRQ_MASK_l2_soft_irq_mask_START (0)
#define SOC_TCP_SOFT_IRQ_MASK_l2_soft_irq_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_soft_irq_stat : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_TCP_SOFT_IRQ_STAT_UNION;
#endif
#define SOC_TCP_SOFT_IRQ_STAT_l2_soft_irq_stat_START (0)
#define SOC_TCP_SOFT_IRQ_STAT_l2_soft_irq_stat_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_chn_en : 1;
        unsigned int reserved : 18;
        unsigned int addr_chn_base : 13;
    } reg;
} SOC_TCP_TCPC_AHB_ADDR_CHN_UNION;
#endif
#define SOC_TCP_TCPC_AHB_ADDR_CHN_addr_chn_en_START (0)
#define SOC_TCP_TCPC_AHB_ADDR_CHN_addr_chn_en_END (0)
#define SOC_TCP_TCPC_AHB_ADDR_CHN_addr_chn_base_START (19)
#define SOC_TCP_TCPC_AHB_ADDR_CHN_addr_chn_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tim_cnt : 16;
        unsigned int tim_en : 1;
        unsigned int tim_mode : 1;
        unsigned int reserved_0 : 6;
        unsigned int tim_clk_div_sel : 2;
        unsigned int tim_clk_on : 1;
        unsigned int tim_clk_sel : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_TCP_TIM_CFG_UNION;
#endif
#define SOC_TCP_TIM_CFG_tim_cnt_START (0)
#define SOC_TCP_TIM_CFG_tim_cnt_END (15)
#define SOC_TCP_TIM_CFG_tim_en_START (16)
#define SOC_TCP_TIM_CFG_tim_en_END (16)
#define SOC_TCP_TIM_CFG_tim_mode_START (17)
#define SOC_TCP_TIM_CFG_tim_mode_END (17)
#define SOC_TCP_TIM_CFG_tim_clk_div_sel_START (24)
#define SOC_TCP_TIM_CFG_tim_clk_div_sel_END (25)
#define SOC_TCP_TIM_CFG_tim_clk_on_START (26)
#define SOC_TCP_TIM_CFG_tim_clk_on_END (26)
#define SOC_TCP_TIM_CFG_tim_clk_sel_START (27)
#define SOC_TCP_TIM_CFG_tim_clk_sel_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tim_cnt_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TIM_STAT_UNION;
#endif
#define SOC_TCP_TIM_STAT_tim_cnt_stat_START (0)
#define SOC_TCP_TIM_STAT_tim_cnt_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int greg_stat : 32;
    } reg;
} SOC_TCP_GENERAL_REG_UNION;
#endif
#define SOC_TCP_GENERAL_REG_greg_stat_START (0)
#define SOC_TCP_GENERAL_REG_greg_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int common_reg : 32;
    } reg;
} SOC_TCP_COMMON_REG_UNION;
#endif
#define SOC_TCP_COMMON_REG_common_reg_START (0)
#define SOC_TCP_COMMON_REG_common_reg_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

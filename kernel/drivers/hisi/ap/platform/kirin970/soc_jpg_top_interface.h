#ifndef __SOC_JPG_TOP_INTERFACE_H__
#define __SOC_JPG_TOP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_JPG_TOP_JPGENC_CRG_CFG0_ADDR(base) ((base) + (0x0))
#define SOC_JPG_TOP_JPGENC_CRG_CFG1_ADDR(base) ((base) + (0x4))
#define SOC_JPG_TOP_JPGENC_MEM_CFG_ADDR(base) ((base) + (0x8))
#define SOC_JPG_TOP_JPG_RO_STATE_ADDR(base) ((base) + (0xC))
#define SOC_JPG_TOP_JPGDEC_CRG_CFG0_ADDR(base) ((base) + (0x20))
#define SOC_JPG_TOP_JPGDEC_CRG_CFG1_ADDR(base) ((base) + (0x24))
#define SOC_JPG_TOP_JPGDEC_MEM_CFG_ADDR(base) ((base) + (0x28))
#define SOC_JPG_TOP_JPGDEC_IRQ_REG0_ADDR(base) ((base) + (0x2C))
#define SOC_JPG_TOP_JPGDEC_IRQ_REG1_ADDR(base) ((base) + (0x30))
#define SOC_JPG_TOP_JPGDEC_IRQ_REG2_ADDR(base) ((base) + (0x34))
#define SOC_JPG_TOP_TOP_AXI_CFG0_ADDR(base) ((base) + (0x40))
#define SOC_JPG_TOP_CVDR_MEM_CFG_ADDR(base) ((base) + (0x44))
#define SOC_JPG_TOP_CVDR_IRQ_REG0_ADDR(base) ((base) + (0x48))
#define SOC_JPG_TOP_CVDR_IRQ_REG1_ADDR(base) ((base) + (0x4C))
#define SOC_JPG_TOP_CVDR_IRQ_REG2_ADDR(base) ((base) + (0x50))
#define SOC_JPG_TOP_DMA_CRG_CFG1_ADDR(base) ((base) + (0x54))
#define SOC_JPG_TOP_JPG_OTHER_MERGE_IRQ_ADDR(base) ((base) + (0x60))
#define SOC_JPG_TOP_FD_AXI_CFG0_ADDR(base) ((base) + (0x70))
#define SOC_JPG_TOP_FD_CRG_CFG0_ADDR(base) ((base) + (0x74))
#define SOC_JPG_TOP_FD_CRG_CFG1_ADDR(base) ((base) + (0x78))
#define SOC_JPG_TOP_FD_MEM_CFG_ADDR(base) ((base) + (0x7C))
#define SOC_JPG_TOP_JPG_FLUX_CTRL0_0_ADDR(base) ((base) + (0x80))
#define SOC_JPG_TOP_JPG_FLUX_CTRL0_1_ADDR(base) ((base) + (0x84))
#define SOC_JPG_TOP_JPG_FLUX_CTRL1_0_ADDR(base) ((base) + (0x88))
#define SOC_JPG_TOP_JPG_FLUX_CTRL1_1_ADDR(base) ((base) + (0x8C))
#define SOC_JPG_TOP_JPG_FLUX_CTRL2_0_ADDR(base) ((base) + (0x90))
#define SOC_JPG_TOP_JPG_FLUX_CTRL2_1_ADDR(base) ((base) + (0x94))
#define SOC_JPG_TOP_JPG_FLUX_CTRL3_0_ADDR(base) ((base) + (0x98))
#define SOC_JPG_TOP_JPG_FLUX_CTRL3_1_ADDR(base) ((base) + (0x9C))
#define SOC_JPG_TOP_FD_SMMU_MASTER_REG0_ADDR(base) ((base) + (0xB0))
#define SOC_JPG_TOP_FD_SMMU_MASTER_REG1_ADDR(base) ((base) + (0xB4))
#define SOC_JPG_TOP_FD_SMMU_MASTER_REG2_ADDR(base) ((base) + (0xB8))
#define SOC_JPG_TOP_JPG_DEBUG_0_ADDR(base) ((base) + (0x100))
#define SOC_JPG_TOP_JPG_DEBUG_1_ADDR(base) ((base) + (0x104))
#define SOC_JPG_TOP_JPG_DEBUG_2_ADDR(base) ((base) + (0x108))
#define SOC_JPG_TOP_JPG_DEBUG_3_ADDR(base) ((base) + (0x10C))
#define SOC_JPG_TOP_JPG_SEC_CTRL_S_ADDR(base) ((base) + (0x800))
#define SOC_JPG_TOP_FD_AXI_CFG1_S_ADDR(base) ((base) + (0x810))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgenc_clken : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_JPG_TOP_JPGENC_CRG_CFG0_UNION;
#endif
#define SOC_JPG_TOP_JPGENC_CRG_CFG0_jpgenc_clken_START (0)
#define SOC_JPG_TOP_JPGENC_CRG_CFG0_jpgenc_clken_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgenc_soft_rst : 1;
        unsigned int reserved_0 : 15;
        unsigned int prefetch_stop_jpgenc : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_JPG_TOP_JPGENC_CRG_CFG1_UNION;
#endif
#define SOC_JPG_TOP_JPGENC_CRG_CFG1_jpgenc_soft_rst_START (0)
#define SOC_JPG_TOP_JPGENC_CRG_CFG1_jpgenc_soft_rst_END (0)
#define SOC_JPG_TOP_JPGENC_CRG_CFG1_prefetch_stop_jpgenc_START (16)
#define SOC_JPG_TOP_JPGENC_CRG_CFG1_prefetch_stop_jpgenc_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgenc_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_JPG_TOP_JPGENC_MEM_CFG_UNION;
#endif
#define SOC_JPG_TOP_JPGENC_MEM_CFG_jpgenc_mem_ctrl_START (0)
#define SOC_JPG_TOP_JPGENC_MEM_CFG_jpgenc_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prefetch_stop_ok_jpgenc : 1;
        unsigned int prefetch_stop_ok_jpgdec : 1;
        unsigned int reserved_0 : 6;
        unsigned int jpg_smmu_idle : 1;
        unsigned int jpg_cvdr_busy : 1;
        unsigned int reserved_1 : 6;
        unsigned int jpg_axi_dlock_irq : 1;
        unsigned int jpg_axi_dlock_wr : 1;
        unsigned int jpg_axi_dlock_slv : 1;
        unsigned int jpg_axi_dlock_mst : 1;
        unsigned int jpg_axi_dlock_id : 8;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_JPG_TOP_JPG_RO_STATE_UNION;
#endif
#define SOC_JPG_TOP_JPG_RO_STATE_prefetch_stop_ok_jpgenc_START (0)
#define SOC_JPG_TOP_JPG_RO_STATE_prefetch_stop_ok_jpgenc_END (0)
#define SOC_JPG_TOP_JPG_RO_STATE_prefetch_stop_ok_jpgdec_START (1)
#define SOC_JPG_TOP_JPG_RO_STATE_prefetch_stop_ok_jpgdec_END (1)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_smmu_idle_START (8)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_smmu_idle_END (8)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_cvdr_busy_START (9)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_cvdr_busy_END (9)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_axi_dlock_irq_START (16)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_axi_dlock_irq_END (16)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_axi_dlock_wr_START (17)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_axi_dlock_wr_END (17)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_axi_dlock_slv_START (18)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_axi_dlock_slv_END (18)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_axi_dlock_mst_START (19)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_axi_dlock_mst_END (19)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_axi_dlock_id_START (20)
#define SOC_JPG_TOP_JPG_RO_STATE_jpg_axi_dlock_id_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgdec_clken : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_JPG_TOP_JPGDEC_CRG_CFG0_UNION;
#endif
#define SOC_JPG_TOP_JPGDEC_CRG_CFG0_jpgdec_clken_START (0)
#define SOC_JPG_TOP_JPGDEC_CRG_CFG0_jpgdec_clken_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgdec_soft_rst : 1;
        unsigned int reserved_0 : 15;
        unsigned int prefetch_stop_jpgdec : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_JPG_TOP_JPGDEC_CRG_CFG1_UNION;
#endif
#define SOC_JPG_TOP_JPGDEC_CRG_CFG1_jpgdec_soft_rst_START (0)
#define SOC_JPG_TOP_JPGDEC_CRG_CFG1_jpgdec_soft_rst_END (0)
#define SOC_JPG_TOP_JPGDEC_CRG_CFG1_prefetch_stop_jpgdec_START (16)
#define SOC_JPG_TOP_JPGDEC_CRG_CFG1_prefetch_stop_jpgdec_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgdec_mem_ctrl_sp : 16;
        unsigned int jpgdec_mem_ctrl_tp : 16;
    } reg;
} SOC_JPG_TOP_JPGDEC_MEM_CFG_UNION;
#endif
#define SOC_JPG_TOP_JPGDEC_MEM_CFG_jpgdec_mem_ctrl_sp_START (0)
#define SOC_JPG_TOP_JPGDEC_MEM_CFG_jpgdec_mem_ctrl_sp_END (15)
#define SOC_JPG_TOP_JPGDEC_MEM_CFG_jpgdec_mem_ctrl_tp_START (16)
#define SOC_JPG_TOP_JPGDEC_MEM_CFG_jpgdec_mem_ctrl_tp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgdec_irq_clr : 4;
        unsigned int reserved_0 : 12;
        unsigned int jpgdec_irq_force : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_JPG_TOP_JPGDEC_IRQ_REG0_UNION;
#endif
#define SOC_JPG_TOP_JPGDEC_IRQ_REG0_jpgdec_irq_clr_START (0)
#define SOC_JPG_TOP_JPGDEC_IRQ_REG0_jpgdec_irq_clr_END (3)
#define SOC_JPG_TOP_JPGDEC_IRQ_REG0_jpgdec_irq_force_START (16)
#define SOC_JPG_TOP_JPGDEC_IRQ_REG0_jpgdec_irq_force_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgdec_irq_mask : 4;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_JPG_TOP_JPGDEC_IRQ_REG1_UNION;
#endif
#define SOC_JPG_TOP_JPGDEC_IRQ_REG1_jpgdec_irq_mask_START (0)
#define SOC_JPG_TOP_JPGDEC_IRQ_REG1_jpgdec_irq_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpgdec_irq_state_mask : 4;
        unsigned int reserved_0 : 12;
        unsigned int jpgdec_irq_state_raw : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_JPG_TOP_JPGDEC_IRQ_REG2_UNION;
#endif
#define SOC_JPG_TOP_JPGDEC_IRQ_REG2_jpgdec_irq_state_mask_START (0)
#define SOC_JPG_TOP_JPGDEC_IRQ_REG2_jpgdec_irq_state_mask_END (3)
#define SOC_JPG_TOP_JPGDEC_IRQ_REG2_jpgdec_irq_state_raw_START (16)
#define SOC_JPG_TOP_JPGDEC_IRQ_REG2_jpgdec_irq_state_raw_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jpg_dw_axi_gatedclock_en : 1;
        unsigned int jpg_smmu_force_clk_on : 1;
        unsigned int jpg_dma_force_clk_on : 1;
        unsigned int jpg_top_apb_force_clk_on : 1;
        unsigned int reserved_0 : 12;
        unsigned int control_disable_axi_data_packing : 1;
        unsigned int mst_priority_fd : 1;
        unsigned int mst_priority_cvdr : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_JPG_TOP_TOP_AXI_CFG0_UNION;
#endif
#define SOC_JPG_TOP_TOP_AXI_CFG0_jpg_dw_axi_gatedclock_en_START (0)
#define SOC_JPG_TOP_TOP_AXI_CFG0_jpg_dw_axi_gatedclock_en_END (0)
#define SOC_JPG_TOP_TOP_AXI_CFG0_jpg_smmu_force_clk_on_START (1)
#define SOC_JPG_TOP_TOP_AXI_CFG0_jpg_smmu_force_clk_on_END (1)
#define SOC_JPG_TOP_TOP_AXI_CFG0_jpg_dma_force_clk_on_START (2)
#define SOC_JPG_TOP_TOP_AXI_CFG0_jpg_dma_force_clk_on_END (2)
#define SOC_JPG_TOP_TOP_AXI_CFG0_jpg_top_apb_force_clk_on_START (3)
#define SOC_JPG_TOP_TOP_AXI_CFG0_jpg_top_apb_force_clk_on_END (3)
#define SOC_JPG_TOP_TOP_AXI_CFG0_control_disable_axi_data_packing_START (16)
#define SOC_JPG_TOP_TOP_AXI_CFG0_control_disable_axi_data_packing_END (16)
#define SOC_JPG_TOP_TOP_AXI_CFG0_mst_priority_fd_START (17)
#define SOC_JPG_TOP_TOP_AXI_CFG0_mst_priority_fd_END (17)
#define SOC_JPG_TOP_TOP_AXI_CFG0_mst_priority_cvdr_START (18)
#define SOC_JPG_TOP_TOP_AXI_CFG0_mst_priority_cvdr_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cvdr_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_JPG_TOP_CVDR_MEM_CFG_UNION;
#endif
#define SOC_JPG_TOP_CVDR_MEM_CFG_cvdr_mem_ctrl_START (0)
#define SOC_JPG_TOP_CVDR_MEM_CFG_cvdr_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cvdr_irq_clr : 6;
        unsigned int reserved_0 : 10;
        unsigned int cvdr_irq_force : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_JPG_TOP_CVDR_IRQ_REG0_UNION;
#endif
#define SOC_JPG_TOP_CVDR_IRQ_REG0_cvdr_irq_clr_START (0)
#define SOC_JPG_TOP_CVDR_IRQ_REG0_cvdr_irq_clr_END (5)
#define SOC_JPG_TOP_CVDR_IRQ_REG0_cvdr_irq_force_START (16)
#define SOC_JPG_TOP_CVDR_IRQ_REG0_cvdr_irq_force_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cvdr_irq_mask : 6;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_JPG_TOP_CVDR_IRQ_REG1_UNION;
#endif
#define SOC_JPG_TOP_CVDR_IRQ_REG1_cvdr_irq_mask_START (0)
#define SOC_JPG_TOP_CVDR_IRQ_REG1_cvdr_irq_mask_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cvdr_irq_state_mask : 6;
        unsigned int reserved_0 : 10;
        unsigned int cvdr_irq_state_raw : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_JPG_TOP_CVDR_IRQ_REG2_UNION;
#endif
#define SOC_JPG_TOP_CVDR_IRQ_REG2_cvdr_irq_state_mask_START (0)
#define SOC_JPG_TOP_CVDR_IRQ_REG2_cvdr_irq_state_mask_END (5)
#define SOC_JPG_TOP_CVDR_IRQ_REG2_cvdr_irq_state_raw_START (16)
#define SOC_JPG_TOP_CVDR_IRQ_REG2_cvdr_irq_state_raw_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cvdr_soft_rst : 1;
        unsigned int smmu_soft_rst : 1;
        unsigned int reserved_0 : 14;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_JPG_TOP_DMA_CRG_CFG1_UNION;
#endif
#define SOC_JPG_TOP_DMA_CRG_CFG1_cvdr_soft_rst_START (0)
#define SOC_JPG_TOP_DMA_CRG_CFG1_cvdr_soft_rst_END (0)
#define SOC_JPG_TOP_DMA_CRG_CFG1_smmu_soft_rst_START (1)
#define SOC_JPG_TOP_DMA_CRG_CFG1_smmu_soft_rst_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int merged_irq_state : 11;
        unsigned int reserved_0 : 5;
        unsigned int ap_irq_state : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_JPG_TOP_JPG_OTHER_MERGE_IRQ_UNION;
#endif
#define SOC_JPG_TOP_JPG_OTHER_MERGE_IRQ_merged_irq_state_START (0)
#define SOC_JPG_TOP_JPG_OTHER_MERGE_IRQ_merged_irq_state_END (10)
#define SOC_JPG_TOP_JPG_OTHER_MERGE_IRQ_ap_irq_state_START (16)
#define SOC_JPG_TOP_JPG_OTHER_MERGE_IRQ_ap_irq_state_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fd_awqos : 2;
        unsigned int fd_arqos : 2;
        unsigned int reserved_0 : 4;
        unsigned int fd_rom_ctrl : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_JPG_TOP_FD_AXI_CFG0_UNION;
#endif
#define SOC_JPG_TOP_FD_AXI_CFG0_fd_awqos_START (0)
#define SOC_JPG_TOP_FD_AXI_CFG0_fd_awqos_END (1)
#define SOC_JPG_TOP_FD_AXI_CFG0_fd_arqos_START (2)
#define SOC_JPG_TOP_FD_AXI_CFG0_fd_arqos_END (3)
#define SOC_JPG_TOP_FD_AXI_CFG0_fd_rom_ctrl_START (8)
#define SOC_JPG_TOP_FD_AXI_CFG0_fd_rom_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fd_apbm_clken : 1;
        unsigned int fd_axim_clken : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_JPG_TOP_FD_CRG_CFG0_UNION;
#endif
#define SOC_JPG_TOP_FD_CRG_CFG0_fd_apbm_clken_START (0)
#define SOC_JPG_TOP_FD_CRG_CFG0_fd_apbm_clken_END (0)
#define SOC_JPG_TOP_FD_CRG_CFG0_fd_axim_clken_START (1)
#define SOC_JPG_TOP_FD_CRG_CFG0_fd_axim_clken_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fd_apbm_soft_rst : 1;
        unsigned int fd_axim_soft_rst : 1;
        unsigned int reserved_0 : 14;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_JPG_TOP_FD_CRG_CFG1_UNION;
#endif
#define SOC_JPG_TOP_FD_CRG_CFG1_fd_apbm_soft_rst_START (0)
#define SOC_JPG_TOP_FD_CRG_CFG1_fd_apbm_soft_rst_END (0)
#define SOC_JPG_TOP_FD_CRG_CFG1_fd_axim_soft_rst_START (1)
#define SOC_JPG_TOP_FD_CRG_CFG1_fd_axim_soft_rst_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fd_mem_ctrl_sp : 16;
        unsigned int fd_mem_ctrl_tp : 16;
    } reg;
} SOC_JPG_TOP_FD_MEM_CFG_UNION;
#endif
#define SOC_JPG_TOP_FD_MEM_CFG_fd_mem_ctrl_sp_START (0)
#define SOC_JPG_TOP_FD_MEM_CFG_fd_mem_ctrl_sp_END (15)
#define SOC_JPG_TOP_FD_MEM_CFG_fd_mem_ctrl_tp_START (16)
#define SOC_JPG_TOP_FD_MEM_CFG_fd_mem_ctrl_tp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl0_cvdr_r : 32;
    } reg;
} SOC_JPG_TOP_JPG_FLUX_CTRL0_0_UNION;
#endif
#define SOC_JPG_TOP_JPG_FLUX_CTRL0_0_flux_ctrl0_cvdr_r_START (0)
#define SOC_JPG_TOP_JPG_FLUX_CTRL0_0_flux_ctrl0_cvdr_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl1_cvdr_r : 32;
    } reg;
} SOC_JPG_TOP_JPG_FLUX_CTRL0_1_UNION;
#endif
#define SOC_JPG_TOP_JPG_FLUX_CTRL0_1_flux_ctrl1_cvdr_r_START (0)
#define SOC_JPG_TOP_JPG_FLUX_CTRL0_1_flux_ctrl1_cvdr_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl0_cvdr_w : 32;
    } reg;
} SOC_JPG_TOP_JPG_FLUX_CTRL1_0_UNION;
#endif
#define SOC_JPG_TOP_JPG_FLUX_CTRL1_0_flux_ctrl0_cvdr_w_START (0)
#define SOC_JPG_TOP_JPG_FLUX_CTRL1_0_flux_ctrl0_cvdr_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl1_cvdr_w : 32;
    } reg;
} SOC_JPG_TOP_JPG_FLUX_CTRL1_1_UNION;
#endif
#define SOC_JPG_TOP_JPG_FLUX_CTRL1_1_flux_ctrl1_cvdr_w_START (0)
#define SOC_JPG_TOP_JPG_FLUX_CTRL1_1_flux_ctrl1_cvdr_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl0_fd_r : 32;
    } reg;
} SOC_JPG_TOP_JPG_FLUX_CTRL2_0_UNION;
#endif
#define SOC_JPG_TOP_JPG_FLUX_CTRL2_0_flux_ctrl0_fd_r_START (0)
#define SOC_JPG_TOP_JPG_FLUX_CTRL2_0_flux_ctrl0_fd_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl1_fd_r : 32;
    } reg;
} SOC_JPG_TOP_JPG_FLUX_CTRL2_1_UNION;
#endif
#define SOC_JPG_TOP_JPG_FLUX_CTRL2_1_flux_ctrl1_fd_r_START (0)
#define SOC_JPG_TOP_JPG_FLUX_CTRL2_1_flux_ctrl1_fd_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl0_fd_w : 32;
    } reg;
} SOC_JPG_TOP_JPG_FLUX_CTRL3_0_UNION;
#endif
#define SOC_JPG_TOP_JPG_FLUX_CTRL3_0_flux_ctrl0_fd_w_START (0)
#define SOC_JPG_TOP_JPG_FLUX_CTRL3_0_flux_ctrl0_fd_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_ctrl1_fd_w : 32;
    } reg;
} SOC_JPG_TOP_JPG_FLUX_CTRL3_1_UNION;
#endif
#define SOC_JPG_TOP_JPG_FLUX_CTRL3_1_flux_ctrl1_fd_w_START (0)
#define SOC_JPG_TOP_JPG_FLUX_CTRL3_1_flux_ctrl1_fd_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fd_prefetch_initial : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_JPG_TOP_FD_SMMU_MASTER_REG0_UNION;
#endif
#define SOC_JPG_TOP_FD_SMMU_MASTER_REG0_fd_prefetch_initial_START (0)
#define SOC_JPG_TOP_FD_SMMU_MASTER_REG0_fd_prefetch_initial_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fd_stream_end : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_JPG_TOP_FD_SMMU_MASTER_REG1_UNION;
#endif
#define SOC_JPG_TOP_FD_SMMU_MASTER_REG1_fd_stream_end_START (0)
#define SOC_JPG_TOP_FD_SMMU_MASTER_REG1_fd_stream_end_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fd_stream_ack : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_JPG_TOP_FD_SMMU_MASTER_REG2_UNION;
#endif
#define SOC_JPG_TOP_FD_SMMU_MASTER_REG2_fd_stream_ack_START (0)
#define SOC_JPG_TOP_FD_SMMU_MASTER_REG2_fd_stream_ack_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_info_0 : 32;
    } reg;
} SOC_JPG_TOP_JPG_DEBUG_0_UNION;
#endif
#define SOC_JPG_TOP_JPG_DEBUG_0_debug_info_0_START (0)
#define SOC_JPG_TOP_JPG_DEBUG_0_debug_info_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_info_1 : 32;
    } reg;
} SOC_JPG_TOP_JPG_DEBUG_1_UNION;
#endif
#define SOC_JPG_TOP_JPG_DEBUG_1_debug_info_1_START (0)
#define SOC_JPG_TOP_JPG_DEBUG_1_debug_info_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_info_2 : 32;
    } reg;
} SOC_JPG_TOP_JPG_DEBUG_2_UNION;
#endif
#define SOC_JPG_TOP_JPG_DEBUG_2_debug_info_2_START (0)
#define SOC_JPG_TOP_JPG_DEBUG_2_debug_info_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_info_3 : 32;
    } reg;
} SOC_JPG_TOP_JPG_DEBUG_3_UNION;
#endif
#define SOC_JPG_TOP_JPG_DEBUG_3_debug_info_3_START (0)
#define SOC_JPG_TOP_JPG_DEBUG_3_debug_info_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int top_tz_secure_n : 1;
        unsigned int jpgenc_tz_secure_n : 1;
        unsigned int jpgdec_tz_secure_n : 1;
        unsigned int fd_tz_secure_n : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_JPG_TOP_JPG_SEC_CTRL_S_UNION;
#endif
#define SOC_JPG_TOP_JPG_SEC_CTRL_S_top_tz_secure_n_START (0)
#define SOC_JPG_TOP_JPG_SEC_CTRL_S_top_tz_secure_n_END (0)
#define SOC_JPG_TOP_JPG_SEC_CTRL_S_jpgenc_tz_secure_n_START (1)
#define SOC_JPG_TOP_JPG_SEC_CTRL_S_jpgenc_tz_secure_n_END (1)
#define SOC_JPG_TOP_JPG_SEC_CTRL_S_jpgdec_tz_secure_n_START (2)
#define SOC_JPG_TOP_JPG_SEC_CTRL_S_jpgdec_tz_secure_n_END (2)
#define SOC_JPG_TOP_JPG_SEC_CTRL_S_fd_tz_secure_n_START (3)
#define SOC_JPG_TOP_JPG_SEC_CTRL_S_fd_tz_secure_n_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fd_mid : 6;
        unsigned int reserved_0 : 2;
        unsigned int fd_axi_prot : 3;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_JPG_TOP_FD_AXI_CFG1_S_UNION;
#endif
#define SOC_JPG_TOP_FD_AXI_CFG1_S_fd_mid_START (0)
#define SOC_JPG_TOP_FD_AXI_CFG1_S_fd_mid_END (5)
#define SOC_JPG_TOP_FD_AXI_CFG1_S_fd_axi_prot_START (8)
#define SOC_JPG_TOP_FD_AXI_CFG1_S_fd_axi_prot_END (10)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

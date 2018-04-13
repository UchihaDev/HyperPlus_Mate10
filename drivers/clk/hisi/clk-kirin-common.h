enum {
	HS_PMCTRL,
	HS_SYSCTRL,
	HS_CRGCTRL,
	HS_PMUCTRL,
	HS_PCTRL,
	HS_MEDIACRG,
	HS_IOMCUCRG,
	HS_MEDIA1CRG,
	HS_MEDIA2CRG,
};
enum {
	HS_UNBLOCK_MODE,
	HS_BLOCK_MODE,
};
#define DVFS_MAX_FREQ_NUM				2
#define DVFS_MAX_VOLT_NUM				3
#define DDR_HW_VOTE				1
#define PERI_AVS_LOOP_MAX			40
#define DDRC_MIN_CLK_ID			4
#define DDRC_MAX_CLK_ID			5
void __iomem *hs_clk_base(u32 ctrl);
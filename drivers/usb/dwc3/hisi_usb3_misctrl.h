#ifndef _DWC3_HISI_COMMON__H
#define _DWC3_HISI_COMMON__H

#include <linux/hisi/usb/hisi_usb_interface.h>

/* misc ctrl internal inteface */
void init_misc_ctrl_addr(void __iomem *base);
void init_sc_misc_ctrl_addr(void __iomem *base);

char *misc_ctrl_status_string(unsigned int misc_ctrl_status);
char *misc_ctrl_type_string(enum misc_ctrl_type type);

void usb3_misc_reg_writel(u32 val, unsigned long int offset);
u32 usb3_misc_reg_readl(unsigned long int offset);
void usb3_misc_reg_setbit(u32 bit, unsigned long int offset);
void usb3_misc_reg_clrbit(u32 bit, unsigned long int offset);
void usb3_misc_reg_setvalue(u32 val, unsigned long int offset);
void usb3_misc_reg_clrvalue(u32 val, unsigned long int offset);

u32 usb3_sc_misc_reg_readl(unsigned long int offset);
void usb3_sc_misc_reg_writel(u32 val, unsigned long int offset);
void usb3_sc_misc_reg_setbit(u32 bit, unsigned long int offset);
void usb3_sc_misc_reg_clrbit(u32 bit, unsigned long int offset);
void usb3_sc_misc_reg_setvalue(u32 val, unsigned long int offset);
void usb3_sc_misc_reg_clrvalue(u32 val, unsigned long int offset);

int usb3_misc_ctrl_is_unreset(void __iomem *pericfg_base);
int usb3_misc_ctrl_is_reset(void __iomem *pericfg_base);

/* combophy control register internal interface */
enum phy_cr_start_type {
	PHY_CR_READ,
	PHY_CR_WRITE
};

void usb31phy_cr_set_addr(u32 addr);
void usb31phy_cr_clk(void);
void usb31phy_cr_100clk(void);
int usb31phy_cr_wait_ack(void);
void usb31phy_cr_start(enum phy_cr_start_type type);
void usb31phy_cr_set_sel(void);
int dwc3_is_highspeed_only(void);
int dwc3_set_highspeed_only(void);
#endif /* _DWC3_HISI_COMMON__H */

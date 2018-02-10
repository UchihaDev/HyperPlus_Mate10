
#include "drv_venc.h"
#include "venc_regulator.h"
#include "drv_venc_osal.h"


HI_U32 b_Regular_down_flag = HI_TRUE;

/* 外边复位vedu, 并设置时钟，撤销复位l00214825  */
HI_S32 VENC_DRV_BoardInit(HI_VOID)
{
	HI_S32 ret = 0;
	HI_DBG_VENC("enter %s()\n", __func__);

	ret = Venc_Regulator_Enable();/*lint !e838 */
	if (ret != 0){
		HI_INFO_VENC("enable regulator failed\n", __func__);
		return HI_FAILURE;
	}

	HI_DBG_VENC("exit %s ()\n", __func__);
	return HI_SUCCESS;
}

HI_VOID VENC_DRV_BoardDeinit(HI_VOID)
{
	HI_DBG_VENC("enter %s ()\n", __func__);
	Venc_Regulator_Disable();
	HI_DBG_VENC("exit %s ()\n", __func__);
}



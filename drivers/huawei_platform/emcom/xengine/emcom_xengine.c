#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/time.h>
#include <net/sock.h>
#include <net/tcp.h>
#include <net/ip.h>
#include <net/netlink.h>
#include <linux/skbuff.h>
#include <linux/types.h>
#include <linux/netlink.h>
#include <uapi/linux/netlink.h>
#include <linux/kthread.h>
#include "../emcom_netlink.h"
#include "../emcom_utils.h"

#ifdef CONFIG_HUAWEI_BASTET
#include <huawei_platform/power/bastet/bastet_utils.h>
#endif
#include <huawei_platform/emcom/emcom_xengine.h>
#include <linux/version.h>


#undef HWLOG_TAG
#define HWLOG_TAG emcom_xengine
HWLOG_REGIST();
MODULE_LICENSE("GPL");


#define     EMCOM_MAX_ACC_APP  (5)
#define     EMCOM_UID_ACC_AGE_MAX  (1000)

#ifdef CONFIG_HUAWEI_BASTET_COMM
	extern int bastet_comm_keypsInfo_write(uint32_t ulState);
#endif

struct Emcom_Xengine_acc_app_info     g_CurrentUids[EMCOM_MAX_ACC_APP];
/******************************************************************************
   6 函数实现
******************************************************************************/
static inline bool invalid_uid(uid_t uid)
{
	/* if uid less than 10000, it is not an Android apk */
	return (uid < UID_APP);
}

/*****************************************************************************
 函 数 名  : Emcom_Xengine_Init
 功能描述  : 初始化快抢技术相关结构体
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史  :
	1.日	期   : 2017年03月13日
	  作	者   : z00371705
	  修改内容   : 新生成函数
*****************************************************************************/
void Emcom_Xengine_Init(void)
{
	uint8_t  index;
	for( index = 0; index < EMCOM_MAX_ACC_APP; index ++)
	{
		g_CurrentUids[index].lUid = UID_INVALID_APP;
		g_CurrentUids[index].ulAge = 0;
	}
}


/*****************************************************************************
 函 数 名  : emcom_process_clear
 功能描述  : 处理上层下发的清除消息
 输入参数  :无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史  :
    1.日    期   : 2016年12月07日
       作    者   : z00371705
       修改内容   : 新生成函数

*****************************************************************************/
bool Emcom_Xengine_IsAccUid(uid_t lUid)
{
	uint8_t  index;
	for( index = 0; index < EMCOM_MAX_ACC_APP; index ++)
	{
		if( lUid == g_CurrentUids[index].lUid )
		{
			return true;
		}
	}

	return false;
}

#if defined(CONFIG_PPPOLAC) || defined(CONFIG_PPPOPNS)
/*****************************************************************************
 函 数 名  : BST_FG_Hook_Ul_Stub
 功能描述  : 勾取上行数据包
 输入参数  : struct sock *pstSock  socket对象
                           struct msghdr *msg   发送的消息结构体
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史  :
    1.日    期   : 2015年12月13日
      作    者   : z00371705
      修改内容   : 新生成函数
*****************************************************************************/

bool Emcom_Xengine_Hook_Ul_Stub(struct sock *pstSock)
{
	uid_t lSockUid = 0;
	bool  bFound   = false;

	if(( NULL == pstSock ) )
	{
		EMCOM_LOGD("Emcom_Xengine_Hook_Ul_Stub param invalid\n");
		return false;
	}

	/**
	 * if uid equals current acc uid, accelerate it,else stop it
	 */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 1, 10)
	lSockUid = sock_i_uid(pstSock).val;
#else
	lSockUid = sock_i_uid(pstSock);
#endif

	if( invalid_uid ( lSockUid ))
	{
		return false;
	}

	bFound = Emcom_Xengine_IsAccUid ( lSockUid );
	
	return bFound;
}
#endif


/*****************************************************************************
 函 数 名  : emcom_process_clear
 功能描述  : 处理上层下发的清除消息
 输入参数  :无
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史  :
    1.日    期   : 2016年12月07日
       作    者   : z00371705
       修改内容   : 新生成函数

*****************************************************************************/
int Emcom_Xengine_clear(void)
{
	uint8_t  index;
	for( index = 0; index < EMCOM_MAX_ACC_APP; index ++)
	{
		g_CurrentUids[index].lUid = UID_INVALID_APP;
		g_CurrentUids[index].ulAge = 0;
	}

	return 0;
}

/*****************************************************************************
 函 数 名  : BST_FG_StartAccUid
 功能描述  : 启动app加速
 输入参数  : uint8_t *pdata  加速的app信息
                           uint16_t len 数据长度                
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史  :
        1.日    期   : 2016年11月18日
           作    者   : z00371705
           修改内容   : 新生成函数
*****************************************************************************/

int Emcom_Xengine_StartAccUid(uint8_t *pdata, uint16_t len)
{
	uid_t              uid;
	uint8_t            index;
	uint8_t            ucIdleIndex;
	uint8_t            ucOldIndex;
	uint8_t            ucOldAge;
	bool               bFound;
	/*input param check*/
	if( NULL == pdata )
	{
		EMCOM_LOGE("Emcom_Xengine_StartAccUid:data is null");
		return -EINVAL;
	}

	/*check len is invalid*/
	if(len != sizeof(uid_t))
	{
		EMCOM_LOGI("Emcom_Xengine_StartAccUid: len:%d is illegal", len);
		return -EINVAL;
	}

	uid =*(uid_t *)pdata;
	
	/*check uid*/
	if (invalid_uid(uid))
		return -EINVAL;

	EMCOM_LOGD("Emcom_Xengine_StartAccUid: uid:%d ready to added", uid);
	ucIdleIndex = EMCOM_MAX_ACC_APP;
	ucOldIndex  = EMCOM_MAX_ACC_APP;
	ucOldAge    = 0;
	bFound  = false;
	
	/*check whether has the same uid, and  record the first idle position and the oldest position*/
	for( index = 0; index < EMCOM_MAX_ACC_APP; index ++)
	{	
		if( UID_INVALID_APP == g_CurrentUids[index].lUid )
		{
			if( EMCOM_MAX_ACC_APP == ucIdleIndex )
			{
				ucIdleIndex  = index;
			}
		}
		else if( uid == g_CurrentUids[index].lUid )
		{
			g_CurrentUids[index].ulAge = 0;
			bFound = true;
		}
		else
		{
			g_CurrentUids[index].ulAge ++;
			if( g_CurrentUids[index].ulAge > ucOldAge )
			{
				ucOldAge    = g_CurrentUids[index].ulAge;
				ucOldIndex  = index ;
			}
				
		}
	}
	
	/*remove the too old acc uid*/
	if(ucOldAge  > EMCOM_UID_ACC_AGE_MAX )
	{
		EMCOM_LOGD("Emcom_Xengine_StartAccUid: uid:%d added too long, remove it", g_CurrentUids[ucOldIndex].lUid );
		g_CurrentUids[ucOldIndex].ulAge = 0;
		g_CurrentUids[ucOldIndex].lUid  = UID_INVALID_APP;
	}
	
	EMCOM_LOGD("Emcom_Xengine_StartAccUid: ucIdleIndex=%d,ucOldIndex=%d,ucOldAge=%d",ucIdleIndex, ucOldIndex,ucOldAge);
	
	/*if has already added, return*/
	if(bFound)
	{
		EMCOM_LOGD("Emcom_Xengine_StartAccUid: uid:%d already added", uid);
		return 0;
	}
	
	/*if it is new uid, and has idle position , add it*/
	if( ucIdleIndex < EMCOM_MAX_ACC_APP )
	{
		EMCOM_LOGD("Emcom_Xengine_StartAccUid: uid:%d added", uid);
		g_CurrentUids[ucIdleIndex].ulAge = 0;
		g_CurrentUids[ucIdleIndex].lUid = uid;
		return 0;
	}

	
	/*if it is new uid, and acc list if full , replace the oldest*/
	if( ucOldIndex < EMCOM_MAX_ACC_APP )
	{
		EMCOM_LOGD("Emcom_Xengine_StartAccUid: uid:%d replace the oldest uid:%d", uid,g_CurrentUids[ucOldIndex].lUid);
		g_CurrentUids[ucOldIndex].ulAge = 0;
		g_CurrentUids[ucOldIndex].lUid = uid;
		return 0;
	}
	
	return 0;
}


/*****************************************************************************
 函 数 名  : Emcom_Xengine_StopAccUid
 功能描述  : 停止APP加速
 输入参数  : uint8_t *pdata  停止加速的app信息
                           uint16_t len 数据长度               
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史  :
        1.日    期   : 2016年11月18日
           作    者   : z00371705
           修改内容   : 新生成函数
*****************************************************************************/

int Emcom_Xengine_StopAccUid(uint8_t *pdata, uint16_t len)
{
	uid_t              uid;
	uint8_t            index;

	/*input param check*/	
	if( NULL == pdata )
	{
		EMCOM_LOGE("Emcom_Xengine_StopAccUid:data is null");
		return -EINVAL;
	}
	
	/*check len is invalid*/
	if(len != sizeof(uid_t))
	{
		EMCOM_LOGI("Emcom_Xengine_StopAccUid: len：%d is illegal", len);
		return -EINVAL;
	}
	
	uid =*(uid_t *)pdata;
	
	/*check uid*/
	if (invalid_uid(uid))
		return -EINVAL;

	/*remove specify uid*/
	for( index = 0; index < EMCOM_MAX_ACC_APP; index ++)
	{
		if( uid == g_CurrentUids[index].lUid )
		{
			g_CurrentUids[index].ulAge = 0;
			g_CurrentUids[index].lUid  = UID_INVALID_APP;
			EMCOM_LOGD("Emcom_Xengine_StopAccUid:lUid:%d",uid);
			break;
		}
	}

	return 0;
}


/*****************************************************************************
 函 数 名  : Emcom_Xengine_RrcKeep
 功能描述  : 通知bastet做 RRC加速
 输入参数  : uint8_t *pdata  停止加速的app信息
                           uint16_t len 数据长度               
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史  :
        1.日    期   : 2016年11月18日
           作    者   : z00371705
           修改内容   : 新生成函数
*****************************************************************************/

int Emcom_Xengine_RrcKeep( void )
{	
#ifdef CONFIG_HUAWEI_BASTET
	post_indicate_packet(BST_IND_RRC_KEEP,NULL,0);
#endif
	return 0;
}


/*****************************************************************************
 函 数 名  : Emcom_Send_KeyPsInfo
 功能描述  : emcom xengine 收到damone消息的参数传递给bastet
 输入参数  : uint8_t *pdata  消息的参数
             uint16_t len 数据长度
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史  :
        1.日    期   : 2017年06月30日
           作    者   : l00416134
           修改内容   : 新生成函数
*****************************************************************************/

int Emcom_Send_KeyPsInfo(uint8_t *pdata, uint16_t len)
{
	uint32_t            ulState;

	/*input param check*/
	if( NULL == pdata )
	{
		EMCOM_LOGE("Emcom_Send_KeyPsInfo:data is null");
		return -EINVAL;
	}

	/*check len is invalid*/
	if( len < sizeof( uint32_t ) )
	{
		EMCOM_LOGE("Emcom_Send_KeyPsInfo: len：%d is illegal", len);
		return -EINVAL;
	}

	ulState =*(uint32_t *)pdata;

	if( true != Emcom_Is_Modem_Support() )
	{
		EMCOM_LOGI( "Emcom_Send_KeyPsInfo: modem not support" );
		return -EINVAL;
	}

#ifdef CONFIG_HUAWEI_BASTET_COMM
	bastet_comm_keypsInfo_write( ulState );
#endif
	return 0;
}

/*****************************************************************************
 函 数 名  : Emcom_Xengine_EvtProc
 功能描述  :emcom xengine 收到deamon的消息处理入口
 输入参数  : int32_t event   处理事件
                           uint8_t *pdata  事件的参数
                           uint16_t len 数据长度               
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史  :
        1.日    期   : 2017年03月18日
           作    者   : z00371705
           修改内容   : 新生成函数
*****************************************************************************/

void Emcom_Xengine_EvtProc(int32_t event, uint8_t *pdata, uint16_t len)
{
	switch(event)
	{
		case NETLINK_EMCOM_DK_START_ACC:
			EMCOM_LOGD("emcom netlink receive acc start\n");
			Emcom_Xengine_StartAccUid(pdata,len);
			break;
		case NETLINK_EMCOM_DK_STOP_ACC:
			EMCOM_LOGD("emcom netlink receive acc stop\n");
			Emcom_Xengine_StopAccUid(pdata,len);
			break;
		case NETLINK_EMCOM_DK_CLEAR:
			EMCOM_LOGD("emcom netlink receive clear info\n");
			Emcom_Xengine_clear();
			break;
		case NETLINK_EMCOM_DK_RRC_KEEP:
			EMCOM_LOGD("emcom netlink receive rrc keep\n");
			Emcom_Xengine_RrcKeep();
			break;
		case NETLINK_EMCOM_DK_KEY_PSINFO:
			EMCOM_LOGD("emcom netlink receive psinfo\n");
			Emcom_Send_KeyPsInfo(pdata,len);
			break;
		default:
			EMCOM_LOGI("emcom Xengine unsupport packet, the type is %d.\n", event);
			break;
	}
}




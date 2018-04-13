/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/semaphore.h>
#include <linux/errno.h>
#include <linux/delay.h>
#include <linux/mm.h>
#include <linux/mman.h>
//#include "bsp_socp.h"
#include <linux/fs.h>
#include "osl_thread.h"
#include "bsp_slice.h"
#include "socp_balong.h"
#include "deflate.h"
#include "bsp_rfile.h"

#define SOCP_DEFLATE_DEST_CHAN_0      SOCP_CHAN_DEF(SOCP_CODER_DEST_CHAN, 0)
#define SOCP_DEFLATE_DEST_CHAN_1      SOCP_CHAN_DEF(SOCP_CODER_DEST_CHAN, 1)
#define SOCP_DEFLATE_DEST_CHAN_2      SOCP_CHAN_DEF(SOCP_CODER_DEST_CHAN, 2)
#define SOCP_DEFLATE_DEST_CHAN_3      SOCP_CHAN_DEF(SOCP_CODER_DEST_CHAN, 3)
#define SOCP_DEFLATE_DEST_CHAN_4      SOCP_CHAN_DEF(SOCP_CODER_DEST_CHAN, 4)
#define SOCP_DEFLATE_DEST_CHAN_5      SOCP_CHAN_DEF(SOCP_CODER_DEST_CHAN, 5)
#define SOCP_DEFLATE_DEST_CHAN_6      SOCP_CHAN_DEF(SOCP_CODER_DEST_CHAN, 6)

extern struct deflate_ctrl_info g_strDeflateCtrl;
static BSP_BOOL g_bInit = BSP_FALSE;
char file_path_0[128];
u32 g_compress_flag=0;

#define DEFLATE_VIRT_TO_PHYS(virt) virt_to_phys((void*)virt)
#define DEFLATE_PHYS_TO_VIRT(phy)  (void *)(phys_to_virt((unsigned long)phy))

#define SOC_DEFLATE_CODER_SRC_CHAN                 0x00
#define SOC_DEFLATE_CHAN_DEF(chan_type, chan_id)   ((chan_type<<16)|chan_id)

#define    DEFLATE_CODER_SRC_0       SOC_DEFLATE_CHAN_DEF(SOC_DEFLATE_CODER_SRC_CHAN,0) /* OM命令响应(A核) */
#define    DEFLATE_CODER_SRC_1       SOC_DEFLATE_CHAN_DEF(SOC_DEFLATE_CODER_SRC_CHAN,1)  /* BSP OM通道(A核) */
#define    DEFLATE_CODER_SRC_2       SOC_DEFLATE_CHAN_DEF(SOC_DEFLATE_CODER_SRC_CHAN,2) /* OM诊断消息(A核,高优先级) */
#define    DEFLATE_CODER_SRC_3       SOC_DEFLATE_CHAN_DEF(SOC_DEFLATE_CODER_SRC_CHAN,3)  /* OM诊断消息(A核,低优先级) */
#define    DEFLATE_CODER_SRC_4       SOC_DEFLATE_CHAN_DEF(SOC_DEFLATE_CODER_SRC_CHAN,4) /* OM诊断消息(C核,高优先级) */
#define    DEFLATE_CODER_SRC_5       SOC_DEFLATE_CHAN_DEF(SOC_DEFLATE_CODER_SRC_CHAN,5)  /* OM诊断消息(C核,低优先级) */
#define    DEFLATE_CODER_SRC_6       SOC_DEFLATE_CHAN_DEF(SOC_DEFLATE_CODER_SRC_CHAN,6)  /* OM命令响应(C核) */
#define    DEFLATE_CODER_SRC_7       SOC_DEFLATE_CHAN_DEF(SOC_DEFLATE_CODER_SRC_CHAN,7)  /* 保留 */

BSP_S32 DEV_SOCP_INIT()
do{
    if(!g_bInit)
    {
        if(BSP_OK != socp_init())
        {
            deflate_printf("init fail...\n");
            return BSP_ERROR;
        }
        g_bInit = BSP_TRUE;
    }
}while(0)

BSP_S32 DEV_DEFLATE_INIT()
do{
    if(!g_bInit)
    {
        if(DEFLATE_OK != deflate_init())
        {
            deflate_printf("init fail...\n");
            return BSP_ERROR;
        }
        g_bInit = BSP_TRUE;
    }
}while(0)


BSP_S32 CHECK_DEFLATE_RET(a, b)
do{
    BSP_S32 x;
    x = a;
    if(x != b)
    {
        deflate_printf("%s(%d): ret(0x%x) error...\n", __FUNCTION__, __LINE__, x);
        return x;
    }
}while(0)

unsigned long long g_deflate_dma_test_mask=0xffffffffULL;
#define DEFLATE_TEST_FLUSH_CACHE(ptr, size)                      \
    do{                                                 \
        struct device dev;                              \
        memset(&dev,0,sizeof(struct device));           \
        dev.dma_mask = (unsigned long long *)(&g_deflate_dma_test_mask);    \
        dma_map_single(&dev, ptr, size, DMA_TO_DEVICE);  \
    }while(0)
#define DEFLATE_TEST_INVALID_CACHE(ptr, size)                    \
    do{                                                 \
        struct device dev;                              \
        memset(&dev,0,sizeof(struct device));           \
        dev.dma_mask = (unsigned long long *)(&g_deflate_dma_test_mask);    \
        dma_map_single(&dev, ptr, size, DMA_FROM_DEVICE);  \
    }while(0)

u32 g_ulDeflateDelay = 100;
extern BSP_S32 socp_init(void);
extern BSP_S32 deflate_init(void);
//extern BSP_S32 socp_get_index(u32 u32Size,u32 *index);
BSP_U32 g_SocpDeflateBufCnt = 0;
BSP_U8  *g_pSocpDeflateBuf[1000];
//u32 g_ul_event_flag = false;
typedef struct tagDEFLATE_ST_CASE_S{
    BSP_U32                 bDstSet;
    BSP_U32                 SrcCh;
    BSP_U32                 DstCh;
    BSP_U32                 u32BypassEn;
    SOCP_DATA_TYPE_ENUM_UIN32        eDataType;
    SOCP_ENCSRC_CHNMODE_ENUM_UIN32   eMode;
    SOCP_CHAN_PRIORITY_ENUM_UIN32    ePriority;
 //#if(FEATURE_ON == FEATURE_SOCP_ADDR_64BITS)
 //   unsigned long           InputStart; 
 //#else   
    BSP_U32                 u32InputStart;
// #endif
    BSP_U32                 u32InputSize;
    BSP_U32                 u32RDStart;
    BSP_U32                 u32RDSize;
    BSP_U32                 u32RDThreshold;
// #if(FEATURE_ON == FEATURE_SOCP_ADDR_64BITS)
//    unsigned                OutputStart;
// #else
    BSP_U32                 u32OutputStart;
// #endif
    BSP_U32                 u32OutputSize;
    BSP_U32                 u32Threshold;
    socp_event_cb           EventCb;
    socp_read_cb            ReadCb;
    socp_rd_cb              RdCb;
    //BSP_U32                 TaskId;
    struct task_struct*    TaskId;
    BSP_U32                 u32DataLen;
    BSP_U32                 u32DataCnt;
    SOCP_DATA_TYPE_EN_ENUM_UIN32     eDataTypeEn;
    SOCP_ENC_DEBUG_EN_ENUM_UIN32     eEncDebugEn;
    BSP_U32                 u32EncDstThrh;
}DEFLATE_ST_CASE_S;


 
BSP_S32 SocpDeflateStEventCB_1(BSP_U32 u32ChanID, SOCP_EVENT_ENUM_UIN32 u32Event, BSP_U32 u32Param)
{
    BSP_U32 u32ChanType =  SOCP_REAL_CHAN_TYPE(u32ChanID);
    BSP_U32 u32ChanId   =  SOCP_REAL_CHAN_ID(u32ChanID);

    //g_ul_event_flag = true;

    switch(u32Event)
    {
        case SOCP_EVENT_PKT_HEADER_ERROR:
        {
            socp_printf("chan type is [%d], id is [%d], event is packet header check error!\n", u32ChanType, u32ChanId);
            break;
        }
        case SOCP_EVENT_OUTBUFFER_OVERFLOW:
        {
            socp_printf("chan type is [%d], id is [%d], event is outbuffer overflow!\n", u32ChanType, u32ChanId);
            break;
        }
        case SOCP_EVENT_HDLC_HEADER_ERROR:
        {
            socp_printf("chan type is [%d], id is [%d], event is 0x7e error!\n", u32ChanType, u32ChanId);
            break;
        }
        case SOCP_EVENT_CRC_ERROR:
        {
            socp_printf("chan type is [%d], id is [%d], event is crc error!\n", u32ChanType, u32ChanId);
            break;
        }
        case SOCP_EVENT_PKT_LENGTH_ERROR:
        {
            socp_printf("chan type is [%d], id is [%d], event is pkt length error!\n", u32ChanType, u32ChanId);
            break;
        }
        case SOCP_EVENT_DATA_TYPE_ERROR:
        {
            socp_printf("chan type is [%d], id is [%d], event is data type error!\n", u32ChanType, u32ChanId);
            break;
        }
        case SOCP_EVENT_DECODER_UNDERFLOW:
        {
            socp_printf("chan type is [%d], id is [%d], event is inbuf underflow error!\n", u32ChanType, u32ChanId);
            break;
        }
        case SOCP_EVENT_OUTBUFFER_THRESHOLD_OVERFLOW:
        {
            socp_printf("chan type is [%d], id is [%d], event is outbuffer threshold overflow error!\n", u32ChanType, u32ChanId);
            break;
        }
         case DEFLATE_EVENT_WORK_ABORT:
        {
            socp_printf("chan type is [%d], id is [%d], event is deflate work abort!\n", u32ChanType, u32ChanId);
            break;
        }
        case DEFLATE_EVENT_OVERFLOW :

        {
            socp_printf("chan type is [%d], id is [%d], event is deflate overflow error!\n", u32ChanType, u32ChanId);
            break;
        }
       case DEFLATE_EVENT_THRESHOLD_OVERFLOW:

        {
            socp_printf("chan type is [%d], id is [%d], event is deflate threshold overflow error!\n", u32ChanType, u32ChanId);
            break;
        }
        default:
        {
            socp_printf("the event:0x%x is valid!\n", u32Event);
            return BSP_ERROR;
        }

    }

    return BSP_OK;
}


BSP_S32 SocpDeflateStReadCB_1(BSP_U32 u32ChanID)
{
    BSP_U32 len;
    SOCP_BUFFER_RW_STRU Buffer;
    //int i;
    CHECK_DEFLATE_RET(bsp_socp_get_read_buff(u32ChanID, &Buffer), BSP_OK);
   
    len = Buffer.u32Size + Buffer.u32RbSize;  
    deflate_printf("func: SocpStReadCB_1: chan[0x%x] get data len=[%d]\n", u32ChanID, len);
    
    CHECK_DEFLATE_RET(bsp_socp_read_data_done(u32ChanID, len), BSP_OK);
    return 0;
}
BSP_S32 SocpDeflateStRdCB_1(BSP_U32 u32ChanID)
{
    BSP_U32 len;
    SOCP_BUFFER_RW_STRU Buffer;

    CHECK_DEFLATE_RET(bsp_socp_get_rd_buffer(u32ChanID, (SOCP_BUFFER_RW_STRU *)&Buffer), BSP_OK);
    len = Buffer.u32Size + Buffer.u32RbSize;
    deflate_printf("%d chan[0x%x] get RD len=[%d]\n", __LINE__, u32ChanID, len);

    CHECK_DEFLATE_RET(bsp_socp_read_rd_done(u32ChanID, len), BSP_OK);


    return 0;
}

BSP_S32 socp_enc_dst_data_save_cb(u32 chanid)
{
    SOCP_BUFFER_RW_STRU Buffer;
    int fd;
    int ret;
    int len;
    CHECK_DEFLATE_RET(bsp_socp_get_read_buff(chanid,&Buffer), BSP_OK);
    if(1== g_compress_flag)
    {
        fd=bsp_open(file_path_0,O_CREAT|O_RDWR|O_SYNC|O_APPEND,0660);
        if(fd < 0)
        {
            deflate_printf("create file %s failed\n","modem_log/drv/enc.bin");
            return fd;
        }
        bsp_lseek(fd,0,SEEK_END);
        if(Buffer.u32Size && Buffer.pBuffer)
        {
            ret=bsp_write(fd, phys_to_virt((unsigned long)Buffer.pBuffer),Buffer.u32Size);
            if(ret!=Buffer.u32Size)
            {
                deflate_printf("write data len error!0x%x 0x%x\n",ret,Buffer.u32Size);
                bsp_close(fd);
                (void)bsp_socp_read_data_done(chanid,Buffer.u32RbSize+Buffer.u32Size);
                return ret;
            }           
        }
        if(Buffer.u32RbSize && Buffer.pRbBuffer)
        {
            ret=bsp_write(fd, phys_to_virt((unsigned long)Buffer.pRbBuffer),Buffer.u32RbSize);
            if(ret!=Buffer.u32RbSize)
            {
                deflate_printf("write data len error!0x%x 0x%x\n",ret,Buffer.u32RbSize);
                bsp_close(fd);
                (void)bsp_socp_read_data_done(chanid,Buffer.u32RbSize+Buffer.u32Size);
                return ret;
            }           
        }
        (void)bsp_socp_read_data_done(chanid,Buffer.u32RbSize+Buffer.u32Size);
        bsp_close(fd);
        }
    else
    {
        len = Buffer.u32Size + Buffer.u32RbSize;  
        
        CHECK_DEFLATE_RET(bsp_socp_read_data_done(chanid,len), BSP_OK);
    }
    return 0;
        
}
BSP_VOID* TM_deflate_malloc(BSP_U32 u32Size)
{
    BSP_U8 *pItem= NULL;
    BSP_U32 index = 0;

    if(BSP_OK != socp_get_index(u32Size,&index))
    {   
        deflate_printf("get index failed\n");
        return BSP_NULL;
    }

    index = 4;
    /* 分配内存 */
    pItem = (BSP_U8*)__get_free_pages(GFP_KERNEL,index);
    if(!pItem)
    {
        deflate_printf("malloc failed\n");
        return BSP_NULL;
    }

    return (void*)pItem;
}
BSP_S32 TM_deflate_free(BSP_VOID* pMem)
{
    BSP_U32 *pItem;

    pItem = pMem;

    (void)free_pages((unsigned long)pItem,4);
    return BSP_OK;
}

BSP_S32 SocpDeflateStSetEncDst(DEFLATE_ST_CASE_S *pCase)
{
    SOCP_CODER_DEST_CHAN_S EncDstAttr;

    if(!pCase->bDstSet)
    {
        BSP_U8 *p;

//        p = (BSP_U8*)memalign(8, pCase->u32OutputSize);
        //p = (BSP_U8*)cacheDmaMalloc(pCase->u32OutputSize);
        //p = kmalloc(pCase->u32OutputSize, GFP_KERNEL);

        p = (BSP_U8*)TM_deflate_malloc(pCase->u32OutputSize);

        deflate_printf("kmalloc succussed 0x%x\n", p);

        if(BSP_NULL == p)
        {
            deflate_printf("%s[%d] SET ENC DST FAILED!\n", __FUNCTION__, __LINE__);
            return BSP_ERROR;
        }
//#if(FEATURE_ON == FEATURE_SOCP_ADDR_64BITS)
//        pCase->OutputStart = (uintptr_t)p;
//#else
        pCase->u32OutputStart = (uintptr_t)p;
//#endif
       
        g_pSocpDeflateBuf[g_SocpDeflateBufCnt++] = p;

        EncDstAttr.sCoderSetDstBuf.pucOutputStart =(unsigned  char*)DEFLATE_VIRT_TO_PHYS(p);
        EncDstAttr.sCoderSetDstBuf.pucOutputEnd =(unsigned  char* )(DEFLATE_VIRT_TO_PHYS(p) + pCase->u32OutputSize - 1);
        EncDstAttr.sCoderSetDstBuf.u32Threshold = pCase->u32Threshold;
        EncDstAttr.u32EncDstThrh = pCase->u32EncDstThrh;

       // g_socpRxTotal[pCase->DstCh&0xf] = 0;

        //CHECK_RET(bsp_socp_coder_set_dest_chan_attr(pCase->DstCh, &EncDstAttr), BSP_OK);
        if(BSP_OK != bsp_socp_coder_set_dest_chan_attr(pCase->DstCh, &EncDstAttr))
        {
            TM_deflate_free(g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);
            deflate_printf("set enc dst channel failed!\n");

            return BSP_ERROR;
        }
        pCase->bDstSet = BSP_TRUE;        

        return BSP_OK;
    }
    else
    {
        deflate_printf("set enc dst channel failed, the channel has been set!\n");
        return BSP_ERROR;
    }
}
DEFLATE_ST_CASE_S g_stDeflateCase0 =
    {
      
        0,DEFLATE_CODER_SRC_0 , SOCP_DEFLATE_DEST_CHAN_1, 0, SOCP_DATA_TYPE_0, SOCP_ENCSRC_CHNMODE_CTSPACKET, SOCP_CHAN_PRIORITY_0,
        0, 0x2000, 0, 0x40, 5, 0, 0x2000, 1, SocpDeflateStEventCB_1, SocpDeflateStReadCB_1, SocpDeflateStRdCB_1, 0,0x400, 100, SOCP_DATA_TYPE_EN,
        SOCP_ENC_DEBUG_DIS, 2048
    };
 DEFLATE_ST_CASE_S g_stDeflateCase1 =
    {
      
        0, DEFLATE_CODER_SRC_1, SOCP_DEFLATE_DEST_CHAN_1, 0, SOCP_DATA_TYPE_0, SOCP_ENCSRC_CHNMODE_CTSPACKET, SOCP_CHAN_PRIORITY_0,
        0, 0x2000, 0, 0x40, 5, 0, 0x2000, 1, SocpDeflateStEventCB_1, SocpDeflateStReadCB_1, SocpDeflateStRdCB_1, 0,0x40, 10, SOCP_DATA_TYPE_EN,
        SOCP_ENC_DEBUG_DIS, 2048
    };
  DEFLATE_ST_CASE_S g_stDeflateCase2 =
    {
        
        0, DEFLATE_CODER_SRC_2, SOCP_DEFLATE_DEST_CHAN_2, 0, SOCP_DATA_TYPE_0, SOCP_ENCSRC_CHNMODE_CTSPACKET, SOCP_CHAN_PRIORITY_0,
        0, 0x2000, 0, 0x40, 5, 0, 0x2000, 1, SocpDeflateStEventCB_1, SocpDeflateStReadCB_1, SocpDeflateStRdCB_1, 0,0x400, 100, SOCP_DATA_TYPE_EN,
        SOCP_ENC_DEBUG_DIS, 2048
    };
  DEFLATE_ST_CASE_S g_stDeflateCase3 =
    {
        
        0, DEFLATE_CODER_SRC_3, SOCP_DEFLATE_DEST_CHAN_3, 0, SOCP_DATA_TYPE_0, SOCP_ENCSRC_CHNMODE_CTSPACKET, SOCP_CHAN_PRIORITY_0,
        0, 0x2000, 0, 0x40, 5, 0, 0x2000, 1, SocpDeflateStEventCB_1, SocpDeflateStReadCB_1, SocpDeflateStRdCB_1, 0,0x40, 10, SOCP_DATA_TYPE_EN,
        SOCP_ENC_DEBUG_DIS, 2048
    };
   DEFLATE_ST_CASE_S g_stDeflateCase4 =
    {
        
        0, DEFLATE_CODER_SRC_4, SOCP_DEFLATE_DEST_CHAN_4, 0, SOCP_DATA_TYPE_0, SOCP_ENCSRC_CHNMODE_CTSPACKET, SOCP_CHAN_PRIORITY_0,
        0, 0x2000, 0, 0x40, 5, 0, 0x2000, 1, SocpDeflateStEventCB_1, SocpDeflateStReadCB_1, SocpDeflateStRdCB_1, 0,0x40, 10, SOCP_DATA_TYPE_EN,
        SOCP_ENC_DEBUG_DIS, 2048
    };
   DEFLATE_ST_CASE_S g_stDeflateCase5 =
    {
        
        0, DEFLATE_CODER_SRC_5, SOCP_DEFLATE_DEST_CHAN_5, 0, SOCP_DATA_TYPE_0, SOCP_ENCSRC_CHNMODE_CTSPACKET, SOCP_CHAN_PRIORITY_0,
        0, 0x2000, 0, 0x40, 5, 0, 0x2000, 1, SocpDeflateStEventCB_1, SocpDeflateStReadCB_1, SocpDeflateStRdCB_1, 0,0x400, 100, SOCP_DATA_TYPE_EN,
        SOCP_ENC_DEBUG_DIS, 2048
    };
typedef struct
{
    BSP_U8   usSId;
    BSP_U8   usSSId;
    BSP_U8   ucServiceSessionId;
    BSP_U8   ucMsgType;
    BSP_U32  ulMsgTransId;
    BSP_U8   aucTimeData[8];
} DEFLATE_PACKET_HEAD_S;

BSP_S32 SocpDeflateStAllocEncSrc(DEFLATE_ST_CASE_S *pCase)
{
    SOCP_CODER_SRC_CHAN_S EncSrcAttr;
    BSP_U8 *p;
    BSP_U8 *pRd = 0;
    deflate_printf("%d,inputsize!\n",pCase->u32InputSize);
    p = (BSP_U8*)TM_deflate_malloc(pCase->u32InputSize);

    if(BSP_NULL == p)
    {
        deflate_printf("%s[%d] ALLOC ENC SRC FAILED!\n", __FUNCTION__, __LINE__);
        return BSP_ERROR;
    }
//#if(FEATURE_ON == FEATURE_SOCP_ADDR_64BITS)
//   pCase->InputStart = (uintptr_t)p;
//#else
    pCase->u32InputStart = (uintptr_t)p;
//#endif
    g_pSocpDeflateBuf[g_SocpDeflateBufCnt++] = p;

    if(pCase->eMode == SOCP_ENCSRC_CHNMODE_LIST)
    {
        pRd = (BSP_U8*)TM_deflate_malloc(pCase->u32RDSize);
        if(BSP_NULL == pRd)
        {
            deflate_printf("%s[%d] ALLOC ENC SRC RD BUF FAILED!\n", __FUNCTION__, __LINE__);
            TM_deflate_free(g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);
            return BSP_ERROR;
        }
        pCase->u32RDStart = (uintptr_t)pRd;
        g_pSocpDeflateBuf[g_SocpDeflateBufCnt++] = pRd;
    }

    //pCase->u32InputStart = (uintptr_t)p;
    EncSrcAttr.eDataType = pCase->eDataType;
    EncSrcAttr.eDataTypeEn = pCase->eDataTypeEn;
    EncSrcAttr.eDebugEn = pCase->eEncDebugEn;
    EncSrcAttr.eMode = pCase->eMode;
    EncSrcAttr.ePriority = pCase->ePriority;
    EncSrcAttr.u32BypassEn = pCase->u32BypassEn;
    EncSrcAttr.u32DestChanID = pCase->DstCh;
    EncSrcAttr.sCoderSetSrcBuf.pucInputStart = (unsigned char*)(DEFLATE_VIRT_TO_PHYS(p));
    EncSrcAttr.sCoderSetSrcBuf.pucInputEnd = (unsigned char*)(DEFLATE_VIRT_TO_PHYS(p) + pCase->u32InputSize - 1);
    if(pCase->eMode == SOCP_ENCSRC_CHNMODE_LIST)
    {
        EncSrcAttr.sCoderSetSrcBuf.pucRDStart =(unsigned char*)( DEFLATE_VIRT_TO_PHYS(pRd));
        EncSrcAttr.sCoderSetSrcBuf.pucRDEnd = (unsigned char*)(DEFLATE_VIRT_TO_PHYS(pRd) + pCase->u32RDSize - 1);
        EncSrcAttr.sCoderSetSrcBuf.u32RDThreshold = pCase->u32Threshold;
    }

    if(BSP_OK != bsp_socp_coder_set_src_chan(pCase->SrcCh, &EncSrcAttr))
    {
        TM_deflate_free(g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);
        TM_deflate_free(g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);

        deflate_printf("alloc enc src channel failed!\n");

        return BSP_ERROR;
    }

    return 0;
}
BSP_VOID SocpDeflateStGenPayLoad(BSP_U8 *pBuff, BSP_U32 u32DataLen)
{
    BSP_U32 ulTime = 0;
    BSP_U32 ulTime1 = 0;
    DEFLATE_PACKET_HEAD_S * pstSocpPackt = (DEFLATE_PACKET_HEAD_S*)pBuff;
    int i;

    /* 组包SOCP */
    ulTime                           = 0x08070605;
    ulTime1                           = 0x0d0c0b0a;
    pstSocpPackt->usSId              = 1;
    pstSocpPackt->usSSId             = 2;
    pstSocpPackt->ucServiceSessionId = 3;
    pstSocpPackt->ucMsgType          = 4;
    memcpy(pstSocpPackt->aucTimeData, &ulTime, 4);
    memcpy(pstSocpPackt->aucTimeData + 4, &ulTime1, 4);
    pstSocpPackt->ulMsgTransId = 100;
    //pBuff += 16;
    for(i=0; i<(int)u32DataLen; i++)
    {
        //pBuff[i] = i%0xff;
        //pBuff[i] = 0xA5;
        pBuff[i] = i&0xff;
    }

    return;
}
BSP_VOID SocpDeflateStGenPkt(BSP_U8 *pBuff, BSP_U32 u32DataLen)
{
    BSP_U32 *pWord;

    pBuff[0] = 0x49;
    pBuff[1] = 0x53;
    pBuff[2] = 0x49;
    pBuff[3] = 0x48;
    /*
    pBuff[0] = 0x48;
    pBuff[1] = 0x49;
    pBuff[2] = 0x53;
    pBuff[3] = 0x49;
    */
    pWord = (BSP_U32*)(pBuff+4);
    pWord[0] = u32DataLen;
    //pBuff += 8;

    //SocpStGenPayLoad((pBuff+8), u32DataLen-16);
    SocpDeflateStGenPayLoad((pBuff+8), u32DataLen);

    return;
}
BSP_VOID SocpDeflateStGenPayLoad2(BSP_U8 *pBuff, BSP_U32 u32DataLen)
{
    BSP_U32 ulTime = 0;
    BSP_U32 ulTime1 = 0;
    DEFLATE_PACKET_HEAD_S * pstSocpPackt = (DEFLATE_PACKET_HEAD_S*)pBuff;
    int i;

    /* 组包SOCP */
    ulTime                           = 0x08070605;
    ulTime1                           = 0x0d0c0b0a;
    pstSocpPackt->usSId              = 1;
    pstSocpPackt->usSSId             = 2;
    pstSocpPackt->ucServiceSessionId = 3;
    pstSocpPackt->ucMsgType          = 4;
    memcpy(pstSocpPackt->aucTimeData, &ulTime, 4);
    memcpy(pstSocpPackt->aucTimeData + 4, &ulTime1, 4);
    pstSocpPackt->ulMsgTransId = 100;
    //pBuff += 16;
    for(i=0; i<(int)u32DataLen; i++)
    {
        //pBuff[i] = i%0xff;
        //pBuff[i] = 0xA5;
        pBuff[i] = 88;
    }

    return;
}
BSP_VOID SocpDeflateStGenPkt2(BSP_U8 *pBuff, BSP_U32 u32DataLen)
{
    BSP_U32 *pWord;

    pBuff[0] = 0x49;
    pBuff[1] = 0x53;
    pBuff[2] = 0x49;
    pBuff[3] = 0x48;
    /*
    pBuff[0] = 0x48;
    pBuff[1] = 0x49;
    pBuff[2] = 0x53;
    pBuff[3] = 0x49;
    */
    pWord = (BSP_U32*)(pBuff+4);
    pWord[0] = u32DataLen;
    //pBuff += 8;

    //SocpStGenPayLoad((pBuff+8), u32DataLen-16);
    SocpDeflateStGenPayLoad2((pBuff+8), u32DataLen);

    return;
}
u32 deflate_flag = 0;
BSP_S32 socp_deflate_task_001(BSP_VOID *param)
{
    DEFLATE_ST_CASE_S *pCase = (DEFLATE_ST_CASE_S*)param;
    int len = pCase->u32DataLen + 8;
    BSP_U8* packet;
    SOCP_BUFFER_RW_STRU WtBuff;
    int vfcnt = 0;

    packet = (BSP_U8*)TM_deflate_malloc(len);
    if(!packet)
    {
        deflate_printf("%s(%d): malloc faile chan=0x%x len=0x%x\n", __FUNCTION__, __LINE__, pCase->SrcCh, len);
        return -1;
    }
    SocpDeflateStGenPkt(packet, pCase->u32DataLen);
    DEFLATE_TEST_FLUSH_CACHE(packet, pCase->u32DataLen);

    while(1)
    {
        CHECK_DEFLATE_RET(bsp_socp_get_write_buff(pCase->SrcCh, &WtBuff), BSP_OK);
        if(WtBuff.u32Size + WtBuff.u32RbSize >= (u32)len)
        {
            if(WtBuff.u32Size >= (u32)len)
            {
                memcpy((BSP_U8*)DEFLATE_PHYS_TO_VIRT(WtBuff.pBuffer), packet, len);
                DEFLATE_TEST_FLUSH_CACHE(DEFLATE_PHYS_TO_VIRT(WtBuff.pBuffer), len);
            }
            else
            {
                memcpy((BSP_U8*)DEFLATE_PHYS_TO_VIRT(WtBuff.pBuffer), packet, WtBuff.u32Size);
                memcpy((BSP_U8*)DEFLATE_PHYS_TO_VIRT(WtBuff.pRbBuffer), packet+WtBuff.u32Size, len-WtBuff.u32Size);
                DEFLATE_TEST_FLUSH_CACHE(DEFLATE_PHYS_TO_VIRT(WtBuff.pBuffer), WtBuff.u32Size);
                DEFLATE_TEST_FLUSH_CACHE(DEFLATE_PHYS_TO_VIRT(WtBuff.pRbBuffer), len-WtBuff.u32Size);
            }

            CHECK_DEFLATE_RET(bsp_socp_write_done(pCase->SrcCh, len), BSP_OK);
        }
        else
        {
            vfcnt++;
            msleep(g_ulDeflateDelay);
        }

        if(vfcnt > 0x0FFFFFFF)
        {
            deflate_printf(" socp_encode_task_stress_001 break!\n");
            break;
        }
        msleep(g_ulDeflateDelay);

        if(deflate_flag){
            TM_deflate_free(packet);
            return 0;
        }
    }
    TM_deflate_free(packet);
    return 0;
}
BSP_S32 socp_deflate_task_002(BSP_VOID *param)
{
    DEFLATE_ST_CASE_S *pCase = (DEFLATE_ST_CASE_S*)param;
    int len = pCase->u32DataLen + 8;
    BSP_U8* packet;
    SOCP_BUFFER_RW_STRU WtBuff;
    int vfcnt = 0;

    packet = (BSP_U8*)TM_deflate_malloc(len);
    if(!packet)
    {
        deflate_printf("%s(%d): malloc faile chan=0x%x len=0x%x\n", __FUNCTION__, __LINE__, pCase->SrcCh, len);
        return -1;
    }
    SocpDeflateStGenPkt2(packet, pCase->u32DataLen);
    DEFLATE_TEST_FLUSH_CACHE(packet, pCase->u32DataLen);

    while(1)
    {
        CHECK_DEFLATE_RET(bsp_socp_get_write_buff(pCase->SrcCh, &WtBuff), BSP_OK);
        if(WtBuff.u32Size + WtBuff.u32RbSize >= (u32)len)
        {
            if(WtBuff.u32Size >= (u32)len)
            {
                memcpy((BSP_U8*)DEFLATE_PHYS_TO_VIRT(WtBuff.pBuffer), packet, len);
                DEFLATE_TEST_FLUSH_CACHE(DEFLATE_PHYS_TO_VIRT(WtBuff.pBuffer), len);
            }
            else
            {
                memcpy((BSP_U8*)DEFLATE_PHYS_TO_VIRT(WtBuff.pBuffer), packet, WtBuff.u32Size);
                memcpy((BSP_U8*)DEFLATE_PHYS_TO_VIRT(WtBuff.pRbBuffer), packet+WtBuff.u32Size, len-WtBuff.u32Size);
                DEFLATE_TEST_FLUSH_CACHE(DEFLATE_PHYS_TO_VIRT(WtBuff.pBuffer), WtBuff.u32Size);
                DEFLATE_TEST_FLUSH_CACHE(DEFLATE_PHYS_TO_VIRT(WtBuff.pRbBuffer), len-WtBuff.u32Size);
            }

            CHECK_DEFLATE_RET(bsp_socp_write_done(pCase->SrcCh, len), BSP_OK);
        }
        else
        {
            vfcnt++;
            msleep(g_ulDeflateDelay);
        }

        if(vfcnt > 0x0FFFFFFF)
        {
            deflate_printf(" socp_encode_task_stress_001 break!\n");
            break;
        }
        msleep(g_ulDeflateDelay);

        if(deflate_flag){
            TM_deflate_free(packet);
            return 0;
        }
    }
    TM_deflate_free(packet);
    return 0;
}

/*多个源通道对应同一目的通道*/
BSP_S32 SOCP_DEFLATE_ST_001_START(void)
{
    char taskName[30] = {0};
    DEFLATE_ST_CASE_S *pCase0 = &g_stDeflateCase0;
    DEFLATE_ST_CASE_S *pCase1 = &g_stDeflateCase1;
    DEV_SOCP_INIT();
    DEV_DEFLATE_INIT();

    memset(file_path_0,0,sizeof(file_path_0));
    snprintf(file_path_0,sizeof(file_path_0),"/modem_log/drv/%s_0x%x.bin",__func__,bsp_get_slice_value());
    CHECK_DEFLATE_RET(SocpDeflateStAllocEncSrc(pCase0), BSP_OK); 
    CHECK_DEFLATE_RET(SocpDeflateStAllocEncSrc(pCase1), BSP_OK); 
    
    CHECK_DEFLATE_RET(SocpDeflateStSetEncDst(pCase1), BSP_OK); 
    CHECK_DEFLATE_RET(bsp_socp_register_event_cb(pCase1->DstCh, pCase1->EventCb), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_register_read_cb(pCase1->DstCh, socp_enc_dst_data_save_cb), BSP_OK);
    deflate_printf("0x%x!\n",pCase0->SrcCh );
    deflate_printf("0x%x!\n",pCase1->DstCh);
    bsp_socp_compress_enable(pCase0->DstCh);
    CHECK_DEFLATE_RET(bsp_socp_start(pCase0->SrcCh), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_start(pCase1->SrcCh), BSP_OK);
   
    pCase0->TaskId = kthread_run(socp_deflate_task_001,  (BSP_VOID*)(pCase0), taskName);
    if(IS_ERR(pCase0->TaskId))
    {
    
        deflate_printf(" socp_deflate_st_stress_001 break!\n");
        return BSP_ERROR;
        
    }
    pCase1->TaskId = kthread_run(socp_deflate_task_002,  (BSP_VOID*)(pCase1), taskName);
    
    if(IS_ERR(pCase1->TaskId))
    {
    
        deflate_printf(" socp_deflate_st_stress_002 break!\n");
        return BSP_ERROR;
        
    }
    return 0;
}
BSP_S32 SOCP_DEFLATE_ST_001_STOP(void)
{
    CHECK_DEFLATE_RET(bsp_socp_stop(g_stDeflateCase0.SrcCh), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_free_channel(g_stDeflateCase0.SrcCh), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_stop(g_stDeflateCase1.SrcCh), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_free_channel(g_stDeflateCase1.SrcCh), BSP_OK);
    TM_deflate_free( g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);      //源内存0
    TM_deflate_free( g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);      //目的内存0
    TM_deflate_free( g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);      //源内存1
    TM_deflate_free( g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);      //目的内存1
       /*释放任务*/
    if(g_stDeflateCase0.TaskId)
    {
       g_stDeflateCase0.TaskId=NULL; 
    }
   
    return 0;
}
/*32k压缩,阈值中断*/
BSP_S32 SOCP_DEFLATE_ST_002(void)
{
    char taskName[30] = {0};
    DEFLATE_ST_CASE_S *pCase = &g_stDeflateCase2;
    DEV_SOCP_INIT();
    DEV_DEFLATE_INIT();
    g_compress_flag=1;
    memset(file_path_0,0,sizeof(file_path_0));
//    snprintf(file_path,sizeof(file_path),"/modem_log/drv/%s_0x%x.bin",__func__,bsp_get_slice_value());
    snprintf(file_path_0,sizeof(file_path_0),"/modem_log/drv/%s",__func__);
    CHECK_DEFLATE_RET(SocpDeflateStAllocEncSrc(pCase), BSP_OK); 
    CHECK_DEFLATE_RET(SocpDeflateStSetEncDst(pCase), BSP_OK); 
    CHECK_DEFLATE_RET(bsp_socp_register_event_cb(pCase->DstCh, pCase->EventCb), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_register_read_cb(pCase->DstCh, socp_enc_dst_data_save_cb), BSP_OK);   
    deflate_printf("0x%x!\n",pCase->SrcCh );
    deflate_printf("0x%x!\n",pCase->DstCh);
    bsp_socp_compress_enable(pCase->DstCh);
    CHECK_DEFLATE_RET(bsp_socp_start(pCase->SrcCh), BSP_OK);
   
    pCase->TaskId = kthread_run(socp_deflate_task_002,  (BSP_VOID*)(pCase), taskName);
    if(IS_ERR(pCase->TaskId))
    {
    
        deflate_printf(" socp_deflate_st_002 break!\n");
        return BSP_ERROR;
        
    }
    msleep(30000);
    return 0;
}

/*压缩转非压缩切换*/
BSP_S32 SOCP_DEFLATE_ST_003(void)
{   

    DEFLATE_ST_CASE_S *pCase = &g_stDeflateCase2;
    DEV_SOCP_INIT();
    DEV_DEFLATE_INIT();
    g_compress_flag=0;
    CHECK_DEFLATE_RET(bsp_socp_register_read_cb(pCase->DstCh, socp_enc_dst_data_save_cb), BSP_OK);   
    bsp_socp_compress_disable(pCase->DstCh);
    msleep(30000);
    return 0;
  
}
/*非压缩转压缩*/
BSP_S32 SOCP_DEFLATE_ST_004(void)
{   
    DEFLATE_ST_CASE_S *pCase = &g_stDeflateCase2;
    DEV_SOCP_INIT();
    DEV_DEFLATE_INIT();
    g_compress_flag=1;
    CHECK_DEFLATE_RET(bsp_socp_register_read_cb(pCase->DstCh, socp_enc_dst_data_save_cb), BSP_OK);   
    bsp_socp_compress_enable(pCase->DstCh);
    msleep(30000);
    return 0;
  
}

BSP_S32 SOCP_DEFLATE_ST_004_STOP(void)
{
    
    CHECK_DEFLATE_RET(bsp_socp_stop(g_stDeflateCase2.SrcCh), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_free_channel(g_stDeflateCase2.SrcCh), BSP_OK);
 
    TM_deflate_free( g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);      //源内存2
    TM_deflate_free( g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);      //目的内存2
       /*释放任务*/
      /*释放任务*/
    if(g_stDeflateCase2.TaskId)
    {
       g_stDeflateCase2.TaskId=NULL; 
    }
   
    return 0; 
}
/*数据不到32k,ibuf 超时压缩;目的端数据量不够阈值，传输超时中断*/
BSP_S32 SOCP_DEFLATE_ST_005_START(void)
{
    char taskName[30] = {0};
    DEFLATE_ST_CASE_S *pCase = &g_stDeflateCase3;
    DEV_SOCP_INIT();
    DEV_DEFLATE_INIT();
    g_compress_flag=1;
    memset(file_path_0,0,sizeof(file_path_0));
    snprintf(file_path_0,sizeof(file_path_0),"/modem_log/drv/%s_0x%x.bin",__func__,bsp_get_slice_value());
    CHECK_DEFLATE_RET(SocpDeflateStAllocEncSrc(pCase), BSP_OK); 
    CHECK_DEFLATE_RET(SocpDeflateStSetEncDst(pCase), BSP_OK); 
    CHECK_DEFLATE_RET(bsp_socp_register_event_cb(pCase->DstCh, pCase->EventCb), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_register_read_cb(pCase->DstCh, socp_enc_dst_data_save_cb), BSP_OK);
    deflate_printf("0x%x!\n",pCase->SrcCh );
    deflate_printf("0x%x!\n",pCase->DstCh);
    bsp_socp_compress_enable(pCase->DstCh);
    CHECK_DEFLATE_RET(bsp_socp_start(pCase->SrcCh), BSP_OK);
   
    pCase->TaskId = kthread_run(socp_deflate_task_001,  (BSP_VOID*)(pCase), taskName);
    
    if(IS_ERR(pCase->TaskId))
    {
    
        deflate_printf(" socp_deflate_st_003 break!\n");
        return BSP_ERROR;
        
    }
    return 0;
}
BSP_S32 SOCP_DEFLATE_ST_005_STOP(void)
{
    
    CHECK_DEFLATE_RET(bsp_socp_stop(g_stDeflateCase3.SrcCh), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_free_channel(g_stDeflateCase3.SrcCh), BSP_OK);
 
    TM_deflate_free( g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);      //源内存3
    TM_deflate_free( g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);      //目的内存3
       /*释放任务*/
    if(g_stDeflateCase3.TaskId)
    {
       g_stDeflateCase3.TaskId=NULL; 
    }
   
    return 0;
}
/*bypass模式*/
BSP_S32 SOCP_DEFLATE_ST_006_START(void)
{
    char taskName[30] = {0};
    DEFLATE_ST_CASE_S *pCase = &g_stDeflateCase4;
    DEV_SOCP_INIT();
    DEV_DEFLATE_INIT();
    g_compress_flag=1;
    memset(file_path_0,0,sizeof(file_path_0));
    snprintf(file_path_0,sizeof(file_path_0),"/modem_log/drv/%s_0x%x.bin",__func__,bsp_get_slice_value());
    DEFLATE_REG_SETBITS(SOCP_REG_DEFLATE_GLOBALCTRL, 0, 1, 1);
    CHECK_DEFLATE_RET(SocpDeflateStAllocEncSrc(pCase), BSP_OK); 
    CHECK_DEFLATE_RET(SocpDeflateStSetEncDst(pCase), BSP_OK); 
    CHECK_DEFLATE_RET(bsp_socp_register_event_cb(pCase->DstCh, pCase->EventCb), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_register_read_cb(pCase->DstCh, socp_enc_dst_data_save_cb), BSP_OK);
    deflate_printf("0x%x!\n",pCase->SrcCh );
    deflate_printf("0x%x!\n",pCase->DstCh);
    bsp_socp_compress_enable(pCase->DstCh);
    CHECK_DEFLATE_RET(bsp_socp_start(pCase->SrcCh), BSP_OK);
   
    pCase->TaskId = kthread_run(socp_deflate_task_002,  (BSP_VOID*)(pCase), taskName);
    
    if(IS_ERR(pCase->TaskId))
    {
    
        deflate_printf(" socp_deflate_st_005 break!\n");
        return BSP_ERROR;
        
    }
    return 0;
}
BSP_S32 SOCP_DEFLATE_ST_006_STOP(void)
{
    
    CHECK_DEFLATE_RET(bsp_socp_stop(g_stDeflateCase4.SrcCh), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_free_channel(g_stDeflateCase4.SrcCh), BSP_OK);
 
    TM_deflate_free( g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);      //源内存4
    TM_deflate_free( g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);      //目的内存4
       /*释放任务*/
   if(g_stDeflateCase4.TaskId)
    {
       g_stDeflateCase4.TaskId=NULL; 
    }
   
    return 0;
}
/*按包压缩*/
BSP_S32 SOCP_DEFLATE_ST_007_START(void)
{
    char taskName[30] = {0};
    //DEFLATE_ST_CASE_S *pCase1 = &g_stDeflateCase1;
    DEFLATE_ST_CASE_S *pCase = &g_stDeflateCase5;
    DEV_SOCP_INIT();
    DEV_DEFLATE_INIT();
    memset(file_path_0,0,sizeof(file_path_0));
    snprintf(file_path_0,sizeof(file_path_0),"/modem_log/drv/%s_0x%x.bin",__func__,bsp_get_slice_value());
    DEFLATE_REG_SETBITS(SOCP_REG_DEFLATE_GLOBALCTRL, 18, 1, 1);
    CHECK_DEFLATE_RET(SocpDeflateStAllocEncSrc(pCase), BSP_OK); 
   
    CHECK_DEFLATE_RET(SocpDeflateStSetEncDst(pCase), BSP_OK); 
    CHECK_DEFLATE_RET(bsp_socp_register_event_cb(pCase->DstCh, pCase->EventCb), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_register_read_cb(pCase->DstCh, socp_enc_dst_data_save_cb), BSP_OK);
    deflate_printf("0x%x!\n",pCase->SrcCh );
    deflate_printf("0x%x!\n",pCase->DstCh);
    bsp_socp_compress_enable(pCase->DstCh);
    CHECK_DEFLATE_RET(bsp_socp_start(pCase->SrcCh), BSP_OK);
   
    pCase->TaskId = kthread_run(socp_deflate_task_002,  (BSP_VOID*)(pCase), taskName);
    
    if(IS_ERR(pCase->TaskId))
    {
    
        deflate_printf(" socp_deflate_st_006 break!\n");
        return BSP_ERROR;
        
    }
    return 0;
}
BSP_S32 SOCP_DEFLATE_ST_007_STOP(void)
{
    
    CHECK_DEFLATE_RET(bsp_socp_stop(g_stDeflateCase5.SrcCh), BSP_OK);
    CHECK_DEFLATE_RET(bsp_socp_free_channel(g_stDeflateCase5.SrcCh), BSP_OK);
 
    TM_deflate_free( g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);      //源内存5
    TM_deflate_free( g_pSocpDeflateBuf[--g_SocpDeflateBufCnt]);      //目的内存5
       /*释放任务*/
   if(g_stDeflateCase5.TaskId)
    {
       g_stDeflateCase5.TaskId=NULL; 
    }
   
    return 0;
}
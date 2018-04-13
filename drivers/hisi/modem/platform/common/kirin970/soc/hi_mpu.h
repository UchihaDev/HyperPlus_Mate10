#ifndef __HI_MPU_H__
#define __HI_MPU_H__ 
#include <product_config.h>
#include <osl_printf.h>
#define SIZE_8M 0x800000
#define SIZE_32M 0x2000000
#define SIZE_VECTOR CCPU_ITCM_SIZE
extern int ioremap_readonly(void* phy_addr, unsigned int len,void* virt_addr);
static inline void text_protect_cfg(void)
{
    int ret = 0;
    unsigned long virt_addr=0;
    #ifdef CONFIG_CCPU_HAS_TCM
    ret = ioremap_readonly((void*)CCPU_ITCM_ADDR,SIZE_VECTOR,(void*)&virt_addr);
    if(ret==BSP_ERROR)
    {
        osl_printf("text protect failed 3\n");
    }
    #endif
    ret = ioremap_readonly((void*)DDR_MCORE_ADDR,SIZE_32M,(void*)&virt_addr);
    if(ret==BSP_ERROR)
    {
        osl_printf("text protect failed 1\n");
    }
    ret = ioremap_readonly((void*)DDR_MCORE_ADDR+SIZE_32M,SIZE_8M,(void*)&virt_addr);
    if(ret==BSP_ERROR)
    {
        osl_printf("text protect failed 2\n");
    }
}
#ifndef SZ_64M
#define SZ_64M (0x04000000)
#endif
#ifndef SZ_8K
#define SZ_8K (0x2000)
#endif
#ifdef MODEM_SANITIZER
    #define DDR_ATTRIBUTE (MPU_READ_WRTER | MPU_NOEXE|MPU_MEM_NOCACHEABLE| MPU_SHAREABLE)
    #define MPU_MDM_EXE_SIZE DDR_MCORE_SIZE
    #define sanitizer_map(index) \
                (void)mpu_region_cfg(index++, MDM_SANTIZIER_MEM_ADDR, MPU_REGION_64M, MPU_READ_WRTER | MPU_EXE |MPU_MEM_CACHEABLE |MPU_SHAREABLE)
#else
    #define MPU_MDM_EXE_SIZE (DDR_MCORE_SIZE - DDR_MCORE_UNCACHE_SIZE)
    #define DDR_ATTRIBUTE (MPU_STRONGLY_ORDER)
    #define sanitizer_map(index) (void)mpu_region_cfg(index++, 0x1FF00100, MPU_REGION_256B, MPU_READ_ONlY);
#endif
#define SHARE_DDR_SIZE SZ_64M
#define platform_mpu_init(index) \
do{\
 (void)mpu_region_cfg(index++, 0x00000000, MPU_REGION_4G, DDR_ATTRIBUTE);\
 (void)mpu_region_cfg(index++, 0x00000000, MPU_REGION_32K, MPU_READ_WRTER | MPU_EXE | MPU_MEM_NOCACHEABLE );\
 (void)mpu_region_cfg(index++, CCPU_DTCM_ADDR, MPU_REGION_16K, MPU_READ_WRTER | MPU_NOEXE | MPU_MEM_NOCACHEABLE );\
 (void)mpu_region_cfg(index++, DDR_MEM_ADDR, MPU_REGION_256M, MPU_READ_WRTER | MPU_NOEXE |MPU_MEM_NOCACHEABLE);\
 (void)mpu_region_cfg(index++, 0xE0000000, MPU_REGION_512M, MPU_READ_WRTER | MPU_NOEXE | MPU_DEVICE |MPU_SHAREABLE);\
 (void)mpu_region_cfg(index++, CCPU_LLRAM_BASE_ADDR, MPU_REGION_256K, MPU_READ_WRTER | MPU_EXE | MPU_MEM_NOCACHEABLE | MPU_SHAREABLE);\
 (void)mpu_region_cfg(index++, HI_DSP_SUBSYSTEM_BASE_ADDR, MPU_REGION_16M, MPU_READ_WRTER | MPU_NOEXE|MPU_STRONGLY_ORDER | MPU_SHAREABLE);\
 (void)mpu_region_cfg(index++, 0x10000000, MPU_REGION_128M, MPU_READ_WRTER | MPU_NOEXE|MPU_MEM_NOCACHEABLE| MPU_SHAREABLE); \
 sanitizer_map(index);\
}while(0)
#endif

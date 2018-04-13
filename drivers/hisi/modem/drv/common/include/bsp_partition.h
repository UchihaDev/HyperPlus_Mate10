#ifndef __BSP_PARTITION_H__
#define __BSP_PARTITION_H__
#include <product_config.h>

#define PART_MAGIC                     0x54524150
#define PART_NAMELEN                   (16)
#define TOTAL_PART_NUM                 (130) /* just all partitions info */
#define MAX_PART_NUM                   (TOTAL_PART_NUM + 1) /* also contain end flag */
#define BLOCK_SIZE_BYTE                (512)

struct partition {
	char name[PART_NAMELEN];
	unsigned int start;
	unsigned int length;
	unsigned int flags;
};
/*
bit0 : 0x0 - USER_PART
       0x1 - BOOT_PART
bit1 : 0x0 - NOOOB_BURN
       0x1 - OOB_BURN
*/
#if defined(CONFIG_EMMC_BOOT)
#define	USER_PART  0x0
#define	BOOT_PART  0x1
#define OOB_BURN   0x0
#elif defined(CONFIG_UBIFS_BOOT)
#define	USER_PART  0x0
#define	BOOT_PART  0x0
#define OOB_BURN   0x0
#else
#define	USER_PART  0x0
#define	BOOT_PART  0x0
#define OOB_BURN   0x2
#endif
struct partition_head {
    unsigned int magic;
    unsigned int crc;
    unsigned int npart;
    struct partition part[0];
};

int partition_init(void);
struct partition* find_partition(const char *name);
struct partition* find_partition_by_index(unsigned int index);
struct partition* find_last_partition(void);
int get_partition_property(const char *name, unsigned int *property);

#endif

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
#include <linux/mtd/mtd.h>
#include <linux/err.h>
#include <linux/vmalloc.h>
#include <ptable_com.h>

struct rw_ops_para {
    u32 rwsize;
    u32 retlen;
    u32 start_offset;
    u32 data_len;
    u32 remainder;
    u8 *data_buf;
    u8 *tmp_buf;
};

enum {
    FMC_READ = 0,
    FMC_WRITE,
};
/*****************************************************************************
* 函数  : bsp_blk_get_cdromiso_blkname
* 功能  : 获取包含cdromiso 分区的mtd块号的完整路径
* 输入  : 无
* 输出  : 完整路径名存放到blk_path中
* 返回  : 0成功，非0失败
*****************************************************************************/
#define MIN_BUF_LENGTH 128
int bsp_blk_get_cdromiso_blkname(char *blk_path, int len)
{
	int ret = 0;
	struct mtd_info *mtd = NULL;

	if(!blk_path || len < MIN_BUF_LENGTH)
	{
		printk(KERN_ERR"%s para err, %d\n", __func__, len);
		return -EINVAL;
	}

	mtd = get_mtd_device_nm(PTABLE_CDROMISO_NM);
	if (IS_ERR(mtd))
	{
		printk(KERN_ERR"%s :get_mtd_device_nm(%s) error.\n", __func__, PTABLE_CDROMISO_NM);
		return PTR_ERR(mtd);
	}

	snprintf(blk_path, MIN_BUF_LENGTH - 1, "/dev/block/mtdblock%d", mtd->index);
	put_mtd_device(mtd);
	return ret;
}
void fmc_rw_ops_para_set(struct rw_ops_para *fmc_rw_ops_para, u32 rwsize, u32 start_offset,
    u32 data_len, u32 remainder, u8 *data_buf, u8 *tmp_buf)
{
    fmc_rw_ops_para->rwsize = rwsize;
    fmc_rw_ops_para->start_offset = start_offset;
    fmc_rw_ops_para->data_buf = data_buf;

    fmc_rw_ops_para->tmp_buf = tmp_buf;
    fmc_rw_ops_para->remainder = remainder;
    fmc_rw_ops_para->data_len = data_len;
}

#define FMC_BAD_BLK 0x12121212
int fmc_erase_ops(struct mtd_info *mtd, u64 addr)
{
    int ret = 0;
	struct erase_info instr = {0};

	instr.mtd = mtd;
	instr.addr = addr;
	instr.len = mtd->erasesize;
	instr.retries = 2;
	instr.callback = NULL;
	instr.priv = 0;

	ret = mtd_erase(mtd, &instr);
	if(ret)
	{
		printk(KERN_ERR"%s :mtd_erase error, it's going to markbad. ret = %d, fail_addr = 0x%x\n", __func__ , ret , (u32)instr.fail_addr);
		ret = mtd_block_markbad(mtd, (long long)instr.addr);
		if(ret)
		{
			printk(KERN_ERR"%s :mtd_block_markbad error. ret = %d\n", __func__ , ret);
			return -1;
		}
		else
		{
			return FMC_BAD_BLK;
		}
	}
    return 0;
}

int fmc_write_ops(struct mtd_info *mtd, struct rw_ops_para *p)
{
	int ret = 0;
	size_t retlen = 0;
	long long addrblockalign = 0;
	unsigned char *buffer = NULL;

	addrblockalign = (long long)(div_u64(p->start_offset, mtd->erasesize) * mtd->erasesize);
	if((addrblockalign != p->start_offset) || (p->data_len < mtd->erasesize))
	{
		ret = mtd_read(mtd, addrblockalign, mtd->erasesize, &retlen, p->tmp_buf);
		if((ret && ret != -EUCLEAN) || (retlen != mtd->erasesize))
		{
		    printk(KERN_ERR"%s :mtd read error, ret = %d. retlen = %ld\n", __func__ , ret , (unsigned long)retlen);
		    return ret;
		}

		memcpy(p->tmp_buf + p->remainder, p->data_buf, p->rwsize);
		buffer = p->tmp_buf;
	}
	else
	{
		buffer = p->data_buf;
	}

	ret = fmc_erase_ops(mtd, addrblockalign);
	if(ret)
		return ret;

	ret = mtd_write(mtd, addrblockalign, mtd->erasesize, &retlen, (unsigned char*)buffer);
	if(ret || (retlen != mtd->erasesize))
	{
		printk(KERN_ERR"%s :mtd_write error, it's going to markbad.ret = %d, retlen = %ld\n", __func__ , ret , (unsigned long)retlen);
		ret = mtd_block_markbad(mtd, addrblockalign);
		if(ret)
		{
			printk(KERN_ERR"%s :mtd_block_markbad error. ret = %d\n", __func__ , ret);
			return ret;
		}
		else
			return FMC_BAD_BLK;
	}

	return 0;
}
int fmc_read_ops(struct mtd_info *mtd, struct rw_ops_para *p)
{
    int ret;
    size_t retlen = 0;
    ret = mtd_read(mtd, (long long)p->start_offset, p->rwsize, &retlen, p->data_buf);
    if((ret && ret != -EUCLEAN) || (retlen != p->rwsize))
    {
		printk(KERN_ERR"%s :mtd read error, ret = %d, retlen = %d, rwsize = %ld\n", __func__ , ret , (unsigned long)retlen, p->rwsize);
		return ret;
    }
    return 0;
}
int fmc_read_write_ops(struct mtd_info *mtd, u32 part_offset, void *data_addr, u32 data_len, u8 * tmp_buf, u32 ops_type)
{
    int ret = 0;
    u32 remainder = 0, rwsize = 0;
    u32 start_offset = 0, start_blknum = 0;
    unsigned char *data_buf = NULL;
    struct rw_ops_para fmc_rw_ops_para = {0};

    start_blknum = div_u64_rem(part_offset, mtd->erasesize, &start_offset);
	data_buf = data_addr;
	while(data_len > 0)
	{
		if(start_offset >= mtd->size)
		{
			printk(KERN_ERR"%s :partition offset 0x%x beyond partition\n", __func__ , start_offset);
			return -EINVAL;
		}

		div_u64_rem(start_offset, mtd->erasesize, &remainder);
		ret = mtd_block_isbad(mtd, (long long)(start_offset - remainder));
		if (ret)
		{
			printk(KERN_ERR"%s :bad block detected, partition offset 0x%x\n", __func__ , start_offset - remainder);
			start_offset += mtd->erasesize;
            continue;
		}

		if(0 != start_blknum) {
			start_offset += mtd->erasesize;
			start_blknum--;
			continue;
		}

        rwsize = (remainder + data_len < mtd->erasesize) ? data_len : (mtd->erasesize - remainder);

        fmc_rw_ops_para_set(&fmc_rw_ops_para, rwsize, start_offset, data_len, remainder, data_buf, tmp_buf);

        if(FMC_READ == ops_type)
            ret = fmc_read_ops(mtd, &fmc_rw_ops_para);
        else if(FMC_WRITE == ops_type)
            ret = fmc_write_ops(mtd, &fmc_rw_ops_para);
        if(ret == FMC_BAD_BLK){
            //start_offset = fmc_rw_ops_para.start_offset;
            start_offset += mtd->erasesize;
            continue;
        }
        else if(ret)
        {
            printk(KERN_ERR"%s:fmc read write failed, ops 0x%x \n", __func__, ops_type);
            return ret;
        }

        start_offset += rwsize;
		data_len -= rwsize;
		data_buf += rwsize;
     }

    return 0;
}

int bsp_blk_read(const char *partition_name, loff_t partition_offset, void* data_addr, size_t data_len)
{
    int ret = 0;
    struct mtd_info *mtd = NULL;

	if((!partition_name) || (!data_addr))
	{
		printk(KERN_ERR"%s :para error\n", __func__);
		return -EINVAL;
	}

	mtd = get_mtd_device_nm(partition_name);
	if (IS_ERR(mtd))
	{
		printk(KERN_ERR"%s :get_mtd_device_nm(%s) error\n", __func__ ,partition_name);
		return PTR_ERR(mtd);
	}

    ret = fmc_read_write_ops(mtd, partition_offset, data_addr, data_len, NULL, FMC_READ);
	put_mtd_device(mtd);
	return ret;
}
int bsp_blk_write(const char *partition_name, loff_t partition_offset, void* data_addr, size_t data_len)
{
    int ret = 0;
    struct mtd_info *mtd = NULL;
    unsigned char *tmp_buf = NULL;

	if((!partition_name) || (!data_addr))
	{
		printk(KERN_ERR"%s :para error\n", __func__);
		return -EINVAL;
	}

	mtd = get_mtd_device_nm(partition_name);
	if (IS_ERR(mtd))
	{
		printk(KERN_ERR"%s :get_mtd_device_nm(%s) error\n", __func__ ,partition_name);
		return PTR_ERR(mtd);
	}

	tmp_buf = (unsigned char *)vmalloc(mtd->erasesize);
	if(!tmp_buf)
	{
		printk(KERN_ERR"%s :vmalloc failed!\n", __func__);
		return -ENOMEM;
	}

    ret = fmc_read_write_ops(mtd, partition_offset, data_addr, data_len, tmp_buf, FMC_WRITE);

	if(tmp_buf)
	{
		vfree(tmp_buf);
	}

	put_mtd_device(mtd);
	return ret;
}

/*****************************************************************************
* 函数  : bsp_blk_erase
* 功能  : 擦除指定分区的数据
* 输入  : 分区名
* 输出  : 无
* 返回  : 0成功，非0失败
*****************************************************************************/
int bsp_blk_erase(const char *partition_name) // not outstanding code, change??
{
	int ret = 0;
    u64 count = 0;
	struct mtd_info *mtd = NULL;

	if(!partition_name)
	{
		printk(KERN_ERR"%s :para err.\n", __func__);
		return -EINVAL;
	}

	mtd = get_mtd_device_nm(partition_name);
	if (IS_ERR(mtd))
	{
		printk(KERN_ERR"%s :get_mtd_device_nm(%s) error\n", __func__ ,partition_name);
		return PTR_ERR(mtd);
	}

    while(count <= (mtd->size - mtd->erasesize)){
        ret = mtd_block_isbad(mtd, (long long)(count));
        if (ret)
        {
            printk(KERN_ERR"%s :bad block detected, partition offset 0x%x\n", __func__ , (u32)count);
            count += mtd->erasesize;
            continue;
        }

        ret = fmc_erase_ops(mtd, count);
        if(ret)
        {
            printk(KERN_ERR"%s :fmc_erase_ops err, partition = %s, offset = 0x%x, ret %d\n", __func__ ,partition_name, (u32)count, ret);
            break;
        }
        count += mtd->erasesize;
	}

	put_mtd_device(mtd);
	return ret;
}

/*****************************************************************************
* 函数  : bsp_blk_isbad
* 功能  : 查询是否为坏块
* 输入  : 分区名，分区内偏移
* 输出  : 无
* 返回  : 0好块，非0坏块
*****************************************************************************/
int bsp_blk_isbad(const char *partition_name, loff_t partition_offset)
{
	int ret = 0;
	struct mtd_info *mtd = NULL;

	if(!partition_name)
	{
		printk(KERN_ERR"%s :part name error.\n",__func__);
		return -EINVAL;
	}

	mtd = get_mtd_device_nm(partition_name);
	if (IS_ERR(mtd))
	{
		printk(KERN_ERR"%s :get_mtd_device_nm(%s) error\n", __func__ ,partition_name);
		return PTR_ERR(mtd);
	}

	ret = mtd_block_isbad(mtd, (long long)partition_offset);
	if(ret < 0)
	{
		printk(KERN_ERR"%s :mtd_block_isbad error. ret = %d\n", __func__ , ret);
	}

	put_mtd_device(mtd);
	return ret;
}

/*****************************************************************************
* 函数  : bsp_blk_size
* 功能  : 获取一个分区的大小
* 输入  : part_name 分区名字
* 输出  : size  分区的大小值存放在size
* 返回  : 小于0失败，大于等于0成功
*****************************************************************************/
int bsp_blk_size(const char *part_name, u32 *size)
{
	int ret = 0;
	struct mtd_info *mtd = NULL;

	if((!part_name) || (!size))
	{
		printk(KERN_ERR"%s :param error\n",__func__);
		return -1;
	}

	mtd = get_mtd_device_nm(part_name);
	if (IS_ERR(mtd))
	{
		printk(KERN_ERR"%s :get_mtd_device_nm(%s) error\n", __func__ ,part_name);
		return PTR_ERR(mtd);
	}

	*size =(u32)mtd->size;

	put_mtd_device(mtd);
	return ret;
}


EXPORT_SYMBOL_GPL(bsp_blk_get_cdromiso_blkname);
EXPORT_SYMBOL_GPL(bsp_blk_read);
EXPORT_SYMBOL_GPL(bsp_blk_erase);
EXPORT_SYMBOL_GPL(bsp_blk_write);
EXPORT_SYMBOL_GPL(bsp_blk_isbad);
EXPORT_SYMBOL_GPL(bsp_blk_size);



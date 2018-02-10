#ifndef HISI_UFS_BKOPS_H
#define HISI_UFS_BKOPS_H
#include "ufshcd.h"

typedef int (ufs_bkops_query_fn)(struct ufs_hba *hba, u32 *status);
typedef int (ufs_bkops_start_fn)(struct ufs_hba *hba);
typedef int (ufs_bkops_stop_fn)(struct ufs_hba *hba);
struct ufs_dev_bkops_ops {
	ufs_bkops_query_fn *ufs_bkops_query;
	ufs_bkops_start_fn *ufs_bkops_start;
	ufs_bkops_stop_fn *ufs_bkops_stop;
};

#endif


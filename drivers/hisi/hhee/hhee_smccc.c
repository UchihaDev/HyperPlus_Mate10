#include <linux/arm-smccc.h>
#include <hhee.h>

struct arm_smccc_res _hhee_fn_smc(unsigned long function_id,
			unsigned long arg0, unsigned long arg1,
			unsigned long arg2)
{
	struct arm_smccc_res res;

	arm_smccc_smc(function_id, arg0, arg1, arg2, 0ul, 0ul, 0ul, 0ul, &res);
	return res;
}

struct arm_smccc_res _hhee_fn_hvc(unsigned long function_id,
			unsigned long arg0, unsigned long arg1,
			unsigned long arg2)
{
	struct arm_smccc_res res;

	arm_smccc_hvc(function_id, arg0, arg1, arg2, 0ul, 0ul, 0ul, 0ul, &res);
	return res;
}

unsigned long hhee_fn_smc(unsigned long function_id,
			unsigned long arg0, unsigned long arg1,
			unsigned long arg2)
{
	struct arm_smccc_res res;

	res = _hhee_fn_smc(function_id, arg0, arg1, arg2);
	return res.a0;
}

unsigned long hhee_fn_hvc(unsigned long function_id,
			unsigned long arg0, unsigned long arg1,
			unsigned long arg2)
{
	struct arm_smccc_res res;

	res = _hhee_fn_hvc(function_id, arg0, arg1, arg2);
	return res.a0;
}


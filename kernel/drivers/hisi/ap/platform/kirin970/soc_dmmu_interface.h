#ifndef __SOC_DMMU_INTERFACE_H__
#define __SOC_DMMU_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_DMMU_FAMA_REMAP_SRC0_ADDR(base) ((base) + (0x800))
#define SOC_DMMU_FAMA_REMAP_SRC1_ADDR(base) ((base) + (0x804))
#define SOC_DMMU_FAMA_REMAP_SRC2_ADDR(base) ((base) + (0x808))
#define SOC_DMMU_FAMA_REMAP_SRC3_ADDR(base) ((base) + (0x80C))
#define SOC_DMMU_FAMA_REMAP_SRC4_ADDR(base) ((base) + (0x810))
#define SOC_DMMU_FAMA_REMAP_SRC5_ADDR(base) ((base) + (0x814))
#define SOC_DMMU_FAMA_REMAP_SRC6_ADDR(base) ((base) + (0x818))
#define SOC_DMMU_FAMA_REMAP_SRC7_ADDR(base) ((base) + (0x81C))
#define SOC_DMMU_FAMA_REMAP_LEN0_ADDR(base) ((base) + (0x820))
#define SOC_DMMU_FAMA_REMAP_LEN1_ADDR(base) ((base) + (0x824))
#define SOC_DMMU_FAMA_REMAP_LEN2_ADDR(base) ((base) + (0x828))
#define SOC_DMMU_FAMA_REMAP_LEN3_ADDR(base) ((base) + (0x82C))
#define SOC_DMMU_FAMA_REMAP_LEN4_ADDR(base) ((base) + (0x830))
#define SOC_DMMU_FAMA_REMAP_LEN5_ADDR(base) ((base) + (0x834))
#define SOC_DMMU_FAMA_REMAP_LEN6_ADDR(base) ((base) + (0x838))
#define SOC_DMMU_FAMA_REMAP_LEN7_ADDR(base) ((base) + (0x83C))
#define SOC_DMMU_FAMA_REMAP_DST0_ADDR(base) ((base) + (0x840))
#define SOC_DMMU_FAMA_REMAP_DST1_ADDR(base) ((base) + (0x844))
#define SOC_DMMU_FAMA_REMAP_DST2_ADDR(base) ((base) + (0x848))
#define SOC_DMMU_FAMA_REMAP_DST3_ADDR(base) ((base) + (0x84C))
#define SOC_DMMU_FAMA_REMAP_DST4_ADDR(base) ((base) + (0x850))
#define SOC_DMMU_FAMA_REMAP_DST5_ADDR(base) ((base) + (0x854))
#define SOC_DMMU_FAMA_REMAP_DST6_ADDR(base) ((base) + (0x858))
#define SOC_DMMU_FAMA_REMAP_DST7_ADDR(base) ((base) + (0x85C))
#define SOC_DMMU_FAMA_REMAP_ADDR_DEFAULT_ADDR(base) ((base) + (0x860))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_SRC0_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_SRC0_icfg_addr_src0_START (0)
#define SOC_DMMU_FAMA_REMAP_SRC0_icfg_addr_src0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_SRC1_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_SRC1_icfg_addr_src1_START (0)
#define SOC_DMMU_FAMA_REMAP_SRC1_icfg_addr_src1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_SRC2_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_SRC2_icfg_addr_src2_START (0)
#define SOC_DMMU_FAMA_REMAP_SRC2_icfg_addr_src2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_SRC3_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_SRC3_icfg_addr_src3_START (0)
#define SOC_DMMU_FAMA_REMAP_SRC3_icfg_addr_src3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_SRC4_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_SRC4_icfg_addr_src4_START (0)
#define SOC_DMMU_FAMA_REMAP_SRC4_icfg_addr_src4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_SRC5_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_SRC5_icfg_addr_src5_START (0)
#define SOC_DMMU_FAMA_REMAP_SRC5_icfg_addr_src5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_SRC6_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_SRC6_icfg_addr_src6_START (0)
#define SOC_DMMU_FAMA_REMAP_SRC6_icfg_addr_src6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_SRC7_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_SRC7_icfg_addr_src7_START (0)
#define SOC_DMMU_FAMA_REMAP_SRC7_icfg_addr_src7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_LEN0_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_LEN0_icfg_addr_len0_START (0)
#define SOC_DMMU_FAMA_REMAP_LEN0_icfg_addr_len0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_LEN1_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_LEN1_icfg_addr_len1_START (0)
#define SOC_DMMU_FAMA_REMAP_LEN1_icfg_addr_len1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_LEN2_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_LEN2_icfg_addr_len2_START (0)
#define SOC_DMMU_FAMA_REMAP_LEN2_icfg_addr_len2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_LEN3_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_LEN3_icfg_addr_len3_START (0)
#define SOC_DMMU_FAMA_REMAP_LEN3_icfg_addr_len3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_LEN4_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_LEN4_icfg_addr_len4_START (0)
#define SOC_DMMU_FAMA_REMAP_LEN4_icfg_addr_len4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_LEN5_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_LEN5_icfg_addr_len5_START (0)
#define SOC_DMMU_FAMA_REMAP_LEN5_icfg_addr_len5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_LEN6_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_LEN6_icfg_addr_len6_START (0)
#define SOC_DMMU_FAMA_REMAP_LEN6_icfg_addr_len6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DMMU_FAMA_REMAP_LEN7_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_LEN7_icfg_addr_len7_START (0)
#define SOC_DMMU_FAMA_REMAP_LEN7_icfg_addr_len7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst0 : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_DMMU_FAMA_REMAP_DST0_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_DST0_icfg_addr_dst0_START (0)
#define SOC_DMMU_FAMA_REMAP_DST0_icfg_addr_dst0_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst1 : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_DMMU_FAMA_REMAP_DST1_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_DST1_icfg_addr_dst1_START (0)
#define SOC_DMMU_FAMA_REMAP_DST1_icfg_addr_dst1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst2 : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_DMMU_FAMA_REMAP_DST2_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_DST2_icfg_addr_dst2_START (0)
#define SOC_DMMU_FAMA_REMAP_DST2_icfg_addr_dst2_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst3 : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_DMMU_FAMA_REMAP_DST3_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_DST3_icfg_addr_dst3_START (0)
#define SOC_DMMU_FAMA_REMAP_DST3_icfg_addr_dst3_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst4 : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_DMMU_FAMA_REMAP_DST4_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_DST4_icfg_addr_dst4_START (0)
#define SOC_DMMU_FAMA_REMAP_DST4_icfg_addr_dst4_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst5 : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_DMMU_FAMA_REMAP_DST5_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_DST5_icfg_addr_dst5_START (0)
#define SOC_DMMU_FAMA_REMAP_DST5_icfg_addr_dst5_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst6 : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_DMMU_FAMA_REMAP_DST6_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_DST6_icfg_addr_dst6_START (0)
#define SOC_DMMU_FAMA_REMAP_DST6_icfg_addr_dst6_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst7 : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_DMMU_FAMA_REMAP_DST7_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_DST7_icfg_addr_dst7_START (0)
#define SOC_DMMU_FAMA_REMAP_DST7_icfg_addr_dst7_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_default : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_DMMU_FAMA_REMAP_ADDR_DEFAULT_UNION;
#endif
#define SOC_DMMU_FAMA_REMAP_ADDR_DEFAULT_icfg_addr_default_START (0)
#define SOC_DMMU_FAMA_REMAP_ADDR_DEFAULT_icfg_addr_default_END (6)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif

#ifndef _TYPES_H
#define _TYPES_H

#include "wordsize.h"

/* this is a special 64bit data type that is 8-byte aligned */
#define aligned_u64 __u64 __aligned(8)
#define aligned_be64 __be64 __aligned(8)
#define aligned_le64 __le64 __aligned(8)

/*
 * Below are truly Linux-specific types that should never collide with
 * any application/library that wants linux/types.h.
 */
#define __bitwise__
#define __bitwise

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint64_t __u64;
typedef int8_t __s8;
typedef int16_t __s16;
typedef int32_t __s32;
typedef int64_t __s64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef unsigned long ulong;

typedef __u16 __bitwise __le16;
typedef __u16 __bitwise __be16;
typedef __u32 __bitwise __le32;
typedef __u32 __bitwise __be32;
typedef __u64 __bitwise __le64;
typedef __u64 __bitwise __be64;
typedef __u16 __bitwise __sum16;
typedef __u32 __bitwise __wsum;

typedef unsigned __bitwise__ gfp_t;

#define DECLARE_BITMAP(name, bits) unsigned long name[BITS_TO_LONGS(bits)]

#ifdef CONFIG_PHYS_ADDR_T_64BIT
typedef u64 phys_addr_t;
#else
typedef u32 phys_addr_t;
#endif

/* From stdint.h */
/* Largest integral types.  */
#if __WORDSIZE == 64
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
#else
__extension__ typedef long long int __intmax_t;
__extension__ typedef unsigned long long int __uintmax_t;
#endif

/* Largest integral types.  */
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;

/* Types for `void *' pointers.  */
#if __WORDSIZE == 64
#ifndef __intptr_t_defined
typedef long int intptr_t;
#define __intptr_t_defined
#endif
typedef unsigned long int uintptr_t;
#else
#ifndef __intptr_t_defined
typedef int intptr_t;
#define __intptr_t_defined
#endif
typedef unsigned int uintptr_t;
#endif
/* From stdint.h */

// general define
#ifndef NULL
#define NULL 0
#endif
#define null 0

typedef uintptr_t size_t;

typedef unsigned int u_int32_t;

/* From stdbool.h */
#ifndef __cplusplus

#define bool _Bool
#define true 1
#define false 0

#else /* __cplusplus */

/* Supporting _Bool in C++ is a GCC extension.  */
#define _Bool bool

#if __cplusplus < 201103L
/* Defining these macros in C++98 is a GCC extension.  */
#define bool bool
#define false false
#define true true
#endif

#endif /* __cplusplus */
/* From stdbool.h */

/* From stddef.h */
#ifndef __PTRDIFF_TYPE__
#define __PTRDIFF_TYPE__ long int
#endif
typedef __PTRDIFF_TYPE__ ptrdiff_t;
/* From stddef.h */

/* From stdio.h */
/* The value returned by fgetc and similar functions to indicate the
   end of the file.  */
#define EOF (-1)
/* From stdio.h */

#define __packed			__attribute__((__packed__))
#define __aligned(x)			__attribute__((aligned(x)))

#define cpu_to_le16			__cpu_to_le16
#define le16_to_cpu			__le16_to_cpu
#define cpu_to_le32			__cpu_to_le32
#define le32_to_cpu			__le32_to_cpu

#define __le16_to_cpu(x)		((__le16)(x))
#define __cpu_to_le16(x)		((__u16)(x))
#define __le32_to_cpu(x)		((__le32)(x))
#define __cpu_to_le32(x)		((__u32)(x))

#endif

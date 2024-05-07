#ifndef __UTILS_H__
#define __UTILS_H__

/* number of bits in a long int. */
#define BITS_PER_LONG  (__CHAR_BIT__ * __SIZEOF_LONG__)

/* contiguous bitmask starting at bit 'h' and ending at bit 'l' */
#define GENMASK(h, l) (((~0UL) - (1UL << (l)) + 1) & (~0UL >> (BITS_PER_LONG - 1 - (h))))

/* extract the Least Significant Bit */
#define LSB_GET(value) ((value) & -(value))

/* extract a bitfield element from value corresponding to the field mask */
#define FIELD_GET(mask, value)  (((value) & (mask)) / LSB_GET(mask))

/* prepare a bitfield using the mask representing its field position and width */
#define FIELD_PREP(mask, value) (((value) * LSB_GET(mask)) & (mask))

/* prepare bit mask  */
#define BIT(n)  (1 << (n))

/* calculate number of array elements */
#define ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))

/* avoid unused variable warning */
#define UNUSED(x) ((void)(x))

/* swap 16-bits endianness */
#define BSWAP_16(x) (((x) >> 8) | ((x) << 8))

/* swap 32-bits endianness */
#define BSWAP_32(x) \
		((((x) >> 24) & 0xff)	| \
		(((x) << 8) & 0xff0000)	| \
		(((x) >> 8) & 0xff00)	| \
		(((x) << 24) & 0xff000000))

#endif

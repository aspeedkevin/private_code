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

#define BIT(n)  (1 << (n))

#define ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))

#define UNUSED(x) ((void)(x))

#endif

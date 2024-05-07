#include <ctype.h>
#include <lib/malloc.h>
#include <lib/string.h>
#include <types.h>

/**
 * @brief Count the number of leading zeros of a uint16_t
 * @param [IN] x - the uint16_t to be counted
 * @return the number of leading zeros in x
 */
int clz16(uint16_t x)
{
	int n = 0;

	if (x == 0)
		return 16;

	if (x <= 0x00ff) { n += 8; x <<= 8; }
	if (x <= 0x0fff) { n += 4; x <<= 4; }
	if (x <= 0x3fff) { n += 2; x <<= 2; }
	if (x <= 0x7fff) n += 1;

	return n;
}

int clz32(uint32_t x)
{
	int n = 0;

	if (x == 0)
		return 32;

	if (x <= 0x0000ffff) { n += 16; x <<= 16; }
	if (x <= 0x00ffffff) { n += 8; x <<= 8; }
	if (x <= 0x0fffffff) { n += 4; x <<= 4; }
	if (x <= 0x3fffffff) { n += 2; x <<= 2; }
	if (x <= 0x7fffffff) n += 1;

	return n;
}

int clz64(uint64_t x)
{
	int n = 0;

	if (x == 0)
		return 64;

	if (x <= 0x00000000ffffffff) { n += 32; x <<= 32; }
	if (x <= 0x0000ffffffffffff) { n += 16; x <<= 16; }
	if (x <= 0x00ffffffffffffff) { n += 8; x <<= 8; }
	if (x <= 0x0fffffffffffffff) { n += 4; x <<= 4; }
	if (x <= 0x3fffffffffffffff) { n += 2; x <<= 2; }
	if (x <= 0x7fffffffffffffff) n += 1;

	return n;
}

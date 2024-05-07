#ifndef __TRNG_H__
#define __TRNG_H__

#include <types.h>

uint32_t trng_rand(void);
void trng_srand(uint32_t seed);
int nisttrng_init(void);

#endif /* __TRNG_H__ */

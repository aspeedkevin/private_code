#ifndef __RAND_H__
#define __RAND_H__

#include <types.h>

#define RAND_BADNUM	0xbaadc0de

struct rng {
	uint32_t (*rand)(void);
	void (*srand)(uint32_t seed);
};

uint32_t rand(void);
void srand(uint32_t seed);
int rng_register(struct rng *rng);

#endif

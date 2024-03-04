#ifndef __MALLOC_H__
#define __MALLOC_H__

#include <lib/string.h>

void *malloc(size_t bytes);
void *memalign(size_t align, size_t bytes);
void *calloc(size_t nmemb, size_t elem_size);

#endif

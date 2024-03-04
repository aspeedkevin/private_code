#include <types.h>
#include <malloc.h>
#include <printf.h>

static uint32_t malloc_base = CONFIG_SYS_INIT_STACK_ADDR - CONFIG_SYS_MALLOC_LEN;
static uint32_t malloc_ptr = 0;
static uint32_t malloc_limit = CONFIG_SYS_INIT_STACK_ADDR;

#define __ALIGN_MASK(x, mask) (((x) + (mask)) & ~(mask))
#define ALIGN(x, a) __ALIGN_MASK((x), (unsigned long)(a)-1)

static void *alloc(size_t bytes, int align)
{
	unsigned long addr, new_ptr;
	void *ptr;

	addr = ALIGN(malloc_base + malloc_ptr, align);
	new_ptr = addr + bytes;
	if (new_ptr > malloc_limit)
		return NULL;

	ptr = (void *)addr;
	malloc_ptr = ALIGN(new_ptr, sizeof(new_ptr));
	return ptr;
}

void *malloc(size_t bytes)
{
	void *ptr;

	ptr = alloc(bytes, 1);
	return ptr;
}

void *memalign(size_t align, size_t bytes)
{
	void *ptr;

	ptr = alloc(bytes, align);
	if (!ptr)
		return ptr;

	return ptr;
}

void *calloc(size_t nmemb, size_t elem_size)
{
	size_t size = nmemb * elem_size;
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		return ptr;
	memset(ptr, '\0', size);

	return ptr;
}

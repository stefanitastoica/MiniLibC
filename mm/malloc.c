// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size == 0)
        return NULL;

    void *ptr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t mem = nmemb * size;
	void *ptr = malloc(mem);
	memset(ptr, 0, mem);
	return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	char *d = (char *)ptr - sizeof(size_t);
	size_t s = *(size_t *)d;
	return (void)s;
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	void *nptr = mmap(ptr, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	return nptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t mem = nmemb * size;
	void *nptr = mmap(ptr, mem, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	return nptr;
}

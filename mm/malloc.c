// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>


void *malloc(size_t size) {
    // use mem_list to allocate memory

    void *p = (void *)mmap(NULL, size, PROT_READ | PROT_WRITE,
                MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    mem_list_add(p, size);

    p = (void *)p;
    if (p == MAP_FAILED) {
        return NULL;  // Memory allocation failed
    }

    return p;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total = nmemb * size;
	void *p = malloc(total);

	if(p != NULL) {
		memset(p, 0, total);
	}
	return p;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
if (ptr == NULL)
        return;

    struct mem_list *item = mem_list_find(ptr);
    if (item != NULL) {
        if (munmap(ptr, item->len) == 0) {
            mem_list_del(ptr);
        }
    }
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */

	if (ptr == NULL) {
		return malloc(size);
	}

	if (size == 0) {
		return NULL;
	}

	struct mem_list *item = mem_list_find(ptr);

	if (item != NULL) {
		if (size > item->len) {
			void *new_item = malloc(size);
			if (new_item != NULL) {
				memcpy(new_item, item, item->len);
				free(item);
				}
	return new_item;
		}else {
			item->len = size;
			return item;
		}
	}
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */

	size_t total = nmemb * size;

	return realloc(ptr, total);
}

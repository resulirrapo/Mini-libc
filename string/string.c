// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	// implementation from https://stackoverflow.com/questions/14476627/strcpy-implementation-in-c
	char *dest_ptr = destination;

    while (*source != '\0')
    {
        *destination = *source;
        source++;
		destination++;
    }

    *destination = '\0';

	return dest_ptr;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *dest_ptr = destination;
	// looping through each character
	for (size_t i = 0; i < len; i++) {
		if (*source != '\0'){
		*destination = *source;
		destination++;
		source++;
	}else {
		*destination = '\0';
	}
}
	return dest_ptr;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *dest_ptr = destination;
	// going to the end of the first string
	while (*destination != '\0') {
		destination++;
	}

	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
		*destination = '\0';
	return dest_ptr;
}

char *strncat(char *destination, const char *source, size_t len) {
	/* TODO: Implement strncat(). */
	char *dest_ptr = destination;

	while(*destination != '\0') {
		destination++;
	}

	for (size_t i = 0; i < len; i++) {
		if (*source != '\0'){
			*destination = *source;
			destination++;
			source++;
		}

		*destination = '\0';
}
	return dest_ptr;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */

	while(*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

	if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
         } else if (*str1 == '\0') {
            return 0;
        }
		return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	    for (size_t i = 0; i < len; ++i) {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        } else if (*str1 == '\0') {
            return 0;
        }
    }
    return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	//  i took the implementation from itecnote.com
	 while (*str != (char) c) {
        if (!*str++) {
            return NULL;
        }
    }
    return (char *)str;
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *first_str = str;

	while (*str != '\0') {
		str++;
	}

	while (str >= first_str) {
		if(*str == (char)c) {
			return (char*)str;
		}
		str--;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
  if (*needle == '\0') {
        return (char *)haystack;
    }
	// iterating over each character
    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;
		// if h and n reaches null-terminator, increment to coompare the next pair
        while (*h && *n && *h == *n) {
            h++;
            n++;
        }
			// if it points to a null terminator means that we reached the end of a string
        if (!*n) {
            return (char *)haystack;
        }

        haystack++;
    }
    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	const char *last_ocurrence = NULL;

	if (*needle == '\0') {
        return (char *)haystack;
    }

    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && *h == *n) {
            h++;
            n++;
        }

        if (!*n) {
            last_ocurrence = haystack;
        }

        haystack++;
    }
	return (char *)last_ocurrence;
}

void *memcpy(void *destination, const void *source, size_t num) {
	/* TODO: Implement memcpy(). */
	char *destination1 = (char *) destination;
	char *source1 = (char *) source;

	for (size_t i = 0; i < num; i++) {
		destination1[i] = source1[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *destination1 = (char *) destination;
	char *source1 = (char *) source;

	char *ptr_help = (char *) destination;

	// using buffer to handle overlapping
	for (size_t i = 0; i < num; i++) {
		ptr_help[i] = source1[i];
	}

	for (size_t i = 0; i < num; i++) {
		destination1[i] = ptr_help[i];
	}

	return destination1;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *first = ptr1;
	const unsigned char *second = ptr2;

	while (num && (*first == *second)) {
		first++;
		second++;
		num--;
	}

	if (num == 0) {
		return 0;
	} else if (*first < *second) {
		return -1;
	} else {
	return 1;
	}
}


void *memset(void *source, int value, size_t num) {
	/* TODO: Implement memset(). */

	// implementation from https://aticleworld.com/memset-in-c/
	unsigned char* s = source;
	while(num--) {
		*s++ = (unsigned char) value;
	}
	return s;
}

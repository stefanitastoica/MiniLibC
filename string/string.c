// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *d;
	for (d = destination; *source != '\0'; d++, source++) {
		*d = *source;
	}
	*d = *source;
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	int i;
	int nr = (int)len;
	for (i = 0; i < nr && *source != '\0'; i++, source++, destination++)
        *destination = *source;
    while (i++ < nr) {
        *destination = '\0';}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	unsigned long len = strlen(destination);
	char *d = destination;
    d += len;
    d = strcpy(d, source);
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *d = destination;
    while (*d != '\0') {
        d++;
    }
    while (len > 0 && *source != '\0') {
        *d = *source;
		d++;
		source++;
		len--;
    }
    *d = '\0';
    return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		} else {
		str1++;
		str2++;}
	}
	if (*str1 == '\0' && *str2 != '\0')
	       return -1;
	else if (*str1 != '\0' && *str2 == '\0')
		return 1;
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (len > 0 && *str1 != '\0' && *str2 != '\0') {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		} else {
		str1++;
		str2++;
		len--;}
	}
	if (len > 0) {
	if (*str1 == '\0' && *str2 != '\0')
	       return -1;
	else if (*str1 != '\0' && *str2 == '\0')
		return 1;
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
	while (*str != '\0') {
		if (*str == c)
			return (char *)str;
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *d = NULL;
	while (*str != '\0') {
		if (*str == c)
			d = (char *)str;
		str++;
	}
	if (d != NULL)
		return d;
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	while (*haystack != '\0') {
		const char *d = haystack;
		const char *s = needle;
		while (*s != '\0' && *s == *d) {
				d++;
				s++;
		}
		const char *sol = haystack;
		if (*s == '\0')
			return (char *)sol;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *sol = NULL;
	while (*haystack != '\0') {
		const char *d = haystack;
		const char *s = needle;
		while (*s != '\0' && *s == *d) {
				d++;
				s++;
		}
		if (*s == '\0')
			sol = (char *)haystack;
		haystack++;
	}
	return sol;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *d = destination;
	const char *s = source;
	while (num > 0) {
		*d = *s;
		d++;
		s++;
		num--;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	int i;
	int nr = (int)num;
    char* d = (char*)destination;
    char* s = (char*)source;

    if (s > d)
        {for (i = 0; s[i] && i < nr; i++)
                    d[i] = s[i];}
    else if (s < d)
            {for (i = nr - 1; d[i] && i >= 0; i--)
                    d[i] = s[i];}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = (const unsigned char *)ptr1;
	const unsigned char *p2 = (const unsigned char *)ptr2;
	for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) {
			return -1;
		} else if (p1[i] > p2[i]) {
			return 1;}
    }
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *s = (char*)source;
	char v = (char)value;
	while (num > 0) {
		*s = v;
		s++;
		num--;
	}
	return source;
}

#ifndef STRING_H
#define STRING_H

#include <sys/types.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

int memcmp(const void *s1, const void *s2, size_t n);

void *memcpy(void *dst, const void *src, size_t n);

void *memmove(void *dst, const void *src, size_t n);

void *memset(void *s, int c, size_t n);

char* strcpy(char*, const char* src);

size_t strlen(const char*);

#ifdef __cplusplus
}
#endif

#endif /* STRING_H */
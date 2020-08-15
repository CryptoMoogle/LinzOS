#ifndef STDLIB_H
#define STDLIB_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

void abort(void);

int atexit(void (*)(void));
int atoi(const char*);
void free(void*);
char* getenv(const char*);
void* malloc(size_t);

#ifdef __cplusplus
}
#endif

#endif /* STDLIB_H */
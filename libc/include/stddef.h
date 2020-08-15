#ifndef STDDEF_H
#define STDDEF_H

#include <stdint.h>
#include <sys/types.h>

#if defined(__cplusplus)
#define NULL 0
#else
#define NULL ((void *)0)
#endif

#endif /* STDDEF_H */
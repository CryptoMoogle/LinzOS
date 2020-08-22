#ifndef TTY_H
#define TTY_H

#include <stddef.h>

void tty_write(const char *buf, size_t n); ///TODO add DEV select support

void tty_update(void);

#endif /* TTY_H */
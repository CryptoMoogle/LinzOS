
#include <string.h>
#include <stdarg.h>

#include "kprintf.h"
#include "driver/tty.h"

void kprint(const char *fmt, ...){

	va_list arg;

	va_start(arg, fmt);

	int n;

	n = strlen(fmt); ///TODO add vsnprintf support

	tty_write(fmt, n); ///TODO add DEV select support

	va_end(arg);

	tty_update();

}

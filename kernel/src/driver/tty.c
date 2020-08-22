
#include <stddef.h>
#include "tty.h"
#include "screen.h"

#define TTYS_TOTAL      1

static screen_t scr_table[TTYS_TOTAL];
static unsigned int tty_curr = 0;///TODO and tty change and init

static void tty_putchar(int c){

	screen_t *scr;

	scr = &scr_table[tty_curr];

	screen_putchar(scr, (char)c);

}

void tty_write(const char *buf, size_t n){ ///TODO add DEV select support

	size_t i;

	for (i = 0; i < n; i++) {
		tty_putchar(buf[i]);
	}
}

void tty_update(void){

	screen_update(&scr_table[tty_curr]);

}

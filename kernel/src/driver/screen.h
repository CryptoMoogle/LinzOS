#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>

#define SCREEN_WIDTH    80
#define SCREEN_HEIGHT   25

#define BLACK			0X0
#define BLUE			0X1
#define GREEN			0X2
#define CYAN			0X3
#define RED				0X4
#define MAGENTA			0X5
#define BROWN			0X6
#define LIGHT_GRAY		0X7
#define GRAY			0X8
#define LIGHT_BLUE		0X9
#define LIGHT_GREEN		0XA
#define LIGHT_CYAN		0XB
#define LIGHT_RED		0XC
#define LIGHT_MAGENTA	0XD
#define LIGHT_YELLOW	0XE
#define WHITE			0XF

#define DEFAULT_FOREGROUND LIGHT_GRAY
#define DEFAULT_BACKGROUND BLACK
#define DEFAULT_ATTR ((DEFAULT_FOREGROUND & 0x0F)|(DEFAULT_BACKGROUND << 4))

typedef struct screen {
	int32_t  pos_x;
	int32_t  pos_y;
	uint8_t dirty;
	char buf[SCREEN_WIDTH * SCREEN_HEIGHT];
	uint8_t attr[SCREEN_WIDTH * SCREEN_HEIGHT];
}screen_t;

void screen_update(screen_t *scr);

void screen_putchar(screen_t *scr, char c);

void console_process(screen_t *scr, char c);

void console_append(screen_t *scr, char c);

void console_newline(screen_t *scr);

void console_scroll(screen_t *scr, int lines);

#endif /* SCREEN_H */
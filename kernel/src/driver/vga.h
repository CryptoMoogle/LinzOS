#ifndef VGA_H
#define VGA_H

#include <stdint.h>

typedef uint16_t	VGAmem_t;

enum vga_color{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GREY = 7,
	DARK_GREY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_BROWN = 14,
	WHITE = 15,
};

void vga_putchar(uint8_t c, uint32_t back, uint32_t front, uint32_t y, uint32_t x);


#endif /* VGA_H */
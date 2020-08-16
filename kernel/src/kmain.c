
#include <string.h>
#include "driver/vga.h"

int ret = 0x30313233;

int val = 0x36373839;

int main(void){
	
	vga_putchar('H', BLUE, LIGHT_BLUE, 03, 0x0);
	vga_putchar('e', BLUE, LIGHT_BLUE, 03, 0x1);
	vga_putchar('l', BLUE, LIGHT_BLUE, 03, 0x2);
	vga_putchar('l', BLUE, LIGHT_BLUE, 03, 0x3);
	vga_putchar('o', BLUE, LIGHT_BLUE, 03, 0x4);
	vga_putchar(' ', BLUE, LIGHT_BLUE, 03, 0x5);
	vga_putchar('W', BLUE, LIGHT_BLUE, 03, 0x6);
	vga_putchar('o', BLUE, LIGHT_BLUE, 03, 0x7);
	vga_putchar('r', BLUE, LIGHT_BLUE, 03, 0x8);
	vga_putchar('l', BLUE, LIGHT_BLUE, 03, 0x9);
	vga_putchar('d', BLUE, LIGHT_BLUE, 03, 0xA);
	
	memcpy(&ret, &val, 0x1);

	return ret;

}

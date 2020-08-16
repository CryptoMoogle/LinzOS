
#include <stdint.h>
#include "vga.h"

	VGAmem_t *video_memory = (VGAmem_t *)0x000B8000;
	

void vga_putchar(uint8_t c, uint32_t back, uint32_t front, uint32_t y, uint32_t x){
	
	uint8_t attributeByte = (back << 4) | (front & 0x0F);
    uint16_t attribute = attributeByte << 8;
    VGAmem_t *location;

	location = video_memory + (y*80 + x);
	*location = c | attribute;
}

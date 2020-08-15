
#include <stdlib.h>

void abort(void){
	
	while(1){
		asm volatile (".intel_syntax noprefix");
		asm volatile ("mov eax, 0xFEDCBA98");
		asm volatile ("mov edx, 0x76543210");
	}
	
}
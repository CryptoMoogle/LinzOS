
#include <string.h>

#include "kprintf.h"

int ret = 0x30313233;

int val = 0x36373839;

int main(void){
	
	kprint("Goodbye cruel world!\n");
	kprint("A new line\ta tab space\n");
	kprint("\t\t\t\t\t\tsix tabs\rand return\n");
	kprint("12345\b6789 backspace after five\n");
	
	memcpy(&ret, &val, 0x1);

	return ret;

}

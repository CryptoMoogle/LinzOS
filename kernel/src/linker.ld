
ENTRY(_start)

SECTIONS{

	. = 0x00100000;
	_PHYSICAL_START = . ;

	_kernel_start = .;
	
	.text ALIGN (4K) : AT (ADDR (.text))
	{
		*(.begin)
		*(.multiboot)
		*(.text)
	}

	.rodata ALIGN (4K) : AT (ADDR (.rodata))
	{
		*(.rodata)
	}

	.data ALIGN (4K) : AT (ADDR (.data))
	{
		*(.data)
	}
	
	.bss ALIGN (4K) : AT (ADDR (.bss))
	{
		*(COMMON)
		*(.bss)
	}

	.stack ALIGN (4K) : AT (ADDR (.stack))
	{
		*(.stack)
	}
	
	. = ALIGN(4K);
    _kernel_end = .;
    end = .;

}
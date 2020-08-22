
.intel_syntax noprefix

#define MAGIC           0x1BADB002
#define PAGE_ALIGN      (1 << 0)
#define MEMORY_INFO     (1 << 1)
#define FLAGS           (PAGE_ALIGN | MEMORY_INFO)
#define CHECKSUM        -(MAGIC+FLAGS)

#define STACKSIZE		0x4000





/* The kernel start point */
.section .begin
.global _start
_start:
jmp start_kernel

/* Declare a header as in the Multiboot Standard */
.section .multiboot
.align 4
    .long   MAGIC
    .long   FLAGS
    .long   CHECKSUM

/* Write Open at top right //DEBUGGER */
.section .text
start_kernel:
	mov ecx, 0x000B8090
	mov edx, OFFSET write
	mov edi, OFFSET open
call edx

/* Write version at second line //DEBUGGER */
	mov ecx, 0x000B8130
	mov edx, OFFSET write
	mov edi, OFFSET ver
call edx

/* set kernel stack */
	mov esp, OFFSET stack_top
	mov ebp, esp

/* push eax (m_boot magic no.) and ebx (m_boot header) to kernel main */ 
/*	push eax */
/*	push ebx */

/* call main function */
.extern main
call main

/* Return value test //DEBUGGER */
	mov ecx, 0x000B8000
	mov byte ptr[ecx], al
	mov byte ptr[ecx+2], ah
	
/* Write shutdown at second line //DEBUGGER */
	mov ecx, 0x000B8130
	mov edx, OFFSET write
	mov edi, OFFSET shut
call edx

cli
hlt
.Lhang:
	jmp .Lhang

/* Write text function //DEBUGGER */
write:
	mov dl, byte ptr[edi]
	cmp dl, 0
	je .done

	mov byte ptr[ecx], dl
	inc ecx
	mov byte ptr[ecx], 0x2F
	inc ecx

	inc	edi
	jmp	write
.done:
ret

open:	.asciz "OS-Test "
ver:	.asciz "Ver: 1.0"
shut:	.asciz "Closed  "

/* Set stack size */
.section .stack
stack_bottom:
	.skip STACKSIZE
stack_top:


[bits 16]
[org 0x7c00]
mov bp, 0xffff
mov sp, bp
jmp main

%include "variables.inc"

%include "functions.inc"

%include "gdt.inc"

%include "switch_pm.inc"

%include "pm_functions.inc"


[bits 16]
main:
	push MSG_REAL_MODE
	call function_print_string
	push MSG_LOADING_KERNEL
	call function_print_string
	call function_read_kernel_from_disk
	push MSG_KERNEL_LOADED
	call function_print_string
	call function_switch_to_pm

[bits 32]
BEGIN_PM:
	mov esi, MSG_PROT_MODE
	call print_string_pm
	jmp kernel_entry

times 510-($-$$) db 0
dw 0xaa55
kernel_entry:
	;Kernel code will be loaded here





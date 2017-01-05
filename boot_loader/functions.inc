; 1 arg on stack: address of message string null terminated
function_print_string: 
	mov bx, sp
	add bx, 2
	mov bx, [bx]
	print_loop:
		mov al, [bx]
		cmp al, 0x0
		je end_loop
		mov ah, 0x0e
		int 0x10
		inc bx
		jmp print_loop
	end_loop:
		call function_print_new_line
		ret
; 1 arg on stack: hex address
function_print_hex:
	push bx
	mov bx, sp
	add bx, 4
	mov bx, [bx]
	mov ax, bx
	shr bx, 12
	mov bx, [bx+HEXABET]
	mov [HEX_TEMPLATE+2], bl
	mov bx, ax
	shr bx, 8
	and bx, 0x000f
	mov bx, [bx+HEXABET]
	mov [HEX_TEMPLATE+3], bl
	mov bx, ax
	shr bx, 4
	and bx, 0x000f
	mov bx, [bx+HEXABET]
	mov [HEX_TEMPLATE+4], bl
	mov bx, ax
	and bx, 0x000f
	mov bx, [bx+HEXABET]
	mov [HEX_TEMPLATE+5], bl
	push HEX_TEMPLATE
	call function_print_string
	add sp, 2
	pop bx
	ret  
; void
function_read_kernel_from_disk:
	mov ah, 0x02
	mov al, 9
	mov ch, 0
	mov dh, 0
	mov cl, 2
	mov bx, 0
	mov es, bx
	mov bx, kernel_entry
	int 0x13
	jc error_read
	ret

	error_read:
		push ERROR_DISK_MESSAGE
		call function_print_string
		jmp $
;void
function_print_new_line: 
    mov al, 0
    stosb
    mov ah, 0x0e
    mov al, 0x0d
    int 0x10
    mov al, 0x0a 
    int 0x10
	ret

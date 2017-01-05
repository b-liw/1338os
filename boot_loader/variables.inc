HEXABET:
	db '0123456789abcdef'

HEX_TEMPLATE:
	db '0x???? ', 0x0

ERROR_DISK_MESSAGE:
	db 'Error reading disk!', 0x0

MSG_REAL_MODE:
	db 'Started in 16-bit Real Mode', 0x0

MSG_PROT_MODE:
	db 'Successfully switched into 32-bit Protected Mode', 0x0	

MSG_LOADING_KERNEL:
	db 'Loading kernel from disk to address 0x7e00', 0x0	

MSG_KERNEL_LOADED:
	db 'Kernel has been loaded', 0x0
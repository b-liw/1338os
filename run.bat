@echo off
taskkill /F /IM VirtualBox.exe
nasm -I ./boot_loader/  -f bin ./boot_loader/boot.asm -o ./build/boot.img
gcc -ffreestanding -c ./kernel/kernel.c -o ./build/kernel.o -m32
ld -T NUL -o ./build/kernel.tmp -Ttext 0x7e00 -Tdata 0x7f00 ./build/kernel.o
objcopy -O binary ./build/kernel.tmp ./build/kernel.bin
cp ./build/kernel.bin .
cp ./build/boot.img .
copy /b boot.img+kernel.bin os-image.img
trunc os-image.img 10240
cp ./os-image.img ./build/os-image.img
rm os-image.img
rm boot.img
rm kernel.bin
rm ./build/boot.img
rm ./build/kernel.bin
rm ./build/kernel.o
rm ./build/kernel.tmp
"E:\Programy\Virtual Box\VBoxManage" startvm "os_dev"


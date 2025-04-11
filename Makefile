CC = gcc
ASM = nasm
LD = gcc

CFLAGS = -Wall -Wextra -m32
ASFLAGS = -f win32

all: main.exe

main.exe: main.c
	$(CC) $(CFLAGS) -o main.exe main.c

asm: myasm.asm
	$(ASM) $(ASFLAGS) myasm.asm -o myasm.obj
	$(LD) -m32 -o myasm.exe myasm.obj

clean:
	del /Q *.exe *.obj

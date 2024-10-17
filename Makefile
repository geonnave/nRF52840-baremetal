CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -std=gnu11 -nostartfiles -nostdlib -Wall -O0 -Wno-unused-variable
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -nostartfiles -nostdlib -T nrf52.ld -Wl,-Map=final.map

all: main.o startup.o  final.elf

# startup.o: startup.s
# 	$(CC) $(CFLAGS) -o $@ $^
startup.o: nrf52_startup.c
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf: main.o startup.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o *.elf *.map

flash:
	echo "r\nloadfile final.elf\nr\nq" | JLinkExe -device nRF52840_xxAA -if SWD -speed 4000

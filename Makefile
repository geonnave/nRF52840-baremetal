CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -std=gnu11 -nostartfiles -nostdlib -Wall -O0 -Wno-unused-variable
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -nostartfiles -nostdlib -T nrf52.x -Wl,-Map=final.map

all: startup.o main.o final.elf

# startup.o: startup.s
# 	$(CC) $(CFLAGS) -o $@ $^
startup.o: nrf52_startup.c
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf: main.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o *.elf *.map

MCU     = atmega328p
F_CPU   = 16000000UL
PORT   ?= $(firstword $(wildcard /dev/cu.usbmodem* /dev/cu.usbserial*))
TARGET  = main

CC      = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS  = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Wextra -std=c11

.PHONY: all compile flash clean

all: flash

compile: $(TARGET).hex

$(TARGET).elf: $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: $(TARGET).hex
	avrdude -p m328p -c arduino -P $(PORT) -b 115200 -U flash:w:$<:i

clean:
	rm -f $(TARGET).elf $(TARGET).hex

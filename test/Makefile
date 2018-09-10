OBJECTS=../eos/uart.o ../eos/eos.o main.o blinkled.o

ifeq ($(GCC_DIR),)
        GCC_DIR =  c:/ti/msp430_gcc/bin/
        #GCC_DIR =  ~/ti/gcc/bin
endif

SUPPORT_FILE_DIRECTORY = $(GCC_DIR)/../include

DEVICE  = msp430g2553
CC      = $(GCC_DIR)/msp430-elf-gcc
GDB     = $(GCC_DIR)/msp430-elf-gdb

CFLAGS = -I $(SUPPORT_FILE_DIRECTORY) -I ../eos/ -mmcu=$(DEVICE) -O2 -g
LFLAGS = -L $(SUPPORT_FILE_DIRECTORY)

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(LFLAGS) $? -o $(DEVICE).out

debug: all
	$(GDB) $(DEVICE).out

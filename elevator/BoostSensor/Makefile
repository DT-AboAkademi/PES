OBJECTS=bme280.o main.c

GCC_DIR =  ~/ti/gcc/bin
SUPPORT_FILE_DIRECTORY = $(GCC_DIR)/../include

DEVICE  = msp430g2553
CC      = $(GCC_DIR)/msp430-elf-gcc
GDB     = $(GCC_DIR)/msp430-elf-gdb
DEF	= MACHINE_16_BIT

CFLAGS = -I ../driverlib/MSP430FR5xx_6xx -I $(SUPPORT_FILE_DIRECTORY) -mmcu=$(DEVICE) -O2 -g -D$(DEF)
LFLAGS = -L $(SUPPORT_FILE_DIRECTORY)

all: ${OBJECTS}
	$(CC) $(CFLAGS) $(LFLAGS) $? -o $(DEVICE).out

debug: all
	$(GDB) $(DEVICE).out

OBJECTS=uart.o eos.o main.o blinkled.o

ifeq ($(GCC_DIR),)
        GCC_DIR =  c:/ti/msp430_gcc/bin/
        #GCC_DIR =  ~/ti/gcc/bin
endif

SUPPORT_FILE_DIRECTORY = $(GCC_DIR)/../include

DEVICE  = msp430g2553
CC      = $(GCC_DIR)/msp430-elf-gcc
GDB     = $(GCC_DIR)/msp430-elf-gdb

CFLAGS = -I $(SUPPORT_FILE_DIRECTORY) -mmcu=$(DEVICE) -O2 -g
LFLAGS = -L $(SUPPORT_FILE_DIRECTORY)

all: master slave

master: ${OBJECTS} master.o
	$(CC) $(CFLAGS) $(LFLAGS) $? -o $(DEVICE)_master.out

slave: ${OBJECTS} slave.o
	$(CC) $(CFLAGS) $(LFLAGS) $? -o $(DEVICE)_slave.out


debug: all
	$(GDB) $(DEVICE).out

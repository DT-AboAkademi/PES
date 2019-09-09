#include "project.h"
#include <msp430.h>
#include <stdio.h>
#include "../eos/uart.h"


#define LED1_PORT P1OUT
#define LED1_DIR P1DIR
#define LED1BIT (0x1)

#define LED2_PORT P1OUT
#define LED2_DIR P1DIR
#define LED2BIT BIT6

// char buf[100];

void main() {

	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer
	
	LED1_DIR |= LED1BIT;
	
	LED1_PORT |= (LED1BIT);

//        sprintf(buf, "Testing this: %d\n", 7733);
	
	while (1) {

	volatile unsigned int i;

	LED1_PORT &= ~(LED1BIT);
			
	for (i=0;i <65535; i++) ;

	LED1_PORT |= (LED1BIT);
 	
	for (i=0;i <65535; i++) ;

	char buf[30];
   sprintf(buf, "Testing %d\n", 100);
   
  UART_Write(buf);	
	
}
}

//#include "project.h"
#include <msp430.h>


#define LED1_PORT P1OUT
#define LED1_DIR P1DIR
#define LED1BIT (0x1)

#define LED2_PORT P1OUT
#define LED2_DIR P1DIR
#define LED2BIT BIT6



void main() {

	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer
	
	LED1_DIR |= LED1BIT;
	
	LED1_PORT |= (LED1BIT);
	
	while (1) {

	volatile unsigned int i;

	LED1_PORT &= ~(LED1BIT);
			
	for (i=0;i <65535; i++) ;

	LED1_PORT |= (LED1BIT);
 	
	for (i=0;i <65535; i++) ;

}
}

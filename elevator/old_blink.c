//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.2|-->LED
//
//  J. Stevenson
//  Texas Instruments, Inc
//  July 2011
//  Built with Code Composer Studio v5
//***************************************************************************************

#include <msp430.h>				

#define LED1 BIT0
#define LED2 BIT6

#define S1 BIT3

#define DCO_FREQ 1*1e6
#define TIMER_INTERVAL 500 // Given in ms

#define DIVIDER 8
#define TMRC (DCO_FREQ / DIVIDER / 1000 * TIMER_INTERVAL)


void setup() {
	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer

	P1OUT = LED1 | S1;

	P1DIR = (LED1 | LED2);					// Set LEDS to output direction

	P1REN |= S1; // Enable pullup
    	
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	// Set up interrupts and timer 0

	CCTL0 = CCIE;
	TACTL = TASSEL_2 + MC_1 + ID_3;
	
	CCR0 = TMRC;
	//CCR0 = 50000;
	__enable_interrupt();

}

void loop() {


  while(1);
	for(;;) {
		volatile unsigned int i;	// volatile to prevent optimization

		if ((P1IN & (S1)) == 0) {
		  P1OUT ^= (LED1|LED2);				// Toggle P1.0 using exclusive-OR
		}
		

		i = 40000;					// SW Delay
		do i--;
		while(i != 0);
	}
}

void timer_run() {
  P1OUT ^= (LED1|LED2);
}


// Interrupt
//#pragma vector=TIMERA0_VECTOR
__attribute__((interrupt(TIMER0_A0_VECTOR))) void Timer_A(void) {
  timer_run();
  //  CCR0 = TMR;
}



int main(void) {


  setup();

  loop();
  return 0;
}

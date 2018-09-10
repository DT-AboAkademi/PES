#include "project.h"
#include "ports.h"
#include "switch.h"

tByte wasPressed=0;

void Switch_Init() {
	// Configure as input, set pullup, 
	SWITCH1_DIR &= ~(SWITCH1_BIT);
 
//SWITCH1_DIR |= (SWITCH1_BIT);
 
    P1OUT |= (SWITCH1_BIT);
	P1REN |= (SWITCH1_BIT);
	P1SEL &= ~(SWITCH1_BIT);
	}

tByte Switch_GetStat() {

//	return NOT_PRESSED;
	if (!(SWITCH1_IN & (SWITCH1_BIT))) return PRESSED;

	return NOT_PRESSED;

}

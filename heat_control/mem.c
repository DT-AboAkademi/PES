#include "project.h"
#include "ports.h"
#include "switch.h"

void Switch_Init() {
	// Configure as input, set pullup, 
	SWITCH1_DIR &= ~(SWITCH1_BIT);
    P1OUT |= (SWITCH1_BIT);
	P1REN |= (SWITCH1_BIT);
	}

tByte Switch_GetStat() {

	if (SWITCH1_IN & (SWITCH1_BIT)) return NOT_PRESSED;

	return PRESSED;

}

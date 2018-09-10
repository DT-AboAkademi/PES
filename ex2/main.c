#include "project.h"

#include "led.h"
#include "switch.h"

void main() {

	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer

    
	
	while (1) {
		
		if (Switch_GetStat() == PRESSED) {
			Led_Setstat(LEDSTAT_ON);
		}
		Led_Setstat(LEDSTAT_OFF);		
	}
}

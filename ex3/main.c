#include "project.h"
#include "timer.h"

#include "led.h"
#include "switch.h"
#include "traffic.h"
#include "../eos/uart.h"

void main() {

	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer

	
        Timer_Init();
        Led_Init();
		Switch_Init();
		Traffic_Init();
		UART_Init();
	
	_enable_interrupts();
	
	UART_Write("Starting system");
	
	while (1) {
		LPM1;
		//UART_Write("Test....");
		
	} 
	
	
	
}

char buf[100];
void timer_run() {
	static unsigned int count;
	//if (++count %100 == 0) {UART_Write("Testing");}
	if (UART_Read(buf, 100)>0) {UART_Write(buf);}
	Traffic_Update();
}

#include "project.h"
#include "ports.h"
#include "timer.h"

#include "led.h"

tWord blinkInterval;
tByte gLedStat = LEDSTAT_BLINK;

void LED_Init() {
		LED1_DIR |= LED1BIT;
		LED1_PORT &= ~LED1BIT;

		LED2_DIR |= LED2BIT;
		LED2_PORT &= ~LED2BIT;

//		blinkInterval = interval / TIMER_INTERVAL;
} 
	
void LED_Update() {
		LED1_PORT ^= LED1BIT; 
}

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


void Led_Set(tByte Led, tByte state) {

	switch(Led) {
		case RED_LED:
			if (state==LED_ON) {
				LED1_PORT |= LED1BIT;
			} else {
				LED1_PORT &= ~LED1BIT;
			}
			break;
		case GREEN_LED:
			if (state==LED_ON) {
				LED2_PORT |= LED2BIT;
			} else {
				LED2_PORT &= ~LED2BIT;
			}
			break;
	}
}
	
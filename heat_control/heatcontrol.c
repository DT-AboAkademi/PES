#include "project.h"

#include "heatcontrol.h"
#include "ports.h"
#include "led.h"
#include "switch.h"
#include "../eos/uart.h"

typedef enum {RED, RED_AMBER, GREEN, AMBER} eLightState;

eLightState TRAFFIC_state_G;
tLong TRAFFIC_time_in_state_G = 0;
tByte gotoGreen =0;

#define TIME_RED (4 * 1000 / TIMER_INTERVAL)
#define TIME_RED_AMBER (0.7 * 1000 / TIMER_INTERVAL)
#define TIME_GREEN (4 * 1000 / TIMER_INTERVAL)
#define TIME_AMBER (0.5 * 1000 / TIMER_INTERVAL)

void Heater_Init() {
	TRAFFIC_state_G = RED;
	}
	
void Heater_Update() {

if (Switch_GetStat() == PRESSED) {
		gotoGreen = 1;
}

TRAFFIC_time_in_state_G++;


switch (TRAFFIC_state_G) {
		case RED: 
			Led_Set(RED_LED, LED_ON);
			Led_Set(GREEN_LED, LED_OFF);
			if (TRAFFIC_time_in_state_G > TIME_RED || gotoGreen) {
				TRAFFIC_time_in_state_G =0;
				TRAFFIC_state_G = RED_AMBER;
				UART_Write("Going to RED_AMBER");
				gotoGreen = 0;
			}
			break;
		case RED_AMBER: 
			Led_Set(RED_LED, LED_ON);
			Led_Set(GREEN_LED, LED_ON);
			if (TRAFFIC_time_in_state_G > TIME_RED_AMBER) {
				TRAFFIC_time_in_state_G =0;
				TRAFFIC_state_G = GREEN;
				UART_Write("Going to GREEN");
			}
			break;
		case GREEN: 
			Led_Set(RED_LED, LED_OFF);
			Led_Set(GREEN_LED, LED_ON);
			if (TRAFFIC_time_in_state_G > TIME_GREEN) {
				TRAFFIC_time_in_state_G =0;
				TRAFFIC_state_G = AMBER;
				UART_Write("Going to AMBER");

			}
			break;
		case AMBER: 
			Led_Set(RED_LED, LED_ON);
			Led_Set(GREEN_LED, LED_ON);
			if (TRAFFIC_time_in_state_G > TIME_AMBER) {
				TRAFFIC_time_in_state_G =0;
				TRAFFIC_state_G = RED;
				UART_Write("Going to RED");				
			}
			break;
  
 }

   
 }
				
			
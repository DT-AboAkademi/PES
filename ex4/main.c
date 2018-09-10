#include "project.h"
#include "timer.h"

#include "../eos/eos.h"
#include "../eos/uart.h"

#include "led.h"
#include "switch.h"
#include "adc.h"

int main(void) {

  WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer

  LED_Init();
  UART_Init();
  SCH_Init();
  ADC_Init();
  
  SCH_AddTask(LED_Update, 0, 100);
  SCH_AddTask(ADC_Read, 10, 500);
  SCH_AddTask(ADC_Write,20,500);

  UART_Write("Starting up\n\r");	
  
  SCH_Start();

  while(1) {

    SCH_Dispatch();
    }

  return 0;
}


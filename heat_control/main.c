#include "project.h"
#include "timer.h"
#include "string.h"

#include "../eos/eos.h"
#include "../eos/uart.h"

#include "led.h"
#include "switch.h"
#include "adc.h"
#include "heatcontrol.h"

#define SAVE_TO_FLASH_INTERVAL (1000*60)
#define MAGIC 0x38FA

typedef struct tag_state {
	tWord magic; // if initialized contains magic
	tWord state;  //
	tWord last_state;
	tWord time_in_state; // minutes
	tLong runtime;
	tLong Plevel_1;
	tLong Plevel_2;
	tLong Plevel_3;
	tWord temp_out;  // Temperate outside
	tWord temp_water; // Temperature water
} STATE;
	
STATE g_state;

void *INFOB = (void *)0x1080;

int main(void) {
  
  tWord *persistent_state = (tWord *)INFOB;
  
//  ASSERT(sizeof(STATE)<64);  // Data to save not greater that state
 
  WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer

  // copy persistent state into state variable
  memcpy((void *)&g_state, (void *)persistent_state, sizeof(g_state));
  
  // Make sure that state if reset, if used fist time
  if (!g_state.magic == MAGIC) {
	memset((void *)&g_state, 0, sizeof(g_state));
	g_state.magic == MAGIC;
  }
  
  LED_Init();
  UART_Init();
  ADC_Init();
  Heater_Init();
  
  SCH_Init();

  
  SCH_AddTask(LED_Update, 0, 200);
  SCH_AddTask(ADC_Read, 10, 1000); //
  SCH_AddTask(ADC_Write, 20, 1000); //

  //  SCH_AddTask(Save_To_Flash, 30, 1000*30); //
  SCH_AddTask(Heater_Update,40, 1000);
  
  
  char buf[20];
  
  sprintf(buf, "Test \n");
  
  UART_Write("Starting up\n\r");	
  
  SCH_Start();

  while(1) {

    SCH_Dispatch();
	LPM0;
    }

  return 0;
}


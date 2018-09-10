#include <stdio.h>
#include "project.h"
#include "ports.h"
#include "timer.h"

#include "adc.h"
#include "../eos/uart.h"

tWord gADCLastVal=0;
char buf[25];

void ADC_Init() {

		ADC10CTL0 &= ~ENC;

		ADC10CTL0 = ADC10ON +MSC +ADC10SHT_3;
				
		ADC10CTL1 = INCH_10 + ADC10SSEL_3 + ADC10DIV_4; // Channel 3, ADC10CLK/3
		//ADC10CTL0 = SREF_0 + REFON + ADC10SHT_3 + ADC10ON ;  // Vcc & Vss as reference, Sample and hold for 64 Clock cycles, ADC on
		//ADC10CTL1 = INCH_10 + ADC10DIV_3;
		
		//ADC10AE0 |= BIT3;                         // ADC input enable P1.3

		
} 
	
void ADC_Read() {
		tWord count = 32000;
		ADC10CTL0 |= ENC + ADC10SC; // Start new coversion

		while ((ADC10CTL1 & ADC10BUSY) && --count); 
		if (!count) UART_Write("ADC Timeout error");
		
		gADCLastVal = ADC10MEM; // Left shift
		ADC10CTL0 &= ~ENC;
}

void ADC_Write() {
	
	tWord i;
	tWord val = ADC_GetValue();
	tByte q, c=0;
	for (i=10000; i>0; i/=10) {
		q= val/i;
		buf[c++] = q+'0';
		val -= q*i;
	}
	buf[c++] = '\n';
	buf[c++] = '\r';

	buf[c] = '\0';
	
	UART_Write(buf);
}

inline tWord ADC_GetValue() {return gADCLastVal;}

	
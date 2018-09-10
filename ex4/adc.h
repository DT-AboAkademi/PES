#ifndef _ADC_H
#define _ADC_H

#include <msp430.h>

#include "project.h"

void ADC_Init();
void ADC_Read();
void ADC_Write();
tWord ADC_GetValue();


#endif
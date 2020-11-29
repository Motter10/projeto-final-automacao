/*
 * utils.c
 *
 *  Created on: 28 de nov de 2020
 *      Author: sandr
 */
#include "utils.h"
#include "ADC.h"

void UTILS_get_Hour(char* hour)
{
	  struct tm *sTm;

	  time_t now = time (0);
	  sTm = gmtime (&now);

	  strftime (hour, 9, "%H:%M:%S", sTm);
	  return;
}

uint32_t UTILS_To_Temp(uint32_t value_adc)
{
	//
//	float v25 = 4000;// When V25=1.41V at ref 3V3
//	float avgSlope = 5.0;// When avgSlope=5mV/C at ref 3V3
//	float temperature = ((value_adc - v25)/avgSlope)+25;
//	return (uint32_t)temperature;
	uint32_t temperature = (value_adc * ADC_SCALE) * 25;
	return temperature;
}

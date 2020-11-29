/*
 * ADC.c
 *
 *  Created on: Nov 29, 2020
 *      Author: sandr
 */
#include "ADC.h"

uint32_t adc_data[NUMBER_OF_CONVERSTION];
uint8_t  adc_data_ready = 0;

void ADC_Init(ADC_HandleTypeDef hadc1)
{
	//calibração do ADC
	HAL_ADCEx_Calibration_Start(&hadc1);
}

uint32_t ADC_GetValue(ADC_HandleTypeDef hadc1, uint32_t sensor_channel_id)
{
	adc_data_ready = 0;

	HAL_ADC_Start_DMA(&hadc1, adc_data, NUMBER_OF_CONVERSTION);

	//espera conversão
	while(!adc_data_ready);
	return adc_data[0];
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	adc_data_ready = 1;
}

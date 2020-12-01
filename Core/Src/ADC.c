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

uint32_t ADC_GetValue(ADC_HandleTypeDef hadc1, ADC_CHANNEL_Id channel_id)
{
	adc_data_ready = 0;

	HAL_ADC_Start_DMA(&hadc1, adc_data, NUMBER_OF_CONVERSTION);

	HAL_ADC_Stop(&hadc1);

//	while(!adc_data_ready);

	return adc_data[channel_id];

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	adc_data_ready = 1;
}

//void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
//{
//	adc_data_ready = 1;
//}

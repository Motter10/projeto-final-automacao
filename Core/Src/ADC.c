/*
 * ADC.c
 *
 *  Created on: Nov 29, 2020
 *      Author: sandr
 */
#include "ADC.h"

uint32_t adc_data[NUMBER_OF_CONVERSTION];
uint8_t  adc_data_ready = 0;

/**
 * @brief Inicializa ADC_1
 *
 * @retval none
 * @param hadc1 objeto do ADC_1
 *
 */
void ADC_Init(ADC_HandleTypeDef hadc1)
{
	//calibração do ADC
	HAL_ADCEx_Calibration_Start(&hadc1);
}

/**
 * @brief Recebe valor de um canal do ADC_1
 *
 * Retonar valor lido pelo adc em um canal específico, lembrando que channel id
 * é o id do vetor adc_data
 *
 * @retval none
 * @param hadc1 objeto do ADC_1
 * @param cahannel_id id do canal a ser lido
 *
 */
uint32_t ADC_GetValue(ADC_HandleTypeDef hadc1, ADC_CHANNEL_Id channel_id)
{
	adc_data_ready = 0;

	HAL_ADC_Start_DMA(&hadc1, adc_data, NUMBER_OF_CONVERSTION);

	HAL_ADC_Stop(&hadc1);

	return adc_data[channel_id];

}

/**
 * @brief Callback conversão completa do adc
 *
 * Avisa que a leitura completa do adc foi realizada
 *
 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	adc_data_ready = 1;
}

//void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
//{
//	adc_data_ready = 1;
//}

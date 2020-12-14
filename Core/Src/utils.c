/*
 * utils.c
 *
 *  Created on: 28 de nov de 2020
 *      Author: sandr
 */
#include "utils.h"
#include "ADC.h"

/**
 * @brief Converte valor lido no adc para temperatura
 *
 * time_t now = time (0);
 * Na lihna acima, deve-se passar por parâmetro na função time() o valor do tempo atual;
 *
 * @param [out]hour vetor de char que será armazenado a hora
 */
void UTILS_get_Hour(char* hour)
{
	  struct tm *sTm;

	  time_t now = time (0);
	  sTm = gmtime (&now);

	  strftime (hour, 9, "%H:%M:%S", sTm);
	  return;
}

/**
 * @brief Converte valor lido no adc para temperatura
 *
 * Atualmente é apenas um valor fictício para ilustrar o funcionamento do sistema.
 *
 * @retval uint32_t temperatura
 * @param value_adc valor lido em um canal do adc
 */
uint32_t UTILS_To_Temp(uint32_t value_adc)
{
	uint32_t temperature = (value_adc * ADC_SCALE) * 25;
	return temperature;
}

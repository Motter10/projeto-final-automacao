/*
 * proportional_control.c
 *
 *  Created on: Nov 29, 2020
 *      Author: sandr
 */

#include "controller.h"

void CONTROLLER_Get_IsReady(ADC_HandleTypeDef hadc, uint32_t ref_sinal, uint8_t sensor_channel_id)
{
	int32_t sensor_signal = 0;
	uint32_t sensor_temp = 0;
	uint32_t error_signal = 1;

	//continua aquecendo até erro ser zero
	while(error_signal > 0)
	{
		sensor_signal = ADC_GetValue(hadc, sensor_channel_id);
		sensor_temp = UTILS_To_Temp(sensor_signal);

		error_signal = ref_sinal - sensor_temp;

		HAL_Delay(50);
	}
	return;
}

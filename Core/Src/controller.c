/*
 * proportional_control.c
 *
 *  Created on: Nov 29, 2020
 *      Author: sandr
 */

#include "controller.h"

void CONTROLLER_Get_IsReady(ADC_HandleTypeDef hadc, CAPSULE_Recipe_TypeDef capsule)
{
	int32_t sensor_signal = 0;
	uint32_t sensor_temp = 0;
	uint32_t error_signal = 1;
	uint32_t ref_sinal = capsule.water_temp;
	ADC_CHANNEL_Id sensor_channel_id;

	LCD_Clear();

	switch (capsule.water_type) {
		case HOT_WATER:
			LCD_Write_Buffer("Aquecendo a água.");
//			PWM_R1_DATA(R1);
			CONTROLLER_BLOCK_HEATER_DATA(heater_block);
			//aciona R1, aquecimento resistivo
			PWM_Increase(heater_block.pwm);
			sensor_channel_id = heater_block.adc_channel_id;
			break;
//		case ICE_WATER:
//			LCD_Write_Buffer("Refrigerando a água.");
//			PWM_CP1_DATA(CP1);
//			//aciona CP1, compressor de refrigeração
//			PWM_Increase(CP1);
//			break;
		default:
			break;
	}

	//fica no while até chegar na temperatura desejada
	while(error_signal != 0)
	{
		sensor_signal = ADC_GetValue(hadc, sensor_channel_id);

		sensor_temp = UTILS_To_Temp(sensor_signal);

		error_signal = ref_sinal - sensor_temp;


		HAL_Delay(50);
	}
	return;
}

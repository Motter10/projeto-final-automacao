/*
 * statetements.c
 *
 *  Created on: 28 de nov de 2020
 *      Author: sandr
 */

#include "states.h"


uint8_t STATE_Show_Clock()
{
	char hour[10];
	uint8_t recipe = 0;
	uint8_t insert_button = 0;

	while(1)
	{
		UTILS_get_Hour(hour);
		LCD_Clear();
		LCD_Write_Buffer(hour);

		//se botão de inserir capsula for inserido, verificar qual é a receita
		insert_button = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_INSERT_BUTTON);
		if(insert_button)
		{
			recipe = CAPSULE_Verify_Insertion();
		}
		HAL_Delay(200);

		//se tiver uma receita, retorna
		if(recipe){
			return STATE_STARTING_PROCESS;
		}
	}
}


uint8_t STATE_Start_Process()
{
	while(1)
	{
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
		HAL_Delay(2000);
		if(0)
		{
			return STATE_SHOWING_CLOCK;
		}
	}
}

/*
 * statetements.c
 *
 *  Created on: 28 de nov de 2020
 *      Author: sandr
 */

#include "states.h"


CAPSULE_Recipe_TypeDef STATE_Show_Clock()
{
	char hour[10];
	CAPSULE_Recipe_TypeDef capsule = {
			.capsule_type = NONE_CAPSULE_TYPE,
	};
	uint8_t insert_button = 0;

	while(1)
	{
		UTILS_get_Hour(hour);
		LCD_Clear();
		LCD_Write_Buffer(hour);

		insert_button = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_INSERT_BUTTON);

		//se botão de inserir capsula for pressionado, verifica  qual é a receita
		if(insert_button)
		{
			capsule = CAPSULE_Verify_Insertion();
		}

		//se tiver uma cápsula, retorna
		if(capsule.capsule_type != NONE_CAPSULE_TYPE ){

			return capsule;
		}
		HAL_Delay(300);
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	}
}


CAPSULE_Recipe_TypeDef STATE_Starting_Process(CAPSULE_Recipe_TypeDef capsule)
{
	uint8_t confirm_button = 0;

	LCD_Clear();
	LCD_Write_Buffer(capsule.capsule_name);
	LCD_Seccond_Line();
	LCD_Write_Buffer("S --> Iniciar.");

	while(1)
	{

		confirm_button = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_INSERT_BUTTON);

		if(confirm_button)
		{
			return capsule;
		}

		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
		HAL_Delay(300);
	}
}

void STATE_Started_Process(CAPSULE_Recipe_TypeDef capsule)
{
	LCD_Clear();
	LCD_Write_Buffer("Iniciando...");
	HAL_Delay(1500);

	uint8_t confirm_button = 0;
	while(1)
	{
		LCD_Clear();
		LCD_Write_Buffer("Aguarde...");

		confirm_button = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_INSERT_BUTTON);

		if(confirm_button)
		{
			return;
		}


		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
		HAL_Delay(300);
	}
}

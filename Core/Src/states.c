/*
 * statetements.c
 *
 *  Created on: 28 de nov de 2020
 *      Author: sandr
 */

#include "controller.h"
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


CAPSULE_Recipe_TypeDef STATE_Starting_Process(CAPSULE_Recipe_TypeDef capsule, ADC_HandleTypeDef hadc)
{
	uint8_t confirm_button = 0;

	LCD_Clear();
	LCD_Write_Buffer(capsule.capsule_name);
	LCD_Seccond_Line();

//	//se for apenas água, escolhe entre quente, natural e gelada.
//	if(capsule.capsule_type == RECIPE_WATER)


	LCD_Write_Buffer("S --> Iniciar.");

	int32_t sensor_signal = 0;
	float avg_value_P1 = 0;
	float avg_value_P2 = 0;

	int32_t var = 0;
	for (var = 0; var < 32; ++var) {
		sensor_signal += ADC_GetValue(hadc, P1);
	}

	avg_value_P1 = sensor_signal / var;

	//se P1 passar do nivel considerado saturado....
	if(avg_value_P1 > 3000){
		LCD_Clear();
		LCD_Write_Buffer("P1 SATURADO!");
		HAL_Delay(2000);
		RECIPE_NONE_CAPSULE_TYPE_DATA(none_capsule);
		return none_capsule;
	}

	//se receita precisar de CO2, verifica se está P2 saturado
	if(capsule.co2_time > 0)
	{
		sensor_signal = 0;
		for (var = 0; var < 32; ++var) {
			sensor_signal += ADC_GetValue(hadc, P2);
		}

		avg_value_P2 = sensor_signal / var;

		//se P2 passar do nivel considerado saturado....
		if(avg_value_P2 > 3000){
			LCD_Clear();
			LCD_Write_Buffer("P2 SATURADO!");
			HAL_Delay(2000);
			RECIPE_NONE_CAPSULE_TYPE_DATA(none_capsule);
			return none_capsule;
		}
	}


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

void STATE_Started_Process(CAPSULE_Recipe_TypeDef capsule, ADC_HandleTypeDef hadc)
{
	LCD_Clear();
	LCD_Write_Buffer("Iniciando...");
	HAL_Delay(1500);

	uint8_t confirm_button = 0;
	while(1)
	{
		CONTROLLER_Get_IsReady(hadc, capsule);

		return;

	}
}

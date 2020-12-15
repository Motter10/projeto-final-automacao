/*
 * proportional_control.c
 *
 *  Created on: Nov 29, 2020
 *      Author: sandr
 */

#include "controller.h"

/**
 * @brief Executa controlador
 *
 *	Executa o controlador conforme a capsula recebida por parâmetro, quando o erro chegar a zero,
 *	ativa a válvula de água e a bomba principal.
 *
 * @retval none
 * @param hadc objeto do ADC_1
 * @param capsule capsula que determina se precisará aquecer ou resfriar a água.
 *
 */
void CONTROLLER_Execute(ADC_HandleTypeDef hadc, CAPSULE_Recipe_TypeDef capsule)
{
	int32_t sensor_signal = 0;
	uint32_t sensor_temp = 0;
	int32_t error_signal = 1;
	uint32_t ref_sinal = capsule.water_temp;
	ADC_CHANNEL_Id sensor_channel_id;
	uint32_t init_time = 0;
	uint32_t current_time = 0;

	Controler_TypeDef block;
	LCD_Clear();

	Y3(natural_water_output);
	switch (capsule.water_type) {
		case HOT_WATER:
			LCD_Write_Buffer("Aquecendo a água.");
			CONTROLLER_BLOCK_HEATER_DATA(heater_block);
			block = heater_block;
			//aciona R1, aquecimento resistivo
			PWM_Increase(block.pwm);
			sensor_channel_id = heater_block.adc_channel_id;
			break;
		case ICE_WATER:
			LCD_Write_Buffer("Refrigerando a água.");
			CONTROLLER_BLOCK_COOLER_DATA(cooler_block);
			block = cooler_block;
			//aciona CP1, compressor de refrigeração
			PWM_Increase(block.pwm);
			sensor_channel_id = cooler_block.adc_channel_id;
			break;
		case NATURAL_WATER:
			block.output = natural_water_output;
			goto activate_pump;
			break;
		default:
			break;
	}

	init_time = HAL_GetTick();
	current_time = init_time;
	//fica no while até chegar na temperatura desejada
	while(error_signal != 0)
	{
		sensor_signal = ADC_GetValue(hadc, sensor_channel_id);

		sensor_temp = UTILS_To_Temp(sensor_signal);

		error_signal = ref_sinal - sensor_temp;

		HAL_Delay(50);
		current_time = HAL_GetTick();
		if(current_time > (init_time + 300)){
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			init_time = current_time;
		}
	}

	PWM_Decrease(block.pwm);

	activate_pump: ;

	LCD_Clear();
	LCD_Write_Buffer("Ativando bomba...");

	//ativa bomba de saída
	PWM_TypeDef b1 = {.duty_cycle = 1, .pwm_channel = 3, .speed_time=200};
	PWM_Increase(b1);

	LCD_Clear();
	LCD_Write_Buffer("-Despejando água");

	init_time = HAL_GetTick();
	current_time = init_time;

	//se precisar de CO2, ativa CO2
	Y4(co2_output);
	if(capsule.co2_time > 0){
		LCD_Seccond_Line();
		LCD_Write_Buffer("-Despejando CO2");
		HAL_GPIO_WritePin(co2_output.gpio_class, co2_output.gpio_pin, GPIO_PIN_SET);
	}

	HAL_GPIO_WritePin(block.output.gpio_class, block.output.gpio_pin, GPIO_PIN_SET);

	//aguarda até passar o tempo de despejo de água e de CO2.
	while(current_time < (init_time + capsule.water_time) || current_time < (init_time + capsule.co2_time)){
		current_time = HAL_GetTick();

		//se chegou no tempo desejado de água, desliga.
		if(current_time >=  (init_time + capsule.water_time)){
			HAL_GPIO_WritePin(block.output.gpio_class, block.output.gpio_pin, GPIO_PIN_RESET);
		}

		//se chegou no tempo desejado de co2, desliga.
		if(current_time >= (init_time + capsule.co2_time)){
			HAL_GPIO_WritePin(co2_output.gpio_class, co2_output.gpio_pin, GPIO_PIN_RESET);
		}
	}

	//seta tempo para desacelerar
	b1.speed_time = 250;
	PWM_Decrease(b1);
	return;
}

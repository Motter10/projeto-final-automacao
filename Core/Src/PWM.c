/*
 * PWM.c
 *
 *  Created on: Nov 29, 2020
 *      Author: sandr
 */

#include "PWM.h"


/**
 * @brief Inicializa PWM
 *
 * Inicializa canais de PWM.
 * Atenção: ao adicionar um novo canal é necessário atualizar a função manualmente.
 *
 * @retval none
 * @param htim2 objeto do Timer2
 *
 */
void PWM_Init(TIM_HandleTypeDef* htim2)
{
	HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_3);
}

/**
 * @brief Aumenta PWM
 *
 * Aumenta PWM de 0 até pwm máximo passado por parâmetro
 * @retval none
 * @param pwm_data objeto que contém faixa de pwm e o canal do mesmo
 *
 */
void PWM_Increase(PWM_TypeDef pwm_data)
{
	//converte de porcentagem para valor
	uint32_t duty_value_max = pwm_data.duty_cycle * MAX_DUTY_CYCLE_VALUE;
	uint32_t duty_value = 0;

	uint32_t init_time = HAL_GetTick();
	uint32_t current_time = init_time;

	uint32_t inc = duty_value_max / 200.0;

	uint32_t first_time = HAL_GetTick();
	while(duty_value < duty_value_max)
	{
		//Como identificar canal?
		if(pwm_data.pwm_channel == 1)
		{
			TIM2->CCR1 = duty_value;
		}
		else if(pwm_data.pwm_channel == 2)
		{
			TIM2->CCR2 = duty_value;
		}
		else if(pwm_data.pwm_channel == 3)
		{
			TIM2->CCR3 = duty_value;
		}
		duty_value += inc;
		HAL_Delay(1);

		//pisca led
		current_time = HAL_GetTick();
		if(current_time > (init_time + 300)){
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			init_time = current_time;
		}
	}
	uint32_t last_time = HAL_GetTick();
	return;
}

/**
 * @brief Diminui freq. PWM
 *
 * Diminui PWM de pwm_máximo até 0.
 * @retval none
 * @param pwm_data objeto que contém faixa de pwm e o canal do mesmo.
 *
 */
void PWM_Decrease(PWM_TypeDef pwm_data)
{
	//converte de porcentagem para valor
	uint32_t duty_value_max = pwm_data.duty_cycle * MAX_DUTY_CYCLE_VALUE;
	uint32_t init_time = HAL_GetTick();
	uint32_t current_time = init_time;

	while(duty_value_max > 0)
	{
		if(pwm_data.pwm_channel == 1)
		{
			TIM2->CCR1 = duty_value_max;
		}
		else if(pwm_data.pwm_channel == 2)
		{
			TIM2->CCR2 = duty_value_max;
		}
		else if(pwm_data.pwm_channel == 3)
		{
			TIM2->CCR3 = duty_value_max;
		}
		duty_value_max -= 1;
		HAL_Delay(1);

		//pisca led
		current_time = HAL_GetTick();
		if(current_time > (init_time + 300)){
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			init_time = current_time;
		}
	}
}

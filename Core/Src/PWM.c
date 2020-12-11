/*
 * PWM.c
 *
 *  Created on: Nov 29, 2020
 *      Author: sandr
 */

#include "PWM.h"

void PWM_Init(TIM_HandleTypeDef* htim2)
{
	HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_2);
}

void PWM_Increase(PWM_TypeDef pwm_data)
{
	//converte de porcentagem para valor
	uint32_t duty_value = pwm_data.duty_cycle * MAX_DUTY_CYCLE_VALUE;

	while(duty_value < MAX_DUTY_CYCLE_VALUE)
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
		duty_value += 1;
		HAL_Delay(1);
	}
}


void PWM_Decrease(PWM_TypeDef pwm_data)
{
	//converte de porcentagem para valor
	uint32_t duty_value = pwm_data.duty_cycle * MAX_DUTY_CYCLE_VALUE;
	while(duty_value > 0)
	{
		if(pwm_data.pwm_channel == 1)
		{
			TIM2->CCR1 = duty_value;
		}
		else if(pwm_data.pwm_channel == 2)
		{
			TIM2->CCR2 = duty_value;
		}
		duty_value -= 1;
		HAL_Delay(1);
	}
}

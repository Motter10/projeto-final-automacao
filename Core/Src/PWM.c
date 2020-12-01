/*
 * PWM.c
 *
 *  Created on: Nov 29, 2020
 *      Author: sandr
 */

#include "PWM.h"
//	  while(duty_cycle < MAX_DUTY_CYCLE_VALUE)
//	  {
//		  TIM2->CCR1 = duty_cycle;
//		  duty_cycle += 1;
//		  HAL_Delay(0);
//	  }
//
//	  while(duty_cycle > 0)
//	  {
//		  TIM2->CCR1 = duty_cycle;
//		  duty_cycle -= 1;
//		  HAL_Delay(0);
//	  }

void PWM_Increase(PWM_TypeDef pwm_data)
{
	//converte de porcentagem para valor
	uint32_t duty_value = pwm_data.duty_cycle * MAX_DUTY_CYCLE_VALUE;

	while(duty_value < MAX_DUTY_CYCLE_VALUE)
	{
		//Como identificar canal?
	  TIM2->CCR1 = duty_value;
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

	  TIM2->CCR1 = duty_value;
	  duty_value -= 1;
	  HAL_Delay(1);
	}
}

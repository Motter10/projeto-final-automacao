/*
 * PWM.h
 *
 *  Created on: Nov 29, 2020
 *      Author: sandr
 */
#ifndef INC_PWM_H_
#define INC_PWM_H_

#define FREQ_CHAV_DESEJADA		24000
#define CLOCK_UC				64000000
#define MAX_DUTY_CYCLE_VALUE	(CLOCK_UC / FREQ_CHAV_DESEJADA)

#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "stm32f103xb.h"
#include "DWT.h"

typedef struct
{
	uint8_t pwm_channel; //estrutura do stm32
	uint32_t speed_time;
	float duty_cycle;
}PWM_TypeDef;

#define PWM_R1_DATA(PWM_OBJ) PWM_TypeDef PWM_OBJ = {.pwm_channel = 1, .duty_cycle = 1, speed_time = 200}

void PWM_Init(TIM_HandleTypeDef* htim2);

void PWM_Increase(PWM_TypeDef pwm_data);

void PWM_Decrease(PWM_TypeDef pwm_data);



#endif /* INC_PWM_H_ */

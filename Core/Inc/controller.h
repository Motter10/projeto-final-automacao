/*
 * proportional_control.h
 *
 *  Created on: Nov 29, 2020
 *      Author: sandr
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include "stm32f1xx_hal.h"

#include "utils.h"
#include "LCD_4.h"
#include "capsule.h"
#include "ADC.h"
#include "PWM.h"

typedef struct{
	PWM_TypeDef pwm;
	ADC_CHANNEL_Id adc_channel_id;
	uint32_t output;
}Controler_TypeDef;

#define CONTROLLER_BLOCK_HEATER_DATA(CONTROLLER_OBJ) Controler_TypeDef CONTROLLER_OBJ = {.pwm={.pwm_channel = 1, .duty_cycle = 0.1}, .adc_channel_id = IN_5, .output = 3}

#endif /* INC_CONTROLLER_H_ */

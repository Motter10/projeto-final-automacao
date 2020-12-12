/*
 * proportional_control.h
 *
 *  Created on: Nov 29, 2020
 *      Author: sandr
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include <io.h>
#include "stm32f1xx_hal.h"

#include "utils.h"
#include "LCD_4.h"
#include "capsule.h"
#include "ADC.h"
#include "PWM.h"


typedef struct{
	PWM_TypeDef pwm;
	ADC_CHANNEL_Id adc_channel_id;
	Output_TypeDef output;
}Controler_TypeDef;


#define CONTROLLER_BLOCK_HEATER_DATA(CONTROLLER_OBJ) Controler_TypeDef CONTROLLER_OBJ = {.pwm={.pwm_channel = 1, .duty_cycle = 0.1}, .adc_channel_id = IN_5, .output = {.gpio_pin = GPIO_PIN_0, .gpio_class = GPIOB}}

#define CONTROLLER_BLOCK_COOLER_DATA(CONTROLLER_OBJ) Controler_TypeDef CONTROLLER_OBJ = {.pwm={.pwm_channel = 2, .duty_cycle = 0.01}, .adc_channel_id = IN_4, .output = {.gpio_pin = GPIO_PIN_1, .gpio_class = GPIOB}}

#endif /* INC_CONTROLLER_H_ */

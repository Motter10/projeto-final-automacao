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

/*
 * pwm todas informações necessárias para o pwm
 * adc_channel_id canal do ADC
 * output pino de saida para ativar válvula
 */
typedef struct{
	PWM_TypeDef pwm;
	ADC_CHANNEL_Id adc_channel_id;
	Output_TypeDef output;
}Controler_TypeDef;

/*
 * Inicializa controlador de água quente
 */
#define CONTROLLER_BLOCK_HEATER_DATA(CONTROLLER_OBJ) Controler_TypeDef CONTROLLER_OBJ = {.pwm={.pwm_channel = 1, .duty_cycle = 1, .speed_time = 200}, .adc_channel_id = IN_5, .output = {.gpio_pin = GPIO_PIN_0, .gpio_class = GPIOB}}

/*
 * Inicializa controlador de água gelada
 */
#define CONTROLLER_BLOCK_COOLER_DATA(CONTROLLER_OBJ) Controler_TypeDef CONTROLLER_OBJ = {.pwm={.pwm_channel = 2, .duty_cycle = 0.1, .speed_time = 200}, .adc_channel_id = IN_4, .output = {.gpio_pin = GPIO_PIN_1, .gpio_class = GPIOB}}

void CONTROLLER_Execute(ADC_HandleTypeDef hadc, CAPSULE_Recipe_TypeDef capsule);
#endif /* INC_CONTROLLER_H_ */

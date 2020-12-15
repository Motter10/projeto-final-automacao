/*
 * statements.h
 *
 *  Created on: 28 de nov de 2020
 *      Author: sandr
 */

#ifndef INC_STATES_H_
#define INC_STATES_H_

#include "stm32f1xx_hal.h"

#include "utils.h"
#include "LCD_4.h"
#include "capsule.h"
#include "PWM.h"
#include "DWT.h"

/*
 * Número de tipos de agua
 */
#define CHOICES_NUMBER 3

typedef enum{STATE_SHOWING_CLOCK, STATE_STARTING_PROCESS, STATE_STARTED_PROCESS} STATE;

CAPSULE_Recipe_TypeDef STATE_Show_Clock(RTC_HandleTypeDef hrtc);

CAPSULE_Recipe_TypeDef STATE_Starting_Process(CAPSULE_Recipe_TypeDef capsule, ADC_HandleTypeDef hadc);

void STATE_Started_Process(CAPSULE_Recipe_TypeDef capsule, ADC_HandleTypeDef hadc);

#endif /* INC_STATES_H_ */

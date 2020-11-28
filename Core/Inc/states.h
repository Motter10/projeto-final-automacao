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

#define STATE_SHOWING_CLOCK 0
#define STATE_STARTING_PROCESS 1

CAPSULE_Recipe_TypeDef STATE_Show_Clock();

uint8_t STATE_Start_Process(CAPSULE_Recipe_TypeDef capsule);

#endif /* INC_STATES_H_ */

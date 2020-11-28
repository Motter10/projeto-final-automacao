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

uint8_t STATE_Show_Clock();

uint8_t STATE_Start_Process();

#endif /* INC_STATES_H_ */

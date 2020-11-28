/*
 * capsule.h
 *
 *  Created on: Nov 28, 2020
 *      Author: sandr
 */

#ifndef INC_CAPSULE_H_
#define INC_CAPSULE_H_

#include "stm32f1xx_hal.h"

#define CAPSULE_BN1_PORT GPIOB

#define CAPSULE_BN1_BIT_0 GPIO_PIN_3
#define CAPSULE_BN1_BIT_1 GPIO_PIN_4
#define CAPSULE_BN1_BIT_2 GPIO_PIN_5

#define CAPSULE_INSERT_BUTTON GPIO_PIN_8

#define CAPSULE_RECIPE_WATER 			0b001
#define CAPSULE_RECIPE_SPARKLINK_WATER  0b010
#define CAPSULE_RECIPE_ICE_TEA			0b011
#define CAPSULE_RECIPE_HOT_TEA			0b100
#define CAPSULE_RECIPE_SODA				0b101

uint8_t CAPSULE_Verify_Insertion();

#endif /* INC_CAPSULE_H_ */

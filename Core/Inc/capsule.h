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

typedef enum {NONE_CAPSULE_TYPE, RECIPE_WATER, RECIPE_SPARKLINK_WATER, RECIPE_ICE_TEA, RECIPE_HOT_TEA, RECIPE_SODA} CAPSULE_Type;
typedef enum {NONE_WATER_TYPE, ICE_WATER, HOT_WATER, NATURAL_WATER} WATER_Type;

typedef struct
{
	CAPSULE_Type capsule_type;
	WATER_Type water_type;
	float water_time;
	float water_temp;
	float co2_time;
}CAPSULE_Recipe_TypeDef;
#define RECIPE_SPARKLINK_WATER_DATA(RECIPE) CAPSULE_Recipe_TypeDef RECIPE = {.capsule_type = RECIPE_SPARKLINK_WATER, .water_type = ICE_WATER, .water_time = 0,.water_temp = 0, .co2_time = 2}
//agua com gás
//#define RECIPE_NONE_TYPE_DATA(RECIPE) CAPSULE_Recipe_TypeDef RECIPE = { .capsule_type = NONE_CAPSULE_TYPE, 	\
//	.water_type = NONE_WATER_TYPE,		\
//	.water_time = 0.0,       			\
//	.water_temp = 0.0,       			\
//	.co2_time = 0.0}          			 \

//agua com gás
//#define RECIPE_SPARKLINK_WATER_DATA(RECIPE) CAPSULE_Recipe_TypeDef RECIPE = { .capsule_type = RECIPE_SPARKLINK_WATER, .water_type = NONE_WATER_TYPE, .water_time = 3.0,	.water_temp = 15.0,	.co2_time = 1.5	}
//chá gelado
//#define RECIPE_ICE_TEA_DATA(RECIPE) CAPSULE_Recipe_TypeDef RECIPE = { .capsule_type = RECIPE_ICE_TEA, 	\
//	.water_type = NONE_WATER_TYPE,		\
//	.water_time = 2.7,       			\
//	.water_temp = 20.0,       			\
//	.co2_time = 0.0         			 \
//	}

CAPSULE_Recipe_TypeDef CAPSULE_Verify_Insertion();

#endif /* INC_CAPSULE_H_ */

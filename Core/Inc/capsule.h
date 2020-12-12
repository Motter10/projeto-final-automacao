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
	char  capsule_name[16];
	uint32_t water_time;
	uint32_t water_temp;
	uint32_t co2_time;
}CAPSULE_Recipe_TypeDef;

#define RECIPE_NONE_CAPSULE_TYPE_DATA(RECIPE) CAPSULE_Recipe_TypeDef RECIPE = {.capsule_type = NONE_CAPSULE_TYPE, \
		.capsule_name = "Nenhuma", \
		.water_type = NONE_WATER_TYPE, \
		.water_time = 0,\
		.water_temp = 0,\
		.co2_time = 0}

#define RECIPE_WATER_DATA(RECIPE) CAPSULE_Recipe_TypeDef RECIPE = {.capsule_type = RECIPE_WATER, \
		.capsule_name = "Agua", \
		.water_type = NONE_WATER_TYPE, \
		.water_time = 3000,\
		.water_temp = 0,\
		.co2_time = 0}

#define RECIPE_SPARKLINK_WATER_DATA(RECIPE) CAPSULE_Recipe_TypeDef RECIPE = {.capsule_type = RECIPE_SPARKLINK_WATER, \
		.capsule_name = "Agua com gás", \
		.water_type = ICE_WATER, \
		.water_time = 3000,\
		.water_temp = 15,\
		.co2_time = 1500}

#define RECIPE_ICE_TEA_DATA(RECIPE) CAPSULE_Recipe_TypeDef RECIPE = {.capsule_type = RECIPE_ICE_TEA, \
		.capsule_name = "Chá gelado", \
		.water_type = ICE_WATER, \
		.water_time = 2700,\
		.water_temp = 20,\
		.co2_time = 0}

#define RECIPE_HOT_TEA_DATA(RECIPE) CAPSULE_Recipe_TypeDef RECIPE = {.capsule_type = RECIPE_HOT_TEA, \
		.capsule_name = "Chá quente", \
		.water_type = HOT_WATER, \
		.water_time = 2700,\
		.water_temp = 60,\
		.co2_time = 0}

#define RECIPE_SODA_DATA(RECIPE) CAPSULE_Recipe_TypeDef RECIPE = {.capsule_type = RECIPE_SODA, \
		.capsule_name = "Refrigerante", \
		.water_type = ICE_WATER, \
		.water_time = 4000,\
		.water_temp = 17,\
		.co2_time = 2560}

CAPSULE_Recipe_TypeDef CAPSULE_Verify_Insertion();

#endif /* INC_CAPSULE_H_ */

/*
 * capsule.c
 *
 *  Created on: Nov 28, 2020
 *      Author: sandr
 */

#include "capsule.h"
typedef struct
{

int id;

char *name;

} employee;


#define INIT_EMPLOYEE(X) employee X = {.id = 0, .name ="none"}

//CAPSULE_Type capsule_type;
//	WATER_Type water_type;
//	float water_time;
//	float water_temp;
//	float co2_time;
CAPSULE_Recipe_TypeDef CAPSULE_Verify_Insertion()
{
	uint8_t bit_0 = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_BN1_BIT_0);
	uint8_t bit_1 = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_BN1_BIT_1);
	uint8_t bit_2 = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_BN1_BIT_2);

	CAPSULE_Type recipe_type = bit_0 | (bit_1 << 1) | (bit_2 << 2);

//	CAPSULE_Recipe_TypeDef recipe;
//	switch (recipe_type) {
////		case NONE_CAPSULE_TYPE:
////			RECIPE_NONE_TYPE_DATA(recipe);
////			break;
//		case RECIPE_SPARKLINK_WATER:
//			RECIPE_SPARKLINK_WATER_DATA(recipe);
//			break;
//		default:
//			break;
//	}
	INIT_EMPLOYEE (emp);
	RECIPE_SPARKLINK_WATER_DATA(recipe);

	return recipe;
}

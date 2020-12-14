/*
 * capsule.c
 *
 *  Created on: Nov 28, 2020
 *      Author: sandr
 */

#include "capsule.h"

/**
 * @brief Verifica qual capsula foi inserida
 *
 *	Verifica se alguma capsula foi inserida e retorna a mesma.
 *	A capsula é verificada conforme os 3 bits formados por
 *	CAPSULE_BN1_BIT_0 - CAPSULE_BN1_BIT_1 - CAPSULE_BN1_BIT_2
 *
 * @retval CAPSULE_Recipe_TypeDef
 *
 */
CAPSULE_Recipe_TypeDef CAPSULE_Verify_Insertion()
{
	uint8_t bit_0 = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_BN1_BIT_0);
	uint8_t bit_1 = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_BN1_BIT_1);
	uint8_t bit_2 = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_BN1_BIT_2);

	//monta número que identifica capsula
	CAPSULE_Type capsule_type = bit_0 | (bit_1 << 1) | (bit_2 << 2);

	CAPSULE_Recipe_TypeDef recipe;

	//inicializa receitas
	RECIPE_NONE_CAPSULE_TYPE_DATA(recipe_none);
	RECIPE_WATER_DATA(recipe_water);
	RECIPE_SPARKLINK_WATER_DATA(recipe_sparklink_water);
	RECIPE_ICE_TEA_DATA(recipe_ice_tea);
	RECIPE_HOT_TEA_DATA(recipe_hot_tea);
	RECIPE_SODA_DATA(recipe_soda);

	switch (capsule_type) {
		case NONE_CAPSULE_TYPE:
			return recipe_none;
			break;
		case RECIPE_WATER:
				return recipe_water;
				break;
		case RECIPE_SPARKLINK_WATER:
			return recipe_sparklink_water;
			break;
		case RECIPE_ICE_TEA:
				return recipe_ice_tea;
				break;
		case RECIPE_HOT_TEA:
				return recipe_hot_tea;
				break;
		case RECIPE_SODA:
				return recipe_soda;
				break;
		default:
			return recipe_none;
			break;
	}

}

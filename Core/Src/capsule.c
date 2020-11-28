/*
 * capsule.c
 *
 *  Created on: Nov 28, 2020
 *      Author: sandr
 */

#include "capsule.h"

uint8_t CAPSULE_Verify_Insertion()
{
	uint8_t bit_0 = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_BN1_BIT_0);
	uint8_t bit_1 = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_BN1_BIT_1);
	uint8_t bit_2 = HAL_GPIO_ReadPin(CAPSULE_BN1_PORT, CAPSULE_BN1_BIT_2);

	uint8_t recipe = bit_0 | (bit_1 << 1) | (bit_2 << 2);
	return recipe;
}

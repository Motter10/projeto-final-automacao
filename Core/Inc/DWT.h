/*
 * DWT.h
 *
 *  Created on: Dec 15, 2020
 *      Author: sandr
 */

#ifndef INC_DWT_H_
#define INC_DWT_H_
#include "stm32f1xx_hal.h"

uint32_t DWT_Delay_Init(void);

void DWT_Delay_us(volatile uint32_t au32_microseconds);

#endif /* INC_DWT_H_ */

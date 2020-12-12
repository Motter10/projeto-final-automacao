/*
 * outputs.h
 *
 *  Created on: Dec 12, 2020
 *      Author: sandr
 */

#ifndef INC_OUTPUTS_H_
#define INC_OUTPUTS_H_

#include "stm32f1xx_hal.h"

typedef struct{
	uint32_t gpio_pin;
    uint32_t gpio_class;
}Output_TypeDef;

#define Y3(value) Output_TypeDef value = {.gpio_pin = GPIO_PIN_6, .gpio_class = GPIOB}
#define Y4(value) Output_TypeDef value = {.gpio_pin = GPIO_PIN_7, .gpio_class = GPIOB}

#endif /* INC_OUTPUTS_H_ */

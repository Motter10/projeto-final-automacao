/*
 * outputs.h
 *
 *  Created on: Dec 12, 2020
 *      Author: sandr
 */

#ifndef INC_IO_H_
#define INC_IO_H_

#include "stm32f1xx_hal.h"

typedef struct{
	uint32_t gpio_pin;
    uint32_t gpio_class;
}Output_TypeDef;

typedef enum {CONFIRM_PRESSED, CANCEL_PRESSED, INCREASE_PRESSED, DECREASE_PRESSED} Pressed_Type;

#define Y3(value) Output_TypeDef value = {.gpio_pin = GPIO_PIN_6, .gpio_class = GPIOB}
#define Y4(value) Output_TypeDef value = {.gpio_pin = GPIO_PIN_7, .gpio_class = GPIOB}

#define BUTTON_CONFIRMAR(value) Output_TypeDef value = {.gpio_pin = GPIO_PIN_11, .gpio_class = GPIOA}
#define BUTTON_CANCELAR(value) Output_TypeDef value = {.gpio_pin = GPIO_PIN_10, .gpio_class = GPIOA}
#define BUTTON_INCREASE(value) Output_TypeDef value = {.gpio_pin = GPIO_PIN_9, .gpio_class = GPIOA}
#define BUTTON_DECREASE(value) Output_TypeDef value = {.gpio_pin = GPIO_PIN_8, .gpio_class = GPIOA}

Pressed_Type Get_Button_Pressed();

#endif /* INC_IO_H_ */

/*
 * io.c
 *
 *  Created on: Dec 12, 2020
 *      Author: sandr
 */

#include "io.h"

/**
 * @brief Aguarda entrada do usuário
 *
 *	Retorna apenas após o usuário pressionar algum botão
 *
 * @retval Pressed_Type Tipo do botão pressionado
 *
 */
Pressed_Type Get_Button_Pressed()
{
	BUTTON_CONFIRMAR(confirm_button);
	BUTTON_CANCELAR(cancel_button);
	BUTTON_INCREASE(increase_button);
	BUTTON_DECREASE(decrease_button);

	while(1)
	{
		if(HAL_GPIO_ReadPin(confirm_button.gpio_class, confirm_button.gpio_pin)){
			return CONFIRM_PRESSED;
		}
		if(HAL_GPIO_ReadPin(cancel_button.gpio_class, cancel_button.gpio_pin)){
			return CANCEL_PRESSED;
		}
		if(HAL_GPIO_ReadPin(increase_button.gpio_class, increase_button.gpio_pin)){
			return INCREASE_PRESSED;
		}
		if(HAL_GPIO_ReadPin(decrease_button.gpio_class, decrease_button.gpio_pin)){
			return DECREASE_PRESSED;
		}
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
		HAL_Delay(300);
	}
}

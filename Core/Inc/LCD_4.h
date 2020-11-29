/*
 * LCD_4.h
 *
 *  Created on: Oct 27, 2020
 *      Author: sandro
 */

#ifndef INC_LCD_4_H_
#define INC_LCD_4_H_

#include <stdint.h>
#include <stdbool.h>


#include "stm32f1xx_hal.h"

#define CTRL_PINS GPIOB
#define RS GPIO_PIN_9
#define RW GPIO_PIN_10
#define EN GPIO_PIN_11

#define DATA_PINS GPIOB
#define FRST_PIN GPIO_PIN_12

void LCD_Send();

void LCD_Write(uint8_t data, bool is_data);

void LCD_Write_Number(int16_t);

void LCD_Write_Buffer(uint8_t* data);

void LCD_Clear();

void LCD_Shift_Left();

void LCD_Shift_Right();

void LCD_First_Line();

void LCD_Seccond_Line();

void LCD_Create_Custom_Char(uint8_t loc, uint8_t *msg);

void LCD_Init_Custom_Characters();

void LCD_Init();

#endif /* INC_LCD_4_H_ */

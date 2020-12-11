/*
 * ADC.h
 *
 *  Created on: Nov 29, 2020
 *      Author: sandr
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "stm32f1xx_hal.h"

#include "utils.h"
#include "LCD_4.h"
#include "capsule.h"

#define ADC_SCALE (3.3/4095)
#define NUMBER_OF_CONVERSTION	4

//ordena conforme vetor adc_data
typedef enum{IN7 = 3, IN6 = 0, IN_5 = 1, IN_4 = 2} ADC_CHANNEL_Id;

#define P1  IN6
#define P2  IN7

extern uint32_t adc_data[NUMBER_OF_CONVERSTION];
extern uint8_t adc_data_ready;

#endif /* INC_ADC_H_ */

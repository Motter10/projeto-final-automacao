/*
 * utils.h
 *
 *  Created on: 28 de nov de 2020
 *      Author: sandr
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_

#include <stdint.h>
#include <time.h>
#include "stm32f1xx_hal.h"
void UTILS_get_Hour(char *hour, RTC_HandleTypeDef hrtc);

uint32_t UTILS_To_Temp(uint32_t value);

#endif /* INC_UTILS_H_ */

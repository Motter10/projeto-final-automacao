/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TIM2_CH1_____R1_Pin GPIO_PIN_0
#define TIM2_CH1_____R1_GPIO_Port GPIOA
#define TIM2_CH2_____CP1_Pin GPIO_PIN_1
#define TIM2_CH2_____CP1_GPIO_Port GPIOA
#define TIM2_CH3_____B1_Pin GPIO_PIN_2
#define TIM2_CH3_____B1_GPIO_Port GPIOA
#define ADC1_IN4_____T1_Pin GPIO_PIN_4
#define ADC1_IN4_____T1_GPIO_Port GPIOA
#define ADC1_IN5_____T2_Pin GPIO_PIN_5
#define ADC1_IN5_____T2_GPIO_Port GPIOA
#define ADC1_IN6_____P1_Pin GPIO_PIN_6
#define ADC1_IN6_____P1_GPIO_Port GPIOA
#define ADC1_IN7_____P2_Pin GPIO_PIN_7
#define ADC1_IN7_____P2_GPIO_Port GPIOA
#define Y1_Pin GPIO_PIN_0
#define Y1_GPIO_Port GPIOB
#define Y2_Pin GPIO_PIN_1
#define Y2_GPIO_Port GPIOB
#define Display_RW_Pin GPIO_PIN_10
#define Display_RW_GPIO_Port GPIOB
#define Display_EN_Pin GPIO_PIN_11
#define Display_EN_GPIO_Port GPIOB
#define Display_D4_Pin GPIO_PIN_12
#define Display_D4_GPIO_Port GPIOB
#define Display_D5_Pin GPIO_PIN_13
#define Display_D5_GPIO_Port GPIOB
#define Display_D6_Pin GPIO_PIN_14
#define Display_D6_GPIO_Port GPIOB
#define Display_D7_Pin GPIO_PIN_15
#define Display_D7_GPIO_Port GPIOB
#define Button_Increase_Pin GPIO_PIN_11
#define Button_Increase_GPIO_Port GPIOA
#define Button_Confirmar_Pin GPIO_PIN_12
#define Button_Confirmar_GPIO_Port GPIOA
#define BN1_Bit_0_Pin GPIO_PIN_3
#define BN1_Bit_0_GPIO_Port GPIOB
#define BN1_bit_1_Pin GPIO_PIN_4
#define BN1_bit_1_GPIO_Port GPIOB
#define BN1_bit_2_Pin GPIO_PIN_5
#define BN1_bit_2_GPIO_Port GPIOB
#define Y3_Pin GPIO_PIN_6
#define Y3_GPIO_Port GPIOB
#define Y4_Pin GPIO_PIN_7
#define Y4_GPIO_Port GPIOB
#define Inserir_Capsula_Pin GPIO_PIN_8
#define Inserir_Capsula_GPIO_Port GPIOB
#define Display_RS_Pin GPIO_PIN_9
#define Display_RS_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

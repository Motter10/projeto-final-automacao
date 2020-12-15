/*
 * statetements.c
 *
 *  Created on: 28 de nov de 2020
 *      Author: sandr
 */

#include "controller.h"
#include "states.h"

/**
 * @brief Estado Inicial, mostrando relógio
 *
 *	Fica mostrando relógio no display, após capsula ser inserida retorna a mesma.
 *
 * @retval CAPSULE_Recipe_TypeDef capsula inserida
 *
 */
CAPSULE_Recipe_TypeDef STATE_Show_Clock(RTC_HandleTypeDef hrtc)
{
	char hour[10];
	CAPSULE_Recipe_TypeDef capsule = {
			.capsule_type = NONE_CAPSULE_TYPE,
	};
	uint8_t insert_button = 0;

	LCD_Clear();
	while(1)
	{
		UTILS_get_Hour(hour, hrtc);
		LCD_First_Line();
		LCD_Write_Buffer(hour);

		BUTTON_CONFIRMAR(confirm_button);
		insert_button = HAL_GPIO_ReadPin(confirm_button.gpio_class, confirm_button.gpio_pin);

		//se botão de inserir capsula for pressionado, verifica  qual é a receita
		if(insert_button)
		{
			capsule = CAPSULE_Verify_Insertion();
		}

		//se tiver uma cápsula, retorna
		if(capsule.capsule_type != NONE_CAPSULE_TYPE ){

			return capsule;
		}
		DWT_Delay_us(300000);
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_12);
	}
}


/**
 * @brief Iniciando processo
 *
 * Aguarda entradas do usuário, para inicar ou cancelar o processo.
 *
 * @retval CAPSULE_Recipe_TypeDef receita da capsula inserida, se cancelar usuário cancelar inicio, retorna vazia
 * @param capsule capsula que foi inserida
 * @param hadc objeto do ADC_1
 */
CAPSULE_Recipe_TypeDef STATE_Starting_Process(CAPSULE_Recipe_TypeDef capsule, ADC_HandleTypeDef hadc)
{
	uint8_t confirm_button = 0;

	LCD_Clear();
	LCD_Write_Buffer(capsule.capsule_name);
	LCD_Seccond_Line();
	LCD_Write_Buffer("Aguarde...");

	GPIO_PinState pin_state;

	uint32_t init_time = HAL_GetTick();
	uint32_t current_time = init_time;
	uint32_t last_time = init_time;
	while(current_time < (init_time + 2000)){
		current_time = HAL_GetTick();
		if(current_time > last_time + 300){
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_12);
				last_time = current_time;

			}
	}

	//se for apenas água, escolhe entre quente, natural e gelada.
	if(capsule.capsule_type == RECIPE_WATER)
	{
		//vetor para mostrar no display
		char choices[CHOICES_NUMBER][16] = {"Natural", "Gelada  ", "Quente  "};
		//vetor para obter qual informação foi escolhida
		WATER_Type choices_values[CHOICES_NUMBER] = {NATURAL_WATER, ICE_WATER, HOT_WATER};

		//vetor para obter qual temparatura foi escolhida, perguntar para Professor
		uint32_t choices_values_temp[CHOICES_NUMBER] = {0, 20, 60};


		LCD_Clear();
		uint8_t choice_index = 0;
		LCD_Seccond_Line();
		LCD_Write_Buffer("I-D p/ alterar");
		while(1){
			LCD_First_Line();
			LCD_Write_Buffer(choices[choice_index]);

			Pressed_Type pressed_type = Get_Button_Pressed();
			switch (pressed_type) {
				case CONFIRM_PRESSED:
					capsule.water_type = choices_values[choice_index];
					capsule.water_temp = choices_values_temp[choice_index];
					goto choiced;
					break;
				case CANCEL_PRESSED:
					capsule.capsule_type = NONE_CAPSULE_TYPE;
					goto choiced;
					break;
				case INCREASE_PRESSED:
					choice_index = (choice_index < CHOICES_NUMBER - 1) ? choice_index + 1 : 0;
					break;
				case DECREASE_PRESSED:
					choice_index = (choice_index > 0) ? choice_index - 1 : CHOICES_NUMBER - 1;
					break;
				default:
					break;
			}

		}
		choiced: ;
	}


	LCD_Clear();
	LCD_Write_Buffer("S --> Iniciar.");
	LCD_Seccond_Line();
	LCD_Write_Buffer("C --> Cancelar.");

	int32_t sensor_signal = 0;
	float avg_value_P1 = 0;
	float avg_value_P2 = 0;

	int32_t var = 0;
	for (var = 0; var < 32; ++var) {
		sensor_signal += ADC_GetValue(hadc, P1);
	}

	avg_value_P1 = sensor_signal / var;

	//se P1 passar do nivel considerado saturado....
	if(avg_value_P1 > 3000){
		LCD_Clear();
		LCD_Write_Buffer("P1 SATURADO!");
		HAL_Delay(2000);
		RECIPE_NONE_CAPSULE_TYPE_DATA(none_capsule);
		return none_capsule;
	}

	//se receita precisar de CO2, verifica se está P2 saturado
	if(capsule.co2_time > 0)
	{
		sensor_signal = 0;
		for (var = 0; var < 32; ++var) {
			sensor_signal += ADC_GetValue(hadc, P2);
		}

		avg_value_P2 = sensor_signal / var;

		//se P2 passar do nivel considerado saturado....
		if(avg_value_P2 > 3000){
			LCD_Clear();
			LCD_Write_Buffer("P2 SATURADO!");
			HAL_Delay(2000);
			RECIPE_NONE_CAPSULE_TYPE_DATA(none_capsule);
			return none_capsule;
		}
	}

	while(1)
	{

		Pressed_Type pressed_type = Get_Button_Pressed();
		if(pressed_type == CONFIRM_PRESSED)
		{
			return capsule;
		}
		if(pressed_type == CANCEL_PRESSED)
		{
			capsule.capsule_type = NONE_CAPSULE_TYPE;
			return capsule;
		}

		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_12);
		HAL_Delay(300);
	}
}

/**
 * @brief Precesso iniciado
 *
 * Aguarda controlador e despeja água na capsula inserida;
 *
 * @retval CAPSULE_Recipe_TypeDef receita da capsula inserida, se cancelar usuário cancelar inicio, retorna vazia
 * @param capsule capsula que foi inserida
 * @param hadc objeto do ADC_1
 */
void STATE_Started_Process(CAPSULE_Recipe_TypeDef capsule, ADC_HandleTypeDef hadc)
{
	LCD_Clear();
	LCD_Write_Buffer("Iniciando...");

	uint32_t init_time = HAL_GetTick();
	uint32_t current_time = init_time;
	uint32_t last_time = init_time;

	while(current_time < (init_time + 2000)){
		current_time = HAL_GetTick();

		if(current_time > last_time + 300){
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_12);
			last_time = current_time;

		}
	}

	uint8_t confirm_button = 0;
	while(1)
	{
		CONTROLLER_Execute(hadc, capsule);

		return;

	}
}

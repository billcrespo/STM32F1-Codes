/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "stm32f1xx.h"
			
void SystemClock_Config(void);
static void GPIO_Init(void);
static void TIM1_Init(void);

GPIO_InitTypeDef GPIO_InitStruct;
TIM_HandleTypeDef htim1;

int main(void)
{
	HAL_Init();

	SystemClock_Config();

	GPIO_Init();
	TIM1_Init();

	HAL_NVIC_SetPriority(TIM1_UP_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(TIM1_UP_IRQn);

	HAL_TIM_Base_Init(&htim1);
	HAL_TIM_Base_Start_IT(&htim1);


	while(1);

}
void TIM1_UP_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim1);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == TIM1)
	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
}
void TIM1_Init(void)
{
	__HAL_RCC_TIM1_CLK_ENABLE();

	htim1.Instance = TIM1;
	htim1.Init.Prescaler = 31999; //64MHz/32000 = 2000Hz
	htim1.Init.Period = 999;      //2000HZ / 1000 = 2Hz = 0.5s
}

void GPIO_Init(void)
{
	__HAL_RCC_GPIOB_CLK_ENABLE();

	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);

	 GPIO_InitStruct.Pin = GPIO_PIN_10;
	 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	 HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

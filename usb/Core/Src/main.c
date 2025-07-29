/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

static void init_clock(){

	RCC->CR |= RCC_CR_HSEON;

	//Configure PLL
	RCC -> CR &= ~RCC_CR_PLLON; //PLL off, in standby mode
	while(RCC -> CR & RCC_CR_PLLRDY){ //Make sure PLL is locked

	}
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;



}



int main(void)
{


	while(1){

	}

}

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include <string.h>
#include <stdint.h>
extern "C"
{
#include"cmsis_os.h"
#include "app.h"
#include "peripherals.h"
#include "usb_host.h"
}
/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  peripherals_init();
  app_init();
  osKernelStart();

  while (1)
  {

  }
}



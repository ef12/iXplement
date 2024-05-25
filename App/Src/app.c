#include "app.h"
#include "peripherals.h"
#include "cmsis_os.h"

osThreadId defaultTaskHandle;

void StartDefaultTask(void const * argument);

void app_init(void)
{
  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 4096);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);
}




  /* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  static uint32_t task_delay = 50;
  /* Infinite loop */
  for(;;)
  {
	  HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
    if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) != GPIO_PIN_RESET)
    {
      if (50 == task_delay)
      {
        task_delay = 250;
      }
      else
      {
        task_delay = 50;
      }
      /* Some Debouncing */
      osDelay(100);
    }
    osDelay(task_delay);
  }
  /* USER CODE END 5 */
}
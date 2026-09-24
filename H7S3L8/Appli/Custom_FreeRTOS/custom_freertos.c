#include "custom_freertos.h"
#include "FreeRTOS.h"
#include <task.h>

void vBasicTask(void *) {
	int x=0;
	for(;;) {
		x++;
		vTaskDelay(1000);
	}
}

int main(void) {
	TaskHandle_t xHandle = NULL;

	xTaskCreate((TaskFunction_t)vBasicTask, "BasicTask", (configSTACK_DEPTH_TYPE)512, (void *) 0, tskIDLE_PRIORITY, &xHandle);

	vTaskStartScheduler();
	return 0;
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
}



//
//impor queue.c
//
//read()
// c.queueSend

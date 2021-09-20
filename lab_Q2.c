#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>

void task_first(void *data)
{
	while(1)
	{
		printf("Task1 created\n");
		printf("Task1 ended\n");
		vTaskDelay(1000/portTICK_PERIOD_MS);
	}
}

void task_second(void *data)
{
	while(1)
	{
		printf("Task2 created\n");
		printf("Task2 ended\n");
		vTaskDelay(2000/portTICK_PERIOD_MS);
	}
}

void task_third(void *data)
{
	while(1)
	{
		printf("Task1 created\n");
		printf("Task2 ended\n");
		vTaskDelay(5000/portTICK_PERIOD_MS);
	}
}


void app_main(void)
{
   int i=0;
   xTaskCreate(task_first,"task1",2048,NULL,20,NULL);
   xTaskCreate(task_second,"task2",2048,NULL,10,NULL);
   xTaskCreate(task_third,"task3",2048,NULL,20,NULL);

   while(1)
   {
	   printf("[%d] Hello world!\n", i);
	   i++;
	   vTaskDelay(5000/portTICK_PERIOD_MS);
   }
}
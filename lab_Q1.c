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

void task_fourth(void *data)
{
        BaseType_t xHigherPriorityTaskWoken1;
        xHigherPriorityTaskWoken1 = pdTRUE;
        int var=0;
        int buff1;

        while(1)
        {
                printf("task 4 created\n");
                var++;
                xQueueSendFromISR(mque,&var,NULL);
                printf("integer sended\n");
                xQueueReceiveFromISR(mque,&buff1,NULL);
                printf("int recieved from buff 1:%d\n",buff1);
                printf("Task ended\n");
                vTaskDelay(1000/portTICK_PERIOD_MS);
        }
}

void task_fifth(void *data)
{
        BaseType_t xHigherPriorityTaskWoken2;
        xHigherPriorityTaskWoken1 = pdFALSE;
        int var1=0;
        int buff;

        while(1)
        {
                printf("task 5 created\n");
                var++;
                xQueueSendFromISR(mque,&buff,NULL);
                printf("integer sended\n");
                xQueueReceiveFromISR(mque,&buff1,NULL);
                printf("int recieved from buff 1:%d\n",buff1);
                printf("Task ended\n");
                vTaskDelay(1000/portTICK_PERIOD_MS);
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





#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

void *const timer_id;
TimerHandle_t timer_handle;

void task1(void *data)
	{
		while(1)
			{
				printf(" task1 created\n");
				//................
				printf(" task1 ended\n");
				vTaskDelay(1000/portTICK_PERIOD_MS);
			}
	}

 
void task2(void *data)
	{
		while(1)
			{
				printf(" task2 created\n");
				//................
				printf(" task2 ended\n");
				vTaskDelay(2000/portTICK_PERIOD_MS);
			}
	}


void task3(void *params)
{
    timer_handle = xTimerCreate("timer",(10000 / portTICK_PERIOD_MS),pdFALSE,timer_id, callback);

    xTimerStart(my_timer_handle, 1);
    while (1)
    {
        printf("task3 created \n");
        
        printf("task3 ended\n");
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
void callback(TimerHandle_t xTimer)
{
    printf("Callback\n");
}
 
 
void app_main(void)
{
		int i=0;
		xTaskCreate(task1,"task1",1024,NULL,3,NULL);
		
		xTaskCreate(task2,"task2",1024,NULL,2,NULL);
		
		xTaskCreate(task3,"task3",1024,NULL,1,NULL);
		while(1)
			{
				printf("[%d] in main --Hello World!\n",i);
				i++;
				vTaskDelay(2000/portTICK_PERIOD_MS);
			}

}




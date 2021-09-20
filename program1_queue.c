#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
QueueHandle_t xQ1;
void Tone(void *data)
{
	while(1)
	{


	printf("Task (T1) started\n");
	
	printf("Task (T1) ended\n");
	vTaskDelay(1000/portTICK_PERIOD_MS);
	}
}
void Ttwo(void *data)
{
	while(1)
	{


	printf("Task (T2) started\n");
	
	printf("Task (T2) ended\n");
	vTaskDelay(2000/portTICK_PERIOD_MS);
}
	
}
void Tthree(void *data)
{
	while(1)
	{

	
	printf("Task (T3) started\n");
	
	printf("Task (T3) ended\n");
	vTaskDelay(5000/portTICK_PERIOD_MS);
	}
}
void Tfour(void *data)
{
int var=10;
while(1)
{
		xQueueSend(xQ1,&var,0);
		vTaskDelay(3000/portTICK_PERIOD_MS);
}
}

 void Tfive(void *data)
 {
 	while(1)
 	{


 		int buff;
 		xQueueReceive(xQ1,&buff,0);
 		
 			printf("In Task 5 received message from Task 4 is %d\n",buff);
 		vTaskDelay(3000/portTICK_PERIOD_MS);
 	}
 }
void app_main(void)
	{
		xTaskCreate(Tone,"Task_1",2048,NULL,10,NULL);
		xTaskCreate(Ttwo,"Task_2",2048,NULL,6,NULL);
		xTaskCreate(Tthree,"Task_3",2048,NULL,5,NULL);
		xTaskCreate(Tfour,"Task_4",2048,NULL,3,NULL);
		xTaskCreate(Tfive,"Task_5",2048,NULL,1,NULL);
		xQ1= xQueueCreate(3,sizeof(int));
	}

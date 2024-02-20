#include <stm32746g_discovery_qspi.h>
#include "SerialRx.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "main.h"
#include <string.h>
#include <stdio.h>

TaskHandle_t taskHandler;

uint8_t receivedData[100];

uint8_t speed;
uint8_t pitch;
uint8_t roll;
uint16_t altitude;

const char delimiter[] = " ";
char *token;


void Serial_Task(void *pArg);


void CreateSerialTask(){


	//printf("Hello There");
	//Check Serial output

	xTaskCreate(Serial_Task, "Serial_Task", 128, NULL, 1, NULL);


}


void Serial_Task(void *pArg){
	HAL_UART_Receive_DMA(&huart1, receivedData, 100);
	while (1) {




		//vTaskDelay(200);

	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	HAL_UART_Receive_DMA(&huart1, receivedData, 100);
	char *s = receivedData;
	   token = strtok(s, delimiter);
	   if (token != NULL) {
		   speed = atoi(token);
		   token = strtok(NULL, delimiter);
		   if (token != NULL) {
			   //var2 = atoi(token);
			   token = strtok(NULL, delimiter);
			   if (token != NULL) {
				   //var3 = atoi(token);
				   token = strtok(NULL, delimiter);
				   if (token != NULL) {
					   altitude = atoi(token);
				   }
			   }
		   }
	   }
}







#include <stm32746g_discovery_qspi.h>
#include "SerialRx.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

TaskHandle_t taskHandler;

uint8_t receivedData[100];

uint8_t speed;
float pitch;
float roll;
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
			   pitch = atof(token);
			   token = strtok(NULL, delimiter);
			   if (token != NULL) {
				   roll = atof(token);
				   token = strtok(NULL, delimiter);
				   if (token != NULL) {
					   altitude = atoi(token);
				   }
			   }
		   }
	   }
}







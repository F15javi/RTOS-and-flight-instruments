#include <stm32746g_discovery_qspi.h>
#include "Serial.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include "usbd_cdc_if.h"
#include "cmsis_os.h"

TaskHandle_t taskHandler;


uint8_t rx_buffer[100];





typedef struct{
		uint16_t speed;
		float pitch;
		float roll;
		uint16_t altitude;
		float heading;
	}RX_Data;

RX_Data Telemetry;

const char delimiter[] = " ";

char *token;

void Serial_RX(void *pArg);
void Serial_TX(void *pArg);


osMessageQueueId_t DataToDisplayHandle;
	const osMessageQueueAttr_t DataToDisplay_attributes = {
	  .name = "DataToDisplay"
	};

void CreateSerialTask(){




	DataToDisplayHandle = osMessageQueueNew (1, sizeof(RX_Data), &DataToDisplay_attributes);


	xTaskCreate(Serial_RX, "Serial_Rx", 128, NULL, 1, NULL);
	//xTaskCreate(Serial_TX, "Serial_Tx", 128, NULL, 1, NULL);




}
void Serial_TX(void *pArg){

	//char *data = "Hello there\n";
	//CDC_Transmit_FS((uint8_t *) data, 100);

	vTaskDelay(300);
}



void Serial_RX(void *pArg){


	while (1) {
	    //osSemaphoreWait(BinarySemaphoreUARTHandle, osWaitForever);

		if(HAL_UART_Receive_DMA(&huart2, rx_buffer, 100) != HAL_OK)
		  {
		    Error_Handler();

		  }
		if(huart2.hdmarx->ErrorCode == HAL_DMA_ERROR_NO_XFER) {

		    Error_Handler();


		  }


	}
}
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart){
	Error_Handler();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(HAL_UART_Receive_DMA(&huart2, rx_buffer, 100) != HAL_OK)
	{
		Error_Handler();
	}

    if (huart->Instance == USART1){
        //osSemaphoreRelease(BinarySemaphoreUARTHandle);
    	char *s = rx_buffer;
		   token = strtok(s, delimiter);
		   if (token != NULL) {
			   Telemetry.speed = atoi(token);
			   token = strtok(NULL, delimiter);
			   if (token != NULL) {
				   Telemetry.pitch = atof(token);
				   token = strtok(NULL, delimiter);
				   if (token != NULL) {
					   Telemetry.roll = atof(token);
					   token = strtok(NULL, delimiter);
					   if (token != NULL) {
						   Telemetry.heading = atof(token);
							token = strtok(NULL, delimiter);
						   if (token != NULL) {
							   Telemetry.altitude = atoi(token);
						   }
					   }
				   }
			   }
		   }

	   osMessageQueuePut(DataToDisplayHandle, &Telemetry, 0, 0);
	   vTaskDelay(15);
    }
}

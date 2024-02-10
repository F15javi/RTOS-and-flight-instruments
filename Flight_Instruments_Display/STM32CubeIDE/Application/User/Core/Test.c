#include <stm32746g_discovery_qspi.h>
#include "Test.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "main.h"


TaskHandle_t taskHandler;

volatile uint8_t receivedData[9];

void Serial_Test(void *pArg);


void CreateTestTask(){


	//printf("Hello There");
	//Check Serial output

	xTaskCreate(Serial_Test, "Serial_Test", 128, NULL, 1, NULL);


}


void Serial_Test(void *pArg){
	HAL_UART_Receive_DMA(&huart1, receivedData, 9);
	while (1) {




		//vTaskDelay(200);

	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	HAL_UART_Receive_DMA(&huart1, receivedData, 9);

}







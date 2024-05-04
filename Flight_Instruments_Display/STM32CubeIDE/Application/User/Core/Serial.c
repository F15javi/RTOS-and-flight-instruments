#include <stm32746g_discovery_qspi.h>
#include "Serial.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "cmsis_os.h"

TaskHandle_t taskHandler;


uint8_t buffer_RX[64];
uint8_t receivedData[64];

uint16_t speed;
float pitch;
float roll;
uint16_t altitude;
float heading;
uint16_t rpm;
float Fuel_flow;
uint16_t ENG_temp;
uint16_t Oil_p;
uint16_t Oil_t;
float Fuel_tank1;
float Fuel_Tank2;


typedef struct{
		uint16_t speed;
		float pitch;
		float roll;
		uint16_t altitude;
		float heading;
		uint16_t rpm;
		float Fuel_flow;
		uint16_t ENG_temp;
		uint16_t Oil_p;
		uint16_t Oil_t;
		float Fuel_tank1;
		float Fuel_Tank2;


	}RX_Data;

RX_Data Telemetry;

const char delimiter[] = " ";
char *token;


void Serial_RX(void *pArg);
void Serial_TX(void *pArg);


//osMessageQueueId_t DataToDisplayHandle;
//	const osMessageQueueAttr_t DataToDisplay_attributes = {
//	  .name = "DataToDisplay"
//	};



void CreateSerialTask(){

	//DataToDisplayHandle = osMessageQueueNew (1, sizeof(RX_Data), &DataToDisplay_attributes);

	//Check Serial output

	xTaskCreate(Serial_RX, "Serial_Rx", 128, NULL, 1, NULL);
	//xTaskCreate(Serial_TX, "Serial_Tx", 128, NULL, 1, NULL);


}



void Serial_RX(void *pArg){

	uint8_t cmp = 0;

	while (1) {

		memcpy(receivedData, buffer_RX, 64);

		if(receivedData[0] == 0x31){

			char *s = (char *)receivedData;
			token = strtok(s, delimiter);
			if (token != NULL) {
			   token = strtok(NULL, delimiter);
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
							   heading = atof(token);
								token = strtok(NULL, delimiter);
							   if (token != NULL) {
								   altitude = atoi(token);
									token = strtok(NULL, delimiter);
									if (token != NULL) {
										rpm = atoi(token);
										token = strtok(NULL, delimiter);
										if (token != NULL) {
											Fuel_flow = atof(token);
										}
									}
								}
						   }
					   }
				   }
				}
			}

		}
		if(receivedData[0] == 0x32){

			char *d = (char *)receivedData;
			token = strtok(d, delimiter);
			if (token != NULL) {
				token = strtok(NULL, delimiter);
				if (token != NULL) {
					ENG_temp = atoi(token);
					token = strtok(NULL, delimiter);
					if (token != NULL) {
						Oil_p = atoi(token);
						token = strtok(NULL, delimiter);
						if (token != NULL) {
							Oil_t = atoi(token);
							token = strtok(NULL, delimiter);
							if (token != NULL) {
								Fuel_tank1 = atof(token);
								token = strtok(NULL, delimiter);
								if (token != NULL) {
									Fuel_Tank2 = atof(token);
								}
							}
						}
					}
				}
			}

		}
	}
}







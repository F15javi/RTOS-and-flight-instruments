#ifndef SRC_SERIALTASK_H_
#define SRC_SERIALTASK_H_

#include <stm32746g_discovery_qspi.h>
#include "FreeRTOS.h"
#include "task.h"

extern TaskHandle_t taskHandler;



void Serial_RX(void *pArg);
void Serial_TX(void *pArg);

void CreateSerialTask();
#endif /* SRC_SERIALTASK_H_ */

#ifndef SRC_TESTTASK_H_
#define SRC_TESTTASK_H_

#include <stm32746g_discovery_qspi.h>
#include "FreeRTOS.h"
#include "task.h"

extern TaskHandle_t taskHandler;



void Serial_Test(void *pArg);

void CreateTestTask();
#endif /* SRC_TESTTASK_H_ */

#include <stm32746g_discovery_qspi.h>
#include "Render_time.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "cmsis_os.h"





uint8_t avgFps;
uint8_t avgDelay;




void Render_time_task(void *pArg);


void CreateRenderTask(){

	xTaskCreate(Render_time_task, "Render_time_task", 128, NULL, 1, NULL);

}


void Render_time_task(void *pArg){
	uint32_t frameStart = 0;
	static uint32_t frameEnd = 0;

	static GPIO_PinState old_frame_state = GPIO_PIN_RESET;
	GPIO_PinState current_frame_state = GPIO_PIN_RESET;

	int i = 0;

	uint16_t sumDelay;
	uint8_t frameDelay;

	while (1) {




		current_frame_state = HAL_GPIO_ReadPin(FRAME_RATE_GPIO_Port, FRAME_RATE_Pin);

	    if(current_frame_state != old_frame_state){

	    	frameStart = HAL_GetTick();
			frameDelay = (frameStart - frameEnd);


	    	old_frame_state = current_frame_state;
	    	frameEnd = frameStart;
	    }


		if(i < 60){

			sumDelay += frameDelay;
			i++;
		}
		if(i >= 59){

			avgDelay = sumDelay/60;
			if(avgDelay != 0){
				avgFps = 1000/avgDelay;
			}
			sumDelay = 0;
			i = 0;
		}


	}
}








/*
 * Sound.c
 *
 *  Created on: Apr 21, 2024
 *      Author: f15ja
 */
#include <stm32746g_discovery_qspi.h>
#include "Sound.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cmsis_os.h"
#include "fatfs.h"
#include "wav.h"
#include "../../Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.h"

void SoundTask(void *pArg);

FRESULT res;
uint32_t i = 0;          /* Total bytes read */

void CreateSoundTask() {

	xTaskCreate(SoundTask, "SoundTask", 256, NULL, 1, NULL);

}

void play_wav_file(char *file) {

	struct Wav_Header header;
	uint32_t bytesread = 0; /* File write/read counts */
	uint64_t i = 0;
	uint8_t rtext[_MAX_SS];  /* File read buffer */


	res = 	res = f_mount(&SDFatFS, (TCHAR const*) SDPath, 0);

	//Open file for writing (Create)
	res = f_open(&SDFile, file, FA_READ);

	//Read the header of the Wav file
	f_read(&SDFile, &header, 40, (void *)&bytesread);

	while(1){
		/* Get Data from USB Flash Disk */
		f_lseek(&SDFile, i);
		f_read(&SDFile,&rtext, _MAX_SS, (void *)&bytesread);
		if(bytesread == 0){
			BSP_AUDIO_OUT_Stop(CODEC_PDWN_SW);

			res = f_close(&SDFile);

			vTaskDelete(NULL);


		}else{
			vTaskDelay(10);
			BSP_AUDIO_OUT_Play((uint16_t*)&rtext, _MAX_SS);

		}
		i += bytesread;


	}


}

void SoundTask(void *pArg) {

    /*Adjust the Audio frequency */

	const char *file = "helloThere.wav";



	//xTaskCreate(play_wav_file, "PlaySound", 4096, file, 2, NULL);


	while (1) {

		xTaskCreate(play_wav_file, "PlaySound", 4096, file, 2, NULL);
		vTaskDelay(10000);

	}

}

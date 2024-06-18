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
char *file = "helloThere.wav";


extern uint16_t rad_alt;
extern float flapsPos;
extern uint16_t vvi;
extern osMessageQueueId_t GuiToTaskLandingHandle;
static TaskHandle_t h_SoundTask = NULL, h_playsound = NULL;

void SoundTask(void *pvParameters);
void play_wav_file(char *file);

void CreateSoundTask() {

	xTaskCreate(SoundTask, "SoundTask", 256, NULL, 1, &h_SoundTask);

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
	f_read(&SDFile, &header, 44, (void *)&bytesread);

	while(1){
		/* Get Data from USB Flash Disk */
		f_lseek(&SDFile, i);
		f_read(&SDFile,&rtext, _MAX_SS, (void *)&bytesread);
		if(bytesread == 0){
			BSP_AUDIO_OUT_Stop(CODEC_PDWN_SW);

			res = f_close(&SDFile);
	        xTaskNotifyGive(h_SoundTask);

			vTaskDelete(NULL);


		}else{
			vTaskDelay(10);
			BSP_AUDIO_OUT_Play((uint16_t*)&rtext, _MAX_SS);

		}
		i += bytesread;


	}


}

uint8_t check_gpws(){

	uint8_t checkTaskCreation = 0;

	//The plane is going to land
	static uint8_t msg;
	osMessageQueueGet(GuiToTaskLandingHandle, &msg, NULL, 0);

	if(msg == 1){

		if(rad_alt <= 1020 && rad_alt > 990){

			checkTaskCreation = 1;
			file = "1000FT.wav";
			xTaskCreate(play_wav_file, "PlaySound", 4096, file, 24, &h_playsound);


		}else if (rad_alt <= 505 && rad_alt > 490) {

			checkTaskCreation = 1;
			file = "500FT.wav";
			xTaskCreate(play_wav_file, "PlaySound", 4096, file, 24, &h_playsound);

		}else if (rad_alt <= 405 && rad_alt > 390) {

			checkTaskCreation = 1;
			file = "400FT.wav";
			xTaskCreate(play_wav_file, "PlaySound", 4096, file, 24, &h_playsound);

		}else if (rad_alt <= 305 && rad_alt > 290) {

			checkTaskCreation = 1;
			file = "300FT.wav";
			xTaskCreate(play_wav_file, "PlaySound", 4096, file, 24, &h_playsound);

		}else if (rad_alt <= 205 && rad_alt > 190) {

			checkTaskCreation = 1;
			file = "200FT.wav";
			xTaskCreate(play_wav_file, "PlaySound", 4096, file, 24, &h_playsound);

		}else if (rad_alt <= 105 && rad_alt > 90) {

			checkTaskCreation = 1;
			file = "100FT.wav";
			xTaskCreate(play_wav_file, "PlaySound", 4096, file, 24, &h_playsound);

		}else if (rad_alt <= 55 && rad_alt > 50) {

			checkTaskCreation = 1;
			file = "50FT.wav";
			xTaskCreate(play_wav_file, "PlaySound", 4096, file, 24, &h_playsound);

		}else if (rad_alt <= 45 && rad_alt > 40) {

			checkTaskCreation = 1;
			file = "40FT.wav";
			xTaskCreate(play_wav_file, "PlaySound", 4096, file, 24, &h_playsound);

		}else if (rad_alt <= 35 && rad_alt > 30) {

			checkTaskCreation = 1;
			file = "30FT.wav";
			xTaskCreate(play_wav_file, "PlaySound", 4096, file, 24, &h_playsound);

		}else if (rad_alt <= 25 && rad_alt > 20) {

			checkTaskCreation = 1;
			file = "20FT.wav";
			xTaskCreate(play_wav_file, "PlaySound", 4096, file, 24, &h_playsound);

		}else if (rad_alt <= 15 && rad_alt > 10) {

			checkTaskCreation = 1;
			file = "10FT.wav";
			xTaskCreate(play_wav_file, "PlaySound", 4096, file, 24, &h_playsound);

		}else{
			checkTaskCreation = 0;

		}
	}
	return checkTaskCreation;

}
void SoundTask(void *pArg) {

    /*Adjust the Audio frequency */






	while (1) {

			if(check_gpws() == 1){
		        ulTaskNotifyTake(pdTRUE, 7000);
			}




	}

}

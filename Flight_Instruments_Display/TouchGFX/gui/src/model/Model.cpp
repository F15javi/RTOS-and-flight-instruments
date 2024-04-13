#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "stm32f7xx_hal.h"
#include "cmsis_os.h"
#include "main.h"



typedef struct{
				uint16_t speed;
				float pitch;
				float roll;
				uint16_t altitude;
				float heading;
			}RX_Data;

extern "C"{

	extern osMessageQueueId_t DataToDisplayHandle;


	}


Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	RX_Data Telemetry;

	//Get data from the Display queue
	if (osMessageQueueGet(DataToDisplayHandle, &Telemetry, 0U, 0) == osOK)
		{
		// send data to presenter
			modelListener->Update_Speed(Telemetry.speed);
			modelListener->Update_Altitude(Telemetry.altitude);
			modelListener->Update_Horizon(Telemetry.pitch, Telemetry.roll);
			modelListener->Update_Roll(Telemetry.pitch);
			modelListener->Update_Heading(Telemetry.heading);

		}


}

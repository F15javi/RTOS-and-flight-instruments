#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "stm32f7xx_hal.h"
#include "cmsis_os.h"
#include "main.h"

extern __IO uint16_t speed;
extern __IO float pitch;
extern __IO float roll;
extern __IO uint16_t altitude;
extern __IO float heading;
extern __IO uint16_t rpm;
extern __IO float Fuel_flow;
extern __IO uint16_t ENG_temp;
extern __IO uint16_t Oil_p;
extern __IO uint16_t Oil_t;
extern __IO float Fuel_tank1;
extern __IO float Fuel_Tank2;
//typedef struct{
//				uint16_t speed;
//				float pitch;
//				float roll;
//				uint16_t altitude;
//				float heading;
//			}RX_Data;
//
//extern "C"{
//
//	extern osMessageQueueId_t DataToDisplayHandle;
//
//
//	}


Model::Model() : modelListener(0)
{

}

void Model::tick()
{


		modelListener->Update_Speed(speed);
		modelListener->Update_Altitude(altitude);
		modelListener->Update_Horizon(pitch, roll);
		modelListener->Update_Roll(pitch);

		modelListener->Update_Heading(heading);

		modelListener->Update_Rpm(rpm);
		modelListener->Update_Fuel_Flow(Fuel_flow);
		modelListener->Update_Engine_Temp(ENG_temp);
		modelListener->Update_Oil_Pressure(Oil_p);
		modelListener->Update_Oil_Temp(Oil_t);
		modelListener->Update_Fuel_Tank1(Fuel_tank1);
		modelListener->Update_Fuel_Tank2(Fuel_Tank2);


	//RX_Data Telemetry;

		//Get data from the Display queue
//		if (osMessageQueueGet(DataToDisplayHandle, &Telemetry, 0U, 0) == osOK)
//			{
//			// send data to presenter
//
//
//			}



}
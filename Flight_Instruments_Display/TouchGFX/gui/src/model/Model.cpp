#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "stm32f7xx_hal.h"

extern __IO uint16_t altitude;
extern __IO uint8_t speed;
extern __IO float pitch;
extern __IO float roll;
extern __IO float heading;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	modelListener->Update_Speed_Text(speed);
	modelListener->Update_Altitude_Text(altitude);
	modelListener->Update_Horizon(pitch, roll);
	modelListener->Update_Roll_Text(roll);
	modelListener->Update_Heading_Text(heading);


}

#include <gui/screen3_screen/Screen3View.hpp>
#include "stm32f7xx_hal.h"

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}
void Screen3View::Update_Rpm(uint16_t value){

	gauge1.setValue(value);
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", value);

	gauge1.invalidate();
	textArea1.invalidate();

}
void Screen3View::Update_Fuel_Flow(float value){

	uint16_t x = (value*342)/12;


	Fuel_Arrow.setX(x);
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%f", value);


	textArea2.invalidate();
	Fuel_Arrow.invalidate();

}
void Screen3View::Update_Engine_Temp(uint16_t value){

	uint16_t x = (value*425)/2000;


	Eng_Arrow.setX(x);
	Unicode::snprintf(textArea5Buffer, TEXTAREA5_SIZE, "%d", value);


	textArea5.invalidate();
	Eng_Arrow.invalidate();


}
void Screen3View::Update_Oil_Pressure(uint16_t value){

	uint16_t x = (value*425)/140;


	OilP_Arrow.setX(x);
	Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "%d", value);


	textArea3.invalidate();
	Eng_Arrow.invalidate();


}
void Screen3View::Update_Oil_Temp(uint16_t value){

	uint16_t x = (value*425)/140;


	OilF_Arrow.setX(x);
	Unicode::snprintf(textArea4Buffer, TEXTAREA4_SIZE, "%d", value);


	textArea4.invalidate();
	OilF_Arrow.invalidate();

}
void Screen3View::Update_Fuel_Tank1(float value){



}
void Screen3View::Update_Fuel_Tank2(float value){



}

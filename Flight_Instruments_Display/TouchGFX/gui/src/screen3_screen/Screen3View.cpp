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
	image1.invalidate();

}
void Screen3View::Update_Fuel_Flow(float value){

	uint16_t x = (420-241)*(value-0)/(20-0)+241;

	Fuel_Arrow.setX(x);
	Unicode::snprintfFloat(textArea2Buffer, TEXTAREA2_SIZE, "%2.1f", value);


	textArea2.invalidate();
	Fuel_Arrow.invalidate();

}
void Screen3View::Update_Engine_Temp(uint16_t value){

	uint16_t x = (value*186)/2000+241;


	Eng_Arrow.setX(x);
	Unicode::snprintf(textArea5Buffer, TEXTAREA5_SIZE, "%d", value);


	textArea5.invalidate();
	Eng_Arrow.invalidate();


}
void Screen3View::Update_Oil_Pressure(uint16_t value){

	uint16_t x = (value*186)/140+241;


	OilP_Arrow.setX(x);
	Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "%d", value);


	textArea3.invalidate();
	OilP_Arrow.invalidate();


}
void Screen3View::Update_Oil_Temp(uint16_t value){

	uint16_t x = (420-241)*((value-0)/(245-0))+241;


	OilF_Arrow.setX(x);
	Unicode::snprintf(textArea4Buffer, TEXTAREA4_SIZE, "%d", value);


	textArea4.invalidate();
	OilF_Arrow.invalidate();

}
void Screen3View::Update_Fuel_Tank1(float value){
	uint16_t x = (value*186)/30+241;


	Tank1_Arrow.setX(x);

	Tank1_Arrow.invalidate();


}
void Screen3View::Update_Fuel_Tank2(float value){
	uint16_t x = (value*186)/30+241;


	Tank2_Arrow.setX(x);

	Tank2_Arrow.invalidate();


}
void Screen3View::showFPS(uint8_t value){

	uint8_t fps = 0;
	if(FPS.getState() == true){

		fps_text3.setVisible(true);
		ms3.setVisible(true);

		if(value != 0){
			fps = 1000/value;
		}
		Unicode::snprintf(fps_text3Buffer, FPS_TEXT3_SIZE, "%d", fps);
		Unicode::snprintf(ms3Buffer, MS3_SIZE, "%d", value);

		fps_text3.invalidate();
		ms3.invalidate();
	}else{

		fps_text3.setVisible(false);
		ms3.setVisible(false);
	}


}

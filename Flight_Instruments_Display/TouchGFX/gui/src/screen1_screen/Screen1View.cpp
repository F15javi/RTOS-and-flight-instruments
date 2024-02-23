#include <gui/screen1_screen/Screen1View.hpp>
#include "stm32f7xx_hal.h"
#include <string.h>
#include <math.h>



Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
void Screen1View::Update_Speed_Text(uint8_t value){

	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", value);

	textArea1.invalidate();


}
void Screen1View::Update_Altitude_Text(uint16_t value){
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%d", value);
	textArea2.invalidate();

}
void Screen1View::Update_Pitch_Text(float value){

//-104 es el centro de la imagen de fondo


	if(value >= 0){

		float y = (value*200)/50;

		image1.setY(-104+y);

	}else{
		float y = (value*200)/50;
		image1.setY(-104+y);

	}

	image1.invalidate();




}
float DegToRad(float angle){

	return (angle) * M_PI / 180.0;

}
void Screen1View::Update_Roll_Text(float value){

	textureMapper1.setZAngle(DegToRad(value));

}
void Screen1View::Update_Heading_Text(float value){


}

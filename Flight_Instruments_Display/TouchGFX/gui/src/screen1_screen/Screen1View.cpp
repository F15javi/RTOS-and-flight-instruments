#include <gui/screen1_screen/Screen1View.hpp>
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
void Screen1View::Update_Speed(uint16_t value){

	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", value);

	textArea1.invalidate();


}
float DegToRad(float angle){

	return (angle) * M_PI / 180.0;

}

void Screen1View::Update_Altitude(uint16_t value){

	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%d", value);
	textArea2.invalidate();

}

void Screen1View::Update_Horizon(float value, float value2){

//-104 es el centro de la imagen de fondo

	// 1° We have to move the image and the center of rotation
	float y = (value*369)/90;
	float rad = DegToRad(value2);

	if(value >= 0){

		textureMapper1.setBitmapPosition(0.0f,y);



	}else{
		textureMapper1.setBitmapPosition(0.0f,y);


	}
	//2° we rotate
    textureMapper1.setAngles(0.0f, 0.0f, -rad);


	textureMapper1.invalidate();




}

void Screen1View::Update_Roll(float value){

	//textureMapper1.setZAngle(DegToRad(value));

}
void Screen1View::Update_Heading(float value){


}

#include <gui/screen2_screen/Screen2View.hpp>
#include <string.h>
#include <math.h>

uint16_t dir;
uint16_t hdg=0;

float rad_hdg;
Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

float DegToRad2(float angle){

	return (angle) * M_PI / 180.0;

}
void Screen2View::up_hdg(){

	uint16_t hdg_aux;

	if(hdg == 359){
		hdg = 0;
	}else{
		hdg=hdg+1;

	}

	hdg_aux = (dir+hdg)%360;
	rad_hdg = DegToRad2(hdg_aux);

	heading.setAngles(0.0f, 0.0f, rad_hdg);
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%03d", hdg);

	textArea2.invalidate();

}
void Screen2View::down_hdg(){
	uint16_t hdg_aux;
	if(hdg == 0){
		hdg = 359;
	}else{
		hdg=hdg-1;

	}


	hdg_aux = (dir+hdg)%360;
	rad_hdg = DegToRad2(hdg_aux);
	heading.setAngles(0.0f, 0.0f, rad_hdg);

	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%03d", hdg);

	textArea2.invalidate();



}
void Screen2View::Update_Heading(float value){

	dir = value;

	float rad_compass = DegToRad2(value);

	uint16_t aux = value;
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%03d", aux);

	compass.setAngles(0.0f, 0.0f, rad_compass);
	heading.setAngles(0.0f, 0.0f, rad_hdg);


	heading.invalidate();
	compass.invalidate();
	textArea1.invalidate();


}

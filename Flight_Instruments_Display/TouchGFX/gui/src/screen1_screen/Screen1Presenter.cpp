#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}
void Screen1Presenter::Update_Speed_Text(uint8_t value){

	view.Update_Speed_Text(value);

}


void Screen1Presenter::Update_Altitude_Text(uint16_t value){
	view.Update_Altitude_Text(value);

}
void Screen1Presenter::Update_Pitch_Text(float value){
	view.Update_Pitch_Text(value);

}
void Screen1Presenter::Update_Roll_Text(float value){
	view.Update_Roll_Text(value);

}

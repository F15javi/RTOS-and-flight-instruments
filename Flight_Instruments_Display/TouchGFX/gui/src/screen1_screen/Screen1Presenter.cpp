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
void Screen1Presenter::Update_Speed(uint16_t value){

	view.Update_Speed(value);

}


void Screen1Presenter::Update_Altitude(uint16_t value){
	view.Update_Altitude(value);

}
void Screen1Presenter::Update_Horizon(float value, float value2){
	view.Update_Horizon(value, value2);

}
void Screen1Presenter::Update_Roll(float value){
	view.Update_Roll(value);

}
void Screen1Presenter::Update_Heading(float value){
	view.Update_Heading(value);

}
void Screen1Presenter::askTosendData(uint8_t state)
{
	model->sendLandingState(state);
}

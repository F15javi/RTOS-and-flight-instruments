#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

Screen3Presenter::Screen3Presenter(Screen3View& v)
    : view(v)
{

}

void Screen3Presenter::activate()
{

}

void Screen3Presenter::deactivate()
{

}
void Screen3Presenter::Update_Rpm(uint16_t value){
	view.Update_Rpm(value);

}
void Screen3Presenter::Update_Fuel_Flow(float value){
	view.Update_Fuel_Flow(value);

}
void Screen3Presenter::Update_Engine_Temp(uint16_t value){
	view.Update_Engine_Temp(value);

}
void Screen3Presenter::Update_Oil_Pressure(uint16_t value){
	view.Update_Oil_Pressure(value);

}
void Screen3Presenter::Update_Oil_Temp(uint16_t value){
	view.Update_Oil_Temp(value);

}
void Screen3Presenter::Update_Fuel_Tank1(float value){
	view.Update_Fuel_Tank1(value);

}
void Screen3Presenter::Update_Fuel_Tank2(float value){
	view.Update_Fuel_Tank2(value);

}

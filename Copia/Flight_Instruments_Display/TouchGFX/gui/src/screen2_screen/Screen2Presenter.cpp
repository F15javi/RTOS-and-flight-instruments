#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v)
{

}

void Screen2Presenter::activate()
{

}

void Screen2Presenter::deactivate()
{

}

void Screen2Presenter::Update_Heading_Text(float value){
	view.Update_Heading_Text(value);

}
//void Screen2Presenter::up_hdg(){
//
//}void Screen2Presenter::down_hdg(){
//
//}

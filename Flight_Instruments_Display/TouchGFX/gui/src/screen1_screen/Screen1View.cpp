#include <gui/screen1_screen/Screen1View.hpp>
#include "stm32f7xx_hal.h"
#include <string.h>


extern __IO uint8_t rx_datBuffer[35];

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
void Screen1View::Update_Pitch_Text(uint8_t value){




}
void Screen1View::Update_Roll_Text(uint8_t value){



}

#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void Update_Speed_Text(uint8_t value);
	virtual void Update_Altitude_Text(uint16_t value);
	virtual void Update_Pitch_Text(float value);
	virtual void Update_Roll_Text(float value);

protected:
};

#endif // SCREEN1VIEW_HPP

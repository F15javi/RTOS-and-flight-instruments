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

    virtual void Update_Speed(uint16_t value);
	virtual void Update_Altitude(uint16_t value);
	virtual void Update_Horizon(float value, float value2);
	virtual void Update_Roll(float value);
	virtual void Update_Heading(float value);
protected:
};

#endif // SCREEN1VIEW_HPP

#ifndef SCREEN3VIEW_HPP
#define SCREEN3VIEW_HPP

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

class Screen3View : public Screen3ViewBase
{
public:
    Screen3View();
    virtual ~Screen3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void Update_Rpm(uint16_t value);
    virtual void Update_Fuel_Flow(float value);
	virtual void Update_Engine_Temp(uint16_t value);
	virtual void Update_Oil_Pressure(uint16_t value);
	virtual void Update_Oil_Temp(uint16_t value);
	virtual void Update_Fuel_Tank1(float value);
	virtual void Update_Fuel_Tank2(float value);
	virtual void showFPS(uint8_t value);

protected:
};

#endif // SCREEN3VIEW_HPP

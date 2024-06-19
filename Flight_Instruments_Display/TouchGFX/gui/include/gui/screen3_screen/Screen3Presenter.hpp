#ifndef SCREEN3PRESENTER_HPP
#define SCREEN3PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen3View;

class Screen3Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen3Presenter(Screen3View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screen3Presenter() {}
    virtual void Update_Rpm(uint16_t value);
    virtual void Update_Fuel_Flow(float value);
    virtual void Update_Engine_Temp(uint16_t value);
    virtual void Update_Oil_Pressure(uint16_t value);
    virtual void Update_Oil_Temp(uint16_t value);
    virtual void Update_Fuel_Tank1(float value);
    virtual void Update_Fuel_Tank2(float value);
	virtual void showFPS(uint8_t value);


private:
    Screen3Presenter();

    Screen3View& view;
};

#endif // SCREEN3PRESENTER_HPP

#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <touchgfx/hal/Types.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }
    virtual void Update_Speed(uint16_t value) {}
    virtual void Update_Altitude(uint16_t value) {}
    virtual void Update_Horizon(float value, float value2) {}
    virtual void Update_Roll(float value) {}

    virtual void Update_Heading(float value) {}

    virtual void Update_Rpm(uint16_t value) {}
    virtual void Update_Fuel_Flow(float value){}
    virtual void Update_Engine_Temp(uint16_t value){}
    virtual void Update_Oil_Pressure(uint16_t value){}
    virtual void Update_Oil_Temp(uint16_t value){}
    virtual void Update_Fuel_Tank1(float value){}
    virtual void Update_Fuel_Tank2(float value){}
    virtual void showFPS(uint8_t value){}



protected:
    Model* model;
};

#endif // MODELLISTENER_HPP

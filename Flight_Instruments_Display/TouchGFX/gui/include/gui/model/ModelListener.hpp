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
    virtual void Update_Speed_Text(uint8_t value) {}
    virtual void Update_Altitude_Text(uint16_t value) {}
    virtual void Update_Pitch_Text(uint8_t value) {}
    virtual void Update_Roll_Text(uint8_t value) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP

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

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP

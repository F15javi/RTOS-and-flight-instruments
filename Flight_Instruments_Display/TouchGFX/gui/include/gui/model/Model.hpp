#ifndef MODEL_HPP
#define MODEL_HPP
#include "stm32f7xx_hal.h"
#include "cmsis_os.h"

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void sendLandingState(uint8_t state);

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP

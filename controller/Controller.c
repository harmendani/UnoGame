#include "Controller.h"

void runSystem()
{
    startScreen();
    controllerCore();

    return;
}

void controllerCore()
{

    Data *data = executaMotorData();
    while (data->md_training)
    {
        executarMotorPartida();
        data->md_training--;
    }

    return;
}

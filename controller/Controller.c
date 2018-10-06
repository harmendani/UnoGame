#include "Controller.h"

void runSystem()
{
    
    controllerCore();
    return;
}

void controllerCore(){

    startScreen(); 
    Data *data = executaMotorData();
    
    return;
    
}

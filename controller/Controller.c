#include "Controller.h"

void runSystem()
{
    Data *data = executaMotorData();
    writeFileRunSystem(data);
    return;
}

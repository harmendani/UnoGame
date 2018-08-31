#include "Controller.h"

void runSystem()
{
    Data* data = (Data*) malloc(sizeof(Data));
    *data =  executaMotorData();
    return;
}

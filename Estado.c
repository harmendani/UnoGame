/* Implementa as rotinas de 'Estado.h' */
#ifndef ESTADO_H
#define ESTADO_H
#include "Estado.h"
#endif

void start_StateGame()
{

    for (int i = 0; i < 9; i++)
    {
        estadoGlobal.stateGame[i] = '0';
    }

}

void start_StateNext(){
    for (int i = 0; i < 9; i++)
    {
        estadoGlobal.stateNext[i] = '0';
    }
}


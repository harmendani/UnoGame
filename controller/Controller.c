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
    int training = data->md_training;
    int spockWin = 0;
    int machineWin = 0;

    while (training)
    {
        startScreen();
        imprimirDadosEntrada(data);        
        imprimirProgressoTreinamento(data, training);
        executarMotorPartida(data);
        training--;
        if (data->md_data.t_player->nome == SPOCK)
        {   
            //printf("\n>> Wins update: %s \n", j2.nome);
            spockWin++;            
        }
        else
        {
            machineWin++;
            
        }
    }
    printf("\n\nSpock : %d - Machine : %d \n", spockWin, machineWin);
    //imprimirDadosSaida(data);

    return;
}

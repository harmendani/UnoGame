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
    q_Learning *q = executaMotorLearning(data);

    int training = data->md_training;
    int spockWin = 0;
    int machineWin = 0;

    while (training)
    {
        startScreen();
        imprimirDadosEntrada(data);
        imprimirProgressoTreinamento(data, training);
        executarMotorPartida(data, q);
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
    free(q);
    free(data);
    q = NULL;
    data = NULL;
    imprime_MatrixQ();
    return;
}

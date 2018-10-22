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
    while (training)
    {
        system("cls");
        startScreen();
        imprimirDadosEntrada(data);
        puts("\n Executing matchs...");
        imprimirProgressoTreinamento(data, training);
        executarMotorPartida(data);
        training--;
        
    }
    imprimirDadosSaida(data);
    
   
    return;
}

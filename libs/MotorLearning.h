/* Define as rotinas para o motor de aprendizado 
** usando o algoritmo Q Learning e heurísticas de exploração
*/

//Bibliotecas necessárias
#ifndef MOTORDATA_H
#define MOTORDATA_H
#include "./libs/MotorData.h"
#endif

/* Define a estrutura da Função Q*/
typedef struct Q_Function
{
    float discountFactor; // Desconto temporal
    float learningRate;   // Fato de aprendizagem
    float exploitation;   // Taxa de exploração

}q_Learning;

/* Define parâmetros para heurísticas de exploração*/
q_Learning defineParametrosHeuristica(Data *);

/* Define parâmetros para o Q_learning*/
void defineQLearning();

#ifndef MOTOR_LEARNING_C
#define MOTOR_LEARNING_C
#include "../learning/MotorLearning.c"
#endif

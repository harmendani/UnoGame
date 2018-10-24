/* Define as rotinas para o motor de aprendizado 
** usando o algoritmo Q Learning e heurísticas de exploração
*/

// Variáveis globais
float matrixQ[28][5];

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

} q_Learning;

/* Rotina principal da Engine de aprendizado: 
* 1 - Inicia Matriz Global
* 2 - Invoca defineParametrosHeuristica(Data *)
*/
q_Learning *executaMotorLearning(Data *);

/* Define parâmetros para heurísticas de exploração*/
q_Learning *defineParametrosHeuristica(Data *);

/* Constroi artefatos computacionais úteis*/
void start_MatrixQ();
void addSate_MatrixQ(char *);
int calcReward(player *);
void imprime_MatrixQ();


/* Constroi Q Learning a partir de parâmetros e artefatos */
 void updateQLearning(q_Learning*, int);

#ifndef MOTOR_LEARNING_C
#define MOTOR_LEARNING_C
#include "../learning/MotorLearning.c"
#endif

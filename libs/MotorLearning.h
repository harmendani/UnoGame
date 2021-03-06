/* Define as rotinas para o motor de aprendizado 
** usando o algoritmo Q Learning e heurísticas de exploração
*/

// Variáveis globais
float matrixQ[28][6];

//Bibliotecas necessárias
#ifndef MOTORDATA_H
#define MOTORDATA_H
#include "MotorData.h"
#endif

/* Define a estrutura da Função Q*/
typedef struct Q_Function
{
    float discountFactor; // Desconto temporal
    float learningRate;   // Fato de aprendizagem
    float exploitation; 
    int training;  // Taxa de exploração
    int episode;      //Save steps of Match
   
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
int buscarIndiceEstado(char *);
float searchMax_ValueQ(player *);
float search_ValueQ(player *);
int updateVisitState(char *);

/* Constroi Q Learning a partir de parâmetros e artefatos */
void updateQLearning(q_Learning *, player *);

#ifndef MOTOR_LEARNING_C
#define MOTOR_LEARNING_C
#include "../learning/MotorLearning.c"
#endif

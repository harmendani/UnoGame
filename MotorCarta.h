/* Contém declarações e definições para manipular a mecânica básica do jogo referente as cartas
** como contagem, embaralhamento e alocador de cartas em memória
*/


/** INÍCIO: Variáveis Globais **/

/* Listas Globais para guardar as cartas do jogo para: Mesa, Montante e Jogadores. */
Lista *G_l; //Montante
Lista *M_l; //Mesa

/* Variáveis para contagem de cartas da visão Espectador. */
int CONT_MESA;
int CONT_MONTANTE;

/** FIM: Variáveis Globais **/

//Rotinas

/* Aloca um número aleatório para cada carta ao chamar o preparaRandom() referente a cada rotina abaixo. */
void rotinaPreparaRandom();
void preparaRandomAzul();
void preparaRandomVermelho();
void preparaRandomVerde();
void preparaRandomAmarelo();
void preparaRandomZero();
void preparaRandomCoringa();

/*  Transfere as cartas inicializadas para uma lista dinâmica em memória. */
void alocadorDeCartasMemoria();

/* Embaralha todas as cartas da Lista. */
void embaralhadorDeCartas();

/*  Distribui cartas no inicio do jogo para cada player. */
void distribuiCartasInicio();

/* Impressão das cartas em memoria por id, tipo e cor. */
void imprimeIDCartasMemoria();

/*///////////////////////////////////////////////////////////////////////////////////////////////////////
ROTINA PRINCIPAL PARA O MOTOR DE CARTAS: 
Executada apenas uma vez antes do início do jogo. Estão presentes todas as funções necessárias
para carregar as cartas embaralhadas em memória na variável global Lista* G_l.
///////////////////////////////////////////////////////////////////////////////////////////////////////*/
void executarMotorCarta();

#ifndef PLAYER_H
#define PLAYER_H
#include "Player.h"
#endif
/* Recebe uma variável do tipo player e conta o número de cartas nas mãos */
int contadorDeCartas(Lista*);

/* Confere se existe cartas no montante realizando o controle do montante.
** Realize duas tarefas básicas: 
** 1- Aloca a pilha de cartas na mesa no montante caso ele esteja sem cartas. 
** 2- A Pilha da Mesa é zerada após a ação executada acima.
*/
void controlarCartasNoMontante();

/* Essa rotina recebe um ponteiro da lista das mãos do player 
** e aloca as cartas nos vetores de possibilidades do jogador conforme as cartas na mesa
** apontadas por -> M_l.
*/
void alocarVetoresDePossibilidades(Lista*);

/* Essa função recebe o apontador para o player 
** conta as quantidades de carta por tipo de cartas e as aloca em lista para: Normal, Coringa e Ação. S
** OBS:Sempre zera com NULL a lista de cartas apontada para cada tipo no início de sua execução.
*/
void contadorDeCartasPorTipo(player*);

// Implementação desta Interface:
#include "MotorCarta.c"

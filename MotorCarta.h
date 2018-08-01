/* Cont�m declara��es e defini��es para manipular a mec�nica b�sica do jogo referente as cartas
** como contagem, embaralhamento e alocador de cartas em mem�ria
*/


/** IN�CIO: Vari�veis Globais **/

/* Listas Globais para guardar as cartas do jogo para: Mesa, Montante e Jogadores. */
Lista *G_l; //Montante
Lista *M_l; //Mesa

/* Vari�veis para contagem de cartas da vis�o Espectador. */
int CONT_MESA;
int CONT_MONTANTE;

/** FIM: Vari�veis Globais **/

//Rotinas

/* Aloca um n�mero aleat�rio para cada carta ao chamar o preparaRandom() referente a cada rotina abaixo. */
void rotinaPreparaRandom();
void preparaRandomAzul();
void preparaRandomVermelho();
void preparaRandomVerde();
void preparaRandomAmarelo();
void preparaRandomZero();
void preparaRandomCoringa();

/*  Transfere as cartas inicializadas para uma lista din�mica em mem�ria. */
void alocadorDeCartasMemoria();

/* Embaralha todas as cartas da Lista. */
void embaralhadorDeCartas();

/*  Distribui cartas no inicio do jogo para cada player. */
void distribuiCartasInicio();

/*///////////////////////////////////////////////////////////////////////////////////////////////////////
* ROTINA PRINCIPAL PARA O MOTOR DE CARTAS: 
* Executada apenas uma vez antes do in�cio do jogo. Est�o presentes todas as fun��es necess�rias
* para carregar as cartas embaralhadas em mem�ria na vari�vel global Lista* G_l e distribuir para os jogadores.
///////////////////////////////////////////////////////////////////////////////////////////////////////*/
void executarMotorCarta();


#ifndef PLAYER_H
#define PLAYER_H
#include "Player.h"
#endif


/* Recebe uma vari�vel do tipo player e conta o n�mero de cartas nas m�os */
int contadorDeCartas(Lista*);

/* Confere se existe cartas no montante realizando o controle do montante.
** Realize duas tarefas b�sicas: 
** 1- Aloca a pilha de cartas na mesa no montante caso ele esteja sem cartas. 
** 2- A Pilha da Mesa � zerada ap�s a a��o executada acima.
*/
void controlarCartasNoMontante();

/* Essa fun��o recebe o apontador para o player 
** conta as quantidades de carta por tipo de cartas e as aloca em lista para: Normal, Coringa e A��o. S
** OBS:Sempre zera com NULL a lista de cartas apontada para cada tipo no in�cio de sua execu��o.
*/
void contadorDeCartasPorTipo(player*);

// Implementa��o desta Interface:
#ifndef MOTORCARTAS_C
#define MOTORCARTAS_C
#include "MotorCarta.c"
#endif


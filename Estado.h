/* Define e manipula estados do jogo*/

//CONSTANTES
/* Define os estados do jogo para cada vis�o*/
//V1 (Baixo, Médio e Alto) - Visão Contagem
#define S1 "01"
#define S2 "10"
#define S3 "11"
//V2 (Baixo, Médio e Alto) - Visão Mesa
#define S4 "100"
#define S5 "101"
#define S6 "110"
//V3(Crítico, Equilibrado e Favorável) -Visão das Maõs
#define S7 "0111"
#define S8 "1000"
#define S9 "1001"

//TIPOS

struct Estado
{
    /* Salva o estado anterior do jogo  */
    char stateGame[9];
    /* Salva o pr�ximo estado do jogo ap�s executar uma a��o*/
    char stateNext[9];
};
 typedef struct Estado estado;
 
 
//ROTINAS
/*  Ao realizar uma a��o, salva stateNext[n] em stateGame[n].
*   Depois salva S em stateNext[n].
*/
void build_StateGame();

/*Define a string '000000000' para limpar o estado anterior salvo*/
void start_StateGame(estado s);

/*Define a string '000000000' para iniciar a vari�vel de estado do jogo*/
void start_StateNext(estado s);

#ifndef ESTADO_C
#define ESTADO_C
#include "Estado.c"
#endif

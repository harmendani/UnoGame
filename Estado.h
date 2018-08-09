/* Define e manipula estados do jogo */

//CONSTANTES
/* Define os estados do jogo para cada vis�o*/

//V1 (Baixo, Médio e Alto) - Visão Contagem
#define S1 "001"
#define S2 "010"
#define S3 "011"
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
    /* Salva o estado atual do jogo  */
    char stateGame[11];
    /* Salva o estado anterior do jogo ap�s executar uma a��o */
    char stateAnt[11];
};
typedef struct Estado estado;

//Bibliotecas
#ifndef MOTORVISAO_H
#define MOTORVISAO_H
#include "MotorVisao.h"
#endif

//ROTINAS
/*  Ao realizar uma a��o, salva stateNext[n] em stateGame[n].
*   Depois salva S em stateNext[n] - próximo estado do jogo.
*/
static void save_StateAnd();

/* Calcula o estado S atual para o jogador corrente a partir de (s1, s2, s3) */
void build_StateGame(player *);

/* Calcula e devolve sub-estado s1 */
static char *build_SubEstado_1(player *);

/* Calcula e devolve sub-estado s2 */
static char *build_SubEstado_2(player *);

/* Calcula e devolve sub-estado s3 */
static char *build_SubEstado_3(player *);

#ifndef ESTADO_C
#define ESTADO_C
#include "Estado.c"
#endif

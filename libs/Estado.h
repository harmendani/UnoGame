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
#define S7 "01"
#define S8 "10"
#define S9 "11"

//TIPOS

struct Estado
{
    /* Salva o estado atual do jogo antes de executar um ação  */
    char stateGame[9];
    /* Salva o estado anterior do jogo após executar uma ação */
    char stateProx[9];
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
void build_StateProx(player *);

/* Calcula o estado S e salva em stateGame  */
void build_StateGame(player *);

/* Calcula e devolve sub-estado s1 */
static char *build_SubEstado_1(player *);

/* Calcula e devolve sub-estado s2 */
static char *build_SubEstado_2(player *);

/* Calcula e devolve sub-estado s3 */
static char *build_SubEstado_3(player *);

#ifndef ESTADO_C
#define ESTADO_C
#include "../Estado.c"
#endif

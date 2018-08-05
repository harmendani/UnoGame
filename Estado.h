/* Define e manipula estados do jogo */


//CONSTANTES
/* Define os estados do jogo para cada vis�o*/
//Valor default - inicial
#define DEFAULT "000000000"
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
    /* Salva os subestados atuais*/
    char state_contagem[4];
    char state_mesa[4];
    char state_maos[4];

    /* Salva o estado atual do jogo  */
    char stateGame[10];
    /* Salva o pr�ximo estado do jogo ap�s executar uma a��o */
    char stateNext[10];
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
static void save_StateGame();

/*Define NULL para inicializar todos as Strings da struct Estado */
void start_StateGame(estado *);

/* Calcula o estado S corrente para o jogador atual a partir de (s1, s2, s3) */
char *build_StateGame();

/* Calcula e devolve sub-estado s1 */
static char *build_SubEstado_1(player*);

/* Calcula e devolve sub-estado s2 */
static char *build_SubEstado_2(player*);

/* Calcula e devolve sub-estado s3 */
static char *build_SubEstado_3(player*);

#ifndef ESTADO_C
#define ESTADO_C
#include "Estado.c"
#endif

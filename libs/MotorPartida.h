/* Este arquivo cont�m rotinas e vari�veis  que permitem 
** controlar as partidas de jogo
 */

#ifndef MOTORDATA_H
#define MOTORDATA_H
#include "MotorData.h"
#endif

#ifndef MOTOR_LEARNING_H
#define MOTOR_LEARNING_H
#include "MotorLearning.h"
#endif

/** IN�CIO: Vari�veis Globais **/
static bool STATUS_PARTIDA; // Guarda TRUE ou FALSE para indicar o termino da partida.
static bool STATUS_PILHA_MESA;
static bool STATUS_MONTANTE_DESCARTE;
/** FIM: Vari�veis Globais **/

/*///////////////////////////////////////////////////////////////////////////////////////////////////////
* ROTINA PRINCIPAL PARA O MOTOR DE PARTIDA:
* - Executa startMatch().
* - Invoca rotina que define player de saída e o salva.
* - Começa loop de rodadas com o player do passo acima até a condição de parada : 
*   Quantidade de cartas == 0 pra alguma jogador (*player)
///////////////////////////////////////////////////////////////////////////////////////////////////////*/
void executarMotorPartida(Data *, q_Learning*);

/* Rotina básica para iniciar variáveis de controle da partida:
* STATUS_PARTIDA -> TRUE.
* STATUS_PILHA_MESA -> FALSE.
* STATUS_MONTANTE_DESCARTE -> TRUE.
*/
static void start_StatusMatch();

/* Rotina básica para inserir valores nas variáveis de controle
*  para indicar o final da partida:
* STATUS_PARTIDA -> FALSE;
* STATUS_PILHA_MESA -> FALSE;
* STATUS_MONTANTE_DESCARTE -> FALSE;
*/
static void end_StatusMatch();

/* Rotina Principal para iniciar cada partida:
*  - Inicializa jogadores invocando a rotina inicializaJogadores().
*  - Invoca executarMotorCarta() para inicializar e distribuir as cartas do jogo.
* - Define os valores padrões iniciais para as Variáveis deste módulo: start_StatusMatch().
*/
void start_Match();

/* Rotina Principal para finalizar a partida:
*  Define os valores padrões finais para as Variáveis deste módulo: end_StatusMatch().
*/
void end_Match();

//PROCEDIMENTOS INTERNOS

/* Verifica existe Partida e devolve TRUE se for verdade, tal que:
** STATUS_PARTIDA -> true;
*/
bool isMatch();

/* Determina aleatoriamente o jogador a começar a partida*/
player *definePlayerSaida();

/* Devolve jogador vencedor da partida */
player *definePlayerVencedor(player *);

/* Lança o jogador correto para efetuar uma jogada*/
player *throwPlay(player *, q_Learning*);

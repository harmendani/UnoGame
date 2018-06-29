/* Este arquivo cont�m rotinas e vari�veis  que permitem 
** controlar as partidas de jogo
 */

/** IN�CIO: Vari�veis Globais **/
static bool STATUS_PARTIDA;
static bool STATUS_PILHA_MESA;
static bool STATUS_MONTANTE_DESCARTE; // Guarda TRUE ou FALSE para indicar o termino da partida.
/** FIM: Vari�veis Globais **/

//ROTINAS

/* Rotina básica para iniciar variáveis de controle da partida
* STATUS_PARTIDA;
* STATUS_PILHA_MESA;
* STATUS_MONTANTE_DESCARTE
*/
void start_StatusMatch();

/* Rotina Principal para iniciar cada partida:
* - Invoca executarMotorCarta(). para inicializar e embaralhar as cartas do jogo.
* - Inicializa jogadores invocando a rotina inicializaJogadores().
* - Invoca distribuiCartasInicio() para distribuir 7 cartas para os jogadores.
* - Define os valores padrões iniciais para as Variáveis deste módulo:
* STATUS_PARTIDA -> TRUE.
* STATUS_PILHA_MESA -> FALSE.
* STATUS_MONTANTE_DESCARTE -> TRUE.
*/
void start_Match();

/* Este arquivo cont�m rotinas e vari�veis  que permitem 
** controlar as partidas de jogo
 */

/** IN�CIO: Vari�veis Globais **/
static bool STATUS_PARTIDA; // Guarda TRUE ou FALSE para indicar o termino da partida.
static bool STATUS_PILHA_MESA;
static bool STATUS_MONTANTE_DESCARTE; 
/** FIM: Vari�veis Globais **/

//ROTINAS PRINCIPAIS

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
void definePlayerSaida();

/* Determina quem executa a ação de jogar*/
void defineVezDoPlayer();
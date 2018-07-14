/* Este arquivo cont�m rotinas e vari�veis  que permitem 
** controlar as partidas de jogo
 */

/** IN�CIO: Vari�veis Globais **/
static bool STATUS_PARTIDA; // Guarda TRUE ou FALSE para indicar o termino da partida.
static bool STATUS_PILHA_MESA;
static bool STATUS_MONTANTE_DESCARTE; 
/** FIM: Vari�veis Globais **/

//ROTINAS

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
* - Invoca executarMotorCarta(). para inicializar e embaralhar as cartas do jogo.
* - Inicializa jogadores invocando a rotina inicializaJogadores().
* - Invoca distribuiCartasInicio() para distribuir 7 cartas para os jogadores.
* - Define os valores padrões iniciais para as Variáveis deste módulo: start_StatusMatch().
*
*/
void start_Match();

/* Rotina Principal para finalizar a partida:
*  Define os valores padrões finais para as Variáveis deste módulo: end_StatusMatch().
*  Limpa da memória:
* - Lista das mãos dos jogadores.
* - Lista do montante de Descarte (G_l).
* -  Lista da pilha da mesa (M_l).
*/
void end_Match();

/* Algoritmos úteis*/
#ifndef UTIL_H
#define UTIL_H
#include ".\util\Util.h"
#endif


//Protótipos
/* Inicializa os dois jogadores com um nome próprio, 
** identificação, cartas em mão e estado inicial.
*/

void inicializaJogadores();

//CONSTANTES
/* Nomes comuns para jogadores*/
#define MACHINE "Machine"
#define SPOCK "Spock"

/* Identifica id do player*/
#define AR 1	// Com aprendizado de máquina
#define NO_AR 0 // Sem aprenzido de máquina

// TIPOS DEFINIDOS
typedef struct jogador
{
	int id;					 /* Identificador do jogador */
	string nome;			 /* Nome do jogador durante as partidas */
	Lista *listaMaos;		 /* Mantem uma referencia para as cartas em mãos */
	bool bool_statusJogador; /* Indica a vez do jogador, tem somente valor true quando  é vez dele */
	int vitorias;			 /* Guarda o número de vitórias a cada partida realizada */
	carta cartaNaMesa;		 /* Guarda as informações da carta atual na mesa */

	/* *Matriz tipo: carta*
	 *Linhas:            || Colunas:
	 *Número ->            [0....108].
	 *Cor ->               [0....108]
     *Coringa Comprar 4 -> [0....108].
     *Coringa No_Action -> [0....108].
     *Sequencia númerica -> [0....108].
	*/
	carta matrizDePossibilidades[5][108]; // Salva as possibilidades de jogada atual.
	int numDeCartasNormal[108];			  // Salva quantidade de cartas do tipo Normal.
	int numDeCartasAcao[108];			  // Salva quantidade de cartas do tipo Ação.
	int numDeCartasCoringa[108];		  // Salva quantidade de cartas do tipo Coringa.
										  //stateJogador; // Define o estado (s1, s2, s3) atual do jogo para o agente jogador.
} player;

/* INÍCIO: Variáveis Globais*/
player j1;
player j2;
/* FIM: Variáveis Globais*/
// Implementação
#ifndef PLAYER_C
#define PLAYER_C
#include "Player.c"
#endif


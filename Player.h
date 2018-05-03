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


// TIPOS
struct jogador
{
	int id;			  /* Identificador do jogador */
	string nome;	  /* Nome do jogador durante as partidas */
	Lista *listaMaos; /* Mantem uma referencia para as cartas em mãos */

	bool bool_statusJogador; /* Indica a vez do jogador, tem somente valor true quando é vez dele */
	int vitorias;			 /* Guarda o número de vitórias a cada partida realizada */
	carta cartaNaMesa;		 /* Guarda as informações da carta atual na mesa */

	int numDeCartasNormal;  // Salva quantidade de cartas do tipo Normal.
	int numDeCartasAcao;	// Salva quantidade de cartas do tipo Ação.
	int numDeCartasCoringa; // Salva quantidade de cartas do tipo Coringa.
	Lista *cartasNormal;	// Lista temporária que salva as cartas do tipo Normal.
	Lista *cartasAcao;		// Lista temporária que salva as cartas do tipo Acao.
	Lista *cartasCoringa;   // Lista temporária que salva as cartas do tipo Coringa.
	vision visaoPlayer;		// Salva as vis�es atuais do jogo
							//stateJogador; // Define o estado (s1, s2, s3) atual do jogo para o agente jogador.
};

typedef struct jogador player;

/* INÍCIO: Variáveis Globais*/
player j1;
player j2;
/* FIM: Variáveis Globais*/

#ifndef PLAYER_C
#define PLAYER_C
#include "Player.c"
#endif

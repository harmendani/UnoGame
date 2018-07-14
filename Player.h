#ifndef UTIL_H
#define UTIL_H
#include ".\util\Util.h"
#endif


//Prot?�tipos
/* Inicializa os dois jogadores com um nome pr?�prio, 
** identifica?�?�o, cartas em m?�o e estado inicial.
*/
void inicializaJogadores();

//CONSTANTES
/* Nomes comuns para jogadores*/
#define MACHINE "Machine"
#define SPOCK "Spock"

/* Identifica id do player*/
#define AR 1	// Com aprendizado de m??quina
#define NO_AR 0 // Sem aprenzido de m??quina


// TIPOS
typedef struct jogador player;

struct jogador
{   
	int id;			  /* Identificador do jogador 0: NO AR -- 1 AR*/
	string nome;	  /* Nome do jogador durante as partidas */
	Lista *listaMaos; /* Mantem uma referencia para as cartas em m?�os */

	bool bool_statusJogador; /* Indica a vez do jogador, tem somente valor true quando ?? vez dele */
	int vitorias;			 /* Guarda o n??mero de vit?�rias a cada partida realizada */
	
	int numDeCartasNormal;  // Salva quantidade de cartas do tipo Normal.
	int numDeCartasAcao;	// Salva quantidade de cartas do tipo A?�?�o.
	int numDeCartasCoringa; // Salva quantidade de cartas do tipo Coringa.
	Lista *cartasNormal;	// Lista tempor??ria que salva as cartas do tipo Normal.
	Lista *cartasAcao;		// Lista tempor??ria que salva as cartas do tipo Acao.
	Lista *cartasCoringa;   // Lista tempor??ria que salva as cartas do tipo Coringa.
	vision visaoPlayer;		// Salva as vis?es atuais do jogo
	player* adversario;		// Salva o jogador adversário no início da partida.			
	estado estadoPlayer;    // Define o estado (s1, s2, s3) para o agente jogador.
};





/* IN?�CIO: Vari??veis Globais*/
player j1;
player j2;
/* FIM: Vari??veis Globais*/

#ifndef PLAYER_C
#define PLAYER_C
#include "Player.c"
#endif

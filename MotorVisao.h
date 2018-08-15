/* Vis�o dos jogos s�o contagens, predi��es e verifica��es em rela��o as cartas e
** s�o utilizados para que o motor de IA do jogo tome as melhores decis�es.
*/

// TIPOS DEFINIDOS
typedef struct VisaoContagem
{
    int i_quantMesa;
    int i_quantMontante;

} st_Contagem;

typedef struct VisaoMesa
{
    carta* c_cartaMesa;

} st_Mesa;

typedef struct VisaoJogador
{
    int i_quantJogador;
    int i_quantadversario;

} st_Jogador;

typedef struct VisaoTotal
{
    st_Contagem contagem;
    st_Mesa mesa;
    st_Jogador jogador;
} vision;

#ifndef MOTORCARTA_H
#define MOTORCARTA_H
#include "MotorCarta.h"
#endif

#ifndef PLAYER_H
#define PLAYER_H
#include "Player.h"
#endif

// Vis�o Contagem
/* Retorna a quantidade de cartas na mesa */
int v_QuantMesa();

/* Retorna a quantidade de cartas no montante */
int v_QuantMontante();

// Vis�o Mesa
/* Retorna a carta da mesa */
carta* v_VerificarCartaMesa();

// Vis�o Jogador
/* Retorna a quantidade de cartas de qualquer jogador */
int v_QuantPlayer(player *);

/* Zera variáveis do tipo Vision a cada execução do motor para garantir integridade 
** da visao do jogador.
*/
static void inicializarMotorVisao(player*);

/*///////////////////////////////////////////////////////////////////////////////////////////////////////
* ROTINA PRINCIPAL PARA O MOTOR DE VISÃO: 
* Executa todas as rotinas necessárias para processar e salvar os dados na visão do jogador.
* A rotina precisa conhecer apenas o jogador - Recebe como argumento :ponteiro para o player.
* //////////////////////////////////////////////////////////////////////////////////////////////////////*/
void executarMotorVisao(player *p);

#ifndef MOTORVISAO_C
#define MOTORVISAO_C
#include "MotorVisao.c"
#endif

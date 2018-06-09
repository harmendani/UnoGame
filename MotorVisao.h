/* Visão dos jogos são contagens, predições e verificações em relação as cartas e
** são utilizados para que o motor de IA do jogo tome as melhores decisões.
*/

// TIPOS DEFINIDOS
typedef struct VisaoContagem
{
    int i_quantMesa;
    int i_quantMontante;

} st_Contagem;

typedef struct VisaoMesa
{
    carta c_cartaMesa;
    
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

// Visão Contagem
/* Retorna a quantidade de cartas na mesa */
int v_QuantMesa();

/* Retorna a quantidade de cartas no montante */
int v_QuantMontante();

// Visão Mesa
/* Retorna a carta da mesa */
carta v_VerificarCartaMesa();

// Visão Jogador
/* Retorna a quantidade de cartas de qualquer jogador */
int v_QuantPlayer(player);

#ifndef MOTORVISAO_C
#define MOTORVISAO_C
#include "MotorVisao.c"
#endif

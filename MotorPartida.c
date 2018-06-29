/* Implementa a interface "MotorPartida.h" com algumas funções
para manipular as partidas*/

#include "MotorPartida.h"

void start_StatusMatch()
{
    STATUS_PARTIDA = true;
    if (!lst_IsEmpty(M_l))
        return;
    STATUS_PILHA_MESA = false;
    if (lst_IsEmpty(G_l))
        return;
    STATUS_MONTANTE_DESCARTE = true;
}
void start_Match()
{

    executarMotorCarta();
    inicializaJogadores();
    distribuiCartasInicio();
    start_StatusMatch(); // Invoca rotina deste módulo
    
}

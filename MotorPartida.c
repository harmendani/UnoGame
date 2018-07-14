/* Implementa a interface "MotorPartida.h" com algumas funções
para manipular as partidas*/

#include "MotorPartida.h"

// PROCEDIMENTOS DE START
static void start_StatusMatch()
{

    STATUS_PARTIDA = true;
    if (!lst_IsEmpty(M_l))
    {
        puts("\nExceção: PILHA_MESA!\n");
        return;
    }

    STATUS_PILHA_MESA = false;
    if (lst_IsEmpty(G_l))
    {
        puts("\nExceção: MONTANTE_DESCARTE!\n");
        return;
    }

    STATUS_MONTANTE_DESCARTE = true;
}
void start_Match()
{

    executarMotorCarta();
    inicializaJogadores();
    start_StatusMatch();
}

// PROCEDIMENTOS DE END
static void end_StatusMatch()
{
    STATUS_PARTIDA = false;
    STATUS_PILHA_MESA = false;
    STATUS_MONTANTE_DESCARTE = false;
    return;
}

void end_Match()
{

    /* Libera Montante de descarte e pilha da mesa */
    lst_FreeList(G_l);
    lst_FreeList(M_l);
    G_l = lst_cria();
    M_l = lst_cria();
    end_StatusMatch();

    return;
}

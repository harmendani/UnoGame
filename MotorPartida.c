/* Implementa a interface "MotorPartida.h" com algumas funções
para manipular as partidas*/

#include "MotorPartida.h"

// PROCEDIMENTOS DE START
static void start_StatusMatch()
{

    STATUS_PARTIDA = true;
    if (lst_IsEmpty(M_l))
    {
        puts("\nExceção: PILHA_MESA!\n");
        return;
    }

    STATUS_PILHA_MESA = true;
    if (lst_IsEmpty(G_l))
    {
        puts("\nExceção: MONTANTE_DESCARTE!\n");
        return;
    }

    STATUS_MONTANTE_DESCARTE = true;
}
void start_Match()
{
    inicializaJogadores();
    executarMotorCarta();
    definePlayerSaida();
    start_StatusMatch();
}

bool isMatch()
{
    int contJ1 = v_QuantPlayer(&j1);
    int contJ2 = v_QuantPlayer(&j2);

    if (contJ1 == 0)
        return false;
    if (contJ2 == 0)
        return false;

    return true;
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

void definePlayerSaida()
{

    int a = randomInteger();
    if ((a % 2) == 0)
    {
        j2.bool_statusJogador = true;
    }
    else
    {
        j1.bool_statusJogador = true;
    }
    return;
}
/*
void defineVezDoPlayer()
{   
    
    carta *temp = lst_ObterCartaRef(M_l); // Obter carta da mesa
    if(temp->AcaoCarta == REVERTER || temp->AcaoCarta == PULAR){
    
    }
    else{

    }

}*/

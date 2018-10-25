/* Implementa a interface "MotorPartida.h" com algumas funções
para manipular as partidas*/

#include "./libs/MotorPartida.h"

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

    while (lst_ObterCarta(M_l).TipoCarta == CORINGA)
    {

        sleep(2);
        inicializaJogadores();
        executarMotorCarta();
    }

    start_StatusMatch();
}

bool isMatch()
{
    int contJ1 = v_QuantPlayer(&j1);
    int contJ2 = v_QuantPlayer(&j2);

    if (contJ1 == 0)
    {
        j1.bool_statusJogador = true;
        return false;
    }

    if (contJ2 == 0)
    {
        j2.bool_statusJogador = true;
        return false;
    }

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

player *definePlayerSaida()
{

    int a = randomInteger();
    if ((a % 2) == 0)
    {
        j2.bool_statusJogador = true;
        return &j2;
    }
    else
    {
        j1.bool_statusJogador = true;
        return &j1;
    }
}

player *definePlayerVencedor(player *p)
{
    if (p->bool_statusJogador == true)
    {
        return p;
    }

    return p->adversario;
}

player *throwPlay(player *p, q_Learning *q)
{
    // Atualiza visão para o player
    executarMotorVisao(p);

    if (p->id == 1)
    {
        switch (p->seqAcao)
        {
        case (-1):
            p->seqAcao = 0;
            break;
        case (0):
            p->seqAcao = 1;
            break;
        case (1):
            p->seqAcao = -1;
            break;
        default:
            puts("\n ERRO FATAL em throwPlay");
            exit(0);
            break;
        }
    }
    // Executa Ação
    p = executarMotorAcao(p, q);

    // retorna próximo jogador
    return p;
    //printf("\n Rodada : %d - Jogador: %s - VisaoMaos: %d", i, p->nome, p->visaoPlayer.jogador.i_quantJogador);
}

//Motor Principal que roda a PARTIDA

void executarMotorPartida(Data *data, q_Learning *q)
{
    // Iniciando Partida
    sleep(1);
    start_Match();

    //Define player que começa a partida
    player *select = definePlayerSaida();
    player *temp = NULL;

    //Roda loop das rodadas
    do
    {
        temp = throwPlay(select, q);
        select = temp;

    } while (isMatch());

    // Salva dados do vencedor na Engine Data
    data->md_data.t_player = definePlayerVencedor(select);

    // Finaliza Partida
    end_Match();
    imprime_MatrixQ();

    return;
}

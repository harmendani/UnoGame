/* Implementa as rotinas de 'Estado.h' */

void start_StateGame(estado *s)
{
    /*Inicializa sub-estados S*/
    strcpy(s->state_contagem, DEFAULT);
    strcpy(s->state_mesa, DEFAULT);
    strcpy(s->state_maos, DEFAULT);

    /*Inicializa Estados S*/
    strcpy(s->stateGame, DEFAULT);
    strcpy(s->stateNext, DEFAULT);

    return;
}

char *build_StateGame()
{
    char sub_estado_1[4]; //Guarda s1
    char sub_estado_2[4]; //Guarda s2
    char sub_estado_3[4]; //Guarda s3

    return DEFAULT;
}

static char *build_SubEstado_1(player *j)
{
    char *sub_estado_1 = (char *)malloc(4 * sizeof(char)); // Guarda s1

    int montante = j->visaoPlayer.contagem.i_quantMontante;
    int pilhaMesa = j->visaoPlayer.contagem.i_quantMesa;
    if (montante <= pilhaMesa)
    {
        strcpy(sub_estado_1, S1);
    }
    else
    {
        if (montante <= (2 * pilhaMesa))
        {
            strcpy(sub_estado_1, S2);
        }
        else
        {
            strcpy(sub_estado_1, S3);
        }
    }

    return sub_estado_1;
}

static char *build_SubEstado_2(player *j)
{

    char *sub_estado_2 = (char *)malloc(4 * sizeof(char)); // Guarda s2

    int contCartaAcao, contCartaCoringa4, contCartaCoringa;

    contCartaCoringa4 = contadorDeCartasCuringa_4(M_l);
    contCartaAcao = contadorDeCartasAcao(M_l);
    contCartaCoringa = contadorDeCartasCuringa(M_l);
    if (j->visaoPlayer.contagem.i_quantMesa > 3)
    {
        if (contCartaCoringa4 == QTD_CARTAS_CORINGA || contCartaAcao >= 12)
        {
            strcpy(sub_estado_2, S4);
        }
        else
        {
            if (contCartaCoringa >= 4 || contCartaAcao >= 6)
            {
                strcpy(sub_estado_2, S5);
            }
            else
            {
                strcpy(sub_estado_2, S6);
            }
        }
    }
    else
    {
        strcpy(sub_estado_2, S6);
    }

    return sub_estado_2;
}

static char *build_SubEstado_3(player *j)
{
    char *sub_estado_3 = (char *)malloc(5 * sizeof(char)); //Guarda s3
    int quantJogador = j->visaoPlayer.jogador.i_quantJogador;
    int quantAdv = j->visaoPlayer.jogador.i_quantadversario;

    if (quantJogador > quantAdv)
    {
        strcpy(sub_estado_3, S7);
    }
    if (quantAdv == quantJogador)
    {
        strcpy(sub_estado_3, S8);
    }
    else
    {
        strcpy(sub_estado_3, S9);
    }

    return sub_estado_3;
}

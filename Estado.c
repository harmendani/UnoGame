/* Implementa as rotinas de 'Estado.h' */

void build_StateGame(player *j)
{
    //memset(j->estadoPlayer.stateGame, NULL, 10);
    char *sub_estado_1 = build_SubEstado_1(j); //Guarda s1
    char *sub_estado_2 = build_SubEstado_2(j); //Guarda s2
    char *sub_estado_3 = build_SubEstado_3(j); //Guarda s3

    strcpy(j->estadoPlayer.stateGame, sub_estado_1);

    strcat(j->estadoPlayer.stateGame, sub_estado_2);

    strcat(j->estadoPlayer.stateGame, sub_estado_3);

    return;
}

void build_StateProx(player *j)
{

    //memset(j->estadoPlayer.stateProx, NULL, 10);
    char *sub_estado_1 = build_SubEstado_1(j); //Guarda s1
    char *sub_estado_2 = build_SubEstado_2(j); //Guarda s2
    char *sub_estado_3 = build_SubEstado_3(j); //Guarda s3

    strcpy(j->estadoPlayer.stateProx, sub_estado_1);

    strcat(j->estadoPlayer.stateProx, sub_estado_2);

    strcat(j->estadoPlayer.stateProx, sub_estado_3);

    return;
}

static char *build_SubEstado_1(player *j)
{
    char *sub_estado_1 = (char *)malloc(4 * sizeof(char)); // Guarda s1

    carta *c = lst_ObterCartaRef(M_l);

    switch (c->TipoCarta)
    {
    case NORMAL:
        strcpy(sub_estado_1, S1);
        break;
    case ACAO:
        strcpy(sub_estado_1, S2);
        break;
    case CORINGA:
        strcpy(sub_estado_1, S3);
        break;
    default:
        puts("\n Erro em escolha build_subEstado1!");
        exit(0);
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
    if (j->visaoPlayer.contagem.i_quantMesa >= 4)
    {
        if (contCartaCoringa4 == 4 || contCartaAcao >= 12)
        {
            strcpy(sub_estado_2, S4);
        }
        else
        {
            if (contCartaCoringa4 > 0 || contCartaAcao >= 6)
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
    char *sub_estado_3 = (char *)malloc(3 * sizeof(char)); //Guarda s3
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
    if (quantJogador < quantAdv)
    {
        strcpy(sub_estado_3, S9);
    }

    return sub_estado_3;
}

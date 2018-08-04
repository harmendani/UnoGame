/* Implementa as rotinas de 'Estado.h' */

static void start_StateGame(estado *s)
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

static char *build_SubEstado_1()
{
    char sub_estado_1[4];        // Guarda s1
    strcpy(sub_estado_1, "000"); // Inicializa valor Default
    int montante = v_QuantMontante();
    int pilhaMesa = v_QuantMesa();
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

static char *build_SubEstado_2()
{

    char sub_estado_2[4]; // Guarda s2
    strcpy(sub_estado_2, "000");
    return sub_estado_2;
}

static char *build_SubEstado_3()
{
    char sub_estado_3[4];        //Guarda s3
    strcpy(sub_estado_3, "000"); // Inicializa valor Default
    return sub_estado_3;
}

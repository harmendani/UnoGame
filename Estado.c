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
}




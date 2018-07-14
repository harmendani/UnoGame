/* Implementa as rotinas de 'Estado.h' */


void start_StateGame(estado *s)
{

    for (int i = 0; i < 9; i++)
    {
        s->stateGame[i] = '0'; 
        s->stateNext[i] = '0';
    }
    
}




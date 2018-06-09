/* Implementa as rotinas de 'Estado.h' */


void start_StateGame(estado s)
{

    for (int i = 0; i < 9; i++)
    {
        s.stateGame[i] = '0';
    }

}

void start_StateNext(estado s){
    for (int i = 0; i < 9; i++)
    {
        s.stateNext[i] = '0';
    }
}


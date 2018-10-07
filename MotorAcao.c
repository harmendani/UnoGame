/* Implementa a interface "MotorAcao.h" com funções e procedimentos
** que manipulam as ações básicas e tomadas de decisões mais complexas
*/

ActionSet *start_ActionSet(player *p)
{
    ActionSet *set = (ActionSet *)malloc(sizeof(ActionSet));
    inicializaActionSet(set);
    defActionSet(p, set);
    return set;
}

inicializaActionSet(ActionSet *a)
{

    a->caseCor = lst_cria();
    a->caseNumero = lst_cria();
    a->caseSimbolo = lst_cria();

    bool coringaComprar = false;
    bool coringaNormal = false;
    int numberAction = 0;

    return;
}

void defActionSet(player *p, ActionSet *a)
{

    switch (p->visaoPlayer.mesa.c_cartaMesa->TipoCarta)
    {
    case NORMAL:

        break;
    case ACAO:

        break;
    case CORINGA:

        break;
    default:
        puts("\n\n ERRO de carta em ACTION_SET \n\n");
        exit(0);
    }
    return;
}

/* Rotinas de mecânicas básicas de cartas de Ação */

void runAction_Comprar4(player *p)
{

    int contador = 4;
    while (contador > 0)
    {
        transferirCartaMontanteParaJogador(p);
        contador--;
    }
    return;
}

void runAction_Comprar2(player *p)
{

    int contador = 2;
    while (contador > 0)
    {
        transferirCartaMontanteParaJogador(p);
        contador--;
    }
    return;
}

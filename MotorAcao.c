/* Implementa a interface "MotorAcao.h" com funções e procedimentos
** que manipulam as ações básicas e tomadas de decisões mais complexas
*/

ActionSet *start_ActionSet(player *p)
{
    ActionSet *set = (ActionSet *)malloc(sizeof(ActionSet));
    defActionSet(p, set);
    return set;
}

void defActionSet(player *p, ActionSet *a)
{

    /* INICIALIZA VARIÁVEIS */
    a->caseList = lst_cria();

    a->normalCor = false;
    a->normalNumero = false;
    a->acaoCor = false;
    a->acaoSimbolo = false;
    a->acaoCorSimbolo = false;
    a->coringa = false;

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

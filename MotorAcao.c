/* Implementa a interface "MotorAcao.h" com funções e procedimentos
** que manipulam as ações básicas e tomadas de decisões mais complexas
*/

ActionSet *start_ActionSet(player *p)
{
    ActionSet *set = (ActionSet *)malloc(sizeof(ActionSet));
    defActionSet(p, set);
    return set;
}

void inicializaActionSet(ActionSet *a)
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
    inicializaActionSet(a);

    switch (p->visaoPlayer.mesa.c_cartaMesa->TipoCarta)
    {
    case NORMAL:
        calc_ActionSet_NUMERO(p, a);
        calc_ActionSet_COR(p, a);
        calc_ActionSet_CORINGA(p, a);
        break;
    case ACAO:
        calc_ActionSet_SIMBOLO(p, a);
        calc_ActionSet_COR(p, a);
        calc_ActionSet_CORINGA(p, a);
        break;
    case CORINGA:
        calc_ActionSet_CORINGA(p, a);
        break;
    default:
        puts("\n\n ERRO de carta em ACTION_SET \n\n");
        exit(0);
    }
    return;
}

/* Rotinas para calcular possibilidades diante de carta da mesa e salvar numa lista */

void calc_ActionSet_COR(player *p, ActionSet *a)
{
    Lista *normal = p->cartasNormal;
    Lista *acao = p->cartasAcao;

    while (normal != NULL)
    {

        if (normal->Carta.CorCarta == p->visaoPlayer.mesa.c_cartaMesa->CorCarta)
        {
            carta temp = lst_ObterCarta(normal);
            a->caseCor = lst_Insere(a->caseCor, temp);
            a->numberAction++;
        }
        normal = normal->prox;
    }

    while (acao != NULL)
    {

        if (acao->Carta.CorCarta == p->visaoPlayer.mesa.c_cartaMesa->CorCarta)
        {
            carta temp = lst_ObterCarta(acao);
            a->caseCor = lst_Insere(a->caseCor, temp);
            a->numberAction++;
        }
        acao = acao->prox;
    }

    return;
}

void calc_ActionSet_NUMERO(player *p, ActionSet *a)
{
    Lista *normal = p->cartasNormal;

    while (normal != NULL)
    {
        if (normal->Carta.numFace == p->visaoPlayer.mesa.c_cartaMesa->numFace)
        {
            carta temp = lst_ObterCarta(normal);
            a->caseNumero = lst_Insere(a->caseNumero, temp);
            a->numberAction++;
        }
        normal = normal->prox;
    }

    return;
}

void calc_ActionSet_SIMBOLO(player *p, ActionSet *a)
{
    Lista *acao = p->cartasAcao;

    while (acao != NULL)
    {
        if (acao->Carta.TipoCarta == p->visaoPlayer.mesa.c_cartaMesa->TipoCarta)
        {
            carta temp = lst_ObterCarta(acao);
            a->caseSimbolo = lst_Insere(a->caseSimbolo, temp);
            a->numberAction++;
        }
        acao = acao->prox;
    }

    return;
}

void calc_ActionSet_CORINGA(player *p, ActionSet *a)
{

    if (p->numDeCartasCoringa > 0)
    {
        a->numberAction++;

        Lista *coringaTemp = p->cartasCoringa;
        while (coringaTemp != NULL)
        {

            if (coringaTemp->Carta.AcaoCarta = CORINGA_COMPRAR_4)
            {
                a->coringaComprar = true;
            }
            a->coringaNormal = true;
            coringaTemp = coringaTemp->prox;
        }
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

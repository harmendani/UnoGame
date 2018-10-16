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
    a->coringaComprar = false;
    a->coringaNormal = false;
    a->normalAction = false;
    a->acaoAction = false;
    a->numberAction = 0;
    a->varCor = 0;
    a->varNum = 0;
    a->action[MENOR_PESO] = false;
    a->action[MAIOR_PESO] = false;
    a->action[COR_DESCARTE] = false;
    a->action[NUM_DESCARTE] = false;

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

        calc_ActionSet_quantCor(a);
        calc_ActionSet_quantNum(a);

        break;
    case ACAO:
        calc_ActionSet_SIMBOLO(p, a);
        calc_ActionSet_COR(p, a);
        calc_ActionSet_CORINGA(p, a);

        calc_ActionSet_quantCor(a);
        calc_ActionSet_quantNum(a);
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

bool isActionController(player *p, bool isAction)
{

    if (isAction == false)
    {
        transferirCartaMontanteParaJogador(p);
        carta temp = lst_ObterCarta(p->listaMaos);
        isAction = onlyActionMatch(p, temp);
        if (isAction)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

bool onlyActionMatch(player *p, carta c)
{

    if (c.TipoCarta == CORINGA)
    {
        return true;
    }
    else
    {
        if (c.TipoCarta == ACAO)
        {
            if (p->visaoPlayer.mesa.c_cartaMesa->AcaoCarta == c.AcaoCarta || p->visaoPlayer.mesa.c_cartaMesa->CorCarta == c.CorCarta)
            {
                return true;
            }
        }
        if (c.TipoCarta == NORMAL)
        {
            if (p->visaoPlayer.mesa.c_cartaMesa->CorCarta == c.CorCarta || p->visaoPlayer.mesa.c_cartaMesa->numFace == c.numFace)
            {
                return true;
            }
        }
    }

    return false;
}
bool execute_ActionSet(player *p)
{

    ActionSet *set = start_ActionSet(p);
    bool action = calc_AcaoForActionSet(p, set);
    action = isActionController(p, action);

    if (action)
    {
        return true;
    }
    return false;
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
            a->normalAction = true;
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
            a->acaoAction = true;
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
            a->normalAction = true;
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
        if (acao->Carta.AcaoCarta == p->visaoPlayer.mesa.c_cartaMesa->AcaoCarta)
        {
            carta temp = lst_ObterCarta(acao);
            a->caseSimbolo = lst_Insere(a->caseSimbolo, temp);
            a->numberAction++;
            a->acaoAction = true;
        }
        acao = acao->prox;
    }

    return;
}

void calc_ActionSet_CORINGA(player *p, ActionSet *a)
{

    if (p->numDeCartasCoringa > 0)
    {

        Lista *coringaTemp = p->cartasCoringa;
        while (coringaTemp != NULL)
        {

            if (coringaTemp->Carta.AcaoCarta == CORINGA_COMPRAR_4)
            {
                a->coringaComprar = true;
                a->numberAction++;
            }
            else
            {
                a->coringaNormal = true;
                a->numberAction++;
            }
            coringaTemp = coringaTemp->prox;
        }
    }

    return;
}

void calc_ActionSet_quantCor(ActionSet *a)
{

    int corTemp = 99;
    if (a->caseCor != NULL)
    {
        a->varCor++;
        corTemp = a->caseCor->Carta.CorCarta;
    }
    if (a->caseNumero != NULL)
    {
        Lista *l = a->caseNumero;
        while (l != NULL)
        {
            if (l->Carta.CorCarta != corTemp)
            {
                switch (l->Carta.CorCarta)
                {
                case AMARELO:
                    a->varCor++;
                    break;
                case AZUL:
                    a->varCor++;
                    break;
                case VERDE:
                    a->varCor++;
                    break;
                case VERMELHO:
                    a->varCor++;
                    break;
                default:
                    puts("\nErro contadorDeCartasPorCorJogador()..\n");
                    exit(0);
                    break;
                }
            }
            l = l->prox;
        }
    }

    if (a->caseSimbolo != NULL)
    {
        Lista *l = a->caseSimbolo;
        while (l != NULL)
        {
            switch (l->Carta.CorCarta)
            {
            case AMARELO:
                a->varCor++;
                break;
            case AZUL:
                a->varCor++;
                break;
            case VERDE:
                a->varCor++;
                break;
            case VERMELHO:
                a->varCor++;
                break;
            default:
                puts("\nErro contadorDeCartasPorCorJogador()..\n");
                exit(0);
                break;
            }
            l = l->prox;
        }
    }

    return;
}

void calc_ActionSet_quantNum(ActionSet *a)
{
    int numTemp = 99;
    if (a->caseNumero != NULL)
    {
        a->varNum++;
        numTemp = a->caseNumero->Carta.numFace;
    }
    if (a->caseCor != NULL)
    {
        Lista *l = a->caseCor;

        while (l != NULL)
        {
            if (l->Carta.TipoCarta == NORMAL && l->Carta.numFace != numTemp)
            {
                switch (l->Carta.numFace)
                {

                case 0:
                    a->varNum++;
                    break;
                case 1:
                    a->varNum++;
                    break;
                case 2:
                    a->varNum++;
                    break;
                case 3:
                    a->varNum++;
                    break;
                case 4:
                    a->varNum++;
                    break;
                case 5:
                    a->varNum++;
                    break;
                case 6:
                    a->varNum++;
                    break;
                case 7:
                    a->varNum++;
                    break;
                case 8:
                    a->varNum++;
                    break;
                case 9:
                    a->varNum++;
                    break;
                default:
                    puts("\nErro contadorDeCartasPorNumero()..\n");
                    exit(0);
                    break;
                }
            }
            l = l->prox;
        }
    }

    return;
}

/* Rotinas Primárias de Ações */

bool calc_AcaoForActionSet(player *p, ActionSet *a)
{

    if (a->numberAction > 0)
    {
        a->action[MENOR_PESO] = calc_AcaoMenorPeso(a);
        a->action[MAIOR_PESO] = calc_AcaoMaiorPeso(a);
        a->action[COR_DESCARTE] = calc_AcaoCorDescarte(a);
        a->action[NUM_DESCARTE] = calc_AcaoNumDescarte(a);

        return true;
    }
    return false;
}

bool calc_AcaoMenorPeso(ActionSet *a)
{

    if (a->normalAction)
    {
        return true;
    }
    if (a->coringaComprar == true || a->coringaNormal == true)
    {
        if (a->acaoAction)
            return true;
    }

    return false;
}

bool calc_AcaoMaiorPeso(ActionSet *a)
{
    if (a->coringaComprar == true || a->coringaNormal == true)
    {
        return true;
    }

    if (a->acaoAction)
    {
        return true;
    }

    return false;
}

bool calc_AcaoCorDescarte(ActionSet *a)
{
    if (a->varCor > 1)
    {
        return true;
    }

    return false;
}

bool calc_AcaoNumDescarte(ActionSet *a)
{

    if (a->varNum > 1)
    {
        return true;
    }
    return false;
}

/* Rotinas de mecânicas básicas de cartas de Ação */

player *runAction_Comprar4(player *p)
{

    int contador = 4;
    while (contador > 0)
    {
        transferirCartaMontanteParaJogador(p->adversario);
        contador--;
    }
    return p;
}

player *runAction_Comprar2(player *p)
{

    int contador = 2;
    while (contador > 0)
    {
        transferirCartaMontanteParaJogador(p->adversario);
        contador--;
    }
    return p;
}

player *runAction_Pular(player *p)
{
    return p;
}
player *runAction_Revert(player *p)
{
    return p;
}

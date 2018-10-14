/* Implementa a interface "MotorAcao.h" com funções e procedimentos
** que manipulam as ações básicas e tomadas de decisões mais complexas
*/

ActionSet *start_ActionSet(player *p)
{
    ActionSet *set = (ActionSet *)malloc(sizeof(ActionSet));
    defActionSet(p, set);
    calc_AcaoForActionSet(p, set);
    return set;
}

void inicializaActionSet(ActionSet *a)
{

    a->caseCor = lst_cria();
    a->caseNumero = lst_cria();
    a->caseSimbolo = lst_cria();
    a->coringaComprar = false;
    a->coringaNormal = false;
    a->numberAction = 0;
    a->varCor = 0;
    a->varNum = 0;

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
        break;
    case CORINGA:
        calc_ActionSet_CORINGA(p, a);

        calc_ActionSet_quantNum(a);
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
        if (acao->Carta.TipoCarta == p->visaoPlayer.mesa.c_cartaMesa->AcaoCarta)
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

            if (coringaTemp->Carta.AcaoCarta == CORINGA_COMPRAR_4)
            {
                a->coringaComprar = true;
            }
            else
            {
                a->coringaNormal = true;
            }
            coringaTemp = coringaTemp->prox;
        }
    }

    return;
}

void calc_ActionSet_quantCor(ActionSet *a)
{
    if (a->caseNumero != NULL)
    {
        Lista *l = a->caseNumero;
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
    
    if(a->caseNumero != NULL){
        a->caseNumero++;
    }
    if (a->caseCor != NULL)
    {
        Lista *l = a->caseCor;
        while (l != NULL)
        {
            if (l->Carta.TipoCarta == NORMAL)
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
        a->action[MENOR_PESO] = calc_AcaoMenorPeso(p);
        a->action[MAIOR_PESO] = calc_AcaoMaiorPeso(p);
        a->action[COR_DESCARTE] = calc_AcaoCorDescarte(a);
        a->action[NUM_DESCARTE] = calc_AcaoNumDescarte(a);

        return true;
    }
    return false;
}

bool calc_AcaoMenorPeso(player *p)
{

    if (p->numDeCartasNormal > 0)
    {
        return true;
    }

    return false;
}

bool calc_AcaoMaiorPeso(player *p)
{
    if (p->numDeCartasCoringa > 0 || p->numDeCartasAcao > 0)
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

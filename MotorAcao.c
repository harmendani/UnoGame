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

    a->caseList = lst_cria();

    switch (p->visaoPlayer.mesa.c_cartaMesa->TipoCarta)
    {
    case NORMAL:
        calc_ActionSet_NORMAL(p, a);
        break;
    case ACAO:
        calc_ActionSet_ACAO(p, a);
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

void calc_ActionSet_NORMAL(player *p, ActionSet *a)
{

    if (p->numDeCartasCoringa > 0)
    {

        Lista *l = p->cartasCoringa;

        while (l != NULL)
        {

            carta temp1 = lst_ObterCarta(l);
            a->caseList = lst_Insere(a->caseList, temp1);

            l = l->prox;
        }
    }

    if (p->numDeCartasAcao > 0)
    {
        Lista *l = p->cartasAcao;

        while (l != NULL)
        {
            if (l->Carta.CorCarta == p->visaoPlayer.mesa.c_cartaMesa->CorCarta)
            {
                carta temp1 = lst_ObterCarta(l);
                a->caseList = lst_Insere(a->caseList, temp1);
            }
            l = l->prox;
        }
    }

    if (p->numDeCartasNormal > 0)
    {
        Lista *l = p->cartasNormal;

        while (l != NULL)
        {
            if (l->Carta.CorCarta == p->visaoPlayer.mesa.c_cartaMesa->CorCarta || l->Carta.numFace == p->visaoPlayer.mesa.c_cartaMesa->numFace)
            {

                carta temp1 = lst_ObterCarta(l);
                a->caseList = lst_Insere(a->caseList, temp1);
            }
            l = l->prox;
        }
    }

    return;
}

void calc_ActionSet_ACAO(player *p, ActionSet *a)
{

    if (p->numDeCartasAcao > 0)
    {
        Lista *l = p->cartasAcao;

        while (l != NULL)
        {
            if (l->Carta.AcaoCarta == p->visaoPlayer.mesa.c_cartaMesa->AcaoCarta)
            {
                carta temp1 = lst_ObterCarta(l);
                a->caseList = lst_Insere(a->caseList, temp1);
            }
            l = l->prox;
        }
    }

    if (p->numDeCartasCoringa > 0)
    {

        Lista *l = p->cartasCoringa;

        while (l != NULL)
        {

            carta temp1 = lst_ObterCarta(l);
            a->caseList = lst_Insere(a->caseList, temp1);

            l = l->prox;
        }
    }

    return;
}

void calc_ActionSet_CORINGA(player *p, ActionSet *a)
{

    if (p->numDeCartasCoringa > 0)
    {

        Lista *l = p->cartasCoringa;

        while (l != NULL)
        {
            if (l->Carta.AcaoCarta == p->visaoPlayer.mesa.c_cartaMesa->AcaoCarta)
            {
                carta temp1 = lst_ObterCarta(l);
                a->caseList = lst_Insere(a->caseList, temp1);
            }
            l = l->prox;
        }
    }
    return;
}

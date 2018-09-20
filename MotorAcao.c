/* Implementa a interface "MotorAcao.h" com funções e procedimentos
** que manipulam as ações básicas e tomadas de decisões mais complexadas
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

        break;

    case CORINGA:

        break;
    default:
        puts("\n\n ERRO de carta em ACTION_SET \n\n");
    }
    return;
}

void calc_ActionSet_NORMAL(player *p, ActionSet *a)
{

    

    if (p->numDeCartasCoringa > 0)
    {

        Lista *l = p->listaMaos;

        while (l != NULL)
        {
            if (l->Carta.TipoCarta == CORINGA)
            {
                carta temp1 = lst_ObterCarta(l);
                a->caseList = lst_Insere(a->caseList, temp1);
            }
            l = l->prox;
        }
    }

    if (p->numDeCartasAcao > 0)
    {
        Lista *l = p->listaMaos;

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
        Lista *l = p->listaMaos;

        while (l != NULL)
        {
            if (l->Carta.CorCarta == p->visaoPlayer.mesa.c_cartaMesa->CorCarta)
            {
                carta temp1 = lst_ObterCarta(l);
                a->caseList = lst_Insere(a->caseList, temp1);
            }
            l = l->prox;
        }

        l = p->listaMaos;
        while (l != NULL)
        {
            if (l->Carta.numFace == p->visaoPlayer.mesa.c_cartaMesa->numFace)
            {
                carta temp1 = lst_ObterCarta(l);
                a->caseList = lst_Insere(a->caseList, temp1);
            }
            l = l->prox;
        }
    }

    return;
}

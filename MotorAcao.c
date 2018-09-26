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
    
    a->normalCor = false;;
    a->normalNumero = false;
    a->acaoCor = false;
    a->acaoSimbolo = false;
    a->acaoCorSimbolo = false;
    a->coringa = false;

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
        a->coringa = true;
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
                a->acaoCor = true;
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
                if (temp1.CorCarta == p->visaoPlayer.mesa.c_cartaMesa->CorCarta)
                {
                    a->normalCor = true;
                }
                else
                {
                    a->normalNumero = true;
                }
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
            if (l->Carta.AcaoCarta == p->visaoPlayer.mesa.c_cartaMesa->AcaoCarta || p->visaoPlayer.mesa.c_cartaMesa->CorCarta == l->Carta.CorCarta)
            {
                carta temp1 = lst_ObterCarta(l);
                if (temp1.CorCarta == p->visaoPlayer.mesa.c_cartaMesa->CorCarta && temp1.AcaoCarta == p->visaoPlayer.mesa.c_cartaMesa->AcaoCarta)
                {
                    a->acaoCorSimbolo = true;
                }
                else
                {
                    if (temp1.CorCarta == p->visaoPlayer.mesa.c_cartaMesa->CorCarta)
                    {
                        a->acaoCor = true;
                    }
                    else
                    {
                        a->acaoSimbolo = true;
                    }
                }
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
            a->coringa = true;
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

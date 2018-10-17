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
        /* Atualiza visao do Jogador */
        executarMotorVisao(p);
        //puts("\n\n // MOTOR VISAO ATUALIZADO\n");
        ActionSet *actSet = start_ActionSet(p);
        isAction = calc_AcaoForActionSet(p, actSet);
        /*if(isAction){
            puts("\n\n // MOTOR VISAO ATUALIZADO COM SUCESSO!!\n");
            Lista *l = NULL;
            puts("\nMao do jogador agora:->\n");
            lst_Imprime(p->listaMaos);
            puts("\nAcoes possiveis:->\n");
            printf("\n action MenorPeso: %d", actSet->action[MENOR_PESO]);
            printf("\n action MaiorPeso: %d", actSet->action[MAIOR_PESO]);
            printf("\n action CorDescarte: %d", actSet->action[COR_DESCARTE]);
            printf("\n action NumDescarte %d", actSet->action[NUM_DESCARTE]);
            puts("\nCarta Match:->\n");
            carta temp = lst_ObterCarta(M_l);
            puts("\n Enquanto isso.. na visao mesa: ");
            l = lst_Insere(l, temp);
            lst_Imprime(l);
            
        }*/
        return isAction;
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

/* Rotinas principais da mecânica de ação */

bool execute_ActionSet(player *p)
{

    ActionSet *set = start_ActionSet(p);
    bool action = calc_AcaoForActionSet(p, set);
    action = isActionController(p, action);

    //testa escolha carta por action[n]
    carta *slt = NULL;
    if (set->action[COR_DESCARTE] == true)
    {
        slt = select_ActionCorDescarte(set, p);
        M_l = lst_Insere(M_l, *slt);
        p->listaMaos = lst_RemovePorId(p->listaMaos, slt->id);
    }
    // fim testa

    if (action)
    {
        return true;
    }
    return false;
}

void choose_ActionSet(ActionSet *a)
{
    return;
}

carta *select_ActionMaiorPeso(ActionSet *a, player *p)
{
    // Cartas Coringa
    Lista *coringaComprar = lst_cria();
    Lista *coringaNormal = lst_cria();

    // Cartas de Ação
    Lista *acaoSimbolo = lst_cria();
    Lista *acaoCor = lst_cria();
    // Variavel auxiliar de retorno
    carta *c = NULL;

    if (a->coringaComprar)
    {

        coringaComprar = p->cartasCoringa;
        while (coringaComprar != NULL)
        {
            if (coringaComprar->Carta.AcaoCarta == CORINGA_COMPRAR_4)
            {
                c = lst_ObterCartaRef(coringaComprar);
                return c;
            }
            coringaComprar = coringaComprar->prox;
        }
    }
    if (a->coringaNormal == true && coringaComprar == NULL)
    {

        coringaNormal = p->cartasCoringa;
        while (coringaNormal != NULL)
        {
            if (coringaNormal->Carta.AcaoCarta == CORINGA_NOACTION)
            {
                c = lst_ObterCartaRef(coringaNormal);
                return c;
            }
            coringaNormal = coringaNormal->prox;
        }
    }
    if (a->acaoAction)
    {
        acaoCor = a->caseCor;
        acaoSimbolo = a->caseSimbolo;

        while (acaoCor != NULL)
        {
            if (acaoCor->Carta.TipoCarta == ACAO && acaoCor->Carta.AcaoCarta == COMPRAR_DUAS)
            {
                c = lst_ObterCartaRef(acaoCor);
                return c;
            }
            if (acaoCor->Carta.TipoCarta == ACAO && acaoCor->Carta.AcaoCarta == PULAR)
            {
                c = lst_ObterCartaRef(acaoCor);
                return c;
            }
            if (acaoCor->Carta.TipoCarta == ACAO && acaoCor->Carta.AcaoCarta == REVERTER)
            {
                c = lst_ObterCartaRef(acaoCor);
                return c;
            }

            acaoCor = acaoCor->prox;
        }

        while (acaoSimbolo != NULL)
        {
            if (acaoSimbolo->Carta.TipoCarta == ACAO && acaoSimbolo->Carta.AcaoCarta == COMPRAR_DUAS)
            {
                c = lst_ObterCartaRef(acaoSimbolo);
                return c;
            }
            if (acaoSimbolo->Carta.TipoCarta == ACAO && acaoSimbolo->Carta.AcaoCarta == PULAR)
            {
                c = lst_ObterCartaRef(acaoSimbolo);
                return c;
            }
            if (acaoSimbolo->Carta.TipoCarta == ACAO && acaoSimbolo->Carta.AcaoCarta == REVERTER)
            {
                c = lst_ObterCartaRef(acaoSimbolo);
                return c;
            }

            acaoSimbolo = acaoSimbolo->prox;
        }
    }
    return NULL;
}

carta *select_ActionMenorPeso(ActionSet *a, player *p)
{
    // Cartas do tipo normal
    Lista *normalCor = lst_cria();
    Lista *normalNum = lst_cria();

    // Cartas do tipo Acao
    Lista *acaoSimbolo = lst_cria();
    Lista *acaoCor = lst_cria();

    // Variável auxiliar de retorno
    carta *c = NULL;
    if (a->normalAction)
    {
        normalCor = a->caseCor;
        while (normalCor != NULL)
        {
            if (normalCor->Carta.TipoCarta == NORMAL)
            {
                c = lst_ObterCartaRef(normalCor);
                return c;
            }
            normalCor = normalCor->prox;
        }

        normalNum = a->caseNumero;
        while (normalCor != NULL)
        {
            c = lst_ObterCartaRef(normalCor);
            return c;
        }
    }
    else
    {
        acaoCor = a->caseCor;
        acaoSimbolo = a->caseSimbolo;

        while (acaoCor != NULL)
        {
            if (acaoCor->Carta.TipoCarta == ACAO && acaoCor->Carta.AcaoCarta == COMPRAR_DUAS)
            {
                c = lst_ObterCartaRef(acaoCor);
                return c;
            }
            if (acaoCor->Carta.TipoCarta == ACAO && acaoCor->Carta.AcaoCarta == PULAR)
            {
                c = lst_ObterCartaRef(acaoCor);
                return c;
            }
            if (acaoCor->Carta.TipoCarta == ACAO && acaoCor->Carta.AcaoCarta == REVERTER)
            {
                c = lst_ObterCartaRef(acaoCor);
                return c;
            }

            acaoCor = acaoCor->prox;
        }

        while (acaoSimbolo != NULL)
        {
            if (acaoSimbolo->Carta.TipoCarta == ACAO && acaoSimbolo->Carta.AcaoCarta == COMPRAR_DUAS)
            {
                c = lst_ObterCartaRef(acaoSimbolo);
                return c;
            }
            if (acaoSimbolo->Carta.TipoCarta == ACAO && acaoSimbolo->Carta.AcaoCarta == PULAR)
            {
                c = lst_ObterCartaRef(acaoSimbolo);
                return c;
            }
            if (acaoSimbolo->Carta.TipoCarta == ACAO && acaoSimbolo->Carta.AcaoCarta == REVERTER)
            {
                c = lst_ObterCartaRef(acaoSimbolo);
                return c;
            }

            acaoSimbolo = acaoSimbolo->prox;
        }
    }
    return NULL;
}

carta *select_ActionCorDescarte(ActionSet *a, player *p)
{

    return NULL;
}

carta *select_ActionNumDescarte(ActionSet *a, player *p)
{

    Lista *normalCor = a->caseCor;
    Lista *normalNum = a->caseNumero;
    Lista *acaoSimbolo = a->caseSimbolo;

    int corMaior = maiorIndiceCorDescarte(a, p);
    carta *c = NULL;

    while (acaoSimbolo != NULL)
    {
        if (acaoSimbolo->Carta.CorCarta == corMaior)
        {
            c = lst_ObterCartaRef(acaoSimbolo);
            return c;
        }
        acaoSimbolo = acaoSimbolo->prox;
    }
    while (normalCor != NULL)
    {
        if (normalCor->Carta.CorCarta == corMaior)
        {
            c = lst_ObterCartaRef(normalCor);
            return c;
        }
        normalCor = normalCor->prox;
    }
    while (normalNum != NULL)
    {
        if (normalNum->Carta.CorCarta == corMaior)
        {
            c = lst_ObterCartaRef(normalNum);
            return c;
        }
        normalNum = normalNum->prox;
    }
    return NULL;
}

/* Rotinas de calculo */

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

cor maiorIndiceCorDescarte(ActionSet *a, player *p)
{
    // Lista auxiliares de cartas normais e de ação
    Lista *normalNum = lst_cria();
    Lista *normalCor = lst_cria();
    Lista *acaoSimbolo = lst_cria();

    float indiceAmarelo = (float)p->visaoPlayer.jogador.historico.i_amarelo + (float)p->visaoPlayer.mesa.historico.i_amarelo;
    float indiceAzul = (float)p->visaoPlayer.jogador.historico.i_azul + (float)p->visaoPlayer.mesa.historico.i_azul;
    float indiceVermelho = (float)p->visaoPlayer.jogador.historico.i_vermelho + (float)p->visaoPlayer.mesa.historico.i_vermelho;
    float indiceVerde = (float)p->visaoPlayer.jogador.historico.i_verde + (float)p->visaoPlayer.mesa.historico.i_verde;

    if (indiceAmarelo == (float)0)
    {
        indiceAmarelo = (float)0;
    }
    else
    {
        indiceAmarelo = indiceAmarelo / (float)25;
    }
    if (indiceAzul == (float)0)
    {
        indiceAzul = (float)0;
    }
    else
    {
        indiceAzul = indiceAzul / (float)25;
    }
    if (indiceVermelho == (float)0)
    {
        indiceVermelho = (float)0;
    }
    else
    {
        indiceVermelho = indiceVermelho / (float)25;
    }
    if (indiceVerde == (float)0)
    {
        indiceVerde = (float)0;
    }
    else
    {
        indiceVerde = indiceVerde / (float)25;
    }

    bool verdeTrue = false;
    bool azulTrue = false;
    bool amareloTrue = false;
    bool vermelhoTrue = false;

    normalNum = a->caseNumero;
    while (normalNum != NULL)
    {
        if (normalNum->Carta.CorCarta == VERDE)
        {
            verdeTrue = true;
        }
        if (normalNum->Carta.CorCarta == VERMELHO)
        {
            vermelhoTrue = true;
        }
        if (normalNum->Carta.CorCarta == AMARELO)
        {
            amareloTrue = true;
        }
        if (normalNum->Carta.CorCarta == AZUL)
        {
            azulTrue = true;
        }
        normalNum = normalNum->prox;
    }

    normalCor = a->caseCor;
    while (normalCor != NULL)
    {
        if (normalCor->Carta.CorCarta == VERDE)
        {
            verdeTrue = true;
        }
        if (normalCor->Carta.CorCarta == VERMELHO)
        {
            vermelhoTrue = true;
        }
        if (normalCor->Carta.CorCarta == AMARELO)
        {
            amareloTrue = true;
        }
        if (normalCor->Carta.CorCarta == AZUL)
        {
            azulTrue = true;
        }
        normalCor = normalCor->prox;
    }

    acaoSimbolo = a->caseSimbolo;
    while (acaoSimbolo != NULL)
    {
        if (acaoSimbolo->Carta.CorCarta == VERDE)
        {
            verdeTrue = true;
        }
        if (acaoSimbolo->Carta.CorCarta == VERMELHO)
        {
            vermelhoTrue = true;
        }
        if (acaoSimbolo->Carta.CorCarta == AMARELO)
        {
            amareloTrue = true;
        }
        if (acaoSimbolo->Carta.CorCarta == AZUL)
        {
            azulTrue = true;
        }
        acaoSimbolo = acaoSimbolo->prox;
    }
    float actionCor[4];
    for (int i = 0; i < 4; i++)
    {
        actionCor[i] = (float)0;
    }
    if (amareloTrue)
    {
        actionCor[AMARELO] = indiceAmarelo;
    }
    if (azulTrue)
    {
        actionCor[AZUL] = indiceAzul;
    }
    if (verdeTrue)
    {
        actionCor[VERDE] = indiceVerde;
    }
    if (vermelhoTrue)
    {
        actionCor[VERMELHO] = indiceVermelho;
    }

    int maior = (float)0;
    float aux = (float)0;
    int maiorCor = -1;
    for (int i = 0; i < 4; i++)
    {
        if (actionCor[i] != (float)0)
        {
            aux = actionCor[i];
            if (aux > maior)
            {
                maior = aux;
                maiorCor = i;
            }
        }
    }

    return maiorCor;
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

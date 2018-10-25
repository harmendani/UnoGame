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
        calc_ActionSet_ALL(p, a);
        calc_ActionSet_CORINGA(p, a);

        break;
    default:
        puts("\n\n ERRO de carta em DEF_ACTION_SET \n\n");
        exit(0);
    }
    return;
}

ActionSet *isActionController(player *p, bool isAction, ActionSet *a)
{

    if (isAction == false)
    {
        transferirCartaMontanteParaJogador(p);
        /* Atualiza visao do Jogador */
        executarMotorVisao(p);
        ActionSet *actSet = start_ActionSet(p);
        isAction = calc_AcaoForActionSet(p, actSet);

        /*if (isAction)
        {
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
        if (isAction)
        {

            return actSet;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return a;
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

/* Motor de Decisão */

acaoSeq executarMotorDecisao(player *p, ActionSet *a)
{

    /*
    int *scoreAcao = calc_ScoreAction(p, a);
    
    int maior = -9;
    int aux = -9;
    acaoSeq acaoIndice = -9;

    for (int i = 0; i < 4; i++)
    {
        printf("acao: %d\n", i);
        
        if (a->action[i])
        {
            if (scoreAcao[i] > aux)
            {
                maior = scoreAcao[i];
                acaoIndice = i;
                aux = maior;
            }
        }
    }*/
    acaoSeq acaoIndice = -9;
    for (int j = 0; j < 4; j++)
    {
        if (a->action[j] == true)
        {
            acaoIndice = j;
            //printf("\n //a->action: %d\n", a->action[j]);
        }
        //printf("\n for em acaoIndice: %d", a->action[j]);
    }

    // printf("\n //acaoIndice: %d\n", acaoIndice);
    return acaoIndice;
}

int *calc_ScoreAction(player *p, ActionSet *a)
{
    int *scoreAcao = (int *)malloc(sizeof(int) * 4);

    for (int i = 0; i < 4; i++)
    {
        scoreAcao[i] = -1;
    }
    int numCoringa = p->numDeCartasCoringa;
    int numAcao = p->numDeCartasAcao;
    int coringaDescartada = contadorDeCartasCuringa_4(M_l);
    int acaoDescartada = contadorDeCartasAcao(M_l);

    if (numCoringa > 0 || numAcao > 0)
    {
        scoreAcao[MAIOR_PESO]++;
    }
    if (p->numDeCartasNormal > (numCoringa + numAcao))
    {
        scoreAcao[MENOR_PESO]++;
        scoreAcao[MENOR_PESO]++;
        scoreAcao[NUM_DESCARTE]++;
        scoreAcao[COR_DESCARTE]++;
        if (numAcao > 1)
        {

            scoreAcao[COR_DESCARTE]++;
            scoreAcao[MAIOR_PESO]++;
        }
        if (numCoringa && a->coringaComprar)
        {
            scoreAcao[MAIOR_PESO]++;
            scoreAcao[MENOR_PESO]++;
        }
        if (numCoringa && a->coringaNormal)
        {

            scoreAcao[MAIOR_PESO]++;
        }
        if (numCoringa < p->numDeCartasAcao)
        {
            scoreAcao[MENOR_PESO]++;
        }
        if (numAcao < p->numDeCartasNormal)
        {
            scoreAcao[NUM_DESCARTE]++;
            scoreAcao[NUM_DESCARTE]++;
        }
        else
        {
            scoreAcao[COR_DESCARTE]++;
        }
    }
    else
    {
        scoreAcao[MAIOR_PESO]++;
        if (a->acaoAction && numCoringa)
        {
            scoreAcao[MAIOR_PESO]++;
            scoreAcao[MAIOR_PESO]++;
        }
        if (a->acaoAction && numCoringa == 0)
        {
            scoreAcao[MAIOR_PESO]++;
            scoreAcao[MENOR_PESO]++;
        }
        if (a->acaoAction > 1)
        {
            scoreAcao[COR_DESCARTE]++;
        }
    }
    if (p->visaoPlayer.jogador.i_quantJogador >= p->visaoPlayer.jogador.i_quantadversario)
    {
        scoreAcao[MAIOR_PESO] = scoreAcao[MAIOR_PESO] * 2;
        scoreAcao[MENOR_PESO]++;
        if (p->numDeCartasNormal > 1 && a->varCor > 1)
        {
            scoreAcao[NUM_DESCARTE]++;
            scoreAcao[NUM_DESCARTE]++;
            scoreAcao[COR_DESCARTE]++;
            scoreAcao[COR_DESCARTE]++;
        }
    }
    else
    {
        scoreAcao[MENOR_PESO] = scoreAcao[MENOR_PESO] * 2;
        scoreAcao[MAIOR_PESO]++;
    }
    if (coringaDescartada > 3)
    {
        scoreAcao[MAIOR_PESO] = scoreAcao[MAIOR_PESO] * 2;
    }
    else
    {
        scoreAcao[MAIOR_PESO]--;
        scoreAcao[MENOR_PESO]++;
    }
    if (acaoDescartada > (p->numDeCartasAcao) && p->numDeCartasNormal > 1)
    {
        scoreAcao[COR_DESCARTE] = scoreAcao[COR_DESCARTE] * 2;
    }
    else
    {
        scoreAcao[MENOR_PESO] = scoreAcao[MENOR_PESO] * 2;
        scoreAcao[NUM_DESCARTE]++;
    }
    if (p->numDeCartasNormal < p->numDeCartasAcao && a->varCor > 1)
    {
        scoreAcao[COR_DESCARTE] = scoreAcao[COR_DESCARTE] * 2;
    }
    else
    {
        scoreAcao[NUM_DESCARTE] = scoreAcao[NUM_DESCARTE] * 2;
        scoreAcao[MENOR_PESO]++;
    }

    return scoreAcao;
}

/* Rotinas principais da mecânica de ação */

player *executarMotorAcao(player *p, q_Learning *q)
{

    ActionSet *set = start_ActionSet(p);
    bool action = calc_AcaoForActionSet(p, set);
    set = isActionController(p, action, set);
    player *pprox = NULL;
    player *temp = p;

    if (set != NULL)
    {
        acaoSeq aSeq = executarMotorDecisao(p, set);
        if (aSeq < 0 || aSeq > 3)
        {
            printf("\n AcaoSeq fora de faixa em MotorDEAcao!! -- value >> %d", aSeq);
            exit(0);
        }

        if (p->id == 1)
        {
            if (p->seqAcao == 0)
            {
                p->codAcao = aSeq;
                
                if (p->codAcao < 0 || p->codAcao > 5)
                {
                    printf("\n CodAcao fora de faixa em MotorDEAcao seqACao == 0!! -- value >> %d", p->codAcao);
                    exit(0);
                }
                build_StateGame(p);
                addSate_MatrixQ(p->estadoPlayer.stateGame);
            }
            if (p->seqAcao == 1)
            {
                build_StateProx(p);
                addSate_MatrixQ(p->estadoPlayer.stateProx);

                /* Update Q Learning */
                if (p->codAcao < 0 || p->codAcao > 5)
                {
                    printf("\n CodAcao fora de faixa em MotorDEAcao seqACao == 1!! -- value %s >> %d", p->nome, p->codAcao);
                    exit(0);
                }
                updateQLearning(q, p);
                p->seqAcao = 1;
                if (p != temp)
                {
                    puts("\n ERRO FATAL MOTOR ACAO DO PLAYER !!\n");
                    exit(0);
                }
                return p;
            }
        }
        pprox = select_ActionSet(set, aSeq, p);

        return pprox;
    }
    else
    {
        p->seqAcao = -1;
        pprox = p->adversario;

        return pprox;
    }
}

player *execute_ActionSet(player *p, carta *c)
{
    player *select = NULL;

    switch (c->TipoCarta)
    {
    case NORMAL:
        M_l = lst_Insere(M_l, *c);
        p->listaMaos = lst_RemovePorId(p->listaMaos, c->id);
        select = p->adversario;
        break;
    case ACAO:
        if (c->AcaoCarta == COMPRAR_DUAS)
        {
            M_l = lst_Insere(M_l, *c);
            p->listaMaos = lst_RemovePorId(p->listaMaos, c->id);
            select = runAction_Comprar2(p);
        }
        if (c->AcaoCarta == REVERTER)
        {
            M_l = lst_Insere(M_l, *c);
            p->listaMaos = lst_RemovePorId(p->listaMaos, c->id);
            select = runAction_Revert(p);
        }
        if (c->AcaoCarta == PULAR)
        {
            M_l = lst_Insere(M_l, *c);
            p->listaMaos = lst_RemovePorId(p->listaMaos, c->id);
            select = runAction_Pular(p);
        }
        break;
    case CORINGA:
        if (c->AcaoCarta == CORINGA_COMPRAR_4)
        {
            M_l = lst_Insere(M_l, *c);
            p->listaMaos = lst_RemovePorId(p->listaMaos, c->id);
            select = runAction_Comprar4(p);
        }
        if (c->AcaoCarta == CORINGA_NOACTION)
        {
            M_l = lst_Insere(M_l, *c);
            p->listaMaos = lst_RemovePorId(p->listaMaos, c->id);
            select = p->adversario;
        }

        break;
    default:
        puts("\n ERRO em execute_ActionSet..! \n");
        exit(0);
        break;
    }
    if (select == NULL)
    {
        puts("\n ERRO em execute_ActionSet");
        exit(0);
    }
    return select;
}

player *select_ActionSet(ActionSet *a, acaoSeq as, player *p)
{
    player *select = NULL;
    carta *c = NULL;

    switch (as)
    {
    case MENOR_PESO:
        //puts("\n MENOR PESO antes");
        c = select_ActionMenorPeso(a, p);
        //puts("\n select  PESO antes");
        select = execute_ActionSet(p, c);
        //puts("\n MENOR PESO depois");
        break;
    case MAIOR_PESO:
        //puts("\n maior PESO antes");
        c = select_ActionMaiorPeso(a, p);
        select = execute_ActionSet(p, c);
        //puts("\n maior PESO depois");
        break;
    case COR_DESCARTE:
        //puts("\n cor descarte antes");
        c = select_ActionCorDescarte(a, p);
        select = execute_ActionSet(p, c);
        //puts("\n cor descarte depois");
        break;
    case NUM_DESCARTE:
        //puts("\n num descarte antes");
        c = select_ActionNumDescarte(a, p);
        select = execute_ActionSet(p, c);
        //puts("\n num descarte depois");
        break;
    default:
        //puts("\n ERRO em select_ActionSet..! \n");
        exit(0);
        break;
    }

    return select;
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
        while (normalNum != NULL)
        {

            c = lst_ObterCartaRef(normalNum);
            return c;
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

carta *select_ActionCorDescarte(ActionSet *a, player *p)
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

carta *select_ActionNumDescarte(ActionSet *a, player *p)
{

    // Lista auxiliares para cartas normais
    Lista *normalCor = a->caseCor;
    Lista *normalNum = a->caseNumero;

    int numeroDesc = maiorIndiceNumDescarte(a, p);
    carta *c = NULL;

    while (normalNum != NULL)
    {
        if (normalNum->Carta.numFace == numeroDesc)
        {
            c = lst_ObterCartaRef(normalNum);
            return c;
        }

        normalNum = normalNum->prox;
    }

    while (normalCor != NULL)
    {
        if (normalCor->Carta.TipoCarta == NORMAL)
        {
            if (normalCor->Carta.numFace == numeroDesc)
            {
                c = lst_ObterCartaRef(normalCor);
                return c;
            }
        }
        normalCor = normalCor->prox;
    }

    return NULL;
}

/* Rotinas de calculo */

void calc_ActionSet_COR(player *p, ActionSet *a)
{
    Lista *normal = p->cartasNormal;
    Lista *acao = p->cartasAcao;
    /*puts("\n // CARTAS MESA \n");
    lst_Imprime(M_l);*/

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

void calc_ActionSet_ALL(player *p, ActionSet *a)
{
    Lista *hands = lst_cria();
    hands = p->cartasNormal;
    a->numberAction = contadorDeCartas(p->cartasAcao) + contadorDeCartas(p->cartasNormal);

    if (p->numDeCartasAcao > 0)
    {
        a->acaoAction = true;
        a->caseSimbolo = p->cartasAcao;
    }
    if (p->numDeCartasNormal > 0)
    {
        a->normalAction = true;
        a->caseNumero = p->cartasNormal;
    }
    if (p->visaoPlayer.jogador.historico.i_amarelo > 0)
    {
        a->varCor++;
    }
    if (p->visaoPlayer.jogador.historico.i_azul > 0)
    {
        a->varCor++;
    }
    if (p->visaoPlayer.jogador.historico.i_verde > 0)
    {
        a->varCor++;
    }
    if (p->visaoPlayer.jogador.historico.i_vermelho > 0)
    {
        a->varCor++;
    }

    while (hands != NULL)
    {
        if (hands->Carta.TipoCarta != CORINGA)
        {
            a->caseCor = lst_Insere(a->caseCor, hands->Carta);
        }
        switch (hands->Carta.numFace)
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
        hands = hands->prox;
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
    //puts("\n --INDICE DESCARTE");
    if (indiceAmarelo == (float)0)
    {
        indiceAmarelo = (float)0;
    }
    else
    {
        indiceAmarelo = indiceAmarelo / (float)25;
        //printf("\n AMARELO : %f ", indiceAmarelo);
    }
    if (indiceAzul == (float)0)
    {
        indiceAzul = (float)0;
    }
    else
    {
        indiceAzul = indiceAzul / (float)25;
        //printf("\n AZUL : %f ", indiceAzul);
    }
    if (indiceVermelho == (float)0)
    {
        indiceVermelho = (float)0;
    }
    else
    {
        indiceVermelho = indiceVermelho / (float)25;
        // printf("\n VERMELHO : %f ", indiceVermelho);
    }
    if (indiceVerde == (float)0)
    {
        indiceVerde = (float)0;
    }
    else
    {
        indiceVerde = indiceVerde / (float)25;
        //printf("\n VERDE : %f ", indiceVerde);
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

int maiorIndiceNumDescarte(ActionSet *a, player *p)
{
    // Lista auxiliares de cartas normais
    Lista *normalNum = lst_cria();
    Lista *normalCor = lst_cria();

    // Auxiliares para retorno
    float aux = (float)0;
    float maior = (float)-1;
    int numeroI;
    normalNum = a->caseNumero;
    while (normalNum != NULL)
    {
        float aux = calculaIndiceNum(normalNum->Carta.numFace, p);
        if (aux > maior)
        {
            maior = aux;
            numeroI = normalNum->Carta.numFace;
        }
        normalNum = normalNum->prox;
    }

    normalCor = a->caseCor;
    while (normalCor != NULL)
    {
        if (normalCor->Carta.TipoCarta == NORMAL)
        {
            float aux = calculaIndiceNum(normalCor->Carta.numFace, p);
            if (aux > maior)
            {
                maior = aux;
                numeroI = normalCor->Carta.numFace;
            }
        }
        normalCor = normalCor->prox;
    }

    return numeroI;
}

float calculaIndiceNum(int num, player *p)
{

    float indiceNum[10];
    for (int i = 0; i < 10; i++)
    {
        indiceNum[i] = (float)0;
    }

    for (int i = 0; i < 10; i++)
    {
        indiceNum[i] = (float)p->visaoPlayer.jogador.historico.numero[i] + (float)p->visaoPlayer.mesa.historico.numero[i];
    }

    bool aux = true;
    while (aux == true)
    {

        switch (num)
        {

        case 0:

            if (indiceNum[num] != (float)0)
            {
                indiceNum[num] = indiceNum[num] / 4;
                //printf("\n Carta 0 : %f", indiceNum[num]);
            }
            aux = false;
            break;

        case 1:
            if (indiceNum[num] != (float)0)
            {
                indiceNum[num] = indiceNum[num] / 8;
                //printf("\n Carta 1 : %f", indiceNum[num]);
            }
            aux = false;
            break;

        case 2:
            if (indiceNum[num] != (float)0)
            {
                indiceNum[num] = indiceNum[num] / 8;
                //printf("\n Carta 2 : %f", indiceNum[num]);
            }
            aux = false;
            break;
        case 3:
            if (indiceNum[num] != (float)0)
            {
                indiceNum[num] = indiceNum[num] / 8;
                //printf("\n Carta 3 : %f", indiceNum[num]);
            }
            aux = false;
            break;
        case 4:
            if (indiceNum[num] != (float)0)
            {
                indiceNum[num] = indiceNum[num] / 8;
                //printf("\n Carta 4 : %f", indiceNum[num]);
            }
            aux = false;
            break;
        case 5:
            if (indiceNum[num] != (float)0)
            {
                indiceNum[num] = indiceNum[num] / 8;
                //printf("\n Carta 5 : %f", indiceNum[num]);
            }
            aux = false;
            break;
        case 6:
            if (indiceNum[num] != (float)0)
            {
                indiceNum[num] = indiceNum[num] / 8;
                //printf("\n Carta 6 : %f", indiceNum[num]);
            }
            aux = false;
            break;
        case 7:
            if (indiceNum[num] != (float)0)
            {
                indiceNum[num] = indiceNum[num] / 8;
                //printf("\n Carta 7 : %f", indiceNum[num]);
            }
            aux = false;
            break;
        case 8:
            if (indiceNum[num] != (float)0)
            {
                indiceNum[num] = indiceNum[num] / 8;
                //printf("\n Carta 8 : %f", indiceNum[num]);
            }
            aux = false;
            break;
        case 9:
            if (indiceNum[num] != (float)0)
            {
                indiceNum[num] = indiceNum[num] / 8;
                //printf("\n Carta 9 : %f", indiceNum[num]);
            }
            aux = false;
            break;
        default:
            puts("\nErro contadorDeCartasPorNumero()..\n");
            exit(0);
            break;
        }
    }
    return indiceNum[num];
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

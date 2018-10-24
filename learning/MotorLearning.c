q_Learning *executaMotorLearning(Data *data)
{

    q_Learning *q = defineParametrosHeuristica(data);
    start_MatrixQ();
    if (errno != 0)
    {
        puts("\n Erro em motorLearning!\n");
        exit(0);
    }
    return q;
}

q_Learning *defineParametrosHeuristica(Data *data)
{

    q_Learning *qdata = (q_Learning *)malloc(sizeof(q_Learning));
    qdata->discountFactor = (float)(data->md_learning.md_discountFactor) / 100;
    qdata->learningRate = (float)(data->md_learning.md_learningRate) / 100;
    qdata->exploitation = (float)(data->md_learning.md_exploitation) / 100;

    return qdata;
}

/* Inicializa tabela de aprendizado */
void start_MatrixQ()
{

    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrixQ[i][j] = -1.0f;
            if (i == 0 && j > 0)
            {
                matrixQ[i][j] = (float)(j - 1);
            }
            if (j == 0 && i > 0)
            {
                matrixQ[i][j] = 100.0f;
            }
        }
    }
    matrixQ[0][0] = -1.0f;

    return;
}

void imprime_MatrixQ()
{

    for (int k = 0; k < 28; k++)
    {
        printf("\n");
        printf("%d\t", k);

        for (int t = 0; t < 5; t++)
        {
            printf("%.0f", matrixQ[k][t]);
            printf("\t");
        }
    }
    return;
}

void addSate_MatrixQ(char *s)
{
    float stateTemp = (float)strtol(s, NULL, 10);
    /*printf("\n Literal > %s", s);
    printf("\n floating > %.0f", stateTemp);*/

    for (int i = 1; i < 28; i++)
    {
        if (matrixQ[i][0] == stateTemp)
            break;

        if (matrixQ[i][0] == 100)
        {
            matrixQ[i][0] = stateTemp;
            break;
        }
    }

    return;
}

int calcReward(player *p)
{
    /* Realiza contagem das maos dos jogadores */
    int qtdPlayer = contadorDeCartas(p->listaMaos);
    int qtdAdv = contadorDeCartas(p->adversario->listaMaos);

    /* Salva hipoteses */
    bool qtdJogadorFavoravel = false;
    bool qtdIndicePlayer = false;

    /* Declara variável para salvar recompensa */
    int reward = 0;

    /* Realiza comparações das contagens */
    
    if (qtdPlayer <= qtdAdv)
    {
        qtdJogadorFavoravel = true;
        reward = reward + 5;

        if (qtdPlayer <= 4)
        {
            qtdIndicePlayer = true;
            reward = reward + 5;
        }
        return reward;
    }
    else
    {
        if (qtdPlayer > 4)
        {
            reward = -10;
        }
        else
        {
            reward = -5;
        }
        return reward;
    }

    return reward;
}



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
            printf("%2.f", matrixQ[k][t]);
            printf("\t");
        }
    }
    return;
}
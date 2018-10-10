

q_Learning *defineParametrosHeuristica(Data *data)
{

    q_Learning *qdata = (q_Learning *)malloc(sizeof(q_Learning));
    qdata->discountFactor = (float)(data->md_learning.md_discountFactor) / 100;
    qdata->learningRate = (float)(data->md_learning.md_learningRate) / 100;
    qdata->exploitation = (float)(data->md_learning.md_exploitation) / 100;

    printf(" \nq data discont %f", qdata->discountFactor);
    printf(" \nq data learning %f", qdata->learningRate);
    printf(" \nq data exploit %f", qdata->exploitation);
    return qdata;
}
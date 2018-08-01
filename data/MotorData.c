static Data *referenciaDataEntrada()
{

    //Declara variável do tipo data
    Data *dataEntrada = (Data *)malloc(sizeof(Data));
    //Inicializa fatores do Q-Learning
    dataEntrada->md_learning.md_discountFactor = 0;
    dataEntrada->md_learning.md_learningRate = 0;
    dataEntrada->md_learning.md_exploitation = 0;
    //Inicializa fatores do Treinamento
    dataEntrada->md_training = MD_ZERO;

    return dataEntrada;
}

static Data *ponteiroData()
{
    Data *dataEntrada = referenciaDataEntrada();
    if (dataEntrada != NULL)
    {
        return dataEntrada;
    }
    else
    {
        puts("\nSistema sem memória..Programa será abortado!");
        exit(0);
    }
}

static void informarDadosEntrada()
{
    puts("\n========ENGINE_DATA========");
    puts("\n=====Training=====");

    puts(" -LOW = 2500\n -MEDIUM = 5000\n -HIGH = 7000\n -INTENSE = 10000\n");
    puts("===========================");
    puts("\n=====Learning=====");

    puts(" -Desconto_Temporal = ]0,100[\n -Fator_Aprendizagem = ]0,100[\n -Taxa_Exploração = [0,100[");
    puts("==============================");
    return;
}

static Data *dadosEntrada()
{

    Data *dataEntrada = ponteiroData();
    bool dadosOk = false;
    fflush(stdin);

    puts("\nEntre com o grau do treino: ");
    scanf("%d", &dataEntrada->md_training);
    fflush(stdin);

    puts("\nEntre com o Desconto_Temporal: ");
    scanf("%d", &dataEntrada->md_learning.md_discountFactor);
    fflush(stdin);

    puts("\nEntre com o Fator_Aprendizagem: ");
    scanf("%d", &dataEntrada->md_learning.md_learningRate);
    fflush(stdin);

    puts("\nEntre com o Taxa_Exploração: ");
    scanf("%d", &dataEntrada->md_learning.md_exploitation);
    fflush(stdin);

    dadosOk = validarDadosEntrada(dataEntrada);

    if (dadosOk)
    {
        system("cls");
        imprimirDadosEntrada(dataEntrada);
        return dataEntrada;
    }

    puts("\nDados inválidos..programa será abortado!");
    exit(0);
}

static bool validarDadosEntrada(Data *dataEntrada)
{

    if (dataEntrada->md_training <= 0)
        return false;
    if (dataEntrada->md_learning.md_discountFactor <= 0 || dataEntrada->md_learning.md_discountFactor >= 100)
        return false;
    if (dataEntrada->md_learning.md_learningRate <= 0 || dataEntrada->md_learning.md_learningRate >= 100)
        return false;
    if (dataEntrada->md_learning.md_exploitation < 0 || dataEntrada->md_learning.md_exploitation >= 100)
        return false;

    return true;
}

void imprimirDadosEntrada(Data *dataEntrada)
{

    puts("\n****Print Dados_Entrada****\n");
    printf(">md_training: %d\n", dataEntrada->md_training);
    printf(">md_discountFactor: %d%% \n", dataEntrada->md_learning.md_discountFactor);
    printf(">md_learningRate: %d%% \n", dataEntrada->md_learning.md_learningRate);
    printf(">md_exploitation: %d%% \n", dataEntrada->md_learning.md_exploitation);
    puts("\n**************************\n");
}

Data *executaMotorData()
{

    informarDadosEntrada();
    return dadosEntrada();
}

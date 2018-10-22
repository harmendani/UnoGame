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
        return dataEntrada;
    }

    puts("\nDados inválidos..programa será abortado!");
    exit(0);
}

static bool validarDadosEntrada(Data *dataEntrada)
{

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
    puts("\n****Input Data****\n");
    printf(">md_discountFactor: %d%% \n", dataEntrada->md_learning.md_discountFactor);
    printf(">md_learningRate: %d%% \n", dataEntrada->md_learning.md_learningRate);
    printf(">md_exploitation: %d%% \n", dataEntrada->md_learning.md_exploitation);
    printf("\n>md_training: %d de %d.", dataEntrada->md_training, (dataEntrada->md_training + 1));
    puts("\n**************************\n");
}

void imprimirDadosSaida(Data *dataSaida)
{
    puts("\n****Output Data****\n");
    printf(">Jogador %s - : ", dataSaida->md_data.t_player->nome);
    printf(">Vitórias %d: ", dataSaida->md_data.t_player->vitorias);
    printf(">Jogador %s - : ", dataSaida->md_data.t_player->adversario->nome);
    printf(">Vitórias %d: ", dataSaida->md_data.t_player->vitorias);
    puts("\n**************************\n");
    return;
}

String textMotorData(char c)
{

    if (c == 'h')
        return "Training\t Desconto_Temporal\t Fator_Aprendizagem\t Taxa_Exploração\n";
    if (c == 'x')
        return ".txt";
    if (c == 'n')
        return "runSystem";
    if (c == 't')
    {
        time_t curtime;
        time(&curtime);
        return ctime(&curtime);
    }
    if (c = 'c')
        return "****************************ENGINE DATA****************************\n";
    if (c = 'f')
        return "***************************END ENGINE DATA*************************\n\n";

    return NULL;
}

void writeFileRunSystem(Data *data)
{
    // Obter Strings necessárias
    String nameFile = textMotorData('n');
    String nameExtension = textMotorData('x');
    String headerMenu = textMotorData('h');
    String startHeader = textMotorData('c');
    String endHeader = textMotorData('f');

    // Escreve cabeçalho do arquivo
    String path = createNameAndPath(DIR, nameFile, nameExtension);
    FILE *file = openFileTxt(path);
    writeStringEndTxt(file, startHeader);
    writeStringEndTxt(file, headerMenu);

    //Escreve Parâmetros de entrada: Data.
    writeIntegerEndTxt(file, "%d\t\t\t", data->md_training);
    writeIntegerEndTxt(file, "%d\t\t\t", data->md_learning.md_discountFactor);
    writeIntegerEndTxt(file, "%d\t\t\t", data->md_learning.md_learningRate);
    writeIntegerEndTxt(file, "%d\n\n", data->md_learning.md_exploitation);

    //Escreve Parâmetros de Hora local e finaliza operação
    String textTime = textMotorData('t');
    fprintf(file, "Current Time = %s\n", textTime);
    writeStringEndTxt(file, endHeader);

    if (ferror(file))
    {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    fclose(file);

    sleep(1);
    printf("\n\n..");
    sleep(1.5);
    printf("....");
    sleep(1);
    printf("..");
    printf(".writeFileRunSystem - Sucess in the writing in disk!..");
    sleep(2);
    printf("..");

    return;
}

Data *executaMotorData()
{
    informarDadosEntrada();
    Data *data = dadosEntrada();
    writeFileRunSystem(data);

    return data;
}

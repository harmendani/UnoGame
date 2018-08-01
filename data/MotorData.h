/* Recebe e manipula os dados da plataforma de simulação*/

/* Exporta tipos declarados */

typedef struct Q_Values LearnFactors;
typedef enum I_Treino IntensidadeTreino;
typedef struct EngineData Data;

/* Enumera o número de partidas do jogo*/
static enum I_Treino {
    MD_ZERO = 0,
    MD_LOW = 2500,
    MD_MEDIUM = 5000,
    MD_HIGH = 7000,
    MD_INTENSE = 10000
};

/* Define a estrutura secundária de valores para o Q_Learning*/
static struct Q_Values
{
    int md_discountFactor; // Desconto temporal
    int md_learningRate;   // Fato de aprendizagem
    int md_exploitation;   // Taxa de exploração
};

/* Define a estrutura principal do Motor*/
static struct EngineData
{
    LearnFactors md_learning;
    IntensidadeTreino md_training;
};

/*Obter ponteiro para tipo Data validando retorno correto*/
static Data *ponteiroData();

/*Aloca espaço e inicializa variável retornando-a*/
static Data *referenciaDataEntrada();

/*Libera dados de entrada da memória*/
static void liberarDataEntrada();

/*Informa os dados a serem lidos pelo sistema*/
static void informarDadosEntrada();

/* Ler os dados de entrada via teclado e retornar referência*/
static Data *dadosEntrada();

/* Valida os dados de entrada*/
static bool validarDadosEntrada(Data *);

/* Imprime na tela os dados de entrada*/
void imprimirDadosEntrada(Data *);

/*Rotina principal exporta dados de entrada*/
Data *executaMotorData();

#ifndef MOTORDATA_C
#define MOTORDATA_C
#include ".\MotorData.c"
#endif

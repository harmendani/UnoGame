/* Interface - Cartas.h - O c�digo-fonte abaixo abstrai as propriedades b�sicas 
da entidade CARTAS -- Desenvolvido por Pedro Harmendani - 2018 --*/

// Prot�tipos
void inicializa_Cartas();

//CONSTANTES
#define QTD_CARTAS_TOTAL 108
// Cartas com PESO CORINGA
#define QTD_CARTAS_CORINGA_COMPRAR_4 4
#define QTD_CARTAS_CORINGA 4
// Cartas com PESO A��O
#define QTD_CARTAS_INVERTE 8
#define QTD_CARTAS_SALTA 8
#define QTD_CARTAS_COMPRAR_2 8
// Cartas NORMAL
#define QTD_CARTAS_AZUL 19     /* Cartas de 0 a 9 -- Apenas uma carta de n� 0 */
#define QTD_CARTAS_VERMELHO 19 /* Cartas de 0 a 9 -- Apenas uma carta de n� 0 */
#define QTD_CARTAS_AMARELO 19  /* Cartas de 0 a 9 -- Apenas uma carta de n� 0 */
#define QTD_CARTAS_VERDE 19    /* Cartas de 0 a 9 -- Apenas uma carta de n� 0 */

// PESOS DAS CARTAS ESPECIAIS
#define PESO_CARTA_CORINGA 50
#define PESO_CARTA_ACAO 20

//TIPOS DEFINIDOS
typedef enum corDaCarta {
    AZUL,
    VERMELHO,
    AMARELO,
    VERDE,
    PRETO
} cor;

typedef enum tipoDaCarta {
    NORMAL, // Peso definido pelo numFace
    CORINGA = PESO_CARTA_CORINGA,
    ACAO = PESO_CARTA_ACAO

} tipo;

typedef enum acaoDaCarta {
    NORMAL_NOACTION,
    COMPRAR_DUAS,
    REVERTER,
    PULAR,
    CORINGA_NOACTION,
    CORINGA_COMPRAR_4
} acao;

typedef struct cartas
{
    cor CorCarta;
    tipo TipoCarta;
    acao AcaoCarta;
    short int numFace;
    int id; /* Usado para embaralhar as cartas */
} carta;

/* Vari�veis Globais do tipo : carta */

// Guarda cartas Azuis
carta vetorCartasAzul[24];

// Guarda cartas Vermelhas
carta vetorCartasVermelho[24];

// Guarda cartas Amarelas
carta vetorCartasAmarelo[24];

// Guarda cartas Verdes
carta vetorCartasVerde[24];

// Guarda cartas de Zero
carta vetorDeCartasZero[4];

// Guarda cartas Coringa
carta vetorDeCartasCoringa[8];

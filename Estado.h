/* Define e manipula estados do jogo*/

//CONSTANTES
/* Define os estados do jogo para cada vis�o*/
//V1 (Baixo, Médio e Alto) - Visão Contagem
#define S1 "01"
#define S2 "10"
#define S3 "11"
//V2 (Baixo, Médio e Alto) - Visão Mesa
#define S4 "100"
#define S5 "101"
#define S6 "110"
//V3(Crítico, Equilibrado e Favorável) -Visão das Maõs
#define S7 "0111"
#define S8 "1000"
#define S9 "1001"

estado estadoGlobal; // Variável global que representa o Estado do jogo

//TIPOS

struct Estado
{
    /* Salva o estado atual do jogo formado por uma tupla Sv1 X Sv2 X Sv3 qualquer */
    char stateGame[9];
    /* Salva o próximo estado do jogo */
    char stateNext[9];
} typedef struct Estado estado;

//ROTINAS
/* Concatena os estados S no vetor stateGame[] para criar os estados do jogo*/
void build_StateGame();
/*Define a string '000000000' para iniciar a variável de estado do jogo*/
void start_StateGame();
/*Define a string '000000000' para limpar o estado anterior salvo*/
void start_StateNext();

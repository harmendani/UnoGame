//Tipos
typedef enum acaoSequencia
{
    MENOR_PESO = 0,
    MAIOR_PESO = 1,
    COR_DESCARTE = 2,
    NUM_DESCARTE = 3

} acaoSeq;

typedef struct caseStruct
{

    Lista *caseCor;
    Lista *caseNumero;
    Lista *caseSimbolo;
    bool coringaComprar;
    bool coringaNormal;
    bool normalAction;
    bool acaoAction;
    int varCor;
    int varNum;
    
    int numberAction;
    bool action[4];

} ActionSet;

/* Rotinas secundárias de Ações */
void defActionSet(player *, ActionSet *);
ActionSet *start_ActionSet(player *);
void inicializaActionSet(ActionSet *);

//Mecânicas básicas de cartas de ação
void runAction_Comprar4(player *);
void runAction_Comprar2(player *);

//Rotinas para calcular possibilidades diante de carta da mesa e salvar numa lista
void calc_ActionSet_COR(player *, ActionSet *);
void calc_ActionSet_NUMERO(player *, ActionSet *);
void calc_ActionSet_SIMBOLO(player *, ActionSet *);
void calc_ActionSet_CORINGA(player *, ActionSet *);

/* Rotinas Primárias de Ações */
bool calc_AcaoForActionSet(player *p, ActionSet *); // Calcula todas possibilidades e salva no vetor action[]
bool calc_AcaoMenorPeso(ActionSet *);
bool calc_AcaoMaiorPeso(ActionSet *);
bool calc_AcaoNumDescarte(ActionSet *);
bool calc_AcaoCorDescarte(ActionSet *);


#ifndef MOTORACAO_C
#define MOTORACAO_C
#include "../MotorAcao.c"
#endif

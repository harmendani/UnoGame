//Tipos
typedef struct caseStruct
{

    Lista *caseCor;
    Lista *caseNumero;
    Lista *caseSimbolo;
    bool coringaComprar;
    bool coringaNormal;
    int numberAction;

} ActionSet;

typedef enum acaoSequencia
{
    MENOR_PESO = 1,
    MAIOR_PESO = 2,
    COR_DESCARTE = 3,
    NUM_DESCARTE = 4

} acaoSeq;

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

#ifndef MOTORACAO_C
#define MOTORACAO_C
#include "../MotorAcao.c"
#endif
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
bool onlyActionMatch(player *, carta);
bool isActionController(player *, bool);

/* Rotinas principais da mecânica de ação */
player *execute_ActionSet(player *, carta *);
bool create_ActionSet(player *);
player *select_ActionSet(ActionSet *, acaoSeq, player *);
carta *select_ActionMaiorPeso(ActionSet *, player *);
carta *select_ActionMenorPeso(ActionSet *, player *);
carta *select_ActionCorDescarte(ActionSet *, player *);
carta *select_ActionNumDescarte(ActionSet *, player *);

//Mecânicas básicas de cartas de ação
player *runAction_Comprar4(player *);
player *runAction_Comprar2(player *);
player *runAction_Pular(player *);
player *runAction_Revert(player *);

//Rotinas de cálculo
void calc_ActionSet_COR(player *, ActionSet *);
void calc_ActionSet_NUMERO(player *, ActionSet *);
void calc_ActionSet_SIMBOLO(player *, ActionSet *);
void calc_ActionSet_CORINGA(player *, ActionSet *);
void calc_ActionSet_ALL(player *, ActionSet *);
cor maiorIndiceCorDescarte(ActionSet *, player *);
int maiorIndiceNumDescarte(ActionSet *, player *);
float calculaIndiceNum(int, player *);

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

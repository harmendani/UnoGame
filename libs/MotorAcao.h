//Tipos
typedef struct caseStruct
{

    Lista *caseList;

} ActionSet;

//Rotinas principais
void defActionSet(player *, ActionSet *);
ActionSet *start_ActionSet(player *);

//Rotinas para calcular possibilidades diante de carta da mesa
void calc_ActionSet_NORMAL(player *, ActionSet *);
void calc_ActionSet_ACAO(player *, ActionSet *);
void calc_ActionSet_CORINGA(player *, ActionSet *);

#ifndef MOTORACAO_C
#define MOTORACAO_C
#include "../MotorAcao.c"
#endif
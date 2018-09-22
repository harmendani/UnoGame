
typedef struct caseStruct
{

    Lista *caseList;

} ActionSet;

void defActionSet(player *, ActionSet *);
ActionSet* start_ActionSet(player *);
//
void calc_ActionSet_NORMAL(player *, ActionSet *);
void calc_ActionSet_ACAO(player *, ActionSet *);

#ifndef MOTORACAO_C
#define MOTORACAO_C
#include "../MotorAcao.c"
#endif
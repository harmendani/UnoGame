//Tipos
typedef struct caseStruct
{

    Lista *caseList;
    //CASE NORMAL
    bool normalCor;
    bool normalNumero;
    //CASE NORMAL AND ACTION OR CORINGA
    bool acaoCor;
    bool acaoSimbolo;    //ONLY ACTION
    bool acaoCorSimbolo; //ONLY ACTION
    bool coringa;        // ALL CASES

} ActionSet;

//Rotinas principais
void defActionSet(player *, ActionSet *);
ActionSet *start_ActionSet(player *);

//Mecânicas básicas de cartas de ação
void runAction_Comprar4(player *);
void runAction_Comprar2(player *);


//Rotinas para calcular possibilidades diante de carta da mesa
void calc_ActionSet_NORMAL(player *, ActionSet *);
void calc_ActionSet_ACAO(player *, ActionSet *);
void calc_ActionSet_CORINGA(player *, ActionSet *);

#ifndef MOTORACAO_C
#define MOTORACAO_C
#include "../MotorAcao.c"
#endif
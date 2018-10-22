/* MenuLib.c  -- Desenvolvido por Pedro Harmendani - 2018 --*/

/** Bibliotecas do Sistema**/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#ifndef TIME_H
#define TIME_H
#include <time.h>
#endif

#include <string.h>
#include <ctype.h>
#include <errno.h>
/** Defini��es de linguagem**/
#include <locale.h>

/**Bibliotecas do jogo**/

#include "boobit.c"

#ifndef CARTAS_C
#define CARTAS_C
#include "./data/Cartas.c"
#endif

#ifndef ESTADO_H
#define ESTADO_H
#include "./libs/Estado.h"
#endif

#ifndef MOTORVISAO_H
#define MOTORVISAO_H
#include "./libs/MotorVisao.h"
#endif

#ifndef MOTORACAO_H
#define MOTORACAO_H
#include "./libs/MotorAcao.h"
#endif

#ifndef MOTORPARTIDA_C
#define MOTORPARTIDA_C
#include "MotorPartida.c"
#endif

#ifndef MOTORDATA_H
#define MOTORDATA_H
#include "./libs/MotorData.h"
#endif

#ifndef MOTOR_LEARNING_H
#define MOTOR_LEARNING_H
#include "./libs/MotorLearning.h"
#endif

#ifndef CONTROLLER_C
#define CONTROLLER_C
#include "./controller/Controller.c"
#endif

void startScreen()
{
    setlocale(LC_ALL, "Portuguese");
    puts("______________________________________________________________________________");
    printf("\n \t--- JOGO DE CARTAS UNO --- v0.1 -- SIMULADOR DE PARTIDAS (2018)\n");
    puts("______________________________________________________________________________");
}

void endProgram()
{
    puts("\n");
    printf("\n--- End Program! ---\n");
    puts("______________________________________________________________________________");
    system("pause");
}

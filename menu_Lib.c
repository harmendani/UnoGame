/* MenuLib.c  -- Desenvolvido por Pedro Harmendani - 2018 --*/

/** Bibliotecas do Sistema**/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
/** Defini��es de linguagem**/
#include <locale.h>

/**Bibliotecas do jogo**/
#ifndef ESTADO_H
#define ESTADO_H
#include "Estado.h"
#endif

#ifndef CARTAS_C
#define CARTAS_C
#include "Cartas.c"
#endif

#ifndef MOTORVISAO_H
#define MOTORVISAO_H
#include "MotorVisao.h"
#endif

/*#ifndef MOTORCARTA_H
#define MOTORCARTA_H
#include "MotorCarta.h"
#endif
*/
/*#ifndef PLAYER_H
#define PLAYER_H
#include "Player.h"
#endif*/

#ifndef MOTORPARTIDA_C
#define MOTORPARTIDA_C
#include "MotorPartida.c"
#endif

#ifndef MOTORDATA_H
#define MOTORDATA_H
#include "./data/MotorData.h"
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
    printf("\n--- AT� MAIS ---\n");
    puts("______________________________________________________________________________");
    system("pause");
}

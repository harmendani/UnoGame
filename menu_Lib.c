/* MenuLib.c  -- Desenvolvido por Pedro Harmendani - 2018 --*/

/** Bibliotecas do Sistema**/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Definições de linguagem**/
#include <locale.h>

/**Bibliotecas do jogo**/

#include "Cartas.c"

#ifndef MOTORCARTA_H
#define MOTORCARTA_H
#include "MotorCarta.h"
#endif

#ifndef PLAYER_H
#define PLAYER_H
#include "Player.h"
#endif

void startScreen()
{
    setlocale(LC_ALL, "Portuguese");
    puts("______________________________________________________________________________");
    printf("\n \t--- JOGO DE CARTAS UNO --- v0.1 -- SIMULADOR DE PARTIDAS (2018)\n");
    puts("______________________________________________________________________________");
    puts("\n");
}

void endProgram()
{
    puts("\n");
    printf("\n--- ATÉ MAIS ---\n");
    puts("______________________________________________________________________________");
    system("pause");
}

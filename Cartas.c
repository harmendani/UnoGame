/* Desenvolvido por Pedro Harmendani - 2018*/
/////////////////////////////////////////////
// Dados - Tipo: carta //////////////////////
/////////////////////////////////////////////

/* Abstrai mecanismos para manipular cartas mem�ria*/
#ifndef LISTACARTA_H
#define LISTACARTA_H
#include "ListaCarta.h"
#endif

void inicializa_Cartas()
{

    /* Cartas Verdes */
    // Guarda cartas Verdes

    //Cor da Carta
    vetorCartasVerde[0].CorCarta = VERDE;
    vetorCartasVerde[1].CorCarta = VERDE;
    vetorCartasVerde[2].CorCarta = VERDE;
    vetorCartasVerde[3].CorCarta = VERDE;
    vetorCartasVerde[4].CorCarta = VERDE;
    vetorCartasVerde[5].CorCarta = VERDE;
    vetorCartasVerde[6].CorCarta = VERDE;
    vetorCartasVerde[7].CorCarta = VERDE;
    vetorCartasVerde[8].CorCarta = VERDE;
    vetorCartasVerde[9].CorCarta = VERDE;
    vetorCartasVerde[10].CorCarta = VERDE;
    vetorCartasVerde[11].CorCarta = VERDE;
    /////////////////////////////////////
    vetorCartasVerde[12].CorCarta = VERDE;
    vetorCartasVerde[13].CorCarta = VERDE;
    vetorCartasVerde[14].CorCarta = VERDE;
    vetorCartasVerde[15].CorCarta = VERDE;
    vetorCartasVerde[16].CorCarta = VERDE;
    vetorCartasVerde[17].CorCarta = VERDE;
    vetorCartasVerde[18].CorCarta = VERDE;
    vetorCartasVerde[19].CorCarta = VERDE;
    vetorCartasVerde[20].CorCarta = VERDE;
    vetorCartasVerde[21].CorCarta = VERDE;
    vetorCartasVerde[22].CorCarta = VERDE;
    vetorCartasVerde[23].CorCarta = VERDE;
    // Tipo Carta
    vetorCartasVerde[0].TipoCarta = NORMAL;
    vetorCartasVerde[1].TipoCarta = NORMAL;
    vetorCartasVerde[2].TipoCarta = NORMAL;
    vetorCartasVerde[3].TipoCarta = NORMAL;
    vetorCartasVerde[4].TipoCarta = NORMAL;
    vetorCartasVerde[5].TipoCarta = NORMAL;
    vetorCartasVerde[6].TipoCarta = NORMAL;
    vetorCartasVerde[7].TipoCarta = NORMAL;
    vetorCartasVerde[8].TipoCarta = NORMAL;
    vetorCartasVerde[9].TipoCarta = ACAO;
    vetorCartasVerde[10].TipoCarta = ACAO;
    vetorCartasVerde[11].TipoCarta = ACAO;
    /////////////////////////////////////
    vetorCartasVerde[12].TipoCarta = NORMAL;
    vetorCartasVerde[13].TipoCarta = NORMAL;
    vetorCartasVerde[14].TipoCarta = NORMAL;
    vetorCartasVerde[15].TipoCarta = NORMAL;
    vetorCartasVerde[16].TipoCarta = NORMAL;
    vetorCartasVerde[17].TipoCarta = NORMAL;
    vetorCartasVerde[18].TipoCarta = NORMAL;
    vetorCartasVerde[19].TipoCarta = NORMAL;
    vetorCartasVerde[20].TipoCarta = NORMAL;
    vetorCartasVerde[21].TipoCarta = ACAO;
    vetorCartasVerde[22].TipoCarta = ACAO;
    vetorCartasVerde[23].TipoCarta = ACAO;
    // A��o da Carta
    vetorCartasVerde[0].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[1].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[2].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[3].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[4].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[5].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[6].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[7].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[8].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[9].AcaoCarta = PULAR;
    vetorCartasVerde[10].AcaoCarta = REVERTER;
    vetorCartasVerde[11].AcaoCarta = COMPRAR_DUAS;
    ////////////////////////////////////////////////
    vetorCartasVerde[12].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[13].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[14].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[15].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[16].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[17].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[18].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[19].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[20].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVerde[21].AcaoCarta = PULAR;
    vetorCartasVerde[22].AcaoCarta = REVERTER;
    vetorCartasVerde[23].AcaoCarta = COMPRAR_DUAS;

    //N�mero da Carta
    vetorCartasVerde[0].numFace = 1;
    vetorCartasVerde[1].numFace = 2;
    vetorCartasVerde[2].numFace = 3;
    vetorCartasVerde[3].numFace = 4;
    vetorCartasVerde[4].numFace = 5;
    vetorCartasVerde[5].numFace = 6;
    vetorCartasVerde[6].numFace = 7;
    vetorCartasVerde[7].numFace = 8;
    vetorCartasVerde[8].numFace = 9;

    /////////////////////////////////////
    vetorCartasVerde[12].numFace = 1;
    vetorCartasVerde[13].numFace = 2;
    vetorCartasVerde[14].numFace = 3;
    vetorCartasVerde[15].numFace = 4;
    vetorCartasVerde[16].numFace = 5;
    vetorCartasVerde[17].numFace = 6;
    vetorCartasVerde[18].numFace = 7;
    vetorCartasVerde[19].numFace = 8;
    vetorCartasVerde[20].numFace = 9;

    /* Cartas Azuis */

    //Cor da Carta
    vetorCartasAzul[0].CorCarta = AZUL;
    vetorCartasAzul[1].CorCarta = AZUL;
    vetorCartasAzul[2].CorCarta = AZUL;
    vetorCartasAzul[3].CorCarta = AZUL;
    vetorCartasAzul[4].CorCarta = AZUL;
    vetorCartasAzul[5].CorCarta = AZUL;
    vetorCartasAzul[6].CorCarta = AZUL;
    vetorCartasAzul[7].CorCarta = AZUL;
    vetorCartasAzul[8].CorCarta = AZUL;
    vetorCartasAzul[9].CorCarta = AZUL;
    vetorCartasAzul[10].CorCarta = AZUL;
    vetorCartasAzul[11].CorCarta = AZUL;
    vetorCartasAzul[12].CorCarta = AZUL;
    vetorCartasAzul[13].CorCarta = AZUL;
    vetorCartasAzul[14].CorCarta = AZUL;
    vetorCartasAzul[15].CorCarta = AZUL;
    vetorCartasAzul[16].CorCarta = AZUL;
    vetorCartasAzul[17].CorCarta = AZUL;
    vetorCartasAzul[18].CorCarta = AZUL;
    vetorCartasAzul[19].CorCarta = AZUL;
    vetorCartasAzul[20].CorCarta = AZUL;
    vetorCartasAzul[21].CorCarta = AZUL;
    vetorCartasAzul[22].CorCarta = AZUL;
    vetorCartasAzul[23].CorCarta = AZUL;
    // Tipo da Carta
    vetorCartasAzul[0].TipoCarta = NORMAL;
    vetorCartasAzul[1].TipoCarta = NORMAL;
    vetorCartasAzul[2].TipoCarta = NORMAL;
    vetorCartasAzul[3].TipoCarta = NORMAL;
    vetorCartasAzul[4].TipoCarta = NORMAL;
    vetorCartasAzul[5].TipoCarta = NORMAL;
    vetorCartasAzul[6].TipoCarta = NORMAL;
    vetorCartasAzul[7].TipoCarta = NORMAL;
    vetorCartasAzul[8].TipoCarta = NORMAL;
    vetorCartasAzul[9].TipoCarta = ACAO;
    vetorCartasAzul[10].TipoCarta = ACAO;
    vetorCartasAzul[11].TipoCarta = ACAO;
    ////////////////////////////////////
    vetorCartasAzul[12].TipoCarta = NORMAL;
    vetorCartasAzul[13].TipoCarta = NORMAL;
    vetorCartasAzul[14].TipoCarta = NORMAL;
    vetorCartasAzul[15].TipoCarta = NORMAL;
    vetorCartasAzul[16].TipoCarta = NORMAL;
    vetorCartasAzul[17].TipoCarta = NORMAL;
    vetorCartasAzul[18].TipoCarta = NORMAL;
    vetorCartasAzul[19].TipoCarta = NORMAL;
    vetorCartasAzul[20].TipoCarta = NORMAL;
    vetorCartasAzul[21].TipoCarta = ACAO;
    vetorCartasAzul[22].TipoCarta = ACAO;
    vetorCartasAzul[23].TipoCarta = ACAO;
    // A��o da Carta
    vetorCartasAzul[0].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[1].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[2].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[3].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[4].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[5].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[6].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[7].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[8].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[9].AcaoCarta = PULAR;
    vetorCartasAzul[10].AcaoCarta = REVERTER;
    vetorCartasAzul[11].AcaoCarta = COMPRAR_DUAS;
    /////////////////////////////////////////////
    vetorCartasAzul[12].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[13].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[14].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[15].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[16].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[17].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[18].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[19].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[20].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAzul[21].AcaoCarta = PULAR;
    vetorCartasAzul[22].AcaoCarta = REVERTER;
    vetorCartasAzul[23].AcaoCarta = COMPRAR_DUAS;
    //N�mero da Carta
    vetorCartasAzul[0].numFace = 1;
    vetorCartasAzul[1].numFace = 2;
    vetorCartasAzul[2].numFace = 3;
    vetorCartasAzul[3].numFace = 4;
    vetorCartasAzul[4].numFace = 5;
    vetorCartasAzul[5].numFace = 6;
    vetorCartasAzul[6].numFace = 7;
    vetorCartasAzul[7].numFace = 8;
    vetorCartasAzul[8].numFace = 9;
    ///////////////////////////////
    vetorCartasAzul[12].numFace = 1;
    vetorCartasAzul[13].numFace = 2;
    vetorCartasAzul[14].numFace = 3;
    vetorCartasAzul[15].numFace = 4;
    vetorCartasAzul[16].numFace = 5;
    vetorCartasAzul[17].numFace = 6;
    vetorCartasAzul[18].numFace = 7;
    vetorCartasAzul[19].numFace = 8;
    vetorCartasAzul[20].numFace = 9;

    /* Cartas Amarelas */

    /* Cartas Amarelo*/
    //Cor da Carta
    vetorCartasAmarelo[0].CorCarta = AMARELO;
    vetorCartasAmarelo[1].CorCarta = AMARELO;
    vetorCartasAmarelo[2].CorCarta = AMARELO;
    vetorCartasAmarelo[3].CorCarta = AMARELO;
    vetorCartasAmarelo[4].CorCarta = AMARELO;
    vetorCartasAmarelo[5].CorCarta = AMARELO;
    vetorCartasAmarelo[6].CorCarta = AMARELO;
    vetorCartasAmarelo[7].CorCarta = AMARELO;
    vetorCartasAmarelo[8].CorCarta = AMARELO;
    vetorCartasAmarelo[9].CorCarta = AMARELO;
    vetorCartasAmarelo[10].CorCarta = AMARELO;
    vetorCartasAmarelo[11].CorCarta = AMARELO;
    /////////////////////////////////////////
    vetorCartasAmarelo[12].CorCarta = AMARELO;
    vetorCartasAmarelo[13].CorCarta = AMARELO;
    vetorCartasAmarelo[14].CorCarta = AMARELO;
    vetorCartasAmarelo[15].CorCarta = AMARELO;
    vetorCartasAmarelo[16].CorCarta = AMARELO;
    vetorCartasAmarelo[17].CorCarta = AMARELO;
    vetorCartasAmarelo[18].CorCarta = AMARELO;
    vetorCartasAmarelo[19].CorCarta = AMARELO;
    vetorCartasAmarelo[20].CorCarta = AMARELO;
    vetorCartasAmarelo[21].CorCarta = AMARELO;
    vetorCartasAmarelo[22].CorCarta = AMARELO;
    vetorCartasAmarelo[23].CorCarta = AMARELO;

    // Tipo da Carta
    vetorCartasAmarelo[0].TipoCarta = NORMAL;
    vetorCartasAmarelo[1].TipoCarta = NORMAL;
    vetorCartasAmarelo[2].TipoCarta = NORMAL;
    vetorCartasAmarelo[3].TipoCarta = NORMAL;
    vetorCartasAmarelo[4].TipoCarta = NORMAL;
    vetorCartasAmarelo[5].TipoCarta = NORMAL;
    vetorCartasAmarelo[6].TipoCarta = NORMAL;
    vetorCartasAmarelo[7].TipoCarta = NORMAL;
    vetorCartasAmarelo[8].TipoCarta = NORMAL;
    vetorCartasAmarelo[9].TipoCarta = ACAO;
    vetorCartasAmarelo[10].TipoCarta = ACAO;
    vetorCartasAmarelo[11].TipoCarta = ACAO;
    //////////////////////
    vetorCartasAmarelo[12].TipoCarta = NORMAL;
    vetorCartasAmarelo[13].TipoCarta = NORMAL;
    vetorCartasAmarelo[14].TipoCarta = NORMAL;
    vetorCartasAmarelo[15].TipoCarta = NORMAL;
    vetorCartasAmarelo[16].TipoCarta = NORMAL;
    vetorCartasAmarelo[17].TipoCarta = NORMAL;
    vetorCartasAmarelo[18].TipoCarta = NORMAL;
    vetorCartasAmarelo[19].TipoCarta = NORMAL;
    vetorCartasAmarelo[20].TipoCarta = NORMAL;
    vetorCartasAmarelo[21].TipoCarta = ACAO;
    vetorCartasAmarelo[22].TipoCarta = ACAO;
    vetorCartasAmarelo[23].TipoCarta = ACAO;
    // A��o da Carta
    vetorCartasAmarelo[0].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[1].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[2].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[3].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[4].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[5].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[6].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[7].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[8].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[9].AcaoCarta = PULAR;
    vetorCartasAmarelo[10].AcaoCarta = REVERTER;
    vetorCartasAmarelo[11].AcaoCarta = COMPRAR_DUAS;
    //////////////////////
    vetorCartasAmarelo[12].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[13].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[14].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[15].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[16].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[17].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[18].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[19].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[20].AcaoCarta = NORMAL_NOACTION;
    vetorCartasAmarelo[21].AcaoCarta = PULAR;
    vetorCartasAmarelo[22].AcaoCarta = REVERTER;
    vetorCartasAmarelo[23].AcaoCarta = COMPRAR_DUAS;
    //N�mero da Carta
    vetorCartasAmarelo[0].numFace = 1;
    vetorCartasAmarelo[1].numFace = 2;
    vetorCartasAmarelo[2].numFace = 3;
    vetorCartasAmarelo[3].numFace = 4;
    vetorCartasAmarelo[4].numFace = 5;
    vetorCartasAmarelo[5].numFace = 6;
    vetorCartasAmarelo[6].numFace = 7;
    vetorCartasAmarelo[7].numFace = 8;
    vetorCartasAmarelo[8].numFace = 9;
    ///////////////////////////////
    vetorCartasAmarelo[12].numFace = 1;
    vetorCartasAmarelo[13].numFace = 2;
    vetorCartasAmarelo[14].numFace = 3;
    vetorCartasAmarelo[15].numFace = 4;
    vetorCartasAmarelo[16].numFace = 5;
    vetorCartasAmarelo[17].numFace = 6;
    vetorCartasAmarelo[18].numFace = 7;
    vetorCartasAmarelo[19].numFace = 8;
    vetorCartasAmarelo[20].numFace = 9;

    /* Cartas Coringa */
    //Guarda cartas Coringa
    //Cor da Carta
    vetorDeCartasCoringa[0].CorCarta = PRETO;
    vetorDeCartasCoringa[1].CorCarta = PRETO;
    vetorDeCartasCoringa[2].CorCarta = PRETO;
    vetorDeCartasCoringa[3].CorCarta = PRETO;
    vetorDeCartasCoringa[4].CorCarta = PRETO;
    vetorDeCartasCoringa[5].CorCarta = PRETO;
    vetorDeCartasCoringa[6].CorCarta = PRETO;
    vetorDeCartasCoringa[7].CorCarta = PRETO;
    // Tipo da Carta
    vetorDeCartasCoringa[0].TipoCarta = CORINGA;
    vetorDeCartasCoringa[1].TipoCarta = CORINGA;
    vetorDeCartasCoringa[2].TipoCarta = CORINGA;
    vetorDeCartasCoringa[3].TipoCarta = CORINGA;
    vetorDeCartasCoringa[4].TipoCarta = CORINGA;
    vetorDeCartasCoringa[5].TipoCarta = CORINGA;
    vetorDeCartasCoringa[6].TipoCarta = CORINGA;
    vetorDeCartasCoringa[7].TipoCarta = CORINGA;
    // A��o da Carta
    vetorDeCartasCoringa[0].AcaoCarta = CORINGA_NOACTION;
    vetorDeCartasCoringa[1].AcaoCarta = CORINGA_NOACTION;
    vetorDeCartasCoringa[2].AcaoCarta = CORINGA_NOACTION;
    vetorDeCartasCoringa[3].AcaoCarta = CORINGA_NOACTION;
    vetorDeCartasCoringa[4].AcaoCarta = CORINGA_COMPRAR_4;
    vetorDeCartasCoringa[5].AcaoCarta = CORINGA_COMPRAR_4;
    vetorDeCartasCoringa[6].AcaoCarta = CORINGA_COMPRAR_4;
    vetorDeCartasCoringa[7].AcaoCarta = CORINGA_COMPRAR_4;

    /* Cartas de Zero */

    //Cor da Carta
    vetorDeCartasZero[0].CorCarta = AZUL;
    vetorDeCartasZero[1].CorCarta = VERMELHO;
    vetorDeCartasZero[2].CorCarta = VERDE;
    vetorDeCartasZero[3].CorCarta = AMARELO;
    // Tipo da Carta
    vetorDeCartasZero[0].TipoCarta = NORMAL;
    vetorDeCartasZero[1].TipoCarta = NORMAL;
    vetorDeCartasZero[2].TipoCarta = NORMAL;
    vetorDeCartasZero[3].TipoCarta = NORMAL;
    // A��o da Carta
    vetorDeCartasZero[0].AcaoCarta = NORMAL_NOACTION;
    vetorDeCartasZero[1].AcaoCarta = NORMAL_NOACTION;
    vetorDeCartasZero[2].AcaoCarta = NORMAL_NOACTION;
    vetorDeCartasZero[3].AcaoCarta = NORMAL_NOACTION;
    //N�mero da Carta
    vetorDeCartasZero[0].numFace = 0;
    vetorDeCartasZero[1].numFace = 0;
    vetorDeCartasZero[2].numFace = 0;
    vetorDeCartasZero[3].numFace = 0;

    /* Cartas Vermelhas*/

    //Cor da Carta
    vetorCartasVermelho[0].CorCarta = VERMELHO;
    vetorCartasVermelho[1].CorCarta = VERMELHO;
    vetorCartasVermelho[2].CorCarta = VERMELHO;
    vetorCartasVermelho[3].CorCarta = VERMELHO;
    vetorCartasVermelho[4].CorCarta = VERMELHO;
    vetorCartasVermelho[5].CorCarta = VERMELHO;
    vetorCartasVermelho[6].CorCarta = VERMELHO;
    vetorCartasVermelho[7].CorCarta = VERMELHO;
    vetorCartasVermelho[8].CorCarta = VERMELHO;
    vetorCartasVermelho[9].CorCarta = VERMELHO;
    vetorCartasVermelho[10].CorCarta = VERMELHO;
    vetorCartasVermelho[11].CorCarta = VERMELHO;
    vetorCartasVermelho[12].CorCarta = VERMELHO;
    vetorCartasVermelho[13].CorCarta = VERMELHO;
    vetorCartasVermelho[14].CorCarta = VERMELHO;
    vetorCartasVermelho[15].CorCarta = VERMELHO;
    vetorCartasVermelho[16].CorCarta = VERMELHO;
    vetorCartasVermelho[17].CorCarta = VERMELHO;
    vetorCartasVermelho[18].CorCarta = VERMELHO;
    vetorCartasVermelho[19].CorCarta = VERMELHO;
    vetorCartasVermelho[20].CorCarta = VERMELHO;
    vetorCartasVermelho[21].CorCarta = VERMELHO;
    vetorCartasVermelho[22].CorCarta = VERMELHO;
    vetorCartasVermelho[23].CorCarta = VERMELHO;
    // Tipo da Carta
    vetorCartasVermelho[0].TipoCarta = NORMAL;
    vetorCartasVermelho[1].TipoCarta = NORMAL;
    vetorCartasVermelho[2].TipoCarta = NORMAL;
    vetorCartasVermelho[3].TipoCarta = NORMAL;
    vetorCartasVermelho[4].TipoCarta = NORMAL;
    vetorCartasVermelho[5].TipoCarta = NORMAL;
    vetorCartasVermelho[6].TipoCarta = NORMAL;
    vetorCartasVermelho[7].TipoCarta = NORMAL;
    vetorCartasVermelho[8].TipoCarta = NORMAL;
    vetorCartasVermelho[9].TipoCarta = ACAO;
    vetorCartasVermelho[10].TipoCarta = ACAO;
    vetorCartasVermelho[11].TipoCarta = ACAO;
    vetorCartasVermelho[12].TipoCarta = NORMAL;
    vetorCartasVermelho[13].TipoCarta = NORMAL;
    vetorCartasVermelho[14].TipoCarta = NORMAL;
    vetorCartasVermelho[15].TipoCarta = NORMAL;
    vetorCartasVermelho[16].TipoCarta = NORMAL;
    vetorCartasVermelho[17].TipoCarta = NORMAL;
    vetorCartasVermelho[18].TipoCarta = NORMAL;
    vetorCartasVermelho[19].TipoCarta = NORMAL;
    vetorCartasVermelho[20].TipoCarta = NORMAL;
    vetorCartasVermelho[21].TipoCarta = ACAO;
    vetorCartasVermelho[22].TipoCarta = ACAO;
    vetorCartasVermelho[23].TipoCarta = ACAO;

    // A��o da Carta
    vetorCartasVermelho[0].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[1].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[2].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[3].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[4].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[5].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[6].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[7].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[8].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[9].AcaoCarta = PULAR;
    vetorCartasVermelho[10].AcaoCarta = REVERTER;
    vetorCartasVermelho[11].AcaoCarta = COMPRAR_DUAS;
    /////////////////////////////////////////////////
    vetorCartasVermelho[12].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[13].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[14].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[15].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[16].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[17].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[18].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[19].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[20].AcaoCarta = NORMAL_NOACTION;
    vetorCartasVermelho[21].AcaoCarta = PULAR;
    vetorCartasVermelho[22].AcaoCarta = REVERTER;
    vetorCartasVermelho[23].AcaoCarta = COMPRAR_DUAS;
    //N�mero da Carta
    vetorCartasVermelho[0].numFace = 1;
    vetorCartasVermelho[1].numFace = 2;
    vetorCartasVermelho[2].numFace = 3;
    vetorCartasVermelho[3].numFace = 4;
    vetorCartasVermelho[4].numFace = 5;
    vetorCartasVermelho[5].numFace = 6;
    vetorCartasVermelho[6].numFace = 7;
    vetorCartasVermelho[7].numFace = 8;
    vetorCartasVermelho[8].numFace = 9;
    //////////////////////////////////////
    vetorCartasVermelho[12].numFace = 1;
    vetorCartasVermelho[13].numFace = 2;
    vetorCartasVermelho[14].numFace = 3;
    vetorCartasVermelho[15].numFace = 4;
    vetorCartasVermelho[16].numFace = 5;
    vetorCartasVermelho[17].numFace = 6;
    vetorCartasVermelho[18].numFace = 7;
    vetorCartasVermelho[19].numFace = 8;
    vetorCartasVermelho[20].numFace = 9;
}

/* SIMULADOR DE JOGOS DE CARTAS UNO - Desenvolvido por Pedro Harmendani - 2018 */

//Bibliotecas
#include "menu_Lib.c"

int main(){	

	
startScreen();

executarMotorCarta();

//lst_Imprime(G_l);

inicializaJogadores();

printf("\nJogador: %s -- IA : %d -- Vitórias: %d -- Vez de Jogar: %d \n",j1.nome, j1.id, j1.vitorias, j1.bool_statusJogador);
printf("Jogador: %s -- IA : %d -- Vitórias: %d -- Vez de Jogar: %d \n",j2.nome, j2.id, j2.vitorias, j2.bool_statusJogador);
	
/**executarMotorCarta();

lst_Imprime(G_l);

inicializaJogadores();

distribuiCartasInicio();
puts("\n\n Cartas Jogador 1");

//carta tempx = lst_ObterCarta(G_l);

lst_Imprime(j1.listaMaos);
puts("\n\n Cartas Jogador 2");
lst_Imprime(j2.listaMaos);

puts("\nExecuta rotina conta cartas por tipo");

contadorDeCartasPorTipo(&j1);
contadorDeCartasPorTipo(&j2);

puts("\nImprime cartas Acao");
lst_Imprime(j1.cartasAcao);
puts("\nImprime cartas Normal");
lst_Imprime(j1.cartasNormal);
puts("\nImprime cartas Coringa");
lst_Imprime(j1.cartasCoringa);

puts("\nExecuta rotina conta cartas por tipo JOGADOR 2:");

contadorDeCartasPorTipo(&j2);
puts("\nImprime cartas Acao");
lst_Imprime(j2.cartasAcao);
puts("\nImprime cartas Normal");
lst_Imprime(j2.cartasNormal);
puts("\nImprime cartas Coringa");
lst_Imprime(j2.cartasCoringa);

int contNormal, contAcao, contCoringa;
contNormal = contAcao = contCoringa = 0;

puts("\n -- JOGADOR 1 -- ");
contNormal = contadorDeCartas(j1.cartasNormal);
contAcao = contadorDeCartas(j1.cartasAcao);
contCoringa = contadorDeCartas(j1.cartasCoringa);
puts("\nImprime cartas Acao");
lst_Imprime(j1.cartasAcao);
puts("\nImprime cartas Normal");
lst_Imprime(j1.cartasNormal);
puts("\nImprime cartas Coringa");
lst_Imprime(j1.cartasCoringa);

printf("\nQTD cartas Acao %d", contAcao);
printf("\nQTD cartas Normal %d", contNormal);
printf("\nQTD cartas Coringa %d", contCoringa);

puts("\n -- JOGADOR 2 -- ");
contNormal = contAcao = contCoringa = 0;
contNormal = contadorDeCartas(j2.cartasNormal);
contAcao = contadorDeCartas(j2.cartasAcao);
contCoringa = contadorDeCartas(j2.cartasCoringa);
puts("\nImprime cartas Acao");
lst_Imprime(j2.cartasAcao);
puts("\nImprime cartas Normal");
lst_Imprime(j2.cartasNormal);
puts("\nImprime cartas Coringa");
lst_Imprime(j2.cartasCoringa);

printf("\nQTD cartas Acao %d", contAcao);
printf("\nQTD cartas Normal %d", contNormal);
printf("\nQTD cartas Coringa %d", contCoringa);

lst_Imprime(G_l);*/
return EXIT_SUCCESS;
}


/* SIMULADOR DE JOGOS DE CARTAS UNO - Desenvolvido por Pedro Harmendani - 2018 */

//Bibliotecas
#include "menu_Lib.c"

int main(){	

	
startScreen();
	
executarMotorCarta();

//lst_Imprime(G_l);

inicializaJogadores();

distribuiCartasInicio();
puts("\n\n Cartas Jogador 1");

lst_Imprime(j1.listaMaos);

puts("\n\n Cartas Jogador 2");
//lst_Imprime(j2.listaMaos);

int numCartas = contadorDeCartas(G_l);
int jp = numCartas;
for(int i = 0; i < jp; i++){
	
/*	printf("Tamanho da Lista %d", numCartas);
	numCartas = contadorDeCartas(G_l);*/
	G_l = lst_Remove(G_l);
	
	
}
//j1.listaMaos = lst_Remove(j1.listaMaos);


	numCartas = contadorDeCartas(G_l);
	printf("Tamanho da Lista %d", numCartas);
	
	
	executarMotorCarta();
	
	//lst_Imprime(G_l);
	
	
	puts("\nTamanho da Lista apos executarRotina\n");
	
		numCartas = contadorDeCartas(G_l);
	printf("Tamanho da Lista %d", numCartas);
	
	int a = contadorDeCartas(j1.listaMaos);
	int b = contadorDeCartas(j2.listaMaos);
	printf("Quantidade cartas do jogador 1: %d ", a);
	printf("Quantidade cartas do jogador 2: %d", b);
endProgram();

return 0;
}


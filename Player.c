

void inicializaJogadores()
{

	j1.id = NO_AR;
	j2.id = AR;

	j1.nome = MACHINE;
	j2.nome = SPOCK;

	j1.listaMaos = lst_cria(); // Inicializa m�os do jogador 1 com o valor NULL
	j2.listaMaos = lst_cria(); // Inicializa m�os do jogador 2 com o valor NULL
}

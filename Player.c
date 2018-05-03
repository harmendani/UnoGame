

void inicializaJogadores()
{
	j1.id = NO_AR;
	j2.id = AR;

	j1.nome = MACHINE;
	j2.nome = SPOCK;

	j1.bool_statusJogador = false;
	j2.bool_statusJogador = false;
	j1.vitorias = 0;
	j2.vitorias = 0;
	j1.listaMaos = lst_cria(); // Inicializa m�os do jogador 1 com o valor NULL
	j2.listaMaos = lst_cria(); // Inicializa m�os do jogador 2 com o valor NULL

	/*j1.visaoPlayer = (vision)NULL;
	j2.visaoPlayer = NULL;

	j1.cartaNaMesa = NULL;
	j2.cartaNaMesa = NULL;*/

	j1.numDeCartasAcao = 0;
	j1.numDeCartasCoringa = 0;
	j1.numDeCartasNormal = 0;

	j2.numDeCartasAcao = 0;
	j2.numDeCartasCoringa = 0;
	j2.numDeCartasNormal = 0;

	j1.cartasNormal = lst_cria();
	j1.cartasAcao = lst_cria();
	j1.cartasCoringa = lst_cria();

	j2.cartasNormal = lst_cria();
	j2.cartasAcao = lst_cria();
	j2.cartasCoringa = lst_cria();
}

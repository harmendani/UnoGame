

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

	j1.rodadas = 0;
	j2.rodadas = 0;
    
    lst_FreeList(j1.listaMaos);
	lst_FreeList(j2.listaMaos);
	j1.listaMaos = lst_cria(); // Inicializa m?os do jogador 1 com o valor NULL
	j2.listaMaos = lst_cria(); // Inicializa m?os do jogador 2 com o valor NULL

	j1.numDeCartasAcao = 0;
	j1.numDeCartasCoringa = 0;
	j1.numDeCartasNormal = 0;

	j2.numDeCartasAcao = 0;
	j2.numDeCartasCoringa = 0;
	j2.numDeCartasNormal = 0;

	lst_FreeList(j1.cartasNormal);
	lst_FreeList(j1.cartasAcao);
	lst_FreeList(j1.cartasCoringa);

	j1.cartasNormal = lst_cria();
	j1.cartasAcao = lst_cria();
	j1.cartasCoringa = lst_cria();

	lst_FreeList(j2.cartasNormal);
	lst_FreeList(j2.cartasAcao);
	lst_FreeList(j2.cartasCoringa);

	j2.cartasNormal = lst_cria();
	j2.cartasAcao = lst_cria();
	j2.cartasCoringa = lst_cria();

	j1.adversario = &j2;
	j2.adversario = &j1;
}

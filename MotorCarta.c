/* Implementa a interface "MotorCarta.h" com algumas funções
que manipulam as cartas durante as partidas*/

void alocadorDeCartasMemoria()
{
	/*Limpa da memória e inicializa montante e pilha*/
	lst_FreeList(G_l);
	lst_FreeList(M_l);
	M_l = lst_cria();
	G_l = lst_cria();

	for (int i = 0; i < 24; i++)
	{
		G_l = lst_Insere(G_l, vetorCartasAzul[i]);
	}
	for (int i = 0; i < 24; i++)
	{
		G_l = lst_Insere(G_l, vetorCartasVermelho[i]);
	}
	for (int i = 0; i < 24; i++)
	{
		G_l = lst_Insere(G_l, vetorCartasAmarelo[i]);
	}

	for (int i = 0; i < 24; i++)
	{
		G_l = lst_Insere(G_l, vetorCartasVerde[i]);
	}
	for (int i = 0; i < 8; i++)
	{
		G_l = lst_Insere(G_l, vetorDeCartasCoringa[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		G_l = lst_Insere(G_l, vetorDeCartasZero[i]);
	}
}

void distribuiCartasInicio()
{
	int n = 7;
	int m = 7;
	while (n > 0)
	{
		carta temp1 = lst_ObterCarta(G_l);
		if (n == 7)
			printf("\nCarta retirad - id: %d \n", temp1.id);
		j1.listaMaos = lst_Insere(j1.listaMaos, temp1);
		if (n > 0)
			G_l = lst_Remove(G_l);
		n--;
	}

	while (m > 0)
	{
		carta temp2 = lst_ObterCarta(G_l);
		j2.listaMaos = lst_Insere(j2.listaMaos, temp2);
		if (m > 0)
			G_l = lst_Remove(G_l);
		m--;
	}
}

void embaralhadorDeCartas()
{

	InsertionSortRandom(QTD_CARTAS_TOTAL, G_l);
}

int contadorDeCartas(Lista *lista)
{
	int numCartas = 0;
	Lista *proxima;
	proxima = lista;
	if (proxima == NULL)
	{
		return 0;
	}
	else
	{
		while (proxima != NULL)
		{
			numCartas++;
			proxima = proxima->prox;
		}
	}
	return numCartas;
}

int contadorDeCartasCuringa_4(Lista *lista)
{
	int numCartas = 0;
	Lista *proxima;
	proxima = lista;
	if (proxima == NULL)
	{
		return 0;
	}
	else
	{
		while (proxima != NULL)
		{
			carta* c = lst_ObterCartaRef(proxima);
			if (c->AcaoCarta == CORINGA_COMPRAR_4){
				numCartas++;
			}
				proxima = proxima->prox;
		}
	}
	return numCartas;
}

void contadorDeCartasPorTipo(player *j)
{
	int contNormal = 0;
	int contAcao = 0;
	int contCoringa = 0;
	/* Sempre zera e libera a lista por tipo de carta para assegurar a integridade */
	lst_FreeList(j->cartasNormal);
	lst_FreeList(j->cartasAcao);
	lst_FreeList(j->cartasCoringa);
	j->cartasNormal = lst_cria();
	j->cartasAcao = lst_cria();
	j->cartasCoringa = lst_cria();

	Lista *l = NULL; // Auxilia para varrer a lista de cartas do jogador.

	/* Conta cartas do tipo Normal */
	l = j->listaMaos;

	while (l != NULL)
	{
		if (l->Carta.TipoCarta == NORMAL)
		{
			contNormal++;
			carta temp1 = lst_ObterCarta(l);
			j->cartasNormal = lst_Insere(j->cartasNormal, temp1);
		}
		l = l->prox;
	}
	l = NULL;
	/* Conta cartas do tipo Ação */
	l = j->listaMaos;
	while (l != NULL)
	{
		if (l->Carta.TipoCarta == ACAO)
		{
			contAcao++;
			carta temp2 = lst_ObterCarta(l);
			j->cartasAcao = lst_Insere(j->cartasAcao, temp2);
		}
		l = l->prox;
	}
	l = NULL;
	/* Conta cartas do tipo Coringa */
	l = j->listaMaos;
	while (l != NULL)
	{
		if (l->Carta.TipoCarta == CORINGA)
		{
			contCoringa++;
			carta temp3 = lst_ObterCarta(l);
			j->cartasCoringa = lst_Insere(j->cartasCoringa, temp3);
		}
		l = l->prox;
	}
	j->numDeCartasNormal = contNormal;
	j->numDeCartasAcao = contAcao;
	j->numDeCartasCoringa = contCoringa;
}

void controlarCartasNoMontante()
{
	if (lst_IsEmpty(G_l))
	{
		G_l = M_l;
		M_l = lst_cria(); // Pilha da mesa recebe NULL.
	}
}

void preparaRandomAzul()
{
	for (int i = 0; i < 24; i++)
	{
		vetorCartasAzul[i].id = randomInteger();
		// printf("\nCarta id: %d", vetorCartasAzul[i].CorCarta);
	}
}

void preparaRandomVermelho()
{
	for (int i = 0; i < 24; i++)
	{
		vetorCartasVermelho[i].id = randomInteger();
		// printf("\nCarta id: %d", vetorCartasVermelho[i].id);
	}
}

void preparaRandomAmarelo()
{
	for (int i = 0; i < 24; i++)
	{
		vetorCartasAmarelo[i].id = randomInteger();
		// printf("\nCarta id: %d", vetorCartasAmarelo[i].id);
	}
}

void preparaRandomVerde()
{
	for (int i = 0; i < 24; i++)
	{
		vetorCartasVerde[i].id = randomInteger();
		// printf("\nCarta id Verde: %d", vetorCartasVerde[i].CorCarta);
	}
}

void preparaRandomZero()
{
	for (int i = 0; i < 4; i++)
	{
		vetorDeCartasZero[i].id = randomInteger();
		// printf("\nCarta id: %d", vetorDeCartasZero[i].id);
	}
}

void preparaRandomCoringa()
{
	for (int i = 0; i < 8; i++)
	{
		vetorDeCartasCoringa[i].id = randomInteger();
		// printf("\nCarta id: %d", vetorDeCartasCoringa[i].id);
	}
}

void rotinaPreparaRandom()
{
	srand(time(NULL));
	preparaRandomAzul();
	preparaRandomVermelho();
	preparaRandomAmarelo();
	preparaRandomVerde();
	preparaRandomZero();
	preparaRandomCoringa();
}

void executarMotorCarta()
{
	inicializa_Cartas();
	rotinaPreparaRandom();
	alocadorDeCartasMemoria();
	embaralhadorDeCartas();
	distribuiCartasInicio();
}

/* Implementa a interface "MotorCarta.h" com algumas funçees
que manipulam as cartas durante as partidas*/

void alocadorDeCartasMemoria()
{

  G_l = lst_cria(); // Cria apontador pra lista de cartas atraves da variavel global no jogo.

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
    j1.listaMaos = lst_Insere(j1.listaMaos, temp1);
    G_l = lst_Remove(G_l);
    n--;
  }

  while (m > 0)
  {
    carta temp2 = lst_ObterCarta(G_l);
    j2.listaMaos = lst_Insere(j2.listaMaos, temp2);
    G_l = lst_Remove(G_l);
    m--;
  }
}

void embaralhadorDeCartas()
{

  InsertionSortRandom(QTD_CARTAS_TOTAL, G_l);
}

int contadorDeCartas(Lista* lista)
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
}

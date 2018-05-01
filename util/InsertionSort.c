/* 
** Programa ordena um vetor de Inteiros [1...n] com o algoritmo Insertion Sort. 
** Complexidade temporal-- O(n^2) -- worst case.
*/

void InsertionSortRandom(int n, Lista *vet)
{

    Lista *p = vet;
    int i, chave;
    int cont = 0;

    carta vetCarta[108];
    while (p != NULL)
    {

        vetCarta[cont] = p->Carta;
        p = p->prox;
        cont++;
    }
    for (int j = 1; j < n; j++)
    {
        chave = vetCarta[j].id;
        i = j - 1;
        while (i >= 0 && vetCarta[i].id > chave)
        {
            carta swap = vetCarta[i + 1];
            vetCarta[i + 1] = vetCarta[i];
            vetCarta[i] = swap;
            i = i - 1;
        }
        vetCarta[i + 1].id = chave;
    }

    Lista *nova;
    nova = lst_cria();
    G_l = nova;
    for (int j = 0; j < 108; j++)
    {
    	vetCarta[j].id = j;
        G_l = lst_Insere(G_l, vetCarta[j]);
        
    }
}

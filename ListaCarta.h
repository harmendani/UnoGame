/////////////////////////////////////////////
//TAD - List Linked - Tipo: carta ////////////
/////////////////////////////////////////////

// Bibliotecas
#ifndef LISTACARTA_C
#define LISTACARTA_C
#include "ListaCarta.c"
#endif

/*
** Fun��es disponibilidades por essa biblioteca
*/



/* Retorna uma lista vazia */
Lista* lst_cria();

/* Insere no inicio da Lista */
Lista* lst_Insere(Lista*, carta);

/* Verifica se Lista está Vazia */
int lst_IsEmpty(Lista*);

/* Remove primeiro Elemento da Lista - topo */
Lista* lst_Remove(Lista*);

/* Imprime elementos da Lista */
void lst_Imprime(Lista*);

/* Imprime elementos em ordem inversa usando Recursividade */
void lst_Imprime_Rec(Lista*);

/* Libera a lista de memória */
void lst_FreeList(Lista*);

/* Obtem carta do topo da lista */
carta lst_ObterCarta(Lista*);

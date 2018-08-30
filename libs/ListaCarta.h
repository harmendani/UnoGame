/////////////////////////////////////////////
//TAD - List Linked - Tipo: carta ////////////
/////////////////////////////////////////////

// Bibliotecas
#ifndef LISTACARTA_C
#define LISTACARTA_C
#include "../ListaCarta.c"
#endif

/*
** Fun??es disponibilidades por essa biblioteca
*/

/* Retorna uma lista vazia */
Lista* lst_cria();

/* Insere no inicio da Lista */
Lista* lst_Insere(Lista*, carta);

/* Verifica se Lista est� Vazia */
int lst_IsEmpty(Lista*);

/* Remove primeiro Elemento da Lista - topo */
Lista* lst_Remove(Lista*);

/* Imprime elementos da Lista */
void lst_Imprime(Lista*);

/* Imprime elementos em ordem inversa usando Recursividade */
void lst_Imprime_Rec(Lista*);

/* Libera a lista de mem�ria */
void lst_FreeList(Lista*);

/* Obtem carta do topo da lista */
carta lst_ObterCarta(Lista*);

/* Obtém referência da carta do topo de uma lista */
carta *lst_ObterCartaRef(Lista *lst);

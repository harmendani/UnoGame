/////////////////////////////////////////////
//TAD - List Linked - Tipo: carta ////////////
/////////////////////////////////////////////

// Bibliotecas
#include "ListaCarta.c"

/*
** Fun��es disponibilidades por essa biblioteca
*/

/* Retorna uma lista vazia */
Lista* lst_cria();

/* Insere no inicio da Lista */
Lista* lst_Insere(Lista* l, carta c );

/* Verifica se Lista está Vazia */
int lst_IsEmpty(Lista* l);

/* Remove primeiro Elemento da Lista - topo */
Lista* lst_Remove(Lista* l);

/* Imprime elementos da Lista */
void lst_Imprime(Lista* l);

/* Imprime elementos em ordem inversa usando Recursividade */
void lst_Imprime_Rec(Lista *l);

/* Libera a lista de memória */
void lst_FreeList(Lista* l);

/* Obtem carta do topo da lista */
carta obter_Carta(Lista* lst);


// Bibliotecas
#ifndef CARTAS_H
#define CARTAS_H
#include "Cartas.h"
#endif

// Estruturas
// Tipos
typedef struct ListaCarta Lista;

struct ListaCarta
{
    carta Carta;
    Lista *prox;
};

// Operações

/* Retorna uma lista vazia */
Lista *lst_cria()
{
    return NULL;
}

/* Insere no inicio da Lista */
Lista *lst_Insere(Lista *atual, carta c)
{

    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->Carta = c;
    novo->prox = atual;
    return novo;
}
/* Verifica se Lista está Vazia */
int lst_IsEmpty(Lista *l)
{

    return (l == NULL);
}

/* Remove primeiro Elemento da Lista - topo */
Lista *lst_Remove(Lista *atual)
{
	if(atual == NULL) return NULL;
    Lista *topo;
    topo = atual->prox;
    printf("\n Removida id: %d", atual->Carta.id);
    free(atual);
    atual = NULL; // Garante que o valor ? NULL

    return topo;
}
/* Imprime elementos da Lista */
void lst_Imprime(Lista *l)
{
    printf("\n Lista de Cartas:\n");
    int i = 1;
    Lista *p = l;
    while (p != NULL)
    {
        printf("\nPos: %d, Id: %d - Cor: %d - Tipo: %d - Acao: %d - NumFace: %d",
               i,
               p->Carta.id,
               p->Carta.CorCarta,
               p->Carta.TipoCarta,
               p->Carta.AcaoCarta,
               p->Carta.numFace);
        p = p->prox;
        i++;
    }
    printf("\n");
}
/* Libera a lista de meméria */
void lst_FreeList(Lista *l)
{
    Lista *p = l;
    while (p != NULL)
    {
        Lista *ant = p->prox;
        free(p);
        p = ant;
    }
}
/* Imprime de trás pra frente usando Recursividade */
void lst_Imprime_Rec(Lista *l)
{
    if (!lst_IsEmpty(l))
    {
        printf("\n");

        lst_Imprime_Rec(l->prox);
        printf("\nID da Carta: %d", l->Carta.TipoCarta);
    }
}

/* Obtém carta do topo de uma lista */
carta lst_ObterCarta(Lista *lst)
{

    carta c_temp = lst->Carta;
    return c_temp;
}

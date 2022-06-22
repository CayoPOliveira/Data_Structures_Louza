#include <stdio.h>
#include <stdlib.h>
#include "PilhaTAD.h"

// Funçes
Pilha *criar_pilha()
{
    Pilha *P = (Pilha *)malloc(sizeof(Pilha));
    P->N = 0;
    P->L = criar_lista();
    return P;
}
void destruir_pilha(Pilha **P)
{
    if (*P == NULL)
        return;
    destruir_lista(&((*P)->L));
    free(*P);
    *P = NULL;
}

// Adicionar
void push_pilha(Pilha *P, int x)
{
    P->N++;
    adicionar_inicio(&(P->L), x);
}

// Remover
void pop_pilha(Pilha *P)
{
    int top = primeiro_elemento(P->L);
    remover_inicio(&(P->L));
    if (top != primeiro_elemento(P->L))
        P->N--;
}

// Topo
int top_pilha(Pilha *P)
{
    return primeiro_elemento(P->L);
}

// Tamanho
int size_pilha(Pilha *P)
{
    return P->N;
}

int empty_pilha(Pilha *P)
{
    if (P->N == 0)
        return 1;
    return 0;
}
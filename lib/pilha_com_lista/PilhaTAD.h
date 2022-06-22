#ifndef PILHA_H
#define PILHA_H

#include "lib/lista_ligada/lista_ligada.h"

typedef struct
{
    int N;
    No *L;
} Pilha;

// Funçes
Pilha *criar_pilha();
void destruir_pilha(Pilha **P);

// Adicionar
void push_pilha(Pilha *P, int x);

// Remover
void pop_pilha(Pilha *P);

// Topo
int top_pilha(Pilha *P);

// Tamanho
int size_pilha(Pilha *P);

// Vazio
int empty_pilha(Pilha *P);

#endif
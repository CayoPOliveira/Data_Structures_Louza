#include <stdio.h>
#include <stdlib.h>
#include "FilaTAD.h"

// Funções
Fila *fila_criar()
{
    Fila *F = (Fila *)malloc(sizeof(Fila));
    F->N = 0;
    F->L = criar_lista(); // Lista feita a partir do outro TAD
    return F;
}
void fila_destruir(Fila **F)
{
    if (*F == NULL) // Fila não foi criada
        return;
    destruir_lista(&((*F)->L)); // Lista destruida a partir do TAD
    free(*F);
    *F = NULL;
}
// Adicionar
void fila_adicionar(Fila *F, int x)
{
    F->N++;                      // incrementa o numero de elementos na fila
    adicionar_final(&(F->L), x); // Adição sempre no final a partir da TAD
}

// Acessar
int fila_front(Fila *F)
{
    return retorna_inicio(F->L); // retorna o valor pela própria tad de lista
}

// Remover
int fila_remover(Fila *F)
{
    int x = remover_inicio(&(F->L)); // remove sempre do inicio a partir da tad
    if (x != -1)                     // se tiver removido realmente um elemento o numero será diferente de -1 e poderei reduzir a valor de N
        F->N--;
    return x;
}

// Extra
int fila_tamanho(Fila *F)
{
    return F->N; // Tamanho
}
int fila_empty(Fila *F)
{
    if (F->N == 0) // Lista vazia, return True
        return 1;
    return 0;
}

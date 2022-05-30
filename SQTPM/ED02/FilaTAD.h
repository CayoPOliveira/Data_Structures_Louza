#ifndef FILA_H
#define FILA_H

#include "LLCircularTAD.h"

// Dados
typedef struct
{
    int N;
    No *L;
} Fila;

// Funções
Fila *fila_criar();           // cria a fila
void fila_destruir(Fila **F); // destruir a fila totalmente

// Adicionar
void fila_adicionar(Fila *F, int x); // adicionar elementos

// Acessar
int fila_front(Fila *F); // retorna o dado no inicio da fila apenas

// Remover
int fila_remover(Fila *F); // retorna o dado removido

// Extra
int fila_tamanho(Fila *F); // retorna o tamanho da fila
int fila_empty(Fila *F);   // retorna 1 se a fila tiver vazia e retorna 0 caso contrário

#endif
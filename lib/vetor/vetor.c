#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

// Funções
vetor *criar_vetor(int tam)
{
    vetor *v = (vetor *)malloc(sizeof(vetor));
    v->dados = (int *)malloc(tam * sizeof(int));
    v->n = 0;
    return v;
}
void destruir_vetor(vetor *v)
{
    free(v->dados);
    free(v);
}

void adicionar_elemento(vetor *v, int x)
{
    v->dados[v->n] = x;
    v->n++;
}
void remover_elemento(vetor *v, int i)
{
    v->dados[i] = v->dados[v->n - 1];
    v->n--;
}

int busca(vetor *v, int x)
{
    int i;
    for (i = 0; i < (v->n); i++)
        if (v->dados[i] == x)
            return i;
    return -1;
}
int acessar(vetor *v, int i)
{
    return v->dados[i];
}
int tamanho(vetor *v)
{
    return v->n;
}

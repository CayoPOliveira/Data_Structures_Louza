#include "vetor_dinamico.h"
#include <stdio.h>
#include <stdlib.h>

// Funções
vetor *criar_vetor(int tam)
{
    vetor *v = (vetor *)malloc(sizeof(vetor));
    v->dados = (int *)malloc(tam * sizeof(int));
    v->n = 0;
    v->alocado = tam;
    return v;
}
void destruir_vetor(vetor *v)
{
    free(v->dados);
    free(v);
}

void adicionar_elemento(vetor *v, int x)
{
    int i, *temp;
    if (v->n == v->alocado)
    {
        temp = v->dados;
        v->alocado *= 2;
        v->dados = (int *)malloc(v->alocado * sizeof(int));
        for (i = 0; i < v->n; i++)
            v->dados[i] = temp[i];
        free(temp);
    }
    v->dados[v->n] = x;
    v->n++;
}
void remover_elemento(vetor *v, int i)
{
    int j, *temp;
    v->dados[i] = v->dados[v->n - 1];
    v->n--;
    if (v->n < v->alocado / 4 && v->alocado >= 4)
    {
        temp = v->dados;
        v->alocado /= 2;
        v->dados = (int *)malloc(v->alocado * sizeof(int));
        for (j = 0; j < v->n; j++)
            v->dados[i] = temp[i];
        free(temp);
    }
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
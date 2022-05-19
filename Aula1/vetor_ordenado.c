#include "vetor_ordenado.h"
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
    int i;
    for (i = v->n - 1; i >= 0 && v->dados[i] > x; i--)
        v->dados[i + 1] = v->dados[i];
    v->dados[i + 1] = x;
    v->n++;
}
void remover_elemento(vetor *v, int i)
{
    for (; i < v->n - 1; i++)
        v->dados[i] = v->dados[i + 1];
    (v->n)--;
}

int busca_binaria(int *dados, int l, int r, int x)
{
    int m = (l + r) / 2;
    if (l > r)
        return -1;
    if (dados[m] == x)
        return m;
    if (dados[m] > x)
        return busca_binaria(dados, l, m - 1, x);
    else
        return busca_binaria(dados, m + 1, r, x);
}
int busca_binaria_iterativa(int *dados, int n, int x)
{
    int l = 0, r = n, m;
    while (l < r)
    {
        m = (l + r) / 2;
        if (dados[m] == x)
            return m;
        else if (dados[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int busca(vetor *v, int x)
{
    return busca_binaria(v->dados, 0, v->n, x);
    // return busca_binaria_iterativa(v->dados, v->n, x);
}
int acessar(vetor *v, int i)
{
    return v->dados[i];
}
int tamanho(vetor *v)
{
    return v->n;
}

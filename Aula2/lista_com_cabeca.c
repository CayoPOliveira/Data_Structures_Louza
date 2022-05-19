#include "lista_com_cabeca.h"
#include <stdio.h>
#include <stdlib.h>

// Funçes
No *criar_lista()
{
    No *q = (No *)malloc(sizeof(No));
    q->dado = 0;
    q->prox = NULL;
    return q;
}
void destruir_iterativo(No **p)
{
    No *q;
    while (*p != NULL)
    {
        q = *p;
        *p = (*p)->prox;
        free(q);
    }
}
void destruir_recursivo(No *p)
{
    if (p != NULL)
    {
        destruir_recursivo(p->prox);
        free(p);
    }
}
void destruir_lista(No **p)
{
    destruir_iterativo(p);
    // destruir_recursivo(*p); *p = NULL;
}
void imprimir_iterativo(No *p)
{
    No *q;
    for (q = p->prox; q != NULL; q = q->prox)
        printf("%d -> ", q->dado);
    printf("NULL\n");
}
void imprimir_recursivo(No *p)
{
    if (p != NULL)
    {
        printf("%d -> ", p->dado);
        imprimir_recursivo(p->prox);
    }
    else
        printf("NULL\n");
}
void imprimir_lista(No *p)
{
    imprimir_iterativo(p);
    // imprimir_recursivo(p->prox);
}

// Adicionar
void adicionar_inicio(No *p, int x)
{
    No *q = (No *)malloc(sizeof(No));
    if (q == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    q->dado = x;
    q->prox = p->prox;
    p->prox = q;
    p->dado++;
}
void adicionar_final(No *p, int x)
{
    No *q, *aux;
    q = (No *)malloc(sizeof(No));
    if (q == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    q->dado = x;
    q->prox = NULL;
    aux = p;
    while (aux->prox != NULL)
        aux = aux->prox;
    aux->prox = q;
    p->dado++;
}

// Remover
void remover_inicio(No *p)
{
    No *q = p->prox;
    if (q == NULL)
        return;
    p->prox = q->prox;
    free(q);
    p->dado--;
}
void remover_final(No *p)
{
    No *q = p;
    if (q->prox != NULL)
    {
        while (q->prox->prox != NULL)
            q = q->prox;
        No *aux = q->prox;
        q->prox = NULL;
        free(aux);
        p->dado--;
    }
}
void remover_valor(No *p, int v)
{
    No *q = p;
    while (q->prox != NULL)
    {
        if (q->prox->dado == v)
            break;
        q = q->prox;
    }
    if (q->prox == NULL)
        return;
    No *temp = q->prox;
    q->prox = temp->prox;
    free(temp);
    p->dado--;
}

// Buscar
int buscar_valor(No *p, int x)
{
    p = p->prox;
    while (p != NULL)
    {
        if (p->dado == x)
            return 1;
        p = p->prox;
    }
    return 0;
}

// Extra
int tamanho_lista(No *p)
{
    return p->dado;
}
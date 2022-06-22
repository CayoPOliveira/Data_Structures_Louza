#include "lista_ligada.h"
#include <stdio.h>
#include <stdlib.h>

// Funçes
No *criar_lista()
{
    return NULL;
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
    for (q = p; q != NULL; q = q->prox)
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
    // imprimir_recursivo(p);
}

// Adicionar
void adicionar_inicio(No **p, int x)
{
    No *q;
    q = (No *)malloc(sizeof(No));
    if (q == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    q->dado = x;
    q->prox = *p;
    *p = q;
}
void adicionar_final(No **p, int x)
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
    if (*p == NULL)
        *p = q;
    else
    {
        aux = *p;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = q;
    }
}

// Remover
void remover_inicio(No **p)
{
    No *q = *p;
    if (q == NULL)
        return;
    *p = q->prox;
    free(q);
}
void remover_final(No **p)
{
    No *q = *p;
    if (q == NULL)
        return;
    if (q->prox == NULL)
    {
        *p = NULL;
        free(q);
        return;
    }
    while (q->prox->prox != NULL)
        q = q->prox;
    free(q->prox);
    q->prox = NULL;
}
void remover_valor(No **p, int v)
{
    No *q = *p;
    if (q == NULL)
        return;
    if (q->dado == v)
    {
        *p = q->prox;
        free(q);
        return;
    }
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
}

// Buscar
int buscar_valor(No *p, int x)
{
    while (p != NULL)
    {
        if (p->dado == x)
            return 1;
        p = p->prox;
    }
    return 0;
}
int acessar_primeiro(No *p)
{
    if (p == NULL)
        return -1; // lista vazia
    No *q = p;
    return q->dado;
}
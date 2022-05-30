#include <stdio.h>
#include <stdlib.h>
#include "LLCircularTAD.h"

// Implementação com lista ligada circular, no L aponta pra o ultimo da lista
// Implementação semelhante ao TAD Lista Circular da aula 3

// Funções
No *criar_lista()
{
    return NULL;
}
void destruir_lista(No **p)
{ // p recebe &L
    if (*p == NULL)
        return; // lista vazia
    No *q = (*p)->prox, *aux;
    while (q != *p)
    {
        aux = q;
        q = q->prox;
        free(aux);
    }
    free(*p);
    *p = NULL;
}

// Imprimir
void imprimir_lista(No *p)
{ // p recebe L
    No *q, *aux = p;
    if (p != NULL)
    {
        for (q = p->prox; q != aux; q = q->prox)
            printf("%d -> ", q->dado);
        printf("%d -> ", q->dado);
    }
    printf("NULL\n");
}

// Adicionar
void adicionar_inicio(No **p, int x)
{ // p recebe &L
    No *q = (No *)malloc(sizeof(No));
    if (q == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    q->dado = x;
    if (*p == NULL)
    { // lista vazia
        *p = q;
        q->prox = q;
    }
    else
    {
        q->prox = (*p)->prox;
        (*p)->prox = q;
    }
}
void adicionar_final(No **p, int x)
{ // p recebe &L
    No *q = (No *)malloc(sizeof(No));
    if (q == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    q->dado = x;
    if (*p == NULL)
    { // lista vazia
        *p = q;
        q->prox = q;
    }
    else
    {
        q->prox = (*p)->prox;
        (*p)->prox = q;
        *p = q;
    }
}

// Remover
int remover_inicio(No **p) // Modificada pra retornar o valor do nó removido // p recebe &L
{
    int x;
    if (*p == NULL)
        return -1; // lista vazia
    No *q = *p;
    if (q->prox == q)
    { // 1 ´unico n´o
        x = q->dado;
        free(q);
        *p = NULL;
        return x;
    }
    q = q->prox;
    (*p)->prox = q->prox;
    x = q->dado;
    free(q);
    return x;
}
int remover_final(No **p) // Modificada pra retornar o valor do nó removido // p recebe &L
{
    int x;
    if (*p == NULL)
        return -1; // lista vazia
    No *q = *p;
    if (q->prox == q)
    { // 1 ´unico nó
        x = q->dado;
        free(q);
        *p = NULL;
        return x;
    }
    No *aux = q;
    while (q->prox != aux)
        q = q->prox;
    q->prox = aux->prox;
    *p = q;
    x = aux->dado;
    free(aux);
    return x;
}
void remover_valor(No **p, int x) // Não foi modificada pra retornar o valor pois já está sendo passado o valor, não faria muito sentido
{                                 // p recebe &L
    if (*p == NULL)
        return; // lista vazia
    No *q = *p;
    if (q->prox == q && q->dado == x)
    { // 1 único nó
        free(q);
        *p = NULL;
        return;
    }
    while (q->prox != *p && (q->prox)->dado != x)
        q = q->prox;
    if ((q->prox)->dado == x)
    { // encontrou
        No *aux = q->prox;
        q->prox = aux->prox;
        if (*p == aux) //último elemento
            *p = q;
        free(aux);
    }
}

// Buscar
int buscar_valor(No *p, int x)
{ // q recebe L
    if (p == NULL)
        return -1; // lista vazia
    No *q = p;
    p = p->prox;
    while (p != q)
    {
        if (p->dado == x)
            return 1; // true!
        p = p->prox;
    }
    if (p->dado == x)
        return 1; // true!
    return 0;     // false == n˜ao encontrou
}

// Extra
int tamanho_lista(No *p)
{
    if (p == NULL)
        return 0; // lista vazia
    No *q = p;
    int tam = 1;
    for (p = p->prox; p != q; p = p->prox)
        tam++;
    return tam;
}

// Fila
int retorna_inicio(No *p)
{
    if (p == NULL)
        return -1;
    return p->prox->dado;
}
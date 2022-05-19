#include "ListaLigadaTAD.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementação com lista duplamente ligada e circular

// Funçes
No *criar_lista()
{
    return NULL;
}
void destruir_lista(No **p)
{
    No *q;
    if ((*p) == NULL) // lista vazia
        return;
    (*p)->ante->prox = NULL; // remove a circulação da lista
    while ((*p) != NULL)
    {
        q = *p;
        *p = (*p)->prox;
        free(q);
    }
}

// Adicionar
void adicionar(No **p, char *str, int x) // Adiciona elementos sempre na posição anterior ao (*L)
{
    // Inicia o nó
    No *q = (No *)malloc(sizeof(No));
    if (q == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    q->dado = x;
    strcpy(q->name, str);

    // lista vazia, atualiza o (*p) com o primeiro nó criado
    if ((*p) == NULL)
    {
        q->prox = q->ante = q;
        (*p) = q;
    } // adiciona o nó como anterior ao (*p)
    else
    {
        q->ante = (*p)->ante;
        q->prox = (*p);
        (*p)->ante->prox = q;
        (*p)->ante = q;
    }
}

// Remover
int remover(No **p, int x) // Remove o primeiro elemento que encontrar com dado x, se x = -1, remove o Nó apontado em (*L) movendo para o próximo nó, se (*L) possuir o dado ele também será movido a frente. Irá retornar -1 caso não tenha sido possível encontrar o nó, ou retorna o dado armazenado no nó que foi excluido.
{
    if ((*p) == NULL)
        return -1;

    No *q = (x == -1 ? (*p) : (*p)->prox);       // Se x passado é -1, então preciso remover o nó em (*p)
    while (q->dado != x && q != (*p) && x != -1) // Do contrário esse laço pra percorrer precisa que q = (*p)->prox
        q = q->prox;
    if (q == (*p) && (q->dado == x || x == -1))
    { // Move o ponteiro (*p) para frente e remove
        (*p) = q->prox;
        if ((*p) == q) // Caso a lista so tenha um elemento
            (*p) = NULL;
        else
        {
            q->ante->prox = q->prox;
            q->prox->ante = q->ante;
        }
        x = q->dado;
        free(q);
        return x;
    }
    else if (q->dado == x) // Para evitar que quando não tenha encontrado elemento ele tente remover o nó em q
    {
        q->ante->prox = q->prox;
        q->prox->ante = q->ante;
        x = q->dado;
        free(q);
        return x;
    }
    return -1;
}

// Mover
// void andar(No **L, int n);  // Move n posições para frente
// void voltar(No **L, int n); // Move n posições no sentido contrário
void andar(No **p, int n) // Move n posições para frente
{
    if ((*p) == NULL)
        return;
    while (n--)
    {
        (*p) = (*p)->prox;
    }
}
void voltar(No **p, int n) // Move n posições no sentido contrário
{
    if ((*p) == NULL)
        return;
    while (n--)
    {
        (*p) = (*p)->ante;
    }
}

void mover(No **p, int n) // Move n posições para frente ou n posições para trás
{
    if ((*p) == NULL)
        return;
    if (n > 0)
        while (n--)
            (*p) = (*p)->prox;
    else //(n < 0)
    {
        n = -n;
        while (n--)
            (*p) = (*p)->ante;
    }
}

// Consultar
int numero_nos(No *p) // Retorna o número de nós
{
    No *q = p;
    int Count;
    for (Count = 1, q = q->prox; q != p; q = q->prox)
        Count++;
    return Count;
}
int dados(No *p, char *name) // Retorna o int do nó apontado por L e por referência retorna a string
{
    strcpy(name, p->name);
    return p->dado;
}

// Imprimir
void imprimir_lista(No *p) // Imprime toda a lista a partir do nó apontado por L
{
    if (p == NULL)
    {
        printf("Lista Vazia\n");
        return;
    }
    No *q = p->prox;
    printf("1:( %s , %d ) -> ", p->name, p->dado);
    int i = 1;
    while (q != p)
    {
        i++;
        printf("%d:( %s , %d ) -> ", i, q->name, q->dado);
        q = q->prox;
    }
    printf("[LOOP] 1:(...) -> ... \n");
}
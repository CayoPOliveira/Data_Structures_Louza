#include <stdio.h>
#include <stdlib.h>
#include "ListaLigadaTAD.h"

#define len_nome 40

int main()
{
    int N, Valor, i, j;
    char Nome[32];
    scanf("%d", &N);
    No *L = criar_lista();
    for (i = 0; i < N; i++)
    {
        scanf("%s%d", Nome, &Valor);
        adicionar(&L, Nome, Valor);
    }
    imprimir_lista(L);

    Valor = remover(&L, -1);
    printf("Valor = %d %s", Valor, (Valor == -1) ? "Não tinha o elemento\n" : "Elemento removido\n");
    imprimir_lista(L);

    mover(&L, 2);
    imprimir_lista(L);

    mover(&L, 5);
    imprimir_lista(L);

    mover(&L, -1);
    imprimir_lista(L);

    mover(&L, -2);
    imprimir_lista(L);

    Valor = remover(&L, 9);
    printf("Valor = %d %s", Valor, (Valor == -1) ? "Não tinha o elemento\n" : "Elemento removido\n");
    imprimir_lista(L);

    Valor = remover(&L, -1);
    printf("Valor = %d %s", Valor, (Valor == -1) ? "Não tinha o elemento\n" : "Elemento removido\n");
    imprimir_lista(L);
    Valor = remover(&L, -1);
    printf("Valor = %d %s", Valor, (Valor == -1) ? "Não tinha o elemento\n" : "Elemento removido\n");
    imprimir_lista(L);
    Valor = remover(&L, -1);
    printf("Valor = %d %s", Valor, (Valor == -1) ? "Não tinha o elemento\n" : "Elemento removido\n");
    imprimir_lista(L);
    Valor = remover(&L, -1);
    printf("Valor = %d %s", Valor, (Valor == -1) ? "Não tinha o elemento\n" : "Elemento removido\n");
    imprimir_lista(L);

    destruir_lista(&L);
    imprimir_lista(L);

    return 0;
}
#include <stdio.h>
#include "lista_ligada.h"
int main()
{
    int i, num;
    No *L = criar_lista();
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
        adicionar_final(&L, i);
    while (L != NULL)
    {
        imprimir_lista(L);
        scanf("%d", &num);
        remover_valor(&L, num);
    }
    destruir_lista(&L);
    return 0;
}
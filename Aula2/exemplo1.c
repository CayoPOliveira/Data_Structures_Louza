#include <stdio.h>
#include "lista_ligada.h"
int main()
{
    int num;
    No *L = criar_lista();
    /*lê números positivos e armazena na lista*/
    do
    {
        scanf("%d", &num);
        if (num > 0)
            adicionar_inicio(&L, num);
    } while (num > 0);
    imprimir_lista(L); /*(em ordem reversa de inserc¸˜ao)*/
    destruir_lista(&L);
    return 0;
}
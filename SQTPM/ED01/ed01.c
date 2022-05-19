#include <stdio.h>
#include "ListaLigadaTAD.h"

#define VENCEDOR(str) printf("Vencedor(a): %s\n", str); // Definição da saída padrão do problema

int main()
{
    // Declaração das variaveis;
    int N, i, Valor;
    char Nome[32];
    No *L;

    // Quando N=0 o laço encerra o programa
    for (scanf("%d", &N); N != 0; scanf("%d", &N))
    {
        // Criação da lista e inserção dos nós
        L = criar_lista();
        for (i = 0; i < N; i++)
        {
            scanf("%s%d", Nome, &Valor);
            adicionar(&L, Nome, Valor);
        }

        // Pegar o dado inteiro do primeiro nó
        Valor = dados(L, Nome);
        // Primeiro movimento não pode remover o elemento
        if (Valor % 2 == 0)
            mover(&L, -Valor); // Como a inserção foi considerada sentido anti horário,
                               // pra ir no sentido horário o número de posições passadas é negativo
        else
            mover(&L, Valor);

        // Roda até ter uma pessoa só (Um nó)
        while (numero_nos(L) != 1)
        {
            // Remove o nó ou pessoa que saiu, e salva o inteiro que ela possuía na variavel valor
            Valor = remover(&L, -1);
            // Movimenta sentido horário ou anti horário
            if (Valor % 2 == 0)
                mover(&L, -Valor);
            else
                mover(&L, (Valor - 1)); // Como a função q remove anda o ponteiro pra frente, e esse sentido está
                                        // convencionado como anti horário, é preciso andar -1 posições do valor encontrado.
        }

        dados(L, Nome);
        VENCEDOR(Nome);     // Ultimo nó
        destruir_lista(&L); // Limpa a lista
    }

    return 0;
}
#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#define TAMANHO_CHAR 32 // Defina o tamanho máximo de seus chars

// Implementação de TAD para lista circular e duplamente ligada
// não utilize mais de um ponteiro pra lista, use sempre o ponteiro que criou a lista

// Dados
typedef struct no
{
    int dado;
    char name[TAMANHO_CHAR];
    struct no *prox;
    struct no *ante;
} No;

// Funções
No *criar_lista();           // Atribua a uma variavel do tipo No*
void destruir_lista(No **L); // Utilize para liberar toda a memória criada para lista

// Adicionar
void adicionar(No **L, char *Str, int x); // Adiciona elementos sempre na posição anterior ao (*L)

// Remover
int remover(No **L, int x); // Remove o primeiro elemento que encontrar com dado x,
                            // se x = -1, remove o Nó apontado em (*L) movendo para
                            // o próximo nó, se (*L) possuir o dado ele também será
                            // movido a frente. Irá retornar -1 caso não tenha sido
                            // possível encontrar o nó, ou retorna o dado armazenado
                            // no nó que foi excluido.

// Mover
void mover(No **p, int n); // Move n posições para frente (n>0) ou n posições para trás (n<0)

// Consultar
int numero_nos(No *L);        // Retorna o número de nós
int dados(No *L, char *name); // Retorna o int do nó apontado por L e por referência retorna a string

// Imprimir
void imprimir_lista(No *L); // Imprime toda a lista a partir do nó apontado por L

#endif
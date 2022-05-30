#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

// Dados
typedef struct no
{
    int dado;
    struct no *prox;
} No;

// Funções
No *criar_lista();
void destruir_lista(No **L);

// Imprimir
void imprimir_lista(No *L);

// Adicionar
void adicionar_inicio(No **L, int x);
void adicionar_final(No **L, int x);

// Remover
int remover_inicio(No **L);
int remover_final(No **L);
void remover_valor(No **L, int x);

// Buscar
int buscar_valor(No *L, int x);

// Extra
int tamanho_lista(No *L);

// Fila e Pilha
int retorna_inicio(No *L); // Retorna o dado do primeiro elemento, função para ser usada em implementações de filas e pilhas

#endif
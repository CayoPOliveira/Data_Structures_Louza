#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

// Dados
typedef struct no
{
  int dado;
  struct no *esq, *dir; // *pai
} No;

// Funções
No *criar_no(int x, No *l, No *r);
void destruir_arvore(No **raiz);

/*
Default Mode
*/
void imprimir_arvore(No *raiz);

/*
Mode:
      1 - Pre ordem
      2 - In ordem
      3 - Pos ordem
*/
void imprimir_arvore_mode(No *raiz, int mode);

No *procurar_no(No *raiz, int x);

int numero_nos(No *raiz);

int altura(No *raiz);

#endif
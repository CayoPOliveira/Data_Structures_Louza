#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

// Dados
typedef struct no
{
  int chave;
  struct no *esq, *dir, *pai; // *pai
} No;

// Funções
No *criar_arvore();
void destruir_arvore(No **p);

/*
Default Mode
*/
void imprimir_arvore(No *p);

/*
Mode:
      1 - Pre ordem
      2 - In ordem
      3 - Pos ordem
*/
void imprimir_arvore_mode(No *p, int mode);

No *inserir(No *p, int chave);
void remover(No **p, int chave);

No *buscar(No *p, int chave);

int numero_nos(No *p);
int altura(No *p);

#endif
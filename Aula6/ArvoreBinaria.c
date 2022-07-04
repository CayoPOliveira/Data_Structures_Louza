#include "ArvoreBinaria.h"
#include <stdio.h>
#include <stdlib.h>

// Funções
No *criar_no(int x, No *l, No *r)
{
  No *no = (No *)malloc(sizeof(No));
  no->dado = x;
  no->esq = l;
  no->dir = r;
  return no;
}
void destruir_arvore(No **raiz)
{
  if (*raiz == NULL)
    return;
  destruir_arvore(&((*raiz)->esq));
  destruir_arvore(&((*raiz)->dir));
  free(*raiz);
  *raiz = NULL;
}

void printnode(int x, int h)
{
  int i;
  for (i = 0; i < h; i++)
    printf("\t");
  printf("%2d\n", x);
}

void print_pre_ordem(No *p, int h)
{
  if (p == NULL)
    return;
  printnode(p->dado, 0);
  print_pre_ordem(p->esq, h + 1);
  print_pre_ordem(p->dir, h + 1);
}

void print_in_ordem(No *p, int h)
{
  if (p == NULL)
    return;
  print_in_ordem(p->esq, h + 1);
  printnode(p->dado, 0);
  print_in_ordem(p->dir, h + 1);
}

void print_pos_ordem(No *p, int h)
{
  if (p == NULL)
    return;
  print_pos_ordem(p->esq, h + 1);
  print_pos_ordem(p->dir, h + 1);
  printnode(p->dado, 0);
}

void print(No *p, int h)
{
  if (p == NULL)
    return;
  print(p->dir, h + 1);
  printnode(p->dado, h);
  print(p->esq, h + 1);
}

void imprimir_arvore_mode(No *raiz, int mode)
{
  switch (mode)
  {
  case 0:
    print(raiz, 0);
    break;
  case 1:
    print_pre_ordem(raiz, 0);
    break;
  case 2:
    print_in_ordem(raiz, 0);
    break;
  case 3:
    print_pos_ordem(raiz, 0);
    break;
  default:
    break;
  }
}

void imprimir_arvore(No *raiz)
{
  imprimir_arvore_mode(raiz, 0);
}

No *procurar_no(No *raiz, int x)
{
  if (raiz == NULL || raiz->dado == x)
    return raiz;
  No *esq = procurar_no(raiz->esq, x);
  if (esq != NULL)
    return esq;
  return procurar_no(raiz->dir, x);
}

int numero_nos(No *raiz)
{
  if (raiz == NULL)
    return 0;
  return numero_nos(raiz->esq) + numero_nos(raiz->dir) + 1;
}

int altura(No *raiz)
{
  int h_esq, h_dir;
  if (raiz == NULL)
    return 0;
  h_esq = altura(raiz->esq);
  h_dir = altura(raiz->dir);
  return (h_esq > h_dir ? h_esq : h_dir) + 1;
}

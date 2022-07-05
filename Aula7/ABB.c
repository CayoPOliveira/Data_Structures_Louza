#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>

// Funções
No *criar_arvore()
{
  return NULL;
}
void destruir_arvore(No **p)
{
  if (*p == NULL)
    return;
  destruir_arvore(&((*p)->esq));
  destruir_arvore(&((*p)->dir));
  free(*p);
  *p = NULL;
}

void printnode(int x, int h)
{
  int i;
  for (i = 0; i < h; i++)
    printf("\t");
  printf("%2d\n", x);
}

void print(No *p, int h)
{
  if (p == NULL)
    return;
  print(p->dir, h + 1);
  printnode(p->chave, h);
  print(p->esq, h + 1);
}

void print_pre_ordem(No *p, int h)
{
  if (p == NULL)
    return;
  printf("%d ", p->chave);
  print_pre_ordem(p->esq, h + 1);
  print_pre_ordem(p->dir, h + 1);
}

void print_in_ordem(No *p, int h)
{
  if (p == NULL)
    return;
  print_in_ordem(p->esq, h + 1);
  printf("%d ", p->chave);
  print_in_ordem(p->dir, h + 1);
}

void print_pos_ordem(No *p, int h)
{
  if (p == NULL)
    return;
  print_pos_ordem(p->esq, h + 1);
  print_pos_ordem(p->dir, h + 1);
  printf("%d ", p->chave);
}

void imprimir_arvore_mode(No *p, int mode)
{
  switch (mode)
  {
  case 0:
    print(p, 0);
    break;
  case 1:
    print_pre_ordem(p, 0);
    break;
  case 2:
    print_in_ordem(p, 0);
    break;
  case 3:
    print_pos_ordem(p, 0);
    break;
  default:
    break;
  }
}

void imprimir_arvore(No *p)
{
  imprimir_arvore_mode(p, 0);
}

No *minimo(No *p)
{ // Recursão em cauda
  if (p == NULL || p->esq == NULL)
    return p;
  return minimo(p->esq);
}
No *minimo_iterativo(No *p)
{
  while (p != NULL && p->esq != NULL)
    p = p->esq;
  return p;
}
No *maximo(No *p)
{ // Recursão em cauda
  if (p == NULL || p->dir == NULL)
    return p;
  return minimo(p->dir);
}
No *maximo_iterativo(No *p)
{
  while (p != NULL && p->dir != NULL)
    p = p->dir;
  return p;
}

No *ancestral_a_direita(No *p)
{
  if (p == NULL)
    return NULL;
  if (p->pai == NULL || p->pai->esq == p)
    return p->pai;
  else
    return ancestral_a_direita(p->pai);
}
No *sucessor(No *p)
{
  if (p == NULL)
    return NULL;
  if (p->dir != NULL)
    return minimo_iterativo(p->dir);
  else
    return ancestral_a_direita(p);
}

No *inserir(No *p, int chave)
{
  if (p == NULL)
  {
    No *novo;
    novo = malloc(sizeof(No));
    novo->esq = novo->dir = NULL;
    novo->chave = chave;
    return novo;
  }
  if (chave < p->chave)
  {
    p->esq = inserir(p->esq, chave);
    p->esq->pai = p;
  }
  else
  {
    p->dir = inserir(p->dir, chave);
    p->dir->pai = p;
  }
  return p;
}

void remover_sucessor(No *p)
{
  No *min = p->dir;
  No *pai = p;
  while (min->esq != NULL)
  {
    pai = min;
    min = min->esq;
  }
  if (pai->esq == min)
  {
    pai->esq = min->dir;
  }
  else
  {
    pai->dir = min->dir;
  }
  p->chave = min->chave;
  free(min);
}
No *remover_rec(No *p, int chave)
{
  // Busca o nó
  if (p == NULL)
    return NULL;
  if (chave < p->chave)
  {
    p->esq = remover_rec(p->esq, chave);
    if (p->esq != NULL)
      p->esq->pai = p;
  }
  else if (chave > p->chave)
  {
    p->dir = remover_rec(p->dir, chave);
    if (p->dir != NULL)
      p->dir->pai = p;
  }
  // Filho a direita é o sucessor
  else if (p->esq == NULL)
  {
    No *q = p->dir;
    free(p);
    return q;
  }
  // Não tem sucessor
  else if (p->dir == NULL)
  {
    No *q = p->esq;
    free(p);
    return q;
  }
  else
    remover_sucessor(p);
  return p;
}
void remover(No **p, int chave)
{
  *p = remover_rec(*p, chave);
}

No *buscar(No *p, int x)
{
  if (p == NULL || p->chave == x)
    return p;
  if (x < p->chave)
    return buscar(p->esq, x);
  else
    return buscar(p->dir, x);
}

int numero_nos(No *p)
{
  if (p == NULL)
    return 0;
  return numero_nos(p->esq) + numero_nos(p->dir) + 1;
}

int altura(No *p)
{
  int h_esq, h_dir;
  if (p == NULL)
    return 0;
  h_esq = altura(p->esq);
  h_dir = altura(p->dir);
  return (h_esq > h_dir ? h_esq : h_dir) + 1;
}

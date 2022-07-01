#include <stdio.h>
#include <stdlib.h>
#include "ABBTAD.h"

/*< Recebe um vetor do percurso em pós-odrem( *P_ordem ), o percurso in-ordem( *I_ordem ) e o tamanho dos vetores.
  Retorna o endereço para a árvore criada >*/
No *new_node(DATA data) // Aloca na memória um nó com dado
{
  No *p = (No *)malloc(sizeof(No));
  p->data = data;
  p->l = p->r = NULL;
  return p;
}
void insert(No **p, int n, int *P_ordem, int i, int *I_ordem, int l, int r)
{
  if (l >= r || i >= r)
    return;

  int m;
  for (m = l; m < r; m++)
  {
    if (I_ordem[m] == P_ordem[i])
      break;
  }
  if (m == r)
    return;

  (*p) = new_node(P_ordem[i]);
  insert(&((*p)->l), n, P_ordem, i + 1, I_ordem, l, m);
  insert(&((*p)->r), n, P_ordem, m + 1, I_ordem, m + 1, r);
}
ABB *abb_criar_arvore_predefinida(int *P_ordem, int *I_ordem, int n)
{
  ABB *abb = (ABB *)malloc(sizeof(ABB));
  abb->N = n;
  insert(&(abb->raiz), n, P_ordem, 0, I_ordem, 0, n);
  return abb;
}

/*< Recebe o endereço do ponteiro para a árvore e libera a memória criada, após a execução (*abb == NULL) >*/
void delete (No *p)
{
  if (p == NULL)
    return;
  delete (p->l);
  delete (p->r);
  free(p);
}
void abb_destruir(ABB **abb)
{
  if (*abb == NULL)
    return;
  delete ((*abb)->raiz);
  free(*abb);
  *abb = NULL;
}

/*< Recebe o endereço da árvore e imprime o percurso em pos-ordem >*/
void print(No *p) // Caso queira mudar o estilo de impressão
{
  printf(PRTDATA, p->data);
}
void print_p_ordem(No *p)
{
  if (p == NULL)
    return;
  print_p_ordem(p->l);
  print_p_ordem(p->r);
  print(p);
}
void abb_imprimir_pos_odem(ABB *abb)
{
  print_p_ordem(abb->raiz);
}

/*< Recebe o endereço da árvore e um dado x. Retorna 1 se o dado está presente na árvore, caso contrário retorna 0;
  Retorna -1 caso a árvore não tenha sido criada >*/
int search(int x, No *p)
{
  if (p == NULL)
    return 0;
  if (p->data == x)
    return 1;
  return search(x, p->l) ? 1 : search(x, p->r);
}
int abb_procurar_no(ABB *abb, int x)
{
  if (abb == NULL)
    return -1;
  return search(x, abb->raiz);
}

/*< Recebe o endereço da árvore e retorna o número de nós armazenados na árvore>*/
int abb_numero_nos(ABB *abb)
{
  if (abb == NULL)
    return -1;
  return abb->N;
}

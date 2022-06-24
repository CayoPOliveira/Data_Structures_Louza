#include <stdlib.h>
#include "ABBTAD.h"

struct no
{
  int data;             // DATA
  struct no *l, *r, *f; // Left, Right Pointers and Father Pointer
};

/*< Recebe um vetor do percurso em pós-odrem( *P_ordem ) e o percurso in-ordem( *I_ordem ) e retorna o endereço para a árvore criada>*/
ABB *abb_criar_arvore_predefinida(int *P_ordem, int *I_ordem)
{
}

/*< Recebe o endereço do ponteiro para a árvore e libera a memória criada, após a execução (*abb == NULL) >*/
void abb_destruir(ABB **abb);

/*< Recebe o endereço da árvore e imprime o percurso em pos-ordem >*/
void abb_imprimir_pos_odem(ABB *abb);

int search(int x, No p)
{
  if (p == NULL)
    return 0;
  if (p->data == x)
    return 1;
  return search(x, p->l) ? 1 : search(x, p->r);
}

/*< Recebe o endereço da árvore e um dado x. Retorna 1 se o dado está presente na árvore, caso contrário retorna 0 >*/
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

/*< Recebe o endereço da árvore e retorna a altura máxima da árvore>*/
int abb_altura(ABB *abb)
{
  if (abb == NULL)
    return -1;
  return abb->H;
}
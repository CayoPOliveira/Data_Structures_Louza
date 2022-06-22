#include <stdlib.h>
#include "pilha_vetor.h"

// Funções
Pilha *pilha_criar()
{
  Pilha *P = malloc(sizeof(Pilha));
  P->dados = malloc(MAX * sizeof(int));
  P->topo = 0;
  P->N = MAX;
  return P;
}
void pilha_destruir(Pilha **p)
{ // p recebe &P
  free((*p)->dados);
  free(*p);
  *p = NULL;
}

// Adicionar
void pilha_adicionar(Pilha *p, int x)
{ // p recebe &P
  p->dados[p->topo] = x;
  p->topo++;
}

// Acessar
int pilha_topo(Pilha *p)
{
  return (p->topo) ? p->dados[p->topo - 1] : -1;
}

// Remover
void pilha_remover(Pilha *p)
{ // p recebe P
  if (p->topo == 0)
    return;
  p->topo--;
}

// Extra
int pilha_tamanho(Pilha *p)
{
  return p->topo;
}
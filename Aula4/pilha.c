#include <stdlib.h>
#include "pilha.h"

// Funções
Pilha *pilha_criar()
{
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->L = criar_lista();
  p->tam = 0;
  return p;
}
void pilha_destruir(Pilha **p)
{ // p recebe &F
  destruir_lista(&((*p)->L));
  free(*p);
  *p = NULL;
}

// Adicionar
void pilha_adicionar(Pilha *p, int x)
{ // p recebe &F
  adicionar_inicio(&(p->L), x);
  p->tam++;
}

// Acessar
int pilha_topo(Pilha *p)
{
  return acessar_primeiro(p->L);
}

// Remover
void pilha_remover(Pilha *p)
{
  remover_inicio(&(*p->L));
  if (p->tam > 0)
    p->tam--;
}

// Extra
int pilha_tamanho(Pilha *p)
{
  return p->tam;
}
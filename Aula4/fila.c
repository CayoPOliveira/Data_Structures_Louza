#include <stdlib.h>
#include "fila.h"

// Funções
Fila *fila_criar()
{
  Fila *p = (Fila *)malloc(sizeof(Fila));
  p->tam = 0;
  p->L = criar_lista();
  return p;
}
void fila_destruir(Fila **p)
{ // p recebe &F
  destruir_lista(&((*p)->L));
  free(*p);
  *p = NULL;
}

// Adicionar
void fila_adicionar(Fila *p, int x)
{ // p recebe F
  adicionar_final(&(p->L), x);
  p->tam++;
}

// Acessar
int fila_topo(Fila *p)
{ // p recebe F
  return acessar_primeiro(p->L);
}

// Remover
void fila_remover(Fila *p)
{ // p recebe &F
  remover_inicio(&(p->L));
  if (p->tam > 0)
    p->tam--;
}

// Extra
int fila_tamanho(Fila *p)
{
  return p->tam;
}

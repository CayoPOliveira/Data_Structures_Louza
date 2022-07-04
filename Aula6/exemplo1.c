#include <stdio.h>
#include "ArvoreBinaria.h"

No *torneio(int *v, int l, int r);

int main()
{
  int teste[8] = {5, 1, 7, 4, 3, 2, 6, 8};
  No *T = torneio(teste, 0, 7);
  imprimir_arvore(T);
  printf("nos: %d\n", numero_nos(T));
  printf("altura: %d\n", altura(T));
  destruir_arvore(&T);
  return 0;
}

No *torneio(int *v, int l, int r)
{
  No *esq, *dir;
  int valor, m = (l + r) / 2;
  if (l == r)
    return criar_no(v[l], NULL, NULL);
  esq = torneio(v, l, m);
  dir = torneio(v, m + 1, r);
  valor = (esq->dado > dir->dado) ? esq->dado : dir->dado;
  return criar_no(valor, esq, dir);
}
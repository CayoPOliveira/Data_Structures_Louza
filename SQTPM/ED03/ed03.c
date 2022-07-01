#include <stdio.h>

#include "ABBTAD.h"

int main()
{
  int c, n;
  char temp[53], temp2[53];
  int Pordem[53], Iordem[53];
  scanf("%d", &c);
  for (int i = 0; i < c; i++)
  {
    scanf("%d%s%s", &n, temp, temp2);
    for (int j = 0; j < n; j++)
    {
      Pordem[j] = (int)temp[j];
      Iordem[j] = (int)temp2[j];
      // printf("%c %c\n", Pordem[j], Iordem[j]);
    }
    // printf("%s\n%s\n", temp, temp2);

    ABB *abb = abb_criar_arvore_predefinida(Pordem, Iordem, n);
    abb_imprimir_pos_odem(abb);
    abb_destruir(&abb);
    printf("\n");
  }

  return 0;
}
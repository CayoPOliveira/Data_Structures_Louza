#include <stdio.h>
#include <string.h>
#include "BinTree_TAD.h"

int main()
{
  int N, M;
  // read input
  scanf("%d%d", &N, &M);
  Forest *F = BinTree_Make_Forest(N);

  char operacao[10];
  int A = 0, B = 0;
  while (M--)
  {
    // for each line;
    scanf("%s", operacao);
    if (!strcmp("link", operacao)) // link
    {
      scanf("%d%d", &A, &B);
      BinTree_Link_AB(F, A, B);
    }
    else if (!strcmp("cut", operacao)) // cut
    {
      scanf("%d", &A);
      BinTree_Cut_A(F, A);
    }
    else if (!strcmp("lca", operacao)) // lca
    {
      scanf("%d%d", &A, &B);
      printf("%d\n", BinTree_LCA_AB(F, A, B));
    }
    // DEBUG
    else if (!strcmp("anc", operacao))
    {
      scanf("%d", &A);
      // just for debug tests
      BinTree_Print_Ancestors_DEBUG(F, A);
    }
  }
  // free
  BinTree_Free_Forest(&F);
  return 0;
}
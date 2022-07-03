#include "BinTree_TAD.h"
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

#define NODE(i) (F->Nodes[(i)])
#define NODE_KEY(i) (NODE(i)->key)
#define NODE_FATHER(i) (NODE(i)->father)
#define NODE_LEFT(i) (NODE(i)->left)
#define NODE_RIGHT(i) (NODE(i)->right)
/*
  Return a pointer of type Forest, used in the other operations,
  Make N nodes roots of subtrees
*/
Forest *BinTree_Make_Forest(int n)
{
  Forest *F = (Forest *)malloc(sizeof(Forest));
  F->N = n;
  F->Nodes = (Node **)malloc((n + 1) * sizeof(Node *));
  for (int i = 1; i < n + 1; i++)
  {
    NODE(i) = (Node *)malloc(sizeof(Node));
    NODE_KEY(i) = i;
    // this is a root first
    NODE_FATHER(i) = NODE_LEFT(i) = NODE_RIGHT(i) = NULL;
  }
  return F;
}
/*
  Free the memory, delete all the nodes
*/
void BinTree_Free_Forest(Forest **F)
{
  for (int i = 0; i < (*F)->N; i++)
    free((*F)->Nodes[i + 1]);
  free((*F)->Nodes);
  free((*F));
  *F = NULL;
}

/*
  Make B the father of node A
  A must be a root (else: use cut operation before)
*/
void BinTree_Link_AB(Forest *F, int a, int b)
{
  Node *pa = NODE(a);
  Node *pb = NODE(b);
  if (pb->left == NULL)
  {
    pb->left = pa;
    pa->father = pb;
    return;
  }
  if (pb->right == NULL)
  {
    pb->right = pa;
    pa->father = pb;
    return;
  }
  // This is not to be hapen -> DEBUG
  else
    return;
}
/*
  Make A root node, remove the father conection
*/
void BinTree_Cut_A(Forest *F, int a)
{
  // This is not to be hapen -> DEBUG
  if (NODE_FATHER(a) == NULL)
    return;

  Node *p = NODE(a);
  Node *father = p->father;
  if (father->left == p) // A is a left child
    father->left = NULL;
  else if (father->right == p) // A is a right child
    father->right = NULL;
  p->father = NULL;
}

/*
  Make a ancestor's array of a node
*/
int BinTree_Ancestors_List(Forest *F, int i, int *ancestors)
{
  int n = 0;
  Node *p = NODE(i);
  while (p != NULL)
  {
    ancestors[n] = p->key;
    n++;
    p = p->father;
  }
  return n;
}
void BinTree_Print_Ancestors(int *anc, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", anc[i]);
  }
  printf("\n");
}
/*
  Find the Lowest Common Ancestor (LCA) of A and B
*/
int BinTree_LCA_AB(Forest *F, int a, int b)
{
  if (a == b) // The worst case can be simple
    return a;

  int anc_a[F->N], anc_b[F->N];
  int Na = 0, Nb = 0;
  /* Ancestors arrays*/
  Na = BinTree_Ancestors_List(F, a, anc_a);
#if DEBUG
  BinTree_Print_Ancestors(anc_a, Na);
#endif
  Nb = BinTree_Ancestors_List(F, b, anc_b);
#if DEBUG
  BinTree_Print_Ancestors(anc_b, Nb);
#endif
  /* Find LCA */
  int lca = 0;
  while (Na > 0 && Nb > 0)
  {
    if (anc_a[--Na] == anc_b[--Nb])
      lca = anc_a[Na];
    else
      break;
  }

  return lca;
}

// DEBUG TOOL
void BinTree_Print_Ancestors_DEBUG(Forest *F, int i)
{
  int n, anc[F->N];
  n = BinTree_Ancestors_List(F, i, anc);
  BinTree_Print_Ancestors(anc, n);
}
#ifndef BINTREE_TAD
#define BINTREE_TAD

typedef struct BinTreeNode
{
  /* key of the node */
  int key; // Keu number of node
  struct BinTreeNode
      *left,   // left child
      *right,  // right child
      *father; // father
} Node;

typedef struct BinTrees
{
  int N;        // Number os nodes
  Node **Nodes; // Array of node pointers
} Forest;

/*
  Return a pointer of type Forest, used in the other operations,
  Make N nodes roots of subtrees
*/
Forest *BinTree_Make_Forest(int n);
/*
  Free the memory, delete all the nodes
*/
void BinTree_Free_Forest(Forest **F);

/*
  Make B the father of node A
  A must be a root (else: use cut operation before)
*/
void BinTree_Link_AB(Forest *F, int a, int b);
/*
  Make A root node, remove the father conection
*/
void BinTree_Cut_A(Forest *F, int a);

/*
  Find the Lowest Common Ancestor (LCA) of A and B
*/
int BinTree_LCA_AB(Forest *F, int a, int b);

// DEBUG TOOL
void BinTree_Print_Ancestors_DEBUG(Forest *F, int i);

#endif
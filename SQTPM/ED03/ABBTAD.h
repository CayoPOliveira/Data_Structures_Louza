/*
  TAD Árvores Binárias de Busca
  Essa TAD se destina a criação, e manipulação de uma árvore binária quando se conhece o percurso pre-ordem e in-ordem.
  Permite consultar posteriormente a altura da árvore, número de nós, procurar um nó e imprimir o percurso pós-ordem
*/

#ifndef ABB_TAD
#define ABB_TAD

typedef struct no
{
  int data;             // DATA
  struct no *l, *r, *f; // Left, Right Pointers and Father Pointer
} No;

typedef struct
{
  int N, H;
  No *raiz;
} ABB;

// Funções

/*< Recebe um vetor do percurso em pós-odrem( *P_ordem ) e o percurso in-ordem( *I_ordem ) e retorna o endereço para a árvore criada>*/
ABB *abb_criar_arvore_predefinida(int *P_ordem, int *I_ordem);

/*< Recebe o endereço do ponteiro para a árvore e libera a memória criada, após a execução (*abb == NULL) >*/
void abb_destruir(ABB **abb);

/*< Recebe o endereço da árvore e imprime o percurso em pos-ordem >*/
void abb_imprimir_pos_odem(ABB *abb);

/*< Recebe o endereço da árvore e um dado x. Retorna 1 se o dado está presente na árvore, caso contrário retorna 0 >*/
int abb_procurar_no(ABB *abb, int x);

/*< Recebe o endereço da árvore e retorna o número de nós armazenados na árvore>*/
int abb_numero_nos(ABB *abb);

/*< Recebe o endereço da árvore e retorna a altura máxima da árvore>*/
int abb_altura(ABB *abb);

#endif
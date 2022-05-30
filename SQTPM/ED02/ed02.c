#include <stdio.h>
#include "FilaTAD.h"

// Guardar i e j em um valor de inteiro apenas
#define ZIP_IJ(i, j) ((i)*1000 + (j))
#define UNZIP_I(x) ((x) / 1000)
#define UNZIP_J(x) ((x) % 1000)

// Maior altitude, usada para borda de segurança da matriz
#define MAX_ALTITUDE 100

typedef struct
{
    int depth; // profundidade da terra
    int hb;    // hydrographic basin id [ int('a') , int('z') ]
} Land;

int main(void)
{
    int H, W, i, j, k, x;
    int Tag = (int)'a'; // Id inicial das bacias

    scanf("%d%d", &H, &W);
    Land M[H + 2][W + 2]; // A matriz possui uma borda pra evitar acesso inválido a memória

    for (i = 0; i < H + 2; i++)
        for (j = 0; j < W + 2; j++)
        {
            if (i == 0 || i == H + 1 || j == 0 || j == W + 1) // Caso da borda
            {
                M[i][j].depth = MAX_ALTITUDE;
                M[i][j].hb = (int)'_';
            }
            else // Matriz de entrada
            {
                scanf("%d", &M[i][j].depth);
                M[i][j].hb = (int)'_';
            }
        }
    Fila *PQueue[MAX_ALTITUDE]; //"fila de prioridade", cada posição é uma fila com prioridade de processamento maior do que a próxima fila
    for (i = 0; i < MAX_ALTITUDE; i++)
    {
        PQueue[i] = fila_criar();
    }

    for (i = 1; i <= H; i++)
        for (j = 1; j <= W; j++)
            if (M[i - 1][j].depth >= M[i][j].depth &&
                M[i + 1][j].depth >= M[i][j].depth &&
                M[i][j + 1].depth >= M[i][j].depth &&
                M[i][j - 1].depth >= M[i][j].depth) // Ponto de dissipação
            {
                M[i][j].hb = Tag++;
                fila_adicionar(PQueue[M[i][j].depth], ZIP_IJ(i, j));
            }

    for (k = 0; k < MAX_ALTITUDE; k++) // Percorre o vetor de filas, priorizando as de menor profundidade primeiro
        while (!fila_empty(PQueue[k])) // Enquanto a fila de profundidade k não estiver vazia será processada as posições
        {
            x = fila_remover(PQueue[k]);
            i = UNZIP_I(x);
            j = UNZIP_J(x);

            // Inserção dos vizinhos quando não estão na borda,
            // possuem profundidade maior que a posição atual e não foram adicionados a nenhuma bacia

            //  baixo
            if (i + 1 <= H && M[i + 1][j].depth > M[i][j].depth && M[i + 1][j].hb == '_')
            {
                M[i + 1][j].hb = M[i][j].hb;                                 // Coloca a mesma bacia para ambos
                fila_adicionar(PQueue[M[i + 1][j].depth], ZIP_IJ(i + 1, j)); // PQueue[] indica a fila de profundidade M[][].depth
            }
            // direita
            if (j + 1 <= W && M[i][j + 1].depth > M[i][j].depth && M[i][j + 1].hb == '_')
            {
                M[i][j + 1].hb = M[i][j].hb;
                fila_adicionar(PQueue[M[i][j + 1].depth], ZIP_IJ(i, j + 1));
            }
            // esquerda
            if (j - 1 >= 1 && M[i][j - 1].depth > M[i][j].depth && M[i][j - 1].hb == '_')
            {
                M[i][j - 1].hb = M[i][j].hb;
                fila_adicionar(PQueue[M[i][j - 1].depth], ZIP_IJ(i, j - 1));
            }
            // cima
            if (i - 1 >= 1 && M[i - 1][j].depth > M[i][j].depth && M[i - 1][j].hb == '_')
            {
                M[i - 1][j].hb = M[i][j].hb;
                fila_adicionar(PQueue[M[i - 1][j].depth], ZIP_IJ(i - 1, j));
            }
        }

    for (i = 1; i <= H; i++) // Output
    {
        for (j = 1; j <= W; j++)
            printf("%c ", (char)M[i][j].hb); // print convertendo os dados em char
        printf("\n");
    }
    for (i = 0; i < MAX_ALTITUDE; i++)
    {
        fila_destruir(&PQueue[i]); // libera a memória da heap
    }
    return 0;
}
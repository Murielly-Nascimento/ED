#include "Aprendizado.h"

typedef struct
{
    int peso;
    APRENDIZADO *aprendizado;
} VERTICE;

struct grafo
{
    int NumVertices;
    int NumArestas;
    int tamanho;
    VERTICE **Mat;
};
typedef struct grafo TipoGrafo;

TipoGrafo *CriarGrafo(int NVertices);

int inserirVertice(TipoGrafo *G, APRENDIZADO *dados);
int removeVertice(TipoGrafo *G, int posicao);

int inserirAresta(TipoGrafo *G, int v1, int v2, int peso);
int retirarAresta(TipoGrafo *Grafo, int v1, int v2);

void exibirGrafo(TipoGrafo *G);
void exibirMatriz(TipoGrafo *G);

TipoGrafo *liberarGrafo(TipoGrafo *G);

int *caminhoMaisCurto(TipoGrafo *G, int origem);
void caminho(TipoGrafo *G, int origem, int destino);
void exibeCaminho(TipoGrafo *G, int origem);

int grauVertice(TipoGrafo *G, int vertice);
int maiorGrau(TipoGrafo *G);

void BuscaEmProfundidade(TipoGrafo *G, int origem);
void conexoesFortes(TipoGrafo *G);

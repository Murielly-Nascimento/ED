#include "TAD_Grafo.h"
#include "TAD_Pilha.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// CRIA GRAFO
TipoGrafo *CriarGrafo(int NVertices)
{
    int i = 0, k = 0;
    TipoGrafo *Grafo;

    // Se o número de vértices é invalido
    if (NVertices <= 0)
        return NULL;

    // Aloca Grafo
    Grafo = (TipoGrafo *)malloc(sizeof(TipoGrafo *));
    if (Grafo == NULL)
        return NULL;

    // Aloca matriz de vértices
    Grafo->Mat = (VERTICE **)malloc(NVertices * sizeof(VERTICE *));
    if (Grafo->Mat == NULL)
    {
        free(Grafo);
        return NULL;
    }

    // Aloca arestas
    for (i = 0; i < NVertices; i++)
    {
        Grafo->Mat[i] = (VERTICE *)calloc(NVertices, sizeof(VERTICE));
        // Se a alocação foi mal sucedida;
        if (Grafo->Mat[i] == NULL)
        {
            for (k = 0; k < i; k++)
                free(Grafo->Mat[k]);
            free(Grafo);
            return NULL;
        }
    }
    Grafo->NumVertices = 0;
    Grafo->NumArestas = 0;
    Grafo->tamanho = NVertices;
    return Grafo;
}

// INSERE VERTICE
int inserirVertice(TipoGrafo *G, APRENDIZADO *dados)
{
    // Grafo não existe
    if (G == NULL)
    {
        printf("Grafo não existe\n");
        return -1;
    }
    // Se o grafo está cheio
    if (G->NumVertices == G->tamanho)
    {
        // Novo tamanho do Grafo
        int novoTam = G->tamanho + 1;

        // Salvo as informações antigas no vetor temp;
        VERTICE temp[100][100] = {0};
        for (int i = 0; i < G->NumVertices; i++)
        {
            for (int k = 0; k < G->NumVertices; k++)
            {
                temp[i][k].aprendizado = G->Mat[i][k].aprendizado;
                temp[i][k].peso = G->Mat[i][k].peso;
            }
        }

        VERTICE **aux;

        // Realoca vertices;
        aux = (VERTICE **)realloc(G->Mat, novoTam * sizeof(VERTICE *));
        if (aux == NULL)
        {
            free(aux);
            return -1;
        }
        // O grafo antigo aponta para o novo aux
        G->Mat = aux;

        // Realoca arestas
        for (int i = 0; i < novoTam; i++)
        {
            aux[i] = (VERTICE *)calloc(novoTam, sizeof(VERTICE *));
            // Se a alocação foi mal sucedida;
            if (G->Mat[i] == NULL)
            {
                for (int k = 0; k < i; k++)
                    free(G->Mat[k]);
                free(G);
                return -1;
            }
            // Se foi bem sucedida
            else
            {
                // Atribuimos as arestas
                for (int k = 0; k < G->NumVertices; k++)
                    aux[i][k] = temp[i][k];
            }
        }

        // Novo tamanho do Grafo
        G->tamanho = novoTam;
    }

    // Inserimos o novo vértice na ultima posição usada da matrix
    int posicao = G->NumVertices;
    G->Mat[posicao][posicao].aprendizado = dados;
    G->NumVertices++;

    return 0;
}

int removeVertice(TipoGrafo *G, int posicao)
{
    // Grafo não existe
    if (G == NULL)
    {
        printf("Grafo não existe\n");
        return -1;
    }

    // Se o vertice não existe
    if (posicao < 0 || posicao > G->NumVertices)
        return -1;

    G->Mat[posicao][posicao].aprendizado = NULL;
    G->Mat[posicao][posicao].peso = 0;

    for (int i = 0; i < G->NumVertices; i++)
    {
        G->Mat[i][posicao].peso = 0;
        G->Mat[posicao][i].peso = 0;
    }
    return 0;
}

// INSERE ARESTA
int inserirAresta(TipoGrafo *G, int v1, int v2, int peso)
{
    // Grafo não existe
    if (G == NULL)
    {
        printf("Grafo não existe\n");
        return -1;
    }

    // Intervalo é invalido
    if (v1 < 0 || v1 >= G->NumVertices || v2 < 0 || v2 >= G->NumVertices)
    {
        printf("Intervalo inválido\n");
        return -1;
    }

    if (G->Mat[v1][v2].peso == 0)
    {
        G->Mat[v1][v2].peso = peso;
        G->NumArestas++;
    }
    return 1;
}

// REMOVE ARESTA
int retirarAresta(TipoGrafo *G, int v1, int v2)
{
    // Grafo não existe
    if (G == NULL)
    {
        printf("Grafo não existe\n");
        return -1;
    }

    // Intervalo é invalido
    if (v1 < 0 || v1 >= G->NumVertices || v2 < 0 || v2 >= G->NumVertices)
    {
        printf("Intervalo inválido\n");
        return -1;
    }

    // Aresta não existe
    if (G->Mat[v1][v2].peso == 0)
    {
        printf("Aresta não existe\n");
        return 0;
    }

    // Remove aresta
    G->Mat[v1][v2].peso = 0;
    G->NumArestas--;
    return 1;
}

// EXIBE GRAFO
void exibirGrafo(TipoGrafo *G)
{
    int v = 0, w = 0;
    printf("\nGrafo - Resumo:\n");
    for (v = 0; v < G->NumVertices; ++v)
    {
        if (G->Mat[v][v].aprendizado != NULL)
        {
            printf("%d - %s", v, G->Mat[v][v].aprendizado->nome);
            for (w = 0; w < G->NumVertices; ++w)
                if (G->Mat[v][w].peso != 0)
                    printf("   Ligado a %s", G->Mat[w][w].aprendizado->nome);
            printf("\n");
        }
    }
}

// EXIBE MATRIZ
void exibirMatriz(TipoGrafo *G)
{
    printf("\nGrafo - Matriz:\n");

    // Printamos as colunas
    printf("     ");
    for (int j = 0; j < G->NumVertices; j++)
    {
        if (G->Mat[j][j].aprendizado != NULL)
            printf(" %d ", j);
    }
    printf("\n");

    // Printamos as linhas e os pesos
    for (int i = 0; i < G->NumVertices; ++i)
    {
        if (G->Mat[i][i].aprendizado != NULL)
        {
            printf("%d:   ", i);
            for (int j = 0; j < G->NumVertices; ++j)
                if (G->Mat[j][j].aprendizado != NULL)
                    printf(" %d ", G->Mat[i][j].peso);
            printf("\n");
        }
    }
}

// LIBERA GRAFO
TipoGrafo *liberarGrafo(TipoGrafo *G)
{
    int i;
    if (G == NULL)
        return NULL;

    for (i = 0; i < G->tamanho; i++)
    {
        free(G->Mat[i]);
    }
    free(G->Mat);
    free(G);
    G = NULL;
    return G;
}

// Caminho Mais Curto
int *caminhoMaisCurto(TipoGrafo *G, int origem)
{
    int i, v, w, minimo, posmin, S;
    int *M, *L;

    M = (int *)malloc(G->NumVertices * sizeof(int));
    L = (int *)malloc(G->NumVertices * sizeof(int));

    // preenchimento preliminar dos vetores
    for (i = 0; i < G->NumVertices; i++)
    {
        M[i] = 0;      // falso, vértice não visitado
        L[i] = 999999; // valor inicial para os custos
    }

    M[origem] = 1;
    for (v = 0; v < G->NumVertices; v++)
    {
        if (G->Mat[origem][v].peso != 0)
        {
            L[v] = G->Mat[origem][v].peso;
        }
    }

    for (i = 0; i < G->NumVertices; i++)
    {
        w = 0;
        minimo = 999999;
        for (v = 0; v < G->NumVertices; v++)
        {
            if (L[v] < minimo && M[v] == 0)
            {
                minimo = L[v];
                posmin = v;
                w = 1;
            }
        }
        if (w == 0)
            break;
        M[posmin] = 1;
        for (v = 0; v < G->NumVertices; v++)
        {
            if (G->Mat[posmin][v].peso != 0 && M[v] == 0)
            {
                S = L[posmin] + G->Mat[posmin][v].peso;
                if (S < L[v])
                    L[v] = S;
            }
        }
    }
    return L;
}

// EXIBE CAMINHO
void exibeCaminho(TipoGrafo *G, int origem)
{
    if (G == NULL)
        return;

    int *L = caminhoMaisCurto(G, origem);

    printf("\nMenor caminho partindo de %d: \n", origem);
    for (int v = 0; v < G->NumVertices; v++)
    {
        if (L[v] == 999999)
            printf("%d: - \n", v);
        else
            printf("%d: %d\n", v, L[v]);
    }
}

// CAMINHO
void caminho(TipoGrafo *G, int origem, int destino)
{
    if (G == NULL)
        return;

    int *vetor = caminhoMaisCurto(G, origem);

    if (vetor[destino] != 999999)
        printf("Há um caminho entre %d e %d\n", origem, destino);
    else
        printf("Não há um caminho entre %d e %d\n", origem, destino);

    return;
}

// GRAU VERTICE
int grauVertice(TipoGrafo *G, int vertice)
{
    if (G == NULL)
        return 0;

    int grau = 0;
    for (int i = 0; i < G->NumVertices; i++)
    {
        grau += G->Mat[vertice][i].peso + G->Mat[i][vertice].peso;
    }

    return grau;
}

// MAIOR GRAU
int maiorGrau(TipoGrafo *G)
{
    if (G == NULL)
        return 0;

    int maior = 0, cont = 0;
    for (int i = 0; i < G->NumVertices; i++)
    {
        int valor = grauVertice(G, i);
        if (valor > maior)
        {
            cont = i;
            maior = valor;
        }
    }
    printf("O vértice de maior grau é %d com peso: %d\n", cont, maior);

    return cont;
}

// BUSCA EM PROFUNDIDADE
void dfs(int origem, bool *visitados, TipoGrafo *G)
{
    printf("%d ", origem);
    visitados[origem] = true;

    for (int i = 0; i < G->NumVertices; i++)
    {
        if (G->Mat[origem][i].peso != 0 && (!visitados[i]))
        {
            dfs(i, visitados, G);
        }
    }
}

void BuscaEmProfundidade(TipoGrafo *G, int origem)
{
    bool *visitados;
    visitados = (bool *)malloc(G->NumVertices * sizeof(bool));
    if (visitados == NULL)
        return;

    int cont = 0;
    dfs(origem, visitados, G);
}

// CONEXOES
void inserePilha(TipoGrafo *G, bool *visitados, TipoPilha *pilha, int vertice)
{
    visitados[vertice] = true;
    int i = 0;

    for (int i = 0; i < G->NumVertices; i++)
    {
        int posicao = G->Mat[vertice][i].peso;
        if ((!visitados[i]) && (posicao != 0))
        {
            inserePilha(G, visitados, pilha, posicao);
        }
    }
    Empilha(vertice, pilha);
}

void transposta(TipoGrafo *G)
{
    int tam = G->NumVertices;

    int aux[tam][tam];

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            aux[j][i] = G->Mat[i][j].peso;
        }
    }
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            G->Mat[i][j].peso = aux[i][j];
        }
    }
}

void conexoesFortes(TipoGrafo *G)
{
    int tam = G->NumVertices;
    bool visitados[tam];

    TipoPilha *pilha;
    // Iniciar a pilha e inserir o vértice de origem
    pilha = (TipoPilha *)malloc(sizeof(TipoPilha));
    if (pilha == NULL)
        return;
    IniciaPilha(pilha);

    for (int i = 0; i < tam; i++)
        visitados[i] = false;

    for (int i = 0; i < tam; i++)
    {
        if (visitados[i] == false)
        {
            inserePilha(G, visitados, pilha, i);
        }
    }
    int count = 1;
    for (int i = 0; i < tam; i++)
        visitados[i] = false;

    transposta(G);

    while (!VaziaPilha(pilha))
    {
        int v = Desempilha(pilha);

        if (visitados[v] == false)
        {
            printf("Componentes fortemente conectados %d: \n", count++);
            dfs(v, visitados, G);
            printf("\n");
        }
    }
    transposta(G);

    free(pilha);
}
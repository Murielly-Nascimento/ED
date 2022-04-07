#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TAD_AVL.h"

#define MAX 50

const char *filename = "francais.txt";
const char *fileIndice = "indice.txt";

void escreve(ArvAVL *raiz, FILE *arq)
{
    if (raiz == NULL)
        return;
    if (*raiz != NULL)
    {
        escreve(&((*raiz)->esq), arq);

        // Escreve a palavra no arquivo
        fprintf(arq, "%s ", (*raiz)->palavra);

        // Percorre a lista de linhas em que a palavra aparece
        for (int i = 0; i < (*raiz)->pos; i++)
        {
            char linha[MAX] = {'\0'};
            snprintf(linha, MAX, "%d", (*raiz)->linha[i]);
            fprintf(arq, "%s ", linha);
        }
        fprintf(arq, "\n");
        escreve(&((*raiz)->dir), arq);
    }
}

int arqIndice(ArvAVL *avl, int NroPalavra, clock_t time)
{

    char total[MAX] = {'\0'};
    char distintas[MAX] = {'\0'};

    // Abre arquivo índice
    FILE *indice = fopen(fileIndice, "w");

    // Cabeçalho do arquivo
    fprintf(indice, "------------------\n");
    fprintf(indice, "Índice:\n");

    // Escreve dados da árvore para o arquivo
    escreve(avl, indice);

    // Número de palavras total
    snprintf(total, MAX, "%d", NroPalavra);
    fprintf(indice, "Número total de palavras:%s\n", total);

    // Número de palavras distintas
    NroPalavra = totalNO_ArvAVL(avl);
    snprintf(distintas, MAX, "%d", NroPalavra);
    fprintf(indice, "Número de palavras distintas:%s\n", distintas);

    // Calcula o tempo levado para realizar esse programa
    clock_t tempo = clock() - time;
    double tempo_total = ((double)tempo) / CLOCKS_PER_SEC;
    char segundos[MAX] = {'\0'};
    snprintf(segundos, MAX, "%lf", tempo_total);

    fprintf(indice, "Tempo de construção do índice usando árvore AVL: %s segundos\n", segundos);

    // Fechamos o arquivo
    fclose(indice);
}

int insere(ArvAVL *avl)
{
    // Abre arquivo
    FILE *arq = fopen(filename, "r");
    char *conteudo_linha = malloc(MAX);
    char *palavra = malloc(MAX);
    int linha = 1;
    int Nropalavra = 0;

    // Le arquivo e preenche arvore
    while (fscanf(arq, "%[^\n] ", conteudo_linha) != EOF)
    {
        palavra = strtok(conteudo_linha, " ,.;!?/");
        while (palavra != NULL)
        {
            insere_ArvAVL(avl, palavra, linha);
            palavra = strtok(NULL, " ,.;!?/");
            Nropalavra++;
        }
        linha++;
    }
    fclose(arq);

    return Nropalavra;
}

int main(int argc, char *argv[])
{
    clock_t time;
    time = clock();

    // Cria arvore
    ArvAVL *avl;
    avl = cria_ArvAVL();

    // Inserimos dados do arquivo na árvore
    int Nropalavra = insere(avl);

    // Criamos o arquivo índice
    arqIndice(avl, Nropalavra, time);

    // Finalizamos o programa
    libera_ArvAVL(avl);
    printf("Indice Remissivo criado com sucesso!\n");
    return 0;
}
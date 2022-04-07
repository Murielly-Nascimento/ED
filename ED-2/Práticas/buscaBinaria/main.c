#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TAD_File.h"

void shellsort(DICIONARIO dados[], int n)
{
    int i = 0, j = 0, h = 1;
    DICIONARIO aux;

    do
    {
        h = h * 3 + 1;
    } while (h < n);

    do
    {
        h /= 3;
        for (i = h; i < n; i++)
        {
            aux = dados[i];
            j = i;
            while (strcmp(dados[j - h].termo, aux.termo) > 0)
            {
                dados[j] = dados[j - h];
                j -= h;
                if (j < h)
                    break;
            }
            dados[j] = aux;
        }
    } while (h != 1);
}

int busca_binaria(DICIONARIO dados[], char elemento[], int esq, int dir)
{
    int meio = 0;
    meio = (esq + dir) / 2;

    if (esq > dir)
        return -1;

    if (strcmp(dados[meio].termo, elemento) == 0)
        return meio;

    else if (strcmp(dados[meio].termo, elemento) > 0)
    {
        dir = meio - 1;
        busca_binaria(dados, elemento, esq, dir);
    }
    else if (strcmp(dados[meio].termo, elemento) < 0)
    {
        esq = meio + 1;
        busca_binaria(dados, elemento, esq, dir);
    }
}

int main(void)
{
    // Dados são passados para a estrutura DICIONARIO
    char nome[] = "dados.txt"; // nome do arquivo
    int tamanho = 0;           // tamanho do arquivo

    DICIONARIO *dados = open_txt(nome, &tamanho);
    DICIONARIO *iterator = dados;

    shellsort(dados, tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        printf("%s\n", iterator->termo);
        iterator++;
    }

    printf("Digite um termo: ");
    char elemento[100] = {'\0'};
    scanf("%s", elemento);

    int pos = busca_binaria(dados, elemento, 0, tamanho - 1);
    if (pos == -1)
        printf("Termo não encontrado\n");
    else
    {
        printf("\nPalavra encontrada!\n");
        printf("Termo: %s\n", dados[pos].termo);
        printf("Classificação: %s\n", dados[pos].termo);
        printf("Significado:%s\n", dados[pos].significado);
    }
    free(dados);
    return 0;
}
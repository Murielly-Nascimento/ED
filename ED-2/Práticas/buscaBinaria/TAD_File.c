#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TAD_File.h"

DICIONARIO *open_txt(char *nome, int *tamanho)
{
    // O arquivo txt já deve existir e portanto faremos apenas uma leitura
    FILE *dados = fopen(nome, "r");

    // Descobrimos quantas linhas e colunas o arquivo têm
    char caracter = '\0';
    int i = 0, j = 0;

    while (caracter != EOF)
    {
        caracter = fgetc(dados);
        if (caracter == '\n')
            i++;
    }

    // Voltamos o ponteiro para o início
    rewind(dados);

    // Linhas é a quantidade de '\n' no arquivo
    int linhas = i;
    *tamanho = (linhas + 1) / 3;

    // Criamos o vetor com os dados de aprendizagem
    DICIONARIO *vetor = malloc((*tamanho) * sizeof(DICIONARIO));

    if (vetor == NULL)
        return NULL;

    char aux[MAX] = {'\0'};

    // Lemos os dados do arquivo e armazenamos no vetor
    for (int i = 0; i < (*tamanho); i++)
    {
        fgets(aux, MAX, dados);
        aux[strcspn(aux, "\n")] = 0; // Remove "\n" da string
        strcpy(vetor[i].termo, aux);

        fgets(aux, MAX, dados);
        aux[strcspn(aux, "\n")] = 0;
        strcpy(vetor[i].classificao, aux);

        fgets(aux, MAX, dados);
        aux[strcspn(aux, "\n")] = 0;
        strcpy(vetor[i].significado, aux);
    }

    // Fechamos o arquivo e liberamos a estrutura que lida com ele
    fclose(dados);

    // A função retorna o vetor preenchido com dados
    return vetor;
}
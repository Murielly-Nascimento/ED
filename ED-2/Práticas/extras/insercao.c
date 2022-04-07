/*
1. Mantemos os elementos entre zero e i-1 ordenados.
2. Achamos a posição do i-ésimo elemento e inserimos ele entre os i-1 que já estavam ordenados.
3. O programa repete esse passo até ordenar todos os elementos.
*/

#include <stdio.h>

void ordInsercao(int *v, int n, int k)
{
    int i = 0, j = 0;
    int aux;
    for (i = 1; i < k; i++)
    {
        //Seleciona um valor na posição i
        aux = v[i];
        //j é um contador
        j = i - 1;
        //Enquanto j <=0 e aux for menor que v[j] movemos os valores
        while ((j >= 0) && (aux < v[j]))
        {
            v[j + 1] = v[j];
            j--;
        }
        //Adicionamos aux na posição i
        v[j + 1] = aux;
    }
    //Note que ele verifica se o vetor está organizado na primeira passagem
    return;
}

int main(void)
{
    int v[] = {6, 5, 4, 3, 2, 1};
    int n = 6;

    ordInsercao(v, n, 3);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
/*6) Escreva um algoritmo que dada uma matriz 3x3, ele calcula a soma de cada linha e a
soma de cada coluna. Mostre a matriz e o resultado das somas*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int A[3][3] = {0}, linha[3] = {0},coluna[3]={0},aux=0;
    srand (time(NULL));
    printf("Preenchendo A com valores aleatórios:\n");
    for(int i=0; i<3 ;i++){
        for(int j=0 ;j<3; j++){
            A[i][j] = (rand()/(double)RAND_MAX)*100;
            aux+=A[i][j];
        }
        linha[i] = aux;
        printf("A soma da linha %d é %d\n",i,linha[i]);
        aux = 0;
    }
    for(int i = 0 ;i<3; i++){
        for(int j=0 ;j<3; j++){
            aux+= A[j][i];
        }
        coluna[i] = aux;
        printf("A soma da coluna %d é %d\n",i,coluna[i]);
        aux = 0;
    }

    return 0;
}
/*4) Faça um algoritmo para ler uma matriz 5x8 e mostrar o menor valor e a sua posição
(linha, coluna)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int A[5][8] = {0}, menor = 0, linha = 0, coluna = 0;
    srand (time(NULL));
    printf("Preenchendo A com valores aleatórios:\n");
    for(int i=0; i<5 ;i++){
        for(int j=0 ;j<8; j++){
            A[i][j] = (rand()/(double)RAND_MAX)*100;
            if(A[i][j] < menor || (i == 0 && j == 0)){
                menor  = A[i][j];
                linha = i;
                coluna = j;
            }
            
        }
    }
    printf("O menor valor é %d que está na %d linha e %d coluna\n",menor,linha,coluna);

    return 0;
}
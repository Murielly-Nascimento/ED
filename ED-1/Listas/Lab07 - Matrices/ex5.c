/*5) Faça um algoritmo para calcular a soma da diagonal principal de uma matriz 5x5*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int A[5][5] = {0}, diagonal = 0;
    srand (time(NULL));
    printf("Preenchendo A com valores aleatórios:\n");
    for(int i=0; i<5 ;i++){
        for(int j=0 ;j<5; j++){
            A[i][j] = (rand()/(double)RAND_MAX)*100;
            if(i == j)
                diagonal  += A[i][j];
        }
    }
    printf("A soma da diagonal é %d\n",diagonal);

    return 0;
}
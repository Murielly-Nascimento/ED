/*3) Faça um programa para multiplicar uma matriz 3x4 por uma 4x5*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int A[3][4] = {0}, B[4][5] = {0}, C[3][5] = {0};
    srand (time(NULL));

    printf("Preenchendo A e B com valores aleatórios:\n");
    for(int i=0; i<3 ;i++){
        for(int j=0 ;j<4; j++){
            A[i][j] = (rand()/(double)RAND_MAX)*100;
        }
    }
    for(int i=0; i<4 ;i++){
        for(int j=0 ;j<5; j++){
            B[i][j] = (rand()/(double)RAND_MAX)*100;
        }
    }

    for(int i=0; i<3 ;i++){
        for(int j=0 ;j<5; j++){
            int aux = 0;
            for(int x = 0 ;x<4; x++){
                aux += A[i][x] * B[x][j];
            }
            C[i][j] = aux;
            printf("C[%d][%d] = %d      ",i,j,C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
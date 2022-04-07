/*2) Faça um programa para multiplicar duas matrizes 3x3*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int A[3][3] = {0}, B[3][3] = {0}, C[3][3] = {0};

    for(int i=0; i<3 ;i++){
        for(int j=0 ;j<3; j++){
            int valor = 0;
            printf("Digite um valor: ");
            scanf("%d",&valor);
            A[i][j] = valor;
            B[i][j] = valor;
            printf("A[%d][%d] = %d      B[%d][%d] = %d\n",i,j,A[i][j],i,j,B[i][j]);
        }
    }

    for(int i=0; i<3 ;i++){
        for(int j=0 ;j<3; j++){
            int aux = 0;
            for(int x = 0 ;x<3; x++){
                aux += A[i][x] * B[x][j];
            }
            C[i][j] = aux;
            printf("C[%d][%d] = %d      ",i,j,C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
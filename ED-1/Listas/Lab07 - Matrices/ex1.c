/*1) Faça um programa que realiza a soma de matrizes. O usuário deve entrar com duas
matrizes 4x4. Mostre o resultado da soma*/

#include<stdio.h>
#include <stdlib.h>

int main(void){

    int mat1[4][4]={0};
    int mat2[4][4]={0};

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            mat1[i][j] = (rand()/(double)RAND_MAX)*100;
            mat2[i][j] = (rand()/(double)RAND_MAX)*100;
            printf("mat1[%d][%d] + mat2[%d][%d] = %d\n",i,j,i,j,mat1[i][j] + mat2[i][j]);
        }
    }

    return 0;
}
/*8) Faça um algoritmo que lê uma matriz 6x6 e soma os valores das partes hachuradas.
Escreva a matriz e a soma das partes calculadas.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int x;
    int y;
}PONTOS;

int main(void){
    int A[6][6] = {0},area_superior_direita = 0, area_superior_esquerda=0;
    PONTOS diagonal_principal[6], diagonal_secundaria[6]={0};
    srand (time(NULL));
    printf("Preenchendo A com valores aleatórios:\n");
    for(int i=0; i<6 ;i++){
        for(int j=0 ;j<6; j++){
            A[i][j] = (rand()/(double)RAND_MAX)*100;
            if(i == j){
                diagonal_principal[i].x = i;
                diagonal_principal[i].y = j;
            }
            if(i+j == 6+1){
                diagonal_secundaria[i].x = i;
                diagonal_secundaria[i].y = j;
            }
        }
    }
    for(int i = 0 ;i<6; i++){
        for(int j=0 ;j<6; j++){
            if(i>=diagonal_principal[i].x && j>diagonal_principal[i].y){
                area_superior_direita +=A[i][j];
            }
            if(i<=diagonal_principal[i].x && j<diagonal_principal[i].y){
                area_superior_esquerda +=A[i][j];
            }
        }
    }

    printf("A soma da area superior a diagonal principal é %d\n",area_superior_direita);
    printf("A soma da area superior a diagonal secundária é %d\n",area_superior_esquerda);

    return 0;
}
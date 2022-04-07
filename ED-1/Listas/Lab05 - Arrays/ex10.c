/*10) Faça um programa que receba do usuário dois arrays A e B, com 3 números inteiros
cada. Crie um novo array C calculando C = A - B. Mostre na tela os dados do array C.*/

#include<stdio.h>

int main(void){
    int A[3]={0}, B[3]={0},C[3]={0};
    printf("<< Subtração de vetores >>\n");

    for(int i=0;i<3;i++){
        printf("Digite o valor %d de A: ",i+1);
        scanf("%d",&A[i]);
    }
    printf("\n");
    for(int i=0;i<3;i++){
        printf("Digite o valor %d de B: ",i+1);
        scanf("%d",&B[i]);
    }
    printf("\nO vetor C, definido como C = A-B é (");
    for(int i=0;i<2;i++){
        C[i] = A[i] - B[i];
        printf("%d, ",C[i]);
    }
    C[2] = A[2] - B[2];
    printf("%d)\n",C[2]);
    return 0;
}
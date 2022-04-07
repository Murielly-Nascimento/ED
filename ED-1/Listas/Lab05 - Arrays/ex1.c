/*1) Crie um programa que lê 6 valores e em seguida mostra na tela os valores lidos. Não
utilize loops e utilize vetores para armazenar os números.*/

#include<stdio.h>

int main(void){
    int vetor[6]={0};
    
    printf("<< Listando um vetor >>\n");
    printf("Entre com o número 1:");
    scanf("%d",&vetor[0]);
    printf("Entre com o número 2:");
    scanf("%d",&vetor[1]);
    printf("Entre com o número 3:");
    scanf("%d",&vetor[2]);
    printf("Entre com o número 4:");
    scanf("%d",&vetor[3]);
    printf("Entre com o número 5:");
    scanf("%d",&vetor[4]);
    printf("Entre com o número 6:");
    scanf("%d",&vetor[5]);

    printf("Os valores lidos são: %d %d %d %d %d %d\n",vetor[0],vetor[1],vetor[2],vetor[3],vetor[4],vetor[5]);
    return 0;
}
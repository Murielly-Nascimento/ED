/*
3) Ler um número e retorne seu antecessor e seu sucessor.
*/

#include<stdio.h>

int main(void){
    printf("Digite um número:");
    int A = 0 ,B = 0, C = 0;
    scanf("%d",&A);
    
    B = A-1;
    C = A+1;
    printf("O antecessor de %d é %d e o seu sucessor é %d\n",A,B,C);
    return 0;
}

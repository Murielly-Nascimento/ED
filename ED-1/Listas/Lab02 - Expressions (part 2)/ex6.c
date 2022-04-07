/*6) Faça um algoritmo que leia o valor de duas variáveis A e B e troque os valores dessas
variáveis.*/

#include<stdio.h>

int main(void){
    int A=0, B=0, aux=0;
    printf("== Troca do conteúdo de variáveis ==\n");
    printf("Entre com o valor de A:");
    scanf("%d",&A);
    printf("Entre com o valor de B:");
    scanf("%d",&B);
    
    aux = A;
    A = B;
    B = aux;

    printf("Após a troca, o valor de A é %d e o de B é %d\n", A, B);
    return 0;
}
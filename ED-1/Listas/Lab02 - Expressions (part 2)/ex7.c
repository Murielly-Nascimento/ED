/*7) Faça um algoritmo que mostre o funcionamento dos operadores lógicos. Peça para o
usuário entrar com dois valores inteiros,, onde 0 implica em FALSO e qualquer outro
número implica em VERDADEIRO.*/

#include<stdio.h>

int main(void){
    int A=0, B=0;
    printf("== Operadores Booleanos ==\n");
    printf("Digite 0 para falso e não 0 para verdadeiro\n");
    printf("Entre com o primeiro valor (A):");
    scanf("%d",&A);
    printf("Entre com o segundo valor (B):");
    scanf("%d",&B);

    printf("A and B: ");
    if(A!=0 && B!=0) printf("1\n");
    else printf("0\n");
    
    printf("A or B: ");
    if(A==0 && B==0) printf("0\n");
    else printf("1\n");

    printf("A xor B: ");
    if((A==0 && B==0) || (A!=0 && B!=0)) printf("0\n");
    else printf("1\n");

    printf("not A: ");
    if(A==0)printf("1\n");
    else printf("0\n");
    return 0;
}
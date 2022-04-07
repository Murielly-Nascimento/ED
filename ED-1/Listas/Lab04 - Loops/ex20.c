/*20) Escreva um programa que leia um numero inteiro positivo n e em seguida imprima n
linhas do chamado Triangulo de Floyd:*/

#include<stdio.h>

int main(void){
    int n=0,a=1;
    printf("<< Triangulo de Floyd >>\n");
    printf("Digite o número de linhas: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",a);
            a++;
        }
        printf("\n");
    }
    return 0;
}
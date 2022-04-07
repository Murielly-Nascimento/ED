/*10) Dado um número inteiro positivo n, calcular a soma dos n primeiros números naturais (faça a soma
utilizando while .*/

#include<stdio.h>

int main(void){
    int n=0,soma=0,i=1;
    printf("<< Soma de n valores naturais >>\n");
    printf("Quantos números deseja somar?");
    scanf("%d",&n);
    while(i<=n){
        soma+=i;
        i++;
    }
    printf("A soma dos %d primeiros números naturais é: ]%d\n",n,soma);
    return 0;
}
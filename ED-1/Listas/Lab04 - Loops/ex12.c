/*12) Refaça o exercício anterior utilizando o comando for*/

#include<stdio.h>

int main(void){
    int n=0,soma=0;
    printf("<< Soma de n valores naturais >>\n");
    printf("Quantos números deseja somar?");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        soma+=i;
    printf("A soma dos %d primeiros números naturais é: %d\n",n,soma);
    return 0;
}
/*11) Refaça o exercício anterior utilizando o comando do .. while;*/

#include<stdio.h>

int main(void){
    int n=0,soma=0,i=1;
    printf("<< Soma de n valores naturais >>\n");
    printf("Quantos números deseja somar?");
    scanf("%d",&n);
    do{
        soma+=i;
        i++;
    }while(i<=n);
    printf("A soma dos %d primeiros números naturais é: %d\n",n,soma);
    return 0;
}
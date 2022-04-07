/*6) Refaça o exercício anterior utilizando o comando for*/

#include<stdio.h>

int main(void){
    int i=0;
    printf("<< Contagem regressiva >>\n");
    printf("Qual é o número inicial?");
    scanf("%d",&i);
    for(;i>=0;i--) 
        printf("%d..",i);
    printf("FIM!\n");
    return 0;
}
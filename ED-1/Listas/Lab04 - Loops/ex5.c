/*5) Refaça o exercício anterior utilizando o comando do .. while;*/

#include<stdio.h>

int main(void){
    int i=0;
    printf("<< Contagem regressiva >>\n");
    printf("Qual é o número inicial?");
    scanf("%d",&i);
   do{
        printf("%d..",i);
        i--;
    } while(i>=0);
    printf("FIM!\n");
    return 0;
}
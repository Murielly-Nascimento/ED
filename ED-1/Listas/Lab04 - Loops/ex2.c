/*2) Refaça o exercício anterior utilizando o comando do .. while;*/

#include<stdio.h>

int main(void){
    int i=10;
    printf("<< Contagem regressiva >>\n");
   do{
        printf("%d..",i);
        i--;
    } while(i>=0);
    printf("FIM!\n");
    return 0;
}
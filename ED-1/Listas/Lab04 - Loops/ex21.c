/*21) Faça um programa que mostre o valor de 1!, 2!, 3!, até 10!. Utilize somente variáveis inteiras*/

#include<stdio.h>

int main(void){
    int fat=1;
    printf("<< Fatorial >>\n");
    for(int i=1;i<=10;i++){
        for(int j=1;j<=i;j++){
            fat*=j;
        }
        printf("%d! = %d\n",i,fat);
        fat=1;
    }
    return 0;
}
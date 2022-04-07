#include<stdio.h>

int main(void){

    char nome[] = {"José Augusto"};
    char *pnome=&nome;
    for(int i=0;i<13;i++)
        printf("%c",*(pnome+i));
    printf("\n");
    return 0;
}
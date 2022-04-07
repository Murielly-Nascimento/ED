/*1)Monte um programa que mostra os valores e os caracteres correspondentes da tabela
ASCII, para valores de 32 à 126. Mostrar 7 caracteres por linha. Para padronização,
utilize três caracteres para representar o valor numérico, separe o número da letra
com espaço, e dada par número/letra com tabulação (/t)*/

#include<stdio.h>

int main(void){
    int ASCII[95]={0};
    for(int i=32,j=0;i<=126;i++){ 
        ASCII[j]=i;
        printf("%d %c   ",ASCII[j],ASCII[j]);
        j++;
        if(j%7==0) printf("\n");
    }
    printf("\n");
    return 0;
}
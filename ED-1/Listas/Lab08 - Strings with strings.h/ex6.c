/*6) Faça um programa que mostre as letras de uma string separadamente.*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    char nome[51]={'\0'};
    int tamanho = 0;
    printf("<< Separa letras>>\n");
    printf("Digite o nome : ");
    gets(nome);
    tamanho = strlen(nome);
    for(int i=0;i<tamanho;i++) printf("%da letra: %c\n",i+1,nome[i]);
    return 0;
}
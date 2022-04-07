/*3) Faça um programa em que o usuário digita dois nomes, e o programa informa se os
nomes são iguais. Use strcmp.*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    char nome[51]={'\0'},nome2[51]={'\0'};
    int tamanho=0;
    
    printf("<< Compara nomes>>\n");
    printf("Digite um nome: ");
    gets(nome);
    printf("Digite um nome: ");
    setbuf(stdin,NULL);
    gets(nome2);
    
   if (strcmp(nome,nome2) == 0) printf("Os nomes digitados são iguais\n");
   else printf("Os nomes digitados são diferentes\n");
   
    return 0;
}
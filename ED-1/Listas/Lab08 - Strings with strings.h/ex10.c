/*10) Faça um programa que dado uma string, imprima se ela for palíndromo ou não.
Lembrando que: Um palíndromo é uma palavra que tem a propriedade de poder ser
lida tanto da direita para a esquerda como da esquerda para a direita.*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    char str[51]={'\0'},invertida[51]={'\0'};
    int tamanho=0;
    printf("<<Palindromo>>\n");
    printf("Digite a string : ");
    gets(str);
    tamanho = strlen(str);
    for(int i=tamanho-1,j=0;i>=0;i--,j++) invertida[j]=str[i];
    if(strcmp(str,invertida)==0) printf("É palindromo\n");
    else printf("Não é palindromo\n");
    return 0;
}
/*2) Faça um programa semelhante ao anterior, só que o nome digitado deve ser mostrado
em letras maiúsculas e também em minúsculas. Procure em string.h uma função que
faça a conversão*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    char nome[51]={'\0'},minusculo[51]={'\0'},maiusculo[51]={'\0'};
    int tamanho=0;
    
    printf("<< Vetor de Char>>\n");
    printf("Digite um nome: ");
    gets(nome);
    
    tamanho = strlen(nome);
    for(int i=0;i<tamanho;i++){
        minusculo[i]=tolower(nome[i]);
        maiusculo[i]=toupper(nome[i]);
    }
    printf("O nome digitado é: %s\n",maiusculo);
    printf("O nome digitado é: %s\n",minusculo);
   
    return 0;
}
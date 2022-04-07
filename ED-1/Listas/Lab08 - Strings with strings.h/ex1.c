/*1) Utilizando strings, crie um programa que leia o nome de uma pessoa e, em seguida,
mostre o nome lido. O nome pode ter no máximo 50 caracteres. Use a função gets()
para efetuar a leitura*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    char nome[51]={'\0'};
    printf("<< Vetor de Char>>\n");
    printf("Digite um nome: ");
    setbuf(stdin,NULL);
    gets(nome);
    printf("O nome digitado é: %s\n",nome);
    return 0;
}
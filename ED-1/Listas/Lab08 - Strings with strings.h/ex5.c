/*5) Faça um programa que recebe o nome e sobrenome de uma pessoa (máximo 40
caracteres), copie o nome para um vetor e o sobrenome para outro. Mostre os dois
vetores copiados.*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    char nome[41]={'\0'},nome1[21]={'\0'},sobrenome[21]={'\0'};
    int tamanho=0,aux=0;
    printf("<< Vetor de Char>>\n");
    printf("Digite um nome e sobrenome: ");
    gets(nome);
    tamanho=strlen(nome);
    for(int i=0;i<tamanho;i++){
        if(nome[i]==' '){
            aux=i;
            break;
        }
    }
    strncpy(nome1,nome,aux);
    for(int i=aux+1,j=0;i<tamanho;i++,j++){
        sobrenome[j]=nome[i];
    }
    printf("Nome: %s\n",nome1);
    printf("Sobrenome: %s\n",sobrenome);
    return 0;
}
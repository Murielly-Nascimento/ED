/*2) Utilizando os conceitos aprendidos até o momento (vetores e tipo char), crie um
programa que leia o nome de uma pessoa e, em seguida, mostre o nome lido. Utilizar
getchar() para entrada dos dados (veja acima um exemplo de como usar o getchar()).
O nome pode ter no máximo 50 caracteres. Não usar as funções de string.h*/

#include<stdio.h>

int main(void){
    char nome[51]={'\0'}, letra = '\0';
    int i=0;

    printf("<< Vetor de char>>\n");
    printf("Digite um nome: ");
    letra = getchar();

    while(letra!='\n'){
        nome[i]=letra;
        i++;
        letra = getchar();
    }
    printf("O nome digitado é:");
    for(int j=0;j< i;j++) printf("%c",nome[j]);
    printf("\n");
    return 0;
}
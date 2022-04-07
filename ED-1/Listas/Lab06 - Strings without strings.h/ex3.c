/*3) Faça um programa semelhante ao anterior, só que o nome digitado deve ser mostrado
em letras maiúsculas (pense como fazer isso olhando a diferença entre os valores dos
caracteres minúsculos e maiúsculos na tabela ASCII). Não usar as funções de string.h*/

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
    for(int j=0;j< i;j++){
        if(nome[j]>=97) nome[j]-=32;
        printf("%c",nome[j]);
    }
    printf("\n");
    return 0;
}
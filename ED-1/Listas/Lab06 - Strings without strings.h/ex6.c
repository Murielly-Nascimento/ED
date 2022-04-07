/*6) Faça um programa que recebe o nome e sobrenome de uma pessoa (máximo 40
caracteres), copie o nome para um vetor e o sobrenome para outro. Mostre os dois
vetores copiados.*/

#include<stdio.h>

int main(void){
    char nomeSobrenome[41]={'\0'},nome[21]={'\0'},sobrenome[21]={'\0'}, letra = '\0';
    int i = 0,k = 0,w=0;

    printf("<< Nomes >>\n");
    printf("\nDigite o primeiro nome e último nome:");
    letra = getchar();

    while(letra!='\n'){
        nomeSobrenome[i]=letra;
        i++;
        letra = getchar();
    }
    printf("Nome: ");
    for(int j=0;j<i;j++){
        if(nomeSobrenome[j]==' '){
            w=j+1;
            break;
        }
        nome[j]=nomeSobrenome[j];
        printf("%c",nome[j]);
    }
    printf("\nSobrenome: ");
    for(int j=w;j<i;j++){
        sobrenome[j]=nomeSobrenome[j];
        printf("%c",sobrenome[j]);
    }
    printf("\n");
    return 0;
}
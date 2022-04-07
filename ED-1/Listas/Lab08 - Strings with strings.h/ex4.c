/*4) Refaça o exercício anterior, para que agora não haja diferenciação entre caracteres
maiúsculos e minúsculos.*/

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

    if(strlen(nome)==strlen(nome2)){
        tamanho = strlen(nome);
        for(int i=0;i<tamanho;i++){
            nome[i]=tolower(nome[i]);
            nome2[i]=tolower(nome[i]);
        }
        if (strcmp(nome,nome2) == 0) printf("Os nomes digitados são iguais\n");
        else printf("Os nomes digitados são diferentes\n");

    } else printf("Os nomes digitados são diferentes\n");
    
    return 0;
}
/*8) Faça um programa em que a pessoa entra com o seu nome, CPF, RG, endereço, CEP,
Cidade, Estado e o programa crie, automaticamente, uma carta de declaração (veja o
modelo abaixo)*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    char nome[51]={'\0'},cpf[15]={'\0'},rg[15]={'\0'};
    char endereco[51]={'\0'},cidade[15]={'\0'},estado[2]={'\0'},cep[15]={'\0'};

    printf("Digite seu nome: ");
    setbuf(stdin,NULL);
    gets(nome);
    printf("Digite seu CPF: ");
    setbuf(stdin,NULL);
    gets(cpf);
    printf("Digite seu RG: ");
    setbuf(stdin,NULL);
    gets(rg);
    printf("Digite seu endereço: ");
    setbuf(stdin,NULL);
    gets(endereco);
    printf("Digite a cidade: ");
    setbuf(stdin,NULL);
    gets(cidade);
    printf("Digite o estado: ");
    setbuf(stdin,NULL);
    gets(estado);
    printf("Digite o CEP: ");
    setbuf(stdin,NULL);
    gets(cep);

    printf("\nD E C L A R A Ç Ã O\n\n");
    printf("Eu, %s, RG %s, CPF %s,\n",nome,rg,cpf);
    printf("residente a %s, %s-%s,\n",endereco,cidade,estado);
    printf("CEP %s venho por meio desta declarar que vou estudar para a prova\n",cep);


    return 0;
}
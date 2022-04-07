/*1. Crie uma estrutura chamada telefone, que armazena o DDD e o telefone. Cadastre 3
telefones e mostre na tela os telefones cadastrados.*/

struct telefone{
    int DDD;
    int number;
};

#include<stdio.h>

int main(void){
    struct telefone numeros[3]={0};
    for(int i=0;i<3;i++){
        printf("Digite o DDD e o telefone %d: ",i+1);
        scanf("%d %d",&numeros[i].DDD,&numeros[i].number);
    }
    for(int i=0;i<3;i++){
        printf("O numero %d é: %d-%d\n",i+1,numeros[i].DDD,numeros[i].number);
    }

    return 0;
}
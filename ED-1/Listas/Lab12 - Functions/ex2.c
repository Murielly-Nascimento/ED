/*2) Altere o exercício anterior para que o procedimento aceite um argumento de quantos
sinais de igual serão mostrados. Ex: DesenhaLinha(4) tem como saída ====;
DesenhaLinha(10) tem como saída ==========. No programa principal execute várias
chamadas a esse procedimento (use um loop)*/

#include<stdio.h>

void DesenhaLinha(int quantidade);

void DesenhaLinha(int quantidade){
    for(int i=0;i<quantidade;i++)printf("=");
}

int main(void){
    int x=0;
    printf("Digite um número: ");
    scanf("%d",&x);

    for(int i=0;i<10;i++){
        DesenhaLinha(x);
        printf("\n");
    }
    return 0;
}
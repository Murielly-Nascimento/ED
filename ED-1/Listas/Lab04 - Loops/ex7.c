/*7) Faça um algoritmo utilizando o comando while que mostra uma contagem progressiva na tela,
iniciando em um valor que o usuário determina e terminando em 0. Mostrar uma mensagem “FIM!”
após a contagem.*/

#include<stdio.h>

int main(void){
    int i=0;
    printf("<< Contagem progressiva até 0 >>\n");
    printf("Qual é o número inicial?");
    scanf("%d",&i);
    while(i<=0){
        printf("%d..",i);
        i++;
    }
    printf("FIM!\n");
    return 0;
}
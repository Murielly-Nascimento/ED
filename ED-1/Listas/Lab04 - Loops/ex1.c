/*1) Faça um algoritmo utilizando o comando while que mostra uma contagem regressiva na tela,
iniciando em 10 e terminando em 0. Mostrar uma mensagem “FIM!” após a contagem.*/

#include<stdio.h>

int main(void){
    int i=10;
    printf("<< Contagem regressiva >>\n");
    while(i>=0){
        printf("%d..",i);
        i--;
    }
    printf("FIM!\n");
    return 0;
}
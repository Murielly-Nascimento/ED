/*1) Faça um procedimento chamado DesenhaLinha. Ele deve desenhar uma linha na tela
usando vários caracteres = (Ex: ========). No programa principal execute várias
chamadas a esse procedimento (use um loop)*/

#include<stdio.h>

void DesenhaLinha(void);

void DesenhaLinha(void){
    printf("\n===============================\n");
}

int main(void){
    for(int i=0;i<10;i++) DesenhaLinha();
    return 0;
}
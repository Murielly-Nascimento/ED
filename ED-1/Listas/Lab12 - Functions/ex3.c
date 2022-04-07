/*3)Faça uma função para calcular o fatorial de um número. Use essa função para calcular
o fatorial de um número que o usuário digitar. Colocar todas as funções E/S (entrada e
saída) no programa principal (use também a função DesenhaLinha – esta pode conter
comandos de saída fora do programa principal).*/

#include<stdio.h>

void DesenhaLinha(int quantidade);
int fatorial(int base);

void DesenhaLinha(int quantidade){
    for(int i=0;i<quantidade;i++)printf("=");
}

int fatorial(int base){
    int fat=1;
    for(int i =1;i<=base;i++){
        fat*=i;
    }
    return fat;
}

int main(void){
    int x=0;
    printf("Digite um número: ");
    scanf("%d",&x);

    printf("%d! = %d\n",x,fatorial(x));

    for(int i=0;i<10;i++){
        DesenhaLinha(x);
        printf("\n");
    }
    return 0;
}
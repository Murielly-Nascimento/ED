/*5) Faça uma função para verificar se um número é um quadrado perfeito (retorne
Verdadeiro caso seja).*/

#include<stdio.h>
#include<stdbool.h>

bool QuadradoPerfeito(int num);

bool QuadradoPerfeito(int num){
    bool quadrado = false;
    for(int i=1;i<num;i++){
        if(num/i==i && num%i==0){
            quadrado = true;
            break;
        }else if(i>num/2 + 1) break; 
    }
    return quadrado;
}

int main(void)
{
    int numero = 0; 
    printf("<< Quadrado Perfeito >>\n");
    printf("Digite um numero: ");
    scanf("%d",&numero);
    if(QuadradoPerfeito(numero)) printf("VERDADEIRO\n");
    else printf("FALSO\n");
    
    return 0;
}
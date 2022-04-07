/*
1) Efetuar a leitura de um número real e apresentar o resultado do quadrado desse
número.
*/

#include<stdio.h>

int main(void){
    
    printf("<< Cálculo da Quadrado de n>>\n");
    printf("Digite um número:");
    
    double A = 0.0, B = 0.0;
    scanf("%lf",&A);
    B=A*A;
  
    printf("O valor de %.2lf ao quadrado é %.2lf\n",A,B);

    return 0;
}

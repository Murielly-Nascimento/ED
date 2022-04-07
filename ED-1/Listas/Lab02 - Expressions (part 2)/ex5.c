/*5) Faça um conversor de número binário para decimal (inteiro). O número deve ter 4 bits,
sendo o bit mais significativo digitado primeiro. Mostrar na resposta o número binário
e o número decimal.*/

#include<stdio.h>
#include<math.h>

int main(void){
    int binario=0,j=3,bit=0;
    double decimal=0.0;

    printf("== Conversor de números binários ==\n");
    printf("Digite o 1o. bit:");
    scanf("%d",&bit);
    binario += bit*pow(10,j);
    decimal += bit * pow(2,j);
    j--;

    printf("Digite o 2o. bit:");
    scanf("%d",&bit);
    binario += bit*pow(10,j);
    decimal += bit * pow(2,j);
    j--;

    printf("Digite o 3o. bit:");
    scanf("%d",&bit);
    binario += bit*pow(10,j);
    decimal += bit * pow(2,j);
    j--;

    printf("Digite o 4o. bit:");
    scanf("%d",&bit);
    binario += bit*pow(10,j);
    decimal += bit * pow(2,j);
    j--;

    printf("O número binário %d corresponde ao número decimal %.0lf\n",binario,decimal);    
    return 0;
}
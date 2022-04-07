/*
2) Ler uma temperatura em graus Celsius e apresentá-la convertida em graus Fahrenheit.
A fórmula de conversão é : F = C ∗ (9.0/5.0)+ 32.0, sendo F a temperatura em Fahrenheit e C 
a temperatura em Celsius
*/

#include<stdio.h>

int main(void){
    
    printf("<< Conversor Temperatura>>\n");
    printf("Digite a temperatura (em Celsius):");
    
    double C = 0.0, F = 0.0;
    scanf("%lf",&C);
    F = C*(9.0/5.0) + 32.0;

    printf("%.0lf graus Celsius correspondem a %.0lf Fahrenheit\n",C,F);
    return 0;
}

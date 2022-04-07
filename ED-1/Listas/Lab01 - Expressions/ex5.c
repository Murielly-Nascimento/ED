/*
5) Receber o salário de um funcionário, calcular e mostrar seu novo salário, sabendo que
ele recebeu um aumento de 25%. OBS: para mostrar o sinal de % no printf use dois
símbolos de %. Exemplo: printf(“Após 25%% de ...”). Se você utilizar somente um % o
compilador interpretará como um especificador de formato)
*/

#include<stdio.h>

int main(void){

    printf("<< Aumento Salarial >>\n");
    printf("Digite o valor do salário R$:");
    double salario = 0.0;
    scanf("%lf",&salario);

    salario = salario*1.25;
    printf("Após 25%% de aumento o salário fica em R$ %.2lf\n",salario);
    return 0;
}

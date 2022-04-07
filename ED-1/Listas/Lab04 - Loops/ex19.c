/*19) José possui no banco R$50.000,00 e Carlos R$ 25.000,00. Carlos poupa R$ 3.000,00 por
mês, enquanto que o José poupa R$800,00. Quantos anos levarão para que o Carlos fique
com mais dinheiro que o José? Faça um algoritmo para mostrar esse cálculo.*/

#include<stdio.h>

int main(void){
    int tempo=0;
    tempo = (50000-25000) / (3000 - 800);
    printf("Carlos levará %d anos para ter mais dinheiro que José\n",tempo);
    return 0;
}
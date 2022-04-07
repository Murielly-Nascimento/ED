/*
10) Três amigos jogaram na loteria. Caso eles ganhem, o prêmio deve ser repartido
proporcionalmente ao valor que cada deu para a realização da aposta. Faça um
programa que lê quanto cada apostador investiu, lê o valor do prêmio, e escreve
quanto cada um ganharia.
*/

#include<stdio.h>

int main(void){
    
    double Jum = 0, Jdois = 0, Jtres = 0,total = 0;
    double premio = 0.0;
    
    printf("<< Loteria >>\n");
    printf("Bolão jogador 1 R$:");
    scanf("%lf",&Jum);
    printf("Bolão jogador 2 R$:");
    scanf("%lf",&Jdois);
    printf("Bolão jogador 3 R$:");
    scanf("%lf",&Jtres);
    printf("Informe o valor do prêmio:");
    scanf("%lf",&premio);

    total = Jum + Jdois + Jtres;
    Jum = premio * (Jum/total);
    Jdois = premio * (Jdois/total);
    Jtres = premio * (Jtres/total);

    printf("Jogador 1 receberá R$:%.1lf\n",Jum);
    printf("Jogador 2 receberá R$:%.1lf\n",Jdois);
    printf("Jogador 3 receberá R$:%.1lf\n",Jtres);
    return 0;
}

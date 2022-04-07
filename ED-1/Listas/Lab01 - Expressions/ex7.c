/*
7) Uma empresa contrata um encanador a R$ 30,00 por dia. Crie um programa que
solicite o número de dias trabalhados pelo encanador e imprima o valor bruto, o
imposto, e a quantia líquida que deverá ser paga ao encanador, sabendo-se que são
descontados 8% para imposto de renda e 4% de ISS.
*/

#include<stdio.h>

int main(void){

    int dias = 0;
    double Vbruto=0.0, Vliquido=0.0, ISS = 0.0,IR = 0.0;

    printf("<< Pagamento encanador >>\n");
    printf("Digite o número de dias trabalhados:");
    scanf("%d",&dias);

    Vbruto = dias * 30;
    ISS = Vbruto * 0.04;
    IR = Vbruto * 0.08;
    Vliquido = Vbruto - (ISS + IR);

    printf("Valor bruto R$: %.0lf\n",Vbruto);
    printf("Valor líquido R$: %.0lf\n",Vliquido);
    printf("ISS R$: %.0lf\nIR R$: %.0lf\n",ISS,IR);

    return 0;
}

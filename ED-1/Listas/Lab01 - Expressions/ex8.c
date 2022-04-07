/*8) Um contador percebeu que o cálculo de IR do encanador estava errado, pois estava
sendo calculado sobre o valor bruto que ele recebeu. Refaça o programa anterior,
considerando que o IR é sobre o valor bruto após o desconto do ISS.
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
    IR = (Vbruto - ISS) * 0.08;
    Vliquido = Vbruto - (ISS + IR);

    printf("Valor bruto R$: %.0lf\n",Vbruto);
    printf("Valor líquido R$: %.2lf\n",Vliquido);
    printf("ISS R$: %.0lf\nIR R$: %.2lf\n",ISS,IR);

    return 0;
}

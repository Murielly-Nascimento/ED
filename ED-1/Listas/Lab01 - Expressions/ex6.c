/*6) A importância de R$ 780.000,00 será dividida entre três ganhadores de um concurso,
sendo que da quantia total:
•
O primeiro ganhador receberá 46%;
•
O segundo receberá 32%;
•
O terceiro receberá o restante;
Calcule e imprima a quantia ganha por cada um dos ganhadores.
*/

#include<stdio.h>

int main(void){
    
    double premio = 780000, primeiro = 0.0,segundo = 0.0,terceiro = 0.0;
    primeiro = premio * 0.46;
    segundo = premio * 0.32;
    terceiro = premio - (primeiro + segundo);

    printf("<< Loteria >>\n");
    printf("Valor total do prêmio:%.0lf\n",premio);
    printf("Primeiro vencedor: %.0lf\n",primeiro);
    printf("Segundo vencedor: %.0lf\n",segundo);
    printf("Terceiro vencedor:%.0lf\n",terceiro);
    return 0;
}

/*14) Dado um inteiro positivo p, verificar se p é primo.*/

#include<stdio.h>

int main(void){
    int valor=0, divisores=0;
    printf("<< Números primos >>\n");
    printf("Entre com o valor:");
    scanf("%d",&valor);
    for(int i=1;i<=valor;i++){
        if(valor%i==0) divisores++;
    }
    if(divisores>2) printf("O número %d não é primo\n",valor);
    else printf("O número %d é primo\n",valor);
    return 0;
}
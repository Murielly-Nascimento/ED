/*15) Faça um conversor binário – decimal. O usuário deve digitar o número de bits do número
binário e um bit deve ser lido por vez*/

#include<stdio.h>
#include<math.h>

int main(void){
    int bits = 0,numero=0, j=0;
    double binario=0.0,decimal=0.0;
    
    printf("<< Conversor binário-decimal >>\n");
    printf("Entre com o número de bits:");
    scanf("%d",&bits);
    j = bits - 1;

    for(int i=bits-1,a=1;i>=0;i--,a++){
        printf("Digite o bit #%d:",a);
        scanf("%d",&numero);
        binario += numero * pow(10,j); j--;
        decimal += numero * pow(2,i);
    }
    printf("O número binário %.0lf em decimal é %.0lf\n",binario,decimal);
    return 0;
}
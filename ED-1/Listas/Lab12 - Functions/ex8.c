/*8) Faça uma função que altere um valor de um número real em x%. Se o valor de x for
negativo ele deve ser decrementado, se for positivo aumente.*/

#include<stdio.h>

int incDec(int A,int incrementa);

int incDec(int A,int incrementa){
    if(A>0) A +=incrementa;
    else A-=incrementa;
    return A;
}

int main(void){
    int num=0,incrementa=0;
    printf("<< INCREMENTA OU DECREMENTA >>\n");
    printf("Digite um numero: ");
    scanf("%d",&num);
    printf("Em quanto ele deve ser incrementado ou decrementado: ");
    scanf("%d",&incrementa);

    printf("%d\n", incDec(num,incrementa));

    return 0;
}
/*9) Crie um procedimento idêntico ao exercício anterior, mas que mude o valor da
variável passada por parâmetro (ou seja, o retorno deve ser void)*/

#include<stdio.h>

void incDec(int *A,int incrementa);

void incDec(int *A,int incrementa){
    if(*A>0) *A +=incrementa;
    else *A-=incrementa;
}

int main(void){
    int num=0,incrementa=0;
    printf("<< INCREMENTA OU DECREMENTA >>\n");
    printf("Digite um numero: ");
    scanf("%d",&num);
    printf("Em quanto ele deve ser incrementado ou decrementado: ");
    scanf("%d",&incrementa);

    incDec(&num,incrementa);

    printf("%d\n",num);

    return 0;
}
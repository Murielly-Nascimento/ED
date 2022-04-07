/*13) Dados n e dois números inteiros positivos i e j diferentes de 0, imprimir em ordem crescente os n
primeiros naturais que são múltiplos de i ou de j e ou de ambos.
Exemplo: Para n = 6 , i = 2 e j = 3 a saída deverá ser : 0,2,3,4,6,8.*/

#include<stdio.h>

int main(void){
    int n=0,i=0,j=0,aux=1,multiplos=1;
    
    printf("<< Múltiplos >>\n");
    printf("Entre com o valor de n:");
    scanf("%d",&n);
    printf("Entre com o valor de i:");
    scanf("%d",&i);
    printf("Entre com o valor de j:");
    scanf("%d",&j);
    printf("0,");

    while(multiplos<n){
        if(aux%i==0 || aux%j==0){
            multiplos++;
            printf("%d,",aux);
        }
        aux++;
    }
    printf("\n");
    return 0;
}
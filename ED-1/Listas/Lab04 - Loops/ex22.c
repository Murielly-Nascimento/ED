/*22) Altere o programa anterior para calcular o10! até 15!. É esperado que ocorra um erro.
Explique o motivo do erro e qual a solução.*/

#include<stdio.h>

int main(void){
    //O tipo int não é capaz de armazenar números maiores que 4 bytes.
    //É preciso usar nesse caso o tipo long int com 8 bytes.
    long int fat=1;
    printf("<< Fatorial >>\n");
    for(int i=1;i<=15;i++){
        for(int j=1;j<=i;j++){
            fat*=j;
        }
        printf("%d! = %ld\n",i,fat);
        fat=1;
    }
    return 0;
}

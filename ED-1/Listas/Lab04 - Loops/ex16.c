/*16) Faça um algoritmo que mostre qual a quantidade máxima de endereços de memória que um
computador com 1, 2, 4, 8, 16, 32, 64 e 128 bits pode representar. O programa deve conter um loop
e uma variável. Use a função pow()*/

#include<stdio.h>
#include<math.h>

int main(void){
    int bit = 2;
    for(bit=2;bit<=128;bit*=2){
        printf("Com %d bits é possível endereçar %.0lf posições de memória\n",bit,pow(2.0,bit));
    }

    return 0;
}
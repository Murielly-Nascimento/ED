/*7) Faça um programa para o usuário entrar com os valores de uma matriz 3x3 e o
programa deve verificar se a matriz é simétrica (A = A T )*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    bool simetrica = true;
    int A[3][3] = {0};
    printf("Preenchendo A\n");
    for(int i=0; i<3 ;i++){
        for(int j=0 ;j<3; j++){
            printf("A[%d][%d]: ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    for(int i = 0 ;i<3; i++){
        for(int j=0 ;j<3; j++){
            if(A[i][j] != A[j][i]){
                simetrica = false;
                break;
            }
        }
    }
    if(simetrica) printf("É simétrica\n");
    else printf("Não é simétrica\n");

    return 0;
}
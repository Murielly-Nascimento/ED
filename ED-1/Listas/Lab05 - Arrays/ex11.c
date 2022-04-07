/*11) Leia 5 números inteiros e armazene em um vetor v. Crie dois novos vetores v1 e v2.
Copie os valores ímpares de v para v1, e os valores pares de v para v2. Note que cada
um dos vetores v1 e v2 tem no máximo 5 elementos, mas nem todos os elementos são
utilizados. No final escreva os elementos UTILIZADOS de v1 e v2.*/

#include<stdio.h>

int main(void){
    int v[5]={0},v1[5]={0},v2[5]={0},j=0,k=0;
    printf("<< Pares e Ímpares >>\n");
    for(int i=0;i<5;i++){
        printf("Digite o valor %d: ",i+1);
        scanf("%d",&v[i]);
        if(v[i]%2==0){
            v2[j]=v[i];
            j++;
        }else{
            v1[k]=v[i];
            k++;
        }
    }
    printf("\nÍmpares: ");
    for(int i=0;i<k;i++) printf("%d ",v1[i]);
    
    printf("\n\nPares: ");
    for(int i=0;i<j;i++) printf("%d ",v2[i]);
    printf("\n");
    return 0;
}
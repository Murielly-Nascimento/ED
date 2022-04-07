/*8) Calcular a média e o desvio padrão de 5 números informados pelo usuário.
Média:*/

#include<stdio.h>
#include<math.h>

int main(void){
    int vet[5]={0};
    double media=0, desvio=0.0;
    
    printf("<< Média e desvio-padrão >>\n");
    for(int i=0;i<5;i++){
        printf("Digite o valor %d: ",i+1);
        scanf("%d",&vet[i]);
        media+=vet[i];
    }
    media = media/5;
    
    for(int i=0;i<5;i++){
        desvio += pow((vet[i]-media),2);
    }
    desvio = sqrt(desvio/4);
    printf("A média é %.0lf e o desvio-padrão é %lf\n",media,desvio);
    return 0;
}
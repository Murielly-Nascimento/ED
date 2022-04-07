/*12) Uma piscina de bolinhas possui bolas azuis, verdes, amarelas e vermelhas. Faça um
programa em que o usuário digita a quantidade de bolinhas de cada cor existente em
uma piscina e mostra a probabilidade de ocorrência de cada cor, indicando qual possui
a maior probabilidade*/

#include<stdio.h>

int main(void){
    int quantidade=0,cores[4]={0};
    double probabilidade=0,maior=0;
    printf("<< Probabilidades >>\n");
    
    printf("Verde: ");
    scanf("%d",&cores[0]);
    printf("Azul: ");
    scanf("%d",&cores[1]);
    printf("Amarela: ");
    scanf("%d",&cores[2]); 
    printf("Vermelha: ");
    scanf("%d",&cores[3]);

    probabilidade = cores[0] + cores[1] + cores[2] + cores[3];
    
    double probils[4]={0.0};
    for(int i=0;i<4;i++){
        probils[i] = cores[i]/probabilidade;
        if(probils[i]>maior) maior=probils[i];
    }
    printf("\nProbabilidades\n");
    printf("Verde: %.1lf%%",probils[0]*100);
    if(probils[0]==maior) printf("<< Maior probabilidade\n");
    else printf("\n");
    printf("Azul: %.1lf%%",probils[1]*100);
    if(probils[1]==maior) printf("<< Maior probabilidade\n");
    else printf("\n");
    printf("Amarela: %.1lf%%",probils[2]*100); 
    if(probils[2]==maior) printf("<< Maior probabilidade\n");
    else printf("\n");
    printf("Vermelha: %.1lf%%",probils[3]*100);
    if(probils[3]==maior) printf("<< Maior probabilidade\n");
    else printf("\n");

    return 0;
}
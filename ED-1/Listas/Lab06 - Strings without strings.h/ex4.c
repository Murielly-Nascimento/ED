/*4) Faça um programa em que o usuário digita dois nomes, e o programa informa se os
nomes são iguais. Não usar as funções de string.h*/

#include<stdio.h>

int main(void){
    char nome1[51]={'\0'},nome2[51]={'\0'}, letra = '\0';
    int i = 0,j = 0;

    printf("<< Compara nomes>>\n");
    printf("Digite o nome1: ");
    letra = getchar();

    while(letra!='\n'){
        nome1[i]=letra;
        i++;
        letra = getchar();
    }

    printf("Digite o nome2: ");
    setbuf(stdin,NULL);
    letra = getchar();

    while(letra!='\n'){
        nome2[j]=letra;
        j++;
        letra = getchar();
    }
    if(i!=j) printf("Os nomes digitados são diferentes\n");
    else{
        int sum=0;
        for(int k=0;k<i;k++){
            if(nome1[k]==nome2[k])sum++;
        }
        if(sum==i) printf("Os nomes digitados são iguais\n");
        else printf("Os nomes digitados são diferentes\n");
    }
    return 0;
}
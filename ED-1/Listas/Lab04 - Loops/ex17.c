/*17) Faça um programa que seja semelhante ao jogo de forca, mas com uma única letra. A letra que o
usuário deve adivinhar deve ser definida no código do programa. O usuário tem 5 chances de acertar
a letra. O programa finaliza sua execução quando o usuário acerta a letra ou quando acabam suas
chances*/

#include<stdio.h>
#include<math.h>

int main(void){
    int i=5;
    char letra='q',tentativa='\0';
    printf("<<Forca de uma letra só>>\n");

    for(i=5;i>0;){
        printf("Qual a letra? ");
        scanf("%c",&tentativa);
        getchar();
        if(tentativa == letra){
            printf("ACERTOU!\n");
            break;
        }
        --i;
        if(i==0) break;
        else if(i==1) printf("Última chance!!!\n");
        else printf("Errado! Você tem mais %d chances\n",i);
    }

    if(i==0) printf("Acabaram suas chances. A letra correta é '%c'\n",letra);
    return 0;
}
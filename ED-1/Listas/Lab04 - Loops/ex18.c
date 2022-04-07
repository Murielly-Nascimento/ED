/*18) Faça um algoritmo que converta uma velocidade expressa em km/h para m/s e vice versa. Você deve
criar um menu com as duas opções de conversão e com uma opção para finalizar o programa. O
usuário poderá fazer quantas conversões desejar, sendo que o programa só será finalizado quando a
opção de finalizar for escolhida (no caso, caso ele escolha a opção ‘q’)*/

#include<stdio.h>

int main(void){
    char opcao='\0';
    while (opcao!='q')
    {
        printf("<< Conversor >>\n");
        printf("Digite uma opção\n");
        printf(" 1 - para converter de km/h para m/s\n");
        printf(" 2 - para converter de m/s para hm/h\n");
        printf(" q - para sair\n");
        setbuf(stdin,NULL);
        scanf("%c",&opcao);
        getchar();
        if(opcao=='1'){
            double velocidade = 0.0;
            printf("Digite a velocidade (km/h):");
            scanf("%lf",&velocidade);
            printf("A velocidade em m/s é %lf\n",velocidade/3.6);
        }
        else if(opcao=='2'){
            double velocidade = 0.0;
            printf("Digite a velocidade (m/s):");
            scanf("%lf",&velocidade);
            printf("A velocidade em km/h é %lf\n",velocidade*3.6);
        }
        else if(opcao =='q') break;
    }
    return 0;
}
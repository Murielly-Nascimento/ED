/*6) Faça uma função para calcular o número neperiano usando uma série (ver abaixo). A
função deve ter como parâmetro o número de termos que serão somados (note que,
quanto maior o número, a resposta estará mais próxima do valor e). Observe que é
preciso calcular o fatorial de vários números – para isso, utilize a função criada
anteriormente. Utilize também o procedimento criado no exercício 2.*/

#include<stdio.h>

int fatorial(int base);
double neperiano(int number);

int fatorial(int base){
    int fat=1;
    for(int i =1;i<=base;i++){
        fat*=i;
    }
    return fat;
}

double neperiano(int number){
    double nep = 1;
    for(int i=1;i<=number;i++){
        nep+= 1.0/fatorial(i);
    }
    return nep;
}

int main(void){
    printf("<<NEPERIANO>>\n");
    printf("Digite um numero: ");
    int number=0;
    scanf("%d",&number);
    printf("e~%.5lf\n",neperiano(number));
    return 0;
}
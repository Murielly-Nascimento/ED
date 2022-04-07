/*4) Faça uma função para calcular x n . Não utilizar o operador pow (nem ^ - que não existe
em C). No programa principal permita ao usuário informar o valor de x e de n (inteiro).
Lembre que n pode assumir valor negativo.*/

#include<stdio.h>

double potencia(int base,int expoente);

double potencia(int base, int expoente){
    double resultado = base;
    
    if(expoente<0){
        double base2 = 1.0/base;
        resultado = base2;
        expoente = expoente * -1;
        
        for(int i=1;i<expoente;i++){
            resultado*=base2;
        }

    }else{
        for(int i=1;i<=expoente;i++) resultado*=base;
    }
    return resultado;
}

int main(void)
{
    int base=0, expoente=0;
    printf("Digite a base: ");
    scanf("%d",&base);
    printf("Digite o expoente: ");
    scanf("%d",&expoente);

    printf("A potencia de %d elevado a %d é: %.3lf\n",base,expoente,potencia(base,expoente));
    
    return 0;
}
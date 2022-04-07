/*6. Faça um programa que controla o consumo de energia dos eletrodomésticos de uma
casa.

• Crie e leia as informações de 5 eletrodomésticos: o nome (máximo 15 letras), potencia (real,
em kW) e tempo ativo por dia (real, em horas).

• Leia um valor de tempo t (em dias), calcule e mostre o consumo total na casa e o consumo
relativo de cada eletrodoméstico (consumo/consumo total) nesse período de tempo.
Apresente este ultimo dado em porcentagem.*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define STRING 50

struct ELETRODOMESTICOS{
    char nome[STRING];
    double potencia;
    double tempo;
};

int main(void){
    struct ELETRODOMESTICOS aparelho[5];
    double consumoT=0, consumoR[5]={0};
    printf("<< CONSUMO DE ENERGIA >>\n");
    for(int i=0;i<5;i++){
        printf("Digite o nome do aparelho: ");
        setbuf(stdin,NULL);
        fgets(aparelho[i].nome,sizeof(aparelho[i].nome),stdin);
        aparelho[i].nome[strcspn(aparelho[i].nome,"\n")]='\0';
        setbuf(stdin,NULL);
        printf("Potencia em kW: ");
        scanf("%lf",&aparelho[i].potencia);
        printf("Tempo ativo por dia: ");
        scanf("%lf",&aparelho[i].tempo);
        consumoT += aparelho[i].tempo * aparelho[i].potencia;
    }
    printf("Digite um numero de dias: ");
    int dias=0;
    scanf("%d",&dias);
    printf("O consumo de energia da casa em %d dias é de %.2lf Kwh\n",dias,consumoT*dias);
    for(int i=0;i<5;i++){
        consumoR[i] = ((aparelho[i].potencia * aparelho[i].tempo)/consumoT)*dias;
        printf("O consumo relativo do %s no periodo de %d dias é de %.2lf Kwh\n",aparelho[i].nome,dias,consumoR[i]);
    }

    return 0;
}
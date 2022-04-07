/*2. Idem ao exercício 1, agora para cadastro de datas. Cadastre 3 datas e mostre o maior
ano cadastrado*/

#include<stdio.h>

struct datas{
    int dia;
    int mes;
    int ano;
};

int main(void){
    struct datas tempo[3]={0};
    int MaiorAno =0;
    for(int i=0;i<3;i++){
        printf("Digite a data %d:\n",i+1);
        printf("Dia: ");
        scanf("%d",&tempo[i].dia);
        printf("Mes: ");
        scanf("%d",&tempo[i].mes);
        printf("Ano: ");
        scanf("%d",&tempo[i].ano);
        if(tempo[i].ano>MaiorAno) MaiorAno = tempo[i].ano;
    }
    printf("Maior ano cadastrado é: %d\n",MaiorAno);
    return 0;
}
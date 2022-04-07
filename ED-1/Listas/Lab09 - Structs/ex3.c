/*3. Idem ao exercício 1, agora para cadastro de endereço. Cadastre 3 endereços, mostre
ao final todos os dados dos endereços cadastrados que são do estado “MG”*/

struct endereco{
    char rua[51];
    int numero;
    char complemento[21];
    char cidade[21];
    char estado[3];
    int cep;
};

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    struct endereco adress[3]={0};
    int aux[3]={0},j=0;
    for(int i=0;i<3;i++){
        printf("Digite o endereco %d:\n",i+1);

        printf("Rua: ");
        setbuf(stdin,NULL);
        fgets(adress[i].rua,50,stdin);
        adress[i].rua[strcspn(adress[i].rua, "\n")] = '\0';

        printf("Numero: ");
        scanf("%d",&adress[i].numero);

        printf("Complemento: ");
        setbuf(stdin,NULL);
        fgets(adress[i].complemento,50,stdin);
        adress[i].complemento[strcspn(adress[i].complemento, "\n")] = '\0';

        printf("Cidade: ");
        setbuf(stdin,NULL);
        fgets(adress[i].cidade,50,stdin);
        adress[i].cidade[strcspn(adress[i].cidade, "\n")] = '\0';

        printf("Estado: ");
        setbuf(stdin,NULL);
        fgets(adress[i].estado,50,stdin);
        adress[i].estado[strcspn(adress[i].estado, "\n")] = '\0';

        printf("CEP: ");
        scanf("%d",&adress[i].cep);

        if(strcmp(adress[i].estado,"MG")==0){
            aux[j]=i;
            j++;
        }
    }
    for(int i=0;i<j;i++){
        printf("Rua %s,%d - %s da cidade de %s/%s de CEP: %d\n",adress[aux[i]].rua,adress[aux[i]].numero,adress[aux[i]].complemento,adress[aux[i]].cidade,adress[aux[i]].estado,adress[aux[i]].cep);
    }
    

    return 0;
}
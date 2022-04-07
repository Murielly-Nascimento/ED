/*7. Desenhe, utilizando uma planilha eletrônica, o mapa de memória real para as variáveis
da estrutura do exercício 6. Para isso, faça um nova cópia do projeto do exercício 6 e
modifique-o inserindo no final do programa um printf para o endereço de cada
variável. Na resposta a esse exercício coloque o código e a planilha (insira ela no
documento em que é apresentada a resposta da prática – não enviar arquivo
separado!)*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define STRING 25

struct ELETRODOMESTICOS{
    char nome[STRING];
    double potencia;
    double tempo;
};

int main(void){
    struct ELETRODOMESTICOS aparelho[5];
    printf("<< CONSUMO DE ENERGIA >>\n");
    for(int i=0;i<5;i++){
        printf("Endereco de aparelho[%d].nome: %p\n",i,&aparelho[i].nome);
        printf("Endereco de aparelho[%d].potencia: %p\n",i,&aparelho[i].potencia);
        printf("Endereco de aparelho[%d].tempo: %p\n",i,&aparelho[i].tempo);
    }
    return 0;
}
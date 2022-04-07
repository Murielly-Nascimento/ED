#include <stdio.h>
#include <string.h>
#include "TGrafico.h"
#include "TMatQuad.h"

int main(void){
    //EX 1
    TGrafico *li = NULL;
    li = cria_grafico();
    char eixo_x[100]={'\0'};
    char eixo_y[100]={'\0'};
    char titulo[100]={'\0'};

    printf("Digite o nome do eixo x:");
    fgets(eixo_x,100,stdin);
    eixo_x[strcspn(eixo_x, "\n")] = '\0';
    printf("Digite o nome do eixo y:");
    fgets(eixo_y,100,stdin);
    eixo_y[strcspn(eixo_y, "\n")] = '\0';
    definir_nomes_eixos(li,eixo_x,eixo_y);

    printf("Digite o nome do Título:");
    fgets(titulo,100,stdin);
    titulo[strcspn(titulo, "\n")] = '\0';
    definir_titulo(li,titulo);

    printf("Digite quantos pontos deseja inserir na lista: ");
    int qtd = 0;
    scanf("%d",&qtd);

    struct ponto pontos[qtd]; // check:<<<erro: Não é para usar VLA no curso!>>>>
    for(int i=0;i<qtd;i++){
        printf("Digite a coordenada (x) do ponto %d: ",i+1);
        scanf("%f",&pontos[i].x);
        printf("Digite a coordenada (y) do ponto %d: ",i+1);
        scanf("%f",&pontos[i].y);// check:<<<erro: e1.5 Não precisa alocar um vetor só para ler todos os pontos. A própria lista da estrutura é quem armazena os pontos>>>>
        insere_ponto_fim(li,pontos[i]);
    }

// check:<<<erro: e1.7 Faltou chamar a função que mostra o gráfico de fato>>>>
// check:<<<erro: e1.8 Faltou chamar a função que apaga o gráfico>>>>
    // EX 2

    struct ponto maior_numero = {0,0};
    maior_valor(li,maior_numero);
    printf("Maior valor: %f (ponto x = %f; y = %f)\n",maior_numero.y,maior_numero.x,maior_numero.y);

    //Ex 3

    int posicao = 0;
    printf("Digite a posição em que o ponto será inserido: ");
    scanf("%d",&posicao);
    struct ponto aux = {0,0};
    printf("Digite a coordenada (x) do ponto %d:",posicao);
    scanf("%f",&aux.x);
    printf("Digite a coordenada (y) do ponto %d:",posicao);
    scanf("%f",&aux.y);
    insere(li,aux,posicao);

    //Ex 4
    int ordem = 0;
    printf("Digite a ordem da matriz: ");
    scanf("%d",&ordem);
    TMatQuad *matriz = NULL;
    matriz = cria_mat_identidade(ordem);

    //Ex 5

    int *vetor = NULL;
    printf("Diagonal da matriz:\n");
    vetor = copia_diagonal(matriz);
    for(int i=0;i<ordem;i++){
        printf("Valor[%d] = %d\n",i+1,vetor[i]);
    }

}
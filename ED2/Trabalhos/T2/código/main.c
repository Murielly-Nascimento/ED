/* Comandos para compilação:
   gcc -c main.c TAD_Grafo.c TAD_File.c TAD_Pilha.c
   gcc -o teste main.o TAD_Grafo.o TAD_File.o TAD_Pilha.o
   ./teste
*/
#include <stdio.h>
#include <stdlib.h>
#include "TAD_Grafo.h"
#include "TAD_File.h"

void criarSubMenu()
{
    printf("\nMENU\n");
    printf("1 - Exibe Grafo\n");
    printf("2 - Remove Vértice\n");
    printf("3 - Insere Aresta\n");
    printf("4 - Remove Aresta\n");
    printf("5 - Exibe Vértice de maior Grau\n");
    printf("6 - Existe caminho\n");
    printf("7 - Menor Caminho a partir de um vértice\n");
    printf("8 - Componentes Fortemente Conectados\n");
    printf("9 - Encerrar\n");
    printf("Digite uma opcao: ");
}

void criarMenu()
{
    printf("\nBEM VINDO AO GRAFO APRENDIZADO\n");
    printf("1 - Iniciar\n");
    printf("2 - Sair\n");
    printf("Digite uma opcao: ");
}

void opcoes(TipoGrafo *g)
{
    int opcao = 0;
    scanf("%d", &opcao);

    while (opcao != 9)
    {
        if (opcao == 1)
        {
            int aux = 0;
            printf("1 - Exibir Grafo\n");
            printf("2 - Exibir Matriz\n");
            printf("Digite uma opção: ");
            scanf("%d", &opcao);

            if (opcao == 1)
                exibirGrafo(g);
            else
            {
                exibirMatriz(g);
            }
        }
        else if (opcao == 2)
        {
            int pos = 0;
            printf("Digite a posição: ");
            scanf("%d", &pos);

            removeVertice(g, pos);
        }
        else if (opcao == 3)
        {
            int origem = 0, destino = 0, peso = 0;

            printf("Digite a origem: ");
            scanf("%d", &origem);

            printf("Digite o destino: ");
            scanf("%d", &destino);

            printf("Digite o peso da ligação: ");
            scanf("%d", &peso);

            inserirAresta(g, origem, destino, peso);
        }
        else if (opcao == 4)
        {

            int origem = 0, destino = 0;

            printf("Digite a origem: ");
            scanf("%d", &origem);

            printf("Digite o destino: ");
            scanf("%d", &destino);

            retirarAresta(g, origem, destino);
        }
        else if (opcao == 5)
        {
            maiorGrau(g);
        }
        else if (opcao == 6)
        {
            int origem = 0, destino = 0;

            printf("Digite a origem: ");
            scanf("%d", &origem);

            printf("Digite o destino: ");
            scanf("%d", &destino);

            caminho(g, origem, destino);
        }
        else if (opcao == 7)
        {
            int origem = 0;
            printf("Digite o vértice de origem: ");
            scanf("%d", &origem);

            exibeCaminho(g, origem);
        }
        else if (opcao == 8)
        {
            conexoesFortes(g);
        }
        else if (opcao == 9)
        {

            break;
        }
        else
            printf("Opção inválida\n");

        criarSubMenu();
        scanf("%d", &opcao);
    }
}

void iniciar()
{
    // Dados são passados para a estrutura APRENDIZADO
    char nome[] = "dados.txt"; // nome do arquivo
    int tamanho = 0;           // tamanho do arquivo

    APRENDIZADO *dados = open_txt(nome, &tamanho);
    APRENDIZADO *iterator = dados;

    /* Criamos o grafo
       Afim de poupar processamento optei por guardar um ponteiro
       para a estrutura APRENDIZADO em cada vértice do grafo.*/
    TipoGrafo *g = CriarGrafo(tamanho);

    // Insiro vértices no grafo. Cada um deles aponta para um dado
    for (int i = 0; i < tamanho; i++)
    {
        inserirVertice(g, iterator);
        iterator++;
    }

    /*Chamo a função com as opções e o Menu*/
    opcoes(g);

    // Liberamos o grafo e a estrutura APRENDIZADO
    free(dados);
    liberarGrafo(g);
}

int main(void)
{

    int opcao = 0;
    criarMenu();
    scanf("%d", &opcao);
    if (opcao == 1)
    {
        criarSubMenu();
        iniciar();
    }

    return 0;
}
//Programa principal.

/**
* @file prog.c
* @brief Testa todas as funções do TAD Matriz(TMat2D.h).
* Elas serão testadas nessa ordem.
*1 - Cria Matriz
*2 - Insere Elemento
*3 - Acessa Elemento
*4 - Preenche Matriz
*5 - Soma Matriz
*6 - Multiplica duas Matrizes
*7 - Multiplica uma Matriz por K.
*8 - Calcula o Traço da Matriz
*9 - Soma das linhas.
10 - Soma das colunas.
11 - Libera o espaço alocado na heap.
*
* @author Murielly Oliveira Nascimento
* @date 21/04/2021
*/

#include <stdio.h>
#include<stdlib.h>
#include "TMat2D.h"

int main(void) {

  //Iremos usar três ponteiros durante o programa.
  //Portanto já os alocaremos.
  //Por questão de praticidade todos as matrizes terão o mesmo número de linhas e colunas.
  //Observando que caso tenham tamanhos diferentes as funções soma,multiplica e outras,
  //fazem os devidos testes para saber se as operações podem ser realizadas.

  int linhas = 0, colunas = 0;
  
  MATRIZ *ponteiroA = NULL;
  MATRIZ *ponteiroB = NULL;
  MATRIZ *ponteiroResultado = NULL;

  printf("<< CRIANDO MATRIZES >>\n");
  printf("Digite o número de linhas e colunas da matriz: ");
  scanf("%d %d",&linhas,&colunas);
  ponteiroA = cria(linhas,colunas);
  ponteiroB = cria(linhas,colunas);
  ponteiroResultado = cria(linhas,colunas);
  if(ponteiroA == NULL || ponteiroB == NULL || ponteiroResultado == NULL){
    printf("Erro ao alocar matrizes\n");
  }else printf("Matrizes alocadas com sucesso\n");


  //Essas variáveis serão reutilizadas ao longo do programa.
  //Dessa forma evitamos instanciar diversas variáveis para resolver os mesmo problemas.
  //Elas começam valendo 0.
  double valor = 0;
  int i = 0,j = 0,sucesso = 0;

  printf("\n<< INSERE ELEMENTO >>\n");
  printf("Digite um valor: ");
  scanf("%lf",&valor);
  printf("Digite i: ");
  scanf("%d",&i);
  printf("Digite j: ");
  scanf("%d",&j);

  //Usaremos a variável sucesso para confirmar se uma operação foi bem sucedida.
  //Note que com exceção da função cria e imprime, todas as outras funções em TMat2D.h,
  //retornam 1 em caso de falha e 0 em caso de sucesso.
  sucesso = insere(ponteiroA,i,j,valor);
  if(sucesso == -1) printf("Erro ao inserir elemento\n");
  else printf("Elemento inserido com sucesso\n");
  
  printf("\n<< ACESSA ELEMENTO >>\n");
  //Note que o i e j são as mesmas variáveis usadas anteriormente.
  //Nesse caso o valor delas será sobrescrevido sem prejuízo para o programa.
  printf("Digite i: ");
  scanf("%d",&i);
  printf("Digite j: ");
  scanf("%d",&j);
  acessa(ponteiroA,i,j,&valor);
  printf("Em matrizA[%d][%d] = %.2lf\n",i,j,valor);

  printf("\n<< PREENCHE MATRIZ >>\n");
  printf("Digite um limite mínimo: ");
  scanf("%d",&i);
  printf("Digite um limite máximo: ");
  scanf("%d",&j);
  preenche(ponteiroA,i,j);
  //Usaremos a função imprime para ver os valores inseridos em A.
  printf("Valores da matriz A:\n");
  imprime(ponteiroA);

  printf("\n<< SOMA DAS MATRIZES >>\n");
  printf("Valores da matriz B:\n");
  //Note que i e j ainda estão instanciados com os valores de limite mínimo e máximo.
  preenche(ponteiroB,i,j);
  imprime(ponteiroB);
  soma(ponteiroA,ponteiroB,ponteiroResultado);
  printf("\nValores da matrizResultado:\n");
  imprime(ponteiroResultado);
  
  printf("\n<< MULTIPLICAÇÃO DAS MATRIZES >>\n");
  //ponteiroA e ponteiroB já estão preenchidos.
  //Iremos sobreescrever os valores em ponteiroResultado.
  multiplica(ponteiroA, ponteiroB, ponteiroResultado);
  printf("Resultado da multiplicação: \n");
  imprime(ponteiroResultado);

  printf("\n<< MULTIPLICAÇÃO POR K >>\n");
  printf("Digite uma constante K: ");
  int K = 0;
  scanf("%d",&K);
  multiplica_por_K(ponteiroA,K,ponteiroResultado);
  printf("Resultado da multiplicação por K:\n");
  imprime(ponteiroResultado);

  printf("\n<< TRAÇO DA MATRIZ >>\n");
  double tracoDaMatriz = 0;
  traco(ponteiroA, &tracoDaMatriz);
  printf("Traço da MatrizA = %.2lf\n",tracoDaMatriz);

  printf("\n<< SOMA DAS LINHAS >>\n");
  //Alocamos dinamicamente o vetorLinhas, pois não sabemos o seu tamanho.
  double *vetorLinhas = (double *)malloc(linhas*sizeof(double));
  soma_das_linhas(ponteiroA, vetorLinhas);
  for(int x=0;x<linhas;x++){
    printf("vetor[%d] = %.2lf\n",x,vetorLinhas[x]);
  }
  //Uma vez terminado o procedimento, liberamos o espaço alocado na heap, para o 
  //qual vetorLinhas aponta.
  free(vetorLinhas);

  printf("\n<< SOMA DAS COLUNAS >>\n");
  double *vetorColunas = (double *)malloc(colunas*sizeof(double));
  soma_das_colunas(ponteiroA, vetorColunas);
  for(int x=0;x<linhas;x++){
    printf("vetor[%d] = %.2lf\n",x,vetorColunas[x]);
  }
  free(vetorColunas);
  //Uma vez terminado o procedimento, liberamos o espaço alocado na heap, para o 
  //qual vetorColunas aponta.

  //Finalizado o programa vamos liberar o espaço alocado no ínicio dele e 
  //para o qual os ponteiros A,B e resultado apontam. 
  libera(ponteiroA);
  libera(ponteiroB);
  libera(ponteiroResultado);
  printf("Espaços liberados com sucesso!\n");
  printf("\n<< FIM DO PROGRAMA >>\n");

  return 0;
}
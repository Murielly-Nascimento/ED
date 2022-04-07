//TAD MATRIZ

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TMat2D.h"

/*
*@brief Recebe o numero de linhas e colunas definido pelo usuário e aloca
*dinamicamente uma matriz. Se bem sucedida retorna 0,caso contrário 1.
*/
MATRIZ *cria(int linhas, int colunas){
  MATRIZ *matriz=NULL;
  matriz = malloc(sizeof(MATRIZ));
  if(matriz==NULL){
    return NULL;
  }else{
    matriz->nlinhas = linhas;
    matriz->ncolunas = colunas;
    //Os dados da matriz são armazenados como um vetor.
    matriz->dados = malloc(colunas*linhas*sizeof(int)); 
    int numero = 0;
    for(int i = 0; i<matriz->nlinhas; i++){
      for(int j = 0; j<matriz->ncolunas; j++){
        insere(matriz,i,j,numero);
      }
    }
  }
  return matriz;
}//cria.


/*
*@brief Recebe uma matriz e libera o espaço alocado para ela na heap
*Se bem sucedida retorna 0,caso contrário 1.
*/
int libera(MATRIZ *matriz){
  if(matriz == NULL){
    return -1;
  }else{
    free(matriz->dados);
    free(matriz);
    return 0;
  }
}//libera

/*
*@brief Recebe uma matriz e insere na posição ij um valor.
*Se bem sucedida retorna 0,caso contrário 1.
*/
int insere(MATRIZ *matriz, int i, int j, int val){
  //Levando em consideração que estamos usando internamente um vetor unidimensional.
  //Temos que calcular qual seria a posição de um elemento aij. 
  int posicao = j * matriz->nlinhas + i;
  matriz->dados[posicao] = val;

  if(matriz->dados==NULL) return -1;
  else return 0;
}//insere.

/*
*@brief Busca um valor na posição ij de uma matriz e o devolve ao usuário.
*Isso é feito através da passagem por referência, usando o ponteiro val.
*Se bem sucedida retorna 0,caso contrário 1.
*/
int acessa(MATRIZ *matriz, int i, int j, int* val){
  int posicao = j * matriz->nlinhas + i;
  *val = matriz->dados[posicao];
  if(*val != matriz->dados[posicao]) return -1;
  else return 0;
}//obtem.

/*
*@brief Prrenche uma matriz com valores aleátorios dentro do intervalo minimo e máximo.
*Se bem sucedida retorna 0,caso contrário 1.
*/
int preenche(MATRIZ *matriz, int maximo, int minimo){
  srand (time(NULL));
  int posicao = 0;
  for(int i=0;i<matriz->nlinhas;i++){
    for(int j=0;j<matriz->ncolunas;j++){
      posicao = j * matriz->nlinhas + i;
      matriz->dados[posicao] = (rand() % (maximo - minimo));
    }
  }
  if(matriz->dados==NULL) return -1;
  else return 0;
}//preenche

/*
*@brief Faz a soma de duas matrizes e o resultado é armazenado na matrizResultado.
*Se bem sucedida retorna 0,caso contrário 1.
*Para a soma de duas matrizes todos os parametros devem ter o mesmo número de linhas  
*colunas.
*/
int soma(MATRIZ *matrizA, MATRIZ *matrizB, MATRIZ *matrizResultado){
  if(matrizA->nlinhas != matrizB->nlinhas || matrizA->ncolunas != matrizB->ncolunas || matrizA->ncolunas != matrizResultado->ncolunas || matrizA->nlinhas != matrizResultado->nlinhas) return -1;
  else{
    for(int i=0;i<matrizA->nlinhas;i++){
      for(int j=0;j<matrizA->ncolunas;j++){
        int posicao = j * matrizA->nlinhas + i;
        matrizResultado->dados[posicao] = matrizA->dados[posicao] + matrizB->dados[posicao];
      }
    }
    if(matrizResultado->dados==NULL) return -1;
    else return 0;
  }
}//soma

/*
*@brief Faz a multiplicação de duas matrizes e o resultado é armazenado na matrizResultado.
*Se bem sucedida retorna 0,caso contrário 1.
*Para a multiplicação de duas matrizes o número de linhas da matrizA 
*deve ser o mesmo que número de colunas da matriz B, e o resultado 
*terá o número de linhas da matrizA e o número de colunas da matrizB.
*/
int multiplica(MATRIZ *matrizA, MATRIZ *matrizB, MATRIZ *matrizResultado){
  if(matrizA->ncolunas != matrizB->nlinhas || matrizResultado->nlinhas != matrizA->nlinhas || matrizResultado->ncolunas != matrizB->ncolunas) return -1;
  else{
    int aux = 0;
    int posicaoA = 0,posicaoB = 0, posicaoResultado = 0;
    for(int i=0;i<matrizA->nlinhas;i++){
      for(int j=0;j<matrizB->ncolunas;j++){
        for(int x = 0; x< matrizB->nlinhas; x++){
          posicaoA = x * matrizA ->nlinhas + i;
          posicaoB = j * matrizB ->nlinhas + x;
          aux+= matrizA->dados[posicaoA] * matrizB->dados[posicaoB];
        }
        posicaoResultado = j * matrizA ->nlinhas + i;
        matrizResultado->dados[posicaoResultado] = aux;
        aux = 0;
      }
    }
    if(matrizResultado->dados==NULL) return -1;
    else return 0;
  }

}//multiplica

/*
*@brief Faz a multiplicação de uma matriz por uma constante K.
*O resultado é armazenado na matrizResultado.
*Se bem sucedida retorna 0,caso contrário 1.
*/
int multiplica_por_K(MATRIZ *matrizA, int K, MATRIZ *matrizResultado){
  for(int i=0;i<matrizA->nlinhas;i++){
    for(int j=0;j<matrizA->ncolunas;j++){
      int posicao = j * matrizA->nlinhas + i;
      matrizResultado->dados[posicao] = matrizA->dados[posicao] * K;
    }
  }
  if(matrizResultado->dados==NULL) return -1;
  else return 0;
}//multiplica_por_K

/*
*@brief Calcula o traço de uma matriz e retorna ao usuário esse valor por
*passagem de referência.
*Se bem sucedida retorna 0,caso contrário 1.
*O traço é a soma de todos os valores na diagonal principal.
*A matriz deve ser quadrada. Ou seja, ter o mesmo número de linhas e colunas.
*/
int traco(MATRIZ *matrizA, int *resultado){
  if(matrizA->nlinhas != matrizA->ncolunas) return -1;
  else{
    for(int i=0;i<matrizA->nlinhas;i++){
    for(int j=0;j<matrizA->ncolunas;j++){
      if(i==j){
        int posicao = j * matrizA->nlinhas + i;
        *resultado += matrizA->dados[posicao];
      }
    }
  }
  if(resultado==NULL) return -1;
  else return 0;
  }
}//traco.

/*
*@brief Faz a soma das linhas da matriz e retorna o valor para o vetor linhas.
*Se bem sucedida retorna 0,caso contrário 1.
*/
int soma_das_linhas(MATRIZ *matrizA, int *linhas){
  for(int i=0;i<matrizA->nlinhas;i++){
    for(int j=0;j<matrizA->ncolunas;j++){
      //Calculamos a posição da mesma forma que fizemos anteriormente.
      int posicao = j * matrizA->nlinhas + i;
      //linhas tem o mesmo tamanho que o número de linhas da matriz.
      linhas[i] += matrizA->dados[posicao];
    }
  }
  if(linhas==NULL) return -1;
  else return 0;
}//soma_das_linhas

/*
*@brief Faz a soma das colunas da matriz e retorna o valor para o vetor colunas.
*Se bem sucedida retorna 0,caso contrário 1.
*/
int soma_das_colunas(MATRIZ *matrizA, int *colunas){
  //O vetor de dados da matriz armazena coluna por coluna.
  //Assim iremos percorrê-lo como um vetor.
  //O tamanho dele é linhas * colunas.
  //A cada vez que i for multiplo do número de linhas significa que a coluna j
  //terminou e devemos ir para a próxima, ou seja, j++.
  int tamanho = matrizA->nlinhas* matrizA->ncolunas;
  for(int i=0,j=0;i<tamanho;i++){
    colunas[j] += matrizA->dados[i];
    if((i+1) % (matrizA->nlinhas) == 0) j++;
  }
  if(colunas==NULL) return -1;
  else return 0;
}//soma_das_colunas

/*
*@brief Imprime uma matriz.
*Use-a para conferir se seus cálculos estão corretos.
*/
void imprime(MATRIZ *matriz){
  for(int i=0;i<matriz->nlinhas;i++){
    for(int j=0;j<matriz->ncolunas;j++){
      int posicao = j * matriz->nlinhas + i;
      printf("%d ",matriz->dados[posicao]);
    }
    printf("\n");
  }
}//imprime.
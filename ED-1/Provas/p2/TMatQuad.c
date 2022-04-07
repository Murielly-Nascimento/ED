#include <stdlib.h>
#include "TMatQuad.h"

struct TMatQuad
{
    int *dados;
    int ordem; // ordem indica o tamanho da matriz. Por exemplo, ordem 3 indica uma matriz 3x3
};


TMatQuad* cria_matquad(int ordem){
   
}

void libera_matquad(TMatQuad *mat){

}

TMatQuad* cria_mat_identidade(int ordem){
    TMatQuad *matriz = NULL;
    matriz = malloc(sizeof(TMatQuad));
    if(matriz == NULL) return NULL;
    else{
        matriz->ordem = ordem;
        matriz->dados = malloc(ordem * sizeof(int));// check:<<<erro: ordem*ordem>>>>
        for(int i=0;i<ordem;i++){
            for(int j=0;j<ordem;j++){
                int posicao = j* ordem + i;
                if(i==j){
                    matriz->dados[posicao] = 1;
                }else{
                    matriz->dados[posicao] = 0;
                }
            }
        }
        return 0;
    }

}

int* copia_diagonal(TMatQuad *m){
    int *vetor = NULL;
    vetor = malloc(m->ordem*sizeof(int));
    if(vetor == NULL || m == NULL) return NULL;
    else{
        int k = 0;
        for(int i=0;i<m->ordem;i++){
            for(int j=0;j<m->ordem;j++){
                if(i==j){// check:<<<erro: otimizar>>>>
                    int posicao = j* m->ordem + i;
                    vetor[k] = m->dados[posicao];
                    k++;
                }
            }
        }
        return vetor;
    }

}

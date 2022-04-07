#include <stdio.h>
#include <stdlib.h>
#include "TGrafico.h"

struct TGrafico
{
    int qtd;
    struct ponto ptos[MAX];
    char nome_eixo_x[100];
    char nome_eixo_y[100];
    char titulo[100];
};


TGrafico* cria_grafico(){

}

void apaga_grafico(TGrafico* li){
}

int definir_nomes_eixos(TGrafico* li, char *eixo_x, char *eixo_y){
}

int definir_titulo(TGrafico* li, char *titulo){
}

int insere_ponto_inicio(TGrafico* li, struct ponto pto){
}

int insere_ponto_fim(TGrafico* li, struct ponto pto){
}

int mostrar_grafico(TGrafico* li){

}

// check:<<<erro: e2.1a não retornou o ponto maior como passagem de parâmetro por referência>>>>
int maior_valor(TGrafico* li,struct ponto pto){
    if(li==NULL || li->qtd == 0) return -1;
    else{
        struct ponto maior = {0,0};
        maior = li->ptos[0];
        for(int i=0;i<li->qtd;i++){
            if(li->ptos[i].y > maior.y){
                maior.y = li->ptos[i].y;
                maior.x = li->ptos[i].x; //faça:maior = li->ptos[i]// check:<<<comentário: >>>>
            }
        }
        return 0;
        // check:<<<erro: faltou a cópia do retorno>>>>
    }
}

int insere(TGrafico* li, struct ponto pto, int pos){
    if(li==NULL || pos >= MAX || pos<0) return -1;
    // check:<<<erro: e3.1 erro de teste lista nula E/OU lista cheia E/OU pos negativo E/OU pos > max>>>>
    if(pos >= li->qtd){
        int aux = 0;
        for(int i = li->qtd; i<pos;i++){
            li->ptos[i].x = 0;
            li->ptos[i].y = 0;
            aux ++;
        }
        li->ptos[pos] = pto;
        li->qtd += aux + 1; //Estou considerando os ptos = 0 na qtd também
        return 0;
    }
    else{
        for(int i = li->qtd-1; i>=pos;i--)
            li->ptos[i+1] = li->ptos[i];
        li->ptos[pos] = pto;// check:<<<erro: e3.5 Erro de indexação de posição>>>>
        li->qtd++;
        return 0; 
    }
}



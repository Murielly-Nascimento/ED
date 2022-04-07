#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "TFile.h"

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define ERROR -2

#define MAX 100

int salva_arquivo(MATRIZ *matriz, char *nome_arquivo){
    char arquivo [MAX] = {"img/"};
    strcat(arquivo,nome_arquivo);

    FILE *img = fopen(arquivo, "wb");

    fwrite(&matriz->nlinhas, sizeof(int), 1, img);
    fwrite(&matriz->ncolunas, sizeof(int), 1, img);

    int valor = 0;

    for(int i = 0; i<matriz->nlinhas; i++){
        for(int j = 0; j<matriz->ncolunas; j++){
            acessa(matriz,i,j,&valor);
            fwrite(&valor, sizeof(int),1,img);
        }
    }
    
    fclose(img);

    return SUCCESS;
}

MATRIZ* open_txt(char *nome)
{
        
    //Como os arquivos ficam no diretório img, concatenamos o nome passado
    //como parâmetro com o diretório.
    char arquivo [MAX] = {"img/"};
    strcat(arquivo,nome);

    //O arquivo txt já deve existir e portanto faremos apenas uma leitura
    FILE *img = fopen(arquivo,"r");
        
    //Descobrimos quantas linhas e colunas o arquivo têm
    char caracter = '\0';
    int i = 0, j = 0;
    while(caracter != EOF){
        caracter = fgetc(img);
        if(caracter == '\n') i++;
        else if(caracter == '\t' || caracter == ' ') j++;
    }

    //Voltamos o ponteiro para o início
    rewind(img);

    //Linhas é a quantidade de '\n' no arquivo 
    int linhas = i;
    //Colunas são as quantidades de '\t'
    //Nesse caso temos que dividir j pelo número de '\n', se não teríamos o número de todos '\t' ao invés da qtd de colunas
    int colunas = floor(j/i);

    //Chamamos a função do TMat2D.h para criar a matriz
    MATRIZ *matriz = cria(linhas, colunas);
    int valor = 0;

    //Lemos os pixels do arquivo e armazenamos na matriz
    for(int i = 0 ;i<linhas; i++){
        for(int j = 0 ;j<colunas; j++){
            fscanf(img,"%d",&valor);
            insere(matriz,i,j,valor);
        }
    }

    //Fechamos o arquivo e liberamos a estrutura que lida com ele
    fclose(img);

    //A função retorna a matriz preenchida com pixels
    return matriz;
}

int *converte_imagem(char *nome_texto, char *nome_binario)
{
    //Precisamos da matriz com os valores do arquivo txt
    //Para isso usamos a função open_txt
    MATRIZ *matriz = open_txt(nome_texto);
    salva_arquivo(matriz,nome_binario);
    libera(matriz);

    //Se a conversão foi bem sucedida.
    return SUCCESS;
}

MATRIZ* open_binario(char *nome)
{
    //O arquivo binário está no diretório img
    char arquivo [MAX] = {"img/"};
    strcat(arquivo,nome);

    //Usamos 'rb' para ler arquivos binários
    FILE *img = fopen(arquivo,"rb");
        
    //Descobrimos a quantidade de linhas e colunas
    int linhas = 0, colunas = 0;
    fread(&linhas, sizeof(int),1,img);
    fread(&colunas, sizeof(int),1,img);

    //Criamos uma matriz para guardar os valores
    MATRIZ *matriz = cria(linhas, colunas);
    int valor = 0;

    //Percorremos a imagem ou arquivo
    //Inserimos os valores na matriz
    for(int i = 0 ;i<linhas; i++){
        for(int j = 0 ;j<colunas; j++){
            fread(&valor, sizeof(int),1,img);
            insere(matriz,i,j,valor);
        }
    }

    //Fechamos o arquivo
    fclose(img);

    //Retornamos a matriz com os valores
    return matriz;
}

int segment_file(char *nome_original, char *nome_resultado, int valor){

    //Precisamos da matriz com os valores do arquivo bin
    //Para isso usamos a função open_binario
    MATRIZ *matriz = open_binario(nome_original);
    MATRIZ *resultado = cria(matriz->nlinhas, matriz->ncolunas);

    int number = 0;

    //Acessamos os valores armazenados na matriz e os escrevemos no arquivo
    //Se um valor de pixel for maior do que o thr passado então escrevemos 1 no arquivo
    //Senão escrevemos 0
    for(int i = 0; i<matriz->nlinhas ; i++){
        for(int j = 0; j<matriz->ncolunas ; j++){
            acessa(matriz,i,j,&number);
            if(number > valor){
                number = 1;
                insere(resultado,i,j,number);
            }
            else if(number <= valor){
                number = 0;
                insere(resultado,i,j,number);
            }
        }
    }

    salva_arquivo(resultado,nome_resultado);

    libera(matriz);
    libera(resultado);

    //Se a segmentação foi bem sucedida.
    return SUCCESS;
}

int componentes_conexos(char *img_segmentada, char *nome_resultado){

    //Abrimos a matriz com os valores da imagem segmentada
    //Criamos a matriz resultado, a qual receberá os mesmos dados da segmentada
    MATRIZ *segmentada = open_binario(img_segmentada);
    MATRIZ *resultado = cria(segmentada->nlinhas,segmentada->ncolunas);

    int valor1 = 0, valor2 = 0, label = 2;

    for(int i = 0; i<resultado->nlinhas; i++){
        for(int j = 0; j<resultado->ncolunas; j++){
            acessa(segmentada,i,j,&valor1);
            insere(resultado,i,j,valor1);
        }
    }

    //Criamos uma pilha de pontos com o tamanho da matriz
    int tamanho = segmentada->nlinhas * segmentada->ncolunas;
    TStackPontos *pilha = stack_create_int(tamanho);
    PONTOS aux, atual;
    
    //Percorremos a matriz segmentada
    for(int i = 1; i < segmentada->nlinhas - 1 ;i++){
        for(int j = 1; j < segmentada->ncolunas - 1 ;j++){
            
            //Acessamos os elementos da matriz segmentada e resultado
            acessa(segmentada,i,j,&valor1);
            acessa(resultado,i,j,&valor2);

            aux.x = i;
            aux.y = j;
            aux.valor = valor1;
            
            //Se a segmentada nessa posição for igual a i e a resultado não tiver sido visitada anteriormente
            if(valor1 == 1 && valor2==1){

                //Matriz resultado[i][j] = label
                insere(resultado,aux.x,aux.y,label);
                //Inserimos aux na pilha
                stack_push_int(pilha,aux);

                //Enquanto a pilha não for vazia
                while(stack_empty_int(pilha)!=0){

                    //Pegamos o primeiro elemento na pilha 
                    stack_top_int(pilha,&atual);
                    //Removemos o primeiro elemento
                    stack_pop_int(pilha);

                    aux.x = atual.x - 1;
                    aux.y = atual.y;
                    
                    acessa(segmentada, aux.x, aux.y, &aux.valor);
                    acessa(resultado, aux.x, aux.y, &valor2);

                    if(aux.valor == 1 && valor2==1){ //ACIMA
                        insere(resultado,aux.x,aux.y, label);
                        stack_push_int(pilha,aux);
                    }

                    aux.x = atual.x + 1;
                    aux.y = atual.y;
                    
                    acessa(segmentada, aux.x, aux.y, &aux.valor);
                    acessa(resultado, aux.x, aux.y, &valor2);

                    if(aux.valor == 1 && valor2==1){ //ABAIXO
                        insere(resultado,aux.x,aux.y, label);
                        stack_push_int(pilha,aux);
                    }


                    aux.x = atual.x;
                    aux.y = atual.y - 1;
                    
                    acessa(segmentada, aux.x, aux.y, &aux.valor);
                    acessa(resultado, aux.x, aux.y, &valor2);

                    if(aux.valor == 1 && valor2==1){ //ESQUERDA 
                        insere(resultado,aux.x,aux.y, label);
                        stack_push_int(pilha,aux);
                    }

                    aux.x = atual.x;
                    aux.y = atual.y + 1;
                    
                    acessa(segmentada, aux.x, aux.y, &aux.valor);
                    acessa(resultado, aux.x, aux.y, &valor2);

                    if(aux.valor == 1 && valor2==1){ //DIREITA
                        insere(resultado,aux.x,aux.y, label);
                        stack_push_int(pilha,aux);
                    }
                }label++;
            }
        }
    }

    //Libera a pilha
    stack_free_int(pilha);

    salva_arquivo(resultado,nome_resultado);

    //Libera matrizes
    libera(segmentada);
    libera(resultado);
    
    return SUCCESS;
}

int labirinto(char *nome_labirinto, char *nome_resultado){

    //Precisamos da matriz com os valores do labirinto
    //Para isso usamos a função open_binario
    MATRIZ *labirinto = open_txt(nome_labirinto);
    MATRIZ *resultado = cria(labirinto->nlinhas,labirinto->ncolunas);
    
    //Descobrimos a entrada para o labirinto
    //Preenchemos a matriz resultado com os valores do labirinto
    PONTOS entrada;
    int valor = 0, valor2 = 0, label = 2;
    for(int i=0; i<labirinto->nlinhas;i++){
        for(int j =0; j<labirinto->ncolunas; j++){
            acessa(labirinto,i,j,&valor);
            insere(resultado,i,j,valor);
            if(valor == 1 && j==0){
                entrada.x = i;
                entrada.y = 0;
                entrada.valor = valor;
                insere(resultado,i,j,label);
            }
        }

    }
    
    bool saida = false, proximo = false;
    int tamanho = labirinto->nlinhas * labirinto->ncolunas;
    TStackPontos *pilha = stack_create_int(tamanho);
    
    
    for(int i=entrada.x; i<labirinto->nlinhas; i++){
        for(int j=1; j<labirinto->ncolunas; j++){
            acessa(labirinto,i,j,&valor);
            acessa(labirinto,i,j,&valor2);
            if(valor == 1){
                
                PONTOS atual;
                atual.x = i;
                atual.y = j;
                atual.valor = valor;

                insere(resultado,i,j,label);

                stack_push_int(pilha,atual);

                while(stack_empty_int(pilha)!=0){
                    PONTOS aux; 
                    stack_top_int(pilha, &aux);
                    stack_pop_int(pilha);
                    proximo = true;

                    if(aux.y == labirinto->ncolunas && aux.valor == 1){
                        saida = true;
                        break;
                    }
                    else if(aux.x < 0 || aux.x >= labirinto->nlinhas || aux.y < 0 || aux.y >= labirinto->ncolunas) break;

                    acessa(labirinto,aux.x + 1,aux.y,&valor);
                    acessa(resultado,aux.x + 1,aux.y,&valor2);

                    if(valor == 1 && valor2 == 1 && proximo){ // ABAIXO
                        insere(resultado,aux.x + 1,aux.y,label);
                        aux.x += 1;
                        stack_push_int(pilha,aux);
                        proximo = false;
                    }

                    acessa(labirinto,aux.x - 1,aux.y,&valor);
                    acessa(resultado,aux.x - 1,aux.y,&valor2);

                    if(valor == 1 && valor2 == 1 && proximo){ //ACIMA
                        insere(resultado,aux.x - 1,aux.y,label);
                        aux.x -= 1;
                        stack_push_int(pilha,aux);
                        proximo = false;
                    }

                    acessa(labirinto,aux.x,aux.y - 1,&valor);
                    acessa(resultado,aux.x,aux.y - 1,&valor2);

                    if(valor == 1 && valor2 == 1 && proximo){ //ESQUERDA
                        insere(resultado,aux.x,aux.y - 1 ,label);
                        aux.y -= 1;
                        stack_push_int(pilha,aux);
                        proximo = false;
                    }

                    acessa(labirinto,aux.x,aux.y + 1,&valor);
                    acessa(resultado,aux.x,aux.y + 1,&valor2);

                    if(valor == 1 && valor2 == 1 && proximo){
                        insere(resultado,aux.x,aux.y + 1 ,label);
                        aux.y += 1;
                        stack_push_int(pilha,aux);
                        proximo = false;
                    }
                    
                }
            }else if(valor2 == label){
                valor2 = 1;
                insere(resultado,i,i,valor2);
            }
            
        }
    }
    
    stack_free_int(pilha);
    
    salva_arquivo(resultado,nome_resultado);
    
    libera(labirinto);
    libera(resultado);

    return SUCCESS;
}






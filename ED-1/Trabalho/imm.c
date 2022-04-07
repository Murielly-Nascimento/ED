#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "lib/TFile.h"

int main(int argc, char *argv[]){
  printf("\n<< RECEBENDO OS ARGUMENTOS >>\n");
  char argumentos[5][30] = {'\0'};
  
  for(int i = 0; i < argc ; i++){
    for(int j = 0; argv[i][j]!='\0'; j++){
      argumentos[i][j] = argv[i][j];
    }
  }

  if(argc == 3){
    if(strcmp(argumentos[1],"-open") == 0){
    
      int tamanho = strlen(argumentos[2]);
      char extensao[3] = {'\0'};
      for(int i = tamanho - 3, j = 0; i<tamanho; i++,j++){
        extensao[j] = argumentos[2][i];
      }
    
      if((strcmp(extensao, "txt") == 0) || (strcmp(extensao, "pgm") == 0)){
    
        MATRIZ *matriz = open_txt(argumentos[2]);
        imprime(matriz);
        libera(matriz);
    
      }else if((strcmp(extensao, "imm") == 0) || (strcmp(extensao, "bin") == 0)){
    
        MATRIZ *matriz = open_binario(argumentos[2]);
        imprime(matriz);
        libera(matriz);
    
      }
    }
  }
  else if(argc == 4){
    if(strcmp(argumentos[1],"-convert") == 0){

      converte_imagem(argumentos[2],argumentos[3]);
      printf("Imagem convertida com sucesso\n");
    
    }
    else if(strcmp(argumentos[1],"-cc") == 0){
     
      componentes_conexos(argumentos[2],argumentos[3]);
     
      MATRIZ *matriz = open_binario(argumentos[3]);
      imprime(matriz);
      libera(matriz);
    
    }
    else if(strcmp(argumentos[1],"-lab") == 0){
    
      labirinto(argumentos[2],argumentos[3]);
      MATRIZ *original = open_txt(argumentos[2]);
      imprime(original);
      libera(original);
      printf("\n\n");
      MATRIZ *resposta = open_binario(argumentos[3]);
      imprime(resposta);
      libera(resposta);
    
    }
  }
  else if(argc == 5){
    if(strcmp(argumentos[1],"-segment") == 0){
    
      int valor = atoi(argumentos[2]);
      segment_file(argumentos[3], argumentos[4], valor);
      MATRIZ *matriz = open_binario(argumentos[4]);
      imprime(matriz);
      libera(matriz); 
    
    }  
  }
  else{
    printf("Comando não encontrado\n");
  }
  return 0;
}

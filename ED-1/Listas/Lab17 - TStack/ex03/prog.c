#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TStack.h"

#define MAX 100

int main(void){
  
  printf("\n<< CRIANDO PILHA >>\n");
  printf("Digite um tamanho: ");
  int tamanho = 0;
  scanf("%d",&tamanho);
  TStack *pilha = stack_create(tamanho);
  if(pilha == NULL){
    printf("Erro ao alocar a pilha\n");
  }

  printf("\n<< INSERINDO ELEMENTOS >>\n");
  printf("Digite um nome: ");
  char nome[MAX] = {'\0'};
  setbuf(stdin,NULL);
  fgets(nome,MAX,stdin);
  nome[strcspn(nome, "\n")] = '\0';
  stack_push(pilha, nome);
  stack_print(pilha);

  printf("\n<< REMOVENDO ELEMENTOS DA PILHA >>\n");
  stack_pop(pilha);
  stack_pop(pilha);
  stack_print(pilha);

  printf("\n<< QUAL ELEMENTO ESTA NO TOPO DA PILHA ? >>\n");
  char caracter = '\0';
  stack_top(pilha,&caracter);
  printf("%c\n",caracter);

  printf("\n<< QUAL É O ESTADO DA PILHA ? >>\n");
  int estado = stack_empty(pilha);
  if(estado == 0) printf("A pilha está vaiza\n");
  else{
    estado = stack_full(pilha);
    if(estado == 0) printf("A pilha está cheia\n");
    else if(estado == -6) printf("Ainda há espaço na pilha\n");
  }

  printf("\n<< LIBERANDO A LISTA >>\n");
  stack_free(pilha);


  return 0;
}
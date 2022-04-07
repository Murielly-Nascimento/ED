#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TStack.h"

#define MAX 100

char *infixaParaPosfixa(char *infixa){
  int tamanho = strlen(infixa);
  char *posfixa = malloc((tamanho+1) * sizeof(char));
  TStack *pilha = stack_create(tamanho+1);
  stack_push(pilha,infixa[0]);

  int j = 0;
  for(int i = 1; infixa[i] != '\0'; i++){
    char aux = '\0';
    if(infixa[i] == '('){
      stack_push(pilha,infixa[i]);
    }
    else if (infixa[i] == ')'){
      desempilha(pilha,&aux);
      while(aux != '('){
        posfixa[j] = aux;
        j++;
        desempilha(pilha,&aux);
      }
    }
    else if(infixa[i] == '+' || infixa[i] == '-'){
      desempilha(pilha,&aux);
      while(aux != '('){
        posfixa[j] = aux;
        j++;
        desempilha(pilha,&aux);
      }
      stack_push(pilha,aux);
      stack_push(pilha,infixa[i]);
    }
    else if(infixa[i] == '*' || infixa[i] == '/'){
      desempilha(pilha,&aux);
      while(aux != '(' && aux != '+' && aux != '-'){
        posfixa[j] = aux;
        j++;
        desempilha(pilha,&aux);
      }
      stack_push(pilha,aux);
      stack_push(pilha,infixa[i]);
    }
    else{
      posfixa[j] = infixa[i];
      j++;
    }
  }
  posfixa[j] = '\0';
  return posfixa;
}


int main(void){
  printf("\n<< EQUAÇÕES >>\n");
  char infixa[MAX] = {'\0'};
  printf("Digite uma expressão matemática começando por '('\n");
  fgets(infixa,MAX,stdin);
  infixa[strcspn(infixa, "\n")] = '\0';

  char *posfixa = infixaParaPosfixa(infixa);

  printf("Expressão posfixa: \n");
  for(int i = 0; posfixa[i]!='\0'; i++)
    printf("%c",posfixa[i]);
  printf("\n");


return 0;
}

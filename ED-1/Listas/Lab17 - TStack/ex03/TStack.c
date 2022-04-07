#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TStack.h"

struct TStack
{
    char *data; //Ponteiro para os caracteres armazenados
    int qtd;    //Quantidade atual
    int MAX;    //Quantidade máxima suportada.
};

/*
*@brief Cria a pilha
*/
TStack *stack_create(int tamanho){
    TStack *st = malloc(sizeof(TStack));
    if(st != NULL){
        st->qtd = 0;
        st->MAX = tamanho;
        st->data = malloc(tamanho*sizeof(char));
    }
    return st;
}//stack_create

/*
*@brief Libera a pilha
*/
int stack_free(TStack *st){
    if(st == NULL) return INVALID_NULL_POINTER;
    free(st->data);
    free(st);
    return SUCCESS;
}//stack_free

/*
*@brief Insere um array de caracteres na pilha
*/
int stack_push(TStack *st, char *palavra){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    else if(strlen(palavra) > st->MAX) return OUT_OF_RANGE;
    
    for(int i = 0; i < strlen(palavra); i++){
      st->data[st->qtd] = palavra[i];
      st->qtd++;
    }
    st->qtd--; //Tiro o '\0'
    return SUCCESS;
}//stack_push

/*
*@brief Apaga o último caracter inserido
*/
int stack_pop(TStack *st){
  if(st == NULL) return INVALID_NULL_POINTER;
  else if(st->data == NULL) return OUT_OF_MEMORY;
  else if(st->qtd == 0) return EMPTY_STACK;

  st->qtd--;
  return SUCCESS;
}//stack_pop

/*
*@brief Retorna o caracter no topo da pilha
*/
int stack_top(TStack *st, char *caracter){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    else if(st->qtd == 0) return EMPTY_STACK;

    *caracter = st->data[st->qtd];
    return SUCCESS;
}//stack_top

/*
*@brief Verifica se a lista está vazia
*/
int stack_empty(TStack *st){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    else if(st->qtd == 0) return SUCCESS;
    else return -6;
}//stack_empty

/*
*@brief Verifica se a lista está cheia
*/
int stack_full(TStack *st){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    else if(st->qtd == st->MAX) return SUCCESS;
    else return -6;
}//stack_full

int stack_print(TStack *st){
  if(st == NULL) return INVALID_NULL_POINTER;
  else if(st->data == NULL) return OUT_OF_MEMORY;

  printf("\n--------------------------------\n");
  for(int i = st->qtd; i >= 0 ;i--)
    printf("%c\n",st->data[i]);
  printf("\n--------------------------------\n");

  return SUCCESS; 
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TStackPontos.h"

struct TStackPontos
{
    PONTOS *data; //Ponteiro para os valores armazenados
    int qtd;    //Quantidade atual
    int maximo;    //Quantidade máxima suportada.
};
/*
*@brief Cria a pilha de  valores
*/
TStackPontos *stack_create_int(int tamanho){
    TStackPontos *st = malloc(sizeof(TStackPontos));
    if(st != NULL){
        st->qtd = 0;
        st->maximo = tamanho;
        st->data = malloc(tamanho*sizeof(PONTOS));
    }
    return st;
}//stack_create_int

/*
*@brief Libera a pilha de valores
*/
int stack_free_int(TStackPontos *st){
    if(st == NULL) return INVALID_NULL_POINTER;
    free(st->data);
    free(st);
    return SUCCESS;
}//stack_free_int

/*
*@brief Insere elementos
*/
int stack_push_int(TStackPontos *st,PONTOS valor){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    
    //A pilha,internamente, funcionará como um vetor
    st->data[st->qtd] = valor;
    st->qtd++;

    return SUCCESS;
}//stack_push_int

/*
*@brief Apaga o último valor inserido
*/
int stack_pop_int(TStackPontos *st){
  if(st == NULL) return INVALID_NULL_POINTER;
  else if(st->data == NULL) return OUT_OF_MEMORY;
  else if(st->qtd == 0) return EMPTY_STACK;

  st->qtd--;
  return SUCCESS;
}//stack_pop_int

/*
*@brief Retorna o caracter no topo da pilha
*/
int stack_top_int(TStackPontos *st, PONTOS *valor){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    else if(st->qtd == 0) return EMPTY_STACK;

    *valor = st->data[st->qtd-1];
    return SUCCESS;
}//stack_top_int

/*
*@brief Verifica se a lista está vazia
*/
int stack_empty_int(TStackPontos *st){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    else if(st->qtd == 0) return SUCCESS;
    else return -6;
}//stack_empty_int

/*
*@brief Verifica se a lista está cheia
*/
int stack_full_int(TStackPontos *st){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    else if(st->qtd == st->maximo) return SUCCESS;
    else return -6;
}//stack_full_int

int stack_print_int(TStackPontos *st){
  if(st == NULL) return INVALID_NULL_POINTER;
  else if(st->data == NULL) return OUT_OF_MEMORY;

  printf("\n--------------------------------\n");
  for(int i = st->qtd; i >= 0 ;i--)
    printf("P(%d,%d) = %d\n",st->data[i].x, st->data[i].y, st->data[i].valor);
  printf("\n--------------------------------\n");

  return SUCCESS; 
}

int desempilhaInt(TStackPontos *st, PONTOS *valor){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    else if(st->qtd == 0) return EMPTY_STACK;
    else{
        *valor = st->data[(st->qtd)-1];
        st->qtd = st->qtd - 1;
        
        return SUCCESS;
    }
}
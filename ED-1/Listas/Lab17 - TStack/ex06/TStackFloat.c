#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TStackFloat.h"

struct TStackFloat
{
    float *data; //Ponteiro para os valores armazenados
    int qtd;    //Quantidade atual
    int maximo;    //Quantidade máxima suportada.
};


/*
*@brief Cria a pilha de  valores
*/
TStackFloat *stack_create_float(int tamanho){
    TStackFloat *st = malloc(sizeof(TStackFloat));
    if(st != NULL){
        st->qtd = 0;
        st->maximo = tamanho;
        st->data = malloc(tamanho*sizeof(float));
    }
    return st;
}//stack_create_float

/*
*@brief Libera a pilha de valores
*/
int stack_free_float(TStackFloat *st){
    if(st == NULL) return INVALID_NULL_POINTER;
    free(st->data);
    free(st);
    return SUCCESS;
}//stack_free_float

/*
*@brief Insere elementos
*/
int stack_push_float(TStackFloat *st,float valor){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    
    //A pilha,internamente, funcionará como um vetor
    st->data[st->qtd] = valor;
    st->qtd++;

    return SUCCESS;
}//stack_push_float

/*
*@brief Apaga o último valor inserido
*/
int stack_pop_float(TStackFloat *st){
  if(st == NULL) return INVALID_NULL_POINTER;
  else if(st->data == NULL) return OUT_OF_MEMORY;
  else if(st->qtd == 0) return EMPTY_STACK;

  st->qtd--;
  return SUCCESS;
}//stack_pop_float

/*
*@brief Retorna o caracter no topo da pilha
*/
int stack_top_float(TStackFloat *st, float *valor){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    else if(st->qtd == 0) return EMPTY_STACK;

    *valor = st->data[st->qtd-1];
    return SUCCESS;
}//stack_top_float

/*
*@brief Verifica se a lista está vazia
*/
int stack_empty_float(TStackFloat *st){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    else if(st->qtd == 0) return SUCCESS;
    else return -6;
}//stack_empty_float

/*
*@brief Verifica se a lista está cheia
*/
int stack_full_float(TStackFloat *st){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    else if(st->qtd == st->maximo) return SUCCESS;
    else return -6;
}//stack_full_float

int stack_print_float(TStackFloat *st){
  if(st == NULL) return INVALID_NULL_POINTER;
  else if(st->data == NULL) return OUT_OF_MEMORY;

  printf("\n--------------------------------\n");
  for(int i = st->qtd; i >= 0 ;i--)
    printf("%f\n",st->data[i]);
  printf("\n--------------------------------\n");

  return SUCCESS; 
}

int desempilhaFloat(TStackFloat *st, float *valor){
    if(st == NULL) return INVALID_NULL_POINTER;
    else if(st->data == NULL) return OUT_OF_MEMORY;
    else if(st->qtd == 0) return EMPTY_STACK;
    else{
        *valor = st->data[(st->qtd)-1];
        st->qtd = st->qtd - 1;
        
        return SUCCESS;
    }
}
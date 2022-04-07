#include <stdio.h>
#include <stdlib.h>
#include "TDLinkedList.h"

typedef struct DLNode DLNode;

struct DLNode {
 struct aluno data;
 DLNode *next;
 DLNode *prev;
};

struct DlinkedList {
 DLNode *begin;
 DLNode *end;
 int size;
};

/*
*@brief Aloca na heap uma lista duplamente encadeada.
*/
List* list_create(void){
  List *list = NULL;
  list = malloc(sizeof(List));
  if(list != NULL){
    //O início e fim da lista apontam para NULL.
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;
  }
  return list;// Irá retornar NULL ou o endereço para a memória alocada na heap
}//list_create

/*
*@brief Libera espaço alocado na heap para a lista duplamente encadeada.
*/
int list_free(List *list){
  if(list == NULL)
    return INVALID_NULL_POINTER;
  DLNode *aux;
  aux = list->begin;
  while(aux!=NULL){
    list->begin = aux->next;
    free(aux);
    aux = list->begin;
  }
  free(list);
  return SUCCESS;
}//list_free

/*
*@brief Insere um elemento no início da lista
*/
int list_push_front(List *list, struct aluno al){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }
  DLNode *node;
  node = malloc(sizeof(DLNode));
  if (node == NULL)
    return OUT_OF_MEMORY;

  node->data = al;
  node->prev = NULL;
  node->next = list->begin;

  if(list->begin == NULL){
    //A lista está vazia
    list->begin = node;
    list->end = node;
    list->size = 1;
  }
  else{
    //A lista possui um nó
    list->begin->prev = node;
    list->begin = node;
    list->size++;
  }
  return SUCCESS;
}//list_push_front

/*
*@brief Insere um elemento no final da lista
*/
int list_push_back(List *list, struct aluno al){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }
  DLNode *node;
  node = malloc(sizeof(DLNode));
  if (node == NULL)
    return OUT_OF_MEMORY;
  
  node->data = al;
  node->next = NULL;
  node->prev = list->end;

  if(list->begin == NULL){
    //A lista está vazia
    list->begin = node;
    list->end = node;
    list->size = 1;
  }
  else{
    //A lista possui um nó
    list->end->next = node;
    list->end = node;
    list->size++;
  }
  return SUCCESS;
}//list_push_back

/*
*@brief Dada uma posição insere-se um elemento. Lembrando que diferente dos arrays,
*listas começam em 1.
*/
int list_insert(List *list, int pos, struct aluno al){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }

  //Se a posicao for negativa ou maior do que o tamanho + 1
  if(pos > list->size + 1 || pos<=0){
    return OUT_OF_RANGE;
  }

  DLNode *node = NULL;
  node = malloc(sizeof(DLNode));
  if (node == NULL)
    return OUT_OF_MEMORY;
  
  node->data = al;
  
  //Se inserirmos no início
  if(pos==1){

    node->prev = NULL;
    node->next = list->begin;

    if(list->begin == NULL){
      //A lista está vazia
      list->begin = node;
      list->end = node;
      list->size = 1;
      return SUCCESS;
    }

    else{
      //A lista possui um nó
      list->begin->prev = node;
      list->begin = node;
      list->size++;
      return SUCCESS;
    }
  }


  //Se inserirmos no final
  else if(pos==list->size + 1){

    node->next = NULL;
    node->prev = list->end;

    if(list->begin == NULL){
      //A lista está vazia
      list->begin = node;
      list->end = node;
      list->size = 1;
    }
    else{
      //A lista possui um nó
      list->end->next = node;
      list->end = node;
      list->size++;
    }
    return SUCCESS;
  }

  //Qualquer outra posicao entre list->begin e list->end
  else{
    int contador = 1;
    DLNode *aux;
    aux = list->begin;
    while(contador < pos -1){
      aux = aux->next;
      contador+=1;
    }
    node->prev = aux;
    node->next = aux->next;
    aux->next->prev = node;
    aux->next = node;
    return SUCCESS;
  }
}//list_insert

/*
*@brief Retorna o tamanho da lista
*/
int list_size(List *list){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }
  return list->size;
}//list_size

/*
*@brief Remove o primeiro elemento
*/
int list_pop_front(List *list){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }
  //Se a lista está vazia.
  if(list->begin == NULL){
    return EMPTY_LIST;
  }
  //aux aponta para o elemento que vamos remover
  DLNode *aux = NULL;
  aux = list->begin;
  //Cabeça da lista aponta para o próximo elemento
  list->begin = list->begin->next;
  //O prev desse elemento passa a apontar para NULL
  list->begin->prev = NULL;
  free(aux);
  return SUCCESS;
}//list_pop_front

/*
*@brief Remove o último elemento
*/
int list_pop_back(List *list){
    if(list == NULL){
    return INVALID_NULL_POINTER;
  }
  //Se a lista está vazia.
  if(list->begin == NULL){
    return EMPTY_LIST;
  }
  //aux aponta para o elemento que vamos remover
  DLNode *aux = NULL;
  aux = list->end;
  list->end = list->end->prev;
  list->end->next = NULL;
  free(aux);
  return SUCCESS;
}//list_pop_back

/*
*@brief Remove um elemento da lista com base em sua posição
*/
int list_erase(List *list, int pos){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }
  if(list->begin == NULL){
    return EMPTY_LIST;
  }
  if ((pos <= 0) || (pos > list->size)){
    return OUT_OF_RANGE;
  }
  if(pos == 1){ //Eliminado o primeiro elemento
    DLNode *aux;
    aux = list->begin;
    //Cabeça da lista aponta para o próximo elemento
    list->begin = list->begin->next;
    //O prev desse elemento passa a apontar para NULL
    list->begin->prev = NULL;
    free(aux);
    return SUCCESS;
  }
  else if(pos == list->size){//Removendo o último elemento
    DLNode *aux;
    aux = list->end;
    list->end = list->end->prev;
    list->end->next = NULL;
    free(aux);
    return SUCCESS;
  }
  else{
    DLNode *aux;
    int contador = 1;
    aux = list->begin;
    while((aux!=NULL) && (contador < pos)){
      aux = aux->next;
      contador++;
    }
    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;
    free(aux);
    return SUCCESS;
  }
}//list_erase

/*
*@brief Encontra um elemento com base em sua posição
*/
int list_find_pos(List *list, int pos, struct aluno *al){
  if(list == NULL)
    return INVALID_NULL_POINTER;
  if(list->begin == NULL)
    return EMPTY_LIST;
  if((pos < 1) || (pos > list->size))
    return OUT_OF_RANGE;
  
  DLNode *aux = list->begin;
  int contador = 1;
  while((aux!=NULL) && (contador != pos)){
    aux = aux->next;
    contador++;
  }
  if(aux == NULL)
    return ELEM_NOT_FOUND;
  else{
    *al = aux->data;
    return SUCCESS;
  }
}//list_find_pos

/*
*@brief Encontra um elemento com base em sua matrícula
*/
int list_find_mat(List *list, int nmat, struct aluno *al){
  if(list == NULL)
    return INVALID_NULL_POINTER;
  if(list->begin==NULL)
    return EMPTY_LIST;
  
  DLNode *aux;
  aux = list->begin;
  while((aux->data.matricula != nmat) && (aux!=NULL))
    aux = aux->next;

  if(aux == NULL)
    return ELEM_NOT_FOUND;
  else{
    *al = aux->data;
    return SUCCESS;
  }
}//list_find_mat

/*
*@brief Encontra o elemento na cabeça da lista
*/
int list_front(List *list, struct aluno *al){
  if(list == NULL)
    return INVALID_NULL_POINTER;
  if(list->begin == NULL)
    return EMPTY_LIST;

  *al = list->begin->data;
  return SUCCESS;
}//list_front

/*
*@brief Encontra o elemento no fim da lista
*/
int list_back(List *list, struct aluno *al){
  if(list == NULL)
    return INVALID_NULL_POINTER;
  if(list->begin == NULL)
    return EMPTY_LIST;

  *al = list->end->data;
  return SUCCESS;
}//list_back

/*
*@brief Encontra a posição de um elemento com base em sua matrícula
*/
int list_get_pos(List *list, int nmat, int *pos){
  if(list == NULL)
    return INVALID_NULL_POINTER;
  if(list->begin == NULL)
    return EMPTY_LIST;

  DLNode *aux;
  aux = list->begin;
  int contador = 1;
  while((aux!=NULL) && (aux->data.matricula != nmat)){
    aux = aux->next;
    contador++;
  }
  if(aux == NULL) return ELEM_NOT_FOUND;
  else{
    *pos = contador;
    return SUCCESS;
  }
}//list_get_pos

/*
*@brief Imprime a lista de frente para trás
*/
int list_print_forward(List *list)
{
  if (list == NULL)
    return INVALID_NULL_POINTER;
  DLNode *aux;
  aux = list->begin;
  printf("\nImprimindo a lista\n");

  while (aux != NULL)
  {
    printf("\n------------------\n");
    printf("Matricula: %d\n", aux->data.matricula);
    printf("Nome: %s\n", aux->data.nome);
    printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

    aux = aux->next;
  }
  printf("\nFim da lista \n");
  return SUCCESS;
}//list_print_forward

/*
*@brief Imprime a lista de trás para frente.
*/
int list_print_reverse(List *list)
{
  if (list == NULL)
      return INVALID_NULL_POINTER;
  DLNode *aux;
  aux = list->end;
  printf("\nImprimindo a lista - reverso\n");

  while (aux != NULL)
  {
      printf("\n------------------\n");
      printf("Matricula: %d\n", aux->data.matricula);
      printf("Nome: %s\n", aux->data.nome);
      printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

      aux = aux->prev;
  }
  printf("\nFim da lista \n");
  return SUCCESS;
}//list_print_reverse
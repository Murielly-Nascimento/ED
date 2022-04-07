#include <stdio.h>
#include <stdlib.h>
#include "TSeqList.h"

struct list
{
  int qtd;
  struct aluno data[MAX];
};

List* create_list(void)
{
  List *li = malloc(sizeof(List));
 
  if(li != NULL)
    li->qtd = 0;

  return li;
}

int free_list(List* li)
{
  free(li);
  return SUCCESS;
}

int consult_list_pos(List* li, int pos, struct aluno *al)
{
  if(li == NULL)
    return INVALID_NULL_POINTER;

  if(li->qtd == 0)
    return EMPTY_LIST;
  
  if(pos > li->qtd || pos <= 0)
    return OUT_OF_RANGE;
  
  *al = li->data[pos-1];
  return SUCCESS;
}

int consult_list_mat(List* li, int mat, struct aluno *al){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  
  if(li->qtd == 0)
    return EMPTY_LIST;
  
  int contador = 0;
  while(li->data[contador].matricula != mat && contador < li->qtd){
    contador++;
  }
  if(contador == li->qtd)
    return ELEM_NOT_FOUND;
  
  *al = li->data[contador];
  return SUCCESS;
}

int list_back(List* li, struct aluno *al){
  if(li == NULL)
    return INVALID_NULL_POINTER;

  if(li->qtd == 0)
    return EMPTY_LIST;

  *al = li->data[li->qtd-1];
  return SUCCESS;
}

int list_push_back(List* li, struct aluno al){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  
  if(li->qtd == MAX)
    return OUT_OF_RANGE;

  li->data[li->qtd] = al;
  li->qtd++;
  return SUCCESS;
}

int list_push_front(List* li, struct aluno al){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  
  if(li->qtd == MAX)
    return OUT_OF_RANGE;
  
  for(int i = li->qtd-1; i>=0 ;i--)
    li->data[i+1] = li->data[i];
  
  li->data[0] = al;
  li->qtd++;
  return SUCCESS;
}

int list_insert_sort(List* li, struct aluno al){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  
  if(li->qtd == MAX)
    return OUT_OF_RANGE;

  int i = 0;
  while(i < li->qtd && li->data[i].matricula < al.matricula)
    i++;
  
  for(int j = li->qtd-1; j>=i; j--)
    li->data[j+1] = li->data[j];
  
  li->data[i] = al;
  li->qtd++;
  return SUCCESS;
}

int list_erase_data(List* li, int mat){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  
  if(li->qtd == 0)
    return EMPTY_LIST;
  
  int i = 0;
  while(i < li->qtd && li->data[i].matricula != mat)
    i++;
  
  if(i == li->qtd)
    return ELEM_NOT_FOUND;
  
  for(int j = i; j < li->qtd-1; j++)
    li->data[j] = li->data[j+1];
  li->qtd--;
  return SUCCESS;
}

int pop_front(List* li){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  
  if(li->qtd == 0)
    return EMPTY_LIST;

  for(int i = 0; i< li->qtd-1; i++)
    li->data[i] = li->data[i+1];
  
  li->qtd--;
  return SUCCESS;
}

int pop_back(List* li){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  
  if(li->qtd == 0)
    return EMPTY_LIST;
  
  li->qtd--;
  return SUCCESS;
}

int list_size(List* li){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  
  return li->qtd;
}

int full_list(List* li){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  return(li->qtd == MAX); 
}

int empty_list(List* li){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  return(li->qtd == 0);
}

int print_list(List *li){
  if(li == NULL) 
    return INVALID_NULL_POINTER;
  int i = 0;
  for(i =0; i<li->qtd; i++){
    printf("Matricula: %d\n",li->data[i].matricula);
    printf("Nome: %s\n",   li->data[i].nome);
    printf("Notas: %f %f %f\n",li->data[i].n1,li->data[i].n2,li->data[i].n3);
    printf("-------------------------------\n");
  }
  return SUCCESS;
}

int print_list_reverse(List *li){
  if(li == NULL) 
    return INVALID_NULL_POINTER;
  int i = 0;
  for(i =li->qtd-1; i>=0; i--){
    printf("Matricula: %d\n",li->data[i].matricula);
    printf("Nome: %s\n",   li->data[i].nome);
    printf("Notas: %f %f %f\n",li->data[i].n1,li->data[i].n2,li->data[i].n3);
    printf("-------------------------------\n");
  }
  return SUCCESS;
}

int optimal_list_erase(List* li, int mat){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  
  if(li->qtd == 0)
    return EMPTY_LIST;

  int i = 0;
  while(i<li->qtd && li->data[i].matricula != mat)
    i++;
  if(i == li->qtd)
    return 0;
  
  li->qtd--;
  li->data[i] = li->data[li->qtd];
  return SUCCESS;
}
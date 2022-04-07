#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "TVarSeqList.h"

struct list{
  int qtd;
  int tamanho_inicial;
  int tamanho_atual;
  struct aluno *dados;
};

List* create_list(int size){
  List *li = NULL;
  li = (List*)malloc(sizeof(struct list));
  if(li!=NULL){
    li->qtd = 0;
    li->tamanho_inicial = size;
    li->tamanho_atual = size;
  }
  li->dados = (struct aluno*)malloc(size*sizeof(struct aluno));
  return li;
}

int free_list(List *li){
  free(li->dados);
  free(li);
  return SUCCESS;
}

int list_push_back(List *li, struct aluno al){
  if(li==NULL) 
    return INVALID_NULL_POINTER;
  if(li->qtd == li->tamanho_atual){
    li->tamanho_atual += li->tamanho_inicial;
    li->dados = realloc(li->dados,li->tamanho_atual*sizeof(struct aluno));
  } 
  li->dados[li->qtd] = al;
  li->qtd ++;
  return SUCCESS; 
}

int list_push_front(List *li, struct aluno al){
  if(li==NULL) 
    return INVALID_NULL_POINTER;
  if(li->qtd == li->tamanho_atual){
    li->tamanho_atual += li->tamanho_inicial;
    li->dados = realloc(li->dados,li->tamanho_atual*sizeof(struct aluno));
  }
  int i = 0;
  for(i = li->qtd-1; i>=0; i--)
    li->dados[i+1] = li->dados[i];
  li->dados[0] = al;
  li->qtd++;
  return SUCCESS;
}

int list_insert_sort(List *li, struct aluno al){
  if(li==NULL) 
    return INVALID_NULL_POINTER;
  if(li->qtd == li->tamanho_atual){
    li->tamanho_atual += li->tamanho_inicial;
    li->dados = realloc(li->dados,li->tamanho_atual*sizeof(struct aluno));
  }
    
  int k =0,i=0;
  while(i<li->qtd && li->dados[i].matricula < al.matricula) 
    i++;

  for(k = li->qtd-1; k>=i; k--)
    li->dados[k+1] = li->dados[k];
  
  li->dados[i] = al;
  li->qtd++;
  return SUCCESS;
}

int list_find_pos(List *li, int pos, struct aluno *al){
  if(li == NULL || pos <=0 || pos>li->qtd) 
    return -1;
  *al = li->dados[pos-1];
  return 0;
}

int list_find_mat(List *li, int mat, struct aluno *al){
  if(li==NULL) 
    return -1;
  int i = 0;
  while(i<li->qtd && li->dados[i].matricula != mat) 
    i++;
  if(i == li->qtd) 
    return -1;
  
  *al = li->dados[i];
  return 0;
}

int pop_front(List *li){
  if(li==NULL)
    return INVALID_NULL_POINTER;
  if(li->qtd == 0)
    return EMPTY_LIST;
  int k = 0;
  for(k = 0; k<li->qtd-1; k++)
    li->dados[k] = li->dados[k+1];
  li->qtd--;
  return SUCCESS;
}

int pop_back(List *li){
  if(li==NULL)
    return INVALID_NULL_POINTER;
  if(li->qtd == 0)
    return EMPTY_LIST;
  li->qtd--;
  return SUCCESS;
}

int list_erase_data(List *li, int mat){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  if(li->qtd == 0)
    return EMPTY_LIST;
  int k =0,i=0;
  while(i<li->qtd && li->dados[i].matricula != mat)
    i++;
  if(i == li->qtd)
    return ELEM_NOT_FOUND;
  for(k = i; k<li->qtd-1; k++)
    li->dados[k] = li->dados[k+1];
  li->qtd--;
  return SUCCESS;
}

int optimal_list_erase(List *li, int mat){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  if(li->qtd == 0)
    return EMPTY_LIST;
  int k =0,i=0;
  while(i<li->qtd && li->dados[i].matricula != mat)
    i++;
  if(i == li->qtd)
    return ELEM_NOT_FOUND;
  
  li->qtd--;
  li->dados[i] = li->dados[li->qtd];
  return SUCCESS;
}


int list_size(List *li){
  if(li == NULL)
    return INVALID_NULL_POINTER;
  else 
    return li->qtd;
}

int full_list(List *li){
  if(li == NULL || (li->qtd != li->tamanho_atual))
    return INVALID_NULL_POINTER;
  return SUCCESS;
}

int empty_list(List *li){
  if(li == NULL || (li->qtd !=0))
    return INVALID_NULL_POINTER;
  return SUCCESS;
}

int print_list(List *li){
  if(li == NULL) 
    return INVALID_NULL_POINTER;
  int i = 0;
  for(i =0; i<li->qtd; i++){
    printf("Matricula: %d\n",li->dados[i].matricula);
    printf("Nome: %s\n",   li->   dados[i].nome);
    printf("Notas: %f %f %f\n",li->dados[i].n1,li->dados[i].n2,li->dados[i].n3);
    printf("-------------------------------\n");
  }
  return SUCCESS;
}

int compact_list(List *li){
  if(li == NULL) 
    return INVALID_NULL_POINTER;
  li->tamanho_atual = (ceil(li->qtd/li->tamanho_inicial) * li->tamanho_inicial) + 1;
  li->dados = realloc(li->dados,li->tamanho_atual*sizeof(struct aluno));
  return SUCCESS;
}



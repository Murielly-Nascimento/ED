#include <stdio.h>
#include <stdlib.h>
#include "TCList.h"


typedef struct clistnode CList_node;

struct circlist{
    CList_node *end;
};

struct clistnode
{
    struct aluno data;
    CList_node *next;
};

/*
*@brief Aloca na heap uma lista circular.
*/
CircList* clist_create(void){
      CircList *clist = NULL;
  clist = malloc(sizeof(CircList));
  if(clist!=NULL){
    clist->end = NULL;
  }
  return clist;
}//clist_create.

/*
*@brief Libera o espaço alocado na heap para a lista circular.
*/
int clist_free(CircList *clist){
  //Verifica se o ponteiro aponta para NULL
  if(clist == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Usamos um ponteiro auxiliar para liberar o espaço alocado na heap
    CList_node *begin, *aux;
    begin = clist -> end;
    begin = begin->next;

    aux = begin;

    while(aux != clist->end){
      begin = aux->next;
      free(aux);
      aux = begin;
    }
    free(begin);
    //Uma vez liberado os nodes, liberamos a lista.
    free(clist);
    return SUCCESS;
  }
}//clist_free.

/*
*@brief Insere no início da lista um elemento
*/
int clist_push_front(CircList *clist, struct aluno al){
  if(clist == NULL){
    return INVALID_NULL_POINTER;
  }else{
    CList_node *node;
    node = malloc(sizeof(CList_node));
    if(node == NULL){
      return OUT_OF_MEMORY;
    }

    node->data = al;

    if(clist->end == NULL){
        node->next = node;
        clist->end = node;
    }
    else{
        node->next = clist->end->next;
        clist->end->next = node;
    }
    return SUCCESS;
  }
}//clist_push_front

/*
*@brief Insere no final da lista um elemento
*/
int clist_push_back(CircList *clist, struct aluno al){
  if(clist == NULL){
    return INVALID_NULL_POINTER;
  }else{
    CList_node *node;
     node = malloc(sizeof(CList_node));
    if(node == NULL){
      return OUT_OF_MEMORY;
    }
    node->data = al;

    if(clist->end == NULL){
        node->next = node;
        clist->end = node;
    }
    else{
        node->next = clist->end->next;
        clist->end->next = node;
        clist->end = node;
    }
    return SUCCESS;
  }
}//clist_push_back

/*
*@brief Remove o primeiro elemento da lista
*/
int clist_pop_front(CircList *clist){
  if(clist == NULL){
    return INVALID_NULL_POINTER;
  }else{
    if(clist->end == NULL){
      return OUT_OF_RANGE;
    }
    CList_node *aux = NULL;
    aux = clist->end->next;
    clist->end->next = aux->next;
    clist->end = aux->next;
    free(aux);

    return SUCCESS;
  }
}//clist_pop_front

/*
*@brief Remove o último elemento da lista
*/
int clist_pop_back(CircList *clist){
  if(clist == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Se a lista está vazia
    if(clist->end == NULL){
      return OUT_OF_RANGE;
    }

    CList_node *aux = clist->end, *aux2 = NULL;

    while(aux->next != clist->end){
        aux = aux->next;
    }
    aux2 = clist->end;
    aux->next = clist->end->next;
    clist->end = aux;
    free(aux2);

    return SUCCESS;
  }
}//clist_pop_back

/*
*@brief Imprime a lista
*/
int clist_print(CircList *clist){
  if (clist == NULL){
    return INVALID_NULL_POINTER;
  }else{
    CList_node *aux;
    aux = clist->end->next;

    while (aux != clist->end){
      printf("\n------------------\n");
      printf("Matricula: %d\n", aux->data.matricula);
      printf("Nome: %s\n", aux->data.nome);
      printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

      aux = aux->next;
    }
    printf("\n------------------\n");
    printf("Matricula: %d\n", aux->data.matricula);
    printf("Nome: %s\n", aux->data.nome);
    printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);
    printf("\nFim da lista \n");

    return SUCCESS;
  }
}//list_print




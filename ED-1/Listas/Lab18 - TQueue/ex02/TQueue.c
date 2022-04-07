#include <stdio.h>
#include <stdlib.h>
#include "TQueue.h"

typedef struct DQNode DQNode;

struct TQueue{
    DQNode *begin;
    DQNode *end;
    int size;
};

struct DQNode
{
    struct aluno data;
    DQNode *next;
};


TQueue* queue_create(void){
    TQueue *queue = malloc(sizeof(TQueue));
    if(queue != NULL){
        queue->begin = NULL;
        queue->end = NULL;
        queue->size = 0;
    }
    return queue;
}

int queue_free(TQueue *queue){
    if(queue == NULL) return INVALID_NULL_POINTER;
    DQNode *aux = queue->begin;
    while(aux!=NULL){
        queue->begin = aux->next;
        free(aux);
        aux = queue->begin;
    }
    free(queue);
    return SUCCESS;
}

int queue_push(TQueue *queue, struct aluno al){

    if(queue == NULL) return INVALID_NULL_POINTER;
    if(queue->begin == NULL){
        DQNode *aux = malloc(sizeof(DQNode));
        aux->data = al;
        aux->next = NULL;
        queue->begin = aux;
        queue->end = aux;
        queue->size++;
        return SUCCESS;
    }
    else{
        DQNode *aux = malloc(sizeof(DQNode));
        aux->data = al;
        aux->next = NULL; 
        queue->end->next = aux;
        queue->end = aux;
        queue->size++;
        return SUCCESS;
    }
}

int queue_pop(TQueue *queue){
    if(queue == NULL) return INVALID_NULL_POINTER;
    if(queue->begin == NULL) return EMPTY_QUEUE;
    DQNode *aux = queue->begin;
    queue->begin = aux->next;
    free(aux);
    queue->size--;
    return SUCCESS;
}

int queue_top(TQueue *queue,struct aluno *al){
    if(queue == NULL) return INVALID_NULL_POINTER;
    if(queue->begin == NULL) return EMPTY_QUEUE;
    *al = queue->begin->data;
    return SUCCESS;
}

int queue_print(TQueue *queue){
    if(queue == NULL) return INVALID_NULL_POINTER;
    if(queue->begin == NULL) return EMPTY_QUEUE;

    DQNode *aux = queue->begin;
    printf("\nImprimindo a fila (tamanho %d)\n", queue->size);

    while (aux != NULL){
      printf("\n------------------\n");
      printf("Matricula: %d\n", aux->data.matricula);
      printf("Nome: %s\n", aux->data.nome);
      printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

      aux = aux->next;
    }
    printf("\nFim da fila \n");
    return SUCCESS; 
}
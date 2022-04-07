#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TSeqQueue.h"

struct TSeqQueue
{
    int front;
    int rear;
    int tamanho_atual;
    int tamanho_maximo;
    int qtd;
    struct aluno *data;
};

TSeqQueue* queue_create(int tamanho){
    TSeqQueue *queue = malloc(sizeof(TSeqQueue));
    if(queue != NULL){
        queue->front = 0;
        queue->rear = 0;
        queue->tamanho_atual = tamanho;
        queue->tamanho_maximo = tamanho;
        queue->qtd = 0;
        queue->data = malloc(tamanho*sizeof(struct aluno));
    }
    return queue;
}

int queue_free(TSeqQueue *queue){
    if(queue == NULL) return INVALID_NULL_POINTER;
    free(queue->data);
    free(queue);
    return SUCCESS;
}

int queue_push(TSeqQueue *queue, struct aluno al){
    if(queue == NULL) return INVALID_NULL_POINTER;
    if(queue->qtd == queue->tamanho_atual){
        queue->tamanho_atual+=queue->tamanho_maximo;
        queue->data = realloc(queue->data,queue->tamanho_atual*sizeof(struct aluno));
        queue->data[queue->rear] = al;
        queue->rear++;
    }
    else if(queue->rear == queue->tamanho_atual && queue->front!=0){
        queue->rear = (queue->rear + 1)%(queue->tamanho_atual);
        queue->data[queue->rear] = al;
    }
    else{
        queue->data[queue->rear] = al;
        queue->rear++;
    }
    queue->qtd++;
    return SUCCESS;
}

int queue_pop(TSeqQueue *queue){
    if(queue == NULL) return INVALID_NULL_POINTER;
    if(queue->tamanho_atual==0) return EMPTY_QUEUE;
    if(queue->front == queue->tamanho_atual){
        queue->front = (queue->front + 1)%(queue->tamanho_atual);
        return SUCCESS;
    }
    queue->front++;
    queue->qtd--;
    return SUCCESS;
}

int queue_top(TSeqQueue *queue,struct aluno *al){
    if(queue == NULL) return INVALID_NULL_POINTER;
    if(queue->tamanho_atual==0) return EMPTY_QUEUE;
    *al = queue->data[queue->front];
    return SUCCESS;
}

int queue_empty(TSeqQueue *queue){
    if(queue == NULL) return INVALID_NULL_POINTER;
    if(queue->tamanho_atual==0) return SUCCESS;
    else return -6;
}

int queue_full(TSeqQueue *queue){
    if(queue == NULL) return INVALID_NULL_POINTER;
    if(queue->rear==queue->front) return SUCCESS;
    else return -6;
}

int queue_print(TSeqQueue *queue){
    if(queue == NULL) return INVALID_NULL_POINTER;
    if(queue->tamanho_atual==0) return EMPTY_QUEUE;

    int aux = queue->front;

    while (aux != queue->rear){
      printf("\n------------------\n");
      printf("Matricula: %d\n", queue->data[aux].matricula);
      printf("Nome: %s\n", queue->data[aux].nome);
      printf("Notas: %f; %f; %f;\n", queue->data[aux].n1, queue->data[aux].n2, queue->data[aux].n3);

      if(queue->front > queue->rear && aux==queue->tamanho_atual)
        aux = 0;
      aux++;
    }
    printf("\nFim da fila \n");
    return SUCCESS; 
}

int compact_list(TSeqQueue *queue){
    if(queue == NULL) return INVALID_NULL_POINTER;
    queue->tamanho_atual = ceil(queue->qtd/queue->tamanho_maximo)*queue->tamanho_maximo;
    queue->data = realloc(queue->data,queue->tamanho_atual*sizeof(struct aluno));
    return SUCCESS;
}
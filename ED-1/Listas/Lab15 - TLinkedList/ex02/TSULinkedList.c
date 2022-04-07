#include <stdio.h>
#include <stdlib.h>
#include "TSULinkedList.h"

//Estruturas usadas
typedef struct LIST_NODE LIST_NODE;

struct LINKED_LIST{
  LIST_NODE *head;
  int size;
  int sorted;
};

struct LIST_NODE{
  struct ALUNO data;
  LIST_NODE *next;
};

/*
*@brief Aloca na heap uma lista encadeada.
*/
LIST* list_create(void){
  LIST *list = NULL;
  list = malloc(sizeof(LIST));
  if(list!=NULL){
    list->head = NULL;
    list->size = 0;
    list->sorted = SORTED;
  }
  return list;
}//list_create.

/*
*@brief Libera o espaço alocado na heap para a lista encadeada.
*/
int list_free(LIST *list){
  //Verifica se o ponteiro aponta para NULL
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Usamos um ponteiro auxiliar para liberar o espaço alocado na heap
    //list->head passa a apontar para o próximo node
    LIST_NODE *aux;
    aux = list -> head;
    while(aux != NULL){
      list->head = aux->next;
      free(aux);
      aux = list->head;
    }
    //Uma vez liberado os nodes, liberamos a lista.
    free(list);
    return SUCCESS;
  }
}//list_free.

/*
*@brief Insere no início da lista um elemento
*/
int list_push_front(LIST *list, struct ALUNO al){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Se a lista estiver ordenada só podemos usar a função list_insert_sorted
    if(list->sorted == SORTED){
      return SORTED;
    }
    LIST_NODE *node;
    node = malloc(sizeof(LIST_NODE));
    if(node == NULL){
      return OUT_OF_MEMORY;
    }
    //Faço a cabeça da lista apontar para o novo elemento e a antiga cabeça passa a ser 
    //o segundo elemento.
    node->data = al;
    node->next = list->head;
    list->head = node;
    list->size +=1;
    list->sorted = NOT_SORTED; 
    return SUCCESS;
  }
}//list_push_front

/*
*@brief Insere no final da lista um elemento
*/
int list_push_back(LIST *list, struct ALUNO al){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Se a lista estiver ordenada só podemos usar a função list_insert_sorted
    if(list->sorted == SORTED){
      return SORTED;
    }
    LIST_NODE *node;
     node = malloc(sizeof(LIST_NODE));
    if(node == NULL){
      return OUT_OF_MEMORY;
    }
    node->data = al;
    node->next = NULL;

    //Se a lista estiver vazia basta fazer a cabeça apontar para node.
    if(list->head == NULL){
      list->head = node;
      list->size +=1;
      list->sorted = NOT_SORTED;
    }
    else{
      //A lista terá ao menos um nó.
      //Uso aux para percorrer a lista até encontrar o último elemento.
      LIST_NODE *aux;
      aux = list->head;

      while(aux->next != NULL){
        aux = aux->next;
      }
      aux->next = node;
      list->size +=1;
      list->sorted = NOT_SORTED;
    }
    return SUCCESS;
  }
}//list_push_back

/*
*@brief Dada uma posição insere-se um elemento. Lembrando que diferente dos arrays,
*listas começam em 1.
*/
int list_insert(LIST *list, int pos, struct ALUNO al){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Se a lista estiver ordenada só podemos usar a função list_insert_sorted
    if(list->sorted == SORTED){
      return SORTED;
    }
    //Se a lista tiver tamanho 3, podemos inserir um elemento ao final dela, ou seja,
    //na quarta posição. Porém, a função falha se o usuário digitar uma posição maior
    //que o tamanho + 1.
    if(pos > list->size + 1 || pos<=0){
      return OUT_OF_RANGE;
    }
    LIST_NODE *node;
    node = malloc(sizeof(LIST_NODE));
    if(node == NULL){
      return OUT_OF_MEMORY;
    }
    node->data = al;

    //Se o usuário quiser inserir o elemento no inicio.
    if(pos == 1){
      node->next = list->head;
      list->head = node;
      list->size +=1;
      list->sorted = NOT_SORTED;
      return SUCCESS;
    }
    //Se o usuário digitar qualquer posicao 1 < posicao < tamanho + 1.
    else{
      //Listas começam em 1
      int posicao = 1;
      LIST_NODE *aux;
      aux = list->head;
      //Queremos inserir um elemento, possivelmente entre outros dois.
      //Devemos considerar para onde o aux->next aponta.
      while(posicao < pos - 1){
        aux = aux->next;
        posicao = posicao + 1;
      }
      node->next = aux->next;
      aux->next = node;
      list->size +=1;
      list->sorted = NOT_SORTED;
      return SUCCESS;
    }
  }
}//list_insert.

/*
*@brief Insere elementos ordenamente com base em sua matrícula.
*/
int list_insert_sorted(LIST *list, struct ALUNO al){
  if (list == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    //Se a lista não estiver ordenada não podemos usar essa função
    if(list->sorted == NOT_SORTED){
      return NOT_SORTED;
    }
    //Se a matrícula for maior que o tamanho da lista + 1.
    if(al.matricula > list_size(list) + 1){
      return OUT_OF_RANGE;
    }
    LIST_NODE *node;
    node = malloc(sizeof(LIST_NODE));
    if(node == NULL){
      return OUT_OF_MEMORY;
    }
    node->data = al;
    node->next = NULL;

    //Quando inserimos o aluno de matricula = 1
    if(al.matricula == 1){
      node->next = list->head;
      list->head = node;
      return SUCCESS;
    }
    
    int posicao = 1;
    LIST_NODE *aux;
    aux = list->head;
  
    while(posicao < al.matricula - 1){
      aux = aux->next;
      posicao = posicao + 1;
    }
    
    node->next = aux ->next;
    aux->next = node;
    return SUCCESS;

  }
}//list_insert_sorted

/*
*@brief Calcula o tamanho da lista
*/
int list_size(LIST *list){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    int contador = 0;
    LIST_NODE *aux = NULL;
    aux = list->head;
    while(aux != NULL){
      aux = aux->next;
      contador += 1;
    }
    return contador;
  }
}//list_size

/*
*@brief Remove o primeiro elemento da lista
*/
int list_pop_front(LIST *list){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Se a lista está vazia
    if(list->head == NULL){
      return OUT_OF_RANGE;
    }
    LIST_NODE *aux = NULL;
    aux = list->head;
    list->head = aux->next;
    free(aux);

    return SUCCESS;
  }
}//list_pop_front

/*
*@brief Remove o último elemento da lista
*/
int list_pop_back(LIST *list){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Se a lista está vazia
    if(list->head == NULL){
      return OUT_OF_RANGE;
    }
    //Vamos precisar de dois ponteiros
    //aux2 para descobrir o último elemento
    //aux para descobrir o penultimo
    LIST_NODE *aux = NULL,*aux2 = NULL;
    aux = list->head;
    aux2 = aux->next;

    while(aux2->next != NULL){
      aux = aux->next;
      aux2 = aux2->next;
    }

    //O penultimo elemento passa a apontar para NULL
    //O último elemento é removido.
    aux->next = NULL;
    free(aux2);
    return SUCCESS;
  }
}//list_pop_back

/*
*@brief Remove um elemento da lista com base na matrícula.
*/
int list_erase_data(LIST *list, int mat){
   if (list == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    //Se a lista está vazia
    if(list->head == NULL){
      return OUT_OF_RANGE;
    }

    //aux para o primeiro elemento.
    //aux2 para o segundo elemento.
    LIST_NODE *aux = NULL, *aux2 = NULL;
    aux = list->head;
    aux2 = aux->next;

    //Se o primeiro elementos é o que estamos buscando
    if(aux->data.matricula == mat){
      //Cabeça da lista passa a apontar para o próximo elemento
      //Removemos o primeiro.
      list->head = aux->next;
      free(aux);
      return SUCCESS;
    }

    int posicao = 1;

    //Percorremos a lista procurando a matrícula.
    while(aux2->data.matricula != mat && posicao <= list_size(list)){
      aux = aux->next;
      aux2 = aux2->next;
      posicao +=1;
    }
    //Se não encontramos o elemento.
    if(aux2 == NULL){
      return ELEM_NOT_FOUND;
    }
    //O elemento anterior passa a apontar para o próximo de aux2.
    aux->next = aux2->next;
    //Removemos aux2.
    free(aux2);
    return SUCCESS;
  }
}//list_erase_data

/*
*@brief Remove um elemento da lista com base na posicao.
*/
int list_erase_pos(LIST *list, int pos){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{

    //Se a lista está vazia ou a posicao desejada é maior do que o tamanho
    if(list->head == NULL || pos > list_size(list) || pos <=0){
      return OUT_OF_RANGE;
    }

    LIST_NODE *aux = NULL;

    //Se queremos eliminar o primeiro elemento
    if(pos == 1){
      aux = list->head;
      list->head = aux->next;
      free(aux);
      return SUCCESS;
    }
    else{
      int posicao = 1;
      LIST_NODE *aux2 = NULL;
      //aux para o primeiro elemento.
      //aux2 para o segundo elemento.
      aux = list->head;
      aux2 = aux->next;
  
      //aux2 começa na 2 posição
      //Se pos = 3, então while rodaria apenas uma vez.
      //aux2 passaria para a terceira posição e o laço termina
      //aux guarda o elemento anterior,no caso 2.
      while(posicao < pos - 1){
        aux = aux->next;
        aux2 = aux2->next;
        posicao = posicao + 1;
      }
      //Basta fazer com que aux->next aponte para o elemento depois de aux2 (aux2->next)
      //E remover aux2.
      aux->next = aux2->next;
      free(aux2);
      return SUCCESS;
    }
  }
}//list_erase_pos

/*
*@brief Descobre qual aluno está em determinada posição. Os dados são
*passados para a variável al.
*/
int list_find_pos(LIST *list, int pos, struct ALUNO *al){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Se a lista está vazia, ou se a posição é maior que o seu tamanho, ou se é negativa,ou igual a zero.
    if(list->head == NULL || pos > list_size(list) || pos<=0){
      return OUT_OF_RANGE;
    }
    LIST_NODE *aux;
    aux = list->head;
    //Se a posição for igual a um retornamos a cabeça da lista.
    if(pos == 1){
      *al = aux->data;
      return SUCCESS;
    }
    //Percorremos a lista
    for(int i = 2; i<=pos;i++){
      aux = aux->next;
    }
    //al recebe os dados que estão na posição
    *al = aux->data;
    return SUCCESS;
  }
}//list_find_pos

/*
*@brief Descobre quem é o aluno de nmatricula.
*/
int list_find_mat(LIST *list, int nmat, struct ALUNO *al){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Se a lista está vazia
    if(list->head == NULL){
      return OUT_OF_RANGE;
    }
    LIST_NODE *aux = NULL;
    aux = list->head;
    //Se a matricula desejada está na cabeça da lista.
    if(aux->data.matricula == nmat){
      *al = aux->data;
      return SUCCESS;
    }

    //Percorremos a lista enquanto não encontramos e não chegamos ao seu último elemento.
    int posicao = 1;
    while(aux->data.matricula != nmat && posicao <= list_size(list)){
      aux = aux->next;
      posicao +=1;
    }
    //Se o elemento não foi encontrado.
    if(aux == NULL){
      return ELEM_NOT_FOUND;
    }
    *al = aux->data;
    return SUCCESS;
  }
}//list_find_mat

/*
*@brief Descobre quem está na cabeça da lista.
*/
int list_front(LIST *list, struct ALUNO *al){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Se a lista está vazia
    if(list->head == NULL){
      return OUT_OF_RANGE;
    }
    LIST_NODE *aux = NULL;
    aux = list->head;
    *al = aux->data;
    return SUCCESS;
  }
}//list_front

/*
*@brief Descobre quem está no fim da lista.
*/
int list_back(LIST *list, struct ALUNO *al){
  if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Se a lista está vazia
    if(list->head == NULL){
      return OUT_OF_RANGE;
    }
    LIST_NODE *aux = NULL;
    aux = list->head;

    while(aux->next != NULL){
      aux = aux->next;
    }
    *al = aux->data;
    return SUCCESS;
  }
}//list_back

/*
*@brief Descobre em qual posicao o aluno de matricula 'n' está.
*/
int list_get_pos(LIST *list, int nmat, int *pos){
    if(list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    //Se a lista está vazia
    if(list->head == NULL){
      return OUT_OF_RANGE;
    }
    LIST_NODE *aux = NULL;
    aux = list->head;
    //Se a matricula desejada está na cabeça da lista.
    if(aux->data.matricula == nmat){
      *pos = 1;
      return SUCCESS;
    }

    //Percorremos a lista enquanto não encontramos e não chegamos ao seu último elemento.
    int posicao = 1;
    while(aux->data.matricula != nmat && posicao <= list_size(list)){
      aux = aux->next;
      posicao +=1;
    }
    //Se o elemento não foi encontrado.
    if(aux == NULL){
      return ELEM_NOT_FOUND;
    }
    *pos = posicao;
    return SUCCESS;
  }
}//list_get_pos

/*
*@brief Imprime a lista
*/
int list_print(LIST *list){
  if (list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    LIST_NODE *aux;
    aux = list->head;
    printf("\nImprimindo a lista (tamanho %d)\n", list_size(list));

    while (aux != NULL){
      printf("\n------------------\n");
      printf("Matricula: %d\n", aux->data.matricula);
      printf("Nome: %s\n", aux->data.nome);
      printf("Notas: %f; %f; %f;\n", aux->data.nota1, aux->data.nota2, aux->data.nota3);

      aux = aux->next;
    }
    printf("\nFim da lista \n");
    return SUCCESS;
  }
}//list_print

/*
*@brief Verifica se a lista está ordenada
*/
int is_sorted(LIST *list){
  if (list == NULL){
    return INVALID_NULL_POINTER;
  }else{
    if(list->head == NULL){
      return OUT_OF_RANGE;
    }
    LIST_NODE *aux = NULL, *aux2 = NULL;
    aux = list->head;
    aux2 = aux->next;
    for(int i=2;i<=list_size(list);i++){
      if(aux->data.matricula > aux2->data.matricula){
        return NOT_SORTED;
      }
    }
    return SUCCESS;
  }
}//is_sorted




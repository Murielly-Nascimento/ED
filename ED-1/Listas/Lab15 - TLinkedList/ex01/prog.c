#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TLinkedList.h"

int main(void){
  LIST *list = NULL;
  struct ALUNO a,b,c,d;

  strcpy(a.nome,"Joao");
  a.matricula = 1;
  a.nota1 = 0;    a.nota2 = 2;    a.nota3 = 0;

  strcpy(b.nome,"Maria");
  b.matricula = 2;
  b.nota1 = 2;    b.nota2 = 0;    b.nota3 = 0;

  strcpy(c.nome,"Jose");
  c.matricula = 3;
  c.nota1 = 0;    c.nota2 = 0;    c.nota3 = 4;

  strcpy(d.nome,"Ana");
  d.matricula = 4;
  d.nota1 = 0;    d.nota2 = 0;    d.nota3 = 2;

  printf("<< CRIANDO A LISTA >>\n");
  list = list_create();
  if (list == NULL){
    printf("ERRO!");
    exit(1);
  } 

  printf("\n<< INSERINDO ELEMENTOS >>\n");
  int sucesso = 0;
  sucesso = list_push_front(list, a);
  switch(sucesso){
    case SUCCESS: printf("Aluno inserido\n");
    break;
    case INVALID_NULL_POINTER: printf("Erro de ponteiro\n");
    break;
    case OUT_OF_MEMORY: printf("Memória insuficiente\n");
    break;
  }
  list_push_back(list, b);
  list_print(list);

  printf("\n<< INSERINDO ORDERNADAMENTE >>\n");
  list_insert_sorted(list, c);

  printf("\n<< INSERINDO EM UMA POSIÇÃO >>\n");
  printf("\nDigite uma posição: ");
  int posicao = 0;
  scanf("%d",&posicao);
  list_insert(list,posicao,d);
  
  printf("\n<< IMPRIMINDO LISTA >>\n");
  list_print(list);

  struct ALUNO aux;
  int matricula = 0;

  printf("\n<< ENCONTRANDO ELEMENTOS >>\n");
  printf("Digite uma posição: ");
  scanf("%d",&posicao);
  list_find_pos(list, posicao, &aux);
  printf("O aluno %s está na posiçao %d\n",aux.nome,posicao);

  printf("\nDigite uma matricula: ");
  scanf("%d",&matricula);
  list_find_mat(list, matricula, &aux);
  printf("O aluno de matrícula %d é %s \n",matricula,aux.nome);

  list_front(list, &aux);
  printf("\nO aluno na primeira posicao é %s \n",aux.nome);

  list_back(list, &aux);
  printf("\nO aluno na ultima posicao é %s \n",aux.nome);

  printf("\nDigite uma matricula: ");
  scanf("%d",&matricula);
  list_get_pos(list, matricula, &posicao);
  printf("O aluno de matricula %d está na posicao %d\n",matricula,posicao);

  printf("\n<< REMOVENDO ELEMENTOS >>\n");
  printf("\nRemovendo o primeiro e o último\n");
  list_pop_front(list);
  list_pop_back(list);
  list_print(list);

  printf("\nDigite uma matricula: ");
  scanf("%d",&matricula);
  list_erase_data(list, matricula);
  list_print(list);
  
  printf("\nDigite uma posicao: ");
  scanf("%d",&posicao);
  list_erase_pos(list, posicao);
  list_print(list);

  printf("\n<< IMPRIME TAMANHO DA LISTA >>\n");
  int tam = list_size(list);
  printf("Tamanho da lista: %d\n", tam);

  printf("\n<< LIBERA ESPAÇO ALOCADO NA HEAP >>\n");
  list_free(list);
  list = NULL;

  printf("\n<< FIM DO PROGRAMA >>\n");
  return 0;
}

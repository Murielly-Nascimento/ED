#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TLinkedList.h"
#include "aluno.h"
#include "TStack.h"

int main(void){
  LIST *list = NULL;
  struct aluno a,b,c,d;

  strcpy(a.nome,"Joao");
  a.matricula = 1;
  a.n1 = 0;    a.n2 = 2;    a.n3 = 0;

  strcpy(b.nome,"Maria");
  b.matricula = 2;
  b.n1 = 2;    b.n2 = 0;    b.n3 = 0;

  strcpy(c.nome,"Jose");
  c.matricula = 3;
  c.n1 = 0;    c.n2 = 0;    c.n3 = 4;

  strcpy(d.nome,"Ana");
  d.matricula = 4;
  d.n1 = 0;    d.n2 = 0;    d.n3 = 2;

  printf("<< CRIANDO A LISTA >>\n");
  list = list_create();
  if (list == NULL){
    printf("ERRO!");
    exit(1);
  } 

  printf("\n<< INSERINDO ELEMENTOS >>\n");
  list_push_back(list, a);
  list_push_back(list, b);
  list_push_back(list, c);
  list_push_back(list, d);
  list_print(list);

  printf("\n<< IMPRIME O REVERSO >>\n");
  list_print_reverse(list);

  printf("\n<< LIBERA ESPAÇO ALOCADO NA HEAP >>\n");
  list_free(list);
  list = NULL;

  printf("\n<< FIM DO PROGRAMA >>\n");
  return 0;
}
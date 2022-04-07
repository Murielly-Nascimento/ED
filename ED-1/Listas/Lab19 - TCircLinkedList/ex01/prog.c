#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TCList.c"

int main(void){
  CircList *clist = NULL;
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
  clist = clist_create();
  if (clist == NULL){
    printf("ERRO!");
    exit(1);
  } 

  printf("\n<< INSERINDO ELEMENTOS >>\n");

  clist_push_back(clist, a);
  clist_push_back(clist, b);
  clist_push_front(clist, c);
  clist_print(clist);

  printf("\n<< REMOVENDO ELEMENTOS >>\n");
  clist_pop_front(clist);
  clist_pop_back(clist);
  clist_print(clist);

  printf("\n<< LIBERA ESPAÇO ALOCADO NA HEAP >>\n");
  clist_free(clist);
  clist = NULL;

  printf("\n<< FIM DO PROGRAMA >>\n");
  return 0;
}
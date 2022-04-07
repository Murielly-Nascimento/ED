#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDLinkedList.h"

int main(void){

  printf("\n<<CRIANDO A LISTA DUPLAMENTE ENCADEADA>>\n");

  struct aluno a,b,c,d;
  strcpy(a.nome,"Joao");
  a.matricula = 1;
  a.n1 = 1;    a.n2 = 0;    a.n3 = 0;

  strcpy(b.nome,"Maria");
  b.matricula = 2;
  b.n1 = 2;    b.n2 = 0;    b.n3 = 0;

  strcpy(c.nome,"Jose");
  c.matricula = 3;
  c.n1 = 0;    c.n2 = 0;    c.n3 = 0;

  strcpy(d.nome,"Ana");
  d.matricula = 4;
  d.n1 = 0;    d.n2 = 0;    d.n3 = 0;

  List *list;
  list = list_create();

  printf("\n<< INSERINDO ELEMENTOS >>\n");
  printf("Insere aluno a no início\n");
  list_push_front(list,a);

  printf("Insere aluno b e c no fim\n");
  list_push_back(list,b);
  list_push_back(list,c);

  printf("Insere aluno d no fim\n");
  list_push_back(list,d);  

  printf("\n<<IMPRIME A LISTA DE FRENTE PARA TRÁS>>\n");
  list_print_forward(list);

  printf("\n<<IMPRIME A LISTA DE TRÁS PARA FRENTE>>\n");
  list_print_reverse(list); 


  printf("\n<< REMOVE ALUNOS DE NOTA 0>>\n");
  list_erase_zeros(list);
  list_print_forward(list);

  printf("\n<<LIBERA A LISTA>\n");
  list_free(list);   

  return 0;
}
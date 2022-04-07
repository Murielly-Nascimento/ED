/* Armazenar uma lista de 1000 pares de termos (português,inglês) numa tabela hash */

#include <stdio.h>
#include <stdlib.h>
#include "TAD_hash.h"

int main(void) {
	TabelaHs *ht;
	int i=0, t = 50, op;
	char *res;
	
	// Criar tabela hash
	ht = criar(t);
	
	{
		char chave[50] = {"http://bit.ly/ABC"};
		char valor[100] = {"https://calendar.google.com/calendar/u/0/r?pli=1"};
		inserirTermoTh(ht, chave, valor);
	}
	{
		char chave[50] = {"https://bit.ly/3NBED51"};
		char valor[100] = {"https://www.roh.org.uk/"};
		inserirTermoTh(ht, chave, valor);
	}
	{
		char chave[50] = {"https://bit.ly/3wOZV9m"};
		char valor[100] = {"https://www.escolabolshoi.com.br/"};
		inserirTermoTh(ht, chave, valor);
	}

	char chave[50] = {"https://bit.ly/3NBED51"};
	
	// Buscar um termo na tabela hash
	printf("\n\nBuscar termo: ");
	res = buscarTermoTh(ht,chave);
	if (res!=NULL)
	  printf("\n\nTraducao: %s -> %s",chave,res);
	else printf("\nTermo não encontrado!");

	printf("\n\nMOSTRAR TABELA HASH\n\n");
	percursoTh(ht);

	removerTermoTh(ht, chave);
	printf("\n\nMOSTRAR TABELA HASH\n\n");
	percursoTh(ht);
	
	liberaTh(ht);
	return 0;
}
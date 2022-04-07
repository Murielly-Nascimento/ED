#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "TAD_hash.h"

/* Criação de uma nova tabela hash. */
TabelaHs *criar (int tam) {

	TabelaHs *tabelaHash = NULL;
	int i = 0;

	if(tam < 1) return NULL;

	/* Alocação de memória para a tabela (estrutura). */
	if((tabelaHash = malloc(sizeof(TabelaHs))) == NULL ) {
		return NULL;
	}
	/* Alocação de memória para o vetor associado à tabela. */
	if((tabelaHash->tab = malloc(sizeof(URL *) * tam)) == NULL) {
		return NULL;
	}

	for(i = 0; i < tam; i++ ) {
		tabelaHash->tab[i] = NULL;
	}

	tabelaHash->tamanho = tam;
	return tabelaHash;	
}



/* Espalhamento para a chave */
int ht_hash(TabelaHs *tabTermos, char *chave) {
	
	unsigned long int hashval = 0; // ULONG_MAX -> valor máximo possível 
	int i = 0;

	while(hashval < ULONG_MAX && i < strlen(chave) ) {
		hashval = hashval << 8;  // deslocamento de oito bits à direita
		hashval += chave[i];
    	printf("\n%lu -> %c (%d)", hashval, chave[i], chave[i]);
		i++;
	}
	return hashval % tabTermos->tamanho;
}

/* Criação do par (chave/valor)*/
URL *criarNovoTermo( char *chave, char *url ) {
	
	URL *nTermo;

	if( ( nTermo = malloc( sizeof( URL ) ) ) == NULL ) {
		return NULL;
	}

	strcpy(nTermo->chave,chave);   // copiar termo chave
	strcpy(nTermo->url,url);   // copiar valor
	nTermo->prox = NULL;

	return nTermo;
}

/* Inserir par chave/valor numa tabela hash. */
void inserirTermoTh(TabelaHs *tabTermos, char *chave, char *url) {
	int bin = 0;
	URL *novoT = NULL;
	URL *pos = NULL;
	URL *ult = NULL;

	bin = ht_hash(tabTermos,chave);
  	//printf("\n Bin Gerado: %d", bin);

	pos = tabTermos->tab[bin];

	while(pos != NULL  && strcmp(chave, pos->chave ) > 0 ) {
		ult = pos;
		pos = pos->prox;
	}

	/* Se a chave já existe, substituir o valor. */
	if(pos != NULL && strcmp(chave, pos->chave ) == 0 ) {
		strcpy(pos->url,url);

	} else {
    /* Se chave não existe, inserir novo par (termo) */
		novoT = criarNovoTermo(chave, url);
    //printf("\nNovo termo: %s %s", novoT->port, novoT->engl);

		/* Inserção no início da lista. */
		if(pos == tabTermos->tab[bin]) {
			novoT->prox = pos;
			tabTermos->tab[bin] = novoT;
	
		/* Inserção ao final da lista. */
		} else if (pos == NULL) {
			ult->prox = novoT;
	
		/* Inserção ordenada */
		} else  {
			novoT->prox = pos;
			ult->prox = novoT;
		}
	}
}


/* Buscar um par chave/valor (termo pt/en) em uma tabela hash. */
char *buscarTermoTh(TabelaHs *tabTermos, char *chv ) {
	int bin = 0;
	URL *par;

	bin = ht_hash(tabTermos, chv);
  //printf("\nPosição na tabela: %d",bin);
	
  /* Alcança a posição bin para buscar o valor da chave. */
	par = tabTermos->tab[bin];
	while( par != NULL && strcmp( chv, par->chave ) > 0 ) {
		par = par->prox;
	}

	if( par == NULL || strcmp( chv, par->chave ) != 0 ) {
		return NULL;

	} else {
		return par->url;
	}
	
}

/* Remover um par chave/valor (termo pt/en) em uma tabela hash. */
int *removerTermoTh(TabelaHs *tabTermos, char *chv ) {
	int bin = 0;
	URL *par, *aux1, *aux2;

	bin = ht_hash(tabTermos, chv);
  	//printf("\nPosição na tabela: %d",bin);
	
  	/* Alcança a posição bin para buscar o valor da chave. */
	aux1 = tabTermos->tab[bin];
	par = aux1->prox;
	while( par != NULL && strcmp( chv, par->chave ) > 0 ) {
		aux1 = aux1->prox;
		par = par->prox;
	}

	if( par == NULL || strcmp( chv, par->chave ) != 0 ) {
		return 1;

	} else {
		URL *aux2 = par->prox;
		aux1->prox = aux2;
		free(par);
		return 0;
	}
	
}


void percursoTh(TabelaHs *tabTermos){
   int i,tam;
   URL *t;

   tam = tabTermos->tamanho;
   for (i=0;i<tam;i++){
     t = tabTermos->tab[i];
     printf("%d:",i);
     while (t != NULL){
       printf("(%s, %s) ",t->chave,t->url);
       t = t->prox;
     }
     printf("\n");
   }
}

void liberaTh(TabelaHs *tabTermos){
   int i = 0,tam = 0;
   URL *t;
   tam = tabTermos->tamanho;
   for (i = 0; i < tam; i++){
		t = tabTermos->tab[i];
		free(t);
   }
	free(tabTermos);
}
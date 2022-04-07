/*23) Use as funções criadas nos exercícios anteriores em um único programa, mas agora
trabalhe com vetores alocados dinamicamente no programa principal. Lembre de
liberar a memória depois de usar os vetores.*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void imprime_vet_int(int *vet,int N);

int negativos(int *vet, int N);
void MaiorMenor(int *vet,int N,int *maior,int *menor);
void modulo(int *vet,int N);
void copiar(int *vet,int *vet2,int N);
void multiplicar(int *vet,int N,int K);

void imprime_vet_int(int *vet,int N){
    for(int i=0;i<N;i++) printf("%d ",vet[i]);
    printf("\n");
}
void MaiorMenor(int *vet,int N,int *maior,int *menor){
    for(int i=0;i<N;i++){
        if(vet[i]<*menor) *menor =vet[i];
        if(vet[i]>*maior) *maior =vet[i];
    }
}
void copiar(int *vet,int *vet2,int N){
    for(int i=0;i<N;i++) vet2[i] = vet[i];
}
void modulo(int *vet,int N){
    for(int i=0;i<N;i++) vet[i] = abs(vet[i]);
}
int negativos(int *vet, int N){
    int neg = 0;
    for(int i=0;i<N;i++){
        if(vet[i]<0) neg++;
    }
    return neg;
}
void multiplicar(int *vet,int N,int K){
    for(int i=0;i<N;i++) vet[i] *= K;
}

int main(void){
    int N=0;
    printf("Entre com o tamanho do vetor: ");
    scanf("%d",&N);

    int *ponteiro=NULL;
    ponteiro = (int *) calloc(N,sizeof(int));
    if(ponteiro==NULL){
        printf("Erro: Memoria Insuficiente!\n");
    }
    for(int i=0;i<N;i++){
        printf("Entre com o elemento %d: ",i);
        scanf("%d",&ponteiro[i]);
    }
    printf("Vetor: ");
    imprime_vet_int(ponteiro,N);

    int maior=ponteiro[0],menor=ponteiro[0];
    MaiorMenor(ponteiro,N,&maior,&menor);
    printf("O maior elemento = %d\nO menor elemento = %d\n",maior,menor);

    printf("Número de negativos: %d\n",negativos(ponteiro,N));
    
    modulo(ponteiro,N);
    printf("Vetor absoluto: ");
    imprime_vet_int(ponteiro,N);

    printf("Copiando para outro vetor (alocado dinamicamente)\n");
    printf("Vetor original: ");
    imprime_vet_int(ponteiro,N);

    int *ponteiro2=NULL;
    ponteiro2 = (int *) calloc(N,sizeof(int));
    if(ponteiro2==NULL){
        printf("Erro: Memoria Insuficiente!\n");
    }

    copiar(ponteiro,ponteiro2,N);
    printf("Vetor copiado: ");
    imprime_vet_int(ponteiro2,N);

    printf("Entre com o valor escalar para multiplicar o vetor original: ");
    int K =0;
    scanf("%d",&K);
    printf("Vetor original: ");
    imprime_vet_int(ponteiro,N);
    printf("Vetor multiplicado: ");
    multiplicar(ponteiro,N,K);
    imprime_vet_int(ponteiro,N);


    free(ponteiro);
    free(ponteiro2);
    return 0;
}
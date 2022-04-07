#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
--- Instruções da prova--- 
Qualquer exercício copiado de um colega ou da internet implicará nota zero em toda a prova,
 mesmo que a cópia seja feita somente de um trecho

A nota será zerada tanto para quem deixou copiar quanto para quem fez a cópia.

Não enviar o enunciado nem as respostas para os colegas

Não haverá checagem de exercício correto. 

Formate a saída de seu programa da melhor forma possível. Por exemplo, se o exercício
pede para informar o valor de um produto, escreva no printf um texto que seja adequado 
ao que for pedido:

Forma correta 
Digite o preço do produto 1: 20
Digite o preço do produto 2: 50.6

Forma errada
20
produto: 50.6

Fique atento também à saída gerada pelo programa. Escreva textos contextualizando os cálculos 
realizado e não somente mostre número Por exemplo:

Forma correta
O consumo de gasolina no mês 5 foi 50L – valor alto
O consumo de gasolina no mês 2 foi 20L – valor baixo

Forma errada
50L
50L – alto
*/



// Fazer um programa para cadastro de carros. As informações para cadastro são: 
// modelo (ex: gol, ka, c3), o ano (ex: 1999, 2015, 2021) e o consumo (ex: 10 Km/l, 7 km/l, 16 Km/l)
// Verificar no main() abaixo os exercícios da prova


// Definir as estruturas necessárias aqui:

struct CARROS{
    char modelo[50];
    int ano;
    double consumo;
};

struct CRLV{
    char nome[50];
    long int cpf;
    struct CARROS carro;
};

// Função: Busca Maior Consumo (ex02)
// Essa função retorna o carro de maior consumo
// Entrada: todos os carros cadastrados 
// Saída: índice do vetor indicando a posição de maior valor
// (se houver empate pode ser retornado qualquer um dos carros)

int MaiorConsumo(struct CARROS *carros, int quantidade);
int Eficiencia(struct CARROS carros);
void *MaiorConsumo2(struct CARROS *carros, int quantidade);
int MaiorConsumo(struct CARROS *carros, int quantidade){
    int maior = carros[0].consumo;
    int posicao = 0;
    for(int i=0;i<quantidade;i++){
        if(carros[i].consumo<maior){
            maior = carros[i].consumo;
            posicao = i;
        }
    }
    return posicao;
}




// Função: Índice de Eficiência (ex03)
// Essa calcula a eficiência energética de um carro
// o índice de eficiência é calculado usando a seguinte fórmula
//
//                                 ano_veiculo - 1991
//   ind = consumo (em km/l)  *  ---------------------            
//                                        30                   
//
// A função deve retornar um valor inteiro de acordo com a classificação listada na tabela abaixo.
// Valores inválidos correspondem a números negativos, zeros e ano menor que 1980 e maior que 2021
// Todos os comandos de entrada e saída devem estar no programa principal
// Todos os cálculos devem ser feitos na função.

/*
+-------------------+-----------------------------------------------+----------------+
| Retorno da Função | Valor do índice de eficiência                 | Classificação  |
+-------------------+-----------------------------------------------+----------------+
| -1                | -                                             | Valor invalido |
+-------------------+-----------------------------------------------+----------------+
| 1                 | acima ou igual 10                             | A              |
+-------------------+-----------------------------------------------+----------------+
| 2                 | acima ou igual a 8,8 e menor que 10           | B              |
+-------------------+-----------------------------------------------+----------------+
| 3                 | acima ou igual a 7,5 e menor que 8,8          | C              |
+-------------------+-----------------------------------------------+----------------+
| 4                 | abaixo de 7,5                                 | D              |
+-------------------+-----------------------------------------------+----------------+

*/

int Eficiencia(struct CARROS carros){
    double eficiencia = 0.0;
    if(carros.ano < 1980 || carros.ano > 2021){
        return -1;
    }else{
        eficiencia =  carros.consumo * (carros.ano - 1991)/30;
        if(eficiencia < 0) return -1;
        else if(eficiencia >= 10) return 1;
        else if(eficiencia >= 8.8 && eficiencia < 10) return 2;
        else if(eficiencia>=7.5 && eficiencia < 8.8) return 3;
        else if (eficiencia < 7.5) return 4;
    }
}


// Função: Busca Maior Consumo - retorno Ponteiro (ex05)
// Essa função retorna o carro de maior consumo
// Entrada: todos os carros cadastrados 
// Saída: ponteiro para posição de vetor de maior valor
// (se houver empate pode ser retornado qualquer um dos carros)

void *MaiorConsumo2(struct CARROS *carros, int quantidade){
    int maior = carros[0].consumo;
    void *posicao = NULL;
    for(int i=0;i<quantidade;i++){
        if(carros[i].consumo<maior){
            maior = carros[i].consumo;
            posicao = &carros[i];
        }
    }
    return posicao;
}



int main(void){

    // Ex 01: permitir que o usuário cadastre quantos carros desejar
    //  - ler do teclado a quantidade de carros que o usuário escolheu
    //  - ler do teclado as informações dos carros 
    printf("Informe quantos carros deseja cadastrar: ");
    int quantidade = 0;
    scanf("%d",&quantidade);

    struct CARROS *carros = NULL;
    carros = (struct CARROS *)calloc(quantidade,sizeof(struct CARROS));
    if(carros==NULL){
        printf("Erro: Memoria Insuficiente!\n");
    }

    for(int i=0;i<quantidade;i++){
        printf("Digite os dados do carro %d:\n",i+1);

        printf("Digite o modelo do carro(gol,ka,c3): ");
        getchar();
        fgets(carros[i].modelo,50,stdin);
        carros->modelo[strcspn(carros[i].modelo,"\n")] = '\0';
        setbuf(stdin,NULL);
        printf("Digite o ano de fabricação do carro: ");
        scanf("%d",&carros[i].ano);
        printf("Digite o consumo em Km/l do carro: ");
        scanf("%lf",&carros[i].consumo);
    }


   // Ex02: utilizando a função de buscar o maior consumo, mostre
   // todas as informações do carro que possui o maior consumo.
   // Todas as funções de entrada e saída devem estar no programa
   // principal
   int maior = MaiorConsumo(carros,quantidade);
   printf("\n\nO carro de maior consumo é o modelo %s do ano %d de consumo %.2lf Km/l\n",carros[maior].modelo,carros[maior].ano,carros[maior].consumo);


   // Ex03: utilizando a função de cálculo de eficiência de um carro
   // mostre para todos os carros o seu índice de eficiência e 
   // a sua classificação de eficiência
   printf("\n\nEficiencia dos veiculos cadastrados\n");
   for(int i=0;i<quantidade;i++){
       int eficiencia = Eficiencia(carros[i]);
       printf("O carro de modelo %s - %d - %.2lf km/l;",carros[i].modelo,carros[i].ano,carros[i].consumo);
       switch(eficiencia){
        case -1:
            printf("Valor Inválido");
            break;
        case 1:
            printf("Classificacao: A\n");
            break;
        case 2:
            printf("Classificacao: B\n");
            break;
        case 3:
            printf("Classificacao: C\n");
            break;
        case 4:
            printf("Classificacao: D\n");
            break;
        default:
            break;
        }
   }
   // exemplo de saída:
   // Ford Ka - 2020 - 10 km/l; Indice: 9.7; Classificação: B

   // Ex04: Crie uma estrutura para guardar informações sobre o
   // documento de um carro CRLV (Certificado de Registro e
   //  Licenciamento de Veículo)
   // Nesse documento deverá ter o Nome, CPF, e as informações
   // do carro (deve-se utilizar a estrutura dos exercícios anteriores)
   // Crie uma variável dessa estrutura e inicialize ela com valores 
   // constantes (não precisa ler do teclado) e depois mostre esses valores

   struct CRLV documentos;

   strcpy(documentos.nome,"Ana Maria");
   documentos.cpf = 97145398704;
   strcpy(documentos.carro.modelo,"Gol");
   documentos.carro.ano = 1998;
   documentos.carro.consumo = 25.2;

   printf("\n\n<< DOCUMENTOS >>\n");
   printf("%s de cpf: %ld. Dono(a) do carro %s - %d - de consumo %.2lf\n\n",documentos.nome,documentos.cpf,documentos.carro.modelo,documentos.carro.ano,documentos.carro.consumo); 
 

   // Ex05: Duplique o exercício 2 e modifique ele para que ao invés de 
   // retornar o índice da posição do vetor que retorne um ponteiro
   // para a posição do vetor. Mostre no programa principal os dados
   // do carro utilizando o ponteiro retornado.

    struct CARROS *Pmaior = MaiorConsumo2(carros,quantidade);
    printf("O carro de maior consumo é o modelo %s do ano %d de consumo %.2lf Km/l\n",Pmaior->modelo,Pmaior->ano,Pmaior->consumo);
   
    free(carros);
    return 0;
}
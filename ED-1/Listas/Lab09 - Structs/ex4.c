/*4. Define a estrutura necessária para armazenar os dados a seguir. Use as subestruturas
dos exercícios anteriores para definir os tipos dos campos com asterisco. Dê suporte
para o cadastro de 5 pessoas:

(a) Cadastre 5 usuários no seu código (não pedir para digitar – cadastre no próprio código
fonte, utilizando comandos de atribuição). A ideia disso é evitar digitação excessiva
durante o teste do programa

(b) Crie um menu com as seguintes opções:
    a. Listar todos os cadastros
    b. Cadastrar/Sobrescrever nova pessoa (pedir em qual posição do vetor ela será
    cadastrada 0,1,2,3, ou 4)
    c. Listar as pessoas que nasceram depois de 1990.
    d. Copiar dados de um cadastro para outro

*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define STRING 100
#define TAMMAX 1000

struct endereco{
    char rua[STRING];
    int numero;
    char complemento[STRING];
    char cidade[STRING];
    char estado[STRING];
    int cep;
};

struct telefone{
    int DDD;
    int number;
};

struct datas{
    int dia;
    int mes;
    int ano;
};

struct cadastro{
    char nome[STRING];
    unsigned int cpf;
    char sexo;
    char estadoCivil[STRING];
    double salario;
    int rg;
    struct endereco residencial;
    struct endereco comercial;
    struct telefone fixo;
    struct telefone celular;
    struct datas nascimento;
    struct datas ingresso;
};

int main(void){
    struct cadastro dados[TAMMAX];

    strcpy(dados[0].nome,"Laura Oliveira Albuquerque");
    dados[0].cpf = 601234567;
    dados[0].sexo ='f';
    strcpy(dados[0].estadoCivil,"Solteira");
    dados[0].salario = 7000.00;
    dados[0].rg = 1234567;
    strcpy(dados[0].residencial.rua,"Porto Alegre");
    dados[0].residencial.numero=36;
    strcpy(dados[0].residencial.complemento,"Apto 3");
    strcpy(dados[0].residencial.cidade,"Uberlandia");
    strcpy(dados[0].residencial.estado,"MG");
    dados[0].residencial.cep=38400712;
    strcpy(dados[0].comercial.rua,"Porto Nossa Senhora");
    dados[0].comercial.numero=136;
    strcpy(dados[0].comercial.complemento,"Bloco 2");
    strcpy(dados[0].comercial.cidade,"Uberlandia");
    strcpy(dados[0].comercial.estado,"MG");
    dados[0].comercial.cep=38400612;
    dados[0].celular.DDD =34;
    dados[0].celular.number =991197072;
    dados[0].fixo.DDD =34;
    dados[0].fixo.number =991197472;
    dados[0].nascimento.dia=1;
    dados[0].nascimento.mes=12;
    dados[0].nascimento.ano=2000;
    dados[0].ingresso.dia=28;
    dados[0].ingresso.mes=12;
    dados[0].ingresso.ano=2010;

    strcpy(dados[1].nome,"Agatha Christie");
    dados[1].cpf = 611234567;
    dados[1].sexo ='f';
    strcpy(dados[1].estadoCivil,"Solteira");
    dados[1].salario = 7111.00;
    dados[1].rg = 1234567;
    strcpy(dados[1].residencial.rua,"Baker Street");
    dados[1].residencial.numero=36;
    strcpy(dados[1].residencial.complemento,"Bloco 2");
    strcpy(dados[1].residencial.cidade,"Londres");
    strcpy(dados[1].residencial.estado,"WL");
    dados[1].residencial.cep=38400712;
    strcpy(dados[1].comercial.rua,"Kensigton");
    dados[1].comercial.numero=136;
    strcpy(dados[1].comercial.complemento,"Bloco 1");
    strcpy(dados[1].comercial.cidade,"Londres");
    strcpy(dados[1].comercial.estado,"WL");
    dados[1].comercial.cep=38400612;
    dados[1].celular.DDD =34;
    dados[1].celular.number =991197072;
    dados[1].fixo.DDD =34;
    dados[1].fixo.number =991197472;
    dados[1].nascimento.dia=1;
    dados[1].nascimento.mes=12;
    dados[1].nascimento.ano=1998;
    dados[1].ingresso.dia=28;
    dados[1].ingresso.mes=12;
    dados[1].ingresso.ano=2010;

    strcpy(dados[2].nome,"Manon Pierre");
    dados[2].cpf = 621234567;
    dados[2].sexo ='f';
    strcpy(dados[2].estadoCivil,"Solteira");
    dados[2].salario = 7222.22;
    dados[2].rg = 1234567;
    strcpy(dados[2].residencial.rua,"Rue de Sévigné");
    dados[2].residencial.numero=36;
    strcpy(dados[2].residencial.complemento,"Apto 3");
    strcpy(dados[2].residencial.cidade,"Paris");
    strcpy(dados[2].residencial.estado,"IS");
    dados[2].residencial.cep=38422712;
    strcpy(dados[2].comercial.rua,"Rue Vieille du Temple ");
    dados[2].comercial.numero=136;
    strcpy(dados[2].comercial.complemento,"Bloco 2");
    strcpy(dados[2].comercial.cidade,"Paris");
    strcpy(dados[2].comercial.estado,"IS");
    dados[2].comercial.cep=38422612;
    dados[2].celular.DDD =34;
    dados[2].celular.number =991197272;
    dados[2].fixo.DDD =34;
    dados[2].fixo.number =991197472;
    dados[2].nascimento.dia=1;
    dados[2].nascimento.mes=12;
    dados[2].nascimento.ano=2002;
    dados[2].ingresso.dia=28;
    dados[2].ingresso.mes=12;
    dados[2].ingresso.ano=2010;

    strcpy(dados[3].nome,"Heitor Carvalho");
    dados[3].cpf = 631234567;
    dados[3].sexo ='m';
    strcpy(dados[3].estadoCivil,"Casado");
    dados[3].salario = 7333.33;
    dados[3].rg = 1234567;
    strcpy(dados[3].residencial.rua,"Roberto Duarte Silva");
    dados[3].residencial.numero=36;
    strcpy(dados[3].residencial.complemento,"Apto 3");
    strcpy(dados[3].residencial.cidade,"Lisboa");
    strcpy(dados[3].residencial.estado,"BR");
    dados[3].residencial.cep=38433712;
    strcpy(dados[3].comercial.rua,"Guarda-Mor");
    dados[3].comercial.numero=136;
    strcpy(dados[3].comercial.complemento,"Bloco 2");
    strcpy(dados[3].comercial.cidade,"Lisboa");
    strcpy(dados[3].comercial.estado,"BR");
    dados[3].comercial.cep=38433612;
    dados[3].celular.DDD =34;
    dados[3].celular.number =991197372;
    dados[3].fixo.DDD =34;
    dados[3].fixo.number =991197472;
    dados[3].nascimento.dia=1;
    dados[3].nascimento.mes=12;
    dados[3].nascimento.ano=2003;
    dados[3].ingresso.dia=28;
    dados[3].ingresso.mes=12;
    dados[3].ingresso.ano=2010;

    strcpy(dados[4].nome,"Emilia Gruber");
    dados[4].cpf = 641234567;
    dados[4].sexo ='f';
    strcpy(dados[4].estadoCivil,"Solteira");
    dados[4].salario = 7444.44;
    dados[4].rg = 1234567;
    strcpy(dados[4].residencial.rua,"Kaerntnerstrasse");
    dados[4].residencial.numero=36;
    strcpy(dados[4].residencial.complemento,"Apto 3");
    strcpy(dados[4].residencial.cidade,"Viena");
    strcpy(dados[4].residencial.estado,"NR");
    dados[4].residencial.cep=38444712;
    strcpy(dados[4].comercial.rua,"Kaerntnerstrasse");
    dados[4].comercial.numero=136;
    strcpy(dados[4].comercial.complemento,"Bloco 2");
    strcpy(dados[4].comercial.cidade,"Viena");
    strcpy(dados[4].comercial.estado,"NR");
    dados[4].comercial.cep=38444612;
    dados[4].celular.DDD =34;
    dados[4].celular.number =991197472;
    dados[4].fixo.DDD =34;
    dados[4].fixo.number =991197472;
    dados[4].nascimento.dia=1;
    dados[4].nascimento.mes=12;
    dados[4].nascimento.ano=1987;
    dados[4].ingresso.dia=28;
    dados[4].ingresso.mes=12;
    dados[4].ingresso.ano=2000;

    int opcao = 10;
    while(opcao!=0){
        printf("<< MENU >>\n");
        printf("1. Listar todos os cadastros\n");
        printf("2. Cadastrar/Sobrescrever nova pessoa\n");
        printf("3. Listar as pessoas que nasceram depois de 1990\n");
        printf("4. Copiar dados de um cadastro para outro\n");
        printf("0. Sair\n");
        printf("Digite uma opcao: ");

        scanf("%d",&opcao);

        if(opcao==1){
            printf("\n");
            int j=0;
            for(j=0;j<TAMMAX;j++){
                if(dados[j].cpf==0){
                    break;
                }
            }
            for(int i=0;i<j;i++){
                printf("Nome: %s\nCPF: %d\n",dados[i].nome,dados[i].cpf);
                printf("Sexo: %c\n",dados[i].sexo);
                printf("Estado Civil: %s\n",dados[i].estadoCivil);
                printf("Salario: %.2lf\nIdentidade: %d\n",dados[i].salario,dados[i].rg);
                printf("Endereco: %s,%d-%s de %s/%s\n",dados[i].residencial.rua,dados[i].residencial.numero,dados[i].residencial.complemento,dados[i].residencial.cidade,dados[i].residencial.estado);
                printf("CEP: %d\n",dados[i].residencial.cep);
                printf("Endereco Comercial: %s,%d-%s de %s/%s\n",dados[i].comercial.rua,dados[i].comercial.numero,dados[i].comercial.complemento,dados[i].comercial.cidade,dados[i].comercial.estado);
                printf("Data de nascimento: %d/%d/%d\n",dados[i].nascimento.dia,dados[i].nascimento.mes,dados[i].nascimento.ano);
                printf("Data de ingresso: %d/%d/%d\n",dados[i].ingresso.dia,dados[i].ingresso.mes,dados[i].ingresso.ano);
                printf("Celular: (%d)%d\n",dados[i].celular.DDD,dados[i].celular.number);
                printf("Telefone residencial: (%d)%d\n\n",dados[i].fixo.DDD,dados[i].fixo.number);
            }
        }else if(opcao==2){
            char subopcao='\0';
            printf("a) Cadastrar pessoa.\n");
            printf("b) Sobrescrever pessoa.\n");
            printf("Opcao: ");
            setbuf(stdin,NULL);
            scanf("%c",&subopcao);
            if(subopcao=='a'){
                printf("Digite os dados da pessoa\n"); 
                int i=0;
                for(i=0;i<TAMMAX;i++){
                    if(dados[i].cpf==0){
                        break;
                    }
                }
                printf("Digite o nome: ");
                getchar();
                fgets(dados[i].nome,sizeof(dados[i].nome),stdin);
                dados[i].nome[strcspn(dados[i].nome,"\n")]='\0';
                printf("Digite o CPF: ");
                scanf("%d",&dados[i].cpf);
                printf("Digite o sexo: ");
                setbuf(stdin,NULL);
                scanf("%c",&dados[i].sexo);
                printf("Digite o estado civil: ");
                scanf("%s", dados[i].estadoCivil);
                printf("Digite o salario e identidade: ");
                scanf("%lf %d",&dados[i].salario,&dados[i].rg);
                printf("Digite o endereco residencial. Rua: ");
                setbuf(stdin,NULL);
                fgets(dados[i].residencial.rua,sizeof(dados[i].residencial.rua),stdin);
                dados[i].residencial.rua[strcspn(dados[i].residencial.rua,"\n")]='\0';
                printf("Numero: ");
                scanf("%d",&dados[i].residencial.numero);
                printf("Complemento: ");
                setbuf(stdin,NULL);
                fgets(dados[i].residencial.complemento,sizeof(dados[i].residencial.complemento),stdin);
                dados[i].residencial.complemento[strcspn(dados[i].residencial.complemento,"\n")]='\0';
                printf("Cidade: ");
                setbuf(stdin,NULL);
                fgets(dados[i].residencial.cidade,sizeof(dados[i].residencial.cidade),stdin);
                dados[i].residencial.cidade[strcspn(dados[i].residencial.cidade,"\n")]='\0';
                printf("Estado: ");
                setbuf(stdin,NULL);
                fgets(dados[i].residencial.estado,sizeof(dados[i].residencial.estado),stdin);
                dados[i].residencial.estado[strcspn(dados[i].residencial.estado,"\n")]='\0';
                printf("Digite o cep: ");
                scanf("%d",&dados[i].residencial.cep);
                printf("Digite o endereco comercial. Rua: ");
                setbuf(stdin,NULL);
                fgets(dados[i].comercial.rua,sizeof(dados[i].comercial.rua),stdin);
                dados[i].comercial.rua[strcspn(dados[i].comercial.rua,"\n")]='\0';
                printf("Numero: ");
                scanf("%d",&dados[i].comercial.numero);
                printf("Complemento: ");
                setbuf(stdin,NULL);
                fgets(dados[i].comercial.complemento,sizeof(dados[i].comercial.complemento),stdin);
                dados[i].comercial.complemento[strcspn(dados[i].comercial.complemento,"\n")]='\0';
                printf("Cidade: ");
                setbuf(stdin,NULL);
                fgets(dados[i].comercial.cidade,sizeof(dados[i].comercial.cidade),stdin);
                dados[i].comercial.cidade[strcspn(dados[i].comercial.cidade,"\n")]='\0';
                printf("Estado: ");
                setbuf(stdin,NULL);
                fgets(dados[i].comercial.estado,sizeof(dados[i].comercial.estado),stdin);
                dados[i].comercial.estado[strcspn(dados[i].comercial.estado,"\n")]='\0';
                printf("Digite o cep: ");
                scanf("%d",&dados[i].comercial.cep);
                printf("Digite a data de nascimento: ");
                scanf("%d %d %d",&dados[i].nascimento.dia,&dados[i].nascimento.mes,&dados[i].nascimento.ano);
                printf("Digite a data de ingresso: ");
                scanf("%d %d %d",&dados[i].ingresso.dia,&dados[i].ingresso.mes,&dados[i].ingresso.ano);
                printf("Digite o celular: ");
                scanf("%d %d",&dados[i].celular.DDD,&dados[i].celular.number);
                printf("Digite o fixo: ");
                scanf("%d %d",&dados[i].fixo.DDD,&dados[i].fixo.number);
            }else if(subopcao=='b'){
                printf("Digite o numero de cadastro a ser sobescrevido: ");
                int i=0;
                scanf("%d",&i);
                printf("Digite os dados da pessoa\n"); 
                printf("Digite o nome: ");
                getchar();
                fgets(dados[i].nome,sizeof(dados[i].nome),stdin);
                dados[i].nome[strcspn(dados[i].nome,"\n")]='\0';
                printf("Digite o CPF: ");
                scanf("%d",&dados[i].cpf);
                printf("Digite o sexo: ");
                setbuf(stdin,NULL);
                scanf("%c",&dados[i].sexo);
                printf("Digite o estado civil: ");
                scanf("%s", dados[i].estadoCivil);
                printf("Digite o salario e identidade: ");
                scanf("%lf %d",&dados[i].salario,&dados[i].rg);
                printf("Digite o endereco residencial. Rua: ");
                setbuf(stdin,NULL);
                fgets(dados[i].residencial.rua,sizeof(dados[i].residencial.rua),stdin);
                dados[i].residencial.rua[strcspn(dados[i].residencial.rua,"\n")]='\0';
                printf("Numero: ");
                scanf("%d",&dados[i].residencial.numero);
                printf("Complemento: ");
                setbuf(stdin,NULL);
                fgets(dados[i].residencial.complemento,sizeof(dados[i].residencial.complemento),stdin);
                dados[i].residencial.complemento[strcspn(dados[i].residencial.complemento,"\n")]='\0';
                printf("Cidade: ");
                setbuf(stdin,NULL);
                fgets(dados[i].residencial.cidade,sizeof(dados[i].residencial.cidade),stdin);
                dados[i].residencial.cidade[strcspn(dados[i].residencial.cidade,"\n")]='\0';
                printf("Estado: ");
                setbuf(stdin,NULL);
                fgets(dados[i].residencial.estado,sizeof(dados[i].residencial.estado),stdin);
                dados[i].residencial.estado[strcspn(dados[i].residencial.estado,"\n")]='\0';
                printf("Digite o cep: ");
                scanf("%d",&dados[i].residencial.cep);
                printf("Digite o endereco comercial. Rua: ");
                setbuf(stdin,NULL);
                fgets(dados[i].comercial.rua,sizeof(dados[i].comercial.rua),stdin);
                dados[i].comercial.rua[strcspn(dados[i].comercial.rua,"\n")]='\0';
                printf("Numero: ");
                scanf("%d",&dados[i].comercial.numero);
                printf("Complemento: ");
                setbuf(stdin,NULL);
                fgets(dados[i].comercial.complemento,sizeof(dados[i].comercial.complemento),stdin);
                dados[i].comercial.complemento[strcspn(dados[i].comercial.complemento,"\n")]='\0';
                printf("Cidade: ");
                setbuf(stdin,NULL);
                fgets(dados[i].comercial.cidade,sizeof(dados[i].comercial.cidade),stdin);
                dados[i].comercial.cidade[strcspn(dados[i].comercial.cidade,"\n")]='\0';
                printf("Estado: ");
                setbuf(stdin,NULL);
                fgets(dados[i].comercial.estado,sizeof(dados[i].comercial.estado),stdin);
                dados[i].comercial.estado[strcspn(dados[i].comercial.estado,"\n")]='\0';
                printf("Digite o cep: ");
                scanf("%d",&dados[i].comercial.cep);
                printf("Digite a data de nascimento: ");
                scanf("%d %d %d",&dados[i].nascimento.dia,&dados[i].nascimento.mes,&dados[i].nascimento.ano);
                printf("Digite a data de ingresso: ");
                scanf("%d %d %d",&dados[i].ingresso.dia,&dados[i].ingresso.mes,&dados[i].ingresso.ano);
                printf("Digite o celular: ");
                scanf("%d %d",&dados[i].celular.DDD,&dados[i].celular.number);
                printf("Digite o fixo: ");
                scanf("%d %d",&dados[i].fixo.DDD,&dados[i].fixo.number);
                scanf("%d",&i);
            }
            
        }else if(opcao==3){
            printf("As pessoas que nasceram depois de 1990 são:\n");
            int j=0,i=0;
            for(j=0;j<TAMMAX;j++){
                if(dados[j].cpf==0){
                    break;		
                }
            }
            for(i=0;i<j;i++){
                if(dados[i].nascimento.ano>1990){
                    printf("%s\n", dados[i].nome);
                }
            }
        }else if(opcao==4){
            printf("Digite o numero de cadastro a ser copiado: ");
            int j=0,n=0,i=0;
            scanf("%d",&j);
            printf("Digite o numero de cadastro a receber a copia: ");
            scanf("%d",&n);
            strncpy(dados[n].nome,dados[j].nome,STRING);
            dados[n].cpf=dados[j].cpf;
            dados[n].sexo=dados[j].sexo;
            strncpy(dados[n].estadoCivil,dados[j].estadoCivil,STRING);
            dados[n].salario=dados[j].salario;
            dados[n].rg=dados[j].rg;
            strncpy(dados[n].residencial.rua,dados[j].residencial.rua,STRING);
            dados[n].residencial.numero = dados[j].residencial.numero;
            strncpy(dados[n].residencial.complemento,dados[j].residencial.complemento,STRING);
            strncpy(dados[n].residencial.cidade,dados[j].residencial.cidade,STRING);
            strncpy(dados[n].residencial.estado,dados[j].residencial.estado,STRING);
            dados[n].residencial.cep=dados[j].residencial.cep;
            strncpy(dados[n].comercial.rua,dados[j].comercial.rua,STRING);
            dados[n].comercial.numero = dados[j].comercial.numero;
            strncpy(dados[n].comercial.complemento,dados[j].comercial.complemento,STRING);
            strncpy(dados[n].comercial.cidade,dados[j].comercial.cidade,STRING);
            strncpy(dados[n].comercial.estado,dados[j].comercial.estado,STRING);
            dados[n].comercial.cep=dados[j].comercial.cep;
            dados[n].nascimento.dia=dados[j].nascimento.dia;
            dados[n].nascimento.mes=dados[j].nascimento.mes;
            dados[n].nascimento.ano=dados[j].nascimento.ano;
            dados[n].ingresso.dia=dados[j].ingresso.dia;
            dados[n].ingresso.mes=dados[j].ingresso.mes;
            dados[n].ingresso.ano=dados[j].ingresso.ano;
            dados[n].celular.DDD=dados[j].celular.DDD;
            dados[n].celular.number=dados[j].celular.number;
            dados[n].fixo.DDD=dados[j].fixo.DDD;
            dados[n].fixo.number=dados[j].fixo.number;

        }
    }

    return 0;
}
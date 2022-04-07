/**
* @file IPC.c
* @brief Cria um menu com 9 opções, das quais o usuário escolhe uma e a mesma é executada.
* As opções são:
*1 - converter de binario para decimal
*2 - converter de hexadecimal para decimal
*3 - converter de decimal para binario
*4 - converter de decimal para hexadecimal
*5 - converter de binario para hexadecimal
*6 - converter de hexadecimal para binario
*7 - converter de fração binaria para decimal
*8 - converter de fração decimal para binario
*9 - somar dois binarios sem sinal
*0 - sair
*
* @author Murielly Oliveira Nascimento e Vitória Silva Cardoso
* @date 07/11/2019
* @bugs Importante salientar que devido a biblioteca math.h a compilação deve seguir esse comandos:
* gcc IPC.c -o IPC -lm
* gcc -std=c11 -o IPC.exe IPC.c -lm
*./IPC.exe
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*
* @brief recebe o valor realtotal da opcao9 e o converte em binário
*/
void opcao9transformaembinario(double a){
 unsigned int parte_int=0;
 double parte_double=0;
 unsigned int quociente=1,resto=0,temp=0,c=0;
 unsigned int temp2=0;
 double b=0,produto=0,temp3=0;
 int binario[32]={0};
 parte_int =a/1;
 parte_double= a-parte_int;
 while(quociente!=0){
   quociente=parte_int/2;
   resto=parte_int%2;
   binario[c]=resto;
   temp=quociente;
   parte_int=temp;
   c++;
 }
 for(int k=c-1;k>=0;k--){
    printf("%d",binario[k]);}
 printf(",");
 while(b<=16){
   produto=parte_double*2;
   if(produto>=1){
     printf("1");
     temp2=produto/1;
     temp3=produto-temp2;
   }
   else{
     printf("0");
     temp3=produto;
   }
   parte_double=temp3;
   b++;
 }
return;
}//opcao9transformaembinario

/*
* @brief recebe o vetor de char da opcao9 e o imprime
*/
void opcao9imprimibinario(char binario[]){
  unsigned int tamanho=0;
 tamanho=strlen(binario);
 for(int n=0;n<tamanho-1;n++){
   printf("%c",binario[n]);
 }
 return;
}//opcao9imprimibinario

/*
* @brief recebe o vetor de char da opcao9 e o converte em real fracionário
*/
double opcao9transformaparareal(char binario[]) {
  unsigned int tamanho=0;
  unsigned int j =0;
  unsigned int soma=0;
  double soma2=0;
  double somatotal=0;
 tamanho=strlen(binario);
 for(int i=0;i<tamanho;i++){
   if(binario[i]==','){
     j=i;
   }
 }
 for(int x=j-1;x>=0;x--){
   if(binario[x]=='1'){
     soma=soma+(pow(2,j-1-x));
    }
 }
 for(int y=j+1,w=0;y<tamanho-1;y++){
   w=w+1;
   if(binario[y]=='1'){
     soma2=soma2+((pow(2,-w)));
   }
 }
 somatotal=soma+soma2;
 return somatotal;
}//opcao9transformaparareal

/*
* @brief lê dois binários fracionários e retornar a sua soma e também a sua soma convertida em real
*/
void opcao9(void) {
  char binario[48]={'\0'};
  char binario2[48]={'\0'};
 double real1=0;
 double real2=0;
 double realtotal=0;
 printf("________________________________________________________\n\n");
 printf("Digite o primeiro binário: ");
 setbuf(stdin, NULL);
 if (fgets(binario, sizeof(binario), stdin) == NULL){
 fprintf(stderr, "Erro ao ler a string\n");
 exit(1);
 }
 printf("\nDigite o segundo binário: ");
 if (fgets(binario2, sizeof(binario2), stdin) == NULL){
 fprintf(stderr, "Erro ao ler a string\n");
 exit(1);
 }
 real1=opcao9transformaparareal(binario);
 real2=opcao9transformaparareal(binario2);
 realtotal=real1+real2;
 printf("\n");
 printf("\t\t");
 opcao9imprimibinario(binario); printf("                %lf",real1);
 printf("\n+\t\t");
 opcao9imprimibinario(binario2);printf("             +");printf("  %lf",real2);
 printf("\n-----------------------\t\t");printf("-----------------------\n");
 opcao9transformaembinario(realtotal);
 printf("_(2)"); printf("        %lf_(10)\n\n",realtotal);
 printf("Deseja somar outros binários (s/n)?");
 return;
}//opcao9

/*
* @brief lê um decimal real e converte em binário fracionário
*/
void opcao8(void) {
 char decimal[48]={'\0'};
 int conversor[48]={0};
 int binario_int[32]={0};
 int binario_float[16]={0};
 unsigned int tamanho=0;
 unsigned int j=0,d=0,a=0,b=0,h=0,e=0;
 unsigned int soma=0,pot=0,pot2=0;
 unsigned int quociente=1,resto=0,temp=0,temp2=0;
 double multp=0, produto=1,soma2=0,temp3=0;

 printf("________________________________________________\n\n");
 printf("Digite um real: ");
 setbuf(stdin, NULL);
 if (fgets(decimal, sizeof(decimal), stdin) == NULL){
 fprintf(stderr, "Erro ao ler a string\n");
 exit(1);
 }
  printf("\n");
 tamanho=strlen(decimal);

 for(int i=0;i<tamanho;i++){
   if(decimal[i]=='.'){
     j=i;
   }
 }
 for(int x=j-1,w=0;x>=0;x--,w++){
   switch(decimal[x]){
     default: decimal[x]=decimal[x]-'0';}
   conversor[x]=decimal[x];
   pot=pow(10,w);
   soma+=conversor[x]*pot;}

 for(e=j+1,d=tamanho-2-e;e<tamanho-1;e++,d--){
   switch(decimal[e]){
     default: decimal[e]=decimal[e]-'0';}
   conversor[e]=decimal[e];
   pot2=pow(10,d);
   soma2+=conversor[e]*pot2;
 }
 printf("%d.%.0lf_(10) = ",soma,soma2);

 while(quociente!=0){
 quociente =soma/2;
 resto=soma%2;
 binario_int[a]=resto;
 temp=quociente;
 soma=quociente;
 a++;
 }
 for(int f=a-1;f>=0;f--){
   printf("%d",binario_int[f]);
 }
 printf(",");

 d=((tamanho-1)-(j+1));
 h=(pow(10,d));
 multp=soma2/h;

 while(b<16){
   produto=multp*2;
    if(produto>=1){
     binario_float[b]=1;
     temp2=produto/1;
     temp3=produto-temp2;
    }
    else{
     binario_float[b]=0;
     temp3=produto;
    }
    multp=temp3;
    printf("%d",binario_float[b]);
   b++;
  }
  printf("_(2)\n\n");
  printf("Deseja converter outro real (s/n)? ");
 return ;
}//opcao8

/*
* @brief lê um binário fracionário e converte em um número real
*/

void opcao7(void) {
  char binario[49]={'\0'};
  unsigned int tamanho=0;
  unsigned int j =0;
  unsigned int soma=0;
  double soma2=0;
  double somatotal=0;
 printf("______________________________________________\n\n");
 printf("Digite um binário fracionário: ");
 setbuf(stdin, NULL);
 if (fgets(binario, sizeof(binario), stdin) == NULL){
 fprintf(stderr, "Erro ao ler a string\n");
 exit(1);
 }
 tamanho=strlen(binario);
 printf("\n");
 for(int v=0;v<tamanho-1;v++){
   printf("%c",binario[v]);}

 printf("_(2) = ");

 for(int i=0;i<tamanho;i++){
   if(binario[i]==',' || binario[i]=='.'){
     j=i;
   }
 }
 for(int x=j-1;x>=0;x--){
   if(binario[x]=='1'){
     soma=soma+(pow(2,j-1-x));
    }
 }

 for(int y=j+1,w=0;y<tamanho-1;y++){
   w=w+1;
   if(binario[y]=='1'){
     soma2=soma2+((pow(2,-w)));
   }
 }
 somatotal=soma+soma2;
 printf("%lf_(10)\n\n",somatotal);
 printf("Deseja converter outro binário fracionário (s/n)? ");
 return ;
}//opcao7

/*
* @brief lê um hexadecimal e converte em binário
*/

void opcao6(void) {
 char hexadecimal[9]={'0'};
 int tamanho=0;
 printf("____________________________________________________________\n\n");
 printf("Digite um hexadecimal: ");
 setbuf(stdin, NULL);
 if (fgets(hexadecimal, sizeof(hexadecimal), stdin) == NULL){
 fprintf(stderr, "Erro ao ler a string\n");
 exit(1);}
 printf("\n");
 tamanho=strlen(hexadecimal);
 for(int x =0;x<tamanho-1;x++){
 printf("%c",hexadecimal[x]);
 }
 printf("_(16) = ");
 for(int i=0;i<tamanho;i++){
     switch(hexadecimal[i]){
     case '0': printf("0");break;
     case '1': printf("1");break;
     case '2': printf("10");break;
     case '3': printf("11");break;
     case '4': printf("100");break;
     case '5': printf("101");break;
     case '6': printf("110");break;
     case '7': printf("111");break;
     case '8': printf("1000");break;
     case '9': printf("1001");break;
     case 'A': printf("1010");break;
     case 'a': printf("1010");break;
     case 'B': printf("1011");break;
     case 'b': printf("1011");break;
     case 'C': printf("1100");break;
     case 'c': printf("1100");break;
     case 'D': printf("1101");break;
     case 'd': printf("1101");break;
     case 'E': printf("1110");break;
     case 'e': printf("1110");break;
     case 'F': printf("1111");break;
     case 'f': printf("1111");break;
    }
 }
 printf("_(2)\n\n");
 printf("Deseja converter outro hexadecimal (s/n)? ");
return;
}//opcao6

/*
* @brief lê um binário e converte em hexadecimal
*/
void opcao5(void){
 unsigned int binario=0;
 unsigned int quociente=1;
 unsigned int resto=0;
 unsigned int temp=0;
 unsigned int temp2[8]={0};
 unsigned int n=0;

 printf("____________________________________________________________\n\n");
 printf("Digite um binário: ");
 scanf("%u",&binario);
 printf("\n%u_(2) = ",binario);
 while(quociente!=0){
   quociente=binario/10000;
   resto=binario%10000;
   temp=quociente;
   binario=temp;
   temp2[n]=resto;
   n++;
 }
 for(int j=n-1;j>=0;j--){
     switch(temp2[j]){
     case 0: printf("0");break;
     case 1: printf("1");break;
     case 10: printf("2");break;
     case 11: printf("3");break;
     case 100: printf("4");break;
     case 101: printf("5");break;
     case 110: printf("6");break;
     case 111: printf("7");break;
     case 1000: printf("8");break;
     case 1001: printf("9");break;
     case 1010: printf("A");break;
     case 1011: printf("B");break;
     case 1100: printf("C");break;
     case 1101: printf("D");break;
     case 1110: printf("E");break;
     case 1111: printf("F");break;
    }
 }
 printf("_(16)\n\n");
 printf("Deseja converter outro binário (s/n)? ");
 return ;
}//opcao5

/*
* @brief lê um natural e converte em hexadecimal
*/

void opcao4(void){
 unsigned int natural=0;
 unsigned int quociente=1;
 unsigned int temp=0;
 unsigned int temp2=0;
 unsigned int resto=0;

 printf("____________________________________________________________\n\n");
 printf("Digite um natural: ");
 scanf("%u",&natural);
 printf("\n%d_(10) = ",natural);
 while(quociente!=0){
   quociente=natural/16;
   resto=natural%16;
   temp=quociente;
   natural=temp;
     switch(resto){
     case 10: printf("A");break;
     case 11: printf("B");break;
     case 12: printf("C");break;
     case 13: printf("D");break;
     case 14: printf("E");break;
     case 15: printf("F");break;
     default: printf("%u",resto);
    }
 }
 printf("_(16)\n\n");
 printf("Deseja converter outro natural (s/n)? ");
 return ;
}//opcao4

/*
* @brief lê um natural e converte em  binário
*/
void opcao3(void){
 unsigned int natural=0;
 unsigned int quociente=1;
 unsigned int i=1;
 unsigned int temp =0;
 unsigned int resto=0;
 int binario[32]={0};
 printf("____________________________________________________________\n\n");
 printf("Digite um natural: ");
 scanf("%u",&natural);
 printf("\n");
 printf("%u_(10) = ",natural);
 while(quociente!=0){
   quociente=natural/2;
   resto=natural%2;
   binario[i]=resto;
   temp=quociente;
   natural=temp;
   i++;
 }
 for(int n=i-1;n>0;n--){
   printf("%d",binario[n]);}
 printf("_(2)\n\n");
 printf("Deseja converter outro natural (s/n)?\n");
 return ;
}//opcao3

/*
* @brief lê um hexadecimal e converte em decimal
*/
void opcao2(void){
 char hexadecimal[9]= {'\0'};
 int conversor[9]={0};
 int i=0;
 int j=0;
 int n=0;
 int tamanho=0;
 int soma=0;
 printf("________________________________________________________\n\n");
 printf("Digite um hexadecimal: ");
 setbuf(stdin, NULL);
 if (fgets(hexadecimal, sizeof(hexadecimal), stdin) == NULL){
 fprintf(stderr, "Erro ao ler a string\n");
 exit(1);
 }

 tamanho=strlen(hexadecimal);
 printf("\n");
 for(i=0;i<tamanho-1;i++){
   j=hexadecimal[i];
   conversor[i]= j;
   switch(conversor[i]){
     case 65: conversor[i]=10;break;
     case 97: conversor[i]=10;break;
     case 66: conversor[i]=11;break;
     case 98: conversor[i]=11;break;
     case 67: conversor[i]=12;break;
     case 99: conversor[i]=12;break;
     case 68: conversor[i]=13;break;
     case 100: conversor[i]=13;break;
     case 69: conversor[i]=14;break;
     case 101: conversor[i]=14;break;
     case 70: conversor[i]=15;break;
     case 102: conversor[i]=15;break;
     default:
     conversor[i]=j-'0';
    }
   printf("%c",hexadecimal[i]);
 }
 for(n=tamanho-2;n>=0;n--){
   soma=soma+(conversor[n]*(pow(16,tamanho-2-n)));
 }
 printf("_(16) = %d_(10)\n\n",soma);
 printf("Deseja converter outro hexadecimal (s/n)? ");
 return;
}//opcao2

/*
* @brief lê um valor binário e o converte em decimal
*/

void opcao1(void){
 char binario[33]= {'\0'};
 int i=0;
 int j =0;
 int tamanho=0;
 int soma=0;
 char c='\0';
 printf("________________________________________________________\n\n");
 printf("Digite um binário: ");
 scanf("%s", binario);
 printf("\n");
 tamanho=strlen(binario);
 while(j<tamanho){
   printf("%c",binario[j]);
   j++;
 }
 for(i=tamanho-1;i>=0;i--){
    if(binario[i]=='1'){
     soma=soma+(pow(2,tamanho-1-i));
    }
 }
 printf("_(2) = %d_(10)\n\n",soma);
 printf("Deseja converter outro binário (s/n)? ");
}//opcao1

/*
* @brief imprime o menu de opções
* @bugs ao executar o código o cabeçalho do conversor fica desalinhado
*/
void imprimir_menu(void){
printf("\n********************************************\n");
printf("*               Conversor                  *\n");
printf("********************************************\n\n");
printf("Opcoes:\n\n");
printf("1 - converter de binario para decimal\n");
printf("2 - converter de hexadecimal para decimal\n");
printf("3 - converter de decimal para binario\n");
printf("4 - converter de decimal para hexadecimal\n");
printf("5 - converter de binario para hexadecimal\n");
printf("6 - converter de hexadecimal para binario\n");
printf("7 - converter de fração binaria para decimal\n");
printf("8 - converter de fração decimal para binario\n");
printf("9 - somar dois binarios sem sinal\n");
printf("0 - sair\n\n");
printf("Digite uma opção: ");
return ;
} //imprimir_menu

/*
* @brief recebe o valor digitado pelo usuário e dependendo de qual seja chama as demais funções
*/
void ler(int o){
   char s[1]={'\0'};
   if(o==1){
     opcao1();
     scanf("%s",s);
     while(s[0]=='s'){
       opcao1();
       scanf("%s",s);
     }
     printf("________________________________________________________\n\n");
     imprimir_menu();
    }
  else if(o==2){
     opcao2();
     scanf("%s",s);
     while(s[0]=='s'){
       opcao2();
       scanf("%s",s);
     }
     printf("________________________________________________________\n\n");
     imprimir_menu();
  }
    else if(o==3){
     opcao3();
     scanf("%s",s);
     while(s[0]=='s'){
       opcao3();
       scanf("%s",s);
     }
     printf("________________________________________________________\n\n");
     imprimir_menu();
  }
    else if(o==4){
     opcao4();
     scanf("%s",s);
     while(s[0]=='s'){
       opcao4();
       scanf("%s",s);
     }
     printf("________________________________________________________\n\n");
     imprimir_menu();
  }
    else if(o==5){
     opcao5();
     scanf("%s",s);
     while(s[0]=='s'){
       opcao5();
       scanf("%s",s);
     }
     printf("________________________________________________________\n\n");
     imprimir_menu();
  }
    else if(o==6){
     opcao6();
     scanf("%s",s);
     while(s[0]=='s'){
       opcao6();
       scanf("%s",s);
     }
     printf("________________________________________________________\n\n");
     imprimir_menu();
  }
    else if(o==7){
     opcao7();
     scanf("%s",s);
     while(s[0]=='s'){
       opcao7();
       scanf("%s",s);
     }
     printf("________________________________________________________\n\n");
     imprimir_menu();
  }
    else if(o==8){
     opcao8();
     scanf("%s",s);
     while(s[0]=='s'){
       opcao8();
       scanf("%s",s);
     }
     printf("________________________________________________________\n\n");
     imprimir_menu();
  }
    else if(o==9){
     opcao9();
     scanf("%s",s);
     while(s[0]=='s'){
       opcao9();
       scanf("%s",s);
     }
     printf("________________________________________________________\n\n");
     imprimir_menu();
  }
 return;
}//ler

/*
* @brief chama a função imprimir_menu e lê a opcao digitada pelo usuário para em seguida chamar a função ler
*/
int main(void){
  unsigned int o=1;
  imprimir_menu();
  while(o!=0){
  scanf("%d",&o);
  ler(o);
  }
 return 0;
}//main
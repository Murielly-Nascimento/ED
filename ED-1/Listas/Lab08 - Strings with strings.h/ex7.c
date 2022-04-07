/*7) Faça um programa que receba do usuario uma string. O programa imprime a string
sem suas vogais.*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>


int main(void){
    char str[51]={'\0'};
    char str2[51]={'\0'};
    int tamanho=0;

    printf("<<Sem vogais>>\n");
    printf("Digite a string: ");
    gets(str);
    tamanho =strlen(str);

    for(int i=0,j=0;i<tamanho;i++){
       if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u' && str[i]!='A' && str[i]!='E' && str[i]!='I' && str[i]!='O' && str[i]!='U'){
            str2[j]=str[i];
            j++;
        }
    }
    printf("Saída sem vogais: %s\n",str2);

    
   
    
    return 0;
}
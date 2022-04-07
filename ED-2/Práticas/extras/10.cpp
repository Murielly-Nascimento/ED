/**
 * Escreva uma função recursiva que determine quantas vezes um dı́gito K ocorre em um
 * número natural N. Por exemplo, o dı́gito 2 ocorre 3 vezes em 762021192.
*/

#include <bits/stdc++.h> 
using namespace std;

int repete(string str, char c, int i, int quantidade){
    if(i == str.size()) return quantidade;
    else{
        if(str[i] == c){
            return repete(str,c,i+1, quantidade+1);
        }
        else return repete(str,c,i+1, quantidade);
    }
}

int main(void){
    string str;
    char c;
    cin>>str;
    cin>>c;
    printf("%d\n", repete(str,c,0,0));
    return 0;
}
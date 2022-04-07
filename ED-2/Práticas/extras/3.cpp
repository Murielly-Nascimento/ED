/**
 * Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321
*/

#include <bits/stdc++.h> 
using namespace std;

string inverte(string str, int ini, int fim){
    if(ini >= fim){
        return str;
    }
    else{
        char aux = str[ini];
        str[ini] = str[fim];
        str[fim] = aux;
        return inverte(str, ini+1, fim-1);
    }
}

int main(void){
    string str;
    cin>>str;
    int fim = str.size()-1;
    cout<<inverte(str,0, fim)<<endl;
    

    return 0;
}
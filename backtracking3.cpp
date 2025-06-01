/*
Dada una matriz cuadrada compuesta de 0 y 1, donde 1 es una escalera que permite subir al siguiente piso
hacer un algoritmo que permita determinar si es posible subir o no a la cima

00000                           0000
10100                           0100
00000                           0000
00000                           0000
00000                           no es posible
es posible 
(c) oscar
*/

#include <iostream>
using namespace std;
bool penepucio(int **matriz, int inf, int sup){
    if(sup-inf==0||sup-inf==1){
        return true;
    }
    for(int i=inf; i<=sup; i++){
        if(matriz[inf][i]==1||matriz[sup][i]==1||matriz[i][inf]==1||matriz[i][sup]==1){
            return penepucio(matriz, inf+1, sup-1);
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int **matriz;
    matriz= new int*[n];
    for(int i=0; i<n; i++){
        matriz[i]= new int[n];
    }
    for(int i=0; i<n*n; i++){
        cin>>matriz[i/n][i%n];
    }
    if(penepucio(matriz, 0, n-1)) 
    cout<<"es entrada";
    else 
    cout<<"no es entrada";
}
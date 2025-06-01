/**
Dada una matriz de dimensiones n x n compuesta por números enteros, elabore un
algoritmo que determine la sub-matriz de suma máxima.
(c) oscar
*/
#include <iostream>
using namespace std;
int N; //tamaño de la matriz
int **matrix;
int sumatotal = 0; //suma total de la submatriz
int wmax=0, amax=0, smax=0, dmax=0; // coordenadas de la submatriz de suma máxima

bool verificar(int w, int a, int s, int d){
    if(w < 0 || a < 0 || s < 0 || d < 0) return false; // No puede haber movimientos negativos
    if(w >= N || a >= N || s >= N || d >= N) return false; // No puede salirse de los límites de la matriz
    return true;
}
void sumax(int w, int a, int s, int d){             //suma todos los elementos de la submatriz
    int sumaux=0;                          //y verifica la solucion
    for(int i=w; i<=s; i++){
        for(int j=a; j<=d; j++){
            sumaux += matrix[i][j];
        }
    }
    if(sumaux>=sumatotal){
        sumatotal = sumaux;
        wmax=w; amax=a; smax=s; dmax=d;
    }
}
void moverderecha(int w, int a, int s, int d){
    int auxd= d;
    int auxa= a;
    while(verificar(w, auxa, s, auxd)){
        sumax(w, auxa, s, auxd);
        auxa++;
        auxd++;
    }
}
void moverabajo(int w, int a, int s, int d){
    int auxw = w;
    int auxs = s;
    while(verificar(auxw, a, auxs, d)){
        moverderecha(auxw, a, auxs, d);
        auxw++;
        auxs++;
    }
}
void penepusio(int w, int a, int s, int d){
    if(w >= N-1 || a >= N-1 || s >= N-1 || d >= N-1) return; //cuando la submatriz es igual a la matriz se termina
    moverabajo(w, a, s, d);
    penepusio(w, a, s+1, d+1);
}

int main(){
    cin>>N;                                //pide el tamaño de la matriz
    matrix = new int*[N];                  
    for(int i = 0; i < N; i++){      
        matrix[i] = new int[N];
        for(int j = 0; j < N; j++){        //crea la matriz dinamica y pide valores
            cin >> matrix[i][j];
        }
    }
    penepusio(0, 0, 0, 0); // Inicia el backtracking desde la esquina superior izquierda

    cout<<wmax << " " << amax << " " << smax << " " << dmax << endl; // Imprime las coordenadas de la submatriz de suma máxima


    return 0;

}

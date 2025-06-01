#include <iostream>
using namespace std;
/* Problema N-Reinas Usando Bactracking
0 -> casilla vacia del tablero
-1 -> Reina
1 ... n -> reseprenta la cantidad de colisiones que tiene una casilla invalida (alcanzable por la reina)

*/

const int FILAS = 4, COLUMNAS = 4, REINAS =4;

char REINA = 'Q', VACIO = ' ', INVALIDA = 'x';

int tablero[FILAS][COLUMNAS];

void initTablero(){
	for(int i = 0; i <FILAS; i++){
		for(int j=0; j<COLUMNAS; j++){
			tablero[i][j] = 0;
		}
	}
}

void printTablero(){
    cout<<endl;
	 for(int i = 0; i <FILAS; i++){
	 	cout<<"|";
		for(int j=0; j<COLUMNAS; j++){
		    if(tablero[i][j] ==-1){
		        cout<<REINA<<"|";
		    }
		     else if(tablero[i][j]!=0){
		        cout<<INVALIDA<<"|";
		    } else
			{
			    cout<<VACIO<<"|";
			}
		}
		cout<<endl;
	}
}

bool esCasillaValida(int i, int j){
	for(int k = 0; k < FILAS; k++){
		if(tablero[k][j]!=0){
		    cout<<"A";
		    return false;
		}
		
	}
	
	for(int l = 0; l < COLUMNAS; l++){
		if(tablero[i][l]!=0){
		    cout<<"B";
		    return false;
		}
	}
	// Verificar la diagonal principal que pasa por (i, j)
    for (int k = 0; i - k >= 0 && j - k >= 0; k++) {
        if (tablero[i - k][j - k] != 0 && (i - k != i || j - k != j)) {
            cout<<"C";
            return false;
        }
    }
    for (int k = 1; i + k < FILAS && j + k < COLUMNAS; k++) {
        if (tablero[i + k][j + k] != 0) {
            cout<<"D";
            return false;
        }
    }

    // Verificar la diagonal secundaria que pasa por (i, j)
    for (int k = 0; i - k >= 0 && j + k < COLUMNAS; k++) {
        if (tablero[i - k][j + k] != 0 && (i - k != i || j + k != j)) {
            cout<<"E";
            return false;
        }
    }
    for (int k = 1; i + k < FILAS && j - k >= 0; k++) {
        if (tablero[i + k][j - k] != 0) {
            cout<<"F";
            return false;
        }
    }
	return true;
}

bool esSolucion(int cantReinas){
	return cantReinas == REINAS ? true : false;
}

bool esValida(int i, int j){
    return tablero[i][j]==0 ? true : false;
}

void tacharInvalidas(int i, int j, bool inverso=false){
	int aux = !inverso ? 1 : -1;
	for(int k = 0; k < FILAS; k++){
		tablero[k][j]+=aux;
	}
	for(int l = 0; l < COLUMNAS; l++){
		tablero[i][l]+= aux;
	}
   // Verificar la diagonal principal que pasa por (i, j)
    for (int k = 0; i - k >= 0 && j - k >= 0; k++) {
        tablero[i - k][j - k]+=aux;
    }
    for (int k = 1; i + k < FILAS && j + k < COLUMNAS; k++) {
        tablero[i + k][j + k]+=aux;
    }
    
      // Verificar la diagonal secundaria que pasa por (i, j)
    for (int k = 0; i - k >= 0 && j + k < COLUMNAS; k++) {
    tablero[i - k][j + k] +=aux;
        
    }
    for (int k = 1; i + k < FILAS && j - k >= 0; k++) {
        tablero[i + k][j - k]+= aux;
    }
    tablero[i][j] =!inverso ? -1 : 0;
}

void colocarReina(int i, int j, int &cantReinas){
	cantReinas++;
	tacharInvalidas(i, j);
	
}

void retirarReina(int i, int j, int &cantReinas){
	 cantReinas--;
	tacharInvalidas(i, j, true);
}
int rec =0;
void nReinas(int cantReinas, int pos=0){
    rec++;
    int i = pos;
    while( i < FILAS * COLUMNAS){
        if(esValida(i/FILAS, i%COLUMNAS)){
            colocarReina(i/FILAS, i%COLUMNAS, cantReinas);
            
            if(cantReinas==3){
                cout<<"Solucion"<<endl;
                printTablero();
            } else {
                cout<<endl<<"Voy por"<<i;
                printTablero();
                nReinas(cantReinas, pos+1);
            }
            
            retirarReina(i/FILAS, i%COLUMNAS, cantReinas);
        }
        i++;
    }
}

int main(){
	initTablero();
	//printTablero();
    nReinas(REINAS);
	return 0;
}

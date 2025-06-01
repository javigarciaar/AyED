#include <iostream>
using namespace std;
/* Problema N-Reinas Usando Bactracking
0 -> casilla vacia del tablero
-1 -> Reina
1 ... n -> reseprenta la cantidad de colisiones que tiene una casilla invalida (alcanzable por la reina)

*/

const int FILAS = 8, COLUMNAS = 8, REINAS =8;

int tablero[FILAS][COLUMNAS];

void initTablero(){
	for(int i = 0; i <FILAS; i++){
		for(int j=0; j<COLUMNAS; j++){
			tablero[i][j] = 0;
		}
	}
}

void printTablero(){
	 for(int i = 0; i <FILAS; i++){
	 	cout<<"|";
		for(int j=0; j<COLUMNAS; j++){
			cout<<tablero[i][j]<<"|";
		}
		cout<<endl;
	}
}

bool esCasillaValida(int i, int j){
	for(int k = 0; k < FILAS; k++){
		if(tablero[k][j]!=0)
		return false;
	}
	
	for(int l = 0; l < COLUMNAS; l++){
		if(tablero[i][l]!=0)
		return false;
	}
	for(int k = 0; k < FILAS; k++){
		if(tablero[k][k]!=0)
		return false;
	}
	for(int k = 0; k < FILAS; k++){
		if(tablero[k][FILAS -1 -k]!=0)
		return false;
	}
	return true;
}

bool esSolucion(int cantReinas){
	return cantReinas == REINAS ? true : false;
}

void tacharInvalidas(int i, int j, bool inverso=false){
	int aux = !inverso ? 1 : -1;
	for(int k = 0; k < FILAS; k++){
		tablero[k][j]+=aux;
	}
	for(int l = 0; l < COLUMNAS; l++){
		tablero[i][l]+= aux;
	}
	for(int k = 0; k < FILAS; k++){
		tablero[k][k]+= aux;
	}
	for(int k = 0; k < FILAS; k++){
		tablero[k][FILAS -1 -k]+= aux;
	}
}

void colocarReina(int i, int j, int &cantReinas){
	cantReinas++;
	tacharInvalidas(i, j);
	tablero[i][j] = -1;
	
}

void retirarReina(int i, int j, int &cantReinas){
	 cantReinas--;
	tacharInvalidas(i, j, true);
	//tablero[i][j] = 0;
}

int main(){
	initTablero();
	printTablero();

	return 0;
}


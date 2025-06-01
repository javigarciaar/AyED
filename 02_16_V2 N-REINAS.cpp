#include <iostream>
#include <string>
using namespace std;
/* Problema N-Reinas Usando Bactracking: Las 8 reinas: El problema consiste en colocar en un tablero de ajedrez 
normal 8 reinas sin que alguna ataque a las demás. En el ajedrez, una reina puede atacar a otra pieza 
desplazándose cualquier distancia en casillas: sobre la fila que ocupa, la columna que ocupa o bien sobre 
la diagonal o las diagonales que ocupa. Un tablero de ajedrez normal tiene 8 filas y 8 columnas.
Javier Garcia 26/04/25
0 -> casilla vacia del tablero
-1 -> Reina
1 ... n -> reseprenta la cantidad de colisiones que tiene una casilla invalida (alcanzable por la reina)
*/

//Parametros del problema y de impresion en pantalla
const int FILAS = 8, COLUMNAS = 8, REINAS = 8;
char REINA = 'R', VACIO = ' ', INVALIDA = ' ';

long Soluciones[100];
int cantidadSoluciones = 0;
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
			} else if(tablero[i][j]!=0){
		       cout<<INVALIDA<<"|";
			} else {
		   	cout<<VACIO<<"|";
			}
		}
		cout<<endl;
	}
}

long Procesar(){
	long aux=0;
	for(int i=0; i < FILAS*COLUMNAS; i++){
		if(tablero[i/FILAS][i%COLUMNAS]==-1){
			aux = aux*10 + i%COLUMNAS;
		}
	}
	return aux; 
}

void AgregarSolucion(){
	Soluciones[cantidadSoluciones] = Procesar();
    cantidadSoluciones++;
}

bool existe(){
	
	long valor = Procesar();
	for(int i=0; i<100; i++){
		if(Soluciones[i]==valor){
			return true;
		}
	}
	return false;
}

bool esSolucion(int cantReinas){ // el approach es que conforme se van colocando reinas, quedan menos por colocar hasta 0
return cantReinas == 0 && !existe();
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
	cantReinas--;
	tacharInvalidas(i, j);

}

void retirarReina(int i, int j, int &cantReinas){
	cantReinas++;
	tacharInvalidas(i, j, true);
}

//Funcion Backtracking
void nReinas(int cantReinas, int pos=0){
    int i = pos;
    while( i < FILAS * COLUMNAS){
        if(esValida(i/FILAS, i%COLUMNAS)){
            colocarReina(i/FILAS, i%COLUMNAS, cantReinas);
            
            if(esSolucion(cantReinas)){
			
				AgregarSolucion();
            	
                printTablero();
                
            } else {
                
                nReinas(cantReinas, pos+1);
            }
           
            retirarReina(i/FILAS, i%COLUMNAS, cantReinas);
        }
        i++;
    }
}

int main(){
	initTablero();
    nReinas(REINAS);
	cout<<endl<<"Cantidad Soluciones "<<cantidadSoluciones<<endl;

	return 0;
}

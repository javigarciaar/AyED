#include <iostream>
#include <string>
using namespace std;
/* 2-12 Problema Laberinto camino costo minimo Usando Bactracking
Javier Garcia 02/05/25
Una matriz bidimensional N x N puede representar un laberinto cuadrado. Cada posición contiene un entero no
negativo que indica si la casilla es transitable (0) o si no lo es (1). Las casillas (1, 1) y (n, n) corresponden 
a la entrada y salida del laberinto y siempre son transitables. Dada una matriz con un laberinto, el problema 
consiste en diseñar un algoritmo que encuentre un camino, si existe, para ir de la entrada a la salida. 
Del mismo modo, consiga el camino de costo mínimo (menos casillas que recorrer). 

0 -> casilla transitable del tablero
1 -> casilla NO transitable del tablero
*/

//Parametros del problema y de impresion en pantalla
const int FILAS = 4, COLUMNAS = FILAS;

struct Coord {
	int x;
	int y;
};

const Coord MOV_POSIBLES[]={{ -1, 0}, {1, 0}, {0, -1}, {0,1}};

int contador=0;
long cantMovimientos = 0;
int tablero[FILAS][COLUMNAS];

void initTablero(){ //Inicializar con los datos ingresados por user
	for(int i = 0; i < FILAS; i++){
		for(int j=0; j< COLUMNAS; j++){
			cin>>tablero[i][j];
		}
	}
}

void printTablero(){
    cout<<endl;
	for(int i = 0; i < FILAS; i++){
		cout<<" | ";
		for(int j=0; j<COLUMNAS; j++){
		    cout<<tablero[i][j]<<" | ";
		  
		}
		cout<<endl;
	}
}

void copiarTablero(int a[FILAS][COLUMNAS], int b[FILAS][COLUMNAS]){
	for(int i = 0; i < FILAS; i++){
		for(int j=0; j<COLUMNAS; j++){
		    a[i][j]=b[i][j];
		}
	}
}

Coord Trasladar(int x, int y, Coord alt, int aux=1){
	return {x+ aux*alt.x, y + aux*alt.y};
}

bool EsValida(int x, int y, Coord mov){
	
	x = x + mov.x;
	y = y + mov.y;
	return (tablero[x][y]==0 && x>=0 && x<FILAS && y>=0 && y<COLUMNAS); // transitable && en los limites
}

void moverJugador(int &x, int &y, Coord mov){
	Coord traslado = Trasladar(x,y, mov);
	x = traslado.x;
	y = traslado.y;
	contador++; // aumento los saltos
	tablero[x][y]= 2; //marco la casilla pisada
}

void retirarJugador(int &x, int &y, Coord mov){
	tablero[x][y]= 0; //la desmarco
	Coord traslado= Trasladar(x,y, mov, -1);
	x = traslado.x;
	y = traslado.y;
	contador--; //disminuyo
}

bool esSolucion(int i, int j){
	return i==FILAS-1 && j == COLUMNAS -1; //si llegamos a [N-1][N-1]
}

struct Sol{
	int matriz[FILAS][COLUMNAS];
	int cantMov;
};

Sol arrSol[100]={}; //Conjunto Mejores Soluciones
int index=0; 		//indice del Conj MS

void procesarSolucion(int cantMovimientos){
	
	if(index==0){ // si es el primer elemento
		arrSol[index].cantMov=cantMovimientos;
		copiarTablero(arrSol[index].matriz, tablero); 
		index++;	
	} else if(arrSol[index-1].cantMov > cantMovimientos){ //si consegui uno mejor, actualizo (comparo mi i, con su anterior)
		arrSol[index-1].cantMov=cantMovimientos; 		//no actualizo el indice ya que sobreescribi la casilla i-1
		copiarTablero(arrSol[index-1].matriz, tablero);
		
	} else if(arrSol[index-1].cantMov == cantMovimientos){ // si consegui otra opcion, con la misma cantidad
		arrSol[index].cantMov=cantMovimientos;
		copiarTablero(arrSol[index].matriz, tablero);
		index++; // si actualizo el indice
	}
}

void Laberinto(int i, int j){
	int a = 0;
	while(a < 4){
		if(EsValida(i,j, MOV_POSIBLES[a])){
			
			moverJugador(i,j, MOV_POSIBLES[a]);
			
			if(esSolucion(i, j)){
				procesarSolucion(contador);
				//cout<<contador<<": "<<endl;
				//printTablero();
			} else {
				Laberinto(i, j);
			}
			
			retirarJugador(i, j, MOV_POSIBLES[a]);
		}
		a++;
	}
}

int main(){
	cout<<"Hola, ingresa el tablero para laberinto de "<<FILAS<<"x"<<FILAS<<": "<<endl;
	initTablero();
	printTablero();
    
    tablero[0][0] = 2; // Marcar la casilla inicial
    Laberinto(0, 0);
    
    cout<<"SOLUCIONES:"<<endl;
    for(int k=0; k<10; k++){
    	if(arrSol[k].cantMov != 0){
    		cout<<"- Saltos: "<<arrSol[k].cantMov<<endl;
	
			for(int i = 0; i < FILAS; i++){
				cout<<" | ";
				for(int j=0; j<COLUMNAS; j++){
				    cout<<arrSol[k].matriz[i][j]<<" | ";
				}
				cout<<endl;
			}
		}
	}
}
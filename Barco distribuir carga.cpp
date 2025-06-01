/*
Barco, contenedores en las 2 alas distribuirlos de manera que haya la menor diferencia de peso entre ambas.
cada ala puede alberga la mitad de los contenedores.

*/

#include <iostream>
#include <math.h>
using namespace std;

int MS=INT_MAX;

void rellenarAlaDerecha(int carga[], int n, int alaDer[], bool selAct[] ){
	int index=0;
	for(int i=0; i<n; i++){
		
		if(!selAct[i] && index <=n/2){
			alaDer[index] = carga[i];
			index++;
		}
	}
}

void compararSol(int n, int alaIzq[], int alaDer[]){
	int pesoIzq=0, pesoDer=0;
	for(int i=0; i<n/2; i++){
		pesoIzq+=alaIzq[i];
		pesoDer+=alaDer[i];
	}
	if(abs(pesoIzq-pesoDer) < MS){
		MS = abs(pesoIzq-pesoDer);
	}
}


void distribuir(int carga[], int alaIzq[], int alaDer[], int n, bool selAct[], int paso =0){
	if(paso>=n/2){
		rellenarAlaDerecha(carga,n, alaDer, selAct);
		compararSol(n, alaIzq, alaDer);
		return;
	}
	
	for(int i=0; i<n; i++){
		if(!selAct[i]){
			selAct[i]=true;
			alaIzq[paso]=carga[i];
			distribuir(carga, alaIzq, alaDer, n, selAct, paso +1);
			selAct[i] = false;
			
		}
	}
}

int main(){
	int carga[5]={13, 6, 12, 20, 1};
	int alaIzq[3]={0};
	int alaDer[3]={0};
	bool selAct[5]={false};
	
	distribuir(carga, alaIzq, alaDer, 5, selAct);
	cout<<MS;
	cout<<" Ala derecha: ";
	for(int i=0; i<3; i++){
		cout<<alaIzq[i]<<" ";
	}
	return 0;
}

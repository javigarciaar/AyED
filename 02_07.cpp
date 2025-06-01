/*
03/05/2025 Ejercicio 2-07
Obtener todos los números de m cifras (m <= 9), todas ellas distintas de cero y distintas entre sí, de tal 
manera que el numero formado por las primeras n cifras, cualquiera que sea n (n <= m) sea múltiplo de n. 
Por ejemplo, para m = 4 son números válidos, entre otros, los siguientes: 1236, ya que 1 es múltiplo de 1,
12 de 2, 123 de 3 y 1236 de 4. 9872,pues 9 es múltiplo de 1, 98 de 2, 987 de 3 y 9872 de 4. 
*/

#include <iostream>
using namespace std;

const int CANTIDAD = 3;
int ALTS[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int cifras[CANTIDAD];

void printCifras(int size){
	for(int i = 0; i < size; i++){
		cout<<cifras[i];
	}
	cout<<endl;
}

bool esDivisible(int k, int n){
	return n % k == 0;
}

long convertir(int size){
	long num=0;
	
	for(int i=0; i<size; i++){
		num = num*10 + cifras[i];
	}
	return num;
}

bool sonDiferentes(int size){
	for(int i=0; i< size -1; i++){
		for(int j=i + 1; j<size; j++){
			if(cifras[i]==cifras[j]){
				return false;
			}
		}
	}
	return true;
}

bool esSolucion(int size){
	
	for(int i=0; i< size; i++){
		long aux = convertir(i + 1);
		if(!esDivisible(i+1, aux)){
			return false;
		}
	}
	
	if(sonDiferentes(size)){
		return true;	
	}
	return false;
	
}

void escribirNumero(int index, int numero){
	cifras[index] = numero;
}

bool esValida(int index, int size){
	return index < size;
}

void backtracking(int size = CANTIDAD, int paso=0){
	int i = 0;
	while(i < 10){
		if(esValida(paso, size)){
			int alt = ALTS[i];
			escribirNumero(paso, alt);
			
			if(esSolucion(size)){
				printCifras(size);
			} else {
				backtracking(size, paso + 1);
			}
		}
		i++;
	}
}

int main(){
	backtracking(3);
}


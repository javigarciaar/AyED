/*
P2. 8) Dado un entero N, imprimir todas las expresiones aritméticas compuestas por los operadores +, - , * y /, 
y los primeros N números naturales en orden en la cual el resultado sea igual a un R dado. El orden de prioridad 
es de izquierda a derecha. Ejemplo: Para N=4 y R=0, algunas expresiones podrían ser: 
-1 -2 +3 * 4 = 0, +1 +2 -3 *4 = 0 
*/
#include <iostream>
#include <string>
using namespace std;

/*
string to_string(int numero){
	string conv = "";
	while(numero!=0){
		
		char aux = (numero%10) + '0';
		numero/=10;
		conv = aux + conv;
		
	}
	return conv;
}
*/
void backtrack(int N, int R, int paso=1, int sol=0, string secuencia = ""){
	if(paso == N + 1){
		if(sol == R){
			cout<<secuencia<<" = "<<R<<endl;
		}
		return;
	} else {
		backtrack(N, R, paso+1, sol+paso, secuencia + "+" + to_string(paso));
		backtrack(N, R, paso+1, sol-paso, secuencia + "-" + to_string(paso));
		if( paso > 1){
			backtrack(N, R, paso+1, sol*paso, secuencia + "*" + to_string(paso));
			backtrack(N, R, paso+1, sol/paso, secuencia + "/" + to_string(paso));	
		}
		
	}
}

int main(){
	//string s= to_string(123);
	//cout<<s;
	backtrack(13, -10);
}

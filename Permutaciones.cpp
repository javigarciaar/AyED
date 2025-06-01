/* P2 9) Obtener todos los números de m cifras (m <= 9), todas ellas distintas de cero y distintas entre sí, de tal manera que el 
numero formado por las primeras n cifras, cualquiera que sea n (n <= m) sea múltiplo de n. Por ejemplo, para m = 4 
son números válidos, entre otros, los siguientes: 1236, ya que 1 es múltiplo de 1, 12 de 2, 123 de 3 y 1236 de 4. 9872, 
pues 9 es múltiplo de 1, 98 de 2, 987 de 3 y 9872 de 4. 
*/
#include <iostream>
using namespace std;

const int CANTIDAD = 9;
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
int cont=0;
void backtracking(int size = CANTIDAD, int paso=0){
	int i = 0;
	while(i < 10){//cantNumorisBD
		if(esValida(paso, size)){
			//int alt = ALTS[i];
			escribirNumero(paso, i);
			if(paso == size -1 && sonDiferentes(size)){
                cont++;
				//printCifras(size);
			} else {
				backtracking(size, paso + 1);
			}
		}
		i++;
	}
}

int main(){
    cout<<"Combinaciones de 6 cifras"<<endl;
	backtracking(9);
    cout<<cont<<endl;
}
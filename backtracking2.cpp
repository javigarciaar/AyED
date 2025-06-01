/*El problema de la mochila o Knapsack consiste en llenar una mochila con una serie de objetos asociados a una serie de pesos
con un valor asociado. Es decir, se dispone de iN tipos de objetos y que no hay un numero limitado de cada tipo de objeto (si
fuera limitado no cambia mucho el problema). Cada tipo i de objeto tiene un peso aW eight[i] positivo y un valor aV alue[i]
positivo asociados.
La mochila tiene una capacidad de peso igual a iCapacity. Se trata de llenar la mochila de tal manera que se maximice el
valor de los objetos incluidos pero respetando al mismo tiempo la restricci´on de capacidad.
(c) oscar*/


#include <iostream>     
using namespace std;

struct objeto{
	int valor;
	int peso;
};

objeto *arr;
int tamanoDeMochila, cantidadDeObjetos;
objeto mochila;
objeto mejorMochila= {0,10000};


bool verificar(int i){
	if(mochila.peso+arr[i].peso>tamanoDeMochila){
  	return false;
  }
  return true;
}

void añadir(int i){
	mochila.peso+=arr[i].peso;
  mochila.valor+=arr[i].valor;
}
void imprimir(){
	cout<<mejorMochila.peso<<endl<<mejorMochila.valor<<endl;
}

void compararsol(){
	if(mochila.valor>=mejorMochila.valor){
  	mejorMochila.peso=mochila.peso;
  	mejorMochila.valor=mochila.valor;
    //imprimir();
  }
}
void retroceder(int i){
  mochila.peso-= arr[i].peso;
  mochila.valor-= arr[i].valor;
}

void carajo(objeto *arr, int indice){
  int i=0;
	for(; i<cantidadDeObjetos; i++){
  	if(verificar(i)){             
      añadir(i);
      compararsol();
      carajo(arr, i);
    }
  }
  retroceder(indice);
}

int main(){
  cin>>tamanoDeMochila;                            
  cin>>cantidadDeObjetos;
  
  arr= new objeto[cantidadDeObjetos];           
  for(int i=0; i<cantidadDeObjetos; i++){
  	cin>>arr[i].valor>>arr[i].peso;
  }
  
  carajo(arr, -1);
  imprimir();
	return 0;
}
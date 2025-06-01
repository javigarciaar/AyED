/*
Dado un arreglo de N números enteros, diseñar algoritmos recursivos que calculen:
● El mayor elemento del arreglo.
● La suma de los elementos del arreglo.
● La media de todos los elementos del arreglo.
● Verificar si el arreglo está ordenado.
*/
#include <iostream>

using namespace std;

int mayorElemento(int arr[], int size){
	
	if(size<=1){
		return arr[0];
	}
	
	return (arr[size-1] >= mayorElemento(arr, size-1)? arr[size-1] : mayorElemento(arr, size-1));
	
}

int sumaElementos(int arr[], int size){
	
	if(size<=1){
		return arr[0];
	}
	
	return arr[size-1] + sumaElementos(arr, size-1);
}

float promedio(int arr[], int size, int paso =1){
	if(size<=1){
		return arr[0]/(float)paso;
	}
	
	arr[size-2]+=arr[size-1];
	
	return promedio(arr, size-1, paso+1);

	
}

bool estaOrdenado(int arr[], int size){
	
	if(size<=1){
		return true;
	}
	
	if(arr[size-2]> arr[size-1]){
		return false; 
	}
	
	return estaOrdenado(arr, size-1);
	
}

int main(){
	int arr[]={-100, -9,0, 9, 100, 1000};
	//int arr[]={-1,100, 23, 12345, -123, 24, 2, 4, 10, -1000};
	int size = sizeof(arr)/sizeof(int);
	cout<<mayorElemento(arr,size)<<endl;
	cout<<sumaElementos(arr,size)<<endl;
	cout<<promedio(arr,size)<<endl;
	cout<<estaOrdenado(arr, size);
	return 0;
}
/*
Operacion a + b*c/d = X, dado un X y un arreglo de enteros sin duploicados a ser usado en la formula, hallar
los valores de a, b, c  y d para que sea valida y todos sean diferentes.
*/
#include <iostream>

using namespace std;

bool Operacion(int arr[], int N, int X, bool selAct[], int paso=0, int res=0, string s=""){
	if(paso==4)
		if(res == X){
			cout<<s<<endl;
			return true;
		}
			
	
	for(int i=0; i<N; i++){
		if(!selAct[i]){
			selAct[i]=true;
			switch(paso){
				case 0:
					Operacion(arr, N, X, selAct, paso + 1, arr[i], s + to_string(arr[i]));
					break;
				case 1:
					Operacion(arr, N, X, selAct, paso + 1, res*arr[i], s + "*" + to_string(arr[i]));
					break;
				case 2:
					Operacion(arr, N, X, selAct, paso + 1, res/arr[i], s + "/" + to_string(arr[i]));
					break;
				case 3:
					Operacion(arr, N, X, selAct, paso + 1, res+arr[i], to_string(arr[i]) + "+" + s);
					break;
			}
			selAct[i]=false;
		}
	}
	return false;
}

int main(){
	int arr[8]={1, 2, 3, 4, 5, 6, 7, 8};
	bool selAct[8] = { false};
	Operacion(arr, 8, 100, selAct);

	return 0;
}

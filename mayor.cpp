#include <iostream>

using namespace std;

int mayor(int arr[], int size){
	if(size ==1){
		return arr[0];
	}
	
	if(arr[0] >= arr[size-1]){
		size--;
	} else if(arr[0] < arr[size-1]){
		arr[0] = arr[size -1];
		size--;
	}
	mayor(arr, size);
}

int main(){
	int arr[]={-1, 20, 2, -10, 2, 9, 29, -2, 100, 100, -10, -100000};
	cout<<mayor(arr, 12);
}

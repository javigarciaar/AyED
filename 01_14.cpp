/*
14. Elabore un algoritmo recursivo el cual dado un arreglo de enteros ordenado en forma ascendente y sin elementos
repetidos, haga una búsqueda binaria de un elemento E indicando si éste existe en el mismo.

*/
#include <iostream>

using namespace std;

bool binarySearch(int arr[], int izq, int der, int target){
	
	if(izq > der) return false;
	
	int mid = (izq + der)/2; //ojo el i + (f-i)/2
	
	if(target==arr[mid]){
		return true;
	} else if(target < arr[mid]){
		return binarySearch(arr, izq, mid -1, target);	//ojo el mid-1
	}
	return binarySearch(arr, mid+1, der, target);	
	
	
}

int BinarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, high, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}
int main(){
	int arr[]={-100, -9,0,9, 12, 100, 1000};
	//int arr[]={-1,100, 23, 12345, -123, 24, 2, 4, 10, -1000};
	int size = sizeof(arr)/sizeof(int);
	cout<<binarySearch(arr,0, size-1, 9)<<endl;
	cout<<BinarySearch(arr,0, size-1, 9)<<endl;

	return 0;
}

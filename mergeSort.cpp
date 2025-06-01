#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
	int sA = mid - left +1;
	int sB = right - mid;
	
	int A[sA], B[sB];
	
	for(int i=0; i<sA; i++){
		A[i] = arr[left + i];
	}
	
	for(int i=0; i<sB; i++){
		B[i] = arr[mid +1 + i];
	}
	
	int ai=0, bi=0, ci=left;
	
	while(ai < sA && bi < sB){
		if(A[ai] == B[bi]){
			arr[ci] = A[ai];
			ai++; bi++; ci++;
		} else if(A[ai] < B[bi]) {
			arr[ci] = A[ai];
			ai++; ci++;
			
		} else {
			arr[ci] = B[bi];
			bi++; ci++;
		}
	}
	
	while( ai < sA){
		arr[ci] = A[ai];
		ai++; ci++;
	}
	
	while( bi < sB){
		arr[ci] = B[bi];
		bi++; ci++;
	}
}

void MergeSort(int arr[], int left, int right){
	
	if(left <= right) return;
	
	int mid = left + (right - left) / 2;
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}


int main(){
	int array[] = {3, 13, 29, -1, 12, 40, 2, 100, -1001, 34, 34, 21};
	int size = sizeof(array) / sizeof(int);
	
	MergeSort(array, 0, size);
	cout<<"Array ordenado con MergeSort"<<endl;
	for(int i = 0; i < size; i++){
		cout<<array[i]<<", ";
	}
	return 0;
}


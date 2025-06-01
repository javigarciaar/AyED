#include <iostream>
using namespace std;

bool buscarTarget(int arr[], int target, int size){
	int index=size-1;
	if(index <0){
  	return false;
  } else if(arr[index]==target){
  	return true;
  } else {
  	buscarTarget(arr, target, index -1);
  }
}
int main(){
	int arr[]={1,2,3,4,5,6,7,8,9,10,11};
	int size = 11;
	cout<<buscarTarget(arr, 27, size);
	return 0;
}


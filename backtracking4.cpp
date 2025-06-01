/* Dado un arreglo de n enteros y un numero X, determinar las combinaciones que satisfagan la formula
a+b*c/d=x. (c) oscar
*/

#include <iostream>
using namespace std;
int arreglo[4];
void penepucio(int arr[], int x, int i){
    if(arr[0]+arr[1]*arr[2]/arr[3]==x){
        cout<<"a= "<<arr[0]<<endl;
        cout<<"b= "<<arr[1]<<endl;
        cout<<"c= "<<arr[2]<<endl;
        cout<<"d= "<<arr[3]<<endl;
    }
    if(i>=4) return;
    for(int k=i; k<4; k++){
        swap(arr[k], arr[i]);
        penepucio(arr, x, i+1);
        swap(arr[k], arr[i]);
    }
}
int main(){
    int n; 
    cin>>n;
    for(int i=0; i<4; i++){
        cin>>arreglo[i];
    }
    penepucio(arreglo, n, 0);
}
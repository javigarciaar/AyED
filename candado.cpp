#include <iostream>
#include <math.h>
using namespace std;
int n;

void aumentar( int *n, int a, int *arr){
    arr[3]=a;
    //comprobacion;
    for(int i=3; i>0; i--){
        if(arr[i]>9){
            arr[i-1]++;
            arr[i]=0;
            a=-1;
        }
    }

    if(arr[0]==n[0]&&arr[1]==n[1]&&arr[2]==n[2]&&arr[3]==n[3]){
        cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<endl;
    }
    
    else{
        cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<endl;
        aumentar(n, a+1, arr);
    }}
    

int main(){
    int arr[4]={0,0,0,0};
    int a=0;
    int n[4];
    for(int i=0; i<4; i++){
        cin>>n[i];
    }
    aumentar(n, a, arr);


}
#include <iostream>
using namespace std;

int main() {
    int x=0;
    int a[]={1,2,3,4,5, 6};
    int n=sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n; i+=2) {
        int j=2;
        for(int k = 1; k <= j; k++) {
            x++;
            cout<<a[0];
        }
    }
    
    /*
    Funcion recursiva que calcule el minimomelemento de un segmeneto de arreglo. Utilice la firma
    int min(int a[], int li, int ls) donde a es el arreglo, li es el indice inicial y ls es el indice final.
    */
    int min(int a[], int li, int ls){ 
        //hecho por la Ia
        if (li == ls) {
            return a[li];
        } else {
            int mid = (li + ls) / 2;
            int leftMin = min(a, li, mid);
            int rightMin = min(a, mid + 1, ls);
            return (leftMin < rightMin) ? leftMin : rightMin;
        }
    }

    int min(int a[], int li, int ls) { //hecho por Javier - lo modifica, not so good
        if (li == ls) {
            return a[li];
        } else {
            if(arr[li] > arr[ls]){
                arr[li]=arr[ls];
            }
            return min(arr, li, ls-1);
        }
    }

    return 0;
}
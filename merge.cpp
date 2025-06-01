#include <iostream>
using namespace std;

void merge ( int a[ ] , int b[ ] , int sa , int sb , int c[ ], int &sc ) {
    sc = sa + sb ;
    int ai = 0 , bi = 0 , ci = 0 ;
    while ( ci<sc ) { // Pa
        if ( a [ ai ] == b [ bi ] ) {
            c [ ci ] = a [ ai ] ;
            ai ++ , bi ++ , ci ++ ;
            sc--;
        } else if ( a [ ai ] < b [ bi ] ) {
            c [ ci ] = a [ ai ] ;
            ai ++ , ci ++ ;
        } else {
            c [ ci ] = b [ bi ] ;
            bi ++ , ci ++ ;
        }
    }
}
int main(){
	int a[] = {2,5,7};
	int b[] = {2,4};
	int sc=10;
	int c[10];
	merge(a,b,3, 2, c, sc);
	
	for(int i=0; i<sc; i++){
		cout<<c[i]<<" ";
	}

	return 0;
}


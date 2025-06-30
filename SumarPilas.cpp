#include <iostream>
using namespace std;
#include "pila.h"

void Rellenar(Pila<int> &A, int a){
    int rev =0;
    while(a!=0){
        rev = rev*10 + a%10;
        a=a/10;
    }
    while(rev!=0){
        A.push(rev%10);
        rev/=10;
    }
}

int SumarPilas(int a, int b){
    Pila<int> A, B, C;
    int carry =0, r=0;
    Rellenar(A, a);
    Rellenar (B, b);
    while(!A.isEmpty() and !B.isEmpty()){
        r = *A.pop() + *B.pop() + carry;
        C.push(r%10);
        carry = r/10;
    }
    while(!A.isEmpty()){
        r = *A.pop() + carry;
        C.push(r%10);
        carry = r/10;
    }
    while(!B.isEmpty()){
        r = *B.pop() + carry;
        C.push(r%10);
        carry = r/10;
    }
    int res=0;
    while(!C.isEmpty()){
        res = res*10 + *C.pop();
    }
    return res;
}

int main(){
    cout<<SumarPilas(145, 535);
}
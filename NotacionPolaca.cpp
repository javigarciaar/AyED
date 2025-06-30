#include "lista.h"
#include "pila.h"
#include <iostream>
using namespace std;

void transformar(Lista<string> &A, Pila<string> &B){
    Nodo<string> *first = A.getHead();
    Nodo<string> *second = first->next;
    while(first != nullptr && second != nullptr){
            swap(first->valor, second->valor);
            first = second->next;
            second = first->next;
    }

    while(!A.isEmpty()){
        B.push(*A.pop());
    }
}

float evaluar(Pila<string> &B){
    Pila<float> C;
    while(!B.isEmpty()){
        string *x = B.pop();
        if(*x == "+"){
            float a = *C.pop();
            float b = *C.pop();
            C.push(a + b);
        } else if(*x == "-"){
            float a = *C.pop();
            float b = *C.pop();
            C.push(b - a);
        } else if(*x == "*"){
            float a = *C.pop();
            float b = *C.pop();
            C.push(a * b);
        } else if(*x == "/"){
            float a = *C.pop();
            float b = *C.pop();
            C.push(b / a);
        } else {
            C.push(stof(*x));
        }
    }
    return *C.top();
}

int main(){
    Lista<string> A;
    Pila<string> B;
    A.agregarAlFinal("1");
    A.agregarAlFinal("+");
    A.agregarAlFinal("2");
    A.agregarAlFinal("*");
    A.agregarAlFinal("3");
    A.print("Lista A: ");
    transformar(A, B);
    B.print("Pila B: ");
}
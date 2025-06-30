/*
Realice el algoritmo recursivo de fibonacci, esta vez utilice una EDD para almacenar los valores que ya han sido 
calculados. Antes de llamar a la recursión verifique si se encuentra el valor en la estructura, de ser así 
tomen ese valor y no llaman a la recursión ... si no, realizan la recursión
*/

#include <iostream>
using namespace std;

class Nodo{
    public:
    int n;
    int fib;
    Nodo* next;

    Nodo(int n =-1, int fib = -1) : n(n), fib(fib), next(nullptr) {}

};

class Lista {
protected:
    Nodo* head;
    int size;
public:
    Lista() : head(nullptr), size(0) {}

    ~Lista() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int n, int valor) {
        Nodo* newNode = new Nodo(n, valor);
        if (isEmpty()) {
            head = newNode;
        } else {
            Nodo* aux = head;
            while (aux->next != nullptr) {
                aux = aux->next;
            }
            aux->next = newNode;
        }
        size++;
    }

    void pop() {
        if (isEmpty()) return;
        Nodo* temp = head;
        
        head = head->next;
        delete temp;
        size--;
        return;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int getSize() const {
        return size;
    }

    void print(string mensaje = "", bool enter = true) {
        cout << mensaje;
        if (enter) cout << endl;
        else cout << " ";
        for (Nodo* aux = head; aux != nullptr; aux = aux->next)
            cout<<aux->fib<<" ";
        cout << endl;
    }

    bool existe(int valor){
        for (Nodo* aux = head; aux != nullptr; aux = aux->next)
            if(aux->n == valor)
                return true;
        return false;
    }

    int buscar(int n){
        for (Nodo* aux = head; aux != nullptr; aux = aux->next)
            if(aux->n == n)
                return aux->fib;
        return -1;
    }

    Nodo* getHead() const { //para poder acceder al head desde la clase ED
        return head;
    }
};
Lista calculados;
int fib(int n){
    
    int x = -1, y=-1;
    if(n == 1 or n == 0)
        return n;

    if(!calculados.existe(n-1)){
        x = fib(n-1);
    } else {
        x = calculados.buscar(n-1);
    }

    if(!calculados.existe(n-2)){
        y = fib(n-2);
    } else {
        y = calculados.buscar(n-2);
    }

    calculados.push(n, x+y);
    return x + y;
}

int fib2(int n){
    if(n<=1) return n;
    return fib2(n-1) + fib2(n-2);
}

int main(){
    int N = 2;
    cout<<fib(N)<<endl;
    cout<<fib2(N);

    calculados.print("Valores calculados: ");
}

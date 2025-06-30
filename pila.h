#include <iostream>
#include "nodo.h"
using namespace std;

template <typename T>
class Pila{
protected:
    Nodo<T> *primero;
    int size;

public:
    Pila(): primero(nullptr), size(0) {}

    ~Pila() {
        while(!isEmpty()) {
            this->pop(); // Liberar memoria de los nodos
        }
    }
    /*
    *insertar nuevo elemento (arriba/antes de los demas)
    * @param valor El valor a insertar en la pila.
    */
    void push(T valor) {
        Nodo<T> *temp = new Nodo<T>(valor, primero);
        primero = temp;
        size++;
    }
    /*
    * Remover el elemento mas arriba de la pila y devolver su valor.
    * @return Un puntero al valor del elemento removido, o nullptr si la pila
    */
    T* pop() { //remover el mas arriba
        if (this->isEmpty()){
            return nullptr;
        }
        T* valor = new T(primero->valor);
        Nodo<T> *temp = primero;
        primero = primero->next;
        delete temp;
        size--;
        return valor;
    }
    /*
    * Obtener el elemento mas arriba de la pila sin removerlo.
    * @return Un puntero al valor del elemento mas arriba, o nullptr si la pila
    */
    T* top() { //Obtener el elemento mas arriba
        if (this->isEmpty())
            return nullptr;
        return new T(primero->valor);
    }
    int getsize() {
        return this->size;
    }
    bool isEmpty() {
        return this->primero == nullptr;
    }
    void print(string mensaje = "", bool enter = true) {
        cout << mensaje;
        if(enter) cout<<endl;
        else cout<<" ";
        for (Nodo<T> *aux = primero; aux != NULL; aux = aux->next)
            cout << aux->valor << " ";
        cout << endl;
    }

    void aggAlFondo(T valor){
        if(this->isEmpty()){
            this->push(valor);
            return;
        }
        T* x = new T(*this->pop());
        aggAlFondo(valor);
        this->push(*x);
        return;
    }

    void invertir(){
        if(this->isEmpty())
            return;
        T* x = new T(*this->pop());
        invertir();
        this->aggAlFondo(*x);
        return;
    }

    void clear() {
        while (!isEmpty()) {
            pop(); // Liberar memoria de los nodos
        }
    }

    Pila* clonar(){
        Pila* clon = new Pila();
        Nodo<T>* aux = this->primero;
        while(aux != nullptr){
            clon->push(aux->valor);
            aux = aux->next;
        }
        clon->invertir();
        return clon;
    }

    void invertirSR(){
        Pila* nueva = new Pila();
        while(!this->isEmpty()){
            nueva->push(*this->pop());
        }
        this->clear();
        this->primero = nueva->primero;
    }
};
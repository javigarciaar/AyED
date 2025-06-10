#include <iostream>
using namespace std;

class Nodo {
public:
    int valor;
    Nodo *next;

    Nodo(int valor = 0, Nodo *next = NULL) {
        this->valor = valor;
        this->next = next;
    }
};

class Lista
{
    Nodo *primero;
    int size;

public:
    Lista() {
        this->size = 0;
        this->primero = NULL;
    }

    ~Lista() {
        delete this->primero;
    }
    void preappend(int valor) { //insertar nuevo elemento (arriba/antes de los demas)
        Nodo *temp = new Nodo(valor, primero);
        primero = temp;
        size++;
    }
    void append(int valor){
        Nodo *temp = new Nodo(valor);
        Nodo *aux = primero;
        for (;aux->next != NULL; aux = aux->next);
        aux->next = temp;
        size++;
    }
    void poplast(){
        Nodo *temp = primero;
        primero = primero->next;
        delete temp;
        size--;
    }
    void deleteFirst() { //remover el mas arriba
        if (this->isEmpty())
            return;
        Nodo *temp = primero;
        primero = primero->next;
        delete temp;
        size--;
    }
    bool search( int target) { //verificar si hay target
        for (Nodo *aux = primero; aux != NULL; aux = aux->next){
            if(aux->valor == target) return true;
        }
        return false;
    }
    int getsize() {
        return this->size;
    }
    bool isEmpty() {
        return primero == NULL;
    }
    void print(){
        for (Nodo *aux = primero; aux != NULL; aux = aux->next)
            cout << aux->valor << " ";
    }
};
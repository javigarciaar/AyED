/*Javier Garcia 5/6/25
IMPLEMENTACION DE PILAS usando memoria dinamica
*/

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

class Pila
{
    Nodo *primero;
    int size;

public:
    Pila() {
        this->size = 0;
        this->primero = NULL;
    }

    ~Pila() {
        delete this->primero;
    }
    void push(int valor) { //insertar nuevo elemento (arriba/antes de los demas)
        Nodo *temp = new Nodo(valor, primero);
        primero = temp;
        size++;
    }
    int pop() { //remover el mas arriba
        if (this->isEmpty())
            return INT_MIN;
        int valor = primero->valor;
        Nodo *temp = primero;
        primero = primero->next;
        delete temp;
        size--;
        return valor;
    }
    int top() { //Obtener el elemento mas arriba
        if (this->isEmpty())
            return INT_MIN;
        return primero->valor;
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

int main()
{
    Pila pila1;
    pila1.push(10);
    pila1.push(234);
    pila1.push(1560);
    pila1.push(934);
    cout << "El tamano de la pila es: " << pila1.getsize() << endl;
    cout << "El elemento top de la pila es: " << pila1.top() << endl;
    cout << "Removiendo el elemento de arriba ";
    pila1.pop();
    cout << "Ahora el nuevo top de la pila es: " << pila1.top() << endl;
    pila1.pop();
    cout << "Ahora el nuevo top de la pila es: " << pila1.top() << endl;
    pila1.pop();
    cout << "El tamano de la pila es: " << pila1.getsize() << endl;
    cout << "Ahora el nuevo top de la pila es: " << pila1.top() << endl;
    pila1.pop();
    cout << "El tamano de la pila es: " << pila1.getsize() << endl;
    cout << "Ahora el nuevo top de la pila es: " << pila1.top() << endl;
}
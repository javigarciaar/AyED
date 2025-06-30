#pragma once
#include <iostream>

template <typename T>
class Nodo
{
public:
    T valor;
    Nodo *next;

    Nodo(T v) : valor(v), next(nullptr) {}
};
template <typename T>
class Cola{
protected:
    int size;
    Nodo<T> *front;
public:
    Cola();
    ~Cola();
    void push(T valor);
    T* pop();
    T* peek();
    bool isEmpty();
    int getSize();
    void print(std::string mensaje = "", bool enter = true);
    Cola* clonar();
    void invertir();
    void aggDePrimero(T valor);
    void clear();
};

template <typename T>
Cola<T>::Cola() : front(nullptr), size(0) {}

template <typename T>
Cola<T>::~Cola() {
    while(!isEmpty()) {
        pop();
    }
}

template <typename T>
void Cola<T>::push(T valor) {
    Nodo<T>* new_p = new Nodo<T>(valor);
    if (isEmpty()) {
        front = new_p;
    } else {
        Nodo<T>* aux = front;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new_p;
    }
    size++;
}
template <typename T>
T* Cola<T>::pop() {
    if (isEmpty()) return nullptr;
    Nodo<T>* temp = front;
    T* valor = new T(front->valor); // Retorna un puntero al valor
    front = front->next;
    delete temp;
    size--;
    return valor; // Retorna el valor eliminado
}
template <typename T>
T* Cola<T>::peek() {
    if (isEmpty()) return nullptr; // Retorna un valor por defecto
    T* valor = new T(front->valor); // Retorna un puntero al valor del frente
    return valor;
}
template <typename T>
bool Cola<T>::isEmpty() {
    return Cola<T>::front == nullptr;
}
template <typename T>
int Cola<T>::getSize() {
    return Cola<T>::size;
}
template <typename T>
void Cola<T>::print(std::string mensaje, bool enter) {
    std::cout << mensaje;
    if(enter) std::cout << std::endl;
    else std::cout << " ";
    for (Nodo<T>* aux = front; aux != nullptr; aux = aux->next)
        std::cout << aux->valor << " ";
    std::cout << std::endl;
}
template <typename T>
Cola<T>* Cola<T>::clonar() {
    Cola* clon = new Cola();
    Nodo<T>* aux = this->front;
    while(aux != nullptr) {
        clon->push(aux->valor);
        aux = aux->next;
    }
    return clon;
}
template <typename T>
void Cola<T>::invertir() {
    if (isEmpty()) return;
    Nodo<T>* temp = front;
    front = nullptr;
    while (temp != nullptr) {
        Nodo<T>* next = temp->next;
        temp->next = front;
        front = temp;
        temp = next;
    }
}
template <typename T>
void Cola<T>::aggDePrimero(T valor) {
    Nodo<T>* newNode = new Nodo<T>(valor);
    newNode->next = front;
    front = newNode;
    size++;
}
template <typename T>
void Cola<T>::clear() {
    while (!isEmpty()) {
        pop(); // Liberar memoria de los nodos
    }
}
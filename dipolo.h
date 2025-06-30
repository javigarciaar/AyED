#include <iostream>
using namespace std;
template <typename T>
class Nodo
{
public:
    T valor;
    Nodo *next;
    Nodo *prev;

    Nodo(T v) : valor(v), next(nullptr), prev(nullptr) {}
};
template <typename T>
class Dipolo{
protected:
    Nodo<T> *front;
    Nodo<T> *back;
public:
    Dipolo() : front(nullptr), back(nullptr) {}

    void pushFront(T valor)
    {
        Nodo<T> *new_p = new Nodo(valor);
        if (!isEmpty()){ // Si la lista no esta vacia
            this->front->prev = new_p;
            new_p->next = this->front;
        }
        else{
            this->back = new_p;
        }
        this->front = new_p;
    }

    void popFront()
    {
        if (isEmpty())
            return;
        Nodo<T> *temp = this->front;
        this->front = this->front->next;
        if (this->front){ // Si hay un nodo prev (no es el front)
            this->front->prev = nullptr;
        }
        else
        { 
            this->back = nullptr;
        }
        temp->next = nullptr; 
        delete temp;
    }

    bool isEmpty()
    {
        return this->front == nullptr && this->back == nullptr;
    }

    void pushBack(T valor)
    {
        Nodo<T> *new_p = new Nodo(valor);
        if (!isEmpty()){ // si no esta vacia
            this->back->next = new_p;
            new_p->prev = this->back;
        }
        else{ 
            this->front = new_p;
        }
        this->back = new_p;
    }

    void popBack()
    {
        if (isEmpty())
            return;

        Nodo<T> *temp = this->back;
        this->back = this->back->prev;
        if (this->back){ // Si hay un next (no es el ultimo)
            this->back->next = nullptr;
        }
        else{
            this->front = nullptr;
        }
        temp->prev = nullptr;
        delete temp;
    }

    void printFront(bool espacio = true) {
    for (Nodo<T>* aux = this->front; aux != nullptr; aux = aux->next) {
        cout << aux->valor;
        if(espacio) cout<<" ";
    }
    cout << endl;
    }

    void printBack( bool espacio = true) {
        for (Nodo<T>* aux = this->back; aux != nullptr; aux = aux->prev) {
            cout << aux->valor << " ";
            if(espacio) cout<<" ";
        }
        cout << endl;
    }
};
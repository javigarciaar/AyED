#include <iostream>
#include "nodo.h"

template <typename T>
class Lista {
protected:
    Nodo<T>* head;
    int size;
public:
    Lista() : head(nullptr), size(0) {}

    ~Lista() {
        while (!isEmpty()) {
            pop();
        }
    }
    /*
    * Agrega un nuevo nodo al final de la lista.
    * @param valor El valor a agregar al final de la lista.
    */
    void agregarAlFinal(T valor) {
        Nodo<T>* newNode = new Nodo<T>(valor);
        if (isEmpty()) {
            head = newNode;
        } else {
            Nodo<T>* aux = head;
            while (aux->next != nullptr) {
                aux = aux->next;
            }
            aux->next = newNode;
        }
        size++;
    }
    /*
    * Elimina el primer nodo de la lista y devuelve su valor.
    * @return Un puntero al valor del nodo eliminado, o nullptr si la lista está vacía.
    */
    T* pop() {
        if (isEmpty()) return nullptr;
        Nodo<T>* temp = head;
        T* valor = new T(head->valor);
        head = head->next;
        delete temp;
        size--;
        return valor;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int getSize() const {
        return size;
    }
    /*
    * Imprime los valores de la lista.
    * @param mensaje Un mensaje opcional que se imprime antes de los valores de la lista
    * @param enter true, imprime un salto de línea al final; false, imprime un espacio.
    */
    void print(std::string mensaje = "", bool enter = true) {
        std::cout << mensaje;
        if (enter) std::cout << std::endl;
        else std::cout << " ";
        for (Nodo<T>* aux = head; aux != nullptr; aux = aux->next)
            std::cout <<aux->valor;//.print();
        std::cout << std::endl;
    }

    Nodo<T>* getHead() {
        return head;
    }

};
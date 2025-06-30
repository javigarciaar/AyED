#include <iostream>
using namespace std;

template <typename T>
class Nodo {
public:
    T valor;
    Nodo* nextC;
    Nodo* nextN;

    Nodo(T p) : valor(p), nextC(nullptr), nextN(nullptr) {}
};

class Persona{
    string nombre;
    int edad;
public:
    Persona(string n, int e) : nombre(n), edad(e) {}
    
    void print() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }

    bool compEdad(const Persona& otra) {
        return this->edad < otra.edad;
    }

    bool compNombre(const Persona& otra) {
        return this->nombre < otra.nombre;
    }

    bool operator>(int edad) {
        return this->edad > edad;
    }

    bool operator>(string nombre) {
        return this->nombre > nombre;
    }

    string getNombre() const {
        return nombre;
    }

    int getEdad() const {
        return edad;
    }

};

class ListaMultienlazada {
protected:
    Nodo<Persona>* headN;
    Nodo<Persona>* headC;
    int size;
public:
    ListaMultienlazada() : headN(nullptr), headC(nullptr), size(0) {}
/*
    ~ListaMultienlazada() {
        while (!isEmpty()) {
            pop();
        }
    }
*/
    void insert(Persona valor) {
        Nodo<Persona>* newNode;
        newNode = new Nodo<Persona>(valor);
        if (isEmpty()) {
            headN = headC = newNode;
        } else {
            Nodo<Persona>* aux1 = headN; Nodo<Persona>* aux2 = nullptr;
            while (aux1 != nullptr && aux1->valor.compNombre(valor)) {
                aux2 = aux1;
                aux1 = aux1->nextN;
            }
            newNode->nextN = aux1;
            if(!aux2){
                headN = newNode; // Insert at the head
            } else {
                aux2->nextN = newNode; // Insert after aux2
            }
            aux1 = headC;
            aux2 = nullptr;
            while (aux1 != nullptr && aux1->valor.compEdad(valor)) {
                aux2 = aux1;
                aux1 = aux1->nextC;
            }
            newNode->nextC = aux1;
            if(!aux2){
                headC = newNode; // Insert at the head
            } else {
                aux2->nextC = newNode; // Insert after aux2
            }
            
        }
        size++;
    }
/*
    Persona* pop() {
        if (isEmpty()) return nullptr;
        Nodo<Persona>* temp = headN;
        Persona* valor = new Persona(headN->valor);
        head = head->next;
        delete temp;
        size--;
        return valor;
    }
*/
    bool isEmpty() const {
        return headN == nullptr;
    }

    int getSize() const {
        return size;
    }

    void printN(string mensaje = "", bool enter = true) {
        cout << mensaje;
        if (enter) cout << endl;
        else cout << " ";
        for (Nodo<Persona>* aux = headN; aux != nullptr; aux = aux->nextN)
            aux->valor.print();
        cout << endl;
    }

    void printC(string mensaje = "", bool enter = true) {
        cout << mensaje;
        if (enter) cout << endl;
        else cout << " ";
        for (Nodo<Persona>* aux = headC; aux != nullptr; aux = aux->nextC)
            aux->valor.print();
        cout << endl;
    }

    Nodo<Persona>* getHeadN() const { //para poder acceder al head desde la clase ED
        return headN;
    }

    Nodo<Persona>* getHeadC() const { //para poder acceder al head desde la clase ED
        return headC;
    }

};




int main() {
    // Example usage of the Lista class
    ListaMultienlazada lista;
    lista.insert(Persona("Juan", 30));
    lista.insert(Persona("Ana", 25));
    lista.insert(Persona("Pedro", 35));
    lista.insert(Persona("Maria", 20));
    lista.insert(Persona("Luis", 28));
    lista.insert(Persona("Carlos", 22));
    lista.printC("Lista ordenada por edad:");
    lista.printN("Lista ordenada por nombre:");
    return 0;
}
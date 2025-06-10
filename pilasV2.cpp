/*
Siguiente reto: 
Crea una clase "Pila_v2" que herede de Pila, esta clase va a permitir operaciones entre los nodos, sólo debes implementar estos métodos:

Nodo* buscar(int valor);
bool existe(int valor);
void extraer(int valor); // e.g.: Se tiene la pila: [1, 3, 5] al invocar a extraer(3) --> [1, 5]
void preAgregar(int valor_a_buscar, int valor_a_insertar);  // e.g.: Se tiene la pila: [1, 3, 5] al invocar a preAgregar(3, 2)  --> [1, 2, 3, 5]
void postAgregar(int valor_a_buscar, int valor_a_insertar); // e.g.: Se tiene la pila: [1, 3, 5] al invocar a postAgregar(3, 4) --> [1, 3, 4, 5]

*/
#include <iostream>
using namespace std;

class Nodo {
private: // ++++ Como buena práctica cambia estos atributos a Protected o Private y realiza las modificaciones necesarias
    int valor;
    Nodo *next;
public:
    Nodo(int valor = 0, Nodo *next = NULL) {
        this->valor = valor;
        this->next = next;
    }
    int getValor() {
        return this->valor;
    }
    Nodo* getNext() {
        return this->next;
    }

    void setNext(Nodo* ptr) {
        this->next = ptr;
    }

    ~Nodo(){
        delete this->next; //ya es un borrado recursivo, 
    }
    /* Mensaje de la IA
    Nodo1->Nodo2->Nodo3->NULL
    Si haces delete Nodo1;, ocurre lo siguiente:
    Se llama al destructor de Nodo1.
    Dentro del destructor de Nodo1, se ejecuta delete this->next;, es decir, delete Nodo2;.
    Ahora se llama al destructor de Nodo2, que a su vez ejecuta delete this->next;, es decir, delete Nodo3;.
    Finalmente, se llama al destructor de Nodo3, que ejecuta delete this->next;, pero como next es NULL, no pasa nada más.
    */
};

class Pila
{
protected: // ++++ Cambiado a protected para que las clases derivadas puedan acceder a estos atributos
    Nodo *primero;
    int size;

public:
    Pila() {
        this->size = 0;
        this->primero = NULL;
    }

    ~Pila() {
        delete this->primero; // ++++ OJO, como está actualmente tu implementación, al eliminar el enlace al primero pierdes los (n-1) elementos y no podrás liberarlos de la memoria.
        /*
            Puedes:
                crear el destructor de Nodo y que ocurra un evento en cadena al eliminarse el primero (recursivo)
                o de manera iterativa irlos eliminando 
            
            Luego voy a mostrar como desarrollo esta función
        */
    }
    void push(int valor) { //insertar nuevo elemento (arriba/antes de los demas)
        primero = new Nodo(valor, primero); // ++++ Las dos líneas anteriores pueden juntarse como: "primero = new Nodo(valor, primero);"  ^.^
        size++;
    }
    int pop() { //remover el mas arriba
        if (this->isEmpty())
            return INT_MIN;
        int valor = primero->getValor();
        Nodo *temp = primero;
        primero = primero->getNext();
        temp->setNext(nullptr); // Rompe el enlace con los demas para evitar borrado recursivo
        delete temp; //ahora solo borra el nodo actual
        size--;
        return valor;
    }
    int top() { //Obtener el elemento mas arriba
        if (this->isEmpty())
            return INT_MIN;
        return primero->getValor();
    }
    int getsize() {
        return this->size;
    }
    bool isEmpty() {
        return primero == NULL;
    }
    void print(){
        for (Nodo *aux = primero; aux != NULL; aux = aux->getNext())
            cout << aux->getValor() << " ";
        cout << endl;
    }
};

class Pila2 : public Pila {
    public:
    Pila2() : Pila() {} // Constructor que llama al constructor de la clase base Pila
    Nodo* buscar(int valor){
        for (Nodo *aux = primero; aux != NULL; aux = aux->getNext())
            if(aux->getValor() == valor) return aux;
        return NULL;
    }
    bool existe(int valor){
        for (Nodo *aux = primero; aux != NULL; aux = aux->getNext())
            if(aux->getValor() == valor) return true;
        return false;
    }
    void extraer1(int valor) // e.g.: Se tiene la pila: [1, 3, 5] al invocar a extraer(3) --> [1, 5]
    {   
        if (primero == NULL) return;
        Nodo* prev = primero;
        if(prev->getValor() == valor) { // Si es el primer nodo
            pop(); // Remover el primero
            return;
        }
        Nodo *curr = prev->getNext(); // Comenzar desde el segundo nodo y asi tengo 2 puntos antes y current
        for (; curr != NULL; curr = curr->getNext(), prev = prev->getNext()) {
            if(curr->getValor() == valor) {
                prev->setNext(curr->getNext()); // Saltar el nodo a eliminar
                curr->setNext(nullptr); // Rompe el enlace con los demas para evitar borrado recursivo
                delete curr; // Liberar memoria del nodo eliminado
                size--;
                return;
            }
        }  
    }
void extraer2(int valor) // e.g.: Se tiene la pila: [1, 3, 5] al invocar a extraer(3) --> [1, 5]
    {
        if (primero == NULL) return;
        Nodo* curr = primero;
        if(curr->getValor() == valor) { // Si es el primer nodo
            pop(); // Remover el primero
            return;
        }
        for (; curr->getNext() != NULL; curr = curr->getNext()) { //verificar curr->next para no generar segmentation por el if de abajo
            if(curr->getNext()->getValor() == valor) {
                Nodo* aux = curr->getNext(); // Guardar el nodo a eliminar
                
                curr->setNext(curr->getNext()->getNext()); // Saltar el nodo a eliminar
                aux->setNext(nullptr); // Rompe el enlace con los demas para evitar borrado recursivo
                delete aux; // Liberar memoria del nodo eliminado
                size--;
                return;
            }
        }  
    }
    void preAgregar(int valor_a_buscar, int valor_a_insertar)  // e.g.: Se tiene la pila: [1, 3, 5] al invocar a preAgregar(3, 2)  --> [1, 2, 3, 5]
    {   if (primero == NULL) return;
        Nodo* curr = primero;
         if(curr->getValor() == valor_a_buscar) { // Si es el primer nodo
            push(valor_a_insertar); // Remover el primero
            return;
        }
        for (; curr != NULL; curr = curr->getNext()) {
            if(curr->getNext()->getValor() == valor_a_buscar) {
                Nodo* nuevo = new Nodo(valor_a_insertar, curr->getNext()); // Crear el nuevo nodo
                curr->setNext(nuevo); // Insertar el nuevo nodo antes del nodo a buscar
                size++;
                return;
            }
        }  
    }
void postAgregar(int valor_a_buscar, int valor_a_insertar) // e.g.: Se tiene la pila: [1, 3, 5] al invocar a postAgregar(3, 4) --> [1, 3, 4, 5]
{   if (primero == NULL) return;
    Nodo* curr = primero;

        for (; curr != NULL; curr = curr->getNext()) {
            if(curr->getValor() == valor_a_buscar) {
                Nodo* nuevo = new Nodo(valor_a_insertar, curr->getNext()); // Crear el nuevo nodo
                curr->setNext(nuevo); // Insertar el nuevo nodo antes del nodo a buscar
                size++;
                return;
            }
        }  
    }
};

int main()
{
    Pila2 pila1;
    pila1.push(1);
    pila1.push(2);
    pila1.push(3);
    pila1.push(4);
    pila1.print();
    cout<<"Existe el 5? " << (pila1.existe(5) ? "Si" : "No") << endl;
    cout<<"Existe el 3? " << (pila1.existe(3) ? "Si" : "No") << endl;
    Nodo* encontrado = pila1.buscar(3);
    cout<< "Encontrado: " << (encontrado ? to_string(encontrado->getValor()) : "No encontrado") << endl;
    cout<<"extraer el 3: ";
    pila1.extraer2(3);
    pila1.print();
    pila1.preAgregar(2, 5); // Agregar 5 antes de 2
    cout<<"\nDespues de preAgregar 5 antes de 2: ";
    pila1.print();
    pila1.postAgregar(2, 7); // Agregar 5 antes de 2
    cout<<"\nDespues de postAgregar 7 antes de 2: ";
    pila1.print();
    pila1.extraer2(1);
    pila1.print();
    pila1.extraer2(347);
    pila1.print();
    pila1.pop();
    pila1.pop();
    pila1.pop();
    pila1.postAgregar(7, 5);
    pila1.print();

}
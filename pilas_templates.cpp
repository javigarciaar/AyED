/* Javier Garcia
Implementacion de Pilas usando templates
*/
#include <iostream>
using namespace std;
template <typename T>
class Pila{
protected: // listo ++++ Cambiado a protected para que las clases derivadas puedan acceder a estos atributos
    struct Nodo{
        T valor;
        Nodo *next;
        Nodo(T valor = 0, Nodo *next = NULL) : valor(valor), next(next) {}
    };

    Nodo *primero;
    int size;

public:
    Pila(){
        this->size = 0;
        this->primero = NULL;
    }

    ~Pila(){
        delete this->primero;
    }
    void push(T valor){  // insertar nuevo elemento (arriba/antes de los demas)
        primero = new Nodo(valor, primero); // listo ++++ Las dos líneas anteriores pueden juntarse como: "primero = new Nodo(valor, primero);"  ^.^
        size++;
    }
    T pop(){ // remover el mas arriba
        if (this->isEmpty())
            return INT_MIN;
        T valor = primero->valor;
        Nodo *temp = primero;
        primero = primero->next;
        temp->next=nullptr; // Rompe el enlace con los demas para evitar borrado recursivo
        delete temp;            // ahora solo borra el nodo actual
        size--;
        return valor;
    }
    T top(){ // Obtener el elemento mas arriba
        if (this->isEmpty())
            return INT_MIN;
        return primero->valor;
    }
    int getsize(){
        return this->size;
    }
    bool isEmpty(){
        return primero == NULL;
    }
    void print(){
        for (Nodo *aux = primero; aux != NULL; aux = aux->next)
            cout << aux->valor << " ";
        cout << endl;
    }
};
template <typename T>
class Pila2 : public Pila<T>{
public:
    using typename Pila<T>::Nodo; // Para poder usar Nodo dentro de Pila2
    Pila2() : Pila<T>() {} // Constructor que llama al constructor de la clase base Pila
    Nodo *buscar(T valor){
        for (Nodo *aux = this->primero; aux != NULL; aux = aux->next)
            if (abs(aux->valor - valor) < 1e-6)
                return aux;
        return NULL;
    }
    bool existe(T valor){
        for (Nodo *aux = this->primero; aux != NULL; aux = aux->next)
            if (abs(aux->valor - valor) < 1e-6) // Comparación para evitar problemas de precisión con flotantes
                return true;
        return false;
    }
    void extraer1(T valor) {// e.g.: Se tiene la pila: [1, 3, 5] al invocar a extraer(3) --> [1, 5]
        //Version 1: Uso 2 punteros, uno para el nodo anterior y otro para el actual
        if (this->primero == NULL)
            return;
        Nodo *prev = this->primero;
        if (abs(prev->valor - valor) < 1e-6){          // Si es el primer nodo
            this->pop();          // Remover el primero
            return;
        }

        Nodo *curr = prev->next; // Comenzar desde el segundo nodo y asi tengo 2 puntos antes y current
        for (; curr != NULL; curr = curr->next, prev = prev->next){
            if (abs(curr->valor - valor) < 1e-6){
                prev->next= curr->next; // Saltar el nodo a eliminar
                curr->next= nullptr;         // Rompe el enlace con los demas para evitar borrado recursivo
                delete curr;                    // Liberar memoria del nodo eliminado
                this->size--;
                return;
            }
        }
    }
    void extraer2(T valor){ // e.g.: Se tiene la pila: [1, 3, 5] al invocar a extraer(3) --> [1, 5]
    //Version 2: Uso un solo puntero, recorro la pila y verifico si el siguiente nodo es el que quiero eliminar
        if (this->primero == NULL)
            return;
        Nodo *curr = this->primero;
        if (abs(curr->valor - valor) < 1e-6){          // Si es el primer nodo
            this->pop(); // Remover el primero
            return;
        }
        for (; curr->next != NULL; curr = curr->next){ // verificar curr->next para no generar segmentation por el if de abajo
            if (abs(curr->next->valor- valor) <1e-6){
                Nodo *aux = curr->next;                // Guardar el nodo a eliminar
                curr->next=curr->next->next;  // Saltar el nodo a eliminar
                aux->next = nullptr;                      // Rompe el enlace con los demas para evitar borrado recursivo
                delete aux;                                 // eliminar nodo
                this->size--;
                return;
            }
        }
    }
    void preAgregar(T valor_a_buscar, T valor_a_insertar){ // e.g.: Se tiene la pila: [1, 3, 5] al invocar a preAgregar(3, 2)  --> [1, 2, 3, 5]
    
        if (this->primero == NULL)
            return;
        Nodo *curr = this->primero;
        if (abs(curr->valor - valor_a_buscar ) < 1e-6)
        {                           // Si es el primer nodo
            this->push(valor_a_insertar); // Remover el primero
            return;
        }
        for (; curr->next != NULL; curr = curr->next)
        {
            if (abs(curr->next->valor - valor_a_buscar) < 1e-6)
            {
                Nodo *nuevo = new Nodo(valor_a_insertar, curr->next); // Crear el nuevo nodo
                curr->next=nuevo;                                      // Insertar el nuevo nodo antes del nodo a buscar
                this->size++;
                return;
            }
        }
    }
    void postAgregar(T valor_a_buscar, T valor_a_insertar){// e.g.: Se tiene la pila: [1, 3, 5] al invocar a postAgregar(3, 4) --> [1, 3, 4, 5]
    
        if (this->primero == NULL)
            return;
        Nodo *curr = this->primero;

        for (; curr != NULL; curr = curr->next){
            if (abs(curr->valor - valor_a_buscar) < 1e-6){
                Nodo *nuevo = new Nodo(valor_a_insertar, curr->next); // Crear el nuevo nodo
                curr->next=nuevo;                                      // Insertar el nuevo nodo antes del nodo a buscar
                this->size++;
                return;
            }
        }
    }
};

int main()
{
    Pila2<float> pila1;
    pila1.push(3.0f);
    pila1.push(2.34f);
    pila1.push(3.14159f);
    pila1.push(5.0f);
    pila1.print();
    cout << "Existe el 5? " << (pila1.existe(5.0) ? "Si" : "No") << endl;
    cout << "Existe el 3? " << (pila1.existe(3) ? "Si" : "No") << endl;
    //Nodo*encontrado = pila1.buscar(3);
    //cout << "Encontrado: Dir" << encontrado << " "<< encontrado->valor << endl;
    cout << "extraer el 3: ";
    pila1.extraer1(3);
    pila1.print();
    pila1.preAgregar(2.34, 5); // Agregar 5 antes de 2
    cout << "\nDespues de preAgregar 5 antes de 2: ";
    pila1.print();
    pila1.postAgregar(2, 7); // Agregar 7 desp de 2
    cout << "\nDespues de postAgregar 7 despues de 2: ";
    pila1.print();
    pila1.extraer2(1);
    pila1.print();
    pila1.extraer2(347); // Aguanta el caso borde de no encontrar el valor
    pila1.print();
    pila1.pop();
    pila1.pop();
    pila1.pop();
    cout<<" Pop de 3 elementos y postAgregar 5 despues de 7"<<endl;
    pila1.postAgregar(7, 5);
    pila1.print();
}
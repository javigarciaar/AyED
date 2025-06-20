/*Javier Garcia 5/6/25
IMPLEMENTACION DE PILAS usando memoria dinamica
*/

#include <iostream>
using namespace std;
template <typename T>
class Nodo {
public:
    T valor;
    Nodo* next;
    Nodo(T valor, Nodo* next = NULL) : valor(valor), next(next) {}

};
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
    void push(T valor) { //insertar nuevo elemento (arriba/antes de los demas)
        Nodo<T> *temp = new Nodo(valor, primero);
        primero = temp;
        size++;
    }
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
};

int main()
{
    Pila<int> pila1;
    Pila<int>* pila2;
    Pila<int>* p_pila3 = new Pila<int>(); // Crear una pila vacia
    pila1.push(10);
    pila1.push(234);
    pila1.push(1560);
    pila1.push(934);
    pila1.print();
    cout << endl;
    pila1.aggAlFondo(9990);
    pila2 = pila1.clonar(); // Clonar la pila1 a pila2
    cout << "Despues de agg al fondo: ";
    pila1.print();
    cout << endl;
    pila1.invertir();
    cout << "Despues de invertir: ";
    pila1.print();
    cout << endl;
    cout << "El tamano de la pila es: " << pila1.getsize() << endl;
    int* topValue = pila1.top();
    if (topValue) {
    cout << "El elemento top de la pila es: " << *topValue << endl;
    }
    else {
        cout << "La pila esta vacia." << endl;
    }
    cout << "Removiendo el elemento de arriba ";
    pila1.pop();
    topValue = pila1.top();
if (topValue) {
    cout << "El elemento top de la pila es: " << *topValue << endl;
    }
    else {
        cout << "La pila esta vacia." << endl;
    }
    pila1.pop();
    topValue = pila1.top();
if (topValue) {
    cout << "El elemento top de la pila es: " << *topValue << endl;
    }
    else {
        cout << "La pila esta vacia." << endl;
    }
    pila1.pop();
    cout << "El tamano de la pila es: " << pila1.getsize() << endl;
    topValue = pila1.top();
if (topValue) {
    cout << "El elemento top de la pila es: " << *topValue << endl;
    }
    else {
        cout << "La pila esta vacia." << endl;
    }
    pila1.pop();
    cout << "El tamano de la pila es: " << pila1.getsize() << endl;
    topValue = pila1.top();
    if (topValue) {
        cout << "El elemento top de la pila es: " << *topValue << endl;
    }
    else {
        cout << "La pila esta vacia." << endl;
    }
    delete topValue; // Liberar memoria del valor top
    pila1.print();
    cout << "Pila clonada: ";
    pila2->print();
    delete pila2; // Liberar memoria de la pila clonada
    p_pila3->push(100);
    p_pila3->push(200);
    p_pila3->push(300);
    p_pila3->print("Pila original:", false);
    p_pila3->invertir();
    p_pila3->print("Pila invertida:", false);
    delete p_pila3; // Liberar memoria de la pila vacia
    return 0;
}
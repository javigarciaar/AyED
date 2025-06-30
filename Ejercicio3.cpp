/*
Se desean crear Grupos de Personas, estos grupos tienen un nombre "Partida caimanera - fútbol" en el cual se encuentran Personas, es posible crear múltiples grupos y una persona puede estar en múltiples grupos.
Al momento de contabilizar e imprimir los miembros del grupo debe tomar en cuenta que:
Si la persona se encuentra con la cuenta desactivada (campo esCuentaActiva)  es como si no estuviese en el grupo.
Es decir, una persona con la cuenta desactivada no influye en la cuenta del size del grupo ni en la impresión de los miembros del grupo.
Deben considerar si: Una persona ya existe en el grupo, no se debe agregar de nuevo (aplica igual si se encuentra desactivado)

Busque máximixar la eficiencia en espacio de esta solución, explique como logra esto
*/

#include <iostream>
using namespace std;

class Persona{
public:
    string username;
    bool isActive;

    Persona(string username) : username(username), isActive(true){}

    void print(bool printStatus = true) {
        cout << "User: " <<username;
        if(printStatus) 
            this->printStatus();
        cout << endl;
    }
    void printStatus() {
        cout << " Status " << (isActive ? "activo" : "inactivo");
    }
    void changeStatus() {
        isActive = !isActive; // Cambia el estado activo/inactivo
    }
};
template <typename T>
class Nodo {
public:
    T valor;
    Nodo* next;

    Nodo(T p) : valor(p), next(nullptr) {}
};

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

    void push(T valor) {
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

    void print(string mensaje = "", bool enter = true) {
        cout << mensaje;
        if (enter) cout << endl;
        else cout << " ";
        for (Nodo<T>* aux = head; aux != nullptr; aux = aux->next)
            aux->valor.print();
        cout << endl;
    }

};

class ListaP : public Lista<Persona> {
public:
    ListaP() : Lista() {}

    void push(Persona valor) {
        // Verifica si el usuario ya existe antes de agregarlo
        for (Nodo<Persona>* aux = head; aux != nullptr; aux = aux->next) {
            if (aux->valor.username == valor.username) {
                cout << "Usuario ya existe: " << valor.username << endl;
                return; // No agregar si ya existe
            }
        }
        Lista<Persona>::push(valor); // Llama al método push de la clase padre
    }

    void ImprimirDatoUser(string username) {
        for (Nodo<Persona>* aux = head; aux != nullptr; aux = aux->next) {
            if (aux->valor.username == username) {
                aux->valor.print(); // Imprime el usuario y su estado
                return;
            }
        }
        cout << "Usuario no encontrado" << endl;
    }

    Persona* search(string username){
        for (Nodo<Persona>* aux = head; aux != nullptr; aux = aux->next)
            if(aux->valor.username == username){
                return &aux->valor;
            }
        return nullptr; // Si no se encuentra la persona
    }
};

class Grupo : public Lista<Persona*>{
    
    string nombre;
public:
    Grupo(string nombre) : nombre(nombre){}

    void agregarPersona(Persona* persona){
        this->push(persona);
    }

    int contarMiembrosActivos(){
        int contador =0;
        for (Nodo<Persona*>* aux = head; aux != nullptr; aux = aux->next){
            if(aux->valor->isActive)
                contador++;
        }
        return contador;
    }

    void printMiembros(){
        cout << "Miembros del grupo " << nombre << ":" << endl;
        for (Nodo<Persona*>* aux = head; aux != nullptr; aux = aux->next){
            if(aux->valor->isActive)
                aux->valor->print(false);
        }
    }
    
};

int main(){
    ListaP listaPersonas;
    Persona *p = nullptr;
    Persona xd("el_pepe");
    listaPersonas.push(Persona("bastian"));
    listaPersonas.push(Persona("javigarciaar"));
    listaPersonas.push(Persona("osacr"));
    listaPersonas.push(Persona("bastian"));
    listaPersonas.push(xd);
    listaPersonas.print("Lista de Personas:");
    p = listaPersonas.search("bastian");
    if (p != nullptr) 
        p->changeStatus();
    listaPersonas.print("Lista de Personas:");
    
    Grupo grupo1("Grupo de fuol");
    Grupo grupo2("Grupo de amigos");
    if (p != nullptr) 
        grupo1.agregarPersona(p);
    grupo2.agregarPersona(&xd);
    p = listaPersonas.search("javigarciaar");
    if (p != nullptr) {
        grupo1.agregarPersona(p);
        grupo2.agregarPersona(p);
    }
    grupo1.printMiembros();
    cout << "Miembros activos en el grupo 1: " << grupo1.contarMiembrosActivos() << endl << endl;
    grupo2.printMiembros();
    cout << "Miembros activos en el grupo 2: " << grupo2.contarMiembrosActivos() << endl << endl;

    p = listaPersonas.search("javigarciaar");
    if(p != nullptr)
        p->changeStatus();
    grupo1.printMiembros();
    cout << "Miembros activos en el grupo 1: " << grupo1.contarMiembrosActivos() << endl;
    return 0;
}
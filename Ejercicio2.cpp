/* Javier Garcia 20/06/25
Segundo ejercicio:
La página IMDB no posee un listado de favoritos para sus usuarios, se desea que cree una estructura en la cual puedan almacenar, adicionalmente deben ofrecer que los usuarios pueden reordenar estos "items" con los siguientes métodos:
* void moverDePrimero(int peliculaID)
* void moverDeUltimo(int peliculaID)
* void moverUnaPosicionArriba(int peliculaID)
* void moverUnaPosicionAbajo(int peliculaID)
* void imprimirFavoritos()
*/

#include <iostream>
using namespace std;
class Pelicula {
public:
    int id;
    string titulo;

    Pelicula(int id=0, string titulo="") : id(id), titulo(titulo) {}

    void print() {
        cout << "ID: " << id << ", Titulo: " << titulo << endl;
    }
};
class Nodo {
public:
    Pelicula valor;
    Nodo* next;
    Nodo* prev;

    Nodo(Pelicula p = Pelicula()) : valor(p), next(nullptr), prev(nullptr) {}
};
class Dipolo{
protected:
    Nodo *front;
    Nodo *back;
public:
    Dipolo() : front(nullptr), back(nullptr) {}

    ~Dipolo() {
        while (!isEmpty()) {
            popFront(); // Liberar memoria de los nodos
        }
    }

    void pushFront(Pelicula valor)
    {
        Nodo *new_p = new Nodo(valor);
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
        Nodo *temp = this->front;
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

    void pushBack(Pelicula valor)
    {
        Nodo *new_p = new Nodo(valor);
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

        Nodo *temp = this->back;
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
        for (Nodo* aux = this->front; aux != nullptr; aux = aux->next) {
            aux->valor.print();
            if(espacio) cout<<" ";
        }
        cout << endl;
    }

    void printBack( bool espacio = true) {
        for (Nodo* aux = this->back; aux != nullptr; aux = aux->prev) {
            aux->valor.print();
            if(espacio) cout<<" ";
        }
        cout << endl;
    }
};

class Favoritos : public Dipolo {
public:
    void eliminar(Nodo* nodo){
        if (nodo == nullptr) return; // Si el nodo es nulo, no hacer nada

        if (nodo->prev) {
            nodo->prev->next = nodo->next; // Conectar el nodo previo con el siguiente
        } else {
            front = nodo->next; // Si es el primer nodo, actualizar el frente
        }

        if (nodo->next) {
            nodo->next->prev = nodo->prev; // Conectar el nodo siguiente con el previo
        } else {
            back = nodo->prev; // Si es el ultimo nodo, actualizar el final
        }

        delete nodo; // Liberar memoria del nodo eliminado
    }

    Nodo* buscarNodo(int Idpelicula) {
        Nodo* aux = front;
        while (aux != nullptr) {
            if (aux->valor.id == Idpelicula) {
                return aux; // Retorna el nodo que contiene la pelicula
                
            }
            aux = aux->next;
        }
        return nullptr; // Si no se encuentra la pelicula

    }

    void swap(Nodo* a, Nodo* b) {
        if (a == nullptr || b == nullptr) return; 
        Pelicula temp = a->valor;
        a->valor = b->valor;
        b->valor = temp;
    }

    void moverDePrimero(int target){
        Nodo* aux = buscarNodo(target);
        if(aux == nullptr) return; // Si no se encuentra la pelicula, no hacer nada
        if(aux == front) return; // Si ya es el primero, no hacer nada
        Pelicula p(aux->valor);
        eliminar(aux);
        pushFront(p); // Mover la pelicula al frente
    }

    void moverDeUltimo(int target){
        Nodo* aux = buscarNodo(target);
        if(aux == nullptr) return; // Si no se encuentra la pelicula, no hacer nada
        if(aux == back) return; // Si ya es el ultimo, no hacer nada
        Pelicula p = aux->valor;
        eliminar(aux);
        pushBack(p); // Mover la pelicula al final
    }

    void moverUnaPosicionArriba(int peliculaID) {
        Nodo* aux = buscarNodo(peliculaID);
        if (aux == nullptr || aux == front) return; // Si no se encuentra la pelicula o ya es el primero, no hacer nada
        swap(aux, aux->prev); // Intercambiar con el nodo previo
    }

    void moverUnaPosicionAbajo(int peliculaID) {
        Nodo* aux = buscarNodo(peliculaID);
        if( aux == nullptr || aux->next == nullptr) return; // Si no se encuentra la pelicula o ya es el ultimo, no hacer nada
        moverUnaPosicionArriba(aux->next->valor.id);
    }

    void imprimirFavoritos(string mensaje = "") {
        cout << mensaje<<endl;
        printFront();
    }
};

int main(){
    Favoritos ListaIMBD;
    ListaIMBD.pushBack(Pelicula(284392, "Batman"));
    ListaIMBD.pushBack(Pelicula(231, "La sustancia")); 
    ListaIMBD.pushBack(Pelicula(123, "Los increibles"));
    ListaIMBD.pushBack(Pelicula(666, "American Psycho"));

    ListaIMBD.imprimirFavoritos("Lista de favoritos inicial: ");
    ListaIMBD.moverDePrimero(123); 
    ListaIMBD.imprimirFavoritos("Lista de favoritos despues de mover 'Los increibles' al frente: ");
    ListaIMBD.moverDeUltimo(284392); 
    ListaIMBD.imprimirFavoritos("Lista de favoritos despues de mover 'Batman' al final: ");
    ListaIMBD.moverUnaPosicionArriba(666); 
    ListaIMBD.imprimirFavoritos("Lista de favoritos despues de mover 'American Psycho' una posicion arriba: ");

    ListaIMBD.moverUnaPosicionAbajo(2344531); 
    ListaIMBD.imprimirFavoritos("Despues de mover una que no existe: ");
}

                
/*// Se desea almacenar un listado de ciudades del mundo: e.g: El Cairo, Egipto; Manila, Filipinas; Caracas, Venezuela... etc
// Desarrolle una EDD en la cual tenga los siguientes métodos:
void listarCiudades(string pais); // Imprime las ciudades asociadas a ese país
string getPais(string ciudad); // Retorna el país asociado a esa ciudad


Se desea que no se repitan ni ciudades ni paises
Carcas, Venezuela
Valencia, Venezuela
Maracaibo, Venezuela
*/

#include <iostream>
using namespace std;

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

    Nodo<T>* getHead() const { //para poder acceder al head desde la clase ED
        return head;
    }

};

template <typename T>
class ListaSinRepeticion : public Lista<T> {
    public:
    void push(T x){
        for(Nodo<T>* aux = this->head; aux!=nullptr; aux = aux->next)
            if(aux->valor == x)
                return;
        Lista<T>::push(x);
    }
};

class Pais{
public:
    string nombre;
    ListaSinRepeticion<string> ciudades;
    Pais(string nombre) : nombre(nombre) {}

    void agregarCiudad(string ciudad) {
        if (!ciudades.isEmpty()) {
            for (Nodo<string>* aux = ciudades.getHead(); aux != nullptr; aux = aux->next) {
                if (aux->valor == ciudad) {
                    cout << "Ciudad ya existe: " << ciudad << endl;
                    return; // No agregar si ya existe
                }
            }
        }
        ciudades.push(ciudad);
    }

    void print(){
        cout<<this->nombre<<": ";
        this->printCiudades();
    }

    void printCiudades(){
        for (Nodo<string>* aux = ciudades.getHead(); aux != nullptr; aux = aux->next) {
                cout<<aux->valor<<", ";
            }
        cout<<endl;
    }

    bool operator==(Pais pais){
        return this->nombre == pais.nombre;
    }
};


class ED : public ListaSinRepeticion<Pais> {
    public:
    ED() : ListaSinRepeticion() {}

    void agregarCiudad(string pais, string ciudad){
        this->push(Pais(pais)); //no se agrega el pais si ya existe.

        for(Nodo<Pais>* aux = this->head; aux!=nullptr; aux = aux->next)
            if(aux->valor.nombre == pais){
                aux->valor.ciudades.push(ciudad);
                return;
            }
    }

    void listarCiudades(string pais){
        for(Nodo<Pais>* aux = this->head; aux!=nullptr; aux = aux->next)
            if(aux->valor.nombre == pais)
                aux->valor.printCiudades();
    }

    string getPais(string ciudad){
        for(Nodo<Pais>* aux = this->head; aux!=nullptr; aux = aux->next)
            for(Nodo<string>* j = aux->valor.ciudades.getHead(); j!=nullptr; j = j->next)
                if(j->valor == ciudad)
                    return aux->valor.nombre;
        return "";
    }
};

int main(){
    ED ListaPaises;
    do{
        string nombrePais;
        cin>>nombrePais;
        if(nombrePais == "-1")
            break;
        ListaPaises.push(Pais(nombrePais));
    } while (true);

    ListaPaises.print("Listado de Paises: ");

    do{
        string nombrePais, ciudadPais;
        cin>>nombrePais>>ciudadPais;
        if(nombrePais == "-1" or ciudadPais == "-1")
            break;
        ListaPaises.agregarCiudad(nombrePais, ciudadPais);
    } while (true);
    
    ListaPaises.print();
    string aux;
    cin>>aux;
    ListaPaises.listarCiudades(aux);
    cin>>aux;
    cout<<ListaPaises.getPais(aux);
}


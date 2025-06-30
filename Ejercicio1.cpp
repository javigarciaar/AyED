/*Javier Garcia 20/06/25
Se desea realizar un grupo demografico, la idea es tener en una estructura con dos listados (separados por sexo) y que podamos proporcionar estadísticas de las personas que se encuentran allí.
Se asume que la clase Persona existe, y tiene los siguientes atributos: edad, estatura, peso...
Debe diseñar la estructura para alojar a las personas y ofrecer los siguientes métodos:
float getEdadPromedioHombres()
float getEdadPromedioMujeres()
float getEdadPromedio()
float porcentajeHombres()
float porcentajeMujeres()
float getEstaturaPromedioHombres()
float getEstaturaPromedioMujeres()
float getEstaturaPromedio()
*/

#include <iostream>
using namespace std;
class Persona{
public:
    char sexo; // h = hombre, m = mujer
    float peso;
    float estatura;
    int edad;

    Persona(char sexo, int edad=0, float peso=0, float estatura=0) : sexo(sexo), peso(peso), edad(edad), estatura(estatura) {}

    void print() const {
        cout << "Peso: " << peso << ", Edad: " << edad << ", Estatura" << estatura << ", sexo: "<< sexo<< endl;
    }
};
class Nodo {
public:
    Persona valor;
    Nodo* next;

    Nodo(Persona p) : valor(p), next(nullptr) {}
};

class Lista {
protected:
    Nodo* head;
    int size;
public:
    Lista() : head(nullptr), size(0) {}

    ~Lista() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(Persona valor) {
        Nodo* newNode = new Nodo(valor);
        if (isEmpty()) {
            head = newNode;
        } else {
            Nodo* aux = head;
            while (aux->next != nullptr) {
                aux = aux->next;
            }
            aux->next = newNode;
        }
        size++;
    }

    Persona* pop() {
        if (isEmpty()) return nullptr;
        Nodo* temp = head;
        Persona* valor = new Persona(head->valor);
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
        for (Nodo* aux = head; aux != nullptr; aux = aux->next)
            aux->valor.print();
        cout << endl;
    }

    Nodo* getHead() const { //para poder acceder al head desde la clase ED
        return head;
    }
};

class ED {
public:    //Los atributos son publicos para poder acceder a metodos de listas desde el main
    Lista Hombres;
    Lista Mujeres;

    ED() {}
    
    void agregarPersona(Persona p) {
        if(p.sexo=='h' || p.sexo=='H') { //Agrega segun el sexo, si no es H o M, no se agrega
            Hombres.push(p);        
        } else if(p.sexo=='m' || p.sexo=='M') {
            Mujeres.push(p);
        }
    }

    float getEdadPromedioHombres() {
        Nodo* aux = Hombres.getHead();
        float total = 0;
        if(Hombres.isEmpty()) return 0;
        while(aux != nullptr) {
            total += aux->valor.edad;
            aux = aux->next;
        }
        return total / Hombres.getSize();
    }

    float getEdadPromedioMujeres() {
        Nodo* aux = Mujeres.getHead();
        float total = 0;
        if(Mujeres.isEmpty()) return 0;
        while(aux != nullptr) {
            total += aux->valor.edad;
            aux = aux->next;
        }
        return total / Mujeres.getSize();
    }

    float getEdadPromedio(){
        float promHombres = getEdadPromedioHombres();
        float promMujeres = getEdadPromedioMujeres();
        int cantTotal = Hombres.getSize() + Mujeres.getSize();
        if(cantTotal == 0) return 0;
        return (promHombres * Hombres.getSize() + promMujeres * Mujeres.getSize()) / cantTotal; //Formula 
    }

    float porcentajeHombres() {
        int cantTotal = Hombres.getSize() + Mujeres.getSize();
        if(cantTotal == 0) return 0;
        return ((Hombres.getSize())* 100.0 / cantTotal); //el 100.0 para convertir a float
    }

    float porcentajeMujeres() {
        return (100.0 - porcentajeHombres()); // total - porcentaje hombres
    }

    float getEstaturaPromedioHombres() {
        Nodo* aux = Hombres.getHead();
        float total = 0;
        if(Hombres.isEmpty()) return 0;
        while(aux != nullptr) {
            total += aux->valor.estatura;
            aux = aux->next;
        }
        return total / Hombres.getSize();
    }

    float getEstaturaPromedioMujeres() {
        Nodo* aux = Mujeres.getHead();
        float total = 0;
        if(Mujeres.isEmpty()) return 0;
        while(aux != nullptr) {
            total += aux->valor.estatura;
            aux = aux->next;
        }
        return total / Mujeres.getSize();
    }

    float getEstaturaPromedio() {
        float promHombres = getEstaturaPromedioHombres();
        float promMujeres = getEstaturaPromedioMujeres();
        int cantTotal = Hombres.getSize() + Mujeres.getSize();
        if(cantTotal == 0) return 0;
        return (promHombres * Hombres.getSize() + promMujeres * Mujeres.getSize()) / cantTotal;
    }
};

int main(){
    ED grupo;
    grupo.agregarPersona(Persona('h', 25, 70, 1.75));
    grupo.agregarPersona(Persona('m', 30, 65, 1.65));
    grupo.agregarPersona(Persona('h', 20, 81, 1.80));
    grupo.agregarPersona(Persona('m', 22, 55, 1.60));
    grupo.agregarPersona(Persona('h', 65, 75, 1.85));
    grupo.agregarPersona(Persona('h', 15, 60, 1.75));
    grupo.Hombres.print("Hombres: ");
    grupo.Mujeres.print("Mujeres: ");
    cout << "Edad promedio hombres: " << grupo.getEdadPromedioHombres() << endl;
    cout << "Edad promedio mujeres: " << grupo.getEdadPromedioMujeres() << endl;
    cout << "Edad promedio total: " << grupo.getEdadPromedio() << endl;
    cout << "Porcentaje hombres: " << grupo.porcentajeHombres() << "%" << endl;
    cout << "Porcentaje mujeres: " << grupo.porcentajeMujeres() << "%" << endl;
    cout << "Estatura promedio hombres: " << grupo.getEstaturaPromedioHombres() << endl;
    cout << "Estatura promedio mujeres: " << grupo.getEstaturaPromedioMujeres() << endl;
    cout << "Estatura promedio total: " << grupo.getEstaturaPromedio() << endl;

    return 0;

}
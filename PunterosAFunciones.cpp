#include <iostream>
using namespace std;


class Persona{
    string nombre;
    int edad;
public:
    Persona(string n, int e) : nombre(n), edad(e) {}
    
    void print() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }

    bool compEdad(const Persona& otra) {
        return this->edad <= otra.edad;
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


int mult(int a, int b) {
    return a * b;
}

void print(int (*func)(int, int), int a, int b) {
    cout << "Resultado: " << func(a, b) << endl;
}

 

int main() {
    Persona p1("Juan", 30);
    Persona p2("Ana", 257);

    bool (Persona::*compararNombres)(const Persona&) = &Persona::compNombre;
    bool resultado = (p1.*compararNombres)(p2);
    bool (Persona::*compararEdades)(const Persona&) = &Persona::compEdad;
    bool resultado2 = (p1.*compararEdades)(p2);
    cout << "Comparación de nombres: " << (resultado2 ? "p1 <= p2" : "p1 > p2") << endl;

    int (*funcPtr)(int, int) = mult; // Puntero a función
    print(funcPtr, 5, 10); // Llamada a la función a través del puntero
    cout<<funcPtr(2, 3)<<endl; // Llamada directa al puntero a función
    return 0;
}
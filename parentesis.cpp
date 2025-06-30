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

    void invertirSR(){
        Pila* nueva = new Pila();
        while(!this->isEmpty()){
            nueva->push(*this->pop());
        }
        this->clear();
        this->primero = nueva->primero;
    }
};

bool parentesis(string s){
    int tamano = s.size();
    Pila<char> pila;
    for(int i = 0; i < tamano; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            pila.push(s[i]);
        } else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(pila.isEmpty()) return false;
            char top = *pila.pop();
            if((s[i] == ')' && top != '(') ||
               (s[i] == '}' && top != '{') ||
               (s[i] == ']' && top != '[')){
                return false;
            }
        }
    }
    return true;
}

float operar(float a, float b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if(b != 0) return a / b;
    }
    return -1;
}



float NotacionPostFija(string s){
    int tam = s.size();
    Pila<float> pila;
    float r;
    for(int i = 0; i< tam; i++){
        if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/'){
            float a = *pila.pop();
            float b = *pila.pop();
             r = operar(a, b, s[i]);
            pila.push(r);
            continue;
        }
        else if (s[i] < '0' or s[i] > '9'){
            continue;
        }
        string substring = "";
        while(s[i] != ' '){
            substring += s[i];
            i++;
        }
        float convertido = stof(substring);
        substring ="";
        pila.push(convertido);
    }
    return r;
}


int main(){
    

    cout<<NotacionPostFija("41 32 + 5567 *");
    return 0;
}
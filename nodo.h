#pragma once
template <typename T>
class Nodo {
public:
    T valor;
    Nodo<T>* next;
    Nodo(T valor, Nodo<T>* next = nullptr) : valor(valor), next(next) {}
};
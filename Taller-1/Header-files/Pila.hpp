#include "Lista.hpp"

template<typename T>
class Pila {
    Node<T>* top = NULL;

public:
    bool empty();
    void insertar(T dato);
    void eliminar();
    T get();
};

template<typename T>
bool Pila<T>::empty() {
    return top == NULL;
}

template<typename T>
void Pila<T>::insertar(T dato) {
    Node<T>* node = new Node<T>(dato);

    node->next = top;
    top = node;
}

template<typename T>
void Pila<T>::eliminar() {
    if (!empty())
        top = top->next;
}

template<typename T>
T Pila<T>::get() {
    return top->data;
}
#ifndef Lista_hpp
#define Lista_hpp

#include <iostream>

template<typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T data) : data(data), next(NULL) {}
};

template<typename T>
class Lista {
    Node<T>* ptr = NULL;

public:
    bool empty();
    int length();

    void insert(T dato);
    void remove(int index);
    void forEach(void (*func)(T*, int));

    T* get(int posicion);
};

template <typename T>
bool Lista<T>::empty() {
    return (ptr == NULL);
}

template <typename T>
int Lista<T>::length() {
    int c = 1;
    Node<T>* p = ptr;

    if(empty()) return 0;

    while (p != NULL) {
        p = p->next;
        c++;
    }

    return c;
}


template <typename T>
T* Lista<T>::get(int index) {
    int c = 0;
    Node<T>* p = ptr;

    if (empty() || index < 0 || index >= length())
        throw "ERROR: No existe el elemento";

    while (p != NULL && c++ < index) {
        p = p->next;
    }

    return &p->data;
}



template <typename T>
void Lista<T>::insert(T dato) {
    Node<T>* p = ptr;
    Node<T>* nuevo = new Node<T>(dato);

    if (empty()) {
        ptr = nuevo;
        return;
    }

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = nuevo;
}

template <typename T>
void Lista<T>::remove(int index) {
    int c = 0;
    Node<T>* p = ptr;
    Node<T>* q = ptr;

    if (index < 0 || empty()) return;

    if (index == 0) {
        ptr = ptr->next;
        p->next = NULL;
        delete p;
    }

    while (p->next != NULL && c++ < index) {
        q = p;
        p = p->next;
    }

    q->next = p->next;
    p->next = NULL;
    delete p;
}


template <typename T>
void Lista<T>::forEach(void (*func)(T*, int)) {
    Node<T>* p = ptr;
    int c = 0;

    if (empty()) return;

    while (p != NULL) {
        func(&p->data, c++);
        p = p->next;
    }
}

#endif
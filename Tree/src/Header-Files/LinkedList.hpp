#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <exception>
#include <iostream>


namespace tree {

    template<typename type>
    struct Node {
        type value;
        Node<type>* next;

        Node(type value) : value(value), next(nullptr) {}
        Node() : next(nullptr) {}
        ~Node() {}
    };


    template<typename type>
    class List {
        Node<type>* start;
        Node<type>* end;

    public:
        unsigned int length;
        List() : start(nullptr), end(nullptr), length(0) {}
        ~List();
        type& operator[](int);
        void append(type);
        void pop();
        void clear(int);
    };

}

template<typename type>
type& tree::List<type>::operator[](int index) {
    Node<type>* temp;
    int i = 0;

    if (start == nullptr)
        throw std::logic_error("ERROR: List empty");

    if (index < 0 || index >= length)
        throw std::logic_error("ERROR: Index out of range");

    temp = start;

    while (i++ < index) {
        temp = temp->next;
    }

    return temp->value;
}

template<typename type>
void tree::List<type>::append(type element) {
    if (end == nullptr) {
        end = new Node<type>(element);
        start = end;
    }
    else {
        end->next = new Node<type>(element);
        end = end->next;
    }

    length++;
}

template<typename type>
void tree::List<type>::pop() {
    Node<type>* temp;

    if (start != nullptr) {
        temp = start->next;
        delete start;
        start = temp;
        length--;
    }
}

template<typename type>
void tree::List<type>::clear(int index) {
    Node<type>* temp = start;
    int i = 0;

    if (start == nullptr)
        throw std::logic_error("ERROR: List empty");

    if (index < 0 || index > length) {
        return;
    }

    if (index == 0) {
        pop();
        return;
    }

    while (i++ < index - 1) {
        temp = temp->next;
    }

    if (temp->next == end) {
        end = temp;
    }

    temp->next = temp->next->next;
    length--;
}


template<typename type>
tree::List<type>::~List() {
    Node<type>* temp = start;
    Node<type>* temp1 = start;

    while (temp != nullptr && temp1 != nullptr) {
        temp1 = temp->next;
        delete temp;
        temp = temp1;
        temp1 = temp1->next;
    }
}


#endif


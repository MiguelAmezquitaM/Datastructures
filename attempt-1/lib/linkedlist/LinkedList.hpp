#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "SimpleNode.cpp"
#include <iostream>

template <typename T>
class LinkedList
{
private:
    SimpleNode<T> first_node;

public:
    int length;
    LinkedList();
    void append(T obj);
    void pop();

    T &operator[](int);
    const std::string toString();
};

#endif
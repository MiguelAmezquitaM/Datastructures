#ifndef SimpleNode_hpp
#define SimpleNode_hpp

#include <iostream>

template <typename T>
class SimpleNode
{
public:
    T data;
    SimpleNode<T> *next;

    SimpleNode(T data);
    SimpleNode();

    void set_data(T obj);
};

#endif
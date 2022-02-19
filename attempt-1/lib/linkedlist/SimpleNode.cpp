#include "SimpleNode.hpp"

template <typename T>
SimpleNode<T>::SimpleNode(T obj)
{
    data = obj;
}

template <typename T>
SimpleNode<T>::SimpleNode()
{
}

template <typename T>
void SimpleNode<T>::set_data(T obj)
{
    data = obj;
}
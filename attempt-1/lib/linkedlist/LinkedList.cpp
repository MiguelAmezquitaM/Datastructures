#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
    length = 0;
}

template <typename T>
void LinkedList<T>::append(T obj)
{

    if (length > 0)
    {
        SimpleNode<T> *node = new SimpleNode<T>(obj);
        SimpleNode<T> *temp = &first_node;

        for (int i = 1; i < length; i++)
            temp = temp->next;

        temp->next = node;
    }

    else
        first_node.data = obj;

    length++;
}

template <typename T>
T &LinkedList<T>::operator[](int i)
{
    if (i > length || i < 0)
        throw "Index out of range";

    if (i == 0)
        return first_node.data;

    else
    {
        SimpleNode<T> *temp = first_node.next;

        for (int it = 1; it < i; it++)
            temp = temp->next;

        return temp->data;
    }
}

template <typename T>
void LinkedList<T>::pop()
{
    if (length == 0)
        return;

    length > 1
        ? first_node = *first_node.next
        : first_node = SimpleNode<T>();

    length--;
}

template <typename T>
const std::string LinkedList<T>::toString()
{
    std::string text;

    if (length == 0)
    {
        text = "[ ]";
        return text;
    }

    text = "[ ";

    SimpleNode<T> *temp = &first_node;

    for (int i = 0; i < length; i++)
    {
        text += temp->data;

        if (i + 1 < length)
            text += ", ";

        temp = temp->next;
    }

    text += " ]";

    return text;
}

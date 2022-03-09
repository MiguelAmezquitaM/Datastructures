#include "Client.hpp"
#include <iostream>

using std::cout;

bool ClientQueue::empty()
{
    return start == -1;
}

void ClientQueue::insert(Client cliente)
{
    if (empty())
        start++;
    queue[++end] = cliente;
}

void ClientQueue::pop()
{
    if (!empty())
    {
        if (start == end)
        {
            start = end = -1;
        }
        else
        {
            start++;
        }
    }
}

void ClientQueue::print()
{
    if (!empty())
    {
        for (int i = start; i <= end; i++)
        {
            cout << " " << queue[i].name;
        }
        cout << "\n";
    }
}

Client ClientQueue::get()
{
    if (!empty())
    {
        return queue[start];
    }
}




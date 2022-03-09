#include "Bank.hpp"


void Bank::input(Client cliente)
{
    clientQueue.insert(cliente);
}

void Bank::attend()
{
    Client cliente = clientQueue.get();
    if (cliente.type == consignment)
    {
        consignments += cliente.value;
    }
    else if (cliente.type == retirement)
    {
        retirements += cliente.value;
    }
    clientQueue.pop();
}

Client Bank::nextClient()
{
    return clientQueue.get();
}

void Bank::deleteById(int id)
{
    ClientQueue temp;

    while (!clientQueue.empty())
    {
        if (clientQueue.get().id == id)
        {
            break;
        }
        temp.insert(clientQueue.get());
        clientQueue.pop();
    }

    clientQueue.pop();

    while (!temp.empty())
    {
        clientQueue.insert(temp.get());
        temp.pop();
    }
}

void Bank::print()
{
    clientQueue.print();
}

Bank::Bank() : consignments(0), retirements(0)
{
}